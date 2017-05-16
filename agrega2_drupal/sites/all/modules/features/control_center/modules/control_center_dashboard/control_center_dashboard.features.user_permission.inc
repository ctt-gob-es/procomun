<?php
/**
 * @file
 * control_center_dashboard.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function control_center_dashboard_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer communities'.
  $permissions['administer communities'] = array(
    'name' => 'administer communities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ag_section_social_netwok',
  );

  return $permissions;
}
