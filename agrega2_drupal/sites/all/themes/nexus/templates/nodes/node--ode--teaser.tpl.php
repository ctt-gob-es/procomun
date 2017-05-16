<?php if(!$page): ?>
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>

  <?php if(!$page): ?>
    <header>
  <?php endif; ?>
    <?php if (isset($certified)) : ?>
      <div class="certificate-ode">
        <?php print $certified; ?>
      </div>
    <?php endif; ?>
    <div class="field field-name-title-field field-type-text field-label-hidden">
      <div class="field-items">
        <h2>
          <?php print l($title, 'ode/view/' . $solr_id, array('class' => 'title')); ?>
        </h2>
      </div>
    </div>

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
<!--      <?php /*if(!empty($content['og_group_ref'])): */?>
        <span class="posted">
        <strong><?php /*print t('In'); */?></strong>
          <?php /*print render($content['og_group_ref']); */?>
        </span>
      --><?php /*endif;*/?>
    </div>
    <?php endif; ?>
  <?php if(!$page): ?>
    </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['title_field']);
      hide($content['comments']);
      hide($content['links']);
      // We must render field_valora_el_recurso as Link:
      hide($content['field_valora_el_recurso']);
      hide($content['service_links']);
      hide($content['og_share']);
      hide($content['og_group_ref']);
      print render($content);
    ?>
  </div>

  <footer>
    <div class="social-networks-options section inline-elements">
      <?php print render($content['og_share']); ?>
      <div id="social-voting"><?php print render($content['field_valora_el_recurso']); ?></div>
      <?php print $rrss_teaser; ?>
    </div>
    <?php if( ($content['links']['follow_flag']['#markup']) || !empty($content['links']['comment']['#links']) ): ?>
    <ul class="social">
      <li>
        <?php
          print render($content['links']['follow_flag']);
          print render($content['links']);
        ?>
      </li>
    </ul>
    <?php endif; ?>
  </footer>

  <?php if (isset($comment_count) && $comment_count > 0): ?>
    <div class="timeline-comments">
      <?php if ($comment_count > 2): ?>
        <span class="see-more-comments">
          <?php print l(t('See more comments'), 'ode/view/' . $solr_id, array('class' => 'title', 'fragment' => 'comments')); ?>
        </span>
      <?php endif; ?>    
      <?php print $timeline_comments; ?>
    </div>
  <?php endif; ?>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
