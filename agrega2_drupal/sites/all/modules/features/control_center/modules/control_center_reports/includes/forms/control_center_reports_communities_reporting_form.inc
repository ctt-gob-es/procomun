<?php

############
### CORE ###
############
/**
 * Procomun - Communities reports.
 *
 * @param $form
 * @param $form_state
 * @return array $form
 */
function control_center_reports_communities_reporting_form($form, &$form_state) {
  $form = array();

  $form['apply_date'] = array(
    '#type' => 'checkbox',
    '#title' => t('Filter by date'),
    '#description' => t('This option lets you generate a report which shows the number of published
                        content in the communities in a date range.'),
    '#default_value' => FALSE,
  );

  $form['start_date'] = array(
    '#type' => 'date',
    '#title' => t('Start date'),
    '#states' => array(
      'visible' => array(
        ':input[name="apply_date"]' => array('checked' => TRUE)
      ),
      'required' => array(
        ':input[name="apply_date"]' => array('checked' => TRUE)
      ),
    ),
  );

  $form['end_date'] = array(
    '#type' => 'date',
    '#title' => t('End date'),
    '#states' => array(
      'visible' => array(
        ':input[name="apply_date"]' => array('checked' => TRUE)
      ),
      'required' => array(
        ':input[name="apply_date"]' => array('checked' => TRUE)
      ),
    ),
  );

  $form['submit'] = array(
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
function control_center_reports_communities_reporting_form_submit($form, &$form_state) {
  // Get data from database.
  $data_report = control_center_reports_communities_reporting_generate_report($form_state['values']);

  $report = array(
    // Report's header.
    'header' => control_center_reports_communities_reporting_generate_headers(),
    // Transforms the data in each row.
    'rows' => control_center_reports_communities_reporting_generate_rows($data_report),
  );

  // Generate CSV file.
  control_center_reports_render_report($report);
}

/**
 * Generate the necessary raw data for generate the CSV file.
 *
 * @param  array $filters Filters submitted by the form.
 * @return array $data Data related to the communities.
 */
function control_center_reports_communities_reporting_generate_report($filters) {
  $data = array();

  $data['general_data'] = _get_general_data();

  // Get data and combine with array general_data automatically
  _get_users_number($data);
  _get_admin_members($data);
  _get_communities($data);
  _get_comments($data);
  _get_likes($data);
  _get_content_published($filters, $data);

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
function control_center_reports_communities_reporting_generate_headers() {
  // Define the header function.
  $og_bundles = og_get_all_group_content_bundle();

  $header = array(
    t('Title'),
    t('Description'),
    t('Community type'),
    t('Owner'),
    t('Users number'),
    t('Administrators number'),
    t('Number of comments'),
    t('Number of "Likes"'),
  );

  foreach ($og_bundles['node'] as $key => $value) {
    $header += array($key => $value);
  }

  return $header;
}

/**
 * Generate the rows for the report.
 *
 * @param $data
 * @return array $rows
 */
function control_center_reports_communities_reporting_generate_rows($data) {
  $rows = array();

  foreach ($data as $key => $value) {
    foreach ($value as $k => $v) {
      $rows[] = array(
        $v->title,
        $v->body_value,
        $v->community_type,
        $v->name,
        $v->users_number,
        $v->admin_members,
        (isset($v->comments)) ? $v->comments : 0,
        (isset($v->likes)) ? $v->likes : 0,
        (isset($v->post)) ? $v->post : 0,
        (isset($v->debate)) ? $v->debate : 0,
        (isset($v->poll)) ? $v->poll : 0,
        (isset($v->event)) ? $v->event : 0,
        (isset($v->simplenews)) ? $v->simplenews : 0,
        (isset($v->question)) ? $v->question : 0,
        (isset($v->ode)) ? $v->ode : 0,
        (isset($v->recurso_de_aprendizaje)) ? $v->recurso_de_aprendizaje : 0,
        (isset($v->answer)) ? $v->answer : 0,
      );
    }
  }

  return $rows;
}


################
### DATABASE ###
################
/**
 * Get the title, description and the creator of the community.
 *
 * @return mixed
 */
function _get_general_data() {
  $sql = db_select('node', 'n');
  $sql->join('users', 'u', 'u.uid = n.uid');
  $sql->leftjoin('field_data_body', 'fdb', 'fdb.entity_id = n.nid');
  $query = $sql->fields('n', array('title'))
    ->fields('fdb', array('body_value'))
    ->fields('u', array('name'))
    ->fields('n', array('nid'))
    ->condition('n.type', 'social_network', '=')
    ->execute()
    ->fetchAllAssoc('nid');

  return $query;
}

/**
 * Get the number of users in the community.
 *
 * @param $data
 */
function _get_users_number($data) {
  $sql = 'SELECT ogm.gid, COUNT(u.uid) AS usuarios ';
  $sql .= 'FROM {og_membership} AS ogm ';
  $sql .= 'INNER JOIN {users} AS u ON ogm.etid = u.uid ';
  $sql .= "WHERE ogm.entity_type = 'user' ";
  $sql .= 'GROUP BY ogm.gid';
  $query = db_query($sql)->fetchAllKeyed(0,1);

  // Combine arrays general data with users numbers
  foreach($data['general_data'] as $key => $value) {
    foreach ($query as $k => $v) {
      if ($value->nid == $k) {
        $data['general_data'][$key]->users_number = $v;
      }
    }
  }
}

/**
 * Get administrators members.
 *
 * @param $data
 */
function _get_admin_members($data) {
  $sql = 'SELECT ogm.gid, count(ogm.etid) as admin_number ';
  $sql .= 'FROM {og_membership} AS ogm ';
  $sql .= 'INNER JOIN {og_users_roles} ogur ON ogur.uid = ogm.etid and ogur.gid = ogm.gid ';
  $sql .= 'INNER JOIN {og_role} ogr ON ogr.rid = ogur.rid ';
  $sql .= "WHERE ogm.entity_type = 'user' AND ogm.state = 1 ";
  $sql .= 'GROUP BY ogm.gid ';
  $query = db_query($sql)->fetchAllKeyed(0,1);

  foreach($data['general_data'] as $key => $value) {
    foreach ($query as $k => $v) {
      if ($value->nid == $k) {
        $data['general_data'][$key]->admin_members = $v;
      }
    }
  }
}

/**
 * Get communities number.
 *
 * @param $data
 * @internal param $filters
 */
function _get_communities($data) {
  $sql = 'SELECT ga.group_access_value AS group_access,
                 ogp.field_og_permissions_level_value AS level_permission,
                 ga.entity_id ';
  $sql .= 'FROM {field_data_group_access} ga ';
  $sql .= 'LEFT JOIN {field_data_field_og_permissions_level} ogp ON ogp.entity_id = ga.entity_id ';
  $query = db_query($sql)->fetchAll();

  // Combine arrays general data with users numbers.
  foreach ($data['general_data'] as $key => $value) {
    foreach ($query as $k => $v) {
      if ($value->nid == $v->entity_id) {
        if ($v->group_access == 0 && $v->level_permission == 0) {
          $data['general_data'][$key]->community_type = t('Public community');
        }
        elseif($v->group_access == 0 && $v->level_permission == 1) {
          $data['general_data'][$key]->community_type = t('Restricted community');
        }
        else {
          $data['general_data'][$key]->community_type = t('Private community');
        }
      }
    }
  }
}

/**
 * Get content published for each type of community.
 *
 * @param $filters
 * @param $data
 */
function _get_content_published($filters, $data) {
  // Get the existing nodes for each type of community.
  $bundles = og_get_all_group_content_bundle();
  $bundles = implode("','", array_keys($bundles['node']));

  // Create timestamp from start date indicated in the form
  $start_date = mktime(
    0,
    0,
    0,
    $filters['start_date']['month'],
    $filters['start_date']['day'],
    $filters['start_date']['year']
  );

  // Create timestamp from end date indicated in the form
  $end_date = mktime(
    0,
    0,
    0,
    $filters['end_date']['month'],
    $filters['end_date']['day']+1,
    $filters['end_date']['year']
  );

  $sql = 'SELECT ogm.gid, n.type, count(n.nid) AS nodes_number ';
  $sql .= 'FROM {node} n ';
  $sql .= 'INNER JOIN {node_type} nt ON n.type = nt.type ';
  $sql .= 'INNER JOIN {og_membership} ogm ON ogm.etid = n.nid ';
  $sql .= "WHERE n.type IN ('$bundles') AND ogm.entity_type = 'node' ";

  if ($filters['apply_date'] && isset($filters['start_date']) && isset($filters['end_date'])) {
    $sql .= "AND n.created BETWEEN $start_date AND $end_date ";
  }

  $sql .= 'GROUP BY ogm.gid, n.type ';
  $sql .= 'ORDER BY nt.name';
  $query = db_query($sql)->fetchAll();

  // Combine arrays general data with nodes number for each community.
  foreach ($data['general_data'] as $key => $value) {
    foreach ($query as $k => $v) {
      if ($value->nid == $v->gid) {
        $type = $v->type;
        $data['general_data'][$key]->$type = $v->nodes_number;
      }
    }
  }
}

/**
 * Get comments for each community.
 *
 * @param $data
 */
function _get_comments($data) {
  $sql = 'SELECT ogm.gid, count(c.nid) as comments ';
  $sql .= 'FROM {node} n ';
  $sql .= 'INNER JOIN {og_membership} ogm ON ogm.etid = n.nid ';
  $sql .= 'LEFT JOIN {comment} c ON c.nid = n.nid ';
  $sql .= "WHERE ogm.entity_type = 'node' ";
  $sql .= 'GROUP BY ogm.gid ';
  $query = db_query($sql)->fetchAllKeyed(0,1);

  // Combine arrays general data with users numbers
  foreach($data['general_data'] as $key => $value) {
    foreach ($query as $k => $v) {
      if ($value->nid == $k) {
        $data['general_data'][$key]->comments = $v;
      }
    }
  }
}

/**
 * Get number of likes for each community.
 *
 * @param $data
 */
function _get_likes($data) {
  $sql = 'SELECT ogm.gid, fc.count as likes ';
  $sql .= 'FROM {node} n ';
  $sql .= 'INNER JOIN {og_membership} ogm ON ogm.etid = n.nid ';
  $sql .= 'INNER JOIN {flag_counts} fc ON fc.entity_id = n.nid ';
  $sql .= "WHERE fc.fid = 2 AND ogm.entity_type = 'node' ";
  $sql .= 'GROUP BY ogm.gid ';
  $query = db_query($sql)->fetchAllKeyed(0,1);

  // Combine arrays general data with users numbers
  foreach($data['general_data'] as $key => $value) {
    foreach ($query as $k => $v) {
      if ($value->nid == $k) {
        $data['general_data'][$key]->likes = $v;
      }
    }
  }
}
