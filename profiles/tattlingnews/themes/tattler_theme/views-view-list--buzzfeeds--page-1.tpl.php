<?php

  $sorting = $_GET['sortby'];
  if (empty($sorting)) $sorting = 'alpha'; //default

  $filter = $_GET['filter'];
  if (empty($filter)) $filter = 'all';  //default

  $names = array( 'filter' => array(), 'sorting' => array() );  
  
  $names['filter'] = array ();

  $names['sorting'] = array (
    'alpha' => t('Alphabetical'),
    'chrono' => t('Reverse-Chrono'),    
//    'mostbuzz' => t('Most Buzz'),    
  );
  
?>
<div id="blue_header" class="clearfix">
  <h1><?php print t('Feeds');?></h1>
  <div id="filter">
  <ul>
    <?php print _tattlerui_render_view_filter_control_links
          ('filter', $names, $sorting, $filter, 'buzzfeeds'); ?>
  </ul>          
  </div><!--/mentions filter-->
   <div id="timeframe_filter" class="clearfix">
   <ul>
    <li><?php print t('SORT BY:'); ?></li>
    <?php print _tattlerui_render_view_filter_control_links
          ('sorting', $names, $sorting, $filter, 'buzzfeeds'); ?>
   </ul>          
  </div><!--/time frame filter-->  
</div><!--/blueheader-->  


<div id="sources_content" class="main_content">
  <div class="listing_area">

  <ul>
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>    
  </ul> 

  </div>
</div>
