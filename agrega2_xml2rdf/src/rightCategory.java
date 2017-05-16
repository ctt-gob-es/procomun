import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.DCTerms;

/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/7/14
 * Time: 3:01 PM
 * To change this template use File | Settings | File Templates.
 */
public class rightCategory {

    // ***************************** right - description ***********************************
    // ***************** Right Category *******************************************************
    public void parse_Right_Category(NodeList rightList, String NS, Individual resource_individual, OntModel lom_Model,
            String LOM_PREFIX) {
        if (rightList != null && rightList.getLength() > 0) {
            Node node = rightList.item(0);

            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element rightE = (Element) node;

                // ***************************** right - cost **********************************
                System.out.println("Analyzing Right.Cost");

                NodeList costList = rightE.getElementsByTagName(LOM_PREFIX + ":cost");
                if (costList.getLength() != 0) {

                    Node nodeCost = costList.item(0);
                    Element costE = (Element) nodeCost;
                    NodeList costValueList = costE.getElementsByTagName(LOM_PREFIX + ":value");

                    if (costValueList.getLength() != 0 && costValueList.item(0).hasChildNodes()) {

                    	if(costValueList.item(0).getChildNodes().item(0) != null){
                    		String costValue = costValueList.item(0).getChildNodes().item(0).getNodeValue();
                            if (!costValue.isEmpty()) {
                                OntProperty hasCost = lom_Model.getDatatypeProperty(NS + "cost");
                                resource_individual.addProperty(hasCost, costValue);
                            }
                    	}                        
                    }
                }
                // ***************************** right - copyright ***********************************
                System.out.println("Analyzing Right.Copyright");
                NodeList copyrightAndOtherRestrictionsList = rightE.getElementsByTagName(LOM_PREFIX
                        + ":copyrightAndOtherRestrictions");
                Node nodeCopyright = copyrightAndOtherRestrictionsList.item(0);
                Element copyrightAndOtherRestrictionsE = (Element) nodeCopyright;
                NodeList copyrightValueList = copyrightAndOtherRestrictionsE
                        .getElementsByTagName(LOM_PREFIX + ":value");

                if (copyrightValueList.getLength() != 0 && copyrightValueList.item(0).hasChildNodes()) {

                	if(copyrightValueList.item(0).getChildNodes().item(0) != null){
                		String copyrightValue = copyrightValueList.item(0).getChildNodes().item(0).getNodeValue();
                        if (!copyrightValue.isEmpty()) {
                            OntProperty hasCopyright = lom_Model.getDatatypeProperty(NS + "copyrightAndOtherRestrictions");
                            resource_individual.addProperty(hasCopyright, copyrightValue);

                        }
                	}                    
                }
                // ***************************** right - description ***********************************
                System.out.println("Analyzing Right.Description");
                NodeList rightDescription = rightE.getElementsByTagName(LOM_PREFIX + ":description");
                for (int i = 0; i < rightDescription.getLength(); i++) {
                    if (!rightDescription.item(i).getParentNode().getNodeName().equals(LOM_PREFIX + ":rights"))
                        continue;
                    Node rightDescriptionNode = rightDescription.item(i);
                    Element e1 = (Element) rightDescriptionNode;
                    // ***************************** string ***********************************
                    NodeList nodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                    if (nodeList.getLength() != 0 && nodeList.item(0).hasChildNodes()) {
                        for (int j = 0; j < nodeList.getLength(); j++) {
                        	if(nodeList.item(j).getChildNodes().item(0) != null){
                        		String rightDescriptionValue = nodeList.item(j).getChildNodes().item(0).getNodeValue();
                                if (!rightDescriptionValue.isEmpty()) {
                                    // OntProperty CopyrightDescriptionProperty =lom_Model.getDatatypeProperty(NS +
                                    // "hasCopyrightDescription" );
                                    OntProperty CopyrightDescriptionProperty = lom_Model
                                            .getAnnotationProperty(DCTerms.rights.getURI());
                                    if (nodeList.item(j).hasAttributes())
                                        resource_individual.addProperty(CopyrightDescriptionProperty,
                                                rightDescriptionValue, nodeList.item(j).getAttributes().item(0)
                                                        .getNodeValue());
                                    else
                                        resource_individual
                                                .addProperty(CopyrightDescriptionProperty, rightDescriptionValue);
                                }
                        	}                            
                        }
                    }
                }

                // ***************************** right - Access ***********************************
                System.out.println("Analyzing Right.Access");

                NodeList accessNodeList = rightE.getElementsByTagName(LOM_PREFIX + ":access");

                if (accessNodeList.getLength() != 0) {
                    Node access1 = accessNodeList.item(0);
                    Element accessE1 = (Element) access1;
                    NodeList accessDescriptionValueList1 = accessE1.getElementsByTagName(LOM_PREFIX + ":string");
                    if (accessDescriptionValueList1.getLength() != 0
                            && accessDescriptionValueList1.item(0).hasChildNodes()) {

                    	if(accessDescriptionValueList1.item(0).getChildNodes().item(0) != null){
                    		String accessDescriptionTemp = accessDescriptionValueList1.item(0).getChildNodes().item(0)
                                    .getNodeValue();
                            if (!accessDescriptionTemp.isEmpty()) {

                                OntProperty AccessDescriptionProperty = lom_Model.getDatatypeProperty(NS
                                        + "accessDescription");
                                if (accessDescriptionValueList1.item(0).hasAttributes())
                                    resource_individual.addProperty(AccessDescriptionProperty, accessDescriptionTemp,
                                            accessDescriptionValueList1.item(0).getAttributes().item(0).getNodeValue());
                                else
                                    resource_individual.addProperty(AccessDescriptionProperty, accessDescriptionTemp);
                            }
                    	}                        
                    }

                    NodeList accessTypeList1 = accessE1.getElementsByTagName(LOM_PREFIX + ":value");

                    if (accessTypeList1.getLength() != 0 && accessTypeList1.item(0).hasChildNodes()) {

                    	if(accessTypeList1.item(0).getChildNodes().item(0) != null){
                    		String accessType1 = accessTypeList1.item(0).getChildNodes().item(0).getNodeValue();
                            if (!accessType1.isEmpty()) {
                                OntProperty AccessType = lom_Model.getDatatypeProperty(NS + "accessType");
                                resource_individual.addProperty(AccessType, accessType1);
                            }
                    	}                        
                    }
                }

            }
        }// Rights

    }
}