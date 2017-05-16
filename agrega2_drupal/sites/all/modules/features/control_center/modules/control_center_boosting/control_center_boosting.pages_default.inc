<?php
/**
 * @file
 * control_center_boosting.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_boosting_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_update_fields_boosting';
  $page->task = 'page';
  $page->admin_title = 'Control center update fields boosting';
  $page->admin_description = 'Admin control center page for communities';
  $page->path = 'admin/control-center/boosting';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer communities',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Boosting configuration',
    'name' => 'menu-control-center-main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Boosting configuration',
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
  $handler->name = 'page_control_center_update_fields_boosting__panel_context_883fdb3f-3712-4ced-9d5b-e56138ecbc2f';
  $handler->task = 'page';
  $handler->subtask = 'control_center_update_fields_boosting';
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
    'name' => '',
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
  $display->title = 'Boosting configuration';
  $display->uuid = '718b34a3-2716-4752-9e90-2c2cbd1f523c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1f0b8064-163e-4c0b-8dbc-1a0da3974873';
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
    $pane->uuid = '1f0b8064-163e-4c0b-8dbc-1a0da3974873';
    $display->content['new-1f0b8064-163e-4c0b-8dbc-1a0da3974873'] = $pane;
    $display->panels['right'][0] = 'new-1f0b8064-163e-4c0b-8dbc-1a0da3974873';
    $pane = new stdClass();
    $pane->pid = 'new-b41a32e5-9766-47b2-871c-a1557d371fa1';
    $pane->panel = 'right';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h2',
      'class' => '',
      'id' => '',
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
    $pane->uuid = 'b41a32e5-9766-47b2-871c-a1557d371fa1';
    $display->content['new-b41a32e5-9766-47b2-871c-a1557d371fa1'] = $pane;
    $display->panels['right'][1] = 'new-b41a32e5-9766-47b2-871c-a1557d371fa1';
    $pane = new stdClass();
    $pane->pid = 'new-888762f9-b695-46b4-ab9c-aa9620e48235';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'solr_fields_boosting_list-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '888762f9-b695-46b4-ab9c-aa9620e48235';
    $display->content['new-888762f9-b695-46b4-ab9c-aa9620e48235'] = $pane;
    $display->panels['right'][2] = 'new-888762f9-b695-46b4-ab9c-aa9620e48235';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_update_fields_boosting'] = $page;

  return $pages;

}
