<?php
/**
 * @file
 * ag_section_polls.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ag_section_polls_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_poll';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_poll'] = $strongarm;

  return $export;
}
