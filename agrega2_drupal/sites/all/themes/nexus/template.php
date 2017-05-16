<?php
/**
 * Implements hook_html_head_alter().
 * This will overwrite the default meta character type tag with HTML5 version.
 */
function nexus_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

/**
 * Implements hook_css_alter().
 */
function nexus_css_alter(&$css) {
  $data = array();

  if (!$cache = cache_get('nexus::excludes:css')) {
    // Get the nexus css to exclude and set in cache:
    $css_skip = (array) theme_get_setting('css_exclude', 'nexus');
    foreach ($css_skip as $value) {
      $data[$value] = $value;
    }
    cache_set('nexus::excludes:css', $data, 'cache', CACHE_TEMPORARY);
  }
  else {
    $data = $cache->data;
  }

  // Unset our skipped CSS:
  $css = array_diff_key($css, $data);
}

/**
 * Insert themed breadcrumb page navigation at top of the node content.
 */
function nexus_breadcrumb($vars) {
  $breadcrumb = $vars['breadcrumb'];
  if (!empty($breadcrumb)) {
    // Use CSS to hide titile .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    // comment below line to hide current page to breadcrumb
    $breadcrumb[] = drupal_get_title();
    $output .= '<nav class="breadcrumb">' . implode('<span class="breadcrumb_next"> » </span>', $breadcrumb) . '</nav>';
    return $output;
  }
}

/**
 * Implements template_preprocess_html().
 */
function nexus_preprocess_html(&$vars) {

  if (isset($vars['node'])) {
    // For full nodes.
    $vars['classes_array'][] = ($vars['node']) ? 'full-node' : '';
    // For forums.
    $vars['classes_array'][] = (($vars['node']->type == 'forum') || (arg(0) == 'forum')) ? 'forum' : '';
  }
  else {
    // Forums.
    $vars['classes_array'][] = (arg(0) == 'forum') ? 'forum' : '';
  }
  if (module_exists('panels') && function_exists('panels_get_current_page_display')) {
    $vars['classes_array'][] = (panels_get_current_page_display()) ? 'panels' : '';
  }

  // Since menu is rendered in preprocess_page we need to detect it here to add body classes
  $has_main_menu = theme_get_setting('toggle_main_menu');
  $has_secondary_menu = theme_get_setting('toggle_secondary_menu');

  /* Add extra classes to body for more flexible theming */

  if ($has_main_menu or $has_secondary_menu) {
    $vars['classes_array'][] = 'with-navigation';
  }

  if ($has_secondary_menu) {
    $vars['classes_array'][] = 'with-subnav';
  }

  if (!empty($vars['page']['featured'])) {
    $vars['classes_array'][] = 'featured';
  }

  if ($vars['is_admin']) {
    $vars['classes_array'][] = 'admin';
  }

  if (!empty($vars['page']['sidebar_first'])) {
    $vars['classes_array'][] = 'sidebar-left';
  }

  if (!empty($vars['page']['sidebar_second'])) {
    $vars['classes_array'][] = 'sidebar-right';
  }

  if (!empty($vars['page']['header_top'])) {
    $vars['classes_array'][] = 'header_top';
  }

  if ($vars['is_admin']) {
    $vars['classes_array'][] = 'admin';
  }

  if (!$vars['is_front']) {
    // Add unique classes for each page and website section
    $path = drupal_get_path_alias($_GET['q']);
    $temp = explode('/', $path, 2);
    $section = array_shift($temp);
    $page_name = array_shift($temp);

    // add template suggestions
    $vars['theme_hook_suggestions'][] = "page__section__" . $section;
    $vars['theme_hook_suggestions'][] = "page__" . $page_name;

    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        if ($section == 'node') {
          array_pop($vars['classes_array']); // Remove 'section-node'
        }
        $vars['classes_array'][] = 'section-node-add'; // Add 'section-node-add'
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        if ($section == 'node') {
          array_pop($vars['classes_array']); // Remove 'section-node'
        }
        $vars['classes_array'][] = 'section-node-' . arg(2); // Add 'section-node-edit' or 'section-node-delete'
      }
    }
  }

  if (arg(0) == 'user' || arg(0) == 'users') {
    array_push($vars['classes_array'], 'page-user-view');
  }

  drupal_add_library('system', 'ui.tooltip');
}


/**
 * Override or insert variables into the page template.
 */
function nexus_preprocess_page(&$vars) {
  if (isset($vars['node_title'])) {
    $vars['title'] = $vars['node_title'];
  }
  $vars['title_attributes_array']['class'][] = 'page-title';
  if (isset($vars['node']->type)) {
    if ($vars['node']->type == 'question' || $vars['node']->type == 'answer' || $vars['node']->type == 'debate') {
      $vars['title_attributes_array']['class'][] = 'hide';
    }
  }
  if (isset($vars['main_menu'])) {
    $vars['main_menu'] = theme('links__system_main_menu', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('links', 'main-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['main_menu'] = FALSE;
  }
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_menu'] = theme('links__system_secondary_menu', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('links', 'secondary-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['secondary_menu'] = FALSE;
  }
  // Adding classes wether #navigation is here or not
  if (!empty($vars['main_menu']) or !empty($vars['sub_menu'])) {
    $vars['classes_array'][] = 'with-navigation';
  }
  if (!empty($vars['secondary_menu'])) {
    $vars['classes_array'][] = 'with-subnav';
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($vars['title_suffix']['add_or_remove_shortcut']) && $vars['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $vars['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $vars['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $vars['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

  if (!theme_get_setting('nexus_feed_icons')) {
    $vars['feed_icons'] = '';
  }
  if (isset($vars['node'])) {
    // If the node type is "blog" the template suggestion will be "page--blog.tpl.php".
    $vars['theme_hook_suggestions'][] = 'page__' . str_replace('_', '--', $vars['node']->type);
  }

  // Add first/last classes to node listings about to be rendered.
  if (isset($vars['page']['content']['system_main']['nodes'])) {
    // All nids about to be loaded (without the #sorted attribute).
    $nids = element_children($vars['page']['content']['system_main']['nodes']);
    // Only add first/last classes if there is more than 1 node being rendered.
    if (count($nids) > 1) {
      $first_nid = reset($nids);
      $last_nid = end($nids);
      $first_node = $vars['page']['content']['system_main']['nodes'][$first_nid]['#node'];
      $first_node->classes_array = array('first');
      $last_node = $vars['page']['content']['system_main']['nodes'][$last_nid]['#node'];
      $last_node->classes_array = array('last');
    }
  }

  // When we are viewing an org we need to redirect to the profile because we need to hide the account.
  if (arg(0) == 'user' && is_numeric(arg(1)) && !arg(2)) {
    if (isset($vars['page']['content']['system_main']['#account']->uid)) {
      $org_role = array_search('organization', $vars['page']['content']['system_main']['#account']->roles);
      if ($org_role != FALSE) {
        $vars['tabs']['#primary'][1]['#link']['href'] = 'user/' . $vars['page']['content']['system_main']['#account']->uid . '/edit/datos_organizacion';
      }
    }
  }

  // Hide the account edit tab for an org.
  if (arg(0) == 'user' && is_numeric(arg(1)) && arg(2) == 'edit') {
    if (isset($vars['page']['content']['system_main']['#user']->uid)) {
      $org_role = array_search('organization', $vars['page']['content']['system_main']['#user']->roles);
      if ($org_role != FALSE) {
        $vars['tabs']['#primary'][1]['#link']['href'] = 'user/' . $vars['page']['content']['system_main']['#user']->uid . '/edit/datos_organizacion';
        if (isset($vars['tabs']['#secondary'][0])) {
          unset($vars['tabs']['#secondary'][0]);
        }
      }
    }
  }

  // Add links to create content
  $query = explode('/', $_GET['q']);
  $link = '';
  $rss_link = '';
  if (in_array('ode-search', $query)) {
    switch ($_GET['type']) {
      case 'COMMUNITY':
        $link = l(t('Request a new community'), 'node/add/social-network', array(
          'attributes' => array(
            'id' => 'request-new-community',
            'title' => t('Request a new community'),
          ),
        ));
        break;
      case 'LEARNING_RESOURCE':
        $link = l(t('Create learning resource'), 'ode/add', array(
          'attributes' => array(
            'id' => 'create-learning-resource',
            'title' => t('Create learning resource'),
          ),
        ));
        break;
      case 'POST':
        $link = l(t('Create post'), 'node/add/post', array(
          'attributes' => array(
            'id' => 'create-post',
            'title' => t('Create post'),
          ),
          'query' => array('destination' => 'user/' . $vars['user']->uid . '/timeline'),
        ));
        break;
      case 'QUESTION':
        $link = l(t('Create question'), 'node/add/question', array(
          'attributes' => array(
            'id' => 'create-question',
            'title' => t('Create question'),
          ),
          'query' => array('destination' => 'user/' . $vars['user']->uid . '/timeline'),
        ));
        break;
      case 'LEARNING_PATH':
        $link = l(t('Create learning path'), 'node/add/itinerary', array(
          'attributes' => array(
            'id' => 'create-learning-path',
            'title' => t('Create learning path'),
          ),
          'query' => array('destination' => 'user/' . $vars['user']->uid . '/learning-paths'),
        ));
        break;
      case 'PODCAST':
        $link = l(t('Create podcast'), 'node/add/podcast', array(
          'attributes' => array(
            'id' => 'create-podcast',
            'title' => t('Create podcast'),
          ),
          'query' => array('destination' => 'user/' . $vars['user']->uid . '/timeline'),
        ));

        $rss_link = l(t('Subscribe to RSS'), 'latest-podcasts', array(
          'attributes' => array(
            'id' => 'latest-podcasts',
            'title' => t('Subscribe to RSS'),
            'target' => '_blank',
          ),
        ));
        break;
      case 'WEBINAR':
        // Create webinar button only appear if the user is community
        // administrator member.
        $is_administrator = OgDrupalToolKit::userHasRole($vars['user']->uid, 'administrator member');
        if ($is_administrator) {
          $link = l(t('Create webinar'), 'node/add/webinar', array(
            'attributes' => array(
              'id' => 'create-webinar',
              'title' => t('Create webinar'),
            ),
            'query' => array('destination' => 'user/' . $vars['user']->uid . '/timeline'),
          ));
        }
        break;
    }
  }

  // Delete tabs in my communities section.
  if (in_array('my-communities', $query)) {
    $vars['tabs']['#primary'] = '';
  }

  // RSS link button variable.
  if (!empty($link) && $vars['logged_in']) {
    $vars['rss_link'] = '<span class="rss-link">' . $rss_link . '</span>';
  }

  // Create content link button variable.
  if (!empty($link) && $vars['logged_in']) {
    $vars['create_link'] = '<span class="create-link">' . $link . '</span>';
  }

  // Hide Help section tabs. Tabs are inside panel.
  if (!empty($vars['theme_hook_suggestions'][0]) && $vars['theme_hook_suggestions'][0] == 'page__help') {
    unset($vars['tabs']);
    drupal_add_js(drupal_get_path('module', 'ag_section_help') . '/js/help_section.js');
  }

  // Add share link to info_bar region
  if (isset($vars['share_link'])) {
    $share_link['#markup'] = $vars['share_link'];
    $share_link['#weight'] = 0;
    array_unshift($vars['page']['info_bar'], $share_link);
  }

  // Set the correct title for each notification and message tab
  if (!empty($vars['theme_hook_suggestions']) && in_array('page__messages', $vars['theme_hook_suggestions'])) {
    global $user;

    drupal_set_title('');
    if (isset($query[1])) {
      switch ($query[1]) {
        case 'notifications':
          //Get notifications number
          $notifications_number = ag_section_notifications_get_number_unread();
          $vars['tab_title'] = t('Notifications') . ' (' . $notifications_number . ' ' . t('new entries') . ')';
          break;

        case 'blocked':
          $vars['tab_title'] = t('Blocked users');
          break;
      }
    }
    else if ($query[0] == 'messages') {
      //Get messages number. Privatemsg already has a method to get unread messages number.
      $messages_number = module_exists('privatemsg') ? privatemsg_unread_count($user) : 0;
      $vars['tab_title'] = t('Messages') . ' (' . $messages_number . ' ' . t('new') . ')';
    }
  }

  // Create View button in user profile
  $vars['profile_view_button'] = '';
  $vars['profile_view_class'] = '';
  $user_id = arg(1);

  if (isset($vars['tabs']['#primary'][0]['#link']['path']) && $vars['tabs']['#primary'][0]['#link']['path'] == 'user/%/view') {
    $vars['profile_view_button'] = l(t('View'), 'user/' . $user_id, array(
      'attributes' => array(
        'title' => t('View profile'),
      ),
    ));
    $vars['profile_view_class'] = 'view-profile-button';
    $vars['tabs']['#primary'] = $vars['tabs']['#secondary'];
    $vars['tabs']['#secondary'] = '';
  }

  if (isset($vars['tabs']['#primary'][1]['#link']['path']) && $vars['tabs']['#primary'][1]['#link']['path'] == 'user/%/edit') {
    $vars['tabs']['#primary'] = '';
  }
}

function nexus_preprocess_block(&$vars) {
  $block = & $vars['block'];

  $vars['title_attributes_array']['class'][] = 'block__title';

  $title_attributes = $vars['title_attributes_array'] ? drupal_attributes($vars['title_attributes_array']) : '';

  if ($block->subject && ($block->region == "sidebar_first" || $block->region == "sidebar_second" || $block->region == 'left')) {
    $block->subject = '<h3' . $title_attributes . '>' . $block->subject . '</h3>';
  }
  elseif ($block->subject != '') {
    $block->subject = '<h2' . $title_attributes . '>' . $block->subject . '</h2>';
  }
}

/**
 * Duplicate of theme_menu_local_tasks() but adds clearfix to tabs.
 */
function nexus_menu_local_tasks(&$vars) {
  $output = '';
  if (!empty($vars['primary'])) {
    $vars['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $vars['primary']['#prefix'] .= '<ul class="tabs primary clearfix">';
    $vars['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($vars['primary']);
  }
  if (!empty($vars['secondary'])) {
    $vars['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    if (arg(0) == 'user') {
      $vars['secondary'][0]['#link']['title'] = t('My account');
      $vars['secondary']['#prefix'] .= '<ul class="nav nav-tabs">';
    }
    else {
      $vars['secondary']['#prefix'] .= '<ul class="tabs secondary clearfix">';
    }
    $vars['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($vars['secondary']);
  }
  return $output;
}

/**
 * Override theme_menu_local_task() for add classes to tabs <li>.
 */
function nexus_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  // Add classes to tabs li
  $tab_class = '';
  if (isset($link['path']) && !empty($link['path'])) {
    switch($link['path']) {
      case 'messages/notifications':
        $tab_class = 'notifications';
        break;
      case 'messages/list':
        $tab_class = 'messages-list';
        break;
      case 'messages/view/%':
        $tab_class = 'messages-view';
        break;
      case 'messages/blocked':
        $tab_class = 'messages-blocked';
        break;
      case 'user/%/my-communities/subscribed':
        $tab_class = 'my-communities-subscribed';
        break;
      case 'user/%/my-communities/pending':
        $tab_class = 'my-communities-pending';
        break;
      case 'user/%/edit/account':
        $tab_class = 'micuenta';
        break;
      case 'user/%/edit/datos_personales':
        $tab_class = 'admin-users';
        break;
      case 'user/%/edit/simplenews':
        $tab_class = 'boletin';
        break;
      case 'user/%/edit/cv':
        $tab_class = 'user-cv-tab';
        break;
      case 'user/register':
        $tab_class = 'my-communities-pending';
        break;
      case 'user/login':
        $tab_class = 'micuenta';
        break;
      case 'user/password':
        $tab_class = 'messages-list';
        break;
    }
  }

  return '<li' . (!empty($variables['element']['#active']) ? ' class="active' . (!empty($tab_class) ? ' ' . $tab_class : '') . '"' : (!empty($tab_class) ? ' class="' . $tab_class . '"': '')) . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}

/**
 * Override or insert variables into the node template.
 */
function nexus_preprocess_node(&$vars) {
  global $user;

  //Remove the og_share links if the node is the Help and FAQs community
  $is_faq_path = drupal_match_path(current_path(), 'node/' . FAQS);
  if ($is_faq_path) {
    unset($vars['content']['og_share']);
  }

  if ($vars['view_mode'] == 'full' && node_is_page($vars['node'])) {
    $vars['classes_array'][] = 'node-full';
  }

  if (!in_array('node-' . $vars['view_mode'], $vars['classes_array'])) {
    $vars['classes_array'][] = 'node-' . $vars['view_mode'];
  }

  $vars['date'] = t('!datetime', array('!datetime' => date('j F Y', strtotime($vars['created']))));

  // Proporcionamos template suggestions para los nodos por view mode.
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__' . $vars['view_mode'];

  _generate_newsletter_miniatures($vars);

  if (($vars['type'] == 'ode' || $vars['type'] == 'post' ||
       $vars['type'] == 'itinerary' || $vars['type'] == 'podcast' ||
       $vars['type'] == 'webinar') && $vars['view_mode'] == 'teaser') {
    if (isset($vars['content']['og_share']['#prefix'])) {
      $vars['content']['og_share']['#prefix'] = '<div class="share-local-networks">';
    }
    $vars['timeline_comments'] = views_embed_view('ag_teaser_comments', 'panel_pane_1', $vars['nid']);
  }

  if ($vars['type'] == 'ode' && $vars['view_mode'] == 'activities' ) {
    $vars['content']['links']['comment']['#links']['comment-add']['title'] = t('Make a comment');
  }

  // Add service links only for teaser
  if (($vars['type'] == 'ode' || $vars['type'] == 'post' ||
       $vars['type'] == 'event' || $vars['type'] == 'podcast' ||
       $vars['type'] == 'webinar') && $vars['view_mode'] == 'teaser') {
    $links = module_exists('service_links') ? service_links_render(NULL): '';
    $vars['rrss_teaser'] = theme('rrss_dropdown_widget', array('rrss_links_teaser' => $links));
  }

  if ($vars['type'] == 'answer' && $vars['view_mode'] == 'teaser' && isset($vars['field_question_ref'][0]['entity'])) {
    $vars['title_question_ref'] = '<h2>' . l($vars['field_question_ref'][0]['entity']->title, 'node/' . $vars['field_question_ref'][0]['entity']->nid, array(
      'fragment' => 'node-' . $vars['nid'],
    )) . '</h2>';
  }

  if((isset($vars['type']) && $vars['type'] == 'itinerary') && ($vars['view_mode'] == 'full' && $vars['logged_in'])) {
    // Check if user have access to edit current itinerary.
    if (user_access('edit any itinerary content') || (user_access('edit own itinerary content') && $vars['uid'] == $user->uid)) {
      $vars['edit_link'] = l(t('Edit'), 'node/' . $vars['nid'] . '/edit', array(
        'query' => array(
          'destination' => 'node/' . $vars['node']->nid,
        ),
        'attributes' => array(
          'id' => 'edit-itinerary',
          'title' => t('Edit'),
        ),
      ));
    }

    // Add clone learning path button.
    $og_group_ref = array();
    foreach ($vars['og_group_ref'] as $group) {
      $og_group_ref[] = $group['target_id'];
    }
    $og_group_ref = implode(', ', $og_group_ref);
    $vars['clone_link'] = l(t('Clone'), 'node/add/itinerary', array(
      'query' => array(
        'field_base_itinerary' => $vars['node']->nid,
        'og_group_ref' => $og_group_ref,
        'destination' => 'user/' . $vars['user']->uid . '/learning-paths'
      ),
      'attributes' => array(
        'id' => 'clone-learning-path',
        'title' => t('Clone learning path'),
      ),
    ));
  }
}

function _generate_newsletter_miniatures(&$vars) {
  $newsletter_types = array('post', 'question', 'debate', 'event', 'poll', 'ode');
  $preview_width = '100px';
  $preview_height = '100px';
  if (in_array($vars['type'], $newsletter_types) && $vars['view_mode'] == 'newsletter') {
    switch($vars['type']) {
      case 'post':
        $default_image = !empty($vars['field_imagen_miniatura']) ? $vars['field_imagen_miniatura'][LANGUAGE_NONE][0]['uri'] : drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
        $vars['miniatura_newsletter'] = theme('image', array(
          'path' => $default_image,
          'alt' => !empty($vars['title']) ? $vars['title'] : '',
          'title' => !empty($vars['title']) ? $vars['title'] : '',
          'width' => $preview_width,
          'height' => $preview_height
        ));
        break;
      case 'debate':
        $default_image = drupal_get_path('theme', 'nexus') . '/images/debates_default_02.jpg';
        $vars['miniatura_newsletter'] = theme('image', array(
          'path' => $default_image,
          'alt' => !empty($vars['title']) ? $vars['title'] : '',
          'title' => !empty($vars['title']) ? $vars['title'] : '',
          'width' => $preview_width,
          'height' => $preview_height
        ));
        break;
      case 'poll':
        $default_image = drupal_get_path('theme', 'nexus') . '/images/encuestas_default.jpg';
        $vars['miniatura_newsletter'] = theme('image', array(
          'path' => $default_image,
          'alt' => !empty($vars['title']) ? $vars['title'] : '',
          'title' => !empty($vars['title']) ? $vars['title'] : '',
          'width' => $preview_width,
          'height' => $preview_height
        ));
        break;
      case 'event':
        $default_image = drupal_get_path('theme', 'nexus') . '/images/eventos_default.jpg';
        $vars['miniatura_newsletter'] = theme('image', array(
          'path' => $default_image,
          'alt' => !empty($vars['title']) ? $vars['title'] : '',
          'title' => !empty($vars['title']) ? $vars['title'] : '',
          'width' => $preview_width,
          'height' => $preview_height
        ));
        break;
      case 'question':
        $default_image = drupal_get_path('theme', 'nexus') . '/images/preguntas_default.jpg';
        $vars['miniatura_newsletter'] = theme('image', array(
          'path' => $default_image,
          'alt' => !empty($vars['title']) ? $vars['title'] : '',
          'title' => !empty($vars['title']) ? $vars['title'] : '',
          'width' => $preview_width,
          'height' => $preview_height
        ));
        break;
      case 'ode':
        $ode = ag_visualization_ode_get_solr_ode($vars['field_solrid'][LANGUAGE_NONE][0]['value']);
        if (isset($ode['preview'])) {
          if (strpos($ode['preview'], 'sites/default/files')) {
            $vars['miniatura_newsletter'] = theme('image', array(
              'path' => $ode['preview'],
              'alt' => !empty($vars['title']) ? $vars['title'] : '',
              'title' => !empty($vars['title']) ? $vars['title'] : '',
              'width' => $preview_width,
              'height' => $preview_height
            ));
          }
          else {
            $vars['miniatura_newsletter'] = '<img src="http://' . $ode['preview'] .
              '" alt="' . (!empty($vars['title']) ? $vars['title'] : '') .
              '" title="' . (!empty($vars['title']) ? $vars['title'] : '') .
              '" width="' . $preview_width .
              '" height="' . $preview_height . '">';
          }
        }
        else {
          $default_image = drupal_get_path('theme', 'nexus') . '/images/recursos_default.jpg';
          $vars['miniatura_newsletter'] = theme('image', array(
            'path' => $default_image,
            'alt' => !empty($vars['title']) ? $vars['title'] : '',
            'title' => !empty($vars['title']) ? $vars['title'] : '',
            'width' => $preview_width,
            'height' => $preview_height
          ));
        }
        break;
    }
  }
}

function nexus_menu_tree(&$variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}

function nexus_page_alter($page) {
  // <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1"/>
  $viewport = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, user-scalable=yes'
    )
  );
  drupal_add_html_head($viewport, 'viewport');
}

/**
 * @docme
 */
function nexus_preprocess_user_profile(&$vars) {
  global $user;
  $account = user_load($vars['elements']['#account']->uid);

  // Flag public view mode.
  $public_view = FALSE;
  if ($vars['elements']['#view_mode'] == 'public') {
    $public_view = TRUE;
  }

  $vars['tabs'] = '<ul class="nav nav-tabs">';
  // Hide account when the user is an organization.
  if ($public_view == FALSE && (array_search('organization', $vars['elements']['#account']->roles) == FALSE)) {
    $vars['tabs'] .= '<li class="micuenta profile-tab-mi-cuenta active"><a role="tab" data-toggle="tab" href="#profile-mi-cuenta">' . t('My account') . '</a></li>';
  }
  $types = profile2_get_types();

  // Only the public view is displayed when the user is not an organization,
  // and we are not visiting the public profile.
  if ($public_view == FALSE && (array_search('organization', $vars['elements']['#account']->roles) == FALSE)) {
    $vars['mi_cuenta'] = theme('ag_section_profile_users_mi_cuenta', array('profile' => $account));
  }
  else {
    // TPL for public profile view.
    $vars['theme_hook_suggestions'][] = 'user_profile__public';
    $image_path = isset($account->picture->uri) ? $account->picture->uri : NULL;
    if (!isset($image_path)) {$image_path = variable_get('user_picture_default', '');}
    // Change the user's picture with this render array.
    $user_picture_public = array(
      '#theme' => 'image_style',
      '#path' => $image_path,
      '#style_name' => 'ag_scalecrop_150x150',
      '#attributes' => array(
        'alt' => t('@user_name\'s image', array('@user_name' => $account->name)),
        'title' => t('@user_name', array('@user_name' => $account->name)),
        'class' => array('user-public-picture'),
      )
    );

    if (isset($vars['user_profile']['profile_datos_personales']['view']['profile2'])) {
      $keys = array_keys($vars['user_profile']['profile_datos_personales']['view']['profile2']);
      $profile_key = $keys[0];
      if ($user->uid && !in_array('organization', $account->roles) && !empty($vars['user_profile']['most_used_tags'])) {
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['most_used_tags']['#prefix'] = '<div class="most-used-tags"><div class="field-label">' . t('@used_labels:', array('@used_labels' => t('Most used labels'))) . '</div>';
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['most_used_tags']['#suffix'] = '</div>';
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['most_used_tags']['#markup'] = drupal_render($vars['user_profile']['most_used_tags']);
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['most_used_tags']['#weight'] = 10;
      }

      if (!empty($vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc'])) {
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc']['#prefix'] = '<div class="social-network-links"><span class="social-follow-me">' . t('Follow me:') . '</span>';
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc']['#suffix'] = '</div>';
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc']['#weight'] = 11;
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc']['#access'] = FALSE;
      }
    }

    $user_picture_public['#weight'] = 9;

    // Add these elements to 'datos_personales' profile
    $rendered_user = drupal_render($user_picture_public);
    if ($public_view) {
      $vars['user_profile']['user_picture'] = array(
        '#markup' => $rendered_user,
        '#weight' => -10,
      );
    }
    $vars['user_profile']['profile_datos_personales'][] = $vars['user_profile']['user_picture'];
    if ($user->uid && !in_array('organization', $account->roles)){
      // Only for registered users.
      if (isset($vars['user_profile']['most_used_tags'])) {
        $vars['user_profile']['profile_datos_personales'][] = $vars['user_profile']['most_used_tags'];
      }
    }
    if (isset($vars['user_profile']['profile_datos_personales']['view']['profile2']) &&
        isset($vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc'])) {
      $vars['user_profile']['profile_datos_personales'][] = $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc'];
      unset(
        $vars['user_profile']['profile_datos_personales']['view']['profile2'][$profile_key]['field_social_network_personal_fc']
      );
    }
    unset(
      $vars['user_profile']['user_picture'],
      $vars['user_profile']['most_used_tags']
    );
  }

  if ($user->uid && !empty($types)) {
    // Try sorting by weights in 'admin/structure/profiles'.
    // Indicating in my cv a weight of 10 and a weight of 0 to My personal data.
    // Yet these changes still showed me in first place My CV.
    arsort($types);
    // Flag for the first element of the tabs.
    $first = TRUE;
    foreach ($types as $type) {
      $profile = profile2_load_by_user($vars['elements']['#account']->uid, $type->type);

      // Label for the tab.
      $tab_label = isset($profile->label) ? $type->getTranslation('label', 'en') : '';
      if ($public_view == 1 && !empty($profile->type) && $profile->type != 'datos_organizacion') {
        // Remove the first word i.e. 'My CV' will be set as 'CV'
        $tab_label = strstr($tab_label, " ");
      }
      if (!empty($profile->type) && $profile->type == 'datos_personales') {
        $id_entity_name = $profile->field_name_surname['und'][0]['value'];
        $profile_datos_personales = entity_load('field_collection_item', array($id_entity_name));
        $vars['profile_datos_personales'] = $profile_datos_personales;
      }

      $tab_privacy = check_profile_privcacy($profile);
      if (!empty($profile) && $tab_privacy) {
        $active_class = array();
        // 'datos_organizacion' profile will be active when viewing the user profile.
        if (($first && $public_view) || $profile->type == 'datos_organizacion') {
          // Set the active class.
          $active_class[] = 'active';
          $first = FALSE;
        }

        $vars['tabs'] .= "<li class=\"admin-users profile-tab-$profile->type " . implode(' ', $active_class) . "\">";
        $vars['tabs'] .= '<a role="tab" data-toggle="tab" href="#profile-' .
          str_replace("_", "-", $profile->type) . '">' . t($tab_label) . '</a>';
        $vars['tabs'] .= '</li>';
      }
    }
    // My organization tab. Show this tab for non organization user profiles.
    // Search for organization role to detect it.
    $org_role = array_search('organization', $vars['elements']['#account']->roles);
    if ($org_role == FALSE) {
      if (isset($account->field_organization_reference['und'][0]['target_id'])) {
        $organization_label = ($public_view == TRUE) ? t('Organization') : t('My organization');
        $vars['tabs'] .= "<li class=\"profile-tab-my-organization " . implode(' ', $active_class) . "\">";
        $vars['tabs'] .= '<a role="tab" data-toggle="tab" href="#profile-my-organization">' . $organization_label . '</a>';
        $vars['tabs'] .= '</li>';
      }
    }
  }
  $vars['tabs'] .= '</ul>';

  // Create Edit button in user profile
  $user_id = arg(1);
  $vars['profile_edit_button'] = l(t('Edit'), 'user/' . $user_id . '/edit', array(
    'attributes' => array(
      'title' => t('Edit profile'),
      'id' => 'contact-us',
    ),
  ));
  $vars['profile_edit_class'] = 'edit-profile-button';
}

function nexus_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  if ($root_path == 'user/%' || $root_path == 'user/%/edit' ||
    $root_path == 'user/%/edit/datos_personales' || $root_path == 'user/%/edit/cv' ||
    $root_path == 'user/%/edit/simplenews' ||  $root_path == 'user/%/edit/datos_organizacion'
  ) {

    foreach ($data['tabs'][0]['output'] as $key => $value) {
      foreach ($value['#link'] as $k => $v) {
        if ($k == 'path' && $v != 'user/%/edit' && $root_path == 'user/%') {
          unset($data['tabs'][0]['output'][$key]);
        }
        else {
          if ($k == 'path' && $v != 'user/%/view' &&
            ($root_path != 'user/%')
          ) {
            unset($data['tabs'][0]['output'][$key]);
          }
        }
      }
    }
  }
}

/**
 * Format tags going to be used in sarnia-view-[SEARCHTYPE].tpl.php templates.
 * Output is 'keywords' by default, but can be selected as parameter.
 * If a facet field is already enabled by the user, it won't be repeated.
 *
 * @param array $properties
 *   Properties/vars send to the template
 * @param string $prop_key
 *   Property key name where are the tags to be processed.
 * @param array $options
 *   Aditionally you can change some default options:
 *     - type: Alters $query['type']. If no one is providad defaults to $properties['type']
 * @param string $output_key
 *   It allows chosing output key in array to save tag formatting.
 */
function _build_tags(&$properties, $prop_key, $options = array(), $output_key = 'keywords') {
  $properties[$output_key] = array();

  foreach (array_keys($properties[$prop_key]) as $elem) {
    $query = array();
    $query['query'] = isset($_GET['query']) ? $_GET['query'] : "";
    $query['type'] = isset($options['type']) ? $options['type'] : $properties['type'];
    $number_filter = 0;

    //Check if facet is already selected by the user.
    $exists = FALSE;
    while (isset($_GET['f'][$number_filter])) {
      $query['f[' . $number_filter . ']'] = $_GET['f'][$number_filter];

      //Checking facet already in use.
      $exists = $exists || ($query['f[' . $number_filter . ']'] == $prop_key . ':"' . $properties[$prop_key][$elem] . '"');
      $number_filter++;
    }

    //Add only if new facet enabled.
    if (!$exists) {
      $query['f[' . $number_filter . ']'] = $prop_key . ':"' . $properties[$prop_key][$elem] . '"';
    }

    if (!empty($properties[$prop_key][$elem])) {
      $properties[$output_key][] = l(t($properties[$prop_key][$elem]), 'ode-search', array('query' => $query));
    }
  }
}

/**
 * Same as build tags, but with taxonomy translation in case it is needed.
 * Format tags going to be used in sarnia-view-[SEARCHTYPE].tpl.php templates.
 * Output is 'keywords' by default, but can be selected as parameter.
 * If a facet field is already enabled by the user, it won't be repeated.
 *
 * @param array $properties
 *   Properties/vars send to the template
 * @param string $prop_key
 *   Property key name where are the tags to be processed.
 * @param array $options
 *   Aditionally you can change some default options:
 *     - type: Alters $query['type']. If no one is providad defaults to $properties['type']
 * @param string $output_key
 *   It allows chosing output key in array to save tag formatting.
 * @param string $vocabulary
 *   Must be specified to load taxonomy to be able to translate it.
 */
function _build_tags_from_taxonomy(&$properties, $prop_key, $options = array(), $output_key = 'keywords', $vocabulary = '') {
  $properties[$output_key] = array();

  foreach (array_keys($properties[$prop_key]) as $elem) {
    $query = array();
    $query['query'] = isset($_GET['query']) ? $_GET['query'] : "";
    $query['type'] = isset($options['type']) ? $options['type'] : $properties['type'];
    $number_filter = 0;

    //Check if facet is already selected by the user.
    $exists = FALSE;
    while (isset($_GET['f'][$number_filter])) {
      $query['f[' . $number_filter . ']'] = $_GET['f'][$number_filter];

      //Checking facet already in use.
      $exists = $exists || ($query['f[' . $number_filter . ']'] == $prop_key . ':"' . $properties[$prop_key][$elem] . '"');
      $number_filter++;
    }

    //Add only if new facet enabled.
    if (!$exists) {
      $query['f[' . $number_filter . ']'] = $prop_key . ':"' . $properties[$prop_key][$elem] . '"';
    }

    if (!empty($properties[$prop_key][$elem])) {
      $name = $properties[$prop_key][$elem];
      if (!empty($vocabulary)) {
        //Taxonomies in this web are always spanish as default language.
        $name = ag_visualization_ode_i18n_translate_term_cached($name, 'es', $vocabulary);
      }
      $properties[$output_key][] = l(t($name), 'ode-search', array('query' => $query));
    }
  }
}


/**
 * Overwrite theme_links of locale module to display a custom title
 * instead of original title.
 */
function nexus_links__locale_block(&$vars) {
  $content = '';
  foreach ($vars['links'] as $language => $langInfo) {
    $vars['links'][$language]['title'] = t('Welcome', array(), array('langcode' => $language));
    $vars['links'][$language]['query'] = drupal_get_query_parameters();
    $vars['links'][$language]['attributes'] += array('lang' => $language);
  }
  $content = '<span class="current-language">' . t('Welcome') . '</span>';

  // Unset current language from language selector
  $current_lang = ag_general_current_lang();
  unset($vars['links'][$current_lang->language]);

  $content .= theme_links($vars);
  return $content;
}

/**
 * Implements template_preprocess_views_view_field().
 */
function nexus_preprocess_views_view_field(&$vars) {
  if ($vars['view']->name == 'ag2_og_members_list' && $vars['field']->field == 'nothing') {
    $file = DrupalToolKit::getUserData($vars['row']->entity, array('picture'))->uri;
    if (!empty($file)) {
      $vars['output'] = theme('image_style', array('style_name' => 'profile_image', 'path' => $file));
    }
    else {
      $vars['output'] = theme('image_style', array('style_name' => 'profile_image', 'path' => variable_get('user_picture_default', '')));
    }
  }

  // Add field node status classes to control center content and community administration views
  if ((($vars['view']->name == 'agrega2_communities_administration' && $vars['view']->current_display == 'panel_pane_2') ||
       ($vars['view']->name == 'agrega2_content_administration' && $vars['view']->current_display == 'panel_pane_1')
      ) && $vars['field']->field == 'status') {
    $status_class = $vars['row']->node_status == '1' ? 'ico-true' : 'ico-false';
    $vars['output'] = '<p class="' . $status_class . '"></p>';
  }

  // Add field certified status classes to content certification view
  if ($vars['view']->name == 'agrega2_content_certification' && $vars['view']->current_display == 'panel_pane_certifications_list' && $vars['field']->field == 'field_certified') {
    $status_class = $vars['row']->field_field_certified[0]['raw']['value'] == '1' ? 'ico-true' : 'ico-false';
    $vars['output'] = '<p class="' . $status_class . '"></p>';
  }

  // Add field user status classes to control center users view
  if ($vars['view']->name == 'control_center_users' && $vars['view']->current_display == 'panel_pane_1' && $vars['field']->field == 'status') {
    $status_class = $vars['row']->users_status == '1' ? 'ico-true' : 'ico-false';
    $vars['output'] = '<p class="' . $status_class . '"></p>';
  }
}

/**
 * Implements template_preprocess_views_view().
 */
function nexus_preprocess_views_view(&$vars) {
  if (isset($vars['view']->name)) {
    $function = 'nexus_preprocess_views_view__'.$vars['view']->name;
    if (function_exists($function)) {
     $function($vars);
    }
  }

  // Alter view more link for home more recent list
  if ($vars['view']->name == 'ag_home_more_recent' && $vars['view']->current_display == 'panel_pane_home_more_recent') {
    $vars['more'] = '<span class="home-view-more">' . l(t('View more'), 'ode-search', array(
      'attributes' => array(
        'title' => t('View more'),
      ),
      'query' => array(
        'sort' => 'publicationDate-DESC',
        'type' => '',
      )
    )) . '</span>';
  }

  // Alter view more link for home new communities list
  if ($vars['view']->name == 'ag_home_new_communities' && $vars['view']->current_display == 'panel_pane_home_new_communities') {
    $vars['more'] = '<span class="home-view-more">' . l(t('View more'), 'ode-search', array(
        'attributes' => array(
          'title' => t('View more'),
        ),
        'query' => array(
          'sort' => 'communityDate-DESC',
          'type' => 'COMMUNITY',
        )
      )) . '</span>';
  }
}

/**
 * Implements hook_preprocess_views_pre_render().
 */
function nexus_views_pre_render(&$view) {
  // Add fivestar js and css to view when show view with load more pager
  if ($view->name == 'user_timeline' || $view->name == 'my_favourites' || $view->name == 'community_wall_faceted_search'  || $view->name == 'my_learning_paths') {
    drupal_add_js(drupal_get_path('module', 'fivestar') . '/js/fivestar.js');
    drupal_add_js(drupal_get_path('module', 'fivestar') . '/js/fivestar.ajax.js');
    drupal_add_css(drupal_get_path('module', 'fivestar') . '/css/fivestar.css');
  }
}

/**
 * Implements template_preprocess_views_view_table().
 */
function nexus_preprocess_views_view_table(&$vars) {
  global $user;

  $view = &$vars['view'];

  // Avoid an user who does not have the administrator role can order the views
  // located in the 'User manual' section.
  if ($view->name == 'manual_index' && $view->current_display == 'panel_pane_1') {
    if (!in_array('administrator', array_values($user->roles)) && current_path() == 'help/manual') {
      // Remove row class.
      unset($vars['row_classes']);
    }
  }

  // Add index number into the items.
  if ($view->name == 'manual_index' && $view->current_display == 'panel_pane_1') {
    // Change the title to enter the index number in the item.
    $title = "{$vars['id']}. {$vars['title']}";
    $vars['title'] = $title;

    // Add index number to related content. Get view rows to change the title
    // which was processed previously.
    $counter = 1;
    foreach (array_keys($vars['rows']) as $key) {
      if (!empty($vars['rows'][$key])) {
        $text = "{$vars['id']}.{$counter}. {$view->result[$key]->node_title}";
        $options = array(
          'attributes' => array(
            'data-nid' => $vars['view']->result[$key]->nid,
            'class' => 'link-index-manual',
          ),
        );
        $vars['rows'][$key]['title'] = l($text, 'javascript:', $options);
      }
      $counter++;
    }
  }
}

/**
 * Preprocess function to user_timeline view
 */
function nexus_preprocess_views_view__user_timeline(&$vars) {
  // Alter specific view.
  if($vars['display_id'] == 'panel_pane_1') {
    global $user;

    // Check if hide filters.
    $show_filters = ag_general_show_facet_filters();

    $vars['hide_filters'] = '';
    if (!$show_filters) {
      $vars['hide_filters'] = 'hidden';
    }
  }
}

/**
 * Preprocess function to my_favourites view
 */
function nexus_preprocess_views_view__my_favourites(&$vars) {
  // Alter specific view.
  if($vars['display_id'] == 'panel_pane_my_favourites') {

    // Check if hide filters.
    $show_filters = ag_general_show_facet_filters();

    $vars['hide_filters'] = '';
    if (!$show_filters) {
      $vars['hide_filters'] = 'hidden';
    }
  }
}

/**
 * Preprocess function to my_learning_paths view
 */
function nexus_preprocess_views_view__my_learning_paths(&$vars) {
  // Alter specific view.
  if($vars['display_id'] == 'panel_pane_my_learning_paths') {

    // Check if hide filters.
    $show_filters = ag_general_show_facet_filters();

    $vars['hide_filters'] = '';
    if (!$show_filters) {
      $vars['hide_filters'] = 'hidden';
    }
  }
}

/**
 * Preprocess function to ag2_og_polls_list
 */
function nexus_preprocess_views_view__ag2_og_polls_list(&$vars) {
  // Alter specific view.
  if($vars['display_id'] == 'panel_pane_1') {
    global $user;

    // Check if hide filters.
    $show_filters = ag_general_show_facet_filters();

    $vars['hide_filters'] = '';
    if (!$show_filters) {
      $vars['hide_filters'] = 'hidden';
    }
  }
}

/**
 * Preprocess function to agrega2_events
 */
function nexus_preprocess_views_view__agrega2_events(&$vars) {
  // Alter specific view.
  if($vars['display_id'] == 'panel_pane_1') {
    global $user;

    // Check if hide filters.
    $show_filters = ag_general_show_facet_filters();

    $vars['hide_filters'] = '';
    if (!$show_filters) {
      $vars['hide_filters'] = 'hidden';
    }
  }
}

/**
 * Preprocess function to agrega2_events
 */
function nexus_preprocess_views_view__ag2_og_members_list(&$vars) {
  // Alter specific view.
  if($vars['display_id'] == 'panel_pane_1') {
    global $user;

    // Check if hide filters.
    $show_filters = ag_general_show_facet_filters();

    $vars['hide_filters'] = '';
    if (!$show_filters) {
      $vars['hide_filters'] = 'hidden';
    }
  }
}

/**
 * Preprocess function to community_wall_faceted_search view
 */
function nexus_preprocess_views_view__community_wall_faceted_search(&$vars) {
  // Add custom js to hide/show communities in node teasers if there are more than three
  drupal_add_js([
    'ag_general' => [
      'parent_selector' => 'div.field-name-og-group-ref div.field-items',
      'child_selector' => 'div.field-item',
      'how_content_show' => 3
    ]
  ], 'setting');
  drupal_add_js(drupal_get_path('module', 'ag_general') . '/js/toggle-content.js');

  // Hide filters region if not filters applied
  if($vars['view']->current_display == 'panel_pane_1') {
    $vars['hide_filters'] = ag_section_social_netwok_show_facet_filters();
  }
}


// Separamos a un archivo independiente el preprocesado de los view de sarnia. Ocupan mucho.
require_once "template.preprocess.sarnia-view.php";

//We don't want sticky header tables in our theme as they don't work well with responsive
function nexus_js_alter(&$js) {
  unset($js['misc/tableheader.js']);
}

/**
 * Implements theme_link().
 */
function nexus_link($variables) {
  if (isset($variables['path'])) {
    return '<a href="' . check_plain(url($variables ['path'], $variables ['options'])) . '"' . drupal_attributes($variables ['options']['attributes']) . '>' . ($variables ['options']['html'] ? $variables ['text'] : check_plain($variables ['text'])) . '</a>';
  }
  else {
    return ($variables ['options']['html'] ? $variables ['text'] : check_plain($variables ['text']));
  }
}

/**
 * Implements template_preprocess_simplenews_newsletter_body().
 */
function nexus_preprocess_simplenews_newsletter_body(&$vars) {
  $body = $vars['build']['body'][0]['#markup'];

  // Convert body classes to inline styles
  $body = str_replace('class="rteindent1"', 'style="margin-left:40px;"', $body);
  $body = str_replace('class="rteindent2"', 'style="margin-left:80px;"', $body);
  $body = str_replace('class="rteindent3"', 'style="margin-left:120px;"', $body);
  $body = str_replace('class="rteindent4"', 'style="margin-left:160px;"', $body);
  $body = str_replace('class="rtecenter"', 'style="text-align:center;"', $body);
  $body = str_replace('class="rteright"', 'style="text-align:right;"', $body);
  $body = str_replace('class="rtejustify"', 'style="text-align:justify;"', $body);

  $vars['build']['body'][0]['#markup'] = $body;
  $vars['content_ref'] = $vars['build']['field_simplenews_content_ref'];

  unset($vars['build']['field_simplenews_content_ref']);
}

/**
 * Implements template_preprocess_views_view_accordion().
 */
function nexus_preprocess_views_view_accordion(&$vars) {
  // Add index number to items.
  if ($vars['view']->name == 'manual_content' && ($vars['view']->current_display == 'panel_pane_1' || $vars['view']->current_display == 'panel_pane_2')) {
    // First to taxonomy terms.
    $term_title = $vars['id'] . '. ' . $vars['title'];
    $vars['title'] = $term_title;

    // Add index number to related content. Take results from rows keys and change title into result view.
    $keys = array_keys($vars['rows']);
    $counter = 1;
    foreach ($keys as $key) {
      if (!empty($vars['rows'][$key])) {
        $index_token_replace = $vars['id'] . '.' . $counter . '. ';
        $token_data = array(
          'manual_index' => $index_token_replace,
        );
        $vars['rows'][$key] = token_replace($vars['rows'][$key], $token_data);
      }
      $counter++;
    }
  }

  // Preprocess variables for views accordion faq template
  if ($vars['view']->name == 'faq' && $vars['view']->current_display == 'panel_pane_faq_list') {
    $faq_results = array();
    global $user;

    foreach($vars['view']->result as $result) {
      // Access and load to reply form
      $form = '';
      $admin_members = array('1');
      if (user_access('create faq content') && in_array($user->uid, $admin_members)) {
        $node = node_load($result->nid);
        $form = drupal_get_form('ag_section_help_reply_form', $result->nid, $node->type);
      }

      $faq_results[] = array(
        'nid' => $result->nid,
        'title' => $result->node_title,
        'author' => l(ag_section_profile_users_get_name_surname_cached($result->node_uid),
          'profile/' . $result->node_uid . '/public', array(
            'absolute' => TRUE,
            'attributes' => array(
              'class' => 'username',
              'title' => t('View user profile'),
            ),
        )),
        'post_date' => format_date($result->node_created, 'custom', 'd-m-Y'),
        'num_comments' => $result->node_comment_statistics_comment_count,
        'body' => $result->field_body[0]['rendered']['#markup'],
        'answers' => views_embed_view('faq', 'panel_pane_faq_answers_list', $result->nid),
        'reply' => !empty($form) ? render($form) : '',
      );
    }

    $vars['faq_results'] = !empty($faq_results) ? $faq_results : '';
  }

  // Preprocess variables for views accordion template
  // Add data attribute with the nid
  if (($vars['view']->name == 'help_search' && $vars['view']->current_display == 'panel_pane_1') ||
      ($vars['view']->name == 'manual_content' && ($vars['view']->current_display == 'panel_pane_1' || $vars['view']->current_display == 'panel_pane_2')) ||
      ($vars['view']->name == 'faq' && $vars['view']->current_display == 'panel_pane_faq_list') ||
      ($vars['view']->name == 'new_functionalities' && $vars['view']->current_display == 'panel_pane_new_functionalities_list')) {
    foreach ($vars['classes_array'] as $key => $classes) {
      $vars['attributes_array'][$key] = 'data-nid="' . $vars['view']->result[$key]->nid . '"';
    }
  }
}

/**
 * Preprocess function to manual_content view
 */
function nexus_preprocess_views_view__manual_content(&$vars) {
  // Add extra generic class to view.
  $vars['classes_array'][] = 'view-accordion-generic';
}

/**
 * Preprocess function to new_functionalities view
 */
function nexus_preprocess_views_view__new_functionalities(&$vars) {
  // Add extra generic class to view.
  $vars['classes_array'][] = 'view-accordion-generic';
}

/**
 * Preprocess function to new_functionalities view
 */
function nexus_preprocess_views_view__faq(&$vars) {
  // Add extra generic class to view.
  $vars['classes_array'][] = 'view-accordion-generic';
}

/**
 * Preprocess function to help search view
 */
function nexus_preprocess_views_view__help_search(&$vars) {
  // Add extra generic class to view.
  $vars['classes_array'][] = 'view-accordion-generic';
}

/**
 * Preprocess function to rate_template_emotion
 */
function nexus_preprocess_rate_template_emotion(&$vars) {
  if (isset($vars['display_options']['description'])) {
    $vars['display_options']['description'] = t($vars['display_options']['description']);
  }
}

/**
 * Override Panels nexus_panels_default_style_render_region() callback.
 *
 * @ingroup themeable
 */
function nexus_panels_default_style_render_region($vars) {
  $output = '';
//  $output .= '<div class="region region-' . $vars['region_id'] . '">';
  $output .= implode('', $vars['panes']);
//  $output .= '</div>';
  return $output;
}

/**
 * Override Facetapi theme_facetapi_link_active()
 * Returns HTML for an active facet item.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 *
 * @ingroup themeable
 */
function nexus_facetapi_link_active($variables) {

  // Sanitizes the link text if necessary.
  $sanitize = empty($variables['options']['html']);
  $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

  // Theme function variables fro accessible markup.
  // @see http://drupal.org/node/1316580
  $accessible_vars = array(
    'text' => $variables['text'],
    'active' => TRUE,
  );

  // Builds link, passes through t() which gives us the ability to change the
  // position of the widget on a per-language basis.
  $replacements = array(
    '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
    '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
  );

  // Adds count to link if one was passed.
  if (isset($variables['count'])) {
    $variables['text'] = $variables['count'] . ',' . $variables['text'];
  }

  $variables['text'] .= t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
  $variables['options']['html'] = TRUE;
  return theme_link($variables) . $link_text;
}

/**
 * Preprocess function to panels_pane template
 */
function nexus_preprocess_panels_pane(&$vars) {
  // Add community title to community wall template
  if ($vars['pane']->subtype == 'community_wall_faceted_search-panel_pane_1' && isset($vars['display']->args[0])) {
    if (og_is_group('node', $vars['display']->args[0])) {
      $community = entity_load_single('node', $vars['display']->args[0]);
      $vars['community_name'] = $community->title;
      $vars['community_name_attributes'] = '';
    }
  }

  // Add extra class and pane title for debates list
  if ($vars['pane']->subtype == 'ag_section_questions_answers-selector_question_debate') {
    $vars['display']->wrap_class = 'wrapper-detail-content';
    $vars['display']->title_middle = '<h2 class="pane-title">' . t('Questions and discussions') . '</h2>';
  }

  // Add extra class for node details.
  $allowed_types = array('webinar', 'event', 'debate', 'question');
  if ($vars['pane']->subtype == 'node' && isset($vars['content']['node'])) {
    // Get node type.
    $node = $vars['content']['node'];
    $node_data = array_shift($node);
    if (!empty($node_data['#bundle']) && in_array($node_data['#bundle'], $allowed_types)) {
      $vars['classes_array'][] = 'wrapper-detail-content';
    }
  }

  // Add extra class for content wrapper.
  if ($vars['pane']->subtype == 'user' && isset($vars['pane']->configuration['view_mode']) && $vars['pane']->configuration['view_mode'] == 'public') {
    $vars['classes_array'][] = 'wrapper-detail-content';
  }

  // Add Create learning path button.
  if ($vars['pane']->subtype == 'my_learning_paths-panel_pane_my_learning_paths') {
    $vars['create_learning_path'] = l(t('Create learning path'), 'node/add/itinerary', array(
      'attributes' => array(
        'id' => 'create-learning-path',
        'title' => t('Create learning path'),
      ),
      'query' => array('destination' => 'user/' . $vars['user']->uid . '/learning-paths'),
    ));
  }
}

/**
 * Override theme_menu_link().
 */
function nexus_menu_link($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Add custom class to control center links
  switch ($element['#href']) {
    case 'admin/control-center':
      $element['#attributes']['class'][] = 'control-center';
      break;
    case 'admin/control-center/communities':
      $element['#attributes']['class'][] = 'admin-communities';
      break;
    case 'admin/control-center/content':
      $element['#attributes']['class'][] = 'admin-content';
      break;
    case 'admin/control-center/certifications/list':
      $element['#attributes']['class'][] = 'admin-certifications';
      break;
    case 'admin/control-center/users':
      $element['#attributes']['class'][] = 'admin-users';
      break;
    case 'admin/control-center/reports':
      $element['#attributes']['class'][] = 'reports';
      break;
    case 'admin/control-center/boosting':
      $element['#attributes']['class'][] = 'boosting';
      break;
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function nexus_superfish_build($variables) {
  $output = array('content' => '');
  $id = $variables['id'];
  $menu = $variables['menu'];
  $depth = $variables['depth'];
  $trail = $variables['trail'];
  $clone_parent = $variables['clone_parent'];
  // Keep $sfsettings untouched as we need to pass it to the child menus.
  $settings = $sfsettings = $variables['sfsettings'];
  $megamenu = $megamenu_below = $settings['megamenu'];
  $total_children = $parent_children = $single_children = 0;
  $i = 1;

  // Reckon the total number of available menu items.
  foreach ($menu as $menu_item) {
    if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
      $total_children++;
    }
  }

  // sfTouchscreen.
  // Adding cloned parent to the sub-menu.
  if ($clone_parent !== FALSE) {
    array_unshift($menu, $clone_parent);
  }

  foreach ($menu as $menu_item) {
    $show_children = $megamenu_wrapper = $megamenu_column = $megamenu_content = FALSE;
    $item_class = $link_class = array();
    $mlid = $menu_item['link']['mlid'];

    if (!isset($menu_item['link']['hidden']) || $menu_item['link']['hidden'] == 0) {
      $item_class[] = ($trail && in_array($mlid, $trail)) ? 'active-trail' : '';

      // Add helper classes to the menu items and hyperlinks.
      $settings['firstlast'] = ($settings['dfirstlast'] == 1 && $total_children == 1) ? 0 : $settings['firstlast'];
      $item_class[] = ($settings['firstlast'] == 1) ? (($i == 1 && $i == $total_children) ? 'firstandlast' : (($i == 1) ? 'first' : (($i == $total_children) ? 'last' : 'middle'))) : '';
      $settings['zebra'] = ($settings['dzebra'] == 1 && $total_children == 1) ? 0 : $settings['zebra'];
      $item_class[] = ($settings['zebra'] == 1) ? (($i % 2) ? 'odd' : 'even') : '';
      $item_class[] = ($settings['itemcount'] == 1) ? 'sf-item-' . $i : '';
      $item_class[] = ($settings['itemdepth'] == 1) ? 'sf-depth-' . $menu_item['link']['depth'] : '';
      $link_class[] = ($settings['itemdepth'] == 1) ? 'sf-depth-' . $menu_item['link']['depth'] : '';
      $item_class[] = ($settings['liclass']) ? trim($settings['liclass']) : '';
      $item_class[] = ($clone_parent !== FALSE) ? 'sf-clone-parent' : '';
      if (strpos($settings['hlclass'], ' ')) {
        $l = explode(' ', $settings['hlclass']);
        foreach ($l as $c) {
          $link_class[] = trim($c);
        }
      }
      else {
        $link_class[] = $settings['hlclass'];
      }
      $i++;

      // Hide hyperlink descriptions ("title" attribute).
      if ($settings['hidelinkdescription'] == 1) {
        unset($menu_item['link']['localized_options']['attributes']['title']);
      }

      // Insert hyperlink description ("title" attribute) into the text.
      $show_linkdescription = ($settings['linkdescription'] == 1 && !empty($menu_item['link']['localized_options']['attributes']['title'])) ? TRUE : FALSE;
      if ($show_linkdescription) {
        if (!empty($settings['hldmenus'])) {
          $show_linkdescription = (is_array($settings['hldmenus'])) ? ((in_array($mlid, $settings['hldmenus'])) ? TRUE : FALSE) : (($mlid == $settings['hldmenus']) ? TRUE : FALSE);
        }
        if (!empty($settings['hldexclude'])) {
          $show_linkdescription = (is_array($settings['hldexclude'])) ? ((in_array($mlid, $settings['hldexclude'])) ? FALSE : $show_linkdescription) : (($settings['hldexclude'] == $mlid) ? FALSE : $show_linkdescription);
        }
        if ($show_linkdescription) {
          $menu_item['link']['title'] .= ' <span class="sf-description">';
          $menu_item['link']['title'] .= (!empty($menu_item['link']['localized_options']['attributes']['title'])) ? $menu_item['link']['localized_options']['attributes']['title'] : array();
          $menu_item['link']['title'] .= '</span>';
          $menu_item['link']['localized_options']['html'] = TRUE;
        }
      }

      // Add custom HTML codes around the menu items.
      if ($sfsettings['wrapul'] && strpos($sfsettings['wrapul'], ',') !== FALSE) {
        $wul = explode(',', $sfsettings['wrapul']);
        // In case you just wanted to add something after the element.
        if (drupal_substr($sfsettings['wrapul'], 0) == ',') {
          array_unshift($wul, '');
        }
      }
      else {
        $wul = array();
      }

      // Add custom HTML codes around the hyperlinks.
      if ($settings['wraphl'] && strpos($settings['wraphl'], ',') !== FALSE) {
        $whl = explode(',', $settings['wraphl']);
        // The same as above.
        if (drupal_substr($settings['wraphl'], 0) == ',') {
          array_unshift($whl, '');
        }
      }
      else {
        $whl = array();
      }

      // Add custom HTML codes around the hyperlinks text.
      if ($settings['wraphlt'] && strpos($settings['wraphlt'], ',') !== FALSE) {
        $whlt = explode(',', $settings['wraphlt']);
        // The same as above.
        if (drupal_substr($settings['wraphlt'], 0) == ',') {
          array_unshift($whlt, '');
        }
        $menu_item['link']['title'] = $whlt[0] . $menu_item['link']['title'] . $whlt[1];
        $menu_item['link']['localized_options']['html'] = TRUE;
      }

      $expanded = ($sfsettings['expanded'] == 1) ? (($menu_item['link']['expanded'] == 1) ? TRUE : FALSE) : TRUE;

      if (!empty($menu_item['link']['has_children']) && !empty($menu_item['below']) && $depth != 0 && $expanded === TRUE) {

        // Megamenu is still beta, there is a good chance this will be changed.
        if (!empty($settings['megamenu_exclude'])) {
          if (is_array($settings['megamenu_exclude'])) {
            $megamenu_below = (in_array($mlid, $settings['megamenu_exclude'])) ? 0 : $megamenu;
          }
          else {
            $megamenu_below = ($settings['megamenu_exclude'] == $mlid) ? 0 : $megamenu;
          }
          // Send the result to the sub-menu.
          $sfsettings['megamenu'] = $megamenu_below;
        }
        if ($megamenu_below == 1) {
          $megamenu_wrapper = ($menu_item['link']['depth'] == $settings['megamenu_depth']) ? TRUE : FALSE;
          $megamenu_column = ($menu_item['link']['depth'] == $settings['megamenu_depth'] + 1) ? TRUE : FALSE;
          $megamenu_content = ($menu_item['link']['depth'] >= $settings['megamenu_depth'] && $menu_item['link']['depth'] <= $settings['megamenu_levels']) ? TRUE : FALSE;
        }

        // sfTouchscreen.
        // Preparing the cloned parent links to be added to the sub-menus.
        $below_visible = array();
        foreach ($menu_item['below'] as $below) {
          if (!isset($below['link']['hidden']) || $below['link']['hidden'] == 0) {
            $below_visible[] = 1;
          }
        }
        if ($settings['clone_parent'] == 1 && in_array(1, $below_visible)) {
          $clone_parent = $menu_item;
          unset($clone_parent['below']);
          unset($clone_parent['has_children']);
        }
        else {
          $clone_parent = FALSE;
        }

        // Render the sub-menu.
        $var = array(
            'id' => $id,
            'menu' => $menu_item['below'],
            'depth' => $depth,
            'trail' => $trail,
            'clone_parent' => $clone_parent,
            'sfsettings' => $sfsettings,
        );
        $children = theme('superfish_build', $var);
        // Check to see whether it should be displayed.
        $show_children = (($menu_item['link']['depth'] <= $depth || $depth == -1) && $children['content']) ? TRUE : FALSE;
        if ($show_children) {
          // Add item counter classes.
          if ($settings['itemcounter']) {
            $item_class[] = 'sf-total-children-' . $children['total_children'];
            $item_class[] = 'sf-parent-children-' . $children['parent_children'];
            $item_class[] = 'sf-single-children-' . $children['single_children'];
          }
          // More helper classes.
          $item_class[] = ($megamenu_column) ? 'sf-megamenu-column' : '';
          $item_class[] = $link_class[] = 'menuparent';
        }
        $parent_children++;

        // Add class based on query type. This is for leave only active when path is the same.
        if(isset($menu_item['link']['localized_options']['query']['type'])){
          $link_class[] = strtolower($menu_item['link']['localized_options']['query']['type']);
        }
      }
      else {
        $item_class[] = 'sf-no-children';
        $single_children++;
        
        // Check if is novelty link.
        if (isset($menu_item['link']['localized_options']['query']['novelty'])) {
          $link_class[] = 'novelty';
        }
      }

      $item_class = trim(implode(' ', superfish_array_filter($item_class)));

      if (isset($menu_item['link']['localized_options']['attributes']['class'])) {
        $link_class_current = $menu_item['link']['localized_options']['attributes']['class'];
        $link_class = array_merge($link_class_current, superfish_array_filter($link_class));
      }
      $menu_item['link']['localized_options']['attributes']['class'] = superfish_array_filter($link_class);

      // The Context module uses theme_menu_link,
      // Superfish does not, this is why we have to do this.
      if (function_exists('context_active_contexts')) {
        if ($contexts = context_active_contexts()) {
          foreach ($contexts as $context) {
            if ((isset($context->reactions['menu']))) {
              if ($menu_item['link']['href'] == $context->reactions['menu']) {
                $menu_item['link']['localized_options']['attributes']['class'][] = 'active';
              }
            }
          }
        }
      }

      // Render the menu item.
      // Should a theme be used for menu items?
      if ($settings['use_item_theme']) {
        $item_variables = array(
            'element' => array(
                'attributes' => array(
                    'id' => 'menu-' . $mlid . '-' . $id,
                    'class' => trim($item_class),
                ),
                'below' => ($show_children) ? $children['content'] : NULL,
                'item' => $menu_item,
            ),
            'properties' => array(
                'megamenu' => array(
                    'megamenu_column' => $megamenu_column,
                    'megamenu_wrapper' => $megamenu_wrapper,
                    'megamenu_content' => $megamenu_content,
                ),
                'use_link_theme' => $settings['use_link_theme'],
                'wrapper' => array(
                    'wul' => $wul,
                    'whl' => $whl,
                ),
            ),
            'sfsettings' => $sfsettings,
        );
        $output['content'] .= theme('superfish_menu_item', $item_variables);
      }
      else {
        $output['content'] .= '<li' . drupal_attributes(array('id' => 'menu-' . $mlid . '-' . $id, 'class' => $item_class)) . '>';
        $output['content'] .= ($megamenu_column) ? '<div class="sf-megamenu-column">' : '';
        $output['content'] .= isset($whl[0]) ? $whl[0] : '';
        if ($settings['use_link_theme']) {
          $link_variables = array(
              'menu_item' => $menu_item,
              'link_options' => $menu_item['link']['localized_options'],
          );
          $output['content'] .= theme('superfish_menu_item_link', $link_variables);
        }
        else {
          $output['content'] .= l($menu_item['link']['title'], $menu_item['link']['href'], $menu_item['link']['localized_options']);
        }
        $output['content'] .= isset($whl[1]) ? $whl[1] : '';
        $output['content'] .= ($megamenu_wrapper) ? '<ul class="sf-megamenu"><li class="sf-megamenu-wrapper ' . $item_class . '">' : '';
        $output['content'] .= ($show_children) ? (isset($wul[0]) ? $wul[0] : '') : '';
        $output['content'] .= ($show_children) ? (($megamenu_content) ? '<ol>' : '<ul>') : '';
        $output['content'] .= ($show_children) ? $children['content'] : '';
        $output['content'] .= ($show_children) ? (($megamenu_content) ? '</ol>' : '</ul>') : '';
        $output['content'] .= ($show_children) ? (isset($wul[1]) ? $wul[1] : '') : '';
        $output['content'] .= ($megamenu_wrapper) ? '</li></ul>' : '';
        $output['content'] .= ($megamenu_column) ? '</div>' : '';
        $output['content'] .= '</li>';
      }
    }
  }
  $output['total_children'] = $total_children;
  $output['parent_children'] = $parent_children;
  $output['single_children'] = $single_children;
  return $output;
}

/**
 * Implements hook_preprocess_HOOK().
 */
function nexus_preprocess_link(&$variables) {
  // Filter to be sure we are applying changes to the links we want to. In this case it is from parent links on menu-home.
  if (substr_count($variables['path'], 'ode-search') > 0 ) {
    //dpm($variables);
  }
  $class_filter = ((isset($variables['options']['attributes']['class']) && is_array($variables['options']['attributes']['class'])) && in_array('menuparent', $variables['options']['attributes']['class']));
  if (substr_count($variables['path'], 'ode-search') > 0 && $class_filter) {
    // We have a class based on parent type, so if we go through any son we change class to his parent.
    if (isset($_GET['type'])) {
      $type = $_GET['type'];

      switch ($type) {
        case 'LEARNING_RESOURCE':
        case 'POST':
        case 'URL':
          $type = 'learning_resource';
          break;
        case 'USER':
        case 'COMMUNITY':
        case 'POLL':
        case 'DISCUSSION':
        case 'WEBINAR':
        case 'EVENT':
          $type = 'user';
          break;
      }

      // Search for this type class on array of classes
      $parent_identifier = array_search($type, $variables['options']['attributes']['class']);

      if ($parent_identifier == FALSE || isset($_GET['novelty'])) {
        $active_key = array_search('active', $variables['options']['attributes']['class']);

        // If we found active class we delete it.
        if($active_key !== FALSE) {
          unset($variables['options']['attributes']['class'][$active_key]);
        }
      }
    }
  }

  // Force novelty link active.
  if (!isset($_GET['novelty']) && isset($variables['options']['attributes']['class']) && is_array($variables['options']['attributes']['class']) && in_array('novelty', $variables['options']['attributes']['class'])) {
    $active_key = array_search('active', $variables['options']['attributes']['class']);
    if($active_key !== FALSE) {
      unset($variables['options']['attributes']['class'][$active_key]);
    }
  }
}

/**
 * Implements hook_preprocess_HOOK().
 */
function nexus_preprocess_pager(&$vars) {
  // Alter default pager
  $node = menu_get_object();

  if (in_array($node->type, array('debate', 'event', 'webinar', 'post', 'poll', 'ode'))) {
    $vars['tags'] = array('«','‹','','›','»');
    $vars['quantity'] = 10;
  }
}

/**
 * Default theme function for all RSS rows.
 */
function nexus_preprocess_views_view_row_rss(&$vars) {
  $item = &$vars['row'];

  $results = $vars['view']->result;
  $elements = array();
  foreach ($results as $result) {
    $elements[$result->nid] = array(
      'trackid' => $result->field_field_soundcloud_trackid[0]['raw']['value'],
      'size' => $result->field_field_file_size[0]['raw']['value'],
    );
  }

  // Add xml enclosure tag for Soundcloud media file.
  $item->elements[] = array(
    'key' => 'enclosure',
    'attributes' => array(
      'url' => 'https://api.soundcloud.com/tracks/' .
                $elements[$item->nid]['trackid'] .
                '/download?client_id=' . SOUNDCLOUD_CLIENT_ID,
      'length' => $elements[$item->nid]['size'],
      'type' => 'audio/mpeg',
    ),
  );

  $vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
}
