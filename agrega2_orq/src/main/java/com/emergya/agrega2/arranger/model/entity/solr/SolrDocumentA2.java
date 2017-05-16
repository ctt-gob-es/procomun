package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.Date;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;

/**
 * Base Solr Document Entity. Contains all common fields, Mandatory fields, between {@link SolrDocumentType}
 */
public abstract class SolrDocumentA2 extends Entity {

    /**
     * 
     */
    private static final long serialVersionUID = -163977987202448424L;

    @Field("type")
    private SolrDocumentType type;

    @Field("title")
    private String title;

    @Field("description")
    private String description;

    @Field("idDrupal")
    private String idDrupal;

    @Field("labels")
    private List<String> labels;

    @Field("published")
    private String published;

    @Field("certified")
    private String certified;

    @Field("category")
    private String category;

    @Field
    private Date publicationDate;

    // URI to preview
    @Field
    private String preview;

    @Field("novelty")
    private String novelty;

    public SolrDocumentA2() {
        super();
    }

    public SolrDocumentA2(SolrDocumentType type) {
        super();
        this.type = type;
    }

    /** Method that returns a UUID of @SolrDocument object. Must be implemented by each subclass.
     * @return String that represents the UUID.
     */
    public abstract String generateId();

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public SolrDocumentType getType() {
        return type;
    }

    public void setType(SolrDocumentType type) {
        this.type = type;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getIdDrupal() {
        return idDrupal;
    }

    public void setIdDrupal(String idDrupal) {
        this.idDrupal = idDrupal;
    }

    public List<String> getLabels() {
        return labels;
    }

    public void setLabels(List<String> labels) {
        this.labels = labels;
    }

    public String getPublished() {
        return published;
    }

    public void setPublished(String published) {
        this.published = published;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getPreview() {
        return preview;
    }

    public void setPreview(String preview) {
        this.preview = preview;
    }

    public String getCertified() {
        return certified;
    }

    public void setCertified(String certified) {
        this.certified = certified;
    }

    public Date getPublicationDate() {
        return publicationDate;
    }

    public void setPublicationDate(Date publicationDate) {
        this.publicationDate = publicationDate;
    }

    public String getNovelty() {
        return novelty;
    }

    public void setNovelty(String novelty) {
        this.novelty = novelty;
    }

}
