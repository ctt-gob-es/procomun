package com.emergya.agrega2.odes.service.external.impl;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URL;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.codehaus.jackson.map.ObjectMapper;

import com.emergya.agrega2.arranger.util.impl.Utils;

public class EuropeanaApi2Client {
    private String jsonResult = "";
    private static final Log LOG = LogFactory.getLog(EuropeanaApi2Client.class);

    protected String getJSONResult(String url) throws IOException {
        return Utils.getURLContent(new URL(url), null, null, null);
    }

    public EuropeanaApi2Results searchApi2(Api2Query query, int limit, int start) throws IOException {
        String url = getQueryUrl(query, limit, start);
        return getSearchResults(url);
    }

    public String getQueryUrl(Api2Query query, long limit, long offset) throws UnsupportedEncodingException {

        StringBuilder url = buildBaseSearchUrl();
        url.append(query.getQueryParams());

        if (limit > 0)
            url.append("&rows=").append(limit);
        if (offset > 0)
            url.append("&start=").append(offset);

        return url.toString();
    }

    private StringBuilder buildBaseSearchUrl() {
        StringBuilder url = new StringBuilder();
        url.append(Utils.getMessage("europeana.api.uri"));
        url.append(Utils.getMessage("europeana.search.urn"));
        url.append("?wskey=").append(Utils.getMessage("europeana.api.key")).append("&");

        return url;
    }

    protected EuropeanaApi2Results getSearchResults(String url) throws IOException {
        // Execute Europeana API request
        this.jsonResult = getJSONResult(url);

        return parseApiResponse(jsonResult);
    }

    public EuropeanaApi2Results parseApiResponse(String jsonResult) {
        EuropeanaApi2Results res = null;
        try {
            final ObjectMapper jsonMapper = new ObjectMapper();
            res = jsonMapper.readValue(jsonResult, EuropeanaApi2Results.class);
        } catch (IOException e) {
            Utils.logError(LOG, e, "Europeana is not working correctly");
            return null;
        }
        return res;
    }
}
