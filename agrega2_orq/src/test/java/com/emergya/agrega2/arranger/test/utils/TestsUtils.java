package com.emergya.agrega2.arranger.test.utils;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.Authenticator;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;

import org.apache.commons.io.IOUtils;
import org.codehaus.jackson.map.ObjectMapper;

import com.emergya.agrega2.arranger.model.entity.solr.Entity;
import com.emergya.agrega2.arranger.util.impl.BasicAuthenticator;

public class TestsUtils {

    private TestsUtils() {
    }

    public static String getResponse(String user, String password, String url, String restUrl) {
        if (user == null) {
            Authenticator.setDefault(null);
        } else {
            Authenticator.setDefault(new BasicAuthenticator(user, password));
        }

        try {
            final URL urlObject = new URL(url + restUrl);
            final URLConnection conn = urlObject.openConnection();
            final InputStream inputStream = conn.getInputStream();
            return IOUtils.toString(inputStream);
        } catch (IOException e) {
            return null;
        }
    }

    public static String getResponseByPost(String urlStr, Entity entity) {
        String responseStr = null;
        try {

            final URL url = new URL(urlStr);

            final HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("POST");
            conn.setRequestProperty("Content-Type", "application/json");
            conn.setDoOutput(true);

            final ObjectMapper mapper = new ObjectMapper();

            final DataOutputStream wr = new DataOutputStream(conn.getOutputStream());

            mapper.writeValue(wr, entity);

            wr.flush();
            wr.close();

            // int responseCode = conn.getResponseCode();

            final BufferedReader in = new BufferedReader(new InputStreamReader(conn.getInputStream()));
            final StringBuffer response = new StringBuffer();

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
            }
            in.close();

            responseStr = response.toString();

        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return responseStr;
    }

}
