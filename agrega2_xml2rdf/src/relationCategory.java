import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.DCTerms;

/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/7/14
 * Time: 3:06 PM
 * To change this template use File | Settings | File Templates.
 */
public class relationCategory {

    // ***************** Relation Category *******************************************************
    public void parse_Relation_Category(NodeList relationList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {
        if (relationList != null && relationList.getLength() > 0) {
            for (int relationIndex = 0; relationIndex < relationList.getLength(); relationIndex++) {

                OntClass RelationalC = lom_Model.getOntClass(NS + "Relation");
                OntProperty RelationProperty = lom_Model.getObjectProperty(NS + "relation");
                Individual Relation_Individual = lom_Model.createIndividual(NS + "Relation_" + metadataURI + "_"
                        + (relationIndex + 1), RelationalC);
                resource_individual.addProperty(RelationProperty, Relation_Individual);

                Node node = relationList.item(relationIndex);

                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element relationE = (Element) node;

                    // ***************************** relation- kind ***********************************
                    System.out.println("Analyzing Relation.Kind");
                    NodeList kindList = relationE.getElementsByTagName(LOM_PREFIX + ":kind");
                    Node kindNode = kindList.item(0);
                    Element kindE = (Element) kindNode;
                    NodeList kindValueList = kindE.getElementsByTagName(LOM_PREFIX + ":value");
                    if (kindValueList.getLength() != 0 && kindValueList.item(0).hasChildNodes()) {
                    	if(kindValueList.item(0).getChildNodes().item(0) != null){
                    		String kindValue = kindValueList.item(0).getChildNodes().item(0).getNodeValue();
                            if (!kindValue.isEmpty()) {
                                OntProperty relationKindProperty = lom_Model.getDatatypeProperty(NS + "relationKind");
                                Relation_Individual.addProperty(relationKindProperty, kindValue);
                            }
                    	}                        
                    }

                    // ***************************** relation- Resource ***********************************
                    System.out.println("Analyzing Relation.Resource");
                    NodeList resourceList = relationE.getElementsByTagName(LOM_PREFIX + ":resource");
                    Node resourceNode = resourceList.item(0);
                    Element resourceE = (Element) resourceNode;
                    // ***************************** resource identifier ***********************************
                    NodeList resourceIdentifierList = resourceE.getElementsByTagName(LOM_PREFIX + ":identifier");
                    for (int i = 0; i < resourceIdentifierList.getLength(); i++) {
                        Node resourceIdentifierNode = resourceIdentifierList.item(i);
                        Element resourceIdentifierE = (Element) resourceIdentifierNode;

                        // ******************* RESOURCE_IDENTIFIER_INSTANCE ****************************
                        OntClass Identifier = lom_Model.getOntClass(NS + "Identifier");
                        OntProperty R_Identifier = lom_Model.getObjectProperty(NS + "identifier");
                        Individual Resource_Identifier = lom_Model.createIndividual(NS + "relation_identifier_"
                                + metadataURI + "_" + (relationIndex + 1) + "_" + (i + 1), Identifier);
                        Relation_Individual.addProperty(R_Identifier, Resource_Identifier);

                        // ***************************** catalog ***********************************
                        System.out.println("Analyzing ResourceIdentifier.Catalog");
                        NodeList resourceCatalogNodeList = resourceIdentifierE.getElementsByTagName(LOM_PREFIX
                                + ":catalog");
                        if (resourceCatalogNodeList.getLength() != 0 && resourceCatalogNodeList.item(0).hasChildNodes()) {

                        	if(resourceCatalogNodeList.item(0).getChildNodes().item(0) != null){
                        		String resourceCatalogValue = resourceCatalogNodeList.item(0).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!resourceCatalogValue.isEmpty()) {
                                    OntProperty hasCatalog = lom_Model.getDatatypeProperty(NS + "identifierCatalog");
                                    Resource_Identifier.addProperty(hasCatalog, resourceCatalogValue);
                                }
                        	}                            
                        }

                        // ***************************** Entry ***********************************
                        System.out.println("Analyzing ResourceIdentifier.Entry");
                        NodeList resourceEntryNodeList = resourceIdentifierE
                                .getElementsByTagName(LOM_PREFIX + ":entry");
                        if (resourceEntryNodeList.getLength() != 0 && resourceEntryNodeList.item(0).hasChildNodes()) {
                        	if(resourceEntryNodeList.item(0).getChildNodes().item(0) != null){
                        		String resourceEntryValue = resourceEntryNodeList.item(0).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!resourceEntryValue.isEmpty()) {
                                    // OntProperty hasEntry=lom_Model.getDatatypeProperty(NS+"hasEntry");
                                    OntProperty hasEntry = lom_Model.getAnnotationProperty(DCTerms.identifier.getURI());
                                    Resource_Identifier.addProperty(hasEntry, resourceEntryValue);
                                }
                        	}                            
                        }
                    }

                    // ***************************** Description **********************************
                    System.out.println("Analyzing Resource.Description");
                    NodeList resourceDescriptionList = resourceE.getElementsByTagName(LOM_PREFIX + ":description");
                    for (int i = 0; i < resourceDescriptionList.getLength(); i++) {
                        Node descNode = resourceDescriptionList.item(i);
                        Element e1 = (Element) descNode;

                        // ******************* Relational_DESCRIPTION_INSTANCE ****************************
                        OntClass DescriptionR = lom_Model.getOntClass(NS + "LangString");
                        OntProperty R_Description = lom_Model.getObjectProperty(NS + "relatedResourceDescription");
                        Individual Relational_Description = lom_Model.createIndividual(NS + "relational_description_"
                                + metadataURI + "_" + (relationIndex + 1) + "_" + (i + 1), DescriptionR);
                        Relation_Individual.addProperty(R_Description, Relational_Description);

                        // ***************************** string ***********************************
                        NodeList descNodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                        if (descNodeList.getLength() != 0 && descNodeList.item(0).hasChildNodes()) {

                            for (int j = 0; j < descNodeList.getLength(); j++) {
                            	if(descNodeList.item(j).getChildNodes().item(0) != null){
                            		String descriptionValue = descNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                    if (!descriptionValue.isEmpty()) {
                                        // OntProperty description =lom_Model.getDatatypeProperty(NS + "hasValue" );
                                        OntProperty description = lom_Model.getAnnotationProperty(DCTerms.description
                                                .getURI());
                                        if (descNodeList.item(j).hasAttributes())
                                            Relational_Description.addProperty(description, descriptionValue, descNodeList
                                                    .item(j).getAttributes().item(0).getNodeValue());
                                        else
                                            Relational_Description.addProperty(description, descriptionValue);

                                    }
                            	}                                
                            }
                        }
                    }
                }
            } // Relation
        }

    }
}
