package com.emergya.agrega2.odes.service.external.impl;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.solr.client.solrj.impl.XMLResponseParser;
import org.apache.solr.common.SolrDocument;
import org.apache.solr.common.SolrDocumentList;
import org.apache.solr.common.util.NamedList;

import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * @author ajrodriguez
 *
 */
public class RedinedSolrWrapperImpl extends InterlinkingWrapper {

    private static final Log LOG = LogFactory.getLog(RedinedSolrWrapperImpl.class);

    static final String TITLE_FIELD = "title";
	static final String URL_FIELD = "dc.identifier.uri";		

	static final String KEY_RESPONSE_FIELD = "response";

	public List<String> getContent(final String titleParam) {
		final String url = getRedinedUrl(titleParam);
		return processRedinedUrl(url);
	}

	private String getRedinedUrl(final String titleParam) {

		String redinedUrl = Utils.getMessage("REDINED_SOLR_URL");

		StringBuilder sbRedinedUrl = new StringBuilder(redinedUrl);
		sbRedinedUrl.append("q=title:").append(titleParam.replace(" ", "+")).append("&");
		sbRedinedUrl.append("fl=").append(TITLE_FIELD).append(",").append(URL_FIELD);

		return sbRedinedUrl.toString();
	}

	@SuppressWarnings("unchecked")
	private List<String> processRedinedUrl(final String url) {

		final String separator = Utils.getMessage("format_separator");

		List<String> result = new ArrayList<String>();
		String urlContent = null;

		try {
			urlContent = Utils.getURLContent(new URL(url), null, null, null);

			if (!Utils.isEmpty(urlContent)) {

				final XMLResponseParser responseParser = new XMLResponseParser();
				final NamedList<Object> solrResponse = responseParser
						.processResponse(new BufferedReader(new StringReader(urlContent)));
				final SolrDocumentList doclist = (SolrDocumentList) solrResponse.get(KEY_RESPONSE_FIELD);

				for (SolrDocument doc : doclist) {

					try {

						final String title = (String) doc.getFieldValue(TITLE_FIELD);

						if (doc.getFieldValue(URL_FIELD) instanceof List) {
							final List<String> uriList = (List<String>) doc.getFieldValue(URL_FIELD);
							for (String uri : uriList) {
								StringBuilder sb = new StringBuilder();
								sb.append(uri).append(separator).append(title).append(separator)
										.append(REDINED_ID);
								result.add(sb.toString());
							}
						} else {
							final String uri = (String) doc.getFieldValue(URL_FIELD);
							StringBuilder sb = new StringBuilder();
							sb.append(uri).append(separator).append(title).append(separator).append(REDINED_ID);
							result.add(sb.toString());
						}
					} catch (ClassCastException e) {
						Utils.logError(LOG, e, "Some of output fields have changed their type");
					}
				}
			}
		} catch (IOException e) {
			Utils.logError(LOG, "Cannot get content from REDINED URL: {0}", url);
		}
		return result;
	}
}
