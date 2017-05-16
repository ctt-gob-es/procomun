<?php if(!$page): ?>
  <div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
<?php endif; ?>
  <?php if(!$page): ?>
    <header>
  <?php endif; ?>
    <?php if($display_submitted): ?>
    <h4 class="title" <?php print $title_attributes; ?>>
      <?php print l($title, 'node/' . $node->nid, array('absolute' => TRUE)); ?>
    </h4>
    <ul class="meta clearfix submitted">
       <li class="published">
        <?php $p = t('@type', array('@type' => $node_type_label)) .' '. t('@published by:', array('@published' => isset($content['shared_text']) ? render($content['shared_text']) : t('published'))) . ' ' . $name .' | '. t('@Posted', array('@Posted' => isset($content['shared_text']) ? render($content['shared_text']) : t('Posted'))). ' ' . t('@time ago', array('@time' => $time_ago));
          if(!empty($content['og_group_ref'])){ $p.= ' | '. t('In') .' '. trim(strip_tags(render($content['og_group_ref']),'<a>'));}
          echo $p;
         ?>
      </li>
    </ul>
    <?php endif; ?>
  <?php if(!$page): ?>
    </header>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['title']);
      hide($content['comments']);
      hide($content['links']);

      // We must render field_valora_el_recurso as Link:
      hide($content['field_valora_el_recurso']);
      hide($content['service_links']);
      print render($content);
    ?>
  </div>

  

  <?php print render($content['comments']); ?>

<?php if(!$page): ?>
  </div>
<?php endif; ?>
