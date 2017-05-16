package com.emergya.agrega2.arranger.test.utils;

import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.apache.solr.client.solrj.SolrQuery;
import org.apache.solr.client.solrj.SolrQuery.ORDER;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.apache.solr.client.solrj.impl.HttpSolrServer.RemoteSolrException;
import org.apache.solr.client.solrj.response.QueryResponse;
import org.apache.solr.client.solrj.response.UpdateResponse;
import org.apache.solr.common.SolrDocument;
import org.apache.solr.common.SolrDocumentList;
import org.codehaus.jackson.map.ObjectMapper;
import org.springframework.util.CollectionUtils;

import com.emergya.agrega2.arranger.controller.impl.SolrServiceController;
import com.emergya.agrega2.arranger.dumps.LoadDump;
import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.solr.Comment;
import com.emergya.agrega2.arranger.model.entity.solr.Community;
import com.emergya.agrega2.arranger.model.entity.solr.Discussion;
import com.emergya.agrega2.arranger.model.entity.solr.Event;
import com.emergya.agrega2.arranger.model.entity.solr.GenericEntity;
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
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.OdeContentJson;
import com.emergya.agrega2.odes.util.VisualizerUtils;

import es.pode.parseadorXML.castor.MetaMetadata;
import es.pode.parseadorXML.lomes.lomesAgrega.MetaMetadataAgrega;

public class Main {

    public static void main(String[] args) {

        // final String identifier = "es-an_2013070913_9102607";
        // final String nodoOde = AgregaUtil.getNodoOde(identifier, "es");
        //
        // final UsuarioVO agregaUser =
        // AgregaUtil.getAgregaUserByMecId(identifier);
        // System.out.println(AgregaUtil.getPublicator(agregaUser, nodoOde));
        // System.out.println(AgregaUtil.getPublicatorName(agregaUser));

        //LoadDump.loadContent(new String[] { LoadDump.OPT_PUBLICATOR, LoadDump.OPT_ODENODE });

    }

    private static void deleteDocumentsBytype(final String type) {
        final String serverUrl = SolrSupport.getServerURL(true);
        final HttpSolrServer server = new HttpSolrServer(serverUrl);
        final SolrDocumentList results = SolrSupport.getDocumentsByType(type, server);
        if (results != null) {
            for (final SolrDocument doc : results) {
                final String id = (String) doc.getFieldValue("id");
                final boolean deleted = SolrSupport.deleteDocumentById(id, server);
                if (deleted) {
                    System.out.println("OK Deleted document with ID: " + id);
                } else {
                    System.out.println("NOK Deleted document with ID: " + id);
                }
            }
        }
    }

    /**
     * @return
     */
    public static List<OdeContentJson> localizar() {
        String identifier = "es_20071116_3_0181500";
        final List<OdeContentJson> odeTreeData = VisualizerUtils.getODETreeData("1416349668902", "es");

        return odeTreeData;
    }

    public static void unPublishDocument(final String idSolr) {
        SolrServiceController controller = new SolrServiceController();
        GenericEntity document = new GenericEntity();
        document.setId(idSolr);
        controller.unpublishDocument(document);

        System.out.println(idSolr + " -> OK!");
    }

    public static void publishDocument(final String idSolr) {
        SolrServiceController controller = new SolrServiceController();
        GenericEntity document = new GenericEntity();
        document.setId(idSolr);
        controller.publishDocument(document);

        System.out.println(idSolr + " -> OK!");
    }

    public static void parseVcard() {
        final String vCardStr = "*";

        MetaMetadataAgrega md = new MetaMetadataAgrega(new MetaMetadata());
        try {
            System.out.println(md.interpretaVCard(vCardStr).getNombre());
            System.out.println(md.interpretaVCard(vCardStr).getCorreo());
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    private static org.apache.solr.common.SolrDocument existsDocument(String mecIdentifier) throws SolrServerException {

        final String serverUrl = SolrSupport.getServerURL(true);
        final HttpSolrServer server = new HttpSolrServer(serverUrl);

        SolrQuery query = new SolrQuery();
        query.add("q", "mecIdentifier:" + "\"" + mecIdentifier + "\"");
        query.addSort("lastIndexDate", ORDER.desc);

        QueryResponse response = server.query(query);

        if (response != null && !CollectionUtils.isEmpty(response.getResults())) {
            return response.getResults().get(0);
        } else {
            return null;
        }

    }

    private static SolrDocumentA2 getSolrDocumentById(final String id, final HttpSolrServer server) {
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
            } else if (type.equals(SolrDocumentType.URL.name())) {
                return objMapper.convertValue(tmp, Url.class);
            } else if (type.equals(SolrDocumentType.LEARNING_PATH.name())) {
                return objMapper.convertValue(tmp, LearningPath.class);
            }
        } catch (SolrServerException | IndexOutOfBoundsException e) {
            e.printStackTrace();
        }
        return null;

    }

    private static boolean injectDocument(SolrDocumentA2 document, HttpSolrServer server) {

        try {
            final UpdateResponse response = server.addBean(document);
            int status = response.getStatus();
            return status == 0 ? true : false;
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SolrServerException e) {
            e.printStackTrace();
        } catch (RemoteSolrException e) {
            e.printStackTrace();
        }

        return false;

    }

}
