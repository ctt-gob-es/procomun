/*
 * EuropeanaResults.java - europeana4j
 * (C) 2011 Digibis S.L.
 */
package com.emergya.agrega2.odes.service.external.impl;

import java.util.Collections;
import java.util.List;

import org.codehaus.jackson.annotate.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class EuropeanaApi2Results {
    public List<EuropeanaApi2Item> getAllItems() {
        if (this.getItems() == null) {
            return Collections.emptyList();
        } else {
            return Collections.unmodifiableList(this.getItems());
        }
    }

    protected long totalResults;

    private List<EuropeanaApi2Item> items;

    public List<EuropeanaApi2Item> getItems() {
        return items;
    }

    public void setItems(List<EuropeanaApi2Item> items) {
        this.items = items;
    }

}
