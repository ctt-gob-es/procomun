<?php
/**
 * @file
 * ag_visualization_ode.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ag_visualization_ode_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_author_vcard|field_collection_item|field_contribuciones_ode|form';
  $field_group->group_name = 'group_author_vcard';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_contribuciones_ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author data',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Author data',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-author-vcard field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_author_vcard|field_collection_item|field_contribuciones_ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_clasificacion|node|ode|form';
  $field_group->group_name = 'group_clasificacion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Classification',
    'weight' => '13',
    'children' => array(
      0 => 'field_arbol_curricular',
      1 => 'field_nivel_educativo',
      2 => 'field_accesibilidad',
      3 => 'field_competencias',
      4 => 'field_knowledge_area',
      5 => 'field_learning_context',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Classification',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-clasificacion field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_clasificacion|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_destinatario_recurso|node|ode|form';
  $field_group->group_name = 'group_destinatario_recurso';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Addressee and application range',
    'weight' => '15',
    'children' => array(
      0 => 'field_agrupacion_de_alumnos',
      1 => 'field_destinatarios',
      2 => 'field_lugar_de_utilizaci_n',
      3 => 'field_modalidad_de_uso',
      4 => 'field_educational_language',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Addressee and application range',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-destinatario-recurso field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_destinatario_recurso|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_didactic_objectives|node|ode|form';
  $field_group->group_name = 'group_didactic_objectives';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Didactic objectives',
    'weight' => '5',
    'children' => array(
      0 => 'field_objetivos_did_cticos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Didactic objectives',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-didactic-objectives field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_didactic_objectives|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_license|node|ode|form';
  $field_group->group_name = 'group_license';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'License',
    'weight' => '12',
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
  $export['group_license|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other_license|node|ode|form';
  $field_group->group_name = 'group_other_license';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_license';
  $field_group->data = array(
    'label' => 'Choose another license',
    'weight' => '38',
    'children' => array(
      0 => 'field_allow_modifications',
      1 => 'field_comercial_use',
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
  $export['group_other_license|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prior_knowledge|node|ode|form';
  $field_group->group_name = 'group_prior_knowledge';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Prior knowledge',
    'weight' => '4',
    'children' => array(
      0 => 'field_conocimiento_previo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Prior knowledge',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-prior-knowledge field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_prior_knowledge|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tipo_de_recurso|node|ode|form';
  $field_group->group_name = 'group_tipo_de_recurso';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Resource type',
    'weight' => '14',
    'children' => array(
      0 => 'field_recurso_de_aprendizaje',
      1 => 'field_recurso_educativo',
      2 => 'field_resource_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Resource type',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-tipo-de-recurso field-group-fieldset',
        'description' => 'Please select at least an item from these fields below and no more than one option for each field.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_tipo_de_recurso|node|ode|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_vcard|field_collection_item|field_contribuciones_ode|form';
  $field_group->group_name = 'group_user_vcard';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_contribuciones_ode';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Author data',
    'weight' => '1',
    'children' => array(
      0 => 'field_correo_electr_nico',
      1 => 'field_organizaci_n',
      2 => 'field_contribuidor',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Author data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-user-vcard field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_vcard|field_collection_item|field_contribuciones_ode|form'] = $field_group;

  return $export;
}
