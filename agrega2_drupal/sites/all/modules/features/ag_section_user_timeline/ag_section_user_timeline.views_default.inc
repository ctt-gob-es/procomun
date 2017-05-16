<?php
/**
 * @file
 * ag_section_user_timeline.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ag_section_user_timeline_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_timeline';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_user_timeline';
  $view->human_name = 'User timeline';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My interests';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'más';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reiniciar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '389';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elementos por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Desplazamiento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹';
  $handler->display->display_options['pager']['options']['tags']['next'] = '›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There isn\'t new content in your timeline';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_user_timeline';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Indexed Content: Date changed */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_user_timeline';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: Author: Users who flagged the entity with flag follow_user (indexed) */
  $handler->display->display_options['filters']['author_flag_follow_user_user']['id'] = 'author_flag_follow_user_user';
  $handler->display->display_options['filters']['author_flag_follow_user_user']['table'] = 'search_api_index_user_timeline';
  $handler->display->display_options['filters']['author_flag_follow_user_user']['field'] = 'author_flag_follow_user_user';
  $handler->display->display_options['filters']['author_flag_follow_user_user']['value'] = array(
    0 => '1',
  );
  $handler->display->display_options['filters']['author_flag_follow_user_user']['group'] = 1;
  /* Filter criterion: Indexed Content: Author */
  $handler->display->display_options['filters']['author']['id'] = 'author';
  $handler->display->display_options['filters']['author']['table'] = 'search_api_index_user_timeline';
  $handler->display->display_options['filters']['author']['field'] = 'author';
  $handler->display->display_options['filters']['author']['value'] = array(
    0 => '1',
  );
  $handler->display->display_options['filters']['author']['group'] = 1;
  /* Filter criterion: Indexed Content: Author */
  $handler->display->display_options['filters']['author_1']['id'] = 'author_1';
  $handler->display->display_options['filters']['author_1']['table'] = 'search_api_index_user_timeline';
  $handler->display->display_options['filters']['author_1']['field'] = 'author';
  $handler->display->display_options['filters']['author_1']['value'] = array(
    0 => '1',
  );

  /* Display: Timeline content pane */
  $handler = $view->new_display('panel_pane', 'Timeline content pane', 'panel_pane_1');
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
  $handler->display->display_options['argument_input'] = array(
    'author_flag_follow_user_user' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Author: Users who flagged the entity with flag follow_user (indexed)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['user_timeline'] = array(
    t('Master'),
    t('My interests'),
    t('más'),
    t('Aplicar'),
    t('Reiniciar'),
    t('Ordenar por'),
    t('Asc'),
    t('Desc'),
    t('Elementos por página'),
    t('- Todos -'),
    t('Desplazamiento'),
    t('«'),
    t('‹'),
    t('›'),
    t('»'),
    t('There isn\'t new content in your timeline'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Timeline content pane'),
    t('more'),
    t('Vista panel'),
  );
  $export['user_timeline'] = $view;

  return $export;
}
