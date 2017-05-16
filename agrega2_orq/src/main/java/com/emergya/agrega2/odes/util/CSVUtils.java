package com.emergya.agrega2.odes.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Properties;

import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;

import com.emergya.agrega2.arranger.util.impl.Utils;

public class CSVUtils {

    private static final Log LOG = LogFactory.getLog(CSVUtils.class);

    private static final String EXTENSION = ".csv";
    private static final String CA = "_ca";
    private static final String EN = "_en";
    private static final String GL = "_gl";
    private static final String EU = "_eu";

    private static Properties props = new Properties();

    private static Map<String, List<ArrayList<TaxonNode>>> curricularTree;
    private static Map<String, List<ArrayList<TaxonNode>>> curricularTreeCa;
    private static Map<String, List<ArrayList<TaxonNode>>> curricularTreeEn;
    private static Map<String, List<ArrayList<TaxonNode>>> curricularTreeGa;
    private static Map<String, List<ArrayList<TaxonNode>>> curricularTreeEu;
    private static Map<String, LearningContext> learningContext;
    private static Map<String, LearningContext> learningContextCa;
    private static Map<String, LearningContext> learningContextEn;
    private static Map<String, LearningContext> learningContextGa;
    private static Map<String, LearningContext> learningContextEu;
    private static Map<String, String> ageRanges;
    private static Map<String, ResourceType> resourceType;

    static {
        try {
            props.load(new InputStreamReader(Utils.class.getResourceAsStream("/properties/general.properties"), "UTF-8"));
        } catch (final Exception e) {
            throw new ExceptionInInitializerError(e);
        }

        final String resourcePathCurricularTreeEs = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.areaconocimiento") + EXTENSION;
        final String resourcePathCurricularTreeCa = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.areaconocimiento") + CA + EXTENSION;
        final String resourcePathCurricularTreeEn = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.areaconocimiento") + EN + EXTENSION;
        final String resourcePathCurricularTreeGa = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.areaconocimiento") + GL + EXTENSION;
        final String resourcePathCurricularTreeEu = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.areaconocimiento") + EU + EXTENSION;

        final String resourcePathLearningResourceEs = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.contextoeducativo") + EXTENSION;
        final String resourcePathLearningResourceCa = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.contextoeducativo") + CA + EXTENSION;
        final String resourcePathLearningResourceEn = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.contextoeducativo") + EN + EXTENSION;
        final String resourcePathLearningResourceGa = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.contextoeducativo") + GL + EXTENSION;
        final String resourcePathLearningResourceEu = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.contextoeducativo") + EU + EXTENSION;

        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathCurricularTreeEs);
        curricularTree = loadCurricularTree(resourcePathCurricularTreeEs);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathCurricularTreeCa);
        curricularTreeCa = loadCurricularTree(resourcePathCurricularTreeCa);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathCurricularTreeEn);
        curricularTreeEn = loadCurricularTree(resourcePathCurricularTreeEn);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathCurricularTreeGa);
        curricularTreeGa = loadCurricularTree(resourcePathCurricularTreeGa);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathCurricularTreeEu);
        curricularTreeEu = loadCurricularTree(resourcePathCurricularTreeEu);

        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathLearningResourceEs);
        learningContext = loadLearningContext(resourcePathLearningResourceEs);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathLearningResourceCa);
        learningContextCa = loadLearningContext(resourcePathLearningResourceCa);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathLearningResourceEn);
        learningContextEn = loadLearningContext(resourcePathLearningResourceEn);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathLearningResourceGa);
        learningContextGa = loadLearningContext(resourcePathLearningResourceGa);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathLearningResourceEu);
        learningContextEu = loadLearningContext(resourcePathLearningResourceEu);

        final String resourcePathAgeRanges = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.rangosedad") + EXTENSION;
        final String resourcePathResourceType = props.getProperty("arranger.intef.csv.base")
                + props.getProperty("arranger.intef.csv.tiporecurso") + EXTENSION;

        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathAgeRanges);
        ageRanges = loadAgeRanges(resourcePathAgeRanges);
        Utils.logInfo(LOG, "Reading CSV: {0}", resourcePathResourceType);
        resourceType = loadResourceTypes(resourcePathResourceType);
    }

    /** Load new curricularTree catalog to mapping with old LRE catalog
     * @param resourcePath Path to mapping file
     */
    private static Map<String, List<ArrayList<TaxonNode>>> loadCurricularTree(final String resourcePath) {
        Utils.logInfo(LOG, "Loading Curricular Tree Data: New catalog to LOMES/LRE");
        Map<String, List<ArrayList<TaxonNode>>> tree = new HashMap<String, List<ArrayList<TaxonNode>>>();

        final String cvsSplitBy = ",";
        final String csvFile = generateTempFileFromResource(resourcePath, EXTENSION);

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            br.readLine(); // skip first row (titles)

            // Each Line of CSV mapping file
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(cvsSplitBy);
                try {
                    List<ArrayList<TaxonNode>> lreAllLevels = new ArrayList<ArrayList<TaxonNode>>();
                    // Each LRE Tree
                    for (int i = 1; i < dataRow.length; i++) {
                        ArrayList<TaxonNode> lreLevel = new ArrayList<CSVUtils.TaxonNode>();
                        final String[] lreLevelsStr = dataRow[i].split("##");

                        // Each node from a Tree
                        for (int j = 0; j < lreLevelsStr.length; j++) {
                            String[] splitLevelNode = lreLevelsStr[j].split("#");
                            TaxonNode levelNode = new TaxonNode(splitLevelNode[0], splitLevelNode[1]);
                            lreLevel.add(levelNode);
                        }
                        lreAllLevels.add(lreLevel);
                    }
                    // Setting Key (Curricular Tree level)and value (Curricular
                    // Tree nodes)
                    tree.put(dataRow[0], lreAllLevels);

                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, e, "ArrayIndexOutOfBoundsException on CSVUtils.loadCurricularTree");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on Utils.loadCurricularTree");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on Utils.loadCurricularTree");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }

        return tree;
    }

    /** Load new learningContext catalog to mapping with old catalog
     * @param resourcePath Path to mapping file
     */
    private static Map<String, LearningContext> loadLearningContext(final String resourcePath) {
        Utils.logInfo(LOG, "Loading Learning Context Data: New catalog to LOMES/LRE");
        Map<String, LearningContext> tree = new HashMap<String, LearningContext>();

        final String cvsSplitBy = ",";
        final String csvFile = generateTempFileFromResource(resourcePath, EXTENSION);

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            br.readLine(); // skip first row (titles)

            // Each Line of CSV mapping file
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(cvsSplitBy);
                try {
                    List<List<TaxonNode>> loeLearningContextTree = new ArrayList<List<TaxonNode>>();
                    List<TaxonNode> lreLearningContextTree = new ArrayList<TaxonNode>();

                    // LOAD LOE TREE: LIST(TREE)
                    if (!Utils.isEmpty(dataRow[1])) {

                        final String[] loeTrees = dataRow[1].split("###");
                        for (int i = 0; i < loeTrees.length; i++) {
                            ArrayList<TaxonNode> loeTree = new ArrayList<TaxonNode>();
                            final String[] loeLevelsStr = loeTrees[i].split("##");

                            // Each node from a Tree
                            for (int j = 0; j < loeLevelsStr.length; j++) {
                                String[] splitLevelNode = loeLevelsStr[j].split("#");
                                TaxonNode levelNode = new TaxonNode(splitLevelNode[0], splitLevelNode[1]);
                                loeTree.add(levelNode);
                            }

                            loeLearningContextTree.add(loeTree);
                        }
                    }

                    // LOAD LRE TREE
                    final String[] lreTree = dataRow[2].split("##");
                    for (int j = 0; j < lreTree.length; j++) {
                        String[] splitLevelNode = lreTree[j].split("#");
                        TaxonNode levelNode = new TaxonNode(splitLevelNode[0], splitLevelNode[1]);
                        lreLearningContextTree.add(levelNode);
                    }
                    // Setting Key (New catalog literal) and value (Learning
                    // context trees)

                    final LearningContext learningContext = new LearningContext(loeLearningContextTree,
                            lreLearningContextTree);
                    tree.put(dataRow[0], learningContext);

                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, e, "ArrayIndexOutOfBoundsException on CSVUtils.loadLearningContext");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on Utils.loadLearningContext");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on Utils.loadLearningContext");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }

        return tree;
    }

    private static Map<String, ResourceType> loadResourceTypes(final String resourcePath) {
        Utils.logInfo(LOG, "Loading Resource Types Data");
        Map<String, ResourceType> respurceTypes = new HashMap<String, ResourceType>();

        final String cvsSplitBy = ",";
        final String csvFile = generateTempFileFromResource(resourcePath, EXTENSION);

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            br.readLine(); // skip first row (titles)

            // Each Line of CSV mapping file
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(cvsSplitBy);
                try {
                    respurceTypes.put(dataRow[0], new ResourceType(dataRow[1], dataRow[2]));

                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, "ArrayIndexOutOfBoundsException on CSVUtils.loadResourceTypes");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on Utils.loadResourceTypes");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on Utils.loadResourceTypes");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }

        return respurceTypes;
    }

    private static Map<String, String> loadAgeRanges(final String resourcePath) {
        Utils.logInfo(LOG, "Loading Age ranges Data");
        Map<String, String> ageRanges = new HashMap<String, String>();

        final String cvsSplitBy = ",";
        final String csvFile = generateTempFileFromResource(resourcePath, EXTENSION);

        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(csvFile));
            String line = "";
            br.readLine(); // skip first row (titles)

            // Each Line of CSV mapping file
            while ((line = br.readLine()) != null) {
                String[] dataRow = line.split(cvsSplitBy);
                try {
                    final String ageRange = dataRow[1];
                    if (!Utils.isEmpty(ageRange)) {
                        ageRanges.put(dataRow[0], ageRange);
                    }

                } catch (ArrayIndexOutOfBoundsException e) {
                    Utils.logWarn(LOG, "ArrayIndexOutOfBoundsException on CSVUtils.loadAgeRanges");
                } catch (NullPointerException e) {
                    Utils.logError(LOG, e);
                }
            }
        } catch (FileNotFoundException e) {
            Utils.logError(LOG, e, "FileNotFoundException on Utils.loadAgeRanges");
        } catch (IOException e) {
            Utils.logError(LOG, e, "IOException on Utils.loadAgeRanges");
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }

        return ageRanges;
    }

    /** Generates a temporally file from a resource file. This file will be deleted on exit.
     * @param resourcePath Path to resource
     * @param extension Resource extension
     * @return Absolute path to temporally file
     */
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

    /**
     * GETTERS AND SETTERS
     * */
    public static Map<String, List<ArrayList<TaxonNode>>> getCurricularTree(final String language) {
        if (Utils.equalsStr("ca", language)) {
            return curricularTreeCa;
        } else if (Utils.equalsStr("en", language)) {
            return curricularTreeEn;
        } else if (Utils.equalsStr("ga", language)) {
            return curricularTreeGa;
        } else if (Utils.equalsStr("eu", language)) {
            return curricularTreeEu;
        } else {
            return curricularTree;
        }
    }

    public static Map<String, LearningContext> getLearningContext(final String language) {
        if (Utils.equalsStr("ca", language)) {
            return learningContextCa;
        } else if (Utils.equalsStr("en", language)) {
            return learningContextEn;
        } else if (Utils.equalsStr("ga", language)) {
            return learningContextGa;
        } else if (Utils.equalsStr("eu", language)) {
            return learningContextEu;
        } else {
            return learningContext;
        }
    }

    public static Map<String, String> getAgeRanges() {
        return ageRanges;
    }

    public static Map<String, ResourceType> getResourceType() {
        return resourceType;
    }

    /** Represents a LRE Level
     * @author ajrodriguez
     *
     */
    public static class TaxonNode {
        private String id;
        private String description;

        public TaxonNode(String id, String description) {
            super();
            this.id = id;
            this.description = description;
        }

        public String getlevelNodeParsed() {
            return id + " - " + description;
        }

        @Override
        public String toString() {
            StringBuffer sb = new StringBuffer();
            sb.append("id: ").append(id).append("\n").append("description: ").append(description).append("\n");
            return sb.toString();
        }

        public String getId() {
            return id;
        }

        public void setId(String id) {
            this.id = id;
        }

        public String getDescription() {
            return description;
        }

        public void setDescription(String description) {
            this.description = description;
        }
    }

    public static class LearningContext {
        private List<List<TaxonNode>> loeLearningContextTree;
        private List<TaxonNode> lreLearningContextTree;

        public LearningContext(List<List<TaxonNode>> loeLearningContextTree, List<TaxonNode> lreLearningContextTree) {
            super();
            this.loeLearningContextTree = loeLearningContextTree;
            this.lreLearningContextTree = lreLearningContextTree;
        }

        public List<List<TaxonNode>> getLoeLearningContextTree() {
            return loeLearningContextTree;
        }

        public void setLoeLearningContextTree(List<List<TaxonNode>> loeLearningContextTree) {
            this.loeLearningContextTree = loeLearningContextTree;
        }

        public List<TaxonNode> getLreLearningContextTree() {
            return lreLearningContextTree;
        }

        public void setLreLearningContextTree(List<TaxonNode> lreLearningContextTree) {
            this.lreLearningContextTree = lreLearningContextTree;
        }

    }

    public static class ResourceType {
        private String lomes;
        private String lre;

        public ResourceType(String lomes, String lre) {
            super();
            this.lomes = lomes;
            this.lre = lre;
        }

        public String getLomes() {
            return lomes;
        }

        public void setLomes(String lomes) {
            this.lomes = lomes;
        }

        public String getLre() {
            return lre;
        }

        public void setLre(String lre) {
            this.lre = lre;
        }

    }

}
