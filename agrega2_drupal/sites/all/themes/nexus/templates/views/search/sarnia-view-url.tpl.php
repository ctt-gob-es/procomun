<?php
/**
 * External content row template.
 */
?>
<li class="search-result url-result clearfix">
  <div class="col-sm-12">
    <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>
  <div class="col-sm-2">
    <div class="image"><?php print $properties['urlPicture']; ?></div>
  </div>

  <div class="col-sm-10">
<!--    <?php /*if (!empty($properties['descriptionStr'])): */?>
      <div class="description"><?php /*print $properties['descriptionStr']; */?></div>
    --><?php /*endif; */?>

    <?php if (!empty($properties['url'])): ?>
      <div class="url"><?php print $properties['url']; ?></div>
    <?php endif; ?>

    <?php if (!empty($properties['keywords'])): ?>
      <div class="extra-info">
        <div class="tags">
          <?php if (isset($properties['keywords'])): ?>
            <?php foreach ($properties['keywords'] as $keyword): ?>
              <?php print $keyword; ?>
            <?php endforeach; ?>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>
  </div>
</li>
