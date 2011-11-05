<?php
// $Id: drupal_queue.drush.inc,v 1.4 2010/05/04 21:15:42 alexb Exp $

/**
 * @file
 * Drush integration for Drupal Queue API.
 */

/**
 * Implementation of hook_drush_help().
 */
function drupal_queue_drush_help($section) {
  switch ($section) {
    case 'drush:queue-cron':
      return dt('Run Drupal queue workers. As opposed to "drush cron" that can only be run one at a time on a single site, "drush queue-cron" can be invoked as many times as the server load allows. Otherwise, schedule like drush cron.');
  }
}

/**
 * Implementation of hook_queue_drush_command().
 */
function drupal_queue_drush_command() {
  $items = array();
  $items['queue-cron'] = array(
    'callback' => 'drupal_queue_cron_run',
    'description' => 'Run Drupal queue workers.',
  );
  return $items;
}

/**
 * Run the drupal_queue cron code before normal drush cron is run.
 *
 * This needs to run before the normal drupal cron, because the normal
 * drupal cron will exit with an error if it is already running, but
 * the Drupal_Queue cron does not have this limitation.
 */
function drush_drupal_queue_pre_core_cron() {
  if (function_exists('drupal_queue_cron_run') && variable_get('drupal_queue_on_cron', TRUE)) {
    drupal_queue_cron_run();
  }
}
