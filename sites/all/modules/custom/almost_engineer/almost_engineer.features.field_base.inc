<?php
/**
 * @file
 * almost_engineer.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function almost_engineer_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_project'.
  $field_bases['field_project'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_project',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'projects',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
