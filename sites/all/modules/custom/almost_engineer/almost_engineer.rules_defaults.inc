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
  return $items;
}
