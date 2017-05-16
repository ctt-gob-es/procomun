import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.VCARD;

/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/7/14
 * Time: 3:07 PM
 * To change this template use File | Settings | File Templates.
 */
public class annotationCategory {
    // ***************** Annotation Category *******************************************************
    public void parse_Annotation_Category(NodeList annotationList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {
        if (annotationList != null && annotationList.getLength() > 0) {
            for (int annotationIndex = 0; annotationIndex < annotationList.getLength(); annotationIndex++) {

                Node node = annotationList.item(annotationIndex);

                OntClass AnnotationC = lom_Model.getOntClass(NS + "Annotation");
                OntProperty AnnotationProperty = lom_Model.getObjectProperty(NS + "annotation");
                Individual Annotation_Individual = lom_Model.createIndividual(NS + "AnnotationIndex_" + metadataURI
                        + "_" + (annotationIndex + 1), AnnotationC);
                resource_individual.addProperty(AnnotationProperty, Annotation_Individual);

                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element annotationE = (Element) node;

                    // ***************************** annotation entity ***********************************
                    System.out.println("Analyzing Annotation.Entity");

                    NodeList annotationEntityList = annotationE.getElementsByTagName(LOM_PREFIX + ":entity");
                    if (annotationEntityList.getLength() != 0 && annotationEntityList.item(0).hasChildNodes()) {
                        OntClass AnnotationEntity = lom_Model.getOntClass(VCARD.getURI());
                        OntProperty AnnotationEntityProperty = lom_Model.getObjectProperty(NS + "annotationEntity");
                        Individual AnnotationEntity_Individual = lom_Model.createIndividual(NS + "AnnotationEntity_"
                                + metadataURI + "_" + (annotationIndex + 1), AnnotationEntity);
                        Annotation_Individual.addProperty(AnnotationEntityProperty, AnnotationEntity_Individual);

                        if(annotationEntityList.item(0).getChildNodes().item(0) != null){
                        	String annotationValue = annotationEntityList.item(0).getChildNodes().item(0).getNodeValue();
                            if (!annotationValue.isEmpty()) {
                                vCardParser vCardParser = new vCardParser();
                                if (!vCardParser.name(annotationValue).trim().isEmpty())
                                    AnnotationEntity_Individual.addProperty(VCARD.N, vCardParser.name(annotationValue)
                                            .trim());
                                if (!vCardParser.fullName(annotationValue).trim().isEmpty())
                                    AnnotationEntity_Individual.addProperty(VCARD.FN, vCardParser.fullName(annotationValue)
                                            .trim());
                                if (!vCardParser.email(annotationValue).trim().isEmpty())
                                    AnnotationEntity_Individual.addProperty(VCARD.EMAIL, vCardParser.email(annotationValue)
                                            .trim());
                                if (!vCardParser.organization(annotationValue).trim().isEmpty())
                                    AnnotationEntity_Individual.addProperty(VCARD.ORG,
                                            vCardParser.organization(annotationValue).trim());
                           }
                        }                        
                    }
                    // ***************************** annotation dateTime ***********************************
                    // ***************************** Entity -Date ***********************************
                    NodeList contributionDateNodeList = annotationE.getElementsByTagName(LOM_PREFIX + ":dateTime");
                    if (contributionDateNodeList.getLength() != 0 && contributionDateNodeList.item(0).hasChildNodes()) {
                    	if(contributionDateNodeList.item(0).getChildNodes().item(0) != null){
                    		String contributionDate = contributionDateNodeList.item(0).getChildNodes().item(0)
                                    .getNodeValue();
                            if (!contributionDate.isEmpty()) {
                                OntProperty ContributionDateProperty = lom_Model.getDatatypeProperty(NS + "dateTimeValue");
                                Annotation_Individual.addProperty(ContributionDateProperty, contributionDate);
                            }
                    	}                        
                    }
                    // ***************************** Entity -Description ***********************************
                    NodeList contributionDateDescriptionNodeList = annotationE.getElementsByTagName(LOM_PREFIX
                            + ":string");
                    if (contributionDateDescriptionNodeList.getLength() != 0
                            && contributionDateDescriptionNodeList.item(0).hasChildNodes()) {
                    	if(contributionDateDescriptionNodeList.item(0).getChildNodes().item(0) != null){
                    		String contributionDateDescription = contributionDateDescriptionNodeList.item(0)
                                    .getChildNodes().item(0).getNodeValue();
                            if (!contributionDateDescription.isEmpty()) {
                                OntProperty ContributionDateDescriptionProperty = lom_Model.getDatatypeProperty(NS
                                        + "dateTimeDescription");
                                if (contributionDateDescriptionNodeList.item(0).hasAttributes())
                                    Annotation_Individual.addProperty(ContributionDateDescriptionProperty,
                                            contributionDateDescription, contributionDateDescriptionNodeList.item(0)
                                                    .getAttributes().item(0).getNodeValue());
                                else
                                    Annotation_Individual.addProperty(ContributionDateDescriptionProperty,
                                            contributionDateDescription);
                            }
                    	}                        
                    }
                    // ***************************** Description **********************************
                    System.out.println("Analyzing Annotation.Description");
                    NodeList annotationDescriptionList = annotationE.getElementsByTagName(LOM_PREFIX + ":description");
                    for (int i = 0; i < annotationDescriptionList.getLength(); i++) {
                        if (annotationDescriptionList.item(i).getParentNode().getNodeName()
                                .equals(LOM_PREFIX + ":annotation")) {

                            Node descNode = annotationDescriptionList.item(i);
                            Element e1 = (Element) descNode;
                            // ***************************** string ***********************************
                            NodeList descNodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");

                            for (int j = 0; j < descNodeList.getLength(); j++) {
                            	if(descNodeList.item(j).getChildNodes().item(0) != null){
                            		String descriptionValue = descNodeList.item(j).getChildNodes().item(0).getNodeValue();
                                    if (!descriptionValue.isEmpty()) {
                                        OntProperty description = lom_Model.getDatatypeProperty(NS
                                                + "annotationDescription");
                                        if (descNodeList.item(j).hasAttributes())
                                            Annotation_Individual.addProperty(description, descriptionValue, descNodeList
                                                    .item(j).getAttributes().item(0).getNodeValue());
                                        else
                                            Annotation_Individual.addProperty(description, descriptionValue);
                                    }
                            	}                                
                            }
                        }
                    }
                }
            } // Annotation
        }

    }

}
