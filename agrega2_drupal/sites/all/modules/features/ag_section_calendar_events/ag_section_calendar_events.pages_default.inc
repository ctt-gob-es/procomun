<?php
/**
 * @file
 * ag_section_calendar_events.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ag_section_calendar_events_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Event variant',
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
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'event' => 'event',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'ag-9-3';
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
  $display->uuid = '68905622-d64e-48b5-b985-e0a6a2ca55b1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9f077794-e3a5-482c-a3dc-549ea4707cb4';
    $pane->panel = 'left';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '%node:title-field',
      'override_title_heading' => 'h1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'node node-event',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9f077794-e3a5-482c-a3dc-549ea4707cb4';
    $display->content['new-9f077794-e3a5-482c-a3dc-549ea4707cb4'] = $pane;
    $display->panels['left'][0] = 'new-9f077794-e3a5-482c-a3dc-549ea4707cb4';
    $pane = new stdClass();
    $pane->pid = 'new-677bbc9f-b604-4e96-b126-546f7627fb8d';
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
    $pane->uuid = '677bbc9f-b604-4e96-b126-546f7627fb8d';
    $display->content['new-677bbc9f-b604-4e96-b126-546f7627fb8d'] = $pane;
    $display->panels['right'][0] = 'new-677bbc9f-b604-4e96-b126-546f7627fb8d';
    $pane = new stdClass();
    $pane->pid = 'new-79e9cd6e-c8ff-40df-950f-53d56427c281';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'events_calendar-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '79e9cd6e-c8ff-40df-950f-53d56427c281';
    $display->content['new-79e9cd6e-c8ff-40df-950f-53d56427c281'] = $pane;
    $display->panels['right'][1] = 'new-79e9cd6e-c8ff-40df-950f-53d56427c281';
    $pane = new stdClass();
    $pane->pid = 'new-b93649f9-6701-4e6b-801b-02d2672855d3';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'events_calendar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'upcoming_events',
      'context' => array(
        0 => '',
      ),
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
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b93649f9-6701-4e6b-801b-02d2672855d3';
    $display->content['new-b93649f9-6701-4e6b-801b-02d2672855d3'] = $pane;
    $display->panels['right'][2] = 'new-b93649f9-6701-4e6b-801b-02d2672855d3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9f077794-e3a5-482c-a3dc-549ea4707cb4';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_calendar_events_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community_events';
  $page->task = 'page';
  $page->admin_title = 'Community events';
  $page->admin_description = 'Events associated to a community';
  $page->path = 'node/%node/events';
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
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer group',
        ),
        'context' => 'logged-in-user',
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
  $handler->name = 'page_community_events_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community_events';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Community events',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'community-events',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
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
  $display->title = 'Eventos';
  $display->uuid = 'ffc14914-d2af-45c8-b635-a04a3c6f45af';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-83c4d27c-0337-4b2e-a671-6875f4c18268';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-2c76rGnijKTkNQrvh3BxiEg0ZP4Kcz6i';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filtrar por tipo de evento',
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
    $pane->uuid = '83c4d27c-0337-4b2e-a671-6875f4c18268';
    $display->content['new-83c4d27c-0337-4b2e-a671-6875f4c18268'] = $pane;
    $display->panels['left'][0] = 'new-83c4d27c-0337-4b2e-a671-6875f4c18268';
    $pane = new stdClass();
    $pane->pid = 'new-cfd64c88-b243-462f-9422-2dbb3af52c6f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_events-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cfd64c88-b243-462f-9422-2dbb3af52c6f';
    $display->content['new-cfd64c88-b243-462f-9422-2dbb3af52c6f'] = $pane;
    $display->panels['middle'][0] = 'new-cfd64c88-b243-462f-9422-2dbb3af52c6f';
    $pane = new stdClass();
    $pane->pid = 'new-3942f566-2c85-4ac6-9838-49c2b4de339d';
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
    $pane->uuid = '3942f566-2c85-4ac6-9838-49c2b4de339d';
    $display->content['new-3942f566-2c85-4ac6-9838-49c2b4de339d'] = $pane;
    $display->panels['right'][0] = 'new-3942f566-2c85-4ac6-9838-49c2b4de339d';
    $pane = new stdClass();
    $pane->pid = 'new-4887ec86-c325-4895-bd6b-802ac83db663';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'events_calendar-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4887ec86-c325-4895-bd6b-802ac83db663';
    $display->content['new-4887ec86-c325-4895-bd6b-802ac83db663'] = $pane;
    $display->panels['right'][1] = 'new-4887ec86-c325-4895-bd6b-802ac83db663';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community_events'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community_filter_events';
  $page->task = 'page';
  $page->admin_title = 'Community filter events';
  $page->admin_description = 'Events filterd by timestamps';
  $page->path = 'node/%node/events/%time';
  $page->access = array(
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
    'time' => array(
      'id' => 1,
      'identifier' => 'Texto',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_community_filter_events_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community_filter_events';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Eventos',
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
  $display->title = '';
  $display->uuid = '7443a694-cd9a-4587-8fdf-516f40f7eb30';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7dea2319-07f6-48cf-ab05-b24c21615509';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-2c76rGnijKTkNQrvh3BxiEg0ZP4Kcz6i';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7dea2319-07f6-48cf-ab05-b24c21615509';
    $display->content['new-7dea2319-07f6-48cf-ab05-b24c21615509'] = $pane;
    $display->panels['left'][0] = 'new-7dea2319-07f6-48cf-ab05-b24c21615509';
    $pane = new stdClass();
    $pane->pid = 'new-e46abe07-32b5-4894-bd4d-fa3810aab1b9';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_events-panel_pane_2';
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
    $pane->uuid = 'e46abe07-32b5-4894-bd4d-fa3810aab1b9';
    $display->content['new-e46abe07-32b5-4894-bd4d-fa3810aab1b9'] = $pane;
    $display->panels['middle'][0] = 'new-e46abe07-32b5-4894-bd4d-fa3810aab1b9';
    $pane = new stdClass();
    $pane->pid = 'new-fde8711d-0562-42a2-86e7-c11cc5e9eed0';
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
    $pane->uuid = 'fde8711d-0562-42a2-86e7-c11cc5e9eed0';
    $display->content['new-fde8711d-0562-42a2-86e7-c11cc5e9eed0'] = $pane;
    $display->panels['right'][0] = 'new-fde8711d-0562-42a2-86e7-c11cc5e9eed0';
    $pane = new stdClass();
    $pane->pid = 'new-c8f08404-6618-4fdd-a2c7-a65c49a168f3';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'events_calendar-panel_pane_1';
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
    $pane->uuid = 'c8f08404-6618-4fdd-a2c7-a65c49a168f3';
    $display->content['new-c8f08404-6618-4fdd-a2c7-a65c49a168f3'] = $pane;
    $display->panels['right'][1] = 'new-c8f08404-6618-4fdd-a2c7-a65c49a168f3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community_filter_events'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_events';
  $page->task = 'page';
  $page->admin_title = 'User events';
  $page->admin_description = 'List of user\'s events';
  $page->path = 'user/%uid/events';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'uid' => array(
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
  $handler->name = 'page_user_events_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_events';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User events',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'user-events-list',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
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
  $display->title = 'Eventos';
  $display->uuid = '421dc6a0-a6e8-4025-b52c-27c6aa312688';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-704695fd-7964-46ac-aa56-fa784ab1e39d';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-2c76rGnijKTkNQrvh3BxiEg0ZP4Kcz6i';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '704695fd-7964-46ac-aa56-fa784ab1e39d';
    $display->content['new-704695fd-7964-46ac-aa56-fa784ab1e39d'] = $pane;
    $display->panels['left'][0] = 'new-704695fd-7964-46ac-aa56-fa784ab1e39d';
    $pane = new stdClass();
    $pane->pid = 'new-0f3a2ba3-b894-43a4-be1a-beb45207a675';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_events-panel_pane_2';
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
    $pane->uuid = '0f3a2ba3-b894-43a4-be1a-beb45207a675';
    $display->content['new-0f3a2ba3-b894-43a4-be1a-beb45207a675'] = $pane;
    $display->panels['middle'][0] = 'new-0f3a2ba3-b894-43a4-be1a-beb45207a675';
    $pane = new stdClass();
    $pane->pid = 'new-9d9cb978-a529-49bd-a53d-c70df54f1509';
    $pane->panel = 'right';
    $pane->type = 'user_activity_summary';
    $pane->subtype = 'user_activity_summary';
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
    $pane->uuid = '9d9cb978-a529-49bd-a53d-c70df54f1509';
    $display->content['new-9d9cb978-a529-49bd-a53d-c70df54f1509'] = $pane;
    $display->panels['right'][0] = 'new-9d9cb978-a529-49bd-a53d-c70df54f1509';
    $pane = new stdClass();
    $pane->pid = 'new-af7bf7b1-f352-4cf1-9bcb-e11ac6bb1560';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_2';
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
    $pane->uuid = 'af7bf7b1-f352-4cf1-9bcb-e11ac6bb1560';
    $display->content['new-af7bf7b1-f352-4cf1-9bcb-e11ac6bb1560'] = $pane;
    $display->panels['right'][1] = 'new-af7bf7b1-f352-4cf1-9bcb-e11ac6bb1560';
    $pane = new stdClass();
    $pane->pid = 'new-67b88dbf-763c-4bcd-915e-fc351c6c22b0';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '67b88dbf-763c-4bcd-915e-fc351c6c22b0';
    $display->content['new-67b88dbf-763c-4bcd-915e-fc351c6c22b0'] = $pane;
    $display->panels['right'][2] = 'new-67b88dbf-763c-4bcd-915e-fc351c6c22b0';
    $pane = new stdClass();
    $pane->pid = 'new-3d0a07f4-9496-4ee9-bd93-379d6fa5d90c';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3d0a07f4-9496-4ee9-bd93-379d6fa5d90c';
    $display->content['new-3d0a07f4-9496-4ee9-bd93-379d6fa5d90c'] = $pane;
    $display->panels['right'][3] = 'new-3d0a07f4-9496-4ee9-bd93-379d6fa5d90c';
    $pane = new stdClass();
    $pane->pid = 'new-b6ec444d-f225-4ed1-aaf7-00cb85450a8f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'events_calendar-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'b6ec444d-f225-4ed1-aaf7-00cb85450a8f';
    $display->content['new-b6ec444d-f225-4ed1-aaf7-00cb85450a8f'] = $pane;
    $display->panels['right'][4] = 'new-b6ec444d-f225-4ed1-aaf7-00cb85450a8f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_events'] = $page;

  return $pages;

}
