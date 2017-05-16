package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.Date;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;

/**
 *  * This class defines a {@link SolrDocumentType} Post {@link Post}
 */
public class Webinar extends Post {

    /**
     * 
     */
    private static final long serialVersionUID = 2332474553809394485L;

    @Field
    private String webinarUrl;

    @Field
    private Date startDate;

    @Field
    private Date endDate;

    @Field
    private String duration;

    public Webinar() {
        super(SolrDocumentType.WEBINAR);
    }

    public String getWebinarUrl() {
        return webinarUrl;
    }

    public void setWebinarUrl(String webinarUrl) {
        this.webinarUrl = webinarUrl;
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

    public String getDuration() {
        return duration;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

}
