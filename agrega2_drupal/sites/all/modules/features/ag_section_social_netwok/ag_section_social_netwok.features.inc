<?php
/**
 * @file
 * ag_section_social_netwok.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_social_netwok_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
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
function ag_section_social_netwok_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ag_section_social_netwok_image_default_styles() {
  $styles = array();

  // Exported image style: 32x32.
  $styles['32x32'] = array(
    'name' => '32x32',
    'label' => '32x32',
    'effects' => array(
      3 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 32,
          'height' => 32,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_image.
  $styles['profile_image'] = array(
    'name' => 'profile_image',
    'label' => 'Profile image',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_message_type().
 */
function ag_section_social_netwok_default_message_type() {
  $items = array();
  $items['community_accepted'] = entity_import('message_type', '{
    "name" : "community_accepted",
    "description" : "Community accepted",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003ELa teva sol\\u00b7licitud de creaci\\u00f3 de la nova comunitat [message:field-social-network-ref:title-field] ha estat acceptada per un administrador\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ELa teva sol\\u00b7licitud de creaci\\u00f3 de la nova comunitat [message:field-social-network-ref:title-field] ha estat acceptada per un administrador\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EYour request to create the new community [message:field-social-network-ref:title-field] has been accepted by an administrator\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EYour request to create the new community [message:field-social-network-ref:title-field] has been accepted by an administrator\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003ETu solicitud de creaci\\u00f3n de la nueva comunidad [message:field-social-network-ref:title-field] ha sido aceptada por un administrador\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ETu solicitud de creaci\\u00f3n de la nueva comunidad [message:field-social-network-ref:title-field] ha sido aceptada por un administrador\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EKomunitate [message:field-social-network-ref:title-field] berri bat sortzeko eskaera onartu administratzaile batek.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EKomunitate [message:field-social-network-ref:title-field] berri bat sortzeko eskaera onartu administratzaile batek.\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EA s\\u00faa petici\\u00f3n para crear la nova comunidade [message:field-social-network-ref:title-field] foi aceptada por un administrador\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EA s\\u00faa petici\\u00f3n para crear la nova comunidade [message:field-social-network-ref:title-field] foi aceptada por un administrador\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['community_rejected'] = entity_import('message_type', '{
    "name" : "community_rejected",
    "description" : "Community rejected",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003ELa teva sol\\u00b7licitud de creaci\\u00f3 d\\u0027una nova comunitat ha estat rebutjada per un administrador\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ELa teva sol\\u00b7licitud de creaci\\u00f3 d\\u0027una nova comunitat ha estat rebutjada per un administrador\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EYour request to create a new community has been rejected by an administrator\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EYour request to create a new community has been rejected by an administrator\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003ETu solicitud de creaci\\u00f3n de una nueva comunidad ha sido rechazada por un administrador\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ETu solicitud de creaci\\u00f3n de una nueva comunidad ha sido rechazada por un administrador\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EKomunitate berri bat sortzeko eskaera baztertu administratzaile batek\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EKomunitate berri bat sortzeko eskaera baztertu administratzaile batek\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EA s\\u00faa petici\\u00f3n para crear unha nova comunidade foi rexeitada por un administrador\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EA s\\u00faa petici\\u00f3n para crear unha nova comunidade foi rexeitada por un administrador\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_pending_community'] = entity_import('message_type', '{
    "name" : "new_pending_community",
    "description" : "New pending community",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003EL\\u0027usuari [message:user:name] ha sol\\u00b7licitat la creaci\\u00f3 d\\u0027una nova comunitat\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EL\\u0027usuari [message:user:name] ha sol\\u00b7licitat la creaci\\u00f3 d\\u0027una nova comunitat\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EThe user [message:user:name] has requested the creation of a new community\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EThe user [message:user:name] has requested the creation of a new community\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003EEl usuario [message:user:name] ha solicitado la creaci\\u00f3n de una nueva comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEl usuario [message:user:name] ha solicitado la creaci\\u00f3n de una nueva comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EErabiltzaileak [message:user:name] komunitate berri bat sortzea eskatu du\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EErabiltzaileak [message:user:name] komunitate berri bat sortzea eskatu du\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EO usuario [message:user:name] solicitou a creaci\\u00f3n dunha nova comunidade\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EO usuario [message:user:name] solicitou a creaci\\u00f3n dunha nova comunidade\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['requested_community_creation_pending'] = entity_import('message_type', '{
    "name" : "requested_community_creation_pending",
    "description" : "Requested community creation pending",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003ELa seva sol\\u00b7licitud de creaci\\u00f3 de la comunitat [message:field-social-network-ref:title-field] ha estat rebuda i est\\u00e0 a l\\u0027espera de ser processada per algun administrador del sistema.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ELa seva sol\\u00b7licitud de creaci\\u00f3 de la comunitat [message:field-social-network-ref:title-field] ha estat rebuda i est\\u00e0 a l\\u0027espera de ser processada per algun administrador del sistema.\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EYour request to create the community [message:field-social-network-ref:title-field] has been received and awaits to be processed by a system administrator.\\u003C\\/p\\u003E",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EYour request to create the community [message:field-social-network-ref:title-field] has been received and awaits to be processed by a system administrator.\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003ESu solicitud de creaci\\u00f3n de la comunidad [message:field-social-network-ref:title-field] ha sido recibida y est\\u00e1 a la espera de ser procesada por alg\\u00fan administrador del sistema.\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ESu solicitud de creaci\\u00f3n de la comunidad [message:field-social-network-ref:title-field] ha sido recibida y est\\u00e1 a la espera de ser procesada por alg\\u00fan administrador del sistema.\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EKomunitate ([message:field-social-network-ref:title-field]) bat sortzeko eskaera jaso ditu, eta sistemaren administratzaile batek tratatuko dira zain.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EKomunitate ([message:field-social-network-ref:title-field]) bat sortzeko eskaera jaso ditu, eta sistemaren administratzaile batek tratatuko dira zain.\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003ES\\u00faa solicitude para crear la comunidade [message:field-social-network-ref:title-field] foi recibida e est\\u00e1 \\u00e1 espera ser\\u00e1n procesados por un administrador do sistema.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ES\\u00faa solicitude para crear la comunidade [message:field-social-network-ref:title-field] foi recibida e est\\u00e1 \\u00e1 espera ser\\u00e1n procesados por un administrador do sistema.\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function ag_section_social_netwok_node_info() {
  $items = array(
    'social_network' => array(
      'name' => t('Comunidad'),
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
function ag_section_social_netwok_default_search_api_index() {
  $items = array();
  $items['my_favourites'] = entity_import('search_api_index', '{
    "name" : "My favourites",
    "machine_name" : "my_favourites",
    "description" : null,
    "server" : "community_wall_mysql_",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "author:flag_favorite_flagged" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_categories" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_labels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "flag_favorite_user" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "nid" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_membership" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "og_membership" },
        "og_membership:id" : { "type" : "list\\u003Cinteger\\u003E" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
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
              "podcast" : "podcast",
              "ode" : "ode",
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
  $items['users_index'] = entity_import('search_api_index', '{
    "name" : "Users index",
    "machine_name" : "users_index",
    "description" : null,
    "server" : "search_community_members_list",
    "item_type" : "user",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "name" : { "type" : "string" },
        "og_membership:group_type" : { "type" : "list\\u003Cstring\\u003E" },
        "og_membership:id" : { "type" : "list\\u003Cinteger\\u003E" },
        "og_membership:state" : { "type" : "list\\u003Cinteger\\u003E" },
        "og_membership:type" : {
          "type" : "list\\u003Cstring\\u003E",
          "entity_type" : "og_membership_type"
        },
        "og_user_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_user_node:nid" : { "type" : "list\\u003Cinteger\\u003E" },
        "profile_datos_personales:field_country_personal_fc" : { "type" : "integer", "entity_type" : "field_collection_item" },
        "profile_datos_personales:field_edu_center_personal_fc" : { "type" : "integer", "entity_type" : "field_collection_item" },
        "profile_datos_personales:field_locality_personal_fc" : { "type" : "integer", "entity_type" : "field_collection_item" },
        "profile_datos_personales:field_name_surname" : { "type" : "integer", "entity_type" : "field_collection_item" },
        "profile_datos_personales:field_province_personal_fc" : { "type" : "integer", "entity_type" : "field_collection_item" },
        "profile_datos_personales:field_province_personal_fc:field_province" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "uid" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['wall_contents_index'] = entity_import('search_api_index', '{
    "name" : "Wall contents index",
    "machine_name" : "wall_contents_index",
    "description" : null,
    "server" : "community_wall_mysql_",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_categories" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_labels" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "string" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "og_membership" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "og_membership" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" },
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

/**
 * Implements hook_default_search_api_server().
 */
function ag_section_social_netwok_default_search_api_server() {
  $items = array();
  $items['community_wall_mysql_'] = entity_import('search_api_server', '{
    "name" : "community wall(MySQL)",
    "machine_name" : "community_wall_mysql_",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : {
        "wall_contents_index" : {
          "type" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_wall_contents_index_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "og_membership" : {
            "table" : "search_api_db_wall_contents_index_og_membership",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_labels" : {
            "table" : "search_api_db_wall_contents_index_field_labels",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_categories" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "field_categories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_wall_contents_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_wall_contents_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          }
        },
        "user_timeline" : {
          "nid" : {
            "table" : "search_api_db_user_timeline",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_user_timeline",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_user_timeline",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_user_timeline",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_user_timeline",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_user_timeline",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_labels" : {
            "table" : "search_api_db_user_timeline_field_labels",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_user_timeline_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_categories" : {
            "table" : "search_api_db_user_timeline",
            "column" : "field_categories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "og_membership" : {
            "table" : "search_api_db_user_timeline_og_membership",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_user_timeline",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_user_timeline_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "og_membership:id" : {
            "table" : "search_api_db_user_timeline_og_membership_id",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "author:flag_follow_user_user" : {
            "table" : "search_api_db_user_timeline_author_flag_follow_user_user",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_user_timeline",
            "column" : "title",
            "type" : "string",
            "boost" : "1.0"
          },
          "comment" : {
            "table" : "search_api_db_user_timeline",
            "column" : "comment",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comments" : {
            "table" : "search_api_db_user_timeline_comments",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "title_field" : {
            "table" : "search_api_db_user_timeline",
            "column" : "title_field",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_user_timeline_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_solrid" : {
            "table" : "search_api_db_user_timeline",
            "column" : "field_solrid",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_answer_state" : {
            "table" : "search_api_db_user_timeline",
            "column" : "field_answer_state",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_debate_state" : {
            "table" : "search_api_db_user_timeline",
            "column" : "field_debate_state",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_author_others" : {
            "table" : "search_api_db_user_timeline_field_author_others",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_author_ref" : {
            "table" : "search_api_db_user_timeline_field_author_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_certified" : {
            "table" : "search_api_db_user_timeline",
            "column" : "field_certified",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_keywords" : {
            "table" : "search_api_db_user_timeline_field_keywords",
            "column" : "field_keywords",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_poll_status" : {
            "table" : "search_api_db_user_timeline",
            "column" : "field_poll_status",
            "type" : "integer",
            "boost" : "1.0"
          }
        },
        "favorites" : {
          "nid" : {
            "table" : "search_api_db_favorites",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_favorites",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_favorites",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_favorites_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "flag_favorite_user" : {
            "table" : "search_api_db_favorites_flag_favorite_user",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_favorites",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_favorites_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_categories" : {
            "table" : "search_api_db_favorites",
            "column" : "field_categories",
            "type" : "integer",
            "boost" : "1.0"
          }
        },
        "my_favourites" : {
          "nid" : {
            "table" : "search_api_db_my_favourites",
            "column" : "nid",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_my_favourites",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_my_favourites",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_my_favourites",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_my_favourites",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_my_favourites",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_labels" : {
            "table" : "search_api_db_my_favourites_field_labels",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_my_favourites_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_categories" : {
            "table" : "search_api_db_my_favourites",
            "column" : "field_categories",
            "type" : "integer",
            "boost" : "1.0"
          },
          "og_membership" : {
            "table" : "search_api_db_my_favourites_og_membership",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_my_favourites",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_my_favourites_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "author:flag_favorite_flagged" : {
            "table" : "search_api_db_my_favourites_author_flag_favorite_flagged",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_membership:id" : {
            "table" : "search_api_db_my_favourites_og_membership_id",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "flag_favorite_user" : {
            "table" : "search_api_db_my_favourites_flag_favorite_user",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  $items['search_community_members_list'] = entity_import('search_api_server', '{
    "name" : "Search community members list",
    "machine_name" : "search_community_members_list",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 1 },
      "indexes" : { "users_index" : {
          "uid" : {
            "table" : "search_api_db_users_index",
            "column" : "uid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "name" : {
            "table" : "search_api_db_users_index",
            "column" : "name",
            "type" : "string",
            "boost" : "1.0"
          },
          "og_user_node" : {
            "table" : "search_api_db_users_index_og_user_node",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_users_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "og_user_node:nid" : {
            "table" : "search_api_db_users_index_og_user_node_nid",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "profile_datos_personales:field_province_personal_fc:field_province" : {
            "table" : "search_api_db_users_index",
            "column" : "profile_datos_personales_field_province_personal_fc_field_prov",
            "type" : "string",
            "boost" : "1.0"
          },
          "profile_datos_personales:field_country_personal_fc" : {
            "table" : "search_api_db_users_index",
            "column" : "profile_datos_personales_field_country_personal_fc",
            "type" : "integer",
            "boost" : "1.0"
          },
          "profile_datos_personales:field_edu_center_personal_fc" : {
            "table" : "search_api_db_users_index",
            "column" : "profile_datos_personales_field_edu_center_personal_fc",
            "type" : "integer",
            "boost" : "1.0"
          },
          "profile_datos_personales:field_locality_personal_fc" : {
            "table" : "search_api_db_users_index",
            "column" : "profile_datos_personales_field_locality_personal_fc",
            "type" : "integer",
            "boost" : "1.0"
          },
          "profile_datos_personales:field_name_surname" : {
            "table" : "search_api_db_users_index",
            "column" : "profile_datos_personales_field_name_surname",
            "type" : "integer",
            "boost" : "1.0"
          },
          "profile_datos_personales:field_province_personal_fc" : {
            "table" : "search_api_db_users_index",
            "column" : "profile_datos_personales_field_province_personal_fc",
            "type" : "integer",
            "boost" : "1.0"
          },
          "og_membership:state" : {
            "table" : "search_api_db_users_index_og_membership_state",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_membership:id" : {
            "table" : "search_api_db_users_index_og_membership_id",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "og_membership:type" : {
            "table" : "search_api_db_users_index_og_membership_type",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "og_membership:group_type" : {
            "table" : "search_api_db_users_index_og_membership_group_type",
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
