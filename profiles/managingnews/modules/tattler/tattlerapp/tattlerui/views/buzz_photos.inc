<?php 

$view = new view;
$view->name = 'buzz_photos';
$view->description = 'Buzz Photos';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('relationships', array(
  'flag_content_rel' => array(
    'label' => 'boorkmarks',
    'required' => 0,
    'flag' => 'bookmark',
    'user_scope' => 'any',
    'id' => 'flag_content_rel',
    'table' => 'node',
    'field' => 'flag_content_rel',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'field_source_nid' => array(
    'label' => 'Source',
    'required' => 1,
    'delta' => -1,
    'id' => 'field_source_nid',
    'table' => 'node_data_field_source',
    'field' => 'field_source_nid',
    'relationship' => 'none',
  ),
));
$handler->override_option('fields', array(
  'field_images_m_value' => array(
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
      'group' => 0,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_images_m_value',
    'table' => 'node_data_field_images_m',
    'field' => 'field_images_m_value',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'url' => array(
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
    'display_url' => 'url',
    'exclude' => 0,
    'id' => 'url',
    'table' => 'feedapi_node_item',
    'field' => 'url',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'field_last_decorated_m_value' => array(
    'order' => 'DESC',
    'delta' => -1,
    'id' => 'field_last_decorated_m_value',
    'table' => 'node_data_field_last_decorated_m',
    'field' => 'field_last_decorated_m_value',
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
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'field_images_m_value' => array(
    'operator' => 'not empty',
    'value' => '',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'case' => 0,
    'id' => 'field_images_m_value',
    'table' => 'node_data_field_images_m',
    'field' => 'field_images_m_value',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'role',
  'role' => array(
    '2' => 2,
  ),
));
$handler->override_option('items_per_page', 12);
$handler->override_option('style_plugin', 'list');
$handler->override_option('style_options', array(
  'type' => 'ul',
));
$handler = $view->new_display('block', 'Photos Block', 'block_1');
$handler->override_option('block_description', '');
$handler->override_option('block_caching', -1);
