<?php
// $Id: flag.tpl.php,v 1.1.2.6 2008/12/03 14:10:00 mooffie Exp $

/**
 * @file
 * Default theme implementation to display a flag link, and a message after the action
 * is carried out.
 *
 * Available variables:
 *
 * - $flag: The flag object itself. You will only need to use it when the
 *   following variables don't suffice.
 * - $flag_name_css: The flag name, with all "_" replaced with "-". For use in 'class'
 *   attributes.
 * - $flag_classes: A space-separated list of CSS classes that should be applied to the link.
 *
 * - $action: The action the link is about to carry out, either "flag" or "unflag".
 * - $last_action: The action, as a passive English verb, either "flagged" or
 *   "unflagged", that led to the current status of the flag.
 *
 * - $link_href: The URL for the flag link.
 * - $link_text: The text to show for the link.
 * - $link_title: The title attribute for the link.
 *
 * - $message_text: The long message to show after a flag action has been carried out.
 * - $after_flagging: This template is called for the link both before and after being
 *   flagged. If displaying to the user immediately after flagging, this value
 *   will be boolean TRUE. This is usually used in conjunction with immedate
 *   JavaScript-based toggling of flags.
 * - $setup: TRUE when this template is parsed for the first time; Use this
 *   flag to carry out procedures that are needed only once; e.g., linking to CSS
 *   and JS files.
 *
 * NOTE: This template spaces out the <span> tags for clarity only. When doing some
 * advanced theming you may have to remove all the whitespace.
 */

  if ($setup) {
    drupal_add_js(drupal_get_path('module', 'flag') .'/theme/flag.js');
  }
?>

<?php
$state = ($action=='flag') ? 'blacklist' : 'blacklist_on';
$msg = ($action=='flag') ? t('Add Source to Blacklist') : t('Remove Source from Blacklist');
?>

<?php if (arg(0) == 'sources') { ?>
<a href="<?php print $link_href; ?>" class="buzz_icon <?php print $state; ?>"></a>    
<?php } else { ?>
<div class="buzz_icon buzz_only_icon <?php print $state; ?>"></div><a href="<?php print $link_href; ?>" class="<?php print $state; ?>"><?php print $msg; ?></a>    
<?php } ?>
