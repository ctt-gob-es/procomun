<?php
/**
 * Form to configure cl@ve variables
 */
function clave_configuration_form($form, &$form_state) {

  $default_value = variable_get('clave_url_server', '');
  $form['clave_url_server'] = array(
    '#type' => 'textfield',
    '#title' => t('Cl@ve url server'),
    '#description' => t('Cl@ve url server with http or https protocol'),
    '#default_value' => $default_value,
  );

  $default_value = variable_get('clave_qaa_level', 3);
  $form['clave_qaa_level'] = array(
    '#type' => 'select',
    '#options' => array('2' => t('Level 2'), '3' => t('Level 3'), '4' => t('Level 4')),
    '#title' => t('Identification level'),
    '#description' => t('Identification level'),
    '#default_value' => $default_value,
  );
  
  $default_value = variable_get('clave_providers', array());
  $form['clave_providers'] = array(
    '#type' => 'checkboxes',
    '#options' => array('aFirma' => '@firma','Stork' => 'Stork', 'AEAT' => 'AEAT', 'SS' => 'GISS'),
    '#title' => t('Service providers'),
    '#default_value' => $default_value,
  );

  $default_value = variable_get('clave_application_id', '');
  $form['clave_application_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Application id'),
    '#description' => t('Application id for Procomun'),
    '#default_value' => $default_value,
  );

  $default_value = variable_get('clave_sia_code', '');
  $form['clave_sia_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Sia code'),
    '#description' => t('Sia code for Procomun'),
    '#default_value' => $default_value,
  );

  $default_value = variable_get('clave_start_stop', 0);
  $form['clave_start_stop'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Cl@ve authentication login'),
    '#default_value' => $default_value,
  );

  //Custom submit
  $form['#submit'][] = 'stop_service_notification_form_submit';

  return system_settings_form($form);
}

/**
 * Form to configure stop service notification
 */
function stop_service_notification_form($form, &$form_state) {

  $translate_value = t(variable_get('stop_service_notification_title', ''));
  $default_value = variable_get('stop_service_notification_title', '');
  $form['stop_service_notification_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Stop service notification title'),
    '#description' => t('Stop service notification title in English'),
    '#default_value' => $default_value,
  );

  $translate_value = t(variable_get('stop_service_notification_text', ''));
  $default_value = variable_get('stop_service_notification_text', '');
  $form['stop_service_notification_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Stop service notification text'),
    '#description' => t('Stop service notification text in English'),
    '#default_value' => $default_value,
  );

  $form['links'] = array(
    '#type' => 'container',
  );

  $default_value = variable_get('stop_service_notification_link', '');
  $form['links']['stop_service_notification_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to display on notification'),
    '#default_value' => $default_value,
    '#description' => t('Link to be displayed on notification'),
  );

  $translate_value = t(variable_get('stop_service_notification_link_text', ''));
  $default_value = variable_get('stop_service_notification_link_text', '');
  $form['links']['stop_service_notification_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Text to display on link'),
    '#default_value' => $default_value,
    '#description' => t('Use a text in English to be displayed as Link title'),
  );

  $default_value = variable_get('stop_service_notification_check', 0);
  $form['stop_service_notification_check'] = array(
    '#type' => 'checkbox',
    '#title' => t('Put stop service notification in homepage'),
    '#default_value' => $default_value,
    '#description' => t('When enabled, a notification appears in homepage'),
  );

  //Custom submit
  $form['#submit'][] = 'stop_service_notification_form_submit';

  return system_settings_form($form);
}

/**
 * Implements FORM_ID_validate().
 */
function stop_service_notification_form_validate($form, &$form_state) {
  // Get current submitted link.
  $submitted_link = $form_state['values']['stop_service_notification_link'];

  // Check if link module exists, then use their link validation. If not, use valid_url drupal function.
  if (!empty($submitted_link)) {
    if (module_exists('link')) {
      $valid_url = link_validate_url(trim($submitted_link));
    }
    else {
      $valid_url = valid_url(trim($submitted_link), TRUE);
    }

    if (!$valid_url) {
      form_set_error('stop_service_notification_link', t('Notification link must be a valid URL'));
    }

    // Actually if valid_url is external we can save it without http:// or https://
    // So when we are about to build the anchor it is builded like a internal link.
    // Avoid this by checking if any external link starts with http:// or https://
    if ($valid_url == 'external' && preg_match('#^https?://#i', $submitted_link) !== 1) {
      form_set_error('stop_service_notification_link', t('If it is a external link, must start with http:// or https://'));
    }
  }
}

/**
 * Submit function for Form to configure stop service notification
 */
function stop_service_notification_form_submit($form, &$form_state) {
  //Clear cache page for avoid authcache and varnish
  cache_clear_all('*', 'cache_page', TRUE);
}