<?php
/**
 * @file
 * ag_section_content_type_learning_resource.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ag_section_content_type_learning_resource_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'LearningResource Variant',
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
              'recurso_de_aprendizaje' => 'recurso_de_aprendizaje',
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
  $display->uuid = '6bd21927-75bf-4a60-ac59-390c3d5bd43f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74ca01e7-172f-48bb-ae84-d1021876413b';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '74ca01e7-172f-48bb-ae84-d1021876413b';
    $display->content['new-74ca01e7-172f-48bb-ae84-d1021876413b'] = $pane;
    $display->panels['middle'][0] = 'new-74ca01e7-172f-48bb-ae84-d1021876413b';
    $pane = new stdClass();
    $pane->pid = 'new-683d6f45-ad18-4cbf-a594-58f8cbca21b1';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '683d6f45-ad18-4cbf-a594-58f8cbca21b1';
    $display->content['new-683d6f45-ad18-4cbf-a594-58f8cbca21b1'] = $pane;
    $display->panels['right'][0] = 'new-683d6f45-ad18-4cbf-a594-58f8cbca21b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-683d6f45-ad18-4cbf-a594-58f8cbca21b1';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}
