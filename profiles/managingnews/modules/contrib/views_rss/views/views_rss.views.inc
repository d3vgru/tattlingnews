<?php
// $Id: views_rss.views.inc,v 1.1.2.1 2010/03/02 21:03:30 alexb Exp $

/**
 * @file
 * Views plugins definition for views_rss.
 */

/**
 * Implementation of hook_views_style_plugins(). Adds view types to views UI interface.
 */
function views_rss_views_plugins() {
  return array(
    'style' => array(
      'rss_fields' => array(
        'title' => t('RSS Feed - Fields'),
        'help' => t('Outputs a RSS formatted feed'),
        'handler' => 'views_plugin_style_rss_fields',
        'theme' => 'views_view_views_rss_fields',
        'theme file' => 'views_rss_views_fields.theme.inc',
        'theme path' => drupal_get_path('module', 'views_rss') .'/views',
        'path' => drupal_get_path('module', 'views_rss') .'/views',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'feed',
      ),
    ),
  );
}
