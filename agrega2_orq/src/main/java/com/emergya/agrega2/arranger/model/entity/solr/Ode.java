package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.ArrayList;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.ContentFile;

/**
 * This class defines a {@link SolrDocumentType} ODE {@link SolrDocumentA2}
 */
public class Ode extends LearningObject {

    /**
     * 
     */
    private static final long serialVersionUID = 4847973018843914965L;

    @Field
    private String generatedId;

    @Field
    private List<String> generalIdentifier;

    @Field
    private String mecIdentifier;

    @Field
    private List<String> technicalFormat;

    @Field
    private String technicalSize;

    // Format: TYPE#NAME
    @Field
    private List<String> technicalRequirementTypeName;

    @Field
    private String technicalInstallationRemarks;

    @Field
    private List<String> technicalOtherPlatformRequirements;

    @Field
    private List<String> educationalLanguage;

    @Field
    private List<String> educationalCognitiveProcess;

    @Field
    private String rightsAccessDescription;

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

    /**
     * Table of contents (from IMSMANIFEST, not from LOM-ES)
     */
    private List<ContentFile> contentTable;

    @Field
    private List<String> generalCoverage;

    @Field
    private String generalStructure;

    @Field
    private List<String> lifeCycleVersion;

    @Field
    private String lifeCycleStatus;

    // Format: TYPE#NAME#MIN VERSION#MAX VERSION
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

    // Format: ENTITY#DESCRIPTION#DATE
    @Field
    private List<String> annotationEntityDescriptionDate;

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
    private List<String> knowledgeArea;

    @Field
    private List<String> learningContext;

    @Field
    private List<String> resourceType;

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
        final StringBuilder sb = new StringBuilder();
        for (String s : generalIdentifier) {
            sb.append(s);
        }
        return Utils.generateID(getType().name() + sb.toString());
    }

    public String getGeneratedId() {
        return generatedId;
    }

    public void setGeneratedId(String generatedId) {
        this.generatedId = generatedId;
    }

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

    public String getRightsAccessDescription() {
        return rightsAccessDescription;
    }

    public void setRightsAccessDescription(String rightsAccessDescription) {
        this.rightsAccessDescription = rightsAccessDescription;
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

    public List<String> getTitleLinks() {
        return titleLinks;
    }

    public void setTitleLinks(List<String> titleLinks) {
        this.titleLinks = titleLinks;
    }

    public List<ContentFile> getContentTable() {
        return contentTable;
    }

    public void setContentTable(List<ContentFile> contentTable) {
        this.contentTable = contentTable;
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

    public List<String> getKnowledgeArea() {
        return knowledgeArea;
    }

    public void setKnowledgeArea(List<String> knowledgeArea) {
        this.knowledgeArea = knowledgeArea;
    }

    public void addKnowledgeArea(final String area) {
        if (this.getKnowledgeArea() == null) {
            this.setKnowledgeArea(new ArrayList<String>());
        }
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
        if (this.getLearningContext() == null) {
            this.setLearningContext(new ArrayList<String>());
        }
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

    public void setResourceType(List<String> resourceType) {
        this.resourceType = resourceType;
    }

    public void addResourceType(final String resourceType) {
        if (this.getResourceType() == null) {
            this.setResourceType(new ArrayList<String>());
        }
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

    public String getOdeNode() {
        return odeNode;
    }

    public void setOdeNode(String odeNode) {
        this.odeNode = odeNode;
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
