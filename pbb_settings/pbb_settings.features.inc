<?php
/**
 * @file
 * pbb_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pbb_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pbb_settings_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pbb_settings_node_info() {
  $items = array(
    'ideas' => array(
      'name' => t('Ideas'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
