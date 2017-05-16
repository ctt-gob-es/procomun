package com.emergya.agrega2.odes.test;

import java.io.IOException;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;

public class DevUtils {

    private static final Log LOG = LogFactory.getLog(DevUtils.class);

    public static void main(String[] args) {

        final String serverUrl = SolrSupport.getServerURL(true);
        // final int rep = 100;
        //
        // addUser(serverUrl, rep);

        SolrSupport.getSolrDocumentById("229da313865de41628673fd6ba91ef25");

    }

    public static void addUser(String serverUrl, int rep) {
        User user;
        final HttpSolrServer server = new HttpSolrServer(serverUrl);

        for (int i = 0; i < rep; i++) {
            user = new User();
            user.setUserBirthDate(DataFactoryUtil.getRandomDate());
            user.setUserCountry("España");
            user.setDescription(DataFactoryUtil.getRandomString(150));
            user.setUserDni(DataFactoryUtil.getDni());
            user.setUserEducativeCenter(DataFactoryUtil.getRandomString(20));
            user.setUserEducativeCenterUrl(DataFactoryUtil.getRandomString(25));
            user.setId(user.generateId());
            user.setUserLocality(DataFactoryUtil.getProvincia());
            user.setUserName(DataFactoryUtil.getNombre());
            user.setUserProvince(user.getUserLocality());
            user.setUserSurName(DataFactoryUtil.getApellido());
            user.setTitle(DataFactoryUtil.getRandomString(25));

            try {
                server.addBean(user);
                Utils.logInfo(LOG, "Added UUID: " + user.getId());
            } catch (IOException | SolrServerException e) {
                e.printStackTrace();
            }
        }
        try {
            server.commit();
        } catch (SolrServerException | IOException e) {
            e.printStackTrace();
        }
        Utils.logInfo(LOG, "END");
    }

    public static void addOde(String serverUrl, int rep) {

        Ode ode;
        final HttpSolrServer server = new HttpSolrServer(serverUrl);

        for (int i = 0; i < rep; i++) {
            ode = new Ode();
            // ode.setAuthor(DataFactoryUtil.getNombre());
            ode.setTitle(DataFactoryUtil.getRandomString(10));
            ode.setPublicationDate(DataFactoryUtil.getRandomDate());

            try {
                server.addBean(ode);
                Utils.logInfo(LOG, "Added UUID: " + ode.getId());
            } catch (IOException | SolrServerException e) {
                e.printStackTrace();
            }
        }
        try {
            server.commit();
        } catch (SolrServerException | IOException e) {
            e.printStackTrace();
        }
        Utils.logInfo(LOG, "END");
    }

}
