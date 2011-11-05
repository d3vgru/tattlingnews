<?php

/**
 * Return a default list of feeds search for mentions.
 *  - %s will be replaced by search keywords
 *  - %# stands for space-trimmed string. Delicious does not allow whitespace in keywords:
 */
function buzz_get_search_feeds() {

  $buzz_feeds = array();
  $buzz_feeds['news'] = array(
    'Ask/Bloglines' => 'http://www.bloglines.com/search?q="%s"&format=rss',
    'Google Blog Search' => 'http://blogsearch.google.com/blogsearch_feeds?q="%s"&ie=utf-8&num=10&output=rss',
    'Google News Search' => 'http://news.google.com/news?hl=en&ned=us&ie=UTF-8&q="%s"&nolr=1&output=rss',
    'OneRiot' => 'http://www.oneriot.com/rss/serp?q="%s"',
    'NewsTree' => 'http://newstree.org/opensearch?query="%s"&hs=0&hp=10',
    'WordPress' => 'http://en.search.wordpress.com/?q="%s"&s=date&f=feed',    
    'IceRocket' => 'http://blogs.icerocket.com/search?q="%s"&rss=1',
    'Technorati' => 'http://feeds.technorati.com/search/"%s"',
    'Topix' => 'http://www.topix.com/search/article?blogs=1&dedup=1&xml=1&q="%s"',
    'Delicious' => 'http://delicious.com/tag/%#', 
    'BlogPulse' => 'http://www.blogpulse.com/rss?query="%s"',
  ); 
  $buzz_feeds['tweets'] = array (
    'Twitter' => 'http://search.twitter.com/search.atom?q="%s"',
    'Twitter Hashtag/User' => 'http://search.twitter.com/search.atom?q=+%#',    
  );
  $buzz_feeds['video']= array(
    'Truveo' => 'http://xml.truveo.com/rss?query="%s" sort:mostRecent',
    'Youtube - Text' => 'http://gdata.youtube.com/feeds/base/videos?q="%s"&client=ytapi-youtube-search&v=2',
    'Youtube - Tags' => 'http://gdata.youtube.com/feeds/base/videos/-/%#?client=ytapi-youtube-browse&v=2',
    'Google Video' => 'http://video.google.com/videosearch?q="%s"&output=rss',
    'Blip TV' => 'http://blip.tv/?y=0;search="%s";page=1;x=0;s=search&skin=rss',
    'Daily Motion' => 'http://www.dailymotion.com/rss/relevance/search/"%s"/1'
  );
  $buzz_feeds['photo'] = array(
    'Flickr' => 'http://api.flickr.com/services/feeds/photos_public.gne?tags="%s"&format=rss_200',
  );
  
  return $buzz_feeds;
}

function buzz_get_search_feed_type($feed_key) {
  static $map;
  
  if (empty($map)) {
    $feeds = buzz_get_search_feeds();
    foreach ($feeds as $type => $typed_feeds) {
      foreach ($typed_feeds as $id => $feedino) {
        $map[$id] = $type;
      }
    }
  }
  
  return ($map[$feed_key]);
}