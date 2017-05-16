<?php
/**
 * @file
 * control_center_dashboard.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function control_center_dashboard_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'control_center_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Control center dashboard';
  $page->admin_description = 'Dashboard for control center landing page';
  $page->path = 'admin/control-center/';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center users',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center organizations',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center communities reports',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center procomun reports',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      4 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center contents',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      5 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access control center communities',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Dashboard',
    'name' => 'menu-control-center-main-menu',
    'weight' => '-1',
    'parent' => array(
      'type' => 'none',
      'title' => 'Dashboard',
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
  $handler->name = 'page_control_center_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'control_center_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'community-admin',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
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
  $display->title = '';
  $display->uuid = 'f9163f82-7ef5-4ee4-98b8-9c029549d612';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-12b9dc8b-51d5-47a5-80ae-3206e9f1683d';
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
    $pane->uuid = '12b9dc8b-51d5-47a5-80ae-3206e9f1683d';
    $display->content['new-12b9dc8b-51d5-47a5-80ae-3206e9f1683d'] = $pane;
    $display->panels['right'][0] = 'new-12b9dc8b-51d5-47a5-80ae-3206e9f1683d';
    $pane = new stdClass();
    $pane->pid = 'new-04a9e2f5-e5d3-48d5-adf5-3b70c47f325b';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Dashboard Information',
      'title' => 'Panel de control',
      'body' => '<p>Bienvenido al panel de control</p>

<p>En este panel podrás gestionar comunidades, contenidos y usuarios. Además, podrás ver los informes generados en el sistema. Desde los siguientes botones se accederán a todas estas funcionalidades:</p>

<ul>
	<li>Administrar comunidades: Desde aquí se podrán gestionar las comunidades creadas en Procomún así como la moderación de aquellas comunidades que los usuarios han solicitado crear.</li>
	<li>Administrar contenidos: Desde esta zona de gestión se podrán eliminar contentido, publicar y retirar contenido</li>
	<li>Administrar certificaciones: Desde esta zona se podrá ver la interacción de los usuarios con el contenido en función al número de "me gusta", comentarios, votos y visitas, así como ver los contenidos que han sido certificados y certificar o eliminar la certificación de los mismos en masa.</li>
	<li>Administrar usuarios: Esta es la zona de administración de los usuarios del portal. Desde aquí, los administradores podrán cancelar o bloquear usuarios</li>
	<li>Procomún Reports: Desde este apartado del panel de control se podrán generar los informes de Procomún y comunidades</li>
</ul>

<p>&nbsp;</p>

<p>Solo aquellos usuarios con permisos, podrán ver y acceder a cada una de las zonas de gestión.</p>
',
      'format' => 'rich_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '04a9e2f5-e5d3-48d5-adf5-3b70c47f325b';
    $display->content['new-04a9e2f5-e5d3-48d5-adf5-3b70c47f325b'] = $pane;
    $display->panels['right'][1] = 'new-04a9e2f5-e5d3-48d5-adf5-3b70c47f325b';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-12b9dc8b-51d5-47a5-80ae-3206e9f1683d';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['control_center_dashboard'] = $page;

  return $pages;

}
