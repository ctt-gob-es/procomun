

import java.io.File;
import java.io.FileFilter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FilenameFilter;
import java.io.PrintStream;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntModelSpec;
import com.hp.hpl.jena.rdf.model.Model;
import com.hp.hpl.jena.rdf.model.ModelFactory;
import com.hp.hpl.jena.util.FileManager;

public class Agrega_XML_RDF {

    OntModel lom_Model = null;
    Individual resource_individual = null;

    public static String NS = null;// http://www.agrega.es/ont/lom2owl";

    // where we've stashed it on disk for the time being
    protected static String SOURCE_FILE = null;

    // where the final dump is stored
    protected static String OUTPUT_Folder = null;// "./src/output";
    // where the log file is stored
    protected static String LOG_Folder = null;
    protected static String LOG_File = null;

    // Extension of rdf dumps
    protected static String OUTPUT_Extension = null;
    // format of rdf dumps
    protected static String OUTPUT_Format = null;
    // the name of dataset
    protected static String DATASET_NAME = null;
    // the name of dump file
    protected static String DumpFileName = null;

    // the port in which FUSEKI is run
    protected static String PORT = null;

    // config file name
    protected static String Config_file_path = "config.xml";
//  protected static String Config_file_path = "src/config_development.xml";

    // where we've stashed it on disk for the time being
    protected static String XML_Folder = null;// "./src/input";

    protected static String LOM_PREFIX = null;// "TURTLE";

    protected static String NUMBER_OF_RECORDS = null;// "TURTLE";
    private File folderPath = null;

    Agrega_XML_RDF(File folderPath_input) {
        this.folderPath = folderPath_input;
    }

    // ******************** Load OWL file into Model ***************************
    protected void loadModel(OntModel m) {
        Model baseOntology = FileManager.get().loadModel(SOURCE_FILE);
        m.addSubModel(baseOntology);
    }

    // ******************** read config file ***************************
    public static void readConfigFile() {
        try {

            File fXmlFile = new File(Config_file_path);
            DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(fXmlFile);
            doc.getDocumentElement().normalize();

            NodeList nList = doc.getElementsByTagName("LOM2RDF");
            System.out.println("----------------------------");

            for (int temp = 0; temp < nList.getLength(); temp++) {
                Node nNode = nList.item(temp);
                if (nNode.getNodeType() == Node.ELEMENT_NODE) {
                    Element eElement = (Element) nNode;
                    NS = eElement.getElementsByTagName("SOURCE_URL").item(0).getTextContent().trim();
                    SOURCE_FILE = eElement.getElementsByTagName("SOURCE_FILE").item(0).getTextContent().trim();
                    XML_Folder = eElement.getElementsByTagName("XML_Folder").item(0).getTextContent().trim();
                    OUTPUT_Format = eElement.getElementsByTagName("OUTPUT_Format").item(0).getTextContent().trim();
                    OUTPUT_Folder = eElement.getElementsByTagName("OUTPUT_Folder").item(0).getTextContent().trim();

                    LOM_PREFIX = eElement.getElementsByTagName("LOM_PREFIX").item(0).getTextContent().trim();
                    PORT = eElement.getElementsByTagName("PORT").item(0).getTextContent().trim();
                    DATASET_NAME = eElement.getElementsByTagName("DATASET_NAME").item(0).getTextContent().trim();
                    NUMBER_OF_RECORDS = eElement.getElementsByTagName("RECORDS").item(0).getTextContent().trim();
                    DumpFileName = eElement.getElementsByTagName("DumpFileName").item(0).getTextContent().trim();
                }
            }
            if (OUTPUT_Format.toLowerCase().equals("turtle"))
                OUTPUT_Extension = "ttl";
            else if (OUTPUT_Format.toLowerCase().equals("n-triple"))
                OUTPUT_Extension = "nt";
            else if (OUTPUT_Format.toLowerCase().equals("rdf/xml"))
                OUTPUT_Extension = "rdf";
            else {
                System.out.println("The output format not found! please modify the config file.");
                System.exit(1);
            }
            if (DumpFileName.isEmpty() || NS.isEmpty() || SOURCE_FILE.isEmpty() || XML_Folder.isEmpty()
                    || OUTPUT_Format.isEmpty() || OUTPUT_Folder.isEmpty() || LOM_PREFIX.isEmpty() || PORT.isEmpty()
                    || DATASET_NAME.isEmpty() || NUMBER_OF_RECORDS.isEmpty()) {
                System.out
                        .println("Something wrong in the config file!? Please read the instruction inside the config file");
                System.exit(1);
            }

        } catch (FileNotFoundException NF) {
            System.out.println("config.xml not found!");
            System.exit(1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // ***************** Set prefix
    // *******************************************************
    String lomPrefix = "lom";
    String dcPrefix = "dcterms";
    String lomVoc = "lomVoc";
    String RDFPrefix = "rdf";
    String vCARD = "VCARD";

    public void setRDFPrefix() {
        lom_Model.setNsPrefix(lomPrefix, NS);
        lom_Model.setNsPrefix(dcPrefix, "http://purl.org/dc/terms/");
        lom_Model.setNsPrefix(lomVoc, "http://ltsc.ieee.org/rdf/lomv1p0/vocabulary#");
        lom_Model.setNsPrefix(RDFPrefix, "http://www.w3.org/1999/02/22-rdf-syntax-ns#");
        lom_Model.setNsPrefix(vCARD, "http://www.w3.org/2001/vcard-rdf/3.0#");
    }

    // ***************** Main Parser
    // *******************************************************
    public void run() {

        String fileName, fileNameWithoutExtension = null, metadataURI = null;
        // an array to store the list of files
        File[] listOfFiles;
        int fileNumber;
        // Filtering XML files
        FilenameFilter filter = new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return name.endsWith(".xml") || name.endsWith(".XML");
            }
        };

        try {
            listOfFiles = this.folderPath.listFiles(filter);
            System.out.println("Folder=" + this.folderPath);

            fileNumber = listOfFiles.length;
            if (fileNumber == 0) {
                System.out.println("No XML files found in the selected folder");
                return;
            }

            if (NUMBER_OF_RECORDS.equals("ALL") || NUMBER_OF_RECORDS.equals("all")) {
                fileNumber = fileNumber;
            } else {
                try {
                    int records = Integer.parseInt(NUMBER_OF_RECORDS);
                    if (records < fileNumber + 2)
                        fileNumber = records;
                } catch (NumberFormatException nfe) {
                    System.out
                            .println("Error! Number of reocrds has not been configured properly. Check your config file. ******************");
                    System.exit(1);
                }
            }

            System.out.println("processing " + fileNumber + " files ...");

            System.out.println("================================================================");

            lom_Model = ModelFactory.createOntologyModel(OntModelSpec.OWL_MEM);

            // setRDFPrefix();
            setRDFPrefix();
            System.out.println("Writing prefix...");

            // Loading model
            loadModel(lom_Model);

            for (int fileIndex = 0; fileIndex < fileNumber; fileIndex++) {
                System.out.println("******************processing " + (fileIndex + 1)
                        + "th file **************************");

                fileName = listOfFiles[fileIndex].getPath();
                File file = new File(fileName);

                if (file.exists()) {

                    // *************** identifier of XML file (getting file name
                    // without extension )*******************
                    fileNameWithoutExtension = file.getName().substring(0, file.getName().length() - 4);
                    metadataURI = fileNameWithoutExtension;// +"-"+fileIndex;
                                                           // //UUID.randomUUID().toString()+"/";
                    System.out.println("metadataURI=" + metadataURI);

                    // fout=new
                    // FileOutputStream(OUTPUT_Folder+"/"+fileNameWithoutExtension+"."+OUTPUT_Extension);

                    // Creating Learning Object Class
                    OntClass LearningObject = lom_Model.getOntClass(NS + "LearningObject");

                    // create an instance of LOM
                    resource_individual = lom_Model.createIndividual(NS + metadataURI + "/", LearningObject);

                    try {
                        // *************** processing XML file
                        // *********************************************
                        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
                        DocumentBuilder db = dbf.newDocumentBuilder();
                        Document doc = db.parse(file);
                        Element docEle = doc.getDocumentElement();

                        System.out.println("Starting the parsing ...");

                        // ================================================
                        // General
                        // ========================================================
                        NodeList GeneralList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "general");
                        generalCategory generalCategory = new generalCategory();
                        generalCategory.parse_General_Category(GeneralList, NS, resource_individual, lom_Model,
                                metadataURI, LOM_PREFIX);

                        // ================================================ LIFE
                        // CYCLE
                        // ========================================================
                        NodeList lifeCycleList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "lifeCycle");
                        lifecycleCategory lifecycleCategory = new lifecycleCategory();
                        lifecycleCategory.parse_Lifecycle_Category(lifeCycleList, NS, resource_individual, lom_Model,
                                metadataURI, LOM_PREFIX);

                        // ================================================
                        // META-METADATA
                        // =====================================================
                        NodeList metaMetadataList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "metaMetadata");
                        metaMetadataCategory metaMetadataCategory = new metaMetadataCategory();
                        metaMetadataCategory.parse_metaMetadata_Category(metaMetadataList, NS, resource_individual,
                                lom_Model, metadataURI, LOM_PREFIX);

                        // ================================================
                        // Technical
                        // =====================================================
                        NodeList TechnicalList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "technical");
                        technicalCategory technicalCategory = new technicalCategory();
                        technicalCategory.parse_Technical_Category(TechnicalList, NS, resource_individual, lom_Model,
                                metadataURI, LOM_PREFIX);

                        // ================================================
                        // Educational
                        // ========================================================

                        NodeList educationalList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "educational");
                        educationalCategory educationalCategory = new educationalCategory();
                        educationalCategory.parse_Educational_Category(educationalList, NS, resource_individual,
                                lom_Model, metadataURI, LOM_PREFIX);

                        // ================================================
                        // Rights
                        // =====================================================
                        NodeList rightList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "rights");
                        rightCategory rightCategory = new rightCategory();
                        rightCategory.parse_Right_Category(rightList, NS, resource_individual, lom_Model, LOM_PREFIX);

                        // ================================================
                        // Relation
                        // =====================================================
                        NodeList relationList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "relation");
                        relationCategory relationCategory = new relationCategory();
                        relationCategory.parse_Relation_Category(relationList, NS, resource_individual, lom_Model,
                                metadataURI, LOM_PREFIX);

                        // ================================================
                        // Annotation
                        // =====================================================
                        NodeList annotationList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "annotation");
                        annotationCategory annotationCategory = new annotationCategory();
                        annotationCategory.parse_Annotation_Category(annotationList, NS, resource_individual,
                                lom_Model, metadataURI, LOM_PREFIX);

                        // ================================================
                        // Classification
                        // =====================================================
                        NodeList classificationList = docEle.getElementsByTagName(LOM_PREFIX + ":" + "classification");
                        classificationCategory classificationCategory = new classificationCategory();
                        classificationCategory.parse_Classification_Category(classificationList, NS,
                                resource_individual, lom_Model, metadataURI, LOM_PREFIX);

                        // ============================================================================================================
                        System.out.println("is run successfully!");

                    } catch (Exception e) {
                        System.out.println(e);
                    }
                    // lom_Model.write(fout,"N3");
                    // lom_Model.add(resource_individual.getModel());
                    // lom_Model.write(dumpFile, OUTPUT_Format);
                }
            }
            String dumpFileAddress = OUTPUT_Folder + "/" + DumpFileName + "." + OUTPUT_Extension;
            File dumpF = new File(dumpFileAddress);
            int i = 0;
            while (dumpF.exists()) {
                dumpFileAddress = OUTPUT_Folder + "/" + DumpFileName + "_" + String.valueOf(i++) + "."
                        + OUTPUT_Extension;
                dumpF = new File(dumpFileAddress);
            }

            FileOutputStream dumpFile = new FileOutputStream(dumpFileAddress);

            lom_Model.write(dumpFile, OUTPUT_Format);

            
        } catch (Exception fileE) {
            System.out.println("Can not read the folder. Error is:" + fileE);
        }

    }

    public static void main(String[] args) throws Exception {

        try {
            // Calculating run time
            // long startTime = System.currentTimeMillis();

            // reading config file
            readConfigFile();

            // Directory of XML files
            SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMddHHmm");
            System.setOut(new PrintStream(new File("XML2RDF_" + sdf.format(new Date()) + ".log")));
            File xmlFolder = new File(XML_Folder);

            if (xmlFolder != null && xmlFolder.isDirectory()) {
                FileFilter filter = new FileFilter() {
                    public boolean accept(File pathname) {
                        return pathname.isDirectory();
                    }
                };
                File[] dirs = xmlFolder.listFiles(filter);
                if (dirs != null && dirs.length > 0) {
                    System.out.println("The folder has subfolders.");
                    for (File dir : dirs) {
                        // the main parser
                        Agrega_XML_RDF parser = new Agrega_XML_RDF(dir);
                        parser.run();
                    }
                    // the main parser
                    Agrega_XML_RDF parser = new Agrega_XML_RDF(xmlFolder);
                    parser.run();
                } else {
                    // the main parser
                    Agrega_XML_RDF parser = new Agrega_XML_RDF(xmlFolder);
                    parser.run();
                }
            }

            // long endTime = System.currentTimeMillis();
            // long totalTime = endTime - startTime;
            // System.out.println("Run time="+totalTime);

        } catch (Exception e) {
            System.err.println("FileStreamsReadnWrite: " + e);
        }
    }
}
