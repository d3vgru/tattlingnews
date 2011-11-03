<div id="trends_content" class="main_content clearfix">
  <h1 class="basic">Trends</h1>
  <div class="left_column">
    <div class="form_title_bar"><h3>manage comparisons</h3></div>
    <div id="comparison_form" class="form_wrapper clearfix">
    
    <?php 
      print drupal_get_form('tattler_trends_query_setup_form');
    ?>
    
    </div><!--/form wrapper-->

    <div class="form_button_bar clearfix">
    <div class="button_orange float-right">
      <!--a href="#">apply</a-->
    </div>
    <div class="button_grey float-right">
      <!--a href="#">clear</a-->
    </div> 
    </div>

    </div>

  <div class="right_column">
    <div class="chart_wrapper"><h3>chart</h3>
      <div>
        <!--img src="<?php print base_path() . path_to_theme(); ?>/images/chart_placeholder.png" /-->
        <?php tattler_trends_draw_chart(); ?>
      </div>
    </div><!--/chart wrapper-->
  </div>
</div><!--/trends content-->


