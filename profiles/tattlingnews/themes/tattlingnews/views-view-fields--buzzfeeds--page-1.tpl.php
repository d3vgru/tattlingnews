<?php

$actions_links = "";

$actions = array();

$nid = $row->nid;

$destopt = array('query' => drupal_get_destination());

$actions = array(
  l( t('Remove Items'), 'node/' . $nid . '/purge', $destopt),
  l( t('Retrieve Items'), 'node/' . $nid . '/refresh', $destopt),  
  l( t('Edit Feed'), 'node/' . $nid . '/edit', $destopt),    
  l( t('Delete Feed'), 'node/' . $nid . '/delete', $destopt),      
);

$cnt = 1;

foreach ($actions as $a) {
  $actions_links .= $a;
  if ($cnt<sizeof($actions)) {
    $actions_links .= "&nbsp;&nbsp;|&nbsp;&nbsp;";  
  }
  $cnt++;
}

?>

<li class="entry clearfix">

  <div class="entry_summary clearfix">
  <div class="float-left">
  <h2><?php print $row->node_title; ?></h2>
  
  <div class="source_and_date"><?php print $actions_links;?></div><!--/source and date-->
  
  </div></div>
  
</li><!--/entry-->