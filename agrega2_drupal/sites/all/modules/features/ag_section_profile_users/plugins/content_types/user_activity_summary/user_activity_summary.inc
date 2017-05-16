<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('User activity summary'),
  'description' => t('Render the user summary activity with numbre of publish content, flags, etc..'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('Agrega2'),
  'render callback' => 'user_activity_summary_content_type_render',
);


/**
 * Render callback.
 */
function user_activity_summary_content_type_render($subtype, $conf, $args, $context) {
  // Data is required
  if (empty($context->data)) {
    return FALSE;
  }
  $user = $context->data;
  $block = new stdClass();
  $file = file_load($user->picture);
  $picture_path = isset($file->uri) ? $file->uri :
    variable_get('user_picture_default', '');

  if (isset($user->uid)) {
    $user->name = ag_section_profile_users_get_name_surname_cached($user->uid);
  }

  $vars = array(
    'user_data' => array(
      'uid' => $user->uid,
      'name' => $user->name,
      'picture' => array(
        '#theme' => 'image_style',
        '#style_name' => '32x32',
        '#path' => $picture_path,
      ),
    ),
  );

  // Add total following users:
  $users_following = flag_get_user_flags('user', NULL, $user->uid);
  $follow_user_count = 0;
  if (isset($users_following['follow_user'])) {
    $follow_user_count = count($users_following['follow_user']);
  }

  $vars['boxes'][] = array(
    'count' => l($follow_user_count, 'user/' . $user->uid . '/followings'),
    'label' => l(t('Following'), 'user/' . $user->uid . '/followings'),
  );

  // Add total followers:
  $followers = flag_get_counts('user', $user->uid);
  $vars['boxes'][] = array(
    'count' => l(isset($followers['follow_user']) ? $followers['follow_user'] : 0, 'user/' . $user->uid . '/followers'),
    'label' => l(t('Followers'), 'user/' . $user->uid . '/followers'),
  );

  // Add total highlighted content:
  $content_highlighted = flag_get_user_flags('node', NULL, $user->uid);
  $content_highlighted_count = 0;
  if (isset($content_highlighted['favorite'])) {
    $content_highlighted_count = count($content_highlighted['favorite']);
  }
  $vars['boxes'][] = array(
    'count' => l($content_highlighted_count, 'user/' . $user->uid . '/favourites'),
    'label' => l(t('Favorited resources'), 'user/' . $user->uid . '/favourites'),
  );

  // Add total resources published
  $bundles = array('recurso_de_aprendizaje', 'ode', 'post');
  $query = ['query' => ['f[0]' => 'author:' . $user->uid]];
  $vars['boxes'][] = array(
    'count' => l(DrupalToolKit::getPublishedContent($user->uid, $bundles, 'node')->count()->execute(), 'user/' . $user->uid . '/timeline', $query),
    'label' => l(t('Published content'), 'user/' . $user->uid . '/timeline', $query),
  );

  //Set block content
  $block->content = array(
    '#theme' => 'user_activity_summary',
    '#vars' => $vars,
  );

  return $block;
}
