<?php

if (module_exists('entityreference_prepopulate')) {
  /**
   * Plugin definition.
   */
  $plugin = array(
    'title' => t('Content creation links on the wall'),
    'description' => t('Crafted links to create content (nodes) for a given group.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'category' => t('Organic groups'),
    'defaults' => array(
      'types' => array(),
      'field_name' => OG_AUDIENCE_FIELD,
    ),
  );
}

/**
 * Render callback.
 */
function og_wall_node_create_links_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return FALSE;
  }
  // Get $node form context data:
  $node = $context->data;

  // Build links.
  $links = array();
  foreach ($conf['types_labels'] as $key => $value) {
    if (in_array($key, $conf['types']) && og_user_access('node', $node->nid, "create $key content")) {
      $options = array('query' => array(drupal_get_destination()));
      $options['query'] += array($conf['field_name'] => $node->nid);

      //Special rules for faqs community. Only administrators may create content, normal users, just questions.
      if ($context->argument == FAQS) {
        $group_roles = og_get_user_roles('node', $context->argument);
        $has_permissions = in_array('administrator member', array_values($group_roles));

        //Post are available only for admins.
        if ($has_permissions && $key == 'post') {
          $links[] = l(t($value), 'node/add/' . $key, $options);
        }
        else if ($key == 'question') {
          //In this community, question is a single button, without debate creation.
          $links[] = l(t($value), 'node/add/' . $key, $options);
        }
      }
      else if ($key == 'ode') {
        // When we've ODEs don't set destination, because it affects to redirects when there is a validation error.
        unset($options['query'][0]);
        $links[] = l(t($value), 'ode/add/', $options);
      }
      else if ($key == 'question') {
        $links[] = l(t('Questions/Discussions'), 'node/' . $node->nid . '/debates');
      }
      else {
        $links[] = l(t($value), 'node/add/' . $key, $options);
      }
    }
  }
  if (!$links) {
    return FALSE;
  }

  $module = 'og';
  $block = new stdClass();
  $block->module = $module;
  $block->title = '<none>';
  $block->content = array('og_wall_node_create_links' => array(
    '#theme' => 'item_list',
    '#items' => $links,
  ));

  return $block;
}

/**
 * Edit form.
 */
function og_wall_node_create_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $options = array();
  foreach (field_info_fields() as $field_name => $field) {
    if (!og_is_group_audience_field($field_name)) {
      continue;
    }

    if ($field['settings']['target_type'] != 'node') {
      continue;
    }
    // Use CTools to get the best matching field name.
    ctools_include('fields');
    $options[$field_name] = ctools_field_label($field_name) . " ($field_name)";
  }

  $form['field_name'] = array(
    '#title' => t('Field name'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $conf['field_name'],
    '#description' => t('The group audience field to prepopulate.'),
    '#required' => TRUE,
  );

  $options = array();
  foreach (node_type_get_types() as $type) {
    if (og_is_group_content_type('node', $type->type)) {
      $options[$type->type] = check_plain($type->name);
    }
  }

  $form['types'] = array(
    '#title' => t('Restrict to content types'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => $conf['types'],
    '#description' => t('If left empty, all possible content types are shown.'),
  );

  foreach ($options as $key => $value) {
    $form['types_labels'][$key] = array(
      '#title' => t('Label for @value', array('@value' => $value)),
      '#type' => 'textfield',
      '#default_value' => $conf['types_labels'][$key],
    );
  }

  return $form;
}

/**
 * Edit form submit callback.
 */
function og_wall_node_create_links_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['field_name'] = $form_state['values']['field_name'];
  $form_state['conf']['types'] = array_filter($form_state['values']['types']);

  foreach ($form_state['values']['types'] as $key => $value) {
    $form_state['conf']['types_labels'][$key] = $form_state['values'][$key];
  }
}
