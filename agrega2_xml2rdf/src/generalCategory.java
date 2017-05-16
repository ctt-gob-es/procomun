import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.DCTerms;
import com.hp.hpl.jena.vocabulary.RDF;

/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/7/14
 * Time: 2:41 PM
 * To change this template use File | Settings | File Templates.
 */
public class generalCategory {
    Boolean hasData;

    public void parse_General_Category(NodeList General_List, String NS, Individual resource_individual,
            OntModel LOM_Model, String metadataURI, String LOM_PREFIX) {
        // Is there any element in lom:general?
        if (General_List != null && General_List.getLength() > 0) {
            Node node = General_List.item(0);
            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element generalE = (Element) node;

                // ***************************** LOM:identifier <MANY> ***********************************
                NodeList General_Identifier_List = generalE.getElementsByTagName(LOM_PREFIX + ":identifier");
                for (int i = 0; i < General_Identifier_List.getLength(); i++) {
                    Node general_Identifier_Node = General_Identifier_List.item(i);
                    Element generalID = (Element) general_Identifier_Node;
                    // ******************* GENERAL_IDENTIFIER_INSTANCE ****************************
                    OntClass Identifier_Class = LOM_Model.getOntClass(NS + "Identifier");
                    OntProperty Identifier_Property = LOM_Model.getObjectProperty(NS + "identifier");
                    Individual General_Identifier_Individual = LOM_Model.createIndividual(NS + "general_identifier_"
                            + metadataURI + "_" + (i + 1), Identifier_Class);
                    resource_individual.addProperty(Identifier_Property, General_Identifier_Individual);

                    // ***************************** catalog ***********************************
                    System.out.println("Analyzing general.Catalog_" + metadataURI + "_" + (i + 1));
                    NodeList GCatalogNodeList = generalID.getElementsByTagName(LOM_PREFIX + ":catalog");
                    if (GCatalogNodeList.getLength() != 0 && GCatalogNodeList.item(0).hasChildNodes()) {
                    	if(GCatalogNodeList.item(0).getChildNodes().item(0) != null){
                    		 String generalCatalogValue = GCatalogNodeList.item(0).getChildNodes().item(0).getNodeValue();
                             if (!generalCatalogValue.isEmpty()) {
                                 hasData = true;
                                 OntProperty hasCatalog = LOM_Model.getDatatypeProperty(NS + "identifierCatalog");
                                 General_Identifier_Individual.addProperty(hasCatalog, generalCatalogValue);
                             }
                    	}                       
                    }
                    // ***************************** Entry ***********************************
                    System.out.println("Analyzing general.Entry_" + metadataURI + "_" + (i + 1));
                    NodeList GEntryNodeList = generalID.getElementsByTagName(LOM_PREFIX + ":entry");
                    if (GEntryNodeList.getLength() != 0 && GEntryNodeList.item(0).hasChildNodes()) {
                    	if(GEntryNodeList.item(0).getChildNodes().item(0) != null){
                    		String generalEntryValue = GEntryNodeList.item(0).getChildNodes().item(0).getNodeValue();
                            if (!generalEntryValue.isEmpty()) {
                                hasData = true;
                                // OntProperty hasEntry=LOM_Model.getDatatypeProperty(NS+"identifierEntry");
                                OntProperty hasEntry = LOM_Model.getAnnotationProperty(DCTerms.identifier.getURI());
                                General_Identifier_Individual.addProperty(hasEntry, generalEntryValue);
                           }
                    	}                        
                    }
                }
                // ***************************** Title **********************************
                System.out.println("Analyzing general.Title");
                NodeList titleList = generalE.getElementsByTagName(LOM_PREFIX + ":title");
                for (int i = 0; i < titleList.getLength(); i++) {
                    Node titleNode = titleList.item(i);
                    Element e1 = (Element) titleNode;

                    // ***************************** string ***********************************
                    NodeList nodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                    if (nodeList.getLength() != 0 && nodeList.item(0).hasChildNodes()) {
                        for (int j = 0; j < nodeList.getLength(); j++) {
                        	if(nodeList.item(j).getChildNodes().item(0) != null){
                        		String titleValue = nodeList.item(j).getChildNodes().item(0).getNodeValue();
                                if (!titleValue.isEmpty()) {
                                    // OntProperty general_title = LOM_Model.getDatatypeProperty(NS + "hasTitle" );
                                    OntProperty general_title = LOM_Model.getAnnotationProperty(DCTerms.title.getURI());

                                    if (nodeList.item(j).hasAttributes())
                                        resource_individual.addProperty(general_title, titleValue, nodeList.item(j)
                                                .getAttributes().item(0).getNodeValue());
                                    else
                                        resource_individual.addProperty(general_title, titleValue);
                                }
                        	}                            
                        }
                    }
                }

                // ***************************** Language **********************************
                System.out.println("Analyzing general.Language");
                NodeList GLang = generalE.getElementsByTagName(LOM_PREFIX + ":language");
                if (GLang.getLength() != 0 && GLang.item(0).hasChildNodes()) {
                    for (int i = 0; i < GLang.getLength(); i++) {
                        if (GLang.item(i).getChildNodes().item(0).equals(null))
                            break;
                        String GeneralLanguage = GLang.item(i).getChildNodes().item(0).getNodeValue();
                        if (!GeneralLanguage.isEmpty()) {
                            OntProperty hasLanguage = LOM_Model.getAnnotationProperty(DCTerms.language.getURI());
                            resource_individual.addProperty(hasLanguage, GeneralLanguage);
                        }
                    }
                }
                // ***************************** General Description **********************************

                NodeList descList = generalE.getElementsByTagName(LOM_PREFIX + ":description");
                for (int i = 0; i < descList.getLength(); i++) {
                    System.out.println("Analyzing general.Description_" + metadataURI + "_" + (i + 1));
                    // ******************* GENERAL_DESCRIPTION_INSTANCE ****************************
                    OntClass Description = LOM_Model.getOntClass(NS + "LangString");
                    OntProperty G_Description = LOM_Model.getObjectProperty(NS + "description");
                    Individual General_Description = LOM_Model.createIndividual(NS + "general_description_"
                            + metadataURI + "_" + (i + 1), Description);
                    resource_individual.addProperty(G_Description, General_Description);

                    Node descNode = descList.item(i);
                    Element e1 = (Element) descNode;
                    // ***************************** string ***********************************
                    NodeList descNodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                    if (descNodeList.getLength() != 0 && descNodeList.item(0).hasChildNodes()) {
                        for (int j = 0; j < descNodeList.getLength(); j++) {
                        	if(descNodeList.item(j).getChildNodes().item(0) != null){
                        		String descriptionValue = descNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                if (!descNodeList.item(j).getChildNodes().item(0).getNodeValue().isEmpty()) {
                                    // OntProperty description = LOM_Model.getDatatypeProperty(NS + "hasValue" );
                                    OntProperty description = LOM_Model.getAnnotationProperty(DCTerms.description.getURI());
                                    if (descNodeList.item(j).hasAttributes())
                                        General_Description.addProperty(description, descriptionValue, descNodeList.item(j)
                                                .getAttributes().item(0).getNodeValue());
                                    else
                                        General_Description.addProperty(description, descriptionValue);
                                }
                        	}                            
                        }
                    }
                }
                System.out.println("Analyzing general.Keyword");

                // ***************************** Keyword **********************************
                NodeList keywordList = generalE.getElementsByTagName(LOM_PREFIX + ":keyword");
                for (int i = 0; i < keywordList.getLength(); i++) {
                    // ******************* GENERAL_KEYWORD_INSTANCE ****************************
                    OntClass keywordC = LOM_Model.getOntClass(NS + "LangString");
                    OntProperty G_keyword = LOM_Model.getObjectProperty(NS + "keyword");
                    Individual General_keyword = LOM_Model.createIndividual(NS + "general_keyword_" + metadataURI + "_"
                            + (i + 1), keywordC);
                    resource_individual.addProperty(G_keyword, General_keyword);

                    // ***************************** writing files **********************************
                    Node keywordNode = keywordList.item(i);
                    Element keywordE = (Element) keywordNode;
                    // ***************************** string ***********************************
                    NodeList keywordNodeList = keywordE.getElementsByTagName(LOM_PREFIX + ":string");
                    if (keywordNodeList.getLength() != 0 && keywordNodeList.item(0).hasChildNodes()) {

                        for (int j = 0; j < keywordNodeList.getLength(); j++) {
                        	if(keywordNodeList.item(j).getChildNodes().item(0) != null){
                        		String keywordValue = keywordNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                if (!keywordValue.isEmpty()) {
                                    // OntProperty keywordV = LOM_Model.getDatatypeProperty(NS + "hasValue" );
                                    OntProperty keywordV = LOM_Model.getAnnotationProperty(RDF.value.getURI());
                                    if (keywordNodeList.item(j).hasAttributes())
                                        General_keyword.addProperty(keywordV, keywordValue, keywordNodeList.item(j)
                                                .getAttributes().item(0).getNodeValue());
                                    else
                                        General_keyword.addProperty(keywordV, keywordValue);
                                }
                        	}                            
                        }
                    }
                }

                // ***************************** Coverage **********************************
                System.out.println("Analyzing general.Coverage");
                NodeList coverageList = generalE.getElementsByTagName(LOM_PREFIX + ":coverage");

                for (int i = 0; i < coverageList.getLength(); i++) {
                    // ******************* GENERAL_COVERAGE_INSTANCE ****************************
                    OntClass coverageC = LOM_Model.getOntClass(NS + "LangString");
                    OntProperty G_coverage = LOM_Model.getObjectProperty(NS + "coverage");
                    Individual General_coverage = LOM_Model.createIndividual(NS + "general_coverage_" + metadataURI
                            + "_" + (i + 1), coverageC);
                    resource_individual.addProperty(G_coverage, General_coverage);

                    Node coverageNode = coverageList.item(i);
                    Element coverageE = (Element) coverageNode;
                    // ***************************** string ***********************************
                    NodeList coverageNodeList = coverageE.getElementsByTagName(LOM_PREFIX + ":string");
                    if (coverageNodeList.getLength() != 0 && coverageNodeList.item(0).hasChildNodes()) {

                        for (int j = 0; j < coverageNodeList.getLength(); j++) {
                        	if(coverageNodeList.item(j).getChildNodes().item(0) != null){
                        		String coverageValue = coverageNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                if (!coverageValue.isEmpty()) {
                                    // OntProperty coverageV = LOM_Model.getDatatypeProperty(NS + "hasValue" );
                                    OntProperty coverageV = LOM_Model.getAnnotationProperty(DCTerms.coverage.getURI());
                                    if (coverageNodeList.item(j).hasAttributes())
                                        General_coverage.addProperty(coverageV, coverageValue, coverageNodeList.item(j)
                                                .getAttributes().item(0).getNodeValue());
                                    else
                                        General_coverage.addProperty(coverageV, coverageValue);

                                }
                        	}                            
                        }
                    }
                }

                // ***************************** Structure **********************************
                System.out.println("Analyzing general.Structure");
                NodeList GStruct = generalE.getElementsByTagName(LOM_PREFIX + ":structure");

                Node GIDNode1 = GStruct.item(0);
                Element generalID1 = (Element) GIDNode1;

                // ***************************** value ***********************************
                if (GStruct.getLength() != 0 && GStruct.item(0).hasChildNodes()) {
                    NodeList GeneralStructList = generalID1.getElementsByTagName(LOM_PREFIX + ":value");

                    if(GeneralStructList.item(0).getChildNodes().item(0) != null){
                    	 String GeneralStruct = GeneralStructList.item(0).getChildNodes().item(0).getNodeValue();
                         if (!GeneralStruct.isEmpty()) {
                             OntProperty structure = LOM_Model.getDatatypeProperty(NS + "structure");
                             resource_individual.addProperty(structure, GeneralStruct);
                         }
                    }                   
                }

                // ***************************** Aggregation Level **********************************
                System.out.println("Analyzing general.Aggregation Level");
                NodeList GAggregation = generalE.getElementsByTagName(LOM_PREFIX + ":aggregationLevel");

                Node GAggNode1 = GAggregation.item(0);
                Element generalAgg = (Element) GAggNode1;

                // ***************************** value ***********************************
                if (GAggregation.getLength() != 0 && GAggregation.item(0).hasChildNodes()) {
                    NodeList GeneralAggList = generalAgg.getElementsByTagName(LOM_PREFIX + ":value");
                    if(GeneralAggList.item(0).getChildNodes().item(0) != null){
                    	String GeneralAgg = GeneralAggList.item(0).getChildNodes().item(0).getNodeValue();
                        if (!GeneralAgg.isEmpty()) {
                            OntProperty aggregationLevelProperty = LOM_Model.getDatatypeProperty(NS + "aggregationLevel");
                            resource_individual.addProperty(aggregationLevelProperty, GeneralAgg);
                        }
                    }                    
                }
            }
        }
    }
}
