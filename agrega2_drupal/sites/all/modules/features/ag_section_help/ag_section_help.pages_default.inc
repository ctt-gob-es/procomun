<?php
/**
 * @file
 * ag_section_help.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_help_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_contents_faq_pending';
  $page->task = 'page';
  $page->admin_title = 'Control center contents faq pending';
  $page->admin_description = 'Admin control panel for managing the faq pending contents';
  $page->path = 'admin/control-center/content/faq-pending';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center contents',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Moderar preguntas frecuentes',
    'name' => 'navigation',
    'weight' => '1',
    'parent' => array(
      'type' => 'normal',
      'title' => '',
      'name' => 'menu-control-center-main-menu',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_control_center_contents_faq_pending__panel_context_9ec0bb9e-ae20-4ebb-aeba-1644ed35b946';
  $handler->task = 'page';
  $handler->subtask = 'control_center_contents_faq_pending';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Control center content list',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'administer nodes',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'ag-3-9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Moderar preguntas frecuentes';
  $display->uuid = '54a6b2a0-2df3-4f97-b451-9f6e783df9bc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-control-center-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
    $display->content['new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a'] = $pane;
    $display->panels['right'][0] = 'new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
    $pane = new stdClass();
    $pane->pid = 'new-53f64a10-131f-452a-b71e-147ba8dcd12d';
    $pane->panel = 'right';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'none',
      'class' => '',
      'id' => '',
      'override_title' => 1,
      'override_title_text' => 'Lista de preguntas frecuentes',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '53f64a10-131f-452a-b71e-147ba8dcd12d';
    $display->content['new-53f64a10-131f-452a-b71e-147ba8dcd12d'] = $pane;
    $display->panels['right'][1] = 'new-53f64a10-131f-452a-b71e-147ba8dcd12d';
    $pane = new stdClass();
    $pane->pid = 'new-ebf723b5-38c1-4092-8d43-4b67b1c3243c';
    $pane->panel = 'right';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ebf723b5-38c1-4092-8d43-4b67b1c3243c';
    $display->content['new-ebf723b5-38c1-4092-8d43-4b67b1c3243c'] = $pane;
    $display->panels['right'][2] = 'new-ebf723b5-38c1-4092-8d43-4b67b1c3243c';
    $pane = new stdClass();
    $pane->pid = 'new-ed59b3c5-0a9e-4e85-8a65-ca8ddd83a0f2';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'faq-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ed59b3c5-0a9e-4e85-8a65-ca8ddd83a0f2';
    $display->content['new-ed59b3c5-0a9e-4e85-8a65-ca8ddd83a0f2'] = $pane;
    $display->panels['right'][3] = 'new-ed59b3c5-0a9e-4e85-8a65-ca8ddd83a0f2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-6b5b787a-c403-4ac0-9a2f-e60ef1c4cc3a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_contents_faq_pending'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frequently_asked_questions';
  $page->task = 'page';
  $page->admin_title = 'Frequently asked questions';
  $page->admin_description = '';
  $page->path = 'help/faq';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Frecuently asked questions',
    'name' => 'navigation',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => 'help',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_frequently_asked_questions__panel';
  $handler->task = 'page';
  $handler->subtask = 'frequently_asked_questions';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Ayuda';
  $display->uuid = 'a2b188dd-c873-4d0d-b1a7-0c2bfd99b522';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d33074fa-c4df-4b17-acf9-74032bf0bc2d';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-help_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
      'css_class' => 'search-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd33074fa-c4df-4b17-acf9-74032bf0bc2d';
    $display->content['new-d33074fa-c4df-4b17-acf9-74032bf0bc2d'] = $pane;
    $display->panels['middle'][0] = 'new-d33074fa-c4df-4b17-acf9-74032bf0bc2d';
    $pane = new stdClass();
    $pane->pid = 'new-203c09f5-0d00-420c-bc6a-4e7f1bfac7b2';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_contact_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-header',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '203c09f5-0d00-420c-bc6a-4e7f1bfac7b2';
    $display->content['new-203c09f5-0d00-420c-bc6a-4e7f1bfac7b2'] = $pane;
    $display->panels['middle'][1] = 'new-203c09f5-0d00-420c-bc6a-4e7f1bfac7b2';
    $pane = new stdClass();
    $pane->pid = 'new-bd17d643-e756-42b5-ac27-003520ae6808';
    $pane->panel = 'middle';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
      'css_class' => 'help-tabs',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bd17d643-e756-42b5-ac27-003520ae6808';
    $display->content['new-bd17d643-e756-42b5-ac27-003520ae6808'] = $pane;
    $display->panels['middle'][2] = 'new-bd17d643-e756-42b5-ac27-003520ae6808';
    $pane = new stdClass();
    $pane->pid = 'new-55a938b5-3845-48dc-ad27-54b535364115';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_faq_pane_title';
    $pane->shown = TRUE;
    $pane->access = array();
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
    $pane->uuid = '55a938b5-3845-48dc-ad27-54b535364115';
    $display->content['new-55a938b5-3845-48dc-ad27-54b535364115'] = $pane;
    $display->panels['middle'][3] = 'new-55a938b5-3845-48dc-ad27-54b535364115';
    $pane = new stdClass();
    $pane->pid = 'new-6a2276fe-9df4-444e-8c1a-60dd4e220e2c';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_create_faq_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'new-content-button',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6a2276fe-9df4-444e-8c1a-60dd4e220e2c';
    $display->content['new-6a2276fe-9df4-444e-8c1a-60dd4e220e2c'] = $pane;
    $display->panels['middle'][4] = 'new-6a2276fe-9df4-444e-8c1a-60dd4e220e2c';
    $pane = new stdClass();
    $pane->pid = 'new-8069c229-74fa-4f49-b33d-21eb989d9297';
    $pane->panel = 'middle';
    $pane->type = 'faq_form';
    $pane->subtype = 'faq_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '8069c229-74fa-4f49-b33d-21eb989d9297';
    $display->content['new-8069c229-74fa-4f49-b33d-21eb989d9297'] = $pane;
    $display->panels['middle'][5] = 'new-8069c229-74fa-4f49-b33d-21eb989d9297';
    $pane = new stdClass();
    $pane->pid = 'new-eea14d10-6dc0-4197-94d9-b9ae0501166a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'faq-panel_pane_faq_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'eea14d10-6dc0-4197-94d9-b9ae0501166a';
    $display->content['new-eea14d10-6dc0-4197-94d9-b9ae0501166a'] = $pane;
    $display->panels['middle'][6] = 'new-eea14d10-6dc0-4197-94d9-b9ae0501166a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frequently_asked_questions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'help_search';
  $page->task = 'page';
  $page->admin_title = 'Help Search';
  $page->admin_description = '';
  $page->path = 'help/search';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'action',
    'title' => '',
    'name' => 'navigation',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_help_search__panel';
  $handler->task = 'page';
  $handler->subtask = 'help_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Ayuda';
  $display->uuid = 'b5160dd7-db26-4515-955c-7b3d1c197db5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c655aff5-7d08-48c0-ab5f-c4abcd0edfeb';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-help_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
      'css_class' => 'search-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c655aff5-7d08-48c0-ab5f-c4abcd0edfeb';
    $display->content['new-c655aff5-7d08-48c0-ab5f-c4abcd0edfeb'] = $pane;
    $display->panels['middle'][0] = 'new-c655aff5-7d08-48c0-ab5f-c4abcd0edfeb';
    $pane = new stdClass();
    $pane->pid = 'new-251e7f73-d577-45c9-8818-dfc48e05d59b';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_contact_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-header',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '251e7f73-d577-45c9-8818-dfc48e05d59b';
    $display->content['new-251e7f73-d577-45c9-8818-dfc48e05d59b'] = $pane;
    $display->panels['middle'][1] = 'new-251e7f73-d577-45c9-8818-dfc48e05d59b';
    $pane = new stdClass();
    $pane->pid = 'new-8fe14c15-4b2b-4cf4-b0c1-c45a8429fb34';
    $pane->panel = 'middle';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
      'css_class' => 'help-tabs',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8fe14c15-4b2b-4cf4-b0c1-c45a8429fb34';
    $display->content['new-8fe14c15-4b2b-4cf4-b0c1-c45a8429fb34'] = $pane;
    $display->panels['middle'][2] = 'new-8fe14c15-4b2b-4cf4-b0c1-c45a8429fb34';
    $pane = new stdClass();
    $pane->pid = 'new-ff92717b-87a0-4fd4-a39e-fde967b6b453';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'help_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ff92717b-87a0-4fd4-a39e-fde967b6b453';
    $display->content['new-ff92717b-87a0-4fd4-a39e-fde967b6b453'] = $pane;
    $display->panels['middle'][3] = 'new-ff92717b-87a0-4fd4-a39e-fde967b6b453';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ff92717b-87a0-4fd4-a39e-fde967b6b453';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['help_search'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'landing_help';
  $page->task = 'page';
  $page->admin_title = 'Landing help';
  $page->admin_description = '';
  $page->path = 'help';
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
  $handler->name = 'page_landing_help__panel';
  $handler->task = 'page';
  $handler->subtask = 'landing_help';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Ayuda';
  $display->uuid = '0501f9a7-eed7-4136-8b39-cc1350d018df';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-77350388-64ad-44bc-9936-b8083dba0c7c';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-help_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
      'css_class' => 'search-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '77350388-64ad-44bc-9936-b8083dba0c7c';
    $display->content['new-77350388-64ad-44bc-9936-b8083dba0c7c'] = $pane;
    $display->panels['middle'][0] = 'new-77350388-64ad-44bc-9936-b8083dba0c7c';
    $pane = new stdClass();
    $pane->pid = 'new-15a5d729-43e8-4f71-bb50-37a931e5126d';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_contact_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-header',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '15a5d729-43e8-4f71-bb50-37a931e5126d';
    $display->content['new-15a5d729-43e8-4f71-bb50-37a931e5126d'] = $pane;
    $display->panels['middle'][1] = 'new-15a5d729-43e8-4f71-bb50-37a931e5126d';
    $pane = new stdClass();
    $pane->pid = 'new-6d150e1e-e37a-4161-b68c-1667354c4d60';
    $pane->panel = 'middle';
    $pane->type = 'custom_translatable_block';
    $pane->subtype = 'custom_translatable_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'content_type_custom_block_title' => 'Manual',
      'content_type_custom_block_content' => 'See the updated web operation manual. It is available online or for download in pdf format.',
      'content_type_custom_block_class' => 'landing-help-manual',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'content_type_custom_block_title_link' => 'help/manual',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'first',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6d150e1e-e37a-4161-b68c-1667354c4d60';
    $display->content['new-6d150e1e-e37a-4161-b68c-1667354c4d60'] = $pane;
    $display->panels['middle'][2] = 'new-6d150e1e-e37a-4161-b68c-1667354c4d60';
    $pane = new stdClass();
    $pane->pid = 'new-f883018f-c848-4982-a0ad-39ac02e67e0c';
    $pane->panel = 'middle';
    $pane->type = 'custom_translatable_block';
    $pane->subtype = 'custom_translatable_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'content_type_custom_block_title' => 'Frequent questions',
      'content_type_custom_block_content' => 'Find answers to the most relevant questions posed by users.',
      'content_type_custom_block_class' => 'landing-help-faq',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'content_type_custom_block_title_link' => 'help/faq',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f883018f-c848-4982-a0ad-39ac02e67e0c';
    $display->content['new-f883018f-c848-4982-a0ad-39ac02e67e0c'] = $pane;
    $display->panels['middle'][3] = 'new-f883018f-c848-4982-a0ad-39ac02e67e0c';
    $pane = new stdClass();
    $pane->pid = 'new-bcd0796d-61bc-47e6-bde4-61f6369b35b2';
    $pane->panel = 'middle';
    $pane->type = 'custom_translatable_block';
    $pane->subtype = 'custom_translatable_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'content_type_custom_block_title' => 'New functionalities',
      'content_type_custom_block_content' => 'Stay informed of operating improvements portal.',
      'content_type_custom_block_class' => 'landing-help-new',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'content_type_custom_block_title_link' => 'help/functionality',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'bcd0796d-61bc-47e6-bde4-61f6369b35b2';
    $display->content['new-bcd0796d-61bc-47e6-bde4-61f6369b35b2'] = $pane;
    $display->panels['middle'][4] = 'new-bcd0796d-61bc-47e6-bde4-61f6369b35b2';
    $pane = new stdClass();
    $pane->pid = 'new-3c5acc24-8cbb-434b-8ddb-b0e6dcbe332a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'help_landing_rankings-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-rankings first most-viewed',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '3c5acc24-8cbb-434b-8ddb-b0e6dcbe332a';
    $display->content['new-3c5acc24-8cbb-434b-8ddb-b0e6dcbe332a'] = $pane;
    $display->panels['middle'][5] = 'new-3c5acc24-8cbb-434b-8ddb-b0e6dcbe332a';
    $pane = new stdClass();
    $pane->pid = 'new-a13b7ea9-e2d2-41e9-9076-055992c262ca';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'help_landing_rankings-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-rankings most-rated',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'a13b7ea9-e2d2-41e9-9076-055992c262ca';
    $display->content['new-a13b7ea9-e2d2-41e9-9076-055992c262ca'] = $pane;
    $display->panels['middle'][6] = 'new-a13b7ea9-e2d2-41e9-9076-055992c262ca';
    $pane = new stdClass();
    $pane->pid = 'new-bc28115c-c6fe-4a84-88f1-f495ae0ff958';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'help_landing_rankings-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-rankings most-recent',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'bc28115c-c6fe-4a84-88f1-f495ae0ff958';
    $display->content['new-bc28115c-c6fe-4a84-88f1-f495ae0ff958'] = $pane;
    $display->panels['middle'][7] = 'new-bc28115c-c6fe-4a84-88f1-f495ae0ff958';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['landing_help'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'manual_section';
  $page->task = 'page';
  $page->admin_title = 'Manual section';
  $page->admin_description = '';
  $page->path = 'help/manual';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Manual',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_manual_section__panel';
  $handler->task = 'page';
  $handler->subtask = 'manual_section';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Ayuda';
  $display->uuid = 'd5417b8e-15fc-4c2b-92ff-d47b1b37b03c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3e9069c1-b208-48bf-b9c6-e2804ab81602';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-help_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
      'css_class' => 'search-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3e9069c1-b208-48bf-b9c6-e2804ab81602';
    $display->content['new-3e9069c1-b208-48bf-b9c6-e2804ab81602'] = $pane;
    $display->panels['middle'][0] = 'new-3e9069c1-b208-48bf-b9c6-e2804ab81602';
    $pane = new stdClass();
    $pane->pid = 'new-6e065a0e-0e0f-4154-a931-cb78293c20a7';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_contact_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-header',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6e065a0e-0e0f-4154-a931-cb78293c20a7';
    $display->content['new-6e065a0e-0e0f-4154-a931-cb78293c20a7'] = $pane;
    $display->panels['middle'][1] = 'new-6e065a0e-0e0f-4154-a931-cb78293c20a7';
    $pane = new stdClass();
    $pane->pid = 'new-7cc4156d-7e0f-4387-8a49-d6d69d063e93';
    $pane->panel = 'middle';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
      'css_class' => 'help-tabs',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7cc4156d-7e0f-4387-8a49-d6d69d063e93';
    $display->content['new-7cc4156d-7e0f-4387-8a49-d6d69d063e93'] = $pane;
    $display->panels['middle'][2] = 'new-7cc4156d-7e0f-4387-8a49-d6d69d063e93';
    $pane = new stdClass();
    $pane->pid = 'new-be41cf8d-eaf6-40b7-a6d9-e91e9a367216';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'manual_index-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'col-sm-3 col-md-3 manual-index',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'be41cf8d-eaf6-40b7-a6d9-e91e9a367216';
    $display->content['new-be41cf8d-eaf6-40b7-a6d9-e91e9a367216'] = $pane;
    $display->panels['middle'][3] = 'new-be41cf8d-eaf6-40b7-a6d9-e91e9a367216';
    $pane = new stdClass();
    $pane->pid = 'new-a3df382b-67ae-4c3f-b2ff-398ffdf81438';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'help_manual_content';
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
      'css_class' => 'col-sm-9 col-md-9 manual-content',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a3df382b-67ae-4c3f-b2ff-398ffdf81438';
    $display->content['new-a3df382b-67ae-4c3f-b2ff-398ffdf81438'] = $pane;
    $display->panels['middle'][4] = 'new-a3df382b-67ae-4c3f-b2ff-398ffdf81438';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['manual_section'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'new_functionalities';
  $page->task = 'page';
  $page->admin_title = 'New functionalities';
  $page->admin_description = '';
  $page->path = 'help/functionality';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'New functionalities',
    'name' => 'navigation',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_new_functionalities__panel';
  $handler->task = 'page';
  $handler->subtask = 'new_functionalities';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Ayuda';
  $display->uuid = 'fe43843e-26a3-41fc-b25b-6cffdab0254d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e4a9f6b-a012-427a-b475-59c61e6414f0';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-help_search-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
      'css_class' => 'search-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8e4a9f6b-a012-427a-b475-59c61e6414f0';
    $display->content['new-8e4a9f6b-a012-427a-b475-59c61e6414f0'] = $pane;
    $display->panels['middle'][0] = 'new-8e4a9f6b-a012-427a-b475-59c61e6414f0';
    $pane = new stdClass();
    $pane->pid = 'new-e7e3ec18-8eb7-4ebc-8804-ebd82a677aea';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_contact_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'help-header',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e7e3ec18-8eb7-4ebc-8804-ebd82a677aea';
    $display->content['new-e7e3ec18-8eb7-4ebc-8804-ebd82a677aea'] = $pane;
    $display->panels['middle'][1] = 'new-e7e3ec18-8eb7-4ebc-8804-ebd82a677aea';
    $pane = new stdClass();
    $pane->pid = 'new-209cf47b-fd4c-4102-843e-794a40a7858e';
    $pane->panel = 'middle';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
      'css_class' => 'help-tabs',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '209cf47b-fd4c-4102-843e-794a40a7858e';
    $display->content['new-209cf47b-fd4c-4102-843e-794a40a7858e'] = $pane;
    $display->panels['middle'][2] = 'new-209cf47b-fd4c-4102-843e-794a40a7858e';
    $pane = new stdClass();
    $pane->pid = 'new-ea2fdee4-678e-4b82-9187-461522a1014f';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_help-custom_new_functionality_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'new-content-button',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ea2fdee4-678e-4b82-9187-461522a1014f';
    $display->content['new-ea2fdee4-678e-4b82-9187-461522a1014f'] = $pane;
    $display->panels['middle'][3] = 'new-ea2fdee4-678e-4b82-9187-461522a1014f';
    $pane = new stdClass();
    $pane->pid = 'new-c3abdaf0-9a80-4a94-9a12-b08e047dec1f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'new_functionalities-panel_pane_new_functionalities_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c3abdaf0-9a80-4a94-9a12-b08e047dec1f';
    $display->content['new-c3abdaf0-9a80-4a94-9a12-b08e047dec1f'] = $pane;
    $display->panels['middle'][4] = 'new-c3abdaf0-9a80-4a94-9a12-b08e047dec1f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['new_functionalities'] = $page;

  return $pages;

}
