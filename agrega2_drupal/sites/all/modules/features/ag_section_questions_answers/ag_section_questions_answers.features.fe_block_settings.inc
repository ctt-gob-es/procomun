<?php
/**
 * @file
 * ag_section_questions_answers.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ag_section_questions_answers_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['ag_section_questions_answers-selector_question_debate'] = array(
    'cache' => 8,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'selector_question_debate',
    'module' => 'ag_section_questions_answers',
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
