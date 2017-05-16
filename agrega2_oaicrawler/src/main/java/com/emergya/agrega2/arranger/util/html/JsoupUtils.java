package com.emergya.agrega2.arranger.util.html;

import java.nio.charset.Charset;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;

public class JsoupUtils {

    /** Get @Jsoup @Document from given URL
     * @param url url URL to retrieve
     * @param cs URl charset
     * @return
     * @throws HTTPNotFoundException
     */
    public static Document getJsoupDocument(String url, Charset cs) throws HTTPNotFoundException {
        final String html = HTMLUtils.checkAndRetrieveHTML(url, cs);
        return Jsoup.parse(html);
    }

}
