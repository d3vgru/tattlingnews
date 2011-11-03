Drupal.behaviors.tattler_sourceslisting = function(context) {
    
  $("li.entry").hover(
    function()
    {
      $('div.actions', this).show();
    },
    function()
    {
      $('div.actions', this).hide();
    }
  );
  
}