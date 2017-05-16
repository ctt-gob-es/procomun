<?php
/**
 * @file
 * ag_section_podcast.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_podcast_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_podcast_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ag_section_podcast_node_info() {
  $items = array(
    'podcast' => array(
      'name' => t('Podcast'),
      'base' => 'node_content',
      'description' => t('Use Podcasts to share in communities posts with SoundCloud widget embed.'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
