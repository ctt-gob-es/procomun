<?php
/**
 * @file
 * ag_section_newsletter.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ag_section_newsletter_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:social_network:create simplenews content'
  $permissions['node:social_network:create simplenews content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:delete any simplenews content'
  $permissions['node:social_network:delete any simplenews content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:delete own simplenews content'
  $permissions['node:social_network:delete own simplenews content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:update any simplenews content'
  $permissions['node:social_network:update any simplenews content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:update own simplenews content'
  $permissions['node:social_network:update own simplenews content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
