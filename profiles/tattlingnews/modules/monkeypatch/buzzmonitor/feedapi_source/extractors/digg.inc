<?php

class ExtractorDigg implements ISourceExtractor {
  
  var $url;

  function getWeight() {
    return 100; //execute this extractor towards the end of the extractor queue.
  }
  
/*
    API DOMAIN: 
    
    
    BY TITLE:
    GET /story/{story clean title}
    http://apidoc.digg.com/ListStories#ExampleRequest
    
    BY URL:    
    GET /stories?link={url_encoded url}
    
    Or By md5 Hash of the URL:
    Get /stories?linkhash=
    http://apidoc.digg.com/ListStories#Arguments
*/
  
  function extract() {
  
    $parsed_url = parse_url($this->url);
    $domain = $parsed_url['host'];
    
    if (strpos($domain,'digg.com') === FALSE) return $this->url; //Don't do anything, not a Digg URL.
    
    $appkey = urlencode('http://drupal.org/project/buzzmonitor');
    
    // Examples: 
    // "http://digg.com/environment/Leaked_Report_Biofuels_Are_the_Cause_of_Global_Food_Crisis"
    // "http://feeds.digg.com/~r/digg/popular/~3/4DpDTazAbFU/Baffling_Safe_Sex_Poster_Found_in_Taiwan_PIC"
    $pattern = '/.*http.?:\/\/.*\/(.*)/is';
    $clean_title = preg_replace($pattern, '$1', $this->url);
    if( strlen($clean_title) == strlen($this->url) ) { //nothing matched
      return false;
    }
    
    $url = "http://services.digg.com/story/" . $clean_title;
    $url .= "?appkey=" . $appkey;
    
    $ret = drupal_http_request($url);
    
    if ( $ret->code != 200 ) return false;
    
    $xml = simplexml_load_string($ret->data, NULL);
    $link = (string)$xml->story->attributes()->link;
    return $link;

  }

}