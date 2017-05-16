<?php
/**
 * @file
 * Plugin content type for panels to manage community's users.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Community manage people form'),
  'description' => t("Custom ct pane form add community's users."),
  'category' => t('Form'),
  'render callback' => 'control_center_community_adduser',
);

/**
 * Render callback.
 */
function control_center_community_adduser($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'control_center_communities';
  $block->title = '<none>';

  //Load the include file for node pages
  module_load_include('inc', 'og_ui', 'og_ui.admin');

  //Load corresponding form and set redirect
  $form = drupal_get_form('og_ui_add_users', 'node', $args[0]);
  $block->content = $form;

  return $block;
}
