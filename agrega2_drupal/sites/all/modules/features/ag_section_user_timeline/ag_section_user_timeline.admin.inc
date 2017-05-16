<?php

function administer_procomun_interests_welcome_block($form, &$form_state) {

  // Adding a config form to make timeline header block title and text configurable
  $form['global_interest_block_text_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Config the user timeline block'),
    '#collapsible' => TRUE,
    '#collapse' => FALSE,
  );

  // Provide a default text to timeline block
  $default_text = 'This page called "My interests" will, from now, your "main door" to Procomun. There you\'ll find, in the central side, the contributions which users you follow have done and your activity.';

  // And finally, adding both field to the form
  $form['global_interest_block_text_fieldset']['user_timeline_welcome_block_title'] = array(
    '#type' => 'textarea',
    '#title' => t('User timeline welcome block text in English'),
    '#default_value' => variable_get('user_timeline_welcome_block_title', 'Welcome to the new version of Procomun Space'),
  );

  $form['global_interest_block_text_fieldset']['user_timeline_welcome_block_text'] = array(
    '#type' => 'textarea',
    '#title' => t('User timeline welcome block text in English'),
    '#default_value' => variable_get('user_timeline_welcome_block_text', $default_text),
  );

  return system_settings_form($form);
}
