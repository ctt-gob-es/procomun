<?php
/**
 * This file is the template for printing the facebook timeline
 *
 * Variables
 * $fanpage The fanpage to retrieve the posts
 */
?>
<div id="fb-root"></div>

<div class="fb-like-box" data-href="https://www.facebook.com/<?php print $fanpage; ?>"
     data-width="300" data-height="400"
     data-colorscheme="light" data-show-faces="true" data-header="true"
     data-stream="true" data-show-border="true">
</div>