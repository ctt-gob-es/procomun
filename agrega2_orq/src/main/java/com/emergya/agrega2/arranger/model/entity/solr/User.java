package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.Date;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;
import org.codehaus.jackson.map.annotate.JsonSerialize;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.json.JsonDateUserSerializer;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * This class defines a {@link SolrDocumentType} User {@link SolrDocumentA2}
 */
public class User extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = 3960032603320664768L;

    @Field
    private String userName;

    @Field
    private String userSurName;

    @Field
    private String userLogin;

    @Field
    private String userPassword;

    @Field
    private String userMail;

    @Field
    private Date userBirthDate;

    @Field
    private String userCountry;

    @Field
    private String userDni;

    @Field
    private String userProvince;

    @Field
    private String userLocality;

    @Field
    private String userEducativeCenter;

    @Field
    private String userEducativeCenterUrl;

    @Field
    private List<String> userLabels;

    @Field
    private String userPlace;

    public User() {
        super(SolrDocumentType.USER);
    }

    @Override
    public String generateId() {
        final StringBuilder sb = new StringBuilder(getType().name());
        if (!Utils.isEmpty(userDni)) {
            sb.append(userDni);
        }
        if (!Utils.isEmpty(getIdDrupal())) {
            sb.append(getIdDrupal());
        }
        if (!Utils.isEmpty(userLocality)) {
            sb.append(userLocality);
        }
        if (!Utils.isEmpty(userBirthDate)) {
            sb.append(userBirthDate);
        }
        return Utils.generateID(sb.toString());
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getUserSurName() {
        return userSurName;
    }

    public void setUserSurName(String userSurName) {
        this.userSurName = userSurName;
    }

    public String getUserNameSurname() {
        return userName + " " + userSurName;
    }

    @Field
    public void setUserNameSurname(String userNameSurname) {
        // Code not necessary. Field built in the getter
    }

    public String getUserLogin() {
        return userLogin;
    }

    public void setUserLogin(String userLogin) {
        this.userLogin = userLogin;
    }

    public String getUserPassword() {
        return userPassword;
    }

    public void setUserPassword(String userPassword) {
        this.userPassword = userPassword;
    }

    public String getUserMail() {
        return userMail;
    }

    public void setUserMail(String userMail) {
        this.userMail = userMail;
    }

    @JsonSerialize(using = JsonDateUserSerializer.class)
    public Date getUserBirthDate() {
        return userBirthDate;
    }

    public void setUserBirthDate(Date userBirthDate) {
        this.userBirthDate = userBirthDate;
    }

    public String getUserCountry() {
        return userCountry;
    }

    public void setUserCountry(String userCountry) {
        this.userCountry = userCountry;
    }

    public String getUserDni() {
        return userDni;
    }

    public void setUserDni(String userDni) {
        this.userDni = userDni;
    }

    public String getUserProvince() {
        return userProvince;
    }

    public void setUserProvince(String userProvince) {
        this.userProvince = userProvince;
    }

    public String getUserLocality() {
        return userLocality;
    }

    public void setUserLocality(String userLocality) {
        this.userLocality = userLocality;
    }

    public String getUserEducativeCenter() {
        return userEducativeCenter;
    }

    public void setUserEducativeCenter(String userEducativeCenter) {
        this.userEducativeCenter = userEducativeCenter;
    }

    public String getUserEducativeCenterUrl() {
        return userEducativeCenterUrl;
    }

    public void setUserEducativeCenterUrl(String userEducativeCenterUrl) {
        this.userEducativeCenterUrl = userEducativeCenterUrl;
    }

    public List<String> getUserLabels() {
        return userLabels;
    }

    public void setUserLabels(List<String> userLabels) {
        this.userLabels = userLabels;
    }

    public String getUserPlace() {
        return userPlace;
    }

    public void setUserPlace(String userPlace) {
        this.userPlace = userPlace;
    }

}
