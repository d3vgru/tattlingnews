// $Id: README.txt,v 1.1.2.3.4.2 2008/12/31 00:09:52 arthuregg Exp $

SWFObject_api Module

Description
-------------------------------------
This module makes it easier to add flash content to sites


Installation
-------------------------------------
 1) Place module into modules directory
 2) Download SWFObject library 2 from:
      http://code.google.com/p/swfobject/
 3) Place the swfobject.js file into modules/swfobject_api/
 4) Place the expressinstall.swf file into modules/swfobject_api/
 5) Activate module in admin/build/modules
 6) Configure the module via admin/settings/swfobject_api

Usage
------------------------------------
Adding flash to your theme is as simple as:

  $url = "myflashfile.swf"; //path to flash file
  $params = array('width' => 100, 'height' => 100 );
  $variables = array('foo' => 'bar');
  print theme("swfobject_api", $url, $params, $variables);

Example:

  <?php
    $params = array(
      'width' => 320,
      'height' => 240,
    );

    $vars = array(
      'file' => base_path() . path_to_theme() .'/files/song.mp3',
      'image' =>  base_path() . path_to_theme() ./files/image.jpg',
    );

    print theme("swfobject_api", base_path() . path_to_theme() . '/flash/mediaplayer.swf', $params, $vars);
  ?>

Advanced Usage
------------------------------------
 You can change the class and id of the div wrapping the flash file with:
 $param['div_id']
 $param['class']

 You can change the "No flash detected" message with
 $param['no_flash'] = t('No flash for you');
 
 You can also pass text and a drupal filter to the no_flash option:
 $param['no_flash'] = array( 
   'text' => t('This is your text'),
   'filter' => 3, // drupal filter id
  );
  
  You can pass php to this variable as well.
  
 
 
 
 
