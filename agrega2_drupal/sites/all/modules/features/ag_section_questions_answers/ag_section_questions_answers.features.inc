<?php
/**
 * @file
 * ag_section_questions_answers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_questions_answers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_questions_answers_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ag_section_questions_answers_node_info() {
  $items = array(
    'answer' => array(
      'name' => t('Respuesta'),
      'base' => 'node_content',
      'description' => t('Crea la respuesta a una pregunta realizada'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'debate' => array(
      'name' => t('Debate'),
      'base' => 'node_content',
      'description' => t('Crea un nuevo debate en Agrega2'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'question' => array(
      'name' => t('Pregunta'),
      'base' => 'node_content',
      'description' => t('Crear una nueva pregunta'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function ag_section_questions_answers_default_search_api_index() {
  $items = array();
  $items['search_labels_for_question_and_debate'] = entity_import('search_api_index', '{
    "name" : "Search categories for question and debate",
    "machine_name" : "search_labels_for_question_and_debate",
    "description" : "Index for categories of questions and debates",
    "server" : "search_questions_and_debates",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "created" : { "type" : "date" },
        "field_categories" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : {
            "default" : "1",
            "bundles" : { "debate" : "debate", "question" : "question" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
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
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ag_section_questions_answers_default_search_api_server() {
  $items = array();
  $items['search_questions_and_debates'] = entity_import('search_api_server', '{
    "name" : "Search questions and debates",
    "machine_name" : "search_questions_and_debates",
    "description" : "This server is for search questions and debates based on the labels",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 1 },
      "indexes" : { "search_labels_for_question_and_debate" : {
          "type" : {
            "table" : "search_api_db_search_labels_for_question_and_debate",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_search_labels_for_question_and_debate",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_search_labels_for_question_and_debate",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_search_labels_for_question_and_debate",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_categories" : {
            "table" : "search_api_db_search_labels_for_question_and_debate",
            "column" : "field_categories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_search_labels_for_question_and_debate_og_group_r",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
