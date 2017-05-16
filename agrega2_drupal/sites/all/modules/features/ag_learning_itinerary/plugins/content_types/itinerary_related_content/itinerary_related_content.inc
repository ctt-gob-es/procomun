<?php
/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Learning path related content'),
  'description' => t('Render the related content for a learning path'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('Agrega2'),
  'render callback' => 'itinerary_related_content_content_type_render',
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
function itinerary_related_content_content_type_render($subtype, $conf, $args, $context) {
  // Data is required
  if (empty($context->data)) {
    return FALSE;
  }

  $interest_content = $context->data->field_interest_content['und'];

  $block = new stdClass();
  $block->title = t('Related contents');
  $block->content = callback_render_related_content($interest_content);

  return $block;
}

/**
 * Render the content body for the related content on a Learning Itinerary.
 *
 * @param array $content
 *   Contents related with current Learning path.
 *
 * @return array
 *
 * @ingroup callbacks
 */
function callback_render_related_content($content) {
  if (!empty($content)) {
    $items = array();

    foreach ($content as $item) {
      $item_rendered = array(
        '#theme' => 'ag_recommended_itinerary_content',
        '#data' => $item['entity'],
      );

      $items[] = render($item_rendered);
    }

    $content = array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#attributes' => array(
        'class' => array('recomended_contents_list'),
      ),
    );
  }
  else {
    // If not results show a message.
    $content = array(
      '#type' => 'markup',
      '#markup' => '<span>' . t('There is no related content for this learning path') . '</span>',
    );
  }

  return $content;
}
