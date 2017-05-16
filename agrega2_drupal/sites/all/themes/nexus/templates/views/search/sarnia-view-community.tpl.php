<?php
/**
 * User row template.
 */
?>
<li class="search-result community-result clearfix">
  <div class="col-sm-12">
    <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>
  <div class="col-sm-2">
    <div class="image"><?php print $properties['communityPicture']; ?></div>
  </div>

  <div class="col-sm-10">
    <?php if (!empty($properties['descriptionStr'])): ?>
      <div class="description"><?php print $properties['descriptionStr']; ?></div>
    <?php endif; ?>

    <table class="extra-table">
      <tr class="row">
        <td class="label col-sm-3"><?php print t('Resources number'); ?></td>
        <td class="content col-sm-9"><?php print $properties['number_resources']; ?></td>
      </tr>

      <tr class="row">
        <td class="label col-sm-3"><?php print t('Subscribers number'); ?></td>
        <td class="content col-sm-9"><?php print $properties['number_subscribers']; ?></td>
      </tr>

      <tr class="row">
        <td class="label col-sm-3"><?php print t('Community type'); ?></td>
        <td class="content col-sm-9"><?php print $properties['community_type']; ?></td>
      </tr>
    </table>

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
