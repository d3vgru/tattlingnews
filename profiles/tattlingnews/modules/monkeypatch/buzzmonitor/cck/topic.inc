<?php

$content['type']  = array (
  'name' => 'Topic',
  'type' => 'topic',
  'description' => 'A topic from which to generate feeds.',
  'title_label' => 'Topic',
  'body_label' => '',
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
  'old_type' => 'topic',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'rdf_schema_class' => '',
  'comment' => '0',
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
    'enabled' => 0,
    'refresh_on_create' => 0,
    'update_existing' => 1,
    'skip' => 0,
    'items_delete' => '0',
    'parsers' => 
    array (
      'parser_common_syndication' => 
      array (
        'enabled' => 0,
        'weight' => '0',
      ),
    ),
    'processors' => 
    array (
      'feedapi_source' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'extract_source' => 1,
      ),
      'feedapi_node' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'content_type' => 'page',
        'node_date' => 'feed',
        'promote' => '3',
        'x_dedupe' => '0',
      ),
      'feedapi_inherit' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'inherit_taxonomy' => 1,
      ),
    ),
  ),
);
