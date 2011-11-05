<?php

class SitetitleDataProvider implements FeedSourceDataProvider {

  public $url;
  
  private $source;
  private $BATCH_SIZE = 5;
  
  
  public function retrieveData() {
  }
    
  public function attachData(&$source_node) {
  }
  
  function cron() {
     
      $limit = $this->BATCH_SIZE;
      $url_field_name = SOURCE_URL_FIELD;
      
      $query = db_query_range("
          SELECT n.nid, {$url_field_name}_value as $url_field_name
          FROM {content_type_source} c
          JOIN {node} n ON n.nid=c.nid AND n.vid=c.vid
          WHERE n.type = '%s' AND n.title like 'http%' 
          ORDER BY n.changed asc"
          
          , SOURCE_CONTENT_TYPE, 0, $limit);
      
        while ($source_nid_obj = db_fetch_object($query)) {
           $url = $source_nid_obj->{SOURCE_URL_FIELD};                      
           $extractor = new MentionSourceExtractor($url);
           $title = $extractor->getSiteTitle();

            $title = str_ireplace('http://', '', $title);
            $title = str_ireplace('https://', '', $title);            
           
          if (trim($title) != trim($url)) {
            db_query("
              UPDATE {node} 
              SET title='%s'
              WHERE nid =  %d            
            ", $title, $source_nid_obj->nid);
            
            db_query("
              UPDATE {node_revisions} 
              SET title='%s'
              WHERE nid =  %d            
            ", $title, $source_nid_obj->nid);
            
          }
          
        }
  }

}
