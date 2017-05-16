<?php

/**
 * @file
 * Definition of ag_section_social_netwok_handler_community_type.
 */

/**
 * Description of what my handler does.
 */
class ag_section_social_netwok_handler_community_type_field extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['group_access'] = array(
      'table' => 'field_data_group_access',
      'field' => 'group_access_value',
    );
    $this->additional_fields['field_og_permissions_level'] = array(
      'table' => 'field_data_field_og_permissions_level',
      'field' => 'field_og_permissions_level_value',
    );
  }

  /**
   * Loads additional fields.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    // Get the values from the query:
    $group_access_value = $this->get_value($values, 'group_access');
    $og_permissions_level_value = $this->get_value($values, 'field_og_permissions_level');
    // By default its a private community:
    $type = t('Private');

    if ($group_access_value == 0) {
      if ($og_permissions_level_value == 1) {
        // Its restricted:
        $type = t('Restricted');
      }
      else {
        // Its public:
        $type = t('Public');
      }
    }

    return $type;
  }
}
