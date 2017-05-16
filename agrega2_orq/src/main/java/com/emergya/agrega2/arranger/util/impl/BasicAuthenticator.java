package com.emergya.agrega2.arranger.util.impl;

import java.net.Authenticator;
import java.net.PasswordAuthentication;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

public class BasicAuthenticator extends Authenticator {

    private static final Log LOG = LogFactory.getLog(BasicAuthenticator.class);

    private String userName = "";
    private String pass = "";

    public BasicAuthenticator(String userName, String pass) {
        super();
        this.userName = userName;
        this.pass = pass;
    }

    @Override
    public PasswordAuthentication getPasswordAuthentication() {
        Utils.logInfo(LOG, "Password requested on " + getRequestingHost());
        return new PasswordAuthentication(userName, pass.toCharArray());
    }

}
