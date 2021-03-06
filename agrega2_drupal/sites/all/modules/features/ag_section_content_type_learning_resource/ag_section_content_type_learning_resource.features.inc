<?php
/**
 * @file
 * ag_section_content_type_learning_resource.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_content_type_learning_resource_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
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
 * Implements hook_node_info().
 */
function ag_section_content_type_learning_resource_node_info() {
  $items = array(
    'recurso_de_aprendizaje' => array(
      'name' => t('Recurso social'),
      'base' => 'node_content',
      'description' => t('Añadir un recurso social.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
