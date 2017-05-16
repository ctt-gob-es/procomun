package com.emergya.agrega2.arranger.model.entity.solr;

/**
 *  * This class defines a generic {@link Entity}
 */
public class GenericEntity extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -4215952335403473694L;

    @Override
    public String generateId() {
        return super.getId();
    }
}
