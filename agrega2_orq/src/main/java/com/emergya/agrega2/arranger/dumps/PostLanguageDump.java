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
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.util.AgregaUtil;

/**
 * Utlity to get and inject Language to POSTs in Solr
 * 
 * @author ajrodriguez
 *
 */
public class PostLanguageDump {

    private static final Log LOG = LogFactory.getLog(PostLanguageDump.class);

    public static final String ALL = "ALL";

    private static final String ALL_ODES_QUERY = "*:*";
    private static final int MAX_ROWS = 100000;
    private static final int DEFAULT_THREADS_NUM = 300;

    final static String serverUrl = "*";
    final static HttpSolrServer server;

    static {
        server = new HttpSolrServer(serverUrl);
        Utils.logInfo(LOG, "Setting Solr Server to -> {0}", serverUrl);
        Utils.logInfo(LOG, "Setting ODEs Search service to -> {0}{1}", Utils.getMessage(AgregaUtil.AGREGA_URL),
                Utils.getMessage(AgregaUtil.AGREGA_SEARCH_SERVICE));

    }

    public static boolean updateLanguagePosts(String param) {

        String query;
        if (param.equals("ALL")) {
            query = ALL_ODES_QUERY;
        } else {
            Utils.logInfo(LOG, "Wrong parameter: {0}", param);
            return false;
        }

        try {

            Utils.logInfo(LOG, "==============================================");
            Utils.logInfo(LOG, "Posts DUMP process......");
            Utils.logInfo(LOG, "==============================================");

            Utils.logInfo(LOG, "==============================================");
            Utils.logInfo(LOG, "Launching threads......");
            Utils.logInfo(LOG, "==============================================");

            final SolrDocumentList docs = getSolrIds(query);
            final Iterator<SolrDocument> docsIterator = docs.iterator();
            int numDocs = docs.size();
            if (numDocs > 0) {
                final CountDownLatch latch = new CountDownLatch(numDocs);
                final BlockingQueue<SolrDocument> postsToProcess = new ArrayBlockingQueue<SolrDocument>(numDocs);
                while (docsIterator.hasNext()) {
                    postsToProcess.add(docsIterator.next());
                }

                // Configure executor.
                final ExecutorService executor = Executors.newFixedThreadPool(DEFAULT_THREADS_NUM);

                Runnable injector = new Runnable() {
                    @Override
                    public void run() {
                        try {
                            final SolrDocument post = postsToProcess.take();
                            injectLanguageToPost(post);
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

    private static void injectLanguageToPost(final SolrDocument doc) {
        final Post docDest = new Post();

        final String docId = (String) doc.getFieldValue("id");
        final Post solrDoc = (Post) getSolrDocumentById(docId, server);

        final List<String> postGeneralLanguageStr = (List<String>) doc.getFieldValue("generalLanguage");

        if (Utils.isEmpty(postGeneralLanguageStr)) {
            List<String> languages = new ArrayList<String>();
            languages.add("es");
            Utils.copyProperties(solrDoc, docDest);
            docDest.setGeneralLanguage(languages);
            if (injectDocument(docDest)) {
                Utils.logInfo(LOG, "Inserted Language to POST {0} -> {1}", docId, postGeneralLanguageStr);
            } else {
                Utils.logError(LOG, "CANNOT insert Node to ODE {0} -> {1}", docId, postGeneralLanguageStr);
            }
        }
    }
    
    private static SolrDocumentList getSolrIds(String queryStr) {
        final SolrQuery query = new SolrQuery();
        SolrDocumentList docs = null;

        query.setQuery(queryStr);
        query.setFields("id");
        query.setFilterQueries("type:POST");
        query.setRows(MAX_ROWS);

        try {
            docs = server.query(query).getResults();
        } catch (SolrServerException e) {
            Utils.logError(LOG, "Error on query: {0}", queryStr);
        }

        return docs;
    }

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

}
