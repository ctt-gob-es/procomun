<?php
/**
 * @file
 * ag_visualization_ode.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ag_visualization_ode_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_ode';
  $strongarm->value = 0;
  $export['comment_anonymous_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_ode';
  $strongarm->value = 1;
  $export['comment_default_mode_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_ode';
  $strongarm->value = '10';
  $export['comment_default_per_page_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_ode';
  $strongarm->value = 0;
  $export['comment_form_location_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_ode';
  $strongarm->value = '2';
  $export['comment_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_ode';
  $strongarm->value = '0';
  $export['comment_preview_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_ode';
  $strongarm->value = 0;
  $export['comment_subject_field_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__ode';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'lasts' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'newsletter' => array(
        'custom_settings' => TRUE,
      ),
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'activities' => array(
        'custom_settings' => TRUE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_events' => array(
        'custom_settings' => TRUE,
      ),
      'PDF' => array(
        'custom_settings' => FALSE,
      ),
      'learning_path_content' => array(
        'custom_settings' => TRUE,
      ),
      'learning_path_interest_content' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '22',
        ),
        'xmlsitemap' => array(
          'weight' => '23',
        ),
      ),
      'display' => array(
        'flag_og_newsletter' => array(
          'newsletter' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'flag_learning_path_content' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'flag_learning_path_interest_content' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_ode';
  $strongarm->value = 1;
  $export['i18n_node_extended_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_ode';
  $strongarm->value = array();
  $export['i18n_node_options_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_ode';
  $strongarm->value = '0';
  $export['language_content_type_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ode';
  $strongarm->value = array();
  $export['menu_options_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_ode';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ode';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_ode';
  $strongarm->value = '0';
  $export['node_preview_ode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_ode';
  $strongarm->value = 1;
  $export['node_submitted_ode'] = $strongarm;

  return $export;
}
