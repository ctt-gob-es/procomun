<?php
/**
 * @file
 * ag_general.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function ag_general_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'about';
  $path_breadcrumb->name = 'About';
  $path_breadcrumb->path = 'node/33';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -100;
  $export['about'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'add_content';
  $path_breadcrumb->name = 'Add content';
  $path_breadcrumb->path = 'node/add/%name';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agregar contenido',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'name' => array(
        'position' => 2,
        'argument' => 'node_add',
        'settings' => array(
          'identifier' => 'Node add form: node type',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'external_content' => 'external_content',
              'itinerary' => 'itinerary',
              'event' => 'event',
              'functionality' => 'functionality',
              'manual' => 'manual',
              'podcast' => 'podcast',
              'post' => 'post',
              'answer' => 'answer',
              'debate' => 'debate',
              'question' => 'question',
              'social_network' => 'social_network',
              'webinar' => 'webinar',
              'ode' => 'ode',
              'poll' => 'poll',
              'page' => 'page',
            ),
          ),
          'context' => 'name',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['add_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'add_ode';
  $path_breadcrumb->name = 'Add ODE';
  $path_breadcrumb->path = 'ode/add';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Agregar contenido',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -99;
  $export['add_ode'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ayuda_landing';
  $path_breadcrumb->name = 'Ayuda - Landing';
  $path_breadcrumb->path = 'help';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Ayuda',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -35;
  $export['ayuda_landing'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ayuda_manual';
  $path_breadcrumb->name = 'Ayuda - Manual';
  $path_breadcrumb->path = 'help/manual';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Ayuda',
      1 => 'Manual de uso',
    ),
    'paths' => array(
      0 => 'help',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -37;
  $export['ayuda_manual'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'blocked_users';
  $path_breadcrumb->name = 'Notifications and blocked users';
  $path_breadcrumb->path = 'messages/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Notificaciones y mensajes',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -97;
  $export['blocked_users'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'cancel_user_account';
  $path_breadcrumb->name = 'Cancel user account';
  $path_breadcrumb->path = 'user/%uid/cancel';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Cancelar cuenta de usuario',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -95;
  $export['cancel_user_account'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'community_about_page';
  $path_breadcrumb->name = 'Community about page';
  $path_breadcrumb->path = 'node/%node/about';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Acerca de',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['community_about_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center';
  $path_breadcrumb->name = 'Control center';
  $path_breadcrumb->path = 'admin/control-center';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -93;
  $export['control_center'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_administer_communities';
  $path_breadcrumb->name = 'Control center - Administer communities';
  $path_breadcrumb->path = 'admin/control-center/communities';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Administrar comunidades',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -92;
  $export['control_center_administer_communities'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_administer_content';
  $path_breadcrumb->name = 'Control center - Administer content';
  $path_breadcrumb->path = 'admin/control-center/content';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Administrar contenido',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -91;
  $export['control_center_administer_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_administer_organization_members';
  $path_breadcrumb->name = 'Control center - Administer organization members';
  $path_breadcrumb->path = 'admin/control-center/users/organization-members';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Administrar miembros de una organización',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -89;
  $export['control_center_administer_organization_members'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_administer_organizations';
  $path_breadcrumb->name = 'Control center - Administer organizations';
  $path_breadcrumb->path = 'admin/control-center/users/organizations';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Administrar organizaciones',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -90;
  $export['control_center_administer_organizations'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_administer_users';
  $path_breadcrumb->name = 'Control center - Administer users';
  $path_breadcrumb->path = 'admin/control-center/users';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Administrar usuarios',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -88;
  $export['control_center_administer_users'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_communities_reports';
  $path_breadcrumb->name = 'Control center - Communities reports';
  $path_breadcrumb->path = 'admin/control-center/reports/communities-report';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Informe comunidades',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -84;
  $export['control_center_communities_reports'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_pending_communities';
  $path_breadcrumb->name = 'Control center - Pending communities';
  $path_breadcrumb->path = 'admin/control-center/communities/pending';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Administrar comunidades',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -87;
  $export['control_center_pending_communities'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'control_center_procomun_reports';
  $path_breadcrumb->name = 'Control center - Procomun reports';
  $path_breadcrumb->path = 'admin/control-center/reports';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Centro de control',
      1 => 'Informe global',
    ),
    'paths' => array(
      0 => 'admin/control-center',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -83;
  $export['control_center_procomun_reports'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'debates';
  $path_breadcrumb->name = 'Debates';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Debates',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=DISCUSSION',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'debate' => 'debate',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -82;
  $export['debates'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'edit_account';
  $path_breadcrumb->name = 'Edit account';
  $path_breadcrumb->path = 'user/%uid/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mi perfil',
      1 => 'Editar cuenta',
    ),
    'paths' => array(
      0 => 'user',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -81;
  $export['edit_account'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'edit_community';
  $path_breadcrumb->name = 'Edit community';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Editar',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -79;
  $export['edit_community'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'edit_cv';
  $path_breadcrumb->name = 'Edit cv';
  $path_breadcrumb->path = 'user/%uid/edit/cv';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mi perfil',
      1 => 'Editar CV',
    ),
    'paths' => array(
      0 => 'user',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -78;
  $export['edit_cv'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'edit_group';
  $path_breadcrumb->name = 'Edit group';
  $path_breadcrumb->path = 'node/%node/group';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Editar grupo',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -80;
  $export['edit_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'edit_organization';
  $path_breadcrumb->name = 'Edit organization details';
  $path_breadcrumb->path = 'user/%uid/edit/datos_organizacion';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%uid:name',
      1 => 'Editar',
    ),
    'paths' => array(
      0 => 'profile/%uid:uid/public',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['edit_organization'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'edit_personal_data';
  $path_breadcrumb->name = 'Edit personal data';
  $path_breadcrumb->path = 'user/%uid/edit/datos_personales';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mi perfil',
      1 => 'Editar datos personales',
    ),
    'paths' => array(
      0 => 'user',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -76;
  $export['edit_personal_data'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'events';
  $path_breadcrumb->name = 'Events';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Eventos',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=EVENT',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'event' => 'event',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -77;
  $export['events'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'external_content';
  $path_breadcrumb->name = 'External content';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contenidos externos',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=URL',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'external_content' => 'external_content',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -65;
  $export['external_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'help_faq';
  $path_breadcrumb->name = 'Ayuda - Preguntas frecuentes';
  $path_breadcrumb->path = 'help/faq';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Ayuda',
      1 => 'Preguntas frecuentes',
    ),
    'paths' => array(
      0 => 'help',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -85;
  $export['help_faq'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'help_new_functionalities';
  $path_breadcrumb->name = 'Ayuda - Nuevas funcionalidades';
  $path_breadcrumb->path = 'help/functionality';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Ayuda',
      1 => 'Nuevas funcionalidades',
    ),
    'paths' => array(
      0 => 'help',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -86;
  $export['help_new_functionalities'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'help_search';
  $path_breadcrumb->name = 'Ayuda - Buscador';
  $path_breadcrumb->path = 'help/search';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Ayuda',
      1 => 'Buscar en la ayuda',
    ),
    'paths' => array(
      0 => 'help',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -34;
  $export['help_search'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'itineraries';
  $path_breadcrumb->name = 'Itineraries';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Itinerarios de aprendizaje',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?query=&amp;type=LEARNING_PATH',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Contenido: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'itinerary' => 'itinerary',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['itineraries'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'learning_resource';
  $path_breadcrumb->name = 'Learning resource';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Recursos de aprendizaje - %node:title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'recurso_de_aprendizaje' => 'recurso_de_aprendizaje',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -72;
  $export['learning_resource'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'login_clave';
  $path_breadcrumb->name = 'Login - Clave';
  $path_breadcrumb->path = 'login/clave';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Autenticación con Cl@ve',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['login_clave'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'messages';
  $path_breadcrumb->name = 'Messages';
  $path_breadcrumb->path = 'messages';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Notificaciones y mensajes',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -98;
  $export['messages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'my_drafts';
  $path_breadcrumb->name = 'Mis borradores';
  $path_breadcrumb->path = 'user/draft';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis borradores',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -86;
  $export['my_drafts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'my_profile';
  $path_breadcrumb->name = 'My profile';
  $path_breadcrumb->path = 'user/%uid';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mi perfil',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -71;
  $export['my_profile'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'new_message';
  $path_breadcrumb->name = 'New message';
  $path_breadcrumb->path = 'messages/new';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mensajes',
      1 => 'Nuevo mensaje',
    ),
    'paths' => array(
      0 => 'messages',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -70;
  $export['new_message'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'newsletter_edit';
  $path_breadcrumb->name = 'Newsletter edit';
  $path_breadcrumb->path = 'node/%node/ag_section_newsletter/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:og-group-ref:0:title',
      2 => 'Administrar boletines',
      3 => '%node:title-field',
      4 => '!page_title',
    ),
    'paths' => array(
      0 => 'ode-search?query=&amp;type=COMMUNITYauto=',
      1 => '%node:og-group-ref:0:url',
      2 => 'ag_section_newsletter/%node:og-group-ref:0:nid/simplenews',
      3 => '%node:url',
      4 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'simplenews' => 'simplenews',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -74;
  $export['newsletter_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'newsletter_unsubscription';
  $path_breadcrumb->name = 'Newsletter unsubscription';
  $path_breadcrumb->path = 'newsletter/confirm/remove/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Darse de baja del boletín de noticias',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -97;
  $export['newsletter_unsubscription'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'newsletter_view';
  $path_breadcrumb->name = 'Newsletter view';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:og-group-ref:0:title',
      2 => 'Administrar boletines',
      3 => '!page_title',
    ),
    'paths' => array(
      0 => 'ode-search?query=&amp;type=COMMUNITYauto=',
      1 => '%node:og-group-ref:0:url',
      2 => 'ag_section_newsletter/%node:og-group-ref:0:nid/simplenews',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'simplenews' => 'simplenews',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -75;
  $export['newsletter_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'podcasts';
  $path_breadcrumb->name = 'Podcasts';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Podcasts',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?query=&amp;type=PODCAST',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Contenido: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'podcast' => 'podcast',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['podcasts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'polls';
  $path_breadcrumb->name = 'Polls';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Encuestas',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=POLL',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'poll' => 'poll',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -69;
  $export['polls'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'posts';
  $path_breadcrumb->name = 'Posts';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Artículos',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=POST',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'post' => 'post',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -68;
  $export['posts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'privacy_policy';
  $path_breadcrumb->name = 'Privacy policy';
  $path_breadcrumb->path = 'node/2';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -67;
  $export['privacy_policy'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'public_profile';
  $path_breadcrumb->name = 'Public profile';
  $path_breadcrumb->path = 'profile/%uid/public';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Perfil público - %uid:name',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -66;
  $export['public_profile'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'publish_content_confirm';
  $path_breadcrumb->name = 'Publish content confirm';
  $path_breadcrumb->path = 'node/%node/status/publish';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['publish_content_confirm'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'questions';
  $path_breadcrumb->name = 'Questions';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Preguntas',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=QUESTION',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'question' => 'question',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -65;
  $export['questions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'recover_password';
  $path_breadcrumb->name = 'Recover password';
  $path_breadcrumb->path = 'user/password';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Recuperar contraseña',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -63;
  $export['recover_password'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'responses';
  $path_breadcrumb->name = 'Responses';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Respuestas',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'answer' => 'answer',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -64;
  $export['responses'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search';
  $path_breadcrumb->name = 'Search';
  $path_breadcrumb->path = 'ode-search';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Buscador',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -62;
  $export['search'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_answers';
  $path_breadcrumb->name = 'Search answers';
  $path_breadcrumb->path = 'RESPONSE';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Respuestas',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -61;
  $export['search_answers'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_communities';
  $path_breadcrumb->name = 'Search communities';
  $path_breadcrumb->path = 'COMMUNITY';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -60;
  $export['search_communities'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_debates';
  $path_breadcrumb->name = 'Search debates';
  $path_breadcrumb->path = 'DISCUSSION';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Debates',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -59;
  $export['search_debates'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_events';
  $path_breadcrumb->name = 'Search events';
  $path_breadcrumb->path = 'EVENT';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Eventos',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -58;
  $export['search_events'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_external_content';
  $path_breadcrumb->name = 'Search external content';
  $path_breadcrumb->path = 'URL';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contenidos externos',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -56;
  $export['search_external_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_learning_resources';
  $path_breadcrumb->name = 'Search learning resources';
  $path_breadcrumb->path = 'LEARNING_RESOURCE';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Recursos de aprendizaje',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -57;
  $export['search_learning_resources'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_podcasts';
  $path_breadcrumb->name = 'Search podcasts';
  $path_breadcrumb->path = 'PODCAST';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Podcasts',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -56;
  $export['search_podcasts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_polls';
  $path_breadcrumb->name = 'Search polls';
  $path_breadcrumb->path = 'POLL';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Encuestas',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -55;
  $export['search_polls'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_posts';
  $path_breadcrumb->name = 'Search posts';
  $path_breadcrumb->path = 'POST';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Artículos',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -56;
  $export['search_posts'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_questions';
  $path_breadcrumb->name = 'Search questions';
  $path_breadcrumb->path = 'QUESTION';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Preguntas',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -54;
  $export['search_questions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search_users';
  $path_breadcrumb->name = 'Search users';
  $path_breadcrumb->path = 'USER';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Usuarios',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -53;
  $export['search_users'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network';
  $path_breadcrumb->name = 'Social network';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'ode-search?type=COMMUNITY',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -52;
  $export['social_network'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network_debates';
  $path_breadcrumb->name = 'Social network - Debates';
  $path_breadcrumb->path = 'node/%node/debates';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Preguntas y debates',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -51;
  $export['social_network_debates'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network_events';
  $path_breadcrumb->name = 'Social network - Events';
  $path_breadcrumb->path = 'node/%node/events';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Eventos',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -50;
  $export['social_network_events'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network_members';
  $path_breadcrumb->name = 'Social network - Members';
  $path_breadcrumb->path = 'node/%node/members';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Miembros',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -49;
  $export['social_network_members'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network_polls';
  $path_breadcrumb->name = 'Social network - Polls';
  $path_breadcrumb->path = 'node/%node/polls';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Encuestas',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -48;
  $export['social_network_polls'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network_subscribe';
  $path_breadcrumb->name = 'Social network - Subscribe';
  $path_breadcrumb->path = 'group/node/%node/subscribe';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Subscribirse',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -47;
  $export['social_network_subscribe'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'social_network_subscribe_clone';
  $path_breadcrumb->name = 'Social network - Unsubscribe';
  $path_breadcrumb->path = 'group/node/%node/unsubscribe';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Comunidades',
      1 => '%node:title',
      2 => 'Desinscribirse',
    ),
    'paths' => array(
      0 => 'ode-search?query=&type=COMMUNITY&auto=',
      1 => '%node:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Nodo: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'social_network' => 'social_network',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -46;
  $export['social_network_subscribe_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'terms_of_use';
  $path_breadcrumb->name = 'Terms of use';
  $path_breadcrumb->path = 'node/1';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -45;
  $export['terms_of_use'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_communities';
  $path_breadcrumb->name = 'User communities';
  $path_breadcrumb->path = 'user/%uid/my-communities';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis comunidades',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -44;
  $export['user_communities'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_favourites';
  $path_breadcrumb->name = 'User favourites';
  $path_breadcrumb->path = 'user/%uid/favourites';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis favoritos',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -43;
  $export['user_favourites'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_favourites_paged';
  $path_breadcrumb->name = 'User favourites paged';
  $path_breadcrumb->path = 'user/%uid/favourites/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis favoritos',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -43;
  $export['user_favourites_paged'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_learning_paths';
  $path_breadcrumb->name = 'User learning paths';
  $path_breadcrumb->path = 'user/%uid/learning-paths';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis itinerarios de aprendizaje',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -38;
  $export['user_learning_paths'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_login';
  $path_breadcrumb->name = 'User login';
  $path_breadcrumb->path = 'user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Iniciar sesión',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
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
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -42;
  $export['user_login'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_notifications';
  $path_breadcrumb->name = 'User notifications';
  $path_breadcrumb->path = 'user/%uid/notifications';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis notificaciones',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -41;
  $export['user_notifications'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_register';
  $path_breadcrumb->name = 'User register';
  $path_breadcrumb->path = 'user/register';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Registro de usuario',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -40;
  $export['user_register'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_subscriptions';
  $path_breadcrumb->name = 'User subscriptions';
  $path_breadcrumb->path = 'user/%uid/edit/simplenews';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mi perfil',
      1 => 'Suscripciones',
    ),
    'paths' => array(
      0 => 'user',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -39;
  $export['user_subscriptions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_timeline';
  $path_breadcrumb->name = 'User timeline';
  $path_breadcrumb->path = 'user/%uid/timeline';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis intereses',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -38;
  $export['user_timeline'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_timeline_paged';
  $path_breadcrumb->name = 'User timeline paged';
  $path_breadcrumb->path = 'user/%uid/timeline/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Mis intereses',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'uid' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Usuario: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -38;
  $export['user_timeline_paged'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'view_message';
  $path_breadcrumb->name = 'View message';
  $path_breadcrumb->path = 'messages/view/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Notificaciones y mensajes',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -96;
  $export['view_message'] = $path_breadcrumb;

  return $export;
}
