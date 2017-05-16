<?php

/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_authoring {
  
  protected $service_name;
  protected $service_type;
  protected $service_url;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, url from {wsclient_service} WHERE name = :name', array(':name' => 'ode_authors'))->fetchObject();
    $this->service_name = isset($result->name) ? $result->name : '';
    $this->service_type = isset($result->type) ? $result->type : '';
    $this->service_url = isset($result->url) ? $result->url : '';
  }
  /**
   * Query to solr, who queries external webservice to get ode regional authors.
   */  
  public function getOdeAuthor($mec_identifier, $language) {
    
    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);
    if (empty($mec_identifier) || empty($language)) {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters were not successfully received");
    }

    else {

      #contentType
      $arguments['mecIdentifier'] = $mec_identifier;

      #idDrupal
      $arguments['language'] = $language;

      try {
      #Execute service to orchestrator
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = !empty($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', t('GetOdeNode not available. Organization as author could not be obtained'));
        $return[0] = 0;
        $return[1] = '';
      }
    }

    return $return;
  }

  /**
   * Query to solr, who queries external webservice to get ode publisher.
   */
  public function getOdePublisher($mec_identifier) {
    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);
    if (empty($mec_identifier)) {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters were not successfully received");
    }
    else {
      #mecId
      $arguments['mecIdentifier'] = $mec_identifier;

      try {
        #Execute service to orchestrator
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = !empty($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', t('getOdePublicator not available.'));
        $return[0] = 0;
        $return[1] = '';
      }
    }

    return $return;
  }

  /**
   * Service get external publisher name and surname
   */
  public function getOdeExternalPublisher($mail) {
    //Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    if (!empty($mail)) {
      #mail
      $arguments['userName'] = $mail;

      try {
        //Execute service to orchestrator
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = !empty($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', t('Get external publisher not available.'));
        $return[0] = 0;
        $return[1] = '';
      }
    }
    else {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters were not successfully received");
    }

    return $return;
  }

  /**
   * Function for getting download ODE formats
   */
  public function getPifTypes($mec_identifier) {
    //Return information
    $return[0] = 0;
    $return[1] = array();

    //Arguments to pass to orchestrator
    $arguments = array();
    $method = explode("::", __METHOD__);

    if (empty($mec_identifier)) {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters were not successfully received");
    }
    else {
      $arguments['mecIdentifier'] = $mec_identifier;

      try {
        //Execute service to orchestrator
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = !empty($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', t('Download ODE formats not available.'));
        $return[0] = 0;
        $return[1] = '';
      }
    }

    return $return;
  }

  /**
   * Service to delete ode
   */
  public function deleteOde($mail, $mec) {
    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    if (!empty($mail) && !empty($mec)) {
      #mail
      $arguments['userId'] = $mail;

      #mec
      $arguments['mecId'] = $mec;

      try {
        //Execute service to orchestrator
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = !empty($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', t('Delete ODE not available.'));
        $return[0] = 0;
        $return[1] = '';
      }
    }
    else {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters were not successfully received");
    }

    return $return;
  }

  /**
   * Service to delete ode
   */
  public function checkDelete($mail, $mec) {
    //Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    if (!empty($mail) && !empty($mec)) {
      #mail
      $arguments['userId'] = $mail;

      #mec
      $arguments['mecId'] = $mec;

      try {
        //Execute service to orchestrator
        $service = wsclient_service_load($this->service_name);
        $response = call_user_func_array(array($service, $method[1]), $arguments);
        $return[0] = !empty($response);
        $return[1] = $response;
      }
      catch (WSClientException $e) {
        watchdog('orchestrator_services', t('Check delete ODE not available.'));
        $return[0] = 0;
        $return[1] = '';
      }
    }
    else {
      watchdog('orchestrator_services', 'The parameters are not successfully received');
      $return[1] = t("The parameters were not successfully received");
    }

    return $return;
  }
}
