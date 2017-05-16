<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>
  <?php if(!$page): ?>
    <header>
  <?php endif; ?>
    <?php if($display_submitted): ?>
      <ul class="meta clearfix submitted author-info">
        <li class="user-picture">
          <?php $user_picture = DrupalToolKit::getUserData($node->uid, array('picture'))->uri ?>
          <?php if (!empty($user_picture)): ?>
            <?php print theme('image_style', array('style_name' => 'avatar', 'path' => $user_picture)); ?>
          <?php else: ?>
            <?php $default_image = variable_get('user_picture_default', ''); ?>
            <?php print theme('image_style', array('style_name' => 'avatar', 'path' => $default_image,)); ?>
          <?php endif; ?>
        </li>

        <li class="published">
          <span>
            <strong><?php print t($node_type_label); ?></strong>
            <?php print t('@published by:', array('@published' => isset($content['shared_text']) ? render($content['shared_text']) : t('published'))); ?>
          </span>
          <?php print $name; ?>
        </li>

        <li class="date pull-right">
          <span><?php print t('@Posted', array('@Posted' => isset($content['shared_text']) ? render($content['shared_text']) : t('Posted'))); ?></span>
          <?php print t('@time ago', array('@time' => $time_ago)); ?>
        </li>

        <?php if(!empty($content['og_group_ref'])): ?>
          <li class="posted">
            <?php print t('In'); ?>
            <?php print render($content['og_group_ref']); ?>
          </li>
        <?php endif;?>
      </ul>
    <?php endif; ?>
  <?php if(!$page): ?>
    </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      // We must render field_valora_el_recurso as Link:
      hide($content['field_valora_el_recurso']);
      print render($content);
    ?>
  </div>

  <footer>
    <?php if( ($content['links']['follow_flag']) || ($content['links']) || ($content['field_valora_el_recurso'])   ): ?>
    <ul class="social">
      <li>
        <?php
          print render($content['links']['follow_flag']);
          print render($content['links']);
          print render($content['field_valora_el_recurso']);
        ?>
      </li>
    </ul>
     <?php endif; ?>
  </footer>

  <?php print render($content['comments']); ?>
<?php if(!$page): ?>
  </article>
<?php endif; ?>
