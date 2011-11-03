    <div class="clear"></div>
    <div id="footer" class="clear clearfix">
    <div id="footer_and_copyright" class="clear clearfix">
       	<div class="footer_links">
        <ul class="clearfix">	
         	  <li><?php print l(t('mentions'), 'node'); ?>&nbsp;&nbsp;&nbsp;|</li>
            <li><?php print l(t('sources'), 'sources'); ?></li>            
<!--            <li><a href="#">trends</a>&nbsp;&nbsp;&nbsp;|</li>-->
           </div><!--/footer links-->
               <div id="copyright" class="clear clearfix"><a href="http://tattlerapp.com">Tattler (app)</a> is an open-source software licensed under <a href="http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt">GPL v2</a>. </div>
  
    </div><!--/footer and copyright-->
    <div id="powered_by_p2"><img src="<?php print base_path() . path_to_theme(); ?>/images/logo_phase2_footer.gif" alt="Powered by Phase2 Technology" /></div>
    
    </div><!--/footer-->
    
    </div><!--/page wrapper-->

<?php print $closure; ?>

</div><!--/ #main_page_container-->
</body>
</html>
