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
  $items['rules_ban_bad_comments'] = entity_import('rules_config', '{ "rules_ban_bad_comments" : {
      "LABEL" : "USER: Block user from website",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "comment_insert" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "comment:comment-body:value" ],
            "op" : "IN",
            "value" : { "value" : [
                "fuck",
                "Fuck",
                "FUCK",
                "Ass",
                "ass",
                "ASS",
                "liftheightinsoles",
                "bitch",
                "BITCH",
                "slut",
                "SLUT",
                "xxx",
                "XXX",
                "porn",
                "PORN",
                "p0rn",
                "P0RN"
              ]
            }
          }
        }
      ],
      "DO" : [
        { "user_block" : { "account" : [ "comment:author" ] } },
        { "drupal_message" : {
            "message" : "Due to the nature of the comment or post that you have made on the Bit Second website, your access to our website has been blocked and your account has been disabled. \\r\\n\\r\\nIf you have concerns regarding this, please feel free to contact us. ",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
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
  $items['rules_user_create_account'] = entity_import('rules_config', '{ "rules_user_create_account" : {
      "LABEL" : "USER: Create account",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "account", "create", "nonvalid", "user" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "data_set" : { "data" : [ "account:name" ], "value" : [ "account:mail" ] } },
        { "entity_save" : { "data" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_user_user_name_same_as_email'] = entity_import('rules_config', '{ "rules_user_user_name_same_as_email" : {
      "LABEL" : "USER: username and email address match",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-6",
      "OWNER" : "rules",
      "TAGS" : [ "email", "user", "username" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_presave" : [] },
      "IF" : [
        { "AND" : [
            { "NOT entity_is_new" : { "entity" : [ "account" ] } },
            { "NOT data_is" : { "data" : [ "account:name" ], "value" : [ "account:mail" ] } },
            { "NOT data_is" : { "data" : [ "account:uid" ], "value" : "140" } }
          ]
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "account:name" ], "value" : [ "account-unchanged:mail" ] } },
        { "data_set" : { "data" : [ "account:mail" ], "value" : [ "account-unchanged:mail" ] } },
        { "drupal_message" : {
            "message" : "Your username, [account:name], does not match your email address, [account:name].  Your email address has been reverted back to the previous value. Please make sure your email address and username are the same.",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_user_valid_login'] = entity_import('rules_config', '{ "rules_user_valid_login" : {
      "LABEL" : "USER: Initial Login",
      "PLUGIN" : "reaction rule",
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
