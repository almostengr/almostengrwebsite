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

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-bit-second-social.
  $menus['menu-bit-second-social'] = array(
    'menu_name' => 'menu-bit-second-social',
    'title' => 'Social Media',
    'description' => 'Connect with Almost Engineer on social media platforms.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Connect with Almost Engineer on social media platforms.');
  t('Main menu');
  t('Social Media');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');

  return $menus;
}
