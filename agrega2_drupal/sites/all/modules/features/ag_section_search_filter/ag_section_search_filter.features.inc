<?php
/**
 * @file
 * ag_section_search_filter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_search_filter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
