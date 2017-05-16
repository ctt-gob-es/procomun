<?php

/**
 * Implements hook_views_data()
 */
function recommendations_views_data() {
  $data = array();
  $data['recommendations_shared_content']['table']['group'] = t('Recommendations');
  $data['recommendations_shared_content']['table']['join'] = array(
    'node' => array(
      'handler' => 'views_join',
      'left_table' => 'node',
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['recommendations_shared_content']['uid'] = array(
    'title' => t('The primary identifier for a user'),
    'help' => t('The primary identifier for a user'),
    'relationship' => array(
      'base' => 'users',
      'base_field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('The user id who has shared the content'),
      'title' => t('User id'),
      'help' => t('The user id who has shared the content'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['recommendations_shared_content']['nid'] = array(
    'title' => t('Unique identifier for the node'),
    'help' => t('Unique identifier for the node'),
    'relationship' => array(
      'base' => 'node',
      'base_field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('The node id of the shared content'),
      'title' => t('Node id'),
      'help' => t('The node id of the shared content'),
    ),
  );

  $data['recommendations_shared_content']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('When user shared node.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['recommendations_shared_content']['gid'] = array(
    'title' => t('Group ID'),
    'help' => t('When user view of node.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  return $data;
}