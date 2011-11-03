<?php
// $Id: managingnews.profile,v 1.1.2.41 2010/10/10 02:57:49 diggersf Exp $

/**
 * Implementation of hook_profile_details().
 */
function tattlingnews_profile_details() {
  return array(
    'name' => 'Tattling News',
    'description' => 'A news aggregator by Development Seed -> Phase 2. H4x3d by d3vgru.'
  );
}

/**
 * Implementation of hook_profile_modules().
 */
function tattlingnews_profile_modules() {
  // Drupal core
  $modules = array(
    'block',
    'book',
    'color',
    'dblog',
    'filter',
    'help',
    'mark',
    'menu',
    'node',
    'openid',
    'search',
    'system',
    'taxonomy',
    'update',
    'upload',
    'user',
    'ctools',
    'context',
    'context_ui',
    'context_layouts',
    'designkit',
    'features',
    // data must be installed before feeds so the FeedsDataProcessor plugin is enabled properly.
    'data',
    'data_ui',
    'data_search',
    'data_node',
    'data_taxonomy',
    'feeds',
    'feeds_ui',
    'extractor',
    'flot',
	'imageapi',
	'imageapi_gd',
	'imagecache',
	'imagecache_ui',
	'job_scheduler',
    'jquery_ui',
    'kml',
    'libraries',
    'openidadmin',
    'porterstemmer',
    'purl',
    'spaces_dashboard',
    'views',
    'views_ui',
    'views_rss',
    'views_modes',
    'votingapi',
    'schema',
    'strongarm',
    'geotaxonomy',

    // came w/Tattler but add to MN either way
	'admin',
	'content',
	'content_copy',
	'fieldgroup',
	'number',
	'optionwidgets',
	'text',
	'nodereference', 
	'userreference',
	'date_api',
	'date',
	'date_timezone',
	'rdf',
	'charts_graphs',
	'charts_graphs_bluff',
	'distro_client',
	'feedapi',
	'feedapi_node',
	'feedapi_inherit',
	'feedapi_source',
	'feedapi_dedupe',
	'feedapi_itemfilter',
	'flag',
	'img_extractor',
	'plus1',
	'search_config',
	'swfobject_api',
	'tagadelic',
	'views_groupby',
	'views_charts',
	
	// i18n
	'i18n',
	'lang_dropdown',
	'languageicons',
	'translation_helpers',
  );
  return $modules;
}

/**
 * Returns an array list of core mn modules.
 */
function _managingnews_core_modules() {
  return array(
    'mapbox',
    'openlayers',
    'openlayers_ui',
    'openlayers_behaviors',
    'openlayers_views',
    'stored_views',
    'web_widgets',
    'mn_core',
    'mn_about',
    'mn_search',
    'mn_world',
    'mn_channels',
    'mn_widgets',
    'simpleshare',
    'mn_boxes',
    'boxes',

	// tattler-specific stuff
	'buzzmonitor',
	'buzz_yahoo_terms',
	'buzz_topics',
	'tattler_trends',

	// d3vgru
	'mn_curator',
	'sparql',
	'views_bonus_export'
  );
}

/**
 * Implementation of hook_profile_task_list().
 */
function tattlingnews_profile_task_list() {
  return array(
    'mn-configure' => st('Tattling News configuration'),
  );
}

/**
 * Implementation of hook_profile_tasks().
 */
function tattlingnews_profile_tasks(&$task, $url) {
  // Just in case some of the future tasks adds some output
  $output = '';

  if ($task == 'profile') {
    $modules = _managingnews_core_modules();
    $files = module_rebuild_cache();
    $operations = array();
    foreach ($modules as $module) {
      $operations[] = array('_install_module_batch', array($module, $files[$module]->info['name']));
    }
    $batch = array(
      'operations' => $operations,
      'finished' => '_managingnews_profile_batch_finished',
      'title' => st('Installing @drupal', array('@drupal' => drupal_install_profile_name())),
      'error_message' => st('The installation has encountered an error.'),
    );
    // Start a batch, switch to 'profile-install-batch' task. We need to
    // set the variable here, because batch_process() redirects.
    variable_set('install_task', 'profile-install-batch');
    batch_set($batch);
    batch_process($url, $url);
  }

  if ($task == 'mn-configure') {

    // Other variables worth setting.
    variable_set('site_footer', 'Powered by <a href="http://www.managingnews.com">Managing News</a> and <a href="http://www.tattlerapp.com">Tattler</a>.');
    variable_set('site_frontpage', 'feeds');
    variable_set('comment_channel', 0);
    variable_set('comment_feed', 0);
    variable_set('comment_book', 0);
	
	// *** install Tattler ***
//	install_tattler();

    // Clear caches.
    drupal_flush_all_caches();

    // Enable the right theme. This must be handled after drupal_flush_all_caches()
    // which rebuilds the system table based on a stale static cache,
    // blowing away our changes.
    _managingnews_system_theme_data();
    db_query("UPDATE {system} SET status = 0 WHERE type = 'theme'");
    db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' AND name = 'jake'");
    db_query("UPDATE {blocks} SET region = '' WHERE theme = 'jake'");
    variable_set('theme_default', 'jake');

    // Revert key components that are overridden by others on install.
    $revert = array(
      'mn_core' => array('variable'),
      'mn_about' => array('user_permission', 'variable'),
      'mn_channels' => array('user_permission', 'variable'),
    );
    features_revert($revert);

    $task = 'finished';
  }

  return $output;
}

/**
 * Finished callback for the modules install batch.
 *
 * Advance installer task to language import.
 */
function _managingnews_profile_batch_finished($success, $results) {
  variable_set('install_task', 'mn-configure');
}

/**
 * Implementation of hook_form_alter().
 */
function tattlingnews_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'install_configure') {
    $form['site_information']['site_name']['#default_value'] = 'Tattling News';
    $form['site_information']['site_mail']['#default_value'] = 'no-reply@'. $_SERVER['HTTP_HOST'];
    $form['admin_account']['account']['name']['#default_value'] = 'admin';
    $form['admin_account']['account']['mail']['#default_value'] = 'admin@'. $_SERVER['HTTP_HOST'];
	
	// TODO: collect API keys here
	
  }
}

/**
 * Reimplementation of system_theme_data(). The core function's static cache
 * is populated during install prior to active install profile awareness.
 * This workaround makes enabling themes in profiles/managingnews/themes possible.
 */
function _managingnews_system_theme_data() {
  global $profile;
  $profile = 'tattlingnews';

  $themes = drupal_system_listing('\.info$', 'themes');
  $engines = drupal_system_listing('\.engine$', 'themes/engines');

  $defaults = system_theme_default();

  $sub_themes = array();
  foreach ($themes as $key => $theme) {
    $themes[$key]->info = drupal_parse_info_file($theme->filename) + $defaults;

    if (!empty($themes[$key]->info['base theme'])) {
      $sub_themes[] = $key;
    }

    if (isset($themes[$key]->info['engine'])) {
      $engine = $themes[$key]->info['engine'];
      if (isset($engines[$engine])) {
        $themes[$key]->owner = $engines[$engine]->filename;
        $themes[$key]->prefix = $engines[$engine]->name;
        $themes[$key]->template = TRUE;
      }
    }

    // Give the stylesheets proper path information.
    $pathed_stylesheets = array();
    foreach ($themes[$key]->info['stylesheets'] as $media => $stylesheets) {
      foreach ($stylesheets as $stylesheet) {
        $pathed_stylesheets[$media][$stylesheet] = dirname($themes[$key]->filename) .'/'. $stylesheet;
      }
    }
    $themes[$key]->info['stylesheets'] = $pathed_stylesheets;

    // Give the scripts proper path information.
    $scripts = array();
    foreach ($themes[$key]->info['scripts'] as $script) {
      $scripts[$script] = dirname($themes[$key]->filename) .'/'. $script;
    }
    $themes[$key]->info['scripts'] = $scripts;

    // Give the screenshot proper path information.
    if (!empty($themes[$key]->info['screenshot'])) {
      $themes[$key]->info['screenshot'] = dirname($themes[$key]->filename) .'/'. $themes[$key]->info['screenshot'];
    }
  }

  foreach ($sub_themes as $key) {
    $themes[$key]->base_themes = system_find_base_themes($themes, $key);
    // Don't proceed if there was a problem with the root base theme.
    if (!current($themes[$key]->base_themes)) {
      continue;
    }
    $base_key = key($themes[$key]->base_themes);
    foreach (array_keys($themes[$key]->base_themes) as $base_theme) {
      $themes[$base_theme]->sub_themes[$key] = $themes[$key]->info['name'];
    }
    // Copy the 'owner' and 'engine' over if the top level theme uses a
    // theme engine.
    if (isset($themes[$base_key]->owner)) {
      if (isset($themes[$base_key]->info['engine'])) {
        $themes[$key]->info['engine'] = $themes[$base_key]->info['engine'];
        $themes[$key]->owner = $themes[$base_key]->owner;
        $themes[$key]->prefix = $themes[$base_key]->prefix;
      }
      else {
        $themes[$key]->prefix = $key;
      }
    }
  }

  // Extract current files from database.
  system_get_files_database($themes, 'theme');
  db_query("DELETE FROM {system} WHERE type = 'theme'");
  foreach ($themes as $theme) {
    $theme->owner = !isset($theme->owner) ? '' : $theme->owner;
    db_query("INSERT INTO {system} (name, owner, info, type, filename, status, throttle, bootstrap) VALUES ('%s', '%s', '%s', '%s', '%s', %d, %d, %d)", $theme->name, $theme->owner, serialize($theme->info), 'theme', $theme->filename, isset($theme->status) ? $theme->status : 0, 0, 0);
  }
}

function install_tattler() {
    include('tattler.profile.inc');
	
	// make a function
	// values should come from main config form
	// we should save values where form is processed
	/*
    // Save values from the API form
    $form_values = array('values' => $_POST);
    system_settings_form_submit(array(), $form_values);
    */
	
    _install_log(t('Start Tattler installation'));
//    install_include(tattler_profile_modules());
	
    drupal_set_title(t('Tattler Installation'));
    _tattler_base_settings();
    _buzz_set_cck_types();
    _tattler_setup_flags();
    _tattler_initialize_settings();
//    _tattler_setup_blocks();
}
