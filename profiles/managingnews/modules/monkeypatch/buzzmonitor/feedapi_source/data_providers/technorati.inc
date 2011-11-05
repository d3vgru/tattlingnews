<?php

class TechnoratiDataProvider implements FeedSourceDataProvider {
  private $API_URI = 'http://api.technorati.com/';
  private $BATCH_SIZE = 10;

  private $source;
  private $apiKey;
  private $url;
  private $results;

  // Source node field names
  public $field_authority = 'field_technorati_authority';
  public $field_weblog_name = 'field_technorati_weblog_name';
  public $field_weblog_url = 'field_technorati_weblog_url';
  public $field_weblog_rssurl = 'field_technorati_weblog_rssurl';
  public $field_weblog_inboundlinks = 'field_technorati_weblog_inlinks';
  public $field_weblog_lastupdate = 'field_technorati_weblog_update';
  public $field_weblog_rank = 'field_technorati_rank';
  public $field_last_update = 'field_technorati_last_update';


  public function setUrl($url) {
    $this->url = $url;
  }

  public function retrieveData() {
    $headers = array('Content-Type' => 'application/x-www-form-urlencoded');
    $result = drupal_http_request($this->API_URI . 'cosmos', $headers, 'POST', $this->getQueryString());
    $this->parseResults($result->data);
  }

  public function attachData(&$source_node) {
    $TECHNORATI_EXPIRATION_SECONDS = 86400;
    $api_key = variable_get('feedapi_source_technorati_api_key', '');
    if ($api_key == '')
      return false;
  
    $last_update = $source_node->{TECHNORATI_LAST_UPDATE_FIELD}[0]['value'];
    $last_update_ts = strtotime($last_update);
    if ($last_update_ts !== FALSE && $last_update_ts > 0 && ($last_update_ts + $TECHNORATI_EXPIRATION_SECONDS > time()))
      return false;
  
    $this->apiKey  = $api_key;
    $this->source = $source_node;
    $this->url = $source_node->{SOURCE_URL_FIELD}[0]['value'];
    
    $this->retrieveData();
    $this->setSourceFields();
      
    return true;
  }

  public function getResults() {
    return $this->results;
  }

  private function getQueryString() {
    $params = array();
    $params['key'] = $this->apiKey;
    $params['url'] = $this->url;
    $params['type'] = 'weblog';
    $params['limit'] = 1;
    return http_build_query($params, '', '&');
  }

  private function parseResults($results) {
    $this->results = @simplexml_load_string($results);
  }

  public function setSourceFields() {
    $result = $this->results->document->result;
    $this->source->{$this->field_authority}[0]['value'] = (int)$result->weblog->inboundblogs;
    $this->source->{$this->field_weblog_name}[0]['value'] = (string)$result->weblog->name;
    $this->source->{$this->field_weblog_url}[0]['value'] = (string)$result->weblog->url;
    $this->source->{$this->field_weblog_rssurl}[0]['value'] = (string)$result->weblog->rssurl;
    $this->source->{$this->field_weblog_inboundlinks}[0]['value'] = (int)$result->weblog->inboundlinks;
    $this->source->{$this->field_weblog_lastupdate}[0]['value'] = (string)$result->weblog->lastupdate;
    $this->source->{$this->field_weblog_rank}[0]['value'] = $result->weblog->rank;
    $this->source->{$this->field_last_update}[0]['value'] = (string)date('Y-m-d H:i:s');
    
  }

  public function getKeyInfo() {
    $headers = array('Content-Type' => 'application/x-www-form-urlencoded');
    $result = drupal_http_request($this->API_URI . 'keyinfo', $headers, 'POST', 'key=' . $this->apiKey);
    $this->parseResults($result->data);
    $result = $this->results->document->result;
    return array('used' => (int)$result->apiqueries, 'max' => (int)$result->maxqueries);
  }
  
  public function fetchData(&$source_node) {

    $api_key = variable_get('feedapi_source_technorati_api_key', '');
    if ($api_key == '')
      return false;
  
    $this->apiKey  = $api_key;
    $this->source = $source_node;
    $this->url = $source_node->{SOURCE_URL_FIELD}[0]['value'];
    
    //Defaults {$this->field_authority}[0]['value']
    $this->source->{$this->field_authority}[0]['value'] = 0;

    $this->retrieveData();
    $this->setSourceFields();
      
    return true;
  }

  
}

?>
