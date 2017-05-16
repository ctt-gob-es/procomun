<?php
/**
 * @file
 * control_center_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_organization_members';
  $page->task = 'page';
  $page->admin_title = 'Control center organization members';
  $page->admin_description = 'Control center for manage users';
  $page->path = 'admin/control-center/users/organization-members';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Organization members',
    'name' => 'navigation',
    'weight' => '2',
    'parent' => array(
      'type' => 'tab',
      'title' => 'Organization Members',
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
  $handler->name = 'page_control_center_organization_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_organization_members';
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
    'access' => array(
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
  $display->uuid = 'c2d51597-2ba6-4e7d-b24b-b96704f0eaf2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0bbcf2da-d282-4de3-af67-9acb8ee5eb31';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-control-center-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Administración de usuarios',
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
    $pane->uuid = '0bbcf2da-d282-4de3-af67-9acb8ee5eb31';
    $display->content['new-0bbcf2da-d282-4de3-af67-9acb8ee5eb31'] = $pane;
    $display->panels['right'][0] = 'new-0bbcf2da-d282-4de3-af67-9acb8ee5eb31';
    $pane = new stdClass();
    $pane->pid = 'new-59a2bd7f-198a-414d-9059-782fb42d775a';
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
    $pane->uuid = '59a2bd7f-198a-414d-9059-782fb42d775a';
    $display->content['new-59a2bd7f-198a-414d-9059-782fb42d775a'] = $pane;
    $display->panels['right'][1] = 'new-59a2bd7f-198a-414d-9059-782fb42d775a';
    $pane = new stdClass();
    $pane->pid = 'new-53755a4e-2315-483a-b869-f558d1bcada8';
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
    $pane->uuid = '53755a4e-2315-483a-b869-f558d1bcada8';
    $display->content['new-53755a4e-2315-483a-b869-f558d1bcada8'] = $pane;
    $display->panels['right'][2] = 'new-53755a4e-2315-483a-b869-f558d1bcada8';
    $pane = new stdClass();
    $pane->pid = 'new-da273af3-f30b-4383-b6f8-5357800e1aed';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-25d57d61fdfce032078afbca44cd8308';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'da273af3-f30b-4383-b6f8-5357800e1aed';
    $display->content['new-da273af3-f30b-4383-b6f8-5357800e1aed'] = $pane;
    $display->panels['right'][3] = 'new-da273af3-f30b-4383-b6f8-5357800e1aed';
    $pane = new stdClass();
    $pane->pid = 'new-032cd714-b73a-464d-b646-17d39ee6daa1';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'users_organization-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '032cd714-b73a-464d-b646-17d39ee6daa1';
    $display->content['new-032cd714-b73a-464d-b646-17d39ee6daa1'] = $pane;
    $display->panels['right'][4] = 'new-032cd714-b73a-464d-b646-17d39ee6daa1';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-0bbcf2da-d282-4de3-af67-9acb8ee5eb31';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_organization_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_users';
  $page->task = 'page';
  $page->admin_title = 'Control center users';
  $page->admin_description = 'Panel that manage users at control center.';
  $page->path = 'admin/control-center/users/list';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center users',
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
    'type' => 'default tab',
    'title' => 'Administer users',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Administer users',
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
  $handler->name = 'page_control_center_users_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_users';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Control center users',
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
  $display->uuid = 'd4e9b7db-359b-4863-b89e-8b87d7ae02a6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b76df361-a5a2-41d7-9ef9-977ae6534959';
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
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b76df361-a5a2-41d7-9ef9-977ae6534959';
    $display->content['new-b76df361-a5a2-41d7-9ef9-977ae6534959'] = $pane;
    $display->panels['right'][0] = 'new-b76df361-a5a2-41d7-9ef9-977ae6534959';
    $pane = new stdClass();
    $pane->pid = 'new-aebd3da4-e2d0-42f2-9f15-88a2e852352b';
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
    $pane->uuid = 'aebd3da4-e2d0-42f2-9f15-88a2e852352b';
    $display->content['new-aebd3da4-e2d0-42f2-9f15-88a2e852352b'] = $pane;
    $display->panels['right'][1] = 'new-aebd3da4-e2d0-42f2-9f15-88a2e852352b';
    $pane = new stdClass();
    $pane->pid = 'new-6d612fe7-3b2e-4dae-9691-90beaa4d370b';
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
    $pane->uuid = '6d612fe7-3b2e-4dae-9691-90beaa4d370b';
    $display->content['new-6d612fe7-3b2e-4dae-9691-90beaa4d370b'] = $pane;
    $display->panels['right'][2] = 'new-6d612fe7-3b2e-4dae-9691-90beaa4d370b';
    $pane = new stdClass();
    $pane->pid = 'new-71cda37e-7187-485e-bd26-4872bd25e0b7';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-89e0957d377335ccfd4d5ee4f44a8c4a';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '71cda37e-7187-485e-bd26-4872bd25e0b7';
    $display->content['new-71cda37e-7187-485e-bd26-4872bd25e0b7'] = $pane;
    $display->panels['right'][3] = 'new-71cda37e-7187-485e-bd26-4872bd25e0b7';
    $pane = new stdClass();
    $pane->pid = 'new-e92eae77-2586-4e6d-bc3a-992da0e36ac8';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'control_center_users-panel_pane_1';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e92eae77-2586-4e6d-bc3a-992da0e36ac8';
    $display->content['new-e92eae77-2586-4e6d-bc3a-992da0e36ac8'] = $pane;
    $display->panels['right'][4] = 'new-e92eae77-2586-4e6d-bc3a-992da0e36ac8';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-e92eae77-2586-4e6d-bc3a-992da0e36ac8';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_users'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_users_organizations';
  $page->task = 'page';
  $page->admin_title = 'Control center users organizations';
  $page->admin_description = 'Panel that manage users at control center.';
  $page->path = 'admin/control-center/users/organizations';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center organizations',
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
    'type' => 'tab',
    'title' => 'Administer organizations',
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
  $handler->name = 'page_control_center_users_organizations_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_users_organizations';
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
    'access' => array(
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
  $display->uuid = 'ae6082b8-4d19-42f8-ac41-7d2abb718d0f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3c2d0018-7562-42b4-8d74-967c1a13b928';
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
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3c2d0018-7562-42b4-8d74-967c1a13b928';
    $display->content['new-3c2d0018-7562-42b4-8d74-967c1a13b928'] = $pane;
    $display->panels['right'][0] = 'new-3c2d0018-7562-42b4-8d74-967c1a13b928';
    $pane = new stdClass();
    $pane->pid = 'new-e5fd4bf5-b15b-4874-9b10-e65f3c2c9f5c';
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
    $pane->uuid = 'e5fd4bf5-b15b-4874-9b10-e65f3c2c9f5c';
    $display->content['new-e5fd4bf5-b15b-4874-9b10-e65f3c2c9f5c'] = $pane;
    $display->panels['right'][1] = 'new-e5fd4bf5-b15b-4874-9b10-e65f3c2c9f5c';
    $pane = new stdClass();
    $pane->pid = 'new-bf2fb509-3f14-406f-9131-1d2311d5af53';
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
    $pane->uuid = 'bf2fb509-3f14-406f-9131-1d2311d5af53';
    $display->content['new-bf2fb509-3f14-406f-9131-1d2311d5af53'] = $pane;
    $display->panels['right'][2] = 'new-bf2fb509-3f14-406f-9131-1d2311d5af53';
    $pane = new stdClass();
    $pane->pid = 'new-e91319ab-564b-4b7d-af3e-22899e3f48ab';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'views-0bd8dd01c5ca9d890123a969c87668fc';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e91319ab-564b-4b7d-af3e-22899e3f48ab';
    $display->content['new-e91319ab-564b-4b7d-af3e-22899e3f48ab'] = $pane;
    $display->panels['right'][3] = 'new-e91319ab-564b-4b7d-af3e-22899e3f48ab';
    $pane = new stdClass();
    $pane->pid = 'new-4106dd8e-c2ae-477b-9e15-b3b7e99543f7';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'control_center_users-panel_pane_2';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '4106dd8e-c2ae-477b-9e15-b3b7e99543f7';
    $display->content['new-4106dd8e-c2ae-477b-9e15-b3b7e99543f7'] = $pane;
    $display->panels['right'][4] = 'new-4106dd8e-c2ae-477b-9e15-b3b7e99543f7';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-4106dd8e-c2ae-477b-9e15-b3b7e99543f7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_users_organizations'] = $page;

  return $pages;

}
