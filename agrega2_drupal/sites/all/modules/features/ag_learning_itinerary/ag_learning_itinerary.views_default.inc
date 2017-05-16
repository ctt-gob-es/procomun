<?php
/**
 * @file
 * ag_learning_itinerary.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ag_learning_itinerary_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'itinerary_content_detail';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Itinerary content detail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'field_itinerary_content_target_id';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty itinerary content';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'This itinerary doesn\'t have attached content.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_itinerary_content_target_id']['id'] = 'field_itinerary_content_target_id';
  $handler->display->display_options['relationships']['field_itinerary_content_target_id']['table'] = 'field_data_field_itinerary_content';
  $handler->display->display_options['relationships']['field_itinerary_content_target_id']['field'] = 'field_itinerary_content_target_id';
  $handler->display->display_options['relationships']['field_itinerary_content_target_id']['label'] = 'Contenido entidad referenciada de field_itinerary_content';
  $handler->display->display_options['relationships']['field_itinerary_content_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_itinerary_content_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'access denied';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: List learning path content */
  $handler = $view->new_display('panel_pane', 'List learning path content', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:file.original',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Contenido: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['itinerary_content_detail'] = array(
    t('Master'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('« primera'),
    t('‹ anterior'),
    t('siguiente ›'),
    t('última »'),
    t('Empty itinerary content'),
    t('This itinerary doesn\'t have attached content.'),
    t('Contenido entidad referenciada de field_itinerary_content'),
    t('Todo(s)'),
    t('List learning path content'),
    t('more'),
    t('Vista panel'),
  );
  $export['itinerary_content_detail'] = $view;

  $view = new view();
  $view->name = 'learning_path_content';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Learning path content';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Generar contenidos del boletín';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'newsletter';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No hay contenido con estos filtros';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Relationship: Flags: learning_path_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'learning_path_content';
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = 'All';
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Marcado';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['required'] = TRUE;
  /* Filter criterion: Content: Título (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
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
    'ode' => 'ode',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Tipo';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'content-type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'post' => 'post',
    'debate' => 'debate',
    'poll' => 'poll',
    'event' => 'event',
    'question' => 'question',
    'ode' => 'ode',
  );

  /* Display: Learning path content */
  $handler = $view->new_display('block', 'Learning path content', 'learning_path_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Add content to the learning path';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1133';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no content with this filters.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: learning_path_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'marca_content';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'learning_path_content';
  /* Relationship: Flags: learning_path_interest_content */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'marca_interest_content';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'learning_path_interest_content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Default image */
  $handler->display->display_options['fields']['default_image']['id'] = 'default_image';
  $handler->display->display_options['fields']['default_image']['table'] = 'node';
  $handler->display->display_options['fields']['default_image']['field'] = 'default_image';
  $handler->display->display_options['fields']['default_image']['label'] = '';
  $handler->display->display_options['fields']['default_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['default_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['default_image']['empty_zero'] = TRUE;
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'post' => 'post',
    'external_content' => 'external_content',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'webinar' => 'webinar',
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'post' => 'post',
    'external_content' => 'external_content',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'webinar' => 'webinar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'content-type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Área de conocimiento (field_knowledge_area) */
  $handler->display->display_options['filters']['field_knowledge_area_tid']['id'] = 'field_knowledge_area_tid';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['table'] = 'field_data_field_knowledge_area';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['field'] = 'field_knowledge_area_tid';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['value'] = '';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_knowledge_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['operator_id'] = 'field_knowledge_area_tid_op';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['label'] = 'Knowledge area';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['operator'] = 'field_knowledge_area_tid_op';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['identifier'] = 'field_knowledge_area_tid';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_knowledge_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_knowledge_area_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['vocabulary'] = 'knowledgearea';
  /* Filter criterion: Content: Contexto educativo (field_learning_context) */
  $handler->display->display_options['filters']['field_learning_context_tid']['id'] = 'field_learning_context_tid';
  $handler->display->display_options['filters']['field_learning_context_tid']['table'] = 'field_data_field_learning_context';
  $handler->display->display_options['filters']['field_learning_context_tid']['field'] = 'field_learning_context_tid';
  $handler->display->display_options['filters']['field_learning_context_tid']['value'] = '';
  $handler->display->display_options['filters']['field_learning_context_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_learning_context_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['operator_id'] = 'field_learning_context_tid_op';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['label'] = 'Learning context';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['operator'] = 'field_learning_context_tid_op';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['identifier'] = 'field_learning_context_tid';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_learning_context_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_learning_context_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_learning_context_tid']['vocabulary'] = 'learningcontext';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Marcado';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['required'] = TRUE;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged_1']['id'] = 'flagged_1';
  $handler->display->display_options['filters']['flagged_1']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged_1']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['filters']['flagged_1']['value'] = '0';
  $handler->display->display_options['use_ajax_flags'] = array(
    'learning_path_content' => 'learning_path_content',
    'learning_path_interest_content' => 'learning_path_interest_content',
    'follow_user' => 0,
    'favorite' => 0,
    'like' => 0,
    'og_newsletter' => 0,
    'abuse_comment' => 0,
    'abuse_node' => 0,
    'abuse_user' => 0,
    'abuse_whitelist_comment' => 0,
    'abuse_whitelist_node' => 0,
    'abuse_whitelist_user' => 0,
  );
  $handler->display->display_options['use_ajax_flags_noscrolltop'] = 1;
  $handler->display->display_options['use_ajax_flags_widget'] = 'throbber';
  $handler->display->display_options['block_description'] = 'Learning path content';

  /* Display: Learning path content selected */
  $handler = $view->new_display('block', 'Learning path content selected', 'learning_path_content_selected');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content added to the learning path';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'draggableviews' => 'draggableviews',
    'title_field' => 'title_field',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'It has not yet added content';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: learning_path_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'marca_content';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'learning_path_content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save sort';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'post' => 'post',
    'external_content' => 'external_content',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'webinar' => 'webinar',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = 'All';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Marcado';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['required'] = TRUE;
  $handler->display->display_options['use_ajax_flags'] = array(
    'learning_path_content' => 'learning_path_content',
    'follow_user' => 0,
    'favorite' => 0,
    'like' => 0,
    'og_newsletter' => 0,
    'learning_path_interest_content' => 0,
    'abuse_comment' => 0,
    'abuse_node' => 0,
    'abuse_user' => 0,
    'abuse_whitelist_comment' => 0,
    'abuse_whitelist_node' => 0,
    'abuse_whitelist_user' => 0,
  );
  $handler->display->display_options['use_ajax_flags_widget'] = 'throbber';
  $handler->display->display_options['block_description'] = 'Learning path content selected';

  /* Display: Learning path interest content */
  $handler = $view->new_display('block', 'Learning path interest content', 'learning_path_interest_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Add interest content';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1122';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There is no content with this filters.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: learning_path_interest_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'marca_interest_content';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'learning_path_interest_content';
  /* Relationship: Flags: learning_path_content */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'marca_content';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'learning_path_content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Default image */
  $handler->display->display_options['fields']['default_image']['id'] = 'default_image';
  $handler->display->display_options['fields']['default_image']['table'] = 'node';
  $handler->display->display_options['fields']['default_image']['field'] = 'default_image';
  $handler->display->display_options['fields']['default_image']['label'] = '';
  $handler->display->display_options['fields']['default_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['default_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['default_image']['empty_zero'] = TRUE;
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'post' => 'post',
    'external_content' => 'external_content',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'webinar' => 'webinar',
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'post' => 'post',
    'external_content' => 'external_content',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'webinar' => 'webinar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'content-type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Área de conocimiento (field_knowledge_area) */
  $handler->display->display_options['filters']['field_knowledge_area_tid']['id'] = 'field_knowledge_area_tid';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['table'] = 'field_data_field_knowledge_area';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['field'] = 'field_knowledge_area_tid';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['value'] = '';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_knowledge_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['operator_id'] = 'field_knowledge_area_tid_op';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['label'] = 'Knowledge area';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['operator'] = 'field_knowledge_area_tid_op';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['identifier'] = 'field_knowledge_area_tid';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_knowledge_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_knowledge_area_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_knowledge_area_tid']['vocabulary'] = 'knowledgearea';
  /* Filter criterion: Content: Contexto educativo (field_learning_context) */
  $handler->display->display_options['filters']['field_learning_context_tid']['id'] = 'field_learning_context_tid';
  $handler->display->display_options['filters']['field_learning_context_tid']['table'] = 'field_data_field_learning_context';
  $handler->display->display_options['filters']['field_learning_context_tid']['field'] = 'field_learning_context_tid';
  $handler->display->display_options['filters']['field_learning_context_tid']['value'] = '';
  $handler->display->display_options['filters']['field_learning_context_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_learning_context_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['operator_id'] = 'field_learning_context_tid_op';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['label'] = 'Learning context';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['operator'] = 'field_learning_context_tid_op';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['identifier'] = 'field_learning_context_tid';
  $handler->display->display_options['filters']['field_learning_context_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_learning_context_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_learning_context_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_learning_context_tid']['vocabulary'] = 'learningcontext';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Marcado';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['required'] = TRUE;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged_1']['id'] = 'flagged_1';
  $handler->display->display_options['filters']['flagged_1']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged_1']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['filters']['flagged_1']['value'] = '0';
  $handler->display->display_options['use_ajax_flags'] = array(
    'learning_path_content' => 'learning_path_content',
    'learning_path_interest_content' => 'learning_path_interest_content',
    'follow_user' => 0,
    'favorite' => 0,
    'like' => 0,
    'og_newsletter' => 0,
    'abuse_comment' => 0,
    'abuse_node' => 0,
    'abuse_user' => 0,
    'abuse_whitelist_comment' => 0,
    'abuse_whitelist_node' => 0,
    'abuse_whitelist_user' => 0,
  );
  $handler->display->display_options['use_ajax_flags_noscrolltop'] = 1;
  $handler->display->display_options['use_ajax_flags_widget'] = 'throbber';
  $handler->display->display_options['block_description'] = 'Learning path interest content';

  /* Display: Learning path interest content selected */
  $handler = $view->new_display('block', 'Learning path interest content selected', 'learning_path_interest_content_selected');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Content added to the learning path';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'It has not yet added content';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: learning_path_interest_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'marca_interest_content';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'learning_path_interest_content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save sort';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Content: Título */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'post' => 'post',
    'external_content' => 'external_content',
    'itinerary' => 'itinerary',
    'podcast' => 'podcast',
    'ode' => 'ode',
    'webinar' => 'webinar',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = 'All';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['filters']['flagged']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Marcado';
  $handler->display->display_options['filters']['flagged']['expose']['operator'] = 'flagged_op';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['expose']['required'] = TRUE;
  $handler->display->display_options['use_ajax_flags'] = array(
    'learning_path_interest_content' => 'learning_path_interest_content',
    'follow_user' => 0,
    'favorite' => 0,
    'like' => 0,
    'og_newsletter' => 0,
    'learning_path_content' => 0,
    'abuse_comment' => 0,
    'abuse_node' => 0,
    'abuse_user' => 0,
    'abuse_whitelist_comment' => 0,
    'abuse_whitelist_node' => 0,
    'abuse_whitelist_user' => 0,
  );
  $handler->display->display_options['use_ajax_flags_widget'] = 'throbber';
  $handler->display->display_options['block_description'] = 'Learning path interest content selected';
  $translatables['learning_path_content'] = array(
    t('Defaults'),
    t('Generar contenidos del boletín'),
    t('más'),
    t('Aplicar'),
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
    t('No hay contenido con estos filtros'),
    t('flag'),
    t('Marcado'),
    t('Título'),
    t('Tipo'),
    t('Learning path content'),
    t('Add content to the learning path'),
    t('more'),
    t('Search'),
    t('Ordenar por'),
    t('There is no content with this filters.'),
    t('marca_content'),
    t('marca_interest_content'),
    t('Title'),
    t('Type'),
    t('Knowledge area'),
    t('Learning context'),
    t('Learning path content selected'),
    t('Content added to the learning path'),
    t('It has not yet added content'),
    t('Learning path interest content'),
    t('Add interest content'),
    t('Learning path interest content selected'),
  );
  $export['learning_path_content'] = $view;

  $view = new view();
  $view->name = 'my_learning_paths';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_my_learning_paths';
  $view->human_name = 'My learning paths';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My learning paths';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You do not have any learning path yet.';
  $handler->display->display_options['empty']['area']['format'] = 'rich_text';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_my_learning_paths';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_my_learning_paths';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Author */
  $handler->display->display_options['filters']['author']['id'] = 'author';
  $handler->display->display_options['filters']['author']['table'] = 'search_api_index_my_learning_paths';
  $handler->display->display_options['filters']['author']['field'] = 'author';
  $handler->display->display_options['filters']['author']['value'] = array(
    0 => '1',
  );
  $handler->display->display_options['filters']['author']['group'] = 1;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_my_learning_paths';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'itinerary' => 'itinerary',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: My learning paths content pane */
  $handler = $view->new_display('panel_pane', 'My learning paths content pane', 'panel_pane_my_learning_paths');
  $translatables['my_learning_paths'] = array(
    t('Master'),
    t('My learning paths'),
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
    t('You do not have any learning path yet.'),
    t('Node ID'),
    t('.'),
    t(','),
    t('My learning paths content pane'),
    t('View panes'),
  );
  $export['my_learning_paths'] = $view;

  return $export;
}
