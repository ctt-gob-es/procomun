<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>

<?php global $language; ?>
<div class="<?php print $classes; ?>">
  <div class="ag-filter-exposed">
    <?php if (isset($total_items) && $total_items > 0): ?>
      <div class="result">
        <?php print t('Showing results !first_result_position to !last_result_position from a total of !total_items.', array('!first_result_position' => $first_result_position, '!last_result_position' => $last_result_position, '!total_items' => $total_items)); ?>
      </div>
    <?php endif; ?>
    <div class="text"><span><?php print t('Filters applied'); ?></span>
      <div class="clear-all-filter">
        <a href="/<?php print $language->language; ?>/ode-search?query=&type=<?php print $_GET['type'] ?>"><?php print t('Clear all'); ?></a>
      </div>
      <div class="applied-filters"></div>
    </div>
  </div>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <div>
    <ul>
      <?php if (isset($output) && !empty($output)): ?>
        <?php print $output;?>
      <?php else: ?>
          <?php print t('No results found.'); ?>
      <?php endif; ?>
    </ul>
  </div>

  <!-- <?php //if ($rows): ?>
    <div class="view-content">
      <?php //print $rows; ?>
    </div>-
  <?php //elseif ($empty): ?>
    <div class="view-empty">
      <?php //print $empty; ?>
    </div>-->
  <?php //endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
