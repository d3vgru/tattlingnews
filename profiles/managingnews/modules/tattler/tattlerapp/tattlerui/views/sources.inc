<?php

/*
 * View 'sources'
 */
$view = new view;
$view->name = 'sources';
$view->description = 'Sources';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'flag_content_rel' => array(
    'label' => 'Watchlist',
    'required' => 0,
    'flag' => 'watchlist',
    'user_scope' => 'any',
    'id' => 'flag_content_rel',
    'table' => 'node',
    'field' => 'flag_content_rel',
    'relationship' => 'none',
  ),
  'flag_content_rel_1' => array(
    'label' => 'Blacklist',
    'required' => 0,
    'flag' => 'blacklist',
    'user_scope' => 'any',
    'id' => 'flag_content_rel_1',
    'table' => 'node',
    'field' => 'flag_content_rel',
    'relationship' => 'none',
  ),
));
$handler->override_option('fields', array(
  'title' => array(
    'label' => 'Title',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
  'field_url_value' => array(
    'label' => 'URL',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_url_value',
    'table' => 'node_data_field_url',
    'field' => 'field_url_value',
    'relationship' => 'none',
  ),
  'field_favicon_url_value' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_favicon_url_value',
    'table' => 'node_data_field_favicon_url',
    'field' => 'field_favicon_url_value',
    'relationship' => 'none',
  ),
  'field_topic_nid' => array(
    'label' => 'Topic',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_topic_nid',
    'table' => 'node_data_field_topic',
    'field' => 'field_topic_nid',
    'relationship' => 'none',
  ),
  'field_combined_rank_value' => array(
    'label' => 'Combined Rank',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_combined_rank_value',
    'table' => 'node_data_field_combined_rank',
    'field' => 'field_combined_rank_value',
    'relationship' => 'none',
  ),
  'field_technorati_rank_value' => array(
    'label' => 'Technorati Rank',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_technorati_rank_value',
    'table' => 'node_data_field_technorati_rank',
    'field' => 'field_technorati_rank_value',
    'relationship' => 'none',
  ),
  'created' => array(
    'label' => 'Post date',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'date_format' => 'small',
    'custom_date_format' => '',
    'exclude' => 0,
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'field_mention_count_value' => array(
    'label' => 'Buzz #',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'widget',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_mention_count_value',
    'table' => 'node_data_field_mention_count',
    'field' => 'field_mention_count_value',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'title' => array(
    'order' => 'ASC',
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'source' => 'source',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'role',
  'role' => array(
    '2' => 2,
  ),
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('items_per_page', 20);
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'list');
$handler->override_option('style_options', array(
  'grouping' => '',
  'type' => 'ul',
));
$handler = $view->new_display('block', 'Main Sources Listing', 'block_1');
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('block', 'Top Sources Block', 'block_2');
$handler->override_option('sorts', array(
  'field_mention_count_value' => array(
    'order' => 'DESC',
    'delta' => -1,
    'id' => 'field_mention_count_value',
    'table' => 'node_data_field_mention_count',
    'field' => 'field_mention_count_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'status' => array(
    'operator' => '=',
    'value' => '1',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'source' => 'source',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
  'flagged' => array(
    'operator' => '=',
    'value' => '0',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'flagged',
    'table' => 'flag_content',
    'field' => 'flagged',
    'relationship' => 'flag_content_rel_1',
    'override' => array(
      'button' => 'Use default',
    ),
  ),
));
$handler->override_option('items_per_page', 10);
$handler->override_option('use_pager', '0');
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);