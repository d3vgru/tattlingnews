<?php

define ('tattler_TRENDS_GETDATA_ERROR', -1);


function tattler_trends_menu() {
  $items = array();

  $items['tattler/term/autocomplete'] = array(
    'title' => 'Autocomplete taxonomy',
    'page callback' => 'tattler_trend_autocomplete',
    'access arguments' => array('access content'),
    'type' => MENU_CALLBACK,
  );    
    
  return $items;
}


function tattler_trends_query_setup_form() {

  $mpath = drupal_get_path('module', 'tattler_trends');
  drupal_add_js ($mpath . '/tattler_trends.js');
  
  $form = array(); 
  
  $form['#method'] = 'get';
  
  $chart_apis = chart_graphs_apis();  
  
//  dpm($chart_apis);
  
  $first_api = reset($chart_apis);
  $curr_engine = (empty($_GET['chart_engine'])) ? $first_api->name : $_GET['chart_engine'];
  
  $form['chart_engine'] = array(
        '#type' => 'select',
        '#title' => t('Choose Charting Engine'),
        '#options' => array(),        
        '#default_value' => trim($_GET['chart_engine']),                   
  );
  
  if ( is_array($chart_apis) ) {
    foreach ($chart_apis as $api_key => $api) {
      $form['chart_engine']['#options'][$api->name] = $api->nice_name;
      
      $tagid = ' id = "bchen_selector_' . $api->name . '" ';
      if ($api->name != $curr_engine) {
        $attr = ' class="bchen_selector nodisplay"  ' . $tagid;
      }
      else {
        $attr = ' class="bchen_selector"  ' . $tagid;
      }

      
      $form['chart_type_' . $api->name] = array(
        '#prefix' => "<div $tagid $attr>",
        '#suffix' => '</div>',
        '#type' => 'select',
        '#title' => t('Choose %engine Chart Type', array('%engine'=>$api->nice_name)),
        '#options' => array(),
        '#default_value' => trim($_GET['chart_type_' . $api->name]),                   
      );
      
      if (is_array($api->chart_types)) {
        foreach ($api->chart_types as $key => $val) {
          $form['chart_type_' . $api->name]['#options'][$key] = $val; 
        }
      }

    }
  }


  /*$form['chart_type'] = array(
        '#type' => 'select',
        '#title' => t('Choose Chart Type'),
        '#options' => array(
          'line' => t('Line'),
          'pie' => t('Pie'),
          'bar_3d' => t('3D Bar'), 
          'bar_glass' => t('Glass Bar'),           
        ),
        '#default_value' => trim($_GET['chart_type']),                   
  );*/

  $form['period_length'] = array(
        '#prefix' => '<div class="tattler_form_single_line clearfix">',
        '#type' => 'textfield',
        '#title' => t('Period'),
        '#default_value' => ($_GET['period_length'] > 0) ? $_GET['period_length'] : 6 ,
        '#size' => 10,
  );
  
  $form['period_type'] = array(
        '#type' => 'select',
        '#options' => array(
          'weeks' => t('Weeks'),
          'months' => t('Months'),                    
          'days' => t('Days'),          
        ),
        '#default_value' => $_GET['period_type'],
        '#suffix' => '</div>',
  );

  $vocabularies = taxonomy_get_vocabularies($type = 'mention');
    
  $voc_options = array(); 
  $voc_options['any'] = t('Cross-Vocabulary (possible duplicates)');  
  if (is_array($vocabularies)) {
    foreach ($vocabularies as $voc) {
      $voc_options[$voc->vid]  = t($voc->name);
    }
  }

  $form['vocabulary'] = array(
        '#type' => 'select',
        '#title' => t('Choose a vocabulary'),
        '#default_value' => $curr_voc,
        '#options' => $voc_options,
        '#multiple' => FALSE,
  );
  
  $terms_expl_msg = t('Comma-separated list of term names and/or ids. You can also use + condition
  and join tags as far as you provide tids (not names) in the condition. Lookup shows the tids.');
  
  
  $curr_voc = (empty($_GET['vocabulary'])) ? 'any' : $_GET['vocabulary'];
  
  $tagid = ' id = "bvcb_selector_any" ';
  if ('any'!=$curr_voc) {
    $attr = ' class="bvcb_selector nodisplay"  ' . $tagid;
  }
  else {
    $attr = ' class="bvcb_selector"  ' . $tagid;
  }
  $form['taxonomy']['tags']['bvcb_any' ] = array(
          '#type' => 'textfield',
          '#prefix' => '<div ' . $attr . '>',
          '#suffix' => '</div>',
          '#title' => t('Cross-Vocabulary (possible duplicates)'),
          '#description' => $terms_expl_msg,
          '#default_value' => $_GET['bvcb_any'],
          '#autocomplete_path' => 'tattler/term/autocomplete',
          '#size' => 37,
          '#maxlength' => 1024,
  );
  

  if (is_array($vocabularies)) {
    foreach ($vocabularies as $voc) {
    
      $tagid = ' id = "bvcb_selector_' . $voc->vid .'" ';
      if ($voc->vid!=$curr_voc) {
        $attr = ' class="bvcb_selector nodisplay"  ' . $tagid;
      }
      else {
        $attr = ' class="bvcb_selector"  ' . $tagid;
      }
       
      $form['taxonomy']['tags']['bvcb_' . $voc->vid] = array(
            '#type' => 'textfield',
            '#prefix' => '<div ' . $attr . '>',
            '#suffix' => '</div>',
            '#title' => $voc->name,
            '#description' => $terms_expl_msg,
            '#default_value' => $_GET['bvcb_' . $voc->vid],
            '#autocomplete_path' => 'taxonomy/autocomplete/'. $voc->vid,
            '#size' => 37,
            '#maxlength' => 1024,
      );
    }
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Query'),
  );

  $form['clear'] = array(    
//    '#value' => '<input class="form-button" type="reset" value="' . t('Clear the Form') . '" />',
    '#value' => l(t('Start Over'), 'trends', array('attributes'=>array('class'=>'start_over')) ),
  );  
    
  return $form;

}

function tattler_trends_draw_chart() {
  
  $terms = tattler_trends_parse_terms_from_query();
  
  if (empty($terms)) return "";
  
  $result = tattler_trends_get_data($terms);
  
  if ($result == tattler_TRENDS_GETDATA_ERROR) { // some error occured. message would have been set where it occured. Just return.
    return "";    
  }
  
  if (empty($result)) {
    drupal_set_message(t('Query criteria returned zero results'));
    return "";
  };
  
  $chart_engine = $_GET['chart_engine'];
  $canvas = chart_graphs_get_graph($chart_engine);  
  $canvas->type = $_GET['chart_type_' . $chart_engine]; 
        
  $canvas->title = t("Tattler Trend Chart");
  $canvas->y_legend = t("# of Mentions");
  $canvas->colour = '#FFFFFF';
  $canvas->series = $result->series;
  
  // A pie can NOT draw series!
  if ($canvas->type == 'pie') {
    if ( sizeof ($canvas->series) > 1) {
      drupal_set_message(t('Data Error: Pie charts can not draw series. 
        Make sure your query criteria does not return multiple series. 
        It can happen even if you indicate one term, but with a name (instead of tid), 
        since a term with the same name may exist in different vocabularies.'), 'error');
      return "";      
    }
  }

  $keys = array_keys($canvas->series);
  $zero_ser = $canvas->series[$keys[0]];
  $canvas->x_labels = range(1,sizeof($zero_ser),1);
  
  //$canvas->x_labels = array('one', 'two', 'three', 'four', 'five', 'six', 
 //                           'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve');  
  
  $canvas->width = 590;
  $canvas->height = 450;

  $out = $canvas->get_chart();
  print $out;
  
}


function tattler_trends_get_data($terms, $date_type, $date_period) {

  $results = array();
  
  if (!is_array($terms)) return $results;
  
  //$date_type = $_GET['period_type'];  
  //$date_period = $_GET['period_length'];
  
  if (empty($date_period)) {
    drupal_set_message(t('You have to indicate period length!'));
    return '';
  }
  
  switch ($date_type) {
  	case 'months':
  	$date_format = '%Y%m';
  	$date_clause = "FROM_UNIXTIME(n.created) > DATE_SUB(NOW(),INTERVAL $date_period DAY)";
    	break;
  	case 'weeks':
    $date_format = '%x%v';
  	$date_clause = "FROM_UNIXTIME(n.created) > DATE_SUB(NOW(),INTERVAL $date_period WEEK)";    
      break;
    case 'days':
    $date_format = '%Y%j';
    $date_clause = "FROM_UNIXTIME(n.created) > DATE_SUB(NOW(),INTERVAL $date_period DAY)";
      break;
  }

  /**
  * For prudes and purists: this is a complicated query-builder where
  * we do not have luxury of using parametrized queries. Also the term_ids
  * have been thoroughly sanitized and checked already.
  */
  foreach ($terms as $term ) {
    
    $parts = split('\+', $term);
    
    if (sizeof($parts)==1) { // simple tag
    
  		$tid = $parts[0];   
  		     
      $sql = "select count(*) num, mons
      from (
      select n.nid,n.changed, t.tid, 
       DATE_FORMAT( FROM_UNIXTIME(n.created), '%s') mons
       from {node} n
       inner join {term_node} as t on t.nid=n.nid
       where t.tid=$tid AND $date_clause 
       group by n.nid) as trm_x_node
       group by mons order by mons desc
       ";
  	}
  	elseif (sizeof($parts)>1) {
      $i=1; unset($sql_mix1); unset($sql_mix2); 	
      $errorous_tids = FALSE;	        
  		foreach ($parts as $tid) {
  		  //$tag_name .= $term->name." + ";
  		  //Make sure this is a real tid
  		  $tid = db_result(db_query('SELECT tid FROM {term_data} WHERE tid=%d', $tid));  		  
  		  if (!empty($tid)) {
    			$sql_mix1 .= "left join {term_node} as t$i on t$i.nid=n.nid ";
    			$sql_mix2 .= "t$i.tid=$tid AND ";
    			$i++;
  			} 
    		else {
    		  $errorous_tids = TRUE;
    		  drupal_set_message(t('The tid indicated in the query: %tid is invalid', array('%tid'=>$tid)), 'error');
    		}
  		}
  		  		
  		if (!$errorous_tids) {
  		  $sql = "select count(*) num, mons
            from (
               select n.nid,n.changed, 
               DATE_FORMAT( FROM_UNIXTIME(n.created), '%s') mons
               from {node} n
                ".$sql_mix1."WHERE ".substr($sql_mix2,0,-4)." AND $date_clause
               group by n.nid) as trm_x_node
            group by mons order by mons desc
            ";
      }   
    }
    
    $res = db_query($sql, $date_format);
    $results[$term] = array();
    while ($obj=db_fetch_object($res)) {
      $results[$term][$obj->mons] = $obj->num;
    }
  }    
  
  $results_chart = array(); $all_keys = array();

  //-- Fill in blanks and restructure
  if (is_array($results)) {
    foreach ($results as $result) {
      if (is_array($result)) {
        foreach ($result as $mons => $count ) {
          if (!in_array($mons, $all_keys)) {
           $all_keys[] = $mons;
          }
        }        
      }      
    }
  }
  
  if (!is_array($all_keys) || (sizeof($all_keys)<1)) {
    return array();
  }
  
  //-- Restore keys possibly lost due to grouping. Sigh
  $max = max($all_keys);
  $min = min($all_keys);

  $all_keys = array();
  for ($i=$min; $i<=$max; $i++) {
    $all_keys[] = $i;
  }
  
  //-- Fill in blanks and restructure
  if (is_array($results)) {
    foreach ($results as $tid => $result) {
      if (is_array($result)) {
        foreach ($all_keys as $key ) {
          
          if (is_numeric($tid)) {
            $tname = db_result(db_query('SELECT name FROM {term_data} WHERE tid=%d', $tid));  		  
          }
          else if (is_numeric(str_replace('+', '', str_replace(' ', '', $tid)))) {
            $parts = split('\+', $tid);
            $tname = ""; $i=0;
            foreach ($parts as $ptid) {
              $ctname = db_result(db_query('SELECT name FROM {term_data} WHERE tid=%d', $ptid));
              if ($i) {
                $tname .= " + ";
              }
              $tname .= $ctname;
              $i++;
            }
            
          }

          if (!empty($result[$key])) {
            $results_chart[$tname][$key] = (int)$result[$key];
          }
          else {
            $results_chart[$tname][$key] = 0;
          }
        }        
      }      
    }
  }  
    
  $result = new stdClass();
  $result->series =   $results_chart;
  
  return $result;
}

function tattler_trends_parse_terms_from_query() {

  $terms = array();  
  if (is_array($_GET)) {
    foreach ($_GET as $key => $val) {
      if (preg_match('#bvcb_(.+)#ims', $key, $matches))  {
        $vid = $matches[1];
        //dpm($vid);
        //dpm($val);
        if (!empty($val)) {
          $split_terms = drupal_explode_tags($val);
          if (!is_array($split_terms)) {
            $split_terms = array($split_terms);
          }
          foreach($split_terms as $piece) {
            if (is_numeric($piece) && $piece > 0) {           
               //make sure this tid works
               $tid_exists = db_result(db_query("SELECT count(*) FROM {term_data} t WHERE t.tid = %d", $piece));
               if ($tid_exists) {
                 $terms[] = $piece;
               }
            } 
            else if (is_numeric(str_replace('+', '', str_replace(' ', '', $piece)))) { // allow joint conditions
              $terms[] = $piece;              
            }
            else {
              $db_terms = taxonomy_get_term_by_name($piece);
              if (is_array($db_terms)) {
                foreach ($db_terms as $db_term) {
                  if ($db_term->vid == $vid || $vid='any') {
                    $terms[] = $db_term->tid;
                  }
                 }
              }
            }
          }
        }
      }
    }
  }

  return $terms;
}