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
class ExtractorHttpredirects implements ISourceExtractor {
  
  var $url;
   
  function getWeight() {
    return -200;
  }
  
  function extract() {
    
    $more_redirects = TRUE;
    $curr_url = $this->url;
    $i = 0;
    

    //-- Unfortunately some misbehaved servers (e.g. xml.truveo.com) do not return 301 on redirect, so we have to look in the body to look for META redirect tags, hence we can not use HTTP HEAD. However, to compensate this waste of resources/performance, we use modified version of drupal_http_request that does NOT load entire pages :)
    $method = 'GET';    
    
    do {    
      $ret = feedapi_source_http_request(
        $curr_url, 
        array(), //headers
        $method,  
        NULL,    //data
        3       //maximum of 3 redirects please.
      );
      
      $matched = FALSE; $matches = array(); $redirect_url = '';
      $pattern = '#<meta\s+?http-equiv.*?=.*?Refresh.+?content=.+?url.*?=\s*(.*?)[\'";\s]#ims';
      $matched = preg_match($pattern, $ret->data, $matches);
      
      if ($matched && sizeof($matches)>1 && !empty($matches[1])) {
        $redirect_url = $matches[1];
      }
      else {
        if (!empty($ret->redirect_url)) {
          $redirect_url = $ret->redirect_url;
        }
      }
      
      if (empty($redirect_url)) {
        $more_redirects = FALSE;
      }
      else {
        $curr_url = $redirect_url;
      }
      $i++;
      if ($i > 5) $more_redirects = FALSE; //Do not redirect more than 5 times, no matter what.
      
    } while ($more_redirects);
    
    return $curr_url;
  }
  
}