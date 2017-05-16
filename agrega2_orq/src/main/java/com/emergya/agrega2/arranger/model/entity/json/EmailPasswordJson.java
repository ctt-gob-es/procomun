package com.emergya.agrega2.arranger.model.entity.json;

import com.emergya.agrega2.arranger.model.entity.solr.Entity;

public class EmailPasswordJson extends Entity {
    /**
     * 
     */
    private static final long serialVersionUID = -5108920123754037023L;

    private String email;
    private String password;

    public EmailPasswordJson() {
        super();
    }

    public EmailPasswordJson(String email, String password) {
        super();
        this.email = email;
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
