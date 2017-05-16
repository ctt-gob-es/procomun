package com.emergya.agrega2.odes.util;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.util.StringUtils;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.util.Utils;

public class OdesUtil {
    private static final Log LOG = LogFactory.getLog(OdesUtil.class);

    /**
     * Method to get a {@link SolrDocumentA2} ({@link Ode}) from a XML manifest with LOM-ES information
     * @param manifest XML content
     * @return {@link Ode} with fields form the XML
     */
    public static Ode getOdeFromManifest(byte[] manifest) {
        Ode ode = new Ode();
        DocumentBuilder dBuilder;
        Document manifestDoc = null;
        try {
            dBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            manifestDoc = dBuilder.parse(new ByteArrayInputStream(manifest));
        } catch (SAXException | IOException | ParserConfigurationException e) {
            Utils.logError(LOG, e.getMessage());
        }

        if (manifestDoc != null) {
            try {
                ode.setTitle(getXPathValue(manifestDoc, Utils.getMessage("agrega.lomes.xpath.general.title")));
                ode.setDescription(getXPathValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.general.description")));

                /* GENERAL */
                ode.setGeneralDescription(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.general.description")));
                ode.setGeneralIdentifier(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.general.identifier")));
                ode.setGeneralKeyword(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.general.keyword")));
                ode.setGeneralLanguage(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.general.language")));
                ode.setGeneralTitle(getXPathValue(manifestDoc, Utils.getMessage("agrega.lomes.xpath.general.title")));
                ode.setGeneralAggregationLevel(getXPathValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.general.aggregationLevel")));

                ode.setId(ode.generateId());

                /* TECHNICAL */
                ode.setTechnicalFormat(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.technical.format")));
                ode.setTechnicalSize(getXPathValue(manifestDoc, Utils.getMessage("agrega.lomes.xpath.technical.size")));
                ode.setTechnicalOtherPlatformRequirements(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.technical.otherPlatformRequirements")));
                ode.setTechnicalInstallationRemarks(getXPathValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.technical.installationRemarks")));

                List<String> reqTypes = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.technical.requirementType"));
                List<String> reqNames = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.technical.requirementName"));
                if (!Utils.isEmpty(reqTypes)) {
                    List<String> reqTypeNames = new ArrayList<String>();
                    for (int i = 0; i < reqTypes.size(); i++) {
                        String reqType = reqTypes.get(i);
                        String reqName = reqNames.get(i);
                        reqTypeNames.add(reqType + Utils.getMessage("format_separator") + reqName);
                    }
                    ode.setTechnicalRequirementTypeName(reqTypeNames);
                }

                /* LIFECYCLE */
                // FIXME: ROLE#USER#DATE#DESCRIPTION
                List<String> roleItems = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.contribute.role"));
                List<String> entityItems = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.contribute.user"));
                List<String> dateItems = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.contribute.date"));
                List<String> dateDescriptionItems = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.contribute.dateDescription"));
                List<String> lifeCycle = new ArrayList<String>();
                ode.setAuthor(new ArrayList<String>());
                for (int i = 0; i < roleItems.size(); i++) {
                    String role = roleItems.get(i);
                    // FIXME: Parseo de VCARD!!!!! Cogemos el EMAIL?? Hablar con
                    // DRUPAL
                    String user = getEmailFromVCard(entityItems.get(i));
                    if (StringUtils.isEmpty(ode.getAuthor()) && ("author".equals(role) || "publisher".equals(role))) {
                        ode.getAuthor().add(user);
                    }

                    StringBuilder sb = new StringBuilder(role).append(Utils.getMessage("format_separator"))
                            .append(user).append(Utils.getMessage("format_separator")).append(dateItems.get(i))
                            .append(Utils.getMessage("format_separator")).append(dateDescriptionItems.get(i));
                    lifeCycle.add(sb.toString());
                }
                ode.setLifecycleContribute(lifeCycle);

                /* EDUCATIONAL */
                ode.setEducationalLearningResourceType(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.educational.learningResourceType")));
                ode.setEducationalIntendedEndUserRole(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.educational.intendedEndUserRole")));
                ode.setEducationalContext(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.educational.context")));
                ode.setEducationalDescription(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.educational.description")));
                ode.setEducationalLanguage(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.educational.language")));
                ode.setEducationalCognitiveProcess(getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.educational.cognitiveProcess")));

                /* RIGHTS */
                ode.setRightsCopyrightAndOtherRestrictions(getXPathValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.rights.copyrightAndOtherRestrictions")));
                ode.setRightsAccess(getXPathValue(manifestDoc, Utils.getMessage("agrega.lomes.xpath.rights.accessType")));
                ode.setRightsAccessDescription(getXPathValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.rights.accessDescription")));

                /* CLASSIFICATION */

                /* Educational Level */
                List<String> classificationEducationalLevel = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.classification.educationalLevel"));
                if (classificationEducationalLevel != null && classificationEducationalLevel.size() > 0) {
                    for (String idTaxon : classificationEducationalLevel) {
                        String[] idTaxonSplit = idTaxon.split("\\.");
                        switch (idTaxonSplit.length) {
                        case 0:
                            break;
                        case 1:
                            List<String> edLevel1 = ode.getClassificationEducationalLevel1() != null ? ode
                                    .getClassificationEducationalLevel1() : new ArrayList<String>();
                            edLevel1.add(idTaxon);
                            ode.setClassificationEducationalLevel1(edLevel1);
                            break;
                        case 2:
                            List<String> edLevel2 = ode.getClassificationEducationalLevel2() != null ? ode
                                    .getClassificationEducationalLevel2() : new ArrayList<String>();
                            edLevel2.add(idTaxon);
                            ode.setClassificationEducationalLevel2(edLevel2);
                            break;
                        case 3:
                            List<String> edLevel3 = ode.getClassificationEducationalLevel3() != null ? ode
                                    .getClassificationEducationalLevel3() : new ArrayList<String>();
                            edLevel3.add(idTaxon);
                            ode.setClassificationEducationalLevel3(edLevel3);
                            break;
                        case 4:
                            List<String> edLevel4 = ode.getClassificationEducationalLevel4() != null ? ode
                                    .getClassificationEducationalLevel4() : new ArrayList<String>();
                            edLevel4.add(idTaxon);
                            ode.setClassificationEducationalLevel4(edLevel4);
                            break;
                        case 5:
                            List<String> edLevel5 = ode.getClassificationEducationalLevel5() != null ? ode
                                    .getClassificationEducationalLevel5() : new ArrayList<String>();
                            edLevel5.add(idTaxon);
                            ode.setClassificationEducationalLevel5(edLevel5);
                            break;
                        case 6:
                            List<String> edLevel6 = ode.getClassificationEducationalLevel6() != null ? ode
                                    .getClassificationEducationalLevel6() : new ArrayList<String>();
                            edLevel6.add(idTaxon);
                            ode.setClassificationEducationalLevel6(edLevel6);
                            break;
                        default:
                            break;
                        }
                    }
                }

                /* Discipline */
                List<String> classificationDiscipline = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.classification.discipline"));
                if (classificationDiscipline != null && classificationDiscipline.size() > 0) {
                    for (String idTaxon : classificationDiscipline) {
                        String[] idTaxonSplit = idTaxon.split("\\.");
                        switch (idTaxonSplit.length) {
                        case 0:
                            break;
                        case 1:
                            List<String> discipline1 = ode.getClassificationDiscipline1() != null ? ode
                                    .getClassificationDiscipline1() : new ArrayList<String>();
                            discipline1.add(idTaxon);
                            ode.setClassificationDiscipline1(discipline1);
                            break;
                        case 2:
                            List<String> discipline2 = ode.getClassificationDiscipline2() != null ? ode
                                    .getClassificationDiscipline2() : new ArrayList<String>();
                            discipline2.add(idTaxon);
                            ode.setClassificationDiscipline2(discipline2);
                            break;
                        case 3:
                            List<String> discipline3 = ode.getClassificationDiscipline3() != null ? ode
                                    .getClassificationDiscipline3() : new ArrayList<String>();
                            discipline3.add(idTaxon);
                            ode.setClassificationDiscipline3(discipline3);
                            break;
                        case 4:
                            List<String> discipline4 = ode.getClassificationDiscipline4() != null ? ode
                                    .getClassificationDiscipline4() : new ArrayList<String>();
                            discipline4.add(idTaxon);
                            ode.setClassificationDiscipline4(discipline4);
                            break;
                        default:
                            break;
                        }
                    }
                }

                /* Competency */
                List<String> classificationCompetency = getXPathMultiValue(manifestDoc,
                        Utils.getMessage("agrega.lomes.xpath.classification.competency"));
                if (classificationCompetency != null && classificationCompetency.size() > 0) {
                    for (String idTaxon : classificationCompetency) {
                        String[] idTaxonSplit = idTaxon.split("\\.");
                        switch (idTaxonSplit.length) {
                        case 0:
                            break;
                        case 1:
                            List<String> competency1 = ode.getClassificationCompetency1() != null ? ode
                                    .getClassificationCompetency1() : new ArrayList<String>();
                            competency1.add(idTaxon);
                            ode.setClassificationCompetency1(competency1);
                            break;
                        case 2:
                            List<String> competency2 = ode.getClassificationCompetency2() != null ? ode
                                    .getClassificationCompetency2() : new ArrayList<String>();
                            competency2.add(idTaxon);
                            ode.setClassificationCompetency2(competency2);
                            break;
                        default:
                            break;
                        }
                    }
                }

                /* CONTENT */

            } catch (XPathExpressionException e) {
                Utils.logError(LOG, e.getMessage());
            }
        }

        return ode;
    }

    /**
     * Method to get a single XPath value from an XML
     * @param doc XML source
     * @param xPathExpression XPath expression to search
     * @return Result of the evaluation of the XPath expression in the document
     * @throws XPathExpressionException if the expression is not correct
     */
    public static String getXPathValue(Document doc, String xPathExpression) throws XPathExpressionException {
        XPath xpath = XPathFactory.newInstance().newXPath();
        XPathExpression xPathExp = xpath.compile(xPathExpression);
        if (xPathExp != null)
            return xPathExp.evaluate(doc);
        else
            return null;
    }

    /**
     * Method to get a multiple XPath value from an XML
     * @param doc XML source
     * @param xPathExpression XPath expression to search
     * @return Result of the evaluation of the XPath expression in the document
     * @throws XPathExpressionException if the expression is not correct
     */
    public static List<String> getXPathMultiValue(Document doc, String xPathExpression) throws XPathExpressionException {
        List<String> result = new ArrayList<String>();
        XPath xpath = XPathFactory.newInstance().newXPath();

        XPathExpression xPathExp = xpath.compile(xPathExpression);
        if (xPathExp != null) {
            NodeList ids = (NodeList) xPathExp.evaluate(doc, XPathConstants.NODESET);
            if (ids != null) {
                for (int idx = 0; idx < ids.getLength(); idx++) {
                    Node id = ids.item(idx);
                    result.add(id.getTextContent());
                }
            }
        }

        return result;
    }

    /**
     * Method to get the XPath result from an XML
     * @param manifest XML source
     * @param property XPath property to search
     * @param multiple Multiple values or a single one
     * @return A String with the single value or a List of String if multiple values are requested; null if no values are found.
     */
    public static Object getManifestProperty(byte[] manifest, String property, boolean multiple) {
        Object result = null;
        if (manifest != null) {
            DocumentBuilder dBuilder;
            try {
                dBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
                Document manifestDoc = dBuilder.parse(new ByteArrayInputStream(manifest));

                if (multiple)
                    result = getXPathMultiValue(manifestDoc, property);
                else
                    result = getXPathValue(manifestDoc, property);
            } catch (SAXException | IOException | ParserConfigurationException | XPathExpressionException e) {
                Utils.logError(LOG, e.getMessage());
            }

        }

        return result;
    }

    /**
     * Method to get Email information from VCard. It searches for xxx@yyyy format. 
     * @param value String with VCard information
     * @return Email address, if found. Empty string otherwise
     */
    public static String getEmailFromVCard(String value) {
        // String[] words = value.split(" ");
        String str = "";
        String email0 = "";
        String email1 = "";
        // EJEMPLO:
        // BEGIN:VCARD VERSION:3.0 FN:Octavio González
        // EMAIL;TYPE=INTERNET:ogonzalez@emergya.com ORG:Emergya END:VCARD<200b>
        if (!StringUtils.isEmpty(value)) {
            int indexAt = value.indexOf("@");
            if (indexAt > 0) {
                String substring0 = value.substring(0, indexAt);
                int lastIndexSpace = substring0.lastIndexOf(" ");
                if (lastIndexSpace > 0) {
                    email0 = substring0.substring(lastIndexSpace + 1, substring0.length());
                    if (!StringUtils.isEmpty(email0) && email0.contains(":")) {
                        email0 = email0.substring(email0.lastIndexOf(":") + 1, email0.length());
                    }

                    String substring1 = value.substring(indexAt, value.length());
                    int firstIndexSpace = substring1.indexOf(" ");
                    if (firstIndexSpace > 0) {
                        email1 = substring1.substring(0, firstIndexSpace);
                        if (!StringUtils.isEmpty(email1) && email1.contains(":")) {
                            email1 = email1.substring(0, email1.indexOf(":"));
                        }

                        if (!StringUtils.isEmpty(email0) && !StringUtils.isEmpty(email1)) {
                            str = email0 + email1;
                        }
                    }
                }
            }
        }

        return str;
    }

}
