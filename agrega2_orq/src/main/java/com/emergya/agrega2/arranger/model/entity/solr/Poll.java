package com.emergya.agrega2.arranger.model.entity.solr;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Poll {@link SolrDocumentA2}
 */
public class Poll extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -3055998709384919151L;

    public Poll() {
        super(SolrDocumentType.POLL);
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

}
