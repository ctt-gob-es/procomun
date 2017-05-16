<?php
/**
 * Form to configure organizations to send notifications about certifiable odes
 */
function notification_organization_form($form, &$form_state) {

  //Get organizations options
  $options = array();
  $view_result = views_get_view_result('list_organizations_filter', 'entityreference_1');
  
  foreach ($view_result as $result) {
    $options[$result->uid] = $result->users_name;
  }

  //Get saved options
  $default_value = variable_get('notification_organization', array());

  $form['notification_organization'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Select organizations to notify certifiable ode'),
    '#default_value' => !empty($default_value) ? $default_value : array(),
  );

  return system_settings_form($form);
}