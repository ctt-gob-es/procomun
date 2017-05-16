<?php
/**
 * @file
 * Plugin content type for panels to create a FAQ.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Add FAQ form'),
  'description' => t("Custom form to create a FAQ"),
  'category' => t('Agrega2'),
  'render callback' => 'ag_section_help_faq_form',
);

/**
 * Render callback.
 */
function ag_section_help_faq_form($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'ag_section_help';
  $block->title = '<none>';

  $faq_form = drupal_get_form('ag_section_help_add_faq_form');
  $output = drupal_render($faq_form);
  $block->content = $output;

  return $block;
}
