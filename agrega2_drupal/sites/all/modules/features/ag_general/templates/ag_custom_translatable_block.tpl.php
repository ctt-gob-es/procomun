<?php
/**
 * @file
 * Default theme implementation to display a custom translatable block
 *
 * Available variables:
 * - $block_title: the title of the block
 * - $block_content: the content of the block
 * - $block_class: the container class of the block
 */
?>
<div class="custom-block-container <?php print $block_class; ?>">
  <?php if ($block_title) : ?>
  <div class="custom-block-title">
    <?php print $block_title; ?>
  </div>
  <?php endif; ?>
  <div class="custom-block-content">
    <?php print $block_content; ?>
  </div>
</div>
