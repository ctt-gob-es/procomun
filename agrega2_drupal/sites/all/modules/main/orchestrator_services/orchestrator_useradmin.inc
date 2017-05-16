<?php

/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_useradmin {
  
  protected $service_name;
  protected $service_type;
  protected $operations;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, operations from {wsclient_service} WHERE name = :name', array(':name' => 'useradmin'))->fetchObject();
    
    $this->service_name = $result->name;
    $this->service_type = $result->type;
    $this->operations = unserialize($result->operations);
  }
  
  /**
   * Service to update idDrupal in user in orchestrator 
   */  
  public function updateSolr($idDrupal, $idSolr) {  
    
    #Return information
    $return[0] = 0;
    $return[1] = array();
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);
    
    #id
    $arguments['id'] = $idSolr;    

    #idDrupal
    $arguments['idDrupal'] = $idDrupal;
   
    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);
      
      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }      
      else {
        watchdog('orchestrator_services', $result->data);
        $return[1] = $result->status_message;            
      }         
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }
    
    return $return;
  }
  
  /**
   * Service to login
   */  
  public function login($email, $password) {
    
    #Return information
    $return[0] = 0;
    $return[1] = array();
    
    #Arguments to pass to orchestrator
    $arguments = array();    
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################    
    
    #email
    $arguments['email'] = $email;
    
    #password
    $arguments['password'] = $password;
    
    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);
    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);
      
      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }
      else {
        $return[1] = 'User or password incorrect';
      }         
    }
    
    else {
      watchdog('orchestrator_services', $result->data);
      $return[1] = $response->message;            
    }    
    
    return $return;
  }  
  
  /**
   * Service to add new user in orchestrator without to insert user in Agrega2 LDAP 
   * This service is temporary clone AddUser to migrate. After migration, may be delete.
   * NEW: If existing_solr_id is defined, solr will only update its fields.
   */
  public function AddUser_noLDAP($mail, $pass, $profile, $existing_solr_id = '') {

    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################

    #id
    $arguments['id'] = $existing_solr_id;

    #idDrupal
    $arguments['idDrupal'] = '';

    #type
    $arguments['type'] = "USER";

    #title
    $arguments['title'] = '';

    #description
    $arguments['description'] = '';
    
    #userDni
    $arguments['userDni'] = isset($profile['field_dni']['und'][0]['nif']) ? $profile['field_dni']['und'][0]['nif'] : '';

    #userName
    $arguments['userName'] = $profile['field_name_surname']['und'][0]['field_profile_name']['und'][0]['value'];
    
    #userSurName
    $arguments['userSurName'] = $profile['field_name_surname']['und'][0]['field_profile_surname']['und'][0]['value'];;
    
    #userLogin
    $arguments['userLogin'] = $mail;
    
    #userMail
    $arguments['userMail'] = $mail;
    
    #userPassword
    $arguments['userPassword'] = $pass;
    
    #userBirthDate
    $date = explode(" ", $profile['field_date_birth_personal_fc']['und'][0]['field_date_birth']['und'][0]['value']);
    $arguments['userBirthDate'] = $date[0];
    
    #userCountry
    $arguments['userCountry'] = $profile['field_country_personal_fc']['und'][0]['field_countries']['und'][0]['value'];
    
    #userProvince
    $arguments['userProvince'] = isset($profile['field_province_personal_fc']['und'][0]['field_province']['und'][0]['value']) ?
                                 $profile['field_province_personal_fc']['und'][0]['field_province']['und'][0]['value'] : '';

    #userLocality
    $arguments['userLocality'] = isset($profile['field_locality_personal_fc']['und'][0]['field_locality']['und'][0]['value']) ?
                                 $profile['field_locality_personal_fc']['und'][0]['field_locality']['und'][0]['value'] : '';

    #userEducativeCenter
    $arguments['userEducativeCenter'] = $profile['field_edu_center_personal_fc']['und'][0]['field_educative_center']['und'][0]['value'];
  
    #userEducativeCenterUrl
    $arguments['userEducativeCenterUrl'] = isset($profile['field_url_educative_center']['und'][0]['url']) ? $profile['field_url_educative_center']['und'][0]['url']: '';


    #labels & userLabels
    $labels = array();
    if (isset($profile['field_labels']['und']) && count($profile['field_labels']['und']) > 0) {
      foreach($profile['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['userLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['userLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['userLabels'] = array();
    }
    
    #userPlace
    $arguments['userPlace'] = $profile['field_place_fc']['und'][0]['field_place']['und'][0]['value'];

    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);
      
      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }      
      else {
        if (isset($response->httpResponseCode) && $response->httpResponseCode == 502) {
          $return[0] = -1;
          $return[1] = 'Agrega2 issues the following error:'." ".$response->message;
        }
        else {
          watchdog('orchestrator_services', $result->data);
          $return[1] = isset($response->message) ? $response->message : 'No error message available';
        }
      }
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }
    
    return $return;
  }  
  
  /**
   * Service to add new user in orchestrator 
   */  
  public function AddUser($mail, $pass, $profile) {
    
    #Return information
    $return[0] = 0;
    $return[1] = array();
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id
    $arguments['id'] = '';            
    
    #idDrupal
    $arguments['idDrupal'] = '';
  
    #type
    $arguments['type'] = "USER";
    
    #title
    $arguments['title'] = '';
    
    #description
    $arguments['description'] = '';
    
    #userDni
    $arguments['userDni'] = $profile['field_dni']['und'][0]['nif'];
    
    #userName
    $arguments['userName'] = $profile['field_name_surname']['und'][0]['field_profile_name']['und'][0]['value'];
    
    #userSurName
    $arguments['userSurName'] = $profile['field_name_surname']['und'][0]['field_profile_surname']['und'][0]['value'];;
    
    #userLogin
    $arguments['userLogin'] = $mail;
    
    #userMail
    $arguments['userMail'] = $mail;
    
    #userPassword
    $arguments['userPassword'] = $pass;
    
    #userBirthDate
    $date = explode(" ", $profile['field_date_birth_personal_fc']['und'][0]['field_date_birth']['und'][0]['value']);
    $arguments['userBirthDate'] = $date[0];
    
    #userCountry
    $arguments['userCountry'] = $profile['field_country_personal_fc']['und'][0]['field_countries']['und'][0]['value'];
    
    #userProvince
    $arguments['userProvince'] = $profile['field_province_personal_fc']['und'][0]['field_province']['und'][0]['value'];
    
    #userLocality
    $arguments['userLocality'] = $profile['field_locality_personal_fc']['und'][0]['field_locality']['und'][0]['value'];

    #userEducativeCenter
    $arguments['userEducativeCenter'] = $profile['field_edu_center_personal_fc']['und'][0]['field_educative_center']['und'][0]['value'];
  
    #userEducativeCenterUrl
    $arguments['userEducativeCenterUrl'] = $profile['field_url_educative_center']['und'][0]['url'];
   
    #labels & userLabels
    $labels = array();
    if (count($profile['field_labels']['und']) > 0) {
      foreach($profile['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['userLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['userLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['userLabels'] = array();
    }
    
    #userPlace
    $arguments['userPlace'] = $profile['field_place_fc']['und'][0]['field_place']['und'][0]['value'];

    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);
      
      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }      
      else {
        if ($response->httpResponseCode == 502) {
          $return[0] = -1;
          $return[1] = 'Agrega2 issues the following error:'." ".$response->message;
        }
        else {
          watchdog('orchestrator_services', $result->data);
          $return[1] = $result->status_message;            
        }
      }         
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }
    
    return $return;
  }
  
  /**
   * Service to edit user profile in orchestrator 
   */  
  public function edit($name, $mail, $pass, $profile, $user_uid, $solrId) {
      
    $user = user_load($user_uid);

    #Return information
    $return[0] = 0;
    $return[1] = array();
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id
    $arguments['id'] = $solrId;            
    
    #idDrupal
    $arguments['idDrupal'] = $user->uid;
  
    #type
    $arguments['type'] = "USER";
    
    #title
    $arguments['title'] = '';
    
    #description
    $arguments['description'] = '';
    
    #userDni
    $arguments['userDni'] = $profile['field_dni']['und'][0]['nif'];
    
    #userName
    $arguments['userName'] = $profile['field_name_surname']['und'][0]['field_profile_name']['und'][0]['value'];
    
    #userSurName
    $arguments['userSurName'] = $profile['field_name_surname']['und'][0]['field_profile_surname']['und'][0]['value'];;
    
    #userBirthDate
    $date = explode(" ", $profile['field_date_birth_personal_fc']['und'][0]['field_date_birth']['und'][0]['value']);
    $arguments['userBirthDate'] = $date[0];
    
    #userCountry
    $arguments['userCountry'] = $profile['field_country_personal_fc']['und'][0]['field_countries']['und'][0]['value'];
    
    #userProvince
    $arguments['userProvince'] = $profile['field_province_personal_fc']['und'][0]['field_province']['und'][0]['value'];
    
    #userLocality
    $arguments['userLocality'] = $profile['field_locality_personal_fc']['und'][0]['field_locality']['und'][0]['value'];

    #userEducativeCenter
    $arguments['userEducativeCenter'] = $profile['field_edu_center_personal_fc']['und'][0]['field_educative_center']['und'][0]['value'];
  
    #userEducativeCenterUrl
    $arguments['userEducativeCenterUrl'] = $profile['field_url_educative_center']['und'][0]['url'];
   
    #labels & userLabels
    $labels = array();
    if (count($profile['field_labels']['und']) > 0) {
      foreach($profile['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['userLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['userLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['userLabels'] = array();
    }
    
    #userPlace
    $arguments['userPlace'] = isset($profile['field_place_fc']['und'][0]['field_place']['und'][0]['value']) ?
                              $profile['field_place_fc']['und'][0]['field_place']['und'][0]['value'] : '';

    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);

    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);
      
      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }      
      else {
        if ($response->httpResponseCode == 502) {
          $return[0] = -1;
          $return[1] = 'Agrega2 issues the following error:'." ".$response->message;
        }
        else {
          watchdog('orchestrator_services', $result->data);
          $return[1] = $result->status_message;
        }
      }         
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }

    return $return;    
  }  
  
  /**
   * Service to edit user account in orchestrator 
   */  
  public function edit_account($mail, $pass, $user_uid, $solrId) {

    $user = user_load($user_uid);

    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################

    #id
    $arguments['id'] = $solrId;            

    #idDrupal
    $arguments['idDrupal'] = $user->uid;

    #type
    $arguments['type'] = "USER";

    #userLogin
    $arguments['userLogin'] = $user->mail;

    #userMail
    $arguments['userMail'] = $mail;

    #oldMail
    if ($user->mail != $mail) $arguments['oldMail'] = $user->mail;
    else $arguments['oldMail'] = '';

    if (!empty($pass)) {
      #userPassword
      $arguments['userPassword'] = $pass;

      #oldPassword
      $arguments['oldPassword'] = 'true';
    }
    else {
      #userPassword
      $arguments['userPassword'] = '';

      #oldPassword
      $arguments['oldPassword'] = '';      
    }
    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);

      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }
      else {
        if ($response->httpResponseCode == 502) {
          $return[0] = -1;
          $return[1] = 'Agrega2 issues the following error:'." ".$response->message;
        }
        else {
          watchdog('orchestrator_services', $result->data);
          //Message has more info than status_message, which only gives OK or NOK.
          $return[1] = isset($response->message) ? $response->message : $result->status_message;
        }
      }
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }

    return $return;
  }

  /**
   * Service to delete user in orchestrator 
   */
  public function delete_user($solrId, $email) {

    #Return information
    $return[0] = 0;
    $return[1] = array();
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id
    $arguments['id'] = $solrId;            
    
    #idDrupal
    $arguments['email'] = $email;

    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);
      
      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }      
      else {
        if ($response->httpResponseCode == 502) {
          $return[0] = -1;
          $return[1] = 'Agrega2 issues the following error:'." ".$response->message;
        }
        else {
          watchdog('orchestrator_services', $result->data);
          $return[1] = $result->status_message;
        }
      }         
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }
    
    return $return;    
  }      
 
  /**
   * Update node with returned solrID
   */
  function updateSolrID($type, $id, $documentID, $bundle) {
    $query = db_query('INSERT INTO {field_data_field_solrid} (entity_type, bundle, deleted, entity_id, revision_id, language, delta, field_solrid_value) 
                       VALUES (:entity_type, :bundle, :deleted, :entity_id, :revision_id, :language, :delta, :field_solrid_value)', 
                       array(':entity_type' => $type, ':bundle' => $bundle, ':deleted' => 0, ':entity_id' => $id, ':revision_id' => $id, ':language' => 'und', ':delta' => 0, ':field_solrid_value' => $documentID));
  }

  /**
   * Service to check if user exists in Agrega.
   */
  public function checkUserInAgrega($email) {

    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    #email
    $arguments['email'] = $email;

    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);

      if (is_object($response) && ($response->httpResponseCode == 404 || $response->httpResponseCode == 200 || $response->httpResponseCode == 502)) {
        $return[0] = 1;
        $return[1] = $response;
      }
      else {
        watchdog('orchestrator_services', $result->data);
        $return[1] = $result->status_message;
      }
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }

    return $return;
  }

  /**
   * Service to update regional data (userCountryStr, userProvinceStr, userLocalityStr) in user in orchestrator
   */
  public function updateRegional($userCountryStr, $userProvinceStr, $userLocalityStr, $idSolr) {

    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    #id
    $arguments['id'] = $idSolr;

    #userCountryStr
    $arguments['userCountry'] = $userCountryStr;

    #userProvinceStr
    $arguments['userProvince'] = $userProvinceStr;

    #userLocalityStr
    $arguments['userLocality'] = $userLocalityStr;

    #Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method[1]), $arguments);

    if (is_object($result) && property_exists($result, 'data')) {
      $response = json_decode($result->data);

      if (is_object($response) && $response->responseCode == 1) {
        $return[0] = 1;
        $return[1] = $response;
      }
      else {
        watchdog('orchestrator_services', $result->data);
        $return[1] = $result->status_message;
      }
    }
    else {
      watchdog('orchestrator_services', t('Fatal error'));
      $return[1] = 'Fatal error';
    }

    return $return;
  }

 }
