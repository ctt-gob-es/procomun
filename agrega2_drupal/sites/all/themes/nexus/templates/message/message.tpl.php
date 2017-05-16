<?php

/**
 * @file
 * Default theme implementation for message entities.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) entity label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-{ENTITY_TYPE}
 *   - {ENTITY_TYPE}-{BUNDLE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_message()
 * @see template_process()
 */
?>

<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="header-message">
    <?php if (isset($content['user_picture'])): ?>
      <span class="user-picture">
        <?php print render($content['user_picture']); ?>
      </span>
    <?php endif; ?>
    <?php if (isset($content['user_name'])): ?>
      <span class="user-name">
        <?php print render($content['user_name']); ?>
      </span>
    <?php endif; ?>
    <?php if (isset($content['message_subject'])): ?>
      <span class="mesage-subject">
        <?php print render($content['message_subject']); ?>
      </span>
    <?php endif; ?>
  </div>
  <div class="body-message">
    <?php if (isset($content['links'])): ?>
        <?php hide($content['links']); ?>
    <?php endif; ?>
    <?php print render($content); ?>
  </div>
  <?php if (isset($content['links'])): ?>
    <ul class="social">
      <?php print render($content['links']); ?>
    </ul>
  <?php endif; ?>
</div>
