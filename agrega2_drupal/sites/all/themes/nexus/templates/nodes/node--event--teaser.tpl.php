<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

  <?php if(!$page): ?>
    <header>
  <?php endif; ?>

    <?php print render($content['title_field']); ?>

    <div class="author-info">
      <span>
        <span class="user-picture">
          <?php $user_picture = DrupalToolKit::getUserData($node->uid, array('picture'))->uri ?>
          <?php if (!empty($user_picture)): ?>
            <?php print theme('image_style', array('style_name' => 'avatar', 'path' => $user_picture)); ?>
          <?php else: ?>
            <?php $default_image = variable_get('user_picture_default', ''); ?>
            <?php print theme('image_style', array('style_name' => 'avatar', 'path' => $default_image,)); ?>
          <?php endif; ?>
        </span>
        <span class="author"><?php print $name; ?> | </span>
        <span class="date"><?php print $created; ?></span>
      </span>
      <span class="type"><?php print t($node_type_label); ?></span>
    </div>
<!--        <?php /*if(!empty($content['og_group_ref'])): */?>
      <span class="posted">
        <strong><?php /*print t('In'); */?></strong>
        <?php /*print render($content['og_group_ref']); */?>
      </span>
    --><?php /*endif;*/?>

  <?php if(!$page): ?>
    </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['title_field']);
      hide($content['comments']);
      hide($content['links']);
      hide($content['service_links']);
      print render($content);
    ?>
  </div>
    
  <?php if (isset($comment_count) && $comment_count > 0 && isset($timeline_comments) && !empty($timeline_comments)): ?>
    <div class="timeline-comments">
      <?php if ($comment_count > 2): ?>
        <span class="see-more-comments">
          <?php print l(t('See more comments'), 'node/' . $node->nid, array('class' => 'title', 'fragment' => 'comments')); ?>
        </span>
      <?php endif; ?>
      <?php print $timeline_comments; ?>
    </div>
  <?php endif; ?>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
