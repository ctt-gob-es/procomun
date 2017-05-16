package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import javax.xml.bind.annotation.XmlElement;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.Utils;

/**
 * This class defines a {@link SolrDocumentType} ODE {@link SolrDocumentA2}
 */
public class Ode extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = 4847973018843914965L;

    @Field
    private String generatedId;

    @Field
    private List<String> author;

    @Field
    private Date publicationDate;

    @Field
    private List<String> generalIdentifier;

    @Field
    private String mecIdentifier;

    @Field
    private String generalTitle;

    @Field
    private List<String> generalKeyword;

    @Field
    private List<String> generalDescription;

    @Field
    private List<String> generalLanguage;

    @Field
    private String generalAggregationLevel;

    @Field
    private List<String> technicalFormat;

    @Field
    private String technicalSize;

    // TODO: Format: TYPE#NAME
    @Field
    private List<String> technicalRequirementTypeName;

    @Field
    private String technicalInstallationRemarks;

    @Field
    private List<String> technicalOtherPlatformRequirements;

    // TODO: Format: ROLE#USER#DATE#DESCRIPTION
    @Field
    private List<String> lifecycleContribute;

    @Field
    private List<String> educationalLearningResourceType;

    @Field
    private List<String> educationalIntendedEndUserRole;

    @Field
    private List<String> educationalContext;

    @Field
    private List<String> educationalDescription;

    @Field
    private List<String> educationalLanguage;

    @Field
    private List<String> educationalCognitiveProcess;

    @Field
    private String rightsCopyrightAndOtherRestrictions;

    @Field
    private String rightsAccess;

    @Field
    private String rightsAccessDescription;

    @Field
    private List<String> classificationEducationalLevel1;

    @Field
    private List<String> classificationEducationalLevel2;

    @Field
    private List<String> classificationEducationalLevel3;

    @Field
    private List<String> classificationEducationalLevel4;

    @Field
    private List<String> classificationEducationalLevel5;

    @Field
    private List<String> classificationEducationalLevel6;

    @Field
    private List<String> classificationDiscipline1;

    @Field
    private List<String> classificationDiscipline2;

    @Field
    private List<String> classificationDiscipline3;

    @Field
    private List<String> classificationDiscipline4;

    @Field
    private List<String> classificationDiscipline5;

    @Field
    private List<String> classificationDiscipline6;

    @Field
    private List<String> classificationCompetency1;

    @Field
    private List<String> classificationCompetency2;

    @Field
    private List<String> classificationAccessibility1;

    @Field
    private List<String> classificationAccessibility2;

    @Field
    private List<String> classificationAccessibility3;

    @Field
    private List<String> classificationAccessibility4;

    @Field
    private List<String> titleLinks;

    @Field
    private List<String> generalCoverage;

    @Field
    private String generalStructure;

    @Field
    private List<String> lifeCycleVersion;

    @Field
    private String lifeCycleStatus;

    // TODO: Format: TYPE#NAME#MIN VERSION#MAX VERSION
    @Field
    private List<String> technicalRequirementTypeNameMinMax;

    @Field
    private List<String> technicalLocation;

    @Field
    private List<String> technicalDurationDescription;

    @Field
    private String technicalDuration;

    @Field
    private List<String> educationalInteractivityLevel;

    @Field
    private List<String> educationalInteractivityType;

    @Field
    private List<String> educationalSemanticDensity;

    @Field
    private List<String> educationalTypicalAgeRange;

    @Field
    private List<String> educationalDifficulty;

    @Field
    private List<String> educationalTypicalLearningTimeDescription;

    @Field
    private List<String> educationalTypicalLearningTime;

    @Field
    private String rightsCost;

    @Field
    private List<String> rightsDescription;

    @Field
    private List<String> relationIdentifierKind;

    // TODO: Format: ENTITY#DESCRIPTION#DATE
    @Field
    private List<String> annotationEntityDescriptionDate;

    // TODO: Format: SOURCE#LEVEL1#LEVEL2#...#LEVELN
    @Field
    private List<String> classificationEducationalLevel;
    @Field
    private List<String> classificationDiscipline;
    @Field
    private List<String> classificationCompetency;
    @Field
    private List<String> classificationAccessibility;

    @Field
    private List<String> classificationEducationalLevel1Label;

    @Field
    private List<String> classificationEducationalLevel2Label;

    @Field
    private List<String> classificationEducationalLevel3Label;

    @Field
    private List<String> classificationEducationalLevel4Label;

    @Field
    private List<String> classificationEducationalLevel5Label;

    @Field
    private List<String> classificationEducationalLevel6Label;

    @Field
    private List<String> classificationDiscipline1Label;

    @Field
    private List<String> classificationDiscipline2Label;

    @Field
    private List<String> classificationDiscipline3Label;

    @Field
    private List<String> classificationDiscipline4Label;

    @Field
    private List<String> classificationDiscipline5Label;

    @Field
    private List<String> classificationDiscipline6Label;

    @Field
    private List<String> classificationCompetency1Label;

    @Field
    private List<String> classificationCompetency2Label;

    @Field
    private List<String> classificationAccessibility1Label;

    @Field
    private List<String> classificationAccessibility2Label;

    @Field
    private List<String> classificationAccessibility3Label;

    @Field
    private List<String> classificationAccessibility4Label;

    // New Catalog fields

    @Field
    private List<String> knowledgeArea = new ArrayList<String>();

    @Field
    private List<String> learningContext = new ArrayList<String>();

    @Field
    private List<String> resourceType = new ArrayList<String>();

    // URI to preview
    @Field
    private String preview;

    @Field
    private String odeNode = new String();

    @Field
    private String publicator;

    @Field
    private String publicatorName;

    @Field
    private String publicatorEmail;

    public Ode() {
        super(SolrDocumentType.ODE);
    }

    public String generateId() {
        return Utils.generateID();
    }

    public String generateIdentifiersId() {
        final StringBuilder sb = new StringBuilder();
        for (String s : generalIdentifier) {
            sb.append(s);
        }
        return Utils.MD5(getType().name() + sb.toString());
    }

    public String getGeneratedId() {
        return generatedId;
    }

    public void setGeneratedId(String generatedId) {
        this.generatedId = generatedId;
    }

    public List<String> getAuthor() {
        return author;
    }

    public void setAuthor(List<String> author) {
        this.author = author;
    }

    @XmlElement(required = true, nillable = false)
    public List<String> getGeneralIdentifier() {
        return generalIdentifier;
    }

    public void setGeneralIdentifier(List<String> generalIdentifier) {
        this.generalIdentifier = generalIdentifier;
    }

    public String getMecIdentifier() {
        return mecIdentifier;
    }

    public void setMecIdentifier(String mecIdentifier) {
        this.mecIdentifier = mecIdentifier;
    }

    public String getGeneralTitle() {
        return generalTitle;
    }

    public void setGeneralTitle(String generalTitle) {
        this.generalTitle = generalTitle;
    }

    @XmlElement(required = true, nillable = false)
    public List<String> getGeneralKeyword() {
        return generalKeyword;
    }

    public void setGeneralKeyword(List<String> generalKeyword) {
        this.generalKeyword = generalKeyword;
    }

    public List<String> getGeneralDescription() {
        return generalDescription;
    }

    public void setGeneralDescription(List<String> generalDescription) {
        this.generalDescription = generalDescription;
    }

    @XmlElement(required = true, nillable = false)
    public List<String> getGeneralLanguage() {
        return generalLanguage;
    }

    public void setGeneralLanguage(List<String> generalLanguage) {
        this.generalLanguage = generalLanguage;
    }

    @XmlElement(required = true, nillable = false)
    public String getGeneralAggregationLevel() {
        return generalAggregationLevel;
    }

    public void setGeneralAggregationLevel(String generalAggregationLevel) {
        this.generalAggregationLevel = generalAggregationLevel;
    }

    public List<String> getLifecycleContribute() {
        return lifecycleContribute;
    }

    public void setLifecycleContribute(List<String> lifecycleContribute) {
        this.lifecycleContribute = lifecycleContribute;
    }

    @XmlElement(required = true, nillable = false)
    public List<String> getEducationalLearningResourceType() {
        return educationalLearningResourceType;
    }

    public void setEducationalLearningResourceType(List<String> educationalLearningResourceType) {
        this.educationalLearningResourceType = educationalLearningResourceType;
    }

    public List<String> getEducationalIntendedEndUserRole() {
        return educationalIntendedEndUserRole;
    }

    public void setEducationalIntendedEndUserRole(List<String> educationalIntendedEndUserRole) {
        this.educationalIntendedEndUserRole = educationalIntendedEndUserRole;
    }

    public List<String> getEducationalContext() {
        return educationalContext;
    }

    public void setEducationalContext(List<String> educationalContext) {
        this.educationalContext = educationalContext;
    }

    public List<String> getEducationalDescription() {
        return educationalDescription;
    }

    public void setEducationalDescription(List<String> educationalDescription) {
        this.educationalDescription = educationalDescription;
    }

    @XmlElement(required = true, nillable = false)
    public List<String> getEducationalLanguage() {
        return educationalLanguage;
    }

    public void setEducationalLanguage(List<String> educationalLanguage) {
        this.educationalLanguage = educationalLanguage;
    }

    public List<String> getEducationalCognitiveProcess() {
        return educationalCognitiveProcess;
    }

    public void setEducationalCognitiveProcess(List<String> educationalCognitiveProcess) {
        this.educationalCognitiveProcess = educationalCognitiveProcess;
    }

    public List<String> getTechnicalFormat() {
        return technicalFormat;
    }

    public void setTechnicalFormat(List<String> technicalFormat) {
        this.technicalFormat = technicalFormat;
    }

    public String getTechnicalSize() {
        return technicalSize;
    }

    public void setTechnicalSize(String technicalSize) {
        this.technicalSize = technicalSize;
    }

    public List<String> getTechnicalRequirementTypeName() {
        return technicalRequirementTypeName;
    }

    public void setTechnicalRequirementTypeName(List<String> technicalRequirementTypeName) {
        this.technicalRequirementTypeName = technicalRequirementTypeName;
    }

    public String getTechnicalInstallationRemarks() {
        return technicalInstallationRemarks;
    }

    public void setTechnicalInstallationRemarks(String technicalInstallationRemarks) {
        this.technicalInstallationRemarks = technicalInstallationRemarks;
    }

    public List<String> getTechnicalOtherPlatformRequirements() {
        return technicalOtherPlatformRequirements;
    }

    public void setTechnicalOtherPlatformRequirements(List<String> technicalOtherPlatformRequirements) {
        this.technicalOtherPlatformRequirements = technicalOtherPlatformRequirements;
    }

    @XmlElement(required = true, nillable = false)
    public String getRightsCopyrightAndOtherRestrictions() {
        return rightsCopyrightAndOtherRestrictions;
    }

    public void setRightsCopyrightAndOtherRestrictions(String rightsCopyrightAndOtherRestrictions) {
        this.rightsCopyrightAndOtherRestrictions = rightsCopyrightAndOtherRestrictions;
    }

    @XmlElement(required = true, nillable = false)
    public String getRightsAccess() {
        return rightsAccess;
    }

    public void setRightsAccess(String rightsAccess) {
        this.rightsAccess = rightsAccess;
    }

    public String getRightsAccessDescription() {
        return rightsAccessDescription;
    }

    public void setRightsAccessDescription(String rightsAccessDescription) {
        this.rightsAccessDescription = rightsAccessDescription;
    }

    public List<String> getClassificationEducationalLevel1() {
        return classificationEducationalLevel1;
    }

    public void setClassificationEducationalLevel1(List<String> classificationEducationalLevel1) {
        this.classificationEducationalLevel1 = classificationEducationalLevel1;
    }

    public List<String> getClassificationEducationalLevel2() {
        return classificationEducationalLevel2;
    }

    public void setClassificationEducationalLevel2(List<String> classificationEducationalLevel2) {
        this.classificationEducationalLevel2 = classificationEducationalLevel2;
    }

    public List<String> getClassificationEducationalLevel3() {
        return classificationEducationalLevel3;
    }

    public void setClassificationEducationalLevel3(List<String> classificationEducationalLevel3) {
        this.classificationEducationalLevel3 = classificationEducationalLevel3;
    }

    public List<String> getClassificationEducationalLevel4() {
        return classificationEducationalLevel4;
    }

    public void setClassificationEducationalLevel4(List<String> classificationEducationalLevel4) {
        this.classificationEducationalLevel4 = classificationEducationalLevel4;
    }

    public List<String> getClassificationEducationalLevel5() {
        return classificationEducationalLevel5;
    }

    public void setClassificationEducationalLevel5(List<String> classificationEducationalLevel5) {
        this.classificationEducationalLevel5 = classificationEducationalLevel5;
    }

    public List<String> getClassificationEducationalLevel6() {
        return classificationEducationalLevel6;
    }

    public void setClassificationEducationalLevel6(List<String> classificationEducationalLevel6) {
        this.classificationEducationalLevel6 = classificationEducationalLevel6;
    }

    public List<String> getClassificationDiscipline1() {
        return classificationDiscipline1;
    }

    public void setClassificationDiscipline1(List<String> classificationDiscipline1) {
        this.classificationDiscipline1 = classificationDiscipline1;
    }

    public List<String> getClassificationDiscipline2() {
        return classificationDiscipline2;
    }

    public void setClassificationDiscipline2(List<String> classificationDiscipline2) {
        this.classificationDiscipline2 = classificationDiscipline2;
    }

    public List<String> getClassificationDiscipline3() {
        return classificationDiscipline3;
    }

    public void setClassificationDiscipline3(List<String> classificationDiscipline3) {
        this.classificationDiscipline3 = classificationDiscipline3;
    }

    public List<String> getClassificationDiscipline4() {
        return classificationDiscipline4;
    }

    public void setClassificationDiscipline4(List<String> classificationDiscipline4) {
        this.classificationDiscipline4 = classificationDiscipline4;
    }

    public List<String> getClassificationDiscipline5() {
        return classificationDiscipline5;
    }

    public void setClassificationDiscipline5(List<String> classificationDiscipline5) {
        this.classificationDiscipline5 = classificationDiscipline5;
    }

    public List<String> getClassificationDiscipline6() {
        return classificationDiscipline6;
    }

    public void setClassificationDiscipline6(List<String> classificationDiscipline6) {
        this.classificationDiscipline6 = classificationDiscipline6;
    }

    public List<String> getClassificationCompetency1() {
        return classificationCompetency1;
    }

    public void setClassificationCompetency1(List<String> classificationCompetency1) {
        this.classificationCompetency1 = classificationCompetency1;
    }

    public List<String> getClassificationCompetency2() {
        return classificationCompetency2;
    }

    public void setClassificationCompetency2(List<String> classificationCompetency2) {
        this.classificationCompetency2 = classificationCompetency2;
    }

    public Date getPublicationDate() {
        return publicationDate;
    }

    public void setPublicationDate(Date publicationDate) {
        this.publicationDate = publicationDate;
    }

    public List<String> getTitleLinks() {
        return titleLinks;
    }

    public void setTitleLinks(List<String> titleLinks) {
        this.titleLinks = titleLinks;
    }

    public List<String> getGeneralCoverage() {
        return generalCoverage;
    }

    public void setGeneralCoverage(List<String> generalCoverage) {
        this.generalCoverage = generalCoverage;
    }

    public String getGeneralStructure() {
        return generalStructure;
    }

    public void setGeneralStructure(String generalStructure) {
        this.generalStructure = generalStructure;
    }

    public List<String> getLifeCycleVersion() {
        return lifeCycleVersion;
    }

    public void setLifeCycleVersion(List<String> lifeCycleVersion) {
        this.lifeCycleVersion = lifeCycleVersion;
    }

    public String getLifeCycleStatus() {
        return lifeCycleStatus;
    }

    public void setLifeCycleStatus(String lifeCycleStatus) {
        this.lifeCycleStatus = lifeCycleStatus;
    }

    public List<String> getTechnicalRequirementTypeNameMinMax() {
        return technicalRequirementTypeNameMinMax;
    }

    public void setTechnicalRequirementTypeNameMinMax(List<String> technicalRequirementTypeNameMinMax) {
        this.technicalRequirementTypeNameMinMax = technicalRequirementTypeNameMinMax;
    }

    public List<String> getTechnicalLocation() {
        return technicalLocation;
    }

    public void setTechnicalLocation(List<String> technicalLocation) {
        this.technicalLocation = technicalLocation;
    }

    public List<String> getTechnicalDurationDescription() {
        return technicalDurationDescription;
    }

    public void setTechnicalDurationDescription(List<String> technicalDurationDescription) {
        this.technicalDurationDescription = technicalDurationDescription;
    }

    public String getTechnicalDuration() {
        return technicalDuration;
    }

    public void setTechnicalDuration(String technicalDuration) {
        this.technicalDuration = technicalDuration;
    }

    public List<String> getEducationalInteractivityLevel() {
        return educationalInteractivityLevel;
    }

    public void setEducationalInteractivityLevel(List<String> educationalInteractivityLevel) {
        this.educationalInteractivityLevel = educationalInteractivityLevel;
    }

    public List<String> getEducationalInteractivityType() {
        return educationalInteractivityType;
    }

    public void setEducationalInteractivityType(List<String> educationalInteractivityType) {
        this.educationalInteractivityType = educationalInteractivityType;
    }

    public List<String> getEducationalSemanticDensity() {
        return educationalSemanticDensity;
    }

    public void setEducationalSemanticDensity(List<String> educationalSemanticDensity) {
        this.educationalSemanticDensity = educationalSemanticDensity;
    }

    public List<String> getEducationalTypicalAgeRange() {
        return educationalTypicalAgeRange;
    }

    public void setEducationalTypicalAgeRange(List<String> educationalTypicalAgeRange) {
        this.educationalTypicalAgeRange = educationalTypicalAgeRange;
    }

    public List<String> getEducationalDifficulty() {
        return educationalDifficulty;
    }

    public void setEducationalDifficulty(List<String> educationalDifficulty) {
        this.educationalDifficulty = educationalDifficulty;
    }

    public List<String> getEducationalTypicalLearningTimeDescription() {
        return educationalTypicalLearningTimeDescription;
    }

    public void setEducationalTypicalLearningTimeDescription(List<String> educationalTypicalLearningTimeDescription) {
        this.educationalTypicalLearningTimeDescription = educationalTypicalLearningTimeDescription;
    }

    public List<String> getEducationalTypicalLearningTime() {
        return educationalTypicalLearningTime;
    }

    public void setEducationalTypicalLearningTime(List<String> educationalTypicalLearningTime) {
        this.educationalTypicalLearningTime = educationalTypicalLearningTime;
    }

    public String getRightsCost() {
        return rightsCost;
    }

    public void setRightsCost(String rightsCost) {
        this.rightsCost = rightsCost;
    }

    public List<String> getRightsDescription() {
        return rightsDescription;
    }

    public void setRightsDescription(List<String> rightsDescription) {
        this.rightsDescription = rightsDescription;
    }

    public List<String> getRelationIdentifierKind() {
        return relationIdentifierKind;
    }

    public void setRelationIdentifierKind(List<String> relationIdentifierKind) {
        this.relationIdentifierKind = relationIdentifierKind;
    }

    public List<String> getAnnotationEntityDescriptionDate() {
        return annotationEntityDescriptionDate;
    }

    public void setAnnotationEntityDescriptionDate(List<String> annotationEntityDescriptionDate) {
        this.annotationEntityDescriptionDate = annotationEntityDescriptionDate;
    }

    public List<String> getClassificationEducationalLevel() {
        return classificationEducationalLevel;
    }

    public void setClassificationEducationalLevel(List<String> classificationEducationalLevel) {
        this.classificationEducationalLevel = classificationEducationalLevel;
    }

    public List<String> getClassificationDiscipline() {
        return classificationDiscipline;
    }

    public void setClassificationDiscipline(List<String> classificationDiscipline) {
        this.classificationDiscipline = classificationDiscipline;
    }

    public List<String> getClassificationCompetency() {
        return classificationCompetency;
    }

    public void setClassificationCompetency(List<String> classificationCompetency) {
        this.classificationCompetency = classificationCompetency;
    }

    public List<String> getClassificationAccessibility() {
        return classificationAccessibility;
    }

    public void setClassificationAccessibility(List<String> classificationAccessibility) {
        this.classificationAccessibility = classificationAccessibility;
    }

    public List<String> getClassificationEducationalLevel1Label() {
        return classificationEducationalLevel1Label;
    }

    public void setClassificationEducationalLevel1Label(List<String> classificationEducationalLevel1Label) {
        this.classificationEducationalLevel1Label = classificationEducationalLevel1Label;
    }

    public List<String> getClassificationEducationalLevel2Label() {
        return classificationEducationalLevel2Label;
    }

    public void setClassificationEducationalLevel2Label(List<String> classificationEducationalLevel2Label) {
        this.classificationEducationalLevel2Label = classificationEducationalLevel2Label;
    }

    public List<String> getClassificationEducationalLevel3Label() {
        return classificationEducationalLevel3Label;
    }

    public void setClassificationEducationalLevel3Label(List<String> classificationEducationalLevel3Label) {
        this.classificationEducationalLevel3Label = classificationEducationalLevel3Label;
    }

    public List<String> getClassificationEducationalLevel4Label() {
        return classificationEducationalLevel4Label;
    }

    public void setClassificationEducationalLevel4Label(List<String> classificationEducationalLevel4Label) {
        this.classificationEducationalLevel4Label = classificationEducationalLevel4Label;
    }

    public List<String> getClassificationEducationalLevel5Label() {
        return classificationEducationalLevel5Label;
    }

    public void setClassificationEducationalLevel5Label(List<String> classificationEducationalLevel5Label) {
        this.classificationEducationalLevel5Label = classificationEducationalLevel5Label;
    }

    public List<String> getClassificationEducationalLevel6Label() {
        return classificationEducationalLevel6Label;
    }

    public void setClassificationEducationalLevel6Label(List<String> classificationEducationalLevel6Label) {
        this.classificationEducationalLevel6Label = classificationEducationalLevel6Label;
    }

    public List<String> getClassificationDiscipline1Label() {
        return classificationDiscipline1Label;
    }

    public void setClassificationDiscipline1Label(List<String> classificationDiscipline1Label) {
        this.classificationDiscipline1Label = classificationDiscipline1Label;
    }

    public List<String> getClassificationDiscipline2Label() {
        return classificationDiscipline2Label;
    }

    public void setClassificationDiscipline2Label(List<String> classificationDiscipline2Label) {
        this.classificationDiscipline2Label = classificationDiscipline2Label;
    }

    public List<String> getClassificationDiscipline3Label() {
        return classificationDiscipline3Label;
    }

    public void setClassificationDiscipline3Label(List<String> classificationDiscipline3Label) {
        this.classificationDiscipline3Label = classificationDiscipline3Label;
    }

    public List<String> getClassificationDiscipline4Label() {
        return classificationDiscipline4Label;
    }

    public void setClassificationDiscipline4Label(List<String> classificationDiscipline4Label) {
        this.classificationDiscipline4Label = classificationDiscipline4Label;
    }

    public List<String> getClassificationDiscipline5Label() {
        return classificationDiscipline5Label;
    }

    public void setClassificationDiscipline5Label(List<String> classificationDiscipline5Label) {
        this.classificationDiscipline5Label = classificationDiscipline5Label;
    }

    public List<String> getClassificationDiscipline6Label() {
        return classificationDiscipline6Label;
    }

    public void setClassificationDiscipline6Label(List<String> classificationDiscipline6Label) {
        this.classificationDiscipline6Label = classificationDiscipline6Label;
    }

    public List<String> getClassificationCompetency1Label() {
        return classificationCompetency1Label;
    }

    public void setClassificationCompetency1Label(List<String> classificationCompetency1Label) {
        this.classificationCompetency1Label = classificationCompetency1Label;
    }

    public List<String> getClassificationCompetency2Label() {
        return classificationCompetency2Label;
    }

    public void setClassificationCompetency2Label(List<String> classificationCompetency2Label) {
        this.classificationCompetency2Label = classificationCompetency2Label;
    }

    public List<String> getClassificationAccessibility1() {
        return classificationAccessibility1;
    }

    public void setClassificationAccessibility1(List<String> classificationAccessibility1) {
        this.classificationAccessibility1 = classificationAccessibility1;
    }

    public List<String> getClassificationAccessibility2() {
        return classificationAccessibility2;
    }

    public void setClassificationAccessibility2(List<String> classificationAccessibility2) {
        this.classificationAccessibility2 = classificationAccessibility2;
    }

    public List<String> getClassificationAccessibility3() {
        return classificationAccessibility3;
    }

    public void setClassificationAccessibility3(List<String> classificationAccessibility3) {
        this.classificationAccessibility3 = classificationAccessibility3;
    }

    public List<String> getClassificationAccessibility4() {
        return classificationAccessibility4;
    }

    public void setClassificationAccessibility4(List<String> classificationAccessibility4) {
        this.classificationAccessibility4 = classificationAccessibility4;
    }

    public List<String> getClassificationAccessibility1Label() {
        return classificationAccessibility1Label;
    }

    public void setClassificationAccessibility1Label(List<String> classificationAccessibility1Label) {
        this.classificationAccessibility1Label = classificationAccessibility1Label;
    }

    public List<String> getClassificationAccessibility2Label() {
        return classificationAccessibility2Label;
    }

    public void setClassificationAccessibility2Label(List<String> classificationAccessibility2Label) {
        this.classificationAccessibility2Label = classificationAccessibility2Label;
    }

    public List<String> getClassificationAccessibility3Label() {
        return classificationAccessibility3Label;
    }

    public void setClassificationAccessibility3Label(List<String> classificationAccessibility3Label) {
        this.classificationAccessibility3Label = classificationAccessibility3Label;
    }

    public List<String> getClassificationAccessibility4Label() {
        return classificationAccessibility4Label;
    }

    public void setClassificationAccessibility4Label(List<String> classificationAccessibility4Label) {
        this.classificationAccessibility4Label = classificationAccessibility4Label;
    }

    public String getPreview() {
        return preview;
    }

    public void setPreview(String preview) {
        this.preview = preview;
    }

    public String getOdeNode() {
        return odeNode;
    }

    public void setOdeNode(String odeNode) {
        this.odeNode = odeNode;
    }

    public List<String> getKnowledgeArea() {
        return knowledgeArea;
    }

    public void setKnowledgeArea(List<String> knowledgeArea) {
        this.knowledgeArea = knowledgeArea;
    }

    public void addKnowledgeArea(final String area) {
        if (!this.knowledgeArea.contains(area)) {
            this.knowledgeArea.add(area);
        }
    }

    public void addKnowledgeAreas(final List<String> areas) {
        if (areas != null) {
            for (String area : areas) {
                addKnowledgeArea(area);
            }
        }
    }

    public List<String> getLearningContext() {
        return learningContext;
    }

    public void setLearningContext(List<String> learningContext) {
        this.learningContext = learningContext;
    }

    public void addLearningContext(final String context) {
        if (!this.learningContext.contains(context)) {
            this.learningContext.add(context);
        }
    }

    public void addLearningContexts(final List<String> contexts) {
        if (contexts != null) {
            for (String context : contexts) {
                addLearningContext(context);
            }
        }
    }

    public List<String> getResourceType() {
        return resourceType;
    }

    public void addResourceType(final String resourceType) {
        if (!this.resourceType.contains(resourceType)) {
            this.resourceType.add(resourceType);
        }
    }

    public void addResourceTypes(final List<String> resourceTypes) {
        if (resourceTypes != null) {
            for (String resourceType : resourceTypes) {
                addResourceType(resourceType);
            }
        }
    }

    public String getPublicator() {
        return publicator;
    }

    public void setPublicator(String publicator) {
        this.publicator = publicator;
    }

    public String getPublicatorName() {
        return publicatorName;
    }

    public void setPublicatorName(String publicatorName) {
        this.publicatorName = publicatorName;
    }

    public String getPublicatorEmail() {
        return publicatorEmail;
    }

    public void setPublicatorEmail(String publicatorEmail) {
        this.publicatorEmail = publicatorEmail;
    }

}
