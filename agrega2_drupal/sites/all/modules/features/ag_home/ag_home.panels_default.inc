<?php
/**
 * @file
 * ag_home.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function ag_home_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'banner_home_content_count';
  $mini->category = 'Home';
  $mini->admin_title = 'Banner home content count';
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
  $display->uuid = '3e6932d4-b091-4999-92b4-43cdacc273de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8ba6a57a-8df6-4046-8b6f-bfe1b2892c52';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---comunidades';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-sm-3',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8ba6a57a-8df6-4046-8b6f-bfe1b2892c52';
    $display->content['new-8ba6a57a-8df6-4046-8b6f-bfe1b2892c52'] = $pane;
    $display->panels['middle'][0] = 'new-8ba6a57a-8df6-4046-8b6f-bfe1b2892c52';
    $pane = new stdClass();
    $pane->pid = 'new-d93227fe-deb5-4d8b-b187-8c54ca920615';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---recursos';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-sm-3',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd93227fe-deb5-4d8b-b187-8c54ca920615';
    $display->content['new-d93227fe-deb5-4d8b-b187-8c54ca920615'] = $pane;
    $display->panels['middle'][1] = 'new-d93227fe-deb5-4d8b-b187-8c54ca920615';
    $pane = new stdClass();
    $pane->pid = 'new-596b949e-b9fc-42d3-8f37-ec8432ade3a3';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---articulos';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-sm-3',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '596b949e-b9fc-42d3-8f37-ec8432ade3a3';
    $display->content['new-596b949e-b9fc-42d3-8f37-ec8432ade3a3'] = $pane;
    $display->panels['middle'][2] = 'new-596b949e-b9fc-42d3-8f37-ec8432ade3a3';
    $pane = new stdClass();
    $pane->pid = 'new-78b16d44-5e0e-4c42-a913-f8b632707b56';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---eventos';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-sm-3',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '78b16d44-5e0e-4c42-a913-f8b632707b56';
    $display->content['new-78b16d44-5e0e-4c42-a913-f8b632707b56'] = $pane;
    $display->panels['middle'][3] = 'new-78b16d44-5e0e-4c42-a913-f8b632707b56';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['banner_home_content_count'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'home_middle_content';
  $mini->category = 'Home';
  $mini->admin_title = 'Home middle content';
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
  $display->uuid = '546515ab-7907-4c43-baa7-f2903b03820f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-755f52cf-41e7-4574-9db8-259fca69600e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_home_more_recent-panel_pane_home_more_recent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '755f52cf-41e7-4574-9db8-259fca69600e';
    $display->content['new-755f52cf-41e7-4574-9db8-259fca69600e'] = $pane;
    $display->panels['middle'][0] = 'new-755f52cf-41e7-4574-9db8-259fca69600e';
    $pane = new stdClass();
    $pane->pid = 'new-c7734976-8584-48f4-bf85-0161baa3bd6b';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_home_new_communities-panel_pane_home_new_communities';
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
    $pane->uuid = 'c7734976-8584-48f4-bf85-0161baa3bd6b';
    $display->content['new-c7734976-8584-48f4-bf85-0161baa3bd6b'] = $pane;
    $display->panels['middle'][1] = 'new-c7734976-8584-48f4-bf85-0161baa3bd6b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['home_middle_content'] = $mini;

  return $export;
}
