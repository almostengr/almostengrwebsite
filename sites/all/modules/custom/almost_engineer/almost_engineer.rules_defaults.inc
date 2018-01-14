<?php
/**
 * @file
 * almost_engineer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function almost_engineer_default_rules_configuration() {
  $items = array();
  $items['rules_drupal_redirect_from_node'] = entity_import('rules_config', '{ "rules_drupal_redirect_from_node" : {
      "LABEL" : "DRUPAL: Redirect from \\/node",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "TAGS" : [ "drupal", "node", "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "init" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "site:current-page:path" ], "value" : "\\/node" } }
      ],
      "DO" : [ { "redirect" : { "url" : [ "site:url" ] } } ]
    }
  }');
  $items['rules_user_valid_login'] = entity_import('rules_config', '{ "rules_user_valid_login" : {
      "LABEL" : "USER: Initial Login",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "login", "nonvalid", "user" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "7" : "7" } } } }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "7" : "7" } } } },
        { "entity_save" : { "data" : [ "account" ] } },
        { "drupal_message" : { "message" : "Your account has been verified.", "repeat" : "0" } }
      ]
    }
  }');
  return $items;
}
