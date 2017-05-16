package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Post {@link SolrDocumentA2}
 */
public class Url extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = 856015776726412783L;

    @Field
    private String url;

    @Field
    private List<String> generalLanguage;

    public Url() {
        super(SolrDocumentType.URL);
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public List<String> getGeneralLanguage() {
        return generalLanguage;
    }

    public void setGeneralLanguage(List<String> generalLanguage) {
        this.generalLanguage = generalLanguage;
    }

    @Override
    public String generateId() {
        final StringBuilder sb = new StringBuilder();
        if (!Utils.isEmpty(getUrl())) {
            sb.append(getUrl());
        }
        if (!Utils.isEmpty(getIdDrupal())) {
            sb.append(getIdDrupal());
        }

        return Utils.generateID(getType().name() + sb.toString());
    }

}
