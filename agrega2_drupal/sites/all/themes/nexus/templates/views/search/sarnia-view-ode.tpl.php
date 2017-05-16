<?php /** Template Row for ODE **/ ?>
<?php
/**
 * User row template.
 */
?>
<li class="search-result ode-result clearfix<?php if (!empty($properties['certified'])): ?> certified<?php endif; ?>">
  <div class="col-sm-12">
      <h2 class="title"><?php print $properties['titleStr']; ?></h2>
  </div>
  <div class="col-sm-2">
    <div class="image">
      <?php if (!empty($properties['preview'])): ?>
        <?php if (strpos($properties['preview'], '/sites/default/files/') === 0): ?>
          <img src="<?php print $properties['preview']; ?>"/>
        <?php else: ?>
          <img src="http://<?php print $properties['preview']; ?>"/>
        <?php endif; ?>
      <?php else: ?>
        <?php print $properties['default_image']; ?>
      <?php endif; ?>
    </div>
  </div>

  <div class="col-sm-10">
    <?php if (!empty($properties['certified'])): ?>
      <div class="certificate-ode"><?php print $properties['certified']; ?></div>
    <?php endif; ?>

    <?php if (!empty($properties['generalDescriptionStr'])): ?>
      <div class="description">
        <?php if (!empty($properties['authorStr']) || !empty($properties['publicationDate'])): ?>
          <div class="metadata">
            <?php if (!empty($properties['authorStr'])): ?>
              <span class="publisher">
                <span class="author"><?php print $properties['authorStr']; ?></span>
              </span>
            <?php endif; ?>

            <?php if (!empty($properties['publicationDate'])): ?>
              <span class="publication-date">
                <?php $date = strtotime($properties['publicationDate']); ?>
                <span class="date"><?php print date('d/m/Y', $date); ?></span>
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

    <?php if (!empty($properties['knowledgeAreaTags']) || !empty($properties['learningContextTags']) || !empty($properties['resourceTypeTags']) ): ?>
      <table class="extra-table">
        <?php if (!empty($properties['knowledgeAreaTags'])): ?>
          <tr class="row">
            <td class="label col-sm-3"><?php print t('Knowledge area'); ?></td>
            <td class="content col-sm-9">
              <div class="facets">
                <?php if (isset($properties['knowledgeAreaTags'])): ?>
                  <?php print implode(', ', $properties['knowledgeAreaTags']);?>
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
        <?php if (!empty($properties['resourceTypeTags'])): ?>
          <tr class="row">
            <td class="label col-sm-3"><?php print t('Resource type'); ?></td>
            <td class="content col-sm-9">
              <div class="facets">
                <?php if (isset($properties['resourceTypeTags'])): ?>
                  <?php print implode(', ', $properties['resourceTypeTags']); ?>
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
      <?php if (ode_user_flag_access('flag', 'like')): ?>
      <li id="<?php print 'ode-' . $properties['id']; ?>" class="social-like">
        <?php print flag_create_link('like', $properties['idDrupal']); ?>
      </li>
      <?php endif; ?>

      <li class="social-comment comment-link">
        <?php print l(t('Comment'), 'ode/comment/new/' . $properties['id']); ?>
      </li>

      <?php if (ode_user_flag_access('flag', 'favorite')): ?>
      <li id="<?php print 'ode-' . $properties['id']; ?>" class="social-favorite">
        <?php print flag_create_link('favorite', $properties['idDrupal']); ?>
      </li>
      <?php endif; ?>
    </ul>
  <?php endif; ?>
</li>
