<?php
/**
 * @file
 * almost_engineer.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function almost_engineer_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-bit-second-social'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-bit-second-social',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'pixture_reloaded' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -12,
      ),
    ),
    'title' => 'Connect with Me!',
    'visibility' => 0,
  );

  $export['simplenews-0'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 0,
    'module' => 'simplenews',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'pixture_reloaded' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-management'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'management',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'adaptivetheme',
        'weight' => -8,
      ),
      'pixture_reloaded' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['uc_cart-cart'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'cart',
    'module' => 'uc_cart',
    'node_types' => array(),
    'pages' => 'admin*',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => 0,
      ),
      'pixture_reloaded' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -14,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
