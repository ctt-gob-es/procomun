<?php
/**
 * @file
 * ag_section_questions_answers.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ag_section_questions_answers_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create answer content'.
  $permissions['create answer content'] = array(
    'name' => 'create answer content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'flag abuse_comment'.
  $permissions['flag abuse_comment'] = array(
    'name' => 'flag abuse_comment',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag abuse_node'.
  $permissions['flag abuse_node'] = array(
    'name' => 'flag abuse_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag abuse_comment'.
  $permissions['unflag abuse_comment'] = array(
    'name' => 'unflag abuse_comment',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag abuse_node'.
  $permissions['unflag abuse_node'] = array(
    'name' => 'unflag abuse_node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
