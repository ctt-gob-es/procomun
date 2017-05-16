package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Question {@link SolrDocumentA2}
 */
public class Question extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -1430335395937578077L;

    @Field
    private String questionState;

    @Field
    private List<String> questionLabels;

    public Question() {
        super(SolrDocumentType.QUESTION);
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
        if (!Utils.isEmpty(questionState)) {
            sb.append(questionState);
        }

        return Utils.generateID(getType().name() + sb.toString());
    }

    public String getQuestionState() {
        return questionState;
    }

    public void setQuestionState(String questionState) {
        this.questionState = questionState;
    }

    public List<String> getQuestionLabels() {
        return questionLabels;
    }

    public void setQuestionLabels(List<String> questionLabels) {
        this.questionLabels = questionLabels;
    }

}
