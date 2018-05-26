<?php
/**
 * @file
 * almost_engineer_feature.mailhandler_mailbox.inc
 */

/**
 * Implements hook_default_mailhandler_mailbox().
 */
function almost_engineer_feature_default_mailhandler_mailbox() {
  $export = array();

  $mailbox = new stdClass();
  $mailbox->disabled = TRUE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'gmail_service_requests';
  $mailbox->admin_title = 'Gmail Service Requests';
  $mailbox->settings = array(
    'type' => 'imap',
    'folder' => 'INBOX/ServiceRequests',
    'domain' => 'imap.gmail.com',
    'port' => '993',
    'insecure' => 1,
    'name' => 'bitsecondal@gmail.com',
    'pass' => 'ckripkhsopppadbw',
    'extraimap' => '/ssl',
    'limit' => '0',
    'encoding' => 'UTF-8',
    'flag_after_read' => 1,
    'delete_after_read' => 0,
    'fromheader' => 'From',
    'security' => '0',
    'replies' => '0',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
    'readonly' => 0,
  );
  $export['gmail_service_requests'] = $mailbox;

  $mailbox = new stdClass();
  $mailbox->disabled = FALSE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'help_desk';
  $mailbox->admin_title = 'Help Desk';
  $mailbox->settings = array(
    'type' => 'imap',
    'folder' => 'INBOX',
    'domain' => 'mail.bitsecondtech.com',
    'port' => '993',
    'insecure' => 1,
    'name' => 'helpdesk@bitsecondtech.com',
    'pass' => ')k1UQb}48FCM',
    'extraimap' => '/ssl/novalidate-cert',
    'limit' => '25',
    'encoding' => 'UTF-8',
    'flag_after_read' => 1,
    'delete_after_read' => 0,
    'fromheader' => 'From',
    'security' => '1',
    'replies' => '0',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
    'readonly' => 0,
  );
  $export['help_desk'] = $mailbox;

  $mailbox = new stdClass();
  $mailbox->disabled = FALSE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'web_maintenance';
  $mailbox->admin_title = 'Web Maintenance';
  $mailbox->settings = array(
    'type' => 'imap',
    'folder' => 'INBOX',
    'domain' => 'mail.bitsecondtech.com',
    'port' => '993',
    'insecure' => 1,
    'name' => 'webmaint@bitsecondtech.com',
    'pass' => 'Ng?%kkxMO;aK',
    'extraimap' => '/ssl/novalidate-cert',
    'limit' => '25',
    'encoding' => 'UTF-8',
    'flag_after_read' => 1,
    'delete_after_read' => 0,
    'fromheader' => 'From',
    'security' => '1',
    'replies' => '0',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
    'readonly' => 0,
  );
  $export['web_maintenance'] = $mailbox;

  return $export;
}
