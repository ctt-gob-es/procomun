<?php

/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_inyection {
  
  protected $service_name;
  protected $service_type;
  protected $operations;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, operations from {wsclient_service} WHERE name = :name', array(':name' => 'orchestrator_inyection'))->fetchObject();
    
    $this->service_name = $result->name;
    $this->service_type = $result->type;
    $this->operations = unserialize($result->operations);
  }

  /**
   * Service to update idDrupal in user in orchestrator 
   */
  public function UpdateSolr($idDrupal, $idSolr, $publicationDate) {

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    #id
    $arguments['id'] = $idSolr;    

    #idDrupal
    $arguments['idDrupal'] = $idDrupal;

    #publicationDate
    $arguments['publicationDate'] = $publicationDate;

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to update certified value in orchestrator
   */
  public function UpdateCertified($certified, $idSolr) {

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    #id
    $arguments['id'] = $idSolr;

    #idDrupal
    $arguments['certified'] = $certified;

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to update novelty value in orchestrator
   */
  public function UpdateNovelty($novelty, $idSolr) {

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    #id
    $arguments['id'] = $idSolr;

    #Novelty
    $arguments['novelty'] = $novelty;

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }


  /**
   * Service to publish content in orchestrator
   */
  public function PublishDocument($idSolr) {  
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);
    
    #id
    $arguments['id'] = $idSolr;    

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }   
  
  /**
   * Service to unpublish content in orchestrator
   */  
  public function UnpublishDocument($idSolr) {  
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);
    
    #id
    $arguments['id'] = $idSolr;    

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }    
  
  /**
   * Execute method in orchestrator
   */    
  public function execute($method, $arguments) {
    
    $return[0] = 0;
    $return[1] = array();
    
    $service = wsclient_service_load($this->service_name);
    $result = call_user_func_array(array($service, $method), $arguments);
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
   * Service to add new community in orchestrator 
   */  
  public function AddCommunity($form_state) {
    
    global $language;
    
    $user = user_load($form_state['uid']);
    
    $field_language = ($form_state['nid']) ? $language->language : 'und';
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';       
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "COMMUNITY";
    
    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];
    
    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];
    
    #communityDate
    $date = date("Y-m-d", $form_state['created']);
    $time = date("H:i:s", $form_state['created']);
    $arguments['communityDate'] = $date."T".$time."Z";

    #labels & communityLabels
    $labels = array();
    if (count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['communityLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['communityLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['communityLabels'] = array();
    }
    
    #communityAdminSups
    $arguments['communityAdminSups'][] = $user->name;
    
    #published
    $arguments['published'] = $form_state['status'];

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }  
  
  /**
   * Service to update community admins
   */
  public function Update_communityAdminSups($idDrupal, $adminsups = array()) {
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################    
    
    $node = node_load($idDrupal);
    
    #id
    $arguments['id'] = $node->field_solrid['und'][0]['value'];
    
    #idDrupal
    $arguments['idDrupal'] = $idDrupal;
    
    #type
    $arguments['type'] = "COMMUNITY";
    
    #communityAdminSups
    if (count($adminsups) > 0) {
      $result = db_query('SELECT uid, name FROM {users} WHERE uid IN (:users_uid)', array(':users_uid' => $adminsups));
      foreach ($result as $record) {
        $arguments['communityAdminSups'][] = $record->name;
      }
    }
    else {
      $arguments['communityAdminSups'] = array();
    }

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);    
  }

  /**
   * Update field boosting on Solr.
   */
  public function Update_fieldsBoosting($fields) {
    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    if (count($fields) > 0) {
      foreach ($fields as $field) {
        $arguments['fieldsBoosting'][] = $field;
      }
    }
    else {
      $arguments['fieldsBoosting'] = array();
    }

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }
  
  /**
   * Service to add new question in orchestrator 
   */  
  public function AddQuestion($form_state) {
    
    global $language;
    
    $field_language = ($form_state['nid']) ? $language->language : 'und';
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';      
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "QUESTION";

    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];

    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];

    #labels & questionLabels
    $labels = array();
    if (count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['questionLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['questionLabels'][] = $value['name'];
        }
      }
    }
    else {
      $arguments['labels'] = array();
      $arguments['questionLabels'] = array();
    }

    #category
    if (isset($form_state['field_categories']['und'][0]['tid'])) {
      $term = taxonomy_term_load($form_state['field_categories']['und'][0]['tid']);
      $arguments['category'] = $term->name;
    }
    else $arguments['category'] = '';

    #published
    $arguments['published'] = $form_state['status'];
    
    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new response in orchestrator 
   */
  public function AddResponse($form_state) {
    
    global $language;
    
    $field_language = ($form_state['nid']) ? $language->language : 'und';    
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';      
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "RESPONSE";
    
    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];
    
    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];
    
    #responseState
    $arguments['responseState'] = $form_state['field_answer_state']['und'][0]['value'];
    
    #category
    if (count($form_state['field_categories']['und'][0]) > 0) {
      $term = taxonomy_term_load($form_state['field_categories']['und'][0]['tid']);
      if (!empty($term)) {
        $arguments['category'] = $term->name;
      }
    }
    else $arguments['category'] = '';     
    
    #published
    $arguments['published'] = $form_state['status'];    
    
    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }      
  
  /**
   * Service to add new discussion in orchestrator 
   */  
  public function AddDiscussion($form_state) {

    global $language;
    
    $field_language = ($form_state['nid']) ? $language->language : 'und';
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';        
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "DISCUSSION";
    
    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];
    
    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];
    
    #labels & discussionLabels
    $labels = array();
    if (count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['discussionLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['discussionLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['questionLabels'] = array();
    }
    
    #category
    if (count($form_state['field_categories']['und'][0]) > 0) {
      $term = taxonomy_term_load($form_state['field_categories']['und'][0]['tid']);
      $arguments['category'] = $term->name;
    }
    else $arguments['category'] = '';     
    
    #published
    $arguments['published'] = $form_state['status'];

    #novelty
    $arguments['novelty'] = $form_state['field_novelty'][LANGUAGE_NONE][0]['value'];
    
    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }        
  
  /**
   * Service to add new poll in orchestrator 
   */  
  public function AddPoll($form_state) {
    
    global $language;
    
    $field_language = ($form_state['nid']) ? $language->language : 'und';    
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';         
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "POLL";
    
    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];
      
    #description
    $arguments['description'] = '';
    
    #published
    $arguments['published'] = $form_state['status'];
    
    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }        
  
  /**
   * Service to add new event in orchestrator 
   */  
  public function AddEvent($form_state) {
    global $language;

    $field_language = ($form_state['nid']) ? $language->language : 'und';    
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';         
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "EVENT";
    
    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];
    
    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];
    
    #labels & eventLabels
    $labels = array();
    if (count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['eventLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['eventLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['eventLabels'] = array();
    }   
    
    #category
    if (isset($form_state['field_categories']['und'][0]) && count($form_state['field_categories']['und'][0]) > 0) {
      $term = taxonomy_term_load($form_state['field_categories']['und'][0]['tid']);
      //Add only if term was found.
      $arguments['category'] = empty($term) ? '' : $term->name;
    }
    else $arguments['category'] = '';
    
    #published
    $arguments['published'] = $form_state['status'];        

    #Event dates
    if (!empty($form_state['field_event_date'][LANGUAGE_NONE][0]['value'])) {
      $start_date_array = explode(" ", $form_state['field_event_date'][LANGUAGE_NONE][0]['value']);

      if (!empty($start_date_array[0]) && !empty($start_date_array[1])) {
        $arguments['startDate'] = $start_date_array[0] . 'T' . $start_date_array[1] . 'Z';
      }
    }

    if (!empty($form_state['field_event_date'][LANGUAGE_NONE][0]['value2'])) {
      $end_date_array = explode(" ", $form_state['field_event_date'][LANGUAGE_NONE][0]['value2']);

      if (!empty($end_date_array[0]) && !empty($end_date_array[1])) {
        $arguments['endDate'] = $end_date_array[0] . 'T' . $end_date_array[1] . 'Z';
      }
    }

    #novelty
    $arguments['novelty'] = $form_state['field_novelty'][LANGUAGE_NONE][0]['value'];

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }     
  
  /**
   * Service to add new post in orchestrator 
   */  
  public function AddPost($form_state) {
    
    global $language;
    $processor = new OS_orchestrator_processing();

    $field_language = ($form_state['nid']) ? $language->language : 'und';    
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if (isset($form_state['field_solrid']['und']) && $form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';          
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #type
    $arguments['type'] = "POST";
    
    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];
    
    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];
    
    #labels & postLabels
    $labels = array();

    if (isset($form_state['field_labels']['und']) && count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
          $arguments['postLabels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
          $arguments['postLabels'][] = $value['name'];
        }
      }      
    }
    else {
      $arguments['labels'] = array();
      $arguments['postLabels'] = array();
    }   
    
    #category
    if (isset($form_state['field_categories']['und']) && count($form_state['field_categories']['und'][0]) > 0) {
      $term = taxonomy_term_load($form_state['field_categories']['und'][0]['tid']);
      $arguments['category'] = isset($term->name) ? $term->name : '';
    }
    else $arguments['category'] = '';      
    
    #published
    $arguments['published'] = $form_state['status'];    

    if (isset($form_state['field_knowledge_area'])) {
      $arguments['knowledgeArea'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_knowledge_area'], 'und', 'es');
    }
    if (isset($form_state['field_learning_context'])) {
      $arguments['learningContext'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_learning_context'], 'und', 'es');
    }

    $language_field = isset($form_state['field_general_language'][LANGUAGE_NONE][0]['value']) ? $form_state['field_general_language'][LANGUAGE_NONE][0]['value'] : '';
    $language_processed = (($language->language == 'und') ? 'x-none' : $language->language);
    $arguments['generalLanguage'] = !empty($language_field) ? array($language_field) : array($language_processed);

    #Novelty.
    $arguments['novelty'] = $form_state['field_novelty'][LANGUAGE_NONE][0]['value'];

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }
  
  /**
   * Service to update catalog post in orchestrator
   */
  public function AddPostCatalog($post_data) {
    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    #solrid
    $arguments['id'] = $post_data['solrid'];

    #idDrupal
    $arguments['idDrupal'] = $post_data['nid'];

    #type
    $arguments['type'] = "POST";

    #labels & postLabels
    $arguments['labels'] = $post_data['field_labels'];
    $arguments['postLabels'] = $post_data['field_labels'];

    #knowledgeArea
    $arguments['knowledgeArea'] = $post_data['field_knowledge_area'];

    #learningContext
    $arguments['learningContext'] = $post_data['field_learning_context'];

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new ode in orchestrator 
   */  
  public function AddOde($form_state) {
    
    global $language;
    
    $field_language = ($form_state['nid']) ? $language->language : 'und';    
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################
    
    #id (Only updates)
    if (!empty($form_state['field_solrid']) && $form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';          
    
    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';
  
    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new learning resource in orchestrator
   */
  public function AddLearningResource($form_state) {
    global $language;

    #Class to process fields from form_state to solr webservice arguments.
    $processor = new OS_orchestrator_processing();

    $field_language = ($form_state['nid']) ? $language->language : 'und';     
    $language_code = $field_language;

    # User that creates the node
    $user = user_load($form_state['uid']);

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################

    #id (Only updates)
    if (isset($form_state['field_solrid']['und'][0]['value'])) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';

    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';

    #type
    $arguments['type'] = "LEARNING_RESOURCE";

    #Title
    $arguments['title'] = $processor->get_text_field($form_state['title_field'], $language_code, t('Untitled'));

    #Description
    $arguments['description'] = $processor->get_text_field($form_state['field_descripci_n'], $language_code, '');

    #author
    $arguments['author'] = isset($user->mail) ? $user->mail : '';

    #GeneralTitle
    $arguments['generalTitle'] = $processor->get_text_field($form_state['title_field'], $language_code, t('Untitled'));

    #labels & learningResourceLabels & field_labels!
    $labels = array();
    if (!empty($form_state['field_labels']) && count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        //$arguments['labels'][] = $term->name;
        $arguments['generalKeyword'][] = $value['name'];
      }
    }
    else {
       //$arguments['labels'] = array();
       $arguments['generalKeyword'][] = '';
    }

    #Description and general Description
    $arguments['generalDescription'][] = $processor->get_text_field($form_state['field_descripci_n'], $language_code, '');

    #Language (code or name)
    $arguments['generalLanguage'] = array($language_code);

    #General Aggregation level
    $arguments['generalAggregationLevel'] = '';

    #Contribuciones
    //Use node language, or undefined if there is none.
    $language_access_code = isset($form_state['field_contribuciones'][$language_code]) ? $language_code : 'und';
    if (!empty($form_state['field_contribuciones'][$language_access_code])) {
      foreach($form_state['field_contribuciones'][$language_access_code] as $key => $value) {
        //Add more option must be ignored. Only numeric keys are allowed.
        if (!is_numeric($key)) {
          continue;
        }

        //Get these three fields if they exist
        $name = isset($value['field_nombre_y_apellidos'][$language_access_code][0]['value']) ? $value['field_nombre_y_apellidos'][$language_access_code][0]['value'] : '';
        $organization = isset($value['field_organizaci_n'][$language_access_code][0]['value']) ? $value['field_organizaci_n'][$language_access_code][0]['value'] : '';
        $mail = isset($value['field_correo_electr_nico'][$language_access_code][0]['email']) ? $value['field_correo_electr_nico'][$language_access_code][0]['email'] : '';

        //Add row if exists at least one field.
        if (!empty($name) || !empty($organization) || !empty($mail)) {
          $fields = array();
          $fields[0] = $name;
          $fields[1] = $organization;
          $fields[2] = $mail;
          $arguments['lifecycleContribute'][] = implode("##", $fields);
        }
        else {
          $arguments['lifecycleContribute'][] = "######";
        }
      }
    }
    else {
      $arguments['lifecycleContribute'][] = "######";
    }

    #Tipo de Recurso educativo
    $arguments['educationalLearningResourceType'][] = $processor->get_taxonomy_normal_field($form_state['field_recurso_educativo'], $language_code);

    #Destinatario + Agrupacion
    //Use node language, or undefined if there is none.
    $arguments['educationalIntendedEndUserRole'][] = $processor->get_taxonomy_normal_field($form_state['field_destinatarios'], $language_code);
    $arguments['educationalIntendedEndUserRole'][] = $processor->get_taxonomy_normal_field($form_state['field_agrupacion_de_alumnos'], $language_code);

    #Modalidad de uso + Lugar de utilizacion
    $arguments['educationalContext'][] = $processor->get_taxonomy_normal_field($form_state['field_modalidad_de_uso'], $language_code);
    $arguments['educationalContext'][] = $processor->get_taxonomy_normal_field($form_state['field_lugar_de_utilizaci_n'], $language_code);

    #EducationalDescription
    $arguments['educationalDescription'][] = $processor->get_text_field($form_state['field_conocimiento_previo'], $language_code);

    #RightsCopyright
    $arguments['rightsCopyrightAndOtherRestrictions'] = $processor->get_taxonomy_normal_field($form_state['field_licencia'], $language_code);

    #rightAccess TODO:
    $arguments['rightsAccess'] = '';


    #PublicationDate from timestamp to format: yyyy-mm-ddThh:mm:ss.cccZ
    if (!empty($form_state['created'])) {
      $arguments['publicationDate'] = $processor->get_date_iso_from_timestamp($form_state['created']);
    }
    else {
      $arguments['publicationDate'] = '';
    }

    #Nivel educativo/EducationalLevel
    $processor->set_taxonomy_hierarchy($form_state['field_nivel_educativo'], 'classificationEducationalLevel', 6, $arguments, 'es', 'es');
    #Arbol curricular/classification discipline
    $processor->set_taxonomy_hierarchy($form_state['field_arbol_curricular'], 'classificationDiscipline', 6, $arguments, 'es', 'es');

    #Labels just like generalKeyword
    $arguments['labels'] = $arguments['generalKeyword'];

    #published
    $arguments['published'] = $form_state['status'];

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new external content in orchestrator
   */
  public function AddUrl($form_state) {

    global $language;
    $processor = new OS_orchestrator_processing();

    $field_language = ($form_state['nid']) ? $language->language : 'und';

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################

    #id (Only updates)
    if ($form_state['field_solrid']['und'][0]['value']) {
      $arguments['id'] = $form_state['field_solrid']['und'][0]['value'];
    }
    else $arguments['id'] = '';

    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';

    #title
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];

    #description
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];

    #url
    $arguments['url'] = $form_state['field_external_url'][$field_language][0]['url'];;

    #type
    $arguments['type'] = "URL";

    #labels & postLabels
    $labels = array();

    if (count($form_state['field_labels']['und']) > 0) {
      foreach($form_state['field_labels']['und'] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
        }
      }
    }
    else {
      $arguments['labels'] = array();
    }

    #published
    $arguments['published'] = $form_state['status'];

    $language_field = isset($form_state['field_general_language'][LANGUAGE_NONE][0]['value']) ? $form_state['field_general_language'][LANGUAGE_NONE][0]['value'] : '';
    $language_processed = (($language->language == 'und') ? 'x-none' : $language->language);
    $arguments['generalLanguage'] = !empty($language_field) ? array($language_field) : array($language_processed);

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new learning path in orchestrator
   */
  public function AddLearningPath($form_state) {

    global $language;
    $processor = new OS_orchestrator_processing();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    ##################################################################
    #  #Mapping fields (Drupal structure => Orchestrator structure)  #
    ##################################################################

    #id (Only updates)
    if ($form_state['field_solrid'][LANGUAGE_NONE][0]['value']) {
      $arguments['id'] = $form_state['field_solrid'][LANGUAGE_NONE][0]['value'];
    }
    else {
      $arguments['id'] = '';
    }

    #idDrupal
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';

    #title
    if (isset($form_state['title_field']['es'][0]['value'])) {
      $arguments['title'] = $form_state['title_field']['es'][0]['value'];
    }
    elseif (isset($form_state['title_field'][LANGUAGE_NONE][0]['value'])) {
      $arguments['title'] = $form_state['title_field'][LANGUAGE_NONE][0]['value'];
    }
    else {
      $arguments['title'] = '';
    }

    #description
    if (isset($form_state['body'][LANGUAGE_NONE][0]['value'])) {
      $arguments['description'] = $form_state['body'][LANGUAGE_NONE][0]['value'];
    }
    elseif (isset($form_state['body']['es'][0]['value'])) {
      $arguments['description'] = $form_state['body']['es'][0]['value'];
    }
    else {
      $arguments['description'] = '';
    }

    #knowledge_area
    if (isset($form_state['field_knowledge_area'])) {
      $arguments['knowledgeArea'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_knowledge_area'], LANGUAGE_NONE, 'es');
    }

    #learning_context
    if (isset($form_state['field_learning_context'])) {
      $arguments['learningContext'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_learning_context'], LANGUAGE_NONE, 'es');
    }

    #labels
    $labels = array();

    if (count($form_state['field_labels'][LANGUAGE_NONE]) > 0) {
      foreach($form_state['field_labels'][LANGUAGE_NONE] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
        }
      }
    }
    else {
      $arguments['labels'] = array();
    }

    #itineraryContent
    $arguments['itineraryContent'] = array();
    if (isset($form_state['field_itinerary_content'])) {
      foreach($form_state['field_itinerary_content'][LANGUAGE_NONE] as $element) {
        if (isset($element['target_id']) && !empty($element['target_id'])) {
          $arguments['itineraryContent'][] = $element['target_id'];
        }
      }
    }

    #interestContent
    $arguments['interestContent'] = array();
    if (isset($form_state['field_interest_content'])) {
      foreach($form_state['field_interest_content'][LANGUAGE_NONE] as $element) {
        if (isset($element['target_id']) && !empty($element['target_id'])) {
          $arguments['interestContent'][] = $element['target_id'];
        }
      }
    }

    #baseItinerary
    if (isset($form_state['field_base_itinerary'])) {
      $arguments['baseItinerary'] = $form_state['field_base_itinerary'][LANGUAGE_NONE][0]['target_id'];
    }
    else{
      $arguments['baseItinerary'] = '';
    }

    #type
    $arguments['type'] = "LEARNING_PATH";

    #published
    $arguments['published'] = $form_state['status'];

    #Execute service to orchestrator
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new podcast in orchestrator.
   *
   * @param array $form_state
   *   Contains de current state of the form.
   */
  public function AddPodcast($form_state) {

    global $language;
    $processor = new OS_orchestrator_processing();

    $field_language = ($form_state['nid']) ? $language->language : LANGUAGE_NONE;

    // Arguments to pass to orchestrator.
    $arguments = array();

    $method = explode("::", __METHOD__);

    /////////////////////////////////////////////////////////////////
    // Mapping fields (Drupal structure => Orchestrator structure) //
    /////////////////////////////////////////////////////////////////

    // Argument: id (Only updates).
    if (isset($form_state['field_solrid'][LANGUAGE_NONE]) && $form_state['field_solrid'][LANGUAGE_NONE][0]['value']) {
      $arguments['id'] = $form_state['field_solrid'][LANGUAGE_NONE][0]['value'];
    }
    else $arguments['id'] = '';

    // Argument: idDrupal.
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';

    // Argument: type.
    $arguments['type'] = "PODCAST";

    // Argument: title.
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];

    // Argument: description.
    $arguments['description'] = $form_state['body'][$field_language][0]['value'];

    // Argument: podcastUrl.
    $arguments['podcastUrl'] = $form_state['field_podcast_url'][$field_language][0]['url'];

    // Argument: labels.
    if (isset($form_state['field_labels'][LANGUAGE_NONE]) && count($form_state['field_labels'][LANGUAGE_NONE]) > 0) {
      foreach($form_state['field_labels'][LANGUAGE_NONE] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
        }
      }
    }
    else {
      $arguments['labels'] = array();
    }

    // Argument: knowledgeArea.
    if (isset($form_state['field_knowledge_area'])) {
      $arguments['knowledgeArea'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_knowledge_area'], LANGUAGE_NONE, 'es');
    }

    // Argument: learningContext.
    if (isset($form_state['field_learning_context'])) {
      $arguments['learningContext'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_learning_context'], LANGUAGE_NONE, 'es');
    }

    // Argument: published.
    $arguments['published'] = $form_state['status'];

    // Argument: generalLanguage.
    $language_field = isset($form_state['field_general_language'][LANGUAGE_NONE][0]['value']) ? $form_state['field_general_language'][LANGUAGE_NONE][0]['value'] : '';
    $language_processed = (($language->language == LANGUAGE_NONE) ? 'x-none' : $language->language);
    $arguments['generalLanguage'] = !empty($language_field) ? array($language_field) : array($language_processed);

    // Argument: novelty.
    $arguments['novelty'] = $form_state['field_novelty'][LANGUAGE_NONE][0]['value'];

    // Execute service to orchestrator.
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to add new webinar in orchestrator.
   *
   * @param array $form_state
   *   Contains de current state of the form.
   */
  public function AddWebinar($form_state) {

    global $language;
    $processor = new OS_orchestrator_processing();

    $field_language = ($form_state['nid']) ? $language->language : LANGUAGE_NONE;

    // Arguments to pass to orchestrator.
    $arguments = array();

    $method = explode("::", __METHOD__);

    /////////////////////////////////////////////////////////////////
    // Mapping fields (Drupal structure => Orchestrator structure) //
    /////////////////////////////////////////////////////////////////

    // Argument: id (Only updates).
    if (isset($form_state['field_solrid'][LANGUAGE_NONE]) && $form_state['field_solrid'][LANGUAGE_NONE][0]['value']) {
      $arguments['id'] = $form_state['field_solrid'][LANGUAGE_NONE][0]['value'];
    }
    else $arguments['id'] = '';

    // Argument: idDrupal.
    $arguments['idDrupal'] = (!empty($form_state['nid'])) ? $form_state['nid'] : '';

    // Argument: type.
    $arguments['type'] = "WEBINAR";

    // Argument: title.
    $arguments['title'] = $form_state['title_field'][$field_language][0]['value'];

    // Argument: description.
    if (isset($form_state['body'][$field_language][0]['value'])) {
      $arguments['description'] = $form_state['body'][$field_language][0]['value'];
    }
    else {
      $arguments['description'] = '';
    }

    // Argument: startDate.
    if (!empty($form_state['field_class_date'][LANGUAGE_NONE][0]['value'])) {
      $start_date_array = explode(" ", $form_state['field_class_date'][LANGUAGE_NONE][0]['value']);

      if (!empty($start_date_array[0]) && !empty($start_date_array[1])) {
        $arguments['startDate'] = $start_date_array[0] . 'T' . $start_date_array[1] . 'Z';
      }
    }

    // Argument: duration.
    $arguments['duration'] = $form_state['field_duracion'][$field_language][0]['value'];

    // Argument: webinarUrl.
    if (!empty($form_state['field_recording_url'][$field_language][0]['url'])) {
      $arguments['webinarUrl'] = $form_state['field_recording_url'][$field_language][0]['url'];
    }
    else {
      $arguments['webinarUrl'] = '';
    }

    // Argument: labels.
    if (isset($form_state['field_labels'][LANGUAGE_NONE]) && count($form_state['field_labels'][LANGUAGE_NONE]) > 0) {
      foreach($form_state['field_labels'][LANGUAGE_NONE] as $key => $value) {
        if ($value['tid'] != 'autocreate') {
          $term = taxonomy_term_load($value['tid']);
          $arguments['labels'][] = $term->name;
        }
        else {
          $arguments['labels'][] = $value['name'];
        }
      }
    }
    else {
      $arguments['labels'] = array();
    }

    // Argument: knowledgeArea.
    if (isset($form_state['field_knowledge_area'])) {
      $arguments['knowledgeArea'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_knowledge_area'], LANGUAGE_NONE, 'es');
    }
    else {
      $arguments['knowledgeArea'] = array();
    }

    // Argument: learningContext.
    if (isset($form_state['field_learning_context'])) {
      $arguments['learningContext'] = $processor->get_taxonomy_normal_field_multivalued($form_state['field_learning_context'], LANGUAGE_NONE, 'es');
    }
    else {
      $arguments['learningContext'] = array();
    }

    // Argument: published.
    $arguments['published'] = $form_state['status'];

    // Argument: generalLanguage.
    $language_field = isset($form_state['field_general_language'][LANGUAGE_NONE][0]['value']) ? $form_state['field_general_language'][LANGUAGE_NONE][0]['value'] : '';
    $language_processed = (($language->language == LANGUAGE_NONE) ? 'x-none' : $language->language);
    $arguments['generalLanguage'] = !empty($language_field) ? array($language_field) : array($language_processed);

    // Argument: novelty.
    $arguments['novelty'] = $form_state['field_novelty'][LANGUAGE_NONE][0]['value'];

    // Execute service to orchestrator.
    return $this->execute($method[1], $arguments);
  }

  /**
   * Service to delete entity in orchestrator 
   */  
  public function delete_entity($solrId) {
    
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
   * Service to update image preview for an ODE
   */
  public function UpdatePreview($solr_id, $image_url) {
    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    if (isset($solr_id) && isset($image_url)) {
      $arguments['idSolr'] = $solr_id;

      #idDrupal
      $arguments['preview'] = $image_url;

      #Execute service to orchestrator
      return $this->execute($method[1], $arguments);
    }
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
   * Request to get all fields which we can configure their boosting.
   */
  public function getFieldsBoosting() {
    // Return information
    $return[0] = 0;
    $return[1] = array();

    // Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    // Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);

    try {
      $response = call_user_func_array(array($service, $method[1]), $arguments);

      if (!empty($response)) {
        $return[0] = count($response);
        $return[1] = $response;
      }
      else {
        watchdog('orchestrator_services', 'Not found fields');
      }
    } catch (Exception $e) {
      //Set variable error
      $return[0] = -1;
      watchdog("Get boosting fields", t('Encountered an error communicating with service. Fields for boosting not received.'));
    }

    return $return;
  }

}

