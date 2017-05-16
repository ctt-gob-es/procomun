<?php
/**
 * @file
 * ag_section_social_netwok.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function ag_section_social_netwok_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:social_network:add user'
  $permissions['node:social_network:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:administer group'
  $permissions['node:social_network:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:approve and deny subscription'
  $permissions['node:social_network:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:manage members'
  $permissions['node:social_network:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:manage permissions'
  $permissions['node:social_network:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:manage roles'
  $permissions['node:social_network:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:social_network:subscribe'
  $permissions['node:social_network:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:social_network:subscribe without approval'
  $permissions['node:social_network:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:social_network:unsubscribe'
  $permissions['node:social_network:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:social_network:update group'
  $permissions['node:social_network:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
