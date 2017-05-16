<?php

  /**
   * Plugin definition.
   */
  $plugin = array(
    'title' => t('Ag reports content'),
    'category' => t('Agrega2'),
    'render callback' => 'ag_reports_report_content_type_render',
    'edit form' => 'ag_reports_report_content_type_edit_form',
  );


/**
 * Render callback.
 */
function ag_reports_report_content_type_render($subtype, $conf, $args, $context) {
  // Get the selected form form panel options:
  $selected_form = $conf['form-render'];

  // @TODO Add the files necesaries to avoid do a module_load_include:
  $form_state = array(
    'build_info' => array(
      'args' => array(),
    ),
  );
  module_load_include('inc', 'control_center_reports', "includes/forms/$selected_form");

  $block = new stdClass();
  $block->title = '<none>';
  $block->content = drupal_build_form($selected_form, $form_state);

  return $block;
}

/**
 * Config form for ag_reports_report_content_type. This form allow us to select a ag report available.
 */
function ag_reports_report_content_type_edit_form($form, &$form_state) {
  $form_options = control_center_reports_get_available_reports();
  // Get all reports types available:
  $form['form-render'] = array(
    '#type' => 'select',
    '#title' => t('Form to render'),
    '#options' => $form_options,
    '#default_value' => isset($form_state['conf']['form-render']) ? $form_state['conf']['form-render'] : 0,
  );

  return $form;
}

/**
 * Submit callback for ag_reports_report_content_type_edit_form.
 */
function ag_reports_report_content_type_edit_form_submit($form, &$form_state) {
  // Save teh selected form:
  $form_state['conf']['form-render'] = $form_state['values']['form-render'];
}
