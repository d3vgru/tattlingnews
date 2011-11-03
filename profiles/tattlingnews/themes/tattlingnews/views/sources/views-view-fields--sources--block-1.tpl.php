<?php
/**

[nid] => 923
[node_title] => { A }
[node_data_field_url_field_url_value] => http://aliedwards.typepad.com/_a_
[node_type] => source
[node_vid] => 923
[node_data_field_url_field_favicon_url_value] => 
[node_data_field_url_field_watchlist_value] => 
[node_data_field_topic_field_topic_nid] => 
[node_data_field_url_field_combined_rank_value] => 0.890872
[node_data_field_url_field_technorati_rank_value] => 1398
[view_name] => sources:block_1

**/

$blanktarget = array('attributes'=>array('target'=>'blank'));

$source_link = l(substr($row->node_data_field_url_field_url_value, 0, 35), 'node/' . $row->nid);
$source_link .= "&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;";
$source_link .= t("Mentions:") . " " . $row->node_data_field_url_field_mention_count_value;
$source_link .= "&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;";
$source_link .= l( t('Source Website'), $row->node_data_field_url_field_url_value, $blanktarget);

$favico_url = $row->node_data_field_url_field_favicon_url_value;
if (!empty($favico_url)) {
  $favico = '<img src="' . $favico_url . '" class="source_favicon" />';
} else {
  $favico = '<img src="' . path_to_theme() . '/images/clear.gif' . '" class="source_favicon" />';
}

$source_link = $favico . $source_link;


$trati_rank = (empty($row->node_data_field_url_field_technorati_rank_value)) ? t('n/a') : $row->node_data_field_url_field_technorati_rank_value;

$buzz_rank = (empty($row->node_data_field_url_field_combined_rank_value)) ? t('n/a') : $row->node_data_field_url_field_combined_rank_value;

?>

<li class="entry clearfix">

  <div class="entry_summary clearfix">
  <div class="float-left">
  <h2><?php print $row->node_title; ?></h2>
  
  <div class="source_and_date"><?php print $source_link;?></div><!--/source and date-->  
  </div><!--/float left-->
  
  <div class="actions" style="display: none;">
  <ul>
    <li><?php print flag_create_link('watchlist', $row->nid); ?></li> 
    <li><?php print flag_create_link('blacklist', $row->nid); ?></li>     
    <!--li><a id="<?php print $row->nid;?>" class="buzz_icon blacklist"></a></li-->
  </ul>
  
  </div><!--/actions-->   
  </div><!--/entry summary-->         
    
</li><!--/entry-->