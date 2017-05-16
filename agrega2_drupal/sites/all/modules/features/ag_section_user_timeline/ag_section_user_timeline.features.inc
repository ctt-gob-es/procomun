<?php
/**
 * @file
 * ag_section_user_timeline.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_user_timeline_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_user_timeline_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function ag_section_user_timeline_default_search_api_index() {
  $items = array();
  $items['user_timeline'] = entity_import('search_api_index', '{
    "name" : "User timeline",
    "machine_name" : "user_timeline",
    "description" : null,
    "server" : "community_wall_mysql_",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "author:flag_follow_user_user" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "comment" : { "type" : "integer" },
        "comments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "created" : { "type" : "date" },
        "field_answer_state" : { "type" : "string" },
        "field_author_others" : { "type" : "list\\u003Cstring\\u003E" },
        "field_author_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_categories" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_certified" : { "type" : "boolean" },
        "field_debate_state" : { "type" : "string" },
        "field_keywords" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_labels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_poll_status" : { "type" : "integer" },
        "field_solrid" : { "type" : "string" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_membership" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "og_membership" },
        "og_membership:id" : { "type" : "list\\u003Cinteger\\u003E" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "string" },
        "title_field" : { "type" : "string" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "post" : "post",
              "external_content" : "external_content",
              "debate" : "debate",
              "poll" : "poll",
              "event" : "event",
              "itinerary" : "itinerary",
              "podcast" : "podcast",
              "question" : "question",
              "ode" : "ode",
              "recurso_de_aprendizaje" : "recurso_de_aprendizaje",
              "answer" : "answer",
              "webinar" : "webinar"
            }
          }
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
