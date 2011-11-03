<div id="trends_page" class="clearfix" style="margin-left: 70px;">  
  
<style>
  .bluff-wrapper {margin-bottom: 40px;}
</style>  
  
<?php


  $topics =  tattlerui_get_topic_titles('array');
  
  $trends = (array)_ttlr_get_trends();
  
  foreach ($trends as $trend) {
    $canvas = charts_graphs_get_graph('bluff');
    $canvas->type = "line"; 
        
    $canvas->title = t("Top") . ' ' . $trend->name;
    
    $canvas->colour = '#000000';
    $canvas->theme = 'keynote';

    $canvas->series = array();    
    foreach ($trend->entities as $entity) {
      $key = '&nbsp;' . l($entity->name, 'taxonomy/term/' . $entity->tid, array('attributes' => array('target' => '_blank'))) . " [" . $entity->mentions . "]";
      
      $trend_data = _ttlr_term_trend($entity->tid); 
      if (is_array($trend_data)) {
        $values = array_values($trend_data);
      }
      else {
        $values = array();
      }
      $canvas->series[$key] = $values;
      
    }
    if (is_array($trend_data)) {
      $canvas->x_labels = array_keys($trend_data);
    }
    else {
      $canvas->x_labels = array();
    }
    $canvas->width = 810;
    $canvas->height = 240;
    
    $out = $canvas->get_chart();
    echo $out;
  }
  
?>

</div><!--/ .clearfix -->     
