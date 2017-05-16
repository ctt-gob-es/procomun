<?php
/**
 * @file
 * Template to display a mozilla group badges.
 */
?>
<div class="user-mozilla-badges">
  <h2><?php print t('Badges'); ?></h2>
  <?php foreach ($mozilla_badges as $key => $group): ?>
    <li class="user-mozilla-badges-group">
      <h3 class="user-mozilla-badges-groupname">
        <?php print $group['group_name']; ?>
      </h3>
      <ul class="user-mozilla-badges-item-list clearfix">
        <?php foreach ($group['badges'] as $bgid => $badge): ?>
          <li class="user-mozilla-badges-item">
            <img src='<?php print $badge['image']; ?>' border=0 />

            <div class="user-mozilla-badges-metadata">
              <div class="badge-modal-header">
                <a href="#" class="close-badge-icon">Close</a>
              </div>
              <div class="badge-modal-content">
                <div class="badge-modal-img">
                  <img src='<?php print $badge['image']; ?>' border=0 />
                </div>
                <div class="badge-content-list">
                  <h4 class="issued-detail"><?php print t('Issuer details'); ?></h4>
                  <ul class="user-mozilla-badges-metadata-issuer-list">
                    <li><strong><?php print $badge['issuer_name']['label']; ?> :</strong><span><?php print $badge['issuer_name']['data']; ?></li>
                    <li><strong><?php print $badge['issuer_url']['label']; ?> :</strong><span><?php print $badge['issuer_url']['data']; ?></li>
                  </ul>
                  <h4 class="issued-badge"><?php print t('Badge details'); ?></h4>
                  <ul class="user-mozilla-badges-metadata-badge-list">
                    <li><strong><?php print $badge['title']['label']; ?>:</strong><span> <?php print $badge['title']['data']; ?></span></li>
                    <li><strong><?php print $badge['description']['label']; ?>:</strong><span> <?php print $badge['description']['data']; ?></span></li>
                    <li><strong><?php print $badge['criteria_url']['label']; ?>:</strong><span> <?php print $badge['criteria_url']['data']; ?></span></li>
                    <li><strong><?php print $badge['issued']['label']; ?>:</strong><span> <?php print $badge['issued']['format']; ?></span></li>
                  </ul>
                </div>
              </div>
            </div>
          </li>
        <?php endforeach; ?>
      </ul>
    </li>
  <?php endforeach; ?>
</div>
