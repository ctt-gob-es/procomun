<?php
/**
 * @file
 * ag_section_questions_answers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ag_section_questions_answers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agrega2_answers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Agrega2 answers';
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
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_question_ref_target_id']['id'] = 'field_question_ref_target_id';
  $handler->display->display_options['relationships']['field_question_ref_target_id']['table'] = 'field_data_field_question_ref';
  $handler->display->display_options['relationships']['field_question_ref_target_id']['field'] = 'field_question_ref_target_id';
  $handler->display->display_options['relationships']['field_question_ref_target_id']['required'] = TRUE;
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
  /* Contextual filter: Content: Pregunta (field_question_ref) */
  $handler->display->display_options['arguments']['field_question_ref_target_id']['id'] = 'field_question_ref_target_id';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['table'] = 'field_data_field_question_ref';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['field'] = 'field_question_ref_target_id';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'answer' => 'answer',
  );

  /* Display: Answers list */
  $handler = $view->new_display('panel_pane', 'Answers list', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Lista de respuestas de una pregunta';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'answers-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Pregunta (field_question_ref) */
  $handler->display->display_options['arguments']['field_question_ref_target_id']['id'] = 'field_question_ref_target_id';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['table'] = 'field_data_field_question_ref';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['field'] = 'field_question_ref_target_id';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_question_ref_target_id']['summary_options']['items_per_page'] = '25';
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
    'answer' => 'answer',
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['argument_input'] = array(
    'field_question_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Contenido: Pregunta (field_question_ref)',
    ),
  );

  /* Display: User's answer os a spefic question */
  $handler = $view->new_display('block', 'User\'s answer os a spefic question', 'block_1');
  $handler->display->display_options['display_description'] = 'The user\'s answer of a specific question';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'answers-list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'activities';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['agrega2_answers'] = array(
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
    t('Content entity referenced from field_question_ref'),
    t('Todo(s)'),
    t('Answers list'),
    t('Lista de respuestas de una pregunta'),
    t('more'),
    t('Vista panel'),
    t('User\'s answer os a spefic question'),
    t('The user\'s answer of a specific question'),
  );
  $export['agrega2_answers'] = $view;

  $view = new view();
  $view->name = 'agrega2_debates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_search_labels_for_question_and_debate';
  $view->human_name = 'Agrega2 debates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« primera';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'siguiente ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'última »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'debates-list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_search_labels_for_question_and_debate';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_search_labels_for_question_and_debate';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Indexed Content: Comunidades en que se publicará */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_search_labels_for_question_and_debate';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['og_group_ref']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_search_labels_for_question_and_debate';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'debate' => 'debate',
    'question' => 'question',
  );

  /* Display: List content pane */
  $handler = $view->new_display('panel_pane', 'List content pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Lista de preguntas y debates de un grupo';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Content: Comunidades en que se publicará */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_search_labels_for_question_and_debate';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['og_group_ref']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['argument_input'] = array(
    'og_group_ref' => array(
      'type' => 'panel',
      'context' => 'entity:file.basename',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indexed Nodo: Groups audience',
    ),
  );
  $translatables['agrega2_debates'] = array(
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
    t('Node ID'),
    t('.'),
    t(','),
    t('Todo(s)'),
    t('List content pane'),
    t('Lista de preguntas y debates de un grupo'),
    t('more'),
    t('Vista panel'),
  );
  $export['agrega2_debates'] = $view;

  $view = new view();
  $view->name = 'agrega2_questions';
  $view->description = 'Agrega2 view for questions';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Agrega2 questions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest questions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'debates-list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'lasts';
  /* Relationship: OG membership: OG membership from Content */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'Suscripción de nodos de OG';
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
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
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
    'debate' => 'debate',
    'question' => 'question',
  );

  /* Display: Last questions */
  $handler = $view->new_display('panel_pane', 'Last questions', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Últimas preguntas panel contendor';
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'panel',
      'context' => 'entity:file.original',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Suscripción OG: Group ID',
    ),
  );
  $translatables['agrega2_questions'] = array(
    t('Master'),
    t('Latest questions'),
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
    t('Suscripción de nodos de OG'),
    t('Todo(s)'),
    t('Last questions'),
    t('Últimas preguntas panel contendor'),
    t('more'),
    t('Vista panel'),
  );
  $export['agrega2_questions'] = $view;

  return $export;
}
