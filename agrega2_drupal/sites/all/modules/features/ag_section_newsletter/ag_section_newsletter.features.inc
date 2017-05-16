<?php
/**
 * @file
 * ag_section_newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_newsletter_ctools_plugin_api($module = NULL, $api = NULL) {
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
function ag_section_newsletter_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function ag_section_newsletter_flag_default_flags() {
  $flags = array();
  // Exported flag: "Og Newsletter".
  $flags['og_newsletter'] = array(
    'entity_type' => 'node',
    'title' => 'Og Newsletter',
    'global' => 0,
    'types' => array(
      0 => 'post',
      1 => 'debate',
      2 => 'poll',
      3 => 'event',
      4 => 'podcast',
      5 => 'question',
      6 => 'ode',
      7 => 'recurso_de_aprendizaje',
      8 => 'webinar',
    ),
    'flag_short' => 'Add to newsletter',
    'flag_long' => 'Click to add this content to next newsletter',
    'flag_message' => '',
    'unflag_short' => 'Remove from newsletter',
    'unflag_long' => 'Click to remove this content from next newsletter',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -11,
    'show_in_links' => array(
      'newsletter' => 'newsletter',
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'upcoming_events' => 0,
      'lasts' => 0,
      'listing' => 0,
      'diff_standard' => 0,
      'PDF' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'activities' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ag_section_newsletter',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function ag_section_newsletter_node_info() {
  $items = array(
    'simplenews' => array(
      'name' => t('Boletín de noticias'),
      'base' => 'node_content',
      'description' => t('Un boletín de noticias para ser enviado a la lista de suscritos'),
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
