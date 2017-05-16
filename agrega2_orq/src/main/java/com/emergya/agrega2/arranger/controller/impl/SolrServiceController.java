package com.emergya.agrega2.arranger.controller.impl;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.codehaus.jackson.map.ObjectMapper;
import org.springframework.stereotype.Component;
import org.springframework.util.StringUtils;
import org.springframework.web.servlet.HandlerMapping;

import com.emergya.agrega2.arranger.controller.SolrService;
import com.emergya.agrega2.arranger.model.entity.aop.HandleSolrDocument;
import com.emergya.agrega2.arranger.model.entity.json.PreviewComponent;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.json.SolrBoost;
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
import com.emergya.agrega2.arranger.model.entity.solr.Webinar;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Decisor;

/**
 * See {@link SolrService} for more information.
 */
@Component
public class SolrServiceController extends SolrInjectionController implements SolrService {

    private static final Log LOG = LogFactory.getLog(SolrServiceController.class);
    private static final String FAILSTR = "FAIL!";

    public String requestSolr(HttpServletRequest request) {

        String completePath = (String) request.getAttribute(HandlerMapping.PATH_WITHIN_HANDLER_MAPPING_ATTRIBUTE);
        // Pattern path: '/rest/solr/**'
        String patternPath = (String) request.getAttribute(HandlerMapping.BEST_MATCHING_PATTERN_ATTRIBUTE);

        // Remove '**'
        patternPath = StringUtils.replace(patternPath, "**", "");
        // Remove '/rest/solr/'
        completePath = StringUtils.replace(completePath, patternPath, "");
        // Request params: i.e q=texttosearch*&wt=json
        String params = request.getQueryString();

        final String qfParam = SolrSupport.getQfParam();

        if (!Utils.isEmpty(qfParam)) {
            params = params + "&qf=" + qfParam;
        }

        String completeURL = SolrSupport.getServerURL(false) + "/" + completePath + (StringUtils.isEmpty(params) ? "" : "?" + params);
        String response = null;
        try {

            final URL urlObject = new URL(completeURL);
            Utils.logDebug(LOG, "URL for Solr: " + urlObject.toString());
            response = Utils.getURLContent(urlObject, "UTF-8", Utils.getMessage("SOLR_USER"), Utils.getMessage("SOLR_PASS"));
        } catch (MalformedURLException e) {
            Utils.logError(LOG, e, "Malformed URL: " + completeURL);
            return FAILSTR;
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot establish connection! " + completeURL);
            return FAILSTR;
        } catch (Exception e) {
            Utils.logError(LOG, e, "Unexpected error! " + completeURL);
            return FAILSTR;
        }

        return response;
    }

    public String requestSolrOpenData(HttpServletRequest request) {

        String completeURL = getCompleteUrl(request);
        if (completeURL.contains("USER") || completeURL.contains("fq")) {
            return ("Malformed URL");
        }
        completeURL = completeURL.concat("&fq=type:ODE");
        String response = null;
        try {
            final URL urlObject = new URL(completeURL);
            Utils.logDebug(LOG, "URL for Solr: " + urlObject.toString());
            response = Utils.getURLContent(urlObject, "UTF-8", Utils.getMessage("SOLR_USER"), Utils.getMessage("SOLR_PASS"));
        } catch (MalformedURLException e) {
            Utils.logError(LOG, e, "Malformed URL: " + completeURL);
            return FAILSTR;
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot establish connection! " + completeURL);
            return FAILSTR;
        } catch (Exception e) {
            Utils.logError(LOG, e, "Unexpected error! " + completeURL);
            return FAILSTR;
        }

        return response;
    }

    private String getCompleteUrl(HttpServletRequest request) {
        // Complete path: i.e '/rest/solr/empleo/select'
        String completePath = (String) request.getAttribute(HandlerMapping.PATH_WITHIN_HANDLER_MAPPING_ATTRIBUTE);
        
        // Pattern path: '/rest/solr/**'
        String patternPath = (String) request.getAttribute(HandlerMapping.BEST_MATCHING_PATTERN_ATTRIBUTE);
        
        // Remove '**'
        patternPath = StringUtils.replace(patternPath, "**", "");
        
        // Remove '/rest/solr/'
        completePath = StringUtils.replace(completePath, patternPath, "");
        
        // Request params: i.e q=texttosearch*&wt=json
        final String params = request.getQueryString();
        
        final String completeURL = SolrSupport.getServerURL(false) + "/" + completePath + (StringUtils.isEmpty(params) ? "" : "?" + params);
        
        return completeURL;
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrOde(final Ode ode) {
        ode.fillClassificationLabels();
        return injectDocument(ode);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrResponse(final Response response) {
        return injectDocument(response);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrQuestion(final Question question) {
        return injectDocument(question);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrCommunity(final Community community) {
        return injectDocument(community);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrDiscussion(final Discussion discussion) {
        return injectDocument(discussion);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrEvent(final Event event) {
        return injectDocument(event);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrPoll(final Poll poll) {
        return injectDocument(poll);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrLearningResource(final LearningResource learningResource) {
        learningResource.fillClassificationLabels();
        return injectDocument(learningResource);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrComment(final Comment comment) {
        return injectDocument(comment);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrPost(final Post post) {
        Utils.logInfo(LOG, "Invoked add POST");
        return injectDocument(post);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrPodcast(final Podcast podcast) {
        Utils.logInfo(LOG, "Invoked add PODCAST");
        return injectDocument(podcast);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrWebinar(final Webinar webinar) {
        Utils.logInfo(LOG, "Invoked add WEBINAR");
        return injectDocument(webinar);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrUrl(final Url url) {
        Utils.logInfo(LOG, "Invoked add URL");
        return injectDocument(url);
    }

    @HandleSolrDocument
    public ServiceResponse injectToSolrLearningPath(final LearningPath learningPath) {
        Utils.logInfo(LOG, "Invoked add LearningPath");
        return injectDocument(learningPath);
    }

    public ServiceResponse deleteFromSolr(final GenericEntity document) {
        try {
            Utils.logInfo(LOG, "Delete SOLR service invoked: " + new ObjectMapper().writeValueAsString(document));
        } catch (IOException e) {
            Utils.logError(LOG, e);
        }
        if (!Utils.isEmpty(document)) {
            if (SolrSupport.deleteDocumentById(document.getId(), null)) {
                if (!Decisor.removeItem(Long.valueOf(document.getId()))) {
                    Utils.logInfo(LOG, "Deleted Document with ID: {0}. Recommendations not deleted.", document.getId());
                    return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "Document deleted. Recommendations not deleted.", document.getId());
                }
                Utils.logInfo(LOG, "Deleted Document with ID: {0}", document.getId());
                return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "Document deleted.", document.getId());
            } else {
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Document NOT deleted.");
            }
        } else {
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Document NOT deleted.");
        }
    }

    public ServiceResponse updateSolr(final GenericEntity document) {
        try {
            Utils.logInfo(LOG, "Update SOLR service invoked: " + new ObjectMapper().writeValueAsString(document));
        } catch (IOException e) {
            Utils.logError(LOG, e);
        }
        if (document != null && !Utils.isEmpty(document.getId())) {
            SolrDocumentA2 docSolr = SolrSupport.getSolrDocumentById(document.getId());

            if (!Utils.isEmpty(docSolr)) {
                if (!Utils.isEmpty(document.getIdDrupal())) {
                    docSolr.setIdDrupal(document.getIdDrupal());
                }

                if (!Utils.isEmpty(document.getPublished())) {
                    docSolr.setPublished(document.getPublished());
                }

                if (!Utils.isEmpty(document.getCertified())) {
                    docSolr.setCertified(document.getCertified());
                }

                if (!Utils.isEmpty(document.getNovelty())) {
                    docSolr.setNovelty(document.getNovelty());
                }

                if (!Utils.isEmpty(document.getPublicationDate())) {
                    docSolr.setPublicationDate(document.getPublicationDate());
                }
                // else {
                // return new ServiceResponse(ResponseCode.NOK,
                // HttpURLConnection.HTTP_INTERNAL_ERROR,
                // "Field 'publicationDate', 'idDrupal', 'published' or
                // 'certified' are required.");
                // }

                return injectDocument(docSolr);
            } else {
                Utils.logInfo(LOG, "Document not found with id: {0}", document.getId());
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Document NOT found with this id.", document.getId());
            }

        } else {
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Field 'id' is required.");
        }
    }

    public ServiceResponse publishDocument(final GenericEntity document) {
        return updatePublishDocument(document.getId(), true);
    }

    public ServiceResponse unpublishDocument(final GenericEntity document) {
        return updatePublishDocument(document.getId(), false);
    }

    public ServiceResponse updateCertified(final GenericEntity document) {
        return updateSolr(document);
    }

    public ServiceResponse updateNovelty(final GenericEntity document) {
        return updateSolr(document);
    }

    private ServiceResponse updatePublishDocument(final String id, final boolean published) {
        if (!Utils.isEmpty(id)) {
            SolrDocumentA2 docSolr = SolrSupport.getSolrDocumentById(id);
            if (docSolr == null) {
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Document does not exists!");
            }
            docSolr.setPublished(published ? "1" : "0");
            return injectDocument(docSolr);
        } else {
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Field 'id' is required.");
        }
    }

    @Override
    public ServiceResponse updatePreview(PreviewComponent previewComponent) {
        if (!Utils.isEmpty(previewComponent.getIdSolr())) {
            SolrDocumentA2 solrDocument = (SolrDocumentA2) SolrSupport.getSolrDocumentById(previewComponent.getIdSolr());
            if (solrDocument == null) {
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Document does not exists!");
            }
            solrDocument.setPreview(previewComponent.getPreview());
            Utils.logInfo(LOG, "Updating preview on ODE {0}", solrDocument.getId());
            return injectDocument(solrDocument);
        } else {
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Field 'id' is required.");
        }
    }

    @Override
    public List<String> getSolrBoostingFields(String className) {
        List<String> result = null;
        try {
            result = SolrSupport.getSolrBoostingFields(Class.forName("com.emergya.agrega2.arranger.model.entity.solr." + className));
        } catch (ClassNotFoundException e) {
            Utils.logError(LOG, "Cannot find class with name {0}", className);
        }
        return result;
    }

    @Override
    public List<String> getSolrBoostingFields() {
        return SolrSupport.getSolrBoostingFields(null);
    }

    @Override
    public ServiceResponse setSolrBoostingFields(SolrBoost boosting) {
        boolean result = SolrSupport.setSolrBoostingFields(boosting);
        if (result) {
            return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "Boosting setted!");
        } else {
            return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_INTERNAL_ERROR, "Cannot setting boosting!");
        }
    }

    @Override
    public Map<String, String> getSolrBoosting() {
        // TODO Auto-generated method stub
        return Utils.getSolrFieldsBoosting();
    }

}
