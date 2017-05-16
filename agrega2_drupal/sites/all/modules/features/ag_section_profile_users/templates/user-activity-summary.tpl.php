<div id="user-activity-summary-block">
  <div id="user-activity-summary-header" class="clearfix">
    <span class="user-picture"><?php print render($vars['user_data']['picture']); ?></span>
    <span class="name"><?php print(l($vars['user_data']['name'], 'user/' . $vars['user_data']['uid'])); ?></span>
    <span class="user-mail"><?php print $vars['user_mail']; ?></span>
  </div>

  <div id="user-activity-summary-body" class="clearfix">
    <?php foreach ($vars['boxes'] as $cnt => $value) : ?>
      <div class="summary-body-box <?php print (($cnt % 2 == 0) ? 'odd' : 'even') ?>">
        <span class="box-label"><?php print($value['label']); ?></span>
        <span class="box-number"><?php print($value['count']); ?></span>
      </div>
    <?php endforeach; ?>
  </div>

  <?php if (isset($vars['my_contributions_link'])) : ?>
  <div id="user-activity-my-contributions" class="clearfix">
    <?php print render($vars['my_contributions_link']); ?>
  </div>
  <?php endif; ?>

</div>
