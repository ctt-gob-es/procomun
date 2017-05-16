<?php

############
### CORE ###
############
/**
 * Procomun - General reports.
 *
 * @param $form
 * @param $form_state
 * @return array $form
 */
function control_center_reports_procomun_reporting_form($form, &$form_state) {
  $form = array();

  $form['filter_group'] = array(
    '#type' => 'fieldset',
    '#title' => t('Filters group'),
  );

  $form['filter_group']['types'] = array(
    '#type' => 'checkbox',
    '#title' => t('Break down by content type'),
    '#description' => t('Allow get reports filtering by content type.'),
    '#default_value' => FALSE,
  );

  $form['filter_group']['community_type'] = array(
    '#type' => 'checkbox',
    '#title' => t('Break down by community type'),
    '#description' => t('Allow get reports filtering by community type.'),
    '#default_value' => FALSE,
  );

  $form['filter_group']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Get report'),
  );

  return $form;
}

/**
 * Submit reports.
 *
 * @param $form
 * @param $form_state
 */
function control_center_reports_procomun_reporting_form_submit($form, &$form_state) {
  // Get data from database.
  $data_report = control_center_reports_procomun_reporting_generate_report($form_state['values']);

  $report = array(
    // Report's header.
    'header' => control_center_reports_procomun_reporting_generate_headers(),
    // Transforms the data in each row.
    'rows' => control_center_reports_procomun_reporting_generate_rows($data_report),
  );

  // Generate CSV file.
  control_center_reports_render_report($report);
}

/**
 * Generate the necessary raw data for generate the CSV file.
 *
 * @param  array $filters Filters submitted by the form.
 * @return array $data Data related with Procomun.
 */
function control_center_reports_procomun_reporting_generate_report($filters) {
  $data = array();

  $data['organizations'] = _get_organizations();
  $data['users'] = _get_users();
  $data['comments'] = _get_comments();
  $data['likes'] = _get_likes();
  $data['communities'] = _get_communities($filters);
  $data['content_published'] = _get_content_published($filters);

  return $data;
}


#################
### SHOW DATA ###
#################
/**
 * Report's headers.
 *
 * @return array $header Array with the headers array.
 */
function control_center_reports_procomun_reporting_generate_headers() {
  // Define the header function.
  $header = array(t('INDICATOR'), t('VALUE'));

  return $header;
}

/**
 * Generate the rows for the report.
 *
 * @param $data
 * @return array $rows
 */
function control_center_reports_procomun_reporting_generate_rows($data) {
  $rows = array();

  $orchestrator = new OS_orchestrator_selection();
  $service = $orchestrator->multipleSelectionOde('ODE');

  foreach ($data as $key => $value) {
    switch ($key) {
      case 'organizations':
        $rows[] = array(t('Organizations number'), $value['expression']);
        break;

      case 'users':
        $rows[] = array(t('Users number'), $value['expression']);
        break;

      case 'comments':
        $rows[] = array(t('Number of comments'), $value['comments']);
        break;

      case 'likes':
        $rows[] = array(t('Number of "Likes"'), $value['likes']);
        break;

      case 'communities':
        foreach ($value as $k => $v) {
          if ($v->group_access == '0' && $v->level_permission == '0') {
            $rows[] = array(t('Public communities'), $v->communities_number);
          }
          elseif ($v->group_access == '0' && $v->level_permission == '1') {
            $rows[] = array(t('Restricted communities'), $v->communities_number);
          }
          elseif ($v->group_access == '1') {
            $rows[] = array(t('Private communities'), $v->communities_number);
          }
          else {
            $rows[] = array(t('Communities'), $v->communities_number);
          }
        }
        break;

      case 'content_published':
        array_push($rows, array(
          array(
            'data' => t('CONTENT PUBLISHED'),
            'colspan' => 2,
          ),
        ));
        foreach ($value as $k => $v) {
          if (isset($v->total)) {
            $rows[] = array(t('Total'), $v->nodes_number+$service[0]);
          } else {
            if ($v->content_type == 'Recurso de aprendizaje') {
              $rows[] = array($v->content_type, $service[0]);
            } else {
              $rows[] = array($v->content_type, $v->nodes_number);
            }
          }
        }
        break;
    }
  }

  return $rows;
}


################
### DATABASE ###
################
/**
 * Get organizations number.
 *
 * @return mixed
 */
function _get_organizations() {
  $sql = db_select('users', 'u');
  $sql->join('users_roles', 'ur', 'u.uid = ur.uid');
  $query = $sql->fields('u', array('uid'))
    ->condition('ur.rid', 4, '=')
    ->condition('u.status', 1, '=')
    ->countQuery()
    ->execute()
    ->fetchAssoc();

  return $query;
}

/**
 * Get users number.
 *
 * @return mixed
 */
function _get_users() {
  $sql = db_select('users', 'u');
  $sql->leftjoin('users_roles', 'ur', 'u.uid = ur.uid');

  // Multiple conditions for calculate users number.
  $db_or = db_or();
  $db_or->condition('ur.rid', 4, '!=');
  $db_or->condition('ur.rid');
  $sql->condition($db_or);
  $sql->condition('u.status', 1, '=');

  $query = $sql->fields('u', array('uid'))
    ->condition('u.uid', 0, '!=')
    ->countQuery()
    ->execute()
    ->fetchAssoc();

  return $query;
}

/**
 * Get comments number.
 *
 */
function _get_comments() {
  $sql = 'SELECT COUNT(c.nid) AS comments ';
  $sql .= 'FROM {node} n ';
  $sql .= 'INNER JOIN {og_membership} ogm ON ogm.etid = n.nid ';
  $sql .= 'LEFT JOIN {comment} c ON c.nid = n.nid ';
  $sql .= "WHERE ogm.entity_type = 'node' and n.status = :published";
  $query = db_query($sql, array(':published' => NODE_PUBLISHED))->fetchAssoc();

  return $query;
}

/**
 * Get number of likes.
 *
 */
function _get_likes() {
  $sql = 'SELECT COUNT(fc.count) AS likes ';
  $sql .= 'FROM {node} n ';
  $sql .= 'INNER JOIN {og_membership} ogm ON ogm.etid = n.nid ';
  $sql .= 'INNER JOIN {flag_counts} fc ON fc.entity_id = n.nid ';
  $sql .= "WHERE fc.fid = 2 AND ogm.entity_type = 'node' and n.status = :published";
  $query = db_query($sql, array(':published' => NODE_PUBLISHED))->fetchAssoc();

  return $query;
}

/**
 * Get communities number.
 *
 * @param $filters
 * @return mixed
 */
function _get_communities($filters) {
  $sql = 'SELECT count(n.nid) AS communities_number ';
  if ($filters['community_type']) {
    $sql = 'SELECT ga.group_access_value AS group_access,
                 ogpl.field_og_permissions_level_value AS level_permission,
                 count(n.nid) AS communities_number ';
  }
  $sql .= 'FROM {node} n ';
  $sql .= 'INNER JOIN {field_data_group_access} ga ON ga.entity_id = n.nid ';
  $sql .= 'LEFT JOIN {field_data_field_og_permissions_level} ogpl ON ogpl.entity_id = ga.entity_id ';
  $sql .= "WHERE n.type = 'social_network' AND n.status = :published";

  if ($filters['community_type']) {
    $sql .= 'GROUP BY ga.group_access_value, ogpl.field_og_permissions_level_value';
  }
  
  $query = db_query($sql, array(':published' => NODE_PUBLISHED))->fetchAll();

  return $query;
}

/**
 * Get nodes.
 *
 * @param $filters
 * @return mixed
 */
function _get_content_published($filters) {
  $sql = 'SELECT nt.name AS content_type, COUNT(n.nid) AS nodes_number ';
  $sql .= 'FROM {node} n ';
  $sql .= 'RIGHT JOIN {node_type} nt ON n.type = nt.type ';
  $sql .= 'WHERE n.status = :published ';

  if ($filters['types']) {
    $sql .= 'GROUP BY nt.name';
  } else {
    $sql .= "AND n.type != 'ode'";
  }

  $query = db_query($sql, array(':published' => NODE_PUBLISHED))->fetchAll();

  if (!$filters['types']) {
    $query[0]->total = $filters['types'];
  }

  return $query;
}