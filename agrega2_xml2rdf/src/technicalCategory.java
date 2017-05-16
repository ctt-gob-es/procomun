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
 * Time: 2:58 PM
 * To change this template use File | Settings | File Templates.
 */
public class technicalCategory {
    //
    // ***************** Technical Category *******************************************************
    public void parse_Technical_Category(NodeList TechnicalList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {
        if (TechnicalList != null && TechnicalList.getLength() > 0) {
            Node node = TechnicalList.item(0);

            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element e = (Element) node;

                // ***************************** Technical Format **********************************
                System.out.println("Analyzing Technical.Format");
                NodeList technicalFormatList = e.getElementsByTagName(LOM_PREFIX + ":format");
                for (int i = 0; i < technicalFormatList.getLength(); i++) {
                    if (technicalFormatList.item(0).hasChildNodes()) {

                    	if(technicalFormatList.item(i).getChildNodes().item(0) != null){
                    		String formatValue = technicalFormatList.item(i).getChildNodes().item(0).getNodeValue();
                            if (!formatValue.isEmpty()) {
                                // OntProperty
                                // technicalFormatProperty=lom_Model.getDatatypeProperty(NS+"hasTechnicalFormat");
                                OntProperty technicalFormatProperty = lom_Model.getAnnotationProperty(DCTerms.format
                                        .toString());
                                resource_individual.addProperty(technicalFormatProperty, formatValue);
                            }
                    	}                        
                    }
                }
                // ***************************** Technical Size ***********************************
                System.out.println("Analyzing Technical.Size");
                NodeList technicalSize = e.getElementsByTagName(LOM_PREFIX + ":size");
                if (technicalSize.getLength() != 0 && technicalSize.item(0).hasChildNodes()) {

                	if(technicalSize.item(0).getChildNodes().item(0) != null){
                		String sizeValue = technicalSize.item(0).getChildNodes().item(0).getNodeValue();
                        if (!sizeValue.isEmpty()) {
                            // OntProperty technicalSizeProperty=lom_Model.getDatatypeProperty(NS+"hasTechnicalSize");
                            OntProperty technicalSizeProperty = lom_Model.getDatatypeProperty(NS + "technicalSize");
                            resource_individual.addProperty(technicalSizeProperty, sizeValue);
                        }
                	}                    
                }

                // ***************************** Technical Location **********************************
                System.out.println("Analyzing Technical.Location");
                NodeList technicalLocationList = e.getElementsByTagName(LOM_PREFIX + ":location");
                for (int i = 0; i < technicalLocationList.getLength(); i++) {
                    if (technicalLocationList.getLength() != 0 && technicalLocationList.item(0).hasChildNodes()) {

                    	if(technicalLocationList.item(i).getChildNodes().item(0) != null){
                    		String locationValue = technicalLocationList.item(i).getChildNodes().item(0).getNodeValue();
                            if (!locationValue.isEmpty()) {
                                OntProperty technicalLocationProperty = lom_Model.getDatatypeProperty(NS
                                        + "technicalLocation");
                                resource_individual.addProperty(technicalLocationProperty, locationValue);
                            }	
                    	}                        
                    }
                }

                // ***************************** Technical Installation Remark ***********************************
                System.out.println("Analyzing Technical.InstallationRemarks");
                NodeList installationList = e.getElementsByTagName(LOM_PREFIX + ":installationRemarks");
                Node installationNode = installationList.item(0);
                Element e1 = (Element) installationNode;

                if (installationList.getLength() != 0 && installationList.item(0).hasChildNodes()) {
                    // ***************************** string ***********************************
                    NodeList nodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                    for (int j = 0; j < nodeList.getLength(); j++) {                    	
                    	if(nodeList.item(j).getChildNodes().item(0) != null){
                    		String installValue = nodeList.item(j).getChildNodes().item(0).getNodeValue();
                            if (!installValue.isEmpty()) {
                                OntProperty installationRemarkProperty = lom_Model.getDatatypeProperty(NS
                                        + "technicalInstallationRemarks");
                                if (nodeList.item(j).hasAttributes())
                                    resource_individual.addProperty(installationRemarkProperty, installValue, nodeList
                                            .item(j).getAttributes().item(0).getNodeValue());
                                else
                                    resource_individual.addProperty(installationRemarkProperty, installValue);
                            }
                    	}
                    }
                }

                // ***************************** Technical otherPlatformRequirements ***********************************
                System.out.println("Analyzing Technical.otherPlatformRequirements");
                NodeList otherPlatformRequirementsList = e.getElementsByTagName(LOM_PREFIX
                        + ":otherPlatformRequirements");

                if (otherPlatformRequirementsList.getLength() != 0) {
                    Node otherPlatformRequirementsNode = otherPlatformRequirementsList.item(0);
                    Element e2 = (Element) otherPlatformRequirementsNode;
                    if (otherPlatformRequirementsList.getLength() != 0
                            && otherPlatformRequirementsList.item(0).hasChildNodes()) {

                        // ***************************** string ***********************************
                        NodeList otherPlatformNodeList = e2.getElementsByTagName(LOM_PREFIX + ":string");
                        for (int j = 0; j < otherPlatformNodeList.getLength(); j++) {
                            if (otherPlatformNodeList.item(0).hasChildNodes()
                                    && otherPlatformNodeList.item(0).getChildNodes().item(0) != null 
                                    && otherPlatformNodeList.item(0).getChildNodes().item(0).getNodeValue() != null) {
                                String otherPlatformRequirementsValue = otherPlatformNodeList.item(j).getChildNodes()
                                        .item(0).getNodeValue();

                                if (!otherPlatformRequirementsValue.isEmpty()) {
                                    OntProperty otherPlatformRequirementProperty = lom_Model.getDatatypeProperty(NS
                                            + "otherPlatformRequirements");
                                    if (otherPlatformNodeList.item(j).hasAttributes())
                                        resource_individual.addProperty(otherPlatformRequirementProperty,
                                                otherPlatformRequirementsValue, otherPlatformNodeList.item(j)
                                                        .getAttributes().item(0).getNodeValue());
                                    else
                                        resource_individual.addProperty(otherPlatformRequirementProperty,
                                                otherPlatformRequirementsValue);
                                }
                            }
                        }

                    }
                }
                // ***************************** Technical duration ***********************************
                System.out.println("Analyzing Technical.Duration");

                NodeList technicalDurationList = e.getElementsByTagName(LOM_PREFIX + ":duration");
                Node technicalDurationNode = technicalDurationList.item(0);
                Element technicalDurationE = (Element) technicalDurationNode;

                // ******************* Educational_Typical Learning Time_INSTANCE ****************************
                OntClass DurationE = lom_Model.getOntClass(NS + "Duration");
                OntProperty DurationProperty = lom_Model.getObjectProperty(NS + "technicalDuration");
                Individual Duration_Individual = lom_Model.createIndividual(NS + "TechnicalDuration_" + metadataURI,
                        DurationE);
                resource_individual.addProperty(DurationProperty, Duration_Individual);

                if (technicalDurationList.getLength() != 0 && technicalDurationList.item(0).hasChildNodes()) {
                    NodeList technicalDurationNodeList = technicalDurationE.getElementsByTagName(LOM_PREFIX
                            + ":duration");
                    if(technicalDurationNodeList.item(0).getChildNodes().item(0) != null){
                    	String technicalDurationValue = technicalDurationNodeList.item(0).getChildNodes().item(0)
                                .getNodeValue();
                        if (!technicalDurationValue.isEmpty()) {
                            OntProperty hasTechnicalDurationProperty = lom_Model.getDatatypeProperty(NS + "durationValue");
                            Duration_Individual.addProperty(hasTechnicalDurationProperty, technicalDurationValue);

                        }
                    }                    

                    NodeList technicalDurationDescriptionNodeList = technicalDurationE.getElementsByTagName(LOM_PREFIX
                            + ":string");
                    if (technicalDurationDescriptionNodeList.getLength() != 0) {
                    	if(technicalDurationDescriptionNodeList.item(0).getChildNodes().item(0) != null){
                    		String technicalDurationDescriptionValue = technicalDurationDescriptionNodeList.item(0)
                                    .getChildNodes().item(0).getNodeValue();
                            if (!technicalDurationDescriptionValue.isEmpty()) {
                                OntProperty hasTechnicalDurationDescriptionProperty = lom_Model.getDatatypeProperty(NS
                                        + "durationDescription");
                                if (technicalDurationDescriptionNodeList.item(0).hasAttributes())
                                    Duration_Individual.addProperty(hasTechnicalDurationDescriptionProperty,
                                            technicalDurationDescriptionValue, technicalDurationDescriptionNodeList.item(0)
                                                    .getAttributes().item(0).getNodeValue());
                                else
                                    Duration_Individual.addProperty(hasTechnicalDurationDescriptionProperty,
                                            technicalDurationDescriptionValue);

                            }
                    	}                        
                    }
                }

                // ***************************** Requirement **********************************
                System.out.println("Analyzing Technical.Requirement");
                NodeList RequirementList = e.getElementsByTagName(LOM_PREFIX + ":requirement");
                if (RequirementList.getLength() != 0) {
                    for (int i = 0; i < RequirementList.getLength(); i++) {
                        Node RequirementNode = RequirementList.item(i);
                        Element RequirementE = (Element) RequirementNode;

                        // **********************
                        OntClass TechnicalRequirement = lom_Model.getOntClass(NS + "TechnicalRequirement");
                        OntProperty TechnicalRequirementProperty = lom_Model.getObjectProperty(NS
                                + "technicalRequirements");

                        Individual TechnicalRequirementPropertyIndividual = lom_Model.createIndividual(NS
                                + "TechnicalRequirement_" + metadataURI + "_" + (i + 1), TechnicalRequirement);

                        resource_individual.addProperty(TechnicalRequirementProperty,
                                TechnicalRequirementPropertyIndividual);

                        // ***************************** OrComposite ***********************************
                        NodeList OrCompositeNodeList = RequirementE.getElementsByTagName(LOM_PREFIX + ":orComposite");
                        System.out.println("Analyzing Technical.orComposite");

                        if (OrCompositeNodeList.getLength() != 0) {

                            for (int k = 0; k < OrCompositeNodeList.getLength(); k++) {
                                // isCompositeOf
                                OntClass SingleTechnicalRequirement = lom_Model.getOntClass(NS
                                        + "SingleTechnicalRequirement");
                                OntProperty isCompositeOfProperty = lom_Model.getObjectProperty(NS + "isCompositeOf");

                                Individual isCompositeOfIndividual = lom_Model.createIndividual(NS
                                        + "SingleTechnicalRequirement_" + metadataURI + "_" + (i + 1) + "_" + (k + 1),
                                        SingleTechnicalRequirement);

                                TechnicalRequirementPropertyIndividual.addProperty(isCompositeOfProperty,
                                        isCompositeOfIndividual);

                                Node orCompositeNode = RequirementList.item(i);
                                Element orCompositeE = (Element) orCompositeNode;

                                // ***************************** OrComposite - Name ***********************************
                                NodeList orCompositeNameList = orCompositeE.getElementsByTagName(LOM_PREFIX + ":name");
                                System.out.println("Analyzing Technical.orComposite.name");

                                if (orCompositeNameList.getLength() != 0) {

                                    Node orCompositeNameNode = orCompositeNameList.item(k);
                                    Element orCompositeNameE = (Element) orCompositeNameNode;
                                    if (orCompositeNameList.getLength() != 0
                                            && orCompositeNameList.item(0).hasChildNodes()) {
                                        NodeList orCompositeNameValueList = orCompositeNameE
                                                .getElementsByTagName(LOM_PREFIX + ":value");
                                        if(orCompositeNameValueList.item(0).getChildNodes().item(0) != null){
                                        	String orCompositeNameValue = orCompositeNameValueList.item(0).getChildNodes()
                                                    .item(0).getNodeValue();
                                            if (!orCompositeNameValue.isEmpty()) {
                                                OntProperty compositeNameProperty = lom_Model.getDatatypeProperty(NS
                                                        + "orCompositeName");
                                                isCompositeOfIndividual.addProperty(compositeNameProperty,
                                                        orCompositeNameValue);
                                            }
                                        }                                        
                                    }
                                }
                                // ***************************** OrComposite - Type ***********************************
                                NodeList orCompositeTypeList = orCompositeE.getElementsByTagName(LOM_PREFIX + ":type");
                                System.out.println("Analyzing Technical.orComposite.type");

                                if (orCompositeTypeList.getLength() != 0) {

                                    Node orCompositeTypeNode = orCompositeTypeList.item(k);
                                    Element orCompositeTypeE = (Element) orCompositeTypeNode;
                                    NodeList orCompositeTypeValueList = orCompositeTypeE
                                            .getElementsByTagName(LOM_PREFIX + ":value");

                                    if (orCompositeTypeValueList.getLength() != 0
                                            && orCompositeTypeValueList.item(0).hasChildNodes()) {

                                    	if(orCompositeTypeValueList.item(0).getChildNodes().item(0) != null){
                                    		String orCompositeTypeValue = orCompositeTypeValueList.item(0).getChildNodes()
                                                    .item(0).getNodeValue();
                                            if (!orCompositeTypeValue.isEmpty()) {
                                                OntProperty compositeTypeProperty = lom_Model.getDatatypeProperty(NS
                                                        + "orCompositeType");
                                                isCompositeOfIndividual.addProperty(compositeTypeProperty,
                                                        orCompositeTypeValue);
                                            }
                                    	}                                        
                                    }
                                }
                                // ***************************** OrComposite - minimumVersion
                                // ***********************************
                                NodeList orCompositeMinimumVersionList = orCompositeE.getElementsByTagName(LOM_PREFIX
                                        + ":minimumVersion");
                                System.out.println("Analyzing Technical.orComposite.minimumVersion");

                                if (orCompositeMinimumVersionList.getLength() != 0)
                                    if (orCompositeMinimumVersionList.item(0).hasChildNodes()) {

                                    	if( orCompositeMinimumVersionList.item(0).getChildNodes().item(0) != null){
                                    		String orCompositeMinimumVersionValue = orCompositeMinimumVersionList.item(0)
                                                    .getChildNodes().item(0).getNodeValue();
                                            if (!orCompositeMinimumVersionValue.isEmpty()) {

                                                OntProperty compositeMinimumVersionProperty = lom_Model
                                                        .getDatatypeProperty(NS + "orCompositeMinimumVersion");
                                                isCompositeOfIndividual.addProperty(compositeMinimumVersionProperty,
                                                        orCompositeMinimumVersionValue);
                                            }
                                    	}                                        
                                    }
                                // ***************************** OrComposite - maximumVersion
                                // ***********************************
                                NodeList orCompositeMaximumVersionList = orCompositeE.getElementsByTagName(LOM_PREFIX
                                        + ":maximumVersion");
                                System.out.println("Analyzing Technical.orComposite.maximumVersion");

                                if (orCompositeMaximumVersionList.getLength() != 0
                                        && orCompositeMaximumVersionList.item(0).hasChildNodes()) {

                                	if(orCompositeMaximumVersionList.item(0).getChildNodes().item(0) != null){
                                		String orCompositeMaximumVersionValue = orCompositeMaximumVersionList.item(0)
                                                .getChildNodes().item(0).getNodeValue();
                                        if (!orCompositeMaximumVersionValue.isEmpty()) {
                                            OntProperty compositeMaximumVersionProperty = lom_Model.getDatatypeProperty(NS
                                                    + "orCompositeMaximumVersion");
                                            isCompositeOfIndividual.addProperty(compositeMaximumVersionProperty,
                                                    orCompositeMaximumVersionValue);
                                        }
                                	}                                    
                                }
                            }
                        }
                    }
                }
            }
        }// Technical

    }
}
