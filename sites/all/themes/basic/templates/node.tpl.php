<script type="text/javascript">
jQuery(document).ready(function($) {
	  	$(function(){
			$('#slides').slides({
				preload: true,
				play: 10000,
				generatePagination: false
			});
		});		
});



</script>
<div class="background-image">
  <div id="slides">
    <div class="slides_container">
      <?php print render ($content['field_image']);?>
    </div>    
  </div>
</div>

<div class="node-content">
  <h2>
    <?php print $title; ?>
  </h2>
 	  <?php 
  	    // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        hide($content['field_image']);
        print render($content);
       ?>
  	
  <?php if (!empty($content['links']['terms'])): ?>
    <div class="terms">
      <?php print render($content['links']['terms']); ?>
    </div>
  <?php endif;?>
  <?php if (!empty($content['links'])): ?>
    <div class="links">
      <?php print render($content['links']); ?>
    </div>
  <?php endif; ?>
</div>
<div class="vlakje"></div>