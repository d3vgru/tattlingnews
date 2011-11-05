<?php

function tattlerui_mention_views_query_alter(&$view, &$query) {
  tattlerui_mention_list_views_query_alter($view, $query);
  
  if ($filter == 'mostvotes') { 
    $query->orderby[0] = 'votingapi_cache_node_points_vote_sum_value DESC, node_created DESC';
  }

  // Make nodes unique. All the left joins going on can return duplicate mentions (same nid, twice).
  $query->groupby =   array('nid');

}

/**
* Generic portion of mention-list related query alteres shared by both mention View and ttlr_semantic_views View.
*/
function tattlerui_mention_list_views_query_alter(&$view, &$query) {

    _topic_query_alter($query);
    _type_query_alter($query);

    /** Filter by current Source on a Source Detail Page **/
    if (arg(0)=='node' && is_numeric(arg(1))) {
      $ntype = @db_result(@db_query('SELECT type from {node} WHERE nid=%d', arg(1)));
      if ($ntype=='source') {
        $query->where[0]['clauses'][] = 'node_node_data_field_source.nid = %d';
        $query->where[0]['args'][] = arg(1);
      }
    }
    
     /** Filter RSS Feed by current Source on a Source-Specific RSS **/
    if (arg(0) == 'rss' && arg(1) == 'mentions' && arg(2)=='source' && is_numeric(arg(3))) {
      $ntype = @db_result(@db_query('SELECT type from {node} WHERE nid=%d', arg(3)));
      if ($ntype=='source') {
        $query->where[0]['clauses'][] = 'node_node_data_field_source.nid = %d';
        $query->where[0]['args'][] = arg(3);
      }
    }

    /* filter mentions by a taxonomy term */
    if (arg(0)=='node' && !empty($_GET['tagged'])) {
      tattlerui_filter_query_by_term($query);      
    }
    
    /* Term-page filtering **/
    if (arg(0)=='taxonomy' && arg(1)=='term' && is_numeric(arg(2))) {
    
      $alias = $query->queue_table('term_node');
      $query->where[0]['clauses'][] = $alias . '.tid in (%d)';
      $query->where[0]['args'][] = arg(2);
      
    }
    
    $filter = $_GET['filter'];
    $timeframe = $_GET['timeframe'];
    $tagfilter = $_GET['tagged'];
        
    if ($filter == 'watchlist') {     
      $query->where[0]['clauses'][] = 'flag_content_node_1.uid IS NOT NULL';
    }

    if ($filter == 'bookmarks') {     
      $query->where[0]['clauses'][] = 'flag_content_node_2.uid IS NOT NULL';
    }

    tattlerui_timeframe_where_cond($query, $timeframe, $view->name);

    return;
    
    /*** DISABLED FROM HERE BELOW **/

    // Hack to fix the mentions view relationship breaking when sorting is introduced
    //$query->table_queue['node_data_field_combined_rank']['relationship'] = 'node_node_data_field_source';
    //$query->table_queue['node_data_field_combined_rank']['join']->left_table = 'node_node_data_field_source';
    
}

function tattlerui_sources_views_query_alter(&$view, &$query) {
  
  $filter = $_GET['filter'];
  $sorting = $_GET['sortby'];

  // Makes sense only for Top Sources block  
  if ($view->current_display == 'block_2') {
    
    $timeframe = $_GET['timeframe'];
    tattlerui_timeframe_where_cond($query, $timeframe, $view->name); 
     
  }
    
  // Makes sense for both block and full listing  
  if ($filter == 'watchlist') {     
    if ($view->current_display == 'block_2') { //prevent doubling filter name
      tattlerui_prefix_block_title($view->name, 'register', t('Watchlisted'));
    }
    $query->where[0]['clauses'][] = 'flag_content_node.uid IS NOT NULL';
  }

  // Makes sense only for the full Sources Listing page
  if ($view->current_display == 'block_1') {
    if ($filter == 'blacklist') {     
      $query->where[0]['clauses'][] = 'flag_content_node_1.uid IS NOT NULL';
    }
 
    if (empty($sorting)) {$sorting=0;} 
    if ($sorting == 'alpha') {
      $query->orderby[0] = ' node_title ASC ';
    }
  
    if ($sorting == 'chrono') {
      $query->orderby[0] = ' node_created DESC ';
    }
    
    if ($sorting == 'mostbuzz') {
      $query->orderby[0] = ' node_data_field_url_field_mention_count_value DESC ';
    }
  }
  
  // Make nodes unique. All the left joins going on can return duplicate nodes (same nid, twice).
  $query->groupby =   array('nid');

  
}

function tattlerui_buzzfeeds_views_query_alter(&$view, &$query) {
  
  $filter = $_GET['filter'];
  $sorting = $_GET['sortby'];
 
  if ($view->current_display == 'block_1') {
    $timeframe = $_GET['timeframe'];
    tattlerui_timeframe_where_cond($query, $timeframe, $view->name); 
  } 
  
  if ($view->current_display == 'page_1') {
    if ($sorting == 'alpha') {
      $query->orderby[0] = ' node_title ASC ';
    }
  
    if ($sorting == 'chrono') {
      $query->orderby[0] = ' node_created DESC ';
    }
  }
    
}

function tattlerui_term_frequency_views_query_alter(&$view, &$query) {
  $timeframe = $_GET['timeframe'];
  $filter = $_GET['filter'];
      
  $query->add_field ('term_data', 'tid', 'term_data_tid');
  $query->add_field ('vocabulary', 'vid', 'vocabulary_vid'); 

  // This filter must be 1st one to produce grammatically correct sentences :)
  if ($view->current_display == 'block_1') { //only for top-tags block
    if (arg(0)=='node' && is_numeric(arg(1))) { 
      $nid = arg(1);
      $node = node_load($nid);
      if (is_object($node) && $node->type=='source') {
        // Filter by current source!
        $query->where[0]['clauses'][] = 'node_data_field_source.field_source_nid = %d';
        $query->where[0]['args'][] = $nid;
        tattlerui_prefix_block_title($view->name, 'register', t('Source\'s'));                 
      }
    }
  }

  tattlerui_timeframe_where_cond($query, $timeframe, $view->name); 
  
  if ($filter == 'bookmarks') {     
    $query->where[0]['clauses'][] = 'flag_content_node.uid IS NOT NULL';
    tattlerui_prefix_block_title($view->name, 'register', t('Bookmarked'));         
  }
  
}

function tattlerui_buzz_photos_views_query_alter(&$view, &$query) {
  $timeframe = $_GET['timeframe'];  
  $filter = $_GET['filter'];
  
  _topic_query_alter($query);
  
  // This filter must be 1st one to produce grammatically correct sentences :)
  if ($view->current_display == 'block_1') { //only for top-tags block
    if (arg(0)=='node' && is_numeric(arg(1))) { 
      $nid = arg(1);
      $node = node_load($nid);
      if (is_object($node) && $node->type=='source') {
        // Filter by current source!
        $query->where[0]['clauses'][] = 'node_data_field_source.field_source_nid = %d';
        $query->where[0]['args'][] = $nid;
        tattlerui_prefix_block_title($view->name, 'register', t('Source\'s'));                 
      }
    }
  }
  
  // Make nodes unique. All the left joins going on can return duplicate nodes (same nid, twice).
  $query->groupby =   array('nid');
  
  tattlerui_timeframe_where_cond($query, $timeframe, $view->name); 
  
  if ($filter == 'bookmarks') {     
    $query->where[0]['clauses'][] = 'flag_content_node.uid IS NOT NULL';
    tattlerui_prefix_block_title($view->name, 'register', t('Bookmarked'));         
  }

}


/**
* Re-usable filter called from multiple query rewrite functions
*/
function _topic_query_alter(&$query) {

    /* filter mentions by topic */
    $topic_id = $_GET['topic'];
    if ($topic_id=='all') $topic_id = NULL;
    if (!empty($topic_id) && is_numeric($topic_id) && $topic_id>0) {
        $alias = $query->queue_table('term_node');          
        $query->where[0]['clauses'][] = $alias . '.tid in (%s)';
        $query->where[0]['args'][] = $topic_id;   
    }
    
}


/**
* Re-usable filter called from multiple query rewrite functions
*/
function _type_query_alter(&$query) {
  /* filter mentions by type */
    $type = $_GET['msection'];
    if ($type=='all') $type = NULL;
    if (!empty($type)) {
      $type = urldecode($type);
      $type_term = 'type:' . strtolower($type);

      if ($type_term=='type:multimedia') {
        $types_tid = array();
        $exp_types = array('video', 'photo', 'audio');
        foreach ($exp_types as $t) {
          $tid = db_result(db_query("SELECT tid FROM {term_data} WHERE name='%s'", 'type:' . $t));
          if (!empty($tid)) {
            $types_tid[] = $tid;
          }
        }        
        $type_tid = implode(',', $types_tid);        
      }
      else {
        $type_tid = db_result(db_query("SELECT tid FROM {term_data} WHERE name='%s'", $type_term));
      }
      
      if (empty($type_tid)) $type_tid = -1; //non-existant tid to get zero results.
      
      if ($type_tid>0 || $type_tid==-1) {
        $alias = $query->queue_table('term_node');          
        $query->where[0]['clauses'][] = $alias . '.tid in (%s)';
        $query->where[0]['args'][] = $type_tid;   
      }
    }
}

/**
* Re-usable function called from multiple query rewrite functions.
*/
/**
* Re-usable function called from multiple query rewrite functions.
*/
function tattlerui_timeframe_where_cond(&$query, $timeframe, $view_name) {

    if (preg_match('#\d{4}-\d{2}-\d{2}#i', $timeframe)) {
      //There's something wrong with passing as an argument. Sorry :( doing manually
      $timeframe = check_plain($timeframe);
      if (!is_numeric(str_replace('-', '', $timeframe))) return;
      
      $query->where[0]['clauses'][] = '(FROM_UNIXTIME(node.created) >= \''.$timeframe.'\' ) AND (FROM_UNIXTIME(node.created) < DATE_ADD(\''.$timeframe.'\',INTERVAL 1 DAY) )';
      
      tattlerui_prefix_block_title($view_name, 'register', t('Time-Filtered'));     
    }

    if ($timeframe == 'week') {
     $query->where[0]['clauses'][] = 'FROM_UNIXTIME(node.created) > DATE_SUB(NOW(),INTERVAL 7 DAY)';
      tattlerui_prefix_block_title($view_name, 'register', t('Time-Filtered'));     
    }

    if ($timeframe == 'month') {
     $query->where[0]['clauses'][] = 'FROM_UNIXTIME(node.created) > DATE_SUB(NOW(),INTERVAL 30 DAY)';
      tattlerui_prefix_block_title($view_name, 'register', t('Time-Filtered'));      
    }

    if ($timeframe == 'sixmonths') {
     $query->where[0]['clauses'][] = 'FROM_UNIXTIME(node.created) > DATE_SUB(NOW(),INTERVAL 6 MONTH)';
      tattlerui_prefix_block_title($view_name, 'register', t('Time-Filtered'));      
    }

    if ($timeframe == 'year') {
     $query->where[0]['clauses'][] = 'FROM_UNIXTIME(node.created) > DATE_SUB(NOW(),INTERVAL 1 YEAR)';
      tattlerui_prefix_block_title($view_name, 'register', t('Time-Filtered'));      
    }
}
