<?php
/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Comunity public dashboard'),
  'description' => t('Render the main block of a comunity public view.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Agrega2'),
  'render callback' => 'comunity_public_dashboard_content_type_render',
);


/**
 * Render callback.
 */
function comunity_public_dashboard_content_type_render($subtype, $conf, $args, $context) {
  // Data is required
  if (empty($context->data)) {
    return FALSE;
  }

  $entity = $context->data;
  $check = og_is_group('node', $entity);
  if (!$check) {
    $group_nid = $context->data->og_group_ref['und'][0]['target_id'];
    $entities = entity_load('node', array($group_nid));
    $entity = $entities[$group_nid];
  }
  $block = new stdClass();

  $vars = array(
    'comunity_title' => '<h3>' . $entity->title . '</h3>',
    'wall_links' => array(
      '#theme' => 'item_list',
      '#items' => _ag_section_social_work_generate_wall_links($entity->nid),
      '#attributes' => array(
        'class' => array('comunity-wall-links'),
      ),
    ),
    'resources_count' =>
      l(OgDrupalToolKit::countContentsByGroup('node', array('recurso_de_aprendizaje', 'ode', 'post'), $entity->nid),
         'node/' . $entity->nid),
    'members_count' =>
      l(OgDrupalToolKit::countMemberships('user', $entity->nid), 'node/' . $entity->nid . '/members'),
    'administers_list' => array(
      '#theme' => 'item_list',
      '#items' => _ag_section_social_work_get_administers_list($entity),
      '#attributes' => array(
        'class' => array('comunity-administers-list'),
      ),
    ),
    'comunity_access_type' => _ag_section_social_work_get_comunity_type($entity)->text,
    );

  // Render the subscribe/unsubscribe content:
  $subscribe_render = array(
    '#theme' => 'ag_subscribe_unsubscribe',
    '#nid' => $entity->nid,
  );
  $vars['comunity_subscribe_link'] = $subscribe_render;

  // Render the block:
  $block->content = array(
    '#theme' => 'content_comunity_public_dashboard',
    '#vars' => $vars,
    '#attached' => array(
      'js' => array(drupal_get_path('module', 'ag_section_social_netwok') . '/js/comunity_public_dashboard.js'),
    ),
  );

  return $block;
}
