package com.emergya.agrega2.arranger.util.html;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.nio.charset.Charset;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;
import com.emergya.agrega2.arranger.util.Utils;

public class HTMLUtils {

    private static final Log LOG = LogFactory.getLog(HTMLUtils.class);

    private static final ThreadLocal<Set<String>> VISITED_URLS = new ThreadLocal<Set<String>>();
    private static final String LINE = System.getProperties().getProperty("line.separator");

    private static final Pattern CHARSET_PATTERN = Pattern.compile("(?i)\\bcharset=\\s*\"?([^\\s;\"]*)");
    public static final Charset LATIN1_CHARSET = Charset.forName("ISO-8859-1");

    public static String checkAndRetrieveHTML(String url, Charset cs) throws HTTPNotFoundException {
        final Content content = HTMLUtils.getContent(url, cs);
        if (content != null) {
            final String html = content.getContentAsString();

            if (html == null) {
                Utils.logError(LOG, "URL: {0}, Response Code: {1}", url, content.getResponseCode());
                return null;
            }
            if (content.getResponseCode() == HttpURLConnection.HTTP_NOT_FOUND) {
                throw new HTTPNotFoundException();
            }

            return html;
        } else {
            return "";
        }
    }

    public static Content getContent(final String url, final Charset cs) {
        if (!Utils.isEmpty(url)) {
            URL urlObject;
            try {
                urlObject = new URL(url);
                return HTMLUtils.getContent(urlObject, null, null, true, cs);
            } catch (final MalformedURLException e) {
                Utils.logError(LOG, e);
            }
        }
        return null;
    }

    public static Content getContent(final URL urlObject, final String initDelimiter, final String endDelimiter,
            final boolean followRedirects, final Charset cs) {

        if (urlObject != null) {
            try {
                URLConnection conn = urlObject.openConnection();
                if (conn instanceof HttpURLConnection) {
                    final HttpURLConnection httpConn = (HttpURLConnection) conn;
                    httpConn.setRequestProperty("Accept", "text/html,application/xml");
                    final int responseCode = httpConn.getResponseCode();
                    if (followRedirects) {
                        if (isRedirectCode(responseCode)) {
                            final String location = httpConn.getHeaderField("Location");
                            if (Utils.isEmpty(location)) {
                                Utils.logError(LOG, "Empty redirect location!");
                                return null;
                            }
                            Set<String> visited = VISITED_URLS.get();
                            final boolean cleanAfter = visited == null;
                            try {
                                if (visited == null) {
                                    visited = new HashSet<String>();
                                    VISITED_URLS.set(visited);
                                }
                                visited.add(urlObject.toString());
                                final URL locationUrl = new URL(location);
                                if (visited.contains(locationUrl.toString())) {
                                    Utils.logError(LOG, "Cyclic redirect!");
                                    return null;
                                }
                                return getContent(locationUrl, initDelimiter, endDelimiter, followRedirects, cs);
                            } finally {
                                if (cleanAfter)
                                    VISITED_URLS.remove();
                            }
                        }
                    }
                    final String contentType = conn.getContentType().toLowerCase();
                    final String charsetName = cs == null ? charsetNameFromContentType(contentType) : cs.name();
                    if (contentType.startsWith("text/") || contentType.startsWith("application/xml")) {
                        final String stringContent = readContentAsString(
                                responseCode == HttpURLConnection.HTTP_OK ? conn.getInputStream()
                                        : httpConn.getErrorStream(), charsetName, initDelimiter, endDelimiter);
                        return createContent(contentType, charsetName, stringContent, responseCode);
                    } else {
                        if (LOG.isErrorEnabled())
                            LOG.error("Unsupported content type!");
                    }
                } else {
                    if (LOG.isErrorEnabled())
                        LOG.error("Unsupported protocol!");
                }
            } catch (final IOException e) {
                if (LOG.isErrorEnabled()) {
                    LOG.error(e);
                }
            }
        }
        return null;
    }

    private static String readContentAsString(final InputStream is, final String charsetName,
            final String initDelimiter, final String endDelimiter) throws IOException {
        final int initDelimiterLength = Utils.isEmpty(initDelimiter) ? 0 : initDelimiter.length();
        final boolean hasEndDelimiter = !Utils.isEmpty(endDelimiter);
        final BufferedReader br = new BufferedReader(new InputStreamReader(is, charsetName));
        final StringBuilder sb = new StringBuilder();
        for (String line = br.readLine(); line != null; line = br.readLine()) {
            if (initDelimiterLength == 0) {
                sb.append(line);
            } else {
                if (sb.length() > 0) {
                    sb.append(line);
                } else {
                    final int initIndex = line.indexOf(initDelimiter);
                    if (initIndex > -1 && line.length() > initDelimiterLength) {
                        sb.append(line.substring(initIndex + initDelimiterLength));
                    }
                }
            }
            if (sb.length() > 0)
                sb.append(LINE);
            if (hasEndDelimiter && sb.length() > 0) {
                final int endIndex = sb.indexOf(endDelimiter);
                if (endIndex > 0) {
                    sb.substring(0, endIndex);
                    break;
                }
            }
        }
        br.close();
        return sb.toString();
    }

    private static final boolean isRedirectCode(final int responseCode) {
        return responseCode == HttpURLConnection.HTTP_MOVED_PERM || responseCode == HttpURLConnection.HTTP_MOVED_TEMP
                || responseCode == HttpURLConnection.HTTP_SEE_OTHER || responseCode == 307;
    }

    /**
     * Returns a charset name from an http content type header.
     * @param contentType an http content type header.
     * @return a Charset name.
     */
    public static String charsetNameFromContentType(final String contentType) {
        final Matcher m = CHARSET_PATTERN.matcher(contentType);
        if (m.find()) {
            final String cs = m.group(1).trim().toUpperCase();
            return cs;
        }
        // return DEFAULT_CHARSET.name();
        return LATIN1_CHARSET.name();
    }

    private static Content createContent(final String contentType, final String charsetName,
            final String stringContent, final int responseCode) {
        return new Content() {

            @Override
            public String getContentType() {
                return contentType;
            }

            @Override
            public String getContentAsString() {
                return stringContent;
            }

            @Override
            public String getCharsetName() {
                return charsetName;
            }

            @Override
            public int getResponseCode() {
                return responseCode;
            }
        };

    }

}
