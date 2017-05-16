<?php

/**
 * @file
 * Definition of control_center_certifications_handler_sort_by_comments.
 */

/**
 * Handler to sort contents by comments certification criterion
 */
class control_center_certifications_handler_sort_by_comments extends views_handler_sort {

  function query() {
    $this->ensure_my_table();

    // Add join with node_comment_statistics table
    $join = new views_join();
    $join->construct(
      'node_comment_statistics',          // table
      'node',                             // left table
      'nid',                              // left field
      'nid'                               // field
    );
    $join->type = 'INNER';

    // Add join to query; 'node' is the left table name
    if (isset($this->view->exposed_input['sort_by']) && $this->view->exposed_input['sort_by'] == 'sort_by_comments') {
      if (!isset($this->query->relationships['node_comment_statistics'])) {
        $this->query->add_relationship('node_comment_statistics', $join, 'node');
      }
      $this->query->add_orderby(NULL, 'node_comment_statistics.comment_count', $this->options['order'], 'node_comment_statistics_comment_count');
    }
  }

}
