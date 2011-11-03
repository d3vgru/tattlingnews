<?php
// $Id$
?>
<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ' '. $status; print ' '. $zebra; ?>">

  <div class="clear-block">

  <?php if ($comment->new) : ?>
    <span class="new"><?php print drupal_ucfirst($new) ?></span>
  <?php endif; ?>

  <?php print $picture ?>

    <div class="content">
      <?php print $content ?>
      <?php if ($signature): ?>
      <div class="clear-block">
        <div>—</div>
        <?php print $signature ?>
      </div>
      <?php endif; ?>
    </div>
    
  </div>

  <div class="clearfix">
    <div style="border-bottom: 1px solid gray; margin: 3px 0 2px 0;"></div>
    <?php if ($submitted): ?>
    <div class="submitted"><?php print $submitted; ?></div>
    <?php endif; ?>
  
    <?php if ($links): ?>
      <div class="links"><?php print $links ?></div>
    <?php endif; ?>
  </div>
  
</div>
