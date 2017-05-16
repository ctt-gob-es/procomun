import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import com.hp.hpl.jena.ontology.Individual;
import com.hp.hpl.jena.ontology.OntClass;
import com.hp.hpl.jena.ontology.OntModel;
import com.hp.hpl.jena.ontology.OntProperty;
import com.hp.hpl.jena.vocabulary.DCTerms;
import com.hp.hpl.jena.vocabulary.VCARD;

/**
 * Created with IntelliJ IDEA.
 * User: Enayat
 * Date: 4/7/14
 * Time: 2:55 PM
 * To change this template use File | Settings | File Templates.
 */
public class metaMetadataCategory {
    //
    // ***************** metaMetadata Category *******************************************************
    Boolean hasData;

    public void parse_metaMetadata_Category(NodeList metaMetadataList, String NS, Individual resource_individual,
            OntModel lom_Model, String metadataURI, String LOM_PREFIX) {
        if (metaMetadataList != null && metaMetadataList.getLength() > 0) {
            Node node = metaMetadataList.item(0);

            if (node.getNodeType() == Node.ELEMENT_NODE) {
                Element e = (Element) node;

                // ***************************** metaMetadata:Identifier ***********************************
                System.out.println("Analyzing metaMetadata.Identifier");
                NodeList metaMetadataIdentifierList = e.getElementsByTagName(LOM_PREFIX + ":identifier");

                for (int i = 0; i < metaMetadataIdentifierList.getLength(); i++) {
                    Node mNode = metaMetadataIdentifierList.item(i);
                    Element metaMetadataE = (Element) mNode;

                    // ******************* METADATA_IDENTIFIER_INSTANCE ****************************
                    OntClass Identifier = lom_Model.getOntClass(NS + "Identifier");
                    OntProperty M_Identifier = lom_Model.getObjectProperty(NS + "metaMetadataIdentifier");
                    Individual Metadata_Identifier = lom_Model.createIndividual(NS + "metadata_identifier_"
                            + metadataURI + "_" + (i + 1), Identifier);
                    resource_individual.addProperty(M_Identifier, Metadata_Identifier);

                    hasData = false;
                    // ***************************** metaMetadata catalog ************************************
                    System.out.println("Analyzing metaMetadata.Identifier.Catalog");
                    NodeList metaMetadataENodeList = metaMetadataE.getElementsByTagName(LOM_PREFIX + ":catalog");

                    if (metaMetadataENodeList.getLength() != 0 && metaMetadataENodeList.item(0).hasChildNodes()) {
                    	if(metaMetadataENodeList.item(0).getChildNodes().item(0) != null){
                    		String metaMetadataCatalog = metaMetadataENodeList.item(0).getChildNodes().item(0)
                                    .getNodeValue();
                            if (!metaMetadataCatalog.isEmpty()) {
                                hasData = true;
                                OntProperty hasCatalog = lom_Model.getDatatypeProperty(NS + "identifierCatalog");
                                Metadata_Identifier.addProperty(hasCatalog, metaMetadataCatalog);
                            }
                    	}                        
                    }
                    // ***************************** metaMetadata Entry **************************************
                    System.out.println("Analyzing metaMetadata.Identifier.Entry");
                    NodeList MEntryNodeList = metaMetadataE.getElementsByTagName(LOM_PREFIX + ":entry");

                    if (MEntryNodeList.getLength() != 0 && MEntryNodeList.item(0).hasChildNodes()) {
                    	if(MEntryNodeList.item(0).getChildNodes().item(0) != null){
                    		String metaMetadataEntry = MEntryNodeList.item(0).getChildNodes().item(0).getNodeValue();
                            if (!metaMetadataEntry.isEmpty()) {
                                hasData = true;
                                // OntProperty hasEntry=lom_Model.getDatatypeProperty(NS+"hasEntry");
                                OntProperty hasEntry = lom_Model.getAnnotationProperty(DCTerms.identifier.getURI());
                                Metadata_Identifier.addProperty(hasEntry, metaMetadataEntry);
                            }
                    	}                        
                    }
                    // if(hasData)
                    // model.createResource(metadataURI)
                    // .addProperty(metaMetadataIdentifierPrefix, metaMetadataIdentifier);
                }

                // ***************************** metaMetadata Contribute **********************************
                System.out.println("Analyzing metaMetadata.Contribute");
                NodeList metaMetadataContributeList = e.getElementsByTagName(LOM_PREFIX + ":contribute");

                for (int i = 0; i < metaMetadataContributeList.getLength(); i++) {
                    Node contributeNode = metaMetadataContributeList.item(i);
                    Element contributeE = (Element) contributeNode;

                    // ******************* LIFECYCLE_CONTRIBUTE_INSTANCE ****************************
                    OntClass Contribute = lom_Model.getOntClass(NS + "MetaMetadataContribution");
                    OntProperty M_Contribution = lom_Model.getObjectProperty(NS + "metaMetadataContribution");
                    Individual Metadata_Contribution = lom_Model.createIndividual(NS + "metaMetadata_contribution_"
                            + metadataURI + "_" + (i + 1), Contribute);
                    resource_individual.addProperty(M_Contribution, Metadata_Contribution);

                    // ***************************** role -value ***********************************
                    NodeList contributeNodeList = contributeE.getElementsByTagName(LOM_PREFIX + ":value");
                    if (contributeNodeList.getLength() != 0 && contributeNodeList.item(0).hasChildNodes()) {
                    	if(contributeNodeList.item(0).getChildNodes().item(0) != null){
                    		 String contributeRoleValue = contributeNodeList.item(0).getChildNodes().item(0).getNodeValue();
                             if (!contributeRoleValue.isEmpty()) {
                                 OntProperty hasContributionRoleProperty = lom_Model.getDatatypeProperty(NS
                                         + "metaMetadataContributionRole");
                                 Metadata_Contribution.addProperty(hasContributionRoleProperty, contributeRoleValue);
                             }	
                    	}                       
                    }
                    // ***************************** Entity - vcard ***********************************
                    NodeList contributeEntityNodeList = contributeE.getElementsByTagName(LOM_PREFIX + ":entity");

                    for (int k = 0; k < contributeEntityNodeList.getLength(); k++) {

                        // ******************* LMETAMETADATA_CONTRIBUTE_ROLE_INSTANCE ****************************
                        OntClass VCARD_Class = lom_Model.getOntClass(NS + "vCARD");
                        OntProperty L_Contribution_Entity = lom_Model.getObjectProperty(NS + "contributionEntity");

                        Individual MetaMetadata_Contribution_Entity = lom_Model.createIndividual(NS
                                + "metaMetadata_contribution_Entity_" + metadataURI + "_" + (i + 1) + "_" + (k + 1),
                                VCARD_Class);
                        Metadata_Contribution.addProperty(L_Contribution_Entity, MetaMetadata_Contribution_Entity);

                        if (contributeEntityNodeList.getLength() != 0
                                && contributeEntityNodeList.item(0).hasChildNodes()) {
                        	if(contributeEntityNodeList.item(k).getChildNodes() != null){
                        		String contributeEntityValue = contributeEntityNodeList.item(k).getChildNodes().item(0)
                                        .getNodeValue();
                                if (!contributeEntityValue.isEmpty()) {
                                    vCardParser vCardParser = new vCardParser();
                                    if (!vCardParser.name(contributeEntityValue).trim().isEmpty())
                                        MetaMetadata_Contribution_Entity.addProperty(VCARD.N,
                                                vCardParser.name(contributeEntityValue).trim());
                                    if (!vCardParser.fullName(contributeEntityValue).trim().isEmpty())
                                        MetaMetadata_Contribution_Entity.addProperty(VCARD.FN,
                                                vCardParser.fullName(contributeEntityValue).trim());
                                    if (!vCardParser.email(contributeEntityValue).trim().isEmpty())
                                        MetaMetadata_Contribution_Entity.addProperty(VCARD.EMAIL,
                                                vCardParser.email(contributeEntityValue).trim());
                                    if (!vCardParser.organization(contributeEntityValue).trim().isEmpty())
                                        MetaMetadata_Contribution_Entity.addProperty(VCARD.ORG,
                                                vCardParser.organization(contributeEntityValue).trim());
                                }
                        	}                            
                        }
                    }

                    // ***************************** Entity -Date ***********************************
                    NodeList contributionDateNodeList = contributeE.getElementsByTagName(LOM_PREFIX + ":dateTime");
                    if (contributionDateNodeList.getLength() != 0 && contributionDateNodeList.item(0).hasChildNodes()) {
                    	if(contributionDateNodeList.item(0).getChildNodes().item(0) != null){
                    		String contributionDate = contributionDateNodeList.item(0).getChildNodes().item(0)
                                    .getNodeValue();
                            if (!contributionDate.isEmpty()) {
                                OntProperty ContributionDateProperty = lom_Model.getDatatypeProperty(NS + "dateTimeValue");
                                Metadata_Contribution.addProperty(ContributionDateProperty, contributionDate);
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
                                    Metadata_Contribution.addProperty(ContributionDateDescriptionProperty,
                                            contributionDateDescription, contributionDateDescriptionNodeList.item(0)
                                                    .getAttributes().item(0).getNodeValue());
                                else
                                    Metadata_Contribution.addProperty(ContributionDateDescriptionProperty,
                                            contributionDateDescription);
                            }
                    	}                        
                    }
                }

                // ***************************** metaMetadata Schema ***********************************
                System.out.println("Analyzing metaMetadata.Schema");
                NodeList metaMetadataSchemaList = e.getElementsByTagName(LOM_PREFIX + ":metadataSchema");
                for (int i = 0; i < metaMetadataSchemaList.getLength(); i++) {
                    if (metaMetadataSchemaList.item(0).hasChildNodes()) {
                    	if(metaMetadataSchemaList.item(i).getChildNodes().item(0) != null){
                    		String schemaValue = metaMetadataSchemaList.item(i).getChildNodes().item(0).getNodeValue();
                            if (!schemaValue.isEmpty()) {
                                OntProperty metaMetadataSchema = lom_Model.getDatatypeProperty(NS + "metadataSchema");
                                resource_individual.addProperty(metaMetadataSchema, schemaValue);
                            }
                    	}                        
                    }
                }
                // ***************************** metaMetadata Language ***********************************
                System.out.println("Analyzing metaMetadata.Language");
                NodeList metaMetadataLanguage = e.getElementsByTagName(LOM_PREFIX + ":language");
                if(metaMetadataLanguage.item(0).getChildNodes().item(0) != null){
                	String languageValue = metaMetadataLanguage.item(0).getChildNodes().item(0).getNodeValue();
                    if (metaMetadataLanguage.getLength() != 0 && metaMetadataLanguage.item(0).hasChildNodes())
                        if (!languageValue.isEmpty()) {
                            OntProperty metaMetadataLanguageProperty = lom_Model.getDatatypeProperty(NS
                                    + "metaMetadataLanguage");
                            resource_individual.addProperty(metaMetadataLanguageProperty, languageValue);
                        }
                }                
            }
        }// metaMetadata
    }
}
