package com.itelligent.agrega2.dal;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.mahout.cf.taste.impl.common.FastIDSet;
import org.apache.solr.client.solrj.SolrQuery;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.apache.solr.common.SolrDocument;
import org.apache.solr.common.SolrDocumentList;
import org.codehaus.jackson.JsonNode;
import org.codehaus.jackson.JsonProcessingException;
import org.codehaus.jackson.map.ObjectMapper;
import org.springframework.stereotype.Component;

import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.beans.Recomendacion;

/**
 * Clase estatica que se lanza al iniciar el servidor.
 * 
 */
@Component
public class Decisor implements ServletContextListener {

    private static final Log LOG = LogFactory.getLog(Decisor.class);

    private static final int INT_TAM_LOTE = 1000;

    // count lleva la cuenta del numero de veces que se han ejecutado los
    // WebServices RecomendarContenido y RecomendarUsuario.
    private static int count = 0;
    private static String strPath = "/tmp/recommender/";
    private static RecomendadorIteracion recomedadorIteracion;
    private static RecomendadorContenido recomendadorContenido;

    static {
        // Setting default RMI timeout
        try {
            System.setProperty("sun.rmi.transport.tcp.responseTimeout", Utils.getMessage("rmi.timeout"));
        } catch (Exception e) {
            Utils.logError(LOG, "Cannot set custom TimeOut");
        }

        String tmpPath = Utils.getMessage("arranger.recommender.temppath");
        strPath = !Utils.isEmpty(tmpPath) ? tmpPath : strPath;

        try {
            recomendadorContenido = new RecomendadorContenido(strPath);
            recomedadorIteracion = new RecomendadorIteracion(strPath);
        } catch (Exception e) {
            Utils.logError(LOG, e, "Error initializing Recommender");
        }
    }

    /**
     * Metodo que se lanza al iniciar el servidor
     */
    @Override
    public void contextInitialized(ServletContextEvent arg0) {
        File carpetaFuente = new File(strPath);

        if (!carpetaFuente.exists()) {
            carpetaFuente.mkdirs();
        }
    }

    /**
     * Metodo que se lanza al detener el servidor
     */
    @Override
    public void contextDestroyed(ServletContextEvent arg0) {
        Utils.logInfo(LOG, "ServletContextListener destroyed");
    }

    /**
     * Metodo encargado de leer las nuevas interacciones
     * 
     * @return Lis<Interacciones> Lista con las nuevas interacciones
     * @throws Exception
     */
    private static List<Interaccion> leerInteraccionesNuevas() throws Exception {
        Utils.logInfo(LOG, "Reading new interactions...");
        List<Interaccion> lstInteracciones = new ArrayList<>();
        String strResWs = "", strUrlPeticion;
        long dtmMaxInteraccion = recomedadorIteracion.getDtmMax() + 1;

        strUrlPeticion = Utils.getMessage("arranger.drupal.endpoint") + Utils.getMessage("arranger.recommender.interactions.endpoint") + dtmMaxInteraccion + "/1000.json";

        try {
            final String user = Utils.getMessage("arranger.drupal.endpoint.user");
            final String pass = Utils.getMessage("arranger.drupal.endpoint.pass");
            if (!Utils.isEmpty(user) && !Utils.isEmpty(pass)) {
                strResWs = Utils.getURLContent(new URL(strUrlPeticion), null, user, pass);
            } else {
                strResWs = Utils.getURLContent(new URL(strUrlPeticion), null, null, null);
            }

            // Mapeamos
            ObjectMapper mapper = new ObjectMapper();
            // Creamos el árrbol de nodos
            JsonNode rootNode = null;

            rootNode = mapper.readTree(strResWs);
            for (int i = 0; i < rootNode.size(); ++i) {
                lstInteracciones.add(new Interaccion(rootNode.get(i)));
            }

        } catch (JsonProcessingException e) {
            Utils.logError(LOG, e, "Decisor.leerInteraccionesNuevas: Error parsing JSON.");
        } catch (IOException e) {
            Utils.logError(LOG, e, "Decisor.leerInteracionesNuevas: Error getting file..");
        }

        return lstInteracciones;
    }

    /**
     * Método que crea los objetos Contenido con los datos del WebService y los
     * añade a una lista de Contenido que devuelve. Almacena en un entero el
     * último id obtenido.
     * 
     * @return {@code List<Contenido>} Lista de objetos Contenido
     * @throws Exception
     */
    private static List<Contenido> leerContenidosNuevos() throws Exception {
        Utils.logInfo(LOG, "Reading new content");
        List<Contenido> lstContenidos = new ArrayList<>();

        // Solucitud de contenidos nuevos
        String strTodo;
        String query = crearQueryDesdeDtmIndex(INT_TAM_LOTE);
        strTodo = Utils.getURLContent(new URL(query), null, Utils.getMessage("SOLR_USER"), Utils.getMessage("SOLR_PASS"));

        try {
            // Mapeamos
            ObjectMapper mapper = new ObjectMapper();
            JsonNode rootNode;

            rootNode = mapper.readTree(strTodo);

            // Guardamos el numero de documentos totales
            JsonNode nodosDocs = rootNode.findValue("docs");

            for (int i = 0; i < nodosDocs.size(); i++) {
                JsonNode nodoDoc = nodosDocs.get(i);
                lstContenidos.add(new Contenido(nodoDoc));
            }
        } catch (JsonProcessingException e) {
            Utils.logError(LOG, e, "Decisor.LeerContenidosNuevos: Error parsing JSON");
        } catch (IOException e) {
            Utils.logError(LOG, e, "Decisor.LeerContenidos: Error getting files");
        } catch (Exception e1) {
            Utils.logError(LOG, e1, "Error on leerContenidosNuevos");
        }
        return lstContenidos;

    }

    /**
     * Método que lanza los métodos leerContenidosNuevos y
     * leerInteraccionesNuevas
     */
    public static void upload() {

        boolean blnContinue;
        do {
            blnContinue = false;

            try {
                Utils.logInfo(LOG, "Getting content from Solr...");
                List<Contenido> lstContenidos = Decisor.leerContenidosNuevos();

                if (!lstContenidos.isEmpty()) {
                    blnContinue = true;
                }

                Utils.logInfo(LOG, "Adding content...");
                recomendadorContenido.AddContenido(lstContenidos);
                Utils.logInfo(LOG, "Content added. {0} added.", lstContenidos.size());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error updating content.");
            }

            try {
                Utils.logInfo(LOG, "Getting interactions...");
                List<Interaccion> lstInteracciones = Decisor.leerInteraccionesNuevas();

                if (!blnContinue && !lstInteracciones.isEmpty()) {
                    blnContinue = true;
                }

                Utils.logInfo(LOG, "Adding interactions...");
                recomedadorIteracion.AnadirInteracciones(lstInteracciones);
                Utils.logInfo(LOG, "Interactions added. {0} added.", lstInteracciones.size());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error adding interactions.");
            }
        } while (blnContinue);
    }

    public static void incrementarCount() {
        count++;
    }

    public static int getCount() {
        return count;
    }

    public static List<Recomendacion> recomendarContenido(long idUsuario, long idContenido, TipoContenido tipoArecomendar, int numRecomendaciones) {
        Utils.logInfo(LOG, "Getting recommendation to content {0}", idContenido);

        // #153746 Deleted recommendations based on user interacions.
        // List<Recomendacion> lstRecomendaciones;
        List<Recomendacion> lstRecomendaciones = new ArrayList<Recomendacion>();

     // #153746 Deleted recommendations based on user interacions.
//        try {
//            lstRecomendaciones = recomedadorIteracion.recomendar(idUsuario, 0.3, numRecomendaciones, tipoArecomendar, idContenido);
//        } catch (Exception e) {
//            Utils.logError(LOG, e, "ERROR getting recommendation");
//            lstRecomendaciones = new ArrayList<Recomendacion>();
//        }

        /*
         * Si mediante la recomendación por contenido no se obtiene suficientes
         * resultados, se buscan a aprtir del recomendador de contenido
         */
        // int intPendientes = numRecomendaciones - lstRecomendaciones.size();
        int intPendientesTotal = numRecomendaciones * 3 - lstRecomendaciones.size();
        if (intPendientesTotal > 0) {
            List<Recomendacion> lstTmp;
            FastIDSet setInteracionesPropias;
           
         // #153746 Deleted recommendations based on user interacions.
//            if (idUsuario == 0) {
                setInteracionesPropias = new FastIDSet();
//            } else {
//                setInteracionesPropias = recomedadorIteracion.getInteraccionesUsuario(idUsuario);
//            }

            try {
                lstTmp = recomendadorContenido.recomendar(String.valueOf(idContenido), (float) 0, intPendientesTotal, tipoArecomendar, setInteracionesPropias);
            } catch (Exception e) {
                Utils.logError(LOG, e, "ERROR getting recommendation");
                lstTmp = new ArrayList<Recomendacion>();
            }

            lstRecomendaciones.addAll(lstTmp);
        }

        return lstRecomendaciones;

    }

    /**
     * Crea una url con la query de Solr que devolverá la cantidad de documentos
     * indicados en numDocs.
     * 
     * @param maxId
     *            {@code long} Id a partir del cual se empezarán a capturar
     *            documentos, -1 si queremos empezar desde el principio.
     * @param numDocs
     *            {@code int} Número de documentos que capturaremos con la
     *            query.
     * @return {@code String} Query creada con los parámetros maxId y numDocs.
     */
    private static String crearQueryDesdeDtmIndex(int numDocs) {
        final String serverUrl = SolrSupport.getServerURL(false);
        final String querySolr;
        final String strTdate = recomendadorContenido.getTDateMaxEnLucene();

        Utils.logInfo(LOG, "LAST_MAX_dtm = {0}", strTdate);
        querySolr = serverUrl + "/select?q=lastIndexDate:[" + strTdate + "+TO+*]" + "+AND+-published:0" + "&rows=" + numDocs
                + "&sort=lastIndexDate+asc&fl=id,generalDescriptionStr,generalTitleStr,type,lastIndexDate&wt=json&indent=true";

        return querySolr;
    }

    public static long getIdContenidoMax() {
        return recomendadorContenido.getMaxIdEnLucene();
    }

    public static long getDtmInteraccionMax() {
        return recomedadorIteracion.getDtmMax();
    }

    public static boolean removeItem(long idContent) {
        try {
            recomedadorIteracion.deleteInteracctionByContent(idContent);
        } catch (Exception e) {
            Utils.logError(LOG, e, "ERROR deleting item in interaction recommender (" + e.getMessage() + ")");
            return false;
        }

        try {
            recomendadorContenido.eliminarContenido(idContent);
        } catch (Exception e) {
            Utils.logError(LOG, e, "ERROR deleting item in contet recommender (" + e.getMessage() + ")");
            return false;
        }

        return true;
    }

    public static List<Recomendacion> getSolrRecommendations(final int numRecom, final String docType, final String titleToSearch, final String actualId) {
        final String queryStr = "title:" + titleToSearch;
        final SolrQuery query = new SolrQuery();
        SolrDocumentList docs = null;

        query.setQuery(queryStr);
        query.setFields("id", "mecIdentifierStr", "generalIdentifierStr", "type");
        query.setFilterQueries("published:1", "type:\"" + docType + "\"", "-id:" + actualId);
        query.setRows(numRecom);

        final String serverURL = SolrSupport.getServerURL(true);
        HttpSolrServer server = new HttpSolrServer(serverURL);

        List<Recomendacion> results = new ArrayList<Recomendacion>();

        try {
            docs = server.query(query).getResults();
            final Iterator<SolrDocument> docsIterator = docs.iterator();
            int numDocs = docs.size();
            if (numDocs > 0) {
                while (docsIterator.hasNext()) {
                    final SolrDocument next = docsIterator.next();
                    final String docId = (String) next.getFieldValue("id");

                    Recomendacion recom = new Recomendacion(Long.parseLong(docId), 1);

                    results.add(recom);

                }
            }
        } catch (SolrServerException e) {
            Utils.logError(LOG, "Error on query: {0}", queryStr);
        }

        return results;
    }

}
