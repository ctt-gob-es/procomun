<?php if (!empty($data)): ?>
  <span class="go-link"><?php print $data['title']; ?></span>
  <div class="wrap-info">
    <div id="info">
      <?php print theme('image', array('path' => $data['image'], 'alt' => $data['origin'])); ?>
      <div>
        <?php print l($data['origin_title'], $data['origin_link'], array('attributes' => array('target' => '_blank', 'class' => 'origin'))); ?>
        <div><?php print $data['title']; ?></div>
        <?php print l(t('Show more'), $data['link'], array('attributes' => array('target' => '_blank', 'class' => 'more-link'))); ?>
      </div>
    </div>
    <p>
      <?php print t('This information belongs to third parties. INTEF not responsible
                    for the accuracy of the information or the information contained.'); ?>
    </p>
  </div>
<?php endif; ?>
