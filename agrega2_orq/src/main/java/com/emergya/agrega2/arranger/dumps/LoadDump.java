package com.emergya.agrega2.arranger.dumps;

import java.io.IOException;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.solr.client.solrj.SolrQuery;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.apache.solr.client.solrj.impl.HttpSolrServer.RemoteSolrException;
import org.apache.solr.client.solrj.response.QueryResponse;
import org.apache.solr.client.solrj.response.UpdateResponse;
import org.apache.solr.common.SolrDocument;
import org.apache.solr.common.SolrDocumentList;
import org.codehaus.jackson.map.ObjectMapper;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.util.AgregaUtil;

import es.pode.adminusuarios.negocio.servicios.UsuarioVO;
import es.pode.buscar.negocio.buscar.servicios.ValoresBusquedaVO;

public class LoadDump {

    private static final Log LOG = LogFactory.getLog(LoadDump.class);

    private static final int MAX_ROWS = 150000;
    private static final int DEFAULT_THREADS_NUM = 200;

    // This lines are deleted to use SolrSupport.getServerURL
    // final static String serverUrl =
    final static HttpSolrServer server;

    public static final String AGREGA_URL = "agrega.url";

    public static final String OPT_PUBLICATOR = "publicator";
    public static final String OPT_ODENODE = "odeNode";
    public static final String OPT_TITLEORDER = "titleOrder";

    private static List<String> options;

    static {
        String serverUrl = SolrSupport.getServerURL(Boolean.TRUE);
        server = new HttpSolrServer(serverUrl);
        Utils.logInfo(LOG, "Setting Solr Server to -> {0}", serverUrl);
        Utils.logInfo(LOG, "Setting ODEs Search service to -> {0} {1}", Utils.getMessage(AgregaUtil.AGREGA_URL), Utils.getMessage(AgregaUtil.AGREGA_SEARCH_SERVICE));
    }

    public static boolean loadContent(final String[] opts) {

        options = Arrays.asList(opts);

        try {

            Utils.logInfo(LOG, "==============================================");
            Utils.logInfo(LOG, "LOAD DUMP process......");
            Utils.logInfo(LOG, "==============================================");

            Utils.logInfo(LOG, "==============================================");
            Utils.logInfo(LOG, "LOADING threads......");
            Utils.logInfo(LOG, "==============================================");

            final SolrDocumentList docs = getSolrIds();
            final Iterator<SolrDocument> docsIterator = docs.iterator();
            int numDocs = docs.size();
            if (numDocs > 0) {
                final CountDownLatch latch = new CountDownLatch(numDocs);
                final BlockingQueue<SolrDocument> odesToProcess = new ArrayBlockingQueue<SolrDocument>(numDocs);
                while (docsIterator.hasNext()) {
                    odesToProcess.add(docsIterator.next());
                }

                // Configure executor.
                final ExecutorService executor = Executors.newFixedThreadPool(DEFAULT_THREADS_NUM);

                Runnable injector = new Runnable() {
                    @Override
                    public void run() {
                        try {
                            final SolrDocument ode = odesToProcess.take();
                            updateFields(ode);
                            latch.countDown();
                        } catch (InterruptedException e1) {
                            Utils.logError(LOG, e1.getMessage());
                        }
                    }
                };

                // Lunch threads
                for (int i = 0; i < numDocs; i++) {
                    executor.execute(injector);
                }
                executor.shutdown();
            }

        } catch (Exception e) {
            Utils.logError(LOG, e.getMessage());
            return false;
        }
        return true;

    }

    private static void updateFields(final SolrDocument doc) {
        if (options.contains(OPT_PUBLICATOR)) {
            injectPublicatorToOde(doc);
        }
        if (options.contains(OPT_ODENODE)) {
            injectNodeToOde(doc);
        }
        if (options.contains(OPT_TITLEORDER)) {
            updateTitleOrder(doc);
        }
    }

    private static void updateTitleOrder(final SolrDocument doc) {
        final Ode docDest = new Ode();

        final String docId = (String) doc.getFieldValue("id");
        final String titleStr = (String) doc.getFieldValue("titleStr");

        final Ode solrDoc = (Ode) getSolrDocumentById(docId, server);

        Utils.copyProperties(solrDoc, docDest);
        if (injectDocument(docDest)) {
            Utils.logInfo(LOG, "Inserted Title to ODE {0} -> {1}", docId, titleStr);
        } else {
            Utils.logError(LOG, "CANNOT insert Node to ODE {0} -> {1}", docId, titleStr);
        }
    }

    private static void injectPublicatorToOde(final SolrDocument doc) {
        final Ode docDest = new Ode();

        final String docId = (String) doc.getFieldValue("id");
        final String mecIdentifierStr = (String) doc.getFieldValue("mecIdentifierStr");
        final String node = (String) doc.getFieldValue("odeNodeStr");

        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(mecIdentifierStr);
        final String publicatorStr = AgregaUtil.getPublicator(agregaUser, node);
        final String publicatorNameStr = AgregaUtil.getPublicatorName(agregaUser);
        final String publicatorEmailStr = agregaUser != null ? agregaUser.getEmail() : "";

        final Ode solrDoc = (Ode) getSolrDocumentById(docId, server);

        solrDoc.setPublicator(publicatorStr);
        solrDoc.setPublicatorName(publicatorNameStr);
        solrDoc.setPublicatorEmail(publicatorEmailStr);

        Utils.copyProperties(solrDoc, docDest);
        if (injectDocument(docDest)) {
            Utils.logInfo(LOG, "Inserted Publicator to ODE {0} -> {1} | {2} | {3}", docId, mecIdentifierStr, publicatorStr, publicatorNameStr);
        } else {
            Utils.logError(LOG, "CANNOT insert Node to ODE {0} -> {1} | {2} | {3}", docId, mecIdentifierStr, publicatorStr, publicatorNameStr);
        }
    }

    /** This method get the Image preview URl and inject it to Document on Solr
     * @param doc Document to process
     */
    private static void injectNodeToOde(final SolrDocument doc) {
        final Ode docDest = new Ode();

        final String docId = (String) doc.getFieldValue("id");
        final String mecId = (String) doc.getFieldValue("mecIdentifierStr");
        final Ode solrDoc = (Ode) getSolrDocumentById(docId, server);

        String odeNodeStr = solrDoc.getOdeNode();

        String odeLanguage = "es";

        if (solrDoc.getGeneralLanguage() != null) {
            odeLanguage = solrDoc.getGeneralLanguage().get(0);
            if (Utils.equalsStr(odeLanguage, "x-none")) {
                odeLanguage = "es";
            }
        }

        ValoresBusquedaVO valorBusqueda = AgregaUtil.getResultadoBusquedaODE(mecId, odeLanguage);

        Utils.copyProperties(solrDoc, docDest);

        if (valorBusqueda != null && !Utils.isEmpty(valorBusqueda.getNodo())) {
            odeNodeStr = valorBusqueda.getNodo();
        } else {
            odeNodeStr = Utils.getMessage(AGREGA_URL).replace("http://", "");
        }
        docDest.setOdeNode(odeNodeStr);

        if (injectDocument(docDest)) {
            Utils.logInfo(LOG, "Inserted Node to ODE {0} -> {1}", docId, odeNodeStr);
        } else {
            Utils.logError(LOG, "CANNOT insert Node to ODE {0} -> {1}", docId, odeNodeStr);
        }
    }

    /** This method get all SolrIds from ODEs.
     * @param queryStr q parameter on Solr query
     * @return ODEs list
     */
    private static SolrDocumentList getSolrIds() {
        final SolrQuery query = new SolrQuery();
        SolrDocumentList docs = null;

        query.setQuery("*:*");
        // query.setQuery("id:1416349609793");
        query.setFields("id", "mecIdentifierStr", "preview", "odeNodeStr", "generalLanguageStr");
        query.setFilterQueries("type:ODE");
        query.setRows(MAX_ROWS);

        try {
            docs = server.query(query).getResults();
            Utils.logInfo(LOG, "Returned {0} docs", docs.size());
        } catch (SolrServerException e) {
            Utils.logError(LOG, "Error on query: {0}", query.toString(), e);
        }

        return docs;
    }

    /** This method inject a document into Solr server
     * @param document Document to inject
     * @return true if OK, false if NOK
     */
    private static boolean injectDocument(SolrDocumentA2 document) {

        try {
            final UpdateResponse response = server.addBean(document);
            int status = response.getStatus();
            return status == 0 ? true : false;
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot inject document on Solr [IOException]. DocID: {0}", document.getId());
        } catch (SolrServerException e) {
            Utils.logError(LOG, e, "Cannot inject document on Solr [SolrServerException]. DocID: {0}", document.getId());
        } catch (RemoteSolrException e) {
            Utils.logError(LOG, e, "Cannot inject document on Solr [RemoteSolrException]. DocID: {0}", document.getId());
            Utils.logError(LOG, e.getMessage());
        }

        return false;

    }

    public static SolrDocumentA2 getSolrDocumentById(final String id, final HttpSolrServer server) {
        SolrDocument doc = null;

        final SolrQuery q = new SolrQuery("id:" + id);

        try {
            final ObjectMapper objMapper = new ObjectMapper();
            final QueryResponse queryResult = server.query(q);
            Map<String, Object> tmp = new LinkedHashMap<String, Object>();

            final SolrDocumentList results = queryResult.getResults();
            if (!Utils.isEmpty(results)) {
                doc = results.get(0);
            } else {
                return null;
            }
            final Set<String> keySet = doc.keySet();

            Iterator<String> iterator = keySet.iterator();
            while (iterator.hasNext()) {
                final String key = iterator.next();
                if (key.endsWith("Str")) {
                    tmp.put(key.substring(0, key.length() - 3), doc.get(key));
                } else if (!key.endsWith("Auto") && !"lastIndexDate".equals(key)) {
                    tmp.put(key, doc.get(key));
                }

            }

            final Object type = doc.getFieldValue("type");
            if (type.equals(SolrDocumentType.ODE.name())) {
                return objMapper.convertValue(tmp, Ode.class);
            }
        } catch (SolrServerException | IndexOutOfBoundsException e) {
            Utils.logError(LOG, e, "Cannot GET document from Solr [SolrServerException]. DocID: {0}", id);
        }
        return null;

    }

}
