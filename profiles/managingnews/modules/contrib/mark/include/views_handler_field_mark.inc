<?php
// $Id: views_handler_field_mark.inc,v 1.2 2010/03/16 22:40:53 jmiccolis Exp $

/**
 * Field handler for marks
 */
class views_handler_field_mark extends views_handler_field {

  /**
   * Render the field as a mark link.
   */
  function render($values) {
    if (user_access('mark items')) {
      $markname = substr($this->field, 5);
      $value = $values->{$this->field_alias};
      $links = array(); 
      $links[$markname] = array(
        'mark' => mark_load($markname),
        'votingapi' => array(
          'content_type' => $this->table,
          'content_id' => $value,
          'value_type' => 'mark',
          'value' => 1,
          'tag' => $markname,
        ),
      );
      return theme('mark_link', $links);
    }
  }
}
