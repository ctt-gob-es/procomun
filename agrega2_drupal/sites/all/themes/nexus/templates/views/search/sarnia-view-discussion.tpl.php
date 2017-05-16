<?php
/**
 * Discussion row template.
 */
?>
<li class="search-result discussion-result clearfix">
  <div class="col-sm-12">
    <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>
  <div class="col-sm-2">
    <div class="image"><?php print $properties['discussionPicture']; ?></div>
  </div>

  <div class="col-sm-10">
    <?php if (!empty($properties['descriptionStr'])): ?>
      <div class="description"><?php print $properties['descriptionStr']; ?></div>
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

  <?php /** Block social **/ ?>
  <?php if (user_is_logged_in() && isset($properties['idDrupal'])): ?>
    <ul class="social col-sm-12">
      <li class="social-like">
        <?php print flag_create_link('like', $properties['idDrupal']); ?>
      </li>

      <li class="social-comment comment-link">
        <?php print l(t('Comment'), 'comment/new/' . $properties['idDrupal']); ?>
      </li>

      <li class="social-favorite">
        <?php print flag_create_link('favorite', $properties['idDrupal']); ?>
      </li>
    </ul>
  <?php endif; ?>
</li>
