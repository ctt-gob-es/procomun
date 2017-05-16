<?php
/**
 * User row template.
 */
?>
<li class="search-result user-result clearfix">
  <div class="col-sm-1">
    <div class="image"><?php print $properties['userPicture']; ?></div>
  </div>

  <div class="col-sm-11">
    <?php if (!empty($properties['userName'])): ?>
      <h2 class="title"><?php print $properties['userName']; ?></h2>
      <?php if (!empty($properties['followLink'])): ?>
        <?php print $properties['followLink']; ?>
      <?php endif; ?>
    <?php endif; ?>
  </div>

</li>
