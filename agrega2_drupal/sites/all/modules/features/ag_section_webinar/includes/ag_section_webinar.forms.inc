<?php
/**
 * @file
 * Setting up the configuration for webinar.
 */

include_once drupal_get_path('module', 'ag_section_webinar') . '/includes/wiziq-integration/vendor/autoload.php';
use mikemix\Wiziq;

/////////////
/// HOOKS ///
/////////////

/**
 * Implements hook_form_FORM_ID_alter() for webinar_node_form().
 */
function ag_section_webinar_form_webinar_node_form_alter(&$form, &$form_state, $form_id) {
  global $language;

  // Licenses: Comercial use and allow modifications only visible if user is author of resource.
  $form['field_comercial_use']['#states']['visible'] = array(
    ':input[name="field_original_author[und]"]' => array('value' => '1'),
  );
  $form['field_allow_modifications']['#states']['visible'] = array(
    ':input[name="field_original_author[und]"]' => array('value' => '1'),
  );

  // Configure license.
  $comercial_use = $form['field_comercial_use'][LANGUAGE_NONE]['#default_value'];
  $allow_modifications = $form['field_allow_modifications'][LANGUAGE_NONE]['#default_value'];

  $form['current_license'] = array(
    '#type' => 'item',
    '#markup' => ag_visualization_ode_get_license_link($allow_modifications, $comercial_use),
  );

  // Add to fieldset group_license.
  $form['#group_children']['current_license'] = 'group_license';

  // Default value for language.
  $has_current_language = isset($language->language);
  $has_form_language_field = isset($form['field_general_language'][LANGUAGE_NONE]);
  if ($has_current_language && $has_form_language_field && empty($form['field_general_language'][LANGUAGE_NONE]['#default_value'])) {
    if (isset($form['field_general_language'][LANGUAGE_NONE]['#options']) && array_key_exists($language->language, $form['field_general_language'][LANGUAGE_NONE]['#options'])) {
      $form['field_general_language'][LANGUAGE_NONE]['#default_value'] = $language->language;
    }
  }

  // Create label for field_record_webinar.
  $form['field_record_webinar']['record_label'] = array(
    '#type' => 'markup',
    '#prefix' => '<span class="record-label">',
    '#markup' => t('Persistence'),
    '#suffix' => '</span>',
    '#weight' => 0,
  );

  // Hide field_recording_url.
  $form['field_recording_url']['#access'] = FALSE;

  // Node edit mode.
  if ($form['nid']['#value']) {
    // Hide webinar specific fields edition once it has begun or has ended.
    $current_time = time();
    $webinar_date = webinar_date_timestamp($form['#node']);

    if ($current_time >= $webinar_date) {
      $form['field_class_date']['#access'] = FALSE;
      $form['field_duracion']['#access'] = FALSE;
      $form['field_record_webinar']['#access'] = FALSE;
    }
  }

  // Add custom validation.
  $form['#validate'][] = 'ag_section_webinar_virtual_class_creation_validate';
}

/**
 * Validate virtual class creation in WizIQ account and create content if there
 * are no errors.
 *
 * Callback for ag_section_webinar_form_webinar_node_form_alter().
 *
 * @param array $form
 *   Contains the structure of the form.
 * @param array $form_state
 *   Contains the state of the form.
 */
function ag_section_webinar_virtual_class_creation_validate(&$form, &$form_state) {
  $errors = form_get_errors();

  if (!$errors && $form_state['values']['op'] != t('Delete')) {
    global $user;
    $values = $form_state['values'];

    $title = $values['title_field'][LANGUAGE_NONE][0]['value'];
    $id = $user->uid;
    $name = ag_section_profile_users_get_name_surname_cached($user->uid);
    $language = $values['field_general_language'][LANGUAGE_NONE][0]['value'];
    $culture_name = $language . '-' . strtoupper($language);
    $limit = 300;
    $return_url = 'https://procomun.educalab.es';
    $duration = $values['field_duracion'][LANGUAGE_NONE][0]['value'];
    $timezone = $values['field_class_date'][LANGUAGE_NONE][0]['timezone'];
    $webinar_date = $values['field_class_date'][LANGUAGE_NONE][0]['value'];

    // Change date format to WizIQ class creation date format.
    $format_date = 'm/d/Y H:i:s';
    $webinar_date = DateTime::createFromFormat('Y-m-d H:i:s', $webinar_date, new DateTimeZone($timezone));
    $date = format_date($webinar_date->getTimestamp(), 'custom', $format_date);

    // WizIQ api connection.
    $api = wiziq_api_connection();

    // Node add mode.
    if (!$form['nid']['#value']) {
      // Create virtual class.
      try {
        $classroom = Wiziq\Entity\Classroom::build($title, new \DateTime($date))
          ->withPresenter($id, $name)
          ->withLanguageCultureName($culture_name)
          ->withAttendeeLimit($limit)
          ->withCreateRecording(TRUE)
          ->withReturnUrl($return_url)
          ->withDuration($duration)
          ->withTimeZone($timezone);

        $response  = $api->create($classroom);

      } catch (Wiziq\Common\Api\Exception\CallException $e) {
        form_set_error('error', t('WizIQ error: ') . wiziq_error_translation($e));
      } catch (Wiziq\Common\Http\Exception\InvalidResponseException $e) {
        form_set_error('error', t('WizIQ error: ') . $e->getMessage());
      }

      // Manage response.
      if (isset($response) && !empty($response)) {
        // Update field_class_id.
        $form_state['values']['field_classid'][LANGUAGE_NONE][0]['value'] = $response['class_id'];
        // Update field_recording_url.
        $form_state['values']['field_recording_url'][LANGUAGE_NONE][0]['url'] = $response['recording_url'];
        // Update attendees list database table.
        try {
          $status = db_insert('webinar_attendees')
            ->fields(array(
              'uid' => $id,
              'classid' => $response['class_id'],
              'webinar_url' => $response['presenter_url'],
            ))
            ->execute();
        } catch (PDOException $e) {
          $status = 0;
        }

        // TODO: Manage DB insert error.
        if ($status == 0) {
          form_set_error('error', t('Database insert error: ') . $e->getMessage());
        }
      }
    }
    // Node edit mode.
    else {
      // Modify virtual class.
      try {
        $title = $values['title_field'][$values['language']][0]['value'];
        $classroom = Wiziq\Entity\Classroom::build($title, new \DateTime($date))
          ->forModify($form['#node']->field_classid[LANGUAGE_NONE][0]['value'])
          ->withLanguageCultureName($culture_name)
          ->withDuration($duration);

        $response  = $api->modify($classroom);

      } catch (Wiziq\Common\Api\Exception\CallException $e) {
        form_set_error('error', t('WizIQ error: ') . wiziq_error_translation($e));
      } catch (Wiziq\Common\Http\Exception\InvalidResponseException $e) {
        form_set_error('error', t('WizIQ error: ') . $e->getMessage());
      }

      // Manage response.
      if ($response != 'ok') {
        form_set_error('error', t('WizIQ error: Failed to update virtual class'));
      }
    }
  }
}

/////////////////
/// CALLBACKS ///
/////////////////

/**
 * WizIQ authentication.
 *
 * Callback for ag_section_webinar_virtual_class_creation_validate().
 *
 * @return object $api
 *   Return WizIQ manage object.
 */
function wiziq_api_connection() {
  $auth = new Wiziq\API\Auth('************************', '************');
  $gateway = new Wiziq\API\Gateway($auth);
  $api = new Wiziq\API\ClassroomApi($gateway);

  return $api;
}

/**
 * Retrieve a rendered array with the link to subscribe to webinar.
 *
 * @param int $class_id
 *   Virtual class identifier.
 * @param object $account
 *   User account object.
 *
 * @return array $subscribe_wrapper
 *   Return virtual class subscribe wrapper.
 */
function ag_section_webinar_retrieve_subscribe_user_link($class_id, $webinar_url, $account = NULL) {
  // If is not set $uid load the current user uid.
  if (!isset($account)) {
    global $user;
    $account = $user;
  }

  // Manage subscription button access.
  $node = menu_get_object();
  $node_groups = array();
  foreach ($node->og_group_ref[LANGUAGE_NONE] as $group) {
    $node_groups[] = $group['target_id'];
  }
  $user_groups = og_get_groups_by_user($account, 'node');
  $result = array_intersect($user_groups, $node_groups);
  $access = !empty($result) ? TRUE : FALSE;

  if (!empty($class_id) && ($access || !empty($webinar_url))) {
    // Define Ajax wrapper.
    $subscribe_wrapper = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => "subscribe-notifications-$account->uid",
        'class' => "subscribe-notification",
      ),
      '#weight' => '5',
    );

    if (empty($webinar_url)) {
      // Show the subscribe link.
      $subscribe_wrapper['content']['link'] = array(
        '#type' => 'link',
        '#title' => t('Subscribe to the webinar'),
        '#href' => "ag_section_webinar/subscribe/$class_id/$account->uid/nojs",
        '#options' => array(
          'attributes' => array(
            'class' => array('webinar-subscription'),
          ),
        ),
        '#ajax' => array(
          'wrapper' => "subscribe-notifications-$account->uid",
          'method' => 'html',
        ),
      );
    }
    else {
      // Show the login link.
      $subscribe_wrapper['content']['link'] = array(
        '#type' => 'link',
        '#title' => t('Login to the webinar'),
        '#href' => $webinar_url[0],
        '#options' => array(
          'external' => TRUE,
          'attributes' => array(
            'class' => array('webinar-login'),
            'target' => '_blank',
          ),
        )
      );
    }
  }

  return isset($subscribe_wrapper['content']) ? $subscribe_wrapper : array();
}

/**
 * Callback that manage subscriptions to webinar.
 *
 * TODO
 */
function ag_section_webinar_manage_webinar_subscriptions($op, $class_id, $user, $type = 'ajax') {

  switch ($op) {
    case 'subscribe':
      $id = $user->uid;
      $name = ag_section_profile_users_get_name_surname_cached($user->uid);
      $culture_name = $user->language . '-' . strtoupper($user->language);

      // WizIQ api connection.
      $api = wiziq_api_connection();

      try {
        $attendees   = Wiziq\Entity\Attendees::build()
          ->add($id, $name, $culture_name);

        $response = $api->addAttendeesToClass($class_id, $attendees);

      } catch (Wiziq\Common\Api\Exception\CallException $e) {
        form_set_error('error', t('WizIQ error: ') . $e->getMessage());
        $status = 0;
      } catch (Wiziq\Common\Http\Exception\InvalidResponseException $e) {
        form_set_error('error', t('WizIQ error: ') . $e->getMessage());
        $status = 0;
      }

      // Manage response.
      if (isset($response) && !empty($response)) {
        // Update attendees list database table.
        try {
          $status = db_insert('webinar_attendees')
            ->fields(array(
              'uid' => $id,
              'classid' => $class_id,
              'webinar_url' => $response[0]['url'],
            ))
            ->execute();
        } catch (PDOException $e) {
          $status = 0;
        }

        if ($status != 0) {
          $message = t('You have been subscribed successfully');
          $webinar_url[0] = $response[0]['url'];
        }
      }
      break;
  }

  if (!isset($status) || !$status) {
    $message = t('Sorry but your subscription for this webinar has failed. Try again later.');
  }

  // Build the message render array.
  $message_status = (isset($status) && $status) ? 'status' : 'error';
  $messaje_output = '<div class="message-' . $message_status . '">' . $message . '</div>';

  // Deliver Ajax response.
  if ($type == 'ajax') {
    $commands = array();
    $subscribe_wrapper = ag_section_webinar_retrieve_subscribe_user_link($class_id, $webinar_url, $user);

    $commands[] = ajax_command_replace("#subscribe-notifications-$user->uid",
      render($subscribe_wrapper));
    $commands[] = ajax_command_prepend("#subscribe-notifications-$user->uid",
      $messaje_output);

    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    drupal_set_message($message, $message_status);
  }
}

/**
 * Cancel class from WizIQ account.
 *
 * Callback for _orchestrator_services_delete_content().
 *
 * @param object $node
 *   Contains the node object.
 */
function wiziq_cancel_class($node) {
  // Prevent the class from being canceled once it has begun or has ended.
  $current_time = time();
  $webinar_date = webinar_date_timestamp($node);

  if ($current_time < $webinar_date) {
    // WizIQ api connection.
    $api = wiziq_api_connection();

    try {
      $api->cancel($node->field_classid[LANGUAGE_NONE][0]['value']);

    } catch (Wiziq\Common\Api\Exception\CallException $e) {
      form_set_error('error', t('WizIQ error: ') . $e->getMessage());
    } catch (Wiziq\Common\Http\Exception\InvalidResponseException $e) {
      form_set_error('error', t('WizIQ error: ') . $e->getMessage());
    }
  }
}

/**
 * Retrieve webinar date in timestamp format.
 *
 * Callback for wiziq_cancel_class().
 * Callback for hook_node_view().
 *
 * @param object $node
 *   Contains the node object.
 *
 * @return int $webinar_date
 *   Webinar date in timestamp format.
 */
function webinar_date_timestamp($node) {
  $date = $node->field_class_date[LANGUAGE_NONE][0]['value'];
  $timezone = $node->field_class_date[LANGUAGE_NONE][0]['timezone'];

  if (isset($date) && !empty($date) && isset($timezone) && !empty($timezone)) {
    $webinar_date = DateTime::createFromFormat('Y-m-d H:i:s', $date, new DateTimeZone($timezone));
    $webinar_date = $webinar_date->getTimestamp();
  }
  else {
    $webinar_date = 0;
  }

  return $webinar_date;
}

/**
 * Translate WizIQ error messages.
 *
 * Callback for ag_section_webinar_virtual_class_creation_validate().
 *
 * @param object $error
 *   Contains the WizIQ error object.
 *
 * @return string $error_msg
 *   Translated error message.
 */
function wiziq_error_translation($error) {
  $error_messages = array(
    '1003' => t('Specified time zone is not available.'),
    '1004' => t('Start datetime cannot precede current datetime.'),
    '1005' => t('Invalid start_time parameter.'),
    '1012' => t('A webinar is already scheduled on that date and time. Please try a different date and time.'),
    '1014' => t('title parameter is missing.'),
    '1019' => t('start_time parameter is missing.'),
    '1022' => t('Datetime is not in valid format.'),
    '1030' => t('presenter_email parameter is missing.'),
    '1031' => t('presenter_email is not valid.'),
    '1032' => t('You have already scheduled a class for the current time.'),
    '1043' => t('The language is invalid or unsupported in the VC.'),
    '1090' => t('extend_duration parameter is empty or invalid.'),
  );

  if ($error->getCode() == '1010') {
    $msg_var = explode(' ', $error->getMessage());
    $msg_var = $msg_var[4];
    $error_msg = t('Class duration cannot exceed @msg_var minutes.', array('@msg_var' => $msg_var));
  }
  else if ($error->getCode() == '1011') {
    $msg_var = explode(' ', $error->getMessage());
    $msg_var = $msg_var[4];
    $error_msg = t('Attendees cannot exceed @msg_var.', array('@msg_var' => $msg_var));
  }
  else {
    $error_msg = $error_messages[$error->getCode()];
  }

  return $error_msg;
}
