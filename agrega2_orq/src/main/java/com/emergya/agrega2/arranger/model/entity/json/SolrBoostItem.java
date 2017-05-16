package com.emergya.agrega2.arranger.model.entity.json;

public class SolrBoostItem {

    private String fieldName;

    private String boosting;

    private String description;

    public SolrBoostItem() {
        super();
    }

    public SolrBoostItem(String fieldName, String boosting, String description) {
        super();
        this.fieldName = fieldName;
        this.boosting = boosting;
        this.description = description;
    }

    public String getFieldName() {
        return fieldName;
    }

    public void setFieldName(String fieldName) {
        this.fieldName = fieldName;
    }

    public String getBoosting() {
        return boosting;
    }

    public void setBoosting(String boosting) {
        this.boosting = boosting;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

}
