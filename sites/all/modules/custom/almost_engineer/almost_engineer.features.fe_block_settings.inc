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
        'weight' => -10,
      ),
    ),
    'title' => 'Connect with Me!',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'adaptivetheme',
        'weight' => -12,
      ),
      'pixture_reloaded' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -12,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'adaptivetheme',
        'weight' => -9,
      ),
      'pixture_reloaded' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -9,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => -6,
      ),
      'pixture_reloaded' => array(
        'region' => 'menu_bar',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -12,
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

  $export['system-powered-by'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'powered-by',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => -4,
      ),
      'pixture_reloaded' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pixture_reloaded',
        'weight' => -4,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => -9,
      ),
      'pixture_reloaded' => array(
        'region' => 'menu_bar',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => -13,
      ),
    ),
    'title' => 'My Account',
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
        'weight' => -13,
      ),
    ),
    'title' => 'My Cart',
    'visibility' => 0,
  );

  $export['uc_catalog-catalog'] = array(
    'cache' => 5,
    'custom' => 0,
    'delta' => 'catalog',
    'module' => 'uc_catalog',
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
        'region' => '',
        'status' => 0,
        'theme' => 'pixture_reloaded',
        'weight' => -11,
      ),
    ),
    'title' => 'Store',
    'visibility' => 0,
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'login',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme',
        'weight' => -8,
      ),
      'pixture_reloaded' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pixture_reloaded',
        'weight' => -12,
      ),
    ),
    'title' => 'My Account',
    'visibility' => 0,
  );

  return $export;
}
