package com.emergya.agrega2.odes.util;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.List;

import javax.activation.DataHandler;

import org.apache.commons.codec.binary.Base64;
import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.model.entity.json.EmailPasswordJson;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;

import es.pode.adminusuarios.negocio.servicios.GrupoVO;
import es.pode.adminusuarios.negocio.servicios.ResultadoOperacionExternaVO;
import es.pode.adminusuarios.negocio.servicios.SrvAdminUsuariosService;
import es.pode.adminusuarios.negocio.servicios.SrvAdminUsuariosServiceProxy;
import es.pode.adminusuarios.negocio.servicios.UsuarioVO;
import es.pode.buscar.negocio.buscar.servicios.ParametrosBusquedaAvanzadaVO30;
import es.pode.buscar.negocio.buscar.servicios.ResultadoBusquedaVO;
import es.pode.buscar.negocio.buscar.servicios.SrvBuscarService;
import es.pode.buscar.negocio.buscar.servicios.SrvBuscarServiceProxy;
import es.pode.buscar.negocio.buscar.servicios.ValoresBusquedaVO;
import es.pode.entregar.negocio.servicios.ArgObtOrganizacionesVO;
import es.pode.entregar.negocio.servicios.LocalizadorAdlVO;
import es.pode.entregar.negocio.servicios.ManifestVO;
import es.pode.entregar.negocio.servicios.PaquetePifDriVO;
import es.pode.entregar.negocio.servicios.PaquetePifVO;
import es.pode.entregar.negocio.servicios.SrvEntregarService;
import es.pode.entregar.negocio.servicios.SrvEntregarServiceProxy;
import es.pode.entregar.negocio.servicios.TipoPifVO;
import es.pode.publicacion.negocio.servicios.OdePublicadoVO;
import es.pode.publicacion.negocio.servicios.ResultadoOperacionVO;
import es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO;
import es.pode.publicacion.negocio.servicios.SrvPublicacionService;
import es.pode.publicacion.negocio.servicios.SrvPublicacionServiceProxy;
import es.pode.validador.negocio.servicio.ErrorParseoVO;
import es.pode.validador.negocio.servicio.SrvValidadorService;
import es.pode.validador.negocio.servicio.SrvValidadorServiceProxy;
import es.pode.validador.negocio.servicio.ValidaVO;

public class AgregaUtil {
    private static final Log LOG = LogFactory.getLog(AgregaUtil.class);

    // #####################
    // # AGREGA PROPERTIES #
    // #####################
    public static final String AGREGA_URL = "agrega.url";
    public static final String AGREGA_URL_USERS = "agrega.url.users";
    public static final String AGREGA_VALIDATION_SERVICE = "agrega.validation_service";
    public static final String AGREGA_PUBLICATION_SERVICE = "agrega.publication_service";
    public static final String AGREGA_SEARCH_SERVICE = "agrega.search_service";
    public static final String AGREGA_DELIVER_SERVICE = "agrega.deliver_service";
    public static final String AGREGA_VALIDATION_METHOD = "agrega.validation_method";
    public static final String AGREGA_PUBLICATION_METHOD = "agrega.publication_method";
    public static final String AGREGA_SEARCH_METHOD = "agrega.search_method";
    public static final String AGREGA_DELIVER_METHOD = "agrega.deliver_method";

    private static final String FORMAT_CONTENT_IMAGE = "IMAGEN";

    private static final String DEL_ODE_OK_DESC = "Sin errores.";
    private static final String DEL_ODE_OK_RES = "0.0";

    private AgregaUtil() {
    }

    /**
     * Validate an ODE in Agrega (validarCatalogacionWebSemantica)
     * @param base64Content Catalog file in Base64
     * @return Service response 
     */
    public static ServiceResponse validateODE(byte[] base64Content, byte[] base64ContentExtra) {
        Utils.logInfo(LOG, "Entering Validate ODE Service");
        String service = Utils.getMessage(AGREGA_VALIDATION_SERVICE);
        String urlString = Utils.getMessage(AGREGA_URL) + (service != null ? service : "");

        SrvValidadorService validadorService = new SrvValidadorServiceProxy(urlString);

        try {
            ValidaVO result = validadorService.validarCatalogacionExterna(base64Content == null ? "".getBytes() : base64Content,
                    base64ContentExtra == null ? "".getBytes() : base64ContentExtra);

            Utils.logDebug(LOG, "******************RESULTADO********************");
            Utils.logDebug(LOG, "Resultado validación:" + result.getResultadoValidacion());
            Utils.logDebug(LOG, "Ruta Manifest:" + result.getRutaManifest());
            Utils.logDebug(LOG, "Es válido:" + result.getEsValidoManifest());
            if (result.getErrores() != null && result.getErrores().length > 0) {
                for (ErrorParseoVO error : result.getErrores()) {
                    Utils.logDebug(LOG, "Error: " + error.getMensaje());
                }
            }

            if (result.getEsValidoManifest()) {
                return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "OK");

            } else {
                StringBuilder sb = new StringBuilder("Resultado:");
                sb.append(result.getResultadoValidacion());
                if (result.getErrores() != null && result.getErrores().length > 0) {
                    for (ErrorParseoVO error : result.getErrores()) {
                        sb.append("-Error:");
                        sb.append(error.getMensaje());
                        sb.append("(");
                        sb.append(error.getLinea());
                        sb.append(":");
                        sb.append(error.getColumna());
                        sb.append(")");
                    }
                }
                Utils.logInfo(LOG, "Exiting Validate ODE Service");
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, sb.toString());
            }

        } catch (Exception e) {
            Utils.logError(LOG, "Exiting Validate ODE Service with errors: " + e.getMessage());
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }
    }

    /**
     * Publish an ODE in Agrega (publicarWebSemantica)
     * @return Service response 
     */
    public static ServiceResponse publishODE(byte[] base64Content, String author, String title, String editor, String newVersion, String publicationType) {
        Utils.logInfo(LOG, "Entering Publish ODE Service");
        String service = Utils.getMessage(AGREGA_PUBLICATION_SERVICE);
        String urlString = Utils.getMessage(AGREGA_URL) + (service != null ? service : "");

        SrvPublicacionService publicacionService = new SrvPublicacionServiceProxy(urlString);

        try {
            // ResultadoPublicacionVO result =
            // publicacionService.publicarWebSemantica(base64Content,
            // "".getBytes(), getAgregaUserByEmail(author), title,
            // new String[] { getAgregaUserByEmail(editor) }, new
            // Boolean(newVersion), publicationType);
            ResultadoPublicacionVO result = publicacionService.publicacionExterna(base64Content, "".getBytes(), author, title, new String[] { editor }, new Boolean(newVersion),
                    publicationType);

            Utils.logInfo(LOG, "******************RESULTADO********************");
            Utils.logInfo(LOG, "ID: {0}", result.getIdODE());
            Utils.logInfo(LOG, "Descripción: {0}", result.getDescripcion());
            Utils.logInfo(LOG, "ID Resultado: {0}", result.getIdResultado());
            Utils.logInfo(LOG, "Nodo Publicación: {0}", result.getNodoPublicacion());
            Utils.logInfo(LOG, "Path Imagen: {0}", result.getPathImagen());
            Utils.logInfo(LOG, "Path Repositorio: {0}", result.getPathRepositorio());
            Utils.logInfo(LOG, "TamanioODE: {0}", result.getTamainoODE());

            Utils.logInfo(LOG, "Exiting Publish ODE Service");
            if (result != null && "0.0".equals(result.getIdResultado())) {
                return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, result.getIdODE());
            } else {
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, result != null ? result.getDescripcion() : "Error.");
            }

        } catch (RemoteException e) {
            Utils.logError(LOG, "Exiting Publish ODE Service with errors:" + e.getMessage());
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }
    }

    public static ServiceResponse despublishODE(final String mecIdentifier, final String author) {
        Utils.logInfo(LOG, "Entering Despublish ODE Service");
        String service = Utils.getMessage(AGREGA_PUBLICATION_SERVICE);
        String urlString = Utils.getMessage(AGREGA_URL) + (service != null ? service : "");

        SrvPublicacionService publicacionService = new SrvPublicacionServiceProxy(urlString);

        try {
            ResultadoOperacionVO result = publicacionService.despublicacionExterna(mecIdentifier, author);

            Utils.logInfo(LOG, "Exiting Despublish ODE Service");
            if (result != null && "0.0".equals(result.getIdResultado())) {
                return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, result.getIdODE());
            } else {
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, result != null ? result.getDescripcion() : "Error.");
            }

        } catch (RemoteException e) {
            Utils.logError(LOG, "Exiting Desublish ODE Service with errors:" + e.getMessage());
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }
    }

    public static ValoresBusquedaVO getResultadoBusquedaODE(final String identifier, final String language) {
        Utils.logInfo(LOG, "Entering getResultadoBusquedaODE Service");
        ValoresBusquedaVO valorBusquedaVO = null;
        String service = Utils.getMessage(AGREGA_SEARCH_SERVICE);

        String urlString = Utils.getMessage(AGREGA_URL) + (service != null ? service : "");

        SrvBuscarService buscadorService = new SrvBuscarServiceProxy(urlString);

        try {
            ParametrosBusquedaAvanzadaVO30 parametros = new ParametrosBusquedaAvanzadaVO30();
            parametros.setIdentificador(identifier);
            parametros.setComunidadesSeleccionadas(new String[] { "TODAS" });

            if (!Utils.isEmpty(language)) {
                parametros.setIdiomaBusqueda(language);
            }

            ResultadoBusquedaVO result = buscadorService.buscarAvanzado(parametros);

            // ParametrosBusquedaSQIVO arg0 = new ParametrosBusquedaSQIVO(query,
            // maxResultados, startResult, resultadosDevueltos,
            // vocabularioConsulta, idiomaBusqueda);
            // buscadorService.buscarLomEs(arg0);

            Utils.logDebug(LOG, "******************RESULTADO********************");
            Utils.logDebug(LOG, "Resultados búsqueda:" + result.getNumeroResultados());

            ValoresBusquedaVO[] results = result.getResultadoBusqueda();
            if (result.getNumeroResultados() > 0) {
                valorBusquedaVO = results[0];
            }
        } catch (RemoteException e) {
            Utils.logError(LOG, "Exception trying to get the NODE of an ODE: " + e.getMessage());
        }

        Utils.logInfo(LOG, "Exiting getResultadoBusquedaODE Service");
        return valorBusquedaVO;
    }

    @SuppressWarnings("unused")
    private static String getPreviewODE(String identifier) {
        Utils.logInfo(LOG, "Entering getNodoODE Service");
        String preview = "";
        String service = Utils.getMessage(AGREGA_SEARCH_SERVICE);
        String urlString = Utils.getMessage(AGREGA_URL) + (service != null ? service : "");

        SrvBuscarService buscadorService = new SrvBuscarServiceProxy(urlString);

        try {
            ParametrosBusquedaAvanzadaVO30 parametros = new ParametrosBusquedaAvanzadaVO30();
            parametros.setIdentificador(identifier);
            parametros.setComunidadesSeleccionadas(new String[] { "TODAS" });

            ResultadoBusquedaVO result = buscadorService.buscarAvanzado(parametros);

            Utils.logDebug(LOG, "******************RESULTADO********************");
            Utils.logDebug(LOG, "Resultados búsqueda:" + result.getNumeroResultados());

            ValoresBusquedaVO[] results = result.getResultadoBusqueda();
            if (result.getNumeroResultados() > 0) {
                ValoresBusquedaVO res = results[0];
                preview = res.getNodo() + res.getUrlImagen();

            }
        } catch (RemoteException e) {
            Utils.logError(LOG, "Exception trying to get the NODE of an ODE: " + e.getMessage());
        }

        Utils.logInfo(LOG, "Exiting getNodoODE Service");
        return preview;
    }

    /**
     * Search an ODE in Agrega and locate the resources in its node (busces-ma_20080924_1_9164548es-ma_20080924_1_9164548arAvanzado y localizacionPaquetePIF)
     * @param identifier Ode identifier (Catálogo unificado mec-red.es-ccaa de identificación de ODE)
     * @return Service response Response with the URL base of the ODE, if it has been found
     */
    public static ServiceResponse searchODE(String identifier, String language) {
        Utils.logInfo(LOG, "Entering Search/Deliver ODE Service. Identifier {0}, language {1}", identifier, language);

        try {
            String nodo = getNodoOde(identifier, language);
            Utils.logInfo(LOG, "Node {0}", nodo);

            if (!Utils.isEmpty(nodo)) {
                String deliverService = Utils.getMessage(AGREGA_DELIVER_SERVICE);
                SrvEntregarService entregarService = new SrvEntregarServiceProxy("http://" + nodo + "/" + deliverService);
                LocalizadorAdlVO localizador = entregarService.localizacionPaquetePIF(identifier);

                if (localizador != null && !Utils.isEmpty(localizador.getUrl())) {
                    final String message = "http://" + nodo + "/" + localizador.getUrl();
                    Utils.logInfo(LOG, "Exiting Search/Deliver ODE Service. URL -> {0}", message);
                    return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, message);
                } else {
                    Utils.logWarn(LOG, "Error retrieving resource URL.");
                    return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "Error retrieving resource URL.");
                }
            } else {
                Utils.logWarn(LOG, "No resource found with identifier: " + identifier);
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, "No resource found with identifier: " + identifier);
            }
        } catch (RemoteException e) {
            Utils.logError(LOG, "Exiting Search/Deliver ODE Service with errors: " + e.getMessage());
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }
    }

    /**
     * Get organizations and resources of an ODE from Agrega
     * @param identifier MEC-Identifier of the ODE
     * @param idioma Language in which to get the ODE
     * @param usuario UserName of the request (not necessary)
     * @return Manifest with organizations and resources of the ODE
     */
    public static ManifestVO getFilesODE(String identifier, String idioma, String usuario) {
        Utils.logInfo(LOG, "Entering get files ODE Service");
        ManifestVO manifest = null;

        try {
            String nodo = getNodoOde(identifier, idioma);

            if (!Utils.isEmpty(nodo)) {
                String deliverService = Utils.getMessage(AGREGA_DELIVER_SERVICE);
                SrvEntregarService entregarService = new SrvEntregarServiceProxy("http://" + nodo + "/" + deliverService);
                ArgObtOrganizacionesVO ode = new ArgObtOrganizacionesVO();
                ode.setIdentificador(identifier);
                ode.setIdioma(idioma);
                ode.setUsuario(usuario);
                ode.setIdiomaTitulo(idioma);

                manifest = entregarService.obtenerOrganizaciones(ode);
            } else {
                Utils.logWarn(LOG, "No resource found with identifier: " + identifier);
            }
        } catch (Exception e) {
            Utils.logError(LOG, "ODE Metadata could not be obtained from Agrega: " + e.getMessage());
        }

        Utils.logInfo(LOG, "Exiting get files ODE Service");
        return manifest;
    }

    public static String getNodoOde(final String identifier, final String language) {
        String nodo = "";
        ValoresBusquedaVO valorBusqueda = getResultadoBusquedaODE(identifier, language);
        if (valorBusqueda != null && !Utils.isEmpty(valorBusqueda.getNodo())) {
            nodo = valorBusqueda.getNodo();
        } else {
            nodo = Utils.getMessage(AGREGA_URL).replace("http://", "");
        }
        return nodo;
    }

    public static String getPreviewOde(final String identifier, final String language) {
        String preview = null;
        ValoresBusquedaVO valorBusqueda = getResultadoBusquedaODE(identifier, language);
        if (valorBusqueda != null) {
            String nodo = "";
            if (!Utils.isEmpty(valorBusqueda.getNodo())) {
                nodo = valorBusqueda.getNodo();
            } else {
                nodo = Utils.getMessage(AGREGA_URL).replace("http://", "");
            }
            preview = nodo + valorBusqueda.getUrlImagen();
        }
        return preview;
    }

    /*********************************************************************/
    /******************** USER ADMIN SERVICES ****************************/
    /*********************************************************************/

    /**
     * Add an User in Agrega. Required fields are: name, surname, password, mail and DNI
     * @param userSolr {@link User} from Solr/Drupal 
     * @return Response OK/NOK with the result of the operation
     */
    public static ServiceResponse addUser(User userSolr) {
        Utils.logInfo(LOG, "Entering add user ODE Service");
        Utils.logInfo(LOG, Utils.getMessage(AGREGA_URL));
        Utils.logInfo(LOG, Utils.getMessage(AGREGA_URL_USERS));
        ServiceResponse result = null;

        SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));

        if (userSolr != null) {

            UsuarioVO user = new UsuarioVO();

            user.setNombre(userSolr.getUserName());
            user.setApellido1(userSolr.getUserSurName());
            user.setClave(userSolr.getUserPassword());
            user.setEmail(userSolr.getUserMail());
            user.setNIF(userSolr.getUserDni());
            user.setUsuario(userSolr.getUserLogin());

            // Default values
            user.setRecibirCorreoPublicacion(true);
            GrupoVO[] grupos = new GrupoVO[0];
            user.setGrupos(grupos);
            user.setTipoCatalogador("CATALOGADOR");
            user.setFechaDesactivacion(Calendar.getInstance());
            user.setFechaSolicitudAlta(Calendar.getInstance());

            try {
                final ResultadoOperacionExternaVO longResult = usersService.altaUsuarioExterno(user);

                if (!longResult.getCodigoResultado().equals("0")) {
                    throw new RemoteException(longResult.getMensaje());
                } else {
                    final ServiceResponse activateUserResponse = activateUser(new EmailPasswordJson(user.getEmail(), user.getClave()));
                    if (!activateUserResponse.getResponseCode().equals(ResponseCode.OK)) {
                        throw new RemoteException(activateUserResponse.getMessage());
                    }
                }

                result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User registered in Agrega: " + longResult.getMensaje(),
                        String.valueOf(longResult.getCodigoResultado()));

            } catch (RemoteException e) {
                Utils.logError(LOG, "User could not be registered in Agrega: " + e.getMessage());
                result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
            }
        }

        Utils.logInfo(LOG, "Exiting add user ODE Service");
        return result;
    }

    /**
     * Activate an User in Agrega.
     * @param emailPass Email of the user to activate 
     * @return Response OK/NOK with the result of the operation
     */
    public static ServiceResponse activateUser(EmailPasswordJson emailPass) {
        Utils.logInfo(LOG, "Entering activate user ODE Service");
        ServiceResponse result = null;

        SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));

        if (!Utils.isEmpty(emailPass)) {

            try {
                UsuarioVO user = getAgregaUserFullByEmail(emailPass.getEmail());
                if (!Utils.isEmpty(user)) {
                    // ResultadoOperacionExternaVO
                    // modificarUsuarioProComunResponse =
                    // usersService.modificarUsuarioExterno(user,
                    // emailPass.getPassword());
                    ResultadoOperacionExternaVO modificarUsuarioProComunResponse = usersService.modificarUsuarioExterno(user);

                    if (!modificarUsuarioProComunResponse.getCodigoResultado().equals("0")) {
                        throw new RemoteException(modificarUsuarioProComunResponse.getMensaje());
                    }
                    result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User activated in Agrega: " + emailPass.getEmail());
                }
            } catch (RemoteException e) {
                Utils.logError(LOG, "User could not be activated in Agrega: " + e.getMessage());
                result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
            }
        }

        Utils.logInfo(LOG, "Exiting activate user ODE Service");
        return result;
    }

    /**
     * Edit an User in Agrega (name, surname, login). If email/password has changed, the oldMail/oldPassword parameters are required
     * @param userSolr {@link User} from Solr/Drupal
     * @param oldMail Old mail of the user, if new email is provided
     * @param oldPassword Old password of the user, if new password is provided
     * @return Response OK/NOK with the result of the operation
     */

    public static ServiceResponse editUser(User userSolr, String oldMail, String oldPassword) {
        Utils.logInfo(LOG, "Entering edit user ODE Service");
        ServiceResponse result = null;

        SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));

        if (userSolr != null) {

            try {
                UsuarioVO userOld = getAgregaUserFullByEmail(!Utils.isEmpty(oldMail) ? oldMail : userSolr.getUserMail());

                if (userOld != null) {
                    if (!Utils.isEmpty(userSolr.getUserName()) && !userSolr.getUserName().equals(userOld.getNombre())) {
                        userOld.setNombre(userSolr.getUserName());
                    }

                    if (!Utils.isEmpty(userSolr.getUserSurName()) && !userSolr.getUserSurName().equals(userOld.getApellido1())) {
                        userOld.setApellido1(userSolr.getUserSurName());
                    }

                    if (!Utils.isEmpty(userSolr.getUserMail()) && !Utils.isEmpty(oldMail)) {
                        userOld.setEmail(userSolr.getUserMail());
                        // userOld.setUsuario(oldMail);
                    }

                    if (!Utils.isEmpty(userSolr.getUserPassword())) {
                        userOld.setClave(userSolr.getUserPassword());
                    }

                    final String oldPassword2 = !Utils.isEmpty(oldPassword) ? oldPassword : "";
                    userOld.setClave(oldPassword2);

                    // ResultadoOperacionExternaVO edited =
                    // usersService.modificarUsuarioExterno(userOld,
                    // oldPassword2);
                    ResultadoOperacionExternaVO edited = usersService.modificarUsuarioExterno(userOld);

                    if (!edited.getCodigoResultado().equals("0")) {
                        result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK, edited.getCodigoResultado() + edited.getMensaje());
                    } else {
                        result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, edited.getMensaje());
                    }
                } else {
                    result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_OK,
                            "User not found with mail: " + (!Utils.isEmpty(oldMail) ? oldMail : userSolr.getUserMail()));
                }

            } catch (RemoteException e) {
                Utils.logError(LOG, "User could not be edited: " + e.getMessage());
                result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
            }
        }

        Utils.logInfo(LOG, "Exiting edit user ODE Service: {0} - {1}", result.getResponseCode(), result.getMessage());
        return result;
    }

    /**
     * Try to authenticate against Agrega 
     * @param email Email of the user to authenticate
     * @param password Password of the user
     * @return Response OK/NOK with the result of the operation
     */
    public static ServiceResponse login(String email, String password) {
        Utils.logInfo(LOG, "Entering login user ODE Service");
        ServiceResponse result = null;

        SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));

        try {
            // final ResultadoOperacionWebSemanticaVO loginOk =
            // usersService.autenticacionUsuarioProComun(getAgregaUserByEmail(email),
            // password);
            final ResultadoOperacionExternaVO loginOk = usersService.autenticacionUsuarioExterno(email, password);
            if (!loginOk.getCodigoResultado().equals("0")) {
                result = generateNOKResponse(loginOk);
            } else {
                result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, loginOk.getMensaje() + email);
            }

            Utils.logInfo(LOG, "Exiting login user ODE Service {0}", loginOk.getCodigoResultado().equals("0") ? "OK" : "NOK");
        } catch (RemoteException e) {
            Utils.logError(LOG, "User could not be logged in Agrega: " + e.getMessage());
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }

        return result;
    }

    /**
     * Try to delete user from Agrega 
     * @param email Email of the user to delete
     * @param password Password of the user
     * @return Response OK/NOK with the result of the operation
     */
    public static ServiceResponse deleteUser(String email, String password) {
        Utils.logInfo(LOG, "Entering delete user ODE Service");
        ServiceResponse result = null;

        SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));

        UsuarioVO user;
        try {
            user = getAgregaUserFullByEmail(email);
            if (user == null) {
                return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User not found in LDAP");
            }

            // ResultadoOperacionWebSemanticaVO bajaResult =
            // usersService.bajaUsuarioProComun(user.getUsuario(), password);
            ResultadoOperacionExternaVO bajaResult = usersService.bajaUsuarioExterno(email, password);
            if (bajaResult != null && bajaResult.getCodigoResultado().equals("0")) {
                result = new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "Usuario dado de baja correctamente");
            } else {
                result = generateNOKResponse(new ResultadoOperacionExternaVO(bajaResult.getCodigoResultado(), "No se ha dado de baja correctamene al usuario"));
            }

        } catch (RemoteException e) {
            Utils.logError(LOG, "User could not be deleted from Agrega: " + e.getMessage());
            result = new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }

        Utils.logInfo(LOG, "Exiting delete user ODE Service");
        return result;
    }

    /**
     * Try to check NIF, user and mail in Agrega 
     * @param nif Email of the user to delete
     * @param userName Email of the user to delete
     * @param email Email of the user to delete
     * @return Response OK/NOK with the result of the operation
     */
    public static ServiceResponse checkFieldsUser(String nif, String userName, String email) {
        Utils.logInfo(LOG, "Entering check fields user ODE Service");

        SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));

        try {
            if (!Utils.isEmpty(nif)) {
                ResultadoOperacionExternaVO usedNif = usersService.validarCampoUsuarioExterno("documentoIdentidad", nif);
                if (!usedNif.getCodigoResultado().equals("0")) {
                    return generateNOKResponse(usedNif);
                }
            }

            if (!Utils.isEmpty(userName)) {
                ResultadoOperacionExternaVO validUser = usersService.validarCampoUsuarioExterno("identificador", userName);
                if (!validUser.getCodigoResultado().equals("0")) {
                    return generateNOKResponse(validUser);
                }
            }
            if (!Utils.isEmpty(email)) {
                ResultadoOperacionExternaVO usedMail = usersService.validarCampoUsuarioExterno("email", email);
                if (!usedMail.getCodigoResultado().equals("0")) {
                    return generateNOKResponse(usedMail);
                }
            }

            return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "User is valid");

        } catch (RemoteException e) {
            Utils.logError(LOG, "User could not be deleted from Agrega: {0}", e.getMessage());
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, e.getMessage());
        }

    }

    public static byte[] getScorm2004(final String mecIdentifier) throws RemoteException, IOException {
        SrvEntregarService srv = new SrvEntregarServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_DELIVER_SERVICE));
        final PaquetePifDriVO generarPaquetePIFResponse = srv.generarPaquetePIF(mecIdentifier);

        if (generarPaquetePIFResponse.getPaquetePIF() != null) {
            return IOUtils.toByteArray(generarPaquetePIFResponse.getPaquetePIF().getInputStream());
        } else {
            return null;
        }

    }

    /** Method to get href to download an ODE with format
     * @param format
     * @param mecIdentifier
     * @param language
     * @return
     */
    public static String getOdeWithFormat(final String format, final String mecIdentifier, final String language) {

        final String nodoStr = getNodoOde(mecIdentifier, language);
        final String nodo = Utils.isEmpty(nodoStr) ? Utils.getMessage(AGREGA_URL) : "http://" + nodoStr + "/";

        final SrvEntregarService srv = new SrvEntregarServiceProxy(nodo + Utils.getMessage(AGREGA_DELIVER_SERVICE));
        final TipoPifVO pifType = new TipoPifVO(mecIdentifier, format, language);

        try {
            if (format.equals(FORMAT_CONTENT_IMAGE)) {
                return null;
            } else {
                final PaquetePifVO generarPaquetePIFResponse = srv.generarPaquetePIFTipoPIF(pifType);
                final String href = generarPaquetePIFResponse.getHref();

                return !Utils.isEmpty(href) ? nodo + href : null;
            }
        } catch (RemoteException e) {
            Utils.logError(LOG, e, "Cannot obtain 'PaquetePif' {0}, {1}", format, mecIdentifier);
            return null;
        }

    }

    /** Method to get href to download an ODE with IMAGE format
     * @param mecIdentifier
     * @param language
     * @return
     */
    public static String getOdeWithImageFormat(final String mecIdentifier, final String language) {
        final String nodoStr = getNodoOde(mecIdentifier, language);
        final String nodo = Utils.isEmpty(nodoStr) ? Utils.getMessage(AGREGA_URL) : "http://" + nodoStr + "/";
        try {
            final SrvEntregarService srv = new SrvEntregarServiceProxy(nodo + Utils.getMessage(AGREGA_DELIVER_SERVICE));
            final DataHandler paquetePIF = srv.devolverPaquetePIFOImagen(mecIdentifier, true).getPaquetePIF();
            final InputStream inputStream = paquetePIF.getInputStream();

            StringBuilder sb = new StringBuilder();
            final byte[] byteArrayB64 = IOUtils.toByteArray(inputStream);
            // final String b64content = Arrays.toString(byteArrayB64);
            sb.append("data:").append(paquetePIF.getContentType()).append(";base64,").append(Base64.encodeBase64String(byteArrayB64));

            return sb.toString();
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot obtain 'PaquetePif' IMAGE {0}", mecIdentifier);
            return null;
        }
    }

    /** Method to obtain Pif Types from Agrega WS
     * @return
     */
    public static List<String> getPifTypes(final String mecIdentifier) {
        final SrvEntregarService srv = new SrvEntregarServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_DELIVER_SERVICE));

        List<String> types = new ArrayList<String>();

        try {
            types.addAll(Arrays.asList(srv.obtenerTiposPIF()));
        } catch (RemoteException e) {
            Utils.logError(LOG, e, "Cannot obtain 'TiposPif'");
            return null;
        }

        try {

            if (!Utils.isEmpty(types) && !types.contains(FORMAT_CONTENT_IMAGE) && srv.odeConRecursoDirectamenteDescargable(mecIdentifier)) {
                types.add(FORMAT_CONTENT_IMAGE);
            }
        } catch (RemoteException e) {
            Utils.logWarn(LOG, e, "Cannot invoke 'odeConRecursoDirectamenteDescargable'");
        }

        return types;
    }

    public static boolean checkDeletePermission(final String mecId, final String userId) {
        boolean result = false;
        final String odeNode = (String) SolrSupport.getSolrFieldByMECId(mecId, "odeNode");
        final List<String> odeEditors = getOdeEditors(mecId);
        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByUser(odeEditors.get(0));
        final String email = agregaUser.getEmail();
        if (!Utils.isEmpty(agregaUser) && email.equals((userId))) {
            result = true;
        }
        return result;

    }

    public static List<String> getOdeEditors(final String mecId) {
        final SrvPublicacionService publicationService = new SrvPublicacionServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_PUBLICATION_SERVICE));

        List<String> result = null;
        String[] editores;
        try {
            editores = publicationService.obtenerEditoresOdeExterno(mecId);
            if (!Utils.isEmpty(editores)) {
                result = Arrays.asList(editores);
            } else {
                Utils.logWarn(LOG, "Cannot invoke 'obtenerEditoresOdeWebSemantica'");
            }
        } catch (RemoteException e) {
            Utils.logError(LOG, e);
        }
        return result;
    }

    public static UsuarioVO getAgregaUserByUser(final String agregaUser) {
        UsuarioVO usuario = null;
        final SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));
        try {
            usuario = usersService.obtenerDatosUsuario(agregaUser);
        } catch (RemoteException e) {
            Utils.logError(LOG, "Cannot obtain user data {0}", agregaUser);
        }

        return usuario;
    }

    public static String getOdeLanguage(final String mecId) throws RemoteException {
        final SrvPublicacionService publicationService = new SrvPublicacionServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_PUBLICATION_SERVICE));

        String result = "x-none";
        final OdePublicadoVO odePublicado = publicationService.obtenODEPublicado(mecId);
        if (!Utils.isEmpty(odePublicado) && !Utils.isEmpty(odePublicado.getIdioma())) {
            result = odePublicado.getIdioma();
        } else {
            throw new RemoteException();
        }
        return result;
    }

    public static boolean deleteOde(final String mecId, final String userId) {
        final SrvPublicacionService publicationService = new SrvPublicacionServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_PUBLICATION_SERVICE));

        boolean result = false;
        try {
            final ResultadoOperacionVO despublicarWebSemanticaRes = publicationService.despublicacionExterna(mecId, userId);
            final String idResultado = despublicarWebSemanticaRes.getIdResultado();
            final String descripcion = despublicarWebSemanticaRes.getDescripcion();
            if (idResultado.equals(DEL_ODE_OK_RES) && descripcion.equals(DEL_ODE_OK_DESC)) {
                result = true;
            }
        } catch (RemoteException e) {
            Utils.logWarn(LOG, e, "Cannot invoke 'obtenerEditoresOdeWebSemantica'");
        }
        return result;

    }

    /** Metho to generate JSON reposnse with NOK message from Agrega WS NOK response.
     * @param result Agrega WS NOK response
     * @return JSON NOK response
     */
    private static ServiceResponse generateNOKResponse(final ResultadoOperacionExternaVO result) {
        return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_GATEWAY, result.getCodigoResultado() + result.getMensaje());
    }

    /** Method to get user name, Agrega, from user email.
     * @param email User email.
     * @return String with user name on Agrega.
     */
    public static String getAgregaUserByEmail(final String email) {
        String user = null;

        final UsuarioVO agregaUser = getAgregaUserFullByEmail(email);
        if (agregaUser != null) {
            user = agregaUser.getUsuario();
        }

        return user;
    }

    /** Method to get Agrega User from user email.
     * @param email User email.
     * @return UsuarioVO, User in Agrega.
     */
    public static UsuarioVO getAgregaUserFullByEmail(final String email) {
        final SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));
        UsuarioVO agregaUser = null;

        try {
            Utils.logInfo(LOG, "Entering Agrega WS 'obtenerDatosUsuarioPorEmail'.");
            agregaUser = usersService.obtenerDatosUsuarioPorEmail(email);
            Utils.logInfo(LOG, "Recieved response from Agrega WS 'obtenerDatosUsuarioPorEmail'.");
        } catch (RemoteException e) {
            Utils.logError(LOG, e, "RemoteException: Cannot obtain Full User form email {0}", email);
        }

        return agregaUser;
    }

    /** Check if User exists in Agrega.
     * @param user User to check
     * @return true if exists, false in other case
     */
    public static boolean existsUser(final UsuarioVO user) {
        final SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));
        Boolean exists = false;
        try {
            Utils.logInfo(LOG, "Entering Agrega WS 'existeUsuario'.");
            exists = usersService.existeUsuario(user.getUsuario());
            Utils.logInfo(LOG, "Recieved response from Agrega WS 'existeUsuario'.");
        } catch (RemoteException e) {
            Utils.logError(LOG, e, "RemoteException: Cannot check if user {0} exists", user.getUsuario());
        }

        return exists;
    }

    /** Check if User is active in Agrega
     * @param user User to check        
     * @return true if exists, false in other case
     */
    public static boolean isActiveUser(final UsuarioVO user) {
        final SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));
        Boolean isActive = false;
        try {
            Utils.logInfo(LOG, "Entering Agrega WS 'estaActivo'.");
            isActive = usersService.estaActivo(user.getUsuario());
            Utils.logInfo(LOG, "Recieved response from Agrega WS 'estaActivo'.");
        } catch (RemoteException e) {
            Utils.logError(LOG, e, "RemoteException: Cannot check if user {0} is active", user.getUsuario());
        }

        return isActive;
    }

    /** ACtivate User in Agrega
     * @param user User to activate        
     * @return true if User can be activated, false in other case
     */
    public static boolean activateUser(final UsuarioVO user) {
        final SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));
        Boolean activated = true;
        try {
            // TODO check first param in Agrega docs
            Utils.logInfo(LOG, "Entering Agrega WS 'activarUsuario'.");
            usersService.activarUsuario(1L, user.getUsuario());
            Utils.logInfo(LOG, "Recieved response from Agrega WS 'activarUsuario'.");
        } catch (RemoteException e) {
            Utils.logError(LOG, e, "RemoteException: Cannot check if user {0} is active", user.getUsuario());
            activated = false;
        }

        return activated;
    }

    public static UsuarioVO getAgregaUserByMecId(final String mecIdentifier) {
        UsuarioVO agregaUser = null;
        final List<String> odeEditors = getOdeEditors(mecIdentifier);
        if (!Utils.isEmpty(odeEditors)) {
            agregaUser = getAgregaUserByUser(odeEditors.get(0));
        }
        return agregaUser;
    }

    /** Method to obtain ODEs publicator by its mecIdentifier
     * @param mecIdentifier
     * @return String with Odes author email
     */
    public static String getPublicator(final UsuarioVO agregaUser, final String odeNode) {
        if (agregaUser != null) {
            return getPublicatorName(agregaUser);
        } else {
            return getPublicatorNodeAuton(odeNode);
        }
    }

    private static String getPublicatorNodeAuton(final String odeNode) {

        if (odeNode.contains("juntadeandalucia")) {
            return "Junta de Andalucía";
        } else if (odeNode.contains("hezkuntza")) {
            return "País Vasco";
        } else if (odeNode.contains("madrid")) {
            return "Madrid";
        } else if (odeNode.contains("gobiernodecanarias")) {
            return "Canarias";
        } else {
            return "";
        }
    }

    /** Method to obtain ODEs publicator by its mecIdentifier
     * @param mecIdentifier
     * @return String with Odes author email
     */
    public static String getPublicatorName(final UsuarioVO agregaUser) {

        String fullname = null;

        if (!Utils.isEmpty(agregaUser)) {
            StringBuilder strBuilder = new StringBuilder();
            final String nombre = agregaUser.getNombre();
            if (!Utils.isEmpty(nombre)) {
                strBuilder = nombre.contains("INTEF") ? strBuilder.append("INTEF") : strBuilder.append(nombre);
            }
            final String apellido1 = agregaUser.getApellido1();
            if (!Utils.isEmpty(apellido1)) {
                strBuilder = apellido1.contains("PrimerApellido") || apellido1.trim().contains(".") ? strBuilder : strBuilder.append(" ").append(apellido1);
            }
            strBuilder = (!Utils.isEmpty(agregaUser.getApellido2())) ? strBuilder.append(" ").append(agregaUser.getApellido2()) : strBuilder;
            fullname = strBuilder.toString();
        }
        return fullname;
    }

    public static String getPublicatorEmail(final String mecId, final String node) {
        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(mecId);
        return AgregaUtil.getPublicator(agregaUser, node);
    }

    public static String getPublicatorName(final String mecId) {
        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(mecId);
        return AgregaUtil.getPublicatorName(agregaUser);
    }
}
