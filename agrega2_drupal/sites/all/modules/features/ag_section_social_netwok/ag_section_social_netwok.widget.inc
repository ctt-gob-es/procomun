<?php
/**
 * @file In this file we keep all functions for the public community widget
 */
/**
 * Callback that renders the public community widget
 *
 * @param $profile
 *
 * @return string html iframe content that displays the public community profile
 */
function ag_section_social_netwok_widget_callback($community) {

  $path = drupal_lookup_path('source', 'comunidades/' . $community);

  if ($path) {
    $args = explode('/', $path);
    $gid = (!empty($args[1]) && is_numeric($args[1])) ? $args[1] : NULL;
  }
  else {
    $gid = NULL;
  }

  $public_community = _public_community_data($gid);

  return theme('public_community_viewer_iframe', array(
    'public_community' => $public_community,
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
function ag_section_social_netwok_widget_delivery_callback($page_callback_result) {
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
    print theme('public_community_widget_iframe', array('page' => $page_callback_result));
  }
  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 *  Implements hook_preprocess_HOOK()
 */
function ag_section_social_netwok_preprocess_content_comunity_public_dashboard(&$vars) {
  drupal_add_js(drupal_get_path('module', 'ag_section_profile_users') . '/js/profile_users_widget.js');
  drupal_add_css(drupal_get_path('module', 'ag_visualization_ode') . '/css/ode-widget.css');
  $vars['insert_link'] = theme('public_community_widget', array('community_url' => url(current_path(), array('absolute' => true)) . '/widget'));

  $path = current_path();
  if ($path) {
    $args = explode('/', $path);
    $gid = (!empty($args[1]) && is_numeric($args[1])) ? $args[1] : NULL;
  }
  else {
    $gid = NULL;
  }

  $vars['is_private'] = true;
  if ($vars['vars']['comunity_access_type'] == t('Public community')) {
    $vars['share_message'] = t('Share public community');
    $vars['is_private'] = false;
  }
  elseif ($vars['vars']['comunity_access_type'] == t('Restricted community')) {
    $vars['share_message'] = t('Share restricted community');
    $vars['is_private'] = false;
  }

  if ($gid != NULL) {
    $vars['is_member'] = og_is_member('node', $gid, 'user') ? TRUE : FALSE;
  }
  else {
    $vars['is_member'] = FALSE;
  }
}

/**
 * Preprocess theme for rendering the iframe
 *
 * @param $variables
 */
function ag_section_social_netwok_preprocess_public_community_widget_iframe(&$variables) {
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

/**
 *  Implements hook_preprocess_HOOK()
 */
function ag_section_social_netwok_preprocess_public_community_viewer_iframe(&$vars) {

  if ($vars['public_community']['status'] == TRUE && !empty($vars['public_community']['data'])) {
    $logo_path = theme_get_setting('logo');
    global $base_url;

    $vars['public_community']['data']['procomun_logo'] = l(theme('image', array('path' => $logo_path)), '', array(
      'html' => TRUE,
      'absolute' => TRUE,
      'attributes' => array('class' => 'procomun-logo', 'target' => '_blank'),
    ));

    $vars['public_community']['data']['linked_name'] = l($vars['public_community']['data']['name'], $vars['public_community']['data']['path'], array(
      'absolute' => TRUE,
      'attributes' => array('class' => 'comunity-title', 'target' => '_blank'),
    ));

    $vars['public_community']['data']['num_contents'] = array(
      'label' => t('Resources:') . ' ',
      'value' => $vars['public_community']['data']['num_contents'],
    );

    $vars['public_community']['data']['num_members'] = array(
      'label' => t('Members:') . ' ',
      'value' => $vars['public_community']['data']['num_members'],
    );

    $vars['public_community']['data']['recent_activity'] = array(
      'label' => t('Recent activity'),
      'value' => $vars['public_community']['data']['recent_activity'],
    );
  }
}
