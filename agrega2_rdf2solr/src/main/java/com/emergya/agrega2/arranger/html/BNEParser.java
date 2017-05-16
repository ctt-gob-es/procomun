package com.emergya.agrega2.arranger.html;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;
import com.emergya.agrega2.arranger.util.Utils;
import com.emergya.agrega2.arranger.util.html.JsoupUtils;

public class BNEParser implements OriginParser {

    private static final Log LOG = LogFactory.getLog(BNEParser.class);

    public TitleLinkContent getContent(final String url) throws HTTPNotFoundException {
        final Document doc = JsoupUtils.getJsoupDocument(url, null);

        // /html/body/section/header/div[1]/h1
        final Elements elemsh1 = doc.select("html > body > section > header > div:eq(1) > h1");

        final TitleLinkContent titleLinkContent = new TitleLinkContent();

        final Element elemh1 = elemsh1.get(0);
        final String text = elemh1.text();
        if (!Utils.isEmpty(text)) {
            titleLinkContent.setTitle(text);
        } else {
            titleLinkContent.setTitle(url);
        }
        Utils.logInfo(LOG, "Got Title from URI {0} -> {1}", url, titleLinkContent.getTitle());
        return titleLinkContent;
    }

    public void testBNE() {

        String url = "http://datos.bne.es/resource/a4638182";
        BNEParser parser = new BNEParser();
        try {
            TitleLinkContent content = parser.getContent(url);
            Utils.logInfo(LOG, content.getTitle());
        } catch (HTTPNotFoundException e) {
            e.printStackTrace();
        }

    }

}
