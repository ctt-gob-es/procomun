<?php
/**
 * @file
 * Views hooks for the ag_section_social_netwok feature.
 */

/**
* Implements hook_views_default_views_alter()
* Alters OG view "og_members_admin", in order to filter by Name and Surname instead of username.
* Username is still shown as field, as format_username is correctly called to show them.
* This hook does not need to be placed on modulename.views_default.inc, according to DrupalAPI.
*/
function ag_section_social_netwok_views_default_views_alter(&$views) {
  if (array_key_exists('og_members_admin', $views)) {
    $handler = &$views['og_members_admin']->display['default']->handler;

    // Relación: Usuario: Perfil
    $handler->display->display_options['relationships']['profile']['id'] = 'profile';
    $handler->display->display_options['relationships']['profile']['table'] = 'users';
    $handler->display->display_options['relationships']['profile']['field'] = 'profile';
    $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
      'datos_personales' => 'datos_personales',
    );

    // Relación: Perfil: Nombre y Apellidos (field_name_surname)
    $handler->display->display_options['relationships']['field_name_surname_value']['id'] = 'field_name_surname_value';
    $handler->display->display_options['relationships']['field_name_surname_value']['table'] = 'field_data_field_name_surname';
    $handler->display->display_options['relationships']['field_name_surname_value']['field'] = 'field_name_surname_value';
    $handler->display->display_options['relationships']['field_name_surname_value']['relationship'] = 'profile';
    $handler->display->display_options['relationships']['field_name_surname_value']['label'] = 'Nombre y apellidos';
    $handler->display->display_options['relationships']['field_name_surname_value']['delta'] = '-1';

    // Field: User: Name
    $handler->display->display_options['fields']['name']['label'] = 'Nombre y apellidos';

    /* Criterios de filtrado: Field collection item: Nombre (field_profile_name) */
    $handler->display->display_options['filters']['field_profile_name_value']['id'] = 'field_profile_name_value';
    $handler->display->display_options['filters']['field_profile_name_value']['table'] = 'field_data_field_profile_name';
    $handler->display->display_options['filters']['field_profile_name_value']['field'] = 'field_profile_name_value';
    $handler->display->display_options['filters']['field_profile_name_value']['relationship'] = 'field_name_surname_value';
    $handler->display->display_options['filters']['field_profile_name_value']['operator'] = 'starts';
    $handler->display->display_options['filters']['field_profile_name_value']['group'] = 1;
    $handler->display->display_options['filters']['field_profile_name_value']['exposed'] = TRUE;
    $handler->display->display_options['filters']['field_profile_name_value']['expose']['operator_id'] = 'field_profile_name_value_op';
    $handler->display->display_options['filters']['field_profile_name_value']['expose']['label'] = 'Nombre';
    $handler->display->display_options['filters']['field_profile_name_value']['expose']['operator'] = 'field_profile_name_value_op';
    $handler->display->display_options['filters']['field_profile_name_value']['expose']['identifier'] = 'field_profile_name_value';
    $handler->display->display_options['filters']['field_profile_name_value']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );
    /* Criterios de filtrado: Field collection item: Apellidos (field_profile_surname) */
    $handler->display->display_options['filters']['field_profile_surname_value']['id'] = 'field_profile_surname_value';
    $handler->display->display_options['filters']['field_profile_surname_value']['table'] = 'field_data_field_profile_surname';
    $handler->display->display_options['filters']['field_profile_surname_value']['field'] = 'field_profile_surname_value';
    $handler->display->display_options['filters']['field_profile_surname_value']['relationship'] = 'field_name_surname_value';
    $handler->display->display_options['filters']['field_profile_surname_value']['operator'] = 'contains';
    $handler->display->display_options['filters']['field_profile_surname_value']['group'] = 1;
    $handler->display->display_options['filters']['field_profile_surname_value']['exposed'] = TRUE;
    $handler->display->display_options['filters']['field_profile_surname_value']['expose']['operator_id'] = 'field_profile_surname_value_op';
    $handler->display->display_options['filters']['field_profile_surname_value']['expose']['label'] = 'Apellidos';
    $handler->display->display_options['filters']['field_profile_surname_value']['expose']['operator'] = 'field_profile_surname_value_op';
    $handler->display->display_options['filters']['field_profile_surname_value']['expose']['identifier'] = 'field_profile_surname_value';
    $handler->display->display_options['filters']['field_profile_surname_value']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
    );

    //Remove uid/username filter.
    unset($handler->display->display_options['filters']['uid']);
  }
}