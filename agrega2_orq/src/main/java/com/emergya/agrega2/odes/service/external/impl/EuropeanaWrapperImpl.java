package com.emergya.agrega2.odes.service.external.impl;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * @author rberenguel
 *
 */
public class EuropeanaWrapperImpl extends InterlinkingWrapper {

	private static final Log LOG = LogFactory.getLog(EuropeanaWrapperImpl.class);

	public List<String> getContent(final String titleParam) {

		List<String> result = new ArrayList<String>();

		if (!Utils.isEmpty(titleParam)) {

			final String separator = Utils.getMessage("format_separator");

			try {

				Api2Query europeanaQuery = new Api2Query();
				europeanaQuery.setQueryParams("query=".concat(titleParam.replace(" ", "+")));
				europeanaQuery.setNotProvider("Hispana");

				EuropeanaApi2Client europeanaClient = new EuropeanaApi2Client();
				EuropeanaApi2Results res = europeanaClient.searchApi2(europeanaQuery,
						Integer.valueOf(Utils.getMessage("NUM_MAX_RESULT")), 1);

				if (!Utils.isEmpty(res)) {

					for (EuropeanaApi2Item object : res.getAllItems()) {
						try {
							StringBuilder sb = new StringBuilder();

							String link = object.getGuid().substring(0, object.getGuid().indexOf("html") + 4);
							sb.append(link).append(separator).append(object.getTitle().get(0)).append(separator)
									.append(EUROPEANA_ID);
							result.add(sb.toString());
						} catch (RuntimeException e) {
							Utils.logError(LOG, e, "Europeana search have changed their structure");
						}
					}
				}
			} catch (Exception e) {
				Utils.logError(LOG, e, "Cannot get content from Europeana");
			}
		}
		return result;
	}
}
