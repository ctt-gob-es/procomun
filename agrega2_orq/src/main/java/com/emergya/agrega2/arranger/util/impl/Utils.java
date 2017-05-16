package com.emergya.agrega2.arranger.util.impl;

import java.beans.PropertyDescriptor;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.net.Authenticator;
import java.net.URL;
import java.net.URLConnection;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicLong;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Unmarshaller;

import org.apache.commons.codec.digest.DigestUtils;
import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.BeanWrapper;
import org.springframework.beans.BeansException;
import org.springframework.beans.FatalBeanException;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;
import org.springframework.util.Assert;

import com.fasterxml.jackson.annotation.ObjectIdGenerators.UUIDGenerator;

/**
 * Util methods for the arranger
 */
/**
 * @author ajrodriguez
 *
 */
public class Utils {

    private static Map<String, String> accesibilidad;
    private static Map<String, String> arbol_curricular;
    private static Map<String, String> competencias;
    private static Map<String, String> licencias;
    private static Map<String, String> nivel_educativo;

    private static Map<String, String> accesibilidadRev;
    private static Map<String, String> arbolCurricularRev;
    private static Map<String, String> competenciasRev;
    private static Map<String, String> licenciasRev;
    private static Map<String, String> nivelEducativoRev;

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

    private static AtomicLong currentMillis;

    private static Properties props = new Properties();

    private static final Log LOG = LogFactory.getLog(Utils.class);

    private Utils() {
    }

    public static final String DEFAULT_DATE_FORMAT = "yyyy-MM-dd'T'HH:mm:ss.S'Z'";

    public static final String NOMILLIS_DATE_FORMAT = "yyyy-MM-dd'T'HH:mm:ss'Z'";

    private static Map<String, String> solrFieldsBoosting;

    static {

        currentMillis = new AtomicLong(System.currentTimeMillis());

        try {
            props.load(new InputStreamReader(Utils.class.getResourceAsStream("/properties/general.properties"), "ISO-8859-1"));
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

        accesibilidadRev = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.accesibilidad"), true);
        arbolCurricularRev = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.arbol_curricular"), true);
        competenciasRev = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.competencias"), true);
        licenciasRev = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.licencias"), true);
        nivelEducativoRev = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.nivel_educativo"), true);

        accesibilidadLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.accesibilidad"), null);
        arbolCurricularLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.arbol_curricular"), null);
        competenciasLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.competencias"), null);
        licenciasLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.licencias"), null);
        nivelEducativoLabel = loadCSVFromClassPath(props.getProperty("arranger.drupal.csv.base") + props.getProperty("arranger.drupal.csv.nivel_educativo"), null);

        // LOMES TO NEW CATALOG
        curricularTreeLomes = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.areaconocimiento.new"), "LOE");
        curricularTreeEtb = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.areaconocimiento.new"), "ETB");
        learningContextLomes = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.contextoeducativo.new"), "LOM-ES");
        learningContextEtb = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.contextoeducativo.new"), "ETB");
        resourceTypeLomes = loadMapNewCatalog(props.getProperty("arranger.intef.csv.base") + props.getProperty("arranger.intef.csv.tiporecurso.rdf"), "LOM-ES");

        /**
         *  This Map stores each field configured for boosting in Solr queries.
         */
        solrFieldsBoosting = new Hashtable<String, String>();
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

    public static String generateTempFileFromResource(String resourcePath, String extension) {
        final Resource classPathResource = new ClassPathResource(resourcePath + extension);
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

        return path;
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

    public static String getMessage(String property, Object... params) {
        return MessageFormat.format(props.getProperty(property), params);
    }

    /**
     * Get response content from an URL
     * 
     * @param urlObject URL to get content from
     * @param encoding Encoding of the content
     * @param user If user needed
     * @param pass If pass needed
     * @return URL Response String
     * @throws IOException
     */
    public static String getURLContent(final URL urlObject, final String encoding, final String user, final String pass) throws IOException {

        if (!Utils.isEmpty(user) && !Utils.isEmpty(pass)) {
            Authenticator.setDefault(new BasicAuthenticator(user, pass));
        }

        final URLConnection conn = urlObject.openConnection();
        conn.setConnectTimeout(2500);
        final InputStream inputStream = conn.getInputStream();
        return IOUtils.toString(inputStream, encoding);
    }

    /**
     * String Util methods
     */

    public static String md5(final String text) {
        if (text != null && text.length() > 0) {
            return DigestUtils.md5Hex(text);
        }
        return null;
    }

    public static String sha1(final String text) {
        if (text != null && text.length() > 0) {
            return DigestUtils.sha1Hex(text);
        }
        return null;
    }

    public static boolean isEmpty(final String text) {
        return text == null || text.trim().length() == 0;
    }

    public static boolean isEmpty(final Collection<?> collection) {
        return collection == null || collection.isEmpty();
    }

    public static boolean equalsStr(final String s1, final String s2) {
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
        return value.isEmpty();
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

    /**
     * LOG methods
     * */

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
        return new Object[] {};
    }

    public static void logTrace(final Log log, final Object message) {
        if (log != null && log.isTraceEnabled()) {
            log.trace(message);
        }
    }

    public static void logTrace(final Log log, final String message, final Object arg0, final Object... args) {
        if (log != null && log.isTraceEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
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
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
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
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
            log.info(m);
        }
    }

    public static void logWarn(final Log log, final String message) {
        logWarn(log, null, message);
    }

    public static void logWarn(final Log log, final Throwable t, final String message, final Object arg0, final Object... args) {
        if (log != null && log.isWarnEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
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
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
            logWarn(log, null, m);
        }
    }

    public static void logError(final Log log, final String message) {
        logError(log, null, message);
    }

    public static void logError(final Log log, final String message, final String arg0, final Object... args) {
        if (log != null && log.isErrorEnabled()) {
            final Object[] a = union(arg0, args);
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
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
            final String m = a.length > 0 ? MessageFormat.format(message, a) : message;
            logError(log, t, m);
        }
    }

    public static String generateID(final String str) {
        return md5(str);
    }

    /**
     * Generates a unique identifier for the String parameter.
     * @param id 
     * @param prefijo Prefix to use
     * @return
     */
    public static String getUUID(String id, String prefijo) {
        String result = null;
        String idTmp = new String(id);

        if (id != null) {
            long time = System.currentTimeMillis();
            idTmp += Long.toString(time);

            UUIDGenerator generator = new UUIDGenerator();
            generator.generateId(idTmp);
            UUID uuid = generator.generateId(idTmp);

            if (uuid != null) {
                result = uuid.toString();
                if (prefijo != null) {
                    result = prefijo + result;
                }
            }
        }
        return result;
    }

    /** Load a Map<K, V> from a CSV with columns (K,V)
     * @param path to CSV
     * @return Map<K, V>
     */
    public static Map<String, String> loadCSV(final String path, final Boolean reverse) {
        final String csvFile = path;
        final String cvsSplitBy = ",";

        Map<String, String> data = new HashMap<String, String>();

        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(csvFile));
            data = loadCSVFromBuffer(br, cvsSplitBy, reverse);
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

    private static Map<String, String> loadCSVFromBuffer(final BufferedReader br, final String cvsSplitBy, final Boolean reverse) throws IOException {
        final Map<String, String> data = new HashMap<String, String>();
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
        return data;
    }

    /** Load a Map<K, V> from a CSV with columns (K,V)
     * @param path to CSV on ClassPath
     * @param reverse to load the map as Map<V, K>
     * @return Map<K, V>
     */
    public static Map<String, String> loadCSVFromClassPath(final String resourcePath, final Boolean reverse) {
        final Resource classPathResource = new ClassPathResource(resourcePath);

        Map<String, String> data = new HashMap<String, String>();
        try {
            Utils.logInfo(LOG, "Reading CSV: {0}", resourcePath);
            data = loadCSV(classPathResource.getFile().getAbsolutePath(), reverse);
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot read CSV: {0}", resourcePath);
        }
        return data;
    }

    /**
     * Copy the property values of the given source bean into the given target bean if empty,
     * ignoring empty values.
     * <p>Note: The source and target classes do not have to match or even be derived
     * from each other, as long as the properties match. Any bean properties that the
     * source bean exposes but the target bean does not will silently be ignored.
     * <p>This is just a convenience method. For more complex transfer needs,
     * consider using a full BeanWrapper.
     * @param source the source bean
     * @param target the target bean
     * @throws BeansException if the copying failed
     * @see BeanWrapper
     */
    public static void copyProperties(Object source, Object target) throws BeansException {

        Assert.notNull(source, "Source must not be null");
        Assert.notNull(target, "Target must not be null");

        Class<?> actualEditable = target.getClass();
        PropertyDescriptor[] targetPds = BeanUtils.getPropertyDescriptors(actualEditable);

        for (PropertyDescriptor targetPd : targetPds) {
            if (targetPd.getWriteMethod() != null) {
                PropertyDescriptor sourcePd = BeanUtils.getPropertyDescriptor(source.getClass(), targetPd.getName());
                if (sourcePd != null && sourcePd.getReadMethod() != null) {
                    try {
                        Method readMethod = sourcePd.getReadMethod();
                        if (!Modifier.isPublic(readMethod.getDeclaringClass().getModifiers())) {
                            readMethod.setAccessible(true);
                        }
                        Object valueSource = readMethod.invoke(source);
                        if (!isEmpty(valueSource)) {
                            // Object valueTarget = readMethod.invoke(target);
                            // if (valueTarget == null) {
                            Method writeMethod = targetPd.getWriteMethod();
                            if (!Modifier.isPublic(writeMethod.getDeclaringClass().getModifiers())) {
                                writeMethod.setAccessible(true);
                            }
                            writeMethod.invoke(target, valueSource);
                            // }
                        }
                    } catch (Exception ex) {
                        throw new FatalBeanException("Could not copy properties from source to target", ex);
                    }
                }
            }
        }
    }

    public static String getToken(final long timeStamp) {
        return md5(getMessage("token") + timeStamp);
    }

    public static long getCurrentMillis() {
        return currentMillis.getAndIncrement();
    }

    public static Properties getProps() {
        return props;
    }

    public static <T> T object(final String xml, final Class<T> cls) {
        if (xml == null || cls == null)
            return null;
        try {
            final JAXBContext context = JAXBContext.newInstance(cls);
            final Unmarshaller unmarshaller = context.createUnmarshaller();
            @SuppressWarnings("unchecked")
            final T obj = (T) unmarshaller.unmarshal(new StringReader(xml));
            return obj;
        } catch (final JAXBException e) {
            if (LOG.isErrorEnabled())
                LOG.error(e);
        }
        return null;
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

    public static Map<String, String> getAccesibilidadRev() {
        return accesibilidadRev;
    }

    public static Map<String, String> getArbolCurricularRev() {
        return arbolCurricularRev;
    }

    public static Map<String, String> getCompetenciasRev() {
        return competenciasRev;
    }

    public static Map<String, String> getLicenciasRev() {
        return licenciasRev;
    }

    public static Map<String, String> getNivelEducativoRev() {
        return nivelEducativoRev;
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

    public static Map<String, List<String>> getResourceTypeLomes() {
        return resourceTypeLomes;
    }

    public static Map<String, String> getSolrFieldsBoosting() {
        return solrFieldsBoosting;
    }

    public static void setSolrFieldsBoosting(Map<String, String> solrFieldsBoosting) {
        Utils.solrFieldsBoosting = solrFieldsBoosting;
    }

    public static Map<String, List<String>> getLearningContextLomes() {
        return learningContextLomes;
    }

    public static void setLearningContextLomes(Map<String, List<String>> learningContextLomes) {
        Utils.learningContextLomes = learningContextLomes;
    }

    public static Map<String, List<String>> getLearningContextEtb() {
        return learningContextEtb;
    }

    public static void setLearningContextEtb(Map<String, List<String>> learningContextEtb) {
        Utils.learningContextEtb = learningContextEtb;
    }

    public static Map<String, List<String>> getCurricularTreeLomes() {
        return curricularTreeLomes;
    }

    public static void setCurricularTreeLomes(Map<String, List<String>> curricularTreeLomes) {
        Utils.curricularTreeLomes = curricularTreeLomes;
    }

    public static Map<String, List<String>> getCurricularTreeEtb() {
        return curricularTreeEtb;
    }

    public static void setCurricularTreeEtb(Map<String, List<String>> curricularTreeEtb) {
        Utils.curricularTreeEtb = curricularTreeEtb;
    }

}
