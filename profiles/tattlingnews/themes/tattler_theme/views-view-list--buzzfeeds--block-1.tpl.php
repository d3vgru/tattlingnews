<div id="top_feeds" class="module clearfix clear">
    
  <div class="title_bar clearfix">
    <h3 class="float-left"><?php print tattlerui_prefix_block_title($view->name, 'query') . t('top feeds'); ?></h3>
    <!--div class="chart_icon"><a href="#"><?php print t('CHART'); ?></a></div-->
  </div>

  <ul>
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>
    
  </ul> 

</div><!--/ top_sources -->
