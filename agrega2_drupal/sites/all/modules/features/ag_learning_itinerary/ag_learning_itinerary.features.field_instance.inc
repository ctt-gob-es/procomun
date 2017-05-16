<?php
/**
 * @file
 * ag_learning_itinerary.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ag_learning_itinerary_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-itinerary-body'
  $field_instances['node-itinerary-body'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 1,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 50,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'words',
        ),
        'type' => 'smart_trim_format',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 1,
          'more_text' => 'Read more',
          'summary_handler' => 'full',
          'trim_length' => 50,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'words',
        ),
        'type' => 'smart_trim_format',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'smart_trim',
        'settings' => array(
          'more_link' => 1,
          'more_text' => 'Open learning path',
          'summary_handler' => 'full',
          'trim_length' => 50,
          'trim_link' => 0,
          'trim_options' => array(
            'text' => 0,
          ),
          'trim_preserve_tags' => '',
          'trim_suffix' => '...',
          'trim_type' => 'words',
        ),
        'type' => 'smart_trim_format',
        'weight' => 2,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Descripción',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_base_itinerary'
  $field_instances['node-itinerary-field_base_itinerary'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_base_itinerary',
    'label' => 'Itinerario base',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'hide',
          'action_on_edit' => 1,
          'fallback' => 'hide',
          'providers' => array(
            'node' => 0,
            'og_context' => 0,
            'url' => 1,
            'user' => 0,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_interest_content'
  $field_instances['node-itinerary-field_interest_content'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_interest_content',
    'label' => 'Otros recursos de interés',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_itinerary_content'
  $field_instances['node-itinerary-field_itinerary_content'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_itinerary_content',
    'label' => 'Recursos del itinerario',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_knowledge_area'
  $field_instances['node-itinerary-field_knowledge_area'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_knowledge_area',
    'label' => 'Área de conocimiento',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_labels'
  $field_instances['node-itinerary-field_labels'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'module' => 'shs',
        'settings' => array(
          'linked' => FALSE,
        ),
        'type' => 'shs_default',
        'weight' => 2,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'module' => 'shs',
        'settings' => array(
          'linked' => FALSE,
        ),
        'type' => 'shs_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'shs',
        'settings' => array(
          'linked' => FALSE,
        ),
        'type' => 'shs_default',
        'weight' => 3,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_labels',
    'label' => 'Etiquetas',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_learning_context'
  $field_instances['node-itinerary-field_learning_context'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_learning_context',
    'label' => 'Contexto educativo',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_question_share'
  $field_instances['node-itinerary-field_question_share'] = array(
    'bundle' => 'itinerary',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_question_share',
    'label' => 'Permitir que otros lo compartan',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-itinerary-field_solrid'
  $field_instances['node-itinerary-field_solrid'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_solrid',
    'label' => 'solrID',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_hidden',
      'settings' => array(),
      'type' => 'field_hidden',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-itinerary-og_group_ref'
  $field_instances['node-itinerary-og_group_ref'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'ag_general',
        'settings' => array(),
        'type' => 'ag2_og_list_default',
        'weight' => 9,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'ag_general',
        'settings' => array(),
        'type' => 'ag2_og_list_default',
        'weight' => 0,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Comunidades en que se publicará',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'access_override' => 0,
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'none',
          'action_on_edit' => 0,
          'fallback' => 'none',
          'providers' => array(
            'node' => 0,
            'og_context' => 0,
            'url' => 1,
            'user' => 0,
          ),
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(),
      'type' => 'og_complex',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-itinerary-title_field'
  $field_instances['node-itinerary-title_field'] = array(
    'bundle' => 'itinerary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'activities' => array(
        'label' => 'above',
        'module' => 'title',
        'settings' => array(
          'title_class' => 'title',
          'title_link' => 'content',
          'title_style' => 'h2',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => '',
          'title_link' => '',
          'title_style' => '',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'lasts' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'listing' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'newsletter' => array(
        'label' => 'above',
        'module' => 'title',
        'settings' => array(
          'title_class' => 'title',
          'title_link' => 'content',
          'title_style' => 'h2',
        ),
        'type' => 'title_linked',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'title',
        'settings' => array(
          'title_class' => 'title',
          'title_link' => 'content',
          'title_style' => 'h2',
        ),
        'type' => 'title_linked',
        'weight' => 1,
      ),
      'upcoming_events' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'title_field',
    'label' => 'Título',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'hide_label' => array(
        'entity' => 0,
        'page' => 0,
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comunidades en que se publicará');
  t('Contexto educativo');
  t('Descripción');
  t('Etiquetas');
  t('Itinerario base');
  t('Otros recursos de interés');
  t('Permitir que otros lo compartan');
  t('Recursos del itinerario');
  t('Título');
  t('solrID');
  t('Área de conocimiento');

  return $field_instances;
}
