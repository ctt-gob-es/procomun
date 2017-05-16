<?php
/**
 * @file
 * ag_visualization_ode.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ag_visualization_ode_taxonomy_default_vocabularies() {
  return array(
    'palabras_clave' => array(
      'name' => 'Palabras clave',
      'machine_name' => 'palabras_clave',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'rol_contribuidor' => array(
      'name' => 'Rol contribuidor',
      'machine_name' => 'rol_contribuidor',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'tipo_de_licencia' => array(
      'name' => 'Tipo de licencia',
      'machine_name' => 'tipo_de_licencia',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
