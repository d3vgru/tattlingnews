<div id="blue_header" class="clearfix">
<h1><?php print ('All Tags'); ?></h1>
<div id="filter">
	<ul>
   </ul>   
</div><!--/mentions filter-->
 <div id="timeframe_filter" class="clearfix">
   	<ul>
    </ul>                                     
</div><!--/time frame filter-->        
</div><!--/blueheader-->

<div class="view view-<?php print $css_name; ?> view-id-<?php print $name; ?> view-display-id-<?php print $display_id; ?> view-dom-id-<?php print $dom_id; ?>">
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <div id="paging" class="clearfix clear">
    <div id="paging_list">
    <?php print $pager; ?>
    </div></div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

   <?php if ($pager): ?>
    <div id="paging" class="clearfix clear">
    <div id="paging_list">
    <?php print $pager; ?>
    </div></div>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div> <?php // class view ?>
