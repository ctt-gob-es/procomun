<?php

/**
 * @file
 * Default theme implementation to format the simplenews newsletter body.
 *
 * Copy this file in your theme directory to create a custom themed body.
 * Rename it to override it. Available templates:
 *   simplenews-newsletter-body--[tid].tpl.php
 *   simplenews-newsletter-body--[view mode].tpl.php
 *   simplenews-newsletter-body--[tid]--[view mode].tpl.php
 * See README.txt for more details.
 *
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $title: Node title
 * - $language: Language code
 * - $view_mode: Active view mode
 * - $simplenews_theme: Contains the path to the configured mail theme.
 * - $simplenews_subscriber: The subscriber for which the newsletter is built.
 *   Note that depending on the used caching strategy, the generated body might
 *   be used for multiple subscribers. If you created personalized newsletters
 *   and can't use tokens for that, make sure to disable caching or write a
 *   custom caching strategy implemention.
 *
 * @see template_preprocess_simplenews_newsletter_body()
 */
?>
<h2 style="padding: 0; margin: 20px 0 10px; color: #1A3752; font-size: 22px;"><?php print $title; ?></h2>
<div style="padding: 0px; margin: 15px auto; font-size: 16px; color: #666666;"><?php print render($build); ?></div>

<div style="">
  <div style="font-size: 18px; margin: 35px 0 15px; font-weight: bold; color: #1A3752;"><?php print $content_ref['#title']; ?>:</div>
  <div style="padding: 15px 0; overflow: hidden; box-sizing: border-box; width: calc(100% - 37px); border-radius: 5px; border: 1px solid #cccccc; box-shadow: 3px 3px 6px #cccccc">
    <?php foreach ($content_ref['#items'] as $item): ?>
      <?php $vars = (array)$item['entity']; ?>
      <?php $vars['view_mode'] = 'newsletter'; ?>
      <?php _generate_newsletter_miniatures($vars); ?>
      <div class="elem" style="padding: 15px 0; overflow: hidden; float: left; margin: 0 15px; width: calc(50% - 30px)">
        <div style=" width: 100px; float: left; margin-right: 15px; text-align: center;">
          <?php print $vars['miniatura_newsletter']; ?>
        </div>
        <header style="float: left; width: calc(100% - 115px);">
          <h4 style="margin: 0 0 10px; font-weight: bold; font-size: 18px;"><?php print l($item['entity']->title, 'node/' . $item['entity']->nid, array('absolute' => TRUE, 'attributes' => array('style' => 'color: #1A3752; text-decoration: none; white-space: nowrap; text-overflow: ellipsis; overflow: hidden; display: block;'))); ?></h4>
          <span style="text-transform: uppercase; font-size: 12px; color: #666666;"><?php print t('@type', array('@type' => t($item['entity']->type))); ?></span>
        </header>
      </div>
    <?php endforeach; ?>
  </div>
</div>
