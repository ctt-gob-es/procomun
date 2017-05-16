<div id="comunity-public-dashboard-block">
  <div class="comunity-public-dashboard-header">
    <span class="comunity-title">
      <?php print render($vars['comunity_title']); ?>
    </span>
    <span class="comunity-link-action">sdsdsd</span>
  </div>
  <div class="comunity-public-dashboard-links">
    <?php print render($vars['wall_links']); ?>
  </div>
  <div class="comunity-public-dashboard-counters">
    <div class="comunity-public-dashboard-count">
      <span class="comunity-public-dashboard-count-number">
        <?php print render($vars['resources_count']);?>
      </span>
      <span class="comunity-public-dashboard-count-title">
        <?php print t('Resources')?>
      </span>
    </div>
    <div class="comunity-public-dashboard-count">
      <span class="comunity-public-dashboard-count-number">
        <?php print render($vars['members_count']);?>
      </span>
      <span class="comunity-public-dashboard-count-title">
        <?php print t('Members')?>
      </span>
    </div>
  </div>
  <div class="comunity-public-dashboard-administers">
    <span class="administers-label">
      <?php print(t('Administrators'));?>
    </span>
    <span class="administers-list">
      <?php print render($vars['administers_list']);?>
    </span>
  </div>
  <div class="comunity-public-dashboard-subscribe">
    <span class="comunity-access-type">
      <?php print render($vars['comunity_access_type']);?>
    </span>
    <span class="comunity-subscribe">
      <?php print render($vars['comunity_subscribe_link']);?>
    </span>
  </div>
  <div class="comunity-public-dashboard-share">
    <?php if (!$is_private && $is_member): ?>
      <div class="screenViewer inner-section">
        <div class="normal-actions do-inline pull-right space-l-inline-elements">
          <div class="insert do-inline"><div class="ico ico-insertar"></div><div class="value"><?php print $share_message; ?></div></div>
        </div>

        <div class="content">
          <div class="normal-actions-holder">
            <div class="insert"><textarea rows="2"><?php print $insert_link; ?></textarea></div>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>

