<?php
/**
 * @file
 * control_center_reports.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_reports_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_reports_community_reporting';
  $page->task = 'page';
  $page->admin_title = 'Control center Communities reports';
  $page->admin_description = 'Control center Communities reports';
  $page->path = 'admin/control-center/reports/communities-report';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center communities reports',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Communities',
    'name' => 'navigation',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_control_center_reports_community_reporting_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_reports_community_reporting';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'ag-3-9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0d8f11e0-81c7-4bb2-b9ad-0e593dc6be96';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3feed514-0959-4a66-8887-598c58cc9466';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-control-center-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3feed514-0959-4a66-8887-598c58cc9466';
    $display->content['new-3feed514-0959-4a66-8887-598c58cc9466'] = $pane;
    $display->panels['right'][0] = 'new-3feed514-0959-4a66-8887-598c58cc9466';
    $pane = new stdClass();
    $pane->pid = 'new-ec69d9d8-c6a0-4275-a303-757371ab4c26';
    $pane->panel = 'right';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ec69d9d8-c6a0-4275-a303-757371ab4c26';
    $display->content['new-ec69d9d8-c6a0-4275-a303-757371ab4c26'] = $pane;
    $display->panels['right'][1] = 'new-ec69d9d8-c6a0-4275-a303-757371ab4c26';
    $pane = new stdClass();
    $pane->pid = 'new-4f698dbb-3d5a-4b99-ac7c-d4bb60605fee';
    $pane->panel = 'right';
    $pane->type = 'ag_reports_report_content_type';
    $pane->subtype = 'ag_reports_report_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'form-render' => 'control_center_reports_communities_reporting_form',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4f698dbb-3d5a-4b99-ac7c-d4bb60605fee';
    $display->content['new-4f698dbb-3d5a-4b99-ac7c-d4bb60605fee'] = $pane;
    $display->panels['right'][2] = 'new-4f698dbb-3d5a-4b99-ac7c-d4bb60605fee';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3feed514-0959-4a66-8887-598c58cc9466';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_reports_community_reporting'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_reports_procomun_reporting';
  $page->task = 'page';
  $page->admin_title = 'Control center Global reports';
  $page->admin_description = 'Control center Global reports';
  $page->path = 'admin/control-center/reports/global-report';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center procomun reports',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Global',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Reports',
      'name' => 'menu-control-center-main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_control_center_reports_procomun_reporting_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_reports_procomun_reporting';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'ag-3-9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Reports';
  $display->uuid = 'dd0aea4c-f03b-4864-8962-ce4d642572ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6e50ae44-48df-4fed-9a6d-df829a4e04ac';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-control-center-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6e50ae44-48df-4fed-9a6d-df829a4e04ac';
    $display->content['new-6e50ae44-48df-4fed-9a6d-df829a4e04ac'] = $pane;
    $display->panels['right'][0] = 'new-6e50ae44-48df-4fed-9a6d-df829a4e04ac';
    $pane = new stdClass();
    $pane->pid = 'new-855b248a-b290-4918-91dc-27cf2e2103c0';
    $pane->panel = 'right';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '855b248a-b290-4918-91dc-27cf2e2103c0';
    $display->content['new-855b248a-b290-4918-91dc-27cf2e2103c0'] = $pane;
    $display->panels['right'][1] = 'new-855b248a-b290-4918-91dc-27cf2e2103c0';
    $pane = new stdClass();
    $pane->pid = 'new-6565d863-14f6-40b7-9e1b-b8999ec3ca87';
    $pane->panel = 'right';
    $pane->type = 'ag_reports_report_content_type';
    $pane->subtype = 'ag_reports_report_content_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'form-render' => 'control_center_reports_procomun_reporting_form',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6565d863-14f6-40b7-9e1b-b8999ec3ca87';
    $display->content['new-6565d863-14f6-40b7-9e1b-b8999ec3ca87'] = $pane;
    $display->panels['right'][2] = 'new-6565d863-14f6-40b7-9e1b-b8999ec3ca87';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-855b248a-b290-4918-91dc-27cf2e2103c0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_reports_procomun_reporting'] = $page;

  return $pages;

}
