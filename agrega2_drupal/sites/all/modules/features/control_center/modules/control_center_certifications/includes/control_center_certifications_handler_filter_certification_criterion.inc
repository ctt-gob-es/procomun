<?php

/**
 * @file
 * Definition of control_center_certifications_handler_filter_certification_criterion.
 */

/**
 * Simple filter to filter contents by certification criteria odes
 */
class control_center_certifications_handler_filter_certification_criterion extends views_handler_filter {

  /**
   * Options form subform for setting exposed filter options.
   */
  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);

    // Create select form element with certification criteria
    $form['value']['certification_criterion'] = array(
      '#type' => 'select',
      '#options' => array(
        '0' => t('All'),
        '1' => t('Exceed likes'),
        '2' => t('Exceed comments'),
        '3' => t('Exceed votes/average'),
        '4' => t('Exceed visits'),
      ),
      '#default_value' => '0',
    );
  }

  /**
   * Alter views query when filter is used.
   */
  function query() {
    // Make sure base table is included in the query
    $this->ensure_my_table();

    // Retrieve real filter name from view options
    // This requires 'real field' filter option to be set (see code above)
    $real_field_name = $this->real_field;

    // Get the value of the submitted filter
    $value = $this->view->exposed_data[$real_field_name];

    // Finally, alter views query
    if (isset($value) && !empty($value)) {
      switch ($value) {
        case '1':
          // Add join with odelikescount mysql view
          $join = new views_join();
          $join->construct(
            'odelikescount',          // table
            'node',                   // left table
            'nid',                    // left field
            'nid'                     // field
          );

          // Add join to query; 'node' is the left table name
          if (!isset($this->query->relationships['odelikescount'])) {
            $this->query->add_relationship('odelikescount', $join, 'node');
          }

          $this->query->add_field(NULL, 'odelikescount.total_likes', 'total_likes');
          $this->query->add_where(1, 'total_likes', variable_get('ode_number_likes'), '>=');
          break;

        case '2':
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
          if (!isset($this->query->relationships['node_comment_statistics'])) {
            $this->query->add_relationship('node_comment_statistics', $join, 'node');
          }

          $this->query->add_where(1, 'node_comment_statistics.comment_count', variable_get('ode_number_comments'), '>=');
          break;

        case '3':
          // Add join with votingapi_cache table
          // Votes
          $join = new views_join();
          $join->construct(
            'votingapi_cache',          // table
            'node',                     // left table
            'nid',                      // left field
            'entity_id'                 // field
          );
          $join->extra = "votingapi_cache.entity_type = 'node' AND votingapi_cache.function = 'count'";

          // Add join to query; 'node' is the left table name
          if (!isset($this->query->relationships['votingapi_cache'])) {
            $this->query->add_relationship('votingapi_cache', $join, 'node');
          }

          $this->query->add_where(1, 'votingapi_cache.value', variable_get('ode_number_votes'), '>=');

          // Average
          $join = new views_join();
          $join->construct(
            'votingapi_cache',          // table
            'node',                     // left table
            'nid',                      // left field
            'entity_id'                 // field
          );
          $join->extra = "votingapi_cache_average.entity_type = 'node' AND votingapi_cache_average.function = 'average'";

          // Add join to query; 'node' is the left table name
          if (!isset($this->query->relationships['votingapi_cache_average'])) {
            $this->query->add_relationship('votingapi_cache_average', $join, 'node');
          }

          $this->query->add_where(1, 'votingapi_cache_average.value', variable_get('ode_average'), '>=');
          break;

        case '4':
          // Add join with odevisitscount mysql view
          $join = new views_join();
          $join->construct(
            'odevisitscount',          // table
            'node',                    // left table
            'nid',                     // left field
            'nid'                      // field
          );

          // Add join to query; 'node' is the left table name
          if (!isset($this->query->relationships['odevisitscount'])) {
            $this->query->add_relationship('odevisitscount', $join, 'node');
          }

          $this->query->add_field(NULL, 'odevisitscount.total_visits', 'total_visits');
          $this->query->add_where(1, 'total_visits', variable_get('ode_number_visits'), '>=');
          break;

        default:
          break;
      }
    }
  }
}
