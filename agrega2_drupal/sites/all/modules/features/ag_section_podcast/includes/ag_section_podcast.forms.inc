<?php
/**
 * @file
 * Setting up the configuration for podcast.
 */

include_once drupal_get_path('module', 'ag_section_podcast') . '/includes/soundcloud/src/Soundcloud/autoload.php';
use Njasm\Soundcloud\SoundcloudFacade;
// or soundcloud if you don't need a facade for specific tasks
use Njasm\Soundcloud\Soundcloud;

// Soundcloud upload allowed file types.
define('SOUNDCLOUD_FILE_TYPE', 'aiff wav flac alac ogg mp2 mp3 aac amr wma');
// Upload max file size in MB.
define('SOUNDCLOUD_FILE_SIZE', 128);
// Soundcloud App client id.
define('SOUNDCLOUD_CLIENT_ID', '********************************');
// Soundcloud App client secret.
define('SOUNDCLOUD_CLIENT_SECRET', '********************************');
// Soundcloud account user name.
define('SOUNDCLOUD_USERNAME', '**********************');
// Soundcloud account password.
define('SOUNDCLOUD_PASSWORD', '**********************');

/////////////
/// HOOKS ///
/////////////

/**
 * Implements hook_form_FORM_ID_alter() for podcast_node_form().
 */
function ag_section_podcast_form_podcast_node_form_alter(&$form, &$form_state, $form_id) {
  global $language;

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

  // Node add mode.
  if (!$form['nid']['#value']) {

    // Podcast name.
    $form['podcast_name'] = array(
      '#name' => 'podcast_name',
      '#type' => 'textfield',
      '#title' => t('Podcast name'),
      '#size' => 64,
      '#maxlenght' => 128,
      '#weight' => 3.4,
      '#required' => TRUE,
    );

    // Podcast file label definition.
    $podcast_file_label_array = array(
      'label' => array(
        'label_name' => array(
          '#markup' => t('Podcast file'),
        ),
        'label_required' => array(
          '#prefix' =>'<span class="form-required" title="' . t('This field is required.') . '">',
          '#markup' => ' *',
          '#suffix' => '</span>',
        ),
      ),
      '#theme_wrapper' => array('container'),
    );

    // Podcast file.
    $form['podcast_file'] = array(
      '#name' => 'podcast_file',
      '#type' => 'file',
      '#title' => render($podcast_file_label_array['label']),
      '#description' => t('You can upload AIFF, WAVE (WAV), FLAC, ALAC, OGG, MP2, MP3, AAC, AMR and WMA files. The maximum file size is @sizeMB.',
        array('@size' => SOUNDCLOUD_FILE_SIZE)),
      '#size' => 64,
      '#weight' => 3.5,
    );

    // Add to fieldset group_podcast_name.
    $form['#group_children']['podcast_name'] = 'group_podcast';
    $form['#group_children']['podcast_file'] = 'group_podcast';

    // Add custom validate.
    $form['#validate'][] = 'ag_section_podcast_soundcloud_upload_validate';

    // Add custom class to submit button.
    $form['actions']['submit']['#attributes']['class'][] = 'form-submit-podcast';

    // Attach Soundcloud upload screen js.
    $form['#attached']['js'] = array(drupal_get_path('module', 'ag_section_podcast') . '/js/upload_progress.js', 'file');
  }
  // Node edit mode.
  else {
    // Hide field_imagen_miniatura.
    $form['field_imagen_miniatura']['#access'] = FALSE;
  }

  // Hide field_podcast_url.
  $form['field_podcast_url']['#access'] = FALSE;

}

/**
 * Validate custom upload file field and upload to Soundcloud account that file
 * if there are no errors.
 *
 * Callback for ag_section_podcast_form_podcast_node_form_alter().
 *
 * @param array $form
 *   Contains the structure of the form.
 * @param array $form_state
 *   Contains the state of the form.
 *
 */
function ag_section_podcast_soundcloud_upload_validate($form, &$form_state) {
  $errors = form_get_errors();

  // Validate custom file field.
  if (!isset($_FILES['podcast_file']['tmp_name']) ||
      empty($_FILES['podcast_file']['tmp_name'])) {
    $message = t('The field Podcast file is required');
    $errors['podcast_file'] = $message;
    form_set_error('podcast_file', $message);
  }
  else {
    // Create temporal file class to reuse drupal file validate functions.
    $file = new stdClass();
    $file->filename = $_FILES['podcast_file']['name'];
    $file->filesize = $_FILES['podcast_file']['size'];

    // Validate file type.
    $validate_extension = file_validate_extensions($file, SOUNDCLOUD_FILE_TYPE);
    if (!empty($validate_extension)) {
      $errors['podcast_file'] = $validate_extension[0];
      form_set_error('podcast_file', $validate_extension[0]);
    }

    // Validate file size.
    $validate_size = file_validate_size($file, SOUNDCLOUD_FILE_SIZE * 1024 * 1024);
    if (!empty($validate_size)) {
      $errors['podcast_file'] = $validate_size[0];
      form_set_error('podcast_file', $validate_size[0]);
    }
  }

  if (!$errors) {
    // Soundcloud app connection.
    $soundcloud = soundcloud_app_connection();

    // Soundcloud upload.
    $trackPath = $_FILES['podcast_file']['tmp_name'];
    $trackData = array(
      'title' => $form_state['values']['podcast_name'],
      'downloadable' => TRUE,
    );

    // Add artwork image if proceed.
    $fid = $form_state['values']['field_imagen_miniatura'][LANGUAGE_NONE][0]['fid'];
    if (isset($fid) && $fid != 0) {
      $file = file_load($fid);
      $relative_path = variable_get('file_public_path', conf_path() . '/files') . '/' . file_uri_target($file->uri);
      $trackData['artwork_data'] = '@' . $relative_path;
    }

    $response = $soundcloud->upload($trackPath, $trackData);

    // Manage response.
    if ($response->getHttpCode() == '201') {
      $body = $response->bodyArray();
      $form_state['values']['field_podcast_url'][LANGUAGE_NONE][0]['url'] = $body['permalink_url'];
      $form_state['values']['field_soundcloud_trackid'][LANGUAGE_NONE][0]['value'] = $body['id'];
      $form_state['values']['field_file_size'][LANGUAGE_NONE][0]['value'] = $_FILES['podcast_file']['size'];
    }
    else {
      form_set_error('error', t('Soundcloud error: ') . $response->getErrorString());
    }
  }
}

/////////////////
/// CALLBACKS ///
/////////////////

/**
 * Delete file from Soundcloud account.
 *
 * Callback for _orchestrator_services_delete_content().
 *
 * @param object $node
 *   Contains the node object.
 *
 */
function soundcloud_delete_content($node) {
  if ($node->type == 'podcast') {
    $track_id = $node->field_soundcloud_trackid[LANGUAGE_NONE][0]['value'];
    if (isset($track_id) && !empty($track_id)) {
      // Soundcloud app connection.
      $soundcloud = soundcloud_app_connection();

      // Soundcloud delete.
      $soundcloud->delete('/tracks/' . $track_id);
      $response = $soundcloud->request();
    }
  }
}

/**
 * Soundcloud authentication.
 *
 * Callback for ag_section_podcast_form_alter().
 * Callback for _soundcloud_delete_content().
 *
 * @return object $facade
 *   Return soundcloud manage object.
 *
 */
function soundcloud_app_connection() {
  // Soundcloud manage.
  // Soundcloud connection.
  $clientID = SOUNDCLOUD_CLIENT_ID;
  $clientSecret = SOUNDCLOUD_CLIENT_SECRET;
  $facade = new SoundcloudFacade($clientID, $clientSecret);
  if (!variable_get('soundcloud_oauth_token')) {
    $username = SOUNDCLOUD_USERNAME;
    $password = SOUNDCLOUD_PASSWORD;
    // On success, access_token is set by default for next requests.
    $facade->userCredentials($username, $password);
    variable_set('soundcloud_oauth_token', $facade->getAuthToken());
  }
  else {
    $facade->setAccessToken(variable_get('soundcloud_oauth_token'));
    $facade->setAuthScope('non-expiring');
  }

  return $facade;
}
