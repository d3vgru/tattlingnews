<?php
$mentions_rss_badge = tattlerui_mentions_rss_badge();
?>

<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js?pub=xa-4a948c0b1cb90fd5"></script>   
<script>
var addthis_share = 
{ 
    templates: {
                   twitter: '{{title}} {{url}} (from @tattlerapp)'
               }
}

var addthis_config =
{
   data_use_flash: false,
   ui_click: true
}
</script>

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

    <div id="paging" class="clearfix clear">
    <div id="paging_list" class="clearfix" >
      <div class="float-right">
        <?php print $mentions_rss_badge; ?>
      </div>
      <div class="float-left">
        <?php if ($pager): ?>
          <?php print $pager; ?>
        <?php endif; ?>      
      </div>
    </div></div>


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
