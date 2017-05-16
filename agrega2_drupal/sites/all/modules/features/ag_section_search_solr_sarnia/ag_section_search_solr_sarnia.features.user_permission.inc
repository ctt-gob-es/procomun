<?php
/**
 * @file
 * ag_section_search_solr_sarnia.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ag_section_search_solr_sarnia_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_autocomplete for search_api_views_ode_search'.
  $permissions['use search_api_autocomplete for search_api_views_ode_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_ode_search',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}
