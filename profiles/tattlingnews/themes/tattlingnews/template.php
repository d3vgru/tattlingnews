<?php


/**
 * Generates IE CSS links.
 */
function phptemplate_get_ie_styles() {
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie.css" />';
  return $iecss;
}

/**
 * Generates IE6-only CSS links.
 */
function phptemplate_get_ie6_styles() {
  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie6.css" />';
  return $iecss;
}

function tattlerui_logout_link() {
  global $user;
    
  if ($user->uid == 0) {
    $link = l(t('Login'), 'user');
  }
  else {
    $link = l(t('Logout'), 'logout');
  }
  
  return $link;
}

