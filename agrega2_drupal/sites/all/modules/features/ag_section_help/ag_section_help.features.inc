<?php
/**
 * @file
 * ag_section_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_help_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ag_section_help_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function ag_section_help_default_message_type() {
  $items = array();
  $items['new_faq_accepted'] = entity_import('message_type', '{
    "name" : "new_faq_accepted",
    "description" : "New FAQ accepted",
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
          "value" : "\\u003Cp\\u003ES\\u0027ha validat i s\\u0027ha publicat la seva pregunta \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ES\\u0027ha validat i s\\u0027ha publicat la seva pregunta \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EIt has been validated and published his question \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EIt has been validated and published his question \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003ESe ha validado y se ha publicado su pregunta \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ESe ha validado y se ha publicado su pregunta \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EIt baliozkotu eta argitaratu dira bere galdera \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EIt baliozkotu eta argitaratu dira bere galdera \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EFoi validado e publicado a s\\u00faa pregunta \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EFoi validado e publicado a s\\u00faa pregunta \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:faq-path]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_pending_faq'] = entity_import('message_type', '{
    "name" : "new_pending_faq",
    "description" : "New pending FAQ",
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
          "value" : "\\u003Cp\\u003EL\\u0027usuari\\u0026nbsp;[message:user:name] ha sol\\u00b7licitat la creaci\\u00f3 d\\u0027una nova pregunta freq\\u00fcent \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EL\\u0027usuari\\u00a0[message:user:name] ha sol\\u00b7licitat la creaci\\u00f3 d\\u0027una nova pregunta freq\\u00fcent \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EThe user [message:user:name] has requested the creation of a new question \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EThe user [message:user:name] has requested the creation of a new question \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003EEl usuario [message:user:name] ha solicitado la creaci\\u00f3n de una nueva pregunta frecuente \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEl usuario [message:user:name] ha solicitado la creaci\\u00f3n de una nueva pregunta frecuente \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EErabiltzaileak\\u0026nbsp;[message:user:name] galdera komun berri bat sortzea eskatu du \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EErabiltzaileak\\u00a0[message:user:name] galdera komun berri bat sortzea eskatu du \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EO usuario\\u0026nbsp;[message:user:name] solicitou a creaci\\u00f3n dunha nova pregunta com\\u00fan \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EO usuario\\u00a0[message:user:name] solicitou a creaci\\u00f3n dunha nova pregunta com\\u00fan \\u0022[message:field_question_title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[procomun:manage-faq-path]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function ag_section_help_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'functionality' => array(
      'name' => t('Funcionalidad'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'manual' => array(
      'name' => t('Manual'),
      'base' => 'node_content',
      'description' => t('Tipo de contenido para el manual de la sección de ayuda y faqs'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
