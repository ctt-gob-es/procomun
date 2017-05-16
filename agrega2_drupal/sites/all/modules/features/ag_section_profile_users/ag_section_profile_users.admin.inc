<?php
/**
 * Form to configure badges to show in profile user
 */
function cert_organization_form($form, &$form_state) {

  //Get organizations options
  $options = array();
  $view_result = views_get_view_result('list_organizations_filter', 'entityreference_1');
  
  foreach ($view_result as $result) {
    $options[$result->uid] = $result->users_name;
  }

  //Get saved options
  $default_value = variable_get('cert_organization', array());

  $form['cert_organization'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Select organizations to certificate ode'),
    '#default_value' => !empty($default_value) ? $default_value : array(),
  );

  return system_settings_form($form);
}