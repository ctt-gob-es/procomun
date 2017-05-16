<?php
/**
 * @file
 * ag_section_recursos_de_aprendizaje.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ag_section_recursos_de_aprendizaje_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function ag_section_recursos_de_aprendizaje_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: agrega2_home_highlighted_nodeque
  $nodequeues['agrega2_home_highlighted_nodeque'] = array(
    'name' => 'agrega2_home_highlighted_nodeque',
    'title' => 'agrega2_home_highlighted_nodequeue',
    'subqueue_title' => '',
    'size' => 8,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'ode',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
