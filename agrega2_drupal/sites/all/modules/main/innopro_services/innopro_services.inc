<?php

/**
 * Return favorites interactions
 */
function _innopro_services_user_favorites($solrID_user) {

  $return['message'] = '';
  $return['status'] = false;
  $return['data'] = array();
 
  global $user;
  
  if ($user->uid == 0) {
    $return['message'] = t('You must login to consume this service');
  }
  
  else {
    #Get user idDrupal
    $user_uid = _innopro_services_get_idDrupal_user($solrID_user);
    
    if (!empty($user_uid)) {
      if ($user->uid != $user_uid) {
        $return['message'] = t('The requested user does not match the user session');
      }
      
      else {
        #Favorites
        $query = 'SELECT fl.flagging_id, fd.field_solrid_value as entity_id, fl.timestamp, f.name FROM {flagging} fl 
                  INNER JOIN {node} n ON (n.nid = fl.entity_id AND n.type = :tdc AND n.status = :node_status) 
                  INNER JOIN {flag} f ON (f.fid = fl.fid AND f.name = :type) 
                  INNER JOIN {field_data_field_solrid} fd ON (fd.entity_id = fl.entity_id AND fd.entity_type = :entity_type) 
                  WHERE fl.uid = :user_uid';
        $result = db_query($query, array(':tdc' => 'ode', ':node_status' => NODE_PUBLISHED, ':type' => 'favorite', ':entity_type' => 'node', ':user_uid' => $user_uid));
        
        if (count($result) > 0) {
          foreach($result as $record) {
            $return['data'][] = $record->entity_id;
          }  
          
          $return['status'] = true;          
          $return['message'] = (count($return['data']) > 0) ? t('The request was successful') : t('No results');
        }
        else {
          $return['message'] = t('A problem occurred during the execution of the data');
        }
        

      }
    }
    else {
      $return['message'] = t('The requested user does not exist');
    }
  }
  
  return $return;
}

/**
 * Return profile imagen from user
 */
function _innopro_services_user_image($solrID_user) {

  $return['message'] = '';
  $return['status'] = false;
  $return['data'] = array();

  #Get user idDrupal
  $user_uid = _innopro_services_get_idDrupal_user($solrID_user);
  
  if (!empty($user_uid)) {
    $user_profile = user_load($user_uid);
    $return['data'] = url('sites/default/files/pictures/' . $user_profile->picture->filename, array('absolute' => TRUE, 'language' => (object)array('language' => '')));
  }
  else {
    $return['message'] = t('The requested user does not exist');
  }
  
  return $return;
}

/**
 * Set like favorite a ODE
 */
function _innopro_services_user_set_favorite_ode($solrId_ODE, $solrID_user, $action)  {
  
  $return['message'] = '';
  $return['status'] = false;
  $return['data'] = array();
  
  global $user;
  
  if ($user->uid == 0) {
    $return['message'] = t('You must login to consume this service');
  }
  
  else {  
    #Get user idDrupal
    $user_uid = _innopro_services_get_idDrupal_user($solrID_user);
    
    if (!empty($user_uid)) {
      if ($user->uid != $user_uid) {
        $return['message'] = t('The requested user does not match the user session');
      }
      else {
        $return = ag_visualization_ode_flag_external($action, 'favorite', $solrId_ODE, $user_uid);
        $return['data'] = array();
      }
    }
    else {
      $return['message'] = t('The requested user does not exist');
    }    
    
  }
  return $return;
}

/**
 * Get list of categories
 */
function _innopro_services_categories($solrID_user) {
  
  $return['message'] = '';
  $return['status'] = false;
  $return['data'] = array();  
  
  #Get user idDrupal
  $user_uid = _innopro_services_get_idDrupal_user($solrID_user);
  if (!empty($user_uid)) {
    $myvoc = taxonomy_vocabulary_machine_name_load('categories');
    $tree = taxonomy_get_tree($myvoc->vid);
    foreach ($tree as $term) {
      $return['data'][] = $term->name;
    }    
    
    if (count($return['data']) > 0) {
      $return['status'] = true;  
      $return['message'] = t('Information has been received correctly');
    }
    else {
      $return['message'] = t('There was an error in the query information');
    }
  }
  else {
    $return['message'] = t('The requested user does not exist');
  }     
  
  return $return;
}

/**
 * Get list of highlighted resources
 */
function _innopro_services_highlighted_resources($solrID_user) {
  
  $return['message'] = '';
  $return['status'] = false;
  $return['data'] = array();  
  
  #agrega2_home_highlighted
  $view = views_get_view('agrega2_home_highlighted');
  $view->set_display('block');
  $view->execute();
  
  if (is_object($view)) {
    $x = 0;
    foreach($view->result as $key => $value) {
      $return['data'][$x]['title'] = $value->_field_data['nid']['entity']->title;
      $return['data'][$x]['solrid'] = $value->_field_data['nid']['entity']->field_solrid['und'][0]['value'];
      $x++;
    }
    //$return['data'] = $view->result;
    $return['status'] = true;  
    $return['message'] = t('Information has been received correctly');
  }
  
  else {
    $return['message'] = t('There was an error in the query information');
  }
  
  return $return;
}

/**
 * Get idDrupal from Solr Object
 */
function _innopro_services_get_idDrupal_user($solrid_user) {
  $user_uid = db_query('SELECT p.uid FROM {profile} p
                        INNER JOIN {field_data_field_solrid} fdfs ON (fdfs.entity_id = p.pid AND fdfs.field_solrid_value = :solrid)', 
                        array(':solrid' => $solrid_user))->fetch();
  return $user_uid->uid;
}

/**
 * Return user events
 */
function _innopro_services_user_events($solrID_user) {
  global $user;

  $return['message'] = '';
  $return['status'] = FALSE;
  $return['data'] = array();

  if ($user->uid == 0) {
    $return['message'] = t('You must login to consume this service');
  }
  else {
    #Get user idDrupal
    $user_uid = _innopro_services_get_idDrupal_user($solrID_user);

    if (!empty($user_uid)) {
      if ($user->uid != $user_uid) {
        $return['message'] = t('The requested user does not match the user session');
      }
      else {
        #Events
        //get user gropups
        $groups = og_get_groups_by_user($user, 'node');

        if (!empty($groups)) {
          $query = "SELECT n.nid
                    FROM {node} n
                    INNER JOIN {og_membership} ogm ON n.nid = ogm.etid AND ogm.entity_type = :entity_type
                    INNER JOIN {field_data_field_event_date} fdfed ON n.nid = fdfed.entity_id AND (fdfed.entity_type = :entity_type2 AND fdfed.deleted = :deleted)
                    WHERE n.status = :status AND n.type = :node_type AND ogm.gid IN (" . implode(',', $groups) . ")
                    ORDER BY fdfed.field_event_date_value ASC";

          $result = db_query($query, array(':entity_type' => 'node', ':entity_type2' => 'node', ':deleted' => '0', ':status' => NODE_PUBLISHED, ':node_type' => 'event'));

          if (count($result) > 0) {
            foreach($result as $record) {
              $return['data'][] = $record->nid;
            }

            $return['status'] = TRUE;
            $return['message'] = (count($return['data']) > 0) ? t('The request was successful') : t('No results');
          }
          else {
            $return['message'] = t('A problem occurred during the execution of the data');
          }
        }
        else {
          $return['status'] = TRUE;
          $return['message'] = t('No results');
        }
      }
    }
    else {
      $return['message'] = t('The requested user does not exist');
    }
  }

  return $return;
}

/**
 * Return user public profile
 */
function _innopro_services_user_public_profile($email) {
  $return['message'] = '';
  $return['status'] = FALSE;
  $return['data'] = array();

  if (!empty($email) && valid_email_address($email)) {
    #Get user uid from email
    $user_load = DrupalToolkit::getUserDataByMail($email, array('uid', 'picture'));

    if (!empty($user_load->uid)) {
      $uid = $user_load->uid;
      $picture_id = $user_load->picture;

      $user_data = array();

      //Load picture if exists
      if (!empty($picture_id)) {
        $picture = file_load($picture_id);
        if (!empty($picture->uri)) {
          $picture_path = drupal_realpath($picture->uri);
          $picture_contents = file_get_contents($picture_path);
          $user_data['picture'] = base64_encode($picture_contents);
        }
      }

      //Get user profile data
      $profile = profile2_load_by_user($uid, 'datos_personales');
      if (!empty($profile)) {
        $pwrapper = entity_metadata_wrapper('profile2', $profile);
        $profile_properties = $pwrapper->getPropertyInfo();

        foreach ($profile_properties as $profile_property) {
          if (!empty($profile_property['type']) && $profile_property['type'] == 'field_collection_item') {
            //Get entity field collection item
            $fc_entity_item = $pwrapper->$profile_property['bundle']->value();

            $fcwrapper = entity_metadata_wrapper('field_collection_item', $fc_entity_item);
            $fc_properties = $fcwrapper->getPropertyInfo();

            //Check field colletion visibility for this user
            if (isset($fc_properties['field_visibility'])) {
              $fc_visibility = $fcwrapper->field_visibility->raw();

              //Get fields from field collection
              foreach ($fc_properties as $fc_property => $fc_property_data) {
                if (isset($fc_property_data['field']) && $fc_property != 'field_visibility') {
                  $field_value = $fcwrapper->$fc_property->value();

                  //Parse data for field type
                  if (isset($fc_property_data['options list']) && $fc_property_data['type'] == 'text') {
                    $field = field_info_field($fc_property);
                    $allowed_values = list_allowed_values($field);

                    $field_value = $allowed_values[$field_value];
                  }
                  elseif ($fc_property_data['type'] == 'date') {
                    $field_value = format_date($field_value, $type = 'custom', $format = 'Y-m-d');
                  }

                  //Add info to user data array
                  $user_data[$fc_property] = ($fc_visibility) ? $field_value : '';
                }
              }
            }
            else {
              //if field_collection has not field_visibility not include in return
              continue;
            }
          }
        }

        $return['data'] = $user_data;
      }
      else {
        $return['message'] = t('No personal data for user. Cod 1');
      }
    }
    else {
      $return['message'] = t('The requested user does not exist');
    }
  }
  else {
    $return['message'] = t('No param found');
  }

  return $return;
}

/**
 * Return user public profile
 */
function odes_soap_create($ode) {
  global $user;

  $return['message'] = '';
  $return['status'] = FALSE;
  $return['data'] = array();

  if (!empty($ode) && is_object($ode)) {
    if (!empty($user->uid) && !empty($user->mail)) {
      //Call WS function
      $OS_orchestrator_publisher = new OS_orchestrator_publisher();
      $result = $OS_orchestrator_publisher->publish_external_ode_file($ode, $user->mail);

      //Check if ode was created successfully
      if (isset($result->return->documentId)) {
        //if we get solrid save ode in drupal
        $solr_id = $result->return->documentId;

        $ode_data = ag_visualization_ode_get_solr_ode($solr_id);
        //Add user author
        $ode_data['uid_author'] = $uid;

        //Save ode node
        $ode_nid = ag_visualization_ode_save($ode_data);

        if (!empty($ode_nid)) {
          $return['status'] = TRUE;
          $return['message'] = t('Ode saves successfully');
          $return['data'] = array('documentId' => $solr_id);
        }
        else {
          $return['message'] = t('Error saving ode in procomun');
        }
      }
      else {
        $return['message'] = t('Error saving ode');
        if (isset($result->faultstring)) {
          $return['message'] .= '. Error details: ' . $result->faultstring;
        }
      }
    }
    else {
      $return['message'] = t('Invalid access token');
    }
  }
  else {
    $return['message'] = t('No param found');
  }

  return $return;
}

/**
 * Return user public profile
 */
function _synchronize_odes() {
  $return['message'] = '';
  $return['status'] = FALSE;
  $return['data'] = array();

  // Get client ip.
  $ips = DrupalToolkit::getClientIP();

  if (in_array('***.***.***.***', $ips)) {
    try {
      // Force execution without limit time
      ini_set('max_execution_time', 0);

      // Log in as admin for saving odes
      global $user;
      $user = user_load(1);
      drupal_session_regenerate();

      $odes = _ode_save_sync_get_data();

      foreach ($odes as $ode) {
        ag_visualization_ode_save_ode($ode, 'sync');
      }

      $return['message'] = 'OK';
      $return['status'] = TRUE;
    }
    catch (DrupalUpdateException $e) {
      watchdog('innopro_services', 'Error sync odes process. ' . $e->getMessage());
      $return['message'] = 'NOK: ' . $e->getMessage();
    }
  }
  else {
    $return['message'] = 'NOK: No valid IP';
  }

  return $return;
}
