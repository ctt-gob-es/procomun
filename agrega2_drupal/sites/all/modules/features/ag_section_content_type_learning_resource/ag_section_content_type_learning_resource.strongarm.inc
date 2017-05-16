<?php
/**
 * @file
 * ag_section_content_type_learning_resource.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ag_section_content_type_learning_resource_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_recurso_de_aprendizaje';
  $strongarm->value = 0;
  $export['comment_anonymous_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_recurso_de_aprendizaje';
  $strongarm->value = 0;
  $export['comment_default_mode_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_recurso_de_aprendizaje';
  $strongarm->value = '50';
  $export['comment_default_per_page_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_recurso_de_aprendizaje';
  $strongarm->value = 0;
  $export['comment_form_location_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_recurso_de_aprendizaje';
  $strongarm->value = '0';
  $export['comment_preview_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_recurso_de_aprendizaje';
  $strongarm->value = '2';
  $export['comment_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_recurso_de_aprendizaje';
  $strongarm->value = 0;
  $export['comment_subject_field_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__recurso_de_aprendizaje';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
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
      'lasts' => array(
        'custom_settings' => TRUE,
      ),
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'newsletter' => array(
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
      'learning_path_content' => array(
        'custom_settings' => FALSE,
      ),
      'learning_path_interest_content' => array(
        'custom_settings' => FALSE,
      ),
      'PDF' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '18',
        ),
        'language' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'flag_og_newsletter' => array(
          'newsletter' => array(
            'weight' => '3',
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
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_recurso_de_aprendizaje';
  $strongarm->value = 1;
  $export['i18n_node_extended_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_recurso_de_aprendizaje';
  $strongarm->value = array();
  $export['i18n_node_options_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_recurso_de_aprendizaje';
  $strongarm->value = '4';
  $export['language_content_type_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_recurso_de_aprendizaje';
  $strongarm->value = array();
  $export['menu_options_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_recurso_de_aprendizaje';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_recurso_de_aprendizaje';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_recurso_de_aprendizaje';
  $strongarm->value = '0';
  $export['node_preview_recurso_de_aprendizaje'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_recurso_de_aprendizaje';
  $strongarm->value = 0;
  $export['node_submitted_recurso_de_aprendizaje'] = $strongarm;

  return $export;
}
