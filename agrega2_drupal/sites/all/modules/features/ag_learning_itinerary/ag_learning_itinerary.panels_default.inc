<?php
/**
 * @file
 * ag_learning_itinerary.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function ag_learning_itinerary_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'learning_path_content';
  $mini->category = '';
  $mini->admin_title = 'Learning path content';
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
  $display->uuid = '0ca190bf-d154-44a4-b31b-c42b949fdc1d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2dbd8a17-4c52-4a41-b2e8-6992469d0ac8';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'learning_path_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '1133',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'learning_path_content',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2dbd8a17-4c52-4a41-b2e8-6992469d0ac8';
    $display->content['new-2dbd8a17-4c52-4a41-b2e8-6992469d0ac8'] = $pane;
    $display->panels['middle'][0] = 'new-2dbd8a17-4c52-4a41-b2e8-6992469d0ac8';
    $pane = new stdClass();
    $pane->pid = 'new-89c0970a-64d9-4ac5-98c4-e7846bc5482f';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'learning_path_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'learning_path_content_selected',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '89c0970a-64d9-4ac5-98c4-e7846bc5482f';
    $display->content['new-89c0970a-64d9-4ac5-98c4-e7846bc5482f'] = $pane;
    $display->panels['middle'][1] = 'new-89c0970a-64d9-4ac5-98c4-e7846bc5482f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2dbd8a17-4c52-4a41-b2e8-6992469d0ac8';
  $mini->display = $display;
  $export['learning_path_content'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'learning_path_interest_content';
  $mini->category = '';
  $mini->admin_title = 'Learning path interest content';
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
  $display->uuid = '8751a17e-0b4f-416b-b0ac-184b29dd300c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5706be7d-4134-4071-a44d-cf1431ce46fd';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'learning_path_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '1122',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'learning_path_interest_content',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5706be7d-4134-4071-a44d-cf1431ce46fd';
    $display->content['new-5706be7d-4134-4071-a44d-cf1431ce46fd'] = $pane;
    $display->panels['middle'][0] = 'new-5706be7d-4134-4071-a44d-cf1431ce46fd';
    $pane = new stdClass();
    $pane->pid = 'new-b4c2216f-4764-4cbf-a448-24363d98427b';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'learning_path_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'learning_path_interest_content_selected',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b4c2216f-4764-4cbf-a448-24363d98427b';
    $display->content['new-b4c2216f-4764-4cbf-a448-24363d98427b'] = $pane;
    $display->panels['middle'][1] = 'new-b4c2216f-4764-4cbf-a448-24363d98427b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5706be7d-4134-4071-a44d-cf1431ce46fd';
  $mini->display = $display;
  $export['learning_path_interest_content'] = $mini;

  return $export;
}
