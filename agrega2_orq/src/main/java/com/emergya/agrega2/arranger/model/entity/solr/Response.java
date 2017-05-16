package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Response{@link SolrDocumentA2}
 */
public class Response extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = 7522426315514135816L;

    @Field
    private String responseState;

    @Field
    private List<String> responseLabels;

    public Response() {
        super(SolrDocumentType.RESPONSE);
    }

    @Override
    public String generateId() {
        final StringBuilder sb = new StringBuilder();
        if (!Utils.isEmpty(getTitle())) {
            sb.append(getTitle());
        }
        if (!Utils.isEmpty(getIdDrupal())) {
            sb.append(getIdDrupal());
        }
        if (!Utils.isEmpty(responseState)) {
            sb.append(responseState);
        }

        return Utils.generateID(getType().name() + sb.toString());
    }

    public String getResponseState() {
        return responseState;
    }

    public void setResponseState(String responseState) {
        this.responseState = responseState;
    }

    public List<String> getResponseLabels() {
        return responseLabels;
    }

    public void setResponseLabels(List<String> responseLabels) {
        this.responseLabels = responseLabels;
    }

}
