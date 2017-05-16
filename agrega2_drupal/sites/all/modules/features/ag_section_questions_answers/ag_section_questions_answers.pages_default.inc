<?php
/**
 * @file
 * ag_section_questions_answers.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ag_section_questions_answers_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Question variant',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'question',
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
              'question' => 'question',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
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
  $display->uuid = '6e7cebc7-c6f9-419a-8c51-adf4c88ac795';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-330d4db9-e10d-4178-8725-a57b9f556581';
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
    $pane->uuid = '330d4db9-e10d-4178-8725-a57b9f556581';
    $display->content['new-330d4db9-e10d-4178-8725-a57b9f556581'] = $pane;
    $display->panels['left'][0] = 'new-330d4db9-e10d-4178-8725-a57b9f556581';
    $pane = new stdClass();
    $pane->pid = 'new-cd7c15ec-dc6b-464c-8961-812f87b302a9';
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
    $pane->uuid = 'cd7c15ec-dc6b-464c-8961-812f87b302a9';
    $display->content['new-cd7c15ec-dc6b-464c-8961-812f87b302a9'] = $pane;
    $display->panels['right'][0] = 'new-cd7c15ec-dc6b-464c-8961-812f87b302a9';
    $pane = new stdClass();
    $pane->pid = 'new-7655fd02-cec7-466f-bd45-c8697063d009';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7655fd02-cec7-466f-bd45-c8697063d009';
    $display->content['new-7655fd02-cec7-466f-bd45-c8697063d009'] = $pane;
    $display->panels['right'][1] = 'new-7655fd02-cec7-466f-bd45-c8697063d009';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Debate variant',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'debate',
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
              'debate' => 'debate',
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
  $display->uuid = '417e7b62-ccfb-4500-9bcc-844d9c822626';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bca6eb9f-f5a7-4a1a-b629-5a3c200d53ee';
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
    $pane->uuid = 'bca6eb9f-f5a7-4a1a-b629-5a3c200d53ee';
    $display->content['new-bca6eb9f-f5a7-4a1a-b629-5a3c200d53ee'] = $pane;
    $display->panels['left'][0] = 'new-bca6eb9f-f5a7-4a1a-b629-5a3c200d53ee';
    $pane = new stdClass();
    $pane->pid = 'new-615742be-7ed9-46c7-8506-0f56764c9b89';
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
    $pane->uuid = '615742be-7ed9-46c7-8506-0f56764c9b89';
    $display->content['new-615742be-7ed9-46c7-8506-0f56764c9b89'] = $pane;
    $display->panels['right'][0] = 'new-615742be-7ed9-46c7-8506-0f56764c9b89';
    $pane = new stdClass();
    $pane->pid = 'new-3912c0a8-cf25-459c-841f-b92dfb12dcee';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3912c0a8-cf25-459c-841f-b92dfb12dcee';
    $display->content['new-3912c0a8-cf25-459c-841f-b92dfb12dcee'] = $pane;
    $display->panels['right'][1] = 'new-3912c0a8-cf25-459c-841f-b92dfb12dcee';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Question anonymous variant',
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
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'question' => 'question',
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
  $display->uuid = '8e9937c3-1cfb-446c-bf00-27bb2d0ce538';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ef6d105a-b530-41b8-8869-531e1ab4e94c';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '%node:title-field',
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
    $pane->uuid = 'ef6d105a-b530-41b8-8869-531e1ab4e94c';
    $display->content['new-ef6d105a-b530-41b8-8869-531e1ab4e94c'] = $pane;
    $display->panels['middle'][0] = 'new-ef6d105a-b530-41b8-8869-531e1ab4e94c';
    $pane = new stdClass();
    $pane->pid = 'new-04812b51-b611-4cab-b6e4-54cb433388f6';
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
    $pane->uuid = '04812b51-b611-4cab-b6e4-54cb433388f6';
    $display->content['new-04812b51-b611-4cab-b6e4-54cb433388f6'] = $pane;
    $display->panels['right'][0] = 'new-04812b51-b611-4cab-b6e4-54cb433388f6';
    $pane = new stdClass();
    $pane->pid = 'new-8cf02b6d-79e3-4cc9-a982-40d3379ca738';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8cf02b6d-79e3-4cc9-a982-40d3379ca738';
    $display->content['new-8cf02b6d-79e3-4cc9-a982-40d3379ca738'] = $pane;
    $display->panels['right'][1] = 'new-8cf02b6d-79e3-4cc9-a982-40d3379ca738';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  return $export;
}
