<?php

/**
 * @file
 * Orchestrator services - include file.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_publisher {
  
  protected $service_name;
  protected $service_type;
  protected $service_url;
  
  function __construct() {
    #Extract orquestador service
    $result = db_query('SELECT name, type, url from {wsclient_service} WHERE name = :name', array(':name' => 'ode_publishing'))->fetchObject();
    
    $this->service_name = isset($result->name) ? $result->name : '';
    $this->service_type = isset($result->type) ? $result->type : '';
    $this->service_url = isset($result->url) ? $result->url : '';
  }

  ###############################################
  #### WEBSERVICE METHOD: validateODEForm #######
  ###############################################
  /**
  * Function to call webservice validateODEForm method. Includes validation.
  * Optional ZIP permitted. Must not be encoded, if possible.
  * Packaging is done exactly like publish_ode_form, with method get_package_ode_form.
  * In fact, publishing always includes validation.
  */
  public function validate_ode_form($fids, $ode, $fid_image = '') {
    //Check if no url/webservice was configured
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }

    try {
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      $parameters = $this->get_package_ode_form($fids, $ode, $fid_image);

      $response = $client->validateODEForm($parameters);
      return $response;
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }


  ###############################################
  #### WEBSERVICE METHOD: publishODEForm ########
  ###############################################
  /**
  * Function to call webservice publishODEForm method.
  * Includes validation process.
  */
  public function publish_ode_form($fids, $ode, $fid_image = '', $file_zip_fid = '') {
    //Check if no url/webservice was configured
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }

    try {
      //Up limit time in soap response
      ini_set('default_socket_timeout', 600);
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      $parameters = $this->get_package_ode_form($fids, $ode, $fid_image, $file_zip_fid);

      $response = $client->publishODEForm($parameters);
      return $response;
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }

  /**
  * Generates parameters array from file and ode, complying with webservice structure by SOAP.
  */
  public function get_package_ode_form($fids, $ode, $fid_image = '',  $file_zip_fid = '') {

    $content_table = array();

    //Check if file is empty, else, create request structure.
    if (is_array($fids) && !empty($fids)) {

      $files_loaded = file_load_multiple(array_keys($fids), $conditions = array());
      foreach ($files_loaded as $file_fid => $file) {

        $imgbinary = $this->get_file_contents($file);

        $a2file = array('content' => $imgbinary, 'fileName' => $file->filename);
        $title = !empty($fids[$file_fid]) ? $fids[$file_fid] : $file->filename;

        $content_file = array('file' => $a2file, 'title' => $title, 'url' => '', 'order' => 0);

        $content_table[] = $content_file;
      }
    }
    else {
      $a2file = array('content' => '', 'fileName' => '');
      $content_file = array('file' => $a2file, 'title' => '', 'url' => '', 'order' => 0);
      $content_table[] = $content_file;
    }

    //Send image file
    if (!empty($fid_image)) {
      $file_image = file_load($fid_image);
      $imgbinary = $this->get_file_contents($file_image);

      $a2file = array('content' => $imgbinary, 'fileName' => 'vistaPreviaAgrega.png');
    }

    //Send incomplete scorm zip if exists.
    if (!empty($file_zip_fid)) {
      $file_zip = file_load($file_zip_fid);
      $imgbinary = $this->get_file_contents($file_zip);
      $a2file_failed_zip = array('content' => $imgbinary, 'fileName' => 'incompleteScorm.zip');
    }
    else {
      //Normal form, no incomplete ode.
      $a2file_failed_zip = array('content' => '', 'fileName' => '');
    }

    //Prepare content table
    $ode['contentTable'] = $content_table;

    //Finally, all arguments/parameters together.
    $is_new_version = 1;
    $parameters = array('arg0' => $ode, 'arg1' => $is_new_version, 'arg2' => $a2file, 'arg3' => $a2file_failed_zip);
    return $parameters;
  }

  ###############################################
  #### WEBSERVICE METHOD: validateODEFile #######
  ###############################################
  /**
  * Function to call webservice validateODEFile method. Just validation, no publishing.
  * Validation is done ONLY with imsmanifest.xml, with no encoding if possible. No image either.
  */
  public function validate_ode_file($file) {
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }

    try {
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      $parameters = $this->get_package_ode_file_xml($file);

      return $client->validateODEFile($parameters);
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }

  /**
  * Generates parameters array from file, complying with webservice structure by SOAP.
  * Validation is done ONLY with imsmanifest.xml.
  */
  public function get_package_ode_file_xml($file) {
    $imgbinary = get_file_contents($file);

    $a2file = array('content' => $imgbinary, 'fileName' => $file->filename);
    $parameters = array('arg0' => $a2file);
    return $parameters;
  }


  ###############################################
  #### WEBSERVICE METHOD: preloadODEFile ########
  ###############################################
  /**
   * Function to call webservice preloadODEFile method. Includes validation.
   * ZIP needed, with no encoding if possible.
   */
  public function preload_ode_file($file, $file_image = '') {
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }
    try {
      //Up limit time in soap response
      ini_set('default_socket_timeout', 600);
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      $parameters = $this->get_package_ode_file($file, $file_image);

      return $client->preloadODEFile($parameters);
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }


  ###############################################
  #### WEBSERVICE METHOD: publishODEFile ########
  ###############################################
  /**
  * Function to call webservice publishODEFile method. Includes validation.
  * ZIP needed, with no encoding if possible.
  */
  public function publish_ode_file($file, $file_image = '') {
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }
    try {
      //Up limit time in soap response
      ini_set('default_socket_timeout', 600);
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      $parameters = $this->get_package_ode_file($file, $file_image);

      return $client->publishODEFile($parameters);
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }

  /**
   * Function to call webservice publishODEFile method by external request
   * ZIP needed, with no encoding if possible.
   */
  public function publish_external_ode_file($ode, $mail) {
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }
    try {
      //Up limit time in soap response
      ini_set('default_socket_timeout', 600);
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      $parameters = $this->get_package_external_ode_file($ode, $mail);

      return $client->publishODEFile($parameters);
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }

  /**
   * Function to call webservice getOdeWithFormat method.
   */
  public function getOdeWithFormat($format, $mec, $lang = 'es') {
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }
    try {
      //Up limit time in soap response
      ini_set('default_socket_timeout', 600);
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      //Mount parameters.
      $parameters = array('arg0' => $format, 'arg1' => $mec, 'arg2' => $lang);

      return $client->getOdeWithFormat($parameters);
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }

  /**
   * Function to call webservice getOdeWithFormatImage method.
   */
  public function getOdeImageFormat($mec, $lang = 'es') {
    if (empty($this->service_url)) {
      drupal_set_message(t('Webservice url not properly configured.'), 'error');
      return NULL;
    }
    try {
      //Up limit time in soap response
      ini_set('default_socket_timeout', 600);
      $client = new SoapClient($this->service_url, array("trace" => 1, "exception" => 0, 'encoding'=> 'UTF-8'));

      //Mount parameters.
      $parameters = array('arg0' => $mec, 'arg1' => $lang);

      return $client->getOdeImageFormat($parameters);
    } catch (SoapFault $fault) {
      $result = new stdClass();
      $result->faultstring = $fault->faultstring;
      return $result;
    }
  }


  /**
  * Generates parameters array from file and ode, complying with webservice structure by SOAP.
  */
  public function get_package_ode_file($file, $file_image = '') {
    global $user;
    //Check if file is empty, else, create request structure.
    if (!empty($file) && isset($file->filesize) && $file->filesize > 0) {
      //Open, read file, and get contents.
      $abolute_path = drupal_realpath($file->uri);
      $handle = fopen($abolute_path, "r");

      $imgbinary = fread($handle, $file->filesize);
      fclose($handle);

      //Prepare service structure
      $a2file = array('content' => $imgbinary, 'fileName' => $file->filename);
    }
    else {
      drupal_set_message(t('Wrong file format, or file not correctly uploaded.'), 'error');
      return FALSE;
    }

    //Now, upload image.
/*    if (!empty($file_image) && isset($file_image->filesize) && $file_image->filesize > 0) {
      //Open, read file, and get contents.
      $abolute_path = drupal_realpath($file_image->uri);
      $handle = fopen($abolute_path, "r");

      $imgbinary = fread($handle, $file_image->filesize);
      fclose($handle);

      //Prepare service structure
      $a2file_image = array('content' => $imgbinary, 'fileName' => $file_image->filename);
    }
    else {
      drupal_set_message(t('Wrong image format, or file not correctly uploaded.'), 'error');
      return FALSE;
    }*/

    //New version of ODE
    $is_new_version = 1;

    //Author of the ODE
    $author = $user->mail;
    if (isset($file->publish_organization)) {
      $author = $file->publish_organization;
    }

    //Mount parameters.
    $parameters = array('arg0' => $a2file, 'arg1' => $author, 'arg2' => $is_new_version);
    return $parameters;
  }

  /**
   * Generates parameters array from ode object and uid author
   */
  public function get_package_external_ode_file($ode, $mail) {
    if (!empty($ode->file) && !empty($ode->file_name)) {
      //Files parameters
      $zip_file = array('content' => base64_decode($ode->file), 'fileName' => $ode->file_name);

      $is_new_version = 1;

      //Author of the ODE
      if (!empty($mail) && valid_email_address($mail)) {
        $author = $mail;
      }
      else {
        watchdog('orchestrator_services', 'No mail from author in external ode creation');
        return FALSE;
      }
    }
    else {
      watchdog('orchestrator_services', 'No ode parameters in external ode creation');
      return FALSE;
    }

    //Mount parameters.
    $parameters = array('arg0' => $zip_file, 'arg1' => $author, 'arg2' => $is_new_version, 'arg3' => NULL);
    return $parameters;
  }


  /**
  * Open real file with absolute url from a drupal file registry with relative registry and returns its contents.
  */
  public function get_file_contents($file) {
    //Open, read file, and get contents.
    $abolute_path = drupal_realpath($file->uri);
    $handle = fopen($abolute_path, "r");
    $imgbinary = fread($handle, $file->filesize);
    fclose($handle);

    return $imgbinary;
  }
}
