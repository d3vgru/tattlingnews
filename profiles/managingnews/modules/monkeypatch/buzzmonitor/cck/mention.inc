<?php

$content['type']  = array (
  'name' => 'Mention',
  'type' => 'mention',
  'description' => 'A Blog Mention brought in by BuzzMonitor',
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
  'upload' => '1',
  'flag_bookmark_default' => 0,
  'old_type' => 'mention',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'rdf_schema_class' => '',
  'comment' => '2',
  'comment_default_mode' => '4',
  'comment_default_order' => '2',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '0',
  'comment_preview' => '0',
  'comment_form_location' => '0',
  'feedapi' => 
  array (
    'enabled' => 0,
    'upload_method' => 'url',
    'refresh_on_create' => 0,
    'update_existing' => 1,
    'refresh_time' => '1800',
    'items_delete' => '0',
    'parsers' => 
    array (
      'parser_common_syndication' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'accept_invalid_cert' => 0,
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
        'input_format' => '1',
        'node_date' => 'feed',
        'x_dedupe' => '0',
      ),
      'feedapi_inherit' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'inherit_taxonomy' => 1,
        'inherit_author' => 1,
      ),
      'feedapi_dedupe' => 
      array (
        'enabled' => 0,
        'weight' => '0',
        'extreme_dedupe' => 1,
      ),
    ),
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Images URLs',
    'field_name' => 'field_images_m',
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
        '_error_element' => 'default_value_widget][field_images_m][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 0,
    'multiple' => '1',
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
      'weight' => '-2',
      'parent' => '',
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
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Source',
    'field_name' => 'field_source',
    'type' => 'nodereference',
    'widget_type' => 'nodereference_select',
    'change' => 'Change basic information',
    'weight' => '-1',
    'autocomplete_match' => 'contains',
    'size' => 60,
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'nid' => '',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_source' => 
      array (
        0 => 
        array (
          'nid' => '',
        ),
        'nid' => 
        array (
          'nid' => '',
        ),
      ),
    ),
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'referenceable_types' => 
    array (
      'source' => 'source',
      'feed' => 0,
      'mention' => 0,
      'page' => 0,
      'topic' => 0,
      'book' => false,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'op' => 'Save field settings',
    'module' => 'nodereference',
    'widget_module' => 'nodereference',
    'columns' => 
    array (
      'nid' => 
      array (
        'type' => 'int',
        'unsigned' => true,
        'not null' => false,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'weight' => '-1',
      'parent' => '',
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
  2 => 
  array (
    'label' => 'Full Text',
    'field_name' => 'field_fulltext',
    'type' => 'text',
    'widget_type' => 'text_textarea',
    'change' => 'Change basic information',
    'weight' => 0,
    'rows' => '5',
    'size' => 60,
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => '',
        '_error_element' => 'default_value_widget][field_fulltext][0][value',
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => 
    array (
      'field_fulltext' => 
      array (
        0 => 
        array (
          'value' => '',
          '_error_element' => 'default_value_widget][field_fulltext][0][value',
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
      'weight' => 0,
      'parent' => '',
      'label' => 
      array (
        'format' => 'above',
      ),
      'teaser' => 
      array (
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'hidden',
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
    'label' => 'Last Decorated',
    'field_name' => 'field_last_decorated_m',
    'type' => 'datestamp',
    'widget_type' => 'date_text',
    'change' => 'Change basic information',
    'weight' => '1',
    'default_value' => 'blank',
    'default_value2' => 'blank',
    'default_value_code' => '',
    'default_value_code2' => '',
    'input_format' => 'Y/m/d - g:i:sa',
    'input_format_custom' => '',
    'advanced' => 
    array (
      'label_position' => 'within',
      'text_parts' => 
      array (
        'year' => 0,
        'month' => 0,
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'second' => 0,
      ),
    ),
    'increment' => 1,
    'year_range' => '-3:+3',
    'label_position' => 'within',
    'text_parts' => 
    array (
    ),
    'description' => '',
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'repeat' => 0,
    'todate' => '',
    'granularity' => 
    array (
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
      'second' => 'second',
    ),
    'default_format' => 'medium',
    'tz_handling' => 'site',
    'timezone_db' => 'UTC',
    'op' => 'Save field settings',
    'module' => 'date',
    'widget_module' => 'date',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'int',
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'rdf_property' => '',
    'display_settings' => 
    array (
      'weight' => '1',
      'parent' => '',
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
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '-3',
  'menu' => '2',
  'taxonomy' => '-4',
);
