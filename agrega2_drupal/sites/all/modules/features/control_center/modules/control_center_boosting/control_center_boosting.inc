<?php

function _boosting_information_retrieve() {
  $nodes = node_load_multiple(array(), array('type' => 'solr_fields'));
  foreach ($nodes as $node) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $body = $wrapper->body->value();

    // Build array needed for service.
    $boosting_fields[] = array(
      'fieldName' => $wrapper->title->value(),
      'boosting' => $wrapper->field_boosting_weight->value(),
      'description' => $body['value'],
    );
  }

  return $boosting_fields;
}