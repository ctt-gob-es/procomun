package com.itelligent.agrega2.dal.beans;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Decisor;

public class RecomendacionSolr extends Recomendacion {

    private String title;

    private String description;

    private SolrDocumentType type;

    public RecomendacionSolr() {
        super();
    }

    public RecomendacionSolr(final Recomendacion recom) {
        super(recom.getId(), recom.getScore());
        SolrDocumentA2 doc = SolrSupport.getSolrDocumentById(String.valueOf(recom.getId()));
        if (!Utils.isEmpty(doc)) {
            title = doc.getTitle();
            description = doc.getDescription();
            type = doc.getType();
        } else {
            Decisor.removeItem(recom.getId());
        }
    }

    public String getTitle() {
        return title;
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

    public SolrDocumentType getType() {
        return type;
    }

    public void setType(SolrDocumentType type) {
        this.type = type;
    }

}
