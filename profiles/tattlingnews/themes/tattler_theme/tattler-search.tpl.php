<div id="top_search" class="clearfix clear">
  <div id="search_form_field" class="float-left">
   <?php 
     $arg2 = arg(2);
     if (arg(0)=='search' && arg(1)=='node' && !empty($arg2)) {
       $active_keyword = check_plain(urldecode(arg(2)));
     } else {
  	   $active_keyword = 'Search';
     }
  
   ?>
   <input type="text" class="form_field" value="<?php print $active_keyword;?>" />
  </div><!--search form field-->
  
  <div id="search_form_field_tooltip" class="tooltip" style="display: none">
   Tip: you can indicate the content-type of search items. <br/>
   E.g.: "Twitter type:source" will only look for source items.
  </div>
  
  <div id="search_button" class="float-left"><a href="#"><img src="<?php print base_path() . path_to_theme(); ?>/images/button_search.png" alt="Search"></a></div>
            
</div><!-- #top_search -->
