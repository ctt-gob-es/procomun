<?php
/**
 * @file
 * ag_home.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_home_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home__panel';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'threecol_33_34_33_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e2c8aeb7-c509-4a75-b2bb-5418c69a8771';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bd31be08-049c-4aab-8c4b-e73812407ef6';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---vistazo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bd31be08-049c-4aab-8c4b-e73812407ef6';
    $display->content['new-bd31be08-049c-4aab-8c4b-e73812407ef6'] = $pane;
    $display->panels['bottom'][0] = 'new-bd31be08-049c-4aab-8c4b-e73812407ef6';
    $pane = new stdClass();
    $pane->pid = 'new-353c663d-1812-483a-87fb-aedcf43f2c54';
    $pane->panel = 'bottom';
    $pane->type = 'views';
    $pane->subtype = 'agrega2_home_highlighted';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-li-home col-sm-4',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '353c663d-1812-483a-87fb-aedcf43f2c54';
    $display->content['new-353c663d-1812-483a-87fb-aedcf43f2c54'] = $pane;
    $display->panels['bottom'][1] = 'new-353c663d-1812-483a-87fb-aedcf43f2c54';
    $pane = new stdClass();
    $pane->pid = 'new-0e70191f-fe00-47fb-a388-39afbd0dc297';
    $pane->panel = 'bottom';
    $pane->type = 'panels_mini';
    $pane->subtype = 'home_middle_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-li-home col-sm-5',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0e70191f-fe00-47fb-a388-39afbd0dc297';
    $display->content['new-0e70191f-fe00-47fb-a388-39afbd0dc297'] = $pane;
    $display->panels['bottom'][2] = 'new-0e70191f-fe00-47fb-a388-39afbd0dc297';
    $pane = new stdClass();
    $pane->pid = 'new-3b70d46d-ebb8-4f1d-8797-89271795fffe';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'twitter_timeline-twitter_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Twitter',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'block-li-home col-sm-3',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3b70d46d-ebb8-4f1d-8797-89271795fffe';
    $display->content['new-3b70d46d-ebb8-4f1d-8797-89271795fffe'] = $pane;
    $display->panels['bottom'][3] = 'new-3b70d46d-ebb8-4f1d-8797-89271795fffe';
    $pane = new stdClass();
    $pane->pid = 'new-9350255d-9b52-43b3-82dd-b4770f2d267b';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---localiza-contenido';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-bean-banner-home col-sm-4',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9350255d-9b52-43b3-82dd-b4770f2d267b';
    $display->content['new-9350255d-9b52-43b3-82dd-b4770f2d267b'] = $pane;
    $display->panels['top'][0] = 'new-9350255d-9b52-43b3-82dd-b4770f2d267b';
    $pane = new stdClass();
    $pane->pid = 'new-8cbc3b75-eb9b-48a7-acc1-63854beb38d9';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---encuentra-personas';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-bean-banner-home col-sm-4',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8cbc3b75-eb9b-48a7-acc1-63854beb38d9';
    $display->content['new-8cbc3b75-eb9b-48a7-acc1-63854beb38d9'] = $pane;
    $display->panels['top'][1] = 'new-8cbc3b75-eb9b-48a7-acc1-63854beb38d9';
    $pane = new stdClass();
    $pane->pid = 'new-298acff7-b921-46e8-b526-0de92010df89';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'bean-banner-home---mantente-actualiza';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-bean-banner-home col-sm-4',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '298acff7-b921-46e8-b526-0de92010df89';
    $display->content['new-298acff7-b921-46e8-b526-0de92010df89'] = $pane;
    $display->panels['top'][2] = 'new-298acff7-b921-46e8-b526-0de92010df89';
    $pane = new stdClass();
    $pane->pid = 'new-603a0caf-0d7b-4fc4-ae14-92ac3f2cce9a';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'ag_home-custom_register_link';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '603a0caf-0d7b-4fc4-ae14-92ac3f2cce9a';
    $display->content['new-603a0caf-0d7b-4fc4-ae14-92ac3f2cce9a'] = $pane;
    $display->panels['top'][3] = 'new-603a0caf-0d7b-4fc4-ae14-92ac3f2cce9a';
    $pane = new stdClass();
    $pane->pid = 'new-13596b09-5220-4e80-9ead-1b647a781227';
    $pane->panel = 'top';
    $pane->type = 'panels_mini';
    $pane->subtype = 'banner_home_content_count';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '13596b09-5220-4e80-9ead-1b647a781227';
    $display->content['new-13596b09-5220-4e80-9ead-1b647a781227'] = $pane;
    $display->panels['top'][4] = 'new-13596b09-5220-4e80-9ead-1b647a781227';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
