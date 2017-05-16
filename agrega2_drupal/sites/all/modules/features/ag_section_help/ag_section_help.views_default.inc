<?php
/**
 * @file
 * ag_section_help.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ag_section_help_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faq';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Faq';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Frecuently asked questions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'vote',
    'function' => '',
  );
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['suffix'] = ' Responses';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span>[title]</span><span>[comment_count]</span>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Most recent';
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['group_type'] = 'count_distinct';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Best rated';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;
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
    'faq' => 'faq',
  );

  /* Display: FAQ list */
  $handler = $view->new_display('panel_pane', 'FAQ list', 'panel_pane_faq_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are not questions at this moment.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['suffix'] = ' Responses';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Most recent';
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  $handler->display->display_options['sorts']['comment_count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['comment_count']['expose']['label'] = 'Most responded';
  /* Sort criterion: Node count: Node id */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'nodeviewcount';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['sorts']['nid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['nid']['expose']['label'] = 'Most visited';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'faq' => 'faq',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'help_nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';

  /* Display: Answers list */
  $handler = $view->new_display('panel_pane', 'Answers list', 'panel_pane_faq_answers_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Answers';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty answers';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no answers to this question';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Comment: Comments of the node */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'node';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Comment: Author */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'cid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Comment: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'cid';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-m-Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Custom: Vote widget custom field */
  $handler->display->display_options['fields']['vote_widget_custom_field']['id'] = 'vote_widget_custom_field';
  $handler->display->display_options['fields']['vote_widget_custom_field']['table'] = 'custom';
  $handler->display->display_options['fields']['vote_widget_custom_field']['field'] = 'vote_widget_custom_field';
  $handler->display->display_options['fields']['vote_widget_custom_field']['label'] = '';
  $handler->display->display_options['fields']['vote_widget_custom_field']['element_label_colon'] = FALSE;
  /* Field: Comment: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['relationship'] = 'cid';
  $handler->display->display_options['fields']['comment_body']['label'] = '';
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'comment';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'cid';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Unpublished FAQ list */
  $handler = $view->new_display('panel_pane', 'Unpublished FAQ list', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '2';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'uid' => 'uid',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No new pending FAQ to moderate';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = 'Open content in a new tab';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Most recent';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faq' => 'faq',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $translatables['faq'] = array(
    t('Master'),
    t('Frecuently asked questions'),
    t('más'),
    t('Apply'),
    t('Reiniciar'),
    t('Order by'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Vote results'),
    t('.'),
    t(','),
    t(' Responses'),
    t('<span>[title]</span><span>[comment_count]</span>'),
    t('Most recent'),
    t('Best rated'),
    t('FAQ list'),
    t('more'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('There are not questions at this moment.'),
    t('Most responded'),
    t('Most visited'),
    t('Vista panel'),
    t('Answers list'),
    t('Answers'),
    t('Empty answers'),
    t('There are no answers to this question'),
    t('Comments'),
    t('All'),
    t('View panes'),
    t('Unpublished FAQ list'),
    t('No new pending FAQ to moderate'),
    t('author'),
    t('Content'),
    t('- Choose an operation -'),
    t('User'),
    t('Title'),
    t('Open content in a new tab'),
  );
  $export['faq'] = $view;

  $view = new view();
  $view->name = 'help_landing_rankings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Help Landing rankings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Most rated';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<span class="help-icon-[type]"></span>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'faq' => 'faq',
    'functionality' => 'functionality',
    'manual' => 'manual',
  );

  /* Display: Most viewed */
  $handler = $view->new_display('panel_pane', 'Most viewed', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most viewed';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ranking-most-viewed';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<span class="help-icon-[type]"></span>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = 'Clean type';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type_1']['machine_name'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'help/[type_1]?help_nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Node count: Node id */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'nodeviewcount';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';

  /* Display: Most rated */
  $handler = $view->new_display('panel_pane', 'Most rated', 'panel_pane_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ranking-most-rated';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['required'] = TRUE;
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'vote',
    'function' => '',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<span class="help-icon-[type]"></span>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = 'Clean type';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['machine_name'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'help/[type_1]?help_nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;

  /* Display: Most recent */
  $handler = $view->new_display('panel_pane', 'Most recent', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Most recent';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ranking-most-recent';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<span class="help-icon-[type]"></span>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = 'Clean type';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['type_1']['alter']['path'] = 'help/[type_1]?help_nid=[nid]';
  $handler->display->display_options['fields']['type_1']['machine_name'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'help/[type_1]?help_nid=[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $translatables['help_landing_rankings'] = array(
    t('Master'),
    t('Most rated'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No results'),
    t('<span class="help-icon-[type]"></span>'),
    t('Most viewed'),
    t('Clean type'),
    t('View panes'),
    t('Vote results'),
    t('.'),
    t(','),
    t('Most recent'),
  );
  $export['help_landing_rankings'] = $view;

  $view = new view();
  $view->name = 'help_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Help Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Displaying results @start to @end of @total';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="help-icon-[type]"></span>[title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['label'] = 'Clean type';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type_1']['machine_name'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'More details';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'help/[type_1]?help_nid=[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'faq' => 'faq',
    'functionality' => 'functionality',
    'manual' => 'manual',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search into help';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'help_value';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );

  /* Display: Search list */
  $handler = $view->new_display('panel_pane', 'Search list', 'panel_pane_1');
  $handler->display->display_options['link_url'] = 'help/search';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['help_search'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying results @start to @end of @total'),
    t('No results found'),
    t('<span class="help-icon-[type]"></span>[title]'),
    t('Clean type'),
    t('More details'),
    t('Search into help'),
    t('Search list'),
    t('View panes'),
  );
  $export['help_search'] = $view;

  $view = new view();
  $view->name = 'manual_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manual content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manual';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'term_node_tid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'vote',
    'function' => '',
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'término';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'manual_index' => 'manual_index',
    'accesibilidad' => 0,
    'agrupaci_n' => 0,
    'arbol_curricular' => 0,
    'knowledgearea' => 0,
    'asignatura' => 0,
    'categories' => 0,
    'centros_educativos' => 0,
    'competencia' => 0,
    'learningcontext' => 0,
    'destinatario' => 0,
    'tags' => 0,
    'licencia' => 0,
    'lugar_de_utilizaci_n' => 0,
    'modalidad_de_uso' => 0,
    'nivel_educativo' => 0,
    'palabras_clave' => 0,
    'proceso_cognitivo' => 0,
    'recurso_de_aprendizaje' => 0,
    'recurso_educativo' => 0,
    'rol_contribuidor' => 0,
    'tipo_de_licencia' => 0,
    'tipo_de_recurso' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[custom:manual_index][title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'accesibilidad' => 0,
    'agrupaci_n' => 0,
    'arbol_curricular' => 0,
    'knowledgearea' => 0,
    'asignatura' => 0,
    'categories' => 0,
    'centros_educativos' => 0,
    'competencia' => 0,
    'learningcontext' => 0,
    'destinatario' => 0,
    'tags' => 0,
    'manual_index' => 0,
    'licencia' => 0,
    'lugar_de_utilizaci_n' => 0,
    'modalidad_de_uso' => 0,
    'nivel_educativo' => 0,
    'palabras_clave' => 0,
    'proceso_cognitivo' => 0,
    'recurso_de_aprendizaje' => 0,
    'recurso_educativo' => 0,
    'rol_contribuidor' => 0,
    'tipo_de_licencia' => 0,
    'tipo_de_recurso' => 0,
  );
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'term_node_tid';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'manual_index:panel_pane_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    'manual' => 'manual',
  );

  /* Display: Manual content */
  $handler = $view->new_display('panel_pane', 'Manual content', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Manual content PDF */
  $handler = $view->new_display('panel_pane', 'Manual content PDF', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'término';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'manual_index' => 'manual_index',
    'accesibilidad' => 0,
    'agrupaci_n' => 0,
    'arbol_curricular' => 0,
    'knowledgearea' => 0,
    'asignatura' => 0,
    'categories' => 0,
    'centros_educativos' => 0,
    'competencia' => 0,
    'learningcontext' => 0,
    'destinatario' => 0,
    'tags' => 0,
    'licencia' => 0,
    'lugar_de_utilizaci_n' => 0,
    'modalidad_de_uso' => 0,
    'nivel_educativo' => 0,
    'palabras_clave' => 0,
    'proceso_cognitivo' => 0,
    'recurso_de_aprendizaje' => 0,
    'recurso_educativo' => 0,
    'rol_contribuidor' => 0,
    'tipo_de_licencia' => 0,
    'tipo_de_recurso' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[custom:manual_index][title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'accesibilidad' => 0,
    'agrupaci_n' => 0,
    'arbol_curricular' => 0,
    'knowledgearea' => 0,
    'asignatura' => 0,
    'categories' => 0,
    'centros_educativos' => 0,
    'competencia' => 0,
    'learningcontext' => 0,
    'destinatario' => 0,
    'tags' => 0,
    'manual_index' => 0,
    'licencia' => 0,
    'lugar_de_utilizaci_n' => 0,
    'modalidad_de_uso' => 0,
    'nivel_educativo' => 0,
    'palabras_clave' => 0,
    'proceso_cognitivo' => 0,
    'recurso_de_aprendizaje' => 0,
    'recurso_educativo' => 0,
    'rol_contribuidor' => 0,
    'tipo_de_licencia' => 0,
    'tipo_de_recurso' => 0,
  );
  $translatables['manual_content'] = array(
    t('Master'),
    t('Manual'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Vote results'),
    t('término'),
    t('[custom:manual_index][title]'),
    t('Edit'),
    t('.'),
    t(','),
    t('Manual content'),
    t('View panes'),
    t('Manual content PDF'),
  );
  $export['manual_content'] = $view;

  $view = new view();
  $view->name = 'manual_index';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manual index';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Index';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'term_node_tid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'draggableviews' => 'draggableviews',
    'title' => 'title',
    'term_node_tid' => 'term_node_tid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'term_node_tid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'término';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'manual_index' => 'manual_index',
    'accesibilidad' => 0,
    'agrupaci_n' => 0,
    'arbol_curricular' => 0,
    'knowledgearea' => 0,
    'asignatura' => 0,
    'categories' => 0,
    'centros_educativos' => 0,
    'competencia' => 0,
    'learningcontext' => 0,
    'destinatario' => 0,
    'tags' => 0,
    'licencia' => 0,
    'lugar_de_utilizaci_n' => 0,
    'modalidad_de_uso' => 0,
    'nivel_educativo' => 0,
    'palabras_clave' => 0,
    'proceso_cognitivo' => 0,
    'recurso_de_aprendizaje' => 0,
    'recurso_educativo' => 0,
    'rol_contribuidor' => 0,
    'tipo_de_licencia' => 0,
    'tipo_de_recurso' => 0,
  );
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = '';
  $handler->display->display_options['fields']['term_node_tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'accesibilidad' => 0,
    'agrupaci_n' => 0,
    'arbol_curricular' => 0,
    'knowledgearea' => 0,
    'asignatura' => 0,
    'categories' => 0,
    'centros_educativos' => 0,
    'competencia' => 0,
    'learningcontext' => 0,
    'destinatario' => 0,
    'tags' => 0,
    'manual_index' => 0,
    'licencia' => 0,
    'lugar_de_utilizaci_n' => 0,
    'modalidad_de_uso' => 0,
    'nivel_educativo' => 0,
    'palabras_clave' => 0,
    'proceso_cognitivo' => 0,
    'recurso_de_aprendizaje' => 0,
    'recurso_educativo' => 0,
    'rol_contribuidor' => 0,
    'tipo_de_licencia' => 0,
    'tipo_de_recurso' => 0,
  );
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_view'] = 'manual_index:panel_pane_1';
  $handler->display->display_options['sorts']['weight_1']['draggableviews_setting_new_items_bottom_list'] = 1;
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
    'manual' => 'manual',
  );

  /* Display: Manual index */
  $handler = $view->new_display('panel_pane', 'Manual index', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['manual_index'] = array(
    t('Master'),
    t('Index'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('término'),
    t('Manual index'),
    t('View panes'),
  );
  $export['manual_index'] = $view;

  $view = new view();
  $view->name = 'new_functionalities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'New functionalities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'New functionalities';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are not new functionalities at this moment.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'option',
    'tag' => 'vote',
    'function' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Descripción */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Most recent';
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Best rated';
  /* Sort criterion: COUNT(Node count: Node id) */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'nodeviewcount';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['sorts']['nid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['nid']['expose']['label'] = 'Most visited';
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
    'functionality' => 'functionality',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'help_nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: New functionalities list */
  $handler = $view->new_display('panel_pane', 'New functionalities list', 'panel_pane_new_functionalities_list');
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $translatables['new_functionalities'] = array(
    t('Master'),
    t('New functionalities'),
    t('más'),
    t('Apply'),
    t('Reiniciar'),
    t('Order by'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('There are not new functionalities at this moment.'),
    t('Vote results'),
    t('.'),
    t(','),
    t('Most recent'),
    t('Best rated'),
    t('Most visited'),
    t('New functionalities list'),
    t('more'),
    t('Vista panel'),
  );
  $export['new_functionalities'] = $view;

  return $export;
}
