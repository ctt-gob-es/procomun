<?php
/**
 * @file
 * ag_section_questions_answers.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ag_section_questions_answers_default_rules_configuration() {
  $items = array();
  $items['rules_rule_node_abuse'] = entity_import('rules_config', '{ "rules_rule_node_abuse" : {
      "LABEL" : "Rule for node abuse",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : { "flag_flagged_abuse_node" : [] },
      "IF" : [
        { "flag_flagged_node" : {
            "flag" : [ "flag" ],
            "node" : [ "flagging-user:flag-abuse-node-flagged:0" ],
            "flagging_user" : [ "flagging_user" ]
          }
        }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "New reported item as inappropiate",
            "message" : "The item [flagged-node:url] has been reported as inappropiated by [flagging-user:name] ([flagging-user:url])",
            "from" : "[site:mail]"
          }
        }
      ]
    }
  }');
  return $items;
}
