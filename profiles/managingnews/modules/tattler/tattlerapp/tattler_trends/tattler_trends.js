Drupal.behaviors.tattler_trends = function(context) {
  $('#edit-vocabulary').change(function(){
    var id = '#bvcb_selector_' + $(this).val();
    $('.bvcb_selector').hide();
    $(id).show();
  });

  $('#edit-chart-engine').change(function(){
    var id = '#bchen_selector_' + $(this).val();
    $('.bchen_selector').hide();
    $(id).show();
  });

}
