<?php
/**
 * @file
 * ag_external_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_external_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ag_external_content_node_info() {
  $items = array(
    'external_content' => array(
      'name' => t('Contenido externo'),
      'base' => 'node_content',
      'description' => t('Crea contenido que proviene de páginas externas por medio de un bookmarklet.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
