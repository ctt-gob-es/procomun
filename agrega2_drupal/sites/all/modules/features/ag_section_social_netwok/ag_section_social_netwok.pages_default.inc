<?php
/**
 * @file
 * ag_section_social_netwok.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ag_section_social_netwok_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Comunity variant',
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
          'name' => 'og_is_node_group',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
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
  $display->uuid = 'eab12129-829e-4cab-92a2-f50cc6229389';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8fe15f87-f681-4395-bf3e-5f4d4b533a9a';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_social_netwok-facet_filter_title';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8fe15f87-f681-4395-bf3e-5f4d4b533a9a';
    $display->content['new-8fe15f87-f681-4395-bf3e-5f4d4b533a9a'] = $pane;
    $display->panels['left'][0] = 'new-8fe15f87-f681-4395-bf3e-5f4d4b533a9a';
    $pane = new stdClass();
    $pane->pid = 'new-469ebb8d-42f6-4620-bece-2def0508a7e4';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-vUx6UkRX1IxHdXc9Yn5ARYyauECJXBc0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Autor',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '469ebb8d-42f6-4620-bece-2def0508a7e4';
    $display->content['new-469ebb8d-42f6-4620-bece-2def0508a7e4'] = $pane;
    $display->panels['left'][1] = 'new-469ebb8d-42f6-4620-bece-2def0508a7e4';
    $pane = new stdClass();
    $pane->pid = 'new-b318b391-98ce-40e4-a5c1-c95a8ff7a70c';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-lh8c64a5SknW4lSA3GtTPLY0P9sNseBb';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Categoría',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b318b391-98ce-40e4-a5c1-c95a8ff7a70c';
    $display->content['new-b318b391-98ce-40e4-a5c1-c95a8ff7a70c'] = $pane;
    $display->panels['left'][2] = 'new-b318b391-98ce-40e4-a5c1-c95a8ff7a70c';
    $pane = new stdClass();
    $pane->pid = 'new-b0626666-5206-4ac1-a70a-0b374b74f4e6';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-6IEpUbrUKUlC10KbBHAgRm0t5C6M0nJ1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Etiqueta',
      'override_title_heading' => 'h2',
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
    $pane->uuid = 'b0626666-5206-4ac1-a70a-0b374b74f4e6';
    $display->content['new-b0626666-5206-4ac1-a70a-0b374b74f4e6'] = $pane;
    $display->panels['left'][3] = 'new-b0626666-5206-4ac1-a70a-0b374b74f4e6';
    $pane = new stdClass();
    $pane->pid = 'new-5c02924a-1edf-4357-9fdb-5342a2e3e776';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-kaGeIwItrIsXU5JmR5Wfx0DFLE5Ua0Ga';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Tipo de contenido',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5c02924a-1edf-4357-9fdb-5342a2e3e776';
    $display->content['new-5c02924a-1edf-4357-9fdb-5342a2e3e776'] = $pane;
    $display->panels['left'][4] = 'new-5c02924a-1edf-4357-9fdb-5342a2e3e776';
    $pane = new stdClass();
    $pane->pid = 'new-895ab787-c959-488e-843f-91a6f7e1f578';
    $pane->panel = 'middle';
    $pane->type = 'wall_node_create_links';
    $pane->subtype = 'wall_node_create_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'types' => array(
        'itinerary' => 'itinerary',
        'event' => 'event',
        'podcast' => 'podcast',
        'post' => 'post',
        'question' => 'question',
        'webinar' => 'webinar',
        'ode' => 'ode',
        'poll' => 'poll',
      ),
      'field_name' => 'og_group_ref',
      'types_labels' => array(
        'event' => 'Event',
        'post' => 'Post',
        'answer' => '',
        'poll' => 'Poll',
        'recurso_de_aprendizaje' => '',
        'debate' => '',
        'question' => 'Question',
        'ode' => 'Learning resource',
        'simplenews' => '',
        'itinerary' => 'Learning path',
        'podcast' => 'Podcast',
        'external_content' => '',
        'webinar' => 'Webinar',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '895ab787-c959-488e-843f-91a6f7e1f578';
    $display->content['new-895ab787-c959-488e-843f-91a6f7e1f578'] = $pane;
    $display->panels['middle'][0] = 'new-895ab787-c959-488e-843f-91a6f7e1f578';
    $pane = new stdClass();
    $pane->pid = 'new-06699641-8aff-4cc8-a128-d174d4438388';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'community_wall_faceted_search-panel_pane_1';
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
    $pane->uuid = '06699641-8aff-4cc8-a128-d174d4438388';
    $display->content['new-06699641-8aff-4cc8-a128-d174d4438388'] = $pane;
    $display->panels['middle'][1] = 'new-06699641-8aff-4cc8-a128-d174d4438388';
    $pane = new stdClass();
    $pane->pid = 'new-0ea389f6-4dff-4bd4-b4f8-e9aedb1b48e5';
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
    $pane->uuid = '0ea389f6-4dff-4bd4-b4f8-e9aedb1b48e5';
    $display->content['new-0ea389f6-4dff-4bd4-b4f8-e9aedb1b48e5'] = $pane;
    $display->panels['right'][0] = 'new-0ea389f6-4dff-4bd4-b4f8-e9aedb1b48e5';
    $pane = new stdClass();
    $pane->pid = 'new-55af95a3-0cd0-4110-9e40-322336fe7e03';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'white-title-orange',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '55af95a3-0cd0-4110-9e40-322336fe7e03';
    $display->content['new-55af95a3-0cd0-4110-9e40-322336fe7e03'] = $pane;
    $display->panels['right'][1] = 'new-55af95a3-0cd0-4110-9e40-322336fe7e03';
    $pane = new stdClass();
    $pane->pid = 'new-4d12d790-f4fe-430b-95d3-63f5b111e500';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_questions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4d12d790-f4fe-430b-95d3-63f5b111e500';
    $display->content['new-4d12d790-f4fe-430b-95d3-63f5b111e500'] = $pane;
    $display->panels['right'][2] = 'new-4d12d790-f4fe-430b-95d3-63f5b111e500';
    $pane = new stdClass();
    $pane->pid = 'new-9b74bce9-8bb1-4701-bba4-bd7e11542b52';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '9b74bce9-8bb1-4701-bba4-bd7e11542b52';
    $display->content['new-9b74bce9-8bb1-4701-bba4-bd7e11542b52'] = $pane;
    $display->panels['right'][3] = 'new-9b74bce9-8bb1-4701-bba4-bd7e11542b52';
    $pane = new stdClass();
    $pane->pid = 'new-94ded04b-9953-42eb-ba48-63e7270d1ab5';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '94ded04b-9953-42eb-ba48-63e7270d1ab5';
    $display->content['new-94ded04b-9953-42eb-ba48-63e7270d1ab5'] = $pane;
    $display->panels['right'][4] = 'new-94ded04b-9953-42eb-ba48-63e7270d1ab5';
    $pane = new stdClass();
    $pane->pid = 'new-c28bf85e-c53d-41f2-b381-ac6c9c9cff6f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_polls-panel_pane_1';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c28bf85e-c53d-41f2-b381-ac6c9c9cff6f';
    $display->content['new-c28bf85e-c53d-41f2-b381-ac6c9c9cff6f'] = $pane;
    $display->panels['right'][5] = 'new-c28bf85e-c53d-41f2-b381-ac6c9c9cff6f';
    $pane = new stdClass();
    $pane->pid = 'new-1d38d165-1033-44e2-8604-52dd5300126c';
    $pane->panel = 'right';
    $pane->type = 'community_related_content';
    $pane->subtype = 'community_related_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '1d38d165-1033-44e2-8604-52dd5300126c';
    $display->content['new-1d38d165-1033-44e2-8604-52dd5300126c'] = $pane;
    $display->panels['right'][6] = 'new-1d38d165-1033-44e2-8604-52dd5300126c';
    $pane = new stdClass();
    $pane->pid = 'new-b1e35cc5-1b86-4cd8-88ec-9cc28a6e2468';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_voted_content-panel_pane_1';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'b1e35cc5-1b86-4cd8-88ec-9cc28a6e2468';
    $display->content['new-b1e35cc5-1b86-4cd8-88ec-9cc28a6e2468'] = $pane;
    $display->panels['right'][7] = 'new-b1e35cc5-1b86-4cd8-88ec-9cc28a6e2468';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0ea389f6-4dff-4bd4-b4f8-e9aedb1b48e5';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_social_netwok_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community_about_page';
  $page->task = 'page';
  $page->admin_title = 'Community about page';
  $page->admin_description = 'The about page of a community';
  $page->path = 'node/%node/about';
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
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_community_about_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community_about_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'About page',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->title = 'Acerca de %node:title_field';
  $display->uuid = '4e446691-addc-46ca-a858-ae26933dedc8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e52e377-6dc3-487b-98e5-6ed3670beece';
    $pane->panel = 'left';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '5e52e377-6dc3-487b-98e5-6ed3670beece';
    $display->content['new-5e52e377-6dc3-487b-98e5-6ed3670beece'] = $pane;
    $display->panels['left'][0] = 'new-5e52e377-6dc3-487b-98e5-6ed3670beece';
    $pane = new stdClass();
    $pane->pid = 'new-0513c164-751a-4368-8c65-f8946bb549ee';
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
    $pane->uuid = '0513c164-751a-4368-8c65-f8946bb549ee';
    $display->content['new-0513c164-751a-4368-8c65-f8946bb549ee'] = $pane;
    $display->panels['right'][0] = 'new-0513c164-751a-4368-8c65-f8946bb549ee';
    $pane = new stdClass();
    $pane->pid = 'new-35f2dc06-8ed6-4b20-8937-c749d5c4a8cc';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_1';
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
    $pane->uuid = '35f2dc06-8ed6-4b20-8937-c749d5c4a8cc';
    $display->content['new-35f2dc06-8ed6-4b20-8937-c749d5c4a8cc'] = $pane;
    $display->panels['right'][1] = 'new-35f2dc06-8ed6-4b20-8937-c749d5c4a8cc';
    $pane = new stdClass();
    $pane->pid = 'new-03fd1eb3-08d7-47a1-a34d-055df0f34614';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_questions-panel_pane_1';
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
    $pane->uuid = '03fd1eb3-08d7-47a1-a34d-055df0f34614';
    $display->content['new-03fd1eb3-08d7-47a1-a34d-055df0f34614'] = $pane;
    $display->panels['right'][2] = 'new-03fd1eb3-08d7-47a1-a34d-055df0f34614';
    $pane = new stdClass();
    $pane->pid = 'new-292db8da-883d-483b-9833-150e15d7e139';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '292db8da-883d-483b-9833-150e15d7e139';
    $display->content['new-292db8da-883d-483b-9833-150e15d7e139'] = $pane;
    $display->panels['right'][3] = 'new-292db8da-883d-483b-9833-150e15d7e139';
    $pane = new stdClass();
    $pane->pid = 'new-fcdcfc16-d9f9-4fed-90a7-49d3219f4fa2';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_polls-panel_pane_1';
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
    $pane->uuid = 'fcdcfc16-d9f9-4fed-90a7-49d3219f4fa2';
    $display->content['new-fcdcfc16-d9f9-4fed-90a7-49d3219f4fa2'] = $pane;
    $display->panels['right'][4] = 'new-fcdcfc16-d9f9-4fed-90a7-49d3219f4fa2';
    $pane = new stdClass();
    $pane->pid = 'new-7595ed0c-bef3-4745-bfb5-55d908edfa50';
    $pane->panel = 'right';
    $pane->type = 'community_related_content';
    $pane->subtype = 'community_related_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '7595ed0c-bef3-4745-bfb5-55d908edfa50';
    $display->content['new-7595ed0c-bef3-4745-bfb5-55d908edfa50'] = $pane;
    $display->panels['right'][5] = 'new-7595ed0c-bef3-4745-bfb5-55d908edfa50';
    $pane = new stdClass();
    $pane->pid = 'new-d058c3e2-fa54-4970-9c88-805dc75508c7';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_voted_content-panel_pane_1';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'd058c3e2-fa54-4970-9c88-805dc75508c7';
    $display->content['new-d058c3e2-fa54-4970-9c88-805dc75508c7'] = $pane;
    $display->panels['right'][6] = 'new-d058c3e2-fa54-4970-9c88-805dc75508c7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5e52e377-6dc3-487b-98e5-6ed3670beece';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community_about_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community_debates';
  $page->task = 'page';
  $page->admin_title = 'Community debates';
  $page->admin_description = 'This page has the debates of a specific community';
  $page->path = 'node/%node/debates';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_community_debates_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community_debates';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'community-debates panel-3-9',
    'css_id' => 'general-debates',
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
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Preguntas y debates';
  $display->uuid = '8343908c-9be1-4732-b0f3-735d975bc8d8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8f67c572-4053-4728-b7fe-70e23eb7a01a';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-tLtGcLQlt0CkxmDKS9NdJ4as0ATKMO5k';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filtrar por categoría',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-facetapi',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8f67c572-4053-4728-b7fe-70e23eb7a01a';
    $display->content['new-8f67c572-4053-4728-b7fe-70e23eb7a01a'] = $pane;
    $display->panels['left'][0] = 'new-8f67c572-4053-4728-b7fe-70e23eb7a01a';
    $pane = new stdClass();
    $pane->pid = 'new-d848f0ae-90c4-4fe9-92cc-1ad793e1cae1';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_questions_answers-selector_question_debate';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd848f0ae-90c4-4fe9-92cc-1ad793e1cae1';
    $display->content['new-d848f0ae-90c4-4fe9-92cc-1ad793e1cae1'] = $pane;
    $display->panels['middle'][0] = 'new-d848f0ae-90c4-4fe9-92cc-1ad793e1cae1';
    $pane = new stdClass();
    $pane->pid = 'new-b9004d71-9d07-43a4-920f-0d9b963ff76c';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_debates-panel_pane_1';
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
    $pane->uuid = 'b9004d71-9d07-43a4-920f-0d9b963ff76c';
    $display->content['new-b9004d71-9d07-43a4-920f-0d9b963ff76c'] = $pane;
    $display->panels['middle'][1] = 'new-b9004d71-9d07-43a4-920f-0d9b963ff76c';
    $pane = new stdClass();
    $pane->pid = 'new-8fbd8a0a-1552-4e3f-a895-9cce8c098cc4';
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
    $pane->uuid = '8fbd8a0a-1552-4e3f-a895-9cce8c098cc4';
    $display->content['new-8fbd8a0a-1552-4e3f-a895-9cce8c098cc4'] = $pane;
    $display->panels['right'][0] = 'new-8fbd8a0a-1552-4e3f-a895-9cce8c098cc4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community_debates'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'community_members';
  $page->task = 'page';
  $page->admin_title = 'Community members';
  $page->admin_description = '';
  $page->path = 'node/%node/members';
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
  $handler->name = 'page_community_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'community_members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'community-members',
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
  $display->title = 'Miembros de la comunidad';
  $display->uuid = '055537d9-0073-4ac6-9b17-6ed6cb17f44e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c7e59d1a-9ae8-40fa-a046-4a2194614531';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-WCo9nYPWy0R1H150NAMG9gHYHBvoSyht';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filtrar por provincia',
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
    $pane->uuid = 'c7e59d1a-9ae8-40fa-a046-4a2194614531';
    $display->content['new-c7e59d1a-9ae8-40fa-a046-4a2194614531'] = $pane;
    $display->panels['left'][0] = 'new-c7e59d1a-9ae8-40fa-a046-4a2194614531';
    $pane = new stdClass();
    $pane->pid = 'new-c18d59b1-20ad-4420-9b63-d5c934bf0645';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag2_og_members_list-panel_pane_1';
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
    $pane->uuid = 'c18d59b1-20ad-4420-9b63-d5c934bf0645';
    $display->content['new-c18d59b1-20ad-4420-9b63-d5c934bf0645'] = $pane;
    $display->panels['middle'][0] = 'new-c18d59b1-20ad-4420-9b63-d5c934bf0645';
    $pane = new stdClass();
    $pane->pid = 'new-d500170f-38fa-40a7-aa23-4fa8a59a84de';
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
    $pane->uuid = 'd500170f-38fa-40a7-aa23-4fa8a59a84de';
    $display->content['new-d500170f-38fa-40a7-aa23-4fa8a59a84de'] = $pane;
    $display->panels['right'][0] = 'new-d500170f-38fa-40a7-aa23-4fa8a59a84de';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['community_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'favorites_list';
  $page->task = 'page';
  $page->admin_title = 'Favorites list';
  $page->admin_description = 'List of favorites of a given user';
  $page->path = 'user/%uid/favourites';
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
  $handler->name = 'page_favorites_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'favorites_list';
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
      'logic' => 'or',
      'plugins' => array(),
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
  $display->title = 'Favoritos';
  $display->uuid = '9d404103-227e-4b7c-86b5-bd6b2b29dc19';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-90779e67-8c56-4c5a-a51f-2dedd0a911fd';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_social_netwok-facet_filter_title';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '90779e67-8c56-4c5a-a51f-2dedd0a911fd';
    $display->content['new-90779e67-8c56-4c5a-a51f-2dedd0a911fd'] = $pane;
    $display->panels['left'][0] = 'new-90779e67-8c56-4c5a-a51f-2dedd0a911fd';
    $pane = new stdClass();
    $pane->pid = 'new-0742c00e-56bf-4b2a-9e79-0255b3212c18';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-gThU6jPBiACsw7srh3gPq9kOtJtE4CQs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Autor',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0742c00e-56bf-4b2a-9e79-0255b3212c18';
    $display->content['new-0742c00e-56bf-4b2a-9e79-0255b3212c18'] = $pane;
    $display->panels['left'][1] = 'new-0742c00e-56bf-4b2a-9e79-0255b3212c18';
    $pane = new stdClass();
    $pane->pid = 'new-d83bc5cc-d2d2-4520-ab20-d2673ed25d81';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-sEP6uotuiKWLyp7q9u8PpKbICaMhhgZt';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Categoría',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd83bc5cc-d2d2-4520-ab20-d2673ed25d81';
    $display->content['new-d83bc5cc-d2d2-4520-ab20-d2673ed25d81'] = $pane;
    $display->panels['left'][2] = 'new-d83bc5cc-d2d2-4520-ab20-d2673ed25d81';
    $pane = new stdClass();
    $pane->pid = 'new-3cc268e7-a421-4282-8fd9-65456495a944';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-zgLoasHZyNYhIFxU0eQw4FcbKv2b189J';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Etiqueta',
      'override_title_heading' => 'h2',
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
    $pane->uuid = '3cc268e7-a421-4282-8fd9-65456495a944';
    $display->content['new-3cc268e7-a421-4282-8fd9-65456495a944'] = $pane;
    $display->panels['left'][3] = 'new-3cc268e7-a421-4282-8fd9-65456495a944';
    $pane = new stdClass();
    $pane->pid = 'new-e11325ec-4233-4995-8792-3fd594a11a69';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-qd9znYK8kaC1dSng4NrLbmxuYbEoHQpA';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Tipo de contenido',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e11325ec-4233-4995-8792-3fd594a11a69';
    $display->content['new-e11325ec-4233-4995-8792-3fd594a11a69'] = $pane;
    $display->panels['left'][4] = 'new-e11325ec-4233-4995-8792-3fd594a11a69';
    $pane = new stdClass();
    $pane->pid = 'new-17bf7a4d-b674-47bc-ba60-4f2dad049795';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_favourites-panel_pane_my_favourites';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '17bf7a4d-b674-47bc-ba60-4f2dad049795';
    $display->content['new-17bf7a4d-b674-47bc-ba60-4f2dad049795'] = $pane;
    $display->panels['middle'][0] = 'new-17bf7a4d-b674-47bc-ba60-4f2dad049795';
    $pane = new stdClass();
    $pane->pid = 'new-0d13b2a0-beb1-4dcc-9fc0-5bbc131b8fdc';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_profile_users-user_activity_summary';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0d13b2a0-beb1-4dcc-9fc0-5bbc131b8fdc';
    $display->content['new-0d13b2a0-beb1-4dcc-9fc0-5bbc131b8fdc'] = $pane;
    $display->panels['right'][0] = 'new-0d13b2a0-beb1-4dcc-9fc0-5bbc131b8fdc';
    $pane = new stdClass();
    $pane->pid = 'new-b89bf22c-1780-4ba6-b945-0abaabe5d460';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_1';
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
    $pane->uuid = 'b89bf22c-1780-4ba6-b945-0abaabe5d460';
    $display->content['new-b89bf22c-1780-4ba6-b945-0abaabe5d460'] = $pane;
    $display->panels['right'][1] = 'new-b89bf22c-1780-4ba6-b945-0abaabe5d460';
    $pane = new stdClass();
    $pane->pid = 'new-0975ccc2-6831-45d1-aa1e-9ed0d02af6b2';
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
    $pane->uuid = '0975ccc2-6831-45d1-aa1e-9ed0d02af6b2';
    $display->content['new-0975ccc2-6831-45d1-aa1e-9ed0d02af6b2'] = $pane;
    $display->panels['right'][2] = 'new-0975ccc2-6831-45d1-aa1e-9ed0d02af6b2';
    $pane = new stdClass();
    $pane->pid = 'new-4070be6d-f4fd-45f7-a900-5f89ad3809da';
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
    $pane->uuid = '4070be6d-f4fd-45f7-a900-5f89ad3809da';
    $display->content['new-4070be6d-f4fd-45f7-a900-5f89ad3809da'] = $pane;
    $display->panels['right'][3] = 'new-4070be6d-f4fd-45f7-a900-5f89ad3809da';
    $pane = new stdClass();
    $pane->pid = 'new-4a891f31-e7ff-49f5-a768-6d310d2a9464';
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
    $pane->uuid = '4a891f31-e7ff-49f5-a768-6d310d2a9464';
    $display->content['new-4a891f31-e7ff-49f5-a768-6d310d2a9464'] = $pane;
    $display->panels['right'][4] = 'new-4a891f31-e7ff-49f5-a768-6d310d2a9464';
    $pane = new stdClass();
    $pane->pid = 'new-4929c3e0-8779-4831-bd23-34d9cd9eaa5a';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '4929c3e0-8779-4831-bd23-34d9cd9eaa5a';
    $display->content['new-4929c3e0-8779-4831-bd23-34d9cd9eaa5a'] = $pane;
    $display->panels['right'][5] = 'new-4929c3e0-8779-4831-bd23-34d9cd9eaa5a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['favorites_list'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'my_communities';
  $page->task = 'page';
  $page->admin_title = 'My communities';
  $page->admin_description = 'My communities user page';
  $page->path = 'user/%user/my-communities/subscribed';
  $page->access = array(
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
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'My communities',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'My communities',
      'name' => 'main-menu',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_my_communities_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'my_communities';
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
  $display->layout = 'ag-9-3';
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
  $display->uuid = 'ed2bf7d9-ec85-4bb9-a266-ce0c11a8af9c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ad1d68d2-3aa5-4b97-974e-690bd7c23243';
    $pane->panel = 'left';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'primary',
      'id' => 'tabs',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ad1d68d2-3aa5-4b97-974e-690bd7c23243';
    $display->content['new-ad1d68d2-3aa5-4b97-974e-690bd7c23243'] = $pane;
    $display->panels['left'][0] = 'new-ad1d68d2-3aa5-4b97-974e-690bd7c23243';
    $pane = new stdClass();
    $pane->pid = 'new-901b1551-8424-4beb-9757-3cd29cace69a';
    $pane->panel = 'left';
    $pane->type = 'create_community_link';
    $pane->subtype = 'create_community_link';
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
    $pane->uuid = '901b1551-8424-4beb-9757-3cd29cace69a';
    $display->content['new-901b1551-8424-4beb-9757-3cd29cace69a'] = $pane;
    $display->panels['left'][1] = 'new-901b1551-8424-4beb-9757-3cd29cace69a';
    $pane = new stdClass();
    $pane->pid = 'new-feccdb7a-b673-4597-a1f7-fbd7f1db2059';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_3';
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
    $pane->uuid = 'feccdb7a-b673-4597-a1f7-fbd7f1db2059';
    $display->content['new-feccdb7a-b673-4597-a1f7-fbd7f1db2059'] = $pane;
    $display->panels['left'][2] = 'new-feccdb7a-b673-4597-a1f7-fbd7f1db2059';
    $pane = new stdClass();
    $pane->pid = 'new-bcc20f30-18b9-4947-bd69-2746172f64cf';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_profile_users-user_activity_summary';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bcc20f30-18b9-4947-bd69-2746172f64cf';
    $display->content['new-bcc20f30-18b9-4947-bd69-2746172f64cf'] = $pane;
    $display->panels['right'][0] = 'new-bcc20f30-18b9-4947-bd69-2746172f64cf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-feccdb7a-b673-4597-a1f7-fbd7f1db2059';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['my_communities'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'my_pending_communities';
  $page->task = 'page';
  $page->admin_title = 'My pending communities';
  $page->admin_description = 'My communities user page';
  $page->path = 'user/%user/my-communities/pending';
  $page->access = array(
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
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Requests/Invitations',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => 'My communities',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_my_pending_communities_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'my_pending_communities';
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
  $display->layout = 'ag-9-3';
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
  $display->uuid = 'ed2bf7d9-ec85-4bb9-a266-ce0c11a8af9c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fd153bba-3618-4c4a-9e54-29c76881f4de';
    $pane->panel = 'left';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'primary',
      'id' => 'tabs',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fd153bba-3618-4c4a-9e54-29c76881f4de';
    $display->content['new-fd153bba-3618-4c4a-9e54-29c76881f4de'] = $pane;
    $display->panels['left'][0] = 'new-fd153bba-3618-4c4a-9e54-29c76881f4de';
    $pane = new stdClass();
    $pane->pid = 'new-48c0fa3f-8ec5-4539-8049-7f75048e9cd9';
    $pane->panel = 'left';
    $pane->type = 'create_community_link';
    $pane->subtype = 'create_community_link';
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
    $pane->uuid = '48c0fa3f-8ec5-4539-8049-7f75048e9cd9';
    $display->content['new-48c0fa3f-8ec5-4539-8049-7f75048e9cd9'] = $pane;
    $display->panels['left'][1] = 'new-48c0fa3f-8ec5-4539-8049-7f75048e9cd9';
    $pane = new stdClass();
    $pane->pid = 'new-6308540d-3f16-4b6d-9688-739c3d724e2c';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_4';
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
    $pane->uuid = '6308540d-3f16-4b6d-9688-739c3d724e2c';
    $display->content['new-6308540d-3f16-4b6d-9688-739c3d724e2c'] = $pane;
    $display->panels['left'][2] = 'new-6308540d-3f16-4b6d-9688-739c3d724e2c';
    $pane = new stdClass();
    $pane->pid = 'new-79a33c54-f59e-4ac1-abcd-9ba7a3f28db2';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_notifications-panel_pane_2';
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
    $pane->uuid = '79a33c54-f59e-4ac1-abcd-9ba7a3f28db2';
    $display->content['new-79a33c54-f59e-4ac1-abcd-9ba7a3f28db2'] = $pane;
    $display->panels['left'][3] = 'new-79a33c54-f59e-4ac1-abcd-9ba7a3f28db2';
    $pane = new stdClass();
    $pane->pid = 'new-17b5cfc7-63cf-4dff-8976-9815955dd82b';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_profile_users-user_activity_summary';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '17b5cfc7-63cf-4dff-8976-9815955dd82b';
    $display->content['new-17b5cfc7-63cf-4dff-8976-9815955dd82b'] = $pane;
    $display->panels['right'][0] = 'new-17b5cfc7-63cf-4dff-8976-9815955dd82b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['my_pending_communities'] = $page;

  return $pages;

}
