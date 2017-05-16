package com.itelligent.agrega2.test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.mahout.cf.taste.impl.common.FastIDSet;

import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Contenido;
import com.itelligent.agrega2.dal.RecomendadorContenido;
import com.itelligent.agrega2.dal.TipoContenido;
import com.itelligent.agrega2.dal.beans.Recomendacion;

public class Runner {

    private static final Log LOG = LogFactory.getLog(Runner.class);

    private static RecomendadorContenido recomendadorContenidos;

    private static List<Contenido> cargaDebug(String strPath) {

        List<Contenido> lstRes = new ArrayList<Contenido>();
        int intNumFile = 1;
        BufferedReader in = null;

        Utils.logInfo(LOG, "Lectura de ficheros para debug...");
        File dir = new File(strPath);

        File[] files = dir.listFiles(new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return name.toLowerCase().endsWith(".txt");
            }
        });
        Utils.logInfo(LOG, "\t->Número de ficheros leidos: " + files.length);

        for (File file : files) {
            String fileContent = "";

            try {

                in = new BufferedReader(new InputStreamReader(new FileInputStream(file), "8859_1"));

                // Lectura del fichero
                String linea;
                while ((linea = in.readLine()) != null)
                    fileContent += linea;
                in.close();
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                fileContent = "";
            } catch (IOException e) {
                // TODO Auto-generated catch block
                fileContent = "";
            }

            if (fileContent != "") {
                if (intNumFile == 11250) {
                    lstRes.add(new Contenido(intNumFile, file.getName(), fileContent, TipoContenido.COMMUNITY));
                } else {
                    lstRes.add(new Contenido(intNumFile, file.getName(), fileContent, TipoContenido.ODE));
                }
            }

            intNumFile++;
        }

        Utils.logInfo(LOG, "\t->Contenidos creados: " + lstRes.size());

        return lstRes;

    }

    public static void testTiempoCracionIndice(List<Contenido> lstContenidos,
            RecomendadorContenido recomendadorContenidos, String salidaCSV) throws Exception {
        // Creación del fichero
        BufferedWriter bw = new BufferedWriter(new FileWriter(salidaCSV));

        bw.write("Tamaño muestra;Tiempo\n");
        for (int i = 1000; i < lstContenidos.size(); i += 1000) {
            List<Contenido> lstMedicion = lstContenidos.subList(0, i);

            long tiempoInicio = System.currentTimeMillis();
            recomendadorContenidos.AddContenido(lstMedicion);
            long totalTiempo = System.currentTimeMillis() - tiempoInicio;
            totalTiempo = totalTiempo / 1000;
            bw.write(i + ";" + totalTiempo + "\n");
            Utils.logInfo(LOG, i + ";" + totalTiempo);
        }
        bw.close();
    }

    public static void testTiempoRecomendacion(RecomendadorContenido recomendadorContenidos, int intIncemento,
            int intMax, String salidaCSV) throws Exception {
        // Creación del fichero
        BufferedWriter bw = new BufferedWriter(new FileWriter(salidaCSV));

        bw.write("Numero recomendacioens;Tiempo\n");
        for (int i = 1; i < intMax; i += intIncemento) {
            long tiempoInicio = System.currentTimeMillis();
            // recomendadorContenidos.recomendar("10", i, 0);
            long totalTiempo = System.currentTimeMillis() - tiempoInicio;
            totalTiempo = totalTiempo;
            bw.write(i + ";" + totalTiempo + "\n");
            Utils.logInfo(LOG, i + ";" + totalTiempo);
        }
        bw.close();
    }

    /**
     * @param args
     * @throws Exception
     */
    public static void main(String[] args) throws Exception {

        Utils.logInfo(LOG, "TESTING");
        recomendadorContenidos = new RecomendadorContenido(
                "/Users/Mario/Documents/Itelligent/emergya/agrega2/dirRecomendador/");

        // Carga de contenidos para debug, se carga desde textos.
        List<Contenido> lstContenidos = cargaDebug("/Users/Mario/Documents/Itelligent/emergya/textos_prueba");

        // Medición de tiempos de creacion
        // testTiempoCracionIndice(lstContenidos,
        // recomendadorContenidos,"tiempos_add.csv");

        // Añado al recomendador
        recomendadorContenidos.AddContenido(lstContenidos);

        // Solicito ecomendacion

        List<Recomendacion> lstRecomendaciones = recomendadorContenidos.recomendar("2", (float) 0, 10,
                TipoContenido.ODE, new FastIDSet());

        for (Recomendacion recomendacion : lstRecomendaciones) {
            Utils.logInfo(LOG, recomendacion.toString());
        }

        // testTiempoRecomendacion(recomendadorContenidos, 100, 20000,
        // "timeposRecomendacion2000doc.csv");

    }

}
