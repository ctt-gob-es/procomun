<?php
/**
 * @file
 * control_center_users.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function control_center_users_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-25d57d61fdfce032078afbca44cd8308'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '25d57d61fdfce032078afbca44cd8308',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'nexus' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'nexus',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
