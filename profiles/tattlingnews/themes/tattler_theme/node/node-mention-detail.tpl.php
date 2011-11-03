<?php

/**
* @TODO This is an extremely simplistic implementation, done in a hurry
* to just support commeting functionality. Needs more work.
*/

$post_date = $node->feedapi_node->timestamp;
if (empty($post_date))  { //Not all RSSes provide this
  $post_date = $node->created;
}
if (!empty($post_date)) {
  $time_ago = format_interval((time() - $post_date)) . ' ' . t('ago');
}


$orig_url = $node->feedapi_node->url;

$source_nid = $node->field_source[0]['nid'];
$source = node_load($source_nid);
$stitle = (empty($source->title)) ? $source->field_url[0]['value'] : $source->title;
$stitle = ttlr_trim($stitle, 70);
$source_link = t('Source:') . ' ' . l($stitle, 'node/' . $source->nid);

?>

<div id="mention-detail">

  <h1><?php print (l($node->title, $orig_url, array('attributes' => array('target' => '_blank')))); ?></h1>
  
  <div class="source_and_time"><?php print $source_link;?> | <?php print $time_ago; ?></div><!--/source and date-->

  <div id="node-content"><?php print node_teaser(strip_tags($node->content['body']['#value'], '<a><b>')); ?></div>  

  <?php if (arg(0)=='node' && is_numeric(arg(1))) : ?>
    <div id="visible-comments">
      <h2>Comments:</h2>
      <?php print comment_render($node); ?>
    </div>
    <?php print comment_form_box(array('nid' => $node->nid), t('Post new comment')); ?>
  <?php endif; ?>

</div><!--/ #mentions-detail-->