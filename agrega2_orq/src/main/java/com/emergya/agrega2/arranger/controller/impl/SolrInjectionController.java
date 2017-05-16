package com.emergya.agrega2.arranger.controller.impl;

import java.net.HttpURLConnection;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Decisor;

public class SolrInjectionController {

    private static final Log LOG = LogFactory.getLog(SolrInjectionController.class);

    protected ServiceResponse injectDocument(SolrDocumentA2 document) {
        if (SolrSupport.injectDocument(document)) {
            Utils.logInfo(LOG, "Injected Document with ID: {0}", document.getId());
            checkPublished(document);

            return new ServiceResponse(ResponseCode.OK, HttpURLConnection.HTTP_OK, "Document injected.",
                    document.getId());
        } else {
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_INTERNAL_ERROR,
                    "Document NOT injected.");
        }
    }

    /**
     * Check if document has been unpublished from Drupal, to delete it from recommenders
     * @param document Document to check if it has been unpublish
     */
    private void checkPublished(SolrDocumentA2 document) {
        // If document has been unpublished, we have to delete it from
        // recommenders
        if (!Utils.isEmpty(document.getPublished()) && !Utils.isEmpty(document.getId())
                && "0".equals(document.getPublished())) {
            if (!Decisor.removeItem(Long.valueOf(document.getId()))) {
                Utils.logInfo(LOG, "Document unpublished. Recommendations NOT deleted: {0}.", document.getId());
            } else {
                Utils.logInfo(LOG, "Document unpublished. Recommendations deleted: {0}", document.getId());
            }
        }
    }
}
