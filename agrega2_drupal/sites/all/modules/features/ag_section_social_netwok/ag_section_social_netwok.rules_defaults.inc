<?php
/**
 * @file
 * ag_section_social_netwok.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ag_section_social_netwok_default_rules_configuration() {
  $items = array();
  $items['rules_community_creation'] = entity_import('rules_config', '{ "rules_community_creation" : {
      "LABEL" : "Community creation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--social_network" : { "bundle" : "social_network" } },
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "node:author" ], "roles" : { "value" : { "3" : "3" } } } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "A user has requested the creation of a new community",
            "message" : "The user [node:author] has requested the creation of a new community called [node:title]"
          }
        }
      ]
    }
  }');
  return $items;
}
