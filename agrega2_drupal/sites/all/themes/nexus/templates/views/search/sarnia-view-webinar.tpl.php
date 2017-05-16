<?php
/**
 * Webinar row template.
 */
?>
<li class="search-result webinar-result clearfix">
  <div class="col-sm-12">
    <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>

  <div class="col-sm-2">
    <div class="image"><?php print $properties['webinarPicture']; ?></div>
  </div>

  <div class="col-sm-10">
    <?php if (!empty($properties['descriptionStr'])): ?>
      <div class="description"><?php print $properties['descriptionStr']; ?></div>
    <?php endif; ?>

    <?php if (!empty($properties['keywords'])): ?>
      <div class="extra-info">
        <div class="tags">
          <?php if (isset($properties['keywords'])): ?>
            <?php foreach ($properties['keywords'] as $keyword): ?>
              <?php print $keyword; ?>
            <?php endforeach; ?>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!empty($properties['knowledgeAreaTags']) || !empty($properties['learningContextTags']) || !empty($properties['resourceTypeTags']) ): ?>
      <table class="extra-table">
        <?php if (!empty($properties['knowledgeAreaTags'])): ?>
          <tr class="row">
            <td class="label col-sm-3"><?php print t('Knowledge area'); ?></td>
            <td class="content col-sm-9">
              <div class="facets">
                <?php if (isset($properties['knowledgeAreaTags'])): ?>
                  <?php print implode(', ', $properties['knowledgeAreaTags']); ?>
                <?php endif; ?>
              </div>
            </td>
          </tr>
        <?php endif; ?>
        <?php if (!empty($properties['learningContextTags'])): ?>
          <tr class="row">
            <td class="label col-sm-3"><?php print t('Learning context'); ?></td>
            <td class="content col-sm-9">
              <div class="facets">
                <?php if (isset($properties['learningContextTags'])): ?>
                  <?php print implode(', ', $properties['learningContextTags']); ?>
                <?php endif; ?>
              </div>
            </td>
          </tr>
        <?php endif; ?>
      </table>
    <?php endif; ?>
  </div>

  <?php /** Block social **/ ?>
  <?php if (user_is_logged_in() && isset($properties['idDrupal'])): ?>
    <ul class="social col-sm-12">
      <li class="social-like">
        <?php print flag_create_link('like', $properties['idDrupal']); ?>
      </li>

      <li class="social-comment comment-link">
        <?php print l(t('Comment'), 'comment/new/' . $properties['idDrupal']); ?>
      </li>

      <li class="social-favorite">
        <?php print flag_create_link('favorite', $properties['idDrupal']); ?>
      </li>
    </ul>
  <?php endif; ?>
</li>
