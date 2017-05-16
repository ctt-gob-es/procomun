<?php
/**
 * @file
 *
 * This template provides a three column 3-6-3 panel display layout for the 12-column bootstrap grid.
 * The first column will be displayed above the others on the small displays (up).
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display panel-ag-3up-6-3 clearfix row" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel panel-col-first col-md-3 col-sm-12 hide-full">
    <?php print $content['left']; ?>
  </div>
  <div class="<?php if (isset($display->wrap_class)) { print $display->wrap_class . ' '; } ?>panel-panel panel-col col-md-6 col-sm-9 center">
    <?php if (isset($display->title_middle)): ?>
      <?php print $display->title_middle?>
    <?php endif; ?>
    <?php print $content['middle']; ?>
  </div>
  <div class="panel-panel panel-col-last col-md-3 col-sm-3 hide-full">
    <?php print $content['right']; ?>
  </div>
</div>
