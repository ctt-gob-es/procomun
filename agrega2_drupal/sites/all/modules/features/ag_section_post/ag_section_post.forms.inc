<?php
/**
 * @file
 * Code for ag_section_post forms.
 */

function node_change_status_form($form, $form_state) {
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $form_state['build_info']['args'][0],
  );

  $path_options = array('path' => drupal_get_destination());

  // Create label modal window.
  $caption = '<p>' . t('You are about to change the status of this content. Are you sure?') . '</p>';
  $modal_label = '';
  if (!empty($form_state['build_info']['args'][1])) {
    if ($form_state['build_info']['args'][1] == 'publish') {
      $modal_label = t('Are you sure you want to pusblish this content?');
    }
    elseif ($form_state['build_info']['args'][1] == 'unpublish') {
      $modal_label = t('Are you sure you want to unpublish this content?');
    }
  }

  return confirm_form($form, $modal_label, $path_options, $caption);
}

/**
 * Implements FORM_ID_submit().
 */
function node_change_status_form_submit($form, &$form_state) {
  if (intval($form_state['build_info']['args'][0]) || isset($form_state['build_info']['args'][0])) {
    $nid = $form_state['build_info']['args'][0];
    $node = node_load($nid, NULL, TRUE);
    // Check if node its loaded. If not, show a message.
    if ($node !== FALSE) {
      // Unpublish or publish node according to current status and then save it.
      $status = ($node->status == 0) ? 1 : $node->status;
      $msg = ($node->status == 0) ? t('published') : t('unpublished');
      $node->status = $status;
      node_save($node);

      $OS_orchestrator_inyection = new OS_orchestrator_inyection();
      if ($node->type == 'external_content') {
        $operation = 'AddUrl';
      }
      elseif ($node->type == 'itinerary') {
        $operation = 'AddLearningPath';
      }
      elseif ($node->type == 'ode') {
        $content = (Array) $node;
        $form_values = array('values' => $content);
        $publish_result = ag_visualization_ode_form_publish_ode_webservice_publish($form, $form_values);
        if (isset($publish_result->return->responseCode) && $publish_result->return->responseCode == 'NOK') {
          // Unpublish node if errors
          $node->status = 0;
          node_save($node);

          // Set error message just once.
          $errors = form_get_errors();
          if (empty($errors)) {
            drupal_set_message($publish_result->return->message, 'error');
          }
        }
        else {
          // Update field_solrid in Drupal and SOLR if no errors
          if (!empty($form_values['values']['created'])) {
            $date = date("Y-m-d", $form_values['values']['created']);
            $time = date("H:i:s", $form_values['values']['created']);
            $publicationDate = $date."T".$time."Z";
          }
          list($status, $result) = $OS_orchestrator_inyection->UpdateSolr($form_values['values']['nid'], $form_values['values']['field_solrid'][LANGUAGE_NONE][0]['value'], $publicationDate);

          if ($status != 1) {
            drupal_set_message(t($result), 'error');
          }
          else {
            // Update field_solrid in Drupal
            $node->field_solrid[LANGUAGE_NONE][0]['value'] = $result->documentId;
            node_save($node);
          }
        }
      }
      else {
        $operation = 'Add' . ucfirst($node->type);
      }

      $content = (Array) $node;

      if (method_exists($OS_orchestrator_inyection, $operation)) {
        list($status, $result) = $OS_orchestrator_inyection->$operation($content);

        if ($status != 1) {
          drupal_set_message(t($result), 'error');
        }
        else {
          $publicationDate = '';
          if (!empty($node->created)) {
            $date = date("Y-m-d", $node->created);
            $time = date("H:i:s", $node->created);
            $publicationDate = $date."T".$time."Z";
          }

          list($status, $result) = $OS_orchestrator_inyection->UpdateSolr($node->nid, $result->documentId, $publicationDate);

          if ($status != 1) {
            drupal_set_message(t($result), 'error');
          }
          else {
            // Update field_solrid in Drupal
            $node->field_solrid[LANGUAGE_NONE][0]['value'] = $result->documentId;
            node_save($node);
          }
        }
      }

      // Redirect user to draft list.
      $_GET['destination'] = 'user/draft';
      drupal_redirect_form($form_state);

    }
    else {
      drupal_set_message(t('Content could not be updated'), 'error');
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function ag_section_post_form_post_node_form_alter(&$form, &$form_state) {
  global $language;

  // Remove all old procomun image links.
  ag_section_post_edit_form_fix_oldprocomun_images($form);

  // Hide the private field.
  $form['field_private_file']['#access'] = FALSE;

  // Licenses: Comercial use and allow modifications only visible if user is author of resource.
  $form['field_comercial_use']['#states']['visible'] = array(
    ':input[name="field_original_author[und]"]' => array('value' => '1'),
  );
  $form['field_allow_modifications']['#states']['visible'] = array(
    ':input[name="field_original_author[und]"]' => array('value' => '1'),
  );

  // Configure license.
  $comercial_use = $form['field_comercial_use'][LANGUAGE_NONE]['#default_value'];
  $allow_modifications = $form['field_allow_modifications'][LANGUAGE_NONE]['#default_value'];

  $form['current_license'] = array(
    '#type' => 'item',
    '#markup' => ag_visualization_ode_get_license_link($allow_modifications, $comercial_use),
  );

  // Add to fieldset group_license.
  $form['#group_children']['current_license'] = 'group_license';

  // Default value for language.
  $has_current_language = isset($language->language);
  $has_form_language_field = isset($form['field_general_language'][LANGUAGE_NONE]);
  if ($has_current_language && $has_form_language_field && empty($form['field_general_language'][LANGUAGE_NONE]['#default_value'])) {
    if (isset($form['field_general_language'][LANGUAGE_NONE]['#options']) && array_key_exists($language->language, $form['field_general_language'][LANGUAGE_NONE]['#options'])) {
      $form['field_general_language'][LANGUAGE_NONE]['#default_value'] = $language->language;
    }
  }

  // Hide categories, even for admin.
  if (isset($form['field_categories'])) {
    $form['field_categories']['#type'] = 'hidden';
  }

  // Change submit button label from SAve to Send.
  $form['actions']['submit']['#value'] = t('Send');

  // Override autocomplete in Procomun authors field.
  foreach ($form['field_author_ref'][LANGUAGE_NONE] as $key => $element) {
    if (is_numeric($key) && !empty($element['target_id']['#autocomplete_path'])) {
      $form['field_author_ref'][LANGUAGE_NONE][$key]['target_id']['#autocomplete_path'] = 'ag_user/field_author_ref/autocomplete';
    }
  }

  // Callback autocomplete.
  callback_author_autocomplete($form, $form_state);

  // Hide old fields field_author_ref and field_author_others.
  $form['field_author_ref']['#access'] = FALSE;
  $form['field_author_others']['#access'] = FALSE;

  // Add custom validate to transform autocomplete input value to user->name.
  // We can use: array_unshift.
  $form['#validate'] = array_merge(array('ag_general_field_author_ref_autocomplete_validate'), $form['#validate']);

  // Load progressbar and javascript setting variable after build form.
  $form['#after_build'][] = '_load_post_progressbar_after_build';

  // Add description text if current user is admin user.
  if (isset($form['og_group_ref'][LANGUAGE_NONE][0]['admin'])) {
    $form['og_group_ref'][LANGUAGE_NONE]['#description'] = t('At least one of the fields ("Your groups" or "Other groups") is required.');
  }
}

/**
 * Adds gamification progress bar and prepare fields to be processed by JS.
 *
 * Callback for ag_section_post_form_post_node_form_alter().
 *
 * @param array $form
 * @param array $form_state
 *
 * @return array
 *
 * @ingroup callbacks
 */
function _load_post_progressbar_after_build($form, $form_state) {
  if (!$form_state['rebuild']) {
    $lang = $form['#node']->language;

    // Attach JavaScript library for gamification progress bar.
    $form['#attached']['library'][] = array('system', 'ui.progressbar');

    $label_language = isset($form['nid']['#value']) ? $lang : LANGUAGE_NONE;

    $fields = array(
      // TODO - Take care of author fields.
      'titulo' => '#edit-title-field-' . $label_language . '-0-value',
      'idioma' => '#edit-field-general-language-' . $label_language,
      'cuerpo' => '#cke_edit-body-und-0-value',
      'etiquetas' => '#edit-field-labels-und',
      'area_conocimiento' => '#edit_field_knowledge_area_und_chosen',
      'contexto_educativo' => '#edit_field_learning_context_und_chosen',
      'original_author' => '#edit-field-original-author',
      'comercial_use' => '#edit-field-comercial-use',
      'allow_modifications' => '#edit-field-allow-modifications',
      'comunidades' => '#edit_og_group_ref_und_0_default_chosen',
      'visibilidad' => '#edit-field-question-share',
      'miniatura' => '#edit-field-imagen-miniatura-und-0-remove-button',
      'autores' => array(
        'full_name' => 'edit-field-contribuciones-ode-und-0-field-contribuidor-und-0-value',
        'email' => 'edit-field-contribuciones-ode-und-0-field-correo-electr-nico-und-0-email',
      ),
    );


    // Attach settings and according JavaScript file.
    drupal_add_js(drupal_get_path('module', 'ag_section_post') . '/js/post_gamification.js');
    $settings = array(
      'article_fields' => $fields,
      'lang' => $lang
    );
    drupal_add_js(array('ag_section_post' => $settings), 'setting');
  }

  return $form;
}
