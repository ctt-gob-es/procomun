package com.emergya.agrega2.odes.util;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.util.impl.Utils;

public class TransformUtils {

    private static final Log LOG = LogFactory.getLog(Utils.class);

    private static Map<String, List<String>> curricularTreeLomes;

    private static Map<String, List<String>> learningContextLomes;

    private static Map<String, TransformCatalog> transformCatalog;

    static {
        final String base = Utils.getProps().getProperty("arranger.intef.csv.base.transform");
        curricularTreeLomes = loadMapNewCatalog(
                base + Utils.getProps().getProperty("arranger.intef.csv.transform.areaconocimiento"), "LOE");

        learningContextLomes = loadMapNewCatalog(
                base + Utils.getProps().getProperty("arranger.intef.csv.transform.contextoeducativo"), "LOM-ES");

        transformCatalog = loadTransformCatalog(base
                + Utils.getProps().getProperty("arranger.intef.csv.transform.catalog"));
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
        return loadCSVCatalog(Utils.generateTempFileFromResource(resourcePath, ".csv"), column, 0);
    }

    private static Map<String, TransformCatalog> loadTransformCatalog(final String csvFile) {

        final String tmpFile = Utils.generateTempFileFromResource(csvFile, ".csv");

        final String rowSplitBy = ",";
        final String cellSplitBy = "\\|";

        Map<String, TransformCatalog> data = new HashMap<String, TransformUtils.TransformCatalog>();

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(tmpFile));
            String line = "";
            br.readLine(); // skip first row (titles)
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(rowSplitBy);

                if (!Utils.isEmpty(dataRow)) {
                    // Getting key
                    final String key = dataRow[0].toLowerCase();

                    if (!Utils.isEmpty(key)) {
                        // Getting socialLabel, knowledgeArea and
                        // learningContext
                        TransformCatalog comCatalog = null;
                        List<String> newTags = new ArrayList<String>();
                        List<String> newKnowledgeArea = new ArrayList<String>();
                        List<String> newLearningResource = new ArrayList<String>();
                        try {
                            newTags = Arrays.asList(dataRow[1].split(cellSplitBy));
                        } catch (Exception e) {
                            Utils.logWarn(LOG, "Empty newTags cell on TransformCatalog");
                        }
                        try {
                            newKnowledgeArea = Arrays.asList(dataRow[2].split(cellSplitBy));
                        } catch (Exception e) {
                            Utils.logWarn(LOG, "Empty newKnowledgeArea cell on TransformCatalog");
                        }
                        try {
                            newLearningResource = Arrays.asList(dataRow[3].split(cellSplitBy));
                        } catch (Exception e) {
                            Utils.logWarn(LOG, "Empty newLearningResource cell on TransformCatalog");
                        }
                        comCatalog = new TransformCatalog(newTags, newLearningResource, newKnowledgeArea);

                        // Adding to final Map
                        data.put(key, comCatalog);
                    }
                }

            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on TransformUtils.loadCommunityCatalog");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on TransformUtils.loadCommunityCatalog");
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

    /** Load a Map<K, V> from a CSV with new INTEF catalog, columns (K,V)
     * @param path to CSV
     * @return Map<K, V>
     */
    private static Map<String, List<String>> loadCSVCatalog(final String path, final int columnKey,
            final int columnValue) {
        final Map<String, List<String>> data = new HashMap<String, List<String>>();
        final String csvFile = path;
        final String rowSplitBy = ",";

        BufferedReader br = null;

        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            br.readLine(); // skip first row (titles)
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(rowSplitBy);
                try {
                    final String keys[] = dataRow[columnKey].replace("\"", "").split("\\|");
                    for (int i = 0; i < keys.length; i++) {
                        final String key = keys[i].toLowerCase();
                        if (data.containsKey(key)) {
                            data.get(key).add(dataRow[columnValue].trim());
                        } else {
                            data.put(key, new ArrayList<String>(Arrays.asList(dataRow[columnValue])));
                        }
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, "ArrayIndexOutOfBoundsException on TransformUtils.loadCSVCatalog");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e, "Cannot extract key on String: {0}", dataRow[1]);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on TransformUtils.loadCSVCatalog");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on TransformUtils.loadCSVCatalog");
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

    /**
     * Aux classes
     * */

    public static class TransformCatalog {

        private List<String> socialLabels = new ArrayList<String>();
        private List<String> learningContext = new ArrayList<String>();
        private List<String> knowledgeArea = new ArrayList<String>();

        public TransformCatalog(List<String> socialLabels, List<String> learningContext, List<String> knowledgeArea) {
            super();
            this.socialLabels = socialLabels;
            this.learningContext = learningContext;
            this.knowledgeArea = knowledgeArea;
        }

        public List<String> getLearningContext() {
            return learningContext;
        }

        public void setLearningContext(List<String> learningContext) {
            this.learningContext = learningContext;
        }

        public List<String> getKnowledgeArea() {
            return knowledgeArea;
        }

        public void setKnowledgeArea(List<String> knowledgeArea) {
            this.knowledgeArea = knowledgeArea;
        }

        public List<String> getSocialLabels() {
            return socialLabels;
        }

        public void setSocialLabels(List<String> socialLabels) {
            this.socialLabels = socialLabels;
        }

    }

    /**
     * Getters and Setters
     * */

    public static Map<String, List<String>> getCurricularTreeLomes() {
        return curricularTreeLomes;
    }

    public static Map<String, List<String>> getLearningContextLomes() {
        return learningContextLomes;
    }

    public static Map<String, TransformCatalog> getTransformCatalog() {
        return transformCatalog;
    }

}
