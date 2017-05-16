<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php if(isset($edit_link) || isset($clone_link)): ?>
    <div class="button-container">
      <?php if(isset($edit_link)): ?>
        <span class="create-link"><?php print $edit_link; ?></span>
      <?php endif; ?>

      <?php if(isset($clone_link)): ?>
        <span class="clone-link"><?php print $clone_link; ?></span>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if(isset($content['title_field'])): ?>
    <h3><?php echo render($content['title_field']); ?></h3>
  <?php endif; ?>
  <header class="author-info">
    <div class="user-picture">
      <?php if (!empty($content['user_picture'])): ?>
        <?php print render($content['user_picture']); ?>
      <?php endif; ?>
    </div>
    <span>
      <span class="author">
        <?php print $name; ?>&nbsp;|&nbsp;
      </span>

      <span class="publication-date">
        <?php print $created ?>
      </span>

      <?php if(!empty($content['og_group_ref'])): ?>
        <div class="publication-groups">
          <span><?php print t('In the groups'); ?></span>
          <?php print render($content['og_group_ref']); ?>
        </div>
      <?php endif;?>
    </span>
  </header>

  <div class="content"<?php print $content_attributes; ?>>
    <div class="tags">
      <?php print render($content['field_learning_context']); ?>
      <?php print render($content['field_knowledge_area']); ?>
    </div>
    <?php
    hide($content['title_field']);
    hide($content['field_learning_context']);
    hide($content['field_knowledge_area']);
    hide($content['field_itinerary_content']);
    hide($content['field_interest_content']);
    hide($content['field_base_itinerary']);
    hide($content['service_links']);
    hide($content['og_share']);
    hide($content['og_group_ref']);
    hide($content['comments']);
    print render($content);
    ?>
  </div>

    <footer>
      <div class="social-networks-options section inline-elements">
        <?php print render($content['og_share']); ?>
        <?php if(!empty($content['links'])): ?>
          <?php
          // Print rendered service links to get the one we modified on entity view.
          print render($service_links_rendered);
          ?>
        <?php endif; ?>
      </div>
    </footer>
</article>
