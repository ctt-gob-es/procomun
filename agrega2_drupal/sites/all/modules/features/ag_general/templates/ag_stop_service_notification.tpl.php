<div class="stop-service-notification">
  <?php if(!empty($title)): ?>
    <div class="stop-service-notification-title">
      <?php print t($title); ?>
    </div>
  <?php endif; ?>

  <?php if(!empty($description)): ?>
    <div class="stop-service-notification-text">
      <?php print t($description); ?>
    </div>
  <?php endif; ?>

  <?php if(!empty($link)): ?>
    <div class="stop-service-notification-link">
      <?php print $link; ?>
    </div>
  <?php endif; ?>
</div>
