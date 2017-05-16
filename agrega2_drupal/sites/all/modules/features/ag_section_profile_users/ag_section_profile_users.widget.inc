<?php
/**
 * @file In this file we keep all functions for the public users profile widget
 */

/**
 * Callback that renders the public users profile widget
 *
 * @param $profile
 *
 * @return string html iframe content that displays the public users profile
 */
function ag_section_profile_users_widget_callback($uid) {
  $public_profile = array();

  if (module_exists('innopro_services') && module_enable(array('innopro_services'))) {
    module_load_include('inc', 'innopro_services', 'innopro_services');
    $profile = user_load($uid);
    $public_profile = _innopro_services_user_public_profile($profile->mail);
    $public_profile['status'] = ($public_profile['message'] == '') ? TRUE : FALSE;

    //Get site logo
    $logo_path = theme_get_setting('logo');
    global $base_url;

    $public_profile['data']['procomun_logo'] = l(theme('image', array('path' => $logo_path)), '', array(
      'html' => TRUE,
      'absolute' => TRUE,
      'attributes' => array('class' => 'procomun-logo', 'target' => '_blank'),
    ));

    //Decode base64 profile image
    if (!empty($public_profile['data']['picture'])) {
      $imageData = base64_decode($public_profile['data']['picture']);
      $f = finfo_open();
      $mime_type = finfo_buffer($f, $imageData, FILEINFO_MIME_TYPE);
      $public_profile['data']['picture'] = '<img class="user-public-picture" width="150" height="150" alt="" src="' . 'data:' . $mime_type . ';base64,' . $public_profile['data']['picture'] . '">';

    }
    else {
      $public_profile['data']['picture'] = theme('image_style', array('style_name' => 'ag_scalecrop_150x150', 'path' => variable_get('user_picture_default'), 'getsize' => TRUE, 'attributes' => array('class' => 'user-public-picture', 'width' => '150', 'height' => '150')));
    }

    if ($public_profile['status'] && is_numeric($uid)) {
      $public_profile['data']['profile_link'] = l(t('View public profile on Procomun'), 'profile/' . $uid . '/public', array(
        'html' => TRUE,
        'absolute' => TRUE,
        'attributes' => array('target' => '_blank'),
      ));
    }

    $public_profile['data']['recent_activity'] = array(
      'label' => t('Recent activity'),
      'value' => views_embed_view('agrega2_profiles', 'panel_pane_recent_activity_profile_widget')
    );
  }
  else {
    $public_profile['message'] = t('Internal error');
    $public_profile['status'] = FALSE;
  }

  return theme('profile_users_viewer_iframe', array(
    'public_profile' => $public_profile,
  ));
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
function ag_section_profile_users_widget_delivery_callback($page_callback_result) {
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
    print theme('profile_users_widget_iframe', array('page' => $page_callback_result));
  }

  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Preprocess theme for rendering the iframe
 *
 * @param $vars
 */
function ag_section_profile_users_preprocess_user_profile(&$vars) {
  drupal_add_js(drupal_get_path('module', 'ag_section_profile_users') . '/js/profile_users_widget.js');
  drupal_add_css(drupal_get_path('module', 'ag_visualization_ode') . '/css/ode-widget.css');

  $vars['insert_link'] = theme('profile_users_widget', array('profile_url' => url('profile/' . $vars['user']->uid . '/public/widget', array('absolute' => true))));
}

/**
 * Preprocess theme for rendering the iframe
 *
 * @param $vars
 */
function ag_section_profile_users_preprocess_profile_users_widget_iframe(&$variables) {
  $variables += array(
    'body_extra_style' => '',
    'styles' => '',
  );

  $variables['head'] = drupal_get_html_head();
  $variables['css'] = drupal_add_css();

    $only_these_styles = array(
  );

  $only_these_css_expression = array(
    'main',
    'bootstrap'
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
  $variables['scripts'] = drupal_get_js();
}