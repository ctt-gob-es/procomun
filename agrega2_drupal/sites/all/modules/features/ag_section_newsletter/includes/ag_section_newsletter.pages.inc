<?php

/**
 * Callback that manage subscriptions to newsletter.
 */
function ag_section_newsletter_manage_newsletter_subscriptions($group_id, $op, $newsletter_id, $user, $type = 'ajax') {

  switch ($op) {
    case 'subscribe':
      $status = simplenews_subscribe($user->mail, $newsletter_id, FALSE, 'website', '');
      $message = t('You have been subscribed successfully');
      break;
    case 'unsubscribe':
      $status = simplenews_unsubscribe($user->mail, $newsletter_id, FALSE, 'website');
      $message = t('You have been unsubscribed successfully');
      break;
  }

  if (!isset($status) || !$status) {
    $message = t('Sorry but your action has failed, may be you are already
      subscribed/unsubscribed for this newsletter');
  }

  // Build the message render array:
  $message_status = (isset($status) && $status) ? 'status' : 'error';
  $messaje_output = '<div class="message-' . $message_status . '">' . $message . '</div>';
  // Deliver de Ajax response
  if ($type == 'ajax') {
    $commands = array();
    $newsletter_wrapper = ag_section_newsletter_retrieve_subscribe_user_link($group_id, $user);

    $commands[] = ajax_command_replace("#newsletter-notifications-$user->uid",
      render($newsletter_wrapper));
    $commands[] = ajax_command_prepend("#newsletter-notifications-$user->uid", $messaje_output);

    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    drupal_set_message($message, $message_status);
    drupal_goto('node/' . $group_id);
  }
}

/**
 * Retrieve the newsletters for a given group.
 * This is a clone of simplenews_admin_newsletter_issues form simplenews module
 * but filter by $group_id.
 */
function ag_section_newsletter_admin_newsletter_issues($form, &$form_state, $gid) {
  module_load_include('inc', 'simplenews', 'includes/simplenews.admin');

  // Add the link for new newsletters:
  $form['newsletter_new'] = array(
    '#prefix' => '<div class="new-newsletter-link">',
    '#markup' => l(t('Create a new newsletter'), "node/$gid/ag_section_newsletter/new"),
    '#suffix' => '</div>',
  );

  // load the table with the newsletters filters by gid:
  $form['admin'] = ag_section_newsletter_admin_issues($gid);

  return $form;
}

/**
 * Menu callback: subscription administration.
 */
function ag_section_newsletter_admin_subscription($form, &$form_state, $gid) {
  module_load_include('inc', 'simplenews', 'includes/simplenews.admin');
  $form['admin'] = ag_section_newsletter_subscription_list_form($gid);
  return $form;
}

/**
 * Retrieve a full table sort form with all newsletter of a group.
 * @param  $entity $group entity object
 */
function ag_section_newsletter_admin_issues ($gid) {
   // Build an 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );
  $options = array();
  foreach (module_invoke_all('simplenews_issue_operations') as $operation => $array) {
    $options[$operation] = $array['label'];
  }
  /*  $form['options']['operation'] = array(
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => 'activate',
    );*/

  $form['options']['operation'] = array(
    '#type' => 'hidden',
    '#value' => 'activate',
  );

  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send selected newsletters'),
    '#submit' => array('simplenews_admin_issues_submit'),
    '#validate' => array('simplenews_admin_issues_validate'),
  );

  if (variable_get('simplenews_last_cron', '')) {
    $form['last_sent'] = array(
      '#markup' => '<p class="simplenews-last-cron">' . format_plural(variable_get('simplenews_last_sent', 0), 'Last batch: 1 mail sent at !time.', 'Last batch: !count mails sent at !time.', array('!time' => format_date(variable_get('simplenews_last_cron', ''), 'small'), '!count' => variable_get('simplenews_last_sent', 0))) . "</p>\n",
    );
  }
  // Table header. Used as tablesort default
  $header = array(
    'title' => array(
      'data' => t('Title'),
      'specifier' => 'title',
      'type' => 'property',
     ),
    'newsletter' => array(
      'data' => t('Newsletter'),
      'specified' => array(
        'field' => variable_get('simplenews_newsletter_field', 'simplenews_newsletter'),
        'column' => 'target_id',
      ),
      'type' => 'field',
    ),
    'created' => array(
      'data' => t('Created'),
      'specifier' => 'created',
      'sort' => 'desc',
      'type' => 'property',
    ),
    'published' => array('data' => t('Published')),
    'sent' => array('data' => t('Sent')),
    'subscribers' => array('data' => t('Subscribers')),
    'operations' => array('data' => t('Operations')),
  );

  $query = new EntityFieldQuery();
  simplenews_build_issue_filter_query($query);
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->tableSort($header)
    ->entityCondition('bundle', simplenews_get_content_types())
    ->fieldCondition('og_group_ref', 'target_id', $gid)
    ->pager(30)
    ->execute();

  $nids = !empty($result['node']) ? array_keys($result['node']) : array();
  $options = array();

  module_load_include('inc', 'simplenews', 'includes/simplenews.mail');
  $categories = simplenews_newsletter_list();
  foreach (node_load_multiple($nids) as $node) {
    $subscriber_count = simplenews_count_subscriptions(simplenews_issue_newsletter_id($node));
    $pending_count = simplenews_count_spool(array('entity_id' => $node->nid, 'entity_type' => 'node'));
    $send_status = simplenews_issue_status($node) == SIMPLENEWS_STATUS_SEND_PENDING ? $subscriber_count - $pending_count : theme('simplenews_status', array('source' => 'sent', 'status' => simplenews_issue_status($node)));

    $options[$node->nid] = array(
      'title' => l($node->title, 'node/' . $node->nid),
      'newsletter' => simplenews_issue_newsletter_id($node) && isset($categories[simplenews_issue_newsletter_id($node)]) ? $categories[simplenews_issue_newsletter_id($node)] : t('- Unassigned -'),
      'created' => format_date($node->created, 'small'),
      'published' => theme('simplenews_status', array('source' => 'published', 'status' => $node->status)),
      'sent' => $send_status,
      'subscribers' => $subscriber_count,
      'operations' => l(t('edit'), 'node/' . $gid . '/ag_section_newsletter/' . $node->nid . '/edit', array('query' => drupal_get_destination())),
    );
  }

  $form['issues'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No newsletters available.'),
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}


/**
 * Menu callback: ag_section_newsletter subscription administration.
 *
 */
function ag_section_newsletter_subscription_list_form ($gid) {
  // Build an 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );
  $options = array();
  foreach (module_invoke_all('simplenews_subscription_operations') as $operation => $array) {
    $options[$operation] = $array['label'];
  }
  $form['options']['operation'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => 'activate',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#submit' => array('simplenews_subscription_list_form_submit'),
    '#validate' => array('simplenews_subscription_list_form_validate'),
  );

  // Table header. Used as tablesort default
  $header = array(
    'mail' => array('data' => t('Email'), 'field' => 'sn.mail', 'sort' => 'asc'),
    'username' => array('data' => t('Username'), 'field' => 'u.name'),
    'status' => array('data' => t('Status'), 'field' => 'sn.activated'),
    'language' => array('data' => t('Language'), 'field' => 'sn.language'),
    'operations' => array('data' => t('Operations')),
  );

  $query = db_select('simplenews_subscriber', 'sn')->extend('PagerDefault')->extend('TableSort');
  simplenews_build_subscription_filter_query($query);
  $query->leftJoin('users', 'u', 'sn.uid = u.uid');
  $query->innerJoin('simplenews_subscription', 'su', 'sn.snid = su.snid');
  $query->innerJoin('og_membership', 'om', 'om.etid = su.newsletter_id');
  $query->condition('om.entity_type', 'simplenews_newsletter');
  $query->condition('om.gid', $gid);
  $query->condition('su.status', SIMPLENEWS_SUBSCRIPTION_STATUS_SUBSCRIBED);
  $query->addField('u', 'name', 'name');
  $result = $query
    ->fields('sn', array('snid', 'activated', 'mail', 'uid', 'language'))
    ->limit(30)
    ->orderByHeader($header)
    ->execute();

  $options = array();
  $destination = drupal_get_destination();

  foreach ($result as $subscriber) {
    $operations = ag_section_newsletter_retrieve_subscribe_user_link($gid, $subscriber);
    $options[$subscriber->snid] = array(
      'mail' => check_plain($subscriber->mail),
      'username' => isset($subscriber->uid) ? l($subscriber->name, 'user/' . $subscriber->uid) : check_plain($subscriber->name),
      'status' => theme('simplenews_status', array('source' => 'activated', 'status' => $subscriber->activated)),
      'language' => check_plain($subscriber->language),
      'operations' => render($operations),
    );
  }

  $form['subscribers'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No subscribers available.'),
  );

  // Custom pager options
  $args = array('quantity' => 9,'tags' => array('<<','<','','>','>>'));

  $form['pager'] = array(
    // Calling theme('pager') directly so that it the first call after the
    // pager query executed above.
    '#markup' => theme('pager', $args),
  );

  return $form;
}

# # # # # # # # # # # # # # # # # #
# # Generate newsletter section # #
# # # # # # # # # # # # # # # # # #

/**
 * Callback that manage subscriptions to newsletter.
 */
function ag_section_newsletter_generate_newsletter_form($form, &$form_state, $community) {
  drupal_add_js(drupal_get_path('module', 'ag_section_newsletter') . '/js/hide_schedule.js');
  drupal_add_js('misc/tabledrag.js');

  // Flag content related nodes in newsletter edit load
  $newsletter_id = arg(3);
  if (empty($form_state['input'])) {
    global $user;
    $params = array(
      'gid' => $community,
    );
    _ag_section_newsletter_unflag_newsletter_contents($params);
    if (isset($newsletter_id) && is_numeric($newsletter_id)) {
      $newsletter = entity_load_single('node', $newsletter_id);
      if (!empty($newsletter) && $newsletter->type == 'simplenews' && !empty($newsletter->field_simplenews_content_ref)) {
        foreach ($newsletter->field_simplenews_content_ref[LANGUAGE_NONE] as $content_ref) {
          flag('flag', 'og_newsletter', $content_ref['target_id'], $user);
        }
      }
    }
  }

  $form['newsletter_id'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($newsletter_id) && is_numeric($newsletter_id) ? $newsletter_id : '',
  );

  // Newsletter title
  $form['newsletter_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Newsletter title'),
    '#required' => TRUE,
    '#default_value' => isset($newsletter->title_field[LANGUAGE_NONE][0]['value']) ? $newsletter->title_field[LANGUAGE_NONE][0]['value'] : '',
  );

  // Newsletter body
  $form['newsletter_body'] = array(
    '#type' => 'text_format',
    '#title' => t('Newsletter body'),
    '#format' => 'newsletter',
    '#default_value' => isset($newsletter->body[LANGUAGE_NONE][0]['value']) ? $newsletter->body[LANGUAGE_NONE][0]['value'] : '',
  );

  // Add scheduled newsletter fields from content type "Simplenews"
  $form['newsletter_scheduled_sending'] = [
    '#type' => 'fieldset',
    '#title' => t('Newsletter scheduled sending'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['newsletter_scheduled_sending']['field_simplenews_scheduled_send'] = [
    '#type' => 'checkbox',
    '#title' => t('Newsletter scheduled sending'),
    '#default_value' => (isset($newsletter) && $newsletter->field_simplenews_scheduled_send[LANGUAGE_NONE][0]['value'] == '1') ? TRUE : FALSE,
  ];

  // Workaround to add single field from an existing content type (in this case, simplenews)
  $tmpform = [];
  $tmpform_state = [];
  $tmpnode = new stdClass();
  $tmpnode->type = 'simplenews';

  field_attach_form('node', $tmpnode, $tmpform, $tmpform_state);
  $form['newsletter_scheduled_sending']['field_simplenews_scheduled_date'] = $tmpform['field_simplenews_scheduled_date'];
  // Force show this field. For unknown reasons, it doesn't load in forms occasionally
  $form['newsletter_scheduled_sending']['field_simplenews_scheduled_date']['#access'] = TRUE;
  $form_state['field']['field_simplenews_scheduled_date'] = $tmpform_state['field']['field_simplenews_scheduled_date'];

  $form['#tree'] = TRUE;

  // Load scheduled sending values in newsletter edit load
  if (isset($newsletter) && !empty($newsletter->field_simplenews_scheduled_date)) {
    $form['newsletter_scheduled_sending']['field_simplenews_scheduled_date'][LANGUAGE_NONE][0]['#default_value']['value'] = $newsletter->field_simplenews_scheduled_date[LANGUAGE_NONE][0]['value'];
  }

  // Unflag content with og_newsletter flag for reset content added to newsletter in creation form
  if (empty($form_state['input']) && !isset($newsletter)) {
    $params = array(
      'gid' => $community,
    );
    _ag_section_newsletter_unflag_newsletter_contents($params);
  }

  $group_id = $community;
  // Table of content that will send with the newsletter:
  $flagged_content = FlagDrupalToolKit::getFlaggedContentByOg('og_newsletter',
    $group_id)->fetchAllAssoc('entity_id');
  if (!empty($flagged_content)) {

    foreach($flagged_content as $content){
      $form['newsletter_content'][$content->entity_id]['id'] = array(
        '#type' => 'hidden',
        '#default_value' => $content->entity_id,
      );
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save changes'),
    '#name' => 'newsletter-submit'
  );

  return $form;
}

/**
 * Validate callback for ag_section_newsletter_generate_newsletter_form.
 * Check if scheduled sending date/time is greater than now.
 */
function ag_section_newsletter_generate_newsletter_form_validate($form, &$form_state) {
  if ($form_state['values']['newsletter_scheduled_sending']['field_simplenews_scheduled_send']) {
    if (!empty($form_state['values']['newsletter_scheduled_sending']['field_simplenews_scheduled_date'][LANGUAGE_NONE][0]['value'])) {
      $scheduled_datetime = new DateTime($form_state['values']['newsletter_scheduled_sending']['field_simplenews_scheduled_date'][LANGUAGE_NONE][0]['value']);
      $timestamp = $scheduled_datetime->getTimestamp();
      $current_time = REQUEST_TIME;
      if ($timestamp < $current_time) {
        form_set_error('newsletter_scheduled_sending][field_simplenews_scheduled_date', t('Newsletter scheduled date and time has already passed. Please, insert valid date and time values.'));
      }
    }
  }
}

/**
 * Submit callback for ag_section_newsletter_generate_newsletter_form.
 *
 * Create a new newsletter issue with the data from
 * ag_section_newsletter_generate_newsletter_form form.
 */
function ag_section_newsletter_generate_newsletter_form_submit($form, &$form_state) {
  // Obtaining newsletter related contents
  $newsletter_contents = array();

  $flagged_content = json_decode($_POST['content_ref_weight']);
  if (!empty($flagged_content)) {
    foreach ($flagged_content as $content) {
      $newsletter_contents[$content] = array(
        'id' => $content,
      );
    }
  }

  // Generate the newsletter issue
  $group_id = isset($form_state['build_info']['args'][0]) ? $form_state['build_info']['args'][0] : NULL;
  $params = array(
    'newsletter_id' => $form_state['values']['newsletter_id'],
    'title' => check_plain($form_state['values']['newsletter_title']),
    'body' => $form_state['values']['newsletter_body'],
    'related_content' => $newsletter_contents,
    'gid' => $group_id,
    'scheduled_send' => $form_state['values']['newsletter_scheduled_sending']['field_simplenews_scheduled_send'],
    'scheduled_date' => $form_state['values']['newsletter_scheduled_sending']['field_simplenews_scheduled_date'][LANGUAGE_NONE][0]['value'],
  );

  if ($newsletter = ag_section_newsletter_generate_newsletter($params, empty($params['newsletter_id']) ? 'new' : 'edit')) {
    // If all it's ok: Redirect and show success message:
    if (!empty($group_id)) {
      $form_state['redirect'] = "ag_section_newsletter/$group_id/simplenews";
    }
    if (empty($params['newsletter_id'])) {
      drupal_set_message(t('Newsletter created succesfully'));
    }
    else {
      drupal_set_message(t('Newsletter @title updated succesfully', array('@title' => $params['title'])));
    }
  }
}

/**
 * Auxiliary function that compare and order 2 elements by #weight element.
 */
function ag_section_newsletter_weight_arraysort($a, $b) {
  if (isset($a['weight']) && isset($b['weight'])) {
    return $a['weight'] < $b['weight'] ? -1 : 1;
  }
  return 0;
}
