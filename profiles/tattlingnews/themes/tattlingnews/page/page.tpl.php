<?php require_once ( dirname(__FILE__) . '/page.header.inc' ); ?>

    <?php 
    
      $sidebar_visible = tattlerui_right_sidebar_visibility();

      // Logic to determine whether content column should strech
      // horizontally, when there is no right-column content, 
      // e.g. on the Trends page (or any other).
      if ( !empty($right_sidebar) && $sidebar_visible) { 
        $class_only_left = 'class="on_left"'; 
      }
      else {
        $class_only_left = '';
      }
      
    ?>
    
    
    <div id="page_wrapper" class="clearfix center_in_page">
    
    <?php 
      if ($show_tattler_toolbar == TRUE) {
        include_once (dirname(__FILE__) .'/page-toolbar.tpl.php'); 
      }
    ?>
    
    <?php if ($show_messages && $messages): print $messages; endif; ?>
    <div class="tabs"><?php print $tabs; ?></div>        
    
    <div id="page_wrapper" class="clearfix center_in_page">
    
    <div id="content_column" <?php print $class_only_left; ?> >

      
      <div id="drupal_content" class="clearfix clear clear-block">            
        <?php print $content; ?>
      </div>      
    
    </div><!--/content column-->

    <?php if ( !empty($right_sidebar) && $sidebar_visible ) { ?>    
      <div id="right_column">
            
        <?php print $right_sidebar; ?>
      
      </div><!--/right_column-->
    <?php } ?>
    
<?php require_once ( dirname(__FILE__) . '/page.footer.inc' ); ?>