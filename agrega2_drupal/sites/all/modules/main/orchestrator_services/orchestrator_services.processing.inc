<?php

/**
 * @file
 * Orchestrator services - field processing from form_state to solr arguments in both ways.
 * Main functions are:
 *   - prepopulate_arguments_in_node_form:  From solr to form.
 *   - get_arguments_from_node_form         From form to solr.
 */

/**
 * Class representing operations in orchestrator
 */
class OS_orchestrator_processing {

  function __construct() {

  }

/**
* Process zip file if exists in form or GET parameters, then, add them to files section as
* field collection. Only files without folders will be imported.
*/
public function prepopulate_non_catalog_files(&$form, &$form_state) {
  global $user;

  //Get zip if exists.
  if (isset($_SESSION['ode_zip_fid'])) {
    $ode_zip_fid = $_SESSION['ode_zip_fid'];
    //Unset session, just in case user navigates elsewhere and returns to form.
    unset($_SESSION['ode_zip_fid']);
  }
  else if (isset($form_state['ode_zip_fid'])){
    $ode_zip_fid = $form_state['ode_zip_fid'];
  }

  //Some error might have happened if no fid arrived.
  if (empty($ode_zip_fid)) {
    return FALSE;
  }

  if ($_SESSION['ode_zip_no_catalog'] == 2) {
    $fids_to_prepopulate = $ode_zip_fid;
    if (!empty($fids_to_prepopulate)) {
      drupal_set_message(
        t('Multiple single files detected. Its @numfiles files will be extracted and added to this form.',
          array('@numfiles' => count($fids_to_prepopulate)))
      );
    }
  }
  else {
    //Extract root files from zip, save them as managed files by drupal, and return fids.
    $fids_to_prepopulate = $this->extract_and_get_zip_root_fids($form, $ode_zip_fid[0], $_SESSION['mimetype']);

    if (!empty($fids_to_prepopulate)) {
      drupal_set_message(
        t('Compressed file without catalog files detected. Its @numfiles root folder files will be extracted and added to this form.',
        array('@numfiles' => count($fids_to_prepopulate)))
      );
    }
    else {
      drupal_set_message(t('Not compressed single file detected. It will be extracted and added to this form.'));
    }
  }

  //PREPOPULATE FIELD COLLECTION
  //---Idea from http://drupal.stackexchange.com/a/102745. Populates a field collection with as many values as needed.---
  $items_count = count($fids_to_prepopulate);
  $field_name = 'field_archivos_a_adjuntar';
  $form_theme = $form[$field_name][LANGUAGE_NONE]['#theme'];

  $items = &$form_state['field'][$field_name][LANGUAGE_NONE];

  // Generate required number of fields collection
  if ($items_count > 1 and $items['items_count'] != $items_count) {
    $items['items_count'] = $items_count;

    $form[$field_name][LANGUAGE_NONE] = field_multiple_value_form($items['field'], $items['instance'], LANGUAGE_NONE, array(), $form, $form_state);
    // Reset theme function, as field_multiple_value_form hijacks it
    $form[$field_name][LANGUAGE_NONE]['#theme'] = $form_theme;
  }

  // Fill generated fields with data
  for ($delta = 0; $delta < $items_count; $delta++) {
    $form[$field_name][LANGUAGE_NONE][$delta]['field_archivo'][LANGUAGE_NONE][0]['#default_value']['fid'] = $fids_to_prepopulate[$delta];
    $form[$field_name][LANGUAGE_NONE][$delta]['field_nombre_archivo'][LANGUAGE_NONE][0]['value']['#default_value'] = $this->extract_name_from_file($fids_to_prepopulate[$delta]);
  }

  // Fill generated field with data when the file is a no zip single file
  if ($items_count == 0) {
    $form[$field_name][LANGUAGE_NONE][0]['field_archivo'][LANGUAGE_NONE][0]['#default_value']['fid'] = $ode_zip_fid[0];
    $form[$field_name][LANGUAGE_NONE][0]['field_nombre_archivo'][LANGUAGE_NONE][0]['value']['#default_value'] = $this->extract_name_from_file($ode_zip_fid[0]);
  }

  //---

  //Prepolulate organization field if it arrives
  if (!empty($_SESSION['publish_organization'])) {
    $form['publish_organization_fieldset']['publish_organization']['#default_value'] = $_SESSION['publish_organization'];
  }

  // Prepopulate title_field from zip file name
  if (isset($ode_zip_fid[0])) {
    $form['title_field'][LANGUAGE_NONE][0]['value']['#default_value'] = $this->extract_name_from_file($ode_zip_fid[0]);
  }

  // Prepopulate field_resource_type from file mimetype
  if ($items_count == 0) {
    // Case: no zip file
    $file = file_load($ode_zip_fid[0]);
    $mimetype = $this->extract_mimetype($file);
    if ($mimetype['status'] == 1) {
      $_SESSION['mimetype'] = $mimetype['mimetype'];
    }
  }
  else if ($items_count == 1) {
    // Case: no catalog zip file, with a single file inside
    $file = file_load($fids_to_prepopulate[0]);
    $mimetype = $this->extract_mimetype($file);
    if ($mimetype['status'] == 1) {
      $_SESSION['mimetype'] = $mimetype['mimetype'];
    }
  }
}

/*
 * Auxiliary function: extract name without extension from file name
 * @param $fid
*/
private function extract_name_from_file($fid) {
  $file = file_load($fid);
  $filename = '';
  if (isset($file->filename)) {
    $filename = explode('.', $file->filename);
    $filename = $filename[0];
  }

  return $filename;
}

/*
 * Auxiliary function: extract mimetype from file
 * @param $file
*/
public function extract_mimetype($file) {
  $result = array(
    'mimetype' => '',
    'error' => '',
    'status' => 0
  );

  if (isset($file->filename) && !empty($file->filename)) {
    $mimetype = explode('.', $file->filename);
    if (count($mimetype) > 1){
      $result['mimetype'] = drupal_strtolower(array_pop($mimetype));
      $result['status'] = 1;
    }
    else {
      $result['error'] = t('Invalid file');
    }
  }
  else {
    $result['error'] = t('Invalid file');
  }

  return $result;
}

/*
 * Auxiliary function: Validate file extensions inside zip file
 * @param $form
 * @param $fid
 */
private function zip_content_files_validate_extension($form, $fid) {
  $result = FALSE;

  $file = file_load($fid);
  if (isset($form['field_archivos_a_adjuntar'][LANGUAGE_NONE][0]['field_archivo'][LANGUAGE_NONE][0]['#upload_validators']['file_validate_extensions'][0])
      && !empty($form['field_archivos_a_adjuntar'][LANGUAGE_NONE][0]['field_archivo'][LANGUAGE_NONE][0]['#upload_validators']['file_validate_extensions'][0])) {
    $allow_extensions = explode(' ', $form['field_archivos_a_adjuntar'][LANGUAGE_NONE][0]['field_archivo'][LANGUAGE_NONE][0]['#upload_validators']['file_validate_extensions'][0]);
    // Add these types for catalog zip case.
    $allow_extensions = array_merge($allow_extensions, array('xml', 'css', 'js'));
    $file_extension = $this->extract_mimetype($file);

    if ($file_extension['status'] == 1 && in_array($file_extension['mimetype'], $allow_extensions)) {
       $result = TRUE;
    }
  }

  return $result;
}

/**
* Auxiliary function: Open zip file, and extracts any root file to temporary folder, then
* save them into drupal as managed file, and return these fids.
*/
private function extract_and_get_zip_root_fids($form, $ode_zip_fid, $mimetype) {
  //Array where fids will be stored to prepopulate form. If zip is well formed, of course.
  $fids_to_prepopulate = array();

  //Load zip.
  $file = file_load($ode_zip_fid);

  //Check if we find any catalog documents.
  if (isset($file->uri) && isset($mimetype) && $mimetype == 'zip') {
    $real_path = drupal_realpath($file->uri);

    $zip_file = new ZipArchive();
    $zip_file->open($real_path);

    //Extract only files on root folder.
    for ($i = 0; $i < $zip_file->numFiles; $i++) {
      //Get this index(file) stats.
      $stat = $zip_file->statIndex($i);

      //Get file name without folders.
      $filename = basename($stat['name']);

      //If it is in root folder, extract to uploaded_odes folder, and track/save in drupal as temporary fid.
      if ($filename === $stat['name']) {
        $tmp_folder = file_directory_temp();

        //Extract file to temp folder.
        $success = $zip_file->extractTo($tmp_folder, $filename);
        if ($success) {
          //Get content
          $content = file_get_contents($tmp_folder . '/' . $filename);
          //Save in drupal.
          $destination_uri = 'public://uploaded_odes';
          $final_file = file_save_data($content, $destination_uri . '/' . $filename, FILE_EXISTS_RENAME);

          //Delete tmp file.
          file_unmanaged_delete($tmp_folder . '/' . $filename);

          //Update file, as they are always temporary for ODEs.
          $final_file->status = 0;
          file_save($final_file);

          //Add file if it was correctly saved in drupal to a lists of fids to prepopulate form later.
          if (isset($final_file->fid)) {
            $validate = $this->zip_content_files_validate_extension($form, $final_file->fid);

            if ($validate) {
              $fids_to_prepopulate[] = $final_file->fid;
            }
            else {
              file_delete($final_file, TRUE);
              drupal_set_message(t('It did not add the file @filename. This file type is not allowed.' , array('@filename' => $final_file->filename)), 'error');
            }
          }
        }
      }
    }
    $zip_file->close();
  }

  return $fids_to_prepopulate;
}

/*
 * Auxiliary function: extract files fids when the uploaded file is a catalog zip.
 *
 * @param $form
 * @param $ode_zip_fid
 */
private function extract_and_get_catalog_zip_resources_fids($form, $ode_zip_fid) {
  // Array where fids will be stored to prepopulate form. If zip is well formed, of course.
  $fids_to_prepopulate = array(
    'content' => array(),
    'preview' => '',
    'error' => '',
    'status' => 0
  );

  // Load zip.
  $file = file_load($ode_zip_fid);

  // Check if we find any catalog documents.
  if (isset($file->uri)) {
    $real_path = drupal_realpath($file->uri);

    $zip_file = new ZipArchive();
    $zip_file->open($real_path);

    // Extract zip in the temporary folder.
    $tmp_folder = file_directory_temp();
    $full_filename = $tmp_folder . '/' . $file->filename;
    $success = $zip_file->extractTo($full_filename);

    $zip_file->close();

    if ($success) {
      // Extract files contained in imsmanifest.xml
      if (file_exists($full_filename . '/imsmanifest.xml')) {
        // Add ode resources to form.
        $imsmanifest = new SimpleXMLElement(file_get_contents($full_filename . '/imsmanifest.xml'));

        $resources = array();
        foreach ($imsmanifest->resources->resource as $resource) {
          $resources[] = $resource;
        }

        foreach ($resources as $resource) {
          $files = array();
          foreach ($resource->file as $resource_file) {
            $files[] = $resource_file;
          }

          // For each ode resource, add resource files inside to form.
          foreach ($files as $file) {
            $filename = (string)$file->attributes()->href;

            // Extract file to temp folder.
            if (file_exists($full_filename . '/' . $filename)) {
              // Get content.
              $content = file_get_contents($full_filename . '/' . $filename);
              // Save in drupal.
              $destination_uri = 'public://uploaded_odes';
              $tmp_filename = explode('/', $filename);
              $filename = array_pop($tmp_filename);
              $final_file = file_save_data($content, $destination_uri . '/' . $filename, FILE_EXISTS_RENAME);

              // Update file, as they are always temporary for ODEs.
              $final_file->status = 0;
              file_save($final_file);

              // Add file if it was correctly saved in drupal to a lists of fids to prepopulate form later.
              if (isset($final_file->fid)) {
                $validate = $this->zip_content_files_validate_extension($form, $final_file->fid);

                if ($validate) {
                  $fids_to_prepopulate['content'][] = $final_file->fid;
                }
                else {
                  file_delete($final_file, TRUE);
                  drupal_set_message(t('It did not add the file @filename. This file type is not allowed.' , array('@filename' => $final_file->filename)), 'error');
                }
              }
            }
          }
        }
      }

      // Add agrega2 preview to form.
      if (file_exists($full_filename . '/vistaPreviaAgrega.png')) {
        // Get content.
        $content = file_get_contents($full_filename . '/vistaPreviaAgrega.png');
        // Save in drupal.
        $destination_uri = 'public://uploaded_odes';
        $final_file = file_save_data($content, $destination_uri . '/vistaPreviaAgrega.png', FILE_EXISTS_RENAME);

        // Update file, as they are always temporary for ODEs.
        $final_file->status = 0;
        file_save($final_file);

        // Add file if it was correctly saved in drupal to a lists of fids to prepopulate form later.
        if (isset($final_file->fid)) {
          $fids_to_prepopulate['preview'] = $final_file->fid;
        }
      }

      // Delete zip extract temporary directory.
      $this->removeDir($tmp_folder . '/' . $file->filename);
    }
  }

  return $fids_to_prepopulate;
}

/*
 * Auxiliary function: delete a directory and its files recursively.
 *
 * @param $path
 */
private function removeDir($path) {

  // Normalise $path.
  $path = rtrim($path, '/') . '/';

  // Remove all child files and directories.
  $items = glob($path . '*');

  foreach($items as $item) {
    is_dir($item) ? $this->removeDir($item) : unlink($item);
  }

  // Remove directory.
  rmdir($path);
}

/**
* Transforms data from arguments coming from solr to node form fields.
* Loads node ode form with ode data from $_SESSION, received from orchestrator
* after sending a zip with wrong imsmanifest.
*/
public function prepopulate_arguments_in_node_form(&$form, &$form_state) {
  $ode = '';
  $ode_zip_fid = '';

  //Prepare ODE variable. Either session or form_state should have it.
  if (isset($_SESSION['ode'])) {
    $ode = (array) $_SESSION['ode'];
    //Unset session, just in case user navigates elsewhere and returns to form.
    unset($_SESSION['ode']);
  }
  else if (isset($form_state['ode'])){
    $ode = $form_state['ode'];
  }

  //Prepare ODE SCORM ZIP (wrong one, catalog null or incomplete) file descriptor. Either session or form_state should have it.
  //It is "added on the background", inside the form. No file is extracted from it, orchestrator will take care of it for now.
  //It will be sent as an optional parameter to de service, to gather both catalogs as one: this form mixed with the original from the zip.
  if (isset($_SESSION['ode_zip_fid'][0])) {
    $ode_zip_fid = $_SESSION['ode_zip_fid'][0];
    //Unset session, just in case user navigates elsewhere and returns to form.
    unset($_SESSION['ode_zip_fid'][0]);
  }
  else if (isset($form_state['ode_zip_fid'][0])){
    $ode_zip_fid = $form_state['ode_zip_fid'][0];
  }

  $fids_to_prepopulate = $this->extract_and_get_catalog_zip_resources_fids($form, $ode_zip_fid);

  //PREPOPULATE FIELD COLLECTION
  //---Idea from http://drupal.stackexchange.com/a/102745. Populates a field collection with as many values as needed.---
  $items_count = count($fids_to_prepopulate['content']);
  $field_name = 'field_archivos_a_adjuntar';
  $form_theme = $form[$field_name][LANGUAGE_NONE]['#theme'];

  $items = &$form_state['field'][$field_name][LANGUAGE_NONE];

  // Generate required number of fields collection
  if ($items_count > 1 and $items['items_count'] != $items_count) {
    $items['items_count'] = $items_count;

    $form[$field_name][LANGUAGE_NONE] = field_multiple_value_form($items['field'], $items['instance'], LANGUAGE_NONE, array(), $form, $form_state);
    // Reset theme function, as field_multiple_value_form hijacks it
    $form[$field_name][LANGUAGE_NONE]['#theme'] = $form_theme;
  }

  // Fill generated fields with data
  for ($delta = 0; $delta < $items_count; $delta++) {
    $form[$field_name][LANGUAGE_NONE][$delta]['field_archivo'][LANGUAGE_NONE][0]['#default_value']['fid'] = $fids_to_prepopulate['content'][$delta];
    $form[$field_name][LANGUAGE_NONE][$delta]['field_nombre_archivo'][LANGUAGE_NONE][0]['value']['#default_value'] = $this->extract_name_from_file($fids_to_prepopulate['content'][$delta]);
  }
  //---

  // Prepopulate agrega2 preview (miniature)
  if (isset($fids_to_prepopulate['preview'])) {
    $form['field_imagen_miniatura'][LANGUAGE_NONE][0]['#default_value']['fid'] = $fids_to_prepopulate['preview'];
  }


  //Fill form, only if ode variable was fulfilled correctly.
  if (!empty($ode)) {
    //TITLE
    if (isset($ode['title']) && isset($form['title_field'][LANGUAGE_NONE][0]['value'])) {
      $form['title_field'][LANGUAGE_NONE][0]['value']['#default_value'] = $ode['title'];
    }

    //LANGUAGE
    if (isset($ode['generalLanguage']) && isset($form['field_general_language'][LANGUAGE_NONE])) {
      $form['field_general_language'][LANGUAGE_NONE]['#default_value'] = $ode['generalLanguage'];
    }

    //DESCRIPTION
    if (isset($ode['generalDescription']) && isset($form['field_descripci_n'][LANGUAGE_NONE][0]['value'])) {
      $form['field_descripci_n'][LANGUAGE_NONE][0]['value']['#default_value'] = $ode['generalDescription'];
    }


    //PREVIOUS KNOWLEDGE
    if (isset($ode['educationalDescription'][1]) && isset($form['field_conocimiento_previo'][LANGUAGE_NONE][0]['value'])) {
      $form['field_conocimiento_previo'][LANGUAGE_NONE][0]['value']['#default_value'] = $ode['educationalDescription'][0];
    }

    //DIDACTICAL OBJECTIVES
    if (isset($ode['educationalDescription'][0]) && isset($form['field_objetivos_did_cticos'][LANGUAGE_NONE][0]['value'])) {
      $form['field_objetivos_did_cticos'][LANGUAGE_NONE][0]['value']['#default_value'] = $ode['educationalDescription'][1];
    }

    //KEYWORDS
    if (isset($ode['generalKeyword']) && !empty($ode['generalKeyword']) && isset($form['field_keywords'][LANGUAGE_NONE])){
      $form['field_keywords'][LANGUAGE_NONE]['#default_value'] = implode(', ', $ode['generalKeyword']);
    }

    //LABELS
    if (isset($ode['generalKeyword']) && !empty($ode['generalKeyword']) && isset($form['field_labels'][LANGUAGE_NONE])){
      $form['field_labels'][LANGUAGE_NONE]['#default_value'] = implode(', ', $ode['generalKeyword']);
    }

    //LICENSE is creative commons?
    if (isset($ode['rightsCopyrightAndOtherRestrictions'])) {
      $license_values = _get_license_values($ode['rightsCopyrightAndOtherRestrictions']);
      //Allow modifications
      if (isset($license_values['allow_modifications']) && isset($form['field_allow_modifications'][LANGUAGE_NONE])) {
        $form['field_allow_modifications'][LANGUAGE_NONE]['#default_value'] = $license_values['allow_modifications'];
      }
      //Commercial use
      if (isset($license_values['comercial_use']) && isset($form['field_comercial_use'][LANGUAGE_NONE])) {
        $form['field_comercial_use'][LANGUAGE_NONE]['#default_value'] = $license_values['comercial_use'];
      }
    }

    //LIFECYCLE
    if (isset($ode['lifecycleContribute']) && isset($form['field_contribuciones_ode'])) {
      $this->parse_lifecycle($form, $form_state, $ode['lifecycleContribute']);
    }

    // RECURSO DE APRENDIZAJE AND RESOURCE TYPE
    if (isset($ode['resourceType']) && !empty($ode['resourceType']) && isset($form) && isset($form['field_recurso_de_aprendizaje'][LANGUAGE_NONE]['#options'])) {
      if (!is_array($ode['resourceType'])) {
        // Fill field_resource_type
        $resource_type = array_search($ode['resourceType'], $form['field_resource_type'][LANGUAGE_NONE]['#options']);
        if ($resource_type) {
          $form['field_resource_type'][LANGUAGE_NONE]['#default_value'][] = $resource_type;
        }
        // Fill field_recurso_de_aprendizaje
        $recurso_de_aprendizaje = array_search($ode['resourceType'], $form['field_recurso_de_aprendizaje'][LANGUAGE_NONE]['#options']);
        if ($recurso_de_aprendizaje) {
          $form['field_recurso_de_aprendizaje'][LANGUAGE_NONE]['#default_value'] = $recurso_de_aprendizaje;
        }
      }
      else {
        foreach ($ode['resourceType'] as $value) {
          // Fill field_resource_type
          $resource_type = array_search($value, $form['field_resource_type'][LANGUAGE_NONE]['#options']);
          if ($resource_type) {
            $form['field_resource_type'][LANGUAGE_NONE]['#default_value'][] = $resource_type;
          }
          // Fill field_recurso_de_aprendizaje
          $recurso_de_aprendizaje = array_search($value, $form['field_recurso_de_aprendizaje'][LANGUAGE_NONE]['#options']);
          if ($recurso_de_aprendizaje) {
            $form['field_recurso_de_aprendizaje'][LANGUAGE_NONE]['#default_value'] = $recurso_de_aprendizaje;
          }
        }
      }
    }

    // KNOWLEDGE AREA
    if (isset($ode['knowledgeArea']) && !empty($ode['knowledgeArea']) && isset($form) && isset($form['field_knowledge_area'][LANGUAGE_NONE]['#options'])) {
      if (!is_array($ode['knowledgeArea'])) {
        $form['field_knowledge_area'][LANGUAGE_NONE]['#default_value'][] = array_search($ode['knowledgeArea'], $form['field_knowledge_area'][LANGUAGE_NONE]['#options']);
      }
      else {
        foreach ($ode['knowledgeArea'] as $value) {
          $form['field_knowledge_area'][LANGUAGE_NONE]['#default_value'][] = array_search($value, $form['field_knowledge_area'][LANGUAGE_NONE]['#options']);
        }
      }
    }

    // LEARNING CONTEXT
    if (isset($ode['learningContext']) && !empty($ode['learningContext']) && isset($form) && isset($form['field_learning_context'][LANGUAGE_NONE]['#options'])) {
      if (!is_array($ode['learningContext'])) {
        $form['field_learning_context'][LANGUAGE_NONE]['#default_value'][] = array_search($ode['learningContext'], $form['field_learning_context'][LANGUAGE_NONE]['#options']);
      }
      else {
        foreach ($ode['learningContext'] as $value) {
          $form['field_learning_context'][LANGUAGE_NONE]['#default_value'][] = array_search($value, $form['field_learning_context'][LANGUAGE_NONE]['#options']);
        }
      }
    }

    // DESTINATARIOS.
    if (isset($ode['educationalIntendedEndUserRole']) && !empty($ode['educationalIntendedEndUserRole'][0]) && isset($form['field_destinatarios'][LANGUAGE_NONE])) {
      $name = $ode['educationalIntendedEndUserRole'][0];
      $terms = $form['field_destinatarios'][LANGUAGE_NONE]['#options'];
      $value = $this->get_taxonomy_term_id_by_solr_saved_name($name, $terms);
      $form['field_destinatarios'][LANGUAGE_NONE]['#default_value'] = !empty($value) ? $value : $this->get_taxonomy_term_id_by_solr_saved_name('learner', $terms);
    }

    // AGRUPACION DE ALUMNOS.
    if (isset($ode['educationalIntendedEndUserRole']) && !empty($ode['educationalIntendedEndUserRole'][1]) && isset($form['field_agrupacion_de_alumnos'][LANGUAGE_NONE])) {
      $name = $ode['educationalIntendedEndUserRole'][1];
      $terms = $form['field_agrupacion_de_alumnos'][LANGUAGE_NONE]['#options'];
      $value = $this->get_taxonomy_term_id_by_solr_saved_name($name, $terms);
      $form['field_agrupacion_de_alumnos'][LANGUAGE_NONE]['#default_value'] = !empty($value) ? $value : $this->get_taxonomy_term_id_by_solr_saved_name('individual', $terms);
    }

    // EDUCATIONAL LANGUAGE.
    if (isset($ode['educationalLanguage']) && !empty($ode['educationalLanguage']) && isset($form['field_educational_language'][LANGUAGE_NONE])) {
      $form['field_educational_language'][LANGUAGE_NONE]['#default_value'] = $ode['educationalLanguage'];
    }

    // LUGAR DE UTILIZACION.
    if (isset($ode['educationalContext']) && !empty($ode['educationalContext']) && isset($form['field_lugar_de_utilizaci_n'][LANGUAGE_NONE])) {
      if ($ode['educationalContext'][0] == 'classroom') {
        $form['field_lugar_de_utilizaci_n'][LANGUAGE_NONE]['#default_value'] = 4230;
      }
      else if ($ode['educationalContext'][0] == 'home') {
        $form['field_lugar_de_utilizaci_n'][LANGUAGE_NONE]['#default_value'] = 4231;
      }
      else {
        $form['field_lugar_de_utilizaci_n'][LANGUAGE_NONE]['#default_value'] = 4230;
      }
    }

    // MODALIDAD DE USO.
    if (isset($ode['educationalContext']) && !empty($ode['educationalContext']) && isset($form['field_modalidad_de_uso'][LANGUAGE_NONE])) {
      $name = array_pop($ode['educationalContext']);
      $terms = $form['field_modalidad_de_uso'][LANGUAGE_NONE]['#options'];
      $value = $this->get_taxonomy_term_id_by_solr_saved_name($name, $terms);
      $form['field_modalidad_de_uso'][LANGUAGE_NONE]['#default_value'] = !empty($value) ? $value : $this->get_taxonomy_term_id_by_solr_saved_name('presencial', $terms);
    }
  }

  //ZIP, IN CASE CATALOG.
  if (!empty($ode_zip_fid)) {
    drupal_set_message(t('Catalog file detected. All its resource files will be extracted and sent once this form is submitted. Please complete all other catalog fields.'));

    //TODO: FIELD FOR THIS?
    $form_state['test_zip_ode'] = $ode_zip_fid;
  }

  //Prepolulate organization field if it arrives
  if (!empty($_SESSION['publish_organization'])) {
    $form['publish_organization_fieldset']['publish_organization']['#default_value'] = $_SESSION['publish_organization'];
  }
}

/*
 * Return the term ID matching a SOLR term name.
 *
 * @param $name
 *   A term's name
 * @param $terms
 *   List of terms available in field
 *
 * @return
 *   A taxonomy term ID, or empty if the term was not found.
 */
private function get_taxonomy_term_id_by_solr_saved_name($name, $terms) {
  foreach ($terms as $key => $value) {
    $term_name = $this->get_taxonomy_translated_from_tid($key, 'en');
    if ($term_name == $name) {
      return $key;
    }
  }

  return '';
}

/**
 * Creates as many entries as needed in field_contribuciones_ode, filling its values from lifecycleContribute.
 *
 * @param $form
 * @param $form_state
 * @param $lifecycle
 *
 */
public function parse_lifecycle(&$form, &$form_state, $lifecycle) {
  // Size to amplify field_collection.
  $size = count($lifecycle);
  if ($size <= 1) {
    return;
  }

  // Extract authors data.
  $items_count = 0;
  $authors = array();
  for ($delta = 0; $delta < $size; $delta++) {
    $element = $this->extract_lifecycle_data($lifecycle[$delta]);
    if (!empty($element['mail'])) {
      $authors[] = $element;
      $items_count++;
    }
  }

  // Idea from http://drupal.stackexchange.com/a/102745. Populates a field collection with as many values as needed.
  $field_name = 'field_contribuciones_ode';
  $form_theme = $form[$field_name][LANGUAGE_NONE]['#theme'];
  // Remove delete and add more buttons.
  $form[$field_name][LANGUAGE_NONE][0]['remove_button']['#access'] = FALSE;
  $form[$field_name][LANGUAGE_NONE]['add_more']['#access'] = FALSE;
  $items = &$form_state['field'][$field_name][LANGUAGE_NONE];
  // Generate required number of fields collection.
  if ($items_count > 1 and $items['items_count'] != $items_count) {
    $items['items_count'] = $items_count;
    $items['field']['cardinality'] = $items_count;
    $form[$field_name][LANGUAGE_NONE] = field_multiple_value_form($items['field'], $items['instance'], LANGUAGE_NONE, array(), $form, $form_state);
      // Reset theme function, as field_multiple_value_form hijacks it.
      $form[$field_name][LANGUAGE_NONE]['#theme'] = $form_theme;
  }

  // Fill generated fields with data.
  foreach ($authors as $delta => $author) {
    $this->prepopulate_lifecycle($form[$field_name][LANGUAGE_NONE][$delta], $author);
  }
}

/**
 * Extract author's info from lifecycle data.
 *
 * @param $candidate_info
 *
 */
private function extract_lifecycle_data($candidate_info) {
  $element = array();
  $info = explode('##', $candidate_info);

  // Get fields from lifecycle entry, separated with ##.
  $element['role'] = isset($info[0]) ? $info[0] : '';
  $element['vcard'] = isset($info[1]) ? $info[1] : '';
  $element['date_text'] = isset($info[2]) ? $info[2] : '';
  $element['date_type'] = isset($info[3]) ? $info[3] : '';

  // Get author name.
  if (!empty($element['vcard'])) {
    $element['author'] = trim(ag_visualization_ode_parse_vcard_for_author($element['vcard']));
  }
  else {
    $element['author'] = '';
  }

  // Get email, clean if it isnt.
  $element['mail'] = ag_visualization_ode_parse_vcard_for_mail($element['vcard']);
  $element['mail'] = valid_email_address($element['mail']) ? $element['mail'] : '';

  // Get organization
  $element['org'] = ag_visualization_ode_parse_vcard_for_organization($element['vcard']);

  // Get role from english to spanish and tid.
  $element['role_spanish'] = ag_visualization_ode_i18n_translate_term_cached($element['role'], 'en', 'rol_contribuidor');
  if (!empty($element['role_spanish'])) {
    $taxonomy = taxonomy_get_term_by_name($element['role_spanish'], 'rol_contribuidor');
    $taxonomy = is_array($taxonomy) ? $taxonomy[key($taxonomy)] : $taxonomy;

    if (isset($taxonomy->tid)) {
      $element['role_spanish_tid'] = $taxonomy->tid;
    }
  }

  return $element;
}

/**
 * Parses an entry from lifecycle to an entry in field_contribuciones_ode field collection.
 *
 * @param $field_collection
 * @param $element
 *
 */
public function prepopulate_lifecycle(&$field_collection, $element) {
  // Set user role.
  if (isset($field_collection['field_rol_contribuidor'][LANGUAGE_NONE]) && !empty($element['role_spanish_tid']) && is_numeric($element['role_spanish_tid'])) {
    $field_collection['field_rol_contribuidor'][LANGUAGE_NONE]['#default_value'][0] = $element['role_spanish_tid'];
  }

  // Set user name.
  if (isset($field_collection['field_contribuidor'][LANGUAGE_NONE][0]['value']) && !empty($element['author'])) {
    $field_collection['field_contribuidor'][LANGUAGE_NONE][0]['value']['#default_value'] = $element['author'];
  }

  // Set user mail.
  if (isset($field_collection['field_correo_electr_nico'][LANGUAGE_NONE][0]['email']) && !empty($element['mail'])) {
    $field_collection['field_correo_electr_nico'][LANGUAGE_NONE][0]['email']['#default_value'] = $element['mail'];
  }

  // Set user organization.
  if (isset($field_collection['field_organizaci_n'][LANGUAGE_NONE][0]['value']) && !empty($element['org'])) {
    $field_collection['field_organizaci_n'][LANGUAGE_NONE][0]['value']['#default_value'] = $element['org'];
  }

  // Datetime.
  if (isset($field_collection['field_fecha_contribucion'][LANGUAGE_NONE][0]) && !empty($element['date_text'])) {
    $field_collection['field_fecha_contribucion'][LANGUAGE_NONE][0]['#default_value']['value'] = strtotime($element['date_text']);
  }

  // Date description.
  if (isset($field_collection['field_descripcion_fecha'][LANGUAGE_NONE][0]) && !empty($element['date_type'])) {
    $field_collection['field_descripcion_fecha'][LANGUAGE_NONE][0]['value']['#default_value'] = $element['date_type'];
  }
}

/**
* Transforms data from form_state when creating an ode, to a solr-friendly format.
* @return $arguments Array with structure to be sent to webservice by soap.
*/
public function get_arguments_from_node_form($form_state) {

  # Language
  global $language;

  $field_language = ($form_state['nid']) ? $language->language : 'und';
  $language_code = $field_language;

  # User that creates the node
  $user = user_load($form_state['uid']);

  #Arguments to pass to orchestrator
  $arguments = array();

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

  #Original ID from Agrega - Unknown at this point.
  $arguments['generalIdentifier'] = '';

  #type
  $arguments['type'] = "ODE";

  #title
  $arguments['title'] = $this->get_text_field($form_state['title_field'], $language_code, t('Untitled'));

  #Description and general Description
  $arguments['description'] = $this->get_text_field($form_state['field_descripci_n'], $language_code, '');

  #author TODO: Is an array, might be possible to add other users as well in the future.
  $username = isset($user->mail) ? $user->mail : '';
  $arguments['author'] = array($username);

  //Override author if ode is published as organization
  if (!empty($form_state['publish_organization'])) {
    $org_data = ag_section_profile_users_get_organization_data(array($form_state['publish_organization']));
    $arguments['author'] = array($org_data[$form_state['publish_organization']]['mail']);
  }

  #Node title
  $arguments['generalTitle'] = $this->get_text_field($form_state['title_field'], $language_code, t('Untitled'));

  #labels & learningResourceLabels & field_labels!
  if (!empty($form_state['field_keywords']) && count($form_state['field_keywords']['und']) > 0) {
    foreach($form_state['field_keywords']['und'] as $key => $value) {
      $arguments['generalKeyword'][] = $value['name'];
    }
  }
  else {
     $arguments['generalKeyword'][] = '';
  }

  #Description and general Description
  $arguments['generalDescription'][] = $this->get_text_field($form_state['field_descripci_n'], $language_code, '');

  #Certification
  $arguments['certified'] = $this->get_text_field($form_state['field_certified'], $language_code, 0);

  #Language (code or name). ODE has no language, so we take user page language.
  $field_language = ($form_state['nid']) ? $language->language : 'und';


  $language_field = isset($form_state['field_general_language'][LANGUAGE_NONE][0]['value']) ? $form_state['field_general_language'][LANGUAGE_NONE][0]['value'] : '';
  $language_processed = (($language->language == 'und') ? 'x-none' : $language->language);
  $arguments['generalLanguage'] = !empty($language_field) ? array($language_field) : array($language_processed);


  #Contribuciones
  //Node creator must appear as contribution with role author. if user publish as organization empty lifecycleContribute
  if (empty($form_state['publish_organization'])) {
    $arguments['lifecycleContribute'] = array($this->generate_contributor_from_author($user));
  }

  //Use node language, or undefined if there is none.
  $language_access_code = isset($form_state['field_contribuciones_ode'][$language_code]) ? $language_code : 'und';
  if (!empty($form_state['field_contribuciones_ode'][$language_access_code])) {
    foreach($form_state['field_contribuciones_ode'][$language_access_code] as $key => $value) {
      //Add more option must be ignored. Only numeric keys are allowed.
      if (!is_numeric($key)) {
        continue;
      }
      $string = $this->get_contributor_field_collection($value, $language_access_code);
      //Add only if items were fulfilled and able to implode into string.
      if (!empty($string)) {
        $arguments['lifecycleContribute'][] = $string;
      }
    }
  }


  #Tipo de Recurso educativo - DEPRECATED BY NEW TAXONOMIES AND CATEGORIES - Might come back, anyway.
  #CAREFUL, Taxonomy values changed with time. They might not exist or be completely different.
  //$educational_resources = $this->get_taxonomy_lomes_children($form_state['field_recurso_educativo'], $language_code, 17);
  //$learning_resource = $this->get_taxonomy_lomes_children($form_state['field_recurso_de_aprendizaje'], $language_code, 15);
  //$arguments['educationalLearningResourceType'] = array_merge($educational_resources, $learning_resource);
  $arguments['educationalLearningResourceType'] = array('');

  // Default aggregation level.
  $aggregation_level = 2;

  // Prepare aggregation level.
  if (isset($form_state['field_archivos_a_adjuntar'][LANGUAGE_NONE])) {
    $files_fids = ag_visualization_ode_process_files_field_collection($form_state['field_archivos_a_adjuntar'][LANGUAGE_NONE]);

    // Validate if single file is an image (jpg, jpeg, png, gif) for adjust aggregation level.
    if (count($files_fids == 1)) {
      $fid = current(array_keys($files_fids));
      $file = file_load($fid);
      $is_image = file_validate_is_image($file);
      $aggregation_level = empty($is_image) ? 1 : 2;
    }
  }

  // Aggregation level. Ignore field. There are special rules (LOM-ES) for this.
  $arguments['generalAggregationLevel'] = $aggregation_level;
  //$arguments['generalAggregationLevel'] = $this->get_text_field($form_state['field_nivel_de_agregacion'], $language_code);

  #Destinatario + Agrupacion
  //Use node language, or undefined if there is none.
  $arguments['educationalIntendedEndUserRole'][] = $this->get_taxonomy_normal_field($form_state['field_destinatarios'], $language_code);
  $arguments['educationalIntendedEndUserRole'][] = $this->get_taxonomy_normal_field($form_state['field_agrupacion_de_alumnos'], $language_code);

  #Modalidad de uso + Lugar de utilizacion
  $arguments['educationalContext'] = $this->get_taxonomy_lomes_children($form_state['field_lugar_de_utilizaci_n'], $language_code, 11);
  $arguments['educationalContext'][] = $this->get_taxonomy_normal_field($form_state['field_modalidad_de_uso'], $language_code);

  #EducationalDescription
  $arguments['educationalDescription'][] = $this->get_text_field($form_state['field_conocimiento_previo'], $language_code);
  $arguments['educationalDescription'][] = $this->get_text_field($form_state['field_objetivos_did_cticos'], $language_code);

  #RightsCopyright   FIELD WITH CREATIVE COMMONS RESTRICTIONS
  //$arguments['rightsCopyrightAndOtherRestrictions'] = $this->get_taxonomy_normal_field($form_state['field_licencia'], $language_code);
  $comercial_use = isset($form_state['field_comercial_use'][LANGUAGE_NONE][0]['value']) ? $form_state['field_comercial_use'][LANGUAGE_NONE][0]['value'] : 0;
  $allow_modifications = isset($form_state['field_allow_modifications'][LANGUAGE_NONE][0]['value']) ? $form_state['field_allow_modifications'][LANGUAGE_NONE][0]['value'] : 0;
  $license = ag_visualization_ode_get_license_text($allow_modifications, $comercial_use);
  //If empty, we assume the most restrictive of creative commons
  $arguments['rightsCopyrightAndOtherRestrictions'] = !empty($license) ? $license : 'creative commons: attribution - non derived work - non commercial';

  #RightAccess(Type)  FIELD REMOVED
  $arguments['rightsAccess'] = 'universal'; //$this->get_taxonomy_normal_field($form_state['field_tipo_de_licencia'], $language_code);

  #RightAccess(Description) FIELD REMOVED
  $arguments['rightsAccessDescription'] = ''; //$this->get_text_field($form_state['field_descripcion_de_licencia'], $language_code);

  #PublicationDate from timestamp to format: yyyy-mm-ddThh:mm:ss.cccZ
  if (!empty($form_state['created'])) {
    $arguments['publicationDate'] = $this->get_date_iso_from_timestamp($form_state['created']);
  }
  else {
    $arguments['publicationDate'] = '';
  }

  #New taxonomy fields: knowledgeArea, learningContext, and resourceType.
  if (isset($form_state['field_knowledge_area'])) {
    $arguments['knowledgeArea'] = array_unique($this->get_taxonomy_normal_field_multivalued($form_state['field_knowledge_area'], 'und', 'es'));
  }
  if (isset($form_state['field_learning_context'])) {
    $arguments['learningContext'] = array_unique($this->get_taxonomy_normal_field_multivalued($form_state['field_learning_context'], 'und', 'es'));
  }
  if (isset($form_state['field_mimetype_resource_type']) && isset($form_state['field_recurso_de_aprendizaje'])) {
    // Add resource type, calculate from mimetype of ode file.
    $educational_resources = $this->get_taxonomy_normal_field_multivalued($form_state['field_resource_type'], 'und', '', 'es');
    if (!empty($educational_resources)){
      $arguments['resourceType'] = $educational_resources;
    }

    // Add learning resource from form.
    $learning_resource = $this->get_taxonomy_normal_field($form_state['field_recurso_de_aprendizaje'], 'und', '', 'es');
    if (!empty($learning_resource)) {
      $arguments['resourceType'][] = $learning_resource;
    }
  }


  #OLD TAXONOMIES. TO BE DELETED SOMEDAY.
  #Nivel educativo/EducationalLevel
  //$this->set_taxonomy_hierarchy($form_state['field_nivel_educativo'], 'classificationEducationalLevel', 6, $arguments, 'es', 'es');
  #Arbol curricular/classification discipline
  //$this->set_taxonomy_hierarchy($form_state['field_arbol_curricular'], 'classificationDiscipline', 6, $arguments, 'es', 'es');

  #Accessibility
  if (!empty($form_state['field_accesibilidad'][LANGUAGE_NONE][0]['tid'])) {
    $this->set_taxonomy_hierarchy($form_state['field_accesibilidad'], 'classificationAccessibility', 4, $arguments, 'es', 'es');
  }
  #Competency
  if ($form_state['field_competencias'][LANGUAGE_NONE][0]['tid']) {
    $this->set_taxonomy_hierarchy($form_state['field_competencias'], 'classificationCompetency', 2, $arguments, 'es', 'es');
  }

  #labels & learningResourceLabels & field_labels!
  if (!empty($form_state['field_labels']) && count($form_state['field_labels']['und']) > 0) {
    foreach($form_state['field_labels']['und'] as $key => $value) {
      $arguments['labels'][] = $value['name'];
    }
  }
  else {
     $arguments['labels'][] = '';
  }

  //Educational language. Depends on form_state, if it does not exist, global language, else, x-none.
  $language_field = isset($form_state['field_educational_language'][LANGUAGE_NONE][0]['value']) ? $form_state['field_educational_language'][LANGUAGE_NONE][0]['value'] : '';
  $language_processed = (($language->language == 'und') ? 'x-none' : $language->language);
  $arguments['educationalLanguage'] = !empty($language_field) ? array($language_field) : array($language_processed);

  return $arguments;
}


/**
* Auxiliary function to process a taxonomy field from drupal and
* transforms it to solr tree structure as a matrix.
*/
public function process_taxonomy_fields($field_value, &$arguments, $field_name, $depth = 1, $language_output = 'es') {

  //Main goal: Get taxonomy order: ...->grandfather->father->son
  //           Then, add it as a column. In tid and label fields at the same time.
  foreach ($field_value as $key => $value) {
    //Get tid from node field, as it is formatted this way: [0]['tid'] = $element
    if (!isset($value['tid'])) {
      continue;
    }
    $element = $value['tid'];

    //Load taxonomy and load its parents (itself included)
    $term = taxonomy_term_load($element);
    $term_parents = taxonomy_get_parents_all($element);

    //Taxonomy_get_parents_all returns order from son to grandfather. We need it reversed.
    $term_parents = array_reverse($term_parents);

    //Fill with children wherever needed until needed depth is achieved.
    while (count($term_parents) < $depth) {
      $object = new stdClass();
      $object->tid = '';
      $object->name = '';
      $term_parents[] = $object;
    }

    //Process this taxonomy (and parents), adding tid and label
    //as new column, advancing in depth. Example:
    //  First: EducationalLevel1[0] = tid, EducationalLevel1Label = name
    //  Second: EducationalLevel2[0] = tid, EducationalLevel2Label = name
    //   and so on, until another child comes from first foreach, being next column to fill.
    foreach ($term_parents as $parent_key => $parent_object) {
      $new_key = $field_name . ($parent_key+1);
      $arguments[$new_key][] = $parent_object->tid;
      $arguments[$new_key . 'Label'][] = isset($parent_object->tid) ? $this->get_taxonomy_translated_from_tid($parent_object->tid, $language_output) : $parent_object->name; //$parent_object->name;
    }
  }
}

/**
* Creates a VCARD version 3 from username/user description, email and organization.
* @return $result String with VCARD 3.0 format.
*/
public function get_vcard_format($user, $email, $organization) {
  $result = "BEGIN:VCARD VERSION:3.0 ";

  //User is required
  if (empty($user)) {
    return '';
  }

  //Add user
  $result .= "FN: " . $user . " ";

  //Add email if exists
  if (!empty($email)) {
    $result .= "EMAIL;TYPE=INTERNET:" . $email . " ";
  }

  //Add organization if exists
  if (!empty($organization)) {
    $result .= "ORG:" . $organization . " ";
  }

  $result .= "END:VCARD";
  return $result;
}


/**
* Returns taxonomy in certain language from tid only. If there isn't translation, returns original term.
* @return $result Empty if taxonomy loading failed, string translated if possible, or normal one if it couldn't.
*/
public function get_taxonomy_translated_from_tid($tid, $language_code) {
  //Empty tid.
  if (empty($tid) || $tid == 0) {
    return '';
  }

  $term = taxonomy_term_load($tid);
  $term_translated = ($language_code == 'und' || empty($language_code)) ? '' : i18n_taxonomy_term_name($term, $language_code);

  //Return translated, or normal, or empty, depending availability.
  if (!empty($term_translated)) {
    return $term_translated;
  }
  elseif (isset($term->name)) {
    return $term->name;
  }
  else {
    return '';
  }
}
/**
* Parse form_state taxonomy field, and returns solr-friendly format. Language independent.
* @return Taxonomy string, translated if it was possible. Defaults to empty string if no tid was received.
*/
public function get_taxonomy_normal_field($field, $language_code, $default = '', $output_language = 'en') {
  //Use node language, or undefined if there is none.
  $language_access_code = isset($field[$language_code]) ? $language_code : 'und';
  if (!empty($field[$language_access_code][0]['tid'])) {
    $tid = $field[$language_access_code][0]['tid'];
    return $this->get_taxonomy_translated_from_tid($tid, $output_language);
  }
  else {
    return $default;
  }
}

/**
* Parse form_state taxonomy field, and returns solr-friendly format. Language independent. Multivalued.
* @return Taxonomy array, translated if it was possible. Defaults to empty array of strings if no tid was received.
*/
public function get_taxonomy_normal_field_multivalued($field, $language_code, $default = '', $output_language = 'es') {
  //Use node language, or undefined if there is none.
  $language_access_code = isset($field[$language_code]) ? $language_code : 'und';
  $result = array();
  foreach ($field[$language_access_code] as $key => $value) {
    if (is_numeric($key) && !empty($value['tid'])) {
      $tid = $value['tid'];
      $result[] =  $this->get_taxonomy_translated_from_tid($tid, $output_language);
    }
  }

  return $result;
}

/**
* Parse form_state taxonomy field, and returns all children from that taxonomy as array. Language independent.
* @return Taxonomy string, translated if it was possible. Defaults to empty string if no tid was received.
*/
public function get_taxonomy_lomes_children($field, $language_code, $vid) {
  $result = array();
  $language_access_code = isset($field[$language_code]) ? $language_code : 'und';

  //Check if field is empty.
  if (!empty($field[$language_access_code][0]['tid'])) {

    //Load children, add only if english translation is available.
    $children = taxonomy_get_children($field[$language_access_code][0]['tid'], $vid);
    foreach ($children as $key => $value) {
      $translated = $this->get_taxonomy_translated_from_tid($value->tid, 'en');
      if ($translated) {
        $result[] = $translated;
      }
    }
    //Add parent if no children exists.
    if (empty($children)) {
      $result[] = $this->get_taxonomy_translated_from_tid($field[$language_access_code][0]['tid'], 'en');
    }
  }

  return $result;
}

/**
* Parse form_state normal text field, accessing without errors. Language independent.
* @return Field value string.
*/
public function get_text_field($field, $language_code, $default = '') {
  //Use node language, or undefined if there is none.
  $language_access_code = isset($field[$language_code]) ? $language_code : 'und';
  if (isset($field[$language_access_code][0]['value'])) {
    return $field[$language_access_code][0]['value'];
  }
  else {
    return $default;
  }
}

/**
* Turns UNIX timestamp into ISO Date format.
* @return ISO Date as String.
*/
public function get_date_iso_from_timestamp($timestamp) {
  if (!empty($timestamp)) {
    $format = 'Y-m-d\TH:i:s.u\Z';
    $date = substr(date($format, $timestamp), 0, -4) . 'Z';
    return $date;
  }
}

/**
* Generates solr format for taxonomy tree hierarchy. Wrapper for process_taxonomy_fields method,
* making it work independently from languages. Can specify language output.
*/
public function set_taxonomy_hierarchy($field_array, $field_name, $depth = 1, &$arguments, $language_input = 'es', $language_output = 'es') {
  //Save in english if possible.
  $language_access_code = isset($field_array[$language_input]) ? $language : 'und';

  if (isset($field_array[$language_access_code]) && (isset($field_array[$language_access_code][0]['tid']))) {
    $this->process_taxonomy_fields($field_array[$language_access_code], $arguments, $field_name, $depth, $language_output);
  }
  else {
    $this->emptyTaxonomyFields($arguments, $field_name, $depth);
  }
}

/**
* Parses row from contributions field_collection and returns to specific solr format.
* @return String with format: Contributor##VCARD##DATE##dateDescription
*/
public function get_contributor_field_collection($value, $language_access_code) {
 
  //User role - Taxonomy
  if (!empty($value['field_rol_contribuidor'][$language_access_code][0]['tid'])) {
    $tid = $value['field_rol_contribuidor'][$language_access_code][0]['tid'];
    $rol = $this->get_taxonomy_translated_from_tid($tid, 'en');
  }
  else {
    $rol = '';
  }

  //Get VCARD fields
  $contribuidor = isset($value['field_contribuidor'][$language_access_code][0]['value']) ? $value['field_contribuidor'][$language_access_code][0]['value'] : '';
  $mail = isset($value['field_correo_electr_nico'][$language_access_code][0]['email']) ? $value['field_correo_electr_nico'][$language_access_code][0]['email'] : '';
  $organization = isset($value['field_organizaci_n'][$language_access_code][0]['value']) ? $value['field_organizaci_n'][$language_access_code][0]['value'] : '';

  //If VCARD cannot be created, ignore this row.
  if (empty($contribuidor) || empty($mail)) {
    return NULL;
  }

  //--Create VCARD
  $vcard = $this->get_vcard_format($contribuidor, $mail, $organization);

  //Date fields
  $fecha = isset($value['field_fecha_contribucion'][$language_access_code][0]['value']) ? $value['field_fecha_contribucion'][$language_access_code][0]['value'] : '';
  if (!empty($fecha)) {
    $fecha = $this->get_date_iso_from_timestamp($fecha);
  }
  $descripcion_fecha = isset($value['field_descripcion_fecha'][$language_access_code][0]['value']) ? $value['field_descripcion_fecha'][$language_access_code][0]['value'] : '';

  //Add row if exists at least one field.
  if (!empty($rol) || !empty($vcard) || !empty($fecha) || !empty($descripcion_fecha)) {
    $fields = array();
    $fields[0] = $rol;
    $fields[1] = $vcard;
    $fields[2] = $fecha;
    $fields[4] = $descripcion_fecha;

    return implode("##", $fields);
  }
  else {
    //User input is required.
    return NULL;
  }
}

/**
* Turns node creator into solr contributor format, with author role.
* @return String with format: Contributor##VCARD##DATE##dateDescription
*/
public function generate_contributor_from_author($user) {

  //Get user organization
  $wrapper = entity_metadata_wrapper('user', $user);
  $organization_name = '';
  if (isset($wrapper->field_organization_reference)) {
    $organization = $wrapper->field_organization_reference->value();

    if (isset($organization->name)) {
      $organization_name = $organization->name;
    }
  }

  //Load user profile and name_surname field collection. Else, set username.
  $profile = profile2_load_by_user($user, 'datos_personales');
  $field_collection_id = isset($profile->field_name_surname[LANGUAGE_NONE][0]['value']) ? $profile->field_name_surname[LANGUAGE_NONE][0]['value'] : '';

  //Get names if load went ok.
  if (!empty($field_collection_id)){
    $field_collection = entity_load('field_collection_item', array($field_collection_id));
    $field_collection = array_shift($field_collection);

    $real_name = isset($field_collection->field_profile_name[LANGUAGE_NONE][0]['value']) ? $field_collection->field_profile_name[LANGUAGE_NONE][0]['value'] : '';
    $real_surname = isset($field_collection->field_profile_surname[LANGUAGE_NONE][0]['value']) ? $field_collection->field_profile_surname[LANGUAGE_NONE][0]['value'] : '';
  }

  //Set user real name if it was correctly found.
  if (!empty($real_name) && !empty($real_surname)) {
    $name_and_surname = $real_name . ' ' . $real_surname;
  }
  else {
    //Else, use username, as there is no other choice.
    $name_and_surname = $user->name;
  }

  //With or without organization name, create vcard with mail and username.
  $vcard = $this->get_vcard_format($name_and_surname, $user->mail, $organization_name);

  //Prepare array.
  $fields = array();
  $fields[0] = 'author';
  $fields[1] = $vcard;
  $fields[2] = $this->get_date_iso_from_timestamp(time());
  $fields[3] = t('Created date');

  return implode("##", $fields);
}

  /**
  * Generate empty taxonomy matrix if none was received or translated.
  */
  function emptyTaxonomyFields(&$arguments, $field_name, $depth = 1) {

    for ($i = 1; $i <= $depth; $i++) {
        $arguments[$field_name . $i][] = '';
        $arguments[$field_name . $i . 'Label'][] = '';
    }
  }

}
