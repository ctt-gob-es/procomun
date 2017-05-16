<?php
/**
 * @file
 * control_center_communities.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_communities_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community_polls_list';
  $page->task = 'page';
  $page->admin_title = 'Community polls list';
  $page->admin_description = '';
  $page->path = 'node/%node/polls';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer group',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'entity_field_value:node:social_network:group_access',
        'settings' => array(
          'group_access' => array(
            'und' => array(
              0 => array(
                'value' => '0',
              ),
            ),
          ),
          'group_access_value' => '0',
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Nodo: ID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_community_polls_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community_polls_list';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'list-polls',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'ag-3up-6-3';
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
  $display->title = 'Encuestas de la comunidad';
  $display->uuid = '27e2d546-03e0-4d7a-bbc6-c0412ebcea01';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c65e9779-7eaa-45ef-9998-89a37958d976';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-bIq14AD9JZrvz6dM36J1YANBY2PjmUhL';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filtrar por estado',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c65e9779-7eaa-45ef-9998-89a37958d976';
    $display->content['new-c65e9779-7eaa-45ef-9998-89a37958d976'] = $pane;
    $display->panels['left'][0] = 'new-c65e9779-7eaa-45ef-9998-89a37958d976';
    $pane = new stdClass();
    $pane->pid = 'new-5ecb0a95-d6d2-4ad9-b407-4e275b548785';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag2_og_polls_list-panel_pane_1';
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
    $pane->uuid = '5ecb0a95-d6d2-4ad9-b407-4e275b548785';
    $display->content['new-5ecb0a95-d6d2-4ad9-b407-4e275b548785'] = $pane;
    $display->panels['middle'][0] = 'new-5ecb0a95-d6d2-4ad9-b407-4e275b548785';
    $pane = new stdClass();
    $pane->pid = 'new-ed7ec460-2352-413f-815c-049c028d9f39';
    $pane->panel = 'right';
    $pane->type = 'comunity_public_dashboard';
    $pane->subtype = 'comunity_public_dashboard';
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
    $pane->uuid = 'ed7ec460-2352-413f-815c-049c028d9f39';
    $display->content['new-ed7ec460-2352-413f-815c-049c028d9f39'] = $pane;
    $display->panels['right'][0] = 'new-ed7ec460-2352-413f-815c-049c028d9f39';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community_polls_list'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_communities_list';
  $page->task = 'page';
  $page->admin_title = 'Control center communities list';
  $page->admin_description = 'Admin control center page for communities';
  $page->path = 'admin/control-center/communities/list';
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
    'type' => 'default tab',
    'title' => 'Administer communities',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
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
  $handler->name = 'page_control_center_communities_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_communities_list';
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
  $display->title = '';
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
    $pane->pid = 'new-cccdfe36-962d-4844-933e-36cd48b22ec0';
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
    $pane->uuid = 'cccdfe36-962d-4844-933e-36cd48b22ec0';
    $display->content['new-cccdfe36-962d-4844-933e-36cd48b22ec0'] = $pane;
    $display->panels['right'][2] = 'new-cccdfe36-962d-4844-933e-36cd48b22ec0';
    $pane = new stdClass();
    $pane->pid = 'new-d1a810e2-92b5-46da-8082-dac0e34bf401';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_communities_administration-panel_pane_2';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd1a810e2-92b5-46da-8082-dac0e34bf401';
    $display->content['new-d1a810e2-92b5-46da-8082-dac0e34bf401'] = $pane;
    $display->panels['right'][3] = 'new-d1a810e2-92b5-46da-8082-dac0e34bf401';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-d1a810e2-92b5-46da-8082-dac0e34bf401';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_communities_list'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_communities_manage_users';
  $page->task = 'page';
  $page->admin_title = 'Control center communities manage users';
  $page->admin_description = 'Admin control center page for manage community users';
  $page->path = '/admin/control-center/community/%node/users';
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
    'type' => 'none',
    'title' => 'Administer community users',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Administer communities',
      'name' => 'menu-control-center-main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Nodo: ID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_control_center_communities_manage_users_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_communities_manage_users';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Control center communities manage users',
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
  $display->title = '';
  $display->uuid = '7d8cf0ca-2dcf-46b8-a9a2-c177b5b02e6f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-13e31121-08ff-448a-8a26-d3360c4c184d';
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
    $pane->uuid = '13e31121-08ff-448a-8a26-d3360c4c184d';
    $display->content['new-13e31121-08ff-448a-8a26-d3360c4c184d'] = $pane;
    $display->panels['right'][0] = 'new-13e31121-08ff-448a-8a26-d3360c4c184d';
    $pane = new stdClass();
    $pane->pid = 'new-e51a1d6c-86f4-433d-8dae-53b3bc6fe901';
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
    $pane->uuid = 'e51a1d6c-86f4-433d-8dae-53b3bc6fe901';
    $display->content['new-e51a1d6c-86f4-433d-8dae-53b3bc6fe901'] = $pane;
    $display->panels['right'][1] = 'new-e51a1d6c-86f4-433d-8dae-53b3bc6fe901';
    $pane = new stdClass();
    $pane->pid = 'new-089f4466-9f3d-42fc-a499-b81ccc27ee68';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'control_center_communities-ccenter_manage_community_users';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '089f4466-9f3d-42fc-a499-b81ccc27ee68';
    $display->content['new-089f4466-9f3d-42fc-a499-b81ccc27ee68'] = $pane;
    $display->panels['right'][2] = 'new-089f4466-9f3d-42fc-a499-b81ccc27ee68';
    $pane = new stdClass();
    $pane->pid = 'new-76faf1fb-f8ae-4f82-a7b2-a170d1119b96';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_communities_user_administration-panel_pane_1';
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
    $pane->uuid = '76faf1fb-f8ae-4f82-a7b2-a170d1119b96';
    $display->content['new-76faf1fb-f8ae-4f82-a7b2-a170d1119b96'] = $pane;
    $display->panels['right'][3] = 'new-76faf1fb-f8ae-4f82-a7b2-a170d1119b96';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_communities_manage_users'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_community_add_users';
  $page->task = 'page';
  $page->admin_title = 'Control center community add users';
  $page->admin_description = '';
  $page->path = '/admin/control-center/community/%node/users/add-user';
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
    'type' => 'none',
    'title' => 'Add users',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => '',
      'name' => 'menu-control-center-main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
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
  $handler->name = 'page_control_center_community_add_users_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_community_add_users';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Control center community add user',
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
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2ebf2822-96e5-42dd-838e-17b04dfa9bfa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-97a9fd61-31a2-482f-92a4-15f6328b0006';
    $pane->panel = 'middle';
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
    $pane->uuid = '97a9fd61-31a2-482f-92a4-15f6328b0006';
    $display->content['new-97a9fd61-31a2-482f-92a4-15f6328b0006'] = $pane;
    $display->panels['middle'][0] = 'new-97a9fd61-31a2-482f-92a4-15f6328b0006';
    $pane = new stdClass();
    $pane->pid = 'new-bc886539-b1d7-4eb6-b26f-fe5208043edd';
    $pane->panel = 'middle';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
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
    $pane->uuid = 'bc886539-b1d7-4eb6-b26f-fe5208043edd';
    $display->content['new-bc886539-b1d7-4eb6-b26f-fe5208043edd'] = $pane;
    $display->panels['middle'][1] = 'new-bc886539-b1d7-4eb6-b26f-fe5208043edd';
    $pane = new stdClass();
    $pane->pid = 'new-65b5702a-39aa-465b-9190-ff28495ab5d1';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'control_center_communities-ccenter_manage_community_users';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '65b5702a-39aa-465b-9190-ff28495ab5d1';
    $display->content['new-65b5702a-39aa-465b-9190-ff28495ab5d1'] = $pane;
    $display->panels['middle'][2] = 'new-65b5702a-39aa-465b-9190-ff28495ab5d1';
    $pane = new stdClass();
    $pane->pid = 'new-cd4dd135-ca72-425b-895f-db6db3387c4b';
    $pane->panel = 'middle';
    $pane->type = 'community_adduser';
    $pane->subtype = 'community_adduser';
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
    $pane->uuid = 'cd4dd135-ca72-425b-895f-db6db3387c4b';
    $display->content['new-cd4dd135-ca72-425b-895f-db6db3387c4b'] = $pane;
    $display->panels['middle'][3] = 'new-cd4dd135-ca72-425b-895f-db6db3387c4b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_community_add_users'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'pending_communities_administration';
  $page->task = 'page';
  $page->admin_title = 'Administración de comunidades pendientes';
  $page->admin_description = 'Administration page where the administrators approve o reject the creation of a community';
  $page->path = 'admin/control-center/communities/pending';
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
    'title' => 'Pending communities',
    'name' => 'navigation',
    'weight' => '0',
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
  $handler->name = 'page_pending_communities_administration_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'pending_communities_administration';
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
    $pane->pid = 'new-1c296620-569e-4668-a6d7-e88e7aa26297';
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
    $pane->uuid = '1c296620-569e-4668-a6d7-e88e7aa26297';
    $display->content['new-1c296620-569e-4668-a6d7-e88e7aa26297'] = $pane;
    $display->panels['right'][1] = 'new-1c296620-569e-4668-a6d7-e88e7aa26297';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c39a3e27-a33f-479c-823f-80397c07eb31';
    $display->content['new-c39a3e27-a33f-479c-823f-80397c07eb31'] = $pane;
    $display->panels['right'][2] = 'new-c39a3e27-a33f-479c-823f-80397c07eb31';
    $pane = new stdClass();
    $pane->pid = 'new-4610b759-7a25-4bc9-9e0e-ebab4774cf05';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_communities_administration-panel_pane_1';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4610b759-7a25-4bc9-9e0e-ebab4774cf05';
    $display->content['new-4610b759-7a25-4bc9-9e0e-ebab4774cf05'] = $pane;
    $display->panels['right'][3] = 'new-4610b759-7a25-4bc9-9e0e-ebab4774cf05';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-4610b759-7a25-4bc9-9e0e-ebab4774cf05';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['pending_communities_administration'] = $page;

  return $pages;

}
