<?php
// $Id: views-view-list--ttlr-semantic-views--block.tpl.php,v 1.1.2.2 2009/11/18 04:50:48 inadarei Exp $
/**
 * @file views-view-list--ttlr-semantic-views--block.tpl.php
 * Simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<?php tattler_semantics_attach_block_css(); ?>

<div id="semantic-entities-block" class="module clearfix">
  <div class="title_bar clearfix"><h3><?php print tattlerui_prefix_block_title($view->name, 'query') . t('top entities'); ?></h3></div>
  <ul>
    <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
    <?php endforeach; ?>    
  </ul> 
</div><!--/ #semantic-entities -->
