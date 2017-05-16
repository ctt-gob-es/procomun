<?php
/**
 * @file
 * control_center_certifications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function control_center_certifications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agrega2_content_certification';
  $view->description = 'Set of displays for managing content at control center';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Agrega2 content certification';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No se han encontrado resultados.';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No se han encontrado resultados.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'banner' => 'banner',
    'simplenews' => 'simplenews',
    'social_network' => 'social_network',
    'page' => 'page',
    'ode' => 'ode',
    'recurso_de_aprendizaje' => 'recurso_de_aprendizaje',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Publicado';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'post' => 'post',
    'debate' => 'debate',
    'poll' => 'poll',
    'event' => 'event',
    'question' => 'question',
    'answer' => 'answer',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Tipo';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'contenttype';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Título (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Título';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Nombre';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Control center certifications pane old */
  $handler = $view->new_display('panel_pane', 'Control center certifications pane old', 'panel_pane_certifications_list_old');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Administer certifications';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'flagged' => 'flagged',
    'comment_count' => 'comment_count',
    'value' => 'value',
    'nid' => 'nid',
    'field_certified' => 'field_certified',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'flagged' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_certified' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Flags: like */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'marca';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'like';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Resultados de votos';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'count',
  );
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Media de resultados de votos';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'average',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::control_center_certifications_certify_odes' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::control_center_certifications_remove_certification' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['flagged']['label'] = 'Likes';
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['separator'] = '';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Votes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['label'] = 'Average';
  $handler->display->display_options['fields']['value_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  $handler->display->display_options['fields']['value_1']['separator'] = '';
  /* Field: Node count: Node id */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'nodeviewcount';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Visits';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: Content: Certificado */
  $handler->display->display_options['fields']['field_certified']['id'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['table'] = 'field_data_field_certified';
  $handler->display->display_options['fields']['field_certified']['field'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['label'] = 'Certified';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flagged */
  $handler->display->display_options['sorts']['flagged']['id'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['table'] = 'flagging';
  $handler->display->display_options['sorts']['flagged']['field'] = 'flagged';
  $handler->display->display_options['sorts']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['flagged']['group_type'] = 'count_distinct';
  $handler->display->display_options['sorts']['flagged']['order'] = 'DESC';
  $handler->display->display_options['sorts']['flagged']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['flagged']['expose']['label'] = 'Likes';
  /* Sort criterion: Content: Comment count */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  $handler->display->display_options['sorts']['comment_count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['comment_count']['expose']['label'] = 'Comments';
  /* Sort criterion: Vote results: Value */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['value']['expose']['label'] = 'Votes';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;
  /* Sort criterion: Node count: Node id */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'nodeviewcount';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['sorts']['nid']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['nid']['expose']['label'] = 'Visits';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'ode' => 'ode',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Título (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Certificado (field_certified) */
  $handler->display->display_options['filters']['field_certified_value']['id'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['table'] = 'field_data_field_certified';
  $handler->display->display_options['filters']['field_certified_value']['field'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['group'] = 1;
  $handler->display->display_options['filters']['field_certified_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator_id'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['label'] = 'Certified';
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['identifier'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Custom: Certification criterion */
  $handler->display->display_options['filters']['certification_criterion']['id'] = 'certification_criterion';
  $handler->display->display_options['filters']['certification_criterion']['table'] = 'node';
  $handler->display->display_options['filters']['certification_criterion']['field'] = 'certification_criterion';
  $handler->display->display_options['filters']['certification_criterion']['value'] = array(
    'certification_criterion' => '0',
  );
  $handler->display->display_options['filters']['certification_criterion']['group'] = 1;
  $handler->display->display_options['filters']['certification_criterion']['exposed'] = TRUE;
  $handler->display->display_options['filters']['certification_criterion']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['certification_criterion']['expose']['label'] = 'Certification criterion';
  $handler->display->display_options['filters']['certification_criterion']['expose']['operator'] = 'certification_criterion_op';
  $handler->display->display_options['filters']['certification_criterion']['expose']['identifier'] = 'certification_criterion';
  $handler->display->display_options['filters']['certification_criterion']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Certification by likes pane */
  $handler = $view->new_display('panel_pane', 'Certification by likes pane', 'panel_pane_certification_likes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Flags: like */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'like';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['flagged']['label'] = 'Like';
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['separator'] = '';
  /* Field: Content: Certificado */
  $handler->display->display_options['fields']['field_certified']['id'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['table'] = 'field_data_field_certified';
  $handler->display->display_options['fields']['field_certified']['field'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['label'] = 'Certified';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ode' => 'ode',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Título (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Certificado (field_certified) */
  $handler->display->display_options['filters']['field_certified_value']['id'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['table'] = 'field_data_field_certified';
  $handler->display->display_options['filters']['field_certified_value']['field'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['group'] = 1;
  $handler->display->display_options['filters']['field_certified_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator_id'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['label'] = 'Certified';
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['identifier'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['group_type'] = 'count';
  $handler->display->display_options['filters']['flagged']['operator'] = '>=';
  $handler->display->display_options['filters']['flagged']['value']['min'] = '1';
  $handler->display->display_options['filters']['flagged']['value']['max'] = '1';
  $handler->display->display_options['filters']['flagged']['value']['value'] = '[ode_number_likes]';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Marcado';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Certification by comments pane */
  $handler = $view->new_display('panel_pane', 'Certification by comments pane', 'panel_pane_certification_comments');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Comments';
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['separator'] = '';
  /* Field: Content: Certificado */
  $handler->display->display_options['fields']['field_certified']['id'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['table'] = 'field_data_field_certified';
  $handler->display->display_options['fields']['field_certified']['field'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['label'] = 'Certified';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ode' => 'ode',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Título (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Certificado (field_certified) */
  $handler->display->display_options['filters']['field_certified_value']['id'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['table'] = 'field_data_field_certified';
  $handler->display->display_options['filters']['field_certified_value']['field'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['group'] = 1;
  $handler->display->display_options['filters']['field_certified_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator_id'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['label'] = 'Certified';
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['identifier'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Comment count */
  $handler->display->display_options['filters']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['filters']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['operator'] = '>=';
  $handler->display->display_options['filters']['comment_count']['value']['value'] = '[ode_number_comments]';
  $handler->display->display_options['filters']['comment_count']['group'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Certification by votings pane */
  $handler = $view->new_display('panel_pane', 'Certification by votings pane', 'panel_pane_certification_votings');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Resultados de votos';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'count',
  );
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'Media de resultados de votos';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'average',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
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
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Votes';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  /* Field: Content: Certificado */
  $handler->display->display_options['fields']['field_certified']['id'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['table'] = 'field_data_field_certified';
  $handler->display->display_options['fields']['field_certified']['field'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['label'] = 'Certified';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ode' => 'ode',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
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
  /* Filter criterion: Content: Certificado (field_certified) */
  $handler->display->display_options['filters']['field_certified_value']['id'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['table'] = 'field_data_field_certified';
  $handler->display->display_options['filters']['field_certified_value']['field'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['group'] = 1;
  $handler->display->display_options['filters']['field_certified_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator_id'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['label'] = 'Certified';
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['identifier'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Vote results: Value */
  $handler->display->display_options['filters']['value']['id'] = 'value';
  $handler->display->display_options['filters']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['filters']['value']['field'] = 'value';
  $handler->display->display_options['filters']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['filters']['value']['operator'] = '>=';
  $handler->display->display_options['filters']['value']['value']['value'] = '[ode_number_votes]';
  $handler->display->display_options['filters']['value']['group'] = 1;
  /* Filter criterion: Vote results: Value */
  $handler->display->display_options['filters']['value_1']['id'] = 'value_1';
  $handler->display->display_options['filters']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['filters']['value_1']['field'] = 'value';
  $handler->display->display_options['filters']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['filters']['value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['value_1']['value']['value'] = '[ode_average]';
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Administer certifications pane */
  $handler = $view->new_display('panel_pane', 'Administer certifications pane', 'panel_pane_certifications_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Administer certifications';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'flagged' => 'flagged',
    'comment_count' => 'comment_count',
    'value' => 'value',
    'value_1' => 'value_1',
    'nid' => 'nid',
    'field_certified' => 'field_certified',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
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
    'flagged' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_certified' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::control_center_certifications_certify_odes' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::control_center_certifications_remove_certification' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Field: solrID */
  $handler->display->display_options['fields']['field_solrid_5']['id'] = 'field_solrid_5';
  $handler->display->display_options['fields']['field_solrid_5']['table'] = 'field_data_field_solrid';
  $handler->display->display_options['fields']['field_solrid_5']['field'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid_5']['label'] = '';
  $handler->display->display_options['fields']['field_solrid_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_solrid_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solrid_5']['type'] = 'field_hidden_text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Título';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'ode/view/[field_solrid_5]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: solrID */
  $handler->display->display_options['fields']['field_solrid']['id'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid']['table'] = 'field_data_field_solrid';
  $handler->display->display_options['fields']['field_solrid']['field'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid']['label'] = 'Likes';
  $handler->display->display_options['fields']['field_solrid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solrid']['type'] = 'field_hidden_text_plain';
  /* Field: Field: solrID */
  $handler->display->display_options['fields']['field_solrid_1']['id'] = 'field_solrid_1';
  $handler->display->display_options['fields']['field_solrid_1']['table'] = 'field_data_field_solrid';
  $handler->display->display_options['fields']['field_solrid_1']['field'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid_1']['label'] = 'Comments';
  $handler->display->display_options['fields']['field_solrid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solrid_1']['type'] = 'field_hidden_text_plain';
  /* Field: Field: solrID */
  $handler->display->display_options['fields']['field_solrid_2']['id'] = 'field_solrid_2';
  $handler->display->display_options['fields']['field_solrid_2']['table'] = 'field_data_field_solrid';
  $handler->display->display_options['fields']['field_solrid_2']['field'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid_2']['label'] = 'Votes';
  $handler->display->display_options['fields']['field_solrid_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solrid_2']['type'] = 'field_hidden_text_plain';
  /* Field: Field: solrID */
  $handler->display->display_options['fields']['field_solrid_3']['id'] = 'field_solrid_3';
  $handler->display->display_options['fields']['field_solrid_3']['table'] = 'field_data_field_solrid';
  $handler->display->display_options['fields']['field_solrid_3']['field'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid_3']['label'] = 'Average';
  $handler->display->display_options['fields']['field_solrid_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solrid_3']['type'] = 'field_hidden_text_plain';
  /* Field: Field: solrID */
  $handler->display->display_options['fields']['field_solrid_4']['id'] = 'field_solrid_4';
  $handler->display->display_options['fields']['field_solrid_4']['table'] = 'field_data_field_solrid';
  $handler->display->display_options['fields']['field_solrid_4']['field'] = 'field_solrid';
  $handler->display->display_options['fields']['field_solrid_4']['label'] = 'Visits';
  $handler->display->display_options['fields']['field_solrid_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solrid_4']['type'] = 'field_hidden_text_plain';
  /* Field: Content: Certificado */
  $handler->display->display_options['fields']['field_certified']['id'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['table'] = 'field_data_field_certified';
  $handler->display->display_options['fields']['field_certified']['field'] = 'field_certified';
  $handler->display->display_options['fields']['field_certified']['label'] = 'Certified';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Custom: - Any - */
  $handler->display->display_options['sorts']['sort_by_any']['id'] = 'sort_by_any';
  $handler->display->display_options['sorts']['sort_by_any']['table'] = 'node';
  $handler->display->display_options['sorts']['sort_by_any']['field'] = 'sort_by_any';
  $handler->display->display_options['sorts']['sort_by_any']['order'] = 'DESC';
  $handler->display->display_options['sorts']['sort_by_any']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['sort_by_any']['expose']['label'] = '- Any -';
  /* Sort criterion: Custom: Likes */
  $handler->display->display_options['sorts']['sort_by_likes']['id'] = 'sort_by_likes';
  $handler->display->display_options['sorts']['sort_by_likes']['table'] = 'node';
  $handler->display->display_options['sorts']['sort_by_likes']['field'] = 'sort_by_likes';
  $handler->display->display_options['sorts']['sort_by_likes']['order'] = 'DESC';
  $handler->display->display_options['sorts']['sort_by_likes']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['sort_by_likes']['expose']['label'] = 'Likes';
  /* Sort criterion: Custom: Comments */
  $handler->display->display_options['sorts']['sort_by_comments']['id'] = 'sort_by_comments';
  $handler->display->display_options['sorts']['sort_by_comments']['table'] = 'node';
  $handler->display->display_options['sorts']['sort_by_comments']['field'] = 'sort_by_comments';
  $handler->display->display_options['sorts']['sort_by_comments']['order'] = 'DESC';
  $handler->display->display_options['sorts']['sort_by_comments']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['sort_by_comments']['expose']['label'] = 'Comments';
  /* Sort criterion: Custom: Votes */
  $handler->display->display_options['sorts']['sort_by_votes']['id'] = 'sort_by_votes';
  $handler->display->display_options['sorts']['sort_by_votes']['table'] = 'node';
  $handler->display->display_options['sorts']['sort_by_votes']['field'] = 'sort_by_votes';
  $handler->display->display_options['sorts']['sort_by_votes']['order'] = 'DESC';
  $handler->display->display_options['sorts']['sort_by_votes']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['sort_by_votes']['expose']['label'] = 'Votes';
  /* Sort criterion: Custom: Visits */
  $handler->display->display_options['sorts']['sort_by_visits']['id'] = 'sort_by_visits';
  $handler->display->display_options['sorts']['sort_by_visits']['table'] = 'node';
  $handler->display->display_options['sorts']['sort_by_visits']['field'] = 'sort_by_visits';
  $handler->display->display_options['sorts']['sort_by_visits']['order'] = 'DESC';
  $handler->display->display_options['sorts']['sort_by_visits']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['sort_by_visits']['expose']['label'] = 'Visits';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'ode' => 'ode',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Título (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Certificado (field_certified) */
  $handler->display->display_options['filters']['field_certified_value']['id'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['table'] = 'field_data_field_certified';
  $handler->display->display_options['filters']['field_certified_value']['field'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['group'] = 1;
  $handler->display->display_options['filters']['field_certified_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator_id'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['label'] = 'Certified';
  $handler->display->display_options['filters']['field_certified_value']['expose']['operator'] = 'field_certified_value_op';
  $handler->display->display_options['filters']['field_certified_value']['expose']['identifier'] = 'field_certified_value';
  $handler->display->display_options['filters']['field_certified_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Custom: Certification criterion */
  $handler->display->display_options['filters']['certification_criterion']['id'] = 'certification_criterion';
  $handler->display->display_options['filters']['certification_criterion']['table'] = 'node';
  $handler->display->display_options['filters']['certification_criterion']['field'] = 'certification_criterion';
  $handler->display->display_options['filters']['certification_criterion']['value'] = array(
    'certification_criterion' => '0',
  );
  $handler->display->display_options['filters']['certification_criterion']['exposed'] = TRUE;
  $handler->display->display_options['filters']['certification_criterion']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['certification_criterion']['expose']['label'] = 'Criterios de certificación';
  $handler->display->display_options['filters']['certification_criterion']['expose']['operator'] = 'certification_criterion_op';
  $handler->display->display_options['filters']['certification_criterion']['expose']['identifier'] = 'certification_criterion';
  $handler->display->display_options['filters']['certification_criterion']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['agrega2_content_certification'] = array(
    t('Master'),
    t('Content list'),
    t('más'),
    t('Aplicar'),
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
    t('No se han encontrado resultados.'),
    t('author'),
    t('Autor'),
    t('- Choose an operation -'),
    t('Title'),
    t('Type'),
    t('Published'),
    t('Publicado'),
    t('Tipo'),
    t('Título'),
    t('Nombre'),
    t('Control center certifications pane old'),
    t('Administer certifications'),
    t('more'),
    t('Ordenar por'),
    t('marca'),
    t('Resultados de votos'),
    t('Media de resultados de votos'),
    t('Likes'),
    t('Comments'),
    t('.'),
    t('Votes'),
    t('Average'),
    t('Visits'),
    t('Certified'),
    t('Certification criterion'),
    t('Vista panel'),
    t('Certification by likes pane'),
    t('flag'),
    t('Like'),
    t('Marcado'),
    t('Certification by comments pane'),
    t('Certification by votings pane'),
    t('Administer certifications pane'),
    t('- All -'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('- Any -'),
    t('Criterios de certificación'),
  );
  $export['agrega2_content_certification'] = $view;

  return $export;
}
