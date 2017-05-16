<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

  <?php if(!$page): ?>
    <header>
  <?php endif; ?>

    <?php if($clone_link): ?>
      <div class="clone-lp"><?php print $clone_link; ?></div>
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
      hide($content['og_share']);
      hide($content['og_group_ref']);
      print render($content);
    ?>
  </div>

    <footer>
      <div class="social-networks-options section inline-elements">
        <?php print render($content['og_share']); ?>
        <?php
        // Print rendered service links to get the one we modified on entity view.
        print render($service_links_rendered);
        ?>
      </div>
    </footer>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
