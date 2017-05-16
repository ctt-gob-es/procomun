<?php
// $Id: css_watch.admin.inc,v 1.2 2011/02/15 22:35:07 dustincurrie Exp $

/**
 * @file
 *
 * Contains code related to customizeable admin settings
 *
 * @author Dustin Currie <dustin@onlinedesert.com>
 */

/**
 * Menu callback for admin/css_watch/settings.
 */

function css_watch_settings() {
  $form = array();
  $form['css_watch_poll_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Polling Interval'),
    '#description' => t('Enter polling interval in milliseconds'),
    '#default_value' => variable_get('css_watch_poll_interval', CSS_WATCH_DEFAULT_INTERVAL),
  );
  $form['#validate'][] = 'css_watch_settings_validate';
  return system_settings_form($form);
}

/**
 *  Validation callback for css_watch_settings
 */
function css_watch_settings_validate($form, &$form_state) {
  if (!ctype_digit( $form_state['values']['css_watch_poll_interval'])) {
    form_set_error('css_watch_poll_interval', t('Interval must be an integer'));
  }
  $interval = (int) $form_state['values']['css_watch_poll_interval'];
  if ($interval < CSS_WATCH_MIN_INTERVAL || $interval > CSS_WATCH_MAX_INTERVAL) {
    form_set_error('css_watch_poll_interval', t('Interval must be between %min and %max', array('%min' => CSS_WATCH_MIN_INTERVAL, '%max' => CSS_WATCH_MAX_INTERVAL)));
  }
}