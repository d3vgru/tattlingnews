<?php

class CompeteDataProvider implements FeedSourceDataProvider {
  private $API_URI = 'http://api.compete.com/fast-cgi/MI/';

  private $source;
  private $apiKey;
  private $url;
  public $results;

  /* 
  * Attention: these fields are transient and there're no such
  * persistent fields (i.e. with CCK)! Compete.com does NOT
  * allow storing their data. We have to respect this requirement
  * of their license agreement.
  */
  public $field_compete_rank = 'field_compete_rank';
  public $field_compete_traffic = 'field_compete_traffic';
  


  public function setUrl($url) {
    $this->url = $url;
  }

  public function retrieveData() {
    $headers = array(); //array('Content-Type' => 'application/x-www-form-urlencoded');
    $api_url = $this->API_URI;
    $api_query = $this->getQueryString();
    $result = drupal_http_request($api_url . '?' . $api_query, $headers, 'GET');
    
    if ($result->code != '200') {
      error_log ( 'FeedAPI Source WARNING: Error returned while trying to look up compete.com ranking for: ' .
                  $this->url . ' Err Message: ' . $result->error );
      return FALSE;
    }

    $this->parseResults($result->data);
  }
  
  private function getQueryString() {
    $params = array();
    $params['apikey'] = $this->apiKey;
    $params['d'] = $this->url;
    $params['ver'] = 3;
    $params['size'] = small;
    return http_build_query($params, '', '&');
  }

  public function attachData(&$source_node) {
    // Disabled since Compete does not allow storing data locally :(
    // fetchData() is used instead.
    return;
  }

  public function fetchData(&$source_node) {

    $api_key = variable_get('feedapi_source_compete_api_key', '');
    if ($api_key == '')
      return false;
  
    $this->apiKey  = $api_key;
    $this->source = $source_node;
    $this->url = $source_node->{SOURCE_URL_FIELD}[0]['value'];
    
    //Defaults
    $this->source->{$this->field_compete_rank} = array(0 => array('value' => MAX_COMPETE_RANK));
    $this->source->{$this->field_compete_traffic} = array(0 => array('value' => 0));    

    $this->retrieveData();
    $this->setSourceFields();
      
    return true;
  }

  private function parseResults($results) {
    $obj_xml = simplexml_load_string($results);
    $this->results = $obj_xml->dmn->metrics->val->uv;
  }

  public function setSourceFields() {
    $result = $this->results;

    if (!empty($this->results)) {
      $this->source->{$this->field_compete_rank}[0]['value'] = (int)$result->ranking;
        $count = str_replace(',', '', (string)$result->count);
        $count = (int)$count;
      $this->source->{$this->field_compete_traffic}[0]['value'] = $count;
    }

  }

}

?>
