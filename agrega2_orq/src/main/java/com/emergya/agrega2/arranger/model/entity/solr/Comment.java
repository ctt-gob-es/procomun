package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.Date;

import org.apache.solr.client.solrj.beans.Field;
import org.codehaus.jackson.map.annotate.JsonSerialize;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.model.entity.json.JsonDateOdeSerializer;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 *  * This class defines a {@link SolrDocumentType} Comment {@link SolrDocumentA2}
 */
public class Comment extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = -4584814947022621413L;

    @Field
    private String commentContentId;

    @Field
    private String commentUserId;

    @Field
    private Date commentCreationDate;

    public Comment() {
        super(SolrDocumentType.COMMENT);
    }

    @Override
    public String generateId() {
        final StringBuilder sb = new StringBuilder();
        if (!Utils.isEmpty(getIdDrupal())) {
            sb.append(getIdDrupal());
        }

        return Utils.generateID(getType().name() + sb.toString());
    }

    public String getCommentContentId() {
        return commentContentId;
    }

    public void setCommentContentId(String commentContentId) {
        this.commentContentId = commentContentId;
    }

    public String getCommentUserId() {
        return commentUserId;
    }

    public void setCommentUserId(String commentUserId) {
        this.commentUserId = commentUserId;
    }

    @JsonSerialize(using = JsonDateOdeSerializer.class)
    public Date getCommentCreationDate() {
        return commentCreationDate;
    }

    public void setCommentCreationDate(Date commentCreationDate) {
        this.commentCreationDate = commentCreationDate;
    }

}
