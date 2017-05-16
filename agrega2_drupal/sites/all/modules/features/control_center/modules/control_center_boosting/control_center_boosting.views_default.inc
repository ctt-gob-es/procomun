<?php
/**
 * @file
 * control_center_boosting.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function control_center_boosting_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solr_fields_boosting_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solr fields boosting list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_boosting_weight_editable' => 'field_boosting_weight_editable',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_boosting_weight_editable' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['save_messages'] = 'summary';
  $handler->display->display_options['style_options']['batch_size'] = '10';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no fields to config.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Field';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Boosting weight (editable) */
  $handler->display->display_options['fields']['field_boosting_weight_editable']['id'] = 'field_boosting_weight_editable';
  $handler->display->display_options['fields']['field_boosting_weight_editable']['table'] = 'field_data_field_boosting_weight';
  $handler->display->display_options['fields']['field_boosting_weight_editable']['field'] = 'field_boosting_weight_editable';
  $handler->display->display_options['fields']['field_boosting_weight_editable']['label'] = 'Boosting';
  $handler->display->display_options['fields']['field_boosting_weight_editable']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_boosting_weight_editable']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['field_boosting_weight_editable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_boosting_weight_editable']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_boosting_weight_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_boosting_weight_editable']['suppress_label'] = 1;
  $handler->display->display_options['fields']['field_boosting_weight_editable']['suppress_description'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solr_fields' => 'solr_fields',
  );

  /* Display: Panel de contenido */
  $handler = $view->new_display('panel_pane', 'Panel de contenido', 'panel_pane_1');
  $translatables['solr_fields_boosting_list'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('There is no fields to config.'),
    t('Field'),
    t('Descripción'),
    t('Boosting'),
    t(' '),
    t('Panel de contenido'),
    t('View panes'),
  );
  $export['solr_fields_boosting_list'] = $view;

  return $export;
}
