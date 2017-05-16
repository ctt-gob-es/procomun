<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Communities per organization.'),
  'description' => t('Render the communities per organization.'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('Agrega2'),
  'render callback' => 'communities_per_organization_render',
);


/**
 * Render callback.
 */
function communities_per_organization_render($subtype, $conf, $args, $context) {
  // Data is required
  if (empty($context->data)) {
    return FALSE;
  }

  $block = new stdClass();

  $results = db_query('SELECT DISTINCT og_membership.gid from {og_membership} LEFT JOIN {field_data_field_organization_reference} ON field_data_field_organization_reference.entity_id = og_membership.etid WHERE field_data_field_organization_reference.field_organization_reference_target_id = :oid', array(':oid' => $context->argument));

  $content = '';
  $header = array(t('Communities to which it belongs.'));
  $rows = array();
  foreach ($results as $result) {
    $community = db_query('SELECT title FROM {node} WHERE nid = :nid', array(':nid' => $result->gid))->fetchField();
    $rows[] = array(l($community, 'node/' . $result->gid));
  }

  $block->content = theme('table', array('header' => $header,'rows' => $rows));

  return $block;
}

