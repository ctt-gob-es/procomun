<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

<?php if(!$page): ?>
  <header>
<?php endif; ?>

  <?php print render($content['title_field']); ?>

    <?php if($display_submitted): ?>
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
    <?php endif; ?>

<?php if(!$page): ?>
  </header>
<?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
    // Hide comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['og_group_ref']);
    // We must render field_valora_el_recurso as Link:
    hide($content['field_valora_el_recurso']);
    print render($content);
    ?>
  </div>

  <?php print render($content['comments']); ?>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
