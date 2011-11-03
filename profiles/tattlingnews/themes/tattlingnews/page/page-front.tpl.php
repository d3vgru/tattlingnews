<?php require_once ( dirname(__FILE__) . '/page.header.inc' ); ?>
<?php

  $sorting = $_GET['timeframe'];
  if (empty($sorting)) $sorting = 'all'; //default

  $filter = $_GET['filter'];
  if (empty($filter)) $filter = 'all';  //default

  $names = array( 'filter' => array(), 'sorting' => array() );  
  
  $names['filter'] = array (
    'all' => t('All'),
    'watchlist' => t('Watchlist'),    
    'mostvotes' => t('Most Votes'),    
    'bookmarks' => t('Bookmarks'),    
  );

  $names['sorting'] = array (
    'all' => t('All'),  
    //'givendate' => t('Given Date'),    
    'week' => t('Week'),        
    'month' => t('Month'),        
    'sixmonths' => t('6 Months'),            
    'year' => t('One Year'),            
  );
  
  $tattler_page_name = t('Mentions');

?>

<div id="page_wrapper" class="clearfix center_in_page">
  <?php require_once (dirname(__FILE__) .'/page-toolbar.tpl.php'); ?>


  <div id="section-tabs" class="clearfix">
    <ul class="clearfix float-left" style="width: 380px; ">    
     <?php print tattlerui_sectionbar_elements(); ?>                        
    </ul>
    <div id="sssubscription" class="float-left">
      <?php //print tattlerui_mentions_rss_badge(); ?>
    </div>    
  </div><!--/ #section-tabs -->

  <?php if ($show_messages && $messages): print $messages; endif; ?>        
        
  <div class="clearfix">
    <div id="content_column" class="on_left">                
  	  <div id="drupal_content" >  	    	          
        <?php print custompage_view_tile( 'mention', $title=FALSE, 'block_1'); ?>
      </div>   
    </div><!--/content column-->
    <div id="right_column" >    
      <?php print $right_sidebar; ?>       
    </div><!--/right_column-->

  </div><!--/ .clearfix -->     

<?php require_once ( dirname(__FILE__) . '/page.footer.inc' ); ?>