<?php

/**
 * Config form for recommend_content block.
 */
function recommend_content_block_configure_form(&$form) {
  $form['number_recommendations'] = array(
    '#type' => 'select',
    '#required' => TRUE,
    '#title' => t('Number of recomended content'),
    '#description' => t('Select the number of recomended content that will shown in
      the recommended content block'),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)),
    '#default_value' => variable_get('recommendations_number_recommendations', 3),
    '#element_validate' => array('ag_is_numeric_element_validate'),
  );
}


/**
 * Custom element validate for numer_validation element.
 * @see recommend_content_block_configure_form().
 */
function ag_is_numeric_element_validate($element, &$form_state, $form) {
  if (!is_numeric($element['#value'])) {
    form_error($element, t('Number of recomended content must be a number'));
  }
}
