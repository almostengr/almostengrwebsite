<?php
/**
 * @file
 * almost_engineer_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function almost_engineer_feature_default_rules_configuration() {
  $items = array();
  $items['rules_article_almost_afro_engineered'] = entity_import('rules_config', '{ "rules_article_almost_afro_engineered" : {
      "LABEL" : "ARTICLE: Almost Afro Engineered",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "IF" : [
        { "text_matches" : { "text" : [ "node:title" ], "match" : "Almost Afro Engineered" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-simplenews-term" ], "value" : "56" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_article_almost_engineered_tech'] = entity_import('rules_config', '{ "rules_article_almost_engineered_tech" : {
      "LABEL" : "ARTICLE: Almost Engineered Tech",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "IF" : [
        { "text_matches" : { "text" : [ "node:title" ], "match" : "Almost Engineered Tech" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-simplenews-term" ], "value" : "58" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_article_new_almost_afro_engineered'] = entity_import('rules_config', '{ "rules_article_new_almost_afro_engineered" : {
      "LABEL" : "ARTICLE: New Almost Afro Engineered",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "article" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "IF" : [
        { "text_matches" : { "text" : [ "node:title" ], "match" : "Almost Afro Engineered" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-simplenews-term" ], "value" : "56" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_article_new_almost_engineered_tech'] = entity_import('rules_config', '{ "rules_article_new_almost_engineered_tech" : {
      "LABEL" : "ARTICLE: New Almost Engineered Tech",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "article" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "IF" : [
        { "text_matches" : { "text" : [ "node:title" ], "match" : "Almost Engineered Tech" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-simplenews-term" ], "value" : "58" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_article_new_article'] = entity_import('rules_config', '{ "rules_article_new_article" : {
      "LABEL" : "ARTICLE: New Article",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "10",
      "OWNER" : "rules",
      "TAGS" : [ "article" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--article" : { "bundle" : "article" } },
      "DO" : [
        { "data_set" : { "data" : [ "node:field-link:0:title" ], "value" : [ "node:title" ] } },
        { "data_set" : {
            "data" : [ "node:field-link:0:url" ],
            "value" : "https:\\/\\/www.youtube.com\\/watch?v=[node:field-video-id]"
          }
        },
        { "data_set" : {
            "data" : [ "node:body:value" ],
            "value" : "\\u003Ciframe width=\\u0022560\\u0022 height=\\u0022315\\u0022 src=\\u0022https:\\/\\/www.youtube.com\\/embed\\/[node:field-video-id]\\u0022 frameborder=\\u00220\\u0022 allow=\\u0022autoplay; encrypted-media\\u0022 allowfullscreen\\u003E\\u003C\\/iframe\\u003E\\r\\n\\r\\n[node:body]\\r\\n\\r\\nIf you have comments or questions about the video, please leave them on the video\\u0027s YouTube page."
          }
        },
        { "data_set" : { "data" : [ "node:body:format" ], "value" : "full_html" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_article_post_on_front_page_if_published'] = entity_import('rules_config', '{ "rules_article_post_on_front_page_if_published" : {
      "LABEL" : "ARTICLE: Post on front page if published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "article", "front page", "published" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--article" : { "bundle" : "article" } },
      "IF" : [
        { "AND" : [
            { "NOT data_is" : { "data" : [ "node-unchanged:status" ], "value" : [ "node:status" ] } },
            { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "article" : "article" } } } }
          ]
        }
      ],
      "DO" : [
        { "node_promote" : { "node" : [ "node" ] } },
        { "data_set" : { "data" : [ "node:author" ], "value" : "140" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_drupal_redirect_from_node'] = entity_import('rules_config', '{ "rules_drupal_redirect_from_node" : {
      "LABEL" : "DRUPAL: Redirect to home",
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
  $items['rules_find_user_by_email'] = entity_import('rules_config', '{ "rules_find_user_by_email" : {
      "LABEL" : "Find user by email",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "USES VARIABLES" : { "user_email" : { "label" : "User Email", "type" : "text" } },
      "DO" : []
    }
  }');
  $items['rules_portfolio_tp_article'] = entity_import('rules_config', '{ "rules_portfolio_tp_article" : {
      "LABEL" : "portfolio tp article",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--portfolio_item" : { "bundle" : "portfolio_item" } },
      "IF" : [ { "data_is" : { "data" : [ "node:status" ], "value" : "0" } } ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "article",
              "param_title" : [ "node:title" ],
              "param_author" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:body:value" ],
            "value" : [ "node:body:value" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:body:format" ],
            "value" : [ "node:body:format" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity-created:field-image" ],
            "value" : [ "node:field-image" ]
          }
        },
        { "data_set" : { "data" : [ "entity-created:created" ], "value" : [ "node:created" ] } },
        { "data_set" : { "data" : [ "entity-created:status" ], "value" : "0" } },
        { "data_set" : { "data" : [ "entity-created:field-simplenews-term" ], "value" : "58" } },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_redirect_to_almostengineer_domain'] = entity_import('rules_config', '{ "rules_redirect_to_almostengineer_domain" : {
      "LABEL" : "Redirect to almostengineer domain",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-10",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "init" : [] },
      "DO" : []
    }
  }');
  $items['rules_request_close_comments_when_request_completed'] = entity_import('rules_config', '{ "rules_request_close_comments_when_request_completed" : {
      "LABEL" : "Request: Close comments when request completed",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "request", "service request", "update" ],
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_insert--service_request" : { "bundle" : "service_request" },
        "node_update--service_request" : { "bundle" : "service_request" }
      },
      "IF" : [ { "data_is" : { "data" : [ "node:field-state" ], "value" : "128" } } ],
      "DO" : [
        { "data_set" : { "data" : [ "node:comment" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_request_help_desk_email_to_gitlab_issue'] = entity_import('rules_config', '{ "rules_request_help_desk_email_to_gitlab_issue" : {
      "LABEL" : "REQUEST: Help Desk email to Gitlab issue",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "9",
      "OWNER" : "rules",
      "TAGS" : [ "gitlab", "help desk", "helpdesk", "issue" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--service_request" : { "bundle" : "service_request" } },
      "DO" : [
        { "mail" : {
            "to" : "incoming+almostengr\\/bitsecondtech.com-drupal+3fgdqwdrclxd7y9vgdayn4jb4@gitlab.com",
            "subject" : [ "node:title" ],
            "message" : [ "node:body:value" ],
            "from" : [ "node:field-email" ],
            "language" : [ "" ]
          }
        },
        { "node_unpublish" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_requests_close_by_comment'] = entity_import('rules_config', '{ "rules_requests_close_by_comment" : {
      "LABEL" : "REQUESTS: Close by Comment",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : { "comment_insert--comment_node_service_request" : { "bundle" : "comment_node_service_request" } },
      "IF" : [
        { "AND" : [
            { "data_is" : {
                "data" : [ "comment:comment-body" ],
                "op" : "IN",
                "value" : { "value" : [
                    "Request completed",
                    "Request resolved",
                    "REQUEST RESOLVED",
                    "RESOLVING REQUEST",
                    "REQUEST COMPLETED"
                  ]
                }
              }
            },
            { "NOT data_is" : { "data" : [ "comment:node:comment" ], "value" : "1" } }
          ]
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "comment:node:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "node_of_comment" : "Node of comment" } }
          }
        },
        { "data_set" : { "data" : [ "node-of-comment:comment" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "node-of-comment" ] } },
        { "drupal_message" : { "message" : "Request closed", "repeat" : "0" } }
      ]
    }
  }');
  $items['rules_send_client_ticket_notification'] = entity_import('rules_config', '{ "rules_send_client_ticket_notification" : {
      "LABEL" : "Send Client ticket Notification",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "to_email" : { "label" : "to email", "type" : "text" },
        "ticket_status" : { "label" : "Ticket Status", "type" : "text" },
        "ticket_url" : { "label" : "Ticket URL", "type" : "text" },
        "ticket_subject" : { "label" : "Ticket Subject", "type" : "text" }
      },
      "ACTION SET" : [
        { "mail" : {
            "to" : "[to-email:value]",
            "subject" : "Ticket Notification - [ticket-subject:value]",
            "message" : "An update has been made to a ticket that you have submitted. Information regarding the ticket is as follows: \\r\\n\\r\\nSubject: [ticket-subject:value]\\r\\nStatus: [ticket-status:value]\\r\\n\\r\\nFor more information, please visit [ticket-url:value]\\r\\n\\r\\nDo not reply to this email. ",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_user_block_account'] = entity_import('rules_config', '{ "rules_user_block_account" : {
      "LABEL" : "USER: Block Account",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "OR" : [
            { "data_is" : { "data" : [ "account:field-i-m-a-spammer" ], "value" : "1" } },
            { "data_is" : { "data" : [ "account:field-terms-and-conditions" ], "value" : "0" } }
          ]
        }
      ],
      "DO" : [
        { "user_block" : { "account" : [ "account" ] } },
        { "drupal_message" : {
            "message" : "Your account has been blocked due to not accepting the terms and conditions of the site or your account has been flagged as spam. If you feel that this has been done in error, please contact us via the Contact page.",
            "type" : "warning"
          }
        }
      ]
    }
  }');
  $items['rules_user_block_email_address_from_user_account'] = entity_import('rules_config', '{ "rules_user_block_email_address_from_user_account" : {
      "LABEL" : "USER: Block known spam email addresses",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "block", "email", "spam", "user" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [], "user_update" : [] },
      "IF" : [
        { "text_matches" : {
            "text" : [ "account:mail" ],
            "match" : ".xyz\\r\\n.abc\\r\\n.def",
            "operation" : "ends"
          }
        }
      ],
      "DO" : [
        { "user_block" : { "account" : [ "account" ] } },
        { "drupal_message" : {
            "message" : "Your account has been blocked due to violating spam rule requirements. If you believe that this has been done in error, then please contact the site administrator.",
            "type" : "error",
            "repeat" : "0"
          }
        }
      ]
    }
  }');
  $items['rules_user_lookup_by_email'] = entity_import('rules_config', '{ "rules_user_lookup_by_email" : {
      "LABEL" : "user lookup by email",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "email" : { "label" : "Email ", "type" : "text" },
        "last" : { "label" : "Last Name", "type" : "text" },
        "first" : { "label" : "First name", "type" : "text" }
      },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "site:current-user" ], "type" : "user" } }
      ],
      "DO" : []
    }
  }');
  return $items;
}
