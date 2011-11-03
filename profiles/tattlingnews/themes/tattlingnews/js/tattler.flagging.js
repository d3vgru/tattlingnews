Drupal.behaviors.tattler_bmflagging = function(context) {
      
  var elements  = "a.watchlist,a.watchlist_on";
      elements += ",a.blacklist_on,a.blacklist";
      elements += ",a.bookmark,a.bookmark_on";

  $(elements).click(function(e) {
    
    e.preventDefault();
   
    var el = $(this), on, off;
    
    if (el.hasClass('watchlist') || el.hasClass('watchlist_on')) {
      on = 'watchlist_on'; off = 'watchlist';
      on_text  =  Drupal.settings.tattler.msg_watchlist; 
      off_text =  Drupal.settings.tattler.msg_de_watchlist;
    } else if (el.hasClass('blacklist') || el.hasClass('blacklist_on')) {
      on = 'blacklist_on'; off = 'blacklist';
      on_text  = Drupal.settings.tattler.msg_blacklist; 
      off_text = Drupal.settings.tattler.msg_de_blacklist;  
    } else if (el.hasClass('bookmark') || el.hasClass('bookmark_on')) {
      on = 'bookmark_on'; off = 'bookmark';
      on_text  = ''; 
      off_text = '';  
    } else {
      return;
    }

    $.ajax({
      type: 'POST',
      url: el.attr('href'),
      data: { js: true },
      dataType: 'json',
      success: function (data) {
        if (data.status) {
          if (el.hasClass(on)) {
            el
              .addClass(off)
              .removeClass(on)
              .siblings('div.buzz_only_icon')
              .addClass(off)
              .removeClass(on);
            if (el.text().length > 5) el.text(on_text);
          } else if (el.hasClass(off)) {
            el
              .addClass(on)
              .removeClass(off)
              .siblings('div.buzz_only_icon')
              .addClass(on)
              .removeClass(off);

//            el.addClass(on).removeClass(off);            
            if (el.text().length > 5) el.text(off_text);            
          }
        }
        else {
          // Failure.
          alert(data.errorMessage);
          $wrapper.removeClass('flag-waiting');
        }
      },
      error: function (xmlhttp) {
        alert('An HTTP error '+ xmlhttp.status +' occurred.\n'+ element.href);
      }
    });   
    
    return false;  
  });  
}