<?php
/**
 * @file
 * ag_section_profile_users.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ag_section_profile_users_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'public_profile';
  $page->task = 'page';
  $page->admin_title = 'Public profile';
  $page->admin_description = 'The user\'s public profile';
  $page->path = 'profile/%uid/public';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'uid' => array(
      'id' => 1,
      'identifier' => 'Usuario: ID',
      'name' => 'entity_id:user',
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
  $handler->name = 'page_public_profile_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'public_profile';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Public profile panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-user',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'active_user',
          'settings' => NULL,
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'ag-3up-6-3';
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
  $display->title = '%uid:name';
  $display->uuid = '3af54719-b6ab-4f85-a201-de591d394cd4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f0f7bae4-df47-49c5-a110-2425fc711726';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'user';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'view_mode' => 'public',
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = 'f0f7bae4-df47-49c5-a110-2425fc711726';
    $display->content['new-f0f7bae4-df47-49c5-a110-2425fc711726'] = $pane;
    $display->panels['middle'][0] = 'new-f0f7bae4-df47-49c5-a110-2425fc711726';
    $pane = new stdClass();
    $pane->pid = 'new-32f362a5-b2e8-4daf-966b-7d0af30b4659';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_profiles-panel_pane_1';
    $pane->shown = FALSE;
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
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '32f362a5-b2e8-4daf-966b-7d0af30b4659';
    $display->content['new-32f362a5-b2e8-4daf-966b-7d0af30b4659'] = $pane;
    $display->panels['middle'][1] = 'new-32f362a5-b2e8-4daf-966b-7d0af30b4659';
    $pane = new stdClass();
    $pane->pid = 'new-033c54f3-bde1-416d-926a-dc07a4b3a892';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_profile_users-follow_user_block';
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
          'not' => TRUE,
        ),
      ),
    );
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
    $pane->uuid = '033c54f3-bde1-416d-926a-dc07a4b3a892';
    $display->content['new-033c54f3-bde1-416d-926a-dc07a4b3a892'] = $pane;
    $display->panels['right'][0] = 'new-033c54f3-bde1-416d-926a-dc07a4b3a892';
    $pane = new stdClass();
    $pane->pid = 'new-bc0cb16e-e8ff-4320-8433-796a2cca38f7';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'ag_section_profile_users-send_private_message';
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
          'not' => TRUE,
        ),
      ),
    );
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bc0cb16e-e8ff-4320-8433-796a2cca38f7';
    $display->content['new-bc0cb16e-e8ff-4320-8433-796a2cca38f7'] = $pane;
    $display->panels['right'][1] = 'new-bc0cb16e-e8ff-4320-8433-796a2cca38f7';
    $pane = new stdClass();
    $pane->pid = 'new-9a8f22b0-cbfb-445c-9e1f-6553340bc333';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_social_networks-panel_pane_5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9a8f22b0-cbfb-445c-9e1f-6553340bc333';
    $display->content['new-9a8f22b0-cbfb-445c-9e1f-6553340bc333'] = $pane;
    $display->panels['right'][2] = 'new-9a8f22b0-cbfb-445c-9e1f-6553340bc333';
    $pane = new stdClass();
    $pane->pid = 'new-002d1ab5-c707-4e41-85f7-2dcbd0da90eb';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_1';
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
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '002d1ab5-c707-4e41-85f7-2dcbd0da90eb';
    $display->content['new-002d1ab5-c707-4e41-85f7-2dcbd0da90eb'] = $pane;
    $display->panels['right'][3] = 'new-002d1ab5-c707-4e41-85f7-2dcbd0da90eb';
    $pane = new stdClass();
    $pane->pid = 'new-e892a00f-2b18-4b0d-9678-ab88e2163a9f';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_follows-panel_pane_2';
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
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e892a00f-2b18-4b0d-9678-ab88e2163a9f';
    $display->content['new-e892a00f-2b18-4b0d-9678-ab88e2163a9f'] = $pane;
    $display->panels['right'][4] = 'new-e892a00f-2b18-4b0d-9678-ab88e2163a9f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_public_profile_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'public_profile';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-user',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'ag-3up-6-3';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '12b2b413-ce4d-49a3-88cc-5f4f3e6714f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d6c266a7-013d-4f1e-934c-3f380324b604';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'user';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'public',
      'context' => 'argument_entity_id:user_1',
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
    $pane->uuid = 'd6c266a7-013d-4f1e-934c-3f380324b604';
    $display->content['new-d6c266a7-013d-4f1e-934c-3f380324b604'] = $pane;
    $display->panels['middle'][0] = 'new-d6c266a7-013d-4f1e-934c-3f380324b604';
    $pane = new stdClass();
    $pane->pid = 'new-1166226e-8458-4018-963f-832683f1cee4';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'agrega2_profiles-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1166226e-8458-4018-963f-832683f1cee4';
    $display->content['new-1166226e-8458-4018-963f-832683f1cee4'] = $pane;
    $display->panels['middle'][1] = 'new-1166226e-8458-4018-963f-832683f1cee4';
    $pane = new stdClass();
    $pane->pid = 'new-ce3620f3-af31-4b0d-914b-1343787f9029';
    $pane->panel = 'right';
    $pane->type = 'communities_per_organization';
    $pane->subtype = 'communities_per_organization';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce3620f3-af31-4b0d-914b-1343787f9029';
    $display->content['new-ce3620f3-af31-4b0d-914b-1343787f9029'] = $pane;
    $display->panels['right'][0] = 'new-ce3620f3-af31-4b0d-914b-1343787f9029';
    $pane = new stdClass();
    $pane->pid = 'new-cbbbac3c-f5c9-4aa6-b12a-a0e08dcac7ba';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'users_organization-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'style-common',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cbbbac3c-f5c9-4aa6-b12a-a0e08dcac7ba';
    $display->content['new-cbbbac3c-f5c9-4aa6-b12a-a0e08dcac7ba'] = $pane;
    $display->panels['right'][1] = 'new-cbbbac3c-f5c9-4aa6-b12a-a0e08dcac7ba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['public_profile'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_drafts';
  $page->task = 'page';
  $page->admin_title = 'User drafts';
  $page->admin_description = 'Sección de borradores de un usuario';
  $page->path = 'user/draft';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
  $handler->name = 'page_user_drafts__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_drafts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Mis borradores',
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
  $display->title = 'Mis borradores';
  $display->uuid = 'da2cf451-1984-467b-96c1-ae41f5b70d67';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4e716a99-5a86-4ef7-974f-363863808d09';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_draft-panel_pane_1';
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
    $pane->uuid = '4e716a99-5a86-4ef7-974f-363863808d09';
    $display->content['new-4e716a99-5a86-4ef7-974f-363863808d09'] = $pane;
    $display->panels['middle'][0] = 'new-4e716a99-5a86-4ef7-974f-363863808d09';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_drafts'] = $page;

  return $pages;

}
