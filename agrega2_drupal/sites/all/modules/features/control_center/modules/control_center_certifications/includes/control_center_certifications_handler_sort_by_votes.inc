<?php

/**
 * @file
 * Definition of control_center_certifications_handler_sort_by_votes.
 */

/**
 * Handler to sort contents by votes certification criterion
 */
class control_center_certifications_handler_sort_by_votes extends views_handler_sort {

  function query() {
    $this->ensure_my_table();

    // Add join with votingapi_cache table
    $join = new views_join();
    $join->construct(
      'votingapi_cache',          // table
      'node',                     // left table
      'nid',                      // left field
      'entity_id'                 // field
    );
    $join->extra = "votingapi_cache.entity_type = 'node' AND votingapi_cache.function = 'count'";

    // Add join to query; 'node' is the left table name
    if (isset($this->view->exposed_input['sort_by']) && $this->view->exposed_input['sort_by'] == 'sort_by_votes') {
      if (!isset($this->query->relationships['votingapi_cache'])) {
        $this->query->add_relationship('votingapi_cache', $join, 'node');
      }
      $this->query->add_orderby(NULL, 'votingapi_cache.value', $this->options['order'], 'votingapi_cache_node_count_value');
    }
  }

}
