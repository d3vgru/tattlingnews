/**
 * @author Caroline Schnapp
 */
// $Id: jquery.plus1.js,v 1.1.4.5 2011/01/13 16:14:32 nancyw Exp $
// Global killswitch: only run if we are in a supported browser.
if (Drupal.jsEnabled) {
  // Documentation on Drupal JavaScript behaviors can be found here: http://drupal.org/node/114774#javascript-behaviors
  Drupal.behaviors.plus1 = function (context) {
    jQuery('.' + Drupal.settings.plus1.widget_class, context).each(function () {
      var plus1_widget = jQuery(this), plus1_form = plus1_widget.find('form.' + Drupal.settings.plus1.vote_class);
      plus1_form.attr('action', plus1_form.attr('action') + '&json=true').submit(function () {
        jQuery.ajax({
          'type': 'POST',
          'dataType': 'json',
          'url': jQuery(this).attr('action'),
          'success': function (json) {
            plus1_widget.find('.' + Drupal.settings.plus1.score_class).hide().fadeIn('slow').html(json.score);
            plus1_widget.find('.' + Drupal.settings.plus1.message_class).html(json.voted);
          }
        });
        // Preventing the /plus1/vote/<nid> target from being triggered. 
        return false;
      });
    });
  };
}
