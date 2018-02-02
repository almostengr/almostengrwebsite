<?php
/**
 * @file
 * almost_engineer.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function almost_engineer_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'bit_second_email';
  $item->name = 'bit second email';
  $item->subtype = 'email';
  $item->location = 'bitsecondal@gmail.com';
  $item->settings = array();
  $export['bit_second_email'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_profiles().
 */
function almost_engineer_exportables_backup_migrate_profiles() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'default';
  $item->name = 'Default Settings';
  $item->filename = 'BitSecondTech';
  $item->append_timestamp = TRUE;
  $item->timestamp_format = 'Y-m-d\\TH-i-s';
  $item->filters = array(
    'compression' => 'gzip',
    'notify_success_enable' => 0,
    'notify_success_email' => 'bitsecondal@gmail.com',
    'notify_failure_enable' => 1,
    'notify_failure_email' => 'bitsecondal@gmail.com',
    'utils_site_offline' => 0,
    'utils_site_offline_message' => 'Bit Second Tech is currently under maintenance. We should be back shortly. Thank you for your patience.',
    'utils_description' => '',
    'use_cli' => 0,
    'ignore_errors' => 0,
    'sources' => array(
      'db' => array(
        'exclude_tables' => array(),
        'nodata_tables' => array(
          'bsal_cache' => 'bsal_cache',
          'bsal_cache_admin_menu' => 'bsal_cache_admin_menu',
          'bsal_cache_block' => 'bsal_cache_block',
          'bsal_cache_bootstrap' => 'bsal_cache_bootstrap',
          'bsal_cache_field' => 'bsal_cache_field',
          'bsal_cache_filter' => 'bsal_cache_filter',
          'bsal_cache_form' => 'bsal_cache_form',
          'bsal_cache_image' => 'bsal_cache_image',
          'bsal_cache_menu' => 'bsal_cache_menu',
          'bsal_cache_page' => 'bsal_cache_page',
          'bsal_cache_path' => 'bsal_cache_path',
          'bsal_cache_views' => 'bsal_cache_views',
          'bsal_cache_views_data' => 'bsal_cache_views_data',
          'civicrm_acl_cache' => 'civicrm_acl_cache',
          'civicrm_acl_contact_cache' => 'civicrm_acl_contact_cache',
          'civicrm_cache' => 'civicrm_cache',
          'civicrm_group_contact_cache' => 'civicrm_group_contact_cache',
          'civicrm_prevnext_cache' => 'civicrm_prevnext_cache',
        ),
        'utils_lock_tables' => 0,
      ),
      'files' => array(
        'exclude_filepaths' => 'backup_migrate
styles
css
js
ctools
less',
      ),
      'archive' => array(
        'exclude_filepaths' => 'public://backup_migrate
public://styles
public://css
public://js
public://ctools
public://less
private://backup_migrate
sites/default/settings.php
/tmp',
      ),
    ),
  );
  $export['default'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_schedules().
 */
function almost_engineer_exportables_backup_migrate_schedules() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'default_schedule';
  $item->name = 'default schedule';
  $item->source_id = 'db';
  $item->destination_id = 'bit_second_email';
  $item->copy_destination_id = '';
  $item->profile_id = 'default';
  $item->keep = 0;
  $item->period = 604800;
  $item->enabled = FALSE;
  $item->cron = 'builtin';
  $item->cron_schedule = '0 4 * * *';
  $export['default_schedule'] = $item;

  return $export;
}
