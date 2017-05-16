<?php
/**
 * @file
 * ag_section_webinar.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function ag_section_webinar_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_webinars';
  $path_breadcrumb->name = 'Search webinars';
  $path_breadcrumb->path = 'WEBINAR';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Webinars',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -56;
  $export['search_webinars'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'webinars';
  $path_breadcrumb->name = 'Webinars';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Webinars',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?query=&amp;type=WEBINAR',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Contenido: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'webinar' => 'webinar',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['webinars'] = $path_breadcrumb;

  return $export;
}
