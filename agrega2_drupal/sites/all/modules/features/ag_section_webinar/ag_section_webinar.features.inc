<?php
/**
 * @file
 * ag_section_webinar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_webinar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ag_section_webinar_node_info() {
  $items = array(
    'webinar' => array(
      'name' => t('Webinar'),
      'base' => 'node_content',
      'description' => t('Use Webinars to share in communities posts with WizIQ webinars widget embed.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
