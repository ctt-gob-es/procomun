<?php
/**
 * @file
 * ag_section_profile_users.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ag_section_profile_users_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_certified'.
  $permissions['create field_certified'] = array(
    'name' => 'create field_certified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create recurso_de_aprendizaje content'.
  $permissions['create recurso_de_aprendizaje content'] = array(
    'name' => 'create recurso_de_aprendizaje content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit field_certified'.
  $permissions['edit field_certified'] = array(
    'name' => 'edit field_certified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_certified'.
  $permissions['edit own field_certified'] = array(
    'name' => 'edit own field_certified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view any cv profile'.
  $permissions['view any cv profile'] = array(
    'name' => 'view any cv profile',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any datos_personales profile'.
  $permissions['view any datos_personales profile'] = array(
    'name' => 'view any datos_personales profile',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view field_certified'.
  $permissions['view field_certified'] = array(
    'name' => 'view field_certified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_certified'.
  $permissions['view own field_certified'] = array(
    'name' => 'view own field_certified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
