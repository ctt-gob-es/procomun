<?php
/**
 * @file
 * ag_general.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_general_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function ag_general_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorite".
  $flags['favorite'] = array(
    'entity_type' => 'node',
    'title' => 'Favorite',
    'global' => 0,
    'types' => array(
      0 => 'post',
      1 => 'podcast',
      2 => 'ode',
      3 => 'recurso_de_aprendizaje',
      4 => 'webinar',
    ),
    'flag_short' => 'Favourite',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Favourite',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -15,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'upcoming_events' => 0,
      'newsletter' => 0,
      'lasts' => 0,
      'listing' => 0,
      'diff_standard' => 0,
      'PDF' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'activities' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ag_general',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Follow user".
  $flags['follow_user'] = array(
    'entity_type' => 'user',
    'title' => 'Follow user',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow',
    'flag_long' => 'click to follow [user:name]',
    'flag_message' => 'Now you follow [user:name]',
    'unflag_short' => 'Unfollow',
    'unflag_long' => 'Click to don\'t follow [user:name]',
    'unflag_message' => 'Now you don\'t follow [user:name]',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -16,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'public' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'ag_general',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Like".
  $flags['like'] = array(
    'entity_type' => 'node',
    'title' => 'Like',
    'global' => 0,
    'types' => array(
      0 => 'post',
      1 => 'debate',
      2 => 'podcast',
      3 => 'ode',
      4 => 'recurso_de_aprendizaje',
      5 => 'webinar',
    ),
    'flag_short' => 'Like ([node:flag-like-count])',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unlike ([node:flag-like-count])',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -13,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'upcoming_events' => 0,
      'newsletter' => 0,
      'lasts' => 0,
      'listing' => 0,
      'diff_standard' => 0,
      'PDF' => 0,
      'email_plain' => 0,
      'email_html' => 0,
      'email_textalt' => 0,
      'token' => 0,
      'activities' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'ag_general',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function ag_general_image_default_styles() {
  $styles = array();

  // Exported image style: ag_scalecrop_350x227.
  $styles['ag_scalecrop_350x227'] = array(
    'name' => 'ag_scalecrop_350x227',
    'label' => 'ag_scaleCrop_350X227',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 350,
          'height' => 227,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: avatar.
  $styles['avatar'] = array(
    'name' => 'avatar',
    'label' => 'avatar',
    'effects' => array(
      2 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
