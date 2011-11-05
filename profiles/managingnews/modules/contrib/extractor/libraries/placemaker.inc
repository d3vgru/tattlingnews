<?php
// $Id: placemaker.inc,v 1.2 2010/08/10 20:54:34 diggersf Exp $

/**
 * Tags a single item.
 */
function placemaker_extract($text, $config) {
  $term = _placemaker_send_text($text, $config);
  $tags = array();
  if ($term) {
    $tags[$term['tid']] = $term;
  }
  return $tags;
}

/**
 * Sends items to Placemaker API.
 */
function _placemaker_send_text($text, $config) {
  // Make placemaker request.
  $apiendpoint = 'http://wherein.yahooapis.com/v1/document';
  $inputType = 'text/html';

  $outputType = 'xml';
  $post = 'appid='. $config['placemaker_key'] .'&documentContent='. $text .'&documentType='. $inputType .'&inputLanguage='. $config['language'] .'&outputType='. $outputType .'&autoDisambiguate=true';
  $ch = curl_init($apiendpoint);

  curl_setopt($ch, CURLOPT_POST, 1);
  curl_setopt($ch, CURLOPT_POSTFIELDS, $post);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  $results = curl_exec($ch);
  curl_close($ch);

  // Parse results of placemaker request.
  $xml = simplexml_load_string($results);
  $item['name'] = (string)$xml->document->placeDetails->place->name;
  $item['lat'] = (string)$xml->document->placeDetails->place->centroid->latitude;
  $item['lon'] = (string)$xml->document->placeDetails->place->centroid->longitude;

  return $item;
}
