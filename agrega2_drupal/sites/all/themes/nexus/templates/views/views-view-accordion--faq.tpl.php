<?php
/**
 * @file
 * Displays the items of the accordion.
 *
 * @ingroup views_templates
 *
 * Note that the accordion NEEDS <?php print $row ?> to be wrapped by an
 * element, or it will hide all fields on all rows under the first field.
 *
 * Also, if you use field grouping and use the headers of the groups as the
 * accordion headers, these NEED to be inside h3 tags exactly as below
 * (though you can add classes).
 *
 * The current div wraping each row gets two css classes, which should be
 * enough for most cases:
 *     "views-accordion-item"
 *      and a unique per row class like item-0
 */

?>
<?php if (!empty($title)): ?>
  <h3 class="<?php print $view_accordion_id; ?>">
    <?php print $title; ?>
  </h3>
<?php endif; ?>
<?php if ($use_group_header): ?><div><?php endif; ?>
<?php foreach ($faq_results as $id => $result): ?>
  <div class="<?php print $classes_array[$id]; ?>" <?php print $attributes_array[$id]; ?>>
    <div class="views-field views-field-title views-accordion-header">
      <span class="field-content">
        <span class="faq-title"><?php print $result['title']; ?></span>
        <span class="faq-author"> <?php print t('by'); ?> <?php print $result['author']; ?></span>
        <span class="faq-post-date"> | <?php print $result['post_date']; ?></span>
        <span class="faq-num-comments"><span id="faq-num-comments-<?php print $result['nid']; ?>"><?php print $result['num_comments']; ?></span><span> <?php print t('Answers'); ?></span></span>
      </span>
    </div>
    <div class="views-field views-field-body">
      <div class="field-content">
        <?php print $result['body']; ?>
      </div>
    </div>
    <?php if (!empty($result['edit_link'])): ?>
      <div class="edit-link">
        <?php print $result['edit_link']; ?>
      </div>
    <?php endif; ?>
    <div class="answers-results">
      <span id="answer-result-<?php print $result['nid']; ?>"><?php print t('Answers'); ?></span>
      <?php print $result['answers']; ?>
    </div>
    <div class="answer-question">
      <span id="answer-message-<?php print $result['nid']; ?>"></span>
      <?php if (!empty($result['reply'])): ?>
        <h2><?php print t('Answer'); ?></h2>
        <?php print $result['reply']; ?>
      <?php endif; ?>
    </div>
  </div>
<?php endforeach; ?>
<?php if ($use_group_header): ?></div><?php endif; ?>
