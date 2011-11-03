<div id="ttlr-help-page">
  <h1><?php print $node->title;?></h1>
  <div id="ttlr-help-content"
  <?php print $node->body; ?>
  </div>
  
  <div class="clear-block">
    <div class="meta">
    <?php if ($taxonomy): ?>
      <div class="terms"><?php print $terms ?></div>
    <?php endif;?>
    </div>

    <?php if ($links): ?>
      <div class="links"><?php print $links; ?></div>
    <?php endif; ?>
  </div>

</div>