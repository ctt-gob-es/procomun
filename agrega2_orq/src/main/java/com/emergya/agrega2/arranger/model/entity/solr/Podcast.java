package com.emergya.agrega2.arranger.model.entity.solr;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;

/**
 *  * This class defines a {@link SolrDocumentType} Post {@link Post}
 */
public class Podcast extends Post {
  
    /**
	 * 
	 */
	private static final long serialVersionUID = 2332474553809394485L;
	
	@Field("podcastUrl")
    private String podcastUrl;

	public Podcast() {
        super(SolrDocumentType.PODCAST);
    }

	public String getPodcastUrl() {
		return podcastUrl;
	}

	public void setPodcastUrl(String podcastUrl) {
		this.podcastUrl = podcastUrl;
	}
}
