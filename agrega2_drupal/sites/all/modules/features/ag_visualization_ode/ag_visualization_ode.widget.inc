<?php
/**
 * @file In this file we keep all functions for the visualization ode widget
 *        (probably this should be moved to a separate module)
 */

/**
 * Callback that renders the ODE visualizer widget
 *
 * @param $ode
 *
 * @return string html iframe content that displays the ode viewer + content
 */
function ag_visualization_ode_detail_widget_callback($ode) {

  $validation = _ag_visualizer_validate_params($ode);

  //Add visit to ode
  $node_nid = ag_visualization_ode_get_ode_if_exists($ode['id']);
  $user = $GLOBALS['user']->uid;
  $total_visits = ag_visualization_ode_node_view_count($node_nid, $user, $ode['id']);

  if (!$validation['ok']) {
    // @todo improve error handling messages
    return $validation['message'];
  }

  // Check if node exists, to load comments, number of visits, etc.
  return theme('ode_viewer_iframe', array(
    'properties' => $ode,
  ));
}

/**
 * Prepares the friendly code that renders the visualization widget
 *
 * @param $ode_id
 *
 * @return string html
 */
function _get_ode_widget_code($ode_id) {
  $ode_widget_js = file_create_url(drupal_get_path('module', 'ag_visualization_ode') . '/js/ode-widget.js', array('absolute' => TRUE));
  if (($pos = strpos($ode_widget_js, '://')) !== FALSE) {
    $ode_widget_js = substr($ode_widget_js, $pos);
  }
  return theme('ode_widget', array('ode_id' => $ode_id, 'ode_widget_js' => $ode_widget_js));
}

/**
 * Preprocess theme for rendering the iframe
 *
 * @param $vars
 */
function ag_visualization_ode_preprocess_ode_viewer_iframe(&$vars) {

  drupal_add_js(drupal_get_path('module', 'ag_visualization_ode') . '/js/visualization_ode_controller.js');
  drupal_add_js(drupal_get_path('module', 'ag_visualization_ode') . '/js/visualization_ode.js');
  drupal_add_css(drupal_get_path('module', 'ag_visualization_ode') . '/css/ode-widget.css');

  $properties = & $vars['properties'];

  $orquestador_url = variable_get('orchestrator_url', '***********************');
  $vars['ode_visualizer_url'] = $orquestador_url . '/Orquestador/visualizer/html/visualizer_ajax.html';

  if (!empty($properties['odeNode'])) {
    $ode_repository_url = 'http://' . trim($properties['odeNode'], '/');
  }
  else {
    $ode_repository_url = ag_visualization_ode_check_ode_origin($properties['mecIdentifierStr']);
  }

  //TODO: IMPROVE THIS, TEMPORARY FIX. GET PARAMETERS SHOULD IMPROVE AS WEBSERVICE?
  /*
  $download_ode = $ode_repository_url . '/buscador2/DescargarODECU/DescargarODECU.do?identificadorODE=' . $properties['mecIdentifierStr'];
  $download_ode .= '&idioma=es';
  $download_ode .= '&tipoLayoutBuscador=BUSCADOR';
  $download_ode .= '&mostrarVuelta=true';
  $download_ode .= '&areaCurricularBusqueda=';
  $download_ode .= '&tieneIdentidadFederada=false';
  $download_ode .= '&nodoOrigen=';
  $download_ode .= '&mostrarVuelta=true';
  $download_ode .= '&idLicencia=6.2.13';

  $vars['download_ode_link'] = $download_ode;
  */
  $ode_lang = !empty($properties['generalLanguageStr'][0]) ? $properties['generalLanguageStr'][0] : 'es';
  $vars['download_form'] = drupal_get_form('ag_visualization_ode_get_ode_formats', $properties['mecIdentifierStr'], $ode_lang);

  /* @todo review the insert url and anchor content */
  $vars['insert_link'] = _get_ode_widget_code($properties['id']);
  $vars['fullscreen_link'] = l(t('Fullscreen'), 'ode/view/' . $properties['id'] . '/widget', array('attributes' => array('target' => '_blank')));

  /* @todo review, colocar la URL de acceso al json que provee los datos del ODE */
  //Changed odeTreeData endpoint in orchestrator. Needs language now.
  $language = isset($properties['generalLanguageStr'][0]) ? $properties['generalLanguageStr'][0] : 'es';
  $ode_source = "../../rest/odeTreeData/" . $properties['id'] . "/" . $language;

  $ode_config = array(
    'AG_ode_visualizer' => array('ode_source' => $ode_source)
  );

//  $env = 'dev';
//  if ($env == 'dev') {
//    $vars['ode_visualizer_url'] = file_create_url(drupal_get_path('module', 'ag_visualization_ode') . "/ode_visualizer/html/visualizer_ajax.html");
////    $ode_source = $orquestador_url . "/Orquestador/rest/odeTreeData/" . $properties['id'];
//    $ode_source = './test2.json';
//    $ode_config = array(
//      'AG_ode_visualizer' => array('ode_source' => $ode_source)
//    );
//  }

  drupal_add_js($ode_config, 'setting');

}

/**
 * Packages and sends the result of a page callback to the browser as HTML.
 *
 * @param $page_callback_result
 *   The result of a page callback. Can be one of:
 *   - NULL: to indicate no content.
 *   - An integer menu status constant: to indicate an error condition.
 *   - A string of HTML content.
 *   - A renderable array of content.
 *
 * @see drupal_deliver_page()
 */
function ag_visualization_ode_widget_delivery_callback($page_callback_result) {
  // Emit the correct charset HTTP header, but not if the page callback
  // result is NULL, since that likely indicates that it printed something
  // in which case, no further headers may be sent, and not if code running
  // for this page request has already set the content type header.
  if (isset($page_callback_result) && is_null(drupal_get_http_header('Content-Type'))) {
    drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
  }

  // Send appropriate HTTP-Header for browsers and search engines.
  global $language;
  drupal_add_http_header('Content-Language', $language->language);

  // Menu status constants are integers; page content is a string or array.
  if (is_int($page_callback_result)) {
    // Use the default delivery.
    return drupal_deliver_html_page($page_callback_result);
  }
  elseif (isset($page_callback_result)) {
    // Print anything besides a menu constant, assuming it's not NULL or
    // undefined.
    $content = is_array($page_callback_result) ? drupal_render($page_callback_result) : $page_callback_result;
    print theme('ode_visualization_widget_iframe', array('page' => $page_callback_result));
  }

  // Perform end-of-request tasks.
  drupal_page_footer();
}


/**
 * Preprocess variables for iframe.
 */
function template_preprocess_ode_visualization_widget_iframe(&$variables) {

  $variables += array(
    'page_top' => '',
    'page_bottom' => '',
    'styles' => '',
  );

  $variables['head'] = drupal_get_html_head();
  $variables['css'] = drupal_add_css();

// We alter js files here instead hook_js_alter() because
// this hook may alter js in all pages.
  $javascript = drupal_add_js();

  $only_these_js = array(
    "settings",
    "misc/drupal.js",
  );

  $only_these_js_expression = array(
    "jquery",
    "visualization_ode"
  );

  $validateJS = function ($js) use ($only_these_js_expression) {
    foreach ($only_these_js_expression as $string) {
      if (strpos($js, $string) !== FALSE) {
        return TRUE;
      }
    }
    return FALSE;
  };

  foreach ($javascript as $id => $conf) {
    if (!in_array($id, $only_these_js) && !$validateJS($id)) {
//Inline settings are represented as int ID's
      if (!is_int($id)) {
        unset($javascript[$id]);
      }
    }
  }

  $only_these_styles = array(
  );

  $only_these_css_expression = array(
    'ode-widget'
  );

  $validateCSS = function ($css) use ($only_these_css_expression) {
    foreach ($only_these_css_expression as $string) {
      if (strpos($css, $string) !== FALSE) {
        return TRUE;
      }
    }
    return FALSE;
  };

  foreach ($variables['css'] as $id => $conf) {
    if (!in_array($id, $only_these_styles) && !$validateCSS($id)) {
      unset($variables['css'][$id]);
    }
  }

  $variables['styles'] = drupal_get_css($variables['css'], TRUE);

//Build restricted javascript
  $variables['scripts'] = drupal_get_js("header", $javascript);

  $variables['base_path'] = base_path();
  $variables['front_page'] = url();
  $variables['feed_icons'] = drupal_get_feeds();
  $variables['language'] = $GLOBALS['language'];
  $variables['language']->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';
  $variables['logo'] = theme_get_setting('logo');
  $variables['site_name'] = (theme_get_setting('toggle_name') ? filter_xss_admin(variable_get('site_name', 'Drupal')) : '');
  $variables['site_slogan'] = (theme_get_setting('toggle_slogan') ? filter_xss_admin(variable_get('site_slogan', '')) : '');
  $variables['tabs'] = menu_local_tabs();

// RDFa allows annotation of XHTML pages with RDF data, while GRDDL provides
// mechanisms for extraction of this RDF content via XSLT transformation
// using an associated GRDDL profile.
  $variables['rdf_namespaces'] = drupal_get_rdf_namespaces();
  $variables['grddl_profile'] = 'http://www.w3.org/1999/xhtml/vocab';
  $variables['language'] = $GLOBALS['language'];
  $variables['language']->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

// Add favicon.
  if (theme_get_setting('toggle_favicon')) {
    $favicon = theme_get_setting('favicon');
    $type = theme_get_setting('favicon_mimetype');
    drupal_add_html_head_link(array(
      'rel' => 'shortcut icon',
      'href' => drupal_strip_dangerous_protocols($favicon),
      'type' => $type
    ));
  }

// Construct page title.
  if (drupal_get_title()) {
    $head_title = array(
      'title' => strip_tags(drupal_get_title()),
      'name' => check_plain(variable_get('site_name', 'Drupal')),
    );
  }
  else {
    $head_title = array('name' => check_plain(variable_get('site_name', 'Drupal')));
    if (variable_get('site_slogan', '')) {
      $head_title['slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
  }
  $variables['head_title_array'] = $head_title;
  $variables['head_title'] = implode(' | ', $head_title);

// Populate the page template suggestions.
  if ($suggestions = theme_get_suggestions(arg(), 'html')) {
    $variables['theme_hook_suggestions'] = $suggestions;
  }
}

/**
 * Function to get form with ode download formats
 */
function ag_visualization_ode_get_ode_formats($form, $form_state, $mec, $ode_lang) {
  $form = array();

  //Get options for format download select
  $orch_authoring = new OS_orchestrator_authoring();
  $result = $orch_authoring->getPifTypes($mec);

  $options = array('' => '---');
  if (isset($result[0]) && $result[0] && !empty($result[1])) {
    $ode_options = ag_visualization_ode_get_ode_formats_options($result[1]);
    $options += $ode_options;
  }
  $form['format_ode_download'] = array(
   '#type' => 'select',
   '#title' => t('Download as'),
   '#options' => $options,
  );
  $form['mec'] = array(
    '#type' => 'hidden',
    '#value' => $mec,
  );
  $form['ode_lang'] = array(
    '#type' => 'hidden',
    '#value' => $ode_lang,
  );
  $form['op'] = array (
    '#type' => 'submit',
    '#value' => t('Download'),
  );
  return $form;
}

/**
 * Submit function for ode download formats
 */
function ag_visualization_ode_get_ode_formats_submit($form, &$form_state) {

  if (isset($form_state['values']['format_ode_download']) && !empty($form_state['values']['mec']) && !empty($form_state['values']['ode_lang'])) {
    $format_ode_download_ws = $form_state['values']['format_ode_download'];
    //Call WS function
    $OS_orchestrator_publisher = new OS_orchestrator_publisher();
    if ($format_ode_download_ws != 'IMAGEN') {
      $result = $OS_orchestrator_publisher->getOdeWithFormat($format_ode_download_ws, $form_state['values']['mec'], $form_state['values']['ode_lang']);
    }
    else {
      $result = $OS_orchestrator_publisher->getOdeImageFormat($form_state['values']['mec'], $form_state['values']['ode_lang']);
    }

    //Get file from remote url
    if (!empty($result->return)) {
      $path = $result->return;
      ag_visualization_ode_download_ode($path, $format_ode_download_ws);
    }
  }
}

/**
 * Function for getting options ode download formats
 */
function ag_visualization_ode_get_ode_formats_options($options) {
  $ode_options = array();

  if (!empty($options)) {
    foreach ($options as $option) {
      switch ($option) {
        case 'SCORM_2004':
          $ode_options[$option] = 'SCORM 2004';
        break;
        case 'SCORM_12':
          $ode_options[$option] = 'SCORM 1.2';
        break;
        case 'IMS_CP':
          $ode_options[$option] = 'IMSCP';
        break;
        case 'HTML':
          $ode_options[$option] = 'HTML';
        break;
        case 'IMAGEN':
          $ode_options[$option] = t('Image');
        break;
      }
    }
  }

  return $ode_options;
}

/**
 * Function for serving file to download
 */
function ag_visualization_ode_download_ode($path, $format_ode_download_ws) {
  if (!empty($path)) {
    if ($format_ode_download_ws != 'IMAGEN') {
      drupal_add_http_header('Location', $path);
      drupal_exit($path);
    }
    else {
      //Parse data from concat base64 string
      $image_data = explode(',', $path);
      $image_mime_type = str_replace(';base64', '', str_replace('data:', '', $image_data[0]));
      $image_ext = explode('/', $image_mime_type);
      drupal_add_http_header('Pragma', 'public');
      drupal_add_http_header('Expires', '0');
      drupal_add_http_header('Cache-Control', 'must-revalidate, post-check=0, pre-check=0');
      drupal_add_http_header('Content-Transfer-Encoding', 'binary');
      drupal_add_http_header('Content-Type', $image_mime_type);
      drupal_add_http_header('Content-Disposition', 'attachment; filename=ode_image.' . $image_ext[1] . ';');
      echo base64_decode($image_data[1]);
      drupal_exit();
    }
  }
}