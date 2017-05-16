<?php
/**
 * @file
 * Definition of handler_learning_path_default_image.
 */

/**
 * Build a default image for each entity as long as the entity does not have a
 * previously assigned image, in case the entity has an image, the image will
 * be rendered.
 *
 * @ingroup views_filter_handlers
 */
class handler_learning_path_default_image extends views_handler_field {

  /**
   * Construct a new field handler.
   */
  function construct() {
    parent::construct();
  }

  function query() {
    $this->ensure_my_table();
  }

  /**
   * Render the entity image.
   *
   * @param object $values
   *   The values retrieved from the database.
   *
   * @return string $output
   *   Entity image.
   */
  function render($values) {
    $output = $this->render_default_image($values);
    return $output;
  }

  /**
   * TODO: Need comments.
   *
   * @param object $values
   *   The values retrieved from the database.
   *
   * @return string $output
   *   An HTML output containing a default image.
   */
  private function render_default_image($values) {
    switch ($values->node_type) {
      case 'external_content':
        $default_image = drupal_get_path('theme', 'nexus') . '/images/url_default.jpg';
        break;

      case 'itinerary':
        $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
        break;

      case 'ode':
        $wrapper = entity_metadata_wrapper('node', $values->nid);
        $learning_resource = ag_visualization_ode_get_solr_ode($wrapper->field_solrid->value());
        if (!empty($learning_resource['preview'])) {
          if (getimagesize("http://{$learning_resource['preview']}") !== false) {
            $default_image = "http://{$learning_resource['preview']}";
          }
          else {
            $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
          }
        }
        else {
          $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
        }
        break;

      case 'post':
        $wrapper = entity_metadata_wrapper('node', $values->nid);
        $post_image = $wrapper->field_imagen_miniatura->value();
        $default_image = (!empty($post_image['uri'])) ? $post_image['uri'] : drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
        break;
    }

    if (isset($default_image) && !empty($default_image)) {
      $options = array(
        'path' => $default_image,
        'width' => '100px',
        'height' => '100px',
      );
      $output = theme('image', $options);
    }

    return (!empty($output)) ? $output : '';
  }

}
