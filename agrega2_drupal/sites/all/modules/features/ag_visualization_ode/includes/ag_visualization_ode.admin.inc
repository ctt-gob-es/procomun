<?php
/**
 * Form to configure limit values for reportable odes
 */
function notify_values_ode_form($form, &$form_state) {

  //RATED
  $form['rated'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rated variables'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $ode_average = variable_get('ode_average', 80);
  $form['rated']['ode_average'] = array(
    '#type' => 'textfield',
    '#title' => t('Average'),
    '#default_value' => $ode_average,
    '#required' => TRUE,
  );
  $ode_number_votes = variable_get('ode_number_votes', 50);
  $form['rated']['ode_number_votes'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of votes'),
    '#default_value' => $ode_number_votes,
    '#required' => TRUE,
  );

  //LIKES
  $form['likes'] = array(
    '#type' => 'fieldset',
    '#title' => t('Likes variables'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $ode_number_likes = variable_get('ode_number_likes', 100);
  $form['likes']['ode_number_likes'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of likes'),
    '#default_value' => $ode_number_likes,
    '#required' => TRUE,
  );

  //VISITS
  $form['visits'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visits variables'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $ode_number_visits = variable_get('ode_number_visits', 50);
  $form['visits']['ode_number_visits'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of visits'),
    '#default_value' => $ode_number_visits,
    '#required' => TRUE,
  );

  //COMMENTS
  $form['comments'] = array(
    '#type' => 'fieldset',
    '#title' => t('Comments variables'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $ode_number_comments = variable_get('ode_number_comments', 20);
  $form['comments']['ode_number_comments'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of comments'),
    '#default_value' => $ode_number_comments,
    '#required' => TRUE,
  );

  $cert_criteria = variable_get('ode_cert_criteria', array());
  //Add certification criteria checkboxes 
  $form['ode_cert_criteria'] = array(
    '#type' => 'checkboxes',
    '#options' => array('rated' => t('Rated'), 'likes' => t('Likes'), 'visits' => t('Visits'), 'comments' => t('Comments')),
    '#title' => t('Select the criteria to be met by odes to be certifiables'),
    '#default_value' => !empty($cert_criteria) ? $cert_criteria : array(),
    '#required' => TRUE,
  );

  $ode_notify_time = variable_get('ode_notify_time', 604800);
  //Add certification criteria checkboxes 
  $form['ode_notify_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Time to re-notify odes not certified in seconds'),
    '#default_value' => !empty($ode_notify_time) ? $ode_notify_time : 604800,
    '#required' => TRUE,
  );

  return system_settings_form($form);
}