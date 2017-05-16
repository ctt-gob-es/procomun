<?php

/**
 * @file
 * This module define the handlers needed in ag_section_social_netwok feature
 */

/**
 * This handler create links for moderate functionallity. The link allows to
 *
 */
class ag_section_social_netwok_handler_moderate extends views_handler_field_node_link {
  /**
   * Render a link with the callback URL for moderating
   */
  function render_link($node, $values) {
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/control-center/communities/moderate/$node->nid";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('Moderate');
    return $text;
  }
}