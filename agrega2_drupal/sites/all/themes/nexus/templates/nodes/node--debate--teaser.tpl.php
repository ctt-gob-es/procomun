<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>

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
          <span class="author"><?php print $name; ?> | </span>
          <span class="date"><?php print $created; ?></span>
        </span>
        <span class="type"><?php print t($node_type_label); ?></span>
      </div>
      <!--        <?php /*if(!empty($content['og_group_ref'])): */?>
          <span class="posted">
            <strong><?php /*print t('In'); */?></strong>
            <?php /*print render($content['og_group_ref']); */?>
          </span>
        --><?php /*endif;*/?>
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
        if (isset($content['field_categories'])) {
          hide($content['field_categories']);
        }
        print render($content);
      ?>
    </div>

  <footer>
<!--    <div class="social-networks-options section inline-elements">
      <?php /*print render($content['og_share']); */?>
      <div id="social-voting"><?php /*print render($content['field_valora_el_recurso']); */?></div>
      <?php /*print render($rrss); */?>
    </div>-->
    <?php if( $total_answers ): ?>
    <ul class="social">
      <li>
        <span class="content-count"><?php print render($total_answers); ?></span>
      </li>
    </ul>
    <?php endif; ?>
  </footer>

  <?php if (isset($comment_count) && $comment_count > 0 && isset($timeline_comments) && !empty($timeline_comments)): ?>
    <div class="timeline-comments">
      <?php if ($comment_count > 2): ?>
        <span class="see-more-comments">
          <?php print l(t('See more comments'), 'node/' . $node->nid, array('class' => 'title', 'fragment' => 'comments')); ?>
        </span>
      <?php endif; ?>
      <?php print $timeline_comments; ?>
    </div>
  <?php endif; ?>

<?php if(!$page): ?>
  </article>
<?php endif; ?>
