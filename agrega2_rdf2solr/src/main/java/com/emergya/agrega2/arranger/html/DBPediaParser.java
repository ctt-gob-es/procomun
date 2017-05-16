package com.emergya.agrega2.arranger.html;

import java.util.List;

import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;
import com.emergya.agrega2.arranger.util.Utils;
import com.emergya.agrega2.arranger.util.html.JsoupUtils;

public class DBPediaParser implements OriginParser {

    public TitleLinkContent getContent(final String url) throws HTTPNotFoundException {
        final Document doc = JsoupUtils.getJsoupDocument(url, null);
        final Elements elemsTr = doc.getElementsByTag("tr");

        final TitleLinkContent titleLinkContent = new TitleLinkContent();

        // Only valid when we want one attribute
        boolean found = false;

        for (int i = 0; i < elemsTr.size() - 1 && !found; i++) {
            final List<Element> elemsTd = elemsTr.get(i).select("td");
            if (!Utils.isEmpty(elemsTd) && Utils.getMessage("dbpedia.title").equals(elemsTd.get(0).text())) {
                titleLinkContent.setTitle(elemsTd.get(1).text());
                found = true;
            }
        }
        return titleLinkContent;
    }

}
