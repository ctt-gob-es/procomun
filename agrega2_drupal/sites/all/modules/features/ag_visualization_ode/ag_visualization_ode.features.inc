<?php
/**
 * @file
 * ag_visualization_ode.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_visualization_ode_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ag_visualization_ode_node_info() {
  $items = array(
    'ode' => array(
      'name' => t('Recurso de aprendizaje'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => t('Los campos marcados con un asterisco son obligatorios.'),
    ),
  );
  return $items;
}
