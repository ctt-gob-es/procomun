<?php
/**
 * @file
 * ag_section_newsletter.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_newsletter_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'create_newsletter';
  $page->task = 'page';
  $page->admin_title = 'Create newsletter';
  $page->admin_description = '';
  $page->path = 'node/%node/ag_section_newsletter/new';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_perm',
        'settings' => array(
          'perm' => 'administer og newsletter',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Nodo: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_create_newsletter__panel';
  $handler->task = 'page';
  $handler->subtask = 'create_newsletter';
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
  $display->title = 'Crear un nuevo boletín';
  $display->uuid = 'd1dfc312-7858-4454-95fc-8586c14dcf59';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6cee6e10-faec-4606-a072-5c4dffc2d979';
    $pane->panel = 'middle';
    $pane->type = 'newsletter_form';
    $pane->subtype = 'newsletter_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6cee6e10-faec-4606-a072-5c4dffc2d979';
    $display->content['new-6cee6e10-faec-4606-a072-5c4dffc2d979'] = $pane;
    $display->panels['middle'][0] = 'new-6cee6e10-faec-4606-a072-5c4dffc2d979';
    $pane = new stdClass();
    $pane->pid = 'new-841f0617-3515-43cc-809a-2ca197034ff1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_newsletter-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'newsletter-select-content',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '841f0617-3515-43cc-809a-2ca197034ff1';
    $display->content['new-841f0617-3515-43cc-809a-2ca197034ff1'] = $pane;
    $display->panels['middle'][1] = 'new-841f0617-3515-43cc-809a-2ca197034ff1';
    $pane = new stdClass();
    $pane->pid = 'new-565b5e89-43cc-4094-acda-4c67be1e7055';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_newsletter-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '565b5e89-43cc-4094-acda-4c67be1e7055';
    $display->content['new-565b5e89-43cc-4094-acda-4c67be1e7055'] = $pane;
    $display->panels['middle'][2] = 'new-565b5e89-43cc-4094-acda-4c67be1e7055';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['create_newsletter'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'edit_newsletter';
  $page->task = 'page';
  $page->admin_title = 'Edit newsletter';
  $page->admin_description = '';
  $page->path = 'node/%gid/ag_section_newsletter/%node/edit';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_perm',
        'settings' => array(
          'perm' => 'administer og newsletter',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_2',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'gid' => array(
      'id' => 2,
      'identifier' => 'Nodo: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'node' => array(
      'id' => 1,
      'identifier' => 'Nodo: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_edit_newsletter__panel_context_afe30b95-41d0-4002-a046-ec5489833f7f';
  $handler->task = 'page';
  $handler->subtask = 'edit_newsletter';
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
    'name' => '',
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
  $display->title = 'Editar boletín %node:title-field';
  $display->uuid = 'd1dfc312-7858-4454-95fc-8586c14dcf59';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6cee6e10-faec-4606-a072-5c4dffc2d979';
    $pane->panel = 'middle';
    $pane->type = 'newsletter_form';
    $pane->subtype = 'newsletter_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6cee6e10-faec-4606-a072-5c4dffc2d979';
    $display->content['new-6cee6e10-faec-4606-a072-5c4dffc2d979'] = $pane;
    $display->panels['middle'][0] = 'new-6cee6e10-faec-4606-a072-5c4dffc2d979';
    $pane = new stdClass();
    $pane->pid = 'new-245b6217-3e00-4854-b15b-4d5bff61f71a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_newsletter-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_2',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'newsletter-select-content',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '245b6217-3e00-4854-b15b-4d5bff61f71a';
    $display->content['new-245b6217-3e00-4854-b15b-4d5bff61f71a'] = $pane;
    $display->panels['middle'][1] = 'new-245b6217-3e00-4854-b15b-4d5bff61f71a';
    $pane = new stdClass();
    $pane->pid = 'new-9056af03-942c-4315-b294-2979ca79ab5e';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ag_newsletter-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_2',
      ),
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9056af03-942c-4315-b294-2979ca79ab5e';
    $display->content['new-9056af03-942c-4315-b294-2979ca79ab5e'] = $pane;
    $display->panels['middle'][2] = 'new-9056af03-942c-4315-b294-2979ca79ab5e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['edit_newsletter'] = $page;

  return $pages;

}
