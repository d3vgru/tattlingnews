<?php

/**
* This is a trivial implementation returning original URL
**/
class ExtractorDefault implements ISourceExtractor {
  
  var $url;
  
  function getWeight() {
    return 0;
  }
  
  /**
  * This is a trivial implementation returning original URL
  **/
  function extract() {
    return $this->url;
  }
  
}