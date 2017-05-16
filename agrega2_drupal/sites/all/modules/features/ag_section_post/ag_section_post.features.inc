<?php
/**
 * @file
 * ag_section_post.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_post_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ag_section_post_node_info() {
  $items = array(
    'post' => array(
      'name' => t('Artículo'),
      'base' => 'node_content',
      'description' => t('Use Post to share in communities new messages.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
