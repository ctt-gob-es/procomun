<?php
/**
 * @file
 * ag_section_content_type_learning_resource.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ag_section_content_type_learning_resource_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_clasificacion|node|recurso_de_aprendizaje|form';
  $field_group->group_name = 'group_clasificacion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'recurso_de_aprendizaje';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Clasificación',
    'weight' => '10',
    'children' => array(
      0 => 'field_arbol_curricular',
      1 => 'field_nivel_educativo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-clasificacion field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_clasificacion|node|recurso_de_aprendizaje|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_destinatario_recurso|node|recurso_de_aprendizaje|form';
  $field_group->group_name = 'group_destinatario_recurso';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'recurso_de_aprendizaje';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Destinatario y Contexto',
    'weight' => '9',
    'children' => array(
      0 => 'field_agrupacion_de_alumnos',
      1 => 'field_destinatarios',
      2 => 'field_lugar_de_utilizaci_n',
      3 => 'field_modalidad_de_uso',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Destinatario y Contexto',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_destinatario_recurso|node|recurso_de_aprendizaje|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tipo_de_recurso|node|recurso_de_aprendizaje|form';
  $field_group->group_name = 'group_tipo_de_recurso';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'recurso_de_aprendizaje';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tipo de recurso',
    'weight' => '8',
    'children' => array(
      0 => 'field_recurso_educativo',
      1 => 'field_recurso_de_aprendizaje',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tipo-de-recurso field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tipo_de_recurso|node|recurso_de_aprendizaje|form'] = $field_group;

  return $export;
}
