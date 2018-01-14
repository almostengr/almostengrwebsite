<?php
/**
 * @file
 * almost_engineer.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function almost_engineer_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 5,
  );

  // Exported role: not verified.
  $roles['not verified'] = array(
    'name' => 'not verified',
    'weight' => 2,
  );

  // Exported role: verified.
  $roles['verified'] = array(
    'name' => 'verified',
    'weight' => 3,
  );

  return $roles;
}
