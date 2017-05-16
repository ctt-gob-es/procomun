<?php
/**
 * @file
 * Plugin content type for panels to create and edit newsletter.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Newsletter form'),
  'description' => t("Custom form to create and edit newsletter"),
  'category' => t('Agrega2'),
  'render callback' => 'ag_section_newsletter_newsletter_form',
);

/**
 * Render callback.
 */
function ag_section_newsletter_newsletter_form($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'ag_section_newsletter';
  $block->title = '<none>';

  module_load_include('inc', 'ag_section_newsletter', 'includes/ag_section_newsletter.pages');
  $newsletter_form = drupal_get_form('ag_section_newsletter_generate_newsletter_form', $args[0]);
  $output = drupal_render($newsletter_form);
  $block->content = $output;

  return $block;
}
