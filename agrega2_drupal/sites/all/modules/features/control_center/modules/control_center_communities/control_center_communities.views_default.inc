<?php
/**
 * @file
 * control_center_communities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function control_center_communities_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'agrega2_communities_user_administration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Agrega2 communities user administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access control center organizations';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
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
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nothing' => 'nothing',
    'name' => 'name',
    'mail' => 'mail',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Esta comunidad actualmente no tiene ningún usuario suscrito.';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'datos_personales' => 'datos_personales',
  );
  /* Relationship: Profile: Nombre y Apellidos (field_name_surname) */
  $handler->display->display_options['relationships']['field_name_surname_value']['id'] = 'field_name_surname_value';
  $handler->display->display_options['relationships']['field_name_surname_value']['table'] = 'field_data_field_name_surname';
  $handler->display->display_options['relationships']['field_name_surname_value']['field'] = 'field_name_surname_value';
  $handler->display->display_options['relationships']['field_name_surname_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_name_surname_value']['delta'] = '-1';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::control_center_communities_remove_user_from_community' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Name and surname';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field collection item: Nombre (field_profile_name) */
  $handler->display->display_options['filters']['field_profile_name_value']['id'] = 'field_profile_name_value';
  $handler->display->display_options['filters']['field_profile_name_value']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['filters']['field_profile_name_value']['field'] = 'field_profile_name_value';
  $handler->display->display_options['filters']['field_profile_name_value']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['filters']['field_profile_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_profile_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_name_value']['expose']['operator_id'] = 'field_profile_name_value_op';
  $handler->display->display_options['filters']['field_profile_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_profile_name_value']['expose']['operator'] = 'field_profile_name_value_op';
  $handler->display->display_options['filters']['field_profile_name_value']['expose']['identifier'] = 'field_profile_name_value';
  $handler->display->display_options['filters']['field_profile_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field collection item: Apellidos (field_profile_surname) */
  $handler->display->display_options['filters']['field_profile_surname_value']['id'] = 'field_profile_surname_value';
  $handler->display->display_options['filters']['field_profile_surname_value']['table'] = 'field_data_field_profile_surname';
  $handler->display->display_options['filters']['field_profile_surname_value']['field'] = 'field_profile_surname_value';
  $handler->display->display_options['filters']['field_profile_surname_value']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['filters']['field_profile_surname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_profile_surname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_surname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_surname_value']['expose']['operator_id'] = 'field_profile_surname_value_op';
  $handler->display->display_options['filters']['field_profile_surname_value']['expose']['label'] = 'Surname';
  $handler->display->display_options['filters']['field_profile_surname_value']['expose']['operator'] = 'field_profile_surname_value_op';
  $handler->display->display_options['filters']['field_profile_surname_value']['expose']['identifier'] = 'field_profile_surname_value';
  $handler->display->display_options['filters']['field_profile_surname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Agrega2 communities user administration */
  $handler = $view->new_display('panel_pane', 'Agrega2 communities user administration', 'panel_pane_1');
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
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['agrega2_communities_user_administration'] = array(
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
    t('Esta comunidad actualmente no tiene ningún usuario suscrito.'),
    t('Profile'),
    t('field collection item from field_name_surname'),
    t('- Choose an operation -'),
    t('Name and surname'),
    t('E-mail'),
    t('Todo(s)'),
    t('Name'),
    t('Surname'),
    t('Agrega2 communities user administration'),
    t('more'),
    t('View panes'),
  );
  $export['agrega2_communities_user_administration'] = $view;

  return $export;
}
