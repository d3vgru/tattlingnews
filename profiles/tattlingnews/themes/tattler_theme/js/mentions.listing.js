Drupal.behaviors.tattler_mentiontoggle = function(context) {
  
  $('li.entry').click(function(e) {
   if (e.target.nodeName == 'H2') {
    $(this)
     .addClass('entry_active')
     .find('div.entry_detail')
     .show();
   } 
  });

  $('div.close_entry_detail').click(function(e) {
   if (e.target.nodeName == 'A') {
     e.preventDefault();
     $(this)
     .parents('li.entry')
     .removeClass('entry_active')
     .find('div.entry_detail')
     .hide();
   } 
  });
  
  
  
}