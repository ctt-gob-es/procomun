<?php if ($public_community['status'] == TRUE): ?>
  <div id="comunity-public-widget">
    <div class="comunity-public-widget-header">
      <?php print $public_community['data']['procomun_logo']; ?>
      <?php print $public_community['data']['linked_name']; ?>
    </div>
    <div class="comunity-public-widget-counters">
      <div class="comunity-public-widget-count">
        <span class="comunity-public-widget-count-title comunity-members">
          <?php print $public_community['data']['num_members']['label']; ?>
        </span>
        <span class="comunity-public-widget-count-number">
          <?php print $public_community['data']['num_members']['value']; ?>
        </span>
      </div>
      <div class="comunity-public-widget-count">
        <span class="comunity-public-widget-count-title comunity-resources">
          <?php print $public_community['data']['num_contents']['label']; ?>
        </span>
        <span class="comunity-public-widget-count-number">
          <?php print $public_community['data']['num_contents']['value']; ?>
        </span>
      </div>
    </div>
    <div class="comunity-public-widget-activity">
      <span class="recent-activity-label">
        <?php print $public_community['data']['recent_activity']['label']; ?>
      </span>
      <span class="recent-activity-list">
        <?php print $public_community['data']['recent_activity']['value']; ?>
      </span>
    </div>
  </div>
<?php else: ?>
  <div class ="message"><?php print $public_community['message']; ?></div>
<?php endif; ?>
