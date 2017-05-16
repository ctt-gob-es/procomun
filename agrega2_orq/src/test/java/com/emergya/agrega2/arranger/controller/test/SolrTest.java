package com.emergya.agrega2.arranger.controller.test;

import static junit.framework.TestCase.assertEquals;

import java.util.Arrays;

import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.security.crypto.codec.Base64;
import org.springframework.web.client.HttpClientErrorException;

import com.emergya.agrega2.arranger.test.utils.TestsUtils;
import com.emergya.agrega2.arranger.util.impl.Utils;

public class SolrTest {

    private String solrUrl = "";

    // @Before
    public void init() {
        solrUrl = Utils.getMessage("APP_URL") + "rest/solr/";
    }

    static HttpHeaders getHeaders(String auth) {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_XML);
        headers.setAccept(Arrays.asList(MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML));

        if (auth != null) {
            byte[] encodedAuthorisation = Base64.encode(auth.getBytes());
            headers.add("Authorization", "Basic " + new String(encodedAuthorisation));
        }

        return headers;
    }

    // @Test
    public void thatSolrResponds() {
        String response = TestsUtils.getResponse("test_user", "user", solrUrl, "");

        boolean okResponse = response != null && !response.equals("FAIL!");

        assertEquals(true, okResponse);
    }

    public void thatSolrRespondsUser() {
        try {
            String response = TestsUtils.getResponse("test_user", "user", solrUrl, "");

            boolean okResponse = response != null && !response.equals("FAIL!");
            assertEquals(HttpStatus.FORBIDDEN, !okResponse);
        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.FORBIDDEN, ex.getStatusCode());
        }
    }

    public void thatSolrRespondsAdmin() {
        try {
            String response = TestsUtils.getResponse("test_admin", "admin", solrUrl, "");

            boolean okResponse = response != null && !response.equals("FAIL!");
            assertEquals(HttpStatus.FORBIDDEN, !okResponse);
        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.FORBIDDEN, ex.getStatusCode());
        }
    }

    public void thatSolrRespondsRole() {
        try {
            String response = TestsUtils.getResponse("test_role", "role", solrUrl, "");

            boolean okResponse = response != null && !response.equals("FAIL!");
            assertEquals(HttpStatus.FORBIDDEN, !okResponse);
        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.FORBIDDEN, ex.getStatusCode());
        }
    }

    public void thatSolrSearches() {
        String response = TestsUtils.getResponse("test_user", "user", solrUrl, "a2_lomes/select?q=*quijote*&wt=json");

        boolean okResponse = response != null && !response.equals("FAIL!");

        assertEquals(true, okResponse);
    }

}
