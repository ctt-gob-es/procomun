<?php
/**
 * @file
 * ag_section_questions_answers.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ag_section_questions_answers_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_answer';
  $strongarm->value = 0;
  $export['comment_anonymous_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_debate';
  $strongarm->value = 0;
  $export['comment_anonymous_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_question';
  $strongarm->value = 0;
  $export['comment_anonymous_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_answer';
  $strongarm->value = '1';
  $export['comment_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_debate';
  $strongarm->value = '2';
  $export['comment_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_answer';
  $strongarm->value = 1;
  $export['comment_default_mode_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_debate';
  $strongarm->value = 1;
  $export['comment_default_mode_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_question';
  $strongarm->value = 1;
  $export['comment_default_mode_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_answer';
  $strongarm->value = '50';
  $export['comment_default_per_page_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_debate';
  $strongarm->value = '50';
  $export['comment_default_per_page_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_question';
  $strongarm->value = '50';
  $export['comment_default_per_page_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_answer';
  $strongarm->value = 1;
  $export['comment_form_location_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_debate';
  $strongarm->value = 1;
  $export['comment_form_location_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_question';
  $strongarm->value = 1;
  $export['comment_form_location_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_answer';
  $strongarm->value = '1';
  $export['comment_preview_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_debate';
  $strongarm->value = '1';
  $export['comment_preview_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_question';
  $strongarm->value = '1';
  $export['comment_preview_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_question';
  $strongarm->value = '1';
  $export['comment_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_answer';
  $strongarm->value = 1;
  $export['comment_subject_field_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_debate';
  $strongarm->value = 0;
  $export['comment_subject_field_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_question';
  $strongarm->value = 1;
  $export['comment_subject_field_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__answer';
  $strongarm->value = array(
    'default_language' => 'es',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__debate';
  $strongarm->value = array(
    'default_language' => 'es',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__question';
  $strongarm->value = array(
    'default_language' => 'es',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@search_labels_for_question_and_debate';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@search_labels_for_question_and_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__answer';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'lasts' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'newsletter' => array(
        'custom_settings' => TRUE,
      ),
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'activities' => array(
        'custom_settings' => TRUE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_events' => array(
        'custom_settings' => TRUE,
      ),
      'learning_path_content' => array(
        'custom_settings' => FALSE,
      ),
      'learning_path_interest_content' => array(
        'custom_settings' => FALSE,
      ),
      'PDF' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'path' => array(
          'weight' => '8',
        ),
        'language' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__debate';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'lasts' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'newsletter' => array(
        'custom_settings' => TRUE,
      ),
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'activities' => array(
        'custom_settings' => TRUE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'upcoming_events' => array(
        'custom_settings' => TRUE,
      ),
      'PDF' => array(
        'custom_settings' => FALSE,
      ),
      'learning_path_content' => array(
        'custom_settings' => TRUE,
      ),
      'learning_path_interest_content' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'language' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'flag_og_newsletter' => array(
          'default' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'lasts' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'flag_learning_path_content' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'flag_learning_path_interest_content' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__question';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'lasts' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'listing' => array(
        'custom_settings' => TRUE,
      ),
      'activities' => array(
        'custom_settings' => TRUE,
      ),
      'newsletter' => array(
        'custom_settings' => TRUE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'learning_path_content' => array(
        'custom_settings' => TRUE,
      ),
      'learning_path_interest_content' => array(
        'custom_settings' => TRUE,
      ),
      'upcoming_events' => array(
        'custom_settings' => TRUE,
      ),
      'PDF' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'path' => array(
          'weight' => '9',
        ),
        'language' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'flag_og_newsletter' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'flag_learning_path_content' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'flag_learning_path_interest_content' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_content' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'learning_path_interest_content' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'upcoming_events' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'newsletter' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'lasts' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'listing' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'activities' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_answer';
  $strongarm->value = '4';
  $export['language_content_type_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_debate';
  $strongarm->value = '4';
  $export['language_content_type_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_question';
  $strongarm->value = '4';
  $export['language_content_type_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_answer';
  $strongarm->value = array();
  $export['menu_options_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_debate';
  $strongarm->value = array();
  $export['menu_options_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_question';
  $strongarm->value = array();
  $export['menu_options_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_answer';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_debate';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_question';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_answer';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_debate';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_question';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_answer';
  $strongarm->value = '0';
  $export['node_preview_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_debate';
  $strongarm->value = '1';
  $export['node_preview_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_question';
  $strongarm->value = '1';
  $export['node_preview_question'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_answer';
  $strongarm->value = 1;
  $export['node_submitted_answer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_debate';
  $strongarm->value = 1;
  $export['node_submitted_debate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_question';
  $strongarm->value = 1;
  $export['node_submitted_question'] = $strongarm;

  return $export;
}
