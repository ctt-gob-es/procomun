<?php
/**
 * @file
 * control_center_boosting.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function control_center_boosting_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_boosting';
  $path_breadcrumb->name = 'control_center_boosting';
  $path_breadcrumb->path = 'admin/control-center/boosting';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Configuración boosting',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['control_center_boosting'] = $path_breadcrumb;

  return $export;
}
