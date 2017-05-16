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
 * Time: 2:53 PM
 * To change this template use File | Settings | File Templates.
 */
public class lifecycleCategory {
    public void parse_Lifecycle_Category(NodeList lifeCycleList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {
        if (lifeCycleList != null && lifeCycleList.getLength() > 0) {
            for (int i = 0; i < lifeCycleList.getLength(); i++) {

                Node node = lifeCycleList.item(i);

                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element lifeCycleE = (Element) node;

                    // ***************************** LifeCycle:version ***********************************
                    System.out.println("Analyzing LifeCycle.Version");
                    NodeList lifeCycleVersion = lifeCycleE.getElementsByTagName(LOM_PREFIX + ":version");
                    for (i = 0; i < lifeCycleVersion.getLength(); i++) {
                        Node versionNode = lifeCycleVersion.item(i);
                        Element e1 = (Element) versionNode;
                        // ***************************** string ***********************************
                        NodeList nodeList = e1.getElementsByTagName(LOM_PREFIX + ":string");
                        if (nodeList.getLength() != 0 && nodeList.item(0).hasChildNodes()) {

                            for (int j = 0; j < nodeList.getLength(); j++) {
                            	if(nodeList.item(j).getChildNodes().item(0) != null){
                            		String versionValue = nodeList.item(j).getChildNodes().item(0).getNodeValue();
                                    if (!versionValue.isEmpty()) {
                                        OntProperty lifeCycleVersionProperty = lom_Model.getDatatypeProperty(NS
                                                + "lifeCycleVersion");
                                        if (nodeList.item(j).hasAttributes())
                                            resource_individual.addProperty(lifeCycleVersionProperty, versionValue,
                                                    nodeList.item(j).getAttributes().item(0).getNodeValue());
                                        else
                                            resource_individual.addProperty(lifeCycleVersionProperty, versionValue);
                                    }
                            	}                                
                            }
                        }
                    }

                    // ***************************** Life Cycle Status **********************************
                    System.out.println("Analyzing LifeCycle.Status");
                    NodeList lifeCycleStatus = lifeCycleE.getElementsByTagName(LOM_PREFIX + ":status");
                    Node statusNode = lifeCycleStatus.item(0);
                    Element generalAgg = (Element) statusNode;

                    // ***************************** value ***********************************
                    if (lifeCycleStatus.getLength() != 0 && lifeCycleStatus.item(0).hasChildNodes()) {

                        NodeList statusList = generalAgg.getElementsByTagName(LOM_PREFIX + ":value");
                        if(statusList.item(0).getChildNodes().item(0) != null){
                        	String status = statusList.item(0).getChildNodes().item(0).getNodeValue();
                            if (!status.isEmpty()) {
                                OntProperty lifeCycleStatusProperty = lom_Model.getDatatypeProperty(NS + "lifeCycleStatus");
                                resource_individual.addProperty(lifeCycleStatusProperty, status);
                            }
                        }
                    }

                    // ***************************** Life Cycle Contribute **********************************
                    System.out.println("Analyzing LifeCycle.Contribute");
                    NodeList GeneralIdentifierList = lifeCycleE.getElementsByTagName(LOM_PREFIX + ":contribute");

                    for (i = 0; i < GeneralIdentifierList.getLength(); i++) {
                        Node contributeNode = GeneralIdentifierList.item(i);
                        Element contributeE = (Element) contributeNode;

                        // ******************* LIFECYCLE_CONTRIBUTE_INSTANCE ****************************
                        OntClass Contribute = lom_Model.getOntClass(NS + "LifeCycleContribution");
                        OntProperty L_Contribution = lom_Model.getObjectProperty(NS + "lifeCycleContribution");
                        Individual LifeCycle_Contribution = lom_Model.createIndividual(NS + "LifeCycle_contribution_"
                                + metadataURI + "_" + (i + 1), Contribute);
                        resource_individual.addProperty(L_Contribution, LifeCycle_Contribution);

                        // ***************************** role -value ***********************************
                        NodeList contributeNodeList = contributeE.getElementsByTagName(LOM_PREFIX + ":value");
                        System.out.println("Analyzing LifeCycle.Contribute.Role");
                        if (contributeNodeList.getLength() != 0 && contributeNodeList.item(0).hasChildNodes()) {
                        	if(contributeNodeList.item(0).getChildNodes().item(0) != null){
                        		String roleValue = contributeNodeList.item(0).getChildNodes().item(0).getNodeValue();
                                if (!roleValue.isEmpty()) {
                                    OntProperty hasContributionRoleProperty = lom_Model.getDatatypeProperty(NS
                                            + "lifeCycleContributionRole");
                                    LifeCycle_Contribution.addProperty(hasContributionRoleProperty, roleValue);
                                }
                        	}                            
                        }
                        // ***************************** Entity -vcard ***********************************
                        NodeList contributeEntityNodeList = contributeE.getElementsByTagName(LOM_PREFIX + ":entity");
                        System.out.println("Analyzing LifeCycle.Contribute.Entity");
                        for (int k = 0; k < contributeEntityNodeList.getLength(); k++) {

                            // ******************* LIFECYCLE_CONTRIBUTE_ROLE_INSTANCE ****************************
                            OntClass VCARD_Class = lom_Model.getOntClass(NS + "vCARD");
                            OntProperty L_Contribution_Entity = lom_Model.getObjectProperty(NS + "contributionEntity");

                            Individual LifeCycle_Contribution_Entity = lom_Model.createIndividual(NS
                                    + "lifeCycle_contribution_Entity_" + metadataURI + "_" + (i + 1) + "_" + (k + 1),
                                    VCARD_Class);
                            LifeCycle_Contribution.addProperty(L_Contribution_Entity, LifeCycle_Contribution_Entity);

                            if (contributeEntityNodeList.getLength() != 0
                                    && contributeEntityNodeList.item(0).hasChildNodes()) {
                            	if(contributeEntityNodeList.item(k).getChildNodes().item(0) != null){
                            		String ContributeEntityValue = contributeEntityNodeList.item(k).getChildNodes().item(0)
                                            .getNodeValue();

                                    if (!ContributeEntityValue.isEmpty()) {
                                        vCardParser vCardParser = new vCardParser();

                                        if (!vCardParser.name(ContributeEntityValue).trim().isEmpty())
                                            LifeCycle_Contribution_Entity.addProperty(VCARD.N,
                                                    vCardParser.name(ContributeEntityValue).trim());

                                        if (!vCardParser.fullName(ContributeEntityValue).trim().isEmpty())
                                            LifeCycle_Contribution_Entity.addProperty(VCARD.FN,
                                                    vCardParser.fullName(ContributeEntityValue).trim());

                                        if (!vCardParser.email(ContributeEntityValue).trim().isEmpty())
                                            LifeCycle_Contribution_Entity.addProperty(VCARD.EMAIL,
                                                    vCardParser.email(ContributeEntityValue).trim());

                                        if (!vCardParser.organization(ContributeEntityValue).trim().isEmpty())
                                            LifeCycle_Contribution_Entity.addProperty(VCARD.ORG,
                                                    vCardParser.organization(ContributeEntityValue).trim());
                                    }
                            	}                                
                            }
                        }
                        // ***************************** Entity -Date ***********************************
                        NodeList contributionDateNodeList = contributeE.getElementsByTagName(LOM_PREFIX + ":dateTime");
                        System.out.println("Analyzing LifeCycle.Contribute.DateTime");
                        if (contributionDateNodeList.getLength() != 0
                                && contributionDateNodeList.item(0).hasChildNodes()) {
                        	if(contributionDateNodeList.item(0).getChildNodes().item(0) != null){
                        		String contributionDate = contributionDateNodeList.item(0).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!contributionDate.isEmpty()) {
                                    OntProperty ContributionDateProperty = lom_Model.getDatatypeProperty(NS
                                            + "dateTimeValue");
                                    LifeCycle_Contribution.addProperty(ContributionDateProperty, contributionDate);
                                }
                        	}                            
                        }
                        // ***************************** Entity -Description ***********************************
                        NodeList contributionDateDescriptionNodeList = contributeE.getElementsByTagName(LOM_PREFIX
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
                                        LifeCycle_Contribution.addProperty(ContributionDateDescriptionProperty,
                                                contributionDateDescription, contributionDateDescriptionNodeList.item(0)
                                                        .getAttributes().item(0).getNodeValue());
                                    else
                                        LifeCycle_Contribution.addProperty(ContributionDateDescriptionProperty,
                                                contributionDateDescription);
                                }
                        	}                            
                        }
                    }
                } // LIFE CYCLE
            }
        }
    }
}
