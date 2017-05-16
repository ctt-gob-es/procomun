<?php

/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_recommender {
  
  protected $service_name;
  protected $service_type;
  protected $operations;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, operations from {wsclient_service} WHERE name = :name', array(':name' => 'recommender'))->fetchObject();
    
    $this->service_name = $result->name;
    $this->service_type = $result->type;
    $this->operations = unserialize($result->operations);
  }

  /**
   * Service to query recommendations for a entity
   */  
  public function recommender($entity_type, $uid, $entity_id, $result) {
    
    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);
    if (empty($entity_id) || empty($result)) {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters are not successfully received");
    }

    else {
      ##################################################################
      #  #Mapping fields (Drupal structure => Orchestrator structure)  #
      ##################################################################

      #contentType
      $arguments['contentType'] = $entity_type;
     
      #idDrupal
      $arguments['idUser'] = $uid;
  
      #type
      $arguments['idContent'] = $entity_id;
  
      #title
      $arguments['numRecomendaciones'] = $result;
      
      #Execute service to orchestrator
      try{
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = count($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', 'Recommendations error: ' . t('Sorry, the service isn\'t available in this moment'));
        $return[0] = FALSE;
        $return[1] = t('Sorry, the service isn\'t available in this moment');
      }
    }
    
    return $return;
  }

  /**
   * Service to query interlinking for a entity
   */
  public function getInterlinkingContent($solrid) {

    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);
    if (empty($solrid)) {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters are not successfully received");
    }
    else {
      ##################################################################
      #  #Mapping fields (Drupal structure => Orchestrator structure)  #
      ##################################################################

      #solrid
      $arguments['solrid'] = $solrid;

      #Execute service to orchestrator
      try{
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = count($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', 'Recommendations error: ' . t('Sorry, the service isn\'t available in this moment'));
        $return[0] = FALSE;
        $return[1] = t('Sorry, the service isn\'t available in this moment');
      }
    }

    return $return;
  }
 }