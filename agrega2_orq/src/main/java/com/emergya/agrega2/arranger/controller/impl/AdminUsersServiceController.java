package com.emergya.agrega2.arranger.controller.impl;

import java.net.HttpURLConnection;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestBody;

import com.emergya.agrega2.arranger.controller.AdminUsersService;
import com.emergya.agrega2.arranger.model.entity.aop.HandleSolrDocument;
import com.emergya.agrega2.arranger.model.entity.json.EmailPasswordJson;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.json.UserEditJson;
import com.emergya.agrega2.arranger.model.entity.json.UserOde;
import com.emergya.agrega2.arranger.model.entity.solr.GenericEntity;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.util.AgregaUtil;
import com.itelligent.agrega2.dal.Decisor;

import es.pode.adminusuarios.negocio.servicios.UsuarioVO;

/**
 * See {@link AdminUsersService} for more information.
 */
@Component
public class AdminUsersServiceController extends SolrInjectionController implements AdminUsersService {

    private static final String DELETE_USER_PASS = "{SHA}4U4x79ttbdhiEcjO/j29LWkJu/c=";

    /**
     * {@inheritDoc}
     */
    @HandleSolrDocument
    public ServiceResponse addUser(@RequestBody User user) {
        ServiceResponse result = null;
        if (!Utils.isEmpty(user)) {
            if (!Utils.isEmpty(user.getUserMail())) {
                if (!user.getUserMail().contains("+")) {
                    if (!Utils.isEmpty(user.getUserPassword())) {
                        user.setUserPassword(Utils.sha1(user.getUserPassword()));
                        result = AgregaUtil.addUser(user);

                        if (ResponseCode.OK.equals(result.getResponseCode())) {
                            if (ResponseCode.OK.equals(result.getResponseCode())) {
                                result = injectDocument(user);
                                // If document is not injected in Solr, we have
                                // to
                                // delete user from Agrega
                            }
                            if (!ResponseCode.OK.equals(result.getResponseCode())) {
                                AgregaUtil.deleteUser(user.getUserMail(), "");
                            }
                        }
                    }
                }
            }
        }

        return result;
    }

    /**
     * {@inheritDoc}
     */
    @HandleSolrDocument
    public ServiceResponse updateSolrUser(final User user) {
        ServiceResponse result = null;

        if (!Utils.isEmpty(user) && !Utils.isEmpty(user.getId())) {
            result = injectDocument(user);
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User and user id are required");
        }

        return result;
    }

    @HandleSolrDocument
    public ServiceResponse addSolrUser(final User user) {
        return injectDocument(user);
    }

    /**
     * {@inheritDoc}
     */
    public ServiceResponse activateUser(EmailPasswordJson email) {
        ServiceResponse result = null;
        if (!Utils.isEmpty(email) && !Utils.isEmpty(email.getEmail())) {
            result = AgregaUtil.activateUser(email);
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "Mail address is required");
        }

        return result;
    }

    /**
     * {@inheritDoc}
     */
    @HandleSolrDocument
    public ServiceResponse editUser(UserEditJson user) {

        ServiceResponse result = null;
        if (!Utils.isEmpty(user) && !Utils.isEmpty(user.getId())) {

            // Si viene relleno oldPassword, es que el user.getPassword() es el
            // nuevo password. tenemos que obtener de
            // Solr el antiguo y codificar el nuevo en SHA1
            if (!Utils.isEmpty(user.getOldPassword())) {
                user.setOldPassword((String) SolrSupport.getSolrField(user.getId(), "userPasswordStr"));
                user.setUserPassword(Utils.sha1(user.getUserPassword()));
                // Si n no viene relleno el oldPassword, es que no va a cambiar,
                // así que lo obtenemos de Solr y
                // comprobamos
            } else {
                if (!Utils.isEmpty(user.getUserPassword())) {
                    String oldPass = (String) SolrSupport.getSolrField(user.getId(), "userPasswordStr");
                    String pass = user.getUserPassword();

                    // Si el pass NO es el antiguo (ni en claro ni codificado)
                    if (!pass.equals(oldPass) && !pass.equals(oldPass)) {
                        return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "Field 'oldPassword' is required to change the password");
                    }
                }
            }

            result = AgregaUtil.editUser(user, user.getOldMail(), user.getOldPassword());

            if (ResponseCode.OK.equals(result.getResponseCode())) {
                result = injectDocument(user);
            }
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User and User.id are required");
        }

        return result;
    }

    /**
     * {@inheritDoc}
     */
    public ServiceResponse loginUser(EmailPasswordJson emailPassword) {
        String email = !Utils.isEmpty(emailPassword) ? emailPassword.getEmail() : null;
        String password = !Utils.isEmpty(emailPassword) ? emailPassword.getPassword() : null;

        ServiceResponse result = null;
        if (!Utils.isEmpty(email) && !Utils.isEmpty(password)) {
            result = AgregaUtil.login(email, Utils.sha1(password));
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User id, mail address and password are required");
        }

        return result;
    }

    /**
     * {@inheritDoc}
     */
    public ServiceResponse deleteUser(EmailPasswordJson emailPassword) {
        String id = !Utils.isEmpty(emailPassword) ? emailPassword.getId() : null;
        String email = !Utils.isEmpty(emailPassword) ? emailPassword.getEmail() : null;
        String password = !Utils.isEmpty(emailPassword) ? emailPassword.getPassword() : null;

        ServiceResponse result = null;
        if (!Utils.isEmpty(id) && !Utils.isEmpty(email)) {
            result = Utils.isEmpty(password) ? AgregaUtil.deleteUser(email, DELETE_USER_PASS) : AgregaUtil.deleteUser(email, password);

            // En Solr no hay campo "DESACTIVADO" ni nada de eso.
            // ¿Debemos eliminar el usuario de Solr?
            // De momento no hacemos nada
            if (ResponseCode.OK.equals(result.getResponseCode())) {
                boolean deleted = SolrSupport.deleteDocumentById(id, null);
                if (!deleted) {
                    result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User deleted from Agrega but not deleted from Solr");
                } else {
                    if (!Decisor.removeItem(Long.valueOf(id))) {
                        result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User deleted. Recommendations could not be deleted");
                    }
                }
            }
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User id, mail address and password are required");
        }

        return result;
    }

    /**
     * {@inheritDoc}
     */
    public ServiceResponse checkUser(User user) {
        String email = !Utils.isEmpty(user) ? user.getUserMail() : null;
        String nif = !Utils.isEmpty(user) ? user.getUserDni() : null;
        String userName = !Utils.isEmpty(user) ? user.getUserLogin() : null;

        ServiceResponse result = null;
        if (!Utils.isEmpty(email) || !Utils.isEmpty(nif) || !Utils.isEmpty(userName)) {
            result = AgregaUtil.checkFieldsUser(nif, userName, email);
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User email, nif or username is required");
        }

        return result;
    }

    @Override
    public ServiceResponse checkDeleteOdeUser(UserOde userOde) {
        final boolean checkDeletePermission = AgregaUtil.checkDeletePermission(userOde.getMecId(), userOde.getUserId());

        ServiceResponse result = null;

        if (checkDeletePermission) {
            result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User " + userOde.getUserId() + " can delete the ODE with MECID " + userOde.getMecId());
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_FORBIDDEN,
                    "User " + userOde.getUserId() + " CANNOT delete the ODE with MECID " + userOde.getMecId());
        }

        return result;

    }

    @Override
    public ServiceResponse deleteOde(final UserOde userOde) {
        final String mecId = userOde.getMecId();
        final String userId = userOde.getUserId();

        final String uid = AgregaUtil.getAgregaUserByEmail(userId);

        ServiceResponse result = null;

        if (AgregaUtil.checkDeletePermission(mecId, userId)) {
            final boolean deleteOdeRes = AgregaUtil.deleteOde(mecId, uid);
            if (deleteOdeRes) {
                final SolrServiceController solrSrv = new SolrServiceController();
                final String solrId = (String) SolrSupport.getSolrFieldByMECId(mecId, "id");
                final GenericEntity entity = new GenericEntity();
                entity.setId(solrId);
                result = solrSrv.unpublishDocument(entity);
            } else {
                result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Ode NOT deleted in Agrega");
            }
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_FORBIDDEN, "User " + userId + " CANNOT delete the ODE with MECID " + mecId);
        }
        return result;
    }

    @Override
    public ServiceResponse getAgregaUserName(String userName, HttpServletRequest request) {
        final UsuarioVO agregaUserFullByEmail = AgregaUtil.getAgregaUserFullByEmail(userName);

        ServiceResponse response = null;
        if (Utils.isEmpty(agregaUserFullByEmail)) {
            response = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_NOT_FOUND, "Cannot find user in Agrega");
        } else {
            final String name = agregaUserFullByEmail.getNombre();
            final String surName = agregaUserFullByEmail.getApellido1() + " " + agregaUserFullByEmail.getApellido2();
            response = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, name + " " + surName);
        }

        return response;
    }

    @Override
    public ServiceResponse checkUserInAgrega(EmailPasswordJson emailPass) {
        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserFullByEmail(emailPass.getEmail());

        ServiceResponse response = null;
        boolean exists = false;
        if (!Utils.isEmpty(agregaUser)) {
            exists = AgregaUtil.existsUser(agregaUser);
        }
        if (exists) {
            boolean isActive = AgregaUtil.isActiveUser(agregaUser);
            if (!isActive) {
                final boolean activateUserResult = AgregaUtil.activateUser(agregaUser);
                if (activateUserResult) {
                    response = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User exists and had been actived in Agrega");
                } else {
                    response = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_BAD_GATEWAY, "User exists but cannot be activated in Agrega");
                }
            } else {
                response = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User exists and is active in Agrega");
            }
        } else {
            response = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_NOT_FOUND, "User does not exist in Agrega");
        }

        return response;
    }

    @HandleSolrDocument
    public ServiceResponse updateRegional(UserEditJson user) {

        ServiceResponse result = null;
        if (!Utils.isEmpty(user) && !Utils.isEmpty(user.getId())) {

            final User userSolr = (User) SolrSupport.getSolrDocumentById(user.getId());
            userSolr.setUserLocality(user.getUserLocality());
            userSolr.setUserProvince(user.getUserProvince());
            userSolr.setUserCountry(user.getUserCountry());

            result = injectDocument(user);
        } else {
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "User and User.id are required");
        }

        return result;
    }

}
