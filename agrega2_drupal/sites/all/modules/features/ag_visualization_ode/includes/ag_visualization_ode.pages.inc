<?php
/**
 * @file
 * Autocomplete callbacks.
 */

/**
 * Callback that manage certificate ode operations.
 */
function ag_visualization_ode_manage_certificate($node, $op, $type = 'ajax') {
  $wrapper = entity_metadata_wrapper('node', $node);

  switch ($op) {
    case 'certificate':
      $status = 1;
      $message = t('ODE certified successfully');
      $message_type = 'status';
      break;
    case 'delete-certificate':
      $status = 0;
      $message = t('Removed ode certification successfully');
      $message_type = 'status';
      break;
    default:
      $status = FALSE;
      $message_type = 'error';
  }

  //Save changes
  if ($status !== FALSE) {
    $wrapper->field_certified->set($status);
    $wrapper->save();
  }

  // Build the message render array:
  $messaje_output = '<div class="message-$message_type">' . $message . '</div>';
  // Deliver de Ajax response
  if ($type == 'ajax') {
    $commands = array();
    $certificate_link = ag_visualization_ode_certificate_link($node);

    $commands[] = ajax_command_replace("#certificate-ode-" . $node->nid, $certificate_link);
    $commands[] = ajax_command_append("#certificate-ode-" . $node->nid, $messaje_output);

    //Add or quit certified icon
    if ($status === 1) {
      $icon_link = l(t('Quality accredited by INTEF') , 'javascript:', array('external' => TRUE, 'attributes' => array('title' => t('Quality accredited by INTEF'))));

      $commands[] = ajax_command_append(".stats-info", '<div class="certified"><div class="value">' . $icon_link . '</div></div>');
    }
    else if ($status === 0) {
      $commands[] = ajax_command_remove(".certified");
    }

    $page = array('#type' => 'ajax', '#commands' => $commands);
    ajax_deliver($page);
  }
  else {
    drupal_set_message($message);
    drupal_goto('ode/view/' . $wrapper->field_solrid->raw());
  }
}

/**
 * TODO: Needs comments.
 *
 * @param string $string
 */
function ag_visualization_ode_autocomplete_fullname($string = '') {
  $matches = array();

  $query = db_select('profile', 'p');
  $query->join('users', 'u', 'u.uid = p.uid');
  $query->join('field_data_field_name_surname', 'ns', 'ns.entity_id = p.pid');
  $query->join('field_data_field_profile_name', 'pn', 'ns.field_name_surname_value = pn.entity_id');
  $query->join('field_data_field_profile_surname', 'ps', 'ns.field_name_surname_value = ps.entity_id');
  $query->join('field_data_field_edu_center_personal_fc', 'ecp', 'ecp.entity_id = p.pid');
  $query->join('field_data_field_educative_center', 'ec', 'ec.entity_id = ecp.field_edu_center_personal_fc_value');
  $query->join('field_data_field_locality_personal_fc', 'lp', 'lp.entity_id = p.pid');
  $query->join('field_data_field_locality', 'l', 'l.entity_id = lp.field_locality_personal_fc_value');
  $query->fields('u', array('mail', 'uid'));
  $query->fields('pn', array('field_profile_name_value'));
  $query->fields('ps', array('field_profile_surname_value'));
  $query->fields('ec', array('field_educative_center_value'));
  $query->fields('l', array('field_locality_value'));
  $query->addExpression("CONCAT(pn.field_profile_name_value, ' ', ps.field_profile_surname_value)", 'full_name');
  $query->havingCondition('full_name', '%' . db_like($string) . '%', 'LIKE');
  $query->range(0, 10);

  $result = $query->execute();

  foreach ($result as $user) {
    $matches[$user->full_name . ' (' . $user->uid . ')'] = strip_tags($user->full_name . ' (' . $user->field_locality_value . ')' . ' (' . $user->field_educative_center_value . ')');
  }

  drupal_json_output((object) $matches);
}

/**
 * Custom callback for autocomplete path.
 */
function ag_visualization_ode_autocomplete_email($string = '') {
  $matches = array();

  $query = db_select('profile', 'p');
  $query->join('field_data_field_name_surname', 'ns', 'ns.entity_id = p.pid');
  $query->join('field_data_field_profile_name', 'pn', 'ns.field_name_surname_value=pn.entity_id');
  $query->join('field_data_field_profile_surname', 'ps', 'ns.field_name_surname_value=ps.entity_id');
  $query->join('field_data_field_edu_center_personal_fc', 'efc', 'efc.entity_id=p.pid');
  $query->join('field_data_field_educative_center', 'ec', 'ec.entity_id = efc.field_edu_center_personal_fc_value');
  $query->join('field_data_field_locality_personal_fc', 'lfc', 'lfc.entity_id = p.pid');
  $query->join('field_data_field_locality', 'l', 'l.entity_id = lfc.field_locality_personal_fc_value');
  $query->join('users', 'u', 'p.uid=u.uid');
  $query->fields('u', array('mail', 'uid'));
  $query->fields('pn', array('field_profile_name_value'));
  $query->fields('ps', array('field_profile_surname_value'));
  $query->fields('ec', array('field_educative_center_value'));
  $query->fields('l', array('field_locality_value'));
  $query->havingCondition('u.mail', '%' . db_like($string) . '%', 'LIKE');
  $query->range(0, 10);

  $result = $query->execute();

  foreach ($result as $user) {
    $fullname = $user->field_profile_name_value . ' ' . $user->field_profile_surname_value;
    $matches[$user->mail] = strip_tags($fullname . ' (' . $user->field_locality_value . ')' . ' (' . $user->field_educative_center_value . ')');
  }

  drupal_json_output((object) $matches);
}
