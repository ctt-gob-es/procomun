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
          <span class="info-community">
          <span class="author">
            <?php print t('Community'); ?>
            <?php print t('@published by:', array('@published' => isset($content['shared_text']) ? render($content['shared_text']) : t('created'))); ?>
          <?php print $name; ?>
        </span>
          <span class="date"><?php print $created; ?></span>
        <?php if (isset($content['communityType'])) :?>
          <?php print render($content['communityType']); ?>
        <?php endif;?>
        </span>
      </div>
      <?php endif; ?>





  <?php if(!$page): ?>
    </header>
  <?php endif; ?>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
      if (isset($content['newsletter-subscribe-link'])) :
        hide($content['newsletter-subscribe-link']);
      endif;
    ?>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['links']);
      hide($content['title_field']);
      hide($content['membersCount']);
      print render($content);
    ?>
  </div>
  <footer>
    <ul class="social">
      <li>
        <?php
          print render($content['links']);
          if (isset($content['newsletter-subscribe-link'])) :
            print render($content['newsletter-subscribe-link']);
          endif;
        ?>
      </li>
    </ul>
  </footer>

  <?php print render($content['comments']); ?>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
