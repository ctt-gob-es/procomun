<?php
/**
 * @file
 * ag_section_help.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ag_section_help_taxonomy_default_vocabularies() {
  return array(
    'manual_index' => array(
      'name' => 'Índice del manual',
      'machine_name' => 'manual_index',
      'description' => 'Taxonomía para el índice del manual',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
