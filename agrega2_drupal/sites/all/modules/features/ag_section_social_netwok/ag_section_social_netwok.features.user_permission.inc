<?php
/**
 * @file
 * ag_section_social_netwok.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ag_section_social_netwok_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create social_network content'.
  $permissions['create social_network content'] = array(
    'name' => 'create social_network content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
