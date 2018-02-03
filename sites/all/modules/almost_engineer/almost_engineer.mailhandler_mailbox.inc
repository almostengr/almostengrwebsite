<?php
/**
 * @file
 * almost_engineer.mailhandler_mailbox.inc
 */

/**
 * Implements hook_default_mailhandler_mailbox().
 */
function almost_engineer_default_mailhandler_mailbox() {
  $export = array();

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
