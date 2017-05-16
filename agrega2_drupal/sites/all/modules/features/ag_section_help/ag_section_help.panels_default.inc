<?php
/**
 * @file
 * ag_section_help.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function ag_section_help_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'help_manual_content';
  $mini->category = 'Help';
  $mini->admin_title = 'Help manual content';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
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
  $display->uuid = '9d05b014-75d4-458c-8ee7-6545a8f9a1b8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-01d75280-4da5-4f71-8b52-9c98b45a2234';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_help_manual_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '01d75280-4da5-4f71-8b52-9c98b45a2234';
    $display->content['new-01d75280-4da5-4f71-8b52-9c98b45a2234'] = $pane;
    $display->panels['middle'][0] = 'new-01d75280-4da5-4f71-8b52-9c98b45a2234';
    $pane = new stdClass();
    $pane->pid = 'new-e8d8437d-8b10-430a-ae24-f1c088ba0b27';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'manual_content-panel_pane_1';
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
    $pane->uuid = 'e8d8437d-8b10-430a-ae24-f1c088ba0b27';
    $display->content['new-e8d8437d-8b10-430a-ae24-f1c088ba0b27'] = $pane;
    $display->panels['middle'][1] = 'new-e8d8437d-8b10-430a-ae24-f1c088ba0b27';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e8d8437d-8b10-430a-ae24-f1c088ba0b27';
  $mini->display = $display;
  $export['help_manual_content'] = $mini;

  return $export;
}
