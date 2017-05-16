<?php
/**
 * @file
 * ag_section_post.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ag_section_post_taxonomy_default_vocabularies() {
  return array(
    'knowledgearea' => array(
      'name' => 'Área de conocimiento',
      'machine_name' => 'knowledgearea',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'learningcontext' => array(
      'name' => 'Contexto educativo',
      'machine_name' => 'learningcontext',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
