package com.emergya.agrega2.arranger.html;

import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;
import com.emergya.agrega2.arranger.util.Utils;
import com.emergya.agrega2.arranger.util.html.JsoupUtils;

public class CulturaParser implements OriginParser {

    private static final Log LOG = LogFactory.getLog(OriginParser.class);

    public TitleLinkContent getContent(final String url) throws HTTPNotFoundException {
        final Document doc = JsoupUtils.getJsoupDocument(url, null);
        final Elements elemsTr = doc.getElementsByTag("tr");

        final TitleLinkContent titleLinkContent = new TitleLinkContent();

        // Only valid when we want get one attribute
        boolean found = false;

        for (int i = 0; i < elemsTr.size() - 1 && !found; i++) {
            final List<Element> elemsTd = elemsTr.get(i).select("td");
            if (!Utils.isEmpty(elemsTd) && Utils.getMessage("cultura.title").equals(elemsTd.get(0).text())) {
                titleLinkContent.setTitle(elemsTd.get(1).text());
                found = true;
            }
        }
        Utils.logInfo(LOG, "Got Title from URI {0} -> {1}", url, titleLinkContent.getTitle());
        return titleLinkContent;
    }

    public static void main(String args[]) {

        String url = "http://cultura.linkeddata.es/page/BNE/resource/C1001/XX3225905";
        CulturaParser parser = new CulturaParser();
        try {
            TitleLinkContent content = parser.getContent(url);
            System.out.println(content.getTitle());
        } catch (HTTPNotFoundException e) {
            e.printStackTrace();
        }

    }

}
