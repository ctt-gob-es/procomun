<?php
/**
 * @file
 * ag_section_notifications.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ag_section_notifications_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_notifications';
  $view->description = 'Show all existing messages.';
  $view->tag = 'Message';
  $view->base_table = 'message';
  $view->human_name = 'User notifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Mis notificaciones';
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
  $handler->display->display_options['pager']['type'] = 'load_more';
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No hay mensajes creados todavía.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Sello temporal';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = 'Texto';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Message: target_users (field_target_users) */
  $handler->display->display_options['arguments']['field_target_users_target_id']['id'] = 'field_target_users_target_id';
  $handler->display->display_options['arguments']['field_target_users_target_id']['table'] = 'field_data_field_target_users';
  $handler->display->display_options['arguments']['field_target_users_target_id']['field'] = 'field_target_users_target_id';
  $handler->display->display_options['arguments']['field_target_users_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_target_users_target_id']['exception']['title'] = 'Todo(s)';
  $handler->display->display_options['arguments']['field_target_users_target_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_target_users_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_target_users_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_target_users_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'new_invitation_pending' => 'new_invitation_pending',
  );

  /* Display: Panel de contenido */
  $handler = $view->new_display('panel_pane', 'Panel de contenido', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mis notificaciones';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No hay mensajes creados todavía.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'new_invitation_pending' => 'new_invitation_pending',
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['argument_input'] = array(
    'field_target_users_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:file.original',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Mensaje: target_users (field_target_users)',
    ),
  );

  /* Display: Notifications-invitations */
  $handler = $view->new_display('panel_pane', 'Notifications-invitations', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My invitations';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'You do not have invitations.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'new_invitation_pending' => 'new_invitation_pending',
  );
  /* Filter criterion: Message: message_status (field_message_status) */
  $handler->display->display_options['filters']['field_message_status_value']['id'] = 'field_message_status_value';
  $handler->display->display_options['filters']['field_message_status_value']['table'] = 'field_data_field_message_status';
  $handler->display->display_options['filters']['field_message_status_value']['field'] = 'field_message_status_value';
  $handler->display->display_options['filters']['field_message_status_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_message_status_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_category']['name'] = 'Vista panel';
  $handler->display->display_options['argument_input'] = array(
    'field_target_users_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:file.original',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Mensaje: target_users (field_target_users)',
    ),
  );
  $translatables['user_notifications'] = array(
    t('Defaults'),
    t('Mis notificaciones'),
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
    t('No hay mensajes creados todavía.'),
    t('Sello temporal'),
    t('Texto'),
    t('Todo(s)'),
    t('Panel de contenido'),
    t('more'),
    t('Vista panel'),
    t('Notifications-invitations'),
    t('My invitations'),
    t('You do not have invitations.'),
  );
  $export['user_notifications'] = $view;

  return $export;
}
