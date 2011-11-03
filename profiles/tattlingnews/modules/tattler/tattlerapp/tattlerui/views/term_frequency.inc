<?php

$view = new view;
$view->name = 'term_frequency';
$view->description = 'Term Frequency';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'flag_content_rel' => array(
    'label' => 'bookmark',
    'required' => 0,
    'flag' => 'bookmark',
    'user_scope' => 'any',
    'id' => 'flag_content_rel',
    'table' => 'node',
    'field' => 'flag_content_rel',
    'relationship' => 'none',
  ),
  'field_source_nid' => array(
    'label' => 'Source',
    'required' => 0,
    'delta' => -1,
    'id' => 'field_source_nid',
    'table' => 'node_data_field_source',
    'field' => 'field_source_nid',
    'relationship' => 'none',
  ),
));
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid Count',
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
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'name' => array(
    'label' => 'Term',
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
    'link_to_taxonomy' => 1,
    'exclude' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'name_1' => array(
    'label' => 'Vocabulary name',
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
    'exclude' => 0,
    'id' => 'name_1',
    'table' => 'vocabulary',
    'field' => 'name',
    'relationship' => 'none',
  ),
  'views_sql_groupedfields' => array(
    'label' => 'Group By Fields',
    'alter' => array(
      'alter_text' => FALSE,
      'text' => '',
      'make_link' => FALSE,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'trim' => FALSE,
      'max_length' => '',
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'html' => FALSE,
    ),
    'exclude' => '1',
    'id' => 'views_sql_groupedfields',
    'table' => 'views_groupby',
    'field' => 'views_sql_groupedfields',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
    'views_groupby_fields_to_group' => array(
      'name' => 'name',
      'name_1' => 'name_1',
    ),
    'views_groupby_sql_function' => 'count',
    'views_groupby_fields_to_aggregate' => array(
      'nid' => 'nid',
    ),
    'views_groupby_field_sortby' => 'nid',
    'views_groupby_sortby_direction' => 'desc',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'mention' => 'mention',
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
$handler->override_option('style_plugin', 'list');
$handler->override_option('style_options', array(
  'grouping' => '',
  'type' => 'ul',
));
$handler = $view->new_display('page', 'Tag Cloud', 'page_1');
$handler->override_option('items_per_page', 150);
$handler->override_option('use_pager', '1');
$handler->override_option('path', 'buzzcloud');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));
$handler = $view->new_display('block', 'Top Tags Block', 'block_1');
$handler->override_option('items_per_page', 50);
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
