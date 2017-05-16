<?php
/**
 * @file
 * control_center_certifications.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_certifications_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_certification_certifiable';
  $page->task = 'page';
  $page->admin_title = 'Control center certification certifiable by likes';
  $page->admin_description = '';
  $page->path = 'admin/control-center/certifications/certifiable-by-likes';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Exceed likes',
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
  $handler->name = 'page_control_center_certification_certifiable_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_certification_certifiable';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'community-admin',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
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
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b89152c8-9f52-48b9-80d3-8748b40d0cd9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
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
    $pane->uuid = 'fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $display->content['new-fe311408-4ff3-4552-ab42-6154b0cdb3ef'] = $pane;
    $display->panels['right'][0] = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $pane = new stdClass();
    $pane->pid = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
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
    $pane->uuid = 'c39a3e27-a33f-479c-823f-80397c07eb31';
    $display->content['new-c39a3e27-a33f-479c-823f-80397c07eb31'] = $pane;
    $display->panels['right'][1] = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
    $pane = new stdClass();
    $pane->pid = 'new-14c72fa4-5dcd-4dc9-abd8-1bec282513d6';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_content_certification-panel_pane_certification_likes';
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
    $pane->uuid = '14c72fa4-5dcd-4dc9-abd8-1bec282513d6';
    $display->content['new-14c72fa4-5dcd-4dc9-abd8-1bec282513d6'] = $pane;
    $display->panels['right'][2] = 'new-14c72fa4-5dcd-4dc9-abd8-1bec282513d6';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_certification_certifiable'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_certification_certifiable_by_comments';
  $page->task = 'page';
  $page->admin_title = 'Control center certification certifiable by comments';
  $page->admin_description = '';
  $page->path = 'admin/control-center/certifications/certifiable-by-comments';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Exceed comments',
    'name' => 'navigation',
    'weight' => '2',
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
  $handler->name = 'page_control_center_certification_certifiable_by_comments_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_certification_certifiable_by_comments';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'community-admin',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
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
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b89152c8-9f52-48b9-80d3-8748b40d0cd9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
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
    $pane->uuid = 'fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $display->content['new-fe311408-4ff3-4552-ab42-6154b0cdb3ef'] = $pane;
    $display->panels['right'][0] = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $pane = new stdClass();
    $pane->pid = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
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
    $pane->uuid = 'c39a3e27-a33f-479c-823f-80397c07eb31';
    $display->content['new-c39a3e27-a33f-479c-823f-80397c07eb31'] = $pane;
    $display->panels['right'][1] = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
    $pane = new stdClass();
    $pane->pid = 'new-3b808937-d724-4d9d-92a3-0cb486381cfd';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_content_certification-panel_pane_certification_comments';
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
    $pane->uuid = '3b808937-d724-4d9d-92a3-0cb486381cfd';
    $display->content['new-3b808937-d724-4d9d-92a3-0cb486381cfd'] = $pane;
    $display->panels['right'][2] = 'new-3b808937-d724-4d9d-92a3-0cb486381cfd';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_certification_certifiable_by_comments'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_certification_certifiable_by_ratings';
  $page->task = 'page';
  $page->admin_title = 'Control center certification certifiable by votings';
  $page->admin_description = '';
  $page->path = 'admin/control-center/certifications/certifiable-by-votings';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Exceed votes',
    'name' => 'navigation',
    'weight' => '3',
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
  $handler->name = 'page_control_center_certification_certifiable_by_ratings_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_certification_certifiable_by_ratings';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'community-admin',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
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
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b89152c8-9f52-48b9-80d3-8748b40d0cd9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
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
    $pane->uuid = 'fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $display->content['new-fe311408-4ff3-4552-ab42-6154b0cdb3ef'] = $pane;
    $display->panels['right'][0] = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $pane = new stdClass();
    $pane->pid = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
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
    $pane->uuid = 'c39a3e27-a33f-479c-823f-80397c07eb31';
    $display->content['new-c39a3e27-a33f-479c-823f-80397c07eb31'] = $pane;
    $display->panels['right'][1] = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
    $pane = new stdClass();
    $pane->pid = 'new-87469644-e9e9-418c-8c0b-6dff449b11c6';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_content_certification-panel_pane_certification_votings';
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
    $pane->uuid = '87469644-e9e9-418c-8c0b-6dff449b11c6';
    $display->content['new-87469644-e9e9-418c-8c0b-6dff449b11c6'] = $pane;
    $display->panels['right'][2] = 'new-87469644-e9e9-418c-8c0b-6dff449b11c6';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_certification_certifiable_by_ratings'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_certification_certifiable_by_visits';
  $page->task = 'page';
  $page->admin_title = 'Control center certification certifiable by visits';
  $page->admin_description = '';
  $page->path = 'admin/control-center/certifications/certifiable-by-visits';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Exceed visits',
    'name' => 'navigation',
    'weight' => '4',
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
  $handler->name = 'page_control_center_certification_certifiable_by_visits_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_certification_certifiable_by_visits';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'community-admin',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
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
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b89152c8-9f52-48b9-80d3-8748b40d0cd9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
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
    $pane->uuid = 'fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $display->content['new-fe311408-4ff3-4552-ab42-6154b0cdb3ef'] = $pane;
    $display->panels['right'][0] = 'new-fe311408-4ff3-4552-ab42-6154b0cdb3ef';
    $pane = new stdClass();
    $pane->pid = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
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
    $pane->uuid = 'c39a3e27-a33f-479c-823f-80397c07eb31';
    $display->content['new-c39a3e27-a33f-479c-823f-80397c07eb31'] = $pane;
    $display->panels['right'][1] = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
    $pane = new stdClass();
    $pane->pid = 'new-97392648-df13-4036-bf96-804c69364194';
    $pane->panel = 'right';
    $pane->type = 'certification_by_visits';
    $pane->subtype = 'certification_by_visits';
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
    $pane->uuid = '97392648-df13-4036-bf96-804c69364194';
    $display->content['new-97392648-df13-4036-bf96-804c69364194'] = $pane;
    $display->panels['right'][2] = 'new-97392648-df13-4036-bf96-804c69364194';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_certification_certifiable_by_visits'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_certifications_list';
  $page->task = 'page';
  $page->admin_title = 'Control center certifications list';
  $page->admin_description = '';
  $page->path = 'admin/control-center/certifications/list';
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
    'title' => 'Administrar certificaciones',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => 'Administer communities',
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
  $handler->name = 'page_control_center_certifications_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_certifications_list';
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
  $display->title = 'Administrar certificaciones';
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
    $pane->pid = 'new-cccdfe36-962d-4844-933e-36cd48b22ec0';
    $pane->panel = 'right';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = FALSE;
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
    $pane->uuid = 'cccdfe36-962d-4844-933e-36cd48b22ec0';
    $display->content['new-cccdfe36-962d-4844-933e-36cd48b22ec0'] = $pane;
    $display->panels['right'][1] = 'new-cccdfe36-962d-4844-933e-36cd48b22ec0';
    $pane = new stdClass();
    $pane->pid = 'new-bc663c7e-2bd2-4135-8f20-78e014173abb';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_content_certification-panel_pane_certifications_list';
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
    $pane->uuid = 'bc663c7e-2bd2-4135-8f20-78e014173abb';
    $display->content['new-bc663c7e-2bd2-4135-8f20-78e014173abb'] = $pane;
    $display->panels['right'][2] = 'new-bc663c7e-2bd2-4135-8f20-78e014173abb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_certifications_list'] = $page;

  return $pages;

}
