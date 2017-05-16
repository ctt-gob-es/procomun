<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header class="author-info">
    <?php if (!empty($user_picture)): ?>
      <?php print $user_picture; ?>
    <?php endif; ?>

    <?php if ($display_submitted): ?>
      <div class="metadata">
        <span class="author">
          <?php print t('Published by'); ?>&nbsp;
          <?php print $name; ?>&nbsp;|&nbsp;
        </span>

        <span class="publication-date">
          <?php print $created ?>
        </span>

        <?php if (isset($content['field_categories'])): ?>
          <div class="categorization nexus-inline">
            <span>&nbsp;|&nbsp;<?php print t("in"); ?></span>
            <?php print render($content['field_categories']); ?>&nbsp;|&nbsp;
          </div>
        <?php endif; ?>

        <?php if (!empty($total_answers)): ?>
          <span class="content-count">
            <?php print render($total_answers); ?>
          </span>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </header>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['title_field']);
      hide($content['user_link_answer']);
      print render($content);
    ?>
  </div>

  <?php if (!empty($content['links']['flag']['#links'])): ?>
    <footer><?php print render($content['links']); ?></footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <div class="comment-anonymous">
    <?php print render($content['user_link_answer']); ?>
  </div>

  <div class="pane-answers-content-in-questions">
    <h2 class="pane-title"><?php print $add_new_answer_block_subject; ?></h2>
    <?php if (isset($add_new_answer_block_content)): ?>
    <?php print $add_new_answer_block_content; ?>
    <?php endif; ?>
    <?php if (isset($answers_list)): ?>
    <?php print $answers_list; ?>
    <?php endif; ?>
  </div>
</article>
