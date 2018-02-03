<?php
/**
 * @file
 * almost_engineer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function almost_engineer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "backup_migrate" && $api == "backup_migrate_exportables") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "mailhandler" && $api == "mailhandler_mailbox") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function almost_engineer_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function almost_engineer_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'contact_request' => array(
      'name' => t('Contact Request'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service_request' => array(
      'name' => t('Service Request'),
      'base' => 'node_content',
      'description' => t('Use for requesting work that needs to be done to a website or other action item.'),
      'has_title' => '1',
      'title_label' => t('Summary'),
      'help' => '',
    ),
    'teleprompter_script' => array(
      'name' => t('Teleprompter Script'),
      'base' => 'node_content',
      'description' => t('Use for preparing script for video recordings.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
