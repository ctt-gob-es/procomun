package com.emergya.agrega2.arranger.controller;

import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.json.PreviewComponent;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
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

/**
 * 
 */
@Controller
public interface SolrService {

    /** Service to do queries against Solr Server
     * @param request HttpServletRequest with necessary parameters to lunch queries against Solr server
     * @return Solr server response
     */
    @RequestMapping(value = { "/solr/**", "/external/solr/**" }, method = { RequestMethod.GET, RequestMethod.HEAD, RequestMethod.POST }, produces = {
            "application/xml;charset=UTF-8", "application/json;charset=UTF-8", "text/html;charset=UTF-8" })
    @ResponseBody
    public String requestSolr(HttpServletRequest request);

    /** Service to do queries against Solr Server. Only ODEs supported.
     * @param request HttpServletRequest with necessary parameters to lunch queris against Solr server
     * @return Solr server response
     */
    @RequestMapping(value = { "/opendata/**" }, method = { RequestMethod.GET, RequestMethod.HEAD, RequestMethod.POST }, produces = { "application/xml;charset=UTF-8",
            "application/json;charset=UTF-8", "text/html;charset=UTF-8" })
    @ResponseBody
    public String requestSolrOpenData(HttpServletRequest request);

    /** Method to add a {@link SolrDocumentA2} of type ODE into Solr server
     * @param ode JSON that represents a ODE {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddOde", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrOde(@RequestBody final Ode ode);

    /** Method to add a {@link SolrDocumentA2} of type RESPONSE into Solr server
     * @param response JSON that represents a RESPONSE {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddResponse", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrResponse(@RequestBody final Response response);

    /** Method to add a {@link SolrDocumentA2} of type QUESTION into Solr server
     * @param question JSON that represents a QUESTION {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddQuestion", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrQuestion(@RequestBody final Question question);

    /** Method to add a {@link SolrDocumentA2} of type COMMUNITY into Solr server
     * @param user JSON that represents a COMMUNITY {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddCommunity", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrCommunity(@RequestBody final Community community);

    /** Method to add a {@link SolrDocumentA2} of type DISCUSSION into Solr server
     * @param discussion JSON that represents a DISCUSSION {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddDiscussion", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrDiscussion(@RequestBody final Discussion discussion);

    /** Method to add a {@link SolrDocumentA2} of type EVENT into Solr server
     * @param event JSON that represents a EVENT {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddEvent", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrEvent(@RequestBody final Event event);

    /** Method to add a {@link SolrDocumentA2} of type POLL into Solr server
     * @param poll JSON that represents a POLL {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddPoll", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrPoll(@RequestBody final Poll poll);

    /** Method to add a {@link SolrDocumentA2} of type LEARNING_RESOURCE into Solr server
     * @param learningResource JSON that represents a POLL {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddLearningResource", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrLearningResource(@RequestBody final LearningResource learningResource);

    /** Method to add a {@link SolrDocumentA2} of type LEARNING_RESOURCE into Solr server
     * @param comment JSON that represents a POLL {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddComment", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrComment(@RequestBody final Comment comment);

    /** Method to add a {@link SolrDocumentA2} of type POST into Solr server
     * @param post JSON that represents a POST {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddPost", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrPost(@RequestBody final Post post);

    /** Method to add a {@link SolrDocumentA2} of type PODCAST into Solr server
     * @param post JSON that represents a PODCAST {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddPodcast", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrPodcast(@RequestBody final Podcast podcast);

    /** Method to add a {@link SolrDocumentA2} of type WEBINAR into Solr server
     * @param post JSON that represents a WEBINAR {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddWebinar", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrWebinar(@RequestBody final Webinar webinar);

    /** Method to add a {@link SolrDocumentA2} of type URL into Solr server
     * @param post JSON that represents a URL {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddUrl", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrUrl(@RequestBody final Url url);

    /** Method to add a {@link SolrDocumentA2} of type LearningPath into Solr server
     * @param post JSON that represents a URL {@link SolrDocumentType}
     * @return Solr server response
     */
    @RequestMapping(value = "/solrAddLearningPath", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse injectToSolrLearningPath(@RequestBody final LearningPath learningPath);

    /** Method to delete a {@link SolrDocumentA2} from Solr server and recommender services
     * @param document JSON that represents a {@link SolrDocumentA2}. It is only necessary to include the field id
     * @return Solr server response
     */
    @RequestMapping(value = "/solrDelete", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse deleteFromSolr(@RequestBody final GenericEntity document);

    /** Method to update a {@link SolrDocumentA2} on Solr to save the idDrupal field
     * @param document JSON that represents a {@link SolrDocumentA2}. It is only necessary to include the fields id and idDrupal
     * @return Solr server response
     */
    @RequestMapping(value = { "/solrUpdateSolr", "/solrUpdateNodeSolr",
            "updateUserSolr" }, method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse updateSolr(@RequestBody final GenericEntity document);

    /** Method to publish a {@link SolrDocumentA2}
     * @param document id
     * @return Solr server response
     */
    @RequestMapping(value = "/solrPublishDocument", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse publishDocument(@RequestBody final GenericEntity document);

    /** Method to unpublish a {@link SolrDocumentA2}
     * @param document id
     * @return Solr server response
     */
    @RequestMapping(value = "/solrUnpublishDocument", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse unpublishDocument(@RequestBody final GenericEntity document);

    /** Method to set preview field on {@link SolrDocumentA2}
     * @param document id
     * @return Solr server response
     */
    @RequestMapping(value = "/solrUpdatePreview", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse updatePreview(@RequestBody final PreviewComponent previewComponent);

    /** Method to certify, or not, a {@link SolrDocumentA2}
     * @param document id
     * @return Solr server response
     */
    @RequestMapping(value = "/solrCertifyDocument", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse updateCertified(@RequestBody final GenericEntity document);

    /** Method to mark as Nolvety, or not, a {@link SolrDocumentA2}
     * @param document id
     * @return Solr server response
     */
    @RequestMapping(value = "/solrMarkAsNovelty", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse updateNovelty(@RequestBody final GenericEntity document);

    @RequestMapping(value = "/solrFields/{className}", method = RequestMethod.GET)
    @ResponseBody
    public List<String> getSolrBoostingFields(@PathVariable("className") final String className);

    @RequestMapping(value = "/solrFields", method = RequestMethod.GET)
    @ResponseBody
    public List<String> getSolrBoostingFields();

    @RequestMapping(value = "/solrSetSolrBoosting", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public ServiceResponse setSolrBoostingFields(@RequestBody final SolrBoost boosting);

    @RequestMapping(value = "/solrBoosting", method = RequestMethod.GET)
    @ResponseBody
    public Map<String, String> getSolrBoosting();

}
