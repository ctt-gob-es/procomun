<?php
/**
 * @file
 * ag_section_profile_users.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ag_section_profile_users_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = '';
  $context->tag = 'Ag section profile users';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user' => 'user',
        'user#profile-mi-cuenta' => 'user#profile-mi-cuenta',
        'user#profile-datos-personales' => 'user#profile-datos-personales',
        'users/*' => 'users/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ag_section_profile_users-user_activity_summary' => array(
          'module' => 'ag_section_profile_users',
          'delta' => 'user_activity_summary',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ag section profile users');
  $export['user_profile'] = $context;

  return $export;
}
