<?php


function og_share_admin_form() {
  $form = array();
  // Get the bundles that are group content:
  $og_bundles = og_get_all_group_content_bundle();
  // Get the og_share_allowed_contents's  default value
  $allowed_contents_default_values = variable_get('og_share_allowed_contents', array());
  $form['og_share_allowed_contents'] = array(
    '#title' => t('Select the content types that will be allowed to be shared'),
    '#type' => 'checkboxes',
    '#options' => $og_bundles['node'],
    '#default_value' => $allowed_contents_default_values,
  );

  // Get the vew modes listed for node Entity
  $entity_info = entity_get_info('node');
  foreach ($entity_info['view modes'] as $vm_key => $vm_value) {
    $view_modes_options[$vm_key] = $vm_value['label'];
  }
  // Get the og_share_allowed_view_modes's default value:
  $allowed_view_modes_default_values = variable_get('og_share_allowed_view_modes', array());
  $form['og_share_allowed_view_modes'] = array(
    '#title' => t('Select the view modes where the share link will be showed'),
    '#type' => 'checkboxes',
    '#options' => $view_modes_options,
    '#default_value' => $allowed_view_modes_default_values,
  );

  return system_settings_form($form);
}
