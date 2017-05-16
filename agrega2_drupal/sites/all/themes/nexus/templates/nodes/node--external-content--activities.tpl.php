<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

  <?php if(!$page): ?>
    <header>
  <?php endif; ?>
    <span class="title-<?php print $type; ?>"><?php print render($content['title_field']); ?></span>
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

  <footer>
    <?php if( ($content['links']['follow_flag']) || ($content['links']) || ($content['field_valora_el_recurso'])   ): ?>
    <ul class="social">
      <li>
        <?php print render($content['links']['comment']); ?>
      </li>
    </ul>
    <?php endif; ?>
  </footer>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
