<?php
/**
 * @file
 * almost_engineer.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function almost_engineer_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-bit-second-social.
  $menus['menu-bit-second-social'] = array(
    'menu_name' => 'menu-bit-second-social',
    'title' => 'Bit Second Social',
    'description' => 'Connect with Bit Second Tech on other social media platforms.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bit Second Social');
  t('Connect with Bit Second Tech on other social media platforms.');

  return $menus;
}
