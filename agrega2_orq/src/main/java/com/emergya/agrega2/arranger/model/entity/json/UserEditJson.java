package com.emergya.agrega2.arranger.model.entity.json;

import com.emergya.agrega2.arranger.model.entity.solr.User;

public class UserEditJson extends User {
    /**
     * 
     */
    private static final long serialVersionUID = -8637601759718808567L;

    private String oldMail;
    private String oldPassword;

    public String getOldMail() {
        return oldMail;
    }

    public void setOldMail(String oldMail) {
        this.oldMail = oldMail;
    }

    public String getOldPassword() {
        return oldPassword;
    }

    public void setOldPassword(String oldPassword) {
        this.oldPassword = oldPassword;
    }

}
