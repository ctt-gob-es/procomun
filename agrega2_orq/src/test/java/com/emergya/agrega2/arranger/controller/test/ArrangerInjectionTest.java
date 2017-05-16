package com.emergya.agrega2.arranger.controller.test;

import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.List;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import com.emergya.agrega2.arranger.controller.SolrService;
import com.emergya.agrega2.arranger.controller.impl.SolrServiceController;
import com.emergya.agrega2.arranger.model.entity.solr.Comment;
import com.emergya.agrega2.arranger.model.entity.solr.Community;
import com.emergya.agrega2.arranger.model.entity.solr.Discussion;
import com.emergya.agrega2.arranger.model.entity.solr.Entity;
import com.emergya.agrega2.arranger.model.entity.solr.Event;
import com.emergya.agrega2.arranger.model.entity.solr.GenericEntity;
import com.emergya.agrega2.arranger.model.entity.solr.LearningResource;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.Poll;
import com.emergya.agrega2.arranger.model.entity.solr.Question;
import com.emergya.agrega2.arranger.model.entity.solr.Response;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;

public class ArrangerInjectionTest {

    private static final String TITLE = "TITLE";
    private static final String ID = String.valueOf(Utils.getCurrentMillis());

    final Ode ode = new Ode();
    final User user = new User();
    final Response response = new Response();
    final Question question = new Question();
    final Community community = new Community();
    final Event event = new Event();
    final Poll poll = new Poll();
    final Discussion discussion = new Discussion();
    final LearningResource learningResource = new LearningResource();
    final Comment comment = new Comment();

    final List<Entity> documents = new ArrayList<Entity>();

    SolrService solrService;

    @Before
    public void init() {

        solrService = new SolrServiceController();

        ode.setId(ID + 10);
        ode.setTitle(TITLE);

        user.setId(ID + 20);
        user.setTitle(TITLE);

        response.setId(ID + 30);
        response.setTitle(TITLE);

        question.setId(ID + 40);
        question.setTitle(TITLE);

        community.setId(ID + 50);
        community.setTitle(TITLE);

        event.setId(ID + 60);
        event.setTitle(TITLE);

        poll.setId(ID + 70);
        poll.setTitle(TITLE);

        discussion.setId(ID + 80);
        discussion.setTitle(TITLE);

        learningResource.setId(ID + 90);
        learningResource.setTitle(TITLE);

        comment.setId(ID + 100);
        comment.setTitle(TITLE);
    }

    @Test
    public void injectOde() {
        assertTrue("Test: ODE inserted OK!", SolrSupport.injectDocument(ode));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(ode.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(ode);
    }

    @Test
    public void injectQuestion() {
        assertTrue("Test: QUESTION inserted OK!", SolrSupport.injectDocument(question));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(question.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(question);
    }

    @Test
    public void injectCommunity() {
        assertTrue("Test: COMMUNITY inserted OK!", SolrSupport.injectDocument(community));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(community.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(community);
    }

    @Test
    public void injectResponse() {
        assertTrue("Test: RESPONSE inserted OK!", SolrSupport.injectDocument(response));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(response.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(response);
    }

    @Test
    public void injectEvent() {
        assertTrue("Test: EVENT inserted OK!", SolrSupport.injectDocument(event));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(event.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(event);
    }

    @Test
    public void injectPoll() {
        assertTrue("Test: POLL inserted OK!", SolrSupport.injectDocument(poll));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(poll.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(poll);
    }

    @Test
    public void injectDiscussion() {
        assertTrue("Test: DISCUSSION inserted OK!", SolrSupport.injectDocument(discussion));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(discussion.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(discussion);
    }

    @Test
    public void injectLearningResource() {
        assertTrue("Test: LEARNING_RESOURCE inserted OK!", SolrSupport.injectDocument(learningResource));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(learningResource.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(learningResource);
    }

    @Test
    public void injectComment() {
        assertTrue("Test: COMMENT inserted OK!", SolrSupport.injectDocument(comment));

        GenericEntity genEnt = new GenericEntity();
        genEnt.setId(comment.getId());
        genEnt.setIdDrupal("ID_DRUPAL");
        genEnt.setPublished("0");
        assertTrue("Test: idDrupal edited OK!", SolrSupport.injectDocument(genEnt));

        documents.add(comment);
    }

    @After
    public void deleteInserted() {
        for (Entity ent : documents) {
            GenericEntity genEnt = new GenericEntity();
            genEnt.setId(ent.getId());
            assertTrue("Test: Document deleted OK!", SolrSupport.deleteDocumentById(ent.getId(), null));
        }
    }

}
