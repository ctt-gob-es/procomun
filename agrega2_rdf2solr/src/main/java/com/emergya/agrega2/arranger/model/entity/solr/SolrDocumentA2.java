package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;

/**
 * Base Solr Document Entity. Contains all common fields between @SolrDocumentType
 */
public abstract class SolrDocumentA2 extends Entity {

    /**
     * 
     */
    private static final long serialVersionUID = -163977987202448424L;

    public SolrDocumentA2() {
        super();
    }

    public SolrDocumentA2(SolrDocumentType type) {
        super();
        this.type = type;
    }

    @Field("type")
    private SolrDocumentType type;

    @Field("title")
    private String title;

    @Field("description")
    private String description;

    @Field("labels")
    private List<String> labels;

    @Field("idDrupal")
    private String idDrupal;

    public abstract String generateId();

    public String getTitle() {
        return title;
    }

    public SolrDocumentType getType() {
        return type;
    }

    public void setType(SolrDocumentType type) {
        this.type = type;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public List<String> getLabels() {
        return labels;
    }

    public void setLabels(List<String> labels) {
        this.labels = labels;
    }

    public String getIdDrupal() {
        return idDrupal;
    }

    public void setIdDrupal(String idDrupal) {
        this.idDrupal = idDrupal;
    }

}
