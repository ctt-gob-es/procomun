<?php

/**
 * @file
 * This file contains the functionality for managing the configuration for
 * twitter autopublish module.
 */

/**
 * This function is the callback for the configuration settings for the module
 */
function twitter_autopublish_settings() {
  $form = array();
  $form['twitter_autopublish_access_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Access token'),
    '#default_value' => variable_get('twitter_autopublish_access_token', ''),
    '#size' => 75,
    '#maxlength' => 75,
    '#description' => t('Access token given for the application in twitter'),
    '#required' => TRUE,
  );
  $form['twitter_autopublish_access_token_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Access token secret'),
    '#default_value' => variable_get('twitter_autopublish_access_token_secret', ''),
    '#size' => 75,
    '#maxlength' => 75,
    '#description' => t('Access token secret given for the application in twitter'),
    '#required' => TRUE,
  );
  $form['twitter_autopublish_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer key'),
    '#default_value' => variable_get('twitter_autopublish_consumer_key', ''),
    '#size' => 75,
    '#maxlength' => 75,
    '#description' => t('Consumer key given for the application in twitter'),
    '#required' => TRUE,
  );
  $form['twitter_autopublish_consumer_key_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Consumer key secret'),
    '#default_value' => variable_get('twitter_autopublish_consumer_key_secret', ''),
    '#size' => 75,
    '#maxlength' => 75,
    '#description' => t('Consumer key secret given for the application in twitter'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}