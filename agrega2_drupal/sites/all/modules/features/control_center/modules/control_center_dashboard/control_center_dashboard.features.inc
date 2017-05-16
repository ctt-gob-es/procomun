<?php
/**
 * @file
 * control_center_dashboard.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function control_center_dashboard_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
