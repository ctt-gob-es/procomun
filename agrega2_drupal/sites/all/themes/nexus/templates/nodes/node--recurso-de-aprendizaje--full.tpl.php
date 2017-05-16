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
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header>
    <?php print render($title_prefix); ?>

    <?php if(!$page): ?>
      <h2 class="title" <?php print $title_attributes; ?>>
        <?php print l($title, 'node/' . $node->nid); ?>
      </h2>
    <?php endif; ?>

    <?php print render($title_suffix); ?>

    <?php if($display_submitted): ?>
      <ul class="meta clearfix">
        <li class="meta-author">
          <?php print render($user_picture); ?>
          <div class="meta-author-name">
            <?php print t('Shared by');?>
            <?php print $name; ?>
          </div>
          <?php print $date; ?>
        </li>

        <li class="meta-visits">
          <div class="meta-visits-label"><?php print t('Page views'); ?></div>
          <div class="meta-visits-value">
            <?php print (!empty($page_views) ? $page_views : '0'); ?>
          </div>
        </li>

        <li class="meta-comments">
          <div class="meta-comments-label"><?php print t('Comments');?></div>
          <div class="meta-comments-value"><?php print $comment_count;?></div>
        </li>

        <li class="meta-rating">
          <div class="meta-rating-label"><?php print t('Rating');?></div>
          <div class="meta-rating-value">
            <?php print (!empty($fivestar_average) ? $fivestar_average : '0'); ?>
          </div>
        </li>

        <li class="meta-likes">
          <div class="meta-likes-value">
            <?php print (!empty($like_count) ? '+' . $like_count : '0'); ?>
          </div>
        </li>
      </ul>
    <?php endif; ?>
  </header>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // Hide comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      hide($content['field_valora_el_recurso']);
    ?>

    <?php print render($content['field_imagen_miniatura']);?>

    <?php if(isset($content['og_share']) || isset($content['service_links'])): ?>
      <div class="node-top-share-links">
        <?php print render($content['og_share']);?>
        <?php print render($content['service_links']);?>
      </div>
    <?php endif; ?>

    <?php print render($content);?>
  </div>

  <footer class="clearfix">
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
</article>
