<?php
// $Id: views-view-fields--ttlr-semantic-views--block.tpl.php,v 1.1.2.2 2009/11/18 04:50:48 inadarei Exp $

/**

example $row object

stdClass Object
(
    [nid] => 788 //count, in reality.
    [term_data_name] => Twitter
    [vocabulary_name] => Company
    [term_data_tid] => 32
    [vocabulary_vid] => 3
)

*/

?>

<?php

$css_class = tattler_semantics_vocabname_to_css_class($row->vocabulary_name);


$link = l(ttlr_trim($row->term_data_name, 25), 
          'taxonomy/term/' . $row->term_data_tid,
          array('attributes' => array('target' => '_blank')));
          
$count = '<div class="count">'  . t('%count Mentions', array('%count' => $row->nid)) . '</div>';

print "<li class=\"$css_class clearfix\">$link $count</li>";

?>

