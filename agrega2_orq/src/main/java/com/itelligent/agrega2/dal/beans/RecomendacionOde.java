package com.itelligent.agrega2.dal.beans;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;

public class RecomendacionOde extends Recomendacion {

    private String odeTitle;

    private String odeDescription;

    public RecomendacionOde() {
        super();
    }

    public RecomendacionOde(final Recomendacion recom) {
        super(recom.getId(), recom.getScore());
        SolrDocumentA2 doc = (Ode) SolrSupport.getSolrDocumentById(String.valueOf(recom.getId()));
        odeTitle = doc.getTitle();
        odeDescription = doc.getDescription();
    }

    public String getOdeTitle() {
        return odeTitle;
    }

    public void setOdeTitle(String odeTitle) {
        this.odeTitle = odeTitle;
    }

    public String getOdeDescription() {
        return odeDescription;
    }

    public void setOdeDescription(String odeDescription) {
        this.odeDescription = odeDescription;
    }

}
