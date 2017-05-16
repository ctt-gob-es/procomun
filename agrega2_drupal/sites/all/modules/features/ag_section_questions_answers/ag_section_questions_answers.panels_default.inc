<?php
/**
 * @file
 * ag_section_questions_answers.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function ag_section_questions_answers_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'answers_content_in_questions';
  $mini->category = '';
  $mini->admin_title = 'Answers content in questions';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Nodo',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'optional' => 0,
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3790be7e-f791-4d64-885d-345ad7854f75';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-75ed102a-bb69-46c5-bb5e-d807517cbe98';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_questions_answers-add_new_answer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '75ed102a-bb69-46c5-bb5e-d807517cbe98';
    $display->content['new-75ed102a-bb69-46c5-bb5e-d807517cbe98'] = $pane;
    $display->panels['middle'][0] = 'new-75ed102a-bb69-46c5-bb5e-d807517cbe98';
    $pane = new stdClass();
    $pane->pid = 'new-555d78bc-b304-4a20-8fb1-f302a8e4cbd5';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_answers-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '555d78bc-b304-4a20-8fb1-f302a8e4cbd5';
    $display->content['new-555d78bc-b304-4a20-8fb1-f302a8e4cbd5'] = $pane;
    $display->panels['middle'][1] = 'new-555d78bc-b304-4a20-8fb1-f302a8e4cbd5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-75ed102a-bb69-46c5-bb5e-d807517cbe98';
  $mini->display = $display;
  $export['answers_content_in_questions'] = $mini;

  return $export;
}
