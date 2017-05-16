package com.emergya.agrega2.odes.util;

import java.io.File;
import java.io.FileInputStream;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Date;
import java.util.List;

import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.http.client.utils.DateUtils;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.A2File;
import com.emergya.agrega2.odes.beans.ContentFile;
import com.emergya.agrega2.odes.util.CSVUtils.LearningContext;
import com.emergya.agrega2.odes.util.CSVUtils.ResourceType;
import com.emergya.agrega2.odes.util.CSVUtils.TaxonNode;

import es.pode.parseadorXML.LomESDao;
import es.pode.parseadorXML.ParseadorException;
import es.pode.parseadorXML.SCORM2004Dao;
import es.pode.parseadorXML.castor.Classification;
import es.pode.parseadorXML.castor.Educational;
import es.pode.parseadorXML.castor.General;
import es.pode.parseadorXML.castor.Grp_any;
import es.pode.parseadorXML.castor.Item;
import es.pode.parseadorXML.castor.LifeCycle;
import es.pode.parseadorXML.castor.Lom;
import es.pode.parseadorXML.castor.Manifest;
import es.pode.parseadorXML.castor.MetaMetadata;
import es.pode.parseadorXML.castor.Metadata;
import es.pode.parseadorXML.castor.Organization;
import es.pode.parseadorXML.castor.Organizations;
import es.pode.parseadorXML.castor.Resource;
import es.pode.parseadorXML.castor.Resources;
import es.pode.parseadorXML.castor.Rights;
import es.pode.parseadorXML.castor.Technical;
import es.pode.parseadorXML.lomes.lomesAgrega.AnnotationAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.ClassificationAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.ContribucionAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.DuracionAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.EducationalAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.EntidadAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.FechaAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.GeneralAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.IdentificadorAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.LangStringAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.LifeCycleAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.LomAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.MetaMetadataAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.RelationAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.RequisitoAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.RightsAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.RutaTaxonomicaAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.TaxonAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.TechnicalAgrega;
import es.pode.parseadorXML.scorm2004.agrega.ManifestAgrega;

public class OdesMapping {
    private static final Log LOG = LogFactory.getLog(OdesMapping.class);

    private OdesMapping() {
    }

    @SuppressWarnings("unchecked")
    private static void parseGeneralInfo(LomAgrega lomAgrega, Ode ode) {
        /* GENERAL */
        GeneralAgrega general = null;
        try {
            general = lomAgrega.getGeneralAgrega();
        } catch (ParseadorException e1) {
            Utils.logError(LOG, e1, "Error obteniendo el conjunto de propiedades General del manifest");
        }

        if (general != null) {
            // Pueden venir cosas en varios idiomas
            String titulo = null;
            try {
                titulo = general.getTitulo(null);
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalTitle del manifest");
            }
            ode.setGeneralTitle(titulo);
            ode.setTitle(titulo);

            try {
                List<String> descs = general.getDescripciones();
                ode.setGeneralDescription(descs);
                if (!Utils.isEmpty(descs))
                    ode.setDescription(descs.get(0));
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalDescription del manifest");
            }

            try {
                ode.setMecIdentifier(general.obtenerIdentificadorFormatoMEC(Utils.getMessage("agrega.lomes.mec.catalog")));
                List<IdentificadorAgrega> ids = general.getIdentificadoresAv();
                List<String> idsOde = new ArrayList<String>();
                if (!Utils.isEmpty(ids)) {
                    for (IdentificadorAgrega id : ids) {
                        idsOde.add(id.getEntrada());
                    }
                }
                ode.setGeneralIdentifier(idsOde);
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalIdentifier del manifest");
            }
            try {
                ode.setGeneralAggregationLevel(general.getNivelDeAgregacion());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalAggregationLevel del manifest");
            }
            try {
                ode.setGeneralKeyword(general.getPalabrasClave());
                // ode.setLabels(general.getPalabrasClave());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalKeyword del manifest");
            }
            try {
                ode.setGeneralLanguage(general.getIdiomasAv());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalLanguage del manifest");
            }

            // Pueden venir cosas en varios idiomas
            try {
                ode.setGeneralCoverage(getListStringFromListListLangStringAgrega(general.getAmbitos()));
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalCoverage del manifest");
            }

            try {
                ode.setGeneralStructure(general.getEstructuraAv());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad generalStructure del manifest");
            }
        }
    }

    @SuppressWarnings("unchecked")
    private static void parseLifeCycleInfo(LomAgrega lomAgrega, Ode ode) {
        /* LIFECYCLE */
        List<String> lifecycleContribute = new ArrayList<String>();
        LifeCycleAgrega lifeCycle = null;
        try {
            lifeCycle = lomAgrega.getLifeCycleAgrega();
        } catch (ParseadorException e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades LifeCycle del manifest");

        }

        // TODO lifeCycle.getAutores.
        if (lifeCycle != null) {
            List<ContribucionAgrega> contribuciones = lifeCycle.getContribucionesAv();
            final ArrayList<EntidadAgrega> autores = lifeCycle.getAutores();
            List<String> autoresStr = new ArrayList<String>();
            for (EntidadAgrega entidad : autores) {
                autoresStr.add(entidad.getCorreo());
            }
            ode.setAuthor(autoresStr);
            if (!Utils.isEmpty(contribuciones)) {
                for (ContribucionAgrega contribucion : contribuciones) {
                    FechaAgrega fecha = contribucion.getFecha();
                    List<LangStringAgrega> desc = fecha.getDescripciones();
                    String descripcionFecha = "";
                    // Pueden venir cosas en varios idiomas
                    if (!Utils.isEmpty(desc)) {
                        descripcionFecha = desc.get(0).getValor();
                    }
                    String tipo = contribucion.getTipo();
                    List<EntidadAgrega> ents = contribucion.getEntidades();
                    if (!Utils.isEmpty(ents)) {
                        for (EntidadAgrega ent : ents) {
                            // Usamos el formato de VCard????
                            String user = "";
                            try {
                                user = lifeCycle.escribirVCard(ent);
                            } catch (Exception e) {
                                Utils.logError(LOG, e, "Error generando una VCard a partir de una entidad: " + e.getMessage());
                                user = ent.getCorreo();
                                if (Utils.isEmpty(user)) {
                                    user = ent.getNombre();
                                }
                            }
                            // ROLE#USER#DATE#DESCRIPTION
                            if (tipo != null && tipo.equals("publisher") && ode.getPublicationDate() == null) {
                                SimpleDateFormat sdf = new SimpleDateFormat(Utils.DEFAULT_DATE_FORMAT);
                                try {
                                    ode.setPublicationDate(sdf.parse(fecha.getFecha()));
                                } catch (ParseException e) {
                                    sdf.applyPattern("dd-MM-yyyy");
                                    try {
                                        ode.setPublicationDate(sdf.parse(fecha.getFecha()));
                                    } catch (ParseException e1) {
                                        ode.setPublicationDate(DateUtils.parseDate(fecha.getFecha()));
                                    }
                                }

                            }

                            String lifecycle = tipo + Utils.getMessage("format_separator") + user + Utils.getMessage("format_separator") + fecha.getFecha()
                                    + Utils.getMessage("format_separator") + descripcionFecha;
                            lifecycleContribute.add(lifecycle);
                        }

                    }
                }
                if (ode.getPublicationDate() == null) {
                    ode.setPublicationDate(new Date());
                }

                ode.setLifecycleContribute(lifecycleContribute);
            }

            ode.setLifeCycleVersion(getListStringFromListLangStringAgrega(lifeCycle.getVersionAv()));

            ode.setLifeCycleStatus(lifeCycle.getEstatusAv());
        }
    }

    @SuppressWarnings("unchecked")
    private static void parseTechnicalInfo(LomAgrega lomAgrega, Ode ode) {
        /* TECHNICAL */
        TechnicalAgrega technical = null;
        try {
            technical = lomAgrega.getTechnicalAgrega();
        } catch (ParseadorException e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades Technical del manifest");
        }
        if (technical != null) {
            try {
                ode.setTechnicalFormat(technical.getFormatos());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad technicalFormat del manifest");
            }
            ode.setTechnicalSize(technical.getTamañoAv());

            // Pueden venir cosas en varios idiomas
            List<LangStringAgrega> otherPlatReqs = technical.getOtrosRequisitosAv();
            if (!Utils.isEmpty(otherPlatReqs)) {
                List<String> technicalOtherPlatformRequirements = new ArrayList<String>();
                for (LangStringAgrega otherPlatReq : otherPlatReqs) {
                    technicalOtherPlatformRequirements.add(otherPlatReq.getValor());
                }
                ode.setTechnicalOtherPlatformRequirements(technicalOtherPlatformRequirements);
            }

            List<List<RequisitoAgrega>> reqs = technical.getRequisitosAv();
            if (!Utils.isEmpty(reqs)) {
                List<String> technicalRequirementTypeName = new ArrayList<String>();
                List<String> technicalRequirementTypeNameMinMax = new ArrayList<String>();
                for (List<RequisitoAgrega> reqs2 : reqs) {
                    if (!Utils.isEmpty(reqs2)) {
                        for (RequisitoAgrega req : reqs2) {
                            String reqSt = req.getTipo() + Utils.getMessage("format_separator") + req.getNombre();
                            technicalRequirementTypeName.add(reqSt);
                            reqSt = req.getTipo() + Utils.getMessage("format_separator") + req.getNombre() + Utils.getMessage("format_separator") + req.getVersionMinima()
                                    + Utils.getMessage("format_separator") + req.getVersionMaxima();
                            technicalRequirementTypeNameMinMax.add(reqSt);
                        }
                    }
                }
                ode.setTechnicalRequirementTypeName(technicalRequirementTypeName);
                ode.setTechnicalRequirementTypeNameMinMax(technicalRequirementTypeNameMinMax);
            }

            // Pueden venir cosas en varios idiomas
            List<LangStringAgrega> instRemarks = technical.getPautasDeInstalacionAv();
            if (!Utils.isEmpty(instRemarks)) {
                ode.setTechnicalInstallationRemarks(instRemarks.get(0).getValor());
            }

            ode.setTechnicalLocation(technical.getLocalizacionAv());

            ode.setTechnicalDurationDescription(getListStringFromListLangStringAgrega(technical.getDuracionAv().getDescripciones()));
            ode.setTechnicalDuration(technical.getDuracionAv().getDuracion());

        }
    }

    @SuppressWarnings("unchecked")
    private static void parseEducationalInfo(LomAgrega lomAgrega, Ode ode) {

        /* EDUCATIONAL */
        List<EducationalAgrega> educationals = null;
        try {
            educationals = lomAgrega.getEducationalsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades Educational del manifest");
        }
        if (!Utils.isEmpty(educationals)) {
            List<String> educationalLearningResourceType = new ArrayList<String>();
            List<String> educationalIntendedEndUserRole = new ArrayList<String>();
            List<String> educationalLanguage = new ArrayList<String>();
            List<String> educationalContext = new ArrayList<String>();
            List<String> educationalCognitiveProcess = new ArrayList<String>();
            List<String> educationalDescription = new ArrayList<String>();
            List<String> educationalInteractivityType = new ArrayList<String>();
            List<String> educationalInteractivityLevel = new ArrayList<String>();
            List<String> educationalSemanticDensity = new ArrayList<String>();
            List<String> educationalTypicalAgeRange = new ArrayList<String>();
            List<String> educationalDifficulty = new ArrayList<String>();
            List<String> educationalTypicalLearningTime = new ArrayList<String>();
            List<String> educationalTypicalLearningTimeDescription = new ArrayList<String>();

            for (EducationalAgrega educational : educationals) {
                try {
                    educationalLearningResourceType.addAll(educational.getTiposDeRecurso());
                    // New catalog LOM-ES Resource Type
                    for (Object tr : educational.getTiposDeRecurso()) {
                        ode.addResourceTypes(Utils.getResourceTypeLomes().get(tr));
                    }
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalLearningResouceType del manifest");
                }
                try {
                    educationalIntendedEndUserRole.addAll(educational.getDestinatarios());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalIntendedEndUserRole del manifest");
                }
                try {
                    educationalLanguage.addAll(educational.getIdiomasDestinatario());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalLanguage del manifest");
                }
                try {
                    educationalContext.addAll(educational.getContextos());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalContext del manifest");
                }
                try {
                    educationalCognitiveProcess.addAll(educational.getProcesosCognitivos());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalCognitiveProcess del manifest");
                }

                // Pueden venir cosas en varios idiomas
                try {
                    List<String> descriptions = getListStringFromListLangStringAgrega(educational.getDescripcionesAv());
                    if (!Utils.isEmpty(descriptions)) {
                        educationalDescription.addAll(descriptions);
                    }
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalDescription del manifest");
                }

                try {
                    educationalInteractivityLevel.add(educational.getNivelDeInteractividadAv());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalInteractivityLevel del manifest");
                }

                try {
                    educationalInteractivityType.add(educational.getTipoDeInteractividadAv());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalInteractivityType del manifest");
                }

                try {
                    educationalSemanticDensity.add(educational.getDensidadSemanticaAv());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalSemanticDensity del manifest");
                }

                try {
                    educationalTypicalAgeRange.addAll(educational.getRangosEdad());
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad educationalTypicalAgeRange del manifest");
                }

                educationalDifficulty.add(educational.getDificultadAv());

                try {
                    DuracionAgrega duracion = educational.getTiempoTipicoAprendizajeAv();
                    educationalTypicalLearningTime.add(duracion.getDuracion());
                    List<String> descriptions = getListStringFromListLangStringAgrega(duracion.getDescripciones());
                    if (!Utils.isEmpty(descriptions)) {
                        educationalTypicalLearningTimeDescription.addAll(descriptions);
                    }
                } catch (Exception e1) {
                    Utils.logError(LOG, e1, "Error obteniendo la propiedad educationalTypicalLearningTime del manifest");
                }

            }

            // Learning Resource Type
            ode.setEducationalLearningResourceType(educationalLearningResourceType);
            // Intended End User Role
            ode.setEducationalIntendedEndUserRole(educationalIntendedEndUserRole);
            // Language
            ode.setEducationalLanguage(educationalLanguage);
            // Context
            ode.setEducationalContext(educationalContext);
            // Cognitive Process
            ode.setEducationalCognitiveProcess(educationalCognitiveProcess);
            // Description
            ode.setEducationalDescription(educationalDescription);
            // Interactivity Level
            ode.setEducationalInteractivityLevel(educationalInteractivityLevel);
            // Interactivity Type
            ode.setEducationalInteractivityType(educationalInteractivityType);
            // Semantic Density
            ode.setEducationalSemanticDensity(educationalSemanticDensity);
            // Typical Age Range
            ode.setEducationalTypicalAgeRange(educationalTypicalAgeRange);
            // Difficulty
            ode.setEducationalDifficulty(educationalDifficulty);
            // Typical Learning Time
            ode.setEducationalTypicalLearningTime(educationalTypicalLearningTime);
            // Typical Learning Time Descriptions
            ode.setEducationalTypicalLearningTimeDescription(educationalTypicalLearningTimeDescription);

        }
    }

    @SuppressWarnings("unchecked")
    private static void parseRightsInfo(LomAgrega lomAgrega, Ode ode) {
        /* RIGHTS */
        RightsAgrega rights = null;
        try {
            rights = lomAgrega.getRightsAgrega();
        } catch (ParseadorException e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades Rights del manifest");
        }

        if (rights != null) {
            try {
                ode.setRightsCopyrightAndOtherRestrictions(rights.getDerechosDeAutor());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad rightsCopyrightAndOtherRestrictions del manifest");
            }
            try {
                ode.setRightsAccess(rights.getTipoDeAcceso());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad rightsAccess del manifest");
            }
            // Pueden venir cosas en varios idiomas
            try {
                ode.setRightsAccessDescription(rights.getDescripcionAcceso(""));
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad rightsAccessDescription del manifest");
            }

            try {
                ode.setRightsCost(rights.getCoste());
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error obteniendo la propiedad rightsCost del manifest");
            }

            ode.setRightsDescription(getListStringFromListLangStringAgrega(rights.getDescripcionesAv()));
        }
    }

    @SuppressWarnings("unchecked")
    private static void parseRelationInfo(LomAgrega lomAgrega, Ode ode) {
        List<RelationAgrega> relations = null;
        try {
            relations = lomAgrega.getRelationsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades Relation del manifest");
        }

        if (!Utils.isEmpty(relations)) {
            List<String> relationsString = new ArrayList<String>();
            for (RelationAgrega relation : relations) {
                String idRel = relation.getIdentificadorMEC();
                if (Utils.isEmpty(idRel)) {
                    idRel = relation.getRecursoAv().getIdentificador().getEntrada();
                }

                relationsString.add(idRel + Utils.getMessage("format_separator") + relation.getTipoAv());
            }
            ode.setRelationIdentifierKind(relationsString);
        }
    }

    @SuppressWarnings("unchecked")
    private static void parseAnnotationInfo(LomAgrega lomAgrega, Ode ode) {
        List<AnnotationAgrega> annotations = null;
        try {
            annotations = lomAgrega.getAnnotationsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades Annotation del manifest");
        }

        if (!Utils.isEmpty(annotations)) {
            List<String> annotationsString = new ArrayList<String>();
            for (AnnotationAgrega annotation : annotations) {
                String entity = annotation.getEntidadAv();
                List<LangStringAgrega> desc = annotation.getDescripcionAv();
                String description = "";
                // Pueden venir cosas en varios idiomas
                if (!Utils.isEmpty(desc)) {
                    description = desc.get(0).getValor();
                }
                String date = annotation.getFechaAv().getFecha();

                annotationsString.add(entity + Utils.getMessage("format_separator") + description + Utils.getMessage("format_separator") + date);
            }
            ode.setAnnotationEntityDescriptionDate(annotationsString);
        }
    }

    @SuppressWarnings("unchecked")
    private static void parseClassificationInfo(LomAgrega lomAgrega, Ode ode) {
        /* CLASSIFICATION */
        List<ClassificationAgrega> classifications = null;
        try {
            classifications = lomAgrega.getClassificationsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, e, "Error obteniendo el conjunto de propiedades Classification del manifest");
        }

        if (!Utils.isEmpty(classifications)) {
            List<String> edLevel1 = new ArrayList<String>();
            List<String> edLevel2 = new ArrayList<String>();
            List<String> edLevel3 = new ArrayList<String>();
            List<String> edLevel4 = new ArrayList<String>();
            List<String> edLevel5 = new ArrayList<String>();
            List<String> edLevel6 = new ArrayList<String>();
            List<String> discipline1 = new ArrayList<String>();
            List<String> discipline2 = new ArrayList<String>();
            List<String> discipline3 = new ArrayList<String>();
            List<String> discipline4 = new ArrayList<String>();
            List<String> discipline5 = new ArrayList<String>();
            List<String> discipline6 = new ArrayList<String>();
            List<String> competency1 = new ArrayList<String>();
            List<String> competency2 = new ArrayList<String>();
            List<String> accessibility1 = new ArrayList<String>();
            List<String> accessibility2 = new ArrayList<String>();
            List<String> accessibility3 = new ArrayList<String>();
            List<String> accessibility4 = new ArrayList<String>();

            List<String> edLevel1Label = new ArrayList<String>();
            List<String> edLevel2Label = new ArrayList<String>();
            List<String> edLevel3Label = new ArrayList<String>();
            List<String> edLevel4Label = new ArrayList<String>();
            List<String> edLevel5Label = new ArrayList<String>();
            List<String> edLevel6Label = new ArrayList<String>();
            List<String> discipline1Label = new ArrayList<String>();
            List<String> discipline2Label = new ArrayList<String>();
            List<String> discipline3Label = new ArrayList<String>();
            List<String> discipline4Label = new ArrayList<String>();
            List<String> discipline5Label = new ArrayList<String>();
            List<String> discipline6Label = new ArrayList<String>();
            List<String> competency1Label = new ArrayList<String>();
            List<String> competency2Label = new ArrayList<String>();
            List<String> accessibility1Label = new ArrayList<String>();
            List<String> accessibility2Label = new ArrayList<String>();
            List<String> accessibility3Label = new ArrayList<String>();
            List<String> accessibility4Label = new ArrayList<String>();

            for (ClassificationAgrega classification : classifications) {
                String purpose = null;
                try {
                    purpose = classification.getProposito();
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad classificationPurpose del manifest");
                }
                /* Educational level */
                List<String> idTaxons = null;
                List<TaxonAgrega> taxones = null;
                try {
                    idTaxons = classification.getIdsRutasTaxonomicas();

                    final RutaTaxonomicaAgrega rutaTaxonomica = (RutaTaxonomicaAgrega) classification.getRutaTaxonomicasAv().get(0);
                    taxones = rutaTaxonomica.getTaxones();
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo los IDs de los taxones del manifest: " + e.getMessage());
                }
                if (!Utils.isEmpty(idTaxons)) {
                    // Format: <SOURCE>/<ID NIVEL 1>/<ID NIVEL 2>/...
                    for (String idTaxon : idTaxons) {
                        if (idTaxon != null) {
                            String[] idTaxonSplit = idTaxon.split("/");
                            if (idTaxonSplit != null) {

                                /* Educational Level */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.educational_level").equals(purpose)) {
                                    edLevel1.add(idTaxonSplit.length > 1 ? Utils.getNivel_educativo().get(idTaxonSplit[1]) : "");
                                    edLevel1Label.add(idTaxonSplit.length > 1 ? Utils.getNivelEducativoLabel().get(idTaxonSplit[1]) : "");

                                    edLevel2.add(idTaxonSplit.length > 2 ? Utils.getNivel_educativo().get(idTaxonSplit[2]) : "");
                                    edLevel2Label.add(idTaxonSplit.length > 2 ? Utils.getNivelEducativoLabel().get(idTaxonSplit[2]) : "");

                                    edLevel3.add(idTaxonSplit.length > 3 ? Utils.getNivel_educativo().get(idTaxonSplit[3]) : "");
                                    edLevel3Label.add(idTaxonSplit.length > 3 ? Utils.getNivelEducativoLabel().get(idTaxonSplit[3]) : "");

                                    edLevel4.add(idTaxonSplit.length > 4 ? Utils.getNivel_educativo().get(idTaxonSplit[4]) : "");
                                    edLevel4Label.add(idTaxonSplit.length > 4 ? Utils.getNivelEducativoLabel().get(idTaxonSplit[4]) : "");

                                    edLevel5.add(idTaxonSplit.length > 5 ? Utils.getNivel_educativo().get(idTaxonSplit[5]) : "");
                                    edLevel5Label.add(idTaxonSplit.length > 5 ? Utils.getNivelEducativoLabel().get(idTaxonSplit[5]) : "");

                                    edLevel6.add(idTaxonSplit.length > 6 ? Utils.getNivel_educativo().get(idTaxonSplit[6]) : "");
                                    edLevel6Label.add(idTaxonSplit.length > 6 ? Utils.getNivelEducativoLabel().get(idTaxonSplit[6]) : "");

                                    // New catalog LearningContext LOE 2006
                                    for (int i = 1; i < idTaxonSplit.length; i++) {
                                        final List<String> contexts = Utils.getLearningContextLomes().get(idTaxonSplit[i]);
                                        ode.addLearningContexts(contexts);
                                    }

                                    // New catalog LearningContext ETB-LRE
                                    for (int i = 0; i < idTaxonSplit.length; i++) {
                                        final List<String> contexts = Utils.getLearningContextEtb().get(idTaxonSplit[i]);
                                        ode.addLearningContexts(contexts);
                                    }
                                }
                                /* Discipline (árbol curricular) */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.discipline").equals(purpose)) {
                                    if (idTaxonSplit[0].equals(Utils.getMessage("agrega.lomes.classification.source.discipline.lre"))) {
                                        int count = 1;
                                        for (TaxonAgrega taxon : taxones) {
                                            final String valor = ((LangStringAgrega) taxon.getTaxones().get(0)).getValor();
                                            final String id = idTaxonSplit[count];
                                            final String disciplineLabel = id + " - " + valor;

                                            switch (count++) {
                                            case 1:
                                                discipline1Label.add(disciplineLabel);
                                                break;
                                            case 2:
                                                discipline2Label.add(disciplineLabel);
                                                break;
                                            case 3:
                                                discipline3Label.add(disciplineLabel);
                                                break;
                                            case 4:
                                                discipline4Label.add(disciplineLabel);
                                                break;
                                            case 5:
                                                discipline5Label.add(disciplineLabel);
                                                break;
                                            case 6:
                                                discipline6Label.add(disciplineLabel);
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    } else {
                                        discipline1.add(idTaxonSplit.length > 1 ? Utils.getArbol_curricular().get(idTaxonSplit[1]) : "");
                                        discipline1Label.add(idTaxonSplit.length > 1 ? Utils.getArbolCurricularLabel().get(idTaxonSplit[1]) : "");

                                        discipline2.add(idTaxonSplit.length > 2 ? Utils.getArbol_curricular().get(idTaxonSplit[2]) : "");
                                        discipline2Label.add((idTaxonSplit.length > 2 ? Utils.getArbolCurricularLabel().get(idTaxonSplit[2]) : ""));

                                        discipline3.add(idTaxonSplit.length > 3 ? Utils.getArbol_curricular().get(idTaxonSplit[3]) : "");
                                        discipline3Label.add(idTaxonSplit.length > 3 ? Utils.getArbolCurricularLabel().get(idTaxonSplit[3]) : "");

                                        discipline4.add(idTaxonSplit.length > 4 ? Utils.getArbol_curricular().get(idTaxonSplit[4]) : "");
                                        discipline4Label.add(idTaxonSplit.length > 4 ? Utils.getArbolCurricularLabel().get(idTaxonSplit[4]) : "");

                                        discipline5.add(idTaxonSplit.length > 5 ? Utils.getArbol_curricular().get(idTaxonSplit[5]) : "");
                                        discipline5Label.add((idTaxonSplit.length > 5 ? Utils.getArbolCurricularLabel().get(idTaxonSplit[5]) : ""));

                                        discipline6.add(idTaxonSplit.length > 6 ? Utils.getArbol_curricular().get(idTaxonSplit[6]) : "");
                                        discipline6Label.add(idTaxonSplit.length > 6 ? Utils.getArbolCurricularLabel().get(idTaxonSplit[6]) : "");
                                    }

                                    // New catalog KnowledgeArea LOE 2006
                                    if (idTaxonSplit.length > 3) {
                                        ode.addKnowledgeAreas(Utils.getCurricularTreeLomes().get(idTaxonSplit[3]));
                                    }

                                    // New catalog KnowledgeArea ETB-LRE
                                    for (int i = 0; i < idTaxonSplit.length; i++) {
                                        final List<String> areas = Utils.getCurricularTreeEtb().get(idTaxonSplit[i]);
                                        ode.addKnowledgeAreas(areas);
                                    }

                                }
                                /* Competency */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.competency").equals(purpose)) {
                                    competency1.add(idTaxonSplit.length > 1 ? Utils.getCompetencias().get(idTaxonSplit[1]) : "");
                                    competency1Label.add(idTaxonSplit.length > 1 ? Utils.getCompetenciasLabel().get(idTaxonSplit[1]) : "");

                                    competency2.add(idTaxonSplit.length > 2 ? Utils.getCompetencias().get(idTaxonSplit[2]) : "");
                                    competency2Label.add(idTaxonSplit.length > 2 ? Utils.getCompetenciasLabel().get(idTaxonSplit[2]) : "");
                                }
                                /* Accessibility */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.accessibility_restrictions").equals(purpose)) {
                                    accessibility1.add(idTaxonSplit.length > 1 ? Utils.getAccesibilidad().get(idTaxonSplit[1]) : "");
                                    accessibility1Label.add(idTaxonSplit.length > 1 ? Utils.getAccesibilidadLabel().get(idTaxonSplit[1]) : "");

                                    accessibility2.add(idTaxonSplit.length > 2 ? Utils.getAccesibilidad().get(idTaxonSplit[2]) : "");
                                    accessibility2Label.add(idTaxonSplit.length > 2 ? Utils.getAccesibilidadLabel().get(idTaxonSplit[2]) : "");

                                    accessibility3.add(idTaxonSplit.length > 3 ? Utils.getAccesibilidad().get(idTaxonSplit[3]) : "");
                                    accessibility3Label.add(idTaxonSplit.length > 3 ? Utils.getAccesibilidadLabel().get(idTaxonSplit[3]) : "");

                                    accessibility4.add(idTaxonSplit.length > 4 ? Utils.getAccesibilidad().get(idTaxonSplit[4]) : "");
                                    accessibility4Label.add(idTaxonSplit.length > 4 ? Utils.getAccesibilidadLabel().get(idTaxonSplit[4]) : "");
                                }
                            }
                        }
                    }

                }
            }
            ode.setClassificationEducationalLevel1(edLevel1);
            ode.setClassificationEducationalLevel2(edLevel2);
            ode.setClassificationEducationalLevel3(edLevel3);
            ode.setClassificationEducationalLevel4(edLevel4);
            ode.setClassificationEducationalLevel5(edLevel5);
            ode.setClassificationEducationalLevel6(edLevel6);
            ode.setClassificationDiscipline1(discipline1);
            ode.setClassificationDiscipline2(discipline2);
            ode.setClassificationDiscipline3(discipline3);
            ode.setClassificationDiscipline4(discipline4);
            ode.setClassificationDiscipline5(discipline5);
            ode.setClassificationDiscipline6(discipline6);
            ode.setClassificationCompetency1(competency1);
            ode.setClassificationCompetency2(competency2);
            ode.setClassificationAccessibility1(accessibility1);
            ode.setClassificationAccessibility1(accessibility1);
            ode.setClassificationAccessibility1(accessibility1);
            ode.setClassificationAccessibility1(accessibility1);

            ode.setClassificationEducationalLevel1Label(edLevel1Label);
            ode.setClassificationEducationalLevel2Label(edLevel2Label);
            ode.setClassificationEducationalLevel3Label(edLevel3Label);
            ode.setClassificationEducationalLevel4Label(edLevel4Label);
            ode.setClassificationEducationalLevel5Label(edLevel5Label);
            ode.setClassificationEducationalLevel6Label(edLevel6Label);
            ode.setClassificationDiscipline1Label(discipline1Label);
            ode.setClassificationDiscipline2Label(discipline2Label);
            ode.setClassificationDiscipline3Label(discipline3Label);
            ode.setClassificationDiscipline4Label(discipline4Label);
            ode.setClassificationDiscipline5Label(discipline5Label);
            ode.setClassificationDiscipline6Label(discipline6Label);
            ode.setClassificationCompetency1Label(competency1Label);
            ode.setClassificationCompetency2Label(competency2Label);
            ode.setClassificationAccessibility1Label(accessibility1Label);
            ode.setClassificationAccessibility1Label(accessibility1Label);
            ode.setClassificationAccessibility1Label(accessibility1Label);
            ode.setClassificationAccessibility1Label(accessibility1Label);
        }
    }

    /***********************AUX METHODS*************************/

    private static List<String> getListStringFromListListLangStringAgrega(List<List<LangStringAgrega>> listList) {
        List<String> listString = null;
        if (!Utils.isEmpty(listList)) {
            listString = new ArrayList<String>();
            for (List<LangStringAgrega> listList2 : listList) {
                List<String> listAux = getListStringFromListLangStringAgrega(listList2);
                if (!Utils.isEmpty(listAux)) {
                    listString.addAll(listAux);
                }
            }
        }
        return listString;
    }

    private static List<String> getListStringFromListLangStringAgrega(List<LangStringAgrega> listLang) {
        List<String> listString = null;
        if (!Utils.isEmpty(listLang)) {
            listString = new ArrayList<String>();
            for (LangStringAgrega item : listLang) {
                listString.add(item.getValor());
            }
        }
        return listString;
    }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param filePath Path to the imsManifest.xml with the LOM-ES information
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    // public static Ode getOdeFromManifest(String filePath) throws
    // ParseadorException {
    // File file = null;
    // if (!Utils.isEmpty(filePath)) {
    // file = new File(filePath);
    // }
    // return getOdeFromManifest(file);
    //
    // }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param file imsManifest.xml with the LOM-ES information
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    // public static Ode getOdeFromManifest(File file) throws ParseadorException
    // {
    // byte[] byteArray = null;
    // if (file != null) {
    // try {
    // final FileInputStream fileInputStream = new FileInputStream(file);
    // byteArray = IOUtils.toByteArray(fileInputStream);
    // fileInputStream.close();
    // } catch (IOException e) {
    // Utils.logError(LOG, e, "Error accediendo al fichero especificado en: " +
    // file.getName());
    // }
    // }
    //
    // return getOdeFromManifest(byteArray);
    // }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param manifestFile imsManifest.xml with the LOM-ES information
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    public static Ode getOdeFromManifest(A2File manifestFile) throws ParseadorException {
        return getOdeFromManifest(manifestFile.getTmpFolderPath());
    }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param location Location of tmp dir
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    public static Ode getOdeFromManifest(final String location) throws ParseadorException {
        Ode ode = null;

        SCORM2004Dao scormDao = new SCORM2004Dao();
        Manifest manifest = null;

        File manifestTmpFile = new File(location + "imsmanifest.xml");

        try {
            manifest = scormDao.parsearODEEager(manifestTmpFile);
        } catch (ParseadorException e) {
            Utils.logError(LOG, e, "Error parseando el manifest {0}", manifestTmpFile.getName());
            throw new ParseadorException("Error parseando el manifest " + manifestTmpFile.getName());
        }

        if (manifest != null) {
            ManifestAgrega manifestAgrega = new ManifestAgrega(manifest);

            Collection<Lom> lomes;
            try {
                lomes = manifestAgrega.recuperarLomes();
            } catch (ParseadorException e) {
                Utils.logError(LOG, e, "Error recuperando los metadatos LOM-ES del manifest");
                throw new ParseadorException("Error recuperando los metadatos LOM-ES del manifest");
            }

            if (!Utils.isEmpty(lomes)) {
                ode = new Ode();
                for (Lom lom : lomes) {
                    LomAgrega lomAgrega = new LomAgrega(lom);

                    parseGeneralInfo(lomAgrega, ode);

                    parseLifeCycleInfo(lomAgrega, ode);

                    parseTechnicalInfo(lomAgrega, ode);

                    parseEducationalInfo(lomAgrega, ode);

                    parseRightsInfo(lomAgrega, ode);

                    parseRelationInfo(lomAgrega, ode);

                    parseAnnotationInfo(lomAgrega, ode);

                    parseClassificationInfo(lomAgrega, ode);

                }
            }
            /*
             * No necesitamos los ficheros del ODE en Solr. Sólo lo queremos
             * para validar/construir el ODE
             * parseOrganizationResources(manifestAgrega, ode);
             */
        }

        if (manifestTmpFile != null) {
            manifestTmpFile.delete();
        }

        return ode;
    }

    private static void setOrganizationResources(Manifest manifest, Ode ode) {
        String orgIdent = Utils.getUUID(OdesMapping.class.toString(), "ORG-");

        // creo una organizacion
        Organizations orgs = new Organizations();
        orgs.setDefault(orgIdent);
        Organization org = new Organization();
        org.setIdentifier(orgIdent);
        org.setTitle(Utils.getMessage("agrega.lomes.default.organization"));

        Resources ress = new Resources();

        List<ContentFile> contentTable = ode.getContentTable();
        if (!Utils.isEmpty(contentTable)) {
            Collections.sort(contentTable);
            for (int i = 0; i < contentTable.size(); i++) {
                ContentFile file = contentTable.get(i);
                Item item = new Item();
                String itemIdent = Utils.getUUID(OdesMapping.class.toString(), "ITEM-");
                String resourceIdent = Utils.getUUID(OdesMapping.class.toString(), "RES-");
                item.setIdentifierref(resourceIdent);
                item.setIdentifier(itemIdent);
                final String title = file.getTitle();
                if (Utils.isEmpty(title)) {
                    item.setTitle(file.getFile().getFileName());
                } else {
                    item.setTitle(title);
                }
                org.addItem(i, item);

                Resource res = new Resource();
                res.setIdentifier(resourceIdent);
                res.setType("webcontent");
                res.setScormType("asset");
                es.pode.parseadorXML.castor.File vFile = new es.pode.parseadorXML.castor.File();
                vFile.setHref(file.getFile().getFileName());
                res.addFile(vFile);
                res.setHref(file.getFile().getFileName());
                ress.addResource(res);
            }
        }

        orgs.addOrganization(org);
        manifest.setOrganizations(orgs);
        manifest.setResources(ress);

    }

    private static Metadata getScormMetadata() {
        Metadata metadata = new Metadata();
        metadata.setSchema(Utils.getMessage("agrega.scorm.default.schema"));
        metadata.setSchemaversion(Utils.getMessage("agrega.scorm.default.schema.version"));
        return metadata;
    }

    private static GeneralAgrega getGeneralData(Ode ode, String language) throws Exception {
        General general = new General();
        GeneralAgrega ga = new GeneralAgrega(general);

        // Title
        ga.addTituloIdioma(language, ode.getTitle());
        ga.setNivelDeAgregacion(ode.getGeneralAggregationLevel());

        // Identifiers
        List<String> generalIdentifiers = ode.getGeneralIdentifier();
        if (!Utils.isEmpty(generalIdentifiers)) {
            ArrayList<IdentificadorAgrega> lista = new ArrayList<IdentificadorAgrega>();
            for (String idStr : generalIdentifiers) {
                IdentificadorAgrega id = new IdentificadorAgrega();
                id.setCatalogo(Utils.getMessage("agrega.lomes.default.catalog"));
                id.setEntrada(idStr);
                lista.add(id);
            }
            ga.setIdentificadoresAv(lista);
        }

        // Descriptions
        List<String> generalDescriptions = ode.getGeneralDescription();
        if (!Utils.isEmpty(generalDescriptions)) {
            for (String descStr : generalDescriptions) {
                ga.addDescripcion(descStr, language);
            }
        }

        // Languages
        List<String> generalLanguages = ode.getGeneralLanguage();
        if (!Utils.isEmpty(generalLanguages)) {
            for (String langStr : generalLanguages) {
                ga.addIdioma(langStr);
            }
        }

        // Keywords
        List<String> generalKeywords = ode.getGeneralKeyword();
        if (!Utils.isEmpty(generalKeywords)) {
            List<List<LangStringAgrega>> lista = new ArrayList<List<LangStringAgrega>>();
            for (String keyStr : generalKeywords) {
                List<LangStringAgrega> keyList = new ArrayList<LangStringAgrega>();
                LangStringAgrega keyElem = new LangStringAgrega();
                keyElem.setIdioma(language);
                keyElem.setValor(keyStr);
                keyList.add(keyElem);
                lista.add(keyList);
            }
            ga.setPalabrasClaveAv((ArrayList<List<LangStringAgrega>>) lista);
        }

        return ga;
    }

    private static TechnicalAgrega getTechnicalData(Ode ode, String language) throws Exception {
        Technical technical = new Technical();
        TechnicalAgrega ta = new TechnicalAgrega(technical);

        // Size
        ta.setTamañoAv(ode.getTechnicalSize());

        // Formats
        ta.setFormatosAv((ArrayList<String>) ode.getTechnicalFormat());

        // Installation Remarks
        LangStringAgrega insLang = new LangStringAgrega();
        insLang.setIdioma(language);
        insLang.setValor(ode.getTechnicalInstallationRemarks());
        List<LangStringAgrega> ins = new ArrayList<LangStringAgrega>();
        ins.add(insLang);
        ta.setPautasDeInstalacionAv((ArrayList<LangStringAgrega>) ins);

        // Other Platform Requirements
        List<LangStringAgrega> other = new ArrayList<LangStringAgrega>();
        List<String> otherList = ode.getTechnicalOtherPlatformRequirements();
        if (!Utils.isEmpty(otherList)) {
            for (String otherSt : otherList) {
                LangStringAgrega otherLang = new LangStringAgrega();
                otherLang.setIdioma(language);
                otherLang.setValor(otherSt);
                other.add(otherLang);
            }
        }
        ta.setOtrosRequisitosAv((ArrayList<LangStringAgrega>) other);

        // Technical Requirements
        List<List<RequisitoAgrega>> reqs = new ArrayList<List<RequisitoAgrega>>();
        List<String> reqList = ode.getTechnicalRequirementTypeName();
        if (!Utils.isEmpty(reqList)) {
            for (String reqSt : reqList) {
                List<RequisitoAgrega> reqListElem = new ArrayList<RequisitoAgrega>();
                RequisitoAgrega req = new RequisitoAgrega();
                String[] typeName = reqSt.split(Utils.getMessage("format_separator"));
                if (typeName != null) {
                    req.setTipo(typeName[0]);
                    if (typeName.length > 1) {
                        req.setNombre(typeName[1]);
                    }
                }
                reqListElem.add(req);
                reqs.add(reqListElem);
            }
        }
        ta.setRequisitosAv((ArrayList<List<RequisitoAgrega>>) reqs);

        return ta;
    }

    private static LifeCycleAgrega getLifeCycleData(Ode ode, String language) throws Exception {
        LifeCycle lifeCycle = new LifeCycle();
        LifeCycleAgrega la = new LifeCycleAgrega(lifeCycle);

        // ROLE
        List<String> roleUserDateDescription = ode.getLifecycleContribute();
        if (!Utils.isEmpty(roleUserDateDescription)) {
            for (String rudd : roleUserDateDescription) {
                String[] ruddSplit = rudd.split(Utils.getMessage("format_separator"));
                // Usamos el formato de VCard????
                la.addContribucion(ruddSplit[0], ruddSplit[1], ruddSplit[2], ruddSplit[3]);
            }
        }

        return la;
    }

    private static EducationalAgrega[] getEducationalsData(Ode ode, String language) throws Exception {
        Educational educational = new Educational();
        EducationalAgrega ea = new EducationalAgrega(educational);

        List<String> cognitive = ode.getEducationalCognitiveProcess();
        if (!Utils.isEmpty(cognitive)) {
            for (String cogn : cognitive) {
                ea.addProcesoCognitivo(cogn);
            }
        }

        List<String> context = ode.getEducationalContext();
        if (!Utils.isEmpty(context)) {
            for (String cont : context) {
                ea.addContexto(cont);
            }
        }

        List<String> description = ode.getEducationalDescription();
        if (!Utils.isEmpty(description)) {
            ArrayList<ArrayList<LangStringAgrega>> descs = new ArrayList<ArrayList<LangStringAgrega>>();
            for (String desc : description) {
                ArrayList<LangStringAgrega> listDesc = new ArrayList<LangStringAgrega>();
                LangStringAgrega langDesc = new LangStringAgrega();
                langDesc.setIdioma(language);
                langDesc.setValor(desc);
                listDesc.add(langDesc);
                descs.add(listDesc);
            }
            ea.setDescripcionesAv(descs);
        }

        List<String> intended = ode.getEducationalIntendedEndUserRole();
        if (!Utils.isEmpty(intended)) {
            ea.setDestinatariosAv((ArrayList<String>) intended);
        }

        List<String> languages = ode.getEducationalLanguage();
        if (!Utils.isEmpty(languages)) {
            for (String lang : languages) {
                ea.addIdiomaDestinatario(lang);
            }
        }

        List<String> resource = ode.getEducationalLearningResourceType();
        if (!Utils.isEmpty(resource)) {
            for (String res : resource) {
                if (!Utils.isEmpty(res)) {
                    ea.addTipoDeRecurso(res);
                }
            }
        }

        List<String> newResource = ode.getResourceType();
        if (!Utils.isEmpty(newResource)) {
            for (String res : newResource) {
                // New catalog
                // TODO Nuevo flujo: de acuerdo al Tipo mime se rellenará
                // automáticamente. Lo ideal es que se haga la conversión aquí,
                // antes de esta líena añadir la tabla de conversión nueva.
                final ResourceType resourceType = CSVUtils.getResourceType().get(res);
                if (resourceType != null) {

                    ea.addTipoDeRecurso(resourceType.getLre());
                }
            }
        }

        // Target Age
        List<String> learningContexts = ode.getLearningContext();
        ArrayList<List<LangStringAgrega>> lRangosEdad = new ArrayList<List<LangStringAgrega>>();
        for (String learningContext : learningContexts) {
            final String ageRange = CSVUtils.getAgeRanges().get(learningContext);
            if (!Utils.isEmpty(ageRange)) {
                ArrayList<LangStringAgrega> al = new ArrayList<LangStringAgrega>();
                LangStringAgrega ls = new LangStringAgrega();
                ls.setIdioma(language);
                ls.setValor(ageRange);
                al.add(ls);
                lRangosEdad.add(al);
            }
        }
        if (!Utils.isEmpty(lRangosEdad)) {
            ea.setRangosEdadAv(lRangosEdad);
        }

        EducationalAgrega[] eas = new EducationalAgrega[] { ea };
        return eas;
    }

    private static RightsAgrega getRightsData(Ode ode, String language) throws Exception {
        Rights rights = new Rights();
        RightsAgrega ra = new RightsAgrega(rights);

        ra.setAcceso(ode.getRightsAccess(), ode.getRightsAccessDescription());
        ra.setDerechosDeAutor(ode.getRightsCopyrightAndOtherRestrictions());

        return ra;
    }

    private static void getClassificationEducationalLevelData(Ode ode, List<ClassificationAgrega> casList, String language) throws Exception {

        // NEW CATALOG
        if (!Utils.isEmpty(ode.getLearningContext())) {
            getNewClassificationEducationalLevelData(ode, casList, language);
        } else {
            List<String> edLevel1 = ode.getClassificationEducationalLevel1();
            List<String> edLevel2 = ode.getClassificationEducationalLevel2();
            List<String> edLevel3 = ode.getClassificationEducationalLevel3();
            List<String> edLevel4 = ode.getClassificationEducationalLevel4();
            List<String> edLevel5 = ode.getClassificationEducationalLevel5();
            List<String> edLevel6 = ode.getClassificationEducationalLevel6();
            if (!Utils.isEmpty(edLevel1)) {
                for (int i = 0; i < edLevel1.size(); i++) {
                    Classification classification = new Classification();
                    ClassificationAgrega ca = new ClassificationAgrega(classification);
                    ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.educational_level"));
                    ca.setFuente(0, language, Utils.getMessage("agrega.lomes.classification.source.educational_level"));

                    final String ide1 = Utils.getNivelEducativoRev().get(edLevel1.get(i));
                    ca.addTaxon(0, ide1, Utils.getNivelEducativoLabel().get(ide1).split("-")[1].trim(), language);

                    if (!Utils.isEmpty(edLevel2) && edLevel2.size() > i && !Utils.isEmpty(edLevel2.get(i))) {
                        final String ide2 = Utils.getNivelEducativoRev().get(edLevel2.get(i));
                        ca.addTaxon(0, ide2, Utils.getNivelEducativoLabel().get(ide2).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(edLevel3) && edLevel3.size() > i && !Utils.isEmpty(edLevel3.get(i))) {
                        final String ide3 = Utils.getNivelEducativoRev().get(edLevel3.get(i));
                        ca.addTaxon(0, ide3, Utils.getNivelEducativoLabel().get(ide3).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(edLevel4) && edLevel4.size() > i && !Utils.isEmpty(edLevel4.get(i))) {
                        final String ide4 = Utils.getNivelEducativoRev().get(edLevel4.get(i));
                        ca.addTaxon(0, ide4, Utils.getNivelEducativoLabel().get(ide4).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(edLevel5) && edLevel5.size() > i && !Utils.isEmpty(edLevel5.get(i))) {
                        final String ide5 = Utils.getNivelEducativoRev().get(edLevel5.get(i));
                        ca.addTaxon(0, ide5, Utils.getNivelEducativoLabel().get(ide5).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(edLevel6) && edLevel6.size() > i && !Utils.isEmpty(edLevel6.get(i))) {
                        final String ide6 = Utils.getNivelEducativoRev().get(edLevel6.get(i));
                        ca.addTaxon(0, ide6, Utils.getNivelEducativoLabel().get(ide6).split("-")[1].trim(), language);
                    }

                    casList.add(ca);
                }
            }

        }

    }

    private static void getNewClassificationEducationalLevelData(Ode ode, List<ClassificationAgrega> casList, String language) throws Exception {

        // New Catalog learningContext
        final List<String> learningContexts = ode.getLearningContext();

        if (!Utils.isEmpty(learningContexts)) {
            for (String string : learningContexts) {
                int indexRuta = 0;

                final LearningContext learningContextTree = CSVUtils.getLearningContext(language).get(string);
                Utils.logInfo(LOG, "Getting leraningContetTree with {0}, {1}", language, string);
                final List<List<TaxonNode>> loeLearningContextTree = learningContextTree.getLoeLearningContextTree();
                final List<TaxonNode> lreLearningContextTree = learningContextTree.getLreLearningContextTree();

                Classification classification = new Classification();
                ClassificationAgrega ca = new ClassificationAgrega(classification);
                ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.educational_level"));

                if (!Utils.isEmpty(loeLearningContextTree)) {
                    for (List<TaxonNode> tree : loeLearningContextTree) {
                        ca.setFuente(indexRuta, language, Utils.getMessage("agrega.lomes.classification.source.educational_level"));
                        int level = 0;
                        for (TaxonNode taxonNode : tree) {

                            final String getlevelNodeParsed = taxonNode.getlevelNodeParsed();
                            ca.addTaxon(indexRuta, taxonNode.getId(), taxonNode.getDescription(), language);
                            switch (++level) {
                            case 1:
                                if (Utils.isEmpty(ode.getClassificationEducationalLevel1Label())) {
                                    List<String> educationalLevel1Label = new ArrayList<String>();
                                    ode.setClassificationEducationalLevel1Label(educationalLevel1Label);
                                }
                                ode.getClassificationEducationalLevel1Label().add(getlevelNodeParsed);

                                break;
                            case 2:
                                if (Utils.isEmpty(ode.getClassificationEducationalLevel2Label())) {
                                    List<String> educationalLevel2Label = new ArrayList<String>();
                                    ode.setClassificationEducationalLevel2Label(educationalLevel2Label);
                                }
                                ode.getClassificationEducationalLevel2Label().add(getlevelNodeParsed);

                                break;
                            case 3:
                                if (Utils.isEmpty(ode.getClassificationEducationalLevel3Label())) {
                                    List<String> educationalLevel3Label = new ArrayList<String>();
                                    ode.setClassificationEducationalLevel3Label(educationalLevel3Label);
                                }
                                ode.getClassificationEducationalLevel3Label().add(getlevelNodeParsed);

                                break;
                            case 4:
                                if (Utils.isEmpty(ode.getClassificationEducationalLevel4Label())) {
                                    List<String> educationalLevel4Label = new ArrayList<String>();
                                    ode.setClassificationEducationalLevel4Label(educationalLevel4Label);
                                }
                                ode.getClassificationEducationalLevel4Label().add(getlevelNodeParsed);

                                break;
                            case 5:
                                if (Utils.isEmpty(ode.getClassificationEducationalLevel5Label())) {
                                    List<String> educationalLevel5Label = new ArrayList<String>();
                                    ode.setClassificationEducationalLevel5Label(educationalLevel5Label);
                                }
                                ode.getClassificationEducationalLevel5Label().add(getlevelNodeParsed);

                                break;
                            case 6:
                                if (Utils.isEmpty(ode.getClassificationEducationalLevel6Label())) {
                                    List<String> educationalLevel6Label = new ArrayList<String>();
                                    ode.setClassificationEducationalLevel6Label(educationalLevel6Label);
                                }
                                ode.getClassificationEducationalLevel6Label().add(getlevelNodeParsed);

                                break;

                            default:
                                break;
                            }
                        }
                        // casList.add(ca);
                        indexRuta++;
                    }
                }

                if (!Utils.isEmpty(lreLearningContextTree)) {
                    // Classification classification = new Classification();
                    // ClassificationAgrega ca = new
                    // ClassificationAgrega(classification);
                    // ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.educational_level"));
                    ca.setFuente(indexRuta, language, Utils.getMessage("agrega.lomes.classification.source.educational_level.lre"));
                    for (TaxonNode tree : lreLearningContextTree) {
                        ca.addTaxon(indexRuta, tree.getId(), tree.getDescription(), language);
                    }
                    // casList.add(ca);
                    indexRuta++;
                }
                casList.add(ca);

            }

        }
    }

    private static void getClassificationDisciplineData(Ode ode, List<ClassificationAgrega> casList, String language) throws Exception {

        // NEW CATALOG
        if (!Utils.isEmpty(ode.getKnowledgeArea())) {
            getNewClassificationDisciplineData(ode, casList, language);
        } else { // OLD CATALOG
            List<String> disc1 = ode.getClassificationDiscipline1();
            List<String> disc2 = ode.getClassificationDiscipline2();
            List<String> disc3 = ode.getClassificationDiscipline3();
            List<String> disc4 = ode.getClassificationDiscipline4();
            List<String> disc5 = ode.getClassificationDiscipline5();
            List<String> disc6 = ode.getClassificationDiscipline6();
            if (!Utils.isEmpty(disc1)) {
                for (int i = 0; i < disc1.size(); i++) {
                    Classification classification = new Classification();
                    ClassificationAgrega ca = new ClassificationAgrega(classification);
                    ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.discipline"));
                    ca.setFuente(0, language, Utils.getMessage("agrega.lomes.classification.source.discipline.lomes"));

                    final String ide1 = Utils.getArbolCurricularRev().get(disc1.get(i));
                    ca.addTaxon(0, ide1, Utils.getArbolCurricularLabel().get(ide1).split("-")[1].trim(), language);

                    if (!Utils.isEmpty(disc2) && disc2.size() > i && !Utils.isEmpty(disc2.get(i))) {
                        final String ide2 = Utils.getArbolCurricularRev().get(disc2.get(i));
                        ca.addTaxon(0, ide2, Utils.getArbolCurricularLabel().get(ide2).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(disc3) && disc3.size() > i && !Utils.isEmpty(disc3.get(i))) {
                        final String ide3 = Utils.getArbolCurricularRev().get(disc3.get(i));
                        ca.addTaxon(0, ide3, Utils.getArbolCurricularLabel().get(ide3).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(disc4) && disc4.size() > i && !Utils.isEmpty(disc4.get(i))) {
                        final String ide4 = Utils.getArbolCurricularRev().get(disc4.get(i));
                        ca.addTaxon(0, ide4, Utils.getArbolCurricularLabel().get(ide4).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(disc5) && disc5.size() > i && !Utils.isEmpty(disc5.get(i))) {
                        final String ide5 = Utils.getArbolCurricularRev().get(disc5.get(i));
                        ca.addTaxon(0, ide5, Utils.getArbolCurricularLabel().get(ide5).split("-")[1].trim(), language);
                    }

                    if (!Utils.isEmpty(disc6) && disc6.size() > i && !Utils.isEmpty(disc6.get(i))) {
                        final String ide6 = Utils.getArbolCurricularRev().get(disc6.get(i));
                        ca.addTaxon(0, ide6, Utils.getArbolCurricularLabel().get(ide6).split("-")[1].trim(), language);
                    }

                    casList.add(ca);
                }
            }
        }

    }

    private static void getNewClassificationDisciplineData(Ode ode, List<ClassificationAgrega> casList, String language) throws Exception {

        // New Catalog curricularTree
        final List<String> knowledgeAreas = ode.getKnowledgeArea();

        if (!Utils.isEmpty(knowledgeAreas)) {
            for (String string : knowledgeAreas) {

                final List<ArrayList<TaxonNode>> curricularTree = CSVUtils.getCurricularTree(language).get(string);
                for (ArrayList<TaxonNode> tree : curricularTree) {
                    int level = 0;
                    Classification classification = new Classification();
                    ClassificationAgrega ca = new ClassificationAgrega(classification);
                    ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.discipline"));
                    ca.setFuente(0, language, Utils.getMessage("agrega.lomes.classification.source.discipline.lre"));

                    for (TaxonNode taxonNode : tree) {
                        final String getlevelNodeParsed = taxonNode.getlevelNodeParsed();
                        ca.addTaxon(0, taxonNode.getId(), taxonNode.getDescription(), language);
                        switch (++level) {
                        case 1:
                            if (Utils.isEmpty(ode.getClassificationDiscipline1Label())) {
                                List<String> classificationDiscipline1Label = new ArrayList<String>();
                                ode.setClassificationDiscipline1Label(classificationDiscipline1Label);
                            }
                            // ode.setClassificationDiscipline1(idDrupal);
                            ode.getClassificationDiscipline1Label().add(getlevelNodeParsed);

                            break;
                        case 2:
                            if (Utils.isEmpty(ode.getClassificationDiscipline2Label())) {
                                List<String> classificationDiscipline2Label = new ArrayList<String>();
                                ode.setClassificationDiscipline2Label(classificationDiscipline2Label);
                            }
                            // ode.setClassificationDiscipline2(idDrupal);
                            ode.getClassificationDiscipline2Label().add(getlevelNodeParsed);
                            break;
                        case 3:
                            if (Utils.isEmpty(ode.getClassificationDiscipline3Label())) {
                                List<String> classificationDiscipline3Label = new ArrayList<String>();
                                ode.setClassificationDiscipline3Label(classificationDiscipline3Label);
                            }
                            // ode.setClassificationDiscipline3(idDrupal);
                            ode.getClassificationDiscipline3Label().add(getlevelNodeParsed);
                            break;
                        case 4:
                            if (Utils.isEmpty(ode.getClassificationDiscipline4Label())) {
                                List<String> classificationDiscipline4Label = new ArrayList<String>();
                                ode.setClassificationDiscipline4Label(classificationDiscipline4Label);
                            }
                            // ode.setClassificationDiscipline4(idDrupal);
                            ode.getClassificationDiscipline4Label().add(getlevelNodeParsed);
                            break;
                        case 5:
                            if (Utils.isEmpty(ode.getClassificationDiscipline5Label())) {
                                List<String> classificationDiscipline5Label = new ArrayList<String>();
                                ode.setClassificationDiscipline5Label(classificationDiscipline5Label);
                            }
                            // ode.setClassificationDiscipline5(idDrupal);
                            ode.getClassificationDiscipline5Label().add(getlevelNodeParsed);
                            break;
                        case 6:
                            if (Utils.isEmpty(ode.getClassificationDiscipline6Label())) {
                                List<String> classificationDiscipline6Label = new ArrayList<String>();
                                ode.setClassificationDiscipline6Label(classificationDiscipline6Label);
                            }
                            // ode.setClassificationDiscipline6(idDrupal);
                            ode.getClassificationDiscipline6Label().add(getlevelNodeParsed);
                            break;

                        default:
                            break;
                        }

                        Utils.logInfo(LOG, "Know ledge Area Taxon {0} - {1}", taxonNode.getId(), taxonNode.getDescription());
                    }

                    casList.add(ca);
                }

            }

        }
    }

    private static void getClassificationCompetencyData(Ode ode, List<ClassificationAgrega> casList, String language) throws Exception {
        List<String> comp1 = ode.getClassificationCompetency1();
        List<String> comp2 = ode.getClassificationCompetency2();
        if (!Utils.isEmpty(comp1)) {
            for (int i = 0; i < comp1.size(); i++) {
                Classification classification = new Classification();
                ClassificationAgrega ca = new ClassificationAgrega(classification);
                ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.competency"));
                ca.setFuente(0, language, Utils.getMessage("agrega.lomes.classification.source.competency"));

                final String ide1 = Utils.getCompetenciasRev().get(comp1.get(i));
                ca.addTaxon(0, ide1, Utils.getCompetenciasLabel().get(ide1).split("-")[1].trim(), language);

                if (!Utils.isEmpty(comp2) && comp2.size() > i && !Utils.isEmpty(comp2.get(i))) {
                    final String ide2 = Utils.getCompetenciasRev().get(comp2.get(i));
                    ca.addTaxon(0, ide2, Utils.getCompetenciasLabel().get(ide2).split("-")[1].trim(), language);
                }

                casList.add(ca);
            }
        }
    }

    private static void getClassificationAccessibilityData(Ode ode, List<ClassificationAgrega> casList, String language) throws Exception {
        List<String> access1 = ode.getClassificationAccessibility1();
        List<String> access2 = ode.getClassificationAccessibility2();
        List<String> access3 = ode.getClassificationAccessibility3();
        List<String> access4 = ode.getClassificationAccessibility4();
        if (!Utils.isEmpty(access1)) {
            for (int i = 0; i < access1.size(); i++) {
                Classification classification = new Classification();
                ClassificationAgrega ca = new ClassificationAgrega(classification);
                ca.setProposito(Utils.getMessage("agrega.lomes.classification.purpose.accessibility_restrictions"));
                ca.setFuente(0, language, Utils.getMessage("agrega.lomes.classification.source.accessibility_restrictions"));

                final String ide1 = Utils.getAccesibilidadRev().get(access1.get(i));
                ca.addTaxon(0, ide1, Utils.getAccesibilidadLabel().get(ide1).split("-")[1].trim(), language);

                if (!Utils.isEmpty(access2) && access2.size() > i && !Utils.isEmpty(access2.get(i))) {
                    final String ide2 = Utils.getAccesibilidadRev().get(access2.get(i));
                    ca.addTaxon(0, ide2, Utils.getAccesibilidadLabel().get(ide2).split("-")[1].trim(), language);
                }

                if (!Utils.isEmpty(access3) && access3.size() > i && !Utils.isEmpty(access3.get(i))) {
                    final String ide3 = Utils.getAccesibilidadRev().get(access3.get(i));
                    ca.addTaxon(0, ide3, Utils.getAccesibilidadLabel().get(ide3).split("-")[1].trim(), language);
                }

                if (!Utils.isEmpty(access4) && access4.size() > i && !Utils.isEmpty(access4.get(i))) {
                    final String ide4 = Utils.getAccesibilidadRev().get(access4.get(i));
                    ca.addTaxon(0, ide4, Utils.getAccesibilidadLabel().get(ide4).split("-")[1].trim(), language);
                }

                casList.add(ca);
            }
        }
    }

    // TODO: Classification
    private static ClassificationAgrega[] getClassificationsData(Ode ode, String language) throws Exception {

        List<ClassificationAgrega> casList = new ArrayList<ClassificationAgrega>();

        getClassificationEducationalLevelData(ode, casList, language);
        getClassificationDisciplineData(ode, casList, language);
        getClassificationCompetencyData(ode, casList, language);
        getClassificationAccessibilityData(ode, casList, language);

        ClassificationAgrega[] cas = (ClassificationAgrega[]) casList.toArray(new ClassificationAgrega[casList.size()]);
        return cas;
    }

    private static LomAgrega getLomesData(Ode ode) throws Exception {
        LomAgrega la = new LomAgrega(new Lom());

        String language = !Utils.isEmpty(ode.getGeneralLanguage()) ? ode.getGeneralLanguage().get(0) : Utils.getMessage("agrega.lomes.default.language");

        la.setGeneralAgrega(getGeneralData(ode, language));
        la.setTechnicalAgrega(getTechnicalData(ode, language));
        la.setEducationalsAgrega(getEducationalsData(ode, language));
        la.setLifeCycleAgrega(getLifeCycleData(ode, language));
        la.setRightsAgrega(getRightsData(ode, language));
        la.setClassificationsAgrega(getClassificationsData(ode, language));

        /*
         * Recupero el esquema de metadatos
         */
        MetaMetadataAgrega metaA = new MetaMetadataAgrega(new MetaMetadata());
        String schema = Utils.getMessage("agrega.lomes.default.schema");
        metaA.addEsquemaDeMetadatos(schema);
        // Idioma del metadato = idioma del usuario que cataloga
        metaA.setIdioma(language);
        la.setMetaMetadataAgrega(metaA);
        return la;
    }

    public static Manifest initialManifest(Ode ode) throws Exception {
        Manifest manifest = new Manifest();
        manifest.setIdentifier(Utils.getUUID(OdesMapping.class.toString(), "ODE-"));

        setOrganizationResources(manifest, ode);

        manifest.setMetadata(getScormMetadata());

        manifest.getMetadata().setGrp_any(new Grp_any());

        LomAgrega lomAgrega = getLomesData(ode);

        manifest.getMetadata().getGrp_any().addAnyObject(lomAgrega.getLom());

        return manifest;
    }

    /**
     * Builds a manifest file from an {@link Ode}, processing the BASIC elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param ode {@link Ode} with the LOM-ES information
     * @return  imsManifest.xml with the LOM-ES information from the ODE
     * @throws ParseadorException
     */
    public static A2File getManifestFromOde(Ode ode) throws Exception {

        ManifestAgrega manifestAgrega = new ManifestAgrega(initialManifest(ode));

        return getManifestFile(manifestAgrega);
    }

    public static A2File getManifestFile(final ManifestAgrega manifestAgrega) throws Exception {
        A2File manifest = new A2File();
        File manifestFile = new File(Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + Utils.getMessage("agrega.scorm.default.manifest_name"));

        SCORM2004Dao scormDao = new SCORM2004Dao();

        try {
            scormDao.escribirODE(manifestAgrega.getManifest(), manifestFile);
        } catch (ParseadorException e) {
            Utils.logError(LOG, e, "Error al construir el manifest: " + e.getMessage());
        }

        manifest.setFileName(Utils.getMessage("agrega.scorm.default.manifest_name"));
        manifest.setContent(IOUtils.toByteArray(new FileInputStream(manifestFile)));
        return manifest;
    }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param byteArray Content of the imsManifest.xml with the LOM-ES information
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    public static Ode getOdeFromLomesManifest(byte[] byteArray) throws ParseadorException {
        Ode ode = new Ode();
        LomESDao lomesDao = new LomESDao();
        Lom lom = null;
        try {
            lom = lomesDao.parsearLom(IOUtils.toInputStream(new String(byteArray)));
        } catch (ParseadorException e) {
            Utils.logError(LOG, e, "Error parseando el manifest: " + e.getMessage());
            throw new ParseadorException("Error parseando el manifest: " + e.getMessage());
        }

        if (lom != null) {
            LomAgrega lomAgrega = new LomAgrega(lom);

            parseGeneralInfo(lomAgrega, ode);

            parseLifeCycleInfo(lomAgrega, ode);

            parseTechnicalInfo(lomAgrega, ode);

            parseEducationalInfo(lomAgrega, ode);

            parseRightsInfo(lomAgrega, ode);

            parseRelationInfo(lomAgrega, ode);

            parseAnnotationInfo(lomAgrega, ode);

            parseClassificationInfo(lomAgrega, ode);

        }

        return ode;
    }

}
