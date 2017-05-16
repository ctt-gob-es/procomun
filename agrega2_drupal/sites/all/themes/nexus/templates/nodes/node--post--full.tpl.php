<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header class="author-info">
    <?php if (!empty($user_picture)): ?>
      <?php print $user_picture; ?>
    <?php endif; ?>

    <?php if ($display_submitted): ?>
      <span>
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

        <?php if(!empty($content['og_group_ref'])): ?>
          <div class="publication-groups">
            <span><?php print t('In the groups'); ?></span>
            <?php print render($content['og_group_ref']); ?>
          </div>
        <?php endif;?>

        <?php if(isset($content['field_original_user'])): ?>
          <div class="inline">
            <?php hide($content['field_original_user']); ?>
          </div>
        <?php endif; ?>
      </span>

      <span class="content-count">
        <?php print format_plural($comment_count, 'response', 'responses'); ?>
        <a href="#comments">
          <span><?php print render($comment_count); ?></span>
        </a>
      </span>

    <?php endif; ?>
  </header>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['field_valora_el_recurso']);
      hide($content['service_links']);
      hide($content['links']);
      hide($content['og_share']);
      print render($content);
    ?>
  </div>

  <?php if(!empty($content['links'])): ?>
    <footer>
      <div class="social-networks-options section inline-elements">
        <?php
          print render($content['og_share']);
          // Print rendered service links to get the one we modified on entity view.
          print render($service_links_rendered);
        ?>
      </div>
      <ul class="social">
        <li>
          <?php
            print render($content['links']);
            print render($content['links']['follow_flag']);
            print render($content['field_valora_el_recurso']);
          ?>
        </li>
      </ul>
    </footer>
  <?php endif; ?>

  <?php // Print rest of fields. ?>
  <?php print render($content['comments']); ?>
</article>
