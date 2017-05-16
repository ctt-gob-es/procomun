<?php

/**
 * Return users interactions
 */
function _recommendations_users_interactions_retrieve($timestamp, $limit) {
  
  $return = array();
  
  $x = 0;

  if (empty($timestamp) || !is_numeric($timestamp)) return t('The time stamp entered is incorrect');
  else $timestamp = check_plain($timestamp);
  
  if (!empty($limit) && !is_numeric($limit)) $limit = '0';
  
  #Mapeo de campos DRUPAL => ORQUESTADOR
  $solr_types_correlation = variable_get('ag_solr_content_types_names',array());

  #Favorites & Likes
  $query = 'SELECT fl.flagging_id, fd.field_solrid_value as entity_id, fd_user.field_solrid_value as user_id, n.type, fl.timestamp, f.name FROM {flagging} fl 
            INNER JOIN {node} n ON (n.nid = fl.entity_id AND n.status = :node_status) 
            INNER JOIN {flag} f ON (f.fid = fl.fid AND (f.name = :type_1 OR f.name = :type_2)) 
            INNER JOIN {field_data_field_solrid} fd ON (fd.entity_id = fl.entity_id AND fd.entity_type = :entity_type) 
            INNER JOIN {profile} p ON (p.uid = fl.uid AND p.type = :type_profile) 
            INNER JOIN {field_data_field_solrid} fd_user ON (fd_user.entity_id = p.pid AND fd_user.entity_type = :entity_type_user) 
            WHERE fl.timestamp >= :timestamp ';
  $result = db_query($query, array(':node_status' => NODE_PUBLISHED, ':type_1' => 'favorite', ':type_2' => 'like', ':entity_type' => 'node', ':type_profile' => 'datos_personales', ':entity_type_user' => 'profile2', ':timestamp' => $timestamp));

  foreach($result as $record) {
    $return[$x]['uid'] = $record->user_id;
    $return[$x]['action'] = $record->name;
    $return[$x]['type'] =  $solr_types_correlation[$record->type];
    $return[$x]['id'] = $record->entity_id;
    $return[$x]['score'] = '';
    $return[$x]['timestamp'] = $record->timestamp;
    
    $x++;
  }
  
  #Content viewed
  $query = 'SELECT n.type, fd.field_solrid_value as entity_id, fd_user.field_solrid_value as user_id, nv.timestamp FROM {nodeviewcount} nv 
            INNER JOIN {node} n ON (n.nid = nv.nid AND n.status = :node_status) 
            INNER JOIN {field_data_field_solrid} fd ON (fd.entity_id = nv.nid AND fd.entity_type = :entity_type) 
            INNER JOIN {profile} p ON (p.uid = nv.uid AND p.type = :type_profile) 
            INNER JOIN {field_data_field_solrid} fd_user ON (fd_user.entity_id = p.pid AND fd_user.entity_type = :entity_type_user) 
            WHERE nv.timestamp >= :timestamp ';
  $result = db_query($query, array(':node_status' => NODE_PUBLISHED, ':entity_type' => 'node', ':type_profile' => 'datos_personales', ':entity_type_user' => 'profile2', ':timestamp' => $timestamp));

  foreach($result as $record) {
    $return[$x]['uid'] = $record->user_id;
    $return[$x]['action'] = 'view';
    $return[$x]['type'] = $solr_types_correlation[$record->type];
    $return[$x]['id'] = $record->entity_id;
    $return[$x]['score'] = '';
    $return[$x]['timestamp'] = $record->timestamp;
    
    $x++;    
  }
  
  #Shared content
  $query = 'SELECT n.type, fd.field_solrid_value as entity_id, fd_user.field_solrid_value as user_id, rsc.timestamp FROM {recommendations_shared_content} rsc 
            INNER JOIN {node} n ON (n.nid = rsc.nid AND n.status = :node_status) 
            INNER JOIN {field_data_field_solrid} fd ON (fd.entity_id = rsc.nid AND fd.entity_type = :entity_type) 
            INNER JOIN {profile} p ON (p.uid = rsc.uid AND p.type = :type_profile) 
            INNER JOIN {field_data_field_solrid} fd_user ON (fd_user.entity_id = p.pid AND fd_user.entity_type = :entity_type_user) 
            WHERE rsc.timestamp >= :timestamp ';
  $result = db_query($query, array(':node_status' => NODE_PUBLISHED, ':entity_type' => 'node', ':type_profile' => 'datos_personales', ':entity_type_user' => 'profile2', ':timestamp' => $timestamp));

  foreach($result as $record) {
    $return[$x]['uid'] = $record->user_id;
    $return[$x]['action'] = 'shared';
    $return[$x]['type'] = $solr_types_correlation[$record->type];
    $return[$x]['id'] = $record->entity_id;
    $return[$x]['score'] = '';
    $return[$x]['timestamp'] = $record->timestamp;
    
    $x++;    
  }  
 
  #Comments
  $query = 'SELECT n.type, fd.field_solrid_value as entity_id, fd_user.field_solrid_value as user_id, c.created FROM {comment} c 
            INNER JOIN {node} n ON (n.nid = c.nid AND n.status = :node_status) 
            INNER JOIN {field_data_field_solrid} fd ON (fd.entity_id = c.nid AND fd.entity_type = :entity_type) 
            INNER JOIN {profile} p ON (p.uid = c.uid AND p.type = :type_profile) 
            INNER JOIN {field_data_field_solrid} fd_user ON (fd_user.entity_id = p.pid AND fd_user.entity_type = :entity_type_user) 
            WHERE c.created >= :timestamp ';
  $result = db_query($query, array(':node_status' => NODE_PUBLISHED, ':entity_type' => 'node', ':type_profile' => 'datos_personales', ':entity_type_user' => 'profile2', ':timestamp' => $timestamp));

  foreach($result as $record) {
    $return[$x]['uid'] = $record->user_id;
    $return[$x]['action'] = 'comment';
    $return[$x]['type'] = $solr_types_correlation[$record->type];
    $return[$x]['id'] = $record->entity_id;
    $return[$x]['score'] = '';
    $return[$x]['timestamp'] = $record->created;
    
    $x++;
  }    
  
  #Votes
  $query = 'SELECT n.type, fd.field_solrid_value as entity_id, fd_user.field_solrid_value as user_id, vv.value, vv.timestamp FROM {votingapi_vote} vv 
            INNER JOIN {node} n ON (n.nid = vv.entity_id AND n.status = :node_status) 
            INNER JOIN {field_data_field_solrid} fd ON (fd.entity_id = vv.entity_id AND fd.entity_type = :entity_type) 
            INNER JOIN {profile} p ON (p.uid = vv.uid AND p.type = :type_profile) 
            INNER JOIN {field_data_field_solrid} fd_user ON (fd_user.entity_id = p.pid AND fd_user.entity_type = :entity_type_user) 
            WHERE vv.timestamp >= :timestamp ';
  $result = db_query($query, array(':node_status' => NODE_PUBLISHED, ':entity_type' => 'node', ':type_profile' => 'datos_personales', ':entity_type_user' => 'profile2', ':timestamp' => $timestamp));

  foreach($result as $record) {
    $return[$x]['uid'] = $record->user_id;
    $return[$x]['action'] = 'score';
    $return[$x]['type'] = $solr_types_correlation[$record->type];
    $return[$x]['id'] = $record->entity_id;
    $return[$x]['score'] = $record->value;
    $return[$x]['timestamp'] = $record->timestamp;
    
    $x++;
  }    
  
  $return = ($limit) ? array_slice($return, 0, $limit) : $return;
  
  return $return;
}
