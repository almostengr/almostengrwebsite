<?php
/**
 * @file
 * almost_engineer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function almost_engineer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-bit-second-social_youtube:https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig.
  $menu_links['menu-bit-second-social_youtube:https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig'] = array(
    'menu_name' => 'menu-bit-second-social',
    'link_path' => 'https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig',
    'router_path' => '',
    'link_title' => 'YouTube',
    'options' => array(
      'attributes' => array(
        'title' => 'Almost Engineer YouTube Channel',
      ),
      'identifier' => 'menu-bit-second-social_youtube:https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('YouTube');

  return $menu_links;
}
