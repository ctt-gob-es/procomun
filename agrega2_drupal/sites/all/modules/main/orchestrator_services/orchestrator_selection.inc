<?php


/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_selection {
  
  protected $service_name;
  protected $service_type;
  protected $operations;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, operations from {wsclient_service} WHERE name = :name', array(':name' => 'orchestrator_selection'))->fetchObject();
    
    $this->service_name = $result->name;
    $this->service_type = $result->type;
    $this->operations = unserialize($result->operations);
  }
  
  /**
   * Service to get ODE information
   */  
  public function selectOde($oid) {

    #Return information
    $return[0] = 0;
    $return[1] = array();
    
    #Arguments to pass to orchestrator
    $arguments = array();
    
    $method = explode("::", __METHOD__);
    if (!empty($oid)) {
      #ODE ID
      $arguments['q'] = 'id:'.$oid;
      
      #Return method
      $arguments['wt'] = 'json';
      
      #Execute service to orchestrator
      $service = wsclient_service_load($this->service_name);
      $response = call_user_func_array(array($service, $method[1]), $arguments);
      
      if ($response['response']['numFound'] > 0) {
        $return[0] = $response['response']['numFound'];
        $return[1] = $response['response']['docs'];
      }

      else watchdog('orchestrator_services', 'Not found ODES');
    }
    
    else watchdog('orchestrator_services', 'No ODE has received the object properly');
    
    return $return;
  }

  /**
   * Service to get ODE information by mecIdentifierStr
   */
  public function selectOdeByMec($mec) {

    #Return information
    $return[0] = 0;
    $return[1] = array();

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);
    if (!empty($mec)) {
      #ODE ID
      $arguments['q'] = 'mecIdentifier:' . $mec;

      #Return method
      $arguments['wt'] = 'json';

      #We only need normal id.
      $arguments['fl'] = 'id,mecIdentifier';

      #Execute service to orchestrator
      $service = wsclient_service_load($this->service_name);
      $response = call_user_func_array(array($service, $method[1]), $arguments);

      if ($response['response']['numFound'] > 0) {
        $return[0] = $response['response']['numFound'];
        $return[1] = $response['response']['docs'];
      }

      else watchdog('orchestrator_services', 'Not found ODES by mecIdentifierStr');
    }

    else watchdog('orchestrator_services', 'No ODE has received the object properly');

    return $return;
  }

  /**
   * Request to get all ode in Solr.
   *
   * @param $type - Resource to find
   * @return mixed - Response
   */
  public function multipleSelectionOde($type) {
    // Return information
    $return[0] = 0;
    $return[1] = array();

    // Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    if ($type == 'ODE') {
      // Arguments.
      $arguments['q'] = $type;
      $arguments['rows'] = '0';
      $arguments['wt'] = 'json';
      $arguments['indent'] = 'true';

      // Execute service to orchestrator
      $service = wsclient_service_load($this->service_name);

      $response = call_user_func_array(array($service, $method[1]), $arguments);
      if ($response['response']['numFound'] > 0) {
        $return[0] = $response['response']['numFound'];
        $return[1] = $response['response']['docs'];
      }

      else watchdog('orchestrator_services', 'Not found ODES');
    }

    else watchdog('orchestrator_services', 'No ODE has received the object properly');

    return $return;
  }

  /**
   * Request to get all ode in Solr with more flexibility
   *
   * @param $rows - num of rows
   * @param $fields - fields to select
   * @return mixed - Response
   */
  public function multipleSelectionOdeFields($params) {
    // Return information
    $return[0] = 0;
    $return[1] = array();

    // Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    // Arguments.
    $arguments['q'] = isset($params['q']) ? $params['q'] : '*:*';
    $arguments['rows'] = isset($params['rows']) ? $params['rows'] : 10;
    $arguments['wt'] = 'json';
    $arguments['indent'] = 'true';
    $arguments['fl'] = isset($params['fields']) ? implode(',', $params['fields']): 'id';
    $arguments['fq'] = isset($params['fq']) ? $params['fq'] : 'type:ODE';

    // Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);

    $response = call_user_func_array(array($service, $method[1]), $arguments);
    if ($response['response']['numFound'] > 0) {
      $return[0] = $response['response']['numFound'];
      $return[1] = $response['response']['docs'];
    }

    else watchdog('orchestrator_services', 'Not found ODES');

    return $return;
  }

  /**
   * Request to get all ode in Solr.
   *
   * @param $type - Resource to find
   * @return mixed - Response
   */
  public function getUnpublishedODEs() {
    // Return information
    $return[0] = 0;
    $return[1] = array();

    // Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    // Arguments.
    $arguments['q'] = 'published:0 AND idDrupal:[* TO *] AND lastIndexDate:[NOW-3DAY TO NOW]';
    $arguments['wt'] = 'json';
    $arguments['fq'] = 'type:ODE';
    $arguments['indent'] = 'true';
    $arguments['fl'] = 'id,idDrupal';
    $arguments['rows'] = '1000';

    // Execute service to orchestrator
    $service = wsclient_service_load($this->service_name);

    try {
      $response = call_user_func_array(array($service, $method[1]), $arguments);
      if ($response['response']['numFound'] > 0) {
        $return[0] = $response['response']['numFound'];
        $return[1] = $response['response']['docs'];
      }
      else {
        watchdog('orchestrator_services', 'Not found ODES with these criteria');
      }
    } catch (Exception $e) {
      //Set variable error
      $return[0] = -1;
      watchdog("ODE unpublishing", t('Encountered an error communicating with service. Unpublished ODEs not received.'));
    }

    return $return;
  }
}