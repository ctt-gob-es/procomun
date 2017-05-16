<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

  <?php if(!$page): ?>
    <header>
  <?php endif; ?>
    <span class="title-<?php print $type; ?>"><?php print render($content['title_field']); ?></span>
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
          <span class="author"><?php print t('Published by') . ' ' . $name; ?> | </span>
          <span class="date"><?php print $created; ?></span>
          <?php if(!empty($content['og_group_ref'])): ?>
            <span class="posted">
              <?php print t('In groups'); ?>
              <?php print render($content['og_group_ref']); ?>
            </span>
          <?php endif; ?>
        </span>
        <span class="type"><?php print t($node_type_label); ?></span>
      </div>
  <?php if(!$page): ?>
    </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
    // Hide all content except body.
    hide($content['user_comments']);
    print render($content);
    ?>
  </div>
<?php if(!$page): ?>
  </article>
<?php endif; ?>
