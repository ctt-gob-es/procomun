<?php
/**
 * @file
 * Plugin content type for panels create custom translatable block
 */
 
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Content type add translatable block'),
  'description' => t('Custom ct pane add translatable block.'),
  'category' => t('Custom blocks'),
  'render callback' => 'ag_general_custom_block_content_type_render',
  'edit form' => 'ag_general_custom_block_content_type_edit_form',
);

/**
 * Render callback.
 */
function ag_general_custom_block_content_type_render($subtype, $conf, $args, $context) {

  $module = 'ag_general';
  $block = new stdClass();
  $block->module = $module;
  $block->title = '<none>';
  $block->content = NULL;

  if (!empty($conf['content_type_custom_block_title']) && !empty($conf['content_type_custom_block_content']) && !empty($conf['content_type_custom_block_class'])) {
    // Check if title is <none>
    if ($conf['content_type_custom_block_title'] != '<none>') {
      $block_title = t($conf['content_type_custom_block_title']);
      // Check for link.
      if (!empty($conf['content_type_custom_block_title_link'])) {
        $block_title = l($block_title, $conf['content_type_custom_block_title_link']);
      }
    }
    else {
      $block_title = NULL;
    }

    $block->content = theme('custom_translatable_block', array('block_title' => $block_title, 'block_content' => t($conf['content_type_custom_block_content']), 'block_class' => $conf['content_type_custom_block_class']));
  }

  return $block;
}

/**
 * Implementation of a content_type edit form
 */
function ag_general_custom_block_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['content_type_custom_block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Block title'),
    '#description' => t('Use &lt;none&gt; from empty title'),
    '#default_value' => $conf['content_type_custom_block_title'],
    '#required' => TRUE,
  );

  $form['content_type_custom_block_title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Block title link'),
    '#description' => t('Internal relative path'),
    '#default_value' => $conf['content_type_custom_block_title_link'],
    '#required' => FALSE,
  );

  $form['content_type_custom_block_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Block content'),
    '#default_value' => $conf['content_type_custom_block_content'],
    '#required' => TRUE,
  );

  $form['content_type_custom_block_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Block class'),
    '#default_value' => $conf['content_type_custom_block_class'],
    '#required' => TRUE,
  );

  return $form;
}

/**
 * Implementation of a content_type edit form submit callback
 */
function ag_general_custom_block_content_type_edit_form_submit($form, &$form_state) {
  if ($form_state['values']['content_type_custom_block_title'] != '<none>') {
    $translate_block_title = t($form_state['values']['content_type_custom_block_title']);
  }
  $form_state['conf']['content_type_custom_block_title'] = $form_state['values']['content_type_custom_block_title'];
  $form_state['conf']['content_type_custom_block_title_link'] = $form_state['values']['content_type_custom_block_title_link'];
  $translate_block_content = t($form_state['values']['content_type_custom_block_content']);
  $form_state['conf']['content_type_custom_block_content'] = $form_state['values']['content_type_custom_block_content'];
  $form_state['conf']['content_type_custom_block_class'] = $form_state['values']['content_type_custom_block_class'];
}