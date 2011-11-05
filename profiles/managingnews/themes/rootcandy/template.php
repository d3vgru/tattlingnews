<?php
// $Id: template.php,v 1.36.2.11 2008/10/23 05:36:33 sign Exp $

function _rootcandy_admin_links() {
  global $user;
  if ($user->uid) {
    $links[] = '<a href="'. url('user') .'" class="user-name">'. $user->name .'</a>';
    $links[] = '<a href="'. url('logout') .'">'. t('Logout') .'</a>';
    $links = implode(' | ', $links);

    return $links;
  }
}

function rootcandy_body_class($left = NULL, $right = NULL) {
  $class = '';
  if ($left != '' AND $right) {
    $class = 'sidebars';
  }
  else if ($left != '' AND $right == '') {
    $class = 'sidebar-left';
  }
  else if ($left == '' AND $right != '') {
    $class = 'sidebar-right';
  }

  // Add classes describing the menu trail of the page.
  $class .= rootcandy_get_page_classes();

  if (isset($class)) {
    print ' class="'. $class .'"';
  }

}

function _rootcandy_admin_navigation() {
  $path = base_path() . path_to_theme();
  $base = path_to_theme();

  /**
   *
   */
  // get users role
  global $user;
  if ($user->uid != 1) {
    $role = end(array_keys($user->roles));
    $rootcandy_navigation = theme_get_setting('rootcandy_navigation_source_'.$role);
  }
  else {
    $rootcandy_navigation = '_rootcandy_default_navigation';
  }

  if (!$rootcandy_navigation) {
    $menu_tree[] = array('href' => 'user/login', 'title' => t('User login'));
  }
  elseif ($rootcandy_navigation == '_rootcandy_default_navigation') {
    // build default menu
    $menu_tree[] = array('href' => 'admin', 'title' => t('Dashboard'));
    $menu_tree[] = array('href' => 'admin/content', 'title' => t('Content'));
    if (variable_get('node_admin_theme', '0')) {
      $menu_tree[] = array('href' => 'node/add', 'title' => t('Create content'));
    }
    $menu_tree[] = array('href' => 'admin/build', 'title' => t('Building'));
    $menu_tree[] = array('href' => 'admin/settings', 'title' => t('Configuration'));
    $menu_tree[] = array('href' => 'admin/user', 'title' => t('Users'));
    $menu_tree[] = array('href' => 'admin/reports', 'title' => t('Reports'));
    $menu_tree[] = array('href' => 'admin/help', 'title' => t('Help'));
  }
  else {
    $menu_tree = menu_navigation_links($rootcandy_navigation);
  }

  if ($menu_tree) {
    $output = '<ul>';

    $custom_icons = rootcandy_custom_icons();
    if (!isset($custom_icons)) {
      $custom_icons = '';
    }

    $match = _rootcandy_besturlmatch($_GET['q'],$menu_tree);
    foreach ($menu_tree as $key => $item) {
      $id = '';
      // icons
      if (!theme_get_setting('rootcandy_navigation_icons')) {
        $size = theme_get_setting('rootcandy_navigation_icons_size');
        if (!isset($size)) $size = 24;
        $arg = explode("/", $item['href']);
        $icon = _rootcandy_icon($arg, $size, 'admin', $custom_icons);
        if ($icon) $icon = $icon .'<br />';
      }
      if ($key == $match) {
        $id = ' id="current"';
      }
      $output .= '<li'. $id .'><a href="'. url($item['href']) .'">'. $icon . $item['title'] .'</a>';
      $output .= '</li>';
    }
    $output .= '</ul>';
  }

  return $output;
}

function _rootcandy_besturlmatch($needle, $menuitems) {
  $lastmatch = null;
  $lastmatchlen = 0;
  $urlparts = explode('/', $needle);
  $partcount = count($urlparts);

  foreach($menuitems as $key => $menuitem) {
    $href = $menuitem['href'];
    $menuurlparts = explode('/', $href);
    $matches = _rootcandy_countmatches($urlparts, $menuurlparts);
    if (($matches > $lastmatchlen) || (($matches == $lastmatchlen) && (($lastmatch && strlen($menuitems[$lastmatch]['href'])) > strlen($href)) )) {
      $lastmatchlen = $matches;
      $lastmatch = $key;
    }
  }
  return $lastmatch;
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function rootcandy_preprocess_page(&$vars) {
  // get secondary links
  $vars['tabs2'] = menu_secondary_local_tasks();

  // color.module integration
  if (module_exists('color')) {
    _color_page_alter($vars);
  }

  if (arg(0) == 'admin' || (variable_get('test',1) AND ((arg(0) == 'node' AND is_numeric(arg(1)) AND arg(2) == 'edit') || (arg(0) == 'node' AND arg(1) == 'add')))) {
    $vars['go_home'] = '<a href="'.base_path().'">'.t('Go Back to Homepage').'</a>';
  }

  // get theme settings
  $vars['hide_header'] = theme_get_setting('rootcandy_header_display');

  // append legal notice
  $vars['closure'] .= '<div id="legal-notice">Theme created by <a href="http://sotak.co.uk" target="_blank">Marek Sotak</a></div>';

  $vars['hide_content'] = '';

  // dashboard
  if (arg(0) == 'admin' AND !arg(1)) {
    if (!theme_get_setting('rootcandy_dashboard_display')) {
      $vars['dashboard'] = 1;
      // display help and messages in regions
      switch (theme_get_setting('rootcandy_dashboard_help')) {
        case 'left':
          $vars['dashboard_left'] = $vars['help'] . $vars['dashboard_left'];
          unset ($vars['help']);
          break;
        case 'right':
          $vars['dashboard_right'] = $vars['help'] . $vars['dashboard_right'];
          unset ($vars['help']);
          break;
      }

      switch (theme_get_setting('rootcandy_dashboard_messages')) {
        case 'left':
          $vars['dashboard_left'] = $vars['messages'] . $vars['dashboard_left'];
          unset ($vars['messages']);
          break;
        case 'right':
          $vars['dashboard_right'] = $vars['messages'] . $vars['dashboard_right'];
          unset ($vars['messages']);
          break;
      }
    }
    if (theme_get_setting('rootcandy_dashboard_content_display')) {
      $vars['hide_content'] = theme_get_setting('rootcandy_dashboard_content_display');
    }
  }
}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs. Overridden to split the secondary tasks.
 *
 * @ingroup themeable
 */
function rootcandy_menu_local_tasks() {
  return menu_primary_local_tasks();
}

function _rootcandy_icon($name, $size = '16', $subdir = '', $icons = '') {
  $url = implode("/", $name);
  $name = implode("-", $name);
  $path = path_to_theme();
  if ($subdir) {
    $subdir = $subdir .'/';
  }

  if (isset($icons[$url])) {
    $icon = $icons[$url];
  }
  else {
    $icon = $path .'/icons/i'. $size .'/'. $subdir . $name .'.png';
  }

  $output = theme('image', $icon);

  if (!$output) {
    $icon = $path .'/icons/i'. $size .'/misc/unknown.png';
    $output = theme('image', $icon);
  }

  return $output;
}

function rootcandy_custom_icons() {
  $custom_icons = theme_get_setting('rootcandy_navigation_custom_icons');
  if (isset($custom_icons)) {
    $list = explode("\n",$custom_icons);
    $list = array_map('trim', $list);
    $list = array_filter($list, 'strlen');
    foreach ($list as $opt) {
      // Sanitize the user input with a permissive filter.
      $opt = rootcandy_filter_xss($opt);
      if (strpos($opt, '|') !== FALSE) {
        list($key, $value) = explode('|', $opt);
        $icons[$key] = $value ? $value : $key;
      }
      else {
        $icons[$opt] = $opt;
      }
    }
  }
  if (isset($icons)) {
    return $icons;
  }
}

function rootcandy_filter_xss($string) {
  return filter_xss($string);
}

/**
 * Read the theme settings' default values from the .info and save them into the database.
 *
 * @param $theme
 *   The actual name of theme that is being checked.
 */
function rootcandy_settings_init($theme) {
  $themes = list_themes();

  // Get the default values from the .info file.
  $defaults = $themes[$theme]->info['settings'];

  // Get the theme settings saved in the database.
  $settings = theme_get_settings($theme);
  // Don't save the toggle_node_info_ variables.
  if (module_exists('node')) {
    foreach (node_get_types() as $type => $name) {
      unset($settings['toggle_node_info_'. $type]);
    }
  }
  // Save default theme settings.
  variable_set(
    str_replace('/', '_', 'theme_'. $theme .'_settings'),
    array_merge($defaults, $settings)
  );
  // Force refresh of Drupal internals.
  theme_get_setting('', TRUE);
}

/*
 * In addition to initializing the theme settings during HOOK_theme(), init them
 * when viewing/resetting the admin/build/themes/settings/THEME forms.
 */
if (arg(0) == 'admin' && arg(2) == 'themes' && arg(4)) {
  global $theme_key;
  rootcandy_settings_init($theme_key);
}

function rootcandy_get_page_classes($path = NULL) {
  if (!isset($path)) $path = $_GET['q'];
  if ($path) {
    $classes = '';
    $menu_item = explode('/', $path);
    if (count($menu_item)) {
      foreach ($menu_item as $key => $page) {
        $menu_item[$key] = strtr($page, '-', '_');
      }

      do {
        $classes .= ' '. implode('-', $menu_item);
        array_pop($menu_item);
      } while (count($menu_item));
    }
  }

  return $classes;
}

function rootcandy_breadcrumb($breadcrumb) {
  global $language;
  if (!empty($breadcrumb)) {
    if ($language->direction) {
      return '<div class="breadcrumb">'. implode(' « ', array_reverse($breadcrumb)) .'</div>';
    }
    else {
      return '<div class="breadcrumb">'. implode(' » ', $breadcrumb) .'</div>';
    }
  }
}

function _rootcandy_links($links, $attributes = array('class' => 'links')) {
  $output = '';

  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = $key;

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }

      $check_path = $_GET['q'];
      $check_path = explode("/", $check_path);
      $q_path = $check_path[0] .'/'. $check_path[1] .'/'. $check_path[2];
      if (isset($link['href']) && ($link['href'] == $q_path || ($link['href'] == '<front>' && drupal_is_front_page()))) {
        $class .= ' active';
      }
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

function _rootcandy_countmatches($arrayone, $arraytwo) {
  $matches = 0;
  foreach($arraytwo as $i => $part) {
    if (!isset($arrayone[$i])) break;
    if ($arrayone[$i] == $part) $matches = $i+1;
  }
  return $matches;
}
