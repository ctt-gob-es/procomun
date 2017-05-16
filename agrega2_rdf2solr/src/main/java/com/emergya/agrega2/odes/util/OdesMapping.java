package com.emergya.agrega2.odes.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.http.client.utils.DateUtils;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.Utils;

import es.pode.parseadorXML.LomESDao;
import es.pode.parseadorXML.ParseadorException;
import es.pode.parseadorXML.castor.Lom;
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
import es.pode.parseadorXML.lomes.lomesAgrega.RelationAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.RequisitoAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.RightsAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.TechnicalAgrega;

public class OdesMapping {
    private static final Log LOG = LogFactory.getLog(OdesMapping.class);

    private static void parseGeneralInfo(LomAgrega lomAgrega, Ode ode) {
        /* GENERAL */
        GeneralAgrega general = null;
        try {
            general = lomAgrega.getGeneralAgrega();
        } catch (ParseadorException e1) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades General del manifest");
        }

        if (general != null) {

            // FIXME: Pueden venir cosas en varios idiomas
            String titulo = null;
            try {
                titulo = general.getTitulo(null);
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalTitle del manifest");
            }
            ode.setGeneralTitle(titulo);
            ode.setTitle(titulo);

            try {
                List<String> descs = general.getDescripciones();
                ode.setGeneralDescription(descs);
                if (!Utils.isEmpty(descs))
                    ode.setDescription(descs.get(0));
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalDescription del manifest");
            }

            try {
                String idMec = general.obtenerIdentificadorFormatoMEC(Utils.getMessage("agrega.lomes.mec.catalog"));
                Utils.logInfo(LOG, "ID Catálogo MEC {0}: {1}", Utils.getMessage("agrega.lomes.mec.catalog"), idMec);
                ode.setMecIdentifier(idMec);
                List<IdentificadorAgrega> ids = general.getIdentificadoresAv();
                List<String> idsOde = new ArrayList<String>();
                if (!Utils.isEmpty(ids)) {
                    for (IdentificadorAgrega id : ids) {
                        idsOde.add(id.getEntrada());
                    }
                }
                ode.setGeneralIdentifier(idsOde);
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalIdentifier del manifest");
            }
            try {
                ode.setGeneralAggregationLevel(general.getNivelDeAgregacion());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalAggregationLevel del manifest");
            }
            try {
                ode.setGeneralKeyword(general.getPalabrasClave());
                ode.setLabels(general.getPalabrasClave());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalKeyword del manifest");
            }
            try {
                ode.setGeneralLanguage(general.getIdiomasAv());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalLanguage del manifest");
            }

            // FIXME: Pueden venir cosas en varios idiomas
            try {
                ode.setGeneralCoverage(getListStringFromListListLangStringAgrega(general.getAmbitos()));
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalCoverage del manifest");
            }

            try {
                ode.setGeneralStructure(general.getEstructuraAv());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad generalStructure del manifest");
            }
        }
    }

    private static void parseLifeCycleInfo(LomAgrega lomAgrega, Ode ode) {
        /* LIFECYCLE */
        List<String> lifecycleContribute = new ArrayList<String>();
        LifeCycleAgrega lifeCycle = null;
        try {
            lifeCycle = lomAgrega.getLifeCycleAgrega();
        } catch (ParseadorException e) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades LifeCycle del manifest");

        }

        if (lifeCycle != null) {
            List<ContribucionAgrega> contribuciones = lifeCycle.getContribucionesAv();
            if (!Utils.isEmpty(contribuciones)) {
                final ArrayList<EntidadAgrega> autores = lifeCycle.getAutores();
                List<String> autoresStr = new ArrayList<String>();
                for (EntidadAgrega entidad : autores) {
                    autoresStr.add(entidad.getCorreo());
                }
                ode.setAuthor(autoresStr);
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
                                Utils.logError(LOG, e,
                                        "Error generando una VCard a partir de una entidad: " + e.getMessage());
                                user = ent.getCorreo();
                                if (Utils.isEmpty(user)) {
                                    user = ent.getNombre();
                                }
                            }
                            // ROLE#USER#DATE#DESCRIPTION
                            if (tipo != null && tipo.equals("publisher") && ode.getPublicationDate() == null) {
                                // ode.setAuthor(user);
                                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
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

                            String lifecycle = tipo + Utils.getMessage("format_separator") + user
                                    + Utils.getMessage("format_separator") + fecha.getFecha()
                                    + Utils.getMessage("format_separator") + descripcionFecha;
                            lifecycleContribute.add(lifecycle);
                        }

                    }
                }
                if (ode.getPublicationDate() == null) {
                    ode.setPublicationDate(new Date());
                    // ode.setAuthor(author);
                }

                ode.setLifecycleContribute(lifecycleContribute);
            }

            ode.setLifeCycleVersion(getListStringFromListLangStringAgrega(lifeCycle.getVersionAv()));

            ode.setLifeCycleStatus(lifeCycle.getEstatusAv());
        }
    }

    private static void parseTechnicalInfo(LomAgrega lomAgrega, Ode ode) {
        /* TECHNICAL */
        TechnicalAgrega technical = null;
        try {
            technical = lomAgrega.getTechnicalAgrega();
        } catch (ParseadorException e) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades Technical del manifest");
        }
        if (technical != null) {
            try {
                ode.setTechnicalFormat(technical.getFormatos());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad technicalFormat del manifest");
            }
            ode.setTechnicalSize(technical.getTamañoAv());

            // FIXME: Pueden venir cosas en varios idiomas
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
                            reqSt = req.getTipo() + Utils.getMessage("format_separator") + req.getNombre()
                                    + Utils.getMessage("format_separator") + req.getVersionMinima()
                                    + Utils.getMessage("format_separator") + req.getVersionMaxima();
                            technicalRequirementTypeNameMinMax.add(reqSt);
                        }
                    }
                }
                ode.setTechnicalRequirementTypeName(technicalRequirementTypeName);
                ode.setTechnicalRequirementTypeNameMinMax(technicalRequirementTypeNameMinMax);
            }

            // FIXME: Pueden venir cosas en varios idiomas
            List<LangStringAgrega> instRemarks = technical.getPautasDeInstalacionAv();
            if (!Utils.isEmpty(instRemarks)) {
                ode.setTechnicalInstallationRemarks(instRemarks.get(0).getValor());
            }

            ode.setTechnicalLocation(technical.getLocalizacionAv());

            ode.setTechnicalDurationDescription(getListStringFromListLangStringAgrega(technical.getDuracionAv()
                    .getDescripciones()));
            ode.setTechnicalDuration(technical.getDuracionAv().getDuracion());

        }
    }

    private static void parseEducationalInfo(LomAgrega lomAgrega, Ode ode) {

        /* EDUCATIONAL */
        List<EducationalAgrega> educationals = null;
        try {
            educationals = lomAgrega.getEducationalsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades Educational del manifest");
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
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalLearningResouceType del manifest");
                }
                try {
                    educationalIntendedEndUserRole.addAll(educational.getDestinatarios());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalIntendedEndUserRole del manifest");
                }
                try {
                    educationalLanguage.addAll(educational.getIdiomasDestinatario());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalLanguage del manifest");
                }
                try {
                    educationalContext.addAll(educational.getContextos());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalContext del manifest");
                }
                try {
                    educationalCognitiveProcess.addAll(educational.getProcesosCognitivos());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalCognitiveProcess del manifest");
                }

                // FIXME: Pueden venir cosas en varios idiomas
                try {
                    List<String> descriptions = getListStringFromListLangStringAgrega(educational.getDescripcionesAv());
                    if (!Utils.isEmpty(descriptions)) {
                        educationalDescription.addAll(descriptions);
                    }
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalDescription del manifest");
                }

                try {
                    educationalInteractivityLevel.add(educational.getNivelDeInteractividadAv());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalInteractivityLevel del manifest");
                }

                try {
                    educationalInteractivityType.add(educational.getTipoDeInteractividadAv());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalInteractivityType del manifest");
                }

                try {
                    educationalSemanticDensity.add(educational.getDensidadSemanticaAv());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalSemanticDensity del manifest");
                }

                try {
                    educationalTypicalAgeRange.addAll(educational.getRangosEdad());
                } catch (Exception e) {
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalTypicalAgeRange del manifest");
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
                    Utils.logError(LOG, "Error obteniendo la propiedad educationalTypicalLearningTime del manifest");
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

    private static void parseRightsInfo(LomAgrega lomAgrega, Ode ode) {
        /* RIGHTS */
        RightsAgrega rights = null;
        try {
            rights = lomAgrega.getRightsAgrega();
        } catch (ParseadorException e) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades Rights del manifest");
        }

        if (rights != null) {
            try {
                ode.setRightsCopyrightAndOtherRestrictions(rights.getDerechosDeAutor());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad rightsCopyrightAndOtherRestrictions del manifest");
            }
            try {
                ode.setRightsAccess(rights.getTipoDeAcceso());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad rightsAccess del manifest");
            }
            // FIXME: Pueden venir cosas en varios idiomas
            try {
                ode.setRightsAccessDescription(rights.getDescripcionAcceso(""));
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad rightsAccessDescription del manifest");
            }

            try {
                ode.setRightsCost(rights.getCoste());
            } catch (Exception e) {
                Utils.logError(LOG, "Error obteniendo la propiedad rightsCost del manifest");
            }

            ode.setRightsDescription(getListStringFromListLangStringAgrega(rights.getDescripcionesAv()));
        }
    }

    private static void parseRelationInfo(LomAgrega lomAgrega, Ode ode) {
        List<RelationAgrega> relations = null;
        try {
            relations = lomAgrega.getRelationsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades Relation del manifest");
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

    private static void parseAnnotationInfo(LomAgrega lomAgrega, Ode ode) {
        List<AnnotationAgrega> annotations = null;
        try {
            annotations = lomAgrega.getAnnotationsAgrega();
        } catch (Exception e) {
            Utils.logError(LOG, "Error obteniendo el conjunto de propiedades Annotation del manifest");
        }

        if (!Utils.isEmpty(annotations)) {
            List<String> annotationsString = new ArrayList<String>();
            for (AnnotationAgrega annotation : annotations) {
                String entity = annotation.getEntidadAv();
                List<LangStringAgrega> desc = annotation.getDescripcionAv();
                String description = "";
                // FIXME: Pueden venir cosas en varios idiomas
                if (!Utils.isEmpty(desc)) {
                    description = desc.get(0).getValor();
                }
                String date = annotation.getFechaAv().getFecha();

                annotationsString.add(entity + Utils.getMessage("format_separator") + description
                        + Utils.getMessage("format_separator") + date);
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

            // List<String> edLevel = new ArrayList<String>();
            // List<String> discipline = new ArrayList<String>();
            // List<String> competency = new ArrayList<String>();
            // List<String> accessibility = new ArrayList<String>();

            for (ClassificationAgrega classification : classifications) {
                String purpose = null;
                try {
                    purpose = classification.getProposito();
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error obteniendo la propiedad classificationPurpose del manifest");
                }
                /* Educational level */
                List<String> idTaxons = null;
                try {
                    idTaxons = classification.getIdsRutasTaxonomicas();
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
                                if (Utils.getMessage("agrega.lomes.classification.purpose.educational_level").equals(
                                        purpose)) {
                                    edLevel1.add(idTaxonSplit.length > 1 ? Utils.getNivel_educativo().get(
                                            idTaxonSplit[1]) : "");
                                    edLevel1Label.add(idTaxonSplit.length > 1 ? Utils.getNivelEducativoLabel().get(
                                            idTaxonSplit[1]) : "");

                                    edLevel2.add(idTaxonSplit.length > 2 ? Utils.getNivel_educativo().get(
                                            idTaxonSplit[2]) : "");
                                    edLevel2Label.add(idTaxonSplit.length > 2 ? Utils.getNivelEducativoLabel().get(
                                            idTaxonSplit[2]) : "");

                                    edLevel3.add(idTaxonSplit.length > 3 ? Utils.getNivel_educativo().get(
                                            idTaxonSplit[3]) : "");
                                    edLevel3Label.add(idTaxonSplit.length > 3 ? Utils.getNivelEducativoLabel().get(
                                            idTaxonSplit[3]) : "");

                                    edLevel4.add((idTaxonSplit.length > 4 ? Utils.getNivel_educativo().get(
                                            idTaxonSplit[4]) : ""));
                                    edLevel4Label.add(idTaxonSplit.length > 4 ? Utils.getNivelEducativoLabel().get(
                                            idTaxonSplit[4]) : "");

                                    edLevel5.add(idTaxonSplit.length > 5 ? Utils.getNivel_educativo().get(
                                            idTaxonSplit[5]) : "");
                                    edLevel5Label.add(idTaxonSplit.length > 5 ? Utils.getNivelEducativoLabel().get(
                                            idTaxonSplit[5]) : "");

                                    edLevel6.add(idTaxonSplit.length > 6 ? Utils.getNivel_educativo().get(
                                            idTaxonSplit[6]) : "");
                                    edLevel6Label.add(idTaxonSplit.length > 6 ? Utils.getNivelEducativoLabel().get(
                                            idTaxonSplit[6]) : "");

                                    // New catalog LearningContext LOE 2006
                                    for (int i = 1; i < idTaxonSplit.length; i++) {
                                        final List<String> contexts = Utils.getLearningContextLomes().get(
                                                idTaxonSplit[i]);
                                        ode.addLearningContexts(contexts);
                                    }

                                    // New catalog LearningContext ETB-LRE
                                    for (int i = 0; i < idTaxonSplit.length; i++) {
                                        final List<String> contexts = Utils.getLearningContextEtb()
                                                .get(idTaxonSplit[i]);
                                        ode.addLearningContexts(contexts);
                                    }

                                }
                                /* Discipline (árbol curricular) */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.discipline").equals(purpose)) {
                                    discipline1.add(idTaxonSplit.length > 1 ? Utils.getArbol_curricular().get(
                                            idTaxonSplit[1]) : "");
                                    discipline1Label.add(idTaxonSplit.length > 1 ? Utils.getArbolCurricularLabel().get(
                                            idTaxonSplit[1]) : "");

                                    discipline2.add(idTaxonSplit.length > 2 ? Utils.getArbol_curricular().get(
                                            idTaxonSplit[2]) : "");
                                    discipline2Label.add(idTaxonSplit.length > 2 ? Utils.getArbolCurricularLabel().get(
                                            idTaxonSplit[2]) : "");

                                    discipline3.add(idTaxonSplit.length > 3 ? Utils.getArbol_curricular().get(
                                            idTaxonSplit[3]) : "");
                                    discipline3Label.add(idTaxonSplit.length > 3 ? Utils.getArbolCurricularLabel().get(
                                            idTaxonSplit[3]) : "");

                                    discipline4.add(idTaxonSplit.length > 4 ? Utils.getArbol_curricular().get(
                                            idTaxonSplit[4]) : "");
                                    discipline4Label.add(idTaxonSplit.length > 4 ? Utils.getArbolCurricularLabel().get(
                                            idTaxonSplit[4]) : "");

                                    discipline5.add(idTaxonSplit.length > 5 ? Utils.getArbol_curricular().get(
                                            idTaxonSplit[5]) : "");
                                    discipline5Label.add(idTaxonSplit.length > 5 ? Utils.getArbolCurricularLabel().get(
                                            idTaxonSplit[5]) : "");

                                    discipline6.add(idTaxonSplit.length > 6 ? Utils.getArbol_curricular().get(
                                            idTaxonSplit[6]) : "");
                                    discipline6Label.add(idTaxonSplit.length > 6 ? Utils.getArbolCurricularLabel().get(
                                            idTaxonSplit[6]) : "");

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
                                // if
                                // (Utils.getMessage("agrega.etblre.classification.source.discipline").equals(purpose))
                                // {
                                // discipline3LabelEtbLre.add((idTaxonSplit.length
                                // > 3 ? Utils.getArbol_curricular().get(
                                // idTaxonSplit[3]) : ""));
                                // }
                                /* Competency */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.competency").equals(purpose)) {
                                    competency1.add(idTaxonSplit.length > 1 ? Utils.getCompetencias().get(
                                            idTaxonSplit[1]) : "");
                                    competency1Label.add(idTaxonSplit.length > 1 ? Utils.getCompetenciasLabel().get(
                                            idTaxonSplit[1]) : "");

                                    competency2.add(idTaxonSplit.length > 2 ? Utils.getCompetencias().get(
                                            idTaxonSplit[2]) : "");
                                    competency2Label.add(idTaxonSplit.length > 2 ? Utils.getCompetenciasLabel().get(
                                            idTaxonSplit[2]) : "");
                                }
                                /* Accessibility */
                                if (Utils.getMessage("agrega.lomes.classification.purpose.accessibility_restrictions")
                                        .equals(purpose)) {
                                    accessibility1.add(idTaxonSplit.length > 1 ? Utils.getAccesibilidad().get(
                                            idTaxonSplit[1]) : "");
                                    accessibility1Label.add(idTaxonSplit.length > 1 ? Utils.getAccesibilidadLabel()
                                            .get(idTaxonSplit[1]) : "");

                                    accessibility2.add(idTaxonSplit.length > 2 ? Utils.getAccesibilidad().get(
                                            idTaxonSplit[2]) : "");
                                    accessibility2Label.add(idTaxonSplit.length > 2 ? Utils.getAccesibilidadLabel()
                                            .get(idTaxonSplit[2]) : "");

                                    accessibility3.add(idTaxonSplit.length > 3 ? Utils.getAccesibilidad().get(
                                            idTaxonSplit[3]) : "");
                                    accessibility3Label.add(idTaxonSplit.length > 3 ? Utils.getAccesibilidadLabel()
                                            .get(idTaxonSplit[3]) : "");

                                    accessibility4.add(idTaxonSplit.length > 4 ? Utils.getAccesibilidad().get(
                                            idTaxonSplit[4]) : "");
                                    accessibility4Label.add(idTaxonSplit.length > 4 ? Utils.getAccesibilidadLabel()
                                            .get(idTaxonSplit[4]) : "");
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

    // private static void parseOrganizationResources(ManifestAgrega
    // manifestAgrega, Ode ode) {
    // if (manifestAgrega != null && manifestAgrega.getManifest() != null) {
    // Organizations orgs = manifestAgrega.getManifest().getOrganizations();
    // Resources resources = manifestAgrega.getManifest().getResources();
    //
    // List<ContentFile> contentTable = new ArrayList<ContentFile>();
    // Iterator<Resource> itRes = resources.iterateResource();
    // while(itRes.hasNext()){
    // ContentFile file = new ContentFile();
    // Resource res = itRes.next();
    // es.pode.parseadorXML.castor.File[] files = res.getFile();
    // file.setUrl(res.getHref());
    // }
    // }
    // }

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
    public static Ode getOdeFromManifest(String filePath) throws ParseadorException {
        File file = null;
        if (!Utils.isEmpty(filePath)) {
            file = new File(filePath);
        }
        return getOdeFromManifest(file);

    }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param file imsManifest.xml with the LOM-ES information
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    public static Ode getOdeFromManifest(File file) throws ParseadorException {
        byte[] byteArray = null;
        String encoding = "";
        if (file != null) {
            try {
                final FileInputStream fileInputStream = new FileInputStream(file);
                byteArray = IOUtils.toByteArray(fileInputStream);
                encoding = getEncodingFromXML(file);
                fileInputStream.close();
            } catch (IOException e) {
                Utils.logError(LOG, "Error accediendo al fichero especificado en: " + file.getName());
            }
        }

        return getOdeFromManifest(byteArray, encoding);
    }

    private static String getEncodingFromXML(final File filePath) {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader(filePath.getAbsolutePath()));

            final String readLine = br.readLine().toUpperCase();
            // if (readLine.contains("ISO-8859-1")) {
            // return "ISO-8859-1";
            // }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (br != null)
                    br.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
        return "UTF-8";
    }

    /**
     * Builds an ODE from a manifest file, processing the elements: general, lifeCycle, technical, educational, rights, classification (educational level, discipline and competency)
     * @param byteArray Content of the imsManifest.xml with the LOM-ES information
     * @return {@link Ode} with the LOM-ES information from the file
     * @throws ParseadorException
     */
    public static Ode getOdeFromManifest(byte[] byteArray, final String encoding) throws ParseadorException {
        Ode ode = new Ode();

        LomESDao lomesDao = new LomESDao();

        Lom lom = null;
        try {
            lom = lomesDao.parsearLom(IOUtils.toInputStream(new String(byteArray), encoding));
        } catch (ParseadorException | IOException e) {
            Utils.logError(LOG, "Error parseando el manifest: " + e.getMessage());
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

    public static void main(String[] args) {
        try {
            Ode ode = OdesMapping
                    .getOdeFromManifest("*");

            System.out.println(ode.getMecIdentifier());
        } catch (ParseadorException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

}
