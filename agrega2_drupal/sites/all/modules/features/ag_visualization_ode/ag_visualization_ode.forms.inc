<?php
/**
 * @file
 * Code for ode node creation and requests to external webservices
 * related to ode publication and validation.
 */

include_once 'ag_visualization_ode.module';

/**
* Custom form callback to publish an ODE if user has a zip with SCORM format.
*/
function publish_new_ode_form($form_state) {
  global $user;

  // New form with id publish_new_ode_form
  $form = array();

  //First group
  $form['zip'] = array(
    '#type' => 'fieldset',
    '#weight' => 2,
  );

  $form['zip']['custom_zip_description'] = array(
    '#type' => 'item',
    '#markup' => t('With this option you may upload SCORM o IMS package, compressed in zip format, for publishing at Procomún.'),
    '#weight' => 2,
  );

  $form['zip']['custom_zip_description_files'] = array(
    '#type' => 'item',
    '#markup' => t('Also, you may upload a zip without any catalog file and some files in its root folder. These files will be processed and redirected to a resource creation form where you may complete any catalog information.'),
    '#weight' => 3,
  );

  // Attach field_dragndrop from ODE content type.
  $node = new stdClass();
  $node->type = 'ode';
  node_object_prepare($node);
  $attach_form = array();
  field_attach_form('node', $node, $attach_form, $form_state, NULL, array('field_name' => 'field_dragndrop'));

  $form['zip']['upload'] = $attach_form['field_dragndrop'];
  $form['zip']['upload']['#weight'] = 5;
  $form['zip']['upload'][LANGUAGE_NONE][0]['#name'] = 'ode_file';
  $form['zip']['upload'][LANGUAGE_NONE]['#title'] = '';
  $form['zip']['upload'][LANGUAGE_NONE]['#file_upload_title'] = t('Add new files');
  $form['zip']['upload'][LANGUAGE_NONE][0]['#required'] = TRUE;
  $form['zip']['upload'][LANGUAGE_NONE][0]['#upload_location'] = 'public://uploaded_odes/';
  $form['zip']['upload'][LANGUAGE_NONE][0]['#upload_validators']['multiupload_file_validate_zip'] = array('');
  //$form['zip']['upload'][LANGUAGE_NONE][0]['#pre_render'][] = 'publish_new_ode_form_remove_buttons';

  $groups = _ode_get_groups();

  $form['zip']['groups'] = array(
    '#type' => 'select',
    '#title' => t('Communities in which are published'),
    '#options' => $groups,
    '#description' => t('Communities where the content will be published'),
    //'#default_value' => variable_get('global_community_procomun', 0),
    '#required' => TRUE,
    '#weight' => 14,
    '#multiple' => TRUE,
  );

  //Check if user belongs to an organization for showing associated field
  $org_ids = ag_section_profile_users_get_organization($user->uid);
  if (!empty($org_ids)) {
    ag_visualization_ode_publish_organization_form($form, $org_ids);
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#weight' => 50,
  );

  // Add an ODE (Learning resource).
  // This resource is added by default in the Procomun community.
  $global_procomun = variable_get('global_community_procomun', 0);

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'ag_visualization_ode') . '/js/selector_form.js',
  );
  return $form;
}

/**
* Implements hook_form_FORM_ID_alter();
*/
function ag_visualization_ode_form_publish_new_ode_form_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = 'publish_new_ode_form_check_groups';
  $form['#validate'][] = 'publish_new_ode_form_send_solr';

  ag_visualization_ode_prepopulate_select($form['zip']['groups']['#options'], $form['zip']['groups']['#default_value']);
}

/**
* Sets default value of select field og_groups_ref.
* Receives select options to check GET parameters against them, same for Procomun group.
*/
function ag_visualization_ode_prepopulate_select(&$options, &$default_value) {
  //GET OG_GROUP_REF VALUES AND SET IN FIELD. ALSO, PROCOMUN AS DEFAULT.
  $default_groups = array();
  //Prepopulate field
  if (!empty($_GET['og_group_ref'])){
    $gid = $_GET['og_group_ref'];
    if (isset($options[$gid])) {
       $default_groups[] = $gid;
    }
  }
  //Procomun community selected by default, if user belongs to it, of course.
  $procomun_nid = variable_get('global_community_procomun', 0);
  if (!empty($procomun_nid) && isset($options[$procomun_nid])) {
    $default_groups[] = $procomun_nid;
  }

  //Finally, assign default values to field.
  $default_value = $default_groups;
}

/**
* Detects if zip has catalog inside it. It is used to check if we need to avoid
* sending it to Agrega, so that its files might be added to normal ode node form.
*/
function ag_visualization_ode_has_zip_catalog($file) {
  //By default, it is a file without catalog documents.
  $catalog = FALSE;

  //Check if we find any catalog documents.
  if (isset($file->uri)) {
    $real_path = drupal_realpath($file->uri);

    $zip_file = new ZipArchive();
    $zip_file->open($real_path);

    for ($i = 0; $i < $zip_file->numFiles; $i++) {
      $stat = $zip_file->statIndex($i);

      //Get filenames, complete and single file.
      $full_filename = $stat['name'];
      $filename = basename($stat['name']);

      //Check conditions to ensure at least a catalog file exists.
      $has_manifest = (strpos($full_filename, 'imsmanifest.xml') !== false);

      if ($has_manifest) {
        $zip_file->close();
        return TRUE;
      }
    }
    $zip_file->close();
  }
  return $catalog;
}

/**
* Implements validate callback for publish_new_ode_form.
* This form upload ODE by ZIP file with SCORM format. Submit prepares and validates.
*/
function publish_new_ode_form_send_solr($form, &$form_state) {
  $errors = form_get_errors();
  if (!$errors) {
    // Get file ID descriptors.
    $files = $form_state['input']['upload'][LANGUAGE_NONE];
    $num_files = count($files);
    $file = '';
    $fids = array();

    // Single file case.
    if ($num_files == 1) {
      $fids[] = $files[0]['fid'];
      // Load file
      $file = file_load($fids[0]);

      // Deprecated: Only exists for not change the logic for method $OS_orchestrator_publisher->preload_ode_file.
      $file_image = '';

      //Check if user is publishing as organization
      if (!empty($form_state['values']['publish_organization']) && !empty($file)) {
        // Add extra parameter to file object with org id for not alter function arguments.
        $org_id = $form_state['values']['publish_organization'];
        $org_data = ag_section_profile_users_get_organization_data(array($org_id));
        if (!empty($org_data[$org_id]['mail'])) {
          $file->publish_organization = $org_data[$org_id]['mail'];
        }

        // Publish organization argument for prepopulate field.
        $_SESSION['publish_organization'] = $org_id;
      }

      // WARNING: If zip has no catalog files at all, we won't start publishing process, but redirect user to the usual form.
      // There, all its files (except those in folders) will be added/prepopulated to the files field collection.
      $has_catalog = ag_visualization_ode_has_zip_catalog($file);

      // Send zip to publishing methods if it has catalog files. Else, just send it to ode node form.
      if (!empty($has_catalog)) {
        // Catalog single file case.
        // Create request.
        $OS_orchestrator_publisher = new OS_orchestrator_publisher();
        $result = $OS_orchestrator_publisher->preload_ode_file($file, $file_image);

        // SCORM 1.2 case.
        if (isset($result->return->httpResponseCode) && $result->return->httpResponseCode == 200 && $result->return->responseCode == 'RETRY_PUBLISH_ODE') {
          $OS_orchestrator_publisher = new OS_orchestrator_publisher();
          $result = $OS_orchestrator_publisher->publish_ode_file($file, $file_image);
        }

        // Add result solrID if succeeded to later use image on node.
        if (isset($result->return->documentId)) {
          $form_state['solr_id'] = $result->return->documentId;
        }

        // Notify user with result format.
        $result_value = webservice_result_notify_user_if_needed($result);

        if ($result_value == FALSE && isset($result->return->httpResponseCode) && ($result->return->httpResponseCode == 502 || $result->return->httpResponseCode == 506 || $result->return->httpResponseCode == 509)) {
          $form_state['redirect'] = array('ode/add');

          drupal_set_message(t('There was a problem creating the educational resource. Please, contact the administrators'), 'warning');

          if (isset($result->return->ode) && !empty($result->return->ode)) {
            $_SESSION['ode'] = $result->return->ode;
            $_SESSION['ode_zip_fid'] = $fids;
          }
          // With redirect code now in validate, we need to force redirection, which is usually done on submit.
          drupal_redirect_form($form_state);
        }
        else if ($result_value == FALSE && isset($result->return->httpResponseCode) && ($result->return->httpResponseCode == 200 || $result->return->httpResponseCode == 206)
            && $result->return->responseCode == 'NOK') {
          $form_state['redirect'] = array('ode/add');

          if (isset($result->return->ode) && !empty($result->return->ode)) {
            $_SESSION['ode'] = $result->return->ode;
            $_SESSION['ode_zip_fid'] = $fids;
            $_SESSION['ode_zip_no_catalog'] = 0;
          }
          // With redirect code now in validate, we need to force redirection, which is usually done on submit.
          drupal_redirect_form($form_state);
        }
        else if ($result_value == TRUE && isset($result->return->httpResponseCode) && $result->return->httpResponseCode == 200
            && $result->return->responseCode == 'OK' && isset($result->return->documentId) && $result->return->documentId != '-1') {
          $form_state['redirect'] = array('ode/add');
          drupal_redirect_form($form_state);
        }
        else if ($result_value == FALSE && isset($result->faultstring)) {
          $form_state['redirect'] = array('ode/add');
          drupal_redirect_form($form_state);
        }
        else {
          if (isset($result->return->ode) && !empty($result->return->ode)) {
            $_SESSION['ode'] = $result->return->ode;
            $_SESSION['ode_zip_fid'] = $fids;
            $_SESSION['ode_zip_no_catalog'] = 0;
          }

          $form_state['redirect'] = array('node/add/ode');
          drupal_redirect_form($form_state);
        }
      }
      else {
        // No catalog single file case.
        $_SESSION['ode_zip_fid'] = $fids;
        $_SESSION['ode_zip_no_catalog'] = 1;

        $OS_orchestrator_processing = new OS_orchestrator_processing();
        $mimetype = $OS_orchestrator_processing->extract_mimetype($file);
        if ($mimetype['status'] == 1) {
          $_SESSION['mimetype'] = $mimetype['mimetype'];
          // No submit at all, just redirect as if everything went ok.
          $form_state['#submit'] = array();
          $form_state['redirect'] = array('node/add/ode');
          drupal_redirect_form($form_state);
        }
        else {
          form_set_error('ode_file', $mimetype['error']);
        }
      }
    }
    // Multiple file case.
    else {
      foreach ($files as $value) {
        $fids[] = $value['fid'];
      }

      $_SESSION['ode_zip_fid'] = $fids;
      $_SESSION['ode_zip_no_catalog'] = 2;

      $form_state['#submit'] = array();
      $form_state['redirect'] = array('node/add/ode');
      drupal_redirect_form($form_state);
    }
  }
}

/**
* Implements submit callback for publish_new_ode_form.
* Once it was accepted by solr and external service, create node in drupal and assign image.
*/
function publish_new_ode_form_submit($form, &$form_state) {
  global $user;
  $solr_id = $form_state['solr_id'];

  $image_fid = $form_state['values']['picture'];
  if (!empty($image_fid)) {
    $file = file_load($image_fid);
  }

  //Save node only if exists in solr.
  if (!empty($solr_id) ) {
    // Save node from solr.
    $ode = ag_visualization_ode_get_solr_ode($solr_id);
    //Add uid author from drupal.
    if (!empty($user->uid)) {
      $ode['uid_author'] = $user->uid;
    }

    //Check if user published ode as organization
    if (!empty($form_state['values']['publish_organization'])) {
      $ode['publish_organization'] = $form_state['values']['publish_organization'];
    }
    $ode_nid = ag_visualization_ode_save($ode);

    //Assign image if node was correctly saved.
    if (!empty($ode_nid)) {
      $entity = entity_load_single('node', $ode_nid);
      $ewrapper = entity_metadata_wrapper('node', $entity);

      if (!empty($file)) {
        $ewrapper->field_imagen_miniatura->set((array) $file);
        $ewrapper->save();
        entity_save('node', $entity);
      }

      $path_new_ode = 'ode/view/' . $ewrapper->field_solrid->value();
      drupal_set_message(t('You may access created educational resource by clicking on this link: !link', array('!link' => l($ewrapper->title->value(), $path_new_ode))), 'status');

      //No update image in Solr. Removed from this code.
      // If we've the og_group by params redirect to the community:
      $query_params = drupal_get_query_parameters();
      if (isset($query_params['og_group_ref']) && is_numeric($query_params['og_group_ref'])) {
        $form_state['redirect'] = 'node/' . $query_params['og_group_ref'];
      }
    }
  }
}

/**
* Removes upload and remove buttons, as user is confused with both upload and send.
*/
function publish_new_ode_form_remove_buttons($element) {
  unset($element['upload_button']);
  unset($element['remove_button']);
  return $element;
}


/**
* Notifies user with different messages depending on webservice requests results.
* It returns TRUE or FALSE too, in order to stop node submitting.
*/
function webservice_result_notify_user_if_needed($result, $ode_title = '') {
  // Result is not empty.
  if (!empty($result)) {
    // If a response was received, notify user. Returns OK in green and NOK in red as error.
    if (isset($result->return) && isset($result->return->message)) {
      // Check if we receive an 502 error code.
      if ($result->return->httpResponseCode == 502) {
        watchdog('ODE socket error', t('Exception produced creating the ODE with message: @message'), array('@message' => $result->return->message));
        return FALSE;
      }
      // Cover all error cases not processed by orchestrator. They all come from Agrega.
      if (isset($result->return->httpResponseCode) && $result->return->httpResponseCode == 509) {
        form_set_error('form', t('Error when publishing on Agrega') . ': ' . $result->return->message);
        watchdog("ODE creation error", t('Error when publishing on Agrega') . ' Response from Orq as JSON: ' . json_encode($result));
        return FALSE;
      }

      // Check if user has exceeded maximum size limit.
      if (isset($result->return->responseCode) && isset($result->return->httpResponseCode) && $result->return->httpResponseCode == 200 && $result->return->responseCode == 'NOK') {
        form_set_error('form', t('User has reached maximum data limit in Agrega.'));
        watchdog("ODE creation error", t('User has reached maximum data limit in Agrega.') . ' Response from Orq as JSON: ' . json_encode($result));
        return FALSE;
      }
      // Check if error or right validation.
      if (isset($result->return->responseCode) && $result->return->responseCode == 'NOK') {
        form_set_error('form', t('Submitted package couldn\'t be processed (LOM-ES categories not valid or absent). Please review it, fix any errors and submit it again.'));
        watchdog("ODE creation error", t('Exception produced when sending ODE to Sorl/Tomcat server: @message', array('@message' => $result->return->message)));
        return FALSE;
      }
      else if(isset($result->return->responseCode) && $result->return->httpResponseCode == 200 && $result->return->responseCode == 'OK' && isset($result->return->documentId) && $result->return->documentId != '-1'){
        drupal_set_message(t('The resource was created correctly'), 'status');
        $path_new_ode = 'ode/view/' . $result->return->documentId;
        $ode_title = !empty($ode_title) ? $ode_title : $path_new_ode;
        drupal_set_message(t('You may access created educational resource by clicking on this link: !link', array('!link' => l($ode_title, $path_new_ode))), 'status');
        watchdog("ODE creation success", t('Response received: @message',  array('@message' => $result->return->message)));
        return TRUE;
      }
      else if(isset($result->return->responseCode) && $result->return->responseCode == 'OK'){
        drupal_set_message(t('The resource was imported correctly'), 'status');
        watchdog("ODE import success", t('Response received: @message',  array('@message' => $result->return->message)));
        return TRUE;
      }
    }
    elseif (isset($result->faultstring)) {
      form_set_error('form', t('External server not available. Please contact an administrator.'));
      watchdog("ODE creation error", t('Exception produced when sending ODE to Sorl/Tomcat server: @faultstring',  array('@faultstring' => $result->faultstring)));
      return FALSE;
    }
  }
  else {
    form_set_error('form', t('External server did not respond or request is empty.'));
    return FALSE;
  }
}


/**
* Implements hook_form_FORM_ID_alter();
*/
function ag_visualization_ode_form_ode_node_form_alter(&$form, &$form_state, $form_id) {
  global $language;

  //Prevent node from being created. TODO: Must be sure of this.
  //$form['actions']['submit']['#submit'] = array();

  //First, check if ode_zip_no_catalog is true.
  if (!empty($_SESSION['ode_zip_no_catalog']) || !empty($form_state['ode_zip_no_catalog'])) {
    //There must be a zip to extract files from. Rembember, at this point this zip has no scorm catalog files.
    if (isset($_SESSION['ode_zip_fid']) || isset($form_state['ode_zip_fid'])) {
      $OS_orchestrator_processor = new OS_orchestrator_processing();
      $OS_orchestrator_processor->prepopulate_non_catalog_files($form, $form_state);
    }
  }
  else if (isset($_SESSION['ode_zip_fid']) || isset($form_state['ode_zip_fid']) || isset($_SESSION['ode']) || isset($form_state['ode'])) {
    //If zip exists and has catalog:
    //Prepopulate ODE if ZIP form failed, or if user is trying to submit again after this form validation.
    $OS_orchestrator_processor = new OS_orchestrator_processing();
    $OS_orchestrator_processor->prepopulate_arguments_in_node_form($form, $form_state);
  }


  //Hide field field field_question_share. This field is for check if a content should be shared
  //in other communities
  //We don't need to set it TRUE because it is set in ag_visualization_ode_save
  $form['field_question_share']['#access'] = FALSE;

  // Hide field labels.
  $form['field_labels']['#access'] = FALSE;

  // Hide field resource_type.
  $form['field_resource_type']['#access'] = FALSE;

  // Hide field dragndrop.
  $form['field_dragndrop']['#access'] = FALSE;

  //Procomun community selected by default, if user belongs to it, of course.
  $procomun_nid = variable_get('global_community_procomun', 0);
  if (!empty($procomun_nid) && isset($form['og_group_ref'][LANGUAGE_NONE][0]['default']['#options'][$procomun_nid])) {
    //Add as another element inside default value, in case it is already prepopulated.
    $form['og_group_ref'][LANGUAGE_NONE][0]['default']['#default_value'][] = $procomun_nid;
  }

  //If current user-selected language is one of the options of the field, then set it in both language fields.
  $has_current_language = isset($language->language);
  $has_form_language_field = isset($form['field_general_language'][LANGUAGE_NONE]);
  $has_form_educational_language_field = isset($form['field_educational_language'][LANGUAGE_NONE]);
  if ($has_current_language && $has_form_language_field && empty($form['field_general_language'][LANGUAGE_NONE]['#default_value'])) {
    if (isset($form['field_general_language'][LANGUAGE_NONE]['#options']) && array_key_exists($language->language, $form['field_general_language'][LANGUAGE_NONE]['#options'])) {
      $form['field_general_language'][LANGUAGE_NONE]['#default_value'] = $language->language;
    }
  }
  if ($has_current_language && $has_form_language_field && empty($form['field_educational_language'][LANGUAGE_NONE]['#default_value'])) {
    if (isset($form['field_educational_language'][LANGUAGE_NONE]['#options']) && array_key_exists($language->language, $form['field_educational_language'][LANGUAGE_NONE]['#options'])) {
      $form['field_educational_language'][LANGUAGE_NONE]['#default_value'] = $language->language;
    }
  }

  //Remove children from options of "field_recurso_educativo". Children will be included before sending to solr.
  if (isset($form['field_recurso_educativo'])) {
    foreach ($form['field_recurso_educativo']['und']['#options'] as $tid => $name) {
      $parents = taxonomy_get_parents($tid);
      if (!empty($parents)) {
        unset($form['field_recurso_educativo']['und']['#options'][$tid]);
      }
    }
  }

  //Remove children from options of "field_lugar_de_utilizaci_n". Children will be included before sending to solr.
  foreach ($form['field_lugar_de_utilizaci_n']['und']['#options'] as $tid => $name) {
    $parents = taxonomy_get_parents($tid);
    if (!empty($parents)) {
      unset($form['field_lugar_de_utilizaci_n']['und']['#options'][$tid]);
    }
  }

  //Order alphabetically for all languages.
  if (isset($form['field_knowledge_area'][LANGUAGE_NONE]['#options'])) {
    setlocale(LC_ALL, 'es_ES.utf8');
    asort($form['field_knowledge_area'][LANGUAGE_NONE]['#options'], SORT_LOCALE_STRING);
  }

  //Hide old LOM-ES taxonomies, or unused default-valued fields.
  ag_visualization_ode_hide_ode_fields($form);

  // Remove 'remove author' button and 'add more' button and disable fields ode zip catalog load form case.
  if ($_SESSION['ode_zip_no_catalog'] === 0 && isset($form['field_contribuciones_ode'][LANGUAGE_NONE])) {
    foreach($form['field_contribuciones_ode'][LANGUAGE_NONE] as $delta => $value) {
      if (is_int($delta) && is_array($value)) {
        // Remove 'remove author' button.
        $form['field_contribuciones_ode'][LANGUAGE_NONE][$delta]['remove_button']['#access'] = FALSE;
        // Disable author's fields.
        $form['field_contribuciones_ode'][LANGUAGE_NONE][$delta]['field_correo_electr_nico']['#disabled'] = TRUE;
        $form['field_contribuciones_ode'][LANGUAGE_NONE][$delta]['field_organizaci_n']['#disabled'] = TRUE;
        $form['field_contribuciones_ode'][LANGUAGE_NONE][$delta]['field_contribuidor']['#disabled'] = TRUE;
      }
    }
    // Remove 'add more' button.
    $form['field_contribuciones_ode'][LANGUAGE_NONE]['add_more']['#access'] = FALSE;
  }

  //Publish as organization field is built into ag_section_post.module form_alter. Submit action too

  //Add element validate for field_archivos_a_adjuntar for checking required field. Owns validate for administration is jumped
  $form['field_archivos_a_adjuntar']['#element_validate'][] = 'ag_visualization_ode_form_fields_validate';

  //If user enters a contributor, its fields must be filled.
  $form['actions']['submit']['#validate'][] = 'ag_visualization_ode_form_publish_contributors_validation';

  //Publishing on a group AND faqs is not allowed.
  $form['actions']['submit']['#validate'][] = 'ag_visualization_ode_check_groups';


  //This first validate is now unused. Publishing method already validates ODE.
  //TODO: FOR NOW, editing wont upload anything, just edits basic info of the node.
  //$form['actions']['submit']['#validate'][] = 'ag_visualization_ode_form_publish_ode_webservice_validate';
  if (!isset($form['nid']['#value'])) {
    $form['actions']['submit']['#validate'][] = 'ag_visualization_ode_form_publish_ode_webservice_publish';
  }
  // With the option to save an ODE as draft, ODE will be first on Drupal and then sent it to solr.
  elseif ($form['#node']->status == NODE_NOT_PUBLISHED) {
      $form['actions']['submit']['#validate'][] = 'ag_visualization_ode_form_publish_ode_webservice_publish';
  }

  // Load progressbar and javascript setting variable after build form
  $form['#after_build'][] = '_load_progressbar_after_build';

  // Force field group required label
  $form['#groups']['group_tipo_de_recurso']->format_settings['instance_settings']['description'] .= ' <span class="form-required">*</span>';

  // Parse ode file mimetype with orchestrator resource type
  if (isset($_SESSION['mimetype']) && $_SESSION['mimetype'] != 'zip') {
    $resource_types = get_resource_type_from_mimetype($_SESSION['mimetype']);
    $resource_types = explode(',', $resource_types);
    foreach ($resource_types as $type) {
      $term = array_shift(taxonomy_get_term_by_name($type, 'tipo_de_recurso'));
      if ($term) {
        $form['field_resource_type'][LANGUAGE_NONE]['#default_value'][] = _taxonomy_get_tid_from_term($term);
      }
    }
  }

  // Configure license.
  // Comercial use.
  $comercial_use = $form['field_comercial_use'][LANGUAGE_NONE]['#default_value'];
  // Allow modifications.
  $allow_modifications = $form['field_allow_modifications'][LANGUAGE_NONE]['#default_value'];

  $form['current_license'] = array(
    '#type' => 'item',
    '#markup' => ag_visualization_ode_get_license_link($allow_modifications, $comercial_use),
  );

  // Add to fieldset group_license.
  $form['#group_children']['current_license'] = 'group_license';

  // Enable AJAX calls in this form.
  callback_author_autocomplete($form, $form_state);
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'ag_visualization_ode') . '/js/ode_authors.js',
  );
}

/*
 * Return resource types from upload file mimetype
 * @param $mimetype
 */
function get_resource_type_from_mimetype($mimetype) {
  $resource_type = array(
    'jpg' => 'Fotografía,Ilustración',
    'jpeg' => 'Fotografía,Ilustración',
    'png' => 'Fotografía,Ilustración',
    'gif' => 'Fotografía,Ilustración',
    'wma' => 'Video,Animación',
    'mpg' => 'Video,Animación',
    'avi' => 'Video,Animación',
    'flv' => 'Video,Animación',
    'pdf' => 'Texto narrativo',
    'doc' => 'Texto narrativo',
    'docx' => 'Texto narrativo',
    'txt' => 'Texto narrativo',
    'rtf' => 'Texto narrativo',
    'ods' => 'Texto narrativo',
    'xls' => 'Tabla',
    'xlsx' => 'Tabla',
    'csv' => 'Tabla',
    'odt' => 'Tabla',
    'mp3' => 'Música,Efecto sonoro',
    'html' => 'Hipertexto',
    'odp' => 'Presentación multimedia',
    'ppt' => 'Presentación multimedia',
    'pps' => 'Presentación multimedia',
  );

  return $resource_type[$mimetype];
}

/*
 *  Load progressbar and javascript setting variable after build form for load when the form is reload from validate process
 * @param $form
 */
function _load_progressbar_after_build($form, $form_state) {

  if (!$form_state['rebuild']) {
    global $language;
    //Load jQuery UI Progressbar and create setting variable
    drupal_add_library('system', 'ui.progressbar');

    $label_language = isset($form['nid']['#value']) ? $language->language : LANGUAGE_NONE;

    $fields = array(
      'titulo' => '#edit-title-field-' . $label_language . '-0-value',
      'idioma' => '#edit-field-general-language-' . $label_language,
      'descripcion' => '#edit-field-descripci-n-' . $label_language . '-0-value',
      'conocimiento_previo' => '#edit-field-conocimiento-previo-' . $label_language . '-0-value',
      'objetivos_didacticos' => '#edit-field-objetivos-did-cticos-' . $label_language . '-0-value',
      // field_keywords field comes everytime with und language.
      'etiquetas' => 'field_keywords[und]',
      // Archivo_adjunto field comes everytime with und language.
      'archivo_adjunto' => 'field_archivos_a_adjuntar[und][0][field_nombre_archivo][und][0][value]',
      // All author fields come everytime with UND language
      'nombre_autor' => 'edit-field-contribuciones-ode-und-0-field-contribuidor-und-0-value',
      'correo_autor' => 'edit-field-contribuciones-ode-und-0-field-correo-electr-nico-und-0-email',
      'organizacion_autor' => 'field_contribuciones_ode[und][0][field_organizaci_n][und][0][value]',
      'competencias' => '',
      'accesibilidad' => '',
      'area_conocimiento' => '#edit_field_knowledge_area_und_chosen',
      'contexto_educativo' => '#edit_field_learning_context_und_chosen',
      'recurso_educativo' => 'field_resource_type[und]',
      'recurso_aprendizaje' => 'field_recurso_de_aprendizaje[und]',
      'idioma_destinatario' => '#edit-field-educational-language-und',
      'imagen_miniatura' => '#edit-field-imagen-miniatura-und-0-remove-button',
      'comunidades' => '#edit_og_group_ref_und_0_default_chosen',
    );

    drupal_add_js(array('nexusTheme' => array('fields' => $fields)), 'setting');
  }

  return $form;
}

/**
* Function to improve code distribution. It hides old LOM-ES categories from user, and those with a fixed value.
* No need to remove these fields yet, just in case our client request them back.
*/
function ag_visualization_ode_hide_ode_fields(&$form) {
  //Aggregation level is calculated before sending to solr. Cant be selected by user for now.
  if (isset($form['field_nivel_de_agregacion'])) {
    $form['field_nivel_de_agregacion']['#access'] = FALSE;
  }

  //Replaced by resourcetype
  if (isset($form['field_recurso_educativo'])) {
    $form['field_recurso_educativo']['#access'] = FALSE;
  }

  //Field Arbol_curricular is now hidden. Old taxonomy categories are replaced by new ones, but also kept alive just in case a LOM-ES change is requested.
  if (isset($form['field_arbol_curricular'])) {
    $form['field_arbol_curricular']['#access'] = FALSE;
  }

  //Field Nivel_educativo is now hidden. Old taxonomy categories are replaced by new ones, but also kept alive just in case a LOM-ES change is requested.
  if (isset($form['field_nivel_educativo'])) {
    $form['field_nivel_educativo']['#access'] = FALSE;
  }
}

/**
 * Custom validate callback for groups check. hook_node_validate() is not being called for some reason.
 */
function ag_visualization_ode_check_groups(&$form, &$form_state) {
  $groups_number = count($form_state['values']['og_group_ref']['und']);
  $is_in_faq = FALSE;
  $is_in_procomun = FALSE;

  //Check if procomun social network is selected
  $global_procomun = variable_get('global_community_procomun', 0);

  foreach ($form_state['values']['og_group_ref']['und'] as $value) {
    $is_in_faq = $is_in_faq || ($value['target_id'] == FAQS);
    $is_in_procomun = $is_in_procomun || ($value['target_id'] == $global_procomun);
  }

  if (!$is_in_procomun && !$is_in_faq && $groups_number >= 1) {
    form_set_error('og_group_ref', t('At least the Procomún community must be selected'));
  }

  if ($is_in_faq && $groups_number > 1) {
    form_set_error('faq_validation_groups', t('You can\'t publish a content in Help and FAQ in addition with other communities'));
  }

  if ($is_in_faq && $groups_number == 1 && !og_user_access('node', FAQS, 'administer group')) {
    form_set_error('faq_validation_admin', t('Only administrators can publish on this community'));
  }
}

/**
 * Custom validate callback to check if certified button is checked when saving as draft.
 */
function ag_visualization_ode_check_certified_value(&$form, &$form_state) {
  // Only check field_certified value because this validate only runs on save as draft submit.
  if ($form_state['values']['field_certified'][LANGUAGE_NONE][0]['value']) {
    form_set_error('field_certified', t('You can\'t mark as certified a draft learning resource'));
  }
}

/**
 * Custom validate function for checking groups in zip form
 */
function publish_new_ode_form_check_groups($form, &$form_state) {
  //Check if this ODE is being published in FAQ and other group at the same time
  $groups = $form_state['values']['groups'];
  //Check if procomun social network is selected
  $global_procomun = variable_get('global_community_procomun', 0);

  if (!in_array($global_procomun, array_keys($groups)) && !in_array(FAQS, array_keys($groups)) && count($groups) >=1) {
    form_set_error('groups', t('At least the Procomún community must be selected'));
  }

  if (in_array(FAQS, array_keys($groups)) && (count($groups) != 1)) {
    form_set_error('ODE_FAQ_ERROR', t('You can\'t publish content in FAQs and Help and in other group at the same time'));
  }
}

/**
* Custom validate callback for contributors. Only two fields are required if user fills any field.
* Normal required fields would not work, as those validations always require an author to be inserted.
* In our case, this field is not required, and fields may be empty. But if any of the three fields has any text,
* mail and name are required.
*/
function ag_visualization_ode_form_publish_contributors_validation(&$form, &$form_state) {
  //Search through field_collection, and require two specific fields only if something was fulfilled.
  $contributors = $form_state['values']['field_contribuciones_ode'][LANGUAGE_NONE];
  foreach ($contributors as $key => $value) {
    if (!is_numeric($key)) {
      continue;
    }

    //Take the three fields values if they exist.
    $name_surname = isset($value['field_contribuidor'][LANGUAGE_NONE][0]['value']) ? $value['field_contribuidor'][LANGUAGE_NONE][0]['value'] : '';
    $email = isset($value['field_correo_electr_nico'][LANGUAGE_NONE][0]['email']) ? $value['field_correo_electr_nico'][LANGUAGE_NONE][0]['email'] : '';
    $org = isset($value['field_organizaci_n'][LANGUAGE_NONE][0]['value']) ? $value['field_organizaci_n'][LANGUAGE_NONE][0]['value'] : '';

    //Check if something is not empty.
    if (!empty($name_surname) || !empty($email) || !empty($org)) {
      //Then, at least name_surname and mail MUST be fulfilled. Else, notify to please delete the fields.
      if (empty($name_surname)) {
        form_set_error('field_contribuciones_ode][' . LANGUAGE_NONE . '][' . $key . '][field_contribuidor',
                       t('Please enter an author name'));
      }
      if (empty($email)) {
        form_set_error('field_contribuciones_ode][' . LANGUAGE_NONE . '][' . $key . '][field_correo_electr_nico',
                       t('Please enter an author mail'));
      }
    }
  }
}

/**
* Custom validate callback for ode creation form. Validated form by webservice request.
* DEPRECATED. Publish always validate too. Needs miniature image and incomplete zip.
*/
function ag_visualization_ode_form_publish_ode_webservice_validate(&$form, &$form_state) {
  $errors = form_get_errors();

  //This last validation should only send data, if previous ones were ok.
  if (!$errors) {
    $OS_orchestrator_processor = new OS_orchestrator_processing();
    $ode = $OS_orchestrator_processor->get_arguments_from_node_form($form_state['values']);

    // Parse uploaded files (field_collection) fids,  and send them to service code.
    $files_fids = array();
    if (isset($form_state['values']['field_archivos_a_adjuntar']['und'])) {
      $files_fids = ag_visualization_ode_process_files_field_collection($form_state['values']['field_archivos_a_adjuntar']['und']);
    }

    $result = '';
    if (!empty($ode)) {

      //Send request
      $OS_orchestrator_publisher = new OS_orchestrator_publisher();
      $result = $OS_orchestrator_publisher->validate_ode_form($files_fids, $ode);
      $code = webservice_result_notify_user_if_needed($result, $ode['title']);
      return $code;
    }
    else {
      form_set_error('form', t('Error detected while processing values'));
    }
  }
  return FALSE;
}

/**
* Custom validate callback for ode creation form. Validates AND publishes form by webservice request.
*/
function ag_visualization_ode_form_publish_ode_webservice_publish(&$form, &$form_state) {
  $errors = form_get_errors();

  //This last validation should only send data, if previous ones were ok.
  if (!$errors) {

    // Load keywords taxonomy terms for draft direct publication.
    if (!empty($form_state['values']['field_keywords'])) {
      foreach ($form_state['values']['field_keywords'][LANGUAGE_NONE] as $key => $term) {
        if (isset($term['tid']) && $term['tid'] != 'autocreate' && !isset($term['name'])) {
          $term = (Array) taxonomy_term_load($term['tid']);
          $form_state['values']['field_keywords'][LANGUAGE_NONE][$key] = $term;
        }
      }
    }

    //Parse form_state and turn into webservice arguments structures
    $OS_orchestrator_processor = new OS_orchestrator_processing();
    $ode = $OS_orchestrator_processor->get_arguments_from_node_form($form_state['values']);

    // Parse uploaded files (field_collection) fids,  and send them to service code.
    $files_fids = array();
    if (isset($form_state['values']['field_archivos_a_adjuntar']['und'])) {
      $files_fids = ag_visualization_ode_process_files_field_collection($form_state['values']['field_archivos_a_adjuntar']['und']);
    }

    //Send image
    $file_image_fid = '';
    if (!empty($form_state['values']['field_imagen_miniatura']['und'][0]['fid']) && is_numeric($form_state['values']['field_imagen_miniatura']['und'][0]['fid'])) {
      $file_image_fid = $form_state['values']['field_imagen_miniatura']['und'][0]['fid'];
    }

    //Send incomplete ODE as ZIP Scorm if exists.
    $file_zip_fid = '';
    if (!empty($form_state['test_zip_ode']) && is_numeric($form_state['test_zip_ode'])) {
      $file_zip_fid = $form_state['test_zip_ode'];
    }

    $result = '';
    if (!empty($ode)) {
      //Send request
      $OS_orchestrator_publisher = new OS_orchestrator_publisher();
      $result = $OS_orchestrator_publisher->publish_ode_form($files_fids, $ode, $file_image_fid, $file_zip_fid);

      if (isset($result->return->responseCode) && $result->return->responseCode == 'OK' && isset($result->return->documentId)) {
        // Update field_solrid in Drupal and SOLR if no errors
        update_ode_if_validation_success($form_state, $result);
        $code = webservice_result_notify_user_if_needed($result, $ode['title']);
        return $code;
      }
      else {
        // Return error message if error.
        form_set_error('form', $result->return->message);

        return $result;
      }
    }
    else {
      form_set_error('form', t('Error detected while processing values'));
    }
  }
  return FALSE;
}

/**
* Once a request comes back from validation, if it succeeded, update SolrID in content-type.
* No updates to solr image. Removed from this method.
*/
function update_ode_if_validation_success(&$form_state, $result) {
  //Update SolrID from publishing response if it was OK.
  if (isset($result->return->responseCode) && $result->return->responseCode == 'OK' && isset($result->return->documentId)) {
    //Field SolrID has no translation.
    $form_state['values']['field_solrid']['und'][0]['value'] = $result->return->documentId;

    //Removed image sent from this place. Solr will take miniature image from agrega.

    //In fact, we should remove all files in order to avoid saving them in drupal. Agrega has them.
    ag_visualization_ode_set_collection_files_as_temporary($form_state['values']['field_archivos_a_adjuntar'][LANGUAGE_NONE]);
    ag_visualization_ode_set_file_as_temporary($form_state['values']['field_imagen_miniatura'][LANGUAGE_NONE][0]);
  }
}

/**
* Process field_collection of uploaded files from form_state, and gather all fids and filenames.
* @return Array with fid from file as key, and custom filename as value
*         (not the uploaded file filename, but the one chosen by user in aditional text field)
*/
function ag_visualization_ode_process_files_field_collection($form_state_files) {
  $files_fids = array();

  foreach ($form_state_files as $key => $value) {
    //Skip add more button/option in this array.
    if ($key === 'add_more') {
      continue;
    }

    //Gather all fids from files.
    if (isset($value['field_archivo']['und'][0]['fid'])) {
      $fid = $value['field_archivo']['und'][0]['fid'];
      $filename = isset($value['field_nombre_archivo']['und'][0]['value']) ? $value['field_nombre_archivo']['und'][0]['value'] : '';
      $files_fids[$fid] = $filename;
    }
    // When we are sending draft ODE it comes that way,
    elseif (isset($value['value'])) {
      // Get field collection item from id. At the moment this field is kind of "broken".
      // We tested that we can't get the values with entity_metadata_wrapper for this field collection
      // So this is the best way we came for get these values.
      $field_collection = field_collection_item_load($value['value']);
      $fid = $field_collection->field_archivo[LANGUAGE_NONE][0]['fid'];
      $filename = $field_collection->field_nombre_archivo[LANGUAGE_NONE][0]['value'];

      $files_fids[$fid] = $filename;
    }
  }
  if (isset($files_fids[0])) {
    unset($files_fids[0]);
  }

  return $files_fids;
}

/**
* Updates specified solr_id ode in Solr, updating field "preview" with relative path to drupal-hosted ode image.
*/
function ag_visualization_ode_update_solr_ode_preview($solr_id, $file) {
  //Update solr preview field:
  if (isset($file->uri)) {
    //Get file uri or entire path. drupal_realpath: path with server folder structure. file_create_url: external url.
    $uri = $file->uri;
    $external_url = file_create_url($uri);

    //Remove host info
    $url = parse_url($external_url);
    $path = $url['path'];

    //Created new service in solr, to update preview images for odes.
    if (module_exists('orchestrator_services')) {
      $OS_orchestrator_inyection = new OS_orchestrator_inyection();
      list($status, $result) = $OS_orchestrator_inyection->UpdatePreview($solr_id, $path);

      //No need to notify user if solr failed. Image was saved to node, but not Solr.
      if (empty($status)) {
        watchdog("ODE image upload", t('Image could not be uploaded to Solr. Solr_ID: @id, Image path: @imagepath',  array('@id' => $solr_id, '@imagepath' => $path)));
      }
    }

  }
}

function _ode_get_groups() {
  $groups = array();

  if(function_exists('og_get_groups_by_user')) {
    $og_groups = og_get_groups_by_user();
    $groups = array();
    if(isset($og_groups['node'])) {
      $original_groups = $og_groups['node'];
      foreach($original_groups as $key => $value) {
        $groups[$key] = DrupalToolKit::getNodeTitle(array($value))->title;
      }
    }
  }
  return $groups;
}

/**
* If taxonomy select field is hierarchically ordered with "-" before any child,
* this function orders first level alphabetically, leaving deeper levels intact.
* Applies to weird customer request to order alphabetically the taxonomy but only on form.
* Facet will need taxonomy normal weights, so they must remain as they are.
* Also, it won't load any taxonomy or translation, using normal #options to avoid more load.
*/
function ag_visualization_ode_order_taxonomy_first_level_alphabetically(&$options) {
  //Remove children and store in separate array.
  $parenting = array();
  $last_parent = '';
  foreach ($options as $tid => $name) {
    if (strpos($name, '-') === 0 && is_numeric($last_parent_tid)) {
      //Child. Save in parents array.
      $parenting[$last_parent_tid][$tid] = $name;
      //Unset child.
      unset($options[$tid]);
    }
    else {
      //Add this parent to candidate.
      $last_parent_tid = $tid;
    }
  }
  //Order parents.
  asort($options);

  $tmp_options = array();
  foreach($options as $key => $value) {
    $tmp_options[$key] = $value;
    if (!empty($parenting[$key])) {
      $tmp_options = $tmp_options + $parenting[$key];
    }
  }

  //Override options with this custom-alphabetic sorted array. Ignore weights of taxonomy, that only applies to facet block.
  $options = $tmp_options;
}

/**
* Remove all files from ode node form, even miniature image. They are stored in Agrega,
* not in Drupal, so file->status (persistence of file) should not be enabled by normal node form submit.
*/
function ag_visualization_ode_set_collection_files_as_temporary(&$file_fields) {
  //Remove fid from both field_collection and its entity.
  foreach($file_fields as $key => $value) {
    if (is_numeric($key) && isset($file_fields[$key]['field_archivo'][LANGUAGE_NONE][0]['fid'])) {
      ag_visualization_ode_set_file_as_temporary($file_fields[$key]['field_archivo'][LANGUAGE_NONE][0]);
    }
    if (is_numeric($key) && isset($file_fields[$key]['entity']->field_archivo[LANGUAGE_NONE][0]['fid'])) {
      ag_visualization_ode_set_file_as_temporary($file_fields[$key]['entity']->field_archivo[LANGUAGE_NONE][0]);
    }
  }
}

/**
* Simply set null to a managed_file field, in order to leave fid as it was initially uploaded:
* With file->status = 0. This avoids node form from enabling status and forcing permanent status to the file.
*/
function ag_visualization_ode_set_file_as_temporary(&$file_location) {
  $file_location['fid'] = NULL;
}


/**
 * Custom #element validate for fields attach to ODE with form
 */
function ag_visualization_ode_form_fields_validate($element, &$form_state, $form) {
  // Get field_og_permissions_level field & og_roles_permissions values. Skip validation on hidden field by access param
  if ($element['#access'] !== FALSE && empty($form_state['values']['field_archivos_a_adjuntar'][LANGUAGE_NONE][0]['field_archivo'][LANGUAGE_NONE][0]['fid'])) {
    form_set_error('field_archivos_a_adjuntar' , t('The field %field is required.', array('%field' => $element[LANGUAGE_NONE]['#title'])));
  }

  if ($element['#access'] !== FALSE && empty($form_state['values']['field_archivos_a_adjuntar'][LANGUAGE_NONE][0]['field_nombre_archivo'][LANGUAGE_NONE][0]['value'])) {
    form_set_error('field_archivos_a_adjuntar' , t('The field %field is required.', array('%field' => $element[LANGUAGE_NONE]['#title'])));
  }

  // Validate if check at least one item of "Resource type" or "Learning resource"
  if ($element['#access'] !== FALSE && !validate_resource_type_fill($form_state) && empty($form_state['values']['field_recurso_de_aprendizaje'][LANGUAGE_NONE][0]['tid'])) {
    form_set_error('field_resource_type', t('You must select at least one item of any of the blocks in section resource type'));
  }
}

/**
 * Auxiliary function: check if there is any selected item for the field field_resource_type
 *
 * @param $form_state
 */
function validate_resource_type_fill($form_state) {
  if (isset($form_state['values']['field_resource_type'][LANGUAGE_NONE]) && !empty($form_state['values']['field_resource_type'][LANGUAGE_NONE])) {
    foreach ($form_state['values']['field_resource_type'][LANGUAGE_NONE] as $resource) {
      if ($resource != 0) {
        return TRUE;
      }
    }
  }

  return FALSE;
}

/**
 * Custom function to get publish as organization block form
 *
 * @param $org_ids
 *  Organizations uid
 */
function ag_visualization_ode_publish_organization_form(&$form, $org_ids) {
  if (!empty($org_ids)) {
    //Build orgs options. First a default value and then user organization
    $orgs_options = array(t('No publish as organization'));
    $org_data = ag_section_profile_users_get_organization_data($org_ids);

    $org_opt = array();
    foreach ($org_data as $org_id => $org_data) {
      $org_opt[$org_id] = t('Publish as @org_name', array('@org_name' => $org_data['name']));
    }
    $orgs_options += $org_opt;

    $form['publish_organization_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Publish this content as a organization'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 15,
    );

    $form['publish_organization_fieldset']['publish_organization'] = array(
      '#type' => 'radios',
      '#options' => $orgs_options,
      '#title' => t('My organizations'),
      '#default_value' => 0,
    );
  }
}

/**
 * Custom function with confirmation delete ode form
 */
function ode_delete_form($form, $form_state) {

  $form['solrid'] = array(
    '#type' => 'value',
    '#value' => $form_state['build_info']['args'][0]['id'],
  );

  $form['mec'] = array(
    '#type' => 'value',
    '#value' => $form_state['build_info']['args'][0]['mecIdentifierStr'],
  );

  $path_options = array('path' => drupal_get_destination());

  return confirm_form($form, t('Are you sure you want to delete resource?'), $path_options);
}

/**
 * Implements FORM_ID_submit().
 */
function ode_delete_form_submit($form, &$form_state) {
  global $user;

  //Check solrid and mec
  if (!empty($form_state['values']['solrid']) && !empty($form_state['values']['mec'])) {
    //Call to orchestator method
    $solrid = $form_state['values']['solrid'];
    $mec = $form_state['values']['mec'];
    $OS_orchestrator_authoring = new OS_orchestrator_authoring();
    list($status, $result) = $OS_orchestrator_authoring->deleteOde($mec, $user->mail);

    if ($status && isset($result->data)) {
      //Json decode
      $data = json_decode($result->data);

      if (isset($data->httpResponseCode) && $data->httpResponseCode == 200) {
        $node = ode_light_node_load($solrid);
        try {
          // Edit special values with a wrapper.
          $ewrapper = entity_metadata_wrapper('node', $node);

          //Unpublished ode in drupal
          $ewrapper->status->set(0);
          $ewrapper->save();

          drupal_set_message(t('Resource delete successfully.'), 'status');

          //redirect user to search ode form
          $commands = array();
          $commands[] = ctools_ajax_command_redirect('ode-search', 0 , array('query' => array('type' => 'LEARNING_RESOURCE')));
          print ajax_render($commands);
          exit;
        }
        catch (EntityMetadataWrapperException $e) {
          drupal_set_message(t('Error deleting resource in procomun'), 'error');
        }
      }
      else {
        drupal_set_message(t('Error deleting selected resource'), 'error');
      }
    }
    else {
      drupal_set_message(t('Error deleting resource'), 'error');
    }
  }
  else {
    drupal_set_message(t('No resource selected'), 'error');
  }
}

/////////////
/// HOOKS ///
/////////////

/**
 * Implements hook_field_widget_form_alter().
 */
function ag_visualization_ode_field_widget_form_alter(&$element, &$form_state, $context) {
  if ($context['form']['#node']->type == 'ode' || $context['form']['#node']->type == 'post') {
    if ($element['#field_name'] == 'field_contribuciones_ode') {
      switch ($form_state['triggering_element']['#field_name']) {
        case 'field_contribuidor':
          $author_full_name = $form_state['triggering_element']['#value'];
          if (preg_match('/\((\d+)\)/', $author_full_name, $matches)) {
            $author = $matches[1];
          }
          else {
            $author = callback_check_user_by_full_name($author_full_name);
          }
          break;

        case 'field_correo_electr_nico':
          $author_email = $form_state['triggering_element']['#value'];
          $author = DrupalToolKit::getUserDataByMail($author_email, array('uid'))->uid;
          break;
      }

      // Add 'See profile' button.
      if (isset($author) && !empty($author)) {
        $options = array('attributes' => array('target' => '_blank'));
        $link = l(t('See profile'), "profile/{$author}/public", $options);
        $button = array(
          'show_profile' => array('#markup' => $link),
          '#theme_wrappers' => array('container'),
          '#attributes' => array('class' => 'profile-button-ode'),
        );
        $element['show_profile_btn']['#markup'] = render($button);
        $element['show_profile_btn']['#weight'] = 10;
      }
    }
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function ag_visualization_ode_preprocess_field_multiple_value_form(&$variables) {
  $vars = &$variables['element'];
  if (isset($vars['#field_name']) && $vars['#field_name'] == 'field_contribuciones_ode') {
    // Change the default label 'Add another item' to 'Add another author'.
    $vars['add_more']['#value'] = t('Add another author');

    $lang = LANGUAGE_NONE;
    foreach ($vars as $key => $value) {
      if (is_numeric($key)) {
        foreach ($value as $field => $field_value) {
          switch ($field) {
            case 'field_contribuidor':
              $author_full_name = $field_value[$lang][0]['value']['#value'];
              if (preg_match('/\((\d+)\)/', $author_full_name, $matches)) {
                $author = $matches[1];
              }
              else {
                $author = callback_check_user_by_full_name($author_full_name);
              }
              break;

            case 'field_correo_electr_nico':
              $author_email = $field_value[$lang][0]['email']['#value'];
              $author = DrupalToolKit::getUserDataByMail($author_email, array('uid'))->uid;
              break;
          }
        }

        // Add 'See profile' button.
        if (isset($author) && !empty($author)) {
          $options = array('attributes' => array('target' => '_blank'));
          $link = l(t('See profile'), "profile/{$author}/public", $options);
          $button = array(
            'show_profile' => array('#markup' => $link),
            '#theme_wrappers' => array('container'),
            '#attributes' => array('class' => 'profile-button-ode'),
          );
          $vars[$key]['show_profile_btn']['#markup'] = render($button);
          $vars[$key]['show_profile_btn']['#weight'] = 10;
        }
      }
    }
  }
}

/////////////////
/// CALLBACKS ///
/////////////////

/**
 * TODO: Need comments.
 *
 * Callback for ag_visualization_ode_form_ode_node_form_alter().
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   An associative array containing the current state of the form.
 *
 * @ingroup callbacks
 */
function callback_author_autocomplete(&$form, &$form_state) {
  $lang = LANGUAGE_NONE;
  $field = &$form['field_contribuciones_ode'][$lang];
  foreach ($field as $key => $value) {
    if (is_numeric($key)) {
      // Enable autocomplete on this following fields.
      $field[$key]['field_contribuidor'][$lang][0]['value']['#autocomplete_path'] = 'author/autocomplete/fullname';
      $field[$key]['field_correo_electr_nico'][$lang][0]['email']['#autocomplete_path'] = 'author/autocomplete/email';

      // Declare wrapper.
      $wrapper_id = "ajax-autocomplete-author-{$key}";
      $wrapper = array(
        'callback' => 'callback_autocomplete_author_information',
        'wrapper' => $wrapper_id,
      );

      $field[$key]['field_contribuidor'][$lang][0]['value']['#ajax'] = $wrapper;
      $field[$key]['field_correo_electr_nico'][$lang][0]['email']['#ajax'] = $wrapper;

      // Declare container.
      $field[$key]['#prefix'] = '<div id="' . $wrapper_id . '">';
      $field[$key]['#suffix'] = '</div>';
    }
  }

  // Get the current field collection item to known which item must be filled.
  $current_key = $form_state['triggering_element']['#field_parents'][2];
  if (isset($current_key) && is_numeric($current_key)) {
    // Hide 'weight' field for the current field collection item.
    hide($form['field_contribuciones_ode'][$lang][$current_key]['_weight']);

    // Set values for the given field collection item.
    callback_author_autocomplete_set_values($form, $form_state, $current_key);
  }
}

/**
 * TODO: Need comments.
 *
 * Callback for callback_author_autocomplete().
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @param $form_state
 *   An associative array containing the current state of the form.
 *
 * @return mixed
 *   An associative array containing a portion of the form which will be
 *   replaced.
 *
 * @ingroup callbacks
 */
function callback_autocomplete_author_information($form, $form_state) {
  // Get the current field collection item to known which item must be returned
  // as replaced item.
  $current_key = $form_state['triggering_element']['#field_parents'][2];
  return $form['field_contribuciones_ode'][LANGUAGE_NONE][$current_key];
}

/**
 * TODO: Need comments.
 *
 * Callback for callback_author_autocomplete().
 *
 * @param $form
 * @param $form_state
 * @param string $lang
 *
 * @ingroup callbacks
 */
function callback_author_autocomplete_set_values(&$form, &$form_state, $key, $lang = LANGUAGE_NONE) {
  // Simplify access to form elements through the use of passing by reference.
  $field = &$form['field_contribuciones_ode'][$lang];
  $field_state = &$form_state['input']['field_contribuciones_ode'][$lang];

  switch ($form_state['triggering_element']['#field_name']) {
    case 'field_contribuidor';
      $author_full_name = $field_state[$key]['field_contribuidor'][$lang][0]['value'];
      $author = (preg_match('/\((\d+)\)/', $author_full_name, $matches)) ? $matches[1] : callback_check_user_by_full_name($author_full_name);

      if (isset($author) && !empty($author)) {
        // Set value for author email.
        $author_email = DrupalToolKit::getUserData($author, array('mail'))->mail;
        $field[$key]['field_correo_electr_nico'][$lang][0]['email']['#value'] = $author_email;

        // Override author fullname.
        $author_full_name = ag_section_profile_users_get_name_surname_cached($author);
        $field[$key]['field_contribuidor'][$lang][0]['value']['#value'] = $author_full_name;

        // Set value for author organization.
        $author_organization = callback_get_user_organization($author);
        $field[$key]['field_organizaci_n'][$lang][0]['value']['#value'] = $author_organization;
        $field[$key]['field_organizaci_n'][$lang][0]['#disabled'] = TRUE;

        // Set author role.
        $author_role = key(taxonomy_get_term_by_name('Autor', 'rol_contribuidor'));

        // Autocompletes.
        $form_state['autocompletes'][$key]['author_autocompleted'] = TRUE;
        $form_state['autocompletes'][$key]['email_autocompleted'] = TRUE;
      }
      else {
        // Set author role.
        $author_role = key(taxonomy_get_term_by_name('Editor de publicación', 'rol_contribuidor'));

        // Check the field 'Organization'.
        if (empty($field_state[$key]['field_organizaci_n'][$lang][0]['value'])) {
          $field[$key]['field_organizaci_n'][$lang][0]['value']['#value'] = '';
        }

        if ($form_state['autocompletes'][$key]['email_autocompleted']) {
          $form_state['autocompletes'][$key]['email_autocompleted'] = FALSE;
          $field[$key]['field_correo_electr_nico'][$lang][0]['email']['#value'] = '';
        }
        $form_state['autocompletes'][$key]['author_autocompleted'] = FALSE;
      }
      break;

    case 'field_correo_electr_nico':
      $author_email = $field_state[$key]['field_correo_electr_nico'][$lang][0]['email'];
      $author = DrupalToolKit::getUserDataByMail($author_email, array('uid'));

      if (isset($author) && !empty($author)) {
        // Set value for author name.
        $author_full_name = ag_section_profile_users_get_name_surname_cached($author->uid);
        $field[$key]['field_contribuidor'][$lang][0]['value']['#value'] = $author_full_name;

        // Set value for author organization.
        $author_organization = callback_get_user_organization($author->uid);
        $field[$key]['field_organizaci_n'][$lang][0]['value']['#value'] = $author_organization;
        $field[$key]['field_organizaci_n'][$lang][0]['#disabled'] = TRUE;

        // Set author role.
        $author_role = key(taxonomy_get_term_by_name('Autor', 'rol_contribuidor'));

        // Autocompletes.
        $form_state['autocompletes'][$key]['author_autocompleted'] = TRUE;
        $form_state['autocompletes'][$key]['email_autocompleted'] = TRUE;
      }
      else {
        // Set author role.
        $author_role = key(taxonomy_get_term_by_name('Editor de publicación', 'rol_contribuidor'));

        // Check the field 'Organization'.
        if (empty($field_state[$key]['field_organizaci_n'][$lang][0]['value'])) {
          $field[$key]['field_organizaci_n'][$lang][0]['value']['#value'] = '';
        }

        if ($form_state['autocompletes'][$key]['author_autocompleted']) {
          $form_state['autocompletes'][$key]['author_autocompleted'] = FALSE;
          $field[$key]['field_contribuidor'][$lang][0]['value']['#value'] = '';
        }
        $form_state['autocompletes'][$key]['email_autocompleted'] = FALSE;
      }
      break;
  }

  // Set author and editor.
  $form_state['values']['field_contribuciones_ode'][LANGUAGE_NONE][$key]['field_rol_contribuidor'][LANGUAGE_NONE][0]['tid'] = $author_role;
}

////////////////
/// DATABASE ///
////////////////

/**
 * TODO: Need comment.
 *
 * @param $user
 *   The user uid.
 *
 * @return bool
 *
 * @ingroup callbacks
 */
function callback_get_user_organization($user) {
  if(empty($user) || !is_numeric($user)) {
    return FALSE;
  }
  else {
    $query = db_select('field_data_field_organization_name', 'fdfon');
    $query->join('profile', 'p', 'fdfon.entity_id = p.pid');
    $query->join('field_data_field_organization_reference', 'fdfor', 'p.uid=fdfor.field_organization_reference_target_id');
    //$query->addField('p', 'uid', 'id');
    $query->addField('fdfon', 'field_organization_name_value', 'name');
    $query->condition('fdfor.entity_id', $user);
    $result = $query->execute();

    return $result->fetchField();
  }
}

/**
 * TODO: Need comment.
 *
 * @param $full_name
 *
 * @return bool $query
 *
 * @ingroup callbacks
 */
function callback_check_user_by_full_name($full_name) {
  $sql = db_select('users', 'u');
  $sql->join('profile', 'p', 'p.uid = u.uid');
  $sql->join('field_data_field_name_surname', 'ns', 'ns.entity_id = p.pid');
  $sql->join('field_data_field_profile_name', 'pn', 'pn.entity_id = ns.field_name_surname_value');
  $sql->join('field_data_field_profile_surname', 'ps', 'ps.entity_id = ns.field_name_surname_value');
  $sql->addField('u', 'uid');
  $sql->where("CONCAT(pn.field_profile_name_value, ' ', ps.field_profile_surname_value) = :full_name", array(':full_name' => $full_name));
  $query = $sql->execute()->fetchField();

  return (!empty($query)) ? $query : FALSE;
}
