package com.emergya.agrega2.arranger.util;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.text.MessageFormat;
import java.util.Collection;
import java.util.Map;
import java.util.Properties;

import org.apache.commons.codec.digest.DigestUtils;
import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;

/**
 * Util methods for the arranger
 */
public class Utils {

    private static final Log LOG = LogFactory.getLog(Utils.class);

    private static Properties props = new Properties();

    static {

        try {
            props.load(new InputStreamReader(Utils.class.getResourceAsStream("/properties/general.properties"), "UTF-8"));
        } catch (final Exception e) {
            throw new ExceptionInInitializerError(e);
        }

    }

    public static String getMessage(String property, Object... params) {
        return MessageFormat.format(props.getProperty(property), params);
    }

    /**
     * Get response content from an URL
     * 
     * @param urlObject
     *            URL to get content from
     * @param encoding
     *            Encoding of the content
     * @return URL Response String
     * @throws IOException
     */
    public static String getURLContent(URL urlObject, String encoding) throws IOException {
        final URLConnection conn = urlObject.openConnection();
        final InputStream inputStream = conn.getInputStream();
        return IOUtils.toString(inputStream, encoding);
    }

    public static boolean isEmpty(final String text) {
        return text == null || text.trim().length() == 0;
    }

    public static boolean isEmpty(final Collection<?> collection) {
        return collection == null || collection.size() == 0;
    }

    public static boolean equals(final String s1, final String s2) {
        if (s1 == null && s2 == null) {
            return true;
        }
        if ((s1 != null && s2 == null) || (s1 == null && s2 != null)) {
            return false;
        }
        return s1.equals(s2);
    }

    public static boolean isEmpty(final byte[] bytes) {
        return bytes == null || bytes.length == 0;
    }

    public static boolean isEmpty(final Object[] bytes) {
        return bytes == null || bytes.length == 0;
    }

    @SuppressWarnings("rawtypes")
    public static boolean isEmpty(final Map value) {
        return value == null || value.size() == 0;
    }

    public static boolean isEmpty(final Object value) {
        if (value instanceof Collection && Utils.isEmpty((Collection<?>) value)) {
            return true;
        } else if (value instanceof String && Utils.isEmpty((String) value)) {
            return true;
        } else if (value == null) {
            return true;
        }

        return false;
    }

    private static Object[] union(final Object arg0, final Object... args) {
        final int size = 1 + (args != null ? args.length : 0);
        if (size > 0) {
            final Object[] a = new Object[size];
            a[0] = arg0;
            if (args != null) {
                System.arraycopy(args, 0, a, 1, args.length);
            }
            return a;
        }
        return null;
    }

    public static void logTrace(final Log log, final Object message) {
        if (log != null && log.isTraceEnabled()) {
            log.trace(message);
        }
    }

    public static void logTrace(final Log log, final String message, final Object arg0, final Object... args) {
        if (log != null && log.isTraceEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            log.trace(m);
        }
    }

    public static void logDebug(final Log log, final Object message) {
        if (log != null && log.isDebugEnabled()) {
            log.debug(message);
        }
    }

    public static void logDebug(final Log log, final String message, final Object arg0, final Object... args) {
        if (log != null && log.isDebugEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            log.debug(m);
        }
    }

    public static void logInfo(final Log log, final Object message) {
        if (log != null && log.isInfoEnabled()) {
            log.info(message);
        }
    }

    public static void logInfo(final Log log, final String message, final Object arg0, final Object... args) {
        if (log != null && log.isInfoEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            log.info(m);
        }
    }

    public static void logWarn(final Log log, final String message) {
        logWarn(log, null, message);
    }

    public static void logWarn(final Log log, final Throwable t, final String message, final Object arg0,
            final Object... args) {
        if (log != null && log.isWarnEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            logWarn(log, t, m);
        }
    }

    public static void logWarn(final Log log, final Throwable t, final Object message) {
        if (log != null && log.isWarnEnabled()) {
            if (t != null && message == null) {
                log.warn("Warning!", t);
            } else if (t == null && message != null) {
                log.warn(message);
            } else if (t != null && message != null) {
                log.warn(message, t);
            }
        }
    }

    public static void logWarn(final Log log, final String message, final String arg0, final Object... args) {
        if (log != null && log.isWarnEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            logWarn(log, null, m);
        }
    }

    public static void logError(final Log log, final String message) {
        logError(log, null, message);
    }

    public static void logError(final Log log, final String message, final String arg0, final Object... args) {
        if (log != null && log.isErrorEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            logError(log, null, m);
        }
    }

    public static void logError(final Log log, final Throwable t) {
        logError(log, t, null);
    }

    public static void logError(final Log log, final Throwable t, final Object message) {
        if (log != null && log.isErrorEnabled()) {
            if (t != null && message == null) {
                log.error("Error!", t);
            } else if (t == null && message != null) {
                log.error(message);
            } else if (t != null && message != null) {
                log.error(message, t);
            }
        }
    }

    public static void logError(final Log log, final Throwable t, final String message, final Object arg0,
            final Object... args) {
        if (log != null && log.isErrorEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            logError(log, t, m);
        }
    }

    public static String MD5(final String text) {
        if (text != null && text.length() > 0) {
            return DigestUtils.md5Hex(text);
        }
        return null;
    }

    private static String generateTempFileFromResource(final String resourcePath, final String extension) {
        final Resource classPathResource = new ClassPathResource(resourcePath);
        String path = "";

        try {
            final InputStream inputStream = classPathResource.getInputStream();
            Utils.logInfo(LOG, "Reading File: {0}", resourcePath);
            final File tempFile = File.createTempFile("map", extension);
            tempFile.deleteOnExit();
            try (FileOutputStream out = new FileOutputStream(tempFile)) {
                IOUtils.copy(inputStream, out);
            }
            path = tempFile.getAbsolutePath();
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot read File: {0}", resourcePath);
        }
        return path;
    }

    public static String getFormatSeparator() {
        return getMessage("format_separator");
    }

}
