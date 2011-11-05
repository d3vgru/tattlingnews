Drupal.behaviors.tattlerui_mentions_datepicker = function(context) {    

  // When clicking on "Given Date" show the date field
  $('a.sort-givendate', context).click(function(mouseEvent) {
    e.preventDefault();  
    $("#datepicker").datepicker(
      'dialog', 
      '' , 
      function(dateText) { 
        $("#datepicker").val(dateText); 
        $("#filterform").submit(); 
      },
      { 
        dateFormat: 'yy-mm-dd' 
      },
      mouseEvent
    );
    return false;
  });
}