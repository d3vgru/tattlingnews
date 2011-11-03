<div id="photos" class="module clearfix">
  <div class="title_bar clearfix"><h3><?php print tattlerui_prefix_block_title($view->name, 'query') . t('incoming photos'); ?></h3></div>
  <ul>
    <?php foreach ($rows as $id => $row): ?>
      <li><?php print $row; ?></li>
    <?php endforeach; ?>    
  </ul> 
</div><!--/photos-->