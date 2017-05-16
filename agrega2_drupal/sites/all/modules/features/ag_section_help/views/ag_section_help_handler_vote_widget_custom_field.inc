<?php

/**
 * @file
 * Definition of example_handler_custom_field
 */

/**
 * Provides a custom views field.
 */
class ag_section_help_handler_vote_widget_custom_field extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($data) {
    // Generate rate widget with id 1 (vote)
    $output = rate_generate_widget(1, 'comment', $data->comment_node_cid);

    return $output;
  }
}
