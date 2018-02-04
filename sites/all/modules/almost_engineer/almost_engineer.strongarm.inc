<?php
/**
 * @file
 * almost_engineer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function almost_engineer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_blog';
  $strongarm->value = 'edit-menu';
  $export['additional_settings__active_tab_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'address';
  $strongarm->value = array(
    'uc_store_street1' => '',
    'uc_store_street2' => '',
    'uc_store_city' => 'Montgomery',
    'uc_store_zone' => '1',
    'uc_store_country' => '840',
    'uc_store_postal_code' => '',
  );
  $export['address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = '0';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'anonymous';
  $strongarm->value = 'Anonymous';
  $export['anonymous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'at_browscap_detect';
  $strongarm->value = FALSE;
  $export['at_browscap_detect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'at_detection';
  $strongarm->value = FALSE;
  $export['at_detection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'at_mobile_detect';
  $strongarm->value = FALSE;
  $export['at_mobile_detect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_copy_destination_id';
  $strongarm->value = '';
  $export['backup_migrate_copy_destination_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_destination_id';
  $strongarm->value = 'download';
  $export['backup_migrate_destination_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_profile_id';
  $strongarm->value = 'default';
  $export['backup_migrate_profile_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_schedule_last_run_default_schedule';
  $strongarm->value = 1483491371;
  $export['backup_migrate_schedule_last_run_default_schedule'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'backup_migrate_source_id';
  $strongarm->value = 'db';
  $export['backup_migrate_source_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cart-settings__active_tab';
  $strongarm->value = 'edit-continue-shopping';
  $export['cart-settings__active_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'checkout-settings__active_tab';
  $strongarm->value = 'edit-anonymous';
  $export['checkout-settings__active_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_pixture_reloaded_files';
  $strongarm->value = array(
    0 => 'public://color/pixture_reloaded-630088a5/bullet-round.png',
    1 => 'public://color/pixture_reloaded-630088a5/bullet-sm-arrow-right.png',
    2 => 'public://color/pixture_reloaded-630088a5/bullet-sm-arrow-down.png',
    3 => 'public://color/pixture_reloaded-630088a5/button.gif',
    4 => 'public://color/pixture_reloaded-630088a5/button-o.gif',
    5 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/header.png',
    6 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/header-tile.png',
    7 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/menu-tile.png',
    8 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-footer.png',
    9 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-footer-tile.png',
    10 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-menu.png',
    11 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-title.png',
    12 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-wall.png',
    13 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-bar-lite.png',
    14 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-bar.png',
    15 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-lbar-lite.png',
    16 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/bg-lbar.png',
    17 => '/var/www/dev.bitsecondtech.com/sites/default/files/color/pixture_reloaded-630088a5/sf-hover-tile.png',
    18 => 'public://color/pixture_reloaded-630088a5/colors.css',
  );
  $export['color_pixture_reloaded_files'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_pixture_reloaded_logo';
  $strongarm->value = 'public://color/pixture_reloaded-630088a5/logo.png';
  $export['color_pixture_reloaded_logo'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_pixture_reloaded_palette';
  $strongarm->value = array(
    'base' => '#202020',
    'page' => '#ffffff',
    'sitename' => '#feffff',
    'slogan' => '#fefefe',
    'header' => '#fdfdfd',
    'mmenu' => '#fffffe',
    'link' => '#11275f',
    'top' => '#000000',
    'bottom' => '#808080',
    'ftop' => '#181818',
    'fbottom' => '#343434',
    'text' => '#000000',
    'blockh' => '#2b2b2b',
    'blockht' => '#ffffff',
    'blockbg' => '#bdbdbd',
    'borders' => '#bdbdbd',
    'sticky' => '#bdbdbd',
  );
  $export['color_pixture_reloaded_palette'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'color_pixture_reloaded_stylesheets';
  $strongarm->value = array(
    0 => 'public://color/pixture_reloaded-630088a5/colors.css',
  );
  $export['color_pixture_reloaded_stylesheets'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cron_safe_threshold';
  $strongarm->value = '3600';
  $export['cron_safe_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_default_timezone';
  $strongarm->value = 'America/Chicago';
  $export['date_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_first_day';
  $strongarm->value = '0';
  $export['date_first_day'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_long';
  $strongarm->value = 'l, F j, Y - g:ia';
  $export['date_format_long'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_medium';
  $strongarm->value = 'D, Y-m-d H:i';
  $export['date_format_medium'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short';
  $strongarm->value = 'Y-m-d H:i';
  $export['date_format_short'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_uc_store';
  $strongarm->value = 'm/d/Y';
  $export['date_format_uc_store'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'empty_timezone_message';
  $strongarm->value = 1;
  $export['empty_timezone_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_alert';
  $strongarm->value = 0;
  $export['extlink_alert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_alert_text';
  $strongarm->value = 'This link will take you to an external web site.';
  $export['extlink_alert_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_class';
  $strongarm->value = 0;
  $export['extlink_class'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_css_exclude';
  $strongarm->value = '';
  $export['extlink_css_exclude'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_css_explicit';
  $strongarm->value = '';
  $export['extlink_css_explicit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_exclude';
  $strongarm->value = '';
  $export['extlink_exclude'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_img_class';
  $strongarm->value = 0;
  $export['extlink_img_class'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_include';
  $strongarm->value = '';
  $export['extlink_include'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_mailto_class';
  $strongarm->value = 0;
  $export['extlink_mailto_class'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_subdomains';
  $strongarm->value = 1;
  $export['extlink_subdomains'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'extlink_target';
  $strongarm->value = '_blank';
  $export['extlink_target'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_public_path';
  $strongarm->value = 'sites/default/files';
  $export['file_public_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_temporary_path';
  $strongarm->value = '/tmp';
  $export['file_temporary_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_account';
  $strongarm->value = 'UA-64643711-1';
  $export['googleanalytics_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_cache';
  $strongarm->value = 0;
  $export['googleanalytics_cache'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_codesnippet_after';
  $strongarm->value = '';
  $export['googleanalytics_codesnippet_after'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_codesnippet_before';
  $strongarm->value = '';
  $export['googleanalytics_codesnippet_before'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_codesnippet_create';
  $strongarm->value = array();
  $export['googleanalytics_codesnippet_create'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_cross_domains';
  $strongarm->value = '';
  $export['googleanalytics_cross_domains'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom';
  $strongarm->value = '0';
  $export['googleanalytics_custom'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom_dimension';
  $strongarm->value = array();
  $export['googleanalytics_custom_dimension'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_custom_metric';
  $strongarm->value = array();
  $export['googleanalytics_custom_metric'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_debug';
  $strongarm->value = 0;
  $export['googleanalytics_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_pages';
  $strongarm->value = 'admin
admin/*
batch
node/add*
node/*/*
user/*/*';
  $export['googleanalytics_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_premium';
  $strongarm->value = 0;
  $export['googleanalytics_premium'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_privacy_donottrack';
  $strongarm->value = 1;
  $export['googleanalytics_privacy_donottrack'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_roles';
  $strongarm->value = array(
    3 => '3',
    1 => 0,
    2 => 0,
    6 => 0,
    11 => 0,
    9 => 0,
    10 => 0,
  );
  $export['googleanalytics_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_site_search';
  $strongarm->value = 0;
  $export['googleanalytics_site_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackadsense';
  $strongarm->value = 1;
  $export['googleanalytics_trackadsense'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackcolorbox';
  $strongarm->value = 1;
  $export['googleanalytics_trackcolorbox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackdoubleclick';
  $strongarm->value = 0;
  $export['googleanalytics_trackdoubleclick'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_tracker_anonymizeip';
  $strongarm->value = 0;
  $export['googleanalytics_tracker_anonymizeip'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackfiles';
  $strongarm->value = 1;
  $export['googleanalytics_trackfiles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackfiles_extensions';
  $strongarm->value = '7z|aac|arc|arj|asf|asx|avi|bin|csv|doc(x|m)?|dot(x|m)?|exe|flv|gif|gz|gzip|hqx|jar|jpe?g|js|mp(2|3|4|e?g)|mov(ie)?|msi|msp|pdf|phps|png|ppt(x|m)?|pot(x|m)?|pps(x|m)?|ppam|sld(x|m)?|thmx|qtm?|ra(m|r)?|sea|sit|tar|tgz|torrent|txt|wav|wma|wmv|wpd|xls(x|m|b)?|xlt(x|m)|xlam|xml|z|zip';
  $export['googleanalytics_trackfiles_extensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_tracklinkid';
  $strongarm->value = 0;
  $export['googleanalytics_tracklinkid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackmailto';
  $strongarm->value = 1;
  $export['googleanalytics_trackmailto'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackmessages';
  $strongarm->value = array(
    'status' => 0,
    'warning' => 0,
    'error' => 0,
  );
  $export['googleanalytics_trackmessages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackoutbound';
  $strongarm->value = 1;
  $export['googleanalytics_trackoutbound'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackurlfragments';
  $strongarm->value = 0;
  $export['googleanalytics_trackurlfragments'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_trackuserid';
  $strongarm->value = 1;
  $export['googleanalytics_trackuserid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_visibility_pages';
  $strongarm->value = '0';
  $export['googleanalytics_visibility_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_visibility_roles';
  $strongarm->value = '1';
  $export['googleanalytics_visibility_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_element_name';
  $strongarm->value = 'email2';
  $export['honeypot_element_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_article_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_article_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_b2t_ticket_node_form';
  $strongarm->value = 1;
  $export['honeypot_form_b2t_ticket_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_article_form';
  $strongarm->value = 1;
  $export['honeypot_form_comment_node_article_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_b2t_ticket_form';
  $strongarm->value = 1;
  $export['honeypot_form_comment_node_b2t_ticket_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_contact_request_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_contact_request_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_page_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_page_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_portfolio_item_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_portfolio_item_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_product_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_product_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_product_kit_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_product_kit_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_service_request_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_service_request_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_simplenews_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_simplenews_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_teleprompter_script_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_teleprompter_script_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_comment_node_webform_form';
  $strongarm->value = 0;
  $export['honeypot_form_comment_node_webform_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_contact_request_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_contact_request_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_page_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_page_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_portfolio_item_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_portfolio_item_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_product_kit_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_product_kit_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_product_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_product_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_service_request_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_service_request_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_simplenews_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_simplenews_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_teleprompter_script_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_teleprompter_script_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_user_pass';
  $strongarm->value = 1;
  $export['honeypot_form_user_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_user_register_form';
  $strongarm->value = 1;
  $export['honeypot_form_user_register_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_webforms';
  $strongarm->value = 0;
  $export['honeypot_form_webforms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_form_webform_node_form';
  $strongarm->value = 0;
  $export['honeypot_form_webform_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_log';
  $strongarm->value = 1;
  $export['honeypot_log'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_protect_all_forms';
  $strongarm->value = 1;
  $export['honeypot_protect_all_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_time_contact_request';
  $strongarm->value = '1483576499|IDUisj20KhWobnUFjat7Sj0swoJw-_AOXgw9CTYu-dY';
  $export['honeypot_time_contact_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_time_limit';
  $strongarm->value = '4';
  $export['honeypot_time_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'honeypot_use_js_for_cached_pages';
  $strongarm->value = 0;
  $export['honeypot_use_js_for_cached_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'gd';
  $export['image_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_confirm_email_at_registration';
  $strongarm->value = '1';
  $export['logintoboggan_confirm_email_at_registration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_immediate_login_on_register';
  $strongarm->value = 0;
  $export['logintoboggan_immediate_login_on_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_successful_message';
  $strongarm->value = '0';
  $export['logintoboggan_login_successful_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_login_with_email';
  $strongarm->value = '1';
  $export['logintoboggan_login_with_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_minimum_password_length';
  $strongarm->value = '8';
  $export['logintoboggan_minimum_password_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_override_destination_parameter';
  $strongarm->value = 1;
  $export['logintoboggan_override_destination_parameter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_pre_auth_role';
  $strongarm->value = '6';
  $export['logintoboggan_pre_auth_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_purge_unvalidated_user_interval';
  $strongarm->value = '86400';
  $export['logintoboggan_purge_unvalidated_user_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_redirect_on_confirm';
  $strongarm->value = '';
  $export['logintoboggan_redirect_on_confirm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_redirect_on_register';
  $strongarm->value = '';
  $export['logintoboggan_redirect_on_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'logintoboggan_unified_login';
  $strongarm->value = 0;
  $export['logintoboggan_unified_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_activity_threshold';
  $strongarm->value = '5';
  $export['login_security_activity_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_disable_core_login_error';
  $strongarm->value = 0;
  $export['login_security_disable_core_login_error'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_host_hard_banned';
  $strongarm->value = 'The IP address @ip is banned at @site, and will not be able to access any of its content from now on. Please contact the site administrator.';
  $export['login_security_host_hard_banned'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_host_soft_banned';
  $strongarm->value = 'This host is not allowed to log in to @site. Please contact your site administrator.';
  $export['login_security_host_soft_banned'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_host_wrong_count';
  $strongarm->value = '3';
  $export['login_security_host_wrong_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_host_wrong_count_hard';
  $strongarm->value = '0';
  $export['login_security_host_wrong_count_hard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_last_access_timestamp';
  $strongarm->value = 0;
  $export['login_security_last_access_timestamp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_last_login_timestamp';
  $strongarm->value = 1;
  $export['login_security_last_login_timestamp'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_login_activity_email_body';
  $strongarm->value = 'The configured threshold of @activity_threshold logins has been reached with a total of @tracking_current_count invalid login attempts. You should review your log information about login attempts at @site.';
  $export['login_security_login_activity_email_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_login_activity_email_subject';
  $strongarm->value = 'Security information: Unexpected login activity has been detected at @site.';
  $export['login_security_login_activity_email_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_login_activity_email_user';
  $strongarm->value = '';
  $export['login_security_login_activity_email_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_notice_attempts_available';
  $strongarm->value = 0;
  $export['login_security_notice_attempts_available'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_notice_attempts_message';
  $strongarm->value = 'You have used @user_current_count out of @user_block_attempts login attempts. After all @user_block_attempts have been used, you will be unable to login.';
  $export['login_security_notice_attempts_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_threshold_notified';
  $strongarm->value = FALSE;
  $export['login_security_threshold_notified'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_track_time';
  $strongarm->value = '1';
  $export['login_security_track_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_user_blocked';
  $strongarm->value = 'The user @username has been blocked due to failed login attempts.';
  $export['login_security_user_blocked'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_user_blocked_email_body';
  $strongarm->value = 'The user @username (@edit_uri) has been blocked at @site due to the amount of failed login attempts. Please check the logs for more information.';
  $export['login_security_user_blocked_email_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_user_blocked_email_subject';
  $strongarm->value = 'Security action: The user @username has been blocked.';
  $export['login_security_user_blocked_email_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_user_blocked_email_user';
  $strongarm->value = '';
  $export['login_security_user_blocked_email_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'login_security_user_wrong_count';
  $strongarm->value = '3';
  $export['login_security_user_wrong_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maintenance_mode_message';
  $strongarm->value = 'Almost Engineer is currently under maintenance. We should be back shortly. Thank you for your patience.';
  $export['maintenance_mode_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_default_active_menus';
  $strongarm->value = array(
    1 => 'main-menu',
    2 => 'management',
    3 => 'navigation',
    4 => 'user-menu',
    5 => 'menu-bit-second-social',
    6 => 'menu-things-i-use',
  );
  $export['menu_default_active_menus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_expanded';
  $strongarm->value = array(
    0 => 'management',
    1 => 'user-menu',
  );
  $export['menu_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_masks';
  $strongarm->value = array(
    0 => 507,
    1 => 506,
    2 => 501,
    3 => 493,
    4 => 255,
    5 => 253,
    6 => 252,
    7 => 251,
    8 => 250,
    9 => 247,
    10 => 246,
    11 => 245,
    12 => 127,
    13 => 126,
    14 => 125,
    15 => 124,
    16 => 123,
    17 => 122,
    18 => 121,
    19 => 117,
    20 => 89,
    21 => 63,
    22 => 62,
    23 => 61,
    24 => 60,
    25 => 59,
    26 => 58,
    27 => 44,
    28 => 31,
    29 => 30,
    30 => 29,
    31 => 24,
    32 => 21,
    33 => 15,
    34 => 14,
    35 => 13,
    36 => 11,
    37 => 10,
    38 => 8,
    39 => 7,
    40 => 6,
    41 => 5,
    42 => 3,
    43 => 2,
    44 => 1,
  );
  $export['menu_masks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article';
  $strongarm->value = array();
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_b2t_ticket';
  $strongarm->value = array();
  $export['menu_options_b2t_ticket'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_blog';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_book';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_contact_request';
  $strongarm->value = array();
  $export['menu_options_contact_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_issue_ticket';
  $strongarm->value = array();
  $export['menu_options_issue_ticket'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_portfolio_item';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_portfolio_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_product';
  $strongarm->value = array();
  $export['menu_options_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_project_scope_document';
  $strongarm->value = array();
  $export['menu_options_project_scope_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_service_desk_ticket';
  $strongarm->value = array();
  $export['menu_options_service_desk_ticket'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_service_request';
  $strongarm->value = array();
  $export['menu_options_service_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_simplenews';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_teleprompter_script';
  $strongarm->value = array();
  $export['menu_options_teleprompter_script'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_webform';
  $strongarm->value = array(
    0 => 'main-menu',
    1 => 'navigation',
    2 => 'user-menu',
  );
  $export['menu_options_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article';
  $strongarm->value = 'features:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_b2t_ticket';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_b2t_ticket'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_blog';
  $strongarm->value = 'main-menu:450';
  $export['menu_parent_blog'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_book';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_book'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_contact_request';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_contact_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_issue_ticket';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_issue_ticket'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_portfolio_item';
  $strongarm->value = 'main-menu:497';
  $export['menu_parent_portfolio_item'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_product';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_project_scope_document';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_project_scope_document'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_service_desk_ticket';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_service_desk_ticket'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_service_request';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_service_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_simplenews';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_teleprompter_script';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_teleprompter_script'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_webform';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_webform'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'minimum_word_size';
  $strongarm->value = '3';
  $export['minimum_word_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_cache_maximum_age';
  $strongarm->value = '43200';
  $export['page_cache_maximum_age'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_compression';
  $strongarm->value = 1;
  $export['page_compression'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_blog_pattern';
  $strongarm->value = 'blogs/[user:name]';
  $export['pathauto_blog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_case';
  $strongarm->value = '1';
  $export['pathauto_case'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_forum_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_forum_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_ignore_words';
  $strongarm->value = 'a, an, as, at, before, but, by, for, from, is, in, into, like, of, off, on, onto, per, since, than, the, this, that, to, up, via, with';
  $export['pathauto_ignore_words'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_max_component_length';
  $strongarm->value = '100';
  $export['pathauto_max_component_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_max_length';
  $strongarm->value = '100';
  $export['pathauto_max_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_article_pattern';
  $strongarm->value = 'blog/[node:title]';
  $export['pathauto_node_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_contact_request_pattern';
  $strongarm->value = 'contact/[random:hash:md5]';
  $export['pathauto_node_contact_request_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_page_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_portfolio_item_pattern';
  $strongarm->value = 'portfolio/[node:title]';
  $export['pathauto_node_portfolio_item_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_pattern';
  $strongarm->value = 'store/[node:title]';
  $export['pathauto_node_product_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_ampersand';
  $strongarm->value = '0';
  $export['pathauto_punctuation_ampersand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_asterisk';
  $strongarm->value = '0';
  $export['pathauto_punctuation_asterisk'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_at';
  $strongarm->value = '0';
  $export['pathauto_punctuation_at'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_backtick';
  $strongarm->value = '0';
  $export['pathauto_punctuation_backtick'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_back_slash';
  $strongarm->value = '0';
  $export['pathauto_punctuation_back_slash'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_caret';
  $strongarm->value = '0';
  $export['pathauto_punctuation_caret'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_colon';
  $strongarm->value = '0';
  $export['pathauto_punctuation_colon'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_comma';
  $strongarm->value = '0';
  $export['pathauto_punctuation_comma'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_dollar';
  $strongarm->value = '0';
  $export['pathauto_punctuation_dollar'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_double_quotes';
  $strongarm->value = '0';
  $export['pathauto_punctuation_double_quotes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_equal';
  $strongarm->value = '0';
  $export['pathauto_punctuation_equal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_exclamation';
  $strongarm->value = '0';
  $export['pathauto_punctuation_exclamation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_greater_than';
  $strongarm->value = '0';
  $export['pathauto_punctuation_greater_than'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hash';
  $strongarm->value = '0';
  $export['pathauto_punctuation_hash'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_hyphen';
  $strongarm->value = '1';
  $export['pathauto_punctuation_hyphen'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_left_curly';
  $strongarm->value = '0';
  $export['pathauto_punctuation_left_curly'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_left_parenthesis';
  $strongarm->value = '0';
  $export['pathauto_punctuation_left_parenthesis'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_left_square';
  $strongarm->value = '0';
  $export['pathauto_punctuation_left_square'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_less_than';
  $strongarm->value = '0';
  $export['pathauto_punctuation_less_than'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_percent';
  $strongarm->value = '0';
  $export['pathauto_punctuation_percent'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_period';
  $strongarm->value = '0';
  $export['pathauto_punctuation_period'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_pipe';
  $strongarm->value = '0';
  $export['pathauto_punctuation_pipe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_plus';
  $strongarm->value = '0';
  $export['pathauto_punctuation_plus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_question_mark';
  $strongarm->value = '0';
  $export['pathauto_punctuation_question_mark'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_quotes';
  $strongarm->value = '0';
  $export['pathauto_punctuation_quotes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_right_curly';
  $strongarm->value = '0';
  $export['pathauto_punctuation_right_curly'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_right_parenthesis';
  $strongarm->value = '0';
  $export['pathauto_punctuation_right_parenthesis'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_right_square';
  $strongarm->value = '0';
  $export['pathauto_punctuation_right_square'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_semicolon';
  $strongarm->value = '0';
  $export['pathauto_punctuation_semicolon'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_slash';
  $strongarm->value = '0';
  $export['pathauto_punctuation_slash'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_tilde';
  $strongarm->value = '0';
  $export['pathauto_punctuation_tilde'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_punctuation_underscore';
  $strongarm->value = '0';
  $export['pathauto_punctuation_underscore'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_reduce_ascii';
  $strongarm->value = 0;
  $export['pathauto_reduce_ascii'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_separator';
  $strongarm->value = '-';
  $export['pathauto_separator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_catalog_pattern';
  $strongarm->value = 'store/category-[term:name]';
  $export['pathauto_taxonomy_term_catalog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_newsletter_pattern';
  $strongarm->value = 'newsletter/[term:name]';
  $export['pathauto_taxonomy_term_newsletter_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_pattern';
  $strongarm->value = '[term:vocabulary]/[term:name]';
  $export['pathauto_taxonomy_term_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_projects_pattern';
  $strongarm->value = 'projects/[term:name]';
  $export['pathauto_taxonomy_term_projects_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_terms_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_terms_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_transliterate';
  $strongarm->value = FALSE;
  $export['pathauto_transliterate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_uc_catalog_pattern';
  $strongarm->value = 'catalog/[term:name]';
  $export['pathauto_uc_catalog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_update_action';
  $strongarm->value = '2';
  $export['pathauto_update_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_user_pattern';
  $strongarm->value = 'users/[user:name]';
  $export['pathauto_user_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_verbose';
  $strongarm->value = 0;
  $export['pathauto_verbose'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'product-settings__active_tab';
  $strongarm->value = 'edit-product';
  $export['product-settings__active_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_expand_fieldset_article';
  $strongarm->value = '0';
  $export['scheduler_expand_fieldset_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_article';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_past_date_article';
  $strongarm->value = 'error';
  $export['scheduler_publish_past_date_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_article';
  $strongarm->value = 0;
  $export['scheduler_publish_required_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_article';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_article';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_enable_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_use_vertical_tabs_article';
  $strongarm->value = '1';
  $export['scheduler_use_vertical_tabs_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_active_modules';
  $strongarm->value = array(
    'node' => 'node',
    'user' => 0,
  );
  $export['search_active_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_cron_limit';
  $strongarm->value = '100';
  $export['search_cron_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_default_module';
  $strongarm->value = 'node';
  $export['search_default_module'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_logging';
  $strongarm->value = 0;
  $export['search_logging'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_all_forms';
  $strongarm->value = 1;
  $export['securelogin_all_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_base_url';
  $strongarm->value = '';
  $export['securelogin_base_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_comment_form';
  $strongarm->value = 1;
  $export['securelogin_form_comment_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_node_form';
  $strongarm->value = 1;
  $export['securelogin_form_node_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_user_login';
  $strongarm->value = 1;
  $export['securelogin_form_user_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_user_login_block';
  $strongarm->value = 1;
  $export['securelogin_form_user_login_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_user_pass';
  $strongarm->value = 1;
  $export['securelogin_form_user_pass'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_user_pass_reset';
  $strongarm->value = 1;
  $export['securelogin_form_user_pass_reset'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_user_profile_form';
  $strongarm->value = 1;
  $export['securelogin_form_user_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_form_user_register_form';
  $strongarm->value = 1;
  $export['securelogin_form_user_register_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_other_forms';
  $strongarm->value = '';
  $export['securelogin_other_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securelogin_secure_forms';
  $strongarm->value = 1;
  $export['securelogin_secure_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_content_type_article';
  $strongarm->value = 1;
  $export['simplenews_content_type_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_content_type_product';
  $strongarm->value = 0;
  $export['simplenews_content_type_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_content_type_service_request';
  $strongarm->value = 0;
  $export['simplenews_content_type_service_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_content_type_simplenews';
  $strongarm->value = TRUE;
  $export['simplenews_content_type_simplenews'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'simplenews_vid';
  $strongarm->value = '2';
  $export['simplenews_vid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_403';
  $strongarm->value = 'toboggan/denied';
  $export['site_403'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_404';
  $strongarm->value = '';
  $export['site_404'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_default_country';
  $strongarm->value = 'US';
  $export['site_default_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'front';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_mail';
  $strongarm->value = 'noreply@bitsecondtech.com';
  $export['site_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_name';
  $strongarm->value = 'Almost Engineer';
  $export['site_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_slogan';
  $strongarm->value = '';
  $export['site_slogan'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'store__active_tab';
  $strongarm->value = 'edit-display';
  $export['store__active_tab'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'pixture_reloaded';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_garland_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 0,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 0,
    'default_logo' => 0,
    'logo_path' => 'public://b2t_logo_short.png',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'garland_width' => 'fluid',
    'scheme' => 'greenbeam',
    'palette' => array(
      'base' => '#c9c497',
      'link' => '#0c7a00',
      'top' => '#03961e',
      'bottom' => '#7be000',
      'text' => '#494949',
    ),
    'theme' => 'garland',
    'info' => array(
      'fields' => array(
        'base' => 'Base color',
        'link' => 'Link color',
        'top' => 'Header top',
        'bottom' => 'Header bottom',
        'text' => 'Text color',
      ),
      'schemes' => array(
        'default' => array(
          'title' => 'Blue Lagoon (Default)',
          'colors' => array(
            'base' => '#0072b9',
            'link' => '#027ac6',
            'top' => '#2385c2',
            'bottom' => '#5ab5ee',
            'text' => '#494949',
          ),
        ),
        'ash' => array(
          'title' => 'Ash',
          'colors' => array(
            'base' => '#464849',
            'link' => '#2f416f',
            'top' => '#2a2b2d',
            'bottom' => '#5d6779',
          ),
        ),
        'aquamarine' => array(
          'title' => 'Aquamarine',
          'colors' => array(
            'base' => '#55c0e2',
            'link' => '#000000',
            'text' => '#696969',
            'top' => '#085360',
            'bottom' => '#007e94',
          ),
        ),
        'chocolate' => array(
          'title' => 'Belgian Chocolate',
          'colors' => array(
            'base' => '#d5b048',
            'link' => '#6c420e',
            'top' => '#331900',
            'bottom' => '#971702',
          ),
        ),
        'bluemarine' => array(
          'title' => 'Bluemarine',
          'colors' => array(
            'base' => '#3f3f3f',
            'link' => '#336699',
            'text' => '#000000',
            'top' => '#6598cb',
            'bottom' => '#6598cb',
          ),
        ),
        'citrus' => array(
          'title' => 'Citrus Blast',
          'colors' => array(
            'base' => '#d0cb9a',
            'link' => '#917803',
            'top' => '#efde01',
            'bottom' => '#e6fb2d',
          ),
        ),
        'cold' => array(
          'title' => 'Cold Day',
          'colors' => array(
            'base' => '#0f005c',
            'link' => '#434f8c',
            'text' => '#000000',
            'top' => '#4d91ff',
            'bottom' => '#1a1575',
          ),
        ),
        'greenbeam' => array(
          'title' => 'Greenbeam',
          'colors' => array(
            'base' => '#c9c497',
            'link' => '#0c7a00',
            'top' => '#03961e',
            'bottom' => '#7be000',
          ),
        ),
        'mediterrano' => array(
          'title' => 'Mediterrano',
          'colors' => array(
            'base' => '#ffe23d',
            'link' => '#a9290a',
            'top' => '#fc6d1d',
            'bottom' => '#a30f42',
          ),
        ),
        'mercury' => array(
          'title' => 'Mercury',
          'colors' => array(
            'base' => '#788597',
            'link' => '#3f728d',
            'top' => '#a9adbc',
            'bottom' => '#d4d4d4',
            'text' => '#707070',
          ),
        ),
        'nocturnal' => array(
          'title' => 'Nocturnal',
          'colors' => array(
            'base' => '#5b5fa9',
            'link' => '#5b5faa',
            'top' => '#0a2352',
            'bottom' => '#9fa8d5',
          ),
        ),
        'olivia' => array(
          'title' => 'Olivia',
          'colors' => array(
            'base' => '#7db323',
            'link' => '#6a9915',
            'top' => '#b5d52a',
            'bottom' => '#7db323',
            'text' => '#191a19',
          ),
        ),
        'pink_plastic' => array(
          'title' => 'Pink Plastic',
          'colors' => array(
            'base' => '#12020b',
            'link' => '#1b1a13',
            'top' => '#f391c6',
            'bottom' => '#f41063',
            'text' => '#898080',
          ),
        ),
        'shiny_tomato' => array(
          'title' => 'Shiny Tomato',
          'colors' => array(
            'base' => '#b7a0ba',
            'link' => '#c70000',
            'top' => '#a1443a',
            'bottom' => '#f21107',
            'text' => '#515d52',
          ),
        ),
        'teal_top' => array(
          'title' => 'Teal Top',
          'colors' => array(
            'base' => '#18583d',
            'link' => '#1b5f42',
            'top' => '#34775a',
            'bottom' => '#52bf90',
            'text' => '#2d2d2d',
          ),
        ),
        '' => array(
          'title' => 'Custom',
          'colors' => array(),
        ),
      ),
      'copy' => array(
        0 => 'images/menu-collapsed.gif',
        1 => 'images/menu-collapsed-rtl.gif',
        2 => 'images/menu-expanded.gif',
        3 => 'images/menu-leaf.gif',
      ),
      'css' => array(
        0 => 'style.css',
      ),
      'gradients' => array(
        0 => array(
          'dimension' => array(
            0 => 0,
            1 => 38,
            2 => 760,
            3 => 121,
          ),
          'direction' => 'vertical',
          'colors' => array(
            0 => 'top',
            1 => 'bottom',
          ),
        ),
      ),
      'fill' => array(
        'base' => array(
          0 => 0,
          1 => 0,
          2 => 760,
          3 => 568,
        ),
        'link' => array(
          0 => 107,
          1 => 533,
          2 => 41,
          3 => 23,
        ),
      ),
      'slices' => array(
        'images/body.png' => array(
          0 => 0,
          1 => 37,
          2 => 1,
          3 => 280,
        ),
        'images/bg-bar.png' => array(
          0 => 202,
          1 => 530,
          2 => 76,
          3 => 14,
        ),
        'images/bg-bar-white.png' => array(
          0 => 202,
          1 => 506,
          2 => 76,
          3 => 14,
        ),
        'images/bg-tab.png' => array(
          0 => 107,
          1 => 533,
          2 => 41,
          3 => 23,
        ),
        'images/bg-navigation.png' => array(
          0 => 0,
          1 => 0,
          2 => 7,
          3 => 37,
        ),
        'images/bg-content-left.png' => array(
          0 => 40,
          1 => 117,
          2 => 50,
          3 => 352,
        ),
        'images/bg-content-right.png' => array(
          0 => 510,
          1 => 117,
          2 => 50,
          3 => 352,
        ),
        'images/bg-content.png' => array(
          0 => 299,
          1 => 117,
          2 => 7,
          3 => 200,
        ),
        'images/bg-navigation-item.png' => array(
          0 => 32,
          1 => 37,
          2 => 17,
          3 => 12,
        ),
        'images/bg-navigation-item-hover.png' => array(
          0 => 54,
          1 => 37,
          2 => 17,
          3 => 12,
        ),
        'images/gradient-inner.png' => array(
          0 => 646,
          1 => 307,
          2 => 112,
          3 => 42,
        ),
        'logo.png' => array(
          0 => 622,
          1 => 51,
          2 => 64,
          3 => 73,
        ),
        'screenshot.png' => array(
          0 => 0,
          1 => 37,
          2 => 400,
          3 => 240,
        ),
      ),
      'blend_target' => '#ffffff',
      'preview_image' => 'color/preview.png',
      'preview_css' => 'color/preview.css',
      'base_image' => 'color/base.png',
    ),
  );
  $export['theme_garland_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_pixture_reloaded_files_directory';
  $strongarm->value = 'public://adaptivetheme/pixture_reloaded_files';
  $export['theme_pixture_reloaded_files_directory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_pixture_reloaded_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 0,
    'toggle_favicon' => 0,
    'default_logo' => 0,
    'logo_path' => 'sites/all/themes/almostengr/ae_logo.jpg',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'sites/all/themes/almostengr/ae_logo.jpg',
    'favicon_upload' => '',
    'bigscreen_layout' => 'three_col_grail',
    'bigscreen_sidebar_unit' => '%',
    'bigscreen_sidebar_first' => '25',
    'bigscreen_sidebar_second' => '25',
    'bigscreen_page_unit' => '%',
    'bigscreen_page_width' => '100',
    'bigscreen_set_max_width' => 1,
    'bigscreen_max_width_unit' => 'px',
    'bigscreen_max_width' => '1140',
    'bigscreen_media_query' => 'only screen and (min-width:1025px)',
    'tablet_landscape_layout' => 'three_col_grail',
    'tablet_landscape_sidebar_unit' => '%',
    'tablet_landscape_sidebar_first' => '20',
    'tablet_landscape_sidebar_second' => '20',
    'tablet_landscape_page_unit' => '%',
    'tablet_landscape_page_width' => '100',
    'tablet_landscape_media_query' => 'only screen and (min-width:769px) and (max-width:1024px)',
    'tablet_portrait_layout' => 'one_col_vert',
    'tablet_portrait_sidebar_unit' => '%',
    'tablet_portrait_sidebar_first' => '50',
    'tablet_portrait_sidebar_second' => '50',
    'tablet_portrait_page_unit' => '%',
    'tablet_portrait_page_width' => '100',
    'tablet_portrait_media_query' => 'only screen and (min-width:481px) and (max-width:768px)',
    'smalltouch_landscape_layout' => 'one_col_vert',
    'smalltouch_landscape_sidebar_unit' => '%',
    'smalltouch_landscape_sidebar_first' => '50',
    'smalltouch_landscape_sidebar_second' => '50',
    'smalltouch_landscape_media_query' => 'only screen and (min-width:321px) and (max-width:480px)',
    'smalltouch_landscape_page_width' => '100',
    'smalltouch_landscape_page_unit' => '%',
    'smalltouch_portrait_media_query' => 'only screen and (max-width:320px)',
    'smalltouch_portrait_page_width' => '100',
    'smalltouch_portrait_page_unit' => '%',
    'smalltouch_portrait_sidebar_first' => '100',
    'smalltouch_portrait_sidebar_second' => '100',
    'smalltouch_portrait_sidebar_unit' => '%',
    'smalltouch_portrait_layout' => 'one_col_stack',
    'bigscreen_three_50_25_25' => 'three-50-25-25',
    'bigscreen_three_25_25_50' => 'three-25-25-50',
    'bigscreen_three_3x33' => 'three-3x33',
    'bigscreen_three_25_50_25' => 'three-25-50-25',
    'bigscreen_five_5x20' => 'five-5x20-2x3-grid',
    'bigscreen_two_33_66' => 'two-33-66',
    'bigscreen_two_66_33' => 'two-66-33',
    'bigscreen_two_brick' => 'two-brick',
    'bigscreen_two_50' => 'two-50',
    'bigscreen_four_4x25' => 'four-4x25',
    'bigscreen_six_6x16' => 'six-6x16-3x2-grid',
    'bigscreen_three_inset_left' => 'three-inset-left',
    'bigscreen_three_inset_right' => 'three-inset-right',
    'tablet_landscape_three_50_25_25' => 'three-50-25-25',
    'tablet_landscape_three_25_25_50' => 'three-25-25-50',
    'tablet_landscape_three_3x33' => 'three-3x33',
    'tablet_landscape_three_25_50_25' => 'three-25-50-25',
    'tablet_landscape_five_5x20' => 'five-5x20-2x3-grid',
    'tablet_landscape_two_33_66' => 'two-33-66',
    'tablet_landscape_two_66_33' => 'two-66-33',
    'tablet_landscape_two_brick' => 'two-brick',
    'tablet_landscape_two_50' => 'two-50',
    'tablet_landscape_four_4x25' => 'four-4x25',
    'tablet_landscape_six_6x16' => 'six-6x16-3x2-grid',
    'tablet_landscape_three_inset_left' => 'three-inset-left',
    'tablet_landscape_three_inset_right' => 'three-inset-right',
    'tablet_portrait_three_50_25_25' => 'three-50-25-25-stack-top',
    'tablet_portrait_three_25_25_50' => 'three-25-25-50-stack-top',
    'tablet_portrait_three_3x33' => 'three-3x33-stack-top',
    'tablet_portrait_three_25_50_25' => 'three-25-50-25-stack-top',
    'tablet_portrait_five_5x20' => 'five-5x20-1x2x2-grid',
    'tablet_portrait_two_33_66' => 'two-33-66',
    'tablet_portrait_two_66_33' => 'two-66-33',
    'tablet_portrait_two_brick' => 'two-brick',
    'tablet_portrait_two_50' => 'two-50',
    'tablet_portrait_four_4x25' => 'four-4x25-2x2-grid',
    'tablet_portrait_six_6x16' => 'six-6x16-2x3-grid',
    'tablet_portrait_three_inset_left' => 'three-inset-left-wrap',
    'tablet_portrait_three_inset_right' => 'three-inset-right-wrap',
    'smalltouch_landscape_three_50_25_25' => 'three-50-25-25-stack',
    'smalltouch_landscape_three_25_25_50' => 'three-25-25-50-stack',
    'smalltouch_landscape_three_3x33' => 'three-3x33-stack',
    'smalltouch_landscape_three_25_50_25' => 'three-25-50-25-stack',
    'smalltouch_landscape_five_5x20' => 'five-5x20-stack',
    'smalltouch_landscape_two_33_66' => 'two-33-66-stack',
    'smalltouch_landscape_two_66_33' => 'two-66-33-stack',
    'smalltouch_landscape_two_brick' => 'two-brick-stack',
    'smalltouch_landscape_two_50' => 'two-50-stack',
    'smalltouch_landscape_four_4x25' => 'four-4x25-stack',
    'smalltouch_landscape_six_6x16' => 'six-6x16-stack',
    'smalltouch_landscape_three_inset_left' => 'three-inset-left-stack',
    'smalltouch_landscape_three_inset_right' => 'three-inset-right-stack',
    'global_default_layout_toggle' => 0,
    'global_default_layout' => 'smalltouch-portrait',
    'disable_responsive_styles' => 0,
    'global_files_path' => 'public_files',
    'custom_files_path' => '',
    'combine_css_files' => 0,
    'combine_js_files' => 0,
    'enable_custom_media_queries' => 0,
    'load_html5js' => 1,
    'load_matchmediajs' => 0,
    'load_onmediaqueryjs' => 0,
    'load_ltie8css' => 0,
    'load_respondjs' => 0,
    'load_scalefixjs' => 0,
    'adaptivetheme_meta_viewport' => 'width=device-width, initial-scale=1',
    'adaptivetheme_meta_mobileoptimized' => 'width',
    'adaptivetheme_meta_handheldfriendly' => '1',
    'adaptivetheme_meta_apple_mobile_web_app_capable' => 'yes',
    'adaptivetheme_meta_ie_document_mode' => '',
    'adaptivetheme_meta_clear_type' => 0,
    'expose_regions' => 0,
    'show_window_size' => 0,
    'atcore_version_test' => 0,
    'load_all_panels' => 0,
    'load_all_panels_no_sidebars' => 0,
    'enable_extensions' => 1,
    'enable_font_settings' => 1,
    'enable_heading_settings' => 1,
    'enable_image_settings' => 1,
    'enable_apple_touch_icons' => 0,
    'enable_exclude_css' => 0,
    'enable_custom_css' => 0,
    'enable_context_regions' => 0,
    'enable_menu_toggle' => 0,
    'enable_float_region_blocks' => 0,
    'enable_markup_overides' => 1,
    'at-settings__active_tab' => 'edit-bigscreen',
    'base_font_type' => '',
    'base_font' => 'bf-sss',
    'base_font_gwf' => '',
    'base_font_gwf_add_styles' => 0,
    'base_font_gwf_add_styles_300' => 0,
    'base_font_gwf_add_styles_300italic' => 0,
    'base_font_gwf_add_styles_400' => 0,
    'base_font_gwf_add_styles_400italic' => 0,
    'base_font_gwf_add_styles_700' => 0,
    'base_font_gwf_add_styles_700italic' => 0,
    'base_font_gwf_add_charsets' => 0,
    'base_font_gwf_add_charsets_latin' => 0,
    'base_font_gwf_add_charsets_latin-ext' => 0,
    'base_font_gwf_add_charsets_greek' => 0,
    'base_font_gwf_add_charsets_greek-ext' => 0,
    'base_font_gwf_add_charsets_cyrillic' => 0,
    'base_font_gwf_add_charsets_cyrillic-ext' => 0,
    'base_font_gwf_add_charsets_khmer' => 0,
    'base_font_gwf_add_charsets_vietnamese' => 0,
    'base_font_cfs' => '',
    'base_font_size' => '<none>',
    'site_name_font_type' => '',
    'site_name_font' => 'bf-sss',
    'site_name_font_gwf' => '',
    'site_name_font_gwf_add_styles' => 0,
    'site_name_font_gwf_add_styles_300' => 0,
    'site_name_font_gwf_add_styles_300italic' => 0,
    'site_name_font_gwf_add_styles_400' => 0,
    'site_name_font_gwf_add_styles_400italic' => 0,
    'site_name_font_gwf_add_styles_700' => 0,
    'site_name_font_gwf_add_styles_700italic' => 0,
    'site_name_font_gwf_add_charsets' => 0,
    'site_name_font_gwf_add_charsets_latin' => 0,
    'site_name_font_gwf_add_charsets_latin-ext' => 0,
    'site_name_font_gwf_add_charsets_greek' => 0,
    'site_name_font_gwf_add_charsets_greek-ext' => 0,
    'site_name_font_gwf_add_charsets_cyrillic' => 0,
    'site_name_font_gwf_add_charsets_cyrillic-ext' => 0,
    'site_name_font_gwf_add_charsets_khmer' => 0,
    'site_name_font_gwf_add_charsets_vietnamese' => 0,
    'site_name_font_cfs' => '',
    'site_name_font_size' => '2em',
    'site_slogan_font_type' => '',
    'site_slogan_font' => 'bf-sss',
    'site_slogan_font_gwf' => '',
    'site_slogan_font_gwf_add_styles' => 0,
    'site_slogan_font_gwf_add_styles_300' => 0,
    'site_slogan_font_gwf_add_styles_300italic' => 0,
    'site_slogan_font_gwf_add_styles_400' => 0,
    'site_slogan_font_gwf_add_styles_400italic' => 0,
    'site_slogan_font_gwf_add_styles_700' => 0,
    'site_slogan_font_gwf_add_styles_700italic' => 0,
    'site_slogan_font_gwf_add_charsets' => 0,
    'site_slogan_font_gwf_add_charsets_latin' => 0,
    'site_slogan_font_gwf_add_charsets_latin-ext' => 0,
    'site_slogan_font_gwf_add_charsets_greek' => 0,
    'site_slogan_font_gwf_add_charsets_greek-ext' => 0,
    'site_slogan_font_gwf_add_charsets_cyrillic' => 0,
    'site_slogan_font_gwf_add_charsets_cyrillic-ext' => 0,
    'site_slogan_font_gwf_add_charsets_khmer' => 0,
    'site_slogan_font_gwf_add_charsets_vietnamese' => 0,
    'site_slogan_font_cfs' => '',
    'site_slogan_font_size' => '1.2em',
    'page_title_font_type' => '',
    'page_title_font' => 'bf-sss',
    'page_title_font_gwf' => '',
    'page_title_font_gwf_add_styles' => 0,
    'page_title_font_gwf_add_styles_300' => 0,
    'page_title_font_gwf_add_styles_300italic' => 0,
    'page_title_font_gwf_add_styles_400' => 0,
    'page_title_font_gwf_add_styles_400italic' => 0,
    'page_title_font_gwf_add_styles_700' => 0,
    'page_title_font_gwf_add_styles_700italic' => 0,
    'page_title_font_gwf_add_charsets' => 0,
    'page_title_font_gwf_add_charsets_latin' => 0,
    'page_title_font_gwf_add_charsets_latin-ext' => 0,
    'page_title_font_gwf_add_charsets_greek' => 0,
    'page_title_font_gwf_add_charsets_greek-ext' => 0,
    'page_title_font_gwf_add_charsets_cyrillic' => 0,
    'page_title_font_gwf_add_charsets_cyrillic-ext' => 0,
    'page_title_font_gwf_add_charsets_khmer' => 0,
    'page_title_font_gwf_add_charsets_vietnamese' => 0,
    'page_title_font_cfs' => '',
    'page_title_font_size' => '2em',
    'node_title_font_type' => '',
    'node_title_font' => 'bf-sss',
    'node_title_font_gwf' => '',
    'node_title_font_gwf_add_styles' => 0,
    'node_title_font_gwf_add_styles_300' => 0,
    'node_title_font_gwf_add_styles_300italic' => 0,
    'node_title_font_gwf_add_styles_400' => 0,
    'node_title_font_gwf_add_styles_400italic' => 0,
    'node_title_font_gwf_add_styles_700' => 0,
    'node_title_font_gwf_add_styles_700italic' => 0,
    'node_title_font_gwf_add_charsets' => 0,
    'node_title_font_gwf_add_charsets_latin' => 0,
    'node_title_font_gwf_add_charsets_latin-ext' => 0,
    'node_title_font_gwf_add_charsets_greek' => 0,
    'node_title_font_gwf_add_charsets_greek-ext' => 0,
    'node_title_font_gwf_add_charsets_cyrillic' => 0,
    'node_title_font_gwf_add_charsets_cyrillic-ext' => 0,
    'node_title_font_gwf_add_charsets_khmer' => 0,
    'node_title_font_gwf_add_charsets_vietnamese' => 0,
    'node_title_font_cfs' => '',
    'node_title_font_size' => '1.6em',
    'comment_title_font_type' => '',
    'comment_title_font' => 'bf-sss',
    'comment_title_font_gwf' => '',
    'comment_title_font_gwf_add_styles' => 0,
    'comment_title_font_gwf_add_styles_300' => 0,
    'comment_title_font_gwf_add_styles_300italic' => 0,
    'comment_title_font_gwf_add_styles_400' => 0,
    'comment_title_font_gwf_add_styles_400italic' => 0,
    'comment_title_font_gwf_add_styles_700' => 0,
    'comment_title_font_gwf_add_styles_700italic' => 0,
    'comment_title_font_gwf_add_charsets' => 0,
    'comment_title_font_gwf_add_charsets_latin' => 0,
    'comment_title_font_gwf_add_charsets_latin-ext' => 0,
    'comment_title_font_gwf_add_charsets_greek' => 0,
    'comment_title_font_gwf_add_charsets_greek-ext' => 0,
    'comment_title_font_gwf_add_charsets_cyrillic' => 0,
    'comment_title_font_gwf_add_charsets_cyrillic-ext' => 0,
    'comment_title_font_gwf_add_charsets_khmer' => 0,
    'comment_title_font_gwf_add_charsets_vietnamese' => 0,
    'comment_title_font_cfs' => '',
    'comment_title_font_size' => '1.4em',
    'block_title_font_type' => '',
    'block_title_font' => 'bf-sss',
    'block_title_font_gwf' => '',
    'block_title_font_gwf_add_styles' => 0,
    'block_title_font_gwf_add_styles_300' => 0,
    'block_title_font_gwf_add_styles_300italic' => 0,
    'block_title_font_gwf_add_styles_400' => 0,
    'block_title_font_gwf_add_styles_400italic' => 0,
    'block_title_font_gwf_add_styles_700' => 0,
    'block_title_font_gwf_add_styles_700italic' => 0,
    'block_title_font_gwf_add_charsets' => 0,
    'block_title_font_gwf_add_charsets_latin' => 0,
    'block_title_font_gwf_add_charsets_latin-ext' => 0,
    'block_title_font_gwf_add_charsets_greek' => 0,
    'block_title_font_gwf_add_charsets_greek-ext' => 0,
    'block_title_font_gwf_add_charsets_cyrillic' => 0,
    'block_title_font_gwf_add_charsets_cyrillic-ext' => 0,
    'block_title_font_gwf_add_charsets_khmer' => 0,
    'block_title_font_gwf_add_charsets_vietnamese' => 0,
    'block_title_font_cfs' => '',
    'block_title_font_size' => '1.4em',
    'content_headings_h1h4_font_type' => '',
    'content_headings_h1h4_font' => 'bf-sss',
    'content_headings_h1h4_font_gwf' => '',
    'content_headings_h1h4_font_gwf_add_styles' => 0,
    'content_headings_h1h4_font_gwf_add_styles_300' => 0,
    'content_headings_h1h4_font_gwf_add_styles_300italic' => 0,
    'content_headings_h1h4_font_gwf_add_styles_400' => 0,
    'content_headings_h1h4_font_gwf_add_styles_400italic' => 0,
    'content_headings_h1h4_font_gwf_add_styles_700' => 0,
    'content_headings_h1h4_font_gwf_add_styles_700italic' => 0,
    'content_headings_h1h4_font_gwf_add_charsets' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_latin' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_latin-ext' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_greek' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_greek-ext' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_cyrillic' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_cyrillic-ext' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_khmer' => 0,
    'content_headings_h1h4_font_gwf_add_charsets_vietnamese' => 0,
    'content_headings_h1h4_font_cfs' => '',
    'content_headings_h5h6_font_type' => '',
    'content_headings_h5h6_font' => 'bf-sss',
    'content_headings_h5h6_font_gwf' => '',
    'content_headings_h5h6_font_gwf_add_styles' => 0,
    'content_headings_h5h6_font_gwf_add_styles_300' => 0,
    'content_headings_h5h6_font_gwf_add_styles_300italic' => 0,
    'content_headings_h5h6_font_gwf_add_styles_400' => 0,
    'content_headings_h5h6_font_gwf_add_styles_400italic' => 0,
    'content_headings_h5h6_font_gwf_add_styles_700' => 0,
    'content_headings_h5h6_font_gwf_add_styles_700italic' => 0,
    'content_headings_h5h6_font_gwf_add_charsets' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_latin' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_latin-ext' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_greek' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_greek-ext' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_cyrillic' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_cyrillic-ext' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_khmer' => 0,
    'content_headings_h5h6_font_gwf_add_charsets_vietnamese' => 0,
    'content_headings_h5h6_font_cfs' => '',
    'h1_font_size' => '2em',
    'h2_font_size' => '1.6em',
    'h3_font_size' => '1.4em',
    'h4_font_size' => '1.2em',
    'h5_font_size' => '1em',
    'h6_font_size' => '1em',
    'main_menu_font_type' => '',
    'main_menu_font' => 'bf-sss',
    'main_menu_font_gwf' => '',
    'main_menu_font_gwf_add_styles' => 0,
    'main_menu_font_gwf_add_styles_300' => 0,
    'main_menu_font_gwf_add_styles_300italic' => 0,
    'main_menu_font_gwf_add_styles_400' => 0,
    'main_menu_font_gwf_add_styles_400italic' => 0,
    'main_menu_font_gwf_add_styles_700' => 0,
    'main_menu_font_gwf_add_styles_700italic' => 0,
    'main_menu_font_gwf_add_charsets' => 0,
    'main_menu_font_gwf_add_charsets_latin' => 0,
    'main_menu_font_gwf_add_charsets_latin-ext' => 0,
    'main_menu_font_gwf_add_charsets_greek' => 0,
    'main_menu_font_gwf_add_charsets_greek-ext' => 0,
    'main_menu_font_gwf_add_charsets_cyrillic' => 0,
    'main_menu_font_gwf_add_charsets_cyrillic-ext' => 0,
    'main_menu_font_gwf_add_charsets_khmer' => 0,
    'main_menu_font_gwf_add_charsets_vietnamese' => 0,
    'main_menu_font_cfs' => '',
    'main_menu_font_size' => '<none>',
    'secondary_menu_font_type' => '',
    'secondary_menu_font' => 'bf-sss',
    'secondary_menu_font_gwf' => '',
    'secondary_menu_font_gwf_add_styles' => 0,
    'secondary_menu_font_gwf_add_styles_300' => 0,
    'secondary_menu_font_gwf_add_styles_300italic' => 0,
    'secondary_menu_font_gwf_add_styles_400' => 0,
    'secondary_menu_font_gwf_add_styles_400italic' => 0,
    'secondary_menu_font_gwf_add_styles_700' => 0,
    'secondary_menu_font_gwf_add_styles_700italic' => 0,
    'secondary_menu_font_gwf_add_charsets' => 0,
    'secondary_menu_font_gwf_add_charsets_latin' => 0,
    'secondary_menu_font_gwf_add_charsets_latin-ext' => 0,
    'secondary_menu_font_gwf_add_charsets_greek' => 0,
    'secondary_menu_font_gwf_add_charsets_greek-ext' => 0,
    'secondary_menu_font_gwf_add_charsets_cyrillic' => 0,
    'secondary_menu_font_gwf_add_charsets_cyrillic-ext' => 0,
    'secondary_menu_font_gwf_add_charsets_khmer' => 0,
    'secondary_menu_font_gwf_add_charsets_vietnamese' => 0,
    'secondary_menu_font_cfs' => '',
    'secondary_menu_font_size' => '<none>',
    'block_menu_font_type' => '',
    'block_menu_font' => 'bf-sss',
    'block_menu_font_gwf' => '',
    'block_menu_font_gwf_add_styles' => 0,
    'block_menu_font_gwf_add_styles_300' => 0,
    'block_menu_font_gwf_add_styles_300italic' => 0,
    'block_menu_font_gwf_add_styles_400' => 0,
    'block_menu_font_gwf_add_styles_400italic' => 0,
    'block_menu_font_gwf_add_styles_700' => 0,
    'block_menu_font_gwf_add_styles_700italic' => 0,
    'block_menu_font_gwf_add_charsets' => 0,
    'block_menu_font_gwf_add_charsets_latin' => 0,
    'block_menu_font_gwf_add_charsets_latin-ext' => 0,
    'block_menu_font_gwf_add_charsets_greek' => 0,
    'block_menu_font_gwf_add_charsets_greek-ext' => 0,
    'block_menu_font_gwf_add_charsets_cyrillic' => 0,
    'block_menu_font_gwf_add_charsets_cyrillic-ext' => 0,
    'block_menu_font_gwf_add_charsets_khmer' => 0,
    'block_menu_font_gwf_add_charsets_vietnamese' => 0,
    'block_menu_font_cfs' => '',
    'block_menu_font_size' => '<none>',
    'selectors_font_type' => '',
    'selectors_font' => 'bf-sss',
    'selectors_font_gwf' => '',
    'selectors_font_add_styles' => 0,
    'selectors_font_add_styles_300' => 0,
    'selectors_font_add_styles_300italic' => 0,
    'selectors_font_add_styles_400' => 0,
    'selectors_font_add_styles_400italic' => 0,
    'selectors_font_add_styles_700' => 0,
    'selectors_font_add_styles_700italic' => 0,
    'selectors_font_add_charsets' => 0,
    'selectors_font_add_charsets_latin' => 0,
    'selectors_font_add_charsets_latin-ext' => 0,
    'selectors_font_add_charsets_greek' => 0,
    'selectors_font_add_charsets_greek-ext' => 0,
    'selectors_font_add_charsets_cyrillic' => 0,
    'selectors_font_add_charsets_cyrillic-ext' => 0,
    'selectors_font_add_charsets_khmer' => 0,
    'selectors_font_add_charsets_vietnamese' => 0,
    'selectors_font_cfs' => '',
    'selectors_css' => '',
    'site_name_case' => 'snc-n',
    'site_name_weight' => 'snw-n',
    'site_name_alignment' => 'sna-l',
    'site_name_shadow' => 'sns-n',
    'site_slogan_case' => 'ssc-n',
    'site_slogan_weight' => 'ssw-n',
    'site_slogan_alignment' => 'ssa-l',
    'site_slogan_shadow' => 'sss-n',
    'page_title_case' => 'ptc-n',
    'page_title_weight' => 'ptw-b',
    'page_title_alignment' => 'pta-l',
    'page_title_shadow' => 'pts-n',
    'node_title_case' => 'ntc-n',
    'node_title_weight' => 'ntw-b',
    'node_title_alignment' => 'nta-l',
    'node_title_shadow' => 'nts-n',
    'comment_title_case' => 'ctc-n',
    'comment_title_weight' => 'ctw-b',
    'comment_title_alignment' => 'cta-l',
    'comment_title_shadow' => 'cts-n',
    'block_title_case' => 'btc-n',
    'block_title_weight' => 'btw-b',
    'block_title_alignment' => 'bta-l',
    'block_title_shadow' => 'bts-n',
    'image_alignment' => 'ia-n',
    'image_alignment_teaser' => 'iat-n',
    'image_caption_teaser' => 0,
    'image_caption_full' => 0,
    'image_teaser' => 0,
    'global_gutter_width' => '',
    'page_content_type_suggestions' => 0,
    'menu_item_span_elements' => 0,
    'breadcrumb_display' => 1,
    'breadcrumb_home' => 0,
    'breadcrumb_label' => 0,
    'breadcrumb_title' => 1,
    'breadcrumb_separator' => ' &#187; ',
    'login_block_remove_links' => 0,
    'login_block_remove_openid' => 0,
    'horizontal_login_block' => 0,
    'user_block_user_name' => 1,
    'frontpage_remove_title' => 0,
    'unset_block_system_main_front' => 0,
    'feed_icons_hide' => 0,
    'comments_hide_title' => 1,
    'unset_menu_titles' => 0,
    'unset_local_tasks' => 0,
    'adv_search_extra_fieldsets' => 0,
    'skip_link_target' => '#main-content',
    'rel_author' => 0,
    'logo_title' => 1,
    'extra_page_classes' => 1,
    'extra_article_classes' => 1,
    'extra_comment_classes' => 1,
    'extra_block_classes' => 1,
    'extra_menu_classes' => 1,
    'extra_item_list_classes' => 1,
    'attribution_toggle' => 1,
    'corner_radius' => 'rc-0',
    'box_shadows' => 'bs-n',
    'body_background' => 'bb-n',
    'menu_bar_position' => 'mbp-r',
    'menu_bullets' => 'mb-dd',
    'at__active_tab' => 'edit-font',
    'at-release' => '7.x-3.x',
    'at-color' => '1',
    'scheme' => 'gothic',
    'palette' => array(
      'base' => '#202020',
      'page' => '#ffffff',
      'sitename' => '#feffff',
      'slogan' => '#fefefe',
      'header' => '#fdfdfd',
      'mmenu' => '#fffffe',
      'link' => '#11275f',
      'top' => '#000000',
      'bottom' => '#808080',
      'ftop' => '#181818',
      'fbottom' => '#343434',
      'text' => '#000000',
      'blockh' => '#2b2b2b',
      'blockht' => '#ffffff',
      'blockbg' => '#bdbdbd',
      'borders' => '#bdbdbd',
      'sticky' => '#bdbdbd',
    ),
    'theme' => 'pixture_reloaded',
    'info' => array(
      'fields' => array(
        'base' => 'Base',
        'page' => 'Page background',
        'sitename' => 'Site name',
        'slogan' => 'Slogan',
        'header' => 'Header text',
        'mmenu' => 'Main Menu links',
        'link' => 'Links',
        'top' => 'Header top',
        'bottom' => 'Header bottom',
        'ftop' => 'Footer top',
        'fbottom' => 'Footer bottom',
        'text' => 'Text',
        'blockh' => 'Block title bg',
        'blockht' => 'Block title',
        'blockbg' => 'Block body',
        'borders' => 'Borders',
        'sticky' => 'Sticky teaser',
      ),
      'schemes' => array(
        'default' => array(
          'title' => 'Girly Pink (default)',
          'colors' => array(
            'base' => '#eb52c1',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#b21f88',
            'top' => '#b800a5',
            'bottom' => '#ff6bff',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#eb5ac3',
            'blockht' => '#fffffc',
            'blockbg' => '#f9cbec',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'redcarpet' => array(
          'title' => 'Red Carpet',
          'colors' => array(
            'base' => '#de8291',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#c55964',
            'top' => '#861509',
            'bottom' => '#f8306a',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#df8796',
            'blockht' => '#fffffc',
            'blockbg' => '#f5d9de',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'orangesunset' => array(
          'title' => 'Orange Sunset',
          'colors' => array(
            'base' => '#f7b42b',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#8e6130',
            'top' => '#ec8c04',
            'bottom' => '#fade42',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#f7b836',
            'blockht' => '#fffffc',
            'blockbg' => '#fde9c0',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'goldyellow' => array(
          'title' => 'Gold Yellow',
          'colors' => array(
            'base' => '#d1bc00',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#6c7019',
            'top' => '#d5be01',
            'bottom' => '#f0fd58',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#d3bf0d',
            'blockht' => '#fffffc',
            'blockbg' => '#f1ebb3',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'sandstone' => array(
          'title' => 'Sandstone',
          'colors' => array(
            'base' => '#d1681d',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#8b4513',
            'top' => '#d37029',
            'bottom' => '#d2691e',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#000000',
            'blockh' => '#d37029',
            'blockht' => '#fffffc',
            'blockbg' => '#f1d2bc',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'caramelbrown' => array(
          'title' => 'Caramel Brown',
          'colors' => array(
            'base' => '#d59648',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#865518',
            'top' => '#572e05',
            'bottom' => '#eb8919',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#d79b51',
            'blockht' => '#fffffc',
            'blockbg' => '#f2e0c8',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'earthbrown' => array(
          'title' => 'Earth Brown',
          'colors' => array(
            'base' => '#cfb377',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#90712c',
            'top' => '#463406',
            'bottom' => '#e6bd5c',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#d1b77e',
            'blockht' => '#fffffc',
            'blockbg' => '#f1e8d6',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'olivegarden' => array(
          'title' => 'Olive Garden',
          'colors' => array(
            'base' => '#afc94a',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#61751f',
            'top' => '#2d3701',
            'bottom' => '#d2f943',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#b3cc53',
            'blockht' => '#fffffc',
            'blockbg' => '#e7efc9',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'forestgreen' => array(
          'title' => 'Forest Green',
          'colors' => array(
            'base' => '#9bc068',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#3c7c41',
            'top' => '#0e3d0b',
            'bottom' => '#6beb37',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#a0c370',
            'blockht' => '#fffffc',
            'blockbg' => '#e1ecd2',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'teal' => array(
          'title' => 'Teal',
          'colors' => array(
            'base' => '#83b49f',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#486156',
            'top' => '#174431',
            'bottom' => '#52bf90',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#89b8a4',
            'blockht' => '#fffffc',
            'blockbg' => '#dae9e2',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'aquamarine' => array(
          'title' => 'Aquamarine',
          'colors' => array(
            'base' => '#55c0e2',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#000000',
            'top' => '#085360',
            'bottom' => '#007e94',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#5ec3e3',
            'blockht' => '#fffffc',
            'blockbg' => '#ccecf6',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'oceanwater' => array(
          'title' => 'Ocean Water',
          'colors' => array(
            'base' => '#7bc0ea',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#3561b1',
            'top' => '#025fb1',
            'bottom' => '#62c8fd',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#82c3eb',
            'blockht' => '#fffffc',
            'blockbg' => '#d8ecf9',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'deepblue' => array(
          'title' => 'Deep Blue',
          'colors' => array(
            'base' => '#1c44a9',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#4b5cc3',
            'top' => '#062984',
            'bottom' => '#5283ff',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#284ead',
            'blockht' => '#fffffc',
            'blockbg' => '#bbc7e5',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'graphite' => array(
          'title' => 'Graphite',
          'colors' => array(
            'base' => '#9397d7',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#575dc1',
            'top' => '#091c3e',
            'bottom' => '#d0d6f6',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#203254',
            'blockht' => '#fffffc',
            'blockbg' => '#dfe0f3',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'violet' => array(
          'title' => 'Violet',
          'colors' => array(
            'base' => '#ba90c6',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#935b9f',
            'top' => '#250c27',
            'bottom' => '#c271d0',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#be96c9',
            'blockht' => '#fffffc',
            'blockbg' => '#eadeee',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'purplehaze' => array(
          'title' => 'Purple Haze',
          'colors' => array(
            'base' => '#b0a2f6',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#7958a7',
            'top' => '#25008f',
            'bottom' => '#c49eff',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#b4a7f6',
            'blockht' => '#fffffc',
            'blockbg' => '#e7e3fC',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'silver' => array(
          'title' => 'Silver',
          'colors' => array(
            'base' => '#aaaeb1',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#4d637a',
            'top' => '#8c909b',
            'bottom' => '#eeecec',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#aeb2b5',
            'blockht' => '#fffffc',
            'blockbg' => '#e6e7e8',
            'borders' => '#e9e9e9',
            'sticky' => '#f7f7f7',
          ),
        ),
        'ash' => array(
          'title' => 'Ash',
          'colors' => array(
            'base' => '#464849',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#2f416f',
            'top' => '#2a2b2d',
            'bottom' => '#5d6779',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#555555',
            'blockh' => '#4f5152',
            'blockht' => '#ffffff',
            'blockbg' => '#c8c8c9',
            'borders' => '#c8c8c9',
            'sticky' => '#c8c8c9',
          ),
        ),
        'gothic' => array(
          'title' => 'Gothic',
          'colors' => array(
            'base' => '#202020',
            'page' => '#ffffff',
            'sitename' => '#feffff',
            'slogan' => '#fefefe',
            'header' => '#fdfdfd',
            'mmenu' => '#fffffe',
            'link' => '#11275f',
            'top' => '#000000',
            'bottom' => '#808080',
            'ftop' => '#181818',
            'fbottom' => '#343434',
            'text' => '#000000',
            'blockh' => '#2b2b2b',
            'blockht' => '#ffffff',
            'blockbg' => '#bdbdbd',
            'borders' => '#bdbdbd',
            'sticky' => '#bdbdbd',
          ),
        ),
        '' => array(
          'title' => 'Custom',
          'colors' => array(),
        ),
      ),
      'css' => array(
        0 => 'color/colors.css',
      ),
      'copy' => array(
        0 => 'images/bullet-round.png',
        1 => 'images/bullet-sm-arrow-right.png',
        2 => 'images/bullet-sm-arrow-down.png',
        3 => 'images/button.gif',
        4 => 'images/button-o.gif',
      ),
      'gradients' => array(
        0 => array(
          'dimension' => array(
            0 => 0,
            1 => 0,
            2 => 800,
            3 => 94,
          ),
          'direction' => 'vertical',
          'colors' => array(
            0 => 'top',
            1 => 'bottom',
          ),
        ),
      ),
      'fill' => array(
        'base' => array(
          0 => 0,
          1 => 0,
          2 => 800,
          3 => 570,
        ),
        'link' => array(
          0 => 240,
          1 => 530,
          2 => 40,
          3 => 40,
        ),
      ),
      'slices' => array(
        'images/header.png' => array(
          0 => 2,
          1 => 0,
          2 => 512,
          3 => 88,
        ),
        'images/header-tile.png' => array(
          0 => 792,
          1 => 0,
          2 => 8,
          3 => 88,
        ),
        'images/menu-tile.png' => array(
          0 => 792,
          1 => 0,
          2 => 8,
          3 => 32,
        ),
        'images/bg-footer.png' => array(
          0 => 792,
          1 => 0,
          2 => 8,
          3 => 88,
        ),
        'images/bg-footer-tile.png' => array(
          0 => 792,
          1 => 87,
          2 => 1,
          3 => 1,
        ),
        'images/bg-menu.png' => array(
          0 => 0,
          1 => 88,
          2 => 8,
          3 => 32,
        ),
        'images/bg-title.png' => array(
          0 => 20,
          1 => 130,
          2 => 10,
          3 => 10,
        ),
        'images/bg-wall.png' => array(
          0 => 792,
          1 => 120,
          2 => 8,
          3 => 408,
        ),
        'images/bg-bar-lite.png' => array(
          0 => 0,
          1 => 530,
          2 => 8,
          3 => 40,
        ),
        'images/bg-bar.png' => array(
          0 => 20,
          1 => 530,
          2 => 8,
          3 => 40,
        ),
        'images/bg-lbar-lite.png' => array(
          0 => 270,
          1 => 530,
          2 => 8,
          3 => 40,
        ),
        'images/bg-lbar.png' => array(
          0 => 250,
          1 => 530,
          2 => 8,
          3 => 40,
        ),
        'images/sf-hover-tile.png' => array(
          0 => 0,
          1 => 30,
          2 => 250,
          3 => 1,
        ),
      ),
      'blend_target' => '#ffffff',
      'preview_image' => 'color/color-preview.png',
      'preview_css' => 'color/preview.css',
      'base_image' => 'color/base.png',
    ),
    'favicon_mimetype' => 'image/jpeg',
  );
  $export['theme_pixture_reloaded_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 0,
    'toggle_favicon' => 0,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 0,
    'default_logo' => 0,
    'logo_path' => 'sites/all/themes/almostengr/ae_logo.jpg',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'sites/all/themes/almostengr/ae_logo.jpg',
    'favicon_upload' => '',
    'favicon_mimetype' => 'image/jpeg',
  );
  $export['theme_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_124';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city !zone_code  !postal_code
!country_name_if';
  $export['uc_address_format_124'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_840';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city, !zone_code !postal_code
!country_name_if';
  $export['uc_address_format_840'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_add_item_redirect';
  $strongarm->value = 'cart';
  $export['uc_add_item_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_cart_form_enabled';
  $strongarm->value = 1;
  $export['uc_cap_cart_form_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_cart_form_weight';
  $strongarm->value = '0';
  $export['uc_cap_cart_form_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_add_item_msg';
  $strongarm->value = 1;
  $export['uc_cart_add_item_msg'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_anon_duration';
  $strongarm->value = '1';
  $export['uc_cart_anon_duration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_anon_unit';
  $strongarm->value = 'hours';
  $export['uc_cart_anon_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_auth_duration';
  $strongarm->value = '6';
  $export['uc_cart_auth_duration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_auth_unit';
  $strongarm->value = 'hours';
  $export['uc_cart_auth_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_collapsed';
  $strongarm->value = 1;
  $export['uc_cart_block_collapsed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_collapsible';
  $strongarm->value = 1;
  $export['uc_cart_block_collapsible'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_empty_hide';
  $strongarm->value = 1;
  $export['uc_cart_block_empty_hide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_image';
  $strongarm->value = 1;
  $export['uc_cart_block_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_breadcrumb_text';
  $strongarm->value = '';
  $export['uc_cart_breadcrumb_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_breadcrumb_url';
  $strongarm->value = '';
  $export['uc_cart_breadcrumb_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_checkout_complete_page';
  $strongarm->value = '';
  $export['uc_cart_checkout_complete_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_default_same_address';
  $strongarm->value = 1;
  $export['uc_cart_default_same_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_delivery_not_shippable';
  $strongarm->value = 1;
  $export['uc_cart_delivery_not_shippable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_email_validation';
  $strongarm->value = 1;
  $export['uc_cart_email_validation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_empty_button';
  $strongarm->value = 0;
  $export['uc_cart_empty_button'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_mail_existing';
  $strongarm->value = 1;
  $export['uc_cart_mail_existing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_details';
  $strongarm->value = '<b>Optional.</b> New customers may supply custom account details.<br />We will create these for you if no values are entered.';
  $export['uc_cart_new_account_details'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_name';
  $strongarm->value = 0;
  $export['uc_cart_new_account_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_password';
  $strongarm->value = 0;
  $export['uc_cart_new_account_password'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_show_help_text';
  $strongarm->value = 0;
  $export['uc_cart_show_help_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_catalog_breadcrumb';
  $strongarm->value = 1;
  $export['uc_catalog_breadcrumb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_catalog_display';
  $strongarm->value = 'catalog';
  $export['uc_catalog_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_catalog_vid';
  $strongarm->value = '3';
  $export['uc_catalog_vid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_anonymous';
  $strongarm->value = 1;
  $export['uc_checkout_anonymous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_enabled';
  $strongarm->value = 1;
  $export['uc_checkout_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_instructions';
  $strongarm->value = '';
  $export['uc_checkout_instructions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_review_instructions';
  $strongarm->value = '<p>Your order is almost complete. Please review the details below and click \'Submit order\' if all the information is correct.  You may use the \'Back\' button to make changes to your order if necessary.</p>';
  $export['uc_checkout_review_instructions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_collapse_current_pane';
  $strongarm->value = 1;
  $export['uc_collapse_current_pane'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_type';
  $strongarm->value = 'link';
  $export['uc_continue_shopping_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_url';
  $strongarm->value = '';
  $export['uc_continue_shopping_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_use_last_url';
  $strongarm->value = 1;
  $export['uc_continue_shopping_use_last_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_code';
  $strongarm->value = 'USD';
  $export['uc_currency_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_dec';
  $strongarm->value = '.';
  $export['uc_currency_dec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_prec';
  $strongarm->value = '2';
  $export['uc_currency_prec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_sign';
  $strongarm->value = '$';
  $export['uc_currency_sign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_thou';
  $strongarm->value = ',';
  $export['uc_currency_thou'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_customer_list_address';
  $strongarm->value = 'billing';
  $export['uc_customer_list_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_footer_message';
  $strongarm->value = 'none';
  $export['uc_footer_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_googleanalytics_version';
  $strongarm->value = 'analytics.js';
  $export['uc_googleanalytics_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_image_product';
  $strongarm->value = '';
  $export['uc_image_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_cm';
  $strongarm->value = '!value cm';
  $export['uc_length_format_cm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_ft';
  $strongarm->value = '!value ft';
  $export['uc_length_format_ft'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_in';
  $strongarm->value = '!value in';
  $export['uc_length_format_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_mm';
  $strongarm->value = '!value mm';
  $export['uc_length_format_mm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_unit';
  $strongarm->value = 'in';
  $export['uc_length_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_minimum_subtotal';
  $strongarm->value = 0;
  $export['uc_minimum_subtotal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_continue_shopping';
  $strongarm->value = '<p><a href="[site:url]">Return to the front page.</a></p>';
  $export['uc_msg_continue_shopping'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_existing_user';
  $strongarm->value = '<p>Thank you for shopping at [store:name]. Your current order has been attached to the account we found matching your e-mail address.
<br /><br />
<a href="[site:login-url]">Login</a> to view your current order status and order history. Remember to login when you make your next purchase for a faster checkout experience!</p>';
  $export['uc_msg_order_existing_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_logged_in';
  $strongarm->value = '<p>Thank you for shopping at [store:name]. While logged in, you may continue shopping or <a href="[uc_order:url]">view your current order status</a> and order history.</p>';
  $export['uc_msg_order_logged_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_new_user';
  $strongarm->value = '<p>Thank you for shopping at [store:name]. A new account has been created for you here that you may use to view your current order status.
<br /><br />
<a href="[site:login-url]">Login</a> to your new account using the following information:
<br /><br />
<strong>Username:</strong> !new_username<br />
<strong>Password:</strong> !new_password</p>';
  $export['uc_msg_order_new_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_new_user_logged_in';
  $strongarm->value = '<p>Thank you for shopping at [store:name]. A new account has been created for you here that you may use to view your current order status.
<br /><br />
Your password and further instructions have been sent to your e-mail address.
<br /><br />
For your convenience, you are already logged in with your newly created account.</p>';
  $export['uc_msg_order_new_user_logged_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_submit';
  $strongarm->value = '<p>Your order is complete! Your order number is [uc_order:order-number].</p>';
  $export['uc_msg_order_submit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_new_customer_email';
  $strongarm->value = 1;
  $export['uc_new_customer_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_new_customer_login';
  $strongarm->value = 0;
  $export['uc_new_customer_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_new_customer_status_active';
  $strongarm->value = 1;
  $export['uc_new_customer_status_active'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_order_capitalize_addresses';
  $strongarm->value = 1;
  $export['uc_order_capitalize_addresses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_billing_enabled';
  $strongarm->value = 1;
  $export['uc_pane_billing_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_billing_weight';
  $strongarm->value = '4';
  $export['uc_pane_billing_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_cart_enabled';
  $strongarm->value = 1;
  $export['uc_pane_cart_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_cart_weight';
  $strongarm->value = '1';
  $export['uc_pane_cart_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_comments_enabled';
  $strongarm->value = 1;
  $export['uc_pane_comments_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_comments_weight';
  $strongarm->value = '7';
  $export['uc_pane_comments_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_customer_enabled';
  $strongarm->value = 1;
  $export['uc_pane_customer_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_customer_weight';
  $strongarm->value = '2';
  $export['uc_pane_customer_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_delivery_enabled';
  $strongarm->value = 1;
  $export['uc_pane_delivery_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_delivery_weight';
  $strongarm->value = '3';
  $export['uc_pane_delivery_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_payment_enabled';
  $strongarm->value = 1;
  $export['uc_pane_payment_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_payment_weight';
  $strongarm->value = '6';
  $export['uc_pane_payment_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_free_order_checkout';
  $strongarm->value = 1;
  $export['uc_payment_method_free_order_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_free_order_weight';
  $strongarm->value = '0';
  $export['uc_payment_method_free_order_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_ec_checkout';
  $strongarm->value = 0;
  $export['uc_payment_method_paypal_ec_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_ec_weight';
  $strongarm->value = '1';
  $export['uc_payment_method_paypal_ec_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_wps_checkout';
  $strongarm->value = 1;
  $export['uc_payment_method_paypal_wps_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_wps_weight';
  $strongarm->value = '1';
  $export['uc_payment_method_paypal_wps_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_show_order_total_preview';
  $strongarm->value = 1;
  $export['uc_payment_show_order_total_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_add_to_cart_qty';
  $strongarm->value = 1;
  $export['uc_product_add_to_cart_qty'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_image_widget';
  $strongarm->value = '';
  $export['uc_product_image_widget'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_kit_mutable';
  $strongarm->value = '0';
  $export['uc_product_kit_mutable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_shippable_product';
  $strongarm->value = 0;
  $export['uc_product_shippable_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_update_node_view';
  $strongarm->value = 1;
  $export['uc_product_update_node_view'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_by_quantity';
  $strongarm->value = 1;
  $export['uc_roles_default_by_quantity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_end_expiration';
  $strongarm->value = 'rel';
  $export['uc_roles_default_end_expiration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_end_time';
  $strongarm->value = array(
    'year' => '2018',
    'month' => '1',
    'day' => '26',
  );
  $export['uc_roles_default_end_time'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_granularity';
  $strongarm->value = 'month';
  $export['uc_roles_default_granularity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_length';
  $strongarm->value = '6';
  $export['uc_roles_default_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_role';
  $strongarm->value = '9';
  $export['uc_roles_default_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_role_choices';
  $strongarm->value = array(
    9 => '9',
    10 => '10',
    6 => 0,
    11 => 0,
    3 => 0,
  );
  $export['uc_roles_default_role_choices'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_default_show_expiration';
  $strongarm->value = 1;
  $export['uc_roles_default_show_expiration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_reminder_granularity';
  $strongarm->value = 'week';
  $export['uc_roles_reminder_granularity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_roles_reminder_length';
  $strongarm->value = '3';
  $export['uc_roles_reminder_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_sign_after_amount';
  $strongarm->value = 0;
  $export['uc_sign_after_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_city';
  $strongarm->value = 'Montgomery';
  $export['uc_store_city'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_country';
  $strongarm->value = '840';
  $export['uc_store_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_email';
  $strongarm->value = 'bitsecondtech@gmail.com';
  $export['uc_store_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_email_include_name';
  $strongarm->value = 1;
  $export['uc_store_email_include_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_fax';
  $strongarm->value = '';
  $export['uc_store_fax'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_help_page';
  $strongarm->value = '';
  $export['uc_store_help_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_name';
  $strongarm->value = 'Bit Second Tech';
  $export['uc_store_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_owner';
  $strongarm->value = '';
  $export['uc_store_owner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_phone';
  $strongarm->value = '(205) 928-8248';
  $export['uc_store_phone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_postal_code';
  $strongarm->value = '';
  $export['uc_store_postal_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_street1';
  $strongarm->value = '';
  $export['uc_store_street1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_street2';
  $strongarm->value = '';
  $export['uc_store_street2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_zone';
  $strongarm->value = '1';
  $export['uc_store_zone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_use_next_buttons';
  $strongarm->value = 0;
  $export['uc_use_next_buttons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_g';
  $strongarm->value = '!value g';
  $export['uc_weight_format_g'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_kg';
  $strongarm->value = '!value kg';
  $export['uc_weight_format_kg'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_lb';
  $strongarm->value = '!value lb';
  $export['uc_weight_format_lb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_oz';
  $strongarm->value = '!value oz';
  $export['uc_weight_format_oz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_unit';
  $strongarm->value = 'lb';
  $export['uc_weight_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_check_disabled';
  $strongarm->value = 1;
  $export['update_check_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_check_frequency';
  $strongarm->value = '1';
  $export['update_check_frequency'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_last_email_notification';
  $strongarm->value = 1516853914;
  $export['update_last_email_notification'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_notification_threshold';
  $strongarm->value = 'security';
  $export['update_notification_threshold'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'update_notify_emails';
  $strongarm->value = array(
    0 => 'webmaint@bitsecondtech.com',
  );
  $export['update_notify_emails'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_admin_role';
  $strongarm->value = '3';
  $export['user_admin_role'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_cancel_method';
  $strongarm->value = 'user_cancel_block';
  $export['user_cancel_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_default_timezone';
  $strongarm->value = '2';
  $export['user_default_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_email_verification';
  $strongarm->value = TRUE;
  $export['user_email_verification'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_failed_login_ip_limit';
  $strongarm->value = '5';
  $export['user_failed_login_ip_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_failed_login_ip_window';
  $strongarm->value = '10800';
  $export['user_failed_login_ip_window'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_failed_login_user_limit';
  $strongarm->value = '5';
  $export['user_failed_login_user_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_failed_login_user_window';
  $strongarm->value = '3600';
  $export['user_failed_login_user_window'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_cancel_confirm_body';
  $strongarm->value = '[user:name],

A request to cancel your account has been made at [site:name].

You may now cancel your account on [site:url-brief] by clicking this link or copying and pasting it into your browser:

[user:cancel-url]

NOTE: The cancellation of your account is not reversible.

This link expires in one day and nothing will happen if it is not used.

--  [site:name] team';
  $export['user_mail_cancel_confirm_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_cancel_confirm_subject';
  $strongarm->value = 'Account cancellation request for [user:name] at [site:name]';
  $export['user_mail_cancel_confirm_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_body';
  $strongarm->value = '[user:name],

A request to reset the password for your account has been made at [site:name].

You may now log in by clicking this link or copying and pasting it to your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password. It expires after one day and nothing will happen if it\'s not used.

--  [site:name] team';
  $export['user_mail_password_reset_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_password_reset_subject';
  $strongarm->value = 'Replacement login information for [user:name] at [site:name]';
  $export['user_mail_password_reset_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_body';
  $strongarm->value = '[user:name],

A site administrator at [site:name] has created an account for you. You may now log in by clicking this link or copying and pasting it to your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password.

After setting your password, you will be able to log in at [site:login-url] in the future using:

username: [user:name]
password: Your password

--  [site:name] team';
  $export['user_mail_register_admin_created_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_admin_created_subject';
  $strongarm->value = 'Account Details - [site:name]';
  $export['user_mail_register_admin_created_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_body';
  $strongarm->value = '[user:name],

Thank you for registering at [site:name]. You may now log in by clicking this link or copying and pasting it to your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password.

--
[site:name] team';
  $export['user_mail_register_no_approval_required_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_no_approval_required_subject';
  $strongarm->value = 'Account details for [user:name] at [site:name]';
  $export['user_mail_register_no_approval_required_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_body';
  $strongarm->value = 'Hello,

Thank you for registering at [site:name]. Your application for an account is currently pending approval. Once it has been approved, you will receive another e-mail containing information about how to log in, set your password, and other details.


--  [site:name] team';
  $export['user_mail_register_pending_approval_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_register_pending_approval_subject';
  $strongarm->value = 'Account details for [user:name] at [site:name] (pending admin approval)';
  $export['user_mail_register_pending_approval_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_body';
  $strongarm->value = '[user:name],

Your account at [site:name] has been activated.

You may now log in by clicking this link or copying and pasting it into your browser:

[user:one-time-login-url]

This link can only be used once to log in and will lead you to a page where you can set your password.

After setting your password, you will be able to log in at [site:login-url] in the future using:

username: [user:name]
password: Your password

--  [site:name] team';
  $export['user_mail_status_activated_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_notify';
  $strongarm->value = 0;
  $export['user_mail_status_activated_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_activated_subject';
  $strongarm->value = 'Account details for [user:name] at [site:name] (approved)';
  $export['user_mail_status_activated_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_body';
  $strongarm->value = '[user:name],

Your account on [site:name] has been blocked due to violation of terms and conditions or other reasons.

If you feel this has been done in error, you may contact us via the website.

--  [site:name] team';
  $export['user_mail_status_blocked_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_notify';
  $strongarm->value = 1;
  $export['user_mail_status_blocked_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_blocked_subject';
  $strongarm->value = '[site:name] Account Disabled';
  $export['user_mail_status_blocked_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_body';
  $strongarm->value = '[user:name],

Your account on [site:name] has been canceled.

--  [site:name] team';
  $export['user_mail_status_canceled_body'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_notify';
  $strongarm->value = 0;
  $export['user_mail_status_canceled_notify'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_mail_status_canceled_subject';
  $strongarm->value = 'Account details for [user:name] at [site:name] (canceled)';
  $export['user_mail_status_canceled_subject'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_pictures';
  $strongarm->value = 0;
  $export['user_pictures'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_default';
  $strongarm->value = '';
  $export['user_picture_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_dimensions';
  $strongarm->value = '1024x1024';
  $export['user_picture_dimensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_file_size';
  $strongarm->value = '800';
  $export['user_picture_file_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_guidelines';
  $strongarm->value = '';
  $export['user_picture_guidelines'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_path';
  $strongarm->value = 'pictures';
  $export['user_picture_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_style';
  $strongarm->value = 'thumbnail';
  $export['user_picture_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_register';
  $strongarm->value = '0';
  $export['user_register'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_signatures';
  $strongarm->value = 0;
  $export['user_signatures'] = $strongarm;

  return $export;
}
