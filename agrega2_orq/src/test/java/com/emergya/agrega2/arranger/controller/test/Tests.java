package com.emergya.agrega2.arranger.controller.test;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

import org.apache.commons.io.IOUtils;
import org.junit.Assert;
import org.junit.Test;

import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.A2File;
import com.emergya.agrega2.odes.service.impl.OdesServiceImpl;

public class Tests {

    /**
     * @param args
     */
    public static void main(String[] args) {
        A2File a2File = new A2File();
        a2File.setFileName("ODE_AJ");

        InputStream is = null;

        try {
            is = new FileInputStream("*");

            final byte[] byteArray = IOUtils.toByteArray(is);
            a2File.setContent(byteArray);
        } catch (Exception e) {
            e.printStackTrace();
            return;
        } finally {
            try {
                if (is != null) {
                    is.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        OdesServiceImpl srvImpl = new OdesServiceImpl();
        srvImpl.publishODEFile(a2File, "*", true, null);

    }

    @Test
    public void charsetTest() {
        String catalog = "Catálogo unificado mec-red.es-ccaa de identificación de ODE";
        String message = Utils.getMessage("agrega.lomes.mec.catalog");

        Assert.assertEquals(catalog, message);
    }

}
