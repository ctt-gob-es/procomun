<?php
/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_user(&$vars) {
  global $user;
  $properties = & $vars['properties'];
  // Set default user picture.
    if (empty($properties['userPicture'])) {
    $default_image = variable_get('user_picture_default', '');
    $properties['userPicture'] = theme('image_style', array(
      'style_name' => 'medium',
      'path' => $default_image,
      'alt' => $properties['userNameStr'] . ' ' . $properties['userSurNameStr']
    ));
    }
  if(isset($properties['idDrupal'])){
    $properties['userName'] = "";
    $properties['userName'] .= l((!isset($properties['userNameStr']) ? : $properties['userNameStr']) .
      ' ' . (!isset($properties['userSurNameStr']) ? : $properties['userSurNameStr']), 'profile/' . $properties['idDrupal'] . '/public');
  }else{
    $properties['userName'] = (!isset($properties['userNameStr']) ? : $properties['userNameStr']) .
      ' ' . (!isset($properties['userSurNameStr']) ? : $properties['userSurNameStr']);
  }
  if ($user->uid > 0) {
    if (isset($properties['userCountryStr']) && $properties['userCountryStr'] == 'Spain') {
      $properties['userLocality'] = "";
      $properties['userLocality'] .= !isset($properties['userLocalityStr']) ?: $properties['userLocalityStr'];
      $properties['userLocality'] .= !isset($properties['userProvinceStr']) ?: ', ' . $properties['userProvinceStr'];
      $properties['userLocality'] .= !isset($properties['userCountryStr']) ?: ' (' . t($properties['userCountryStr']) . ')';
    }
    else {
      $properties['userLocality'] = "";
      $properties['userLocality'] .= !isset($properties['userPlaceStr']) ?: $properties['userPlaceStr'];
      $properties['userLocality'] .= !isset($properties['userCountryStr']) ?: ' (' . t($properties['userCountryStr']) . ')';
    }
    if (isset($properties['labelsStr'])) {
      _build_tags($properties, 'labelsStr');
    }
    _remove_private_data($properties);
  }
  else {
    unset($properties['userCountryStr']);
    unset($properties['userEducativeCenterStr']);
    unset($properties['userPlaceStr']);
  }
}
/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_community(&$vars) {
  $properties = & $vars['properties'];
  // Set default user picture.
  if (empty($properties['communityPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/comunidades_default.jpg';
    $properties['communityPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : '',
      'attributes' => array('class' => $default_image)
    ));
  }
  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);
  if (isset($properties['communityLabelsStr'])) {
    _build_tags($properties, 'communityLabelsStr');
  }
}
/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_question(&$vars) {
  $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['questionPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/preguntas_default.jpg';
    $properties['questionPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

  if (isset($properties['questionLabelsStr'])) {
    _build_tags($properties, 'questionLabelsStr');
  }

}

/**
 * Implements hook_preprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_url(&$vars) {
    $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['urlPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/url_default.jpg';
    $properties['urlPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

  if (isset($properties['url'])) {
    $properties['url'] = l($properties['url'], link_cleanup_url($properties['url']), array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ));
  }

  if (isset($properties['labelsStr'])) {
    _build_tags($properties, 'labelsStr');
  }

}

/**
 * Implements hook_preprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_response(&$vars) {
  $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['responsePicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/respuestas_default.jpg';
    $properties['responsePicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

  if (isset($properties['responseLabelsStr'])) {
    _build_tags($properties, 'responseLabelsStr');
  }

}

/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_event(&$vars) {
  $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['eventPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/eventos_default.jpg';
    $properties['eventPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

  if (isset($properties['eventLabelsStr'])) {
    _build_tags($properties, 'eventLabelsStr');
  }

}

/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_discussion(&$vars) {
  $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['discussionPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/debates_default_02.jpg';
    $properties['discussionPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

  if (isset($properties['discussionLabelsStr'])) {
    _build_tags($properties, 'discussionLabelsStr');
  }

}

/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_ode(&$vars) {
  $properties = & $vars['properties'];

  //Split all tags with commas. Sometimes solr returns one long tag with lots of them.
  if (isset($properties['labelsStr'])) {
    $properties['labelsStr'] = _split_tags($properties['labelsStr']);
  }
  if (isset($properties['keywords'])) {
    $properties['keywords'] = _split_tags($properties['keywords']);
  }
  if (isset($properties['generalKeywordStr'])) {
    $properties['generalKeywordStr'] = _split_tags($properties['generalKeywordStr']);
  }

  // If no thumbnail image insert an image by default.
  if (empty($properties['preview'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
    $properties['default_image'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['title']) ? $properties['title'] : t('default image')
    ));
  }

  $properties['titleStr'] = empty($properties['generalTitleStr']) ? : l($properties['generalTitleStr'], 'ode/view/' . $properties['id']);

  // @todo realmente es un array?
  $properties['generalDescriptionStr'] = (!empty($properties['generalDescriptionStr']) && is_array($properties['generalDescriptionStr'])) ? $properties['generalDescriptionStr'][0] : "";

  if (!empty($properties['certified'])) {
    $properties['certified'] = l(t('Quality accredited by INTEF') , 'javascript:', array('external' => TRUE, 'attributes' => array('title' => t('Quality accredited by INTEF'))));
  }

  //Tags
  if (isset($properties['generalKeywordStr'])) {
    _build_tags($properties, 'generalKeywordStr', array('type' => 'LEARNING_RESOURCE'));
  }
  //New field knowledgeArea
  if (isset($properties['knowledgeArea'])) {
    _build_tags_from_taxonomy($properties, 'knowledgeArea', array('type' => 'LEARNING_RESOURCE'), 'knowledgeAreaTags', 'knowledgearea');
  }
  //New field learningContext
  if (isset($properties['learningContext'])) {
    _build_tags_from_taxonomy($properties, 'learningContext', array('type' => 'LEARNING_RESOURCE'), 'learningContextTags', 'learningcontext');
  }
  //New field learningContext
  if (isset($properties['resourceType'])) {
    _build_tags_from_taxonomy($properties, 'resourceType', array('type' => 'LEARNING_RESOURCE'), 'resourceTypeTags', 'recurso_educativo');
  }

  if (!empty($properties['educationalLearningResourceTypeStr'])) {
    $type_resource = array();

    foreach (array_keys($properties['educationalLearningResourceTypeStr']) as $elem) {
      $type_resource[] = l(
        $properties['educationalLearningResourceTypeStr'][$elem],
        'ode-search',
        array(
          'query' => array(
            'query' => '',
            'type' => 'LEARNING_RESOURCE',
            'f[0]' => 'educationalLearningResourceTypeStr:"' . $properties['educationalLearningResourceTypeStr'][$elem] . '"'
          )
        ));
    }

    $properties['typeResource'] = implode(', ', $type_resource);
  }

  if (!empty($properties['technicalFormatStr'])) {
    $type_format = array();

    foreach (array_keys($properties['technicalFormatStr']) as $elem) {

      $type_format[] = l($properties['technicalFormatStr'][$elem], 'ode-search', array(
        'query' => array(
          'query' => '',
          'type' => 'LEARNING_RESOURCE',
          'f[0]' => 'technicalFormatStr:"' . $properties['technicalFormatStr'][$elem] . '"'
        )
      ));
    }

    $properties['formatResource'] = implode(', ', $type_format);
  }

  // Add new system ode author.
  //$username_text = ag_visualization_ode_get_author($properties, true);
  //$properties['authorStr'] = $username_text;

  // New way for get publicator from publicatorStr / publicatorEmailStr solr
  // fields.
  $username_text = ag_visualization_ode_new_get_publicator($properties, 'ode-search');
  $properties['authorStr'] = $username_text;
}

/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_learning_resource(&$vars) {
  $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['generalPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
    $properties['generalPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['title']) ? $properties['title'] : t('default image')
    ));
  }

  //Enlace al nodo si tenemos titulo y idDrupal, si no, sin titulo? y sin enlace.
  if (isset($properties['idDrupal']) && !empty($properties['generalTitleStr'])) {
    $path = drupal_get_path_alias('node/' . $properties['idDrupal']);
    $properties['titleStr'] = empty($properties['generalTitleStr']) ? : l($properties['generalTitleStr'], $path);
  }
  else {
    $properties['titleStr'] = empty($properties['generalTitleStr']) ? t('Untitled') : $properties['generalTitleStr'];
  }

  // @todo realmente es un array?
  $properties['generalDescriptionStr'] = (!empty($properties['generalDescriptionStr']) && is_array($properties['generalDescriptionStr'])) ? $properties['generalDescriptionStr'][0] : "";

  if (isset($properties['generalKeywordStr'])) {
    _build_tags($properties, 'generalKeywordStr');
  }

  if (!empty($properties['educationalLearningResourceTypeStr'])) {
    $type_resource = array();

    foreach (array_keys($properties['educationalLearningResourceTypeStr']) as $elem) {
      $type_resource[] = l(
        $properties['educationalLearningResourceTypeStr'][$elem],
        'ode-search',
        array(
          'query' => array(
            'query' => '',
            'type' => 'LEARNING_RESOURCE',
            'f[0]' => 'educationalLearningResourceTypeStr:"' . $properties['educationalLearningResourceTypeStr'][$elem] . '"'
          )
        ));
    }

    $properties['typeResource'] = implode(', ', $type_resource);
  }

  if (!empty($properties['technicalFormatStr'])) {
    $type_format = array();

    foreach (array_keys($properties['technicalFormatStr']) as $elem) {

      $type_format[] = l($properties['technicalFormatStr'][$elem], 'ode-search', array(
        'query' => array(
          'query' => '',
          'type' => 'LEARNING_RESOURCE',
          'f[0]' => 'technicalFormatStr:"' . $properties['technicalFormatStr'][$elem] . '"'
        )
      ));
    }

    $properties['formatResource'] = implode(', ', $type_format);
  }

  $vcard = isset($properties['authorStr']) ? $properties['authorStr'] : FALSE;

  if ($vcard !== FALSE) {
    preg_match("/(?P<begin>FN:)(.*)(?P<end>EMAIL)/", $vcard, $author);
  }
  else {
    $author = array();
  }

  $properties['author'] = $author;

}

/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_poll(&$vars) {
  $properties = & $vars['properties'];

  // Set default user picture.
  if (empty($properties['pollPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/encuestas_default.jpg';
    $properties['pollPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

  if (isset($properties['pollLabelsStr'])) {
    _build_tags($properties, 'pollLabelsStr');
  }
}

/**
 * Implements hook_proprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_post(&$vars) {
  $properties = & $vars['properties'];
  //Redirect all previous CKEditor images to their new locations.
  ag_section_post_fix_oldprocomun_images($properties['descriptionStr']);

  //Remove from search any base64image that may be tough to render.
  ag_section_post_remove_base64_images_from_search($properties['descriptionStr']);

  //Truncate description to 500 characters preseving html tags
  $properties['descriptionStr'] = DrupalToolKit::truncateHtml($properties['descriptionStr'], 500, array('ending' => '...', 'exact' => TRUE, 'html' => TRUE));

  // Set default user picture.
  if (empty($properties['postPicture']) && !empty($properties['preview']) && file_exists(drupal_realpath('.') . $properties['preview'])) {
    $properties['postPicture'] = theme('image', array(
      'path' => $properties['preview'],
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  if (empty($properties['postPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
    $properties['postPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  if (isset($properties['idDrupal'])) {
    $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

    //Add Read more button
    $properties['readmore'] = l(t('Read more'), 'node/' . $properties['idDrupal']);
  }
  else {
    $properties['titleStr'] = empty($properties['titleStr']) ? t('Untitled'): $properties['titleStr'];
  }

  if (isset($properties['postLabelsStr'])) {
    _build_tags($properties, 'postLabelsStr');
  }
  //New field knowledgeArea
  if (isset($properties['knowledgeArea'])) {
    _build_tags_from_taxonomy($properties, 'knowledgeArea', array('type' => 'POST'), 'knowledgeAreaTags', 'knowledgearea');
  }
  //New field learningContext
  if (isset($properties['learningContext'])) {
    _build_tags_from_taxonomy($properties, 'learningContext', array('type' => 'POST'), 'learningContextTags', 'learningcontext');
  }
}

/**
 * Implements hook_preprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_learning_path(&$vars) {
  $properties = & $vars['properties'];
  // Redirect all previous CKEditor images to their new locations.
  ag_section_post_fix_oldprocomun_images($properties['descriptionStr']);

  // Remove from search any base64image that may be tough to render.
  ag_section_post_remove_base64_images_from_search($properties['descriptionStr']);

  // Truncate description to 500 characters preseving html tags.
  $properties['descriptionStr'] = DrupalToolKit::truncateHtml($properties['descriptionStr'], 500, array('ending' => '...', 'exact' => TRUE, 'html' => TRUE));

  if (isset($properties['idDrupal'])) {
    $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);

    // Add Read more button.
    $properties['readmore'] = l(t('Read more'), 'node/' . $properties['idDrupal']);
  }
  else {
    $properties['titleStr'] = empty($properties['titleStr']) ? t('Untitled'): $properties['titleStr'];
  }

  if (isset($properties['labelsStr'])) {
    _build_tags($properties, 'labelsStr');
  }
  // New field knowledgeArea.
  if (isset($properties['knowledgeArea'])) {
    _build_tags_from_taxonomy($properties, 'knowledgeArea', array('type' => 'LEARNING_PATH'), 'knowledgeAreaTags', 'knowledgearea');
  }
  // New field learningContext.
  if (isset($properties['learningContext'])) {
    _build_tags_from_taxonomy($properties, 'learningContext', array('type' => 'LEARNING_PATH'), 'learningContextTags', 'learningcontext');
  }
}

/**
 * Implements hook_preprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_podcast(&$vars) {
  $properties = & $vars['properties'];

  // Redirect all previous CKEditor images to their new locations.
  ag_section_post_fix_oldprocomun_images($properties['descriptionStr']);

  // Remove from search any base64image that may be tough to render.
  ag_section_post_remove_base64_images_from_search($properties['descriptionStr']);

  // Truncate description to 500 characters preseving html tags.
  $properties['descriptionStr'] = DrupalToolKit::truncateHtml($properties['descriptionStr'], 500, array('ending' => '...', 'exact' => TRUE, 'html' => TRUE));

  // Set default user picture.
  if (empty($properties['podcastPicture']) && !empty($properties['preview']) && file_exists(drupal_realpath('.') . $properties['preview'])) {
    $properties['podcastPicture'] = theme('image', array(
      'path' => $properties['preview'],
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  if (empty($properties['podcastPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/podcast_default.jpg';
    $properties['podcastPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  if (isset($properties['idDrupal'])) {
    $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);
    // Add Read more button.
    $properties['readmore'] = l(t('Read more'), 'node/' . $properties['idDrupal']);
  }
  else {
    $properties['titleStr'] = empty($properties['titleStr']) ? t('Untitled'): $properties['titleStr'];
  }

  if (isset($properties['labelsStr'])) {
    _build_tags($properties, 'labelsStr');
  }

  // Field knowledgeArea.
  if (isset($properties['knowledgeArea'])) {
    _build_tags_from_taxonomy($properties, 'knowledgeArea', array('type' => 'PODCAST'), 'knowledgeAreaTags', 'knowledgearea');
  }

  // Field learningContext.
  if (isset($properties['learningContext'])) {
    _build_tags_from_taxonomy($properties, 'learningContext', array('type' => 'PODCAST'), 'learningContextTags', 'learningcontext');
  }
}

/**
 * Implements hook_preprocess_THEMEHOOK();
 */
function nexus_preprocess_sarnia_view_webinar(&$vars) {
  $properties = & $vars['properties'];

  // Redirect all previous CKEditor images to their new locations.
  ag_section_post_fix_oldprocomun_images($properties['descriptionStr']);

  // Remove from search any base64image that may be tough to render.
  ag_section_post_remove_base64_images_from_search($properties['descriptionStr']);

  // Truncate description to 500 characters preseving html tags.
  $properties['descriptionStr'] = DrupalToolKit::truncateHtml($properties['descriptionStr'], 500, array('ending' => '...', 'exact' => TRUE, 'html' => TRUE));

  // Set default user picture.
  if (empty($properties['webinarPicture']) && !empty($properties['preview']) && file_exists(drupal_realpath('.') . $properties['preview'])) {
    $properties['webinarPicture'] = theme('image', array(
      'path' => $properties['preview'],
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  if (empty($properties['webinarPicture'])) {
    $default_image = drupal_get_path('theme', 'nexus') . '/images/webinar_default.jpg';
    $properties['webinarPicture'] = theme('image', array(
      'path' => $default_image,
      'alt' => !empty($properties['titleStr']) ? $properties['titleStr'] : ''
    ));
  }

  if (isset($properties['idDrupal'])) {
    $properties['titleStr'] = empty($properties['titleStr']) ? : l($properties['titleStr'], 'node/' . $properties['idDrupal']);
    // Add Read more button.
    $properties['readmore'] = l(t('Read more'), 'node/' . $properties['idDrupal']);
  }
  else {
    $properties['titleStr'] = empty($properties['titleStr']) ? t('Untitled'): $properties['titleStr'];
  }

  if (isset($properties['labelsStr'])) {
    _build_tags($properties, 'labelsStr');
  }

  // Field knowledgeArea.
  if (isset($properties['knowledgeArea'])) {
    _build_tags_from_taxonomy($properties, 'knowledgeArea', array('type' => 'WEBINAR'), 'knowledgeAreaTags', 'knowledgearea');
  }

  // Field learningContext.
  if (isset($properties['learningContext'])) {
    _build_tags_from_taxonomy($properties, 'learningContext', array('type' => 'WEBINAR'), 'learningContextTags', 'learningcontext');
  }
}

/**
 * This function checks if a field_collections is visible or not
 * @param $item_id The item_id
 */
function _check_field_visibility($item_id) {
  $query = db_select('field_data_field_visibility', 'fdfv');
  $query->fields('fdfv', array('field_visibility_value'));
  $query->condition('fdfv.entity_id', $item_id);

  $result = $query->execute()->fetchField();

  return $result;
}

/**
 * @param $properties Information to show in user's list
 */
function _remove_private_data(&$properties) {
  $user_shown = user_load($properties['idDrupal']);
  $user_profile = profile2_load_by_user($user_shown, 'datos_personales');
  $visible = 1;
  if (isset($user_profile->field_place_fc['und'])) {
    $visible = isset($user_profile->field_place_fc['und'][0]['value']) ? _check_field_visibility($user_profile->field_place_fc['und'][0]['value']) : 0;
  }
  if ($visible == 0) {
    unset($properties['userPlaceStr']);
    $visible = 1;
  }
  $visible = isset($user_profile->field_name_surname['und'][0]['value']) ? _check_field_visibility($user_profile->field_name_surname['und'][0]['value']) : 0;
  if ($visible == 0) {
    unset($properties['userSurNameStr']);
    $visible = 1;
  }
  $visible = isset($user_profile->field_country_personal_fc['und'][0]['value']) ? _check_field_visibility($user_profile->field_country_personal_fc['und'][0]['value']) : 0;
  if ($visible == 0) {
    unset($properties['userCountryStr']);
    $visible = 1;
  }
  $visible = isset($user_profile->field_province_personal_fc['und'][0]['value']) ? _check_field_visibility($user_profile->field_province_personal_fc['und'][0]['value']) : 0;
  if ($visible == 0) {
    unset($properties['userProvinceStr']);
    $visible = 1;
  }
  $visible = isset($user_profile->field_edu_center_personal_fc['und'][0]['value']) ? _check_field_visibility($user_profile->field_edu_center_personal_fc['und'][0]['value']) : 0;
  if ($visible == 0) {
    unset($properties['userEducativeCenterStr']);
    $visible = 1;
  }
  $visible = isset($user_profile->field_locality_personal_fc['und'][0]['value']) ? _check_field_visibility($user_profile->field_locality_personal_fc['und'][0]['value']) : 0;
  if ($visible == 0) {
    unset($properties['userLocality']);
  }
}

/**
 * Splits tags coming from solr, to avoid commas between them.
 * @param $field field to get labels from.
 */
function _split_tags($field) {
  $labels_split = array();
  //Split every entry from solr. Some of them have commas.
  foreach ($field as $key => $value) {
    $labels_split = array_merge($labels_split, explode(',', $value));
  }
  return $labels_split;
}
