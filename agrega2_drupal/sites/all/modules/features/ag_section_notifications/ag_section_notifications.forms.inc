<?php

/**
 * @file
 *
 */

/**
 * Form wrapper to show the confirm message().
 */
function ag_section_notifications_delete_message_form($form, &$form_state) {
  global $user;

  return confirm_form($form, t('Do you really want delete this message?'),
    "user/$user->uid/notifications", NULL, t('Delete'));
}

/**
 * Submit callback for ag_section_notifications_delete_message_form().
 */
function ag_section_notifications_delete_message_form_submit($form, &$form_state) {
  global $user;

  // Get message from args:
  $message = isset($form_state['build_info']['args'][0]) ? $form_state['build_info']['args'][0] : NULL;
  if (!empty($message)) {
    $wp_message = entity_metadata_wrapper('message', $message);
    $wp_message->delete();
    drupal_set_message('The message was delete successfully.');
  }

  // Redirect to user notifications:
  $form_state['redirect'] = "user/$user->uid/notifications";
}

/**
 * Callback for user notifications list tab in control center
 */
function ag_section_notifications_user_notifications() {
  global $user;

  return views_embed_view('user_notifications', 'panel_pane_1', $user->uid);
}
