<?php


/**
 *
 */
function ag_invite_users_form($form, &$form_state) {
  // Get Gid form arguments:
  $gid = $form_state['build_info']['args'][0];

  $form['user_to_invite'] = array(
    '#type' => 'textfield',
    '#title' => t('Search in your follow users to invite to your community'),
    '#autocomplete_path' => "users/invite/$gid/following",
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('form-actions')
    )
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Invite'),
  );

  return $form;
}

/**
 * Submit callback of ag_invite_users_form().
 */
function ag_invite_users_form_submit($form, &$form_state) {
  global $user;

  // Explode user name and get uid and gid
  if (preg_match('!\(([^\)]+)\)!', $form_state['values']['user_to_invite'], $match)) {
    $user_uid = DrupalToolKit::getUserDataByName($match[1], array('uid'))
      ->uid;
  }
  else {
    $user_uid = null;
  }

  if (!empty($user_uid)) {
    $gid = $form_state['build_info']['args'][0];

    // Ensure that the user has not a membership asociated with this group:
    $membership = og_get_membership('node', $gid, 'user', $user_uid);
    if (!$membership) {
      // Creamos un og_membership con estado pendiente:
      $og_membership_options = array(
        'state' => OG_STATE_PENDING,
        'entity' => $user_uid,
      );
      og_group('node', $gid, $og_membership_options);

      // Create the new notification for the user targeted:
      $message = message_create('new_invitation_pending', array('uid' => $user->uid));
      $wrapper = entity_metadata_wrapper('message', $message);
      $wrapper->field_target_users->set(array($user_uid));
      $wrapper->field_social_network_ref->set($gid);
      $wrapper->field_message_status->set(0);
      $wrapper->save();

      // Show confirmation:
      drupal_set_message(t('Your invitation has been sent succesfully'));
    }
    else {
      // The user is has a membership already:
      drupal_set_message(t('This user is a member or has a pending subscription for this group'), 'error');
    }
  }
  else {
    // The user does not exists:
    drupal_set_message(t('This user does not exists in Procomun'), 'error');
  }

}

/**
 * This function defines the form for moderate communities
 */
function ag_section_social_netwok_moderate_community_form($form, &$form_state, $node) {
  $form = array();

  $form['accept'] = array(
    '#type' => 'submit',
    '#value' => t('Accept'),
    '#name' => 'accept',
    '#submit' => array('ag_section_social_netwok_submit_accept'),
  );

  $form['reject'] = array(
    '#type' => 'submit',
    '#value' => t('Reject'),
    '#name' => 'reject',
    '#submit' => array('ag_section_social_netwok_submit_reject'),
  );

  return $form;
}

/**
 * Accept the publication of a social network
 */
function ag_section_social_netwok_submit_accept($form, $form_state, $node) {
  //get the node
  $node = $form_state['build_info']['args'][0];
  //A wrapper to handle the node
  $wrapper = entity_metadata_wrapper('node', $node);
  //Set published the node
  $wrapper->status->set(1);
  //Set status to accepted (2)
  $wrapper->field_social_network_status->set(2);
  //Change the status in the orchestrator
  $solrId = $wrapper->field_solrid->value();
  $OS_orchestrator_inyection = new OS_orchestrator_inyection();
  list($status, $result) = $OS_orchestrator_inyection->PublishDocument($solrId);
  if ($status == 1){
    //save the node
    $wrapper->save();
    //Display a message with the result
    drupal_set_message(t('The community has been accepted successfully.'));
    //Create a new notification
    $message = message_create('community_accepted', array('uid' => $wrapper->author->uid->value()));
    $message_wrapper = entity_metadata_wrapper('message', $message);
    $message_wrapper->field_social_network_ref->set($node->nid);
    $message_wrapper->field_target_users->set(array($wrapper->author->uid->value()));
    $message_wrapper->field_message_status->set(0);
    $message_wrapper->save();
  }
  else {
    //Display a fail message
    drupal_set_message(t('There was a problem while accepting community. Try again later.'));
  }


}

/**
 * Reject the publication of a social network
 */
function ag_section_social_netwok_submit_reject($form, $form_state) {
  //get the node
  $node = $form_state['build_info']['args'][0];
  //A wrapper to handle the node
  $wrapper = entity_metadata_wrapper('node', $node);
  //Set unpublished the node
  $wrapper->status->set(0);
  //Set status to rejected (1)
  $wrapper->field_social_network_status->set(1);
  //Change the status in the orchestrator
  $solrId = $wrapper->field_solrid->value();
  $OS_orchestrator_inyection = new OS_orchestrator_inyection();
  list($status, $result) = $OS_orchestrator_inyection->UnpublishDocument($solrId);
  if ($status == 1){
    //save the node
    $wrapper->save();
    //Display a message with the result
    drupal_set_message(t('The community has been rejected successfully.'));

    //Create a new notification
    $message = message_create('community_rejected', array('uid' => $wrapper->author->uid->value()));
    $message_wrapper = entity_metadata_wrapper('message', $message);
    $message_wrapper->field_social_network_ref->set($node->nid);
    $message_wrapper->field_target_users->set(array($wrapper->author->uid->value()));
    $message_wrapper->field_message_status->set(0);
    $message_wrapper->save();
  }
  else {
    //Display a fail message
    drupal_set_message(t('There was a problem while rejecting community. Try again later.'));
  }

}
