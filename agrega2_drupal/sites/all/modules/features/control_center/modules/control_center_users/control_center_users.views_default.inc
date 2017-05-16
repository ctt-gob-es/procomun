<?php
/**
 * @file
 * control_center_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function control_center_users_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'control_center_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Control center users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access control center organizations';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Order by';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_profile_name' => 'field_profile_name',
    'field_profile_surname' => 'field_profile_surname',
    'view_user' => 'view_user',
    'edit_node' => 'edit_node',
    'cancel_node' => 'cancel_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'field_profile_surname';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_surname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cancel_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'datos_personales' => 'datos_personales',
  );
  /* Relationship: Profile: Nombre y Apellidos (field_name_surname) */
  $handler->display->display_options['relationships']['field_name_surname_value']['id'] = 'field_name_surname_value';
  $handler->display->display_options['relationships']['field_name_surname_value']['table'] = 'field_data_field_name_surname';
  $handler->display->display_options['relationships']['field_name_surname_value']['field'] = 'field_name_surname_value';
  $handler->display->display_options['relationships']['field_name_surname_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_name_surname_value']['delta'] = '-1';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Usuario';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Field collection item: Apellidos */
  $handler->display->display_options['fields']['field_profile_surname']['id'] = 'field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['table'] = 'field_data_field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['field'] = 'field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['fields']['field_profile_surname']['label'] = 'Surname';
  $handler->display->display_options['fields']['field_profile_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_surname']['type'] = 'text_plain';
  /* Field: Field collection item: Nombre */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['fields']['field_profile_name']['type'] = 'text_plain';
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[view_user] [edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operaciones';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_user] [edit_node] [cancel_node]';
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
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Sort criterion: Field collection item: Apellidos (field_profile_surname) */
  $handler->display->display_options['sorts']['field_profile_surname_value']['id'] = 'field_profile_surname_value';
  $handler->display->display_options['sorts']['field_profile_surname_value']['table'] = 'field_data_field_profile_surname';
  $handler->display->display_options['sorts']['field_profile_surname_value']['field'] = 'field_profile_surname_value';
  $handler->display->display_options['sorts']['field_profile_surname_value']['relationship'] = 'field_name_surname_value';
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
  $handler->display->display_options['filters']['field_profile_name_value']['operator'] = 'word';
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
  $handler->display->display_options['filters']['field_profile_surname_value']['operator'] = 'word';
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
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Control center users list Content pane */
  $handler = $view->new_display('panel_pane', 'Control center users list Content pane', 'panel_pane_1');
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
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::ag_general_unblock_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Field collection item: Apellidos */
  $handler->display->display_options['fields']['field_profile_surname']['id'] = 'field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['table'] = 'field_data_field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['field'] = 'field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['fields']['field_profile_surname']['label'] = 'Surname';
  $handler->display->display_options['fields']['field_profile_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_surname']['type'] = 'text_plain';
  /* Field: Field collection item: Nombre */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['fields']['field_profile_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_profile_name']['type'] = 'text_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Activo';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[view_user] [edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [cancel_node]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Field collection item: Nombre (field_profile_name) */
  $handler->display->display_options['filters']['field_profile_name_value']['id'] = 'field_profile_name_value';
  $handler->display->display_options['filters']['field_profile_name_value']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['filters']['field_profile_name_value']['field'] = 'field_profile_name_value';
  $handler->display->display_options['filters']['field_profile_name_value']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['filters']['field_profile_name_value']['operator'] = 'word';
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
  $handler->display->display_options['filters']['field_profile_surname_value']['operator'] = 'word';
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
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Organizations list */
  $handler = $view->new_display('panel_pane', 'Organizations list', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Organizations list';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'datos_organizacion' => 'datos_organizacion',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Profile: Nombre */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Name';
  /* Field: Field: Descripción */
  $handler->display->display_options['fields']['field_descripci_n']['id'] = 'field_descripci_n';
  $handler->display->display_options['fields']['field_descripci_n']['table'] = 'field_data_field_descripci_n';
  $handler->display->display_options['fields']['field_descripci_n']['field'] = 'field_descripci_n';
  $handler->display->display_options['fields']['field_descripci_n']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_descripci_n']['label'] = 'Description';
  $handler->display->display_options['fields']['field_descripci_n']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_descripci_n']['alter']['max_length'] = '280';
  $handler->display->display_options['fields']['field_descripci_n']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_descripci_n']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_descripci_n']['alter']['html'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[view_user] [edit_node]';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: User: Cancel link */
  $handler->display->display_options['fields']['cancel_node']['id'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['table'] = 'users';
  $handler->display->display_options['fields']['cancel_node']['field'] = 'cancel_node';
  $handler->display->display_options['fields']['cancel_node']['label'] = '';
  $handler->display->display_options['fields']['cancel_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['cancel_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [cancel_node]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: Profile: Nombre (field_organization_name) */
  $handler->display->display_options['filters']['field_organization_name_value']['id'] = 'field_organization_name_value';
  $handler->display->display_options['filters']['field_organization_name_value']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['filters']['field_organization_name_value']['field'] = 'field_organization_name_value';
  $handler->display->display_options['filters']['field_organization_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_organization_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_organization_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_name_value']['expose']['operator_id'] = 'field_organization_name_value_op';
  $handler->display->display_options['filters']['field_organization_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_organization_name_value']['expose']['operator'] = 'field_organization_name_value_op';
  $handler->display->display_options['filters']['field_organization_name_value']['expose']['identifier'] = 'field_organization_name_value';
  $handler->display->display_options['filters']['field_organization_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: User list export */
  $handler = $view->new_display('views_data_export', 'User list export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'procomun-listado-usuarios.%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Apellidos */
  $handler->display->display_options['fields']['field_profile_surname']['id'] = 'field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['table'] = 'field_data_field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['field'] = 'field_profile_surname';
  $handler->display->display_options['fields']['field_profile_surname']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['fields']['field_profile_surname']['label'] = 'Surname';
  $handler->display->display_options['fields']['field_profile_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_surname']['type'] = 'text_plain';
  /* Field: Field collection item: Nombre */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'field_name_surname_value';
  $handler->display->display_options['fields']['field_profile_name']['type'] = 'text_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Usuario';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['path'] = 'control-center/users/list/export';
  $handler->display->display_options['displays'] = array(
    'panel_pane_1' => 'panel_pane_1',
    'default' => 0,
    'panel_pane_2' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/control-center/users';
  $handler->display->display_options['segment_size'] = '50';

  /* Display: Organization list export */
  $handler = $view->new_display('views_data_export', 'Organization list export', 'views_data_export_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Organization administer list export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'procomun-listado-organizaciones.%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'datos_organizacion' => 'datos_organizacion',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Nombre */
  $handler->display->display_options['fields']['field_organization_name']['id'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['table'] = 'field_data_field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['field'] = 'field_organization_name';
  $handler->display->display_options['fields']['field_organization_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_organization_name']['label'] = 'Organization name';
  /* Field: Field: Descripción */
  $handler->display->display_options['fields']['field_descripci_n']['id'] = 'field_descripci_n';
  $handler->display->display_options['fields']['field_descripci_n']['table'] = 'field_data_field_descripci_n';
  $handler->display->display_options['fields']['field_descripci_n']['field'] = 'field_descripci_n';
  $handler->display->display_options['fields']['field_descripci_n']['relationship'] = 'profile';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/control-center/users/organizations/export';
  $handler->display->display_options['displays'] = array(
    'panel_pane_2' => 'panel_pane_2',
    'default' => 0,
    'panel_pane_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/control-center/users/organizations';
  $handler->display->display_options['segment_size'] = '50';
  $translatables['control_center_users'] = array(
    t('Master'),
    t('User list'),
    t('más'),
    t('Apply'),
    t('Reiniciar'),
    t('Order by'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- All -'),
    t('Desplazamiento'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Profile'),
    t('field collection item from field_name_surname'),
    t('Usuario'),
    t('Surname'),
    t('Nombre'),
    t('[view_user] [edit_node]'),
    t('Operaciones'),
    t('[view_user] [edit_node] [cancel_node]'),
    t('- Choose an operation -'),
    t('Name'),
    t('Control center users list Content pane'),
    t('more'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('User'),
    t('Activo'),
    t('Operations'),
    t('[edit_node] [cancel_node]'),
    t('Vista panel'),
    t('Organizations list'),
    t('Description'),
    t('User list export'),
    t('Organization list export'),
    t('Organization administer list export'),
    t('Organization name'),
    t('Descripción'),
  );
  $export['control_center_users'] = $view;

  return $export;
}
