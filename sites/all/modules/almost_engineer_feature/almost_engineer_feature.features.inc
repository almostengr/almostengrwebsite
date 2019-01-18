<?php
/**
 * @file
 * almost_engineer_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function almost_engineer_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "mailhandler" && $api == "mailhandler_mailbox") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function almost_engineer_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function almost_engineer_feature_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
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
    'portfolio_item' => array(
      'name' => t('Portfolio Item'),
      'base' => 'node_content',
      'description' => t('Portfolio Item shows off work that has been done'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'service_request' => array(
      'name' => t('Service Request'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
