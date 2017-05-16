package com.emergya.agrega2.arranger.test.utils;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import com.emergya.agrega2.odes.beans.A2File;
import com.emergya.agrega2.odes.service.impl.OdesServiceImpl;

public class TestPreview {

    private static final String PATH = "*";
    private static final String PATH_PREVIEW = "*";
    private static final String PREVIEW_NAME = "vistaPreviaAgrega.png";

    public static void main(String[] args) {

        final Path path = Paths.get(PATH);
        final Path pathPreview = Paths.get(PATH_PREVIEW);

        // Creating ode
        A2File zipFile = new A2File();
        zipFile.setFileName("ode.zip");
        try {
            zipFile.setContent(Files.readAllBytes(path));
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Creating preview
        A2File preview = new A2File();
        preview.setFileName("preview.png");
        try {
            preview.setContent(Files.readAllBytes(pathPreview));
        } catch (IOException e) {
            e.printStackTrace();
        }

        OdesServiceImpl odesService = new OdesServiceImpl();
        odesService.publishODEFile(zipFile, "*", false, preview);

    }
}
