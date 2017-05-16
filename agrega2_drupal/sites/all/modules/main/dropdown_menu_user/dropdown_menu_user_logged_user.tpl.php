<div class="user-login">
<!--  <div class="share-link">
    <?php /*if (isset($share_link)): */?>
      <?php /*print($share_link); */?>
    <?php /*endif; */?>
  </div>-->
  <div class="user-image">
    <?php if (isset($user['image'])): ?>
      <?php print($user['image']); ?>
    <?php endif; ?>
  </div>
  <?php if (isset($user['notifications'])): ?>
    <?php print($user['notifications']); ?>
  <?php endif; ?>

<!--  <div class="user-name">
    <?php /*if (isset($user['name'])): */?>
      <span><?php /*print($user['name']); */?></span>
    <?php /*endif; */?>
  </div>

  <div class="user-settings">
    <div><?php /*print t('Settings'); */?></div>
  </div>

  <div class="user-logout">
    <?php /*$options = array('attributes' => array('title' => t('Logout'))); */?>
    <?php /*print l(t('Logout'), 'user/logout', $options); */?>
  </div>-->
</div>
