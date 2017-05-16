<?php
/**
 * @file
 * Social networks dropdown widget.
 *
 * Available variables:
 * - $links: Array of Social Network links to share content
 */
?>
<div class="share-outside-networks pull-right inline-elements valign-middle space-inline-elements">
  <div class="toggle-social-networks"><span class="share"></span></div>
  <div class="wrapper">
    <?php if (isset($rrss_links_teaser)): ?>
      <div class="item-list">
        <ul class="services_link">
          <?php foreach($rrss_links_teaser as $item): ?>
            <li><?php print $item; ?></li>
          <?php endforeach; ?>
        </ul>
      </div>
    <?php else: ?>
      <?php print render($links); ?>
    <?php endif; ?>
  </div>
</div>
