package com.emergya.agrega2.arranger.solr;

import java.io.IOException;
import java.lang.reflect.Field;
import java.net.URL;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

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
import org.apache.solr.common.params.SolrParams;
import org.codehaus.jackson.map.ObjectMapper;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.json.SolrBoost;
import com.emergya.agrega2.arranger.model.entity.json.SolrBoostItem;
import com.emergya.agrega2.arranger.model.entity.solr.Comment;
import com.emergya.agrega2.arranger.model.entity.solr.Community;
import com.emergya.agrega2.arranger.model.entity.solr.Discussion;
import com.emergya.agrega2.arranger.model.entity.solr.Event;
import com.emergya.agrega2.arranger.model.entity.solr.LearningPath;
import com.emergya.agrega2.arranger.model.entity.solr.LearningResource;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.Podcast;
import com.emergya.agrega2.arranger.model.entity.solr.Poll;
import com.emergya.agrega2.arranger.model.entity.solr.Post;
import com.emergya.agrega2.arranger.model.entity.solr.Question;
import com.emergya.agrega2.arranger.model.entity.solr.Response;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.model.entity.solr.Url;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.model.entity.solr.Webinar;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * Class to interact with Solr Server instance
 */
/**
 * @author ajrodriguez
 *
 */
public class SolrSupport {

    private static final Log LOG = LogFactory.getLog(SolrSupport.class);

    private SolrSupport() {
    }

    /** Method to inject a {@link SolrDocumentA2} into Solr server.
     * @param document Document to insert on Solr
     * @return <code>true</code> if OK, <code>false</code> if NOK
     */
    public static boolean injectDocument(SolrDocumentA2 document) {
        final String serverUrl = getServerURL(true);
        final HttpSolrServer server = new HttpSolrServer(serverUrl);

        try {
            final UpdateResponse response = server.addBean(document);
            int status = response.getStatus();
            // SOLR WILL BE AUTOMATICALLY DO COMMIT
            if (status == 0) {
                status = server.commit().getStatus();
            }
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

    /** Gets the Solr server URL associated to Arranger
     * @return Solr Server URL
     */
    public static String getServerURL(boolean auth) {
        final StringBuilder sb = new StringBuilder();
        sb.append(Utils.getMessage("SOLR_URL_PREFIX"));
        final String solrUser = Utils.getMessage("SOLR_USER");
        if (auth && !Utils.isEmpty(solrUser)) {
            sb.append(solrUser);
            sb.append(":");
            sb.append(Utils.getMessage("SOLR_PASS"));
            sb.append("@");
        }
        sb.append(Utils.getMessage("SOLR_HOST"));
        sb.append(":");
        sb.append(Utils.getMessage("SOLR_PORT"));
        sb.append("/");
        sb.append(Utils.getMessage("SOLR_CONTEXT"));
        sb.append("/");
        sb.append(Utils.getMessage("SOLR_CORE"));
        final String serverURL = sb.toString();
        Utils.logInfo(LOG, "ServerURL {0}", serverURL);
        return serverURL;
    }

    /**
     * Gets a document from Solr by its ID
     * @param id Identifier of the document
     * @return Document associated to the id, if exists
     */
    public static SolrDocumentA2 getSolrDocumentById(final String id) {
        final String serverUrl = getServerURL(true);
        final HttpSolrServer server = new HttpSolrServer(serverUrl);
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
            } else if (type.equals(SolrDocumentType.WEBINAR.name())) {
                return objMapper.convertValue(tmp, Webinar.class);
            } else if (type.equals(SolrDocumentType.URL.name())) {
                return objMapper.convertValue(tmp, Url.class);
            } else if (type.equals(SolrDocumentType.LEARNING_PATH.name())) {
                return objMapper.convertValue(tmp, LearningPath.class);
            }
        } catch (SolrServerException | IndexOutOfBoundsException e) {
            Utils.logError(LOG, e, "Cannot GET document from Solr [SolrServerException]. DocID: {0}", id);
        }
        return null;

    }

    /** Method to get a field of a document from Solr server.
     * @param identifier Identifier of the Solr Document
     * @param field Field of the document to return
     * @return Value of the field specified, or null
     */
    public static Object getSolrField(String identifier, String field) {
        if (!Utils.isEmpty(identifier)) {

            final String serverUrl = getServerURL(true);
            final HttpSolrServer server = new HttpSolrServer(serverUrl);

            SolrParams params = new SolrQuery("id:" + identifier);
            return extractDocumentField(field, server, params);
        } else {
            return null;
        }
    }

    /** Method to get a field of a document from Solr server.
     * @param MECID Identifier of the Solr Document
     * @param field Field of the document to return
     * @return Value of the field specified, or null
     */
    public static Object getSolrFieldByMECId(String mecId, String field) {
        if (!Utils.isEmpty(mecId)) {

            final String serverUrl = getServerURL(true);
            final HttpSolrServer server = new HttpSolrServer(serverUrl);

            SolrParams params = new SolrQuery("mecIdentifierStr:" + mecId);
            return extractDocumentField(field, server, params);
        } else {
            return null;
        }
    }

    private static Object extractDocumentField(String field, final HttpSolrServer server, SolrParams params) {
        QueryResponse response;
        try {
            response = server.query(params);
            SolrDocumentList listResults = response.getResults();
            if (listResults != null && listResults.getNumFound() == 1) {
                org.apache.solr.common.SolrDocument doc = listResults.get(0);
                return doc.getFieldValue(field);
            } else {
                return null;
            }
        } catch (SolrServerException e) {
            Utils.logError(LOG, e, "Cannot execute query on Solr [SolrServerException].");
            return null;
        }
    }

    /** Method to get the identifiers of an ODE from Solr server.
     * @param identifier Identifier of the document to get from Solr
     * @return ODE identifiers if encountered, null otherwise
     */
    public static Collection<Object> getOdeIdentifiers(String identifier) {
        if (!Utils.isEmpty(identifier)) {

            final String serverUrl = getServerURL(true);
            final HttpSolrServer server = new HttpSolrServer(serverUrl);

            SolrParams params = new SolrQuery("id:" + identifier);
            QueryResponse response;
            try {
                response = server.query(params);
                SolrDocumentList listResults = response.getResults();
                if (listResults != null && listResults.getNumFound() == 1) {
                    org.apache.solr.common.SolrDocument doc = listResults.get(0);
                    return doc.getFieldValues("generalIdentifierStr");
                } else {
                    return null;
                }
            } catch (SolrServerException e) {
                Utils.logError(LOG, e, "Cannot execute query on Solr [SolrServerException]. DocID: {0}", identifier);
                return null;
            }
        } else {
            return null;
        }
    }

    public static boolean deleteDocumentById(String identifier, HttpSolrServer server) {
        if (server == null) {
            final String serverUrl = getServerURL(true);
            server = new HttpSolrServer(serverUrl);
        }

        boolean result = false;
        if (!Utils.isEmpty(identifier)) {

            UpdateResponse deleteById = null;
            try {
                deleteById = server.deleteById(identifier);
            } catch (SolrServerException | IOException e) {
                Utils.logError(LOG, e, "Cannot d on Solr [SolrServerException]. DocID: {0}", identifier);
            }
            result = deleteById != null ? deleteById.getStatus() == 0 : false;
        }
        return result;
    }

    /** Method to obtain all {@link org.apache.solr.client.solrj.beans.Field} from a {@link Class}
     * @param cls {@link Class} to obtain the list of {@link org.apache.solr.client.solrj.beans.Field}
     * @return List with names of all Solr declared Fields
     */
    public static List<String> getSolrBoostingFields(Class<?> cls) {

        if (Utils.isEmpty(cls)) {
            final String fields = Utils.getMessage("solr.boosting.fields");
            return Arrays.asList(fields.split(","));
        }

        List<String> solrBoostingFields = new ArrayList<String>();
        List<Class<?>> classes = new ArrayList<Class<?>>();

        classes.add(cls);
        while (cls.getSuperclass() != null) {
            classes.add(cls.getSuperclass());
            cls = cls.getSuperclass();
        }

        for (Class<?> clsObj : classes) {
            final Field[] declaredFields = clsObj.getDeclaredFields();
            for (Field field : declaredFields) {

                if (field.isAnnotationPresent(org.apache.solr.client.solrj.beans.Field.class)) {
                    solrBoostingFields.add(field.getName());
                }
            }
        }

        return solrBoostingFields;
    }

    public static boolean setSolrBoostingFields(SolrBoost boosting) {
        Map<String, String> solrFieldsBoosting = new HashMap<String, String>();
        for (SolrBoostItem solrBoost : boosting.getFieldsBoosting()) {
            solrFieldsBoosting.put(solrBoost.getFieldName(), solrBoost.getBoosting());
        }
        try {
            Utils.setSolrFieldsBoosting(solrFieldsBoosting);
            return true;
        } catch (Exception e) {
            Utils.logError(LOG, e);
            return false;
        }
    }

    public static boolean setSolrBoostingFieldsFromDrupal() {

        boolean result = true;

        final String requestUrl = Utils.getMessage("arranger.drupal.endpoint") + Utils.getMessage("arranger.drupal.boosting.conf");

        try {
            final String response = Utils.getURLContent(new URL(requestUrl), null, null, null);
            final ObjectMapper mapper = new ObjectMapper();
            final SolrBoost boosting = mapper.readValue(response, SolrBoost.class);

            if (!Utils.isEmpty(boosting) || Utils.isEmpty(boosting.getFieldsBoosting())) {
                setSolrBoostingFields(boosting);
            } else {
                result = false;
            }

        } catch (IOException e) {
            Utils.logError(LOG, "Cannot connect to {0}", requestUrl);
            result = false;
        }

        return result;
    }

    public static String getQfParam() {

        StringBuilder sb = new StringBuilder();
        final Map<String, String> solrFieldsBoosting = Utils.getSolrFieldsBoosting();
        for (String field : solrFieldsBoosting.keySet()) {
            sb.append(field).append("^").append(solrFieldsBoosting.get(field)).append(" ");
        }
        return sb.toString().replace(" ", "%20");
    }

    public static SolrDocumentList getDocumentsByType(final String type, HttpSolrServer server) {
        if (server == null) {
            final String serverUrl = getServerURL(true);
            server = new HttpSolrServer(serverUrl);
        }

        final SolrQuery q = new SolrQuery("*:*");
        q.setFilterQueries("type:" + type);
        q.setRows(150000);

        try {
            final QueryResponse queryResult = server.query(q);
            return queryResult.getResults();
        } catch (SolrServerException e) {
            Utils.logError(LOG, e, "Cannot obtain results from Solr");
            return null;
        }

    }
}
