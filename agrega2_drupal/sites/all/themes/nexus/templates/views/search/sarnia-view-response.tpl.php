<?php
/**
 * Response row template.
 */
?>
<li class="search-result response-result clearfix">
  <div class="col-sm-12">
    <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>
  <div class="col-sm-2">
    <div class="image"><?php print $properties['responsePicture']; ?></div>
  </div>

  <div class="col-sm-10">
    <?php $response = (isset($properties['idDrupal'])) ? 'node/' . $properties['idDrupal'] : ''; ?>
    <h2 class="title"><?php print l(t('Show response'), $response); ?></h2>

    <?php if (isset($_GET['type']) && $_GET['type'] != 'RESPONSE'): ?>
      <div class="content-type"><p><?php print t('Response'); ?></p></div>
    <?php endif; ?>

    <?php if (!empty($properties['descriptionStr'])): ?>
      <div class="description"><?php print truncate_utf8($properties['descriptionStr'], 455, FALSE, TRUE); ?></div>
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

    <li class="social-favorite">
      <?php print flag_create_link('favorite', $properties['idDrupal']); ?>
    </li>
  </ul>
  <?php endif; ?>
</li>
