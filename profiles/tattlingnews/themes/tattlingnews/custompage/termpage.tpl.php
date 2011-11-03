<?php


$tid = arg(2);

if (is_numeric($tid)) {
  $term = taxonomy_get_term($tid); 
  $termname='';
  if (!empty($term->name))    {
    $termname = $term->name;
  }
}

tattlerui_embed_asset( path_to_theme() . '/js/mentions.listing.js', 'js');
tattlerui_embed_asset( path_to_theme() . '/js/tattlerui.flagging.js', 'js');

?>
  
<?php print custompage_view_tile( 'mention', $title=FALSE, 'block_1'); ?>          
        