<?php
/**
 * @file
 * ag_learning_itinerary.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ag_learning_itinerary_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit__panel_context_5cfec209-5551-43b8-9e50-b40f9c160bae';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Learning path',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'itinerary' => 'itinerary',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->uuid = '09b18dad-aea1-4632-8a27-a93662dff2c9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3dbb9828-8dbe-413a-94e4-a1c0c005647a';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'block-learning-path-node-form',
      'css_class' => 'block-panels-mini',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3dbb9828-8dbe-413a-94e4-a1c0c005647a';
    $display->content['new-3dbb9828-8dbe-413a-94e4-a1c0c005647a'] = $pane;
    $display->panels['middle'][0] = 'new-3dbb9828-8dbe-413a-94e4-a1c0c005647a';
    $pane = new stdClass();
    $pane->pid = 'new-4fac6d08-27e0-4e53-b68c-df74c55641c2';
    $pane->panel = 'middle';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4fac6d08-27e0-4e53-b68c-df74c55641c2';
    $display->content['new-4fac6d08-27e0-4e53-b68c-df74c55641c2'] = $pane;
    $display->panels['middle'][1] = 'new-4fac6d08-27e0-4e53-b68c-df74c55641c2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit__panel_context_5cfec209-5551-43b8-9e50-b40f9c160bae'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_2f6fb59b-e64d-427d-8794-cdd69cfedf53';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Itinerary variant',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'itinerary' => 'itinerary',
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
  $display->title = '';
  $display->uuid = 'e58cff3f-09c3-41dd-9807-e0db2b14d585';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-de7789d3-342b-4f37-9fa7-aa37d9f97625';
    $pane->panel = 'left';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->uuid = 'de7789d3-342b-4f37-9fa7-aa37d9f97625';
    $display->content['new-de7789d3-342b-4f37-9fa7-aa37d9f97625'] = $pane;
    $display->panels['left'][0] = 'new-de7789d3-342b-4f37-9fa7-aa37d9f97625';
    $pane = new stdClass();
    $pane->pid = 'new-a40e5811-3239-4c57-9386-5942b481d401';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'itinerary_content_detail-panel_pane_1';
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
    $pane->uuid = 'a40e5811-3239-4c57-9386-5942b481d401';
    $display->content['new-a40e5811-3239-4c57-9386-5942b481d401'] = $pane;
    $display->panels['left'][1] = 'new-a40e5811-3239-4c57-9386-5942b481d401';
    $pane = new stdClass();
    $pane->pid = 'new-4bf95205-8fa6-4631-b1f5-5bdc26485dc6';
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
    $pane->uuid = '4bf95205-8fa6-4631-b1f5-5bdc26485dc6';
    $display->content['new-4bf95205-8fa6-4631-b1f5-5bdc26485dc6'] = $pane;
    $display->panels['right'][0] = 'new-4bf95205-8fa6-4631-b1f5-5bdc26485dc6';
    $pane = new stdClass();
    $pane->pid = 'new-874117c6-2c28-4018-a483-e4a240692e71';
    $pane->panel = 'right';
    $pane->type = 'itinerary_base_detail';
    $pane->subtype = 'itinerary_base_detail';
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
    $pane->uuid = '874117c6-2c28-4018-a483-e4a240692e71';
    $display->content['new-874117c6-2c28-4018-a483-e4a240692e71'] = $pane;
    $display->panels['right'][1] = 'new-874117c6-2c28-4018-a483-e4a240692e71';
    $pane = new stdClass();
    $pane->pid = 'new-2cc8dcda-600d-4373-b1cf-a426506eb55e';
    $pane->panel = 'right';
    $pane->type = 'itinerary_related_content';
    $pane->subtype = 'itinerary_related_content';
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
    $pane->uuid = '2cc8dcda-600d-4373-b1cf-a426506eb55e';
    $display->content['new-2cc8dcda-600d-4373-b1cf-a426506eb55e'] = $pane;
    $display->panels['right'][2] = 'new-2cc8dcda-600d-4373-b1cf-a426506eb55e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-de7789d3-342b-4f37-9fa7-aa37d9f97625';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_2f6fb59b-e64d-427d-8794-cdd69cfedf53'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_learning_itinerary_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'learning_paths_timeline';
  $page->task = 'page';
  $page->admin_title = 'Learning paths timeline';
  $page->admin_description = 'List of learning paths of a given user';
  $page->path = 'user/%uid/learning-paths';
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
  $handler->name = 'page_learning_paths_timeline__panel_context_45672970-b15c-42cb-ae98-5615c6db45db';
  $handler->task = 'page';
  $handler->subtask = 'learning_paths_timeline';
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
    'name' => '',
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
    $pane->pid = 'new-1197f2a5-cdd9-4c2c-96c7-adeab507ada4';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-q4W8P1zoOs0cIStXVzV06438rV9Zo2G1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Área de conocimiento',
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
    $pane->uuid = '1197f2a5-cdd9-4c2c-96c7-adeab507ada4';
    $display->content['new-1197f2a5-cdd9-4c2c-96c7-adeab507ada4'] = $pane;
    $display->panels['left'][1] = 'new-1197f2a5-cdd9-4c2c-96c7-adeab507ada4';
    $pane = new stdClass();
    $pane->pid = 'new-9cd6a65e-e525-413b-81ca-a7f54fe4823c';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Gzar2smIOL8qvIWn6KInEEsuby1vegdG';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Contexto educativo',
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
    $pane->uuid = '9cd6a65e-e525-413b-81ca-a7f54fe4823c';
    $display->content['new-9cd6a65e-e525-413b-81ca-a7f54fe4823c'] = $pane;
    $display->panels['left'][2] = 'new-9cd6a65e-e525-413b-81ca-a7f54fe4823c';
    $pane = new stdClass();
    $pane->pid = 'new-058a739f-0e79-4342-a682-08baab5ce55b';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-PrW3ela4Y6QM5sRN0hPIzg6e4KlJB1iG';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Etiquetas',
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
    $pane->uuid = '058a739f-0e79-4342-a682-08baab5ce55b';
    $display->content['new-058a739f-0e79-4342-a682-08baab5ce55b'] = $pane;
    $display->panels['left'][3] = 'new-058a739f-0e79-4342-a682-08baab5ce55b';
    $pane = new stdClass();
    $pane->pid = 'new-ff98ef08-038a-4032-96ef-38d56e51da08';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_learning_paths-panel_pane_my_learning_paths';
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
    $pane->uuid = 'ff98ef08-038a-4032-96ef-38d56e51da08';
    $display->content['new-ff98ef08-038a-4032-96ef-38d56e51da08'] = $pane;
    $display->panels['middle'][0] = 'new-ff98ef08-038a-4032-96ef-38d56e51da08';
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
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['learning_paths_timeline'] = $page;

  return $pages;

}
