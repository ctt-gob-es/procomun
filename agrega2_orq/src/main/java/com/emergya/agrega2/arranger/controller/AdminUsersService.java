package com.emergya.agrega2.arranger.controller;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.model.entity.json.EmailPasswordJson;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.UserEditJson;
import com.emergya.agrega2.arranger.model.entity.json.UserOde;
import com.emergya.agrega2.arranger.model.entity.solr.User;

/**
 * Ping Service to check if Arranger is up.
 */
@Controller
public interface AdminUsersService {

    /**
     * Add an User in Agrega. Required fields are: name, surname, password, mail and DNI, and mail cannot be an alias (containig '+' symbol)
     * @param user {@link User} from Drupal 
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/add" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse addUser(@RequestBody final User user);

    /**
     * Add User information only in Solr
     * @param user {@link User} from Drupal 
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/addSolr" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse addSolrUser(@RequestBody final User user);

    /**
     * Update User information only in Solr
     * @param user {@link User} from Drupal 
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/updateSolr" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse updateSolrUser(@RequestBody final User user);

    /**
     * Activate an User in Agrega.
     * @param email Email of the user to activate 
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/activate" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse activateUser(@RequestBody final EmailPasswordJson email);

    /**
     * Edit an User in Agrega (name, surname, login). If email/password has changed, the oldMail/oldPassword parameters are required
     * @param user {@link User} from Drupal
     * @param oldMail Old mail of the user, if new email is provided
     * @param oldPassword Old password of the user, if new password is provided
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/edit" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse editUser(@RequestBody final UserEditJson user);

    /**
     * Try to authenticate against Agrega 
     * @param email Email of the user to authenticate
     * @param password Password of the user
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/login" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse loginUser(@RequestBody EmailPasswordJson emailPassword);

    /**
     * Try to delete user from Agrega 
     * @param email Email of the user to delete
     * @param password Password of the user
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/delete" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse deleteUser(@RequestBody EmailPasswordJson emailPassword);

    /**
     * Check in Agrega if email, userName and password are available
     * @param user User to check
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/check" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse checkUser(@RequestBody User user);

    /**
     * Check if an User can delete an Ode
     * @param User id (email)
     * @param Ode's MEC ID
     * @return Response OK/NOK with the result of the operation
     */
    @RequestMapping(value = { "/adminUsers/checkDelete" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse checkDeleteOdeUser(@RequestBody UserOde userOde);

    @RequestMapping(value = { "/adminUsers/deleteOde" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse deleteOde(@RequestBody UserOde userOde);

    @RequestMapping(value = { "/adminUsers/getNameByUser" }, method = RequestMethod.GET, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse getAgregaUserName(@RequestParam("userName") final String userName, final HttpServletRequest request);

    /** Check if User exists and is activated in Agrega. If is not activated, try to activate it.
     * @param email User's email
     * @param request HTTP Request
     * @return HTTP 200 if exists and is activated, 500 in other case.
     */
    @RequestMapping(value = { "/adminUsers/checkUserInAgrega" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse checkUserInAgrega(@RequestBody EmailPasswordJson emailPass);

    @RequestMapping(value = { "/adminUsers/updateRegional" }, method = RequestMethod.POST, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse updateRegional(@RequestBody final UserEditJson user);

}
