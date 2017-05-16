<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header class="author-info">
    <?php print $user_picture; ?>

    <?php if($display_submitted): ?>
      <div class="metadata">
        <span class="author">
          <?php print t('Published by '); ?><?php print $name; ?>&nbsp;|&nbsp;
        </span>
        <span class="publication-date">
          <?php print $created; ?>
        </span>

        <?php if(isset($content['field_categories'])): ?>
          <div class="categorization nexus-inline">
            <span><?php print t("in"); ?></span>
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
      </div>
    <?php endif; ?>
  </header>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['field_valora_el_recurso']);
      hide($content['links']);
      print render($content);
    ?>
  </div>

  <?php // Print rest of fields. ?>
  <?php print render($content['comments']); ?>
</article>
