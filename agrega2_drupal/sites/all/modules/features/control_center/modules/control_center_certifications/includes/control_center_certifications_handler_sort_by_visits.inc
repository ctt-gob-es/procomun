<?php

/**
 * @file
 * Definition of control_center_certifications_handler_sort_by_visits.
 */

/**
 * Handler to sort contents by visits certification criterion
 */
class control_center_certifications_handler_sort_by_visits extends views_handler_sort {

  function query() {
    $this->ensure_my_table();

    // Add join with odevisitscount mysql view
    $join = new views_join();
    $join->construct(
      'odevisitscount',          // table
      'node',                    // left table
      'nid',                     // left field
      'nid'                      // field
    );
    $join->type = 'INNER';

    // Add join to query; 'node' is the left table name
    if (isset($this->view->exposed_input['sort_by']) && $this->view->exposed_input['sort_by'] == 'sort_by_visits') {
      if (!isset($this->query->relationships['odevisitscount'])) {
        $this->query->add_relationship('odevisitscount', $join, 'node');
      }
      $this->query->add_orderby(NULL, 'odevisitscount.total_visits', $this->options['order'], 'total_visits');
    }
  }

}
