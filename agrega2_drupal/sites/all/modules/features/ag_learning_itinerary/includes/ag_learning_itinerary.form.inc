<?php
/**
 * @file
 * Setting up the configuration for learning path.
 */

/////////////
/// HOOKS ///
/////////////

/**
 * Implements hook_form_FORM_ID_alter() for itinerary_node_form().
 */
function ag_learning_itinerary_form_itinerary_node_form_alter(&$form, &$form_state, $form_id) {
  global $user;

  // Attach to the form the JavaScript files needed to simulate the multi-step
  // control.
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'ag_learning_itinerary') . '/js/learning_path.js',
    drupal_get_path('module', 'draggableviews') . '/js/draggableviews_table.js',
    'misc/tabledrag.js',
  );

  // Hide fields that should not be displayed to the user.
  $form['#after_build'][] = 'callback_hide_additional_settings';
  $form['field_itinerary_content']['#access'] = FALSE;
  $form['field_interest_content']['#access'] = FALSE;

  // Function to generate the buttons that simulate the multi-step.
  callback_generate_buttons($form);

  // Check if the user is in a creation or edit screen.
  $node = menu_get_object();
  if (empty($node)) {
    // Unflag all content marked by the user.
    callback_unflag_user_content('learning_path_content', $user);
    callback_unflag_user_content('learning_path_interest_content', $user);

    // Setting up the sort in the draggable view.
    //callback_set_sort_draggable($form, $user, 'field_itinerary_content', 'learning_path_content_selected');
    //callback_set_sort_draggable($form, $user, 'field_interest_content', 'learning_path_interest_content_selected');

    // If there is a learning path passed by reference, the learning path will
    // be cloned.
    if (isset($_GET['field_base_itinerary']) && !empty($_GET['field_base_itinerary'])) {
      $node = node_load($_GET['field_base_itinerary']);
      $lang = LANGUAGE_NONE;

      // Create an 'entity metadata wrapper' to ease getting data.
      $wrapper = entity_metadata_wrapper('node', $node);
      $field_base_itinerary_title = $wrapper->title->value();
      $field_base_itinerary_body = $wrapper->body->value();
      $field_base_itinerary_knowledge_area = current($wrapper->field_knowledge_area->value());
      $field_base_itinerary_learning_context = current($wrapper->field_learning_context->value());
      $field_base_itinerary_labels = $wrapper->field_labels->value();
      $field_base_itinerary_allow_share = $wrapper->field_question_share->value();

      // Given an learning path as an argument, fill form fields based on that
      // argument.
      $form['title_field'][$lang][0]['value']['#default_value'] = t('Copy of: @title', array('@title' => $field_base_itinerary_title));
      $form['body'][$lang][0]['#default_value'] = $field_base_itinerary_body['value'];
      $form['field_knowledge_area'][$lang]['#default_value'] = $field_base_itinerary_knowledge_area->tid;
      $form['field_learning_context'][$lang]['#default_value'] = $field_base_itinerary_learning_context->tid;
      $form['field_labels'][$lang]['#default_value'] = taxonomy_implode_tags($field_base_itinerary_labels);
      $form['field_question_share'][$lang]['#default_value'] = $field_base_itinerary_allow_share;

      // If a learning path is passed by reference, mark its contents for the
      // current user.
      callback_flag_user_content('learning_path_content', $user, $node, 'field_itinerary_content');
      callback_flag_user_content('learning_path_interest_content', $user, $node, 'field_interest_content');
    }
  }
  else {
    // Unflag all content marked by the user.
    callback_unflag_user_content('learning_path_content', $user);
    callback_unflag_user_content('learning_path_interest_content', $user);

    // Flag all content stored as content or interest content for the learning
    // path.
    callback_flag_user_content('learning_path_content', $user, $node, 'field_itinerary_content');
    callback_flag_user_content('learning_path_interest_content', $user, $node, 'field_interest_content');

    // Setting up the sort in the draggable view.
    //callback_set_sort_draggable($form, $user, 'field_itinerary_content', 'learning_path_content_selected');
    //callback_set_sort_draggable($form, $user, 'field_interest_content', 'learning_path_interest_content_selected');
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for node_delete_confirm_form().
 */
function ag_learning_itinerary_form_node_delete_confirm_alter(&$form, &$form_state, $form_id) {
  global $user;

  if (isset($form['#node']) && $form['#node']->type == 'itinerary') {
    $_GET['destination'] = 'user/' . $user->uid . '/learning-paths';
  }
}

/////////////////
/// CALLBACKS ///
/////////////////

/**
 * TODO: Need comments.
 *
 * Callback for ag_learning_itinerary_form_itinerary_node_form_alter().
 *
 * @param array $form
 *   Contains the structure of the form.
 * @param object $user
 *   User information.
 * @param string $field
 *   Field name.
 * @param string $view_display
 *   The view display name.
 *
 * @ingroup callbacks
 */
function callback_set_sort_draggable($form, $user, $field, $view_display) {
  // Remove all sort records for the current learning path.
  db_delete('draggableviews_structure')
    ->condition('view_display', $view_display)
    ->condition('user_id', $user->uid)
    ->execute();

  // Save sorted content belonging to the field into the database.
  if (isset($form['#node']->{$field}) && !empty($form['#node']->{$field})) {
    foreach ($form['#node']->{$field}[LANGUAGE_NONE] as $key => $value) {
      if (!empty($value['target_id'])) {
        $record = array(
          'view_name' => 'learning_path_content',
          'view_display' => $view_display,
          'args' => '[]',
          'entity_id' => $value['target_id'],
          'weight' => $key,
          'user_id' => $user->uid,
        );

        drupal_write_record('draggableviews_structure', $record);
      }
    }
  }
}

/**
 * Build the buttons to simulate the pagination of a multi-step form.
 *
 * Callback for ag_learning_itinerary_form_itinerary_node_form_alter().
 *
 * @param $form
 *   Contains the structure of the form.
 *
 * @ingroup callbacks
 */
function callback_generate_buttons(&$form) {
  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'attributes' => array('class' => 'multi-step-control'),
  );

  $variables['items'][] = l('1', '', array(
    'fragment' => 'block-learning-path-node-form',
    'external' => TRUE,
    'attributes' => array('class' => 'active'),
  ));
  $variables['items'][] = l('2', '', array(
    'fragment' => 'block-panels-mini-learning-path-content',
    'external' => TRUE,
  ));
  $variables['items'][] = l('3', '', array(
    'fragment' => 'block-panels-mini-learning-path-interest-content',
    'external' => TRUE,
  ));

  $form['actions']['multi_step_buttons']['#markup'] = theme_item_list($variables);
}
