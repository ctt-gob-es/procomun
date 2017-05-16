<?php

/**
 * Custom for to handle questions moderation params.
 */
function ag_section_help_moderation_email_configuration_settings_form($form, &$form_state) {
  $subject = variable_get('notification_email_subject', '');
  $translation_subject = t($subject);
  $form['notification_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $subject,
    '#description' => t('This is subject field for questions moderation email. This field must be in English'),
  );

  $body = variable_get('notification_email_body', '');
  $translation_body = t($body);
  $form['notification_email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $body,
    '#description' => t('This is the body field for questions moderation email. This field must be in English'),
  );

  if (module_exists('token')) {
    $form['token_info'] = array(
      '#type' => 'item',
      '#markup' => t('Available tokens on both fields: [node:title] [node:body]'),
    );
  }

  return system_settings_form($form);
}