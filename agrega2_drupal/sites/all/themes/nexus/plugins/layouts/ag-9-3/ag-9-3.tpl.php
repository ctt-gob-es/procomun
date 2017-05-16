<?php
/**
 * @file
 * Template for a custom 2 column panel layout: 3 columns and 9 columns in a 12 column bootstrap grid
 */
?>
<div class="panel-display panel-ag-9-3 clearfix row" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel panel-col-first col-sm-9">
    <?php print $content['left']; ?>
  </div>

  <div class="panel-panel panel-col-last col-sm-3">
    <?php print $content['right']; ?>
  </div>
</div>
