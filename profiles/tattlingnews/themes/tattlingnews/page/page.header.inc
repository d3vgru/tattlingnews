<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!--[if lt IE 7]>
  <script src="<?php print base_path() . path_to_theme();?>/js/ie7.js" type="text/javascript"></script>
  <![endif]-->
  <!--[if lte IE 7]><?php print phptemplate_get_ie_styles(); ?><![endif]--><!--If Less Than or Equal (lte) to IE 7-->
  <!--[if lte IE 6]><?php print phptemplate_get_ie6_styles(); ?><![endif]--><!--If Less Than or Equal (lte) to IE 6-->  
     
</head>

<body class="<?php print $body_classes; ?>">

<!--<a href="http://tattler.uservoice.com" id="app-feedback" target="_blank">FEEDBACK</a>-->

<div id="main_page_container" class="clearfix">

<div id="header" class="clearfix">
	<div id="logo_header" class="clearfix clear">
	 <a href="<?php print base_path();?>"><span id="tattler_logo" class="float-left"></span></a>
   
     <?php 
      $tattler_topics_monitored = tattlerui_get_topic_titles();
      $shortened = substr($tattler_topics_monitored, 0, 95);
      if (strlen($shortened) != strlen($tattler_topics_monitored)) $shortened .=  " ...";
      $tattler_topics_monitored = $shortened; 
    ?>
   <div id="tattler_monitoring_left" class="float-left"></div>    
   <div id="tattler_monitoring" class="float-left clearfix">
    <?php if ($user->uid > 0) : ?>
      <b><?php print t('Monitoring:') . '</b> ' . $tattler_topics_monitored; ?>
      <a href="<?php print url('topics'); ?>"><img src="<?php  print base_path() . path_to_theme(); ?>/images/buttons/btn-add.gif" /></a>
    <?php endif; ?>
   </div>    
   <div id="tattler_monitoring_right" class="float-left"></div>    

    <div id="top_nav" class="clearfix">
    	<ul>
<!--        	<li><a href="<?php print base_path();?>"><?php print t('mentions');?></a></li>-->
        	<li><?php print l(t('mentions'), 'node'); ?></li>
            <li><?php print l(t('sources'), 'sources'); ?></li>
<!--             <li><?php print l(t('trends'), 'trends'); ?></li>-->
            <!--li><?php print l(t('feeds'), 'buzzfeeds'); ?></li>
            <li><?php print l(t('tags'), 'buzzcloud'); ?></li-->  
            <li><?php print tattlerui_logout_link(); ?></li>                                                 
      </ul>      
    </div><!--/top nav-->   
    </div><!--/logo_header-->

</div><!--/header-->
