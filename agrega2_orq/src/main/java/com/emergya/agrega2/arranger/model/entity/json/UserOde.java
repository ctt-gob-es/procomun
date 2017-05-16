package com.emergya.agrega2.arranger.model.entity.json;

import com.emergya.agrega2.arranger.model.entity.solr.Entity;

public class UserOde extends Entity {

    /**
     * 
     */
    private static final long serialVersionUID = -3798337500180101805L;

    private String mecId;

    private String userId;

    public String getMecId() {
        return mecId;
    }

    public void setMecId(String mecId) {
        this.mecId = mecId;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

}
