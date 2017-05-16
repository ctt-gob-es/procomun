<?php
/**
 * @file
 * ag_section_content_type_learning_resource.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ag_section_content_type_learning_resource_taxonomy_default_vocabularies() {
  return array(
    'recurso_de_aprendizaje' => array(
      'name' => 'Recurso de aprendizaje',
      'machine_name' => 'recurso_de_aprendizaje',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'recurso_educativo' => array(
      'name' => 'Recurso educativo',
      'machine_name' => 'recurso_educativo',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
