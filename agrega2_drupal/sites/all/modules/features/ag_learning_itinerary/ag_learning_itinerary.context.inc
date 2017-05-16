<?php
/**
 * @file
 * ag_learning_itinerary.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ag_learning_itinerary_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'learning_path';
  $context->description = '';
  $context->tag = 'Learning path';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'itinerary' => 'itinerary',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-learning_path_interest_content' => array(
          'module' => 'panels_mini',
          'delta' => 'learning_path_interest_content',
          'region' => 'content',
          'weight' => '-49',
        ),
        'panels_mini-learning_path_content' => array(
          'module' => 'panels_mini',
          'delta' => 'learning_path_content',
          'region' => 'content',
          'weight' => '-50',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Learning path');
  $export['learning_path'] = $context;

  return $export;
}
