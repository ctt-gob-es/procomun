<?php
/**
 * @file
 * ag_section_search_solr_sarnia.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_search_solr_sarnia_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_search_solr_sarnia_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function ag_section_search_solr_sarnia_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_ode_search'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_ode_search",
    "name" : "ODE  Search",
    "index_id" : "sarnia_ode_search",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [] },
      "min_length" : "3",
      "results" : 1,
      "custom" : { "display" : "default" },
      "submit_button_selector" : ":submit",
      "autosubmit" : 1
    }
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function ag_section_search_solr_sarnia_default_search_api_index() {
  $items = array();
  $items['sarnia_ode_search'] = entity_import('search_api_index', '{
    "name" : "ode_search (Sarnia index)",
    "machine_name" : "sarnia_ode_search",
    "description" : "This index is managed by the Sarnia module.",
    "server" : "ode_search",
    "item_type" : "sarnia_ode_search",
    "options" : {
      "cron_limit" : 0,
      "fields" : {
        "annotationEntityDescriptionDate" : {
          "name" : "annotationEntityDescriptionDate",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "annotationEntityDescriptionDateStr" : {
          "name" : "annotationEntityDescriptionDateStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "author" : { "name" : "author", "indexed" : true, "type" : "text", "boost" : "1.0" },
        "authorStr" : {
          "name" : "authorStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "baseItinerary" : {
          "name" : "baseItinerary",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "category" : {
          "name" : "category",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "categoryStr" : {
          "name" : "categoryStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "certified" : {
          "name" : "certified",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationAccessibility1" : {
          "name" : "classificationAccessibility1",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationAccessibility1Label" : {
          "name" : "classificationAccessibility1Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationCompetency1" : {
          "name" : "classificationCompetency1",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationCompetency1Label" : {
          "name" : "classificationCompetency1Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationCompetency2" : {
          "name" : "classificationCompetency2",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationCompetency2Label" : {
          "name" : "classificationCompetency2Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline1" : {
          "name" : "classificationDiscipline1",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline1Label" : {
          "name" : "classificationDiscipline1Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline2" : {
          "name" : "classificationDiscipline2",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline2Label" : {
          "name" : "classificationDiscipline2Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline3" : {
          "name" : "classificationDiscipline3",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline3Label" : {
          "name" : "classificationDiscipline3Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline4" : {
          "name" : "classificationDiscipline4",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline4Label" : {
          "name" : "classificationDiscipline4Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline5" : {
          "name" : "classificationDiscipline5",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline5Label" : {
          "name" : "classificationDiscipline5Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline6" : {
          "name" : "classificationDiscipline6",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationDiscipline6Label" : {
          "name" : "classificationDiscipline6Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel1" : {
          "name" : "classificationEducationalLevel1",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel1Label" : {
          "name" : "classificationEducationalLevel1Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel2" : {
          "name" : "classificationEducationalLevel2",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel2Label" : {
          "name" : "classificationEducationalLevel2Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel3" : {
          "name" : "classificationEducationalLevel3",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel3Label" : {
          "name" : "classificationEducationalLevel3Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel4" : {
          "name" : "classificationEducationalLevel4",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel4Label" : {
          "name" : "classificationEducationalLevel4Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel5" : {
          "name" : "classificationEducationalLevel5",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel5Label" : {
          "name" : "classificationEducationalLevel5Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel6" : {
          "name" : "classificationEducationalLevel6",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "classificationEducationalLevel6Label" : {
          "name" : "classificationEducationalLevel6Label",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "communityAdminSups" : {
          "name" : "communityAdminSups",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "communityAdminSupsStr" : {
          "name" : "communityAdminSupsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "communityDate" : {
          "name" : "communityDate",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "communityLabels" : {
          "name" : "communityLabels",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "communityLabelsStr" : {
          "name" : "communityLabelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "description" : {
          "name" : "description",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "descriptionStr" : {
          "name" : "descriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "discussionLabels" : {
          "name" : "discussionLabels",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "discussionLabelsStr" : {
          "name" : "discussionLabelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "duration" : {
          "name" : "duration",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalCognitiveProcess" : {
          "name" : "educationalCognitiveProcess",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalCognitiveProcessStr" : {
          "name" : "educationalCognitiveProcessStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalContext" : {
          "name" : "educationalContext",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalContextStr" : {
          "name" : "educationalContextStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalDescription" : {
          "name" : "educationalDescription",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalDescriptionStr" : {
          "name" : "educationalDescriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalDifficulty" : {
          "name" : "educationalDifficulty",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalDifficultyStr" : {
          "name" : "educationalDifficultyStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalIntendedEndUserRole" : {
          "name" : "educationalIntendedEndUserRole",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalIntendedEndUserRoleStr" : {
          "name" : "educationalIntendedEndUserRoleStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalInteractivityLevel" : {
          "name" : "educationalInteractivityLevel",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalInteractivityLevelStr" : {
          "name" : "educationalInteractivityLevelStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalInteractivityType" : {
          "name" : "educationalInteractivityType",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalInteractivityTypeStr" : {
          "name" : "educationalInteractivityTypeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalLanguage" : {
          "name" : "educationalLanguage",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalLanguageStr" : {
          "name" : "educationalLanguageStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalLearningResourceType" : {
          "name" : "educationalLearningResourceType",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalLearningResourceTypeStr" : {
          "name" : "educationalLearningResourceTypeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalSemanticDensity" : {
          "name" : "educationalSemanticDensity",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalSemanticDensityStr" : {
          "name" : "educationalSemanticDensityStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalTypicalAgeRange" : {
          "name" : "educationalTypicalAgeRange",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalTypicalAgeRangeStr" : {
          "name" : "educationalTypicalAgeRangeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalTypicalLearningTime" : {
          "name" : "educationalTypicalLearningTime",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalTypicalLearningTimeDescription" : {
          "name" : "educationalTypicalLearningTimeDescription",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "educationalTypicalLearningTimeDescriptionStr" : {
          "name" : "educationalTypicalLearningTimeDescriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "educationalTypicalLearningTimeStr" : {
          "name" : "educationalTypicalLearningTimeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "endDate" : { "name" : "endDate", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "eventLabels" : {
          "name" : "eventLabels",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "eventLabelsStr" : {
          "name" : "eventLabelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalAggregationLevel" : {
          "name" : "generalAggregationLevel",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalAggregationLevelStr" : {
          "name" : "generalAggregationLevelStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalCoverage" : {
          "name" : "generalCoverage",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalCoverageStr" : {
          "name" : "generalCoverageStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalDescription" : {
          "name" : "generalDescription",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalDescriptionStr" : {
          "name" : "generalDescriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalIdentifier" : {
          "name" : "generalIdentifier",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalIdentifierStr" : {
          "name" : "generalIdentifierStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalKeyword" : {
          "name" : "generalKeyword",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalKeywordAuto" : {
          "name" : "generalKeywordAuto",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalKeywordStr" : {
          "name" : "generalKeywordStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalLanguage" : {
          "name" : "generalLanguage",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalLanguageStr" : {
          "name" : "generalLanguageStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalStructure" : {
          "name" : "generalStructure",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalStructureStr" : {
          "name" : "generalStructureStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generalTitle" : {
          "name" : "generalTitle",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalTitleAuto" : {
          "name" : "generalTitleAuto",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "generalTitleStr" : {
          "name" : "generalTitleStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "generatedId" : {
          "name" : "generatedId",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "id" : { "name" : "id", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "idDrupal" : {
          "name" : "idDrupal",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "interestContent" : {
          "name" : "interestContent",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "itineraryContent" : {
          "name" : "itineraryContent",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "knowledgeArea" : {
          "name" : "knowledgeArea",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "labels" : { "name" : "labels", "indexed" : true, "type" : "text", "boost" : "1.0" },
        "labelsStr" : {
          "name" : "labelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "lastIndexDate" : {
          "name" : "lastIndexDate",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "learningContext" : {
          "name" : "learningContext",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "lifeCycleStatus" : {
          "name" : "lifeCycleStatus",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "lifeCycleStatusStr" : {
          "name" : "lifeCycleStatusStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "lifeCycleVersion" : {
          "name" : "lifeCycleVersion",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "lifeCycleVersionStr" : {
          "name" : "lifeCycleVersionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "lifecycleContribute" : {
          "name" : "lifecycleContribute",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "lifecycleContributeStr" : {
          "name" : "lifecycleContributeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "mecIdentifier" : {
          "name" : "mecIdentifier",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "mecIdentifierStr" : {
          "name" : "mecIdentifierStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "novelty" : { "name" : "novelty", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "odeNode" : { "name" : "odeNode", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "odeNodeStr" : {
          "name" : "odeNodeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "podcastUrl" : {
          "name" : "podcastUrl",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "postLabels" : {
          "name" : "postLabels",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "postLabelsStr" : {
          "name" : "postLabelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "preview" : { "name" : "preview", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "publicationDate" : {
          "name" : "publicationDate",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "publicator" : {
          "name" : "publicator",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "publicatorEmail" : {
          "name" : "publicatorEmail",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "publicatorEmailStr" : {
          "name" : "publicatorEmailStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "publicatorName" : {
          "name" : "publicatorName",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "publicatorNameStr" : {
          "name" : "publicatorNameStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "publicatorStr" : {
          "name" : "publicatorStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "published" : {
          "name" : "published",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "questionLabels" : {
          "name" : "questionLabels",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "questionLabelsStr" : {
          "name" : "questionLabelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "relationIdentifierKind" : {
          "name" : "relationIdentifierKind",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "relationIdentifierKindStr" : {
          "name" : "relationIdentifierKindStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "resourceType" : {
          "name" : "resourceType",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "responseState" : {
          "name" : "responseState",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "responseStateStr" : {
          "name" : "responseStateStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "rightsAccess" : {
          "name" : "rightsAccess",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "rightsAccessDescription" : {
          "name" : "rightsAccessDescription",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "rightsAccessDescriptionStr" : {
          "name" : "rightsAccessDescriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "rightsAccessStr" : {
          "name" : "rightsAccessStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "rightsCopyrightAndOtherRestrictions" : {
          "name" : "rightsCopyrightAndOtherRestrictions",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "rightsCopyrightAndOtherRestrictionsStr" : {
          "name" : "rightsCopyrightAndOtherRestrictionsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "rightsCost" : {
          "name" : "rightsCost",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "rightsCostStr" : {
          "name" : "rightsCostStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "rightsDescription" : {
          "name" : "rightsDescription",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "rightsDescriptionStr" : {
          "name" : "rightsDescriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "startDate" : {
          "name" : "startDate",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalDuration" : {
          "name" : "technicalDuration",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalDurationDescription" : {
          "name" : "technicalDurationDescription",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalDurationDescriptionStr" : {
          "name" : "technicalDurationDescriptionStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalFormat" : {
          "name" : "technicalFormat",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalFormatStr" : {
          "name" : "technicalFormatStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalInstallationRemarks" : {
          "name" : "technicalInstallationRemarks",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalInstallationRemarksStr" : {
          "name" : "technicalInstallationRemarksStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalLocation" : {
          "name" : "technicalLocation",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalLocationStr" : {
          "name" : "technicalLocationStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalOtherPlatformRequirements" : {
          "name" : "technicalOtherPlatformRequirements",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalOtherPlatformRequirementsStr" : {
          "name" : "technicalOtherPlatformRequirementsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalRequirementTypeName" : {
          "name" : "technicalRequirementTypeName",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalRequirementTypeNameMinMax" : {
          "name" : "technicalRequirementTypeNameMinMax",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalRequirementTypeNameMinMaxStr" : {
          "name" : "technicalRequirementTypeNameMinMaxStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalRequirementTypeNameStr" : {
          "name" : "technicalRequirementTypeNameStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "technicalSize" : {
          "name" : "technicalSize",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "technicalSizeStr" : {
          "name" : "technicalSizeStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "text" : { "name" : "text", "indexed" : true, "type" : "text", "boost" : "1.0" },
        "title" : { "name" : "title", "indexed" : true, "type" : "text", "boost" : "1.0" },
        "titleLinks" : {
          "name" : "titleLinks",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "titleLinksStr" : {
          "name" : "titleLinksStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "titleOrder" : {
          "name" : "titleOrder",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "titleStr" : {
          "name" : "titleStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "type" : { "name" : "type", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "url" : { "name" : "url", "indexed" : true, "type" : "none", "boost" : "1.0" },
        "userBirthDate" : {
          "name" : "userBirthDate",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userCountry" : {
          "name" : "userCountry",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userCountryStr" : {
          "name" : "userCountryStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userDni" : { "name" : "userDni", "indexed" : true, "type" : "text", "boost" : "1.0" },
        "userEducativeCenter" : {
          "name" : "userEducativeCenter",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userEducativeCenterStr" : {
          "name" : "userEducativeCenterStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userEducativeCenterUrl" : {
          "name" : "userEducativeCenterUrl",
          "indexed" : false,
          "type" : "none",
          "boost" : "1.0"
        },
        "userLabels" : {
          "name" : "userLabels",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userLabelsAuto" : {
          "name" : "userLabelsAuto",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userLabelsStr" : {
          "name" : "userLabelsStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userLocality" : {
          "name" : "userLocality",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userLocalityStr" : {
          "name" : "userLocalityStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userLogin" : {
          "name" : "userLogin",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userLoginStr" : {
          "name" : "userLoginStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userMail" : {
          "name" : "userMail",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userMailStr" : {
          "name" : "userMailStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userName" : {
          "name" : "userName",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userNameStr" : {
          "name" : "userNameStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userNameSurname" : {
          "name" : "userNameSurname",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userNameSurnameAuto" : {
          "name" : "userNameSurnameAuto",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userNameSurnameStr" : {
          "name" : "userNameSurnameStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userPassword" : {
          "name" : "userPassword",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userPasswordStr" : {
          "name" : "userPasswordStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userPlace" : {
          "name" : "userPlace",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userPlaceStr" : {
          "name" : "userPlaceStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userProvince" : {
          "name" : "userProvince",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userProvinceStr" : {
          "name" : "userProvinceStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "userSurName" : {
          "name" : "userSurName",
          "indexed" : true,
          "type" : "text",
          "boost" : "1.0"
        },
        "userSurNameStr" : {
          "name" : "userSurNameStr",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        },
        "webinarUrl" : {
          "name" : "webinarUrl",
          "indexed" : true,
          "type" : "none",
          "boost" : "1.0"
        }
      },
      "data_alter_callbacks" : {
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : false } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "annotationEntityDescriptionDate" : true,
              "author" : true,
              "category" : true,
              "communityAdminSups" : true,
              "communityLabels" : true,
              "description" : true,
              "discussionLabels" : true,
              "educationalCognitiveProcess" : true,
              "educationalContext" : true,
              "educationalDescription" : true,
              "educationalDifficulty" : true,
              "educationalIntendedEndUserRole" : true,
              "educationalInteractivityLevel" : true,
              "educationalInteractivityType" : true,
              "educationalLanguage" : true,
              "educationalLearningResourceType" : true,
              "educationalSemanticDensity" : true,
              "educationalTypicalAgeRange" : true,
              "educationalTypicalLearningTime" : true,
              "educationalTypicalLearningTimeDescription" : true,
              "eventLabels" : true,
              "generalAggregationLevel" : true,
              "generalCoverage" : true,
              "generalDescription" : true,
              "generalIdentifier" : true,
              "generalKeyword" : true,
              "generalKeywordAuto" : true,
              "generalLanguage" : true,
              "generalStructure" : true,
              "generalTitle" : true,
              "generalTitleAuto" : true,
              "labels" : true,
              "lifeCycleStatus" : true,
              "lifeCycleVersion" : true,
              "lifecycleContribute" : true,
              "mecIdentifier" : true,
              "postLabels" : true,
              "questionLabels" : true,
              "relationIdentifierKind" : true,
              "responseState" : true,
              "rightsAccess" : true,
              "rightsAccessDescription" : true,
              "rightsCopyrightAndOtherRestrictions" : true,
              "rightsCost" : true,
              "rightsDescription" : true,
              "technicalDuration" : true,
              "technicalDurationDescription" : true,
              "technicalFormat" : true,
              "technicalInstallationRemarks" : true,
              "technicalLocation" : true,
              "technicalOtherPlatformRequirements" : true,
              "technicalRequirementTypeName" : true,
              "technicalRequirementTypeNameMinMax" : true,
              "technicalSize" : true,
              "text" : true,
              "title" : true,
              "titleLinks" : true,
              "userCountry" : true,
              "userDni" : true,
              "userEducativeCenter" : true,
              "userLabels" : true,
              "userLabelsAuto" : true,
              "userLocality" : true,
              "userLogin" : true,
              "userMail" : true,
              "userName" : true,
              "userNameSurname" : true,
              "userNameSurnameAuto" : true,
              "userPassword" : true,
              "userPlace" : true,
              "userProvince" : true,
              "userSurName" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "annotationEntityDescriptionDate" : true,
              "author" : true,
              "category" : true,
              "communityAdminSups" : true,
              "communityLabels" : true,
              "description" : true,
              "discussionLabels" : true,
              "educationalCognitiveProcess" : true,
              "educationalContext" : true,
              "educationalDescription" : true,
              "educationalDifficulty" : true,
              "educationalIntendedEndUserRole" : true,
              "educationalInteractivityLevel" : true,
              "educationalInteractivityType" : true,
              "educationalLanguage" : true,
              "educationalLearningResourceType" : true,
              "educationalSemanticDensity" : true,
              "educationalTypicalAgeRange" : true,
              "educationalTypicalLearningTime" : true,
              "educationalTypicalLearningTimeDescription" : true,
              "eventLabels" : true,
              "generalAggregationLevel" : true,
              "generalCoverage" : true,
              "generalDescription" : true,
              "generalIdentifier" : true,
              "generalKeyword" : true,
              "generalKeywordAuto" : true,
              "generalLanguage" : true,
              "generalStructure" : true,
              "generalTitle" : true,
              "generalTitleAuto" : true,
              "labels" : true,
              "lifeCycleStatus" : true,
              "lifeCycleVersion" : true,
              "lifecycleContribute" : true,
              "mecIdentifier" : true,
              "postLabels" : true,
              "questionLabels" : true,
              "relationIdentifierKind" : true,
              "responseState" : true,
              "rightsAccess" : true,
              "rightsAccessDescription" : true,
              "rightsCopyrightAndOtherRestrictions" : true,
              "rightsCost" : true,
              "rightsDescription" : true,
              "technicalDuration" : true,
              "technicalDurationDescription" : true,
              "technicalFormat" : true,
              "technicalInstallationRemarks" : true,
              "technicalLocation" : true,
              "technicalOtherPlatformRequirements" : true,
              "technicalRequirementTypeName" : true,
              "technicalRequirementTypeNameMinMax" : true,
              "technicalSize" : true,
              "text" : true,
              "title" : true,
              "titleLinks" : true,
              "userCountry" : true,
              "userDni" : true,
              "userEducativeCenter" : true,
              "userLabels" : true,
              "userLabelsAuto" : true,
              "userLocality" : true,
              "userLogin" : true,
              "userMail" : true,
              "userName" : true,
              "userNameSurname" : true,
              "userNameSurnameAuto" : true,
              "userPassword" : true,
              "userPlace" : true,
              "userProvince" : true,
              "userSurName" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : {
              "annotationEntityDescriptionDate" : true,
              "author" : true,
              "category" : true,
              "communityAdminSups" : true,
              "communityLabels" : true,
              "description" : true,
              "discussionLabels" : true,
              "educationalCognitiveProcess" : true,
              "educationalContext" : true,
              "educationalDescription" : true,
              "educationalDifficulty" : true,
              "educationalIntendedEndUserRole" : true,
              "educationalInteractivityLevel" : true,
              "educationalInteractivityType" : true,
              "educationalLanguage" : true,
              "educationalLearningResourceType" : true,
              "educationalSemanticDensity" : true,
              "educationalTypicalAgeRange" : true,
              "educationalTypicalLearningTime" : true,
              "educationalTypicalLearningTimeDescription" : true,
              "eventLabels" : true,
              "generalAggregationLevel" : true,
              "generalCoverage" : true,
              "generalDescription" : true,
              "generalIdentifier" : true,
              "generalKeyword" : true,
              "generalKeywordAuto" : true,
              "generalLanguage" : true,
              "generalStructure" : true,
              "generalTitle" : true,
              "generalTitleAuto" : true,
              "labels" : true,
              "lifeCycleStatus" : true,
              "lifeCycleVersion" : true,
              "lifecycleContribute" : true,
              "mecIdentifier" : true,
              "postLabels" : true,
              "questionLabels" : true,
              "relationIdentifierKind" : true,
              "responseState" : true,
              "rightsAccess" : true,
              "rightsAccessDescription" : true,
              "rightsCopyrightAndOtherRestrictions" : true,
              "rightsCost" : true,
              "rightsDescription" : true,
              "technicalDuration" : true,
              "technicalDurationDescription" : true,
              "technicalFormat" : true,
              "technicalInstallationRemarks" : true,
              "technicalLocation" : true,
              "technicalOtherPlatformRequirements" : true,
              "technicalRequirementTypeName" : true,
              "technicalRequirementTypeNameMinMax" : true,
              "technicalSize" : true,
              "text" : true,
              "title" : true,
              "titleLinks" : true,
              "userCountry" : true,
              "userDni" : true,
              "userEducativeCenter" : true,
              "userLabels" : true,
              "userLabelsAuto" : true,
              "userLocality" : true,
              "userLogin" : true,
              "userMail" : true,
              "userName" : true,
              "userNameSurname" : true,
              "userNameSurnameAuto" : true,
              "userPassword" : true,
              "userPlace" : true,
              "userProvince" : true,
              "userSurName" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "annotationEntityDescriptionDate" : true,
              "author" : true,
              "category" : true,
              "communityAdminSups" : true,
              "communityLabels" : true,
              "description" : true,
              "discussionLabels" : true,
              "educationalCognitiveProcess" : true,
              "educationalContext" : true,
              "educationalDescription" : true,
              "educationalDifficulty" : true,
              "educationalIntendedEndUserRole" : true,
              "educationalInteractivityLevel" : true,
              "educationalInteractivityType" : true,
              "educationalLanguage" : true,
              "educationalLearningResourceType" : true,
              "educationalSemanticDensity" : true,
              "educationalTypicalAgeRange" : true,
              "educationalTypicalLearningTime" : true,
              "educationalTypicalLearningTimeDescription" : true,
              "eventLabels" : true,
              "generalAggregationLevel" : true,
              "generalCoverage" : true,
              "generalDescription" : true,
              "generalIdentifier" : true,
              "generalKeyword" : true,
              "generalKeywordAuto" : true,
              "generalLanguage" : true,
              "generalStructure" : true,
              "generalTitle" : true,
              "generalTitleAuto" : true,
              "labels" : true,
              "lifeCycleStatus" : true,
              "lifeCycleVersion" : true,
              "lifecycleContribute" : true,
              "mecIdentifier" : true,
              "postLabels" : true,
              "questionLabels" : true,
              "relationIdentifierKind" : true,
              "responseState" : true,
              "rightsAccess" : true,
              "rightsAccessDescription" : true,
              "rightsCopyrightAndOtherRestrictions" : true,
              "rightsCost" : true,
              "rightsDescription" : true,
              "technicalDuration" : true,
              "technicalDurationDescription" : true,
              "technicalFormat" : true,
              "technicalInstallationRemarks" : true,
              "technicalLocation" : true,
              "technicalOtherPlatformRequirements" : true,
              "technicalRequirementTypeName" : true,
              "technicalRequirementTypeNameMinMax" : true,
              "technicalSize" : true,
              "text" : true,
              "title" : true,
              "titleLinks" : true,
              "userCountry" : true,
              "userDni" : true,
              "userEducativeCenter" : true,
              "userLabels" : true,
              "userLabelsAuto" : true,
              "userLocality" : true,
              "userLogin" : true,
              "userMail" : true,
              "userName" : true,
              "userNameSurname" : true,
              "userNameSurnameAuto" : true,
              "userPassword" : true,
              "userPlace" : true,
              "userProvince" : true,
              "userSurName" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "annotationEntityDescriptionDate" : true,
              "author" : true,
              "category" : true,
              "communityAdminSups" : true,
              "communityLabels" : true,
              "description" : true,
              "discussionLabels" : true,
              "educationalCognitiveProcess" : true,
              "educationalContext" : true,
              "educationalDescription" : true,
              "educationalDifficulty" : true,
              "educationalIntendedEndUserRole" : true,
              "educationalInteractivityLevel" : true,
              "educationalInteractivityType" : true,
              "educationalLanguage" : true,
              "educationalLearningResourceType" : true,
              "educationalSemanticDensity" : true,
              "educationalTypicalAgeRange" : true,
              "educationalTypicalLearningTime" : true,
              "educationalTypicalLearningTimeDescription" : true,
              "eventLabels" : true,
              "generalAggregationLevel" : true,
              "generalCoverage" : true,
              "generalDescription" : true,
              "generalIdentifier" : true,
              "generalKeyword" : true,
              "generalKeywordAuto" : true,
              "generalLanguage" : true,
              "generalStructure" : true,
              "generalTitle" : true,
              "generalTitleAuto" : true,
              "labels" : true,
              "lifeCycleStatus" : true,
              "lifeCycleVersion" : true,
              "lifecycleContribute" : true,
              "mecIdentifier" : true,
              "postLabels" : true,
              "questionLabels" : true,
              "relationIdentifierKind" : true,
              "responseState" : true,
              "rightsAccess" : true,
              "rightsAccessDescription" : true,
              "rightsCopyrightAndOtherRestrictions" : true,
              "rightsCost" : true,
              "rightsDescription" : true,
              "technicalDuration" : true,
              "technicalDurationDescription" : true,
              "technicalFormat" : true,
              "technicalInstallationRemarks" : true,
              "technicalLocation" : true,
              "technicalOtherPlatformRequirements" : true,
              "technicalRequirementTypeName" : true,
              "technicalRequirementTypeNameMinMax" : true,
              "technicalSize" : true,
              "text" : true,
              "title" : true,
              "titleLinks" : true,
              "userCountry" : true,
              "userDni" : true,
              "userEducativeCenter" : true,
              "userLabels" : true,
              "userLabelsAuto" : true,
              "userLocality" : true,
              "userLogin" : true,
              "userMail" : true,
              "userName" : true,
              "userNameSurname" : true,
              "userNameSurnameAuto" : true,
              "userPassword" : true,
              "userPlace" : true,
              "userProvince" : true,
              "userSurName" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "additional fields" : { "feed_node" : "feed_node" }
    },
    "enabled" : "1",
    "read_only" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ag_section_search_solr_sarnia_default_search_api_server() {
  $items = array();
  $items['ode_search'] = entity_import('search_api_server', '{
    "name" : "ode_search",
    "machine_name" : "ode_search",
    "description" : "",
    "class" : "sarnia_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "agrega2-orq",
      "port" : "8080",
      "path" : "\\/Orquestador\\/rest\\/solr",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO",
      "autocorrect_spell" : 0,
      "autocorrect_suggest_words" : 0
    },
    "enabled" : "1"
  }');
  return $items;
}
