<?php
/**
 * @file
 * Code for ag_section_search_solr_sarnia admin forms.
 */

/**
 * Form function for admin solr autocomplete fields.
 */
function admin_solr_autocomplete_fields_form($form, &$form_state) {
  // Define search types in solr
  $types = ag_section_search_get_types();

  $default_value = variable_get('solr_autocomplete_types', array());
  $form['solr_autocomplete_types'] = array(
    '#type' => 'checkboxes',
    '#options' => $types,
    '#title' => t('Select available types for autocomplete solr search'),
    '#default_value' => !empty($default_value) ? $default_value : array(),
  );

  foreach ($types as $type => $label) {
    $key = 'solr_autocomplete_types_' . drupal_strtolower($type) . '_field';
    $default_value = variable_get($key, '');
    // Create text field for each type.
    $form[$key] = array(
      '#type' => 'textfield',
      '#title' => t('Solr field for @type', array('@type' => $label)),
      '#default_value' => !empty($default_value) ? $default_value : '',
    );
  }

  return system_settings_form($form);
}

/**
 * Validate function for admin solr autocomplete fields.
 */
function admin_solr_autocomplete_fields_form_validate($form, &$form_state) {
  // Check emtpy fields if checkbox is checked.
  $autocomplete_types = $form_state['values']['solr_autocomplete_types'];
  $autocomplete_types = array_keys(array_filter($autocomplete_types));

  if (!empty($autocomplete_types)) {
    foreach ($autocomplete_types as $type) {
      $key = 'solr_autocomplete_types_' . drupal_strtolower($type) . '_field';
      if (empty($form_state['values'][$key])) {
        form_set_error($key, t('Solr field for @field is required', array('@field' => $form['solr_autocomplete_types']['#options'][$type])));
      }
    }
  }
}
