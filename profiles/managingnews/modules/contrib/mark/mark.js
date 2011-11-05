// $Id: mark.js,v 1.2 2010/02/22 21:15:39 yhahn Exp $

Drupal.behaviors.mark = function(context) {
  $('.mark-link > a:not(.mark-processed)').click(function() {
    elem = $(this);
    return Drupal.markClickHandler(elem);
  }).addClass('mark-processed');
};

Drupal.markClickHandler = function(elem) {
  if (!elem.hasClass('mark-updating')) {
    elem.addClass('mark-updating');
    var link = {};
    link.href = elem.attr('href');
    link.path = link.href.split('?');
    link.qs = {};
    $.each(link.path[1].split('&'), function(k, v) {
      var i = v.split('=');
      link.qs[i[0]] = i[1];
    });
    link.path = link.path[0];

    $.post(link.path, {token: link.qs.token}, function(data){
      // trigger an update event that others can bind to.
      elem.trigger('mark.drupalMark');

      // todo show confirmation message from data.message
      elem.parent('.mark-link').before(data.markup).remove();
      Drupal.attachBehaviors($('.mark-link'));
    }, "json");
  }
  return false;
};
