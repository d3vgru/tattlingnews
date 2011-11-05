<?php

/**
* Mentions are often brought to BuzzMonitor by search feeds, not the original feeds
* of the blogs that mentions belong to. For correct profiling we have to deduce the
* original feed.
**/
class MentionSourceExtractor {

  var $url;
  var $title;
    
  /**
  * Default constructor
  *
  * @param $op
  *     "get_destination" - remove the redirection URL prefix
  *     "get_properties" - Get Feed Properties if the init URL is already a feed URL (for unit-testing only).  
  *     "get_original_url" - extract the original URL of the mention,obscured by Digg and alikes
  *     "get_source_url" - retrieve the URL of the feed that is the original source of a mention  
  */  
  function MentionSourceExtractor( $url, $op = null ) {
    
    $this->url = trim($url);
    
    switch ($op)  {
      case "get_properties": //retrieve feed properties (title) assuming URL is a feed URL
      case "get_site_title": //retrieve site title assuming URL is a website URL
        //-- no action
        break;
      
      case "get_original_url": //extract the original URL of the mention,obscured by Digg and alikes
        $this->url = $this->getOriginalURL();
        break;

      case "get_source_url": //retrieve the URL of the feed that is the original source of a mention
        $this->url = $this->getOriginalURL();
        $this->url = $this->getSourceURL();
        // Setting proper title takes a lot of time due to network connection
        // We set URL as title here for speed and update to more proper title
        // on Cron (in data_providers/sitetitle.inc).
        $this->title = $this->url;
        //$this->title = $this->getSiteTitle();
        //...
        break;
    }
  }

  function getURL() {
    return $this->url;
  }

  function getTitle() {
    return $this->title;
  }

  /**
  * Extract original URL from obfuscated URLs using different extractors
  */
  function getOriginalURL() {
    
      $extractors = array();
      
      require_once (dirname(__FILE__) . '/extractors/interface.inc' );

      $pathes = glob(dirname(__FILE__) . "/extractors/*.inc");
      if (is_array($pathes)) {
        foreach ($pathes as $path) {
          $filename = pathinfo($path, PATHINFO_FILENAME);
          if ($filename != 'interface') {
            $obj = new stdClass();
            $obj->key = $filename;
            $obj->implClass = 'Extractor' . ucfirst($filename);
            $obj->fullPath = $path;
            require_once ($obj->fullPath);            
              // Due to a shortcoming in PHP < 5.3 this can not be static :(
              $extractor_object = new $obj->implClass;
              $extractor_object->name = $obj->key;
            $weight = $extractor_object->getWeight();
            $extractors[$weight] = $extractor_object;
          }
        }
      }  
      
      ksort($extractors); //Sort by weight
      
      foreach ($extractors as $extractor) {
        $extractor->url = $this->url;
        //$start = microtime();
        $url2 =  $extractor->extract();
        //$elapsed = microtime() - $start;
        //dpm ( $extractor->name . ' took ' . $elapsed . 'ms');
        if (!empty($url2)) {
          $this->url = $url2;          
        }
      }
      
      return $this->url;
    
  }  
 
 
  function getSourceURL() {
    $retr = $this->retrieverFactory();
    $retr->url = $this->url;
    $source_url = $retr->retrieve();
    return $source_url;
  }  
  
  /**
  * A Factory Method that returns appropriate extractor
  * implementation depending on the domain of the feed.
  */
  function retrieverFactory() {
    $mpath = drupal_get_path('module', 'feedapi_source');
    $epath = $mpath . "/retrievers";
    
    require_once ($epath . '/interface.inc');
    
    $parsed_url = parse_url($this->url);
    $domain = $parsed_url['host'];
    $domain = str_replace( 'www.', '', $domain ); //canonize URLs
    
    switch ($domain) {
      case 'twitter.com':
        require_once($epath . "/twitter.inc");
        $retr = new RetrieverTwitter();
        break;      
      default:
        require_once($epath . "/default.inc");
        $retr = new RetrieverDefault();
    }
    
    return $retr;
  }
     
  function getSiteTitle($html=NULL) {
        
    if (empty($html)) {      
      $req = feedapi_source_http_request($this->url);  //performance-optimized
      //$html = $this->getURLContents($this->url);
      $html = $req->data;
    }
    
    $pattern = '/<title>(.+?)<\/title>/ims';
    if (preg_match($pattern,$html,$matches) && $matches[1]) {
      $title = trim($matches[1]);
      $title = preg_replace('/\s+/ims', ' ', $title);
    } 
    else {
      $title = "";
    }
    
    if (strpos($title, 'Error') !== FALSE  ||
        strpos($title, '404') !== FALSE) { // connection errors not caught by CURL. sigh.
      $title = '';
    }
    return $title;
  }   
  
  function getFeedProperties() {
    
    $headers = array();
    $url_parts = parse_url($this->url);
    $password = $username = NULL;
    if (!empty($url_parts['user'])) {
      $password = $url_parts['pass'];
      $username = $url_parts['user'];
    }

    if (!empty($username)) {
      $headers['Authorization'] = 'Basic '. base64_encode("$username:$password");
    }
    
    $ret = drupal_http_request($this->url, $headers);
    if ( $ret->code < 200 || $ret->code > 399)  {
      return false;
    }
   
    if (!defined('LIBXML_VERSION') || (version_compare(phpversion(), '5.1.0', '<'))) {
      @ $xml = simplexml_load_string($ret->data, NULL);
    }
    else {
      @ $xml = simplexml_load_string($ret->data, NULL, LIBXML_NOERROR | LIBXML_NOWARNING);
    }

    if (_parser_common_syndication_feed_format_detect($xml) != FALSE) {
      $parsed_feed = _parser_common_syndication_feedapi_parse($xml);
    } else { return false; }
  
    $properties = new StdClass();
    $properties->title = $parsed_feed->title;
    $properties->link = $parsed_feed->options->link;    
    
    return $properties;
  }
  
  
  public function getStrippedTitle()
  {
    $text = strtolower($this->title);
   
    // strip all non word chars
    $text = preg_replace('/\W/', ' ', $text);
    // replace all white space sections with a dash
    $text = preg_replace('/\ +/', '-', $text);
    // trim dashes
    $text = preg_replace('/\-$/', '', $text);
    $text = preg_replace('/^\-/', '', $text);
   
    return $text;
  }
  
  /** This one uses CURL since drupal_http_request has no clue of timeouts :( **/
  public function getURLContents($url) {
  
    if (!function_exists('curl_init')) return ''; //CURL is an optional lib. Sigh.
    
    // create curl resource 
    $ch = curl_init(); 

    // set url 
    curl_setopt($ch, CURLOPT_URL, $url); 

    //return the transfer as a string 
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);    
    curl_setopt($ch, CURLOPT_MAXREDIR, 1);                 
    curl_setopt($ch, CURLOPT_TIMEOUT, 7);             
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 2);         
    


    // $output contains the output string 
    $out = curl_exec($ch); 

    // close curl resource to free up system resources 
    curl_close($ch);      

    if ($out === FALSE) {
      $out ='';
    }
    
    return $out;
  }


}
