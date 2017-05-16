package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.ArrayList;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Post {@link SolrDocumentA2}
 */
public class Post extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -5292002293085205656L;

    @Field
    private List<String> postLabels;

    // New Catalog fields

    @Field
    private List<String> knowledgeArea = new ArrayList<String>();

    @Field
    private List<String> learningContext = new ArrayList<String>();

    @Field
    private List<String> generalLanguage;

    public Post() {
        super(SolrDocumentType.POST);
    }
    
    public Post(SolrDocumentType type) {
        super(type);
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

    public List<String> getPostLabels() {
        return postLabels;
    }

    public void setPostLabels(List<String> postLabels) {
        this.postLabels = postLabels;
    }

    public void addPostLabel(final String label) {
        if (!this.postLabels.contains(label) && !Utils.isEmpty(label)) {
            this.postLabels.add(label);
        }
    }

    public void addPostLabels(final List<String> labels) {
        if (labels != null) {
            for (String label : labels) {
            		addPostLabel(label);
            }
        }
    }

    public List<String> getKnowledgeArea() {
        return knowledgeArea;
    }

    public void setKnowledgeArea(List<String> knowledgeArea) {
        this.knowledgeArea = knowledgeArea;
    }

    public void addKnowledgeArea(final String area) {
        if (!this.knowledgeArea.contains(area) && !Utils.isEmpty(area)) {
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
        if (!this.learningContext.contains(context) && !Utils.isEmpty(context)) {
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

    public List<String> getGeneralLanguage() {
        return generalLanguage;
    }

    public void setGeneralLanguage(List<String> generalLanguage) {
        this.generalLanguage = generalLanguage;
    }

}
