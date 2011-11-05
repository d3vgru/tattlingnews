<?php

class FaviconDataProvider implements FeedSourceDataProvider {

  public $url;
  public $icon_url;
  
  private $source;
  private $BATCH_SIZE = 5;
  
  // Source node field names
  private $FIELD_FAVICON_URL = 'field_favicon_url';
  
  public function retrieveData() {
  
    $img_url = NULL;
    $headers = array(); 
        
    //Twitter user icons:
    $parsed_url = @parse_url($this->url);
    if (empty($parsed_url)) return;      
    $domain = $parsed_url['host'];
    
    if (strpos($domain,'twitter.com') !== FALSE) { //twitter URL. Huraah
      $username = str_replace('http://twitter.com/', '', $this->url);
      $info_url = 'http://twitter.com/users/show/' . $username . '.json';
      $ret = drupal_http_request($info_url, $headers, 'GET');
      $obj = json_decode($ret->data);
      if (!empty($obj->profile_image_url)) {
        $img_url = $obj->profile_image_url;
        return $img_url;
      }
    }

    //End Twitter user icons.
    
    $url = $this->url . '/favicon.ico';
    $result = drupal_http_request($url, $headers, 'HEAD');
    
    if ($result->code == '200') { // favicon.ico found in the root. IE approach
      $img_url = $url;
      return $img_url;
    }
    
    $url = $this->url;
    $result = drupal_http_request($url, $headers, 'GET');
    
    // <link rel="icon" type="image/png" href="/path/image.png"/>.
    // <link rel="shortcut icon" href="http://www.blogsmithmedia.com/www.engadget.com/media/favicon-v2.ico" />

    if ($result->code > 399 ) {
      error_log ( 'FeedAPI Source WARNING: Error returned while trying to look up favicon for: ' .
                  $this->url . ' Err Message: ' . $result->error );
      return FALSE;
    }
    
    $subject  = $result->data;
        
    $pattern1 = '#<link.*?rel.*?=.*?"(shortcut.*?)?icon".*?href="(.*?)".*?/>#ims';
    $res = preg_match($pattern1, $subject, $matches);
        
    if ($res === FALSE) { // try another sequence
      $pattern2 = '#<link.*?href="(.*?)".*?rel.*?=.*?"(shortcut\w*?)?icon".*?/>#ims';
      $res = preg_match($pattern2, $subject, $matches);
    } 
    else  {
      $img_url = $matches[1];
    }

    if ($res === FALSE) {
      return FALSE;
    } 
    else {
      $img_url = $matches[2];
    }
    
    $img_url = trim($img_url);
    
            
    if (strpos($img_url, 'https?://') === FALSE && 
        (strpos(trim($img_url), '/')) === 0) {
      $parsed = parse_url($this->url);
      if ($parsed === FALSE) return;
      $port = '';
      if ($parsed['port'] !=80 && !empty($parsed['port']) )  {
        $port = ':' . $parsed['port'];
      }
      $domain = $parsed['scheme'] . '//' . $parsed['host'] . $port;
      $img_url = $domain . $img_url;
      
    }
    
    return $img_url;
  }
    
  public function attachData(&$source_node) {

    $this->source = $source_node;
    
    $this->url = $source_node->{SOURCE_URL_FIELD}[0]['value'];
    $this->icon_url = $this->retrieveData();

    //dpm($this->url . '   ' . $this->icon_url);
    
    if(!empty($this->icon_url)) {
      $this->setSourceFields();
    }
      
    return true;
  }

  public function setSourceFields() {
  
    if (empty($this->icon_url)) return;
    
    $this->source->{$this->FIELD_FAVICON_URL}[0]['value'] = $this->icon_url;
  }
  
  function cron() {
     
      $limit = $this->BATCH_SIZE;
      $url_field_name = SOURCE_URL_FIELD;
      
      $query = db_query_range("
          SELECT n.nid, {$url_field_name}_value as $url_field_name
          FROM {content_type_source} c
          JOIN {node} n ON n.nid=c.nid AND n.vid=c.vid
          WHERE {$this->FIELD_FAVICON_URL}_value IS NULL
          ORDER BY n.changed asc"
          
          , 0, $limit);
      
        while ($source_nid_obj = db_fetch_object($query)) {
           // Not so generic but FAST code (performance was MUCH more important here).          
           $src_node = new stdClass();
           $src_node->{SOURCE_URL_FIELD}[0]['value'] = $source_nid_obj->{SOURCE_URL_FIELD};                      
           
           $impl = new FaviconDataProvider();
           
           $impl->attachData($src_node);
          
          if (!empty($impl->icon_url)) {
            @db_query("
              UPDATE {content_type_source} 
              SET {$this->FIELD_FAVICON_URL}_value='%s'
              WHERE nid =  %d            
            ", $impl->icon_url, $source_nid_obj->nid);
          }
          else {
            @db_query("
              UPDATE {node} 
              SET changed='%s'
              WHERE nid =  %d            
            ", time(), $source_nid_obj->nid);
          }
          
        }
  }

}
