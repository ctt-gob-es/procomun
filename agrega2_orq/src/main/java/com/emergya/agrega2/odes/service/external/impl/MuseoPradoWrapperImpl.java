package com.emergya.agrega2.odes.service.external.impl;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.select.Elements;

import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * @author rberenguel
 *
 */
public class MuseoPradoWrapperImpl extends InterlinkingWrapper {

    private static final Log LOG = LogFactory.getLog(MuseoPradoWrapperImpl.class);

    private static final String USER_AGENT = "Mozilla/5.0 (Windows; U; WindowsNT 5.1; en-US; rv1.8.1.6) Gecko/20070725 Firefox/2.0.0.6";

	public List<String> getContent(final String titleParam) {

		List<String> result = new ArrayList<String>();
		String searchUrl = null;

		if (!Utils.isEmpty(titleParam)) {

			final String separator = Utils.getMessage("format_separator");
			final Integer maxResults = Integer.valueOf(Utils.getMessage("NUM_MAX_RESULT"));

			try {

				searchUrl = Utils.getMessage("elprado.url") + titleParam.replace(" ", "+");

				Document document = Jsoup.connect(searchUrl).followRedirects(true).timeout(2000)
						.userAgent(USER_AGENT).referrer("http://www.google.com").get();
				final Elements elements = document.select("div#panResultados > div > figure");

				if(!Utils.isEmpty(elements)){
					for (int counter = 0; counter < maxResults; counter++) {

						try {
							Elements titles = elements.get(counter)
									.select("figure > figcaption.presentacion-listado > dl > dt > a");
							final String title = titles.text();
							final String uri = titles.attr("href");

							StringBuilder sb = new StringBuilder();
							sb.append(uri).append(separator).append(title).append(separator).append(MUSEO_PRADO_ID);
							result.add(sb.toString());

						} catch (RuntimeException e) {
							Utils.logError(LOG, e, "Museo del Prado search have changed their structure");
						}
					}
				}					
			} catch (Exception e) {
				Utils.logError(LOG, e, "Cannot get content from Museo del Prado URL: {0}", searchUrl);
			}
		}
		return result;
	}
}
