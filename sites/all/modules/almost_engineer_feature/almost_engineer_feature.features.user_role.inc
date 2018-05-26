<?php
/**
 * @file
 * almost_engineer_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function almost_engineer_feature_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 6,
  );

  // Exported role: drupal maintenance.
  $roles['drupal maintenance'] = array(
    'name' => 'drupal maintenance',
    'weight' => 5,
  );

  // Exported role: mailing list.
  $roles['mailing list'] = array(
    'name' => 'mailing list',
    'weight' => 3,
  );

  // Exported role: not verified.
  $roles['not verified'] = array(
    'name' => 'not verified',
    'weight' => 2,
  );

  // Exported role: website.
  $roles['website'] = array(
    'name' => 'website',
    'weight' => 4,
  );

  return $roles;
}
