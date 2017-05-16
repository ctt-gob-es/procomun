<?php /** Template Row for ODE **/ ?>
<?php
/**
 * User row template.
 */
?>
<li class="search-result learning-resources-result clearfix">
  <div class="col-sm-12">
    <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>
  <div class="col-sm-2">
    <div class="image"><?php print $properties['generalPicture']; ?></div>
  </div>

  <div class="col-sm-10">
    <?php if (!empty($properties['generalDescriptionStr'])): ?>
      <div class="description">
        <?php if (!empty($properties['authorStr']) || !empty($properties['publicationDate'])): ?>
          <div class="metadata">
            <?php if (!empty($properties['authorStr'])): ?>
              <?php $properties['type'] = explode( '_', $properties['type']); ?>
              <span class="publisher">
                <?php print t('Published by'); ?>
                <span class="author"><?php print $properties['authorStr']; ?></span>
              </span>
            <?php endif; ?>

            <?php if (!empty($properties['publicationDate'])): ?>
              <span class="publication-date">
              <?php print t('on'); ?>
                <?php $date = strtotime($properties['publicationDate']); ?>
                <span class="date"><?php print date('d.m.Y', $date); ?></span>
              </span>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php print $properties['generalDescriptionStr']; ?>
      </div>
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

      <table class="extra-table">
        <?php if (!empty($properties['typeResource'])): ?>
          <tr class="row">
            <td class="label col-sm-3"><?php print t('RESOURCE TYPE'); ?></td>
            <td class="content col-sm-9"><?php print $properties['typeResource']; ?></td>
          </tr>
        <?php endif; ?>

        <?php if (!empty($properties['formatResource'])): ?>
          <tr class="row">
            <td class="label col-sm-3"><?php print t('FORMAT'); ?></td>
            <td class="content col-sm-9"><?php print $properties['formatResource']; ?></td>
          </tr>
        <?php endif; ?>
      </table>
  </div>

  <?php /** Block social **/ ?>
  <?php if (user_is_logged_in() && isset($properties['idDrupal'])): ?>
    <ul class="social col-sm-12">
      <li class="social-like">
        <?php if (isset($properties['idDrupal'])): ?>
          <?php print flag_create_link('like', $properties['idDrupal']); ?>
        <?php endif; ?>
      </li>

      <?php if (user_is_logged_in() && isset($properties['idDrupal'])): ?>
        <li class="social-comment comment-link">
          <?php print l(t('Comment'), 'comment/new/' . $properties['idDrupal']); ?>
        </li>
      <?php endif; ?>

      <li class="social-favorite">
        <?php if (isset($properties['idDrupal'])): ?>
          <?php print flag_create_link('favorite', $properties['idDrupal']); ?>
        <?php endif; ?>
      </li>
    </ul>
  <?php endif; ?>
</li>
