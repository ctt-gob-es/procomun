<?php
/**
 * @file
 * Code for profile and login forms
 */

/**
* Custom form callback for login with Cl@ve
*/
function clave_login_form($form_state) {
  $form = array();

  $default_value = variable_get('clave_url_server', 'https://www.mecd.gob.es/clavemecd/idententificacionClave.form');

  $form['#action'] = $default_value;

  $clave_url = url('clave', array('absolute' => TRUE, 'query' => drupal_get_query_parameters()));
  $form['urlRetorno'] = array(
    '#type' => 'hidden',
    '#value' => $clave_url,
  );

  $default_value = variable_get('clave_qaa_level', 3);
  $form['nivelIdentificacionQaa'] = array(
    '#type' => 'hidden',
    '#value' => base64_encode($default_value),
  );

  $default_value = variable_get('clave_providers', array());
  $form['proveedoresIdentificacion'] = array(
    '#type' => 'hidden',
    '#value' => base64_encode(implode(";", $default_value)),
  );

  $default_value = variable_get('clave_application_id', '');
  $form['idAplicacion'] = array(
    '#type' => 'hidden',
    '#value' => $default_value,
  );

  $default_value = variable_get('clave_sia_code', '');
  $form['codigoSia'] = array(
    '#type' => 'hidden',
    '#value' => base64_encode($default_value),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Login with Cl@ve'),
  );

  return $form;
}

/**
 * Custom function with confirmation to mark content as novelty or not.
 */
function change_content_novelty_form($form, $form_state) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $form_state['build_info']['args'][0],
  );

  $path_options = array('path' => drupal_get_destination());

  // Create label modal window.
  $modal_label = '';
  if (!empty($form_state['build_info']['args'][1])) {
    if ($form_state['build_info']['args'][1] == 'novelty') {
      $modal_label = t('Are you sure you want to mark this content as novelty?');
    }
    elseif ($form_state['build_info']['args'][1] == 'default') {
      $modal_label = t('Are you sure you want to mark this content as not novelty?');
    }
  }

  return confirm_form($form, $modal_label, $path_options);
}

/**
 * Implements FORM_ID_submit().
 */
function change_content_novelty_form_submit($form, &$form_state) {
  if (isset($form_state['build_info']['args'][0]) && intval($form_state['build_info']['args'][0])) {
    $nid = $form_state['build_info']['args'][0];
    $node = node_load($nid, NULL, TRUE);

    // Check if node can be loaded. If not, show a message.
    if ($node !== FALSE) {
      try {
        $wrapper = entity_metadata_wrapper('node', $node);
        $novelty_status = $wrapper->field_novelty->raw();
        // Mark content as novelty or not accordinng to current novelty status.
        $new_status = (empty($novelty_status)) ? '1' : '0';
        $msg = (empty($novelty_status)) ? 'novelty' : 'not novelty';

        $wrapper->field_novelty->set($new_status);
        $wrapper->save();

        $OS_orchestrator_inyection = new OS_orchestrator_inyection();
        list($status, $result) = $OS_orchestrator_inyection->UpdateNovelty(intval($new_status), $wrapper->field_solrid->raw());
        if ($status != 1) {
          drupal_set_message(t($result), 'error');
        }

        drupal_set_message(t('Content successfully marked as @msg', array('@msg' => $msg)), 'status');
      }
      catch (EntityMetadataWrapperException $e) {
        drupal_set_message(t('Content could not be updated'), 'error');
      }
    }
    else {
      drupal_set_message(t('Content could not be updated'), 'error');
    }
  }
}