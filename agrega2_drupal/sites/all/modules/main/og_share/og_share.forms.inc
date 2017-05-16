<?php

/**
 * Form to share our content.
 */
function og_share_share_form($form, $form_state) {
  $form = array();

  // Get the bundles that are group content:
  $my_groups_options = _og_share_get_user_groups_options($form_state['build_info']['args'][0]);
  if (!empty($my_groups_options)) {
    $form['my-groups'] = array(
      '#title' => t('Select in which communities the content will be shared'),
      '#type' => 'checkboxes',
      '#options' => _og_share_get_user_groups_options($form_state['build_info']['args'][0]),
      '#default_value' => _og_share_check_user_groups_options($form_state['build_info']['args'][0]),
    );

    $form['actions'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('form-actions')
      )
    );

    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Share'),
    );
  }
  else {
    // The content has been shared in user's communities.
    $form['message'] = array(
      '#prefix' => '<span class="og_sahre_message">',
      '#type' => 'markup',
      '#markup' => t('Sorry, this content is already shared in all your commnuties'),
      '#suffix' => '</span>',
    );
  }

  return $form;
}

/**
 * Implements hook_form_alter().
 */
function og_share_form_alter(&$form, &$form_state) {
  // Disable the Procomun community option.
  if ($form['#form_id'] == 'og_share_share_form' && isset($form['my-groups'])) {
    $form['my-groups'][PROCOMUN]['#disabled'] = TRUE;
  }
}

/**
 * Implements FORM_ID_submit().
 */
function og_share_share_form_submit($form, $form_state) {
  $node = NULL;
  // Clean the options not selected.
  $groups_values = array_filter($form_state['values']['my-groups']);
  // Always add Procomun community.
  if (!in_array(PROCOMUN, $groups_values)) {
    array_unshift($groups_values, PROCOMUN);
  }
  $args = $form_state['build_info']['args'];
  if (is_object($args[0]) && isset($args[0]->nid)) {
    $node = $args[0];
  }

  // Allow to others to create new nodes: an Share it.
  drupal_alter('og_share_share', $node, $form_state['build_info']['args']);

  if (isset($node)) {
    // Save the new og_group_refs.
    $w_node = entity_metadata_wrapper('node', $node);
    $w_node->og_group_ref->set($groups_values);
    $w_node->save();

    // Invoke hook with shared networks and node.
    module_invoke_all('og_shared_content', $groups_values, $node);

    drupal_set_message(t('@title has been shared', array('@title' => $w_node->get('title')->value())));
  }
}
