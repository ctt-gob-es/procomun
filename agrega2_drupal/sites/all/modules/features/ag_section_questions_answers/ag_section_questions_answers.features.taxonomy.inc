<?php
/**
 * @file
 * ag_section_questions_answers.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ag_section_questions_answers_taxonomy_default_vocabularies() {
  return array(
    'categories' => array(
      'name' => 'Categorías',
      'machine_name' => 'categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
