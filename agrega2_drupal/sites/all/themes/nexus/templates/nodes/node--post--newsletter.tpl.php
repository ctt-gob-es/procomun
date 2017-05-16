<?php if(!$page): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>
  <?php if(!$page): ?>
    <?php if(isset($miniatura_newsletter)): ?>
      <div class="miniatura-newsletter"><?php print $miniatura_newsletter; ?></div>
    <?php endif; ?>
    <header>
  <?php endif; ?>
    <?php if($display_submitted): ?>
    <h4 class="title" <?php print $title_attributes; ?>>
      <?php print l($title, 'node/' . $node->nid, array('absolute' => TRUE, 'attributes' => array('style' => 'color: #1A3752'))); ?>
    </h4>
    <ul class="meta clearfix submitted">
       <li class="published">
         <?php print t('@type', array('@type' => t($node_type_label))); ?>
      </li>
    </ul>
    <?php endif; ?>
  <?php if(!$page): ?>
    </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['title_field']);
      hide($content['links']);
      // We must render field_valora_el_recurso as Link:
      hide($content['field_valora_el_recurso']);
      print render($content);
    ?>
  </div>


  <?php print render($content['comments']); ?>

<?php if(!$page): ?>
  </div>
<?php endif; ?>
