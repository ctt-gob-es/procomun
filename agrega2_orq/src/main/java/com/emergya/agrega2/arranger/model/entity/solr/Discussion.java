package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Discussion {@link SolrDocumentA2}
 */
public class Discussion extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -5606177913990108680L;

    @Field
    private List<String> discussionLabels;

    public Discussion() {
        super(SolrDocumentType.DISCUSSION);
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

        return Utils.generateID(getType().name() + sb.toString());
    }

    public List<String> getDiscussionLabels() {
        return discussionLabels;
    }

    public void setDiscussionLabels(List<String> discussionLabels) {
        this.discussionLabels = discussionLabels;
    }

}
