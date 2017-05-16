package com.emergya.agrega2.odes.test;

import org.junit.After;
import org.junit.Assert;
import org.junit.Before;

import com.emergya.agrega2.arranger.controller.AdminUsersService;
import com.emergya.agrega2.arranger.controller.impl.AdminUsersServiceController;
import com.emergya.agrega2.arranger.model.entity.json.EmailPasswordJson;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.json.UserEditJson;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.util.AgregaUtil;

public class UserServicesTest {

    private final String TEST_PASSWORD = "123456$$654321";
    private final String TEST_PASSWORD_EDIT = "654321$$123456";

    private final String id = String.valueOf(Utils.getCurrentMillis());

    private boolean userEdited;

    private User user;

    final AdminUsersService userService = new AdminUsersServiceController();

    private User initUser() {
        User user = new User();
        user.setId(id);
        user.setUserName("15806703E");
        user.setUserSurName("Ejemplo Emergya 15806703E");
        user.setUserMail("15806703E@emergya.com");
        user.setUserDni("15806703E");
        user.setUserLogin("15806703E");
        user.setUserPassword(TEST_PASSWORD);

        return user;
    }

    private UserEditJson editUser() {
        User user = initUser();
        UserEditJson userEdit = new UserEditJson();
        Utils.copyProperties(user, userEdit);
        // userEdit = (UserEditJson) user;
        userEdit.setUserName("TestUserEmergya1");
        userEdit.setUserDni("63652030J");
        userEdit.setUserSurName("Ejemplo Usuario Emergya");
        userEdit.setUserPassword(TEST_PASSWORD_EDIT);
        userEdit.setOldMail("");
        userEdit.setOldPassword("true");

        return userEdit;
    }

    @Before
    public void init() {
        user = initUser();
        final ServiceResponse addUserResponse = userService.addUser(user);
        Assert.assertNotNull(addUserResponse);
        Assert.assertEquals(ResponseCode.OK, addUserResponse.getResponseCode());

        final ServiceResponse activateUserReponse = userService.activateUser(new EmailPasswordJson(user.getUserMail(), user.getUserPassword()));
        Assert.assertNotNull(activateUserReponse);
        Assert.assertEquals(ResponseCode.OK, activateUserReponse.getResponseCode());
    }

    // @Test
    public void testUserCompleteCycle() {
        userEdited = false;

        // // Check user
        ServiceResponse response = userService.checkUser(user);

        Assert.assertNotNull(response);
        Assert.assertEquals(ResponseCode.OK, response.getResponseCode());

        // // Add user
        ServiceResponse responseAdd = userService.addUser(user);

        Assert.assertNotNull(responseAdd);
        Assert.assertEquals(ResponseCode.OK, responseAdd.getResponseCode());

        EmailPasswordJson emPass = new EmailPasswordJson();
        emPass.setId(responseAdd.getDocumentId());

        // Login OK
        // Volvemos a poner la contraseña original, que se ha cambiado al
        // inyectarlo en Solr
        user = initUser();
        user.setId(responseAdd.getDocumentId());

        emPass.setEmail(user.getUserMail());
        emPass.setPassword(user.getUserPassword());

        ServiceResponse responseLogin = userService.loginUser(emPass);

        Assert.assertNotNull(responseLogin);
        Assert.assertEquals(ResponseCode.OK, responseLogin.getResponseCode());

        // Edit User
        UserEditJson userEdit = editUser();

        ServiceResponse responseEdit = userService.editUser(userEdit);

        Assert.assertNotNull(responseEdit);
        Assert.assertEquals(ResponseCode.OK, responseEdit.getResponseCode());

        userEdited = true;

        // Login OK
        // Volvemos a poner la contraseña original, que se ha cambiado al
        // inyectarlo en Solr
        userEdit = editUser();

        emPass.setEmail(userEdit.getUserMail());
        emPass.setPassword(userEdit.getUserPassword());

        ServiceResponse responseLogin2 = userService.loginUser(emPass);

        Assert.assertNotNull(responseLogin2);
        Assert.assertEquals(ResponseCode.OK, responseLogin2.getResponseCode());
    }

    @After
    public void deleteUser() {
        EmailPasswordJson emPass = new EmailPasswordJson();
        if (userEdited) {
            UserEditJson userEdit = editUser();
            emPass.setId(userEdit.getId());
            emPass.setEmail(userEdit.getUserMail());
            emPass.setPassword(userEdit.getUserPassword());
        } else {
            User user = initUser();
            emPass.setId(user.getId());
            emPass.setEmail(user.getUserMail());
            emPass.setPassword(user.getUserPassword());
        }

        ServiceResponse deleteUserResponse = AgregaUtil.deleteUser(emPass.getEmail(), emPass.getPassword());
        Assert.assertNotNull(deleteUserResponse);
        Assert.assertEquals(ResponseCode.OK, deleteUserResponse.getResponseCode());

        if (deleteUserResponse.getResponseCode().equals(ResponseCode.OK)) {
            Assert.assertEquals(true, SolrSupport.deleteDocumentById(id, null));
        } else {

        }

    }

    // public static void main(String[] args) {
    // String email = "testuser@emergya.com";
    // String nif = "63652030J";
    // // String password = "123456$$654321";
    // String password = "654321$$123456";
    //
    // SrvAdminUsuariosService usersService = new
    // SrvAdminUsuariosServiceProxy();
    // UsuarioVO user = null;
    // try {
    // ServiceResponse response = AgregaUtil.checkFieldsUser(nif, null, email);
    // System.out.println(response.getMessage());
    //
    // user = usersService.obtenerDatosUsuarioWebSemantica(email);
    // System.out.println(user.getEmail());
    //
    // // System.out.println(usersService.bajaUsuarioWebSemantica(email,
    // password));
    // ValidaBajaUsuarioVO baja = usersService.bajaUsuario(new Long[] { new
    // Long(user.getId()) });
    // System.out.println(baja.getNumDeleted() +
    // baja.getItemsDeleted()[0].getEmail());
    // // user.setFechaDesactivacion(null);
    // // user.setClave(Utils.md5("4321"));
    // // boolean res = usersService.modificarUsuarioWebSemantica(user,
    // Utils.md5("1234"));
    // // System.out.println(res);
    // } catch (RemoteException e) {
    // // TODO Auto-generated catch block
    // e.printStackTrace();
    // }
    //
    // ServiceResponse response = AgregaUtil.login(email, Utils.md5(password));
    // System.out.println(response.getMessage());
    //
    // response = AgregaUtil.deleteUser(email, Utils.md5(password));
    // System.out.println(response.getMessage());
    // }
}
