<?php
/**
 * @file
 * ag_section_profile_users.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ag_section_profile_users_default_rules_configuration() {
  $items = array();
  $items['rules_user_login_redirect'] = entity_import('rules_config', '{ "rules_user_login_redirect" : {
      "LABEL" : "User login redirect (Spanish)",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "agregados_profile" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "account:language" ], "value" : "es" } },
        { "NOT user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ],
      "DO" : [ { "redirect" : { "url" : "user\\/[account:uid]\\/timeline" } } ]
    }
  }');
  return $items;
}
