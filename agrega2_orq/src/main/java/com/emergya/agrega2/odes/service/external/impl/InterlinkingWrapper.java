package com.emergya.agrega2.odes.service.external.impl;

import java.util.List;

import com.emergya.agrega2.arranger.util.impl.Utils;

public abstract class InterlinkingWrapper {

	public static final String REDINED_ID = "REDINED";
	public static final String MUSEO_PRADO_ID = "MUSEO_PRADO";
	public static final String EUROPEANA_ID = "EUROPEANA";
	public static final String HISPANA_ID = "HISPANA";

    public static final String SEPARATOR = Utils.getMessage("SOLR_URL_PREFIX");

    public abstract List<String> getContent(final String query);

    // public abstract List<String> mergeContent(List<String> originalContent,
    // final String title);

    public String generateTitleLink(final String url, final String title, final String origin) {
        StringBuilder sb = new StringBuilder();
        sb.append(url);
        sb.append(InterlinkingWrapper.SEPARATOR);
        sb.append(title);
        sb.append(InterlinkingWrapper.SEPARATOR);
        sb.append(origin);

        return sb.toString();
    }

}
