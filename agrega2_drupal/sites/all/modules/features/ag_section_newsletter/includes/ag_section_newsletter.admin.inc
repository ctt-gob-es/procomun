<?php

/**
 * Return the OG simplenews config form.
 */
function ag_section_newsletter_admin_form($form, &$form_state) {
  $form = array();
  // Get the bundles that are group content:
  $og_groups = og_get_all_group_bundle();

  // Get the default bundles that are groups:
  $current_groups = variable_get('ag_section_newsletter_groups_with_default_newsletter', array());
  $form['ag_section_newsletter_groups_with_default_newsletter'] = array(
    '#title' => t('Select the content types which will have a default newsletter when it is created'),
    '#type' => 'checkboxes',
    '#options' => $og_groups['node'],
    '#default_value' => $current_groups,
  );

  return system_settings_form($form);
}

