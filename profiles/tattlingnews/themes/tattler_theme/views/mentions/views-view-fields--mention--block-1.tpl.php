
<?php

/*

stdClass Object
(
    [nid] => 25019
    [node_title] => No results
    [node_revisions_teaser] => Technorati search for "World Bank" has no results
    [node_revisions_format] => 0
    [node_revisions_body] => Technorati search for "World Bank" has no results
    [node_type] => mention
    [node_vid] => 25019
    [node_node_data_field_source_title] => 403 Forbidden
    [node_node_data_field_source_nid] => 13950
    [node_node_data_field_source_node_data_field_url_field_url_value] => http://technorati.com
    [node_node_data_field_source_type] => source
    [node_node_data_field_source_vid] => 13950
    [node_node_data_field_source_node_data_field_url_field_combined_rank_value] => 0.999387
    [node_node_data_field_source_node_data_field_url_field_alexa_data_url_value] => technorati.com/
    [node_node_data_field_source_node_data_field_url_field_favicon_url_value] => http://technorati.com/favicon.ico
    [feedapi_node_item_url] => http://technorati.com/search/%22World+Bank%22?noresults
    [feedapi_node_item_timestamp] => 1247281273
    [votingapi_cache_node_points_vote_sum_value] => 1
    [node_created] => 1247281273
    [node_node_data_field_source_node_data_field_url_field_technorati_authority_value] => 0
    [node_node_data_field_source_node_data_field_combined_rank_field_combined_rank_value] => 0.999387
    [node_created_day] => 20090710
    [view_name] => mention:block_1
)

**/


/**
* All Tags is not part of query, field renderer fetches it, so we oughta get it from the field:
*/
$all_tags = ($fields['tid']->content);

$options_blank = array('attributes'=>array('target'=>'_blank'));

$source_title = $row->node_node_data_field_source_title;
if (empty($source_title)) { //Use URL instead
  $source_title = $row->node_node_data_field_source_node_data_field_url_field_url_value;
}
$source_title = ttlr_trim($source_title, 45);
$source_external = l($source_title, $row->node_node_data_field_source_node_data_field_url_field_url_value,$options_blank);

$source_link = '<div class="float-left">' . t('Source') . ': ' . l($source_title, 'node/' . $row->node_node_data_field_source_nid ) . '&nbsp;|&nbsp;</div>';

$favico_url = $row->node_node_data_field_source_node_data_field_url_field_favicon_url_value;
$favico_url = str_replace('http//', 'http://', $favico_url);
if (!empty($favico_url) && TATTLER_DISPLAY_FAVICONS ) {
  $favico = '<img src="' . $favico_url . '" class="source_favicon" />';
} else {
  $favico = '<img src="' . path_to_theme() . '/images/clear.gif' . '" class="source_favicon" />';
}

$post_date = $row->feedapi_node_item_timestamp;
if (empty($post_date))  { //Not all RSSes provide this
  $post_date = $row->node_created;
}
if (!empty($post_date)) {
  $time_ago = format_interval((time() - $post_date)) . ' ' . t('ago');
}


$orig_url = $row->feedapi_node_item_url;

$comment_img = theme('image', path_to_theme() . '/images/actbar/icon_comment.gif', 'Comment', 'Comment');
$comments_link = l($comment_img . ' ' . t('Comment'), "node/{$row->nid}", array('html' => TRUE, 'query' => drupal_get_destination()));

$mention_title = ttlr_trim($row->node_title, 140);

$tweet_img = theme('image', path_to_theme() . '/images/actbar/icon_tweet.gif', 'Tweet', 'Tweet');
$tweet_link = l($tweet_img . ' ' . t('Tweet'), $orig_url, 
                array('html' => TRUE, 
                      'attributes' => array('class' => 'retweet', 
                                            'title' => $mention_title,
                                            'target' => '_blank',
                                           ),
                ));


$delete_img = theme('image', path_to_theme() . '/images/actbar/icon_remove.gif', 'Remove', 'Remove');
$delete_link = l($delete_img . ' ' . t('Delete'), "node/{$row->nid}/delete", array('html' => TRUE, 'query' => drupal_get_destination()));

$votes = $row->votingapi_cache_node_points_vote_sum_value;
$votes = (empty($votes)) ? 0 : $votes;

$mention_title_safe = str_replace('\'', '"', $mention_title);
$addthis = "<div class=\"addthis_default_style float-left\"><a addthis:url=\"$orig_url\"  addthis:title=\"$mention_title_safe\" href=\"http://www.addthis.com/bookmark.php?v=250&amp;pub=xa-4a948c0b1cb90fd5\" class=\"addthis_button float-left\" style=\"color: #fe6d4c;\">Share</a>&nbsp;|&nbsp;</div>

";

?>

<li class="entry clearfix">

  <div class="entry_summary clearfix">
  <div class="float-left">
    <div class="float-left">
      <?php print $favico; ?>
    </div>
    <div class="float-left">
      <div class="title-and-actions" class="float-left clearfix">
        <h2 class="float-left"><?php print l($row->node_title, $orig_url, array('attributes'=>array('target'=>'_blank'))); ?></h2>   
        <div class="actions" style="display: none;">
        <ul class="ttlr_suckerfish">
          <li><div class="act-button"></div>
            <ul>
              <li><?php print $comments_link; ?></li>
              <li><?php print $tweet_link; ?></li>              
              <?php 
                if (user_access('administer tattler')) {
                  $options = array('attributes'=>array('rel'=>'facebox'), 'html' => TRUE, 'query' => drupal_get_destination()); 
                  $edit_img = theme('image', path_to_theme() . '/images/actbar/icon_edit.gif', 'Edit', 'Edit');                  
              ?>
              <li class="tags"><?php print l($edit_img . ' ' . t('Edit'), 'buzz/' . $row->nid . '/edit', $options);?></li>                        
              <?php } ?>
              
              <li><?php print $delete_link; ?></li>                
            </ul>
          </li>
        </ul>
       </div><!--/ .actions -->   
      </div><!--/ .title-and-actions -->
   
      <div class="source_and_date clearfix">
        <div class="float-left clearfix"><?php print $source_link;?><?php print _tattlerui_plus1_widget($row->nid, $votes); ?><?php print $addthis; ?><?php print flag_create_link('bookmark', $row->nid); ?></div>
        <div class="float-right"><?php print $time_ago; ?></div>
      </div><!--/source and date-->
    </div><!--/ .float left-->
  </div><!--/ .float-left-->
  
  </div><!--/entry summary-->         
  
  

  <?php /***** *********** Entry Detail ******************** ****/ ?>  
    
  <div class="entry_detail clear clearfix" style="display: none;">
  <div class="graphic_and_text">
  <div class="graphic float-left"><?php //print $featured_photo; ?></div>
  <p><?php print strip_tags($row->node_revisions_teaser, '<a><b>'); ?></p>
  
  </div><!--/graphic and text-->
  
  <div class="source_ranking clearfix">
  <ul>
  <li><?php print $source_link; ?>&nbsp;&nbsp;</li>
    <li class="technorati"><?php print $trati;?></li>
    <li class="buzz"><?php print $buzz_rank; ?></li>                   
  </ul>               
  
  </div><!--/source ranking-->
  
  <div class="all_mention_tags clear clearfix">
    <span class="all_tags_caption"> <?php print t('Tags:'); ?> </span>
    <span class="tag_to_edit"><?php print $all_tags; ?></span>
  </div>
  
  <div class="source_actions clear clearfix">
  <ul>
  
  <?php 
    if (user_access('administer tattler')) {
      $options = array('attributes'=>array('rel'=>'#overlay')); 
  ?>
    <li class="tags">
      <?php print l(t('Edit Node Essentials'), 'buzz/' . $row->nid . '/edit', $options);?>
    </li>  
  <?php } ?>
    
  <li><?php print flag_create_link('watchlist', $row->node_node_data_field_source_nid); ?></li> 
  <li><?php print flag_create_link('blacklist', $row->node_node_data_field_source_nid); ?></li>     

  </ul>              
  
  </div><!--/source actions-->   
  <div class="close_entry_detail"><a class="mention_close_link" href="#">CLOSE</a></div>  
  
  </div><!--/entry detail--> 
  
</li><!--/entry-->