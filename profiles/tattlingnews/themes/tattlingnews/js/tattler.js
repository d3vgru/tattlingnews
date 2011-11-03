
Drupal.behaviors.tattler_theme = function(context) { 

	$('#tattler_topic_selector').selectbox({debug: false});
	
  //------- QUICK NODE EDIT POPUP --------
  var theme_path = Drupal.settings.basePath + 'sites/all/themes/tattler/facebox';
  $.facebox.settings.loadingImage = theme_path + '/loading.gif';
  $.facebox.settings.closeImage   = theme_path + '/closelabel.gif';
  $.facebox.settings.opacity = 0.55;   
  $('a[rel*=facebox]').facebox();
 
/*
    // if the function argument is given to overlay, it is assumed to be the onBeforeLoad event listener 
    $("a[rel]").overlay(
      {    
        expose: '#445566',    
        onLoad: function() { 
           // grab wrapper element inside content 
           var wrap = this.getContent().find("div.quick_node_edit_wrap"); 
            
           // load only for the first time it is opened 
           //if (wrap.is(":empty")) { 
               wrap.load(this.getTrigger().attr("href")); 
           //} 
        },
        onClose: function() {
           var wrap = this.getContent().find("div.quick_node_edit_wrap"); 
           //Prepare for the next time          
           wrap.html('Loading...');        
        }
      }
    );
*/
  
  //------- TAG FILTER FIELD ------------
  
  $("input#edit-mentions-tag-filter").focus(function(e) {
    if ($.trim($(this).val()) == Drupal.t("Search Tag")) {
      $(this).val("");
    }
  });

  $("input#edit-mentions-tag-filter").blur(function(e) {
    if ($.trim($(this).val()) == "") {
      $(this).val(Drupal.t("Search Tag"));
    }
  });  

  $("input#edit-mentions-tag-filter", context).keydown(function(e){
    	
    if (e.keyCode == 13) { 
      e.preventDefault();    
      //This seems to interfere with the auto-complete :(
      //search_mention_by_tag();            
      return false;
    }
    
  });

  $("div#tagfilterbutton", context).click(function(e) {
    e.preventDefault();
    search_mention_by_tag();            
    return false;
  });

  function search_mention_by_tag() {
    var curr_url = Drupal.settings.tattlerui.url4_tagged;
    var tags = $.trim($('input#edit-mentions-tag-filter').val());
    if (tags == "" || tags == Drupal.t("Enter a tag")) {
      alert (Drupal.t("Please indicate a tag to filter on."));
      return false;
    }
    
    var query_string = curr_url + "&tagged=" + encodeURIComponent(tags);
    try {
      document.location.href(query_string);
    } catch(ex) {
      document.location = query_string;
    }    
    return false;
  }
  
  //------ TOPIC Selector --------------------
  $("#tattler_topic_selector", context).change(function(e) {
    var curr_url = Drupal.settings.tattlerui.url4_topic;
    var topic = $("#tattler_topic_selector", context).val();
    var query_string = curr_url + "&topic=" + encodeURIComponent(topic);
    try {
      document.location.href(query_string);
    } catch(ex) {
      document.location = query_string;
    }    
    return false;
  }); 

  
  //------ TOOLTIPS FOR TAG FILTER FORM -------
  
  // select all desired input fields and attach tooltips to them 
  $("#tattlerui-tag-filter-form :input").tooltip({ 
   
      //Id of the tag filter element
      tip: 'div#tag_filter_tooltip',
      
      // place tooltip on the right edge 
      position: ['top', 'center'], 
   
      // a little tweaking of the position 
      offset: [-5, 10], 
   
      effect: 'slideup', 
       
      // custom opacity setting 
      opacity: 0.8 
  });
  
  
   //------ TOOLTIPS Search -------
  
  // select all desired input fields and attach tooltips to them 
  $("#search_form_field").tooltip({ 
   
      //Id of the tag filter element
      tip: 'div#search_form_field_tooltip',
      
      // place tooltip on the right edge 
      position: ['top', 'center'], 
   
      // a little tweaking of the position 
      offset: [-5, 10], 
   
      effect: 'slideup', 
       
      // custom opacity setting 
      opacity: 0.8 
  });

  
  //------ SEARCH FIELD  -------
  
  // img#search_button ,  div#search_form_field input
  $("div#search_button img", context).click(function(e) {
    e.preventDefault();    
    redirectToSearch();
    return false;
   });
   
   
  $("div#search_form_field input", context).keydown(function(e){
    	
    if (e.keyCode == 13) { 
      e.preventDefault();    
      redirectToSearch();            
      return false;
    }
    
  });
   
  function redirectToSearch() {
    var dest_url = $('div#search_form_field input').val();
    document.location.href = '/search/node/' + dest_url;
  }
 
 
	//------- ACT BUTTON HOVER --------------
	
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