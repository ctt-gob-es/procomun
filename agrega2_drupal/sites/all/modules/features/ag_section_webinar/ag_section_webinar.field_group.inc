<?php
/**
 * @file
 * ag_section_webinar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ag_section_webinar_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_license|node|webinar|form';
  $field_group->group_name = 'group_license';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webinar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'License',
    'weight' => '10',
    'children' => array(
      0 => 'group_other_license',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'License',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-license field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_license|node|webinar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other_license|node|webinar|form';
  $field_group->group_name = 'group_other_license';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webinar';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_license';
  $field_group->data = array(
    'label' => 'Choose another license',
    'weight' => '13',
    'children' => array(
      0 => 'field_allow_modifications',
      1 => 'field_comercial_use',
      2 => 'field_original_author',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Choose another license',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-other-license field-group-fieldset',
        'description' => 'Procomún offers its users the possibility of licensing the content they provide and they are authors under a Creative Commons license. With a Creative Commons license, you keep your copyright but allow others <a href="http://creativecommons.org/licenses/?lang=es_ES">to copy and share your work</a>, provided that <a href="http://creativecommons.org/choose/?lang=es_ES">they recognize the corresponding authorship</a> and only under the conditions you specify here.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_other_license|node|webinar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_webinar|node|webinar|form';
  $field_group->group_name = 'group_webinar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'webinar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Información del webinar',
    'weight' => '4',
    'children' => array(
      0 => 'field_webinar_date',
      1 => 'field_duracion',
      2 => 'field_record_webinar',
      3 => 'field_classid',
      4 => 'field_recording_url',
      5 => 'field_class_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-webinar field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_webinar|node|webinar|form'] = $field_group;

  return $export;
}
