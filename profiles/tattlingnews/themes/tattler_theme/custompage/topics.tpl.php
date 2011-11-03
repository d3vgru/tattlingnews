<?php

$topics = tattlerui_get_topics();

?>

<div class="main_content">
  <div class="add-topic">
  Here are the topics you are currently monitoring.</br>
  <?php print l('Add a New Topic', 'node/add/topic'); ?>
  </div><!--/add-topic-->
  <div class="listing_area">
    <ul>
    <?php foreach ($topics as $tid => $topic){ ?>
      <li class="entry clearfix">
        <h2><?php print $topic->title; ?></h2>
        KEYWORDS: <?php print $topic->terms;?>
      </li>
    <?php } ?>
    </ul>
  </div>
</div>
