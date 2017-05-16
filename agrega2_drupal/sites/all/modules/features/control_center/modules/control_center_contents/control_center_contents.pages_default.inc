<?php
/**
 * @file
 * control_center_contents.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_contents_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_contents';
  $page->task = 'page';
  $page->admin_title = 'Control center contents';
  $page->admin_description = 'Admin control panel for managing the contents';
  $page->path = 'admin/control-center/content/list';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center contents',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Administer content',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Administer content',
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
  $handler->name = 'page_control_center_contents_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_contents';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Control center content list',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'administer nodes',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = '54a6b2a0-2df3-4f97-b451-9f6e783df9bc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-control-center-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = '6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
    $display->content['new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a'] = $pane;
    $display->panels['right'][0] = 'new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
    $pane = new stdClass();
    $pane->pid = 'new-60de8428-3f5b-43c2-b996-c7342403408c';
    $pane->panel = 'right';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'none',
      'class' => '',
      'id' => '',
      'override_title' => 1,
      'override_title_text' => 'Lista de contenido',
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
    $pane->uuid = '60de8428-3f5b-43c2-b996-c7342403408c';
    $display->content['new-60de8428-3f5b-43c2-b996-c7342403408c'] = $pane;
    $display->panels['right'][1] = 'new-60de8428-3f5b-43c2-b996-c7342403408c';
    $pane = new stdClass();
    $pane->pid = 'new-ebf723b5-38c1-4092-8d43-4b67b1c3243c';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ebf723b5-38c1-4092-8d43-4b67b1c3243c';
    $display->content['new-ebf723b5-38c1-4092-8d43-4b67b1c3243c'] = $pane;
    $display->panels['right'][2] = 'new-ebf723b5-38c1-4092-8d43-4b67b1c3243c';
    $pane = new stdClass();
    $pane->pid = 'new-941e495c-ed8a-4dd2-8d95-a6a3df666b61';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_content_administration-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '941e495c-ed8a-4dd2-8d95-a6a3df666b61';
    $display->content['new-941e495c-ed8a-4dd2-8d95-a6a3df666b61'] = $pane;
    $display->panels['right'][3] = 'new-941e495c-ed8a-4dd2-8d95-a6a3df666b61';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_contents'] = $page;

  return $pages;

}
