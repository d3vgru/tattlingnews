<?php
/*
[nid] => 21529
[node_title] => Commonwealth, World Bank to help indebted nations
[node_revisions_teaser] => Uganda has been named as one of the beneficiaries of the World Bank’s ‘Debt Management Facility’ geared towards helping indebted Commonwealth 
[node_revisions_format] => 0
[node_revisions_body] => Uganda has been named as one of the beneficiaries of the World Bank’s ‘Debt Management Facility’ geared towards helping indebted Commonwealth 
[node_type] => mention
[node_vid] => 21529
[node_node_data_field_source_title] => Monitor Online | Truth Every Day; Uganda news, business, sports, opinion, travel daily
[node_node_data_field_source_nid] => 9424
[node_data_field_url_field_url_value] => http://www.monitor.co.ug
[node_node_data_field_source_type] => source
[node_node_data_field_source_vid] => 9424
[node_data_field_url_field_combined_rank_value] => 0.973768
[node_data_field_url_field_alexa_data_url_value] => monitor.co.ug/
[node_data_field_url_field_favicon_url_value] => 
[feedapi_node_item_url] => http://www.monitor.co.ug/artman/publish/business/Commonwealth_World_Bank_to_help_indebted_nations_86670.shtml
[feedapi_node_item_timestamp] => 1245406200
[votingapi_cache_node_points_vote_sum_value] => 
[node_created] => 1245406200
[node_data_field_url_field_technorati_authority_value] => 0
[node_data_field_combined_rank_field_combined_rank_value] => 0.973768
[node_created_day] => 20090619
[view_name] => mention:page_1
*/

function mentions_rss_safe_str($t) {
  $t = check_plain($t);
  return $t;
//  return "<![CDATA[$t]>";
}

$dbrows = $view->result;

$items = '';

foreach ($dbrows as $row) {

  $title = mentions_rss_safe_str($row->node_title);
  $link = url('node/' . $row->nid, array('absolute'=>TRUE));
  $description = mentions_rss_safe_str($row->node_revisions_teaser);  

  // Additional tags
  $obj = new stdClass();
  $obj->guid = url('node/' . $row->nid, array('absolute'=>TRUE));  
    
  $post_date = $row->feedapi_node_item_timestamp;
  if (empty($post_date))  { //Not all RSSes provide this
    $post_date = $row->node_created;
  }
  if ($_REQUEST['filter'] != 'mostvotes') {
    $datefieldname = "pubDate";
  }
  else {
    $datefieldname = "ttlr:publishDate";
  }
    
  $arrobj=(array)$obj;
  
  $arrobj[$datefieldname] = date('D, d M Y H:i:s O', $post_date);
  
  $arrobj['ttlr:votes'] = $row->votingapi_cache_node_points_vote_sum_value;
  $arrobj['ttlr:technorati_authority'] = $row->node_data_field_url_field_technorati_authority_value;  
  $arrobj['ttlr:source_profile'] = url('node/' . $row->node_node_data_field_source_nid, array('absolute'=>TRUE));
  $arrobj['ttlr:orig_url'] = $row->feedapi_node_item_url;

  $source_title = $row->node_node_data_field_source_title;
  if (empty($source_title)) { //Use URL instead
    $source_title = $row->node_node_data_field_source_node_data_field_url_field_url_value;
  }
  $source_title = mentions_rss_safe_str($source_title);

  $arrobj[] = array(
    'key' => 'source',
    'value' => $source_title,    
    'attributes' => array(
     'url'=>url($row->node_node_data_field_source_node_data_field_url_field_url_value, array('absolute'=>TRUE)),
    ),
  );

  $items .= format_rss_item($title, $link, $description, $arrobj);

}

  drupal_set_header('Content-Type: application/rss+xml; charset=utf-8');

  $site_name = variable_get('site_name', 'Tattler Feed');
  $url = url('rss/mentions');
  $description = 'Mentions feed generated from a Tattler instance';

  $output = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
  $output .= "<rss xmlns:ttlr=\"http://tattlerapp.com/rss/tattler/\" version=\"2.0\">\n";
  $output .= format_rss_channel(t('@site_name Feed', array('@site_name' => $site_name)), 
                                $url, $description, $items, $langcode);
  $output .= "</rss>\n";

print $output;
module_invoke_all('exit'); //e.g. let tokenauth clear the session.

exit();