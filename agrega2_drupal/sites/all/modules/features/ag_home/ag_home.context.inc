<?php
/**
 * @file
 * ag_home.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ag_home_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Context for homepage';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'ag_general-ag_stop_service_notification' => array(
          'module' => 'ag_general',
          'delta' => 'ag_stop_service_notification',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for homepage');
  t('Home');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_general_header';
  $context->description = 'Not logged';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'top_bar',
          'weight' => '-9',
        ),
        'dropdown_menu_user-dropdown_menu_user_login_block' => array(
          'module' => 'dropdown_menu_user',
          'delta' => 'dropdown_menu_user_login_block',
          'region' => 'top_bar',
          'weight' => '-8',
        ),
        'views--exp-ode_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-ode_search-page',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Not logged');
  $export['home_general_header'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_general_header_logged';
  $context->description = 'Logged';
  $context->tag = 'Home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
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
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'user_bar',
          'weight' => '-10',
        ),
        'ag_section_notifications-ag_notifications_block' => array(
          'module' => 'ag_section_notifications',
          'delta' => 'ag_notifications_block',
          'region' => 'user_bar',
          'weight' => '-9',
        ),
        'dropdown_menu_user-dropdown_menu_user_login_block' => array(
          'module' => 'dropdown_menu_user',
          'delta' => 'dropdown_menu_user_login_block',
          'region' => 'user_bar',
          'weight' => '-8',
        ),
        'views--exp-ode_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-ode_search-page',
          'region' => 'preface',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('Logged');
  $export['home_general_header_logged'] = $context;

  return $export;
}
