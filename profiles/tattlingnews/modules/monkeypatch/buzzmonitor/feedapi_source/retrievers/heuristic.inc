<?php

/**
* Heuristical Implementation
**/
class RetrieverHeuristic implements ISourceRetriever {
  
  var $url;
  
  function retrieve() {
    $url = $this->url;
    $path = parse_url($url, PHP_URL_PATH);
    
    $scheme = parse_url($url, PHP_URL_SCHEME) . "://";
    $domain = parse_url($url, PHP_URL_HOST);
    $base_url = $scheme . $domain;
    
    $arr_split = split('/', $path); 
    array_unshift( $arr_split, $domain);
    $arr_path = array();
    //Remove empty elements
    foreach ( $arr_split as $elem ) {
      if (!empty($elem)) {
        $arr_path[] = $elem;
      }
    }
    
    $source_url = $base_url;
    $testurl = $base_url;
    $blogfound = false;
    
    while ( sizeof ($arr_path) > 0 ) {
      array_pop($arr_path);
      $last_id = sizeof($arr_path) - 1;
      if ($last_id < 0) continue;
      if ( is_numeric($arr_path[$last_id]) ) continue; //ignore date parts of URL. Even if those have a feed, we do not want a date-specific feed.
      $testurl = $scheme . implode('/', $arr_path);
      
      //echo "<pre>Testing URL: ".print_r ( $testurl,true)."</pre>";
      
      $ret = drupal_http_request ($testurl);
      if ( $ret->code < 199 || $ret->code > 399 ) {
        continue;
      }
      $html = $ret->data;
      $pattern = '/<link.+?>/ims';      
      $linksfound = preg_match_all($pattern,$html,$matches);
      if ( $linksfound ) {
        if ( $matches && is_array($matches) && sizeof($matches)>0 ) {
          foreach ( $matches[0] as $m ) {
            $m2 = strtolower($m);
            $alternate = strpos($m2, 'alternate');
            $rss = strpos($m2, 'application/rss+xml');
            $atom = strpos($m2, 'application/atom+xm'); 
            $values = array(htmlentities($m), $alternate, $rss, $atom);
            if ( $alternate !==false && ( ($rss !==false) || ($atom !== false) ) ) {
              $source_url = $testurl;
              $blogfound = true;
              break;
            }
          }
        }
        if ($blogfound) break;
      }
    }
    
    return $source_url;
  }
}