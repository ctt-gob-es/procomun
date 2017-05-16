import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.DCTerms;
import com.hp.hpl.jena.vocabulary.RDF;

public class educationalCategory {

    // ***************** Educational Category *******************************************************
    public void parse_Educational_Category(NodeList educationalList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {

        if (educationalList != null && educationalList.getLength() > 0) {

            for (int educationalIndex = 0; educationalIndex < educationalList.getLength(); educationalIndex++) {

                Node node = educationalList.item(educationalIndex);

                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element educationalE = (Element) node;

                    OntClass EducationalC = lom_Model.getOntClass(NS + "Educational");
                    OntProperty EducationalProperty = lom_Model.getObjectProperty(NS + "educational");
                    Individual Educational_Individual = lom_Model.createIndividual(NS + "Educational_" + metadataURI
                            + "_" + (educationalIndex + 1), EducationalC);
                    resource_individual.addProperty(EducationalProperty, Educational_Individual);

                    // ***************************** Educational - interactivityType ***********************************
                    System.out.println("Analyzing Educational.InteractivityType");
                    NodeList interactivityTypeList = educationalE.getElementsByTagName(LOM_PREFIX
                            + ":interactivityType");
                    Node interactivityTypeNode = interactivityTypeList.item(0);
                    Element interactivityTypeE = (Element) interactivityTypeNode;
                    if (interactivityTypeList.getLength() != 0 && interactivityTypeList.item(0).hasChildNodes()) {
                        NodeList interactivityTypeValueList = interactivityTypeE.getElementsByTagName(LOM_PREFIX
                                + ":value");
                        if(interactivityTypeValueList.item(0).getChildNodes().item(0) != null){
                        	String interactivityTypeValue = interactivityTypeValueList.item(0).getChildNodes().item(0)
                                    .getNodeValue();
                            if (!interactivityTypeValue.isEmpty()) {
                                OntProperty hasInteractivityTypeProperty = lom_Model.getDatatypeProperty(NS
                                        + "educationalInteractivityType");
                                Educational_Individual.addProperty(hasInteractivityTypeProperty, interactivityTypeValue);
                            }
                        }                        
                    }

                    // ***************************** Educational - learningResourceType
                    // ***********************************
                    System.out.println("Analyzing Educational.LearningResourceType");
                    NodeList learningResourceTypeList = educationalE.getElementsByTagName(LOM_PREFIX
                            + ":learningResourceType");
                    for (int k = 0; k < learningResourceTypeList.getLength(); k++) {

                        Node learningResourceTypeNode = learningResourceTypeList.item(k);
                        Element learningResourceTypeE = (Element) learningResourceTypeNode;
                        NodeList learningResourceTypeValueList = learningResourceTypeE.getElementsByTagName(LOM_PREFIX
                                + ":value");

                        // Individual LearningResourceType_Individual=lom_Model.createIndividual( NS +
                        // "LearningResourceType-"+(educationalIndex+1)+"-"+(k+1), EducationalC );

                        // Educational_Individual.addProperty(L_Contribution_Entity,LearningResourceType_Individual);

                        if (learningResourceTypeValueList.getLength() != 0
                                && learningResourceTypeValueList.item(0).hasChildNodes()) {

                        	if(learningResourceTypeValueList.item(0).getChildNodes().item(0) != null){
                        		String learningResourceTypeValue = learningResourceTypeValueList.item(0).getChildNodes()
                                        .item(0).getNodeValue();
                                if (!learningResourceTypeValue.isEmpty()) {
                                    // OntProperty
                                    // hasLearningResourceTypeProperty=lom_Model.getDatatypeProperty(NS+"hasLearningResourceType");
                                    OntProperty hasLearningResourceTypeProperty = lom_Model
                                            .getAnnotationProperty(DCTerms.type.getURI());
                                    Educational_Individual.addProperty(hasLearningResourceTypeProperty,
                                            learningResourceTypeValue);
                                }
                        	}                            
                        }
                    }

                    // ***************************** Educational - interactivityLevel
                    // ***********************************
                    System.out.println("Analyzing Educational.InteractivityLevel");
                    NodeList interactivityLevelList = educationalE.getElementsByTagName(LOM_PREFIX
                            + ":interactivityLevel");
                    if (interactivityLevelList.getLength() != 0) {
                        Node interactivityLevelNode = interactivityLevelList.item(0);
                        Element interactivityLevelE = (Element) interactivityLevelNode;
                        NodeList interactivityLevelValueList = interactivityLevelE.getElementsByTagName(LOM_PREFIX
                                + ":value");
                        if (interactivityLevelValueList.getLength() != 0
                                && interactivityLevelValueList.item(0).hasChildNodes()) {

                        	if(interactivityLevelValueList.item(0).getChildNodes().item(0) != null){
                        		String interactivityLevelValue = interactivityLevelValueList.item(0).getChildNodes()
                                        .item(0).getNodeValue();
                                if (!interactivityLevelValue.isEmpty()) {
                                    OntProperty hasInteractivityLevelProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalInteractivityLevel");
                                    Educational_Individual.addProperty(hasInteractivityLevelProperty,
                                            interactivityLevelValue);
                                }
                        	}                            
                        }
                    }
                    // ***************************** Educational - SemanticDensity ***********************************
                    System.out.println("Analyzing Educational.SemanticDensity");
                    NodeList semanticDensityList = educationalE.getElementsByTagName(LOM_PREFIX + ":semanticDensity");
                    if (semanticDensityList.getLength() != 0) {
                        Node semanticDensityNode = semanticDensityList.item(0);
                        Element semanticDensityE = (Element) semanticDensityNode;
                        NodeList semanticDensityValueList = semanticDensityE
                                .getElementsByTagName(LOM_PREFIX + ":value");

                        if (semanticDensityValueList.getLength() != 0
                                && semanticDensityValueList.item(0).hasChildNodes()) {

                        	if(semanticDensityValueList.item(0).getChildNodes().item(0) != null){
                        		String semanticDensityValue = semanticDensityValueList.item(0).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!semanticDensityValue.isEmpty()) {
                                    OntProperty hasSemanticDensitylProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalSemanticDensity");
                                    Educational_Individual.addProperty(hasSemanticDensitylProperty, semanticDensityValue);
                                }
                        	}                            
                        }
                    }
                    // ***************************** Educational - intendedEndUserRole
                    // ***********************************
                    System.out.println("Analyzing Educational.IntendedEndUserRole");
                    NodeList intendedEndUserRoleList = educationalE.getElementsByTagName(LOM_PREFIX
                            + ":intendedEndUserRole");
                    for (int k = 0; k < intendedEndUserRoleList.getLength(); k++) {

                        Node intendedEndUserRoleNode = intendedEndUserRoleList.item(k);
                        Element intendedEndUserRoleE = (Element) intendedEndUserRoleNode;
                        NodeList intendedEndUserRoleValueList = intendedEndUserRoleE.getElementsByTagName(LOM_PREFIX
                                + ":value");

                        if (intendedEndUserRoleValueList.getLength() != 0
                                && intendedEndUserRoleValueList.item(0).hasChildNodes()) {

                        	if(intendedEndUserRoleValueList.item(0).getChildNodes().item(0) != null){
                        		String intendedEndUserRoleValue = intendedEndUserRoleValueList.item(0).getChildNodes()
                                        .item(0).getNodeValue();
                                if (!intendedEndUserRoleValue.isEmpty()) {
                                    OntProperty hasIntendedForUserRoleProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalIntendedUserRole");
                                    Educational_Individual.addProperty(hasIntendedForUserRoleProperty,
                                            intendedEndUserRoleValue);

                                }
                        	}                            
                        }
                    }

                    // ***************************** Educational - context ***********************************
                    System.out.println("Analyzing Educational.Context");
                    NodeList contextList = educationalE.getElementsByTagName(LOM_PREFIX + ":context");
                    for (int k = 0; k < contextList.getLength(); k++) {

                        Node contextNode = contextList.item(k);
                        Element contextE = (Element) contextNode;
                        NodeList contextValueList = contextE.getElementsByTagName(LOM_PREFIX + ":value");
                        if (contextValueList.getLength() != 0 && contextValueList.item(0).hasChildNodes()) {

                        	if(contextValueList.item(0).getChildNodes().item(0) != null){
                        		String contextValue = contextValueList.item(0).getChildNodes().item(0).getNodeValue();
                                if (!contextValue.isEmpty()) {
                                    OntProperty hasEducationalContextProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalContext");
                                    Educational_Individual.addProperty(hasEducationalContextProperty, contextValue);

                                }
                        	}
                        }
                    }
                    // ***************************** Educational - difficulty ***********************************
                    System.out.println("Analyzing Educational.Difficulty");
                    NodeList difficultyList = educationalE.getElementsByTagName(LOM_PREFIX + ":difficulty");
                    if (difficultyList.getLength() != 0) {

                        Node difficultyNode = difficultyList.item(0);
                        Element difficultyE = (Element) difficultyNode;
                        NodeList difficultyValueList = difficultyE.getElementsByTagName(LOM_PREFIX + ":value");

                        if (difficultyValueList.getLength() != 0 && difficultyValueList.item(0).hasChildNodes()) {

                        	if(difficultyValueList.item(0).getChildNodes().item(0) != null){
                        		String difficultyValue = difficultyValueList.item(0).getChildNodes().item(0).getNodeValue();
                                if (!difficultyValue.isEmpty()) {
                                    OntProperty hasDifficultyProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalDifficulty");
                                    Educational_Individual.addProperty(hasDifficultyProperty, difficultyValue);

                                }
                        	}                            
                        }
                    }
                    // ***************************** Typical Learning Time ***********************************
                    System.out.println("Analyzing Educational.Typical Learning Time");

                    NodeList typicalLearningTimeList = educationalE.getElementsByTagName(LOM_PREFIX
                            + ":typicalLearningTime");
                    Node typicalLearningTimeNode = typicalLearningTimeList.item(0);
                    Element typicalLearningTimeE = (Element) typicalLearningTimeNode;

                    if (typicalLearningTimeList.getLength() != 0 && typicalLearningTimeList.item(0).hasChildNodes()) {
                        NodeList typicalLearningTimeNodeList = typicalLearningTimeE.getElementsByTagName(LOM_PREFIX
                                + ":duration");
                        if(typicalLearningTimeNodeList.item(0).getChildNodes().item(0) != null){
                        	String typicalLearningTimeValue = typicalLearningTimeNodeList.item(0).getChildNodes().item(0)
                                    .getNodeValue();
                            // ******************* Educational_Typical Learning Time_INSTANCE ****************************
                            OntClass DurationE = lom_Model.getOntClass(NS + "Duration");
                            OntProperty DurationProperty = lom_Model.getObjectProperty(NS
                                    + "educationalTypicalLearningTime");
                            Individual Duration_Individual = lom_Model.createIndividual(NS + "TypicalLearningTime_"
                                    + metadataURI + "_" + (educationalIndex + 1), DurationE);
                            Educational_Individual.addProperty(DurationProperty, Duration_Individual);
                            if (!typicalLearningTimeValue.isEmpty()) {
                                OntProperty hasTypicalLearningTimeProperty = lom_Model.getDatatypeProperty(NS
                                        + "durationValue");
                                Duration_Individual.addProperty(hasTypicalLearningTimeProperty, typicalLearningTimeValue);

                            }
                            NodeList typicalLearningTimeDescriptionNodeList = typicalLearningTimeE
                                    .getElementsByTagName(LOM_PREFIX + ":string");
                            if (typicalLearningTimeDescriptionNodeList.getLength() != 0) {
                            	if(typicalLearningTimeDescriptionNodeList.item(0).getChildNodes().item(0) != null){
                            		String typicalLearningTimeDescriptionValue = typicalLearningTimeDescriptionNodeList.item(0)
                                            .getChildNodes().item(0).getNodeValue();
                                    if (!typicalLearningTimeDescriptionValue.isEmpty()) {
                                        OntProperty hasTypicalLearningTimeDescriptionProperty = lom_Model
                                                .getDatatypeProperty(NS + "durationDescription");
                                        if (typicalLearningTimeDescriptionNodeList.item(0).hasAttributes())
                                            Duration_Individual.addProperty(hasTypicalLearningTimeDescriptionProperty,
                                                    typicalLearningTimeDescriptionValue, typicalLearningTimeDescriptionNodeList
                                                            .item(0).getAttributes().item(0).getNodeValue());
                                        else
                                            Duration_Individual.addProperty(hasTypicalLearningTimeDescriptionProperty,
                                                    typicalLearningTimeDescriptionValue);

                                    }
                            	}                                
                            }
                        }                        
                    }

                    // ***************************** educational Language **********************************
                    System.out.println("Analyzing Educational.Language");
                    NodeList educationalLanguage = educationalE.getElementsByTagName(LOM_PREFIX + ":language");

                    for (int i = 0; i < educationalLanguage.getLength(); i++) {

                        if (educationalLanguage.getLength() != 0 && educationalLanguage.item(0).hasChildNodes()) {

                        	if(educationalLanguage.item(i).getChildNodes().item(0) != null){
                        		String ELanguage = educationalLanguage.item(i).getChildNodes().item(0).getNodeValue();
                                if (!ELanguage.isEmpty()) {
                                    OntProperty hasLanguageProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalLanguage");
                                    Educational_Individual.addProperty(hasLanguageProperty, ELanguage);
                                }
                        	}                            
                        }
                    }
                    // ***************************** Description **********************************
                    System.out.println("Analyzing Educational.Description");
                    NodeList educationalDescriptionList = educationalE
                            .getElementsByTagName(LOM_PREFIX + ":description");
                    for (int i = 0; i < educationalDescriptionList.getLength(); i++) {
                        if (educationalDescriptionList.item(i).getParentNode().getNodeName()
                                .equals(LOM_PREFIX + ":educational")) {
                            Node descNode = educationalDescriptionList.item(i);
                            Element e1 = (Element) descNode;

                            // ******************* Educational_DESCRIPTION_INSTANCE ****************************
                            OntClass DescriptionE = lom_Model.getOntClass(NS + "LangString");
                            OntProperty E_Description = lom_Model.getObjectProperty(NS + "description");
                            Individual Educational_Description = lom_Model.createIndividual(NS
                                    + "educational_description_" + metadataURI + "_" + (educationalIndex + 1) + "_"
                                    + (i + 1), DescriptionE);
                            Educational_Individual.addProperty(E_Description, Educational_Description);

                            // ***************************** string ***********************************
                            NodeList descNodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");

                            if (descNodeList.getLength() != 0 && descNodeList.item(0).hasChildNodes()) {

                                for (int j = 0; j < descNodeList.getLength(); j++) {
                                	if(descNodeList.item(j).getChildNodes().item(0) != null){
                                		String descriptionValue = descNodeList.item(j).getChildNodes().item(0)
                                                .getNodeValue();
                                        if (!descriptionValue.isEmpty()) {
                                            // OntProperty description =lom_Model.getDatatypeProperty(NS + "hasValue" );
                                            OntProperty description = lom_Model.getAnnotationProperty(DCTerms.description
                                                    .getURI());
                                            if (descNodeList.item(j).hasAttributes())
                                                Educational_Description.addProperty(description, descriptionValue,
                                                        descNodeList.item(j).getAttributes().item(0).getNodeValue());
                                            else
                                                Educational_Description.addProperty(description, descriptionValue);

                                        }
                                	}                                    
                                }
                            }
                        }
                    }

                    // ***************************** educational -Typical age range **********************************
                    System.out.println("Analyzing Educational.Typical age range");
                    NodeList educationalTypicalAgeRangeList = educationalE.getElementsByTagName(LOM_PREFIX
                            + ":typicalAgeRange");
                    for (int i = 0; i < educationalTypicalAgeRangeList.getLength(); i++) {
                        Node descNode = educationalTypicalAgeRangeList.item(i);
                        Element e1 = (Element) descNode;

                        // ******************* Educational_AgeRange_INSTANCE ****************************
                        OntClass TypicalAgeRangeE = lom_Model.getOntClass(NS + "LangString");
                        OntProperty TypicalAgeRangeProperty = lom_Model.getObjectProperty(NS
                                + "educationalTypicalAgeRange");
                        Individual TypicalAgeRange_Individual = lom_Model.createIndividual(NS + "TypicalAgeRange_"
                                + metadataURI + "_" + (i + 1), TypicalAgeRangeE);

                        Educational_Individual.addProperty(TypicalAgeRangeProperty, TypicalAgeRange_Individual);

                        // ***************************** string ***********************************
                        NodeList descNodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                        if (descNodeList.getLength() != 0 && descNodeList.item(0).hasChildNodes()) {

                            for (int j = 0; j < descNodeList.getLength(); j++) {
                            	if(descNodeList.item(j).getChildNodes().item(0) != null){
                            		String typicalAgeRangeValue = descNodeList.item(j).getChildNodes().item(0)
                                            .getNodeValue();
                                    if (!typicalAgeRangeValue.isEmpty()) {
                                        OntProperty typicalAgeRangeProperty = lom_Model.getAnnotationProperty(RDF.value
                                                .getURI());
                                        if (descNodeList.item(j).hasAttributes())
                                            TypicalAgeRange_Individual.addProperty(typicalAgeRangeProperty,
                                                    typicalAgeRangeValue, descNodeList.item(j).getAttributes().item(0)
                                                            .getNodeValue());
                                        else
                                            TypicalAgeRange_Individual.addProperty(typicalAgeRangeProperty,
                                                    typicalAgeRangeValue);

                                    }
                            	}                                
                            }
                        }
                    }
                    // ***************************** Educational - cognitiveProcess***********************************
                    System.out.println("Analyzing Educational.cognitiveProcess");
                    NodeList cognitiveProcessList = educationalE.getElementsByTagName(LOM_PREFIX + ":cognitiveProcess");
                    for (int k = 0; k < cognitiveProcessList.getLength(); k++) {

                        Node cognitiveProcessNode = cognitiveProcessList.item(k);
                        Element cognitiveProcessE = (Element) cognitiveProcessNode;
                        NodeList cognitiveProcessValueList = cognitiveProcessE.getElementsByTagName(LOM_PREFIX
                                + ":value");

                        if (cognitiveProcessValueList.getLength() != 0
                                && cognitiveProcessValueList.item(0).hasChildNodes()) {

                        	if(cognitiveProcessValueList.item(0).getChildNodes().item(0) != null){
                        		String cognitiveProcessValue = cognitiveProcessValueList.item(0).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!cognitiveProcessValue.isEmpty()) {

                                    OntProperty hasCognitiveProcessProperty = lom_Model.getDatatypeProperty(NS
                                            + "educationalCognitiveProcess");
                                    Educational_Individual.addProperty(hasCognitiveProcessProperty, cognitiveProcessValue);
                                }
                        	}                            
                        }
                    }
                }
            }

        }// Educational

    }

}
