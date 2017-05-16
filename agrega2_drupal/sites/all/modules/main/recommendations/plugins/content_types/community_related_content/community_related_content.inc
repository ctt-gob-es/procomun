<?php
/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Comunity related content'),
  'description' => t('Render the related content for a community'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Agrega2'),
  'render callback' => 'comunity_related_content_content_type_render',
);


/**
 * Render callback.
 */
function comunity_related_content_content_type_render($subtype, $conf, $args, $context) {
  // Data is required
  if (empty($context->data)) {
    return FALSE;
  }
  global $user;

  $entity = $context->data;
  $block = new stdClass();

  $wrapper = entity_metadata_wrapper('node', $entity);

  $solr_types_correlation = variable_get('ag_solr_content_types_names',array());

  if (isset($wrapper->field_solrid) && $wrapper->field_solrid->value() && isset($solr_types_correlation[$entity->type])) {
    // Render the block:
    $block->title = t('Related contents');
    $block->content = recommendations_render_related_content($solr_types_correlation[$entity->type],
      $user->uid, $wrapper->field_solrid->value(), 3);
  }

  return $block;
}
