<?php
/**
 * @file
 * ag_learning_itinerary.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_learning_itinerary_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function ag_learning_itinerary_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function ag_learning_itinerary_flag_default_flags() {
  $flags = array();
  // Exported flag: "Learning path".
  $flags['learning_path_content'] = array(
    'entity_type' => 'node',
    'title' => 'Learning path',
    'global' => 0,
    'types' => array(
      0 => 'post',
      1 => 'external_content',
      2 => 'itinerary',
      3 => 'podcast',
      4 => 'ode',
      5 => 'webinar',
    ),
    'flag_short' => 'Add to learning path',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -7,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'upcoming_events' => 0,
      'newsletter' => 0,
      'lasts' => 0,
      'listing' => 0,
      'diff_standard' => 0,
      'PDF' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'activities' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ag_learning_itinerary',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Learning path interest content".
  $flags['learning_path_interest_content'] = array(
    'entity_type' => 'node',
    'title' => 'Learning path interest content',
    'global' => 0,
    'types' => array(
      0 => 'post',
      1 => 'external_content',
      2 => 'itinerary',
      3 => 'podcast',
      4 => 'ode',
      5 => 'webinar',
    ),
    'flag_short' => 'Add to learning path',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remove',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -6,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'upcoming_events' => 0,
      'newsletter' => 0,
      'lasts' => 0,
      'listing' => 0,
      'diff_standard' => 0,
      'PDF' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'activities' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ag_learning_itinerary',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function ag_learning_itinerary_node_info() {
  $items = array(
    'itinerary' => array(
      'name' => t('Itinerario de aprendizaje'),
      'base' => 'node_content',
      'description' => '',
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
function ag_learning_itinerary_default_search_api_index() {
  $items = array();
  $items['my_learning_paths'] = entity_import('search_api_index', '{
    "name" : "My learning paths",
    "machine_name" : "my_learning_paths",
    "description" : null,
    "server" : "search_learning_paths",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_knowledge_area" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_labels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_learning_context" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "itinerary" : "itinerary" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
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
        "search_api_transliteration" : { "status" : 0, "weight" : "15", "settings" : { "fields" : [] } },
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
function ag_learning_itinerary_default_search_api_server() {
  $items = array();
  $items['search_learning_paths'] = entity_import('search_api_server', '{
    "name" : "Search learning paths",
    "machine_name" : "search_learning_paths",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 1 },
      "indexes" : { "my_learning_paths" : {
          "nid" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_labels" : {
            "table" : "search_api_db_my_learning_paths_field_labels",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_knowledge_area" : {
            "table" : "search_api_db_my_learning_paths_field_knowledge_area",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_learning_context" : {
            "table" : "search_api_db_my_learning_paths_field_learning_context",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_my_learning_paths",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_my_learning_paths_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
