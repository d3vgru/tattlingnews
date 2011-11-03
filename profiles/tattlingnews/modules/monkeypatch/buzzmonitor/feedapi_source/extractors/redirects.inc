<?php

/**
* Extracts the final destination URL for redirect URLs
*
* URLs from Search engines often come in the form of: 
* http://service.com?some=other&url=http://realurl.com/realpath
* we need to throw-away the redirector and get to the actual 
* destination URL.
* 
*/
class ExtractorRedirects implements ISourceExtractor {
  
  var $url;
  
  function getWeight() {
    return -100;
  }

    
  function extract() {
    
    // Determine if it is a redirect
    $pattern = '/.*(http.?:\/\/)(.*?)/is';
    $replacement = '$1$2';
    $url = preg_replace($pattern, $replacement, $this->url);
    
    // If the URL is the same length, there is not a redirect
    if(strlen($this->url) === strlen($url)) {
      return $this->url;
    }

    $querystring = parse_url($this->url, PHP_URL_QUERY);

    // Split on &, but not if the & is in an html entity. This is a better impl of parse_str().
    $args = preg_split('|&(?!.[a-z0-9]{1,6}+;)|ims', $querystring);
    if(!is_array($args)) {
      return $this->url;
    }

    // For each resultant query string arg, return if the value a valid URL
    foreach($args as $arg) {
      list($key, $val) = explode('=', $arg, 2);
      $val = urldecode($val);
      if(valid_url($val, TRUE)) {
        return $val;
      }
    }
    
    // All failed, use what we started with
    return $this->url;

  }

}