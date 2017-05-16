<?php
/**
 * @file
 * ag_section_notifications.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_notifications_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_notifications';
  $page->task = 'page';
  $page->admin_title = 'User notifications';
  $page->admin_description = '';
  $page->path = 'user/%user/notifications';
  $page->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'argument_entity_id:user_1',
          1 => 'logged-in-user',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer message types',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Usuario: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_notifications_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_notifications';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ee4fa81b-7fb1-4537-8b02-ee2f22a395e4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a0592bca-3876-4b66-aed8-f2a98910a9be';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_notifications-panel_pane_1';
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
    $pane->uuid = 'a0592bca-3876-4b66-aed8-f2a98910a9be';
    $display->content['new-a0592bca-3876-4b66-aed8-f2a98910a9be'] = $pane;
    $display->panels['middle'][0] = 'new-a0592bca-3876-4b66-aed8-f2a98910a9be';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a0592bca-3876-4b66-aed8-f2a98910a9be';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_notifications'] = $page;

  return $pages;

}
