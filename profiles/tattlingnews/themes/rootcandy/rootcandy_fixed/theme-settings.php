<?php
// $Id: theme-settings.php,v 1.1.2.1 2008/10/23 06:09:21 sign Exp $

/**
 * Implementation of THEMEHOOK_settings() function.
 *
 * @param $saved_settings
 *   array An array of saved settings for this theme.
 * @return
 *   array A form array.
 */
function rootcandy_fixed_settings($saved_settings, $subtheme_defaults = array()) {

  // Get the default values from the .info file.
  $themes = list_themes();
  $defaults = $themes['rootcandy_fixed']->info['settings'];

  // Allow a subtheme to override the default values.
  $defaults = array_merge($defaults, $subtheme_defaults);

  // Merge the saved variables and their default values.
  $settings = array_merge($defaults, $saved_settings);

  // Create the form widgets using Forms API
  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['header']['rootcandy_header_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable header'),
    '#default_value' => $settings['rootcandy_header_display'],
  );
  $form['dashboard'] = array(
    '#type' => 'fieldset',
    '#title' => t('Dashboard'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['dashboard']['rootcandy_dashboard_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable dashboard'),
    '#default_value' => $settings['rootcandy_dashboard_display'],
  );
  $form['dashboard']['rootcandy_dashboard_help'] = array(
    '#type' => 'select',
    '#options' => array('left' => t('Left'),'right' => t('Right'),'content' => t('Content')),
    '#title' => t('Help box position'),
    '#default_value' => $settings['rootcandy_dashboard_help'],
  );
  $form['dashboard']['rootcandy_dashboard_messages'] = array(
    '#type' => 'select',
    '#options' => array('left' => t('Left'),'right' => t('Right'),'content' => t('Content')),
    '#title' => t('Messages box position'),
    '#default_value' => $settings['rootcandy_dashboard_messages'],
  );
  $form['dashboard']['rootcandy_dashboard_content_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable content on a dashboard'),
    '#default_value' => $settings['rootcandy_dashboard_content_display'],
  );

  $form['navigation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Navigation'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // Create the form widgets using Forms API
  $form['navigation']['rootcandy_navigation_icons'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable icons for main navigation'),
    '#default_value' => $settings['rootcandy_navigation_icons'],
  );


  $form['navigation']['rootcandy_navigation_icons_size'] = array(
    '#type' => 'select',
    '#options' => array(16 => 16, 24 => 24, 32 => 32),
    '#title' => t('Set icons size for main navigation'),
    '#default_value' => $settings['rootcandy_navigation_icons_size'],
  );

  $form['navigation']['nav-by-role'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu source by role'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $primary_options = array(
    NULL => t('None'),
    '_rootcandy_default_navigation' => t('default navigation'),
  );
  $primary_options = array_merge($primary_options, menu_get_menus());
  $roles = user_roles(FALSE);
  foreach ($roles as $rid => $role) {
    $default = '';
    if (isset($settings['rootcandy_navigation_source_'. $rid])) {
      $default = $settings['rootcandy_navigation_source_'. $rid];
    }
    $form['navigation']['nav-by-role']['rootcandy_navigation_source_'. $rid] = array(
      '#type' => 'select',
      '#title' => t('@role navigation', array('@role' => $role)),
      '#default_value' => $default,
      '#options' => $primary_options,
      '#tree' => FALSE,
      '#description' => t('Select what should be displayed as the navigation menu for role @role.', array('@role' => $role)),
    );
  }

  $form['navigation']['custom-icons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom icons'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['navigation']['custom-icons']['rootcandy_navigation_custom_icons'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom icons'),
    '#default_value' => $settings['rootcandy_navigation_custom_icons'],
    '#description' => t('Format: menu href|icon path (relative to drupal root) - one item per row. eg. admin/build|files/myicons/admin-build.png'),
    '#required' => FALSE
  );

  // Return the additional form widgets
  return $form;
}