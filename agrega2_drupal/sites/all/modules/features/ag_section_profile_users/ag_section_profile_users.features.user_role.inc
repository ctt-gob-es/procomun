<?php
/**
 * @file
 * ag_section_profile_users.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ag_section_profile_users_user_default_roles() {
  $roles = array();

  // Exported role: organization.
  $roles['organization'] = array(
    'name' => 'organization',
    'weight' => 3,
  );

  return $roles;
}
