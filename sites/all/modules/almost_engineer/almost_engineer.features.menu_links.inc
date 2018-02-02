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

  // Exported menu link: main-menu_contact:node/add/contact-request.
  $menu_links['main-menu_contact:node/add/contact-request'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/contact-request',
    'router_path' => 'node/add/contact-request',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contact:node/add/contact-request',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_my-account:user.
  $menu_links['main-menu_my-account:user'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My Account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_my-account:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: main-menu_projects:projects.
  $menu_links['main-menu_projects:projects'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'projects',
    'router_path' => 'projects',
    'link_title' => 'Projects',
    'options' => array(
      'identifier' => 'main-menu_projects:projects',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_store:catalog.
  $menu_links['main-menu_store:catalog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'catalog',
    'router_path' => 'catalog',
    'link_title' => 'Store',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_store:catalog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-bit-second-social_facebook:http://facebook.com/almostengr.
  $menu_links['menu-bit-second-social_facebook:http://facebook.com/almostengr'] = array(
    'menu_name' => 'menu-bit-second-social',
    'link_path' => 'http://facebook.com/almostengr',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bit-second-social_facebook:http://facebook.com/almostengr',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-bit-second-social_github:https://github.com/bitsecondal.
  $menu_links['menu-bit-second-social_github:https://github.com/bitsecondal'] = array(
    'menu_name' => 'menu-bit-second-social',
    'link_path' => 'https://github.com/bitsecondal',
    'router_path' => '',
    'link_title' => 'GitHub',
    'options' => array(
      'attributes' => array(
        'title' => 'Bit Second on Git Hub. ',
      ),
      'identifier' => 'menu-bit-second-social_github:https://github.com/bitsecondal',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-bit-second-social_instagram:http://instagram.com/almostengr.
  $menu_links['menu-bit-second-social_instagram:http://instagram.com/almostengr'] = array(
    'menu_name' => 'menu-bit-second-social',
    'link_path' => 'http://instagram.com/almostengr',
    'router_path' => '',
    'link_title' => 'Instagram',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bit-second-social_instagram:http://instagram.com/almostengr',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-bit-second-social_twitter:https://twitter.com/bit_second.
  $menu_links['menu-bit-second-social_twitter:https://twitter.com/bit_second'] = array(
    'menu_name' => 'menu-bit-second-social',
    'link_path' => 'https://twitter.com/bit_second',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-bit-second-social_twitter:https://twitter.com/bit_second',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-bit-second-social_youtube:https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig.
  $menu_links['menu-bit-second-social_youtube:https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig'] = array(
    'menu_name' => 'menu-bit-second-social',
    'link_path' => 'https://www.youtube.com/channel/UC4HCouBLtXD1j1U_17aBqig',
    'router_path' => '',
    'link_title' => 'YouTube',
    'options' => array(
      'attributes' => array(
        'title' => 'Bit Second Tech YouTube Channel',
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
  // Exported menu link: user-menu_httpsupportdetailscom:http://supportdetails.com/.
  $menu_links['user-menu_httpsupportdetailscom:http://supportdetails.com/'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'http://supportdetails.com/',
    'router_path' => '',
    'link_title' => 'http://supportdetails.com/',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_httpsupportdetailscom:http://supportdetails.com/',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: user-menu_make-payment:node/248.
  $menu_links['user-menu_make-payment:node/248'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/248',
    'router_path' => 'node/%',
    'link_title' => 'Make Payment',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_make-payment:node/248',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_requests:users/my-requests.
  $menu_links['user-menu_requests:users/my-requests'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'users/my-requests',
    'router_path' => 'users/my-requests',
    'link_title' => 'Requests',
    'options' => array(
      'identifier' => 'user-menu_requests:users/my-requests',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Facebook');
  t('GitHub');
  t('Instagram');
  t('Log out');
  t('Make Payment');
  t('My Account');
  t('Projects');
  t('Requests');
  t('Store');
  t('Twitter');
  t('User account');
  t('YouTube');
  t('http://supportdetails.com/');

  return $menu_links;
}
