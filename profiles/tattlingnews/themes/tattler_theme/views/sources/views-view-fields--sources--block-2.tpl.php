<?php

/*
[nid] => 2288
[node_title] => YouTube - Broadcast Yourself.
[node_data_field_url_field_url_value] => http://youtube.com
[node_type] => source
[node_vid] => 2288
[node_data_field_url_field_favicon_url_value] => http://s.ytimg.com/yt/favicon-vfl1123.ico
[node_data_field_topic_field_topic_nid] => 
[node_data_field_url_field_combined_rank_value] => 0.999997
[node_data_field_url_field_technorati_rank_value] => 
[node_created] => 1235023268
[node_data_field_url_field_mention_count_value] => 1086
[node_data_field_mention_count_field_mention_count_value] => 1086
[view_name] => sources:block_2
**/

$title = $row->node_title;
$title = empty($title) ? $row->node_data_field_url_field_url_value : $title;
$link = l($title, 'node/' . $row->nid);
$link .= ' (' . $row->node_data_field_url_field_mention_count_value . ')';
?>

<li><?php print $link; ?></li>
