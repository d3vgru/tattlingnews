<?php
// $Id: web_widgets_iframe.tpl.php,v 1.1.2.2 2010/10/11 22:17:39 diggersf Exp $
/**
 * @file
 * Template for the code what to embed in external sites
 */
?>
<div style="width:300px; font-family:'Helvetica Neue', Helvetica, Arial, sans-serif; line-height:20px">
<div style="background-color:#333; padding:0px 5px; font-weight:bold">
<div style="color:#fff; font-size:14px; line-height:25px;"><?php print $title ?></div>
<div style="font-size:11px; color:#ccc"><?php print $site_name ?></div>
</div>
<script type="text/javascript">
widgetContext = <?php print $js_variables ?>;
</script>
<div id="<?php print $wid ?>"></div>
<script src="<?php print $script_url ?>"></script>
<div style="font-size: 10px;"><?php print $site_link ?></div></div>