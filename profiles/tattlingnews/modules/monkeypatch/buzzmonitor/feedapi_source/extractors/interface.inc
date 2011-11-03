<?php

interface ISourceExtractor {

  /* This should really be static, but due to a shortcoming in PHP < 5.3 we can't do that */
  public function getWeight();
  
  public function extract();
  
  

}