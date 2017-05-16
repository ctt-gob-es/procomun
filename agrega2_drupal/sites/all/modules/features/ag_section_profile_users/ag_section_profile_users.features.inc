<?php
/**
 * @file
 * ag_section_profile_users.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_profile_users_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_profile_users_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ag_section_profile_users_image_default_styles() {
  $styles = array();

  // Exported image style: ag_scalecrop_150x150.
  $styles['ag_scalecrop_150x150'] = array(
    'name' => 'ag_scalecrop_150x150',
    'label' => 'ag_scaleCrop_150x150',
    'effects' => array(
      3 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function ag_section_profile_users_default_profile2_type() {
  $items = array();
  $items['cv'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "cv",
    "label" : "Mi CV",
    "weight" : "8",
    "data" : { "registration" : 0 }
  }');
  $items['datos_organizacion'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "datos_organizacion",
    "label" : "Datos organizaci\\u00f3n",
    "weight" : "0",
    "data" : { "registration" : 1 }
  }');
  $items['datos_personales'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "datos_personales",
    "label" : "Mis datos personales",
    "weight" : "0",
    "data" : { "registration" : 1 }
  }');
  return $items;
}
