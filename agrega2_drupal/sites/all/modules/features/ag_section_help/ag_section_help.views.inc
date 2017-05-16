<?php

/**
 * @file
 * Views definitions for 'ag_section_help'
 */

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function ag_section_help_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'ag_section_help'),
    ),
    'handlers' => array(
      // The name of my handler
      'ag_section_help_handler_vote_widget_custom_field' => array(
        // The name of the handler we are extending.
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function ag_section_help_views_data() {
  $data = array();
  // Add Ag section help group
  $data['custom']['table']['group'] = t('Custom');
  $data['custom']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );

  // Add custom field
  $data['custom']['vote_widget_custom_field'] = array(
    'title' => t('Vote widget custom field'),
    'help' => t('Provides a vote widget custom field.'),
    'field' => array(
      'handler' => 'ag_section_help_handler_vote_widget_custom_field',
    ),
  );

  return $data;
}
