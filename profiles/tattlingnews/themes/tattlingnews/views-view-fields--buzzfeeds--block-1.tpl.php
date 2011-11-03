<?php

/**
[nid] => 128 // this is actually count
[node_feedapi_node_item_feed_title] => World Bank Twitter Feed
[node_feedapi_node_item_feed_nid] => 8499
[node_feedapi_node_item_feed__feedapi_link] => http://search.twitter.com/search?q=%22World+Bank%22
[view_name] => buzzfeeds:block_1
**/

$options = array('html'=>TRUE, 'attributes'=>array('target'=>'_blank'));
$link = l($row->node_feedapi_node_item_feed_title, $row->node_feedapi_node_item_feed__feedapi_link, $options);
$link .= ' (' . $row->nid . ')';
?>

<li><?php print $link; ?></li>
