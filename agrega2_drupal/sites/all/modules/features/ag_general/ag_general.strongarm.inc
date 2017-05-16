<?php
/**
 * @file
 * ag_general.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ag_general_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_append_to_url';
  $strongarm->value = '';
  $export['service_links_append_to_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_block_not_node_front';
  $strongarm->value = 0;
  $export['service_links_block_not_node_front'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_block_not_node_style';
  $strongarm->value = '2';
  $export['service_links_block_not_node_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_category_types';
  $strongarm->value = array();
  $export['service_links_category_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_category_vocs';
  $strongarm->value = array(
    4 => 0,
    7 => 0,
    5 => 0,
    22 => 0,
    8 => 0,
    18 => 0,
    6 => 0,
    2 => 0,
    23 => 0,
    9 => 0,
    1 => 0,
    24 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
    3 => 0,
    21 => 0,
    13 => 0,
    15 => 0,
    17 => 0,
    19 => 0,
    20 => 0,
    14 => 0,
  );
  $export['service_links_category_vocs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_check_icons';
  $strongarm->value = 1;
  $export['service_links_check_icons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_domain_redirect';
  $strongarm->value = '';
  $export['service_links_domain_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_hide_for_author';
  $strongarm->value = 0;
  $export['service_links_hide_for_author'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_hide_if_unpublished';
  $strongarm->value = 1;
  $export['service_links_hide_if_unpublished'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_label_in_node';
  $strongarm->value = 'Compartir en:';
  $export['service_links_label_in_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_link_view_modes';
  $strongarm->value = array(
    'full' => 0,
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'upcoming_events' => 0,
    'newsletter' => 0,
    'lasts' => 0,
    'listing' => 0,
    'diff_standard' => 0,
    'PDF' => 0,
    'email_plain' => 0,
    'email_html' => 0,
    'email_textalt' => 0,
    'token' => 0,
    'activities' => 0,
  );
  $export['service_links_link_view_modes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_new_window';
  $strongarm->value = '1';
  $export['service_links_new_window'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_node_types';
  $strongarm->value = array(
    'post' => 'post',
    'event' => 'event',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'recurso_de_aprendizaje' => 'recurso_de_aprendizaje',
    'webinar' => 'webinar',
    'article' => 0,
    'banner' => 0,
    'simplenews' => 0,
    'social_network' => 0,
    'external_content' => 0,
    'debate' => 0,
    'poll' => 0,
    'faq' => 0,
    'functionality' => 0,
    'manual' => 0,
    'question' => 0,
    'page' => 0,
    'answer' => 0,
    'solr_fields' => 0,
  );
  $export['service_links_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_node_view_modes';
  $strongarm->value = array(
    'full' => 'full',
    'teaser' => 'teaser',
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
    'upcoming_events' => 0,
    'newsletter' => 0,
    'lasts' => 0,
    'listing' => 0,
    'diff_standard' => 0,
    'PDF' => 0,
    'email_plain' => 0,
    'email_html' => 0,
    'email_textalt' => 0,
    'token' => 0,
    'activities' => 0,
  );
  $export['service_links_node_view_modes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_override_title';
  $strongarm->value = '2';
  $export['service_links_override_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_override_title_text';
  $strongarm->value = '[node:title_field]';
  $export['service_links_override_title_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_page_match_for_node';
  $strongarm->value = '';
  $export['service_links_page_match_for_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_path_icons';
  $strongarm->value = 'sites/all/themes/nexus/images/service_links';
  $export['service_links_path_icons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_short_links_type';
  $strongarm->value = '1';
  $export['service_links_short_links_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_short_links_use';
  $strongarm->value = '1';
  $export['service_links_short_links_use'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_show';
  $strongarm->value = array(
    'delicious' => 0,
    'digg' => 0,
    'stumbleupon' => 0,
    'twitter' => 1,
    'pingthis' => 0,
    'reddit' => 0,
    'slashdot' => 0,
    'newsvine' => 0,
    'furl' => 0,
    'facebook' => 1,
    'myspace' => 0,
    'google' => 0,
    'google_plus' => 1,
    'yahoo' => 0,
    'linkedin' => 1,
    'technorati' => 0,
    'technorati_favorite' => 0,
    'icerocket' => 0,
    'misterwong' => 0,
    'mixx' => 0,
    'box' => 0,
    'blinklist' => 0,
    'identica' => 0,
    'newskicks' => 0,
    'diigo' => 0,
    'Symbaloo' => 1,
  );
  $export['service_links_show'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_style';
  $strongarm->value = '2';
  $export['service_links_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_visibility_for_node';
  $strongarm->value = '0';
  $export['service_links_visibility_for_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_weight';
  $strongarm->value = array(
    'delicious' => '-94',
    'digg' => '-93',
    'stumbleupon' => '-79',
    'twitter' => '-100',
    'pingthis' => '-82',
    'reddit' => '-81',
    'slashdot' => '-80',
    'newsvine' => '-83',
    'furl' => '-91',
    'facebook' => '-99',
    'myspace' => '-85',
    'google' => '-90',
    'google_plus' => '-98',
    'yahoo' => '-76',
    'linkedin' => '-97',
    'technorati' => '-77',
    'technorati_favorite' => '-78',
    'icerocket' => '-89',
    'misterwong' => '-87',
    'mixx' => '-86',
    'box' => '-95',
    'blinklist' => '-96',
    'identica' => '-88',
    'newskicks' => '-84',
    'diigo' => '-92',
    'Symbaloo' => '0',
  );
  $export['service_links_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'service_links_weight_in_node';
  $strongarm->value = '10';
  $export['service_links_weight_in_node'] = $strongarm;

  return $export;
}
