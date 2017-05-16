package com.itelligent.agrega2.dal.beans;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;

public class RecomendacionSolrUser extends Recomendacion {

    private String userName;

    private String userSurName;

    private String userLogin;

    private SolrDocumentType type;

    public RecomendacionSolrUser() {
        super();
    }

    public RecomendacionSolrUser(final Recomendacion recom) {
        super(recom.getId(), recom.getScore());
        SolrDocumentA2 doc = (User) SolrSupport.getSolrDocumentById(String.valueOf(recom.getId()));
        userName = ((User) doc).getUserName();
        userSurName = ((User) doc).getUserSurName();
        userLogin = ((User) doc).getUserLogin();
        type = doc.getType();
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

    public String getUserLogin() {
        return userLogin;
    }

    public void setUserLogin(String userLogin) {
        this.userLogin = userLogin;
    }

    public SolrDocumentType getType() {
        return type;
    }

    public void setType(SolrDocumentType type) {
        this.type = type;
    }

}
