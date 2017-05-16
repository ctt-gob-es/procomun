<?php if ($public_profile['status'] == TRUE): ?>
  <div id="public-profile-widget">
    <div class="public-profile-widget-header">
      <?php print $public_profile['data']['procomun_logo']; ?>
    </div>
    <div class="public-profile-widget-content">
      <span>
        <?php print $public_profile['data']['picture']; ?>
      </span>
      <?php if (!empty($public_profile['data']['field_profile_name'])): ?>
        <span><?php print $public_profile['data']['field_profile_name']; ?></span>
      <?php endif; ?>
      <?php if (!empty($public_profile['data']['field_profile_surname'])): ?>
        <span><?php print $public_profile['data']['field_profile_surname']; ?></span>
      <?php endif; ?>
      <?php if (!empty($public_profile['data']['field_date_birth'])): ?>
        <span><?php print $public_profile['data']['field_date_birth']; ?></span>
      <?php endif; ?>
      <?php if (!empty($public_profile['data']['field_province'])): ?>
        <span><?php print $public_profile['data']['field_province']; ?></span>
      <?php endif; ?>
      <?php if (!empty($public_profile['data']['field_locality'])): ?>
        <span><?php print $public_profile['data']['field_locality']; ?></span>
      <?php endif; ?>
      <?php if (!empty($public_profile['data']['field_countries'])): ?>
        <span><?php print $public_profile['data']['field_countries']; ?></span>
      <?php endif; ?>
      <?php if (!empty($public_profile['data']['field_educative_center'])): ?>
        <span><?php print $public_profile['data']['field_educative_center']; ?></span>
      <?php endif; ?>
      <span class="public-profile-link">
        <?php print $public_profile['data']['profile_link']; ?>
      </span>
    </div>
    <div class="public-profile-widget-activity">
        <span class="recent-activity-label">
          <?php print $public_profile['data']['recent_activity']['label']; ?>
        </span>
        <span class="recent-activity-list">
          <?php print $public_profile['data']['recent_activity']['value']; ?>
        </span>
    </div>
  </div>
<?php else: ?>
  <div class ="message"><?php print $public_profile['message']; ?></div>
<?php endif; ?>
