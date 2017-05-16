package com.itelligent.agrega2.test;

import static org.junit.Assert.assertEquals;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Collection;

import org.codehaus.jackson.JsonParseException;
import org.codehaus.jackson.map.JsonMappingException;
import org.codehaus.jackson.map.ObjectMapper;
import org.codehaus.jackson.type.TypeReference;
import org.junit.Assert;

import com.itelligent.agrega2.dal.beans.Recomendacion;

public class TestAPIRecomendadorUsuario {

    private static final int TAM = 10;

    static void conexion(String restUrl) {
        try {
            URL url = new URL("http://localhost:8080/Recomendador/rest/usuario/" + restUrl);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");
            conn.setRequestProperty("Accept", "application/json");

            int intStatus = conn.getResponseCode();

            conn.disconnect();

            assertEquals(intStatus, 200);

        } catch (MalformedURLException e) {

            Assert.fail("Error parsear url");

        } catch (IOException e) {

            Assert.fail("Error IO");
        }

    }

    static void test(String restUrl) {
        String strTodo = new String();
        try {
            URL url = new URL("http://localhost:8080/Recomendador/rest/usuario/" + restUrl);
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            conn.setRequestMethod("GET");
            conn.setRequestProperty("Accept", "application/json");
            BufferedReader br = new BufferedReader(new InputStreamReader((conn.getInputStream())));
            String strLine;

            while ((strLine = br.readLine()) != null) {
                strTodo += strLine;
            }
            conn.disconnect();

        } catch (MalformedURLException e) {

            Assert.fail("Error parsear url");

        } catch (IOException e) {

            Assert.fail("Error IO" + e.getMessage());

        }
        ObjectMapper mapper = new ObjectMapper();
        Collection<Recomendacion> recomendaciones = null;
        try {
            recomendaciones = mapper.readValue(strTodo, new TypeReference<Collection<Recomendacion>>() {
            });
        } catch (JsonParseException e) {
            Assert.fail("Error JSON sintaxis");
        } catch (JsonMappingException e) {
            Assert.fail("Error mapear JSON");
        } catch (IOException e) {
            Assert.fail("Error IO");
        }

        for (Recomendacion recomendacion : recomendaciones) {
            if (recomendacion.getId() <= 0 || recomendacion.getScore() <= 0) {
                Assert.fail("Error list");
            }
        }
        assertEquals(recomendaciones.size(), TAM);
    }

    // @Test
    public void testRecomendarUsuario() {

        conexion("");
        test("");
    }

    // @Test
    public void testRecomendarUsuarioUsuario() {
        int id_user = 123;
        conexion("user/" + id_user);
        test("user/" + id_user);
    }

}
