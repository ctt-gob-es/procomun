package com.itelligent.agrega2.test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Interaccion;
import com.itelligent.agrega2.dal.RecomendadorIteracion;
import com.itelligent.agrega2.dal.TipoContenido;
import com.itelligent.agrega2.dal.TipoInteraccion;
import com.itelligent.agrega2.dal.beans.Recomendacion;

public class RunnerInteracciones {

    private static final Log LOG = LogFactory.getLog(RunnerInteracciones.class);

    public static List<Interaccion> cargaInteraccionesCSV(String srtPath, String strSeparador, int intNumeroMaximoInteracciones) {
        List<Interaccion> lstRes = new ArrayList<Interaccion>();
        int intNumIter = 0;
        BufferedReader in = null;

        Utils.logInfo(LOG, "Lectura de fichero para debug...");

        File fileInput = new File(srtPath);

        try {

            in = new BufferedReader(new InputStreamReader(new FileInputStream(fileInput)));

            // Lectura del fichero
            String linea;
            while ((linea = in.readLine()) != null && intNumIter < intNumeroMaximoInteracciones) {
                int idUser, idContenido;
                float nota;
                String tipoContenido;
                intNumIter++;
                String[] lineaPartes = linea.split(strSeparador);
                idUser = Integer.parseInt(lineaPartes[0]);
                idContenido = Integer.parseInt(lineaPartes[1]);
                nota = Float.parseFloat(lineaPartes[2]);
                tipoContenido = lineaPartes[3];
                Date d = new Date();

                lstRes.add(new Interaccion(d.getTime(), idUser, idContenido, TipoContenido.valueOf(tipoContenido), TipoInteraccion.VIEW, nota));
            }
            in.close();
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            Utils.logInfo(LOG, e.getMessage());

        } catch (IOException e) {
            // TODO Auto-generated catch block

        }

        Utils.logInfo(LOG, "\t->Contenidos creados: " + intNumIter);

        return lstRes;
    }

    public static void main(String[] args) throws Exception {
        RecomendadorIteracion recomendarInteraccioens = new RecomendadorIteracion("/Users/Mario/Documents/Itelligent/emergya/agrega2/dirRecomendador/");
        //
        // int[] arrayK = {1,2,4,8,16,32,64,128};
        //
        // recomendarInteraccioens.entrenamiento("/Users/Mario/Documents/bigdata/datasets_recomendador/ml-1m/ratings_coma.dat",
        // arrayK);

        // TODO Auto-generated method stub
        List<Interaccion> lstInteracciones = cargaInteraccionesCSV("/Users/Mario/Documents/bigdata/datasets_recomendador/mahout_in_action_preferences.txt", ",", 1000000000);
        Utils.logInfo(LOG, "Interaccioens cargadas " + lstInteracciones.size());

        recomendarInteraccioens.AnadirInteracciones(lstInteracciones);
        List<Recomendacion> lstRecomendaciones = recomendarInteraccioens.recomendar(1, 0, 10, TipoContenido.ODE, 1);
        Utils.logInfo(LOG, "-----------------------------------------------------------------");
        Utils.logInfo(LOG, "Numero de interaccioens para el usuario " + recomendarInteraccioens.getNumeroInteraccionesUsuario(0));
        for (Recomendacion recomendacion : lstRecomendaciones) {
            Utils.logInfo(LOG, recomendacion.getId());// + " -> " +
                                                      // recomendacion.getScore());
        }

        // Segunda tanda de interacciones
        // List<Interaccion> lstInteracciones2 =
        // cargaInteraccionesCSV("/Users/Mario/Documents/bigdata/datasets_recomendador/mini_test
        // copia.txt",
        // ",", 100);
        // Utils.logInfo(LOG, "Interaccioens cargadas " +
        // lstInteracciones2.size() );
        // recomendarInteraccioens.AnadirInteracciones(lstInteracciones2);
        // lstRecomendaciones = recomendarInteraccioens.recomendar(1, -1, -1);
        // Utils.logInfo(LOG,
        // "-----------------------------------------------------------------");
        // for (Recomendacion recomendacion : lstRecomendaciones) {
        // Utils.logInfo(LOG, recomendacion.getId() + " -> " +
        // recomendacion.getScore());
        // }
    }

}
