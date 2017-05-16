package com.emergya.agrega2.arranger.controller.test;

import static junit.framework.TestCase.assertEquals;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.junit.Assert;
import org.junit.Before;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.mock.web.MockHttpServletRequest;
import org.springframework.security.crypto.codec.Base64;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.RestTemplate;

import com.emergya.agrega2.arranger.controller.PingService;
import com.emergya.agrega2.arranger.controller.impl.PingServiceController;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.util.impl.Utils;

public class HelloTest {

    private static final Log LOG = LogFactory.getLog(HelloTest.class);

    private String helloUrl = "";

    @Before
    public void init() {
        helloUrl = Utils.getMessage("APP_URL") + "rest/hello/";
    }

    static HttpHeaders getHeaders(String auth) {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        // headers.setAccept(Arrays.asList(MediaType.APPLICATION_JSON));

        if (auth != null) {
            byte[] encodedAuthorisation = Base64.encode(auth.getBytes());
            headers.add("Authorization", "Basic " + new String(encodedAuthorisation));
        }

        return headers;
    }

    private String getResponse(String user, String password, String restUrl) {
        String auth = null;
        if (user != null && password != null)
            auth = user + ":" + password;
        HttpEntity<String> requestEntity = new HttpEntity<String>(null, getHeaders(auth));

        RestTemplate template = new RestTemplate();

        ResponseEntity<String> entity = template.exchange(helloUrl + restUrl, HttpMethod.GET, requestEntity,
                String.class);

        String hello = entity.getBody();

        // Utils.logInfo(LOG, "The response is \"" + hello + "\"");

        return hello;
    }

    // @Test
    public void thatSaysHello() {
        String hello = getResponse("test_user", "user", "TEST");

        assertEquals("Hello TEST", hello);
    }

    // @Test
    public void thatSaysHelloBadPass() {
        try {
            String hello = getResponse("test_user", "BADPASSWORD", "TEST");

            Assert.fail("Wrong password! Response: " + hello);

        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.UNAUTHORIZED, ex.getStatusCode());
        }

    }

    // @Test
    public void thatSaysHelloBadUser() {
        try {
            String hello = getResponse("test_wrong", "WRONG", "TEST");

            Assert.fail("Wrong user! Response: " + hello);

        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.UNAUTHORIZED, ex.getStatusCode());
        }
    }

    // @Test
    public void thatSaysHelloBadRole() {
        try {
            String hello = getResponse("test_role", "role", "TEST");

            Assert.fail("Wrong role! Response: " + hello);

        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.FORBIDDEN, ex.getStatusCode());
        }

    }

    // @Test
    public void thatSaysHelloBadAdminRole() {
        try {
            String hello = getResponse("test_user", "user", "admin/TEST");

            Assert.fail("Wrong admin role! Response: " + hello);

        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.FORBIDDEN, ex.getStatusCode());
        }

    }

    // @Test
    public void thatSaysHelloNoUser() {
        try {
            String hello = getResponse(null, null, "TEST");

            // Utils.logInfo(LOG, "The response is \"" + hello + "\"");

            Assert.fail("No user! Response: " + hello);

        } catch (HttpClientErrorException ex) {
            assertEquals(HttpStatus.UNAUTHORIZED, ex.getStatusCode());
        }

    }

    // @Test
    public void thatSaysHelloAdmin() {
        String hello = getResponse("test_admin", "admin", "TEST");

        // Utils.logInfo(LOG, "The response is \"" + hello + "\"");

        assertEquals("Hello TEST", hello);

        hello = getResponse("test_admin", "admin", "admin/TEST");

        Utils.logInfo(LOG, "The Admin response is \"" + hello + "\"");

        assertEquals("Hello Admin TEST", hello);
    }

    // @Test
    public void doPingTest() {
        final MockHttpServletRequest request = new MockHttpServletRequest();
        final PingService pingService = new PingServiceController();

        request.setRemoteAddr("JUnit tests from arranger");
        final ServiceResponse pingResponse = pingService.ping(request);

        assertEquals("Do Ping OK!", ResponseCode.OK.equals(pingResponse.getResponseCode()), true);
    }

}
