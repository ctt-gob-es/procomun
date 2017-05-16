<?php
/**
 * @file
 * ag_section_podcast.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ag_section_podcast_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ag_podcast_rss';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ag podcast RSS';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Procomun podcasts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Soundcloud trackID */
  $handler->display->display_options['fields']['field_soundcloud_trackid']['id'] = 'field_soundcloud_trackid';
  $handler->display->display_options['fields']['field_soundcloud_trackid']['table'] = 'field_data_field_soundcloud_trackid';
  $handler->display->display_options['fields']['field_soundcloud_trackid']['field'] = 'field_soundcloud_trackid';
  $handler->display->display_options['fields']['field_soundcloud_trackid']['label'] = '';
  $handler->display->display_options['fields']['field_soundcloud_trackid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_soundcloud_trackid']['type'] = 'field_hidden_numeric_unformatted';
  /* Field: Content: File size */
  $handler->display->display_options['fields']['field_file_size']['id'] = 'field_file_size';
  $handler->display->display_options['fields']['field_file_size']['table'] = 'field_data_field_file_size';
  $handler->display->display_options['fields']['field_file_size']['field'] = 'field_file_size';
  $handler->display->display_options['fields']['field_file_size']['label'] = '';
  $handler->display->display_options['fields']['field_file_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_size']['type'] = 'field_hidden_numeric_unformatted';
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
    'podcast' => 'podcast',
  );

  /* Display: Podcast feed */
  $handler = $view->new_display('feed', 'Podcast feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['path'] = 'latest-podcasts';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['ag_podcast_rss'] = array(
    t('Master'),
    t('Latest Procomun podcasts'),
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
    t('Podcast feed'),
  );
  $export['ag_podcast_rss'] = $view;

  return $export;
}
