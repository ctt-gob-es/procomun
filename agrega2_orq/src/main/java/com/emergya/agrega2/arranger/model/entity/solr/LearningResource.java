package com.emergya.agrega2.arranger.model.entity.solr;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * This class defines a {@link SolrDocumentType} Learning Resource {@link SolrDocumentA2}
 */
public class LearningResource extends LearningObject {

    /**
     * 
     */
    private static final long serialVersionUID = -1699117943258442715L;

    public LearningResource() {
        super(SolrDocumentType.LEARNING_RESOURCE);
    }

    public String generateId() {
        return Utils.generateID(getType().name() + getIdDrupal());
    }

}
