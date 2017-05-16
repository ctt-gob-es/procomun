package com.emergya.agrega2.arranger.model.entity.solr;

import java.util.ArrayList;
import java.util.List;

import org.apache.solr.client.solrj.beans.Field;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;
import com.emergya.agrega2.arranger.util.impl.Utils;

public abstract class LearningObject extends SolrDocumentA2 {

    /**
     * 
     */
    private static final long serialVersionUID = 669935978110466315L;

    @Field
    private List<String> author;

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
    private String rightsCopyrightAndOtherRestrictions;

    @Field
    private String rightsAccess;

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

    public LearningObject() {
        super();
    }

    public LearningObject(SolrDocumentType type) {
        super(type);
    }

    public abstract String generateId();

    public List<String> getAuthor() {
        return author;
    }

    public void setAuthor(List<String> author) {
        this.author = author;
    }

    public String getGeneralTitle() {
        return generalTitle;
    }

    public void setGeneralTitle(String generalTitle) {
        this.generalTitle = generalTitle;
    }

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

    public List<String> getGeneralLanguage() {
        return generalLanguage;
    }

    public void setGeneralLanguage(List<String> generalLanguage) {
        this.generalLanguage = generalLanguage;
    }

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

    public String getRightsCopyrightAndOtherRestrictions() {
        return rightsCopyrightAndOtherRestrictions;
    }

    public void setRightsCopyrightAndOtherRestrictions(String rightsCopyrightAndOtherRestrictions) {
        this.rightsCopyrightAndOtherRestrictions = rightsCopyrightAndOtherRestrictions;
    }

    public String getRightsAccess() {
        return rightsAccess;
    }

    public void setRightsAccess(String rightsAccess) {
        this.rightsAccess = rightsAccess;
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

    /**
     * Fills the classification*Label fields from their Drupal ids, only if Label lists are empty
     */
    public void fillClassificationLabels() {
        /* Educational Level */
        if (!Utils.isEmpty(this.classificationEducationalLevel1) && Utils.isEmpty(this.classificationEducationalLevel1Label)) {
            List<String> edLevelLabel = new ArrayList<String>();
            for (String edL : this.classificationEducationalLevel1) {
                String level = Utils.getNivelEducativoLabel().get(Utils.getNivelEducativoRev().get(edL));
                edLevelLabel.add(level != null ? level : "");
            }
            this.classificationEducationalLevel1Label = edLevelLabel;
        }
        if (!Utils.isEmpty(this.classificationEducationalLevel2) && Utils.isEmpty(this.classificationEducationalLevel2Label)) {
            List<String> edLevelLabel = new ArrayList<String>();
            for (String edL : this.classificationEducationalLevel2) {
                String level = Utils.getNivelEducativoLabel().get(Utils.getNivelEducativoRev().get(edL));
                edLevelLabel.add(level != null ? level : "");
            }
            this.classificationEducationalLevel2Label = edLevelLabel;
        }
        if (!Utils.isEmpty(this.classificationEducationalLevel3) && Utils.isEmpty(this.classificationEducationalLevel3Label)) {
            List<String> edLevelLabel = new ArrayList<String>();
            for (String edL : this.classificationEducationalLevel3) {
                String level = Utils.getNivelEducativoLabel().get(Utils.getNivelEducativoRev().get(edL));
                edLevelLabel.add(level != null ? level : "");
            }
            this.classificationEducationalLevel3Label = edLevelLabel;
        }
        if (!Utils.isEmpty(this.classificationEducationalLevel4) && Utils.isEmpty(this.classificationEducationalLevel4Label)) {
            List<String> edLevelLabel = new ArrayList<String>();
            for (String edL : this.classificationEducationalLevel4) {
                String level = Utils.getNivelEducativoLabel().get(Utils.getNivelEducativoRev().get(edL));
                edLevelLabel.add(level != null ? level : "");
            }
            this.classificationEducationalLevel4Label = edLevelLabel;
        }
        if (!Utils.isEmpty(this.classificationEducationalLevel5) && Utils.isEmpty(this.classificationEducationalLevel5Label)) {
            List<String> edLevelLabel = new ArrayList<String>();
            for (String edL : this.classificationEducationalLevel5) {
                String level = Utils.getNivelEducativoLabel().get(Utils.getNivelEducativoRev().get(edL));
                edLevelLabel.add(level != null ? level : "");
            }
            this.classificationEducationalLevel5Label = edLevelLabel;
        }
        if (!Utils.isEmpty(this.classificationEducationalLevel6) && Utils.isEmpty(this.classificationEducationalLevel6Label)) {
            List<String> edLevelLabel = new ArrayList<String>();
            for (String edL : this.classificationEducationalLevel6) {
                String level = Utils.getNivelEducativoLabel().get(Utils.getNivelEducativoRev().get(edL));
                edLevelLabel.add(level != null ? level : "");
            }
            this.classificationEducationalLevel6Label = edLevelLabel;
        }

        /* Árbol curricular - Discipline */
        if (!Utils.isEmpty(this.classificationDiscipline1) && Utils.isEmpty(this.classificationDiscipline1Label)) {
            List<String> disciplineLabel = new ArrayList<String>();
            for (String dis : this.classificationDiscipline1) {
                String level = Utils.getArbolCurricularLabel().get(Utils.getArbolCurricularRev().get(dis));
                disciplineLabel.add(level != null ? level : "");
            }
            this.classificationDiscipline1Label = disciplineLabel;
        }
        if (!Utils.isEmpty(this.classificationDiscipline2) && Utils.isEmpty(this.classificationDiscipline2Label)) {
            List<String> disciplineLabel = new ArrayList<String>();
            for (String dis : this.classificationDiscipline2) {
                String level = Utils.getArbolCurricularLabel().get(Utils.getArbolCurricularRev().get(dis));
                disciplineLabel.add(level != null ? level : "");
            }
            this.classificationDiscipline2Label = disciplineLabel;
        }
        if (!Utils.isEmpty(this.classificationDiscipline3) && Utils.isEmpty(this.classificationDiscipline3Label)) {
            List<String> disciplineLabel = new ArrayList<String>();
            for (String dis : this.classificationDiscipline3) {
                String level = Utils.getArbolCurricularLabel().get(Utils.getArbolCurricularRev().get(dis));
                disciplineLabel.add(level != null ? level : "");
            }
            this.classificationDiscipline3Label = disciplineLabel;
        }
        if (!Utils.isEmpty(this.classificationDiscipline4) && Utils.isEmpty(this.classificationDiscipline4Label)) {
            List<String> disciplineLabel = new ArrayList<String>();
            for (String dis : this.classificationDiscipline4) {
                String level = Utils.getArbolCurricularLabel().get(Utils.getArbolCurricularRev().get(dis));
                disciplineLabel.add(level != null ? level : "");
            }
            this.classificationDiscipline4Label = disciplineLabel;
        }
        if (!Utils.isEmpty(this.classificationDiscipline5) && Utils.isEmpty(this.classificationDiscipline5Label)) {
            List<String> disciplineLabel = new ArrayList<String>();
            for (String dis : this.classificationDiscipline5) {
                String level = Utils.getArbolCurricularLabel().get(Utils.getArbolCurricularRev().get(dis));
                disciplineLabel.add(level != null ? level : "");
            }
            this.classificationDiscipline5Label = disciplineLabel;
        }
        if (!Utils.isEmpty(this.classificationDiscipline6) && Utils.isEmpty(this.classificationDiscipline6Label)) {
            List<String> disciplineLabel = new ArrayList<String>();
            for (String dis : this.classificationDiscipline6) {
                String level = Utils.getArbolCurricularLabel().get(Utils.getArbolCurricularRev().get(dis));
                disciplineLabel.add(level != null ? level : "");
            }
            this.classificationDiscipline6Label = disciplineLabel;
        }

    }

}
