package com.emergya.agrega2.arranger.solr.test;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import java.io.IOException;

import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.test.utils.DataFactory;

public class SolrInjectionTest {

    final User user = new User();
    String serverUrl;
    HttpSolrServer server;

    @Before
    public void doPing() {
        serverUrl = SolrSupport.getServerURL(true);
        server = new HttpSolrServer(serverUrl);

        try {
            assertTrue("User ping OK! ", server.ping().getStatus() == 0);
        } catch (SolrServerException e) {
            fail("SolrServerException on Ping!");
        } catch (IOException e) {
            fail("IOException on Ping!");
        }
    }

    @Test
    public void injectUser() {
        user.setUserBirthDate(DataFactory.getRandomDate());
        user.setUserCountry("España");
        user.setDescription(DataFactory.getRandomString(150));
        user.setUserDni(DataFactory.getDni());
        user.setUserEducativeCenter(DataFactory.getRandomString(20));
        user.setUserEducativeCenterUrl(DataFactory.getRandomString(25));
        user.setId(user.getUserDni());
        user.setUserLocality(DataFactory.getProvincia());
        user.setUserName(DataFactory.getNombre());
        user.setUserProvince(user.getUserLocality());
        user.setUserSurName(DataFactory.getApellido());
        user.setTitle(DataFactory.getRandomString(25));

        assertTrue("User injection OK!", SolrSupport.injectDocument(user));
    }

    @After
    public void deleteUserInserted() {
        assertTrue("User deletion OK!", SolrSupport.deleteDocumentById(user.getId(), null));
    }

}
