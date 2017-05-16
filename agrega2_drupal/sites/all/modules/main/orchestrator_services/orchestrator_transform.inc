<?php

/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing labels tranforms operations in orchestrator
 */
class OS_orchestrator_transform {
  
  protected $service_name;
  protected $service_type;
  protected $operations;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, operations from {wsclient_service} WHERE name = :name', array(':name' => 'orchestrator_transform'))->fetchObject();
    
    $this->service_name = $result->name;
    $this->service_type = $result->type;
    $this->operations = unserialize($result->operations);
  }

  /**
   * Service to transform post labels
   */  
  public function transformPost($node) {
    global $language;

    #Arguments to pass to orchestrator
    $arguments = array();

    $method = explode("::", __METHOD__);

    //Build arguments
    $nwrapper = entity_metadata_wrapper('node', $node);

    #solrid
    $arguments['id'] = $nwrapper->field_solrid->raw();

    #idDrupal
    $arguments['idDrupal'] = $nwrapper->nid->raw();

    #type
    $arguments['type'] = "POST";

    #labels & postLabels
    $array_labels = $nwrapper->field_labels->value();

    if (!empty($array_labels) && is_array($array_labels)) {
      foreach ($array_labels as $label) {
        if (!empty($label->name)) {
          $arguments['labels'][] = $label->name;
          $arguments['postLabels'][] = $label->name;
        }
      }
    }
    else {
      $arguments['labels'] = array();
      $arguments['postLabels'] = array();
    }

    #Knowledge area
    $knowledge_areas = $nwrapper->field_knowledge_area->value();
    $knowledge_areas_name = array();
    if (!empty($knowledge_areas) && is_array($knowledge_areas)) {
      foreach ($knowledge_areas as $knowledge_area) {
        if (!empty($knowledge_area->name)) {
          $knowledge_areas_name[] = $knowledge_area->name;
        }
      }
    }
    $arguments['knowledgeArea'] = $knowledge_areas_name;

    #Learning context
    $learning_contexts = $nwrapper->field_learning_context->value();
    $learning_contexts_name = array();
    if (!empty($learning_contexts) && is_array($learning_contexts)) {
      foreach ($learning_contexts as $learning_context) {
        if (!empty($learning_context->name)) {
          $learning_contexts_name[] = $learning_context->name;
        }
      }
    }
    $arguments['learningContext'] = $learning_contexts_name;

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

      if (is_object($response) && property_exists($response, 'id')) {
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

