<?php
/**
 * @file
 * ag_section_calendar_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_calendar_events_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_calendar_events_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ag_section_calendar_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Evento'),
      'base' => 'node_content',
      'description' => t('Crear un nuevo evento'),
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
function ag_section_calendar_events_default_search_api_index() {
  $items = array();
  $items['search_index_events_community'] = entity_import('search_api_index', '{
    "name" : "Search index for events of a community",
    "machine_name" : "search_index_events_community",
    "description" : "Search index for events of a community",
    "server" : "ag_server_events",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "field_event_date:value" : { "type" : "integer" },
        "field_event_date:value2" : { "type" : "integer" },
        "field_event_type" : { "type" : "string" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "search_api_language" : { "type" : "string" },
        "type" : { "type" : "string" }
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
function ag_section_calendar_events_default_search_api_server() {
  $items = array();
  $items['ag_server_events'] = entity_import('search_api_server', '{
    "name" : "ag_server_events",
    "machine_name" : "ag_server_events",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 1 },
      "indexes" : { "search_index_events_community" : {
          "nid" : {
            "table" : "search_api_db_search_index_events_community",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_search_index_events_community",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_search_index_events_community_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_search_index_events_community_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_event_type" : {
            "table" : "search_api_db_search_index_events_community",
            "column" : "field_event_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_search_index_events_community",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_event_date:value" : {
            "table" : "search_api_db_search_index_events_community",
            "column" : "field_event_date_value",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_event_date:value2" : {
            "table" : "search_api_db_search_index_events_community",
            "column" : "field_event_date_value2",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
