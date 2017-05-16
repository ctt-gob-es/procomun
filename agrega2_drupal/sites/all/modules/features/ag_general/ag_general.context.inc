<?php
/**
 * @file
 * ag_general.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ag_general_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general_header';
  $context->description = 'Not logged';
  $context->tag = 'Ag general';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
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
        'views--exp-ode_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-ode_search-page',
          'region' => 'info_bar',
          'weight' => '-8',
        ),
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'info_bar',
          'weight' => '-7',
        ),
        'dropdown_menu_user-dropdown_menu_user_login_block' => array(
          'module' => 'dropdown_menu_user',
          'delta' => 'dropdown_menu_user_login_block',
          'region' => 'info_bar',
          'weight' => '-6',
        ),
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'nav',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ag general');
  t('Not logged');
  $export['general_header'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general_header_logged';
  $context->description = '';
  $context->tag = 'Ag general';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
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
        'views--exp-ode_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-ode_search-page',
          'region' => 'info_bar',
          'weight' => '-10',
        ),
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'info_bar',
          'weight' => '-9',
        ),
        'dropdown_menu_user-dropdown_menu_user_login_block' => array(
          'module' => 'dropdown_menu_user',
          'delta' => 'dropdown_menu_user_login_block',
          'region' => 'info_bar',
          'weight' => '-8',
        ),
        'superfish-1' => array(
          'module' => 'superfish',
          'delta' => '1',
          'region' => 'nav',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Ag general');
  $export['general_header_logged'] = $context;

  return $export;
}
