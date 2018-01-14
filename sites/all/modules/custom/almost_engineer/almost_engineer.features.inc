<?php
/**
 * @file
 * almost_engineer.features.inc
 */

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
    'portfolio_item' => array(
      'name' => t('Portfolio Item'),
      'base' => 'node_content',
      'description' => t('Portfolio Item shows off work that has been done'),
      'has_title' => '1',
      'title_label' => t('Title'),
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

/**
 * Implements hook_uc_product_default_classes().
 */
function almost_engineer_uc_product_default_classes() {
  $items = array(
    'product' => array(
      'name' => t('Product'),
      'base' => 'uc_product',
      'description' => t('Use <em>products</em> to represent items for sale on the website, including all the unique information that can be attributed to a specific model number.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
