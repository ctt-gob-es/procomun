<?php
/**
 * @file
 * ag_section_content_type_learning_resource.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ag_section_content_type_learning_resource_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit own recurso_de_aprendizaje content'.
  $permissions['edit own recurso_de_aprendizaje content'] = array(
    'name' => 'edit own recurso_de_aprendizaje content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
