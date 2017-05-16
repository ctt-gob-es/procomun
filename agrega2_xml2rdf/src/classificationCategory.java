import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.RDF;

/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/7/14
 * Time: 3:21 PM
 * To change this template use File | Settings | File Templates.
 */
public class classificationCategory {

    // ***************** Classification Category *******************************************************
    public void parse_Classification_Category(NodeList classificationList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {

        if (classificationList != null && classificationList.getLength() > 0) {

            for (int classificationIndex = 0; classificationIndex < classificationList.getLength(); classificationIndex++) {

                OntClass ClassificationC = lom_Model.getOntClass(NS + "Classification");
                OntProperty ClassificationProperty = lom_Model.getObjectProperty(NS + "classification");
                Individual Classification_Individual = lom_Model.createIndividual(NS + "Classification_" + metadataURI
                        + "_" + (classificationIndex + 1), ClassificationC);
                resource_individual.addProperty(ClassificationProperty, Classification_Individual);

                Node node = classificationList.item(classificationIndex);

                // if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element classificationE = (Element) node;

                // ***************************** classification - purpose ***********************************
                System.out.println("Analyzing Classification.Purpose");
                NodeList classificationPurposeList = classificationE.getElementsByTagName(LOM_PREFIX + ":purpose");
                Node purposeNode = classificationPurposeList.item(0);
                Element purposeE = (Element) purposeNode;
                NodeList purposeValueList = purposeE.getElementsByTagName(LOM_PREFIX + ":value");

                if (purposeValueList.getLength() != 0 && purposeValueList.item(0).hasChildNodes()) {

                	if(purposeValueList.item(0).getChildNodes().item(0) != null){
                		String purposeValue = purposeValueList.item(0).getChildNodes().item(0).getNodeValue();
                        if (!purposeValue.isEmpty()) {
                            OntProperty hasClassificationPurpose = lom_Model.getDatatypeProperty(NS
                                    + "classificationPurpose");
                            Classification_Individual.addProperty(hasClassificationPurpose, purposeValue);
                        }
                	}
                }

                // ***************************** Description **********************************
                System.out.println("Analyzing Classification.Description");
                NodeList classificationDescriptionList = classificationE.getElementsByTagName(LOM_PREFIX
                        + ":description");
                Node descNode = classificationDescriptionList.item(0);
                Element e1 = (Element) descNode;
                // ***************************** string ***********************************
                if (classificationDescriptionList.getLength() != 0) {
                    NodeList descNodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                    if (descNodeList.getLength() != 0 && descNodeList.item(0).hasChildNodes()) {// &&
                                                                                                // classificationDescriptionList.item(0).getParentNode().getNodeName().equals(LOM_PREFIX+":classification")
                                                                                                // ) {

                        for (int j = 0; j < descNodeList.getLength(); j++) {
                            if (classificationDescriptionList.item(j).getParentNode().getNodeName()
                                    .equals(LOM_PREFIX + ":classification")) {
                            	if(descNodeList.item(j).getChildNodes().item(0) != null){
                            		String descriptionValue = descNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                    if (!descriptionValue.isEmpty()) {
                                        OntProperty description = lom_Model.getDatatypeProperty(NS
                                                + "classificationDescription");
                                        if (descNodeList.item(j).hasAttributes())
                                            Classification_Individual.addProperty(description, descriptionValue,
                                                    descNodeList.item(j).getAttributes().item(0).getNodeValue());
                                        else
                                            Classification_Individual.addProperty(description, descriptionValue);

                                    }
                            	}                                
                            }
                        }
                    }
                }
                // ***************************** Keyword **********************************
                System.out.println("Analyzing Classification.Keyword");
                NodeList keywordList = classificationE.getElementsByTagName(LOM_PREFIX + ":keyword");

                for (int i = 0; i < keywordList.getLength(); i++) {

                    // ******************* CLASSIFICATION_KEYWORD_INSTANCE ****************************
                    OntClass keywordC = lom_Model.getOntClass(NS + "LangString");
                    OntProperty C_keyword = lom_Model.getObjectProperty(NS + "classificationKeyword");
                    Individual Classification_keyword = lom_Model.createIndividual(NS + "classification_keyword_"
                            + metadataURI + "_" + (classificationIndex + 1) + "_" + (i + 1), keywordC);
                    Classification_Individual.addProperty(C_keyword, Classification_keyword);

                    Node keywordNode = keywordList.item(i);
                    Element keywrodE = (Element) keywordNode;
                    // ***************************** string ***********************************
                    NodeList keywordNodeList = keywrodE.getElementsByTagName(LOM_PREFIX + ":string");
                    if (keywordNodeList.getLength() != 0 && keywordNodeList.item(0).hasChildNodes()) {

                        for (int j = 0; j < keywordNodeList.getLength(); j++) {
                            if (keywordNodeList.item(j).getParentNode().getNodeName().equals(LOM_PREFIX + ":keyword")) {
                            	if(keywordNodeList.item(j).getChildNodes().item(0) != null){
                            		String keywordValue = keywordNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                    if (!keywordValue.isEmpty()) {
                                        OntProperty keywordV = lom_Model.getAnnotationProperty(RDF.value.getURI());
                                        if (keywordNodeList.item(j).hasAttributes())
                                            Classification_keyword.addProperty(keywordV, keywordValue, keywordNodeList
                                                    .item(j).getAttributes().item(0).getNodeValue());
                                        else
                                            Classification_keyword.addProperty(keywordV, keywordValue);
                                    }
                            	}                                
                            }
                        }
                    }
                }
                // ***************************** taxonpath **********************************
                System.out.println("Analyzing Classification.TaxonPath");
                NodeList taxonPathList = classificationE.getElementsByTagName(LOM_PREFIX + ":taxonPath");
                for (int taxonPathIndex = 0; taxonPathIndex < taxonPathList.getLength(); taxonPathIndex++) {
                    Node taxonPathNode = taxonPathList.item(taxonPathIndex);
                    Element taxonPathE = (Element) taxonPathNode;

                    // Adding blank node
                    // ******************* GENERAL_IDENTIFIER_INSTANCE ****************************
                    OntClass TaxonPath = lom_Model.getOntClass(NS + "TaxonPath");
                    OntProperty TaxonPathProperty = lom_Model.getObjectProperty(NS + "taxonPath");
                    Individual TaxonPath_Individual = lom_Model.createIndividual(NS + "TaxonPath_" + metadataURI + "_"
                            + (classificationIndex + 1) + "_" + (taxonPathIndex + 1), TaxonPath);
                    Classification_Individual.addProperty(TaxonPathProperty, TaxonPath_Individual);

                    // ***************************** string ***********************************
                    NodeList sourceList = taxonPathE.getElementsByTagName(LOM_PREFIX + ":source");
                    Node sourceNode = sourceList.item(0);
                    Element sourceE = (Element) sourceNode;
                    NodeList sourceStringList = sourceE.getElementsByTagName(LOM_PREFIX + ":string");

                    if (sourceStringList.getLength() != 0 && sourceStringList.item(0).hasChildNodes()) {

                        for (int j = 0; j < sourceStringList.getLength(); j++) {
                        	if(sourceStringList.item(j).getChildNodes().item(0) != null){
                        		String sourceStringListValue = sourceStringList.item(j).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!sourceStringListValue.isEmpty()) {
                                    OntProperty hasTaxonpathSource = lom_Model.getDatatypeProperty(NS + "taxonpathSource");
                                    if (sourceStringList.item(j).hasAttributes())
                                        TaxonPath_Individual.addProperty(hasTaxonpathSource, sourceStringListValue,
                                                sourceStringList.item(j).getAttributes().item(0).getNodeValue());
                                    else
                                        TaxonPath_Individual.addProperty(hasTaxonpathSource, sourceStringListValue);

                                }
                        	}
                        }
                    }

                    // ***************************** Taxon ***********************************
                    System.out.println("Analyzing Classification.Taxon");
                    NodeList taxonIdentifierList = taxonPathE.getElementsByTagName(LOM_PREFIX + ":taxon");
                    for (int taxonIndex = 0; taxonIndex < taxonIdentifierList.getLength(); taxonIndex++) {

                        Node taxonNode = taxonIdentifierList.item(taxonIndex);
                        Element taxonE = (Element) taxonNode;
                        // ******************* GENERAL_IDENTIFIER_INSTANCE ****************************
                        OntClass Taxon = lom_Model.getOntClass(NS + "Taxon");
                        OntProperty TaxonProperty = lom_Model.getObjectProperty(NS + "classificationTaxon");
                        Individual Taxon_Individual = lom_Model.createIndividual(NS + "Taxon_" + metadataURI + "_"
                                + (classificationIndex + 1) + "_" + (taxonPathIndex + 1) + "_" + (taxonIndex + 1),
                                Taxon);
                        TaxonPath_Individual.addProperty(TaxonProperty, Taxon_Individual);

                        // ***************************** catalog ***********************************
                        NodeList taxonIdList = taxonE.getElementsByTagName(LOM_PREFIX + ":id");

                        if (taxonIdList.item(0).hasChildNodes()) {
                        	if(taxonIdList.item(0).getChildNodes().item(0) != null){
                        		String taxonIdValue = taxonIdList.item(0).getChildNodes().item(0).getNodeValue();
                                if (!taxonIdValue.isEmpty()) {
                                    OntProperty hasTaxonId = lom_Model.getDatatypeProperty(NS + "taxonId");
                                    Taxon_Individual.addProperty(hasTaxonId, taxonIdValue);
                                }
                        	}                            
                        }

                        // ***************************** Entry ***********************************
                        NodeList taxonEntryNodeList = taxonE.getElementsByTagName(LOM_PREFIX + ":entry");

                        for (int i = 0; i < taxonEntryNodeList.getLength(); i++) {
                            Node taxonEntryNode = taxonEntryNodeList.item(i);
                            Element taxonEntryE = (Element) taxonEntryNode;
                            // ***************************** string ***********************************
                            NodeList nodeList = taxonEntryE.getElementsByTagName(LOM_PREFIX + ":string");
                            if (nodeList.getLength() != 0 && nodeList.item(0).hasChildNodes()) {

                                for (int j = 0; j < nodeList.getLength(); j++) {
                                	if(nodeList.item(0).getChildNodes().item(0) != null){
                                		String taxonEntryValue = nodeList.item(0).getChildNodes().item(0).getNodeValue();
                                        if (!taxonEntryValue.isEmpty()) {
                                            OntProperty hasTaxonEntry = lom_Model.getDatatypeProperty(NS + "taxonEntry");
                                            Taxon_Individual.addProperty(hasTaxonEntry, taxonEntryValue);
                                        }	
                                	}                                    
                                }
                            }
                        }
                    }
                }
                // }
            }
            // m.write( System.out, "Turtle" );
            // System.exit(1);

        }
    }
}
