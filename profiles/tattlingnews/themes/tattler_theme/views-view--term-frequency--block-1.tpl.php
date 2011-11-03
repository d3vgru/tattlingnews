<?php
$db_results = $view->result;

$results = array();
if (is_array($db_results)) {
  foreach ($db_results as $db_tag) {
    if ($db_tag->term_data_tid != 0) {
      $tag = new stdClass();
      $tag->count = (int)$db_tag->nid;
      $tag->tid = (int)$db_tag->term_data_tid;
      $tag->name = $db_tag->term_data_name; 
      $tag->vid = $db_tag->vocabulary_vid;
      $results[] = $tag;    
    }    
  }
}

$tags = tattlerui_build_weighted_tags($results, 6);
$tags = tagadelic_sort_tags($tags);

$tags = theme('tagadelic_weighted', $tags); 

$blockname = tattlerui_prefix_block_title($view->name, 'query') . t('top tags');



$tags = ' <div id="top_tags" class="module clearfix clear">
          <div class="title_bar clearfix">
          <h3 class="float-left">' . $blockname . '</h3>
          <!--div class="chart_icon">
          <a href="#">'.t('CHART').'</a>
          </div--></div>
          <div id="tags">' . $tags . '</div></div>';

echo  $tags;
 
 
