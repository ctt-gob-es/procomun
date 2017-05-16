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
public class LearningPath extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -8577519689739898484L;

    @Field
    private Date learningPathDate;

    @Field
    private String baseItinerary;

    @Field
    private List<String> itineraryContent;

    @Field
    private List<String> interestContent;

    @Field
    private List<String> knowledgeArea = new ArrayList<String>();

    @Field
    private List<String> learningContext = new ArrayList<String>();

    public LearningPath() {
        super(SolrDocumentType.LEARNING_PATH);
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
        if (!Utils.isEmpty(learningPathDate)) {
            sb.append(learningPathDate);
        }

        return Utils.generateID(getType().name() + sb.toString());
    }

    public String getBaseItinerary() {
        return baseItinerary;
    }

    public void setBaseItinerary(String baseItinerary) {
        this.baseItinerary = baseItinerary;
    }

    public List<String> getItineraryContent() {
        return itineraryContent;
    }

    public void setItineraryContent(List<String> itineraryContent) {
        this.itineraryContent = itineraryContent;
    }

    public List<String> getInterestContent() {
        return interestContent;
    }

    public void setInterestContent(List<String> interestContent) {
        this.interestContent = interestContent;
    }

    public List<String> getKnowledgeArea() {
        return knowledgeArea;
    }

    public void setKnowledgeArea(List<String> knowledgeArea) {
        this.knowledgeArea = knowledgeArea;
    }

    public List<String> getLearningContext() {
        return learningContext;
    }

    public void setLearningContext(List<String> learningContext) {
        this.learningContext = learningContext;
    }

}
