<div id="tool" class="clearfix">
	 <?php if ($breadcrumb || $messages || $tabs || $action_links): ?>
          <div id="content-header">

            <?php print $breadcrumb; ?>

            <?php if ($page['highlight']): ?>
              <div id="highlight"><?php print render($page['highlight']) ?></div>
            <?php endif; ?>

           

            <?php print render($title_suffix); ?>
            <?php print $messages; ?>
            <?php print render($page['help']); ?>

         

            <?php if ($action_links): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>

	  			   <?php if ($tabs): ?>
			          <div class="tabs"><?php print render($tabs); ?></div>
			        <?php endif; ?>
            		 <?php if ($page['adminmenu']): ?>
			              <div id="adminmenu"><?php print render($page['adminmenu']) ?></div>
			            <?php endif; ?>
          </div> <!-- /#content-header -->
        <?php endif; ?>
</div>
<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="header">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
      </a>
    <?php endif; ?>
    <div class="slogan">
	</div>
	<a class="call-me" href="/contact"><img src="http://kinderevenementenbureau.nl/sites/all/themes/basic/images/call-me.png" alt="<?php print t('Nieuwsbrief'); ?>"/></a>
    <?php if ($page['header']): ?>
      <div id="header-region" class="clearfix">
        <?php print render($page['header']); ?>
      </div>
    <?php endif; ?>
  </div>
  
  <div id="main" class="clearfix">
    <div id="content-container" class="clearfix">
      <?php print render($page['content']) ?>
    </div>  
  </div> 
  <?php if ($page['footer']): ?>
	  <div id="footer">
		<a id="footerlink" href="#"></a>
    <a id="footerlink2" href="/nieuwsbrief"></a>
	    <?php print render($page['footer']); ?>
	  </div> <!-- /footer -->
	<?php endif; ?>
</div> <!-- /page -->
<script>
jQuery(document).ready(function($) { 
  
  $("#superfish-1").mobileMenu({
    prependTo: "#block-superfish-1",
    combine: true,
    switchWidth: "767",
    topOptionText: "Menu"
  });
  
  });
  </script>