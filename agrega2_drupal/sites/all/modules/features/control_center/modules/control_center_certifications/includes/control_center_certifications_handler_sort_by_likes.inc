<?php

/**
 * @file
 * Definition of control_center_certifications_handler_sort_by_likes.
 */

/**
 * Handler to sort contents by likes certification criterion
 */
class control_center_certifications_handler_sort_by_likes extends views_handler_sort {

  function query() {
    $this->ensure_my_table();

    // Add join with odelikescount mysql view
    $join = new views_join();
    $join->construct(
      'odelikescount',          // table
      'node',                   // left table
      'nid',                    // left field
      'nid'                     // field
    );
    $join->type = 'INNER';

    // Add join to query; 'node' is the left table name
    if (isset($this->view->exposed_input['sort_by']) && $this->view->exposed_input['sort_by'] == 'sort_by_likes') {
      if (!isset($this->query->relationships['odelikescount'])) {
        $this->query->add_relationship('odelikescount', $join, 'node');
      }
      $this->query->add_orderby(NULL, 'odelikescount.total_likes', $this->options['order'], 'total_likes');
    }
  }

}
