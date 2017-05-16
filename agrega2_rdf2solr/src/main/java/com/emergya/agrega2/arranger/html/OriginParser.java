package com.emergya.agrega2.arranger.html;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;

public interface OriginParser {

    public TitleLinkContent getContent(final String url) throws HTTPNotFoundException;

}
