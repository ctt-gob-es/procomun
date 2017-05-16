<?php
/**
 * @file
 * ag_section_newsletter.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function ag_section_newsletter_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'administer_newsletters';
  $path_breadcrumb->name = 'Administer newsletters';
  $path_breadcrumb->path = 'ag_section_newsletter/%node/simplenews';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Administrar boletines',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -36;
  $export['administer_newsletters'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'generate_newsletters';
  $path_breadcrumb->name = 'Create newsletter';
  $path_breadcrumb->path = 'node/%node/ag_section_newsletter/new';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Administrar boletines',
      3 => '!page_title',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITYauto=',
      1 => '%node:url',
      2 => 'ag_section_newsletter/%node:nid/simplenews',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -73;
  $export['generate_newsletters'] = $path_breadcrumb;

  return $export;
}
