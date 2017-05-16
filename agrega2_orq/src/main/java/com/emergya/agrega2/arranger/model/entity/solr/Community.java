package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Community {@link SolrDocumentA2}
 */
public class Community extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -8365055480921129935L;

    @Field
    private Date communityDate;

    @Field
    private List<String> communityLabels;

    @Field
    private List<String> communityAdminSups;

    @Field
    private List<String> knowledgeArea = new ArrayList<String>();

    @Field
    private List<String> learningContext = new ArrayList<String>();

    public Community() {
        super(SolrDocumentType.COMMUNITY);
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
        if (!Utils.isEmpty(communityDate)) {
            sb.append(communityDate);
        }

        return Utils.generateID(getType().name() + sb.toString());
    }

    public Date getCommunityDate() {
        return communityDate;
    }

    public void setCommunityDate(Date communityDate) {
        this.communityDate = communityDate;
    }

    public List<String> getCommunityLabels() {
        return communityLabels;
    }

    public void setCommunityLabels(List<String> communityLabels) {
        this.communityLabels = communityLabels;
    }

    public void addCommunityLabel(final String label) {
        if (!this.communityLabels.contains(label)) {
            this.communityLabels.add(label);
        }
    }

    public void addCommunityLabels(final List<String> labels) {
        if (labels != null) {
            for (String label : labels) {
                addCommunityLabel(label);
            }
        }
    }

    public List<String> getCommunityAdminSups() {
        return communityAdminSups;
    }

    public void setCommunityAdminSups(List<String> communityAdminSups) {
        this.communityAdminSups = communityAdminSups;
    }

    public List<String> getKnowledgeArea() {
        return knowledgeArea;
    }

    public void setKnowledgeArea(List<String> knowledgeArea) {
        this.knowledgeArea = knowledgeArea;
    }

    public void addKnowledgeArea(final String area) {
        if (!this.knowledgeArea.contains(area)) {
            this.knowledgeArea.add(area);
        }
    }

    public void addKnowledgeAreas(final List<String> areas) {
        if (areas != null) {
            for (String area : areas) {
                addKnowledgeArea(area);
            }
        }
    }

    public List<String> getLearningContext() {
        return learningContext;
    }

    public void setLearningContext(List<String> learningContext) {
        this.learningContext = learningContext;
    }

    public void addLearningContext(final String context) {
        if (!this.learningContext.contains(context)) {
            this.learningContext.add(context);
        }
    }

    public void addLearningContexts(final List<String> contexts) {
        if (contexts != null) {
            for (String context : contexts) {
                addLearningContext(context);
            }
        }
    }

}
