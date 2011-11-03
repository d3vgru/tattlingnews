<!-- Helper form for jquery mention datepicker -->
<div style="display:none;">
  <form id="filterform" action="<?php print $_GET['q']; ?>" method="GET">
    <input type="hidden" name="filter" value="<?php print $filter; ?>"/>
    <input type="text" id="datepicker" name="timeframe"/>
  </form>
</div>

  <div id="blue-header" class="clearfix">
    <div id="blue-header-left" class="float-left">
    </div>
    <div id="blue-header-middle" class="float-left">
      <div id="header-upper-section" class="clearfix">
        <h1 class="float-left"><?php print $ttlr_toolbar->page_name;?></h1>
        <?php 
          if ($ttlr_toolbar->page_name == t('Mentions')) {
            //print tattlerui_mentions_rss_badge(); 
          }
        ?>            
        
        <div id="topic_selector" class="float-right">
          <?php if ($show_topic_selector) { ?>
            <select id="tattler_topic_selector" name="myselectbox" tabindex="2">
              <?php $selected = (empty($_GET['topic'])) ? 'selected' : ''; ?>
              <option value="all" <?php print $selected; ?>><?php print t('All Topics'); ?></option>
              <?php 
                $topics =  tattlerui_get_topic_titles('array'); 
                $topic_id = $_GET['topic'];
                foreach ($topics as $key => $topic) {
                  $title = ttlr_trim($topic, 30);
                  $selected = ($key == $topic_id) ? 'selected="selected"' : '';                  
              ?>
            	  <option value="<?php print $key; ?>" <?php print $selected;?> ><?php print $title; ?></option>
          	  <?php } ?>
          </select><!--/ #tattler_topic_selector -->
          <?php } ?>
        </div><!--/ #topic_selector -->

        <?php if ($show_tag_filter) { ?>
        <div id="tag-filter-element" class="float-right">

            <?php print drupal_get_form('tattlerui_tag_filter_form'); ?>
            <div id="tagfilterbutton"></div>
        </div>
        <?php } ?>
        
        <div id="toolbar_stretcher"></div><!-- stretches toolbar hight to ensure proper display when some controls are hidden -->
        
      </div><!--/ #header-upper-section -->
      
      <div id="header-second-section" class="clearfix" >

        <div id="timeframe" class="clearfix">
          <?php print $ttlr_toolbar->timeframe; ?>            
        </div><!--/time frame filter-->
      
        <div id="filter" class="clearfix">
          <?php print $ttlr_toolbar->show_only; ?>
        </div><!--/mentions filter-->

      </div><!--/ #header-second-section -->        
      
    </div><!--/ #blue-header-middle -->
    <div id="blue-header-right" class="float-left">
    </div>        
  </div><!--/ #blue-header-->
