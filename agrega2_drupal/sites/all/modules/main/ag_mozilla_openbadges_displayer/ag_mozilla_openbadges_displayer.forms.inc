<?php
/**
 * Form to configure badges to show in profile user
 */
function ag_badges_config_form($form, &$form_state) {
  global $user;

  //Set breadcrumb
  $breadcrumbs = drupal_get_breadcrumb();
  $breadcrumbs[] = l(t('My profile'), 'user/' . $user->uid);
  $breadcrumbs[] = t('Configure your badges');
  drupal_set_breadcrumb($breadcrumbs);

  //Get user group badges
  $groups_data = ag_mozilla_openbadges_displayer_badges_groups($user);
  $options = array();

  if (!empty($groups_data)) {
    foreach($groups_data->groups as $group) {
      $options[$group->groupId] = $group->name;
    }
  }

  //Get saved options
  $default_value = ag_mozilla_openbadges_displayer_groups_display($user);

  $form['badges_groups'] = array(
    '#type' => 'checkboxes',
    '#options' => $options,
    '#title' => t('Select groups badges to show in profile'),
    '#default_value' => !empty($default_value) ? $default_value : array(),
  );

  //For empty options add text info and hide submit button
  if (empty($options)) {
    $form['nogroups'] = array(
      '#markup' => t('No groups to show'),
    );
  }

  if (!empty($options)) {
    $form['actions'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('form-actions')
      )
    );

    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save'),
    );
  }

  $form['return_link'] = array(
    '#markup' => l(t('Back to profile'), 'user/' . $user->uid),
  );

  return $form;
}

/**
 * Submit callback of ag_invite_users_form().
 */
function ag_badges_config_form_submit($form, &$form_state) {
  global $user;

  //Get user choices
  $new_groups = $form_state['values']['badges_groups'];

  //Get saved options
  $original_groups = ag_mozilla_openbadges_displayer_groups_display($user);

  //Check diferences between arrays
  if ($new_groups != $original_groups) {
    db_delete('mozilla_openbadges_groups')
      ->condition('uid', $user->uid)
      ->execute();

    $query = db_insert('mozilla_openbadges_groups')->fields(array('bgid', 'uid'));
    foreach ($new_groups as $bgid) {
      if (!empty($bgid)) {
        $query->values(array(
          'bgid' => $bgid,
          'uid' => $user->uid,
        ));
      }
    }
    $query->execute();
  }

  drupal_set_message(t('The changes have been saved. They will take effect in minutes.'));
}
