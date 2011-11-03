<?php

/**
* @TODO This is an extremely simplistic implementation, done in a hurry
* to just support Search functionality. Needs more work.
*/


$post_date = $node->feedapi_node->timestamp;
if (empty($post_date))  { //Not all RSSes provide this
  $post_date = $node->created;
}
if (!empty($post_date)) {
  $time_ago = format_interval((time() - $post_date)) . ' ' . t('ago');
}


$orig_url = $node->feedapi_node->url;
$orig_img = '<img src="' . base_path() . path_to_theme() . '/images/icon_go_to_entry.gif" alt="' . t('Go to entry') . '" />';
$orig_url = l($orig_img, $orig_url, array('html'=>TRUE, attributes => array('target' => '_blank')));

$delete_img = theme('image', path_to_theme() . '/images/icon_remove.gif', 'Remove', 'Remove');
$delete_link = l($delete_img, "buzz/{$node->nid}/delete", array('html' => TRUE, 'query' => drupal_get_destination()));

$source_link = l(t('Source Details'), 'node/' . $node->field_source[0]['nid'] );

?>

<div id="mentions_content" class="main_content">
<div class="listing_area">
<ul>

<li class="entry clearfix">

  <div class="entry_summary clearfix">
  <div class="float-left">
  <h2><?php print $node->title; ?></h2>
  
  <div class="source_and_date"><?php print $source_link;?> | <?php print $time_ago; ?></div><!--/source and date--></div><!--/float left-->
  
  </div><!--/entry summary-->         
  
    <p><?php print node_teaser(strip_tags($node->body, '<a><b>')); ?></p>
    
</li><!--/entry-->

</ul>
</div>
</div>