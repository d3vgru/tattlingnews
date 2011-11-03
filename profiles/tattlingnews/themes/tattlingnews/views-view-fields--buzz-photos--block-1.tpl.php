<?php 

//echo "<pre>".print_r ( $row,true)."</pre>";

$img_url = $row->node_data_field_images_m_field_images_m_value;

$img_tag = img_extractor_thumbnail($img_url, 'buzz_photos', 55, 55);

$options = array('html'=>TRUE, 'attributes'=>array('target'=>'_blank'));

$img_tag = l($img_tag, $row->feedapi_node_item_url, $options);

echo $img_tag;
?>
 
 
<?php

/*
SAMPLE:
    [nid] => 6781
    [node_data_field_images_m_field_images_m_value] => http://farm4.static.flickr.com/3010/3029595607_5de1b2d5d0.jpg
    [node_data_field_images_m_delta] => 0
    [node_type] => mention
    [node_vid] => 6781
    [feedapi_node_item_url] => 
    [view_name] => buzz_photos:block_1
      
**/ ?>
