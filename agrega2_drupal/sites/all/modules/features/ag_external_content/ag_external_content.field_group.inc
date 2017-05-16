<?php
/**
 * @file
 * ag_external_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ag_external_content_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_license|node|external_content|form';
  $field_group->group_name = 'group_license';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'external_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Licencia',
    'weight' => '3',
    'children' => array(
      0 => 'field_original_author',
      1 => 'field_comercial_use',
      2 => 'field_allow_modifications',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Licencia',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-license field-group-fieldset',
        'description' => 'Procomún offers its users the possibility of licensing the content they provide and they are authors under a Creative Commons license. With a Creative Commons license, you keep your copyright but allow others <a href="http://creativecommons.org/licenses/?lang=es_ES">to copy and share your work</a>, provided that <a href="http://creativecommons.org/choose/?lang=es_ES">they recognize the corresponding authorship</a> and only under the conditions you specify here.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_license|node|external_content|form'] = $field_group;

  return $export;
}
