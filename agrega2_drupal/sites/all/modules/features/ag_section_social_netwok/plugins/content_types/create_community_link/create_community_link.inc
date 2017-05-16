<?php
/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Create community link'),
  'description' => t('Create community link in My communities section'),
  'category' => t('Agrega2'),
  'render callback' => 'create_community_link_content_type_render',
);


/**
 * Render callback.
 */
function create_community_link_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'ag_section_social_netwok';
  $block->title = '<none>';

  // Render the block:
  $block->content = array(
    '#type' => 'markup',
    '#prefix' => '',
    '#markup' => l(t('Request a new community'), 'node/add/social-network', array(
      'attributes' => array(
        'id' => 'request-new-community',
        'title' => t('Request a new community'),
      ),
    )),
    '#suffix' => '',
  );

  return $block;
}
