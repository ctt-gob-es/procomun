package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.Date;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Event {@link SolrDocumentA2}
 */
public class Event extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -3055998709384919151L;

    @Field
    private List<String> eventLabels;

    @Field
    private Date startDate;

    @Field
    private Date endDate;

    public Event() {
        super(SolrDocumentType.EVENT);
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

    public List<String> getEventLabels() {
        return eventLabels;
    }

    public void setEventLabels(List<String> eventLabels) {
        this.eventLabels = eventLabels;
    }

    public Date getStartDate() {
        return startDate;
    }

    public void setStartDate(Date startDate) {
        this.startDate = startDate;
    }

    public Date getEndDate() {
        return endDate;
    }

    public void setEndDate(Date endDate) {
        this.endDate = endDate;
    }

}
