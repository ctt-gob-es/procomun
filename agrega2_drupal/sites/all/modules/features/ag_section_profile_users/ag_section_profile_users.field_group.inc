<?php
/**
 * @file
 * ag_section_profile_users.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ag_section_profile_users_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experience_public|profile2|cv|public';
  $field_group->group_name = 'group_experience_public';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'public';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Experiencia Laboral',
    'weight' => '2',
    'children' => array(
      0 => 'field_experience_cv',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-experience-public field-group-fieldset',
      ),
    ),
  );
  $export['group_experience_public|profile2|cv|public'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experience_view|profile2|cv|default';
  $field_group->group_name = 'group_experience_view';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Experiencia Laboral',
    'weight' => '1',
    'children' => array(
      0 => 'field_experience_cv',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-experience-view field-group-fieldset',
      ),
    ),
  );
  $export['group_experience_view|profile2|cv|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experience|profile2|cv|form';
  $field_group->group_name = 'group_experience';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work experience',
    'weight' => '1',
    'children' => array(
      0 => 'field_experience_cv',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Work experience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-experience field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_experience|profile2|cv|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization|user|user|form';
  $field_group->group_name = 'group_organization';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organization',
    'weight' => '7',
    'children' => array(
      0 => 'field_organization_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Organization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-organization field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_organization|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data_public|profile2|cv|public';
  $field_group->group_name = 'group_personal_data_public';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'public';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datos Personales',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personal-data-public field-group-fieldset',
      ),
    ),
  );
  $export['group_personal_data_public|profile2|cv|public'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data_view|profile2|cv|default';
  $field_group->group_name = 'group_personal_data_view';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datos Personales',
    'weight' => '0',
    'children' => array(
      0 => 'field_current_position_cv',
      1 => 'field_degree_cv_fc',
      2 => 'field_educational_level_cv',
      3 => 'field_lang_level_cv_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personal-data-view field-group-fieldset',
      ),
    ),
  );
  $export['group_personal_data_view|profile2|cv|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data|profile2|cv|form';
  $field_group->group_name = 'group_personal_data';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Datos Personales',
    'weight' => '0',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-personal-data field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personal_data|profile2|cv|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profesional_skills_public|profile2|cv|public';
  $field_group->group_name = 'group_profesional_skills_public';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'public';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Formación Profesional',
    'weight' => '0',
    'children' => array(
      0 => 'field_additional_formation_cv_fc',
      1 => 'field_current_position_cv',
      2 => 'field_degree_cv_fc',
      3 => 'field_educational_level_cv',
      4 => 'field_lang_level_cv_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profesional-skills-public field-group-fieldset',
      ),
    ),
  );
  $export['group_profesional_skills_public|profile2|cv|public'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profesional_skills_view|profile2|cv|default';
  $field_group->group_name = 'group_profesional_skills_view';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Formación Profesional',
    'weight' => '0',
    'children' => array(
      0 => 'field_additional_formation_cv_fc',
      1 => 'field_current_position_cv',
      2 => 'field_degree_cv_fc',
      3 => 'field_educational_level_cv',
      4 => 'field_lang_level_cv_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profesional-skills-view field-group-fieldset',
      ),
    ),
  );
  $export['group_profesional_skills_view|profile2|cv|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profesional_skills|profile2|cv|form';
  $field_group->group_name = 'group_profesional_skills';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'cv';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vocational Training',
    'weight' => '0',
    'children' => array(
      0 => 'field_additional_formation_cv_fc',
      1 => 'field_current_position_cv',
      2 => 'field_degree_cv_fc',
      3 => 'field_educational_level_cv',
      4 => 'field_lang_level_cv_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vocational Training',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-profesional-skills field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_profesional_skills|profile2|cv|form'] = $field_group;

  return $export;
}
