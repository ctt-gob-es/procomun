<?php
/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Active user'),
  'description' => t('Is user active or blocked'),
  'callback' => 'ag_section_profile_users_active_user_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'ag_section_profile_users_active_user_ctools_settings',
  'summary' => 'ag_section_profile_users_active_user_ctools_summary',
  'all contexts' => TRUE,
);


/**
 * Settings form for the 'by parent term' access plugin
 */
function ag_section_profile_users_active_user_ctools_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Check for access.
 */
function ag_section_profile_users_active_user_ctools_access_check($conf, $context) {
  // Data is required
  if (empty($context['argument_entity_id:user_1'])) {
    return FALSE;
  }

  if (empty($context['argument_entity_id:user_1']->data->status)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
  
  return FALSE;
}

/**
 * Provide a summary description based upon the checked terms.
 */
function ag_section_profile_users_active_user_ctools_summary($conf, $context) {
  return t('Active user');
}
