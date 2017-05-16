package com.emergya.agrega2.odes.service.external.impl;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import com.emergya.agrega2.arranger.util.impl.JsoupUtils;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * @author rberenguel
 *
 */
public class HispanaWrapperImpl extends InterlinkingWrapper {

    private static final Log LOG = LogFactory.getLog(HispanaWrapperImpl.class);

    public List<String> getContent(final String titleParam) {

		List<String> result = new ArrayList<String>();
		String searchUrl = null;

		if (!Utils.isEmpty(titleParam)) {

			final String separator = Utils.getMessage("format_separator");

			try {

				searchUrl = Utils.getMessage("hispana.url", titleParam.replace(" ", "+"));
				
				Document document = JsoupUtils.getJsoupDocument(searchUrl, null);
				Elements elements = document.select("ns1|record");
				
				for (Element element : elements) {
					try {
						final String title = element.select("dc|title").text();
						final String uri = element.select("dc|identifier").text();

						StringBuilder sb = new StringBuilder();
						sb.append(uri).append(separator).append(title).append(separator).append(HISPANA_ID);
						result.add(sb.toString());
					} catch (RuntimeException e) {
						Utils.logError(LOG, e, "Hispana search have changed their structure");
					}
				}

			} catch (Exception e) {
				Utils.logError(LOG, e, "Cannot get content from Hispana URL: {0}: " + searchUrl);
			}
		}
		return result;
	}
}
