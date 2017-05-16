package com.emergya.agrega2.arranger.model.entity.json;

import java.util.List;

public class SolrBoost {

    private List<SolrBoostItem> fieldsBoosting;

    public SolrBoost() {
        super();
    }

    public SolrBoost(List<SolrBoostItem> fieldsBoosting) {
        super();
        this.fieldsBoosting = fieldsBoosting;
    }

    public List<SolrBoostItem> getFieldsBoosting() {
        return fieldsBoosting;
    }

    public void setFieldsBoosting(List<SolrBoostItem> fieldsBoosting) {
        this.fieldsBoosting = fieldsBoosting;
    }

}
