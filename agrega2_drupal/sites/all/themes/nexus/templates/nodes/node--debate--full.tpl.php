<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header class="author-info">
    <?php print $user_picture; ?>

    <?php if($display_submitted): ?>
      <span>
        <span class="author">
          <?php print t('Asked by'); ?>
          <?php print $name; ?>&nbsp;|&nbsp;
        </span>

        <span class="publication-date">
          <?php print t('@time_ago ago', array('@time_ago' => $time_ago)); ?>
        </span>

        <?php if(isset($content['field_categories'])): ?>
          <div class="categorization nexus-inline">
            <span><?php print t("in"); ?></span>
            <?php print render($content['field_categories']); ?>&nbsp;|&nbsp;
          </div>
        <?php endif; ?>
        </span>

        <span class="content-count">
          <a href="#comments">
            <?php print format_plural($comment_count, 'response', 'responses'); ?>
            <span><?php print render($comment_count); ?></span>
          </a>
        </span>
    <?php endif; ?>
  </header>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['title_field']);
      print render($content);
    ?>
  </div>

  <?php if(!empty($content['links'])): ?>
    <footer><?php print render($content['links']); ?></footer>
  <?php endif; ?>

  <?php // Print rest of fields. ?>
  <?php print render($content['comments']); ?>
</article>
