package com.emergya.agrega2.odes.util;

import java.io.IOException;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.xml.sax.SAXException;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.ContentFile;

public class OdesManifestParser {
    private static final Log LOG = LogFactory.getLog(OdesManifestParser.class);

    /**
     * Parses the GENERAL information of the Manifest template (Category 1 of LOM-ES)
     * - Languages
     * - Title
     * - Identifiers
     * - Descriptions
     * - AggregationLevels
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseGeneralInfo(Ode ode, Document xml) {

        // <lomes:title uniqueElementName="title">
        // <lomes:string language="XXXXX">
        String language = !Utils.isEmpty(ode.getGeneralLanguage()) ? ode.getGeneralLanguage().get(0) : Utils
                .getMessage("agrega.lomes.default.language");
        setXMLValueDocument(language, Utils.getMessage("agrega.lomes.xpath.general.title"), xml, "language");

        // <lomes:title uniqueElementName="title">
        // <lomes:string language="">XXXXX</lomes:string>
        // </lomes:title>
        setXMLValueDocument(ode.getTitle(), Utils.getMessage("agrega.lomes.xpath.general.title"), xml, null);

        // <lomes:identifier>
        // <lomes:catalog uniqueElementName="catalog">Procomún</lomes:catalog>
        // <lomes:entry uniqueElementName="entry">XXXXXX</lomes:entry>
        // </lomes:identifier>
        if (!Utils.isEmpty(ode.getGeneralIdentifier())) {
            boolean first = true;
            for (String identifier : ode.getGeneralIdentifier()) {
                try {
                    if (!first) {
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.general.identifier"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    setXMLValueDocument(identifier, Utils.getMessage("agrega.lomes.xpath.general.identifier"), xml,
                            null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample identifier from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.general.identifier"), xml, true);
        }

        // <lomes:description>
        // <lomes:string language="XXXXX">XXXXX</lomes:string>
        // </lomes:description>
        setXMLValueDocument(ode.getDescription(), Utils.getMessage("agrega.lomes.xpath.general.description"), xml, null);
        setXMLValueDocument(language, Utils.getMessage("agrega.lomes.xpath.general.description"), xml, "language");

        if (!Utils.isEmpty(ode.getGeneralDescription())) {
            boolean first = true;
            for (String desc : ode.getGeneralDescription()) {
                try {
                    if (!first) {
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.general.description"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else
                        first = false;
                    setXMLValueDocument(desc, Utils.getMessage("agrega.lomes.xpath.general.description"), xml, null);
                    setXMLValueDocument(language, Utils.getMessage("agrega.lomes.xpath.general.description"), xml,
                            "language");
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }

        // <lomes:language>XXXXX</lomes:language>
        if (!Utils.isEmpty(ode.getGeneralLanguage())) {
            boolean first = true;
            for (String lang : ode.getGeneralLanguage()) {
                try {
                    if (!first) {
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.general.language"), xml);
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else
                        first = false;
                    setXMLValueDocument(lang, Utils.getMessage("agrega.lomes.xpath.general.language"), xml, null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample language from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.general.language"), xml, false);
        }

        // <lomes:aggregationLevel uniqueElementName="aggregationLevel">
        // <lomes:source uniqueElementName="source">LOM-ESv1.0</lomes:source>
        // <lomes:value uniqueElementName="value">XXXXX</lomes:value>
        // </lomes:aggregationLevel>
        if (!Utils.isEmpty(ode.getGeneralAggregationLevel())) {
            setXMLValueDocument(ode.getGeneralAggregationLevel(),
                    Utils.getMessage("agrega.lomes.xpath.general.aggregationLevel"), xml, null);
        } else {
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.general.aggregationLevel"), xml, true);
        }

    }

    /**
     * Parses the LIFECYCLE information of the Manifest template (Category 2 of LOM-ES)
     * - Contribute: Role
     * - Contribute: User
     * - Contribute: Date
     * - Contribute: Date-Description
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseLifeCycleInfo(Ode ode, Document xml) {
        if (!Utils.isEmpty(ode.getLifecycleContribute())) {
            List<String> xPath = new ArrayList<String>();
            // <lomes:role uniqueElementName="role">
            // <lomes:source
            // uniqueElementName="source">LOM-ESv1.0</lomes:source>
            // <lomes:value uniqueElementName="value">XXXXX</lomes:value>
            // </lomes:role>
            xPath.add(Utils.getMessage("agrega.lomes.xpath.contribute.role"));

            // <lomes:entity>XXXXX</lomes:entity>
            xPath.add(Utils.getMessage("agrega.lomes.xpath.contribute.user"));

            // <lomes:date uniqueElementName="date">
            // <lomes:dateTime
            // uniqueElementName="dateTime">XXXXX</lomes:dateTime>
            // <lomes:description>
            // <lomes:string>XXXXX</lomes:string>
            // </lomes:description>
            // </lomes:date>
            xPath.add(Utils.getMessage("agrega.lomes.xpath.contribute.date"));
            xPath.add(Utils.getMessage("agrega.lomes.xpath.contribute.dateDescription"));
            boolean first = true;
            for (String cont : ode.getLifecycleContribute()) {
                try {
                    if (!first) {
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.contribute"), xml);
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    setXMLValueDocument(Arrays.asList(cont.split(Utils.getMessage("format_separator"))), xPath, xml,
                            null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample contribute element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.contribute"), xml, false);
        }
    }

    /**
     * Parses the EDUCATIONAL information of the Manifest template (Category 5 of LOM-ES)
     * - Learning Resource Type
     * - Intended End User Role
     * - Context
     * - Cognitive Process
     * - Description
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseEducationalInfo(Ode ode, Document xml, String language) {

        if (!Utils.isEmpty(ode.getEducationalLearningResourceType())) {
            boolean first = true;
            for (String lrt : ode.getEducationalLearningResourceType()) {
                try {
                    // The first time it is not necessary to create the element
                    // (there is a sample one)
                    if (!first) {
                        // Create a "brother" node
                        Node node = getXPathNode(
                                Utils.getMessage("agrega.lomes.xpath.educational.learningResourceType"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    // <lomes:learningResourceType>
                    // <lomes:source
                    // uniqueElementName="source">LOM-ESv1.0</lomes:source>
                    // <lomes:value
                    // uniqueElementName="value">XXXXX</lomes:value>
                    // </lomes:learningResourceType>
                    setXMLValueDocument(lrt, Utils.getMessage("agrega.lomes.xpath.educational.learningResourceType"),
                            xml, null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample learningResourceType element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.educational.learningResourceType"), xml, true);
        }

        if (!Utils.isEmpty(ode.getEducationalIntendedEndUserRole())) {
            boolean first = true;
            for (String ieur : ode.getEducationalIntendedEndUserRole()) {
                try {
                    // The first time it is not necessary to create the element
                    // (there is a sample one)
                    if (!first) {
                        // Create a "brother" node
                        Node node = getXPathNode(
                                Utils.getMessage("agrega.lomes.xpath.educational.intendedEndUserRole"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    // <lomes:intendedEndUserRole>
                    // <lomes:source
                    // uniqueElementName="source">LOM-ESv1.0</lomes:source>
                    // <lomes:value
                    // uniqueElementName="value">XXXXX</lomes:value>
                    // </lomes:intendedEndUserRole>
                    setXMLValueDocument(ieur, Utils.getMessage("agrega.lomes.xpath.educational.intendedEndUserRole"),
                            xml, null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample intendedEndUserRole element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.educational.intendedEndUserRole"), xml, true);
        }

        if (!Utils.isEmpty(ode.getEducationalContext())) {
            boolean first = true;
            for (String ctx : ode.getEducationalContext()) {
                try {
                    // The first time it is not necessary to create the element
                    // (there is a sample one)
                    if (!first) {
                        // Create a "brother" node
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.educational.context"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    // <lomes:context>
                    // <lomes:source
                    // uniqueElementName="source">LOM-ESv1.0</lomes:source>
                    // <lomes:value
                    // uniqueElementName="value">XXXXX</lomes:value>
                    // </lomes:context>
                    setXMLValueDocument(ctx, Utils.getMessage("agrega.lomes.xpath.educational.context"), xml, null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample context element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.educational.context"), xml, true);
        }

        if (!Utils.isEmpty(ode.getEducationalCognitiveProcess())) {
            boolean first = true;
            for (String cp : ode.getEducationalCognitiveProcess()) {
                try {
                    // The first time it is not necessary to create the element
                    // (there is a sample one)
                    if (!first) {
                        // Create a "brother" node
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.educational.cognitiveProcess"),
                                xml).getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    // <lomes:cognitiveProcess>
                    // <lomes:source
                    // uniqueElementName="source">LOM-ESv1.0</lomes:source>
                    // <lomes:value
                    // uniqueElementName="value">XXXXX</lomes:value>
                    // </lomes:cognitiveProcess>
                    setXMLValueDocument(cp, Utils.getMessage("agrega.lomes.xpath.educational.cognitiveProcess"), xml,
                            null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample cognitiveProcess element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.educational.cognitiveProcess"), xml, true);
        }

        if (!Utils.isEmpty(ode.getEducationalDescription())) {
            boolean first = true;
            for (String dsc : ode.getEducationalDescription()) {
                try {
                    // The first time it is not necessary to create the element
                    // (there is a sample one)
                    if (!first) {
                        // Create a "brother" node
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.educational.description"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    // <lomes:description>
                    // <lomes:string language="XXXXX">XXXXX</lomes:string>
                    // </lomes:description>
                    setXMLValueDocument(dsc, Utils.getMessage("agrega.lomes.xpath.educational.description"), xml, null);
                    setXMLValueDocument(language, Utils.getMessage("agrega.lomes.xpath.educational.description"), xml,
                            "language");
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample description element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.educational.description"), xml, true);
        }

        if (!Utils.isEmpty(ode.getEducationalLanguage())) {
            boolean first = true;
            for (String lng : ode.getEducationalLanguage()) {
                try {
                    // The first time it is not necessary to create the element
                    // (there is a sample one)
                    if (!first) {
                        // Create a "brother" node
                        Node node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.educational.language"), xml)
                                .getParentNode();
                        if (node != null) {
                            Node clone = node.cloneNode(true);
                            Node parent = node.getParentNode();
                            parent.insertBefore(clone, node);
                            xml = parent.getOwnerDocument();
                        }
                    } else {
                        first = false;
                    }
                    // <lomes:language></lomes:language>
                    setXMLValueDocument(lng, Utils.getMessage("agrega.lomes.xpath.educational.language"), xml, null);
                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            // Delete sample description element from XML
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.educational.language"), xml, false);
        }

    }

    /**
     * Parses the RIGHTS information of the Manifest template (Category 6 of LOM-ES)
     * - Copyright and other restrictions
     * - Access type
     * - Access description
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseRightsInfo(Ode ode, Document xml) {
        if (!Utils.isEmpty(ode.getRightsCopyrightAndOtherRestrictions())) {

            // <lomes:copyrightAndOtherRestrictions
            // uniqueElementName="copyrightAndOtherRestrictions">
            // <lomes:source
            // uniqueElementName="source">LOM-ESv1.0</lomes:source>
            // <lomes:value uniqueElementName="value">XXXXX</lomes:value>
            // </lomes:copyrightAndOtherRestrictions>
            setXMLValueDocument(ode.getRightsCopyrightAndOtherRestrictions(),
                    Utils.getMessage("agrega.lomes.xpath.rights.copyrightAndOtherRestrictions"), xml, null);

            // <lomes:access uniqueElementName="access">
            // <lomes:accessType uniqueElementName="accessType">
            // <lomes:source
            // uniqueElementName="source">LOM-ESv1.0</lomes:source>
            // <lomes:value uniqueElementName="value">XXXXX</lomes:value>
            // </lomes:accessType>
            // <lomes:description>
            // <lomes:string>XXXXX</lomes:string>
            // </lomes:description>
            // </lomes:access>
            if (!Utils.isEmpty(ode.getRightsAccess())) {
                setXMLValueDocument(ode.getRightsAccess(), Utils.getMessage("agrega.lomes.xpath.rights.accessType"),
                        xml, null);
            } else {
                deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.rights.accessType"), xml, true);
            }

            if (!Utils.isEmpty(ode.getRightsAccessDescription())) {
                setXMLValueDocument(ode.getRightsAccessDescription(),
                        Utils.getMessage("agrega.lomes.xpath.rights.accessDescription"), xml, null);
            } else {
                deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.rights.accessDescription"), xml, true);
            }
        } else {
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.rights"), xml, false);
        }
    }

    /**
     * Inserts a taxon id in a classification/taxonPath node of a Manifest (Category 9.2.2.1 of LOM-ES)
     * @param node Taxon node of the Manifest
     * @param value Taxon Id
     */
    private static void insertClassificationTaxon(Node node, String value) {
        try {
            setXMLValueDocument(value, Utils.getMessage("agrega.lomes.xpath.classification.taxon.id"), node, null);
            // Taxon Description: "//taxon/entry/string";

            // Clone the Taxon node in the document
            Node taxon = getXPathNode(Utils.getMessage("agrega.lomes.xpath.classification.taxon.id"), node)
                    .getParentNode();
            if (taxon != null) {
                Node clone = taxon.cloneNode(true);
                Node parent = taxon.getParentNode();
                parent.appendChild(clone);
            }
        } catch (XPathExpressionException e) {
            Utils.logError(LOG, e.getMessage());
        }
    }

    /**
     * Insert the purpose (Category 9.1 of LOM-ES) and source (Category 9.2.1 of LOM-ES) values of the classification node of the Manifest and returns the node
     * @param purpose Category 9.1 of LOM-ES
     * @param source Category 9.2.1 of LOM-ES
     * @param xml XML to parse
     * @return Classification node (Category 0 of LOM-ES)
     */
    private static Node parseClassificationNodeInit(String purpose, String source, Document xml) {
        Node node = null;
        try {
            node = getXPathNode(Utils.getMessage("agrega.lomes.xpath.classification"), xml);
        } catch (XPathExpressionException e) {
            Utils.logError(LOG, e.getMessage());
        }

        setXMLValueDocument(purpose, Utils.getMessage("agrega.lomes.xpath.classification.purpose"), xml, null);
        setXMLValueDocument(source, Utils.getMessage("agrega.lomes.xpath.classification.source"), xml, null);

        return node;
    }

    /**
     * Inserts a node as the previous sibling of another one
     * @param node Original node
     * @param clone New node to insert
     */
    private static void duplicateNodeBefore(Node node, Node clone) {
        if (node != null) {
            Node parent = node.getParentNode();
            parent.insertBefore(clone, node);
        }
    }

    /**
     * Parses the EDUCATIONAL_LEVEL information of the Manifest template (Category 9 of LOM-ES)
     * Nivel educativo LOM-ESv1.0 (the tree has max. 6 levels)
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseClassificationEducationalLevelInfo(Ode ode, Document xml) {
        String purposeEdLevel = Utils.getMessage("agrega.lomes.classification.purpose.educational_level");
        String sourceEdLevel = Utils.getMessage("agrega.lomes.classification.source.educational_level");
        // Example: 2.1.1, 2.3, 3.1.2.3.4.5, 4.2.1.3, 6.3.4
        // Level 1: [2, 2, 3, 4, 6]
        // Level 2: [2.1, 2.3, 3.1, 4.2, 6.3]
        // Level 3: [2.1.1, 3.1.2, 4.2.1, 6.3.4]
        // Level 4: [3.1.2.3, 4.2.1.3]
        // Level 5: [3.1.2.3.4]
        // Level 6: [3.1.2.3.4.5]
        List<String> edL1 = ode.getClassificationEducationalLevel1();
        if (!Utils.isEmpty(edL1)) {
            int l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0, l6 = 0;
            while (l1 < edL1.size()) {
                // Create classification node and clone node
                Node node = parseClassificationNodeInit(purposeEdLevel, sourceEdLevel, xml);
                Node cloneL1 = node.cloneNode(true);
                String l1Elem = edL1.get(l1);

                // Parse next level until the id starts with the previous one
                boolean enc2 = false;
                List<String> edL2 = ode.getClassificationEducationalLevel2();
                if (!Utils.isEmpty(edL2)) {
                    while (l2 < edL2.size() && !enc2) {
                        String l2Elem = edL2.get(l2);
                        // It starts with the previous one? (example: 2.1 starts
                        // with 2)
                        if (l2Elem.startsWith(l1Elem)) {
                            // Element found. Insert taxon node
                            enc2 = true;
                            // Insert the taxon node
                            insertClassificationTaxon(node, l2Elem);

                            // Parse next level until the id starts with the
                            // previous one
                            boolean enc3 = false;
                            List<String> edL3 = ode.getClassificationEducationalLevel3();
                            if (!Utils.isEmpty(edL3)) {
                                while (l3 < edL3.size() && !enc3) {
                                    String l3Elem = edL3.get(l3);
                                    // It starts with the previous one?
                                    // (example: 2.1.3 starts with 2.1)
                                    if (l3Elem.startsWith(l2Elem)) {
                                        enc3 = true;
                                        // Insert the taxon node
                                        insertClassificationTaxon(node, l3Elem);

                                        // Parse next level until the id starts
                                        // with the previous one
                                        boolean enc4 = false;
                                        List<String> edL4 = ode.getClassificationEducationalLevel4();
                                        if (!Utils.isEmpty(edL4)) {
                                            while (l4 < edL4.size() && !enc4) {
                                                String l4Elem = edL4.get(l4);
                                                // It starts with the previous
                                                // one? (example: 2.1.3.2 starts
                                                // with 2.1.3)
                                                if (l4Elem.startsWith(l3Elem)) {
                                                    enc4 = true;
                                                    // Insert the taxon node
                                                    insertClassificationTaxon(node, l4Elem);

                                                    // Parse next level until
                                                    // the id starts with the
                                                    // previous one
                                                    boolean enc5 = false;
                                                    List<String> edL5 = ode.getClassificationEducationalLevel5();
                                                    if (!Utils.isEmpty(edL5)) {
                                                        while (l5 < edL5.size() && !enc5) {
                                                            String l5Elem = edL5.get(l5);
                                                            // It starts with
                                                            // the previous one?
                                                            // (example:
                                                            // 2.1.3.2.2
                                                            // starts with
                                                            // 2.1.3.2)
                                                            if (l5Elem.startsWith(l4Elem)) {
                                                                enc5 = true;
                                                                // Insert the
                                                                // taxon node
                                                                insertClassificationTaxon(node, l5Elem);

                                                                // Parse next
                                                                // level until
                                                                // the id starts
                                                                // with the
                                                                // previous one
                                                                boolean enc6 = false;
                                                                List<String> edL6 = ode
                                                                        .getClassificationEducationalLevel6();
                                                                if (!Utils.isEmpty(edL6)) {
                                                                    while (l6 < edL6.size() && !enc6) {
                                                                        String l6Elem = edL6.get(l6);
                                                                        // It
                                                                        // starts
                                                                        // with
                                                                        // the
                                                                        // previous
                                                                        // one?
                                                                        // (example:
                                                                        // 2.1.3.2.2.4
                                                                        // starts
                                                                        // with
                                                                        // 2.1.3.2.2)
                                                                        if (l6Elem.startsWith(l5Elem)) {
                                                                            enc6 = true;
                                                                            // Insert
                                                                            // the
                                                                            // taxon
                                                                            // node
                                                                            insertClassificationTaxon(node, l6Elem);
                                                                            // Conserve
                                                                            // the
                                                                            // index
                                                                            // for
                                                                            // the
                                                                            // next
                                                                            // element
                                                                            // of
                                                                            // the
                                                                            // first
                                                                            // level
                                                                            l6++;
                                                                        } else {
                                                                            break;
                                                                        }
                                                                    }
                                                                }
                                                                // Conserve the
                                                                // index for the
                                                                // next element
                                                                // of the first
                                                                // level
                                                                l5++;
                                                            } else {
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    // Conserve the index for
                                                    // the next element of the
                                                    // first level
                                                    l4++;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                        // Conserve the index for the next
                                        // element of the first level
                                        l3++;
                                    } else {
                                        break;
                                    }
                                }
                            }
                            // Conserve the index for the next element of the
                            // first level
                            l2++;
                        } else {
                            break;
                        }
                    }
                }
                // Insert the first level taxon node
                setXMLValueDocument(l1Elem, Utils.getMessage("agrega.lomes.xpath.classification.taxon.id"), node, null);
                l1++;
                // Generate the sample node for the next classification purpose
                duplicateNodeBefore(node, cloneL1);
            }
        }
    }

    /**
     * Parses the EDUCATIONAL_LEVEL information of the Manifest template (Category 9 of LOM-ES)
     * Árbol curricular LOE 2006 (the tree has max. 4 levels)
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseClassificationDisciplineInfo(Ode ode, Document xml) {
        String purposeDiscipline = Utils.getMessage("agrega.lomes.classification.purpose.discipline");
        String sourceDiscipline = Utils.getMessage("agrega.lomes.classification.source.discipline");
        // Example: 2.1.1, 2.3, 4.2.1.3, 6.3.4
        // Level 1: [2, 2, 4, 6]
        // Level 2: [2.1, 2.3, 4.2, 6.3]
        // Level 3: [2.1.1, 4.2.1, 6.3.4]
        // Level 4: [4.2.1.3]
        List<String> disc1 = ode.getClassificationDiscipline1();
        if (!Utils.isEmpty(disc1)) {
            int l1 = 0, l2 = 0, l3 = 0, l4 = 0;
            while (l1 < disc1.size()) {
                // Create classification node and clone node
                Node node = parseClassificationNodeInit(purposeDiscipline, sourceDiscipline, xml);
                Node cloneL1 = node.cloneNode(true);
                String l1Elem = disc1.get(l1);

                // Parse next level until the id starts with the previous one
                boolean enc2 = false;
                List<String> disc2 = ode.getClassificationDiscipline2();
                if (!Utils.isEmpty(disc2)) {
                    while (l2 < disc2.size() && !enc2) {
                        String l2Elem = disc2.get(l2);
                        // It starts with the previous one? (example: 2.1 starts
                        // with 2)
                        if (l2Elem.startsWith(l1Elem)) {
                            enc2 = true;
                            // Insert the taxon node
                            insertClassificationTaxon(node, l2Elem);

                            // Parse next level until the id starts with the
                            // previous one
                            boolean enc3 = false;
                            List<String> disc3 = ode.getClassificationDiscipline3();
                            if (!Utils.isEmpty(disc3)) {
                                while (l3 < disc3.size() && !enc3) {
                                    String l3Elem = disc3.get(l3);
                                    // It starts with the previous one?
                                    // (example: 2.1.4 starts with 2.1)
                                    if (l3Elem.startsWith(l2Elem)) {
                                        enc3 = true;
                                        // Insert the taxon node
                                        insertClassificationTaxon(node, l3Elem);

                                        // Parse next level until the id starts
                                        // with the previous one
                                        boolean enc4 = false;
                                        List<String> disc4 = ode.getClassificationDiscipline4();
                                        if (!Utils.isEmpty(disc4)) {
                                            while (l4 < disc4.size() && !enc4) {
                                                String l4Elem = disc4.get(l4);
                                                // It starts with the previous
                                                // one? (example: 2.1.4.2 starts
                                                // with 2.1.4)
                                                if (l4Elem.startsWith(l3Elem)) {
                                                    enc4 = true;
                                                    // Insert the taxon node
                                                    insertClassificationTaxon(node, l4Elem);
                                                    // Conserve the index for
                                                    // the next element of the
                                                    // first level
                                                    l4++;
                                                } else {
                                                    break;
                                                }
                                            }
                                        }
                                        // Conserve the index for the next
                                        // element of the first level
                                        l3++;
                                    } else {
                                        break;
                                    }
                                }
                            }
                            // Conserve the index for the next element of the
                            // first level
                            l2++;
                        } else {
                            break;
                        }
                    }
                }
                // Insert the first level taxon node
                setXMLValueDocument(l1Elem, Utils.getMessage("agrega.lomes.xpath.classification.taxon.id"), node, null);
                l1++;
                duplicateNodeBefore(node, cloneL1);
            }

        }
    }

    /**
     * Parses the EDUCATIONAL_LEVEL information of the Manifest template (Category 9 of LOM-ES)
     * Not defined (the tree has max. 2 levels)
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseClassificationCompetencyInfo(Ode ode, Document xml) {
        String purposeCompetency = Utils.getMessage("agrega.lomes.classification.purpose.competency");
        String sourceCompetency = Utils.getMessage("agrega.lomes.classification.source.competency");
        // Example: 2.1, 2, 3.1
        // Level 1: [2, 2, 3]
        // Level 2: [2.1, 3.1]
        List<String> comp1 = ode.getClassificationCompetency1();
        if (!Utils.isEmpty(comp1)) {
            int l1 = 0, l2 = 0;
            while (l1 < comp1.size()) {
                // Create classification node and clone node
                Node node = parseClassificationNodeInit(purposeCompetency, sourceCompetency, xml);
                Node cloneL1 = node.cloneNode(true);
                String l1Elem = comp1.get(l1);

                // Parse next level until the id starts with the previous one
                boolean enc2 = false;
                List<String> comp2 = ode.getClassificationCompetency2();
                if (!Utils.isEmpty(comp2)) {
                    while (l2 < comp2.size() && !enc2) {
                        String l2Elem = comp2.get(l2);
                        // It starts with the previous one? (example: 2.1.4
                        // starts with 2.1)
                        if (l2Elem.startsWith(l1Elem)) {
                            enc2 = true;
                            // Insert the taxon node
                            insertClassificationTaxon(node, l2Elem);
                            // Conserve the index for the next element of the
                            // first level
                            l2++;
                        } else {
                            break;
                        }
                    }
                }
                // Insert the first level taxon node
                setXMLValueDocument(l1Elem, Utils.getMessage("agrega.lomes.xpath.classification.taxon.id"), node, null);
                l1++;
                duplicateNodeBefore(node, cloneL1);
            }
        }
    }

    /**
     * Parses the CLASSIFICATION information of the Manifest template (Category 9 of LOM-ES)
     * - Educational level
     * - Discipline
     * - Competency
     * @param ode ODE to get information from
     * @param xml XML to parse
     */
    private static void parseClassificationInfo(Ode ode, Document xml) {
        // <lomes:classification>
        // <lomes:purpose uniqueElementName="purpose">
        // <lomes:source uniqueElementName="source">LOM-ESv1.0</lomes:source>
        // <lomes:value uniqueElementName="value">XXXXX</lomes:value>
        // </lomes:purpose>
        // <lomes:taxonPath>
        // <lomes:source uniqueElementName="source">
        // <lomes:string>XXXXX</lomes:string>
        // </lomes:source>
        // <lomes:taxon>
        // <lomes:id uniqueElementName="id">XXXXX</lomes:id>
        // <lomes:entry>
        // <lomes:string>FIXME: Taxon description</lomes:string>
        // </lomes:entry>
        parseClassificationEducationalLevelInfo(ode, xml);

        parseClassificationDisciplineInfo(ode, xml);

        parseClassificationCompetencyInfo(ode, xml);

        deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.classification"), xml, false);
    }

    private static void parseOrganizationsResources(Ode ode, Document xml) {
        if (ode.getContentTable() != null && ode.getContentTable().size() > 0) {
            int i = 0;
            List<ContentFile> files = ode.getContentTable();
            Collections.sort(files, Collections.reverseOrder());
            for (ContentFile cFile : files) {
                try {
                    Node organizationNode = getXPathNode(Utils.getMessage("agrega.lomes.xpath.organization.item"), xml);
                    Node cloneOrganization = organizationNode.cloneNode(true);
                    Node resourceNode = getXPathNode("//resources/resource", xml);
                    Node cloneResource = resourceNode.cloneNode(true);

                    setXMLValueDocument(cFile.getTitle(),
                            Utils.getMessage("agrega.lomes.xpath.organization.item.title"), organizationNode, null);
                    setXMLValueDocument("ORG-" + ode.getId() + i,
                            Utils.getMessage("agrega.lomes.xpath.organization.item"), organizationNode, "identifier");
                    setXMLValueDocument("RES-" + ode.getId() + i,
                            Utils.getMessage("agrega.lomes.xpath.organization.item"), organizationNode, "identifierref");

                    if (cFile.getFile() != null) {
                        setXMLValueDocument(cFile.getFile().getFileName(),
                                Utils.getMessage("agrega.lomes.xpath.resource.file"), resourceNode, "href");
                        setXMLValueDocument(cFile.getFile().getFileName(),
                                Utils.getMessage("agrega.lomes.xpath.resource"), resourceNode, "href");
                    }
                    setXMLValueDocument("RES-" + ode.getId() + i, Utils.getMessage("agrega.lomes.xpath.resource"),
                            resourceNode, "identifier");

                    duplicateNodeBefore(organizationNode, cloneOrganization);
                    duplicateNodeBefore(resourceNode, cloneResource);

                    i++;

                } catch (XPathExpressionException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.organization.item"), xml, false);
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.resource"), xml, false);
        } else {
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.resource"), xml, true);
            deleteSampleNode(Utils.getMessage("agrega.lomes.xpath.organization"), xml, true);
        }

    }

    /**
     * Parse an ODE to generate the Manifest XML with the LOM-ES information
     * It is based in a XML template (LOM-ES v1.0) 
     * @param ode ODE to parse
     * @return XML with the Manifest of the ODE parsed (LOM-ES data)
     */
    public static String parseOde(Ode ode) {
        Document xml = getDocumentFromTemplate("imsmanifest_template.xml");

        if (!Utils.isEmpty(ode.getId())) {
            setXMLValueDocument("ODE-" + ode.getId(), "//manifest", xml, "identifier");
        } else {
            setXMLValueDocument("ODE-default-" + System.currentTimeMillis(), "//manifest", xml, "identifier");
        }

        /** GENERAL **/
        parseGeneralInfo(ode, xml);

        // /** TECHNICAL **/
        // Include technical info in the basic form???
        // parseTechnicalInfo(ode, xml);

        /** LIFECYCLE **/
        parseLifeCycleInfo(ode, xml);

        /** MetaMetadata**/
        String language = (ode.getGeneralLanguage() != null && ode.getGeneralLanguage().size() > 0) ? ode
                .getGeneralLanguage().get(0) : Utils.getMessage("agrega.lomes.default.language");
        setXMLValueDocument(language, Utils.getMessage("agrega.lomes.xpath.metaMetadata.language"), xml, null);

        /** EDUCATIONAL **/
        parseEducationalInfo(ode, xml, language);

        /** RIGHTS **/
        parseRightsInfo(ode, xml);

        /** CLASSIFICATION **/
        parseClassificationInfo(ode, xml);

        /** ORGANIZATIONS & RESOURCES **/
        parseOrganizationsResources(ode, xml);

        return getStringFromDoc(xml);
    }

    /**
     * Delete the sample nodes of the manifest
     * @param xPathExpression XPath of the node to delete
     * @param xml XML to parse
     * @param parent Indicates if the node to delete is the the one determined by the xpath (false) or its parent (true)
     */
    private static void deleteSampleNode(String xPathExpression, Document xml, boolean parent) {
        Node node = null;
        try {
            node = getXPathNode(xPathExpression, xml);
            if (parent) {
                node = node.getParentNode();
            }
            node.getParentNode().removeChild(node);
        } catch (Exception e) {
            Utils.logError(LOG, e.getMessage());
        }
    }

    /**
     * Sets a value in a node of an XML template
     * @param value Value to set (it could be a list of values)
     * @param xPathExpression XPath of the node to set (it could be a list of expressions)
     * @param doc XML Document (or Node) to use
     * @param attribute Attribute to set (if it is null, the method set the text content of the node)
     * @return The Document or Node modified
     */
    @SuppressWarnings("unchecked")
    private static Object setXMLValueDocument(Object value, Object xPathExpression, Object doc, String attribute) {
        if (value != null) {
            try {
                if (xPathExpression instanceof String)
                    doc = setXPathValue((String) value, (String) xPathExpression, doc, attribute);
                else {
                    List<String> xPaths = (List<String>) xPathExpression;
                    List<String> values = (List<String>) value;
                    if (values != null && xPaths != null) {
                        int max = xPaths.size();
                        if (values.size() < xPaths.size()) {
                            max = values.size();
                        }
                        for (int i = 0; i < max; i++) {
                            doc = setXPathValue(values.get(i), xPaths.get(i), doc, attribute);
                        }
                    }
                }

            } catch (XPathExpressionException e) {
                Utils.logError(LOG, e.getMessage());
            }
        }

        return doc;
    }

    /**
     * Sets a value in a node of an XML template
     * @param value Value to set
     * @param xPathExpression XPath of the node to set
     * @param template Path to the XML document
     * @param attribute Attribute to set (if it is null, the method set the text content of the node)
     * @return The Document or Node modified
     */
    private static Object setXPathValue(String value, String xPathExpression, Object doc, String attribute)
            throws XPathExpressionException {
        Node node = getXPathNode(xPathExpression, doc);
        if (node != null) {
            if (Utils.isEmpty(attribute))
                node.setTextContent(value);
            else {
                NamedNodeMap attrs = node.getAttributes();
                Attr attr = (Attr) attrs.getNamedItem(attribute);
                attr.setValue(value);
            }
        }
        return doc;
    }

    /**
     * Returns a node of a Document or Node
     * @param xPathExpression XPath of the element to return
     * @param doc Document (or Node) to parse
     * @return The Node found
     * @throws XPathExpressionException If it is not a valid XPath expression
     */
    private static Node getXPathNode(String xPathExpression, Object doc) throws XPathExpressionException {
        XPath xpath = XPathFactory.newInstance().newXPath();
        Node node = (Node) xpath.compile(xPathExpression).evaluate(doc, XPathConstants.NODE);
        return node;
    }

    /**
     * Transform an XML template into a Document (DOM)
     * @param template Path to the XML document
     * @return
     */
    private static Document getDocumentFromTemplate(String template) {
        DocumentBuilder dBuilder;
        Document doc = null;
        try {
            dBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            doc = dBuilder.parse(OdesManifestParser.class.getResourceAsStream(template));
        } catch (ParserConfigurationException e) {
            Utils.logError(LOG, e.getMessage());
        } catch (SAXException e) {
            Utils.logError(LOG, e.getMessage());
        } catch (IOException e) {
            Utils.logError(LOG, e.getMessage());
        }

        return doc;
    }

    /**
     * Transform a DOM element into an XML String
     * @param doc Document or Node to transform
     * @return XML String representation of the document
     */
    private static String getStringFromDoc(Object doc) {
        try {
            DOMSource domSource = new DOMSource((Node) doc);
            StringWriter writer = new StringWriter();
            StreamResult result = new StreamResult(writer);
            TransformerFactory tf = TransformerFactory.newInstance();
            Transformer transformer = tf.newTransformer();
            transformer.transform(domSource, result);
            writer.flush();
            return writer.toString();
        } catch (TransformerException e) {
            Utils.logError(LOG, e.getMessage());
            return null;
        }
    }

}
