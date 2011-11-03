<?php

/**
* Default, trivial Implementation
**/
class RetrieverDefault implements ISourceRetriever {
  
  var $url;
  
  function retrieve() {
    $url = $this->url;
    $parsed = parse_url($url);
    $path = $parsed['path'];
    
    $scheme = $parsed['scheme'] . "://";
    $domain = $parsed['host'];
    $base_url = $scheme . $domain;
    
    return $base_url;
  }
  
}

