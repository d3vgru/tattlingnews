<?php

$content['type']  = array (
  'name' => 'Source',
  'type' => 'source',
  'description' => 'Feed Item\'s Original Source',
  'title_label' => 'Title',
  'body_label' => 'Body',
  'min_word_count' => '0',
  'help' => '',
  'node_options' => 
  array (
    'status' => true,
    'promote' => true,
    'sticky' => false,
    'revision' => false,
  ),
  'language_content_type' => '0',
  'upload' => 1,
  'flag_watchlist_default' => 0,
  'flag_blacklist_default' => 0,
  'old_type' => 'source',
  'orig_type' => '',
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
    'enabled' => 0,
    'upload_method' => 'url',
    'refresh_on_create' => 0,
    'update_existing' => 1,
    'refresh_time' => 1800,
    'items_delete' => '0',
    'parsers' => 
    array (
      'parser_common_syndication' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'accept_invalid_cert' => false,
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
        'input_format' => 0,
        'node_date' => 'feed',
        'x_dedupe' => '0',
      ),
      'feedapi_inherit' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'inherit_taxonomy' => 1,
        'inherit_author' => true,
      ),
      'feedapi_dedupe' => 
      array (
        'enabled' => false,
        'weight' => 0,
        'extreme_dedupe' => true,
      ),
    ),
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'URL',
    'field_name' => 'field_url',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '-2',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_url][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 1,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      0 => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'FavIcon URL',
    'field_name' => 'field_favicon_url',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '-1',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_favicon_url][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_favicon_url' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_favicon_url][0][value',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  2 => 
  array (
    'label' => 'Combined Rank',
    'field_name' => 'field_combined_rank',
    'type' => 'number_float',
    'widget_type' => 'number',
    'change' => 'Change basic information',
    'weight' => 0,
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_combined_rank][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_combined_rank' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_combined_rank][0][value',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'min' => '',
    'max' => '',
    'prefix' => '',
    'suffix' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'number',
    'widget_module' => 'number',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'float',
        'not null' => false,
        'sortable' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      0 => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
    ),
  ),
  3 => 
  array (
    'label' => 'Alexa Rank',
    'field_name' => 'field_alexa_rank',
    'type' => 'number_integer',
    'widget_type' => 'number',
    'change' => 'Change basic information',
    'weight' => '1',
    'description' => '',
    'default_value' => 
    array (
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_alexa_rank' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_alexa_rank][0][value',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'min' => '',
    'max' => '',
    'prefix' => '',
    'suffix' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'number',
    'widget_module' => 'number',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'int',
        'not null' => false,
        'sortable' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      0 => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
    ),
  ),
  4 => 
  array (
    'label' => 'Alexa Data URL',
    'field_name' => 'field_alexa_data_url',
    'type' => 'text',
    'widget_type' => 'text_textfield',
    'change' => 'Change basic information',
    'weight' => '2',
    'rows' => 5,
    'size' => '60',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_alexa_data_url][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_alexa_data_url' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_alexa_data_url][0][value',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'text',
    'widget_module' => 'text',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'text',
        'size' => 'big',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      0 => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
    ),
  ),
  5 => 
  array (
    'label' => 'Buzz #',
    'field_name' => 'field_mention_count',
    'type' => 'number_integer',
    'widget_type' => 'number',
    'change' => 'Change basic information',
    'weight' => '12',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_mention_count][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_mention_count' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_mention_count][0][value',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'min' => '',
    'max' => '',
    'prefix' => '',
    'suffix' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'op' => 'Save field settings',
    'module' => 'number',
    'widget_module' => 'number',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'int',
        'not null' => false,
        'sortable' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      0 => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '-3',
  'menu' => '-4',
  'attachments' => '30',
);
