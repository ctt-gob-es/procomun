package com.emergya.agrega2.odes.beans;

import java.util.List;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonInclude.Include;

@JsonInclude(Include.NON_NULL)
public class OdeContentJson {
    private String label;
    private String href;
    private String id;
    private List<OdeContentJson> children;

    public String getLabel() {
        return label;
    }

    public void setLabel(String label) {
        this.label = label;
    }

    public String getHref() {
        return href;
    }

    public void setHref(String href) {
        this.href = href;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public List<OdeContentJson> getChildren() {
        return children;
    }

    public void setChildren(List<OdeContentJson> children) {
        this.children = children;
    }

}
