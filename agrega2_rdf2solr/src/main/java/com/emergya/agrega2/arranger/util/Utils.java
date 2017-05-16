package com.emergya.agrega2.arranger.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.concurrent.atomic.AtomicLong;

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

    private static AtomicLong currentMillis;

    private static Map<String, String> accesibilidad;
    private static Map<String, String> arbol_curricular;
    private static Map<String, String> competencias;
    private static Map<String, String> licencias;
    private static Map<String, String> nivel_educativo;

    private static Map<String, String> accesibilidadLabel;
    private static Map<String, String> arbolCurricularLabel;
    private static Map<String, String> competenciasLabel;
    private static Map<String, String> licenciasLabel;
    private static Map<String, String> nivelEducativoLabel;

    private static Map<String, List<String>> curricularTreeLomes;
    private static Map<String, List<String>> curricularTreeEtb;

    private static Map<String, List<String>> learningContextLomes;
    private static Map<String, List<String>> learningContextEtb;

    private static Map<String, List<String>> resourceTypeLomes;

    static {

        currentMillis = new AtomicLong(System.currentTimeMillis());

        try {
            props.load(new InputStreamReader(Utils.class.getResourceAsStream("/properties/general.properties"), "UTF-8"));
        } catch (final Exception e) {
            throw new ExceptionInInitializerError(e);
        }

        /**
         * Load Drupal IDs Maps
         * */
        accesibilidad = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.accesibilidad"), false);
        arbol_curricular = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.arbol_curricular"), false);
        competencias = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.competencias"), false);
        licencias = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.licencias"), false);
        nivel_educativo = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.nivel_educativo"), false);

        accesibilidadLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.accesibilidad"), null);
        arbolCurricularLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.arbol_curricular"), null);
        competenciasLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.competencias"), null);
        licenciasLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.licencias"), null);
        nivelEducativoLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.nivel_educativo"), null);
        curricularTreeLomes = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.areaconocimiento"), "LOE");
        curricularTreeEtb = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.areaconocimiento"), "ETB");
        learningContextLomes = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.contextoeducativo"), "LOM-ES");
        learningContextEtb = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.contextoeducativo"), "ETB");
        resourceTypeLomes = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.tiporecurso"), "LOM-ES");

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

    public static void logWarn(final Log log, final Throwable t, final String message, final Object arg0, final Object... args) {
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

    public static void logError(final Log log, final Throwable t, final String message, final Object arg0, final Object... args) {
        if (log != null && log.isErrorEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a != null ? MessageFormat.format(message, a) : message;
            logError(log, t, m);
        }
    }

    public static String generateID() {
        return String.valueOf(getCurrentMillis());
    }

    public static String MD5(final String text) {
        if (text != null && text.length() > 0) {
            return DigestUtils.md5Hex(text);
        }
        return null;
    }

    /** Load a Map<K, V> from a CSV with columns (K,V)
     * @param path to CSV
     * @return Map<K, V>
     */
    public static Map<String, String> loadCSV(final String path, final Boolean reverse) {
        final Map<String, String> data = new HashMap<String, String>();
        final String csvFile = path;
        final String cvsSplitBy = ",";

        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(cvsSplitBy);
                try {
                    /* Id Taxon */
                    final String key = dataRow[1].split("-")[0].replace("\"", "").trim();
                    /* Id Drupal */
                    final String value = dataRow[0].replace("\"", "");
                    if (reverse == null) {
                        data.put(key, dataRow[1].replace("\"", ""));
                    } else if (!reverse) {
                        data.put(key, value);
                    } else {
                        data.put(value, key);
                    }

                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, "ArrayIndexOutOfBoundsException on Utils.loadCSV");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e, "Cannot extract key on String: {0}", dataRow[1]);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on Utils.loadCSV");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on Utils.loadCSV");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }
        return data;
    }

    /** Load a Map<K, V> from a CSV with new INTEf catalog, columns (K,V)
     * @param path to CSV
     * @return Map<K, V>
     */
    private static Map<String, List<String>> loadCSVCatalog(final String path, final int columnKey, final int columnValue) {
        final Map<String, List<String>> data = new HashMap<String, List<String>>();
        final String csvFile = path;
        final String cvsSplitBy = ",";

        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            br.readLine(); // skip first row (titles)
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(cvsSplitBy);
                try {
                    final String keys[] = dataRow[columnKey].replace("\"", "").split("\\|");
                    for (int i = 0; i < keys.length; i++) {
                        final String key = keys[i].trim();
                        if (data.containsKey(key)) {
                            data.get(key).add(dataRow[columnValue].trim());
                        } else {
                            data.put(key, new ArrayList<String>(Arrays.asList(dataRow[columnValue])));
                        }
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, "ArrayIndexOutOfBoundsException on Utils.loadCSVCatalog");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e, "Cannot extract key on String: {0}", dataRow[1]);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on Utils.loadCSVCatalog");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on Utils.loadCSVCatalog");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }
        return data;
    }

    /** Load a Map<K, V> from a CSV with columns (K,V)
     * @param path to CSV on ClassPath
     * @return Map<K, V>
     */
    public static Map<String, String> loadCSVFromClassPath(final String resourcePath, final Boolean reverse) {
        return loadCSV(generateTempFileFromResource(resourcePath, ".csv"), reverse);
    }

    private static Map<String, List<String>> loadMapNewCatalog(final String resourcePath, final String vocabulary) {
        int column = 0;
        if (vocabulary.equals("LOE") || vocabulary.equals("LOM-ES")) {
            column = 1;
        } else if (vocabulary.equals("ETB")) {
            column = 2;
        } else {
            return null;
        }
        return loadCSVCatalog(generateTempFileFromResource(resourcePath, ".csv"), column, 0);
    }

    private static String generateTempFileFromResource(final String resourcePath, final String extension) {
        final Resource classPathResource = new ClassPathResource(resourcePath);
        String path = "";
        File tempFile = null;

        try {
            final InputStream inputStream = classPathResource.getInputStream();
            Utils.logInfo(LOG, "Reading File: {0}", resourcePath);
            tempFile = File.createTempFile("map", extension);

            try (FileOutputStream out = new FileOutputStream(tempFile)) {
                IOUtils.copy(inputStream, out);
            }
            path = tempFile.getAbsolutePath();
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot read File: {0}", resourcePath);
        }

        if (tempFile != null) {
            tempFile.deleteOnExit();
        }

        return path;
    }

    public static long getCurrentMillis() {
        return currentMillis.getAndIncrement();
    }

    public static String getFormatSeparator() {
        return getMessage("format_separator");
    }

    /**
     * Mappings to Drupal IDs matching with LOMes IDs
     * */

    public static Map<String, String> getAccesibilidad() {
        return accesibilidad;
    }

    public static Map<String, String> getArbol_curricular() {
        return arbol_curricular;
    }

    public static Map<String, String> getCompetencias() {
        return competencias;
    }

    public static Map<String, String> getLicencias() {
        return licencias;
    }

    public static Map<String, String> getNivel_educativo() {
        return nivel_educativo;
    }

    public static Map<String, String> getAccesibilidadLabel() {
        return accesibilidadLabel;
    }

    public static Map<String, String> getArbolCurricularLabel() {
        return arbolCurricularLabel;
    }

    public static Map<String, String> getCompetenciasLabel() {
        return competenciasLabel;
    }

    public static Map<String, String> getLicenciasLabel() {
        return licenciasLabel;
    }

    public static Map<String, String> getNivelEducativoLabel() {
        return nivelEducativoLabel;
    }

    public static Map<String, List<String>> getCurricularTreeLomes() {
        return curricularTreeLomes;
    }

    public static Map<String, List<String>> getCurricularTreeEtb() {
        return curricularTreeEtb;
    }

    public static Map<String, List<String>> getLearningContextLomes() {
        return learningContextLomes;
    }

    public static Map<String, List<String>> getLearningContextEtb() {
        return learningContextEtb;
    }

    public static Map<String, List<String>> getResourceTypeLomes() {
        return resourceTypeLomes;
    }

}
