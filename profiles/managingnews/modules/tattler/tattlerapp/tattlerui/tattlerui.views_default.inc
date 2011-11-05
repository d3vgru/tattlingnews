<?php
/**
 * @file tattlerui.views_default.inc
 */
 
/**
 * Implementation of hook_views_default_views().
 */
function tattlerui_views_default_views() {
  // Load all views from the "views" subdirectory
  foreach (glob(dirname(__FILE__) . "/views/*.inc") as $filename) {
      include_once($filename);
      $views[$view->name] = $view;
  }
  return $views;
}
