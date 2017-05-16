<?php
/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Base learning path detail'),
  'description' => t('Render the base learning path details for an learning path that have been cloned.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Agrega2'),
  'render callback' => 'itinerary_base_detail_content_type_render',
);

/**
 * Render callback.
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 *
 * @return bool|object
 */
function itinerary_base_detail_content_type_render($subtype, $conf, $args, $context) {
  // Data is required
  if (empty($context->data)) {
    return FALSE;
  }

  $base_itinerary = (empty($context->data->field_base_itinerary)) ? false : $context->data->field_base_itinerary['und'][0]['entity'];

  $block = new stdClass();
  if($base_itinerary != FALSE) {
    $block->title = t('Original learning path');
    $block->content = callback_render_base_itinerary_content($base_itinerary);
  }

  return $block;
}

/**
 * Render the content for an itinerary base.
 *
 * @param $node
 *
 * @return array
 *
 * @ingroup callbacks
 */
function callback_render_base_itinerary_content($node) {
  if ($node != FALSE) {
    // Get author data needed.
    $author = DrupalToolKit::getUserData($node->uid, array('picture', 'uid'));
    $author_full_name = ag_section_profile_users_get_name_surname_cached($node->uid);

    // Build author content. Author picture go inside.
    $author_content = array(
      'user_photo' => array(
        'uid' => $author->uid,
        'name' => $author_full_name,
        'picture' => array(
          '#theme' => 'image_style',
          '#style_name' => 'ag_scalecrop_150x150',
          '#path' => isset($author->uri) ? $author->uri : variable_get('user_picture_default', ''),
        ),
      ),
      'author_fullname' => array(
        '#markup' => "<span>{$author_full_name}</span>",
      ),
    );

    // Build author link attributes.
    $options = array(
      'html' => TRUE,
      'attributes' => array(
        'target' => '_blank',
        'class' => array('user-picture')
      ),
    );

    // Build all those links needed.
    $author_link = l(render($author_content), 'profile/' . $node->uid . '/public', $options);
    $title_link = l($node->title, 'node/' . $node->nid, array('attributes' => array('target' => '_blank')));

    $content = array(
      '#theme' => 'ag_base_itinerary_details',
      '#data' => array(
        'title' => $title_link,
        'author' => $author_link,
      ),
    );
  }

  return $content;
}