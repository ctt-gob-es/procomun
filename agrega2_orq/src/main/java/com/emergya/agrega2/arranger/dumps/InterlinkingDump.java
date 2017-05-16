package com.emergya.agrega2.arranger.dumps;

import java.io.IOException;
import java.util.ArrayList;
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
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.junit.Before;
import org.junit.Test;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.solr.Comment;
import com.emergya.agrega2.arranger.model.entity.solr.Community;
import com.emergya.agrega2.arranger.model.entity.solr.Discussion;
import com.emergya.agrega2.arranger.model.entity.solr.Event;
import com.emergya.agrega2.arranger.model.entity.solr.LearningResource;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.Podcast;
import com.emergya.agrega2.arranger.model.entity.solr.Poll;
import com.emergya.agrega2.arranger.model.entity.solr.Post;
import com.emergya.agrega2.arranger.model.entity.solr.Question;
import com.emergya.agrega2.arranger.model.entity.solr.Response;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.util.exceptions.HTTPNotFoundException;
import com.emergya.agrega2.arranger.util.impl.JsoupUtils;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.util.AgregaUtil;

/**
 * 
 * @author ajrodriguez
 *
 */
public class InterlinkingDump {

    private static final Log LOG = LogFactory.getLog(InterlinkingDump.class);

    private static final String QUERY = "titleLinkStr:*##BNE*";
    private static final int MAX_ROWS = 150000;
    private static final int DEFAULT_THREADS_NUM = 300;

    private String serverUrl = "*";
    private HttpSolrServer server = null;

    @Before
    public void init() {
        server = new HttpSolrServer(serverUrl);
        Utils.logInfo(LOG, "Setting Solr Server to -> {0}", serverUrl);
        Utils.logInfo(LOG, "Setting ODEs Search service to -> {0} {1}", Utils.getMessage(AgregaUtil.AGREGA_URL), Utils.getMessage(AgregaUtil.AGREGA_SEARCH_SERVICE));

    }

    @Test
    public void updateInterlinkingContent() {

        final String queryStr = "titleLinks:bne";
        final SolrQuery query = new SolrQuery();
        SolrDocumentList docs = null;

        query.setQuery(queryStr);
        query.setFields("id", "titleLinksStr");
        query.setFilterQueries("type:ODE");
        query.setRows(MAX_ROWS);

        try {
            docs = server.query(query).getResults();
            final Iterator<SolrDocument> docsIterator = docs.iterator();
            int numDocs = docs.size();
            Utils.logInfo(LOG, "Getted {0} documents to process", numDocs);
            if (numDocs > 0) {
                while (docsIterator.hasNext()) {
                    final SolrDocument next = docsIterator.next();
                    final String docId = (String) next.getFieldValue("id");

                    final Ode solrDoc = (Ode) getSolrDocumentById(docId, server);

                    Ode docDest = new Ode();
                    Utils.copyProperties(solrDoc, docDest);

                    final List<String> titleLinkStrLst = solrDoc.getTitleLinks();
                    List<String> titleLinkStrLstNew = new ArrayList<String>();
                    boolean bnebool = false;

                    for (final String titleLink : titleLinkStrLst) {
                        bnebool = false;
                        String[] arr = titleLink.split("##");
                        try {
                            if (arr[0].contains("datos.bne.es") || arr[2].equals("BNE")) {
                                bnebool = true;
                                try {
                                    final String contentBNE = getContentBNE(arr[0]);
                                    Utils.logInfo(LOG, "Getted content from {0} -> {1}", arr[0], contentBNE);
                                    titleLinkStrLstNew.add(contentBNE);
                                } catch (HTTPNotFoundException e) {
                                    titleLinkStrLstNew.add(titleLink);
                                    Utils.logError(LOG, e);
                                }
                            } else {
                                titleLinkStrLstNew.add(titleLink);
                            }
                        } catch (ArrayIndexOutOfBoundsException e) {
                            Utils.logError(LOG, e, "Malformed TitleLinksStr in ODE -> {0}", docId);
                        }
                    }
                    docDest.setTitleLinks(titleLinkStrLstNew);

                    if (bnebool && injectDocument(docDest)) {
                        Utils.logInfo(LOG, "Inserted BNE Titles to ODE {0}", docId);
                    } else {
                        Utils.logError(LOG, "CANNOT insert BNE Titles to ODE {0}}", docId);
                    }

                }
            }
        } catch (SolrServerException e) {
            Utils.logError(LOG, "Error on query: {0}", queryStr);
        }

    }

    /** This method get the Image preview URl and inject it to Document on Solr
     * @param doc Document to process
     */
    private void injectImageLanguageToOde(final SolrDocument doc) {
        final Ode docDest = new Ode();

        final String docId = (String) doc.getFieldValue("id");
        final String mecId = (String) doc.getFieldValue("mecIdentifierStr");
        final Ode solrDoc = (Ode) getSolrDocumentById(docId, server);

        String previewUrl = (String) doc.getFieldValue("preview");
        String actualLanguage = (String) solrDoc.getGeneralLanguage().get(0);

        String odeLanguage = "es";

        if (solrDoc.getGeneralLanguage() != null || actualLanguage.equals("x-none")) {
            try {
                odeLanguage = AgregaUtil.getOdeLanguage(mecId);
            } catch (Exception e) {
                odeLanguage = actualLanguage;
                // docDest.setPublished("0");
                Utils.logWarn(LOG, "Cannot invoke 'getOdeLanguage'. ODE IS NOT PUBLISHED");
            }
        }
        Utils.copyProperties(solrDoc, docDest);

        // ODE PREVIEW
        previewUrl = AgregaUtil.getPreviewOde(mecId, odeLanguage);
        docDest.setPreview(previewUrl);

        // ODE LANGUAGE
        List<String> languages = new ArrayList<String>();
        languages.add(odeLanguage);
        docDest.setGeneralLanguage(languages);

        if (injectDocument(docDest)) {
            Utils.logInfo(LOG, "Inserted preview to ODE {0} -> {1}", docId, previewUrl);
        } else {
            Utils.logError(LOG, "CANNOT insert preview to ODE {0} -> {1}", docId, previewUrl);
        }
    }

    public void injectOdeNodes() {

        final String queryStr = "-odeNode:[\"\" TO *]";
        final SolrQuery query = new SolrQuery();
        SolrDocumentList docs = null;

        query.setQuery(queryStr);
        query.setFields("id", "odeNode", "mecIdentifierStr", "generalLanguageStr");
        query.setFilterQueries("type:ODE");
        query.setRows(MAX_ROWS);

        try {
            docs = server.query(query).getResults();
            final Iterator<SolrDocument> docsIterator = docs.iterator();
            int numDocs = docs.size();
            Utils.logInfo(LOG, "Getted {0} documents to process", numDocs);
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
                            updateNodeToOde(ode);
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
        } catch (SolrServerException e) {
            Utils.logError(LOG, "Error on query: {0}", queryStr);
        }

    }

    private void updateNodeToOde(final SolrDocument ode) {
        final String docId = (String) ode.getFieldValue("id");

        final Ode solrDoc = (Ode) getSolrDocumentById(docId, server);

        Ode docDest = new Ode();
        Utils.copyProperties(solrDoc, docDest);

        final String odeNode = solrDoc.getOdeNode();
        final String mecIdentifierStr = solrDoc.getMecIdentifier();
        final List<String> generalLaguageStr = solrDoc.getGeneralLanguage();
        final String language = generalLaguageStr.get(0);

        final String odeNodeNew = AgregaUtil.getNodoOde(mecIdentifierStr, language);
        Utils.logInfo(LOG, "Getted odeNode {0} for ODE {1} - {2}", odeNode, mecIdentifierStr, docId);

        docDest.setOdeNode(odeNodeNew);

        if (injectDocument(docDest)) {
            Utils.logInfo(LOG, "Inserted Node to ODE {0} -> {1}", docId, odeNodeNew);
        } else {
            Utils.logError(LOG, "CANNOT insert Npode to ODE {0} -> {1}", docId, odeNodeNew);
        }
    }

    /** This method get all SolrIds from ODEs.
     * @param queryStr q parameter on Solr query
     * @return ODEs list
     */
    private SolrDocumentList getSolrIds(String queryStr) {
        final SolrQuery query = new SolrQuery();
        SolrDocumentList docs = null;

        query.setQuery(queryStr);
        query.setFields("id", "titleLinksStr");
        query.setFilterQueries("type:ODE");
        query.setRows(MAX_ROWS);

        try {
            docs = server.query(query).getResults();
        } catch (SolrServerException e) {
            Utils.logError(LOG, "Error on query: {0}", queryStr);
        }

        return docs;
    }

    /** This method inject a document into Solr server
     * @param document Document to inject
     * @return true if OK, false if NOK
     */
    private boolean injectDocument(SolrDocumentA2 document) {

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

    public SolrDocumentA2 getSolrDocumentById(final String id, final HttpSolrServer server) {
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
            } else if (type.equals(SolrDocumentType.COMMENT.name())) {
                return objMapper.convertValue(tmp, Comment.class);
            } else if (type.equals(SolrDocumentType.COMMUNITY.name())) {
                return objMapper.convertValue(tmp, Community.class);
            } else if (type.equals(SolrDocumentType.DISCUSSION.name())) {
                return objMapper.convertValue(tmp, Discussion.class);
            } else if (type.equals(SolrDocumentType.EVENT.name())) {
                return objMapper.convertValue(tmp, Event.class);
            } else if (type.equals(SolrDocumentType.LEARNING_RESOURCE.name())) {
                return objMapper.convertValue(tmp, LearningResource.class);
            } else if (type.equals(SolrDocumentType.POLL.name())) {
                return objMapper.convertValue(tmp, Poll.class);
            } else if (type.equals(SolrDocumentType.QUESTION.name())) {
                return objMapper.convertValue(tmp, Question.class);
            } else if (type.equals(SolrDocumentType.RESPONSE.name())) {
                return objMapper.convertValue(tmp, Response.class);
            } else if (type.equals(SolrDocumentType.USER.name())) {
                return objMapper.convertValue(tmp, User.class);
            } else if (type.equals(SolrDocumentType.POST.name())) {
                return objMapper.convertValue(tmp, Post.class);
            } else if (type.equals(SolrDocumentType.PODCAST.name())) {
                return objMapper.convertValue(tmp, Podcast.class);
            }
        } catch (SolrServerException | IndexOutOfBoundsException e) {
            Utils.logError(LOG, e, "Cannot GET document from Solr [SolrServerException]. DocID: {0}", id);
        }
        return null;

    }

    private static String getContentBNE(final String url) throws HTTPNotFoundException {
        final Document doc = JsoupUtils.getJsoupDocument(url, null);

        // /html/body/section/header/div[1]/h1
        final Elements elemsh1 = doc.select("html > body > section > header > div:eq(1) > h1");

        try {
            final Element elemh1 = elemsh1.get(0);
            final String text = elemh1.text();
            if (!Utils.isEmpty(text)) {
                return url + "##" + text + "##" + "BNE";
            } else {
                return url + "##" + url + "##" + "BNE";
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            Utils.logInfo(LOG, "Cannot get h1 from {0}", url);
        }
        return url;
    }

}
