<?php

/**
 * @file
 * Default theme implementation to format the simplenews newsletter footer.
 *
 * Copy this file in your theme directory to create a custom themed footer.
 * Rename it to simplenews-newsletter-footer--[newsletter-id].tpl.php to override it for a
 * newsletter using the newsletter id.
 *
 * @todo Update the available variables.
 * Available variables:
 * - $build: Array as expected by render()
 * - $build['#node']: The $node object
 * - $language: language code
 * - $key: email key [node|test]
 * - $format: newsletter format [plain|html]
 * - $unsubscribe_text: unsubscribe text
 * - $test_message: test message warning message
 * - $simplenews_theme: path to the configured simplenews theme
 *
 * Available tokens:
 * - [simplenews-subscriber:unsubscribe-url]: unsubscribe url to be used as link
 *
 * Other available tokens can be found on the node edit form when token.module
 * is installed.
 *
 * @see template_preprocess_simplenews_newsletter_footer()
 */
?>
<?php if (!$opt_out_hidden): ?>
  <?php if ($format == 'html'): ?>
    <p style="padding: 15px; text-align: right" class="newsletter-footer"><a style="padding: 10px; text-decoration: none; color: white; border-radius: 5px; background-color: #00aa89; font-size: 13px; display: inline-block" href="[simplenews-subscriber:unsubscribe-url]"><?php print $unsubscribe_text ?></a></p>
  <?php else: ?>
  -- <?php print $unsubscribe_text ?>: [simplenews-subscriber:unsubscribe-url]
  <?php endif ?>
<?php endif; ?>

<?php if ($key == 'test'): ?>
- - - <?php print $test_message ?> - - -
<?php endif ?>
