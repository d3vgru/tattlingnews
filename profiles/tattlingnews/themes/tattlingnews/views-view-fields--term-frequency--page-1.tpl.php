<?php

if (!empty($row->term_data_name)) {
  $options = array('attributes'=>array('class'=>tattlerui_zebra_toggle()));
  $link = l($row->term_data_name, 'taxonomy/term/'. $row->term_data_tid, $options);
  echo $link . ' [' . $row->nid . '], &nbsp;&nbsp;&nbsp; ';
}
