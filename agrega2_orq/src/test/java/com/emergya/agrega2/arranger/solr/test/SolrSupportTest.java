package com.emergya.agrega2.arranger.solr.test;

import static junit.framework.TestCase.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.model.entity.solr.User;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;

public class SolrSupportTest {

    private SolrDocumentA2 doc;
    private String solrServerUrl;

    @Before
    public void init() {
        doc = new User();
        doc.setDescription("Description");
        doc.setId("1234567890");

        solrServerUrl = SolrSupport.getServerURL(true);

        assertEquals("Do getServerURL() OK!", solrServerUrl != null, true);
    }

    @Test
    public void injectDocumentTest() {
        assertEquals("Do injectDocumentTest() - Inject OK!", SolrSupport.injectDocument(doc), true);

        try {
            Thread.sleep(20000);
        } catch (InterruptedException e1) {
            fail();
        }

        try {
            assertEquals("Do injectDocumentTest() - getSolrDocumentById() OK!", Utils.isEmpty(SolrSupport.getSolrDocumentById(doc.getId())), false);
        } catch (Exception e) {
            fail();
        }
    }

    @After
    public void finish() {
        assertTrue("Do deleteDocumentById() OK!", SolrSupport.deleteDocumentById(doc.getId(), null));

    }

}
