<?php

/**
* Implementation for Twitter
**/
class RetrieverTwitter implements ISourceRetriever {
  
  var $url;
  
  function retrieve() {
    $url = $this->url;
    $parsed = parse_url($url);
    
    $path = preg_replace('#(/.+?)/status.*?/.+#im', '\1', $parsed['path']);
    if (strlen($path)==strlen($parsed['path'])) {
      $path = ''; //nothing was matched.
    }
    
    $scheme = $parsed['scheme'] . "://";
    $domain = $parsed['host'];
    $base_url = $scheme . $domain . $path;

    return $base_url;
  }
  
}