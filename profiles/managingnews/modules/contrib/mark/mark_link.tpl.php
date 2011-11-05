<?php
// $Id: mark_link.tpl.php,v 1.2 2010/02/22 23:54:07 yhahn Exp $
foreach ($links as $link):
?>
<div class="mark-link <?php print ($link->marked ? 'marked' : 'unmarked') ?>">
  <?php print l($link->title, $link->path, $link->options) ?>
</div>
<?php endforeach; ?>
