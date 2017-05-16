/*
 * EuropeanaItem.java - europeana4j
 * (C) 2011 Digibis S.L.
 */
package com.emergya.agrega2.odes.service.external.impl;

import java.util.List;

import org.codehaus.jackson.annotate.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class EuropeanaApi2Item {

    protected List<String> title;
    protected String guid;

    public List<String> getTitle() {
        return title;
    }

    public void setTitle(List<String> title) {
        this.title = title;
    }

    public String getGuid() {
        return guid;
    }

    public void setGuid(String guid) {
        this.guid = guid;
    }

}
