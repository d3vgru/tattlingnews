<?php
$content['type']  = array (
  'name' => 'Feed',
  'type' => 'feed',
  'description' => 'Items from these feeds will be turned into nodes.',
  'title_label' => 'Title',
  'body_label' => 'Body',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => false,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => '0',
  'old_type' => 'feed',
  'orig_type' => 'feed',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'rdf_schema_class' => '',
  'comment' => '2',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
  'feedapi' => 
  array (
    'enabled' => 1,
    'upload_method' => 'url',
    'feedapi' => 
    array (
      'itemfilter' => 
      array (
        'feedapi_dedupe' => 
        array (
          'enabled' => 1,
          'weight' => '-15',
        ),
      ),
    ),
    'refresh_on_create' => 0,
    'update_existing' => 0,
    'refresh_time' => '900',
    'items_delete' => '0',
    'parsers' => 
    array (
      'parser_common_syndication' => 
      array (
        'enabled' => 1,
        'weight' => '0',
        'accept_invalid_cert' => 1,
      ),
    ),
    'processors' => 
    array (
      'feedapi_source' => 
      array (
        'enabled' => 1,
        'weight' => '7',
        'extract_source' => 1,
      ),
      'feedapi_node' => 
      array (
        'enabled' => 1,
        'weight' => '0',
        'content_type' => 'mention',
        'input_format' => '1',
        'node_date' => 'feed',
        'x_dedupe' => '1',
      ),
      'feedapi_inherit' => 
      array (
        'enabled' => 1,
        'weight' => '3',
        'inherit_taxonomy' => 1,
        'inherit_author' => 1,
      ),
    ),
  ),
);
