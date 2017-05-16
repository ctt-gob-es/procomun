<?php
/**
 * @file
 * control_center_boosting.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function control_center_boosting_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
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
 * Implements hook_views_api().
 */
function control_center_boosting_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function control_center_boosting_node_info() {
  $items = array(
    'solr_fields' => array(
      'name' => t('Solr fields'),
      'base' => 'node_content',
      'description' => t('Content type to boosting of Solr fields.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
