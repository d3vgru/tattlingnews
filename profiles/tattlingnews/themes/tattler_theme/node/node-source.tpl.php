<?php

//$trati = (empty($node->field_technorati_authority[0]['view'])) ? t('n/a') : $node->field_technorati_authority[0]['view'];

$buzz_rank = (empty($node->field_combined_rank[0]['view'])) ? t('n/a') : $node->field_combined_rank[0]['view'];

$source_profile_mpath = drupal_get_path('module', 'feedapi_source');
require_once($source_profile_mpath . '/data_providers/compete.inc');
$compete_provider = new CompeteDataProvider();
$compete_provider->fetchData($node); 
//compete rank can not be treated as integer since compete returns values like 2,506
$compete_rank = (string)$compete_provider->results->ranking;
$compete_rank = (!empty($compete_rank) && $compete_rank != '0') ? $compete_rank : t('n/a');

require_once($source_profile_mpath . '/data_providers/technorati.inc');
$trati_provider = new TechnoratiDataProvider();
$trati_provider->fetchData($node); 
$trati = $node->{$trati_provider->field_authority}[0]['value'];
$trati = (!empty($trati)) ? $trati : t('n/a');


$source_url = l($node->field_url[0]['view'], $node->field_url[0]['value']);

$source_num_mentions = (int)$node->{MENTION_COUNT_FIELD}[0]['value'];
$source_num_mentions .= ' ' . t('Mentions');

$favico = $node->field_favicon_url[0]['value'];
$favico = "<img src=\"$favico\" width=\"16px\" height=\"16px\" />";

?>

         <div id="sources_detail" class="main_content clear clearfix">
         <div class="source33"><?php print l(t('sources'), 'sources');?> &laquo;</div>
  <h1><?php print $node->title;?></h1>
  <div class="source_link33"><?php print $favico . $source_url ?></div>
  
    <div class="source_ranking clear clearfix">
                <ul>
                    <li><?php print  $source_num_mentions; ?></li>
                    <li class="technorati"><?php print $trati; ?></li>
                    <li class="compete"><?php print $compete_rank; ?></li>
                </ul>               
                
                </div><!--/source ranking-->
              
                
                <div class="source_actions clearfix">
                <ul>                
                	<li><?php print flag_create_link('watchlist', $node->nid); ?></li>
                	<li><?php print flag_create_link('blacklist', $node->nid); ?></li>                	
                </ul>              
                
                </div><!--/source actions-->
                


<?php

  // SET UP FILTERING

  $sorting = check_plain($_GET['timeframe']);
  if (empty($sorting)) $sorting = 'all'; //default

  $filter = check_plain($_GET['filter']);
  if (empty($filter)) $filter = 'mostbuzz';  //default

  $names = array( 'filter' => array(), 'sorting' => array() );  
  
  $names['filter'] = array (
    'all' => t('All'),
//    'watchlist' => t('Watchlist'),  // Does not make sense in a context of one specific source
    'bookmarks' => t('Bookmarks'),    
  );

  $names['sorting'] = array (
    'all' => t('All'),  
//    'givendate' => t('Given Date'),  // Too much hassle, not important
    'week' => t('Week'),        
    'month' => t('Month'),        
    'sixmonths' => t('6 Months'),            
    'year' => t('One Year'),            
  );

?>

  
  <?php print custompage_view_tile( 'mention', $title=FALSE, 'block_1'); ?>          
        
  </div><!--/sources detail content-->
  
  