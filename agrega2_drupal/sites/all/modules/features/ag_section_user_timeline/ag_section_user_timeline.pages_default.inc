<?php
/**
 * @file
 * ag_section_user_timeline.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_user_timeline_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_timeline_page';
  $page->task = 'page';
  $page->admin_title = 'User timeline page';
  $page->admin_description = '';
  $page->path = 'user/%user/timeline';
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
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
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
  $handler->name = 'page_user_timeline_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_timeline_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User time line',
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
  $display->title = '%user:name timeline';
  $display->uuid = 'e32145a1-07b8-457b-89d6-6faa6599250e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-82249b70-9b16-42c7-b3e2-42851d901d69';
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
    $pane->uuid = '82249b70-9b16-42c7-b3e2-42851d901d69';
    $display->content['new-82249b70-9b16-42c7-b3e2-42851d901d69'] = $pane;
    $display->panels['left'][0] = 'new-82249b70-9b16-42c7-b3e2-42851d901d69';
    $pane = new stdClass();
    $pane->pid = 'new-66527431-a719-40f5-a7f9-e7594ab6fc1b';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-0qBawcdHdw5lxXW1Ftu5cG0T8ttfbVIz';
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
    $pane->uuid = '66527431-a719-40f5-a7f9-e7594ab6fc1b';
    $display->content['new-66527431-a719-40f5-a7f9-e7594ab6fc1b'] = $pane;
    $display->panels['left'][1] = 'new-66527431-a719-40f5-a7f9-e7594ab6fc1b';
    $pane = new stdClass();
    $pane->pid = 'new-614bd93b-7acd-4d9f-813b-1fff4010897b';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-BFqFiYk32LgPIP2413dJQwlJbO3zGDe3';
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
    $pane->uuid = '614bd93b-7acd-4d9f-813b-1fff4010897b';
    $display->content['new-614bd93b-7acd-4d9f-813b-1fff4010897b'] = $pane;
    $display->panels['left'][2] = 'new-614bd93b-7acd-4d9f-813b-1fff4010897b';
    $pane = new stdClass();
    $pane->pid = 'new-4e6f6bb6-c730-4374-a2bf-2b7efc421776';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-2sTYAM0NnkOVfaS6Fc8OFLMSwK0bztCx';
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
    $pane->uuid = '4e6f6bb6-c730-4374-a2bf-2b7efc421776';
    $display->content['new-4e6f6bb6-c730-4374-a2bf-2b7efc421776'] = $pane;
    $display->panels['left'][3] = 'new-4e6f6bb6-c730-4374-a2bf-2b7efc421776';
    $pane = new stdClass();
    $pane->pid = 'new-590dfacb-a9df-47d3-b17b-bd90ee2536ce';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-ppJuXXTGUxyqdEBtVF7g6XOSOmXL7h7q';
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
    $pane->uuid = '590dfacb-a9df-47d3-b17b-bd90ee2536ce';
    $display->content['new-590dfacb-a9df-47d3-b17b-bd90ee2536ce'] = $pane;
    $display->panels['left'][4] = 'new-590dfacb-a9df-47d3-b17b-bd90ee2536ce';
    $pane = new stdClass();
    $pane->pid = 'new-b5a0c5e3-0216-4c0f-a741-db7b666a13b9';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_user_timeline-wellcome_new_procomun';
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
    $pane->uuid = 'b5a0c5e3-0216-4c0f-a741-db7b666a13b9';
    $display->content['new-b5a0c5e3-0216-4c0f-a741-db7b666a13b9'] = $pane;
    $display->panels['middle'][0] = 'new-b5a0c5e3-0216-4c0f-a741-db7b666a13b9';
    $pane = new stdClass();
    $pane->pid = 'new-702138ea-efc5-4f0e-8c89-dc3e37326b70';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_user_timeline-create_new_content_block';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '702138ea-efc5-4f0e-8c89-dc3e37326b70';
    $display->content['new-702138ea-efc5-4f0e-8c89-dc3e37326b70'] = $pane;
    $display->panels['middle'][1] = 'new-702138ea-efc5-4f0e-8c89-dc3e37326b70';
    $pane = new stdClass();
    $pane->pid = 'new-a9174797-194e-468a-a427-05f555a8374a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_timeline-panel_pane_1';
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
    $pane->uuid = 'a9174797-194e-468a-a427-05f555a8374a';
    $display->content['new-a9174797-194e-468a-a427-05f555a8374a'] = $pane;
    $display->panels['middle'][2] = 'new-a9174797-194e-468a-a427-05f555a8374a';
    $pane = new stdClass();
    $pane->pid = 'new-35f09e5a-3947-4190-a98c-81575affc3e3';
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
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '35f09e5a-3947-4190-a98c-81575affc3e3';
    $display->content['new-35f09e5a-3947-4190-a98c-81575affc3e3'] = $pane;
    $display->panels['right'][0] = 'new-35f09e5a-3947-4190-a98c-81575affc3e3';
    $pane = new stdClass();
    $pane->pid = 'new-8b80ffeb-8c94-4342-ac1d-b29dde5a6758';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => '0',
      'settings' => array(),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8b80ffeb-8c94-4342-ac1d-b29dde5a6758';
    $display->content['new-8b80ffeb-8c94-4342-ac1d-b29dde5a6758'] = $pane;
    $display->panels['right'][1] = 'new-8b80ffeb-8c94-4342-ac1d-b29dde5a6758';
    $pane = new stdClass();
    $pane->pid = 'new-c9ff9885-0463-40dc-8c8c-da7df5cf81a2';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '1800',
        'granularity' => 'none',
      ),
    );
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
    $pane->uuid = 'c9ff9885-0463-40dc-8c8c-da7df5cf81a2';
    $display->content['new-c9ff9885-0463-40dc-8c8c-da7df5cf81a2'] = $pane;
    $display->panels['right'][2] = 'new-c9ff9885-0463-40dc-8c8c-da7df5cf81a2';
    $pane = new stdClass();
    $pane->pid = 'new-be4f3b23-4a75-4e34-8c85-152f5eadd3d5';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '1800',
        'granularity' => 'none',
      ),
    );
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
    $pane->uuid = 'be4f3b23-4a75-4e34-8c85-152f5eadd3d5';
    $display->content['new-be4f3b23-4a75-4e34-8c85-152f5eadd3d5'] = $pane;
    $display->panels['right'][3] = 'new-be4f3b23-4a75-4e34-8c85-152f5eadd3d5';
    $pane = new stdClass();
    $pane->pid = 'new-c9f8b688-6be6-41d1-87f8-8e61d0bb2cde';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '1800',
        'granularity' => 'none',
      ),
    );
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
    $pane->uuid = 'c9f8b688-6be6-41d1-87f8-8e61d0bb2cde';
    $display->content['new-c9f8b688-6be6-41d1-87f8-8e61d0bb2cde'] = $pane;
    $display->panels['right'][4] = 'new-c9f8b688-6be6-41d1-87f8-8e61d0bb2cde';
    $pane = new stdClass();
    $pane->pid = 'new-da32fda5-ecb7-45cb-8873-efc9e55304a3';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'da32fda5-ecb7-45cb-8873-efc9e55304a3';
    $display->content['new-da32fda5-ecb7-45cb-8873-efc9e55304a3'] = $pane;
    $display->panels['right'][5] = 'new-da32fda5-ecb7-45cb-8873-efc9e55304a3';
    $pane = new stdClass();
    $pane->pid = 'new-78967fb1-2d0f-44db-bd5d-32bd223e07fa';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '78967fb1-2d0f-44db-bd5d-32bd223e07fa';
    $display->content['new-78967fb1-2d0f-44db-bd5d-32bd223e07fa'] = $pane;
    $display->panels['right'][6] = 'new-78967fb1-2d0f-44db-bd5d-32bd223e07fa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a9174797-194e-468a-a427-05f555a8374a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_timeline_page'] = $page;

  return $pages;

}
