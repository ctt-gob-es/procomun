<?php /** Template Row for ODE **/ ?>
<div class="detail-ode">
  <div class="detail-content col-md-12">
    <?php if (isset($node->title)): ?>
      <div class="detail-title">
        <h1><?php print $node->title; ?></h1>
      </div>
    <?php endif; ?>
    <?php if (!empty($properties['generalKeywordStr'])): ?>
      <div class="detail-ode-keyword clearfix inner-section">
        <?php foreach ($properties['generalKeywordStr'] as $key => $value): ?>
          <?php $options = array('query' => array(
            'type' => 'LEARNING_RESOURCE',
            'f[0]' => 'generalKeywordStr:"' . $value . '"',)); ?>
          <?php print l(t($value), 'ode-search' , $options); ?>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>

    <?php // Added ode viewer widget ?>
    <div class="screenViewer">
      <?php print $ode_widget; ?>
    </div>
    <?php // Report incident by email if the resource viewer is broken. ?>
    <div class="email-error-report">
      <a href="mailto:<?php print str_rot13(EMAIL_ERROR_CONTACT);?>" title="<?php print t('Report incident with resource viewer') ?>" class="contact_email contact_email-processed"><?php print t('Report incident with resource viewer') ?></a>
    </div>
    <?php if (!empty($properties['authorStr']) || !empty($properties['publicationDate_processed'])): ?>
      <div class="detail-ode-info inner-section">
        <div class="media-object">
          <div class="img right stats-info">
            <div class="pageviews-wrapper">
              <div class="title"><?php print t('Page views'); ?></div>
              <div class="value"><?php print $page_views ?></div>
            </div>

            <div class="comments-wrapper">
              <div class="title"><?php print t('Comments'); ?></div>
              <?php if (isset($node->comment_count)): ?>
                  <div class="value"><?php print $node->comment_count; ?></div>
              <?php else: ?>
                  <div class="value"><?php print '0'; ?></div>
              <?php endif; ?>
            </div>

            <div class="voting-wrapper">
              <div class="title"><?php print t('Number of votes'); ?></div>
              <div class="value"><?php print (!empty($properties['numbers_votes']) ? $properties['numbers_votes'] : '0'); ?></div>
            </div>

            <div class="like-number">
              <div class="value"><div class="ico ico-likes"></div><span class="like-number-value"><?php print $like_count; ?></span></div>
            </div>

            <?php if (!empty($certified)) : ?>
            <div class="certified">
              <div class="value"><?php print $certified; ?></div>
            </div>
            <?php endif; ?>
          </div>

          <div class="body">
            <?php /* Publication info */ ?>
            <div class="info-author left">
              <div class="img left ode-picture">
                <?php // Thumbnail. ?>
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

              <?php if (!empty($properties['authorStr']) || !empty($properties['publicationDate_processed'])): ?>
                <div class="body">
                  <?php if (!empty($properties['authorStr'])): ?>
                    <div class="detail-ode-author-date">
                      <div><?php print t('Published by');?></div>
                      <?php if (is_array($properties['authorStr'])): ?>
                        <span><?php print $properties['authorStr'][0]; ?></span>
                      <?php else: ?>
                        <span class="author"><?php print $properties['authorStr']; ?></span>
                      <?php endif; ?>
                      <?php if (!empty($properties['publicationDate_processed'])): ?>
                        <span class="detail-ode-publish"><?php print $properties['publicationDate_processed']; ?></span>
                      <?php endif; ?>
                    </div>
                  <?php endif; ?>
                </div>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <div class="social-networks-options section inline-elements">
      <?php if (user_is_logged_in()): ?>
        <div class="share-local-networks">
              <?php if (isset($node->nid)): ?>
                <?php print l(t('Share with my communities'), 'og_share/share/'. $node->nid . '/node'); ?>
              <?php else: ?>
                <?php print l(t('Share with my communities'), 'ode/og_share/share/'. $properties['id']); ?>
              <?php endif; ?>
          </div>
      <?php endif; ?>

      <?php if (isset($node->nid)): ?>
        <div id="social-voting">
          <?php $fivestar_element = field_view_field('node', $node, 'field_valora_el_recurso', 'basic'); ?>
          <?php print render($fivestar_element); ?>
        </div>
      <?php endif; ?>

      <?php if (isset($rrss) & !empty($rrss)): ?>
        <?php print render($rrss); ?>
      <?php endif; ?>
    </div>



    <?php /** Block social **/ ?>
    <?php if (user_is_logged_in()): ?>
    <ul class="social-block social social-links space-l-inline-elements section">
      <?php if (ode_user_flag_access('flag', 'like')): ?>
        <li id="<?php print 'ode-' . $properties['id']; ?>" class="social-like">
          <?php if (isset($node->nid)): ?>
            <?php print flag_create_link('like', $node->nid); ?>
          <?php else: ?>
            <span class="social-replace">
                <?php print l(t('Like'), 'ode/flag/flag/like/' . $properties['id'] . '/nojs', array('attributes' => array('class' => array('use-ajax')))); ?>
            </span>
          <?php endif; ?>
        </li>
      <?php endif; ?>

      <?php if (isset($node->nid)): ?>
          <li class="social-comment"><?php print l(t('Comment'), 'comment/new/' . $node->nid); ?></li>
      <?php else: ?>
          <li class="social-comment"><?php print l(t('Comment'), 'ode/comment/new/' . $properties['id']); ?></li>
      <?php endif; ?>

      <?php if (ode_user_flag_access('flag', 'favorite')): ?>
        <li id="<?php print 'ode-' . $properties['id']; ?>" class="social-favorite">
          <?php if (isset($node->nid)): ?>
            <?php print flag_create_link('favorite', $node->nid); ?>
          <?php else: ?>
            <span class="social-replace">
                <?php print l(t('Favorite'), 'ode/flag/flag/favorite/' . $properties['id'] . '/nojs', array('attributes' => array('class' => array('use-ajax')))); ?>
            </span>
          <?php endif; ?>
        </li>
      <?php endif; ?>

      <?php if (ode_user_flag_access('flag', 'abuse_node')): ?>
        <li id="<?php print 'ode-' . $properties['id']; ?>" class="flag-abuse_node">
          <?php if (isset($node->nid)): ?>
            <?php print flag_create_link('abuse_node', $node->nid); ?>
          <?php else: ?>
            <span class="flag-abuse-comment">
                <?php print l(t('Flag as offensive'), 'flag/confirm/flag/abuse_node/' . $properties['id']); ?>
            </span>
          <?php endif; ?>
        </li>
      <?php endif; ?>

      <?php if (!empty($novelty_link)): ?>
      <li id="<?php print 'ode-' . $properties['id']; ?>" class="flag-novelty">
        <?php print $novelty_link; ?>
      </li>
      <?php endif; ?>

      <?php if (isset($node->nid) && !empty($certificate_link)): ?>
        <li id="certificate-ode">
          <?php print $certificate_link; ?>
        </li>
      <?php endif; ?>

      <?php if (!empty($delete_link)): ?>
        <li id="delete-ode">
          <?php print $delete_link; ?>
        </li>
      <?php endif; ?>

    </ul>
    <?php endif; ?>
  </div>
  <div class="wrapper-ode col-md-9 center">
    <span id="fullscreen-button" class="fullscreen-button"></span>
    <?php /** Summary **/ ?>
    <div class="summary inner-section">
      <h2 class="title"><?php print t('Summary'); ?></h2>
      <div class="content">
        <?php if (!empty($properties['generalDescriptionStr'])): ?>
          <div class="detail-ode-description-wrapper">
            <div class="detail-ode-description">
              <?php foreach (array_keys($properties['generalDescriptionStr']) as $elem): ?>
                <p><?php print t($properties['generalDescriptionStr'][$elem]); ?></p>
              <?php endforeach; ?>
            </div>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['educationalDescriptionStr'])): ?>
          <div class="detail-ode-educational-description-wrapper">
            <label><?php print t('Educational orientation'); ?></label>
            <div class="detail-ode-educational-description">
              <?php foreach (array_keys($properties['educationalDescriptionStr']) as $elem): ?>
                <p><?php print t($properties['educationalDescriptionStr'][$elem]); ?></p>
              <?php endforeach; ?>
            </div>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['rightsCopyrightAndOtherRestrictionsStr']) && strpos($properties['rightsCopyrightAndOtherRestrictionsStr'], 'Creative Commons') !== 0): ?>
          <div class="detail-ode-license-wrapper">
            <label><?php print t('License'); ?></label>
            <div class="detail-ode-license">
              <div><?php print t($properties['rightsCopyrightAndOtherRestrictionsStr']); ?></div>
            </div>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['rightsAccessStr'])): ?>
          <div class="detail-ode-license-type-wrapper">
            <label><?php print t('License type'); ?></label>
            <div class="detail-ode-license-type">
              <div><?php print t($properties['rightsAccessStr']); ?></div>
            </div>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['rightsDescriptionStr'])): ?>
          <div class="detail-ode-license-description-wrapper">
            <?php if (is_array($properties['rightsDescriptionStr'])): ?>
              <?php foreach (array_keys($properties['rightsDescriptionStr']) as $elem): ?>
                <div><?php print t($properties['rightsDescriptionStr'][$elem]); ?></div>
              <?php endforeach; ?>
            <?php else: ?>
              <div><?php print t($properties['rightsDescriptionStr']); ?></div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['lifecycleAuthors'])): ?>
          <div class="detail-ode-authors-wrapper">
            <label><?php print t('Authors'); ?></label>
            <div class="detail-ode-authors">
              <?php foreach ($properties['lifecycleAuthors'] as $elem): ?>
                <div>
                  <span><?php print $elem; ?></span>
                </div>
              <?php endforeach; ?>
            </div>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['educationalIntendedEndUserRoleStr'])): ?>
          <div class="detail-ode-enduser-wrapper">
            <label><?php print t('End user'); ?></label>
            <div class="detail-ode-enduser">
              <?php foreach (array_keys($properties['educationalIntendedEndUserRoleStr']) as $elem): ?>
                <span><?php print t($properties['educationalIntendedEndUserRoleStr'][$elem]); ?></span>
              <?php endforeach; ?>
            </div>
          </div>
        <?php endif; ?>

        <?php if (!empty($properties['educationalContextStr'])): ?>
          <div class="detail-ode-context-wrapper">
            <label><?php print t('Educative context'); ?></label>
            <div class="detail-ode-context">
              <?php foreach (array_keys($properties['educationalContextStr']) as $elem): ?>
                <span><?php print t($properties['educationalContextStr'][$elem]); ?></span>
              <?php endforeach; ?>
            </div>
          </div>
        <?php endif; ?>
      </div>
    </div>

    <?php /** Collapsable blocks **/ ?>
    <div class="panel-group" id="accordion">
      <div class="panel collapsible">
        <div class="panel-heading highlight-header">
          <div class="panel-title">
            <h2><?php print t('General'); ?></h2>
            <span class="accordion-collapse-icon collapsed"><div class="ico ico-mas"></div></span>
          </div>
        </div>
        <div id="general-content" class="panel-collapse collapse">
          <div class="panel-body">
            <?php if (!empty($properties['generalKeywordStr'])): ?>
              <div class="detail-ode-keyword-wrapper">
                <label><?php print t('Keywords'); ?></label>
                <div class="detail-ode-keyword clearfix">
                  <?php foreach ($properties['generalKeywordStr'] as $key => $value): ?>
                    <?php $options = array('query' => array(
                      'type' => 'LEARNING_RESOURCE',
                      'f[0]' => 'generalKeywordStr:"' . $value . '"',)); ?>
                    <?php print l(t($value), 'ode-search' , $options); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>

      <div class="panel collapsible">
        <div class="panel-heading highlight-header">
          <div class="panel-title">
            <h2><?php print t('Technique'); ?></h2>
            <span class="accordion-collapse-icon collapsed"><div class="ico ico-mas"></div></span>
          </div>
        </div>
        <div id="technique-content" class="panel-collapse collapse">
          <div class="panel-body">
            <?php if (!empty($properties['technicalFormatStr'])): ?>
              <div class="detail-ode-technical-format-wrapper">
                <label><?php print t('Technical format'); ?></label>
                <div class="detail-ode-technical-format">
                  <?php foreach (array_keys($properties['technicalFormatStr']) as $elem): ?>
                    <?php print $properties['technicalFormatStr'][$elem]; ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['technicalRequirementTypeNameStr'])): ?>
              <div class="detail-ode-technical-requirement-wrapper">
                <label><?php print t('Technical requirement'); ?></label>
                <div class="detail-ode-technical-requirement">
                  <?php foreach (array_keys($properties['technicalRequirementTypeNameStr']) as $elem): ?>
                    <?php $type_requirement = explode('##', $properties['technicalRequirementTypeNameStr'][$elem]); ?>
                    <div>
                      <span><?php print t('@key: ', array('@key' => t($type_requirement['0']))); ?></span>
                      <span><?php print t('@value', array('@value' => t($type_requirement['1']))); ?></span>
                    </div>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['technicalInstallationRemarksStr'])): ?>
              <div class="detail-ode-technical-installation-wrapper">
                <label><?php print t('Technical installation'); ?></label>
                <div class="detail-ode-technical-installation">
                  <?php print t($properties['technicalInstallationRemarksStr']); ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['technicalOtherPlatformRequirementsStr'])): ?>
              <div class="detail-ode-technical-platform-wrapper">
                <label><?php print t('Technical platform'); ?></label>
                <div class="detail-ode-technical-platform">
                  <?php foreach (array_keys($properties['technicalOtherPlatformRequirementsStr']) as $elem): ?>
                    <?php print t($properties['technicalOtherPlatformRequirementsStr'][$elem]); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>

      <div class="panel collapsible">
        <div class="panel-heading highlight-header">
          <div class="panel-title">
            <h2><?php print t('Educational use'); ?></h2>
            <span class="accordion-collapse-icon collapsed"><div class="ico ico-mas"></div></span>
          </div>
        </div>
        <div id="educational-use-content" class="panel-collapse collapse">
          <div class="panel-body">
            <?php if (!empty($properties['educationalInteractivityTypeStr'])): ?>
              <div class="detail-ode-interactivity-type-wrapper">
                <label><?php print t('Interactivity type'); ?></label>
                <div class="detail-ode-interactivity-type">
                  <?php foreach (array_keys($properties['educationalInteractivityTypeStr']) as $elem): ?>
                    <?php print t($properties['educationalInteractivityTypeStr'][$elem]); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalInteractivityLevelStr'])): ?>
              <div class="detail-ode-interactivity-level-wrapper">
                <label><?php print t('Interactivity level'); ?></label>
                <div class="detail-ode-interactivity-level">
                  <?php foreach (array_keys($properties['educationalInteractivityLevelStr']) as $elem): ?>
                    <?php print t($properties['educationalInteractivityLevelStr'][$elem]); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalSemanticDensityStr'])): ?>
              <div class="detail-ode-semantic-wrapper">
                <label><?php print t('Semantic density'); ?></label>
                <div class="detail-ode-semantic">
                  <?php foreach (array_keys($properties['educationalSemanticDensityStr']) as $elem): ?>
                    <?php print t($properties['educationalSemanticDensityStr'][$elem]); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalTypicalAgeRangeStr'])): ?>
              <div class="detail-ode-agerange-wrapper">
                <label><?php print t('Age'); ?></label>
                <div class="detail-ode-agerange">
                  <?php foreach (array_keys($properties['educationalTypicalAgeRangeStr']) as $elem): ?>
                    <span><?php print t($properties['educationalTypicalAgeRangeStr'][$elem]); ?></span>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalDifficultyStr'])): ?>
              <div class="detail-ode-difficulty-wrapper">
                <label><?php print t('Difficulty'); ?></label>
                <div class="detail-ode-difficulty">
                  <?php foreach (array_keys($properties['educationalDifficultyStr']) as $elem): ?>
                    <?php print t($properties['educationalDifficultyStr'][$elem]); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalTypicalLearningTimeDescriptionStr'])): ?>
              <div class="detail-ode-learning-time-wrapper">
                <label><?php print t('Learning time'); ?></label>
                <div class="detail-ode-learning-time">
                  <?php foreach (array_keys($properties['educationalTypicalLearningTimeDescriptionStr']) as $elem): ?>
                    <?php print t($properties['educationalTypicalLearningTimeDescriptionStr'][$elem]); ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalLanguageStr'])): ?>
              <div class="detail-ode-educational-language-wrapper">
                <label><?php print t('Target Language'); ?></label>
                <div class="detail-ode-educational-language">
                  <?php foreach (array_keys($properties['educationalLanguageStr']) as $elem): ?>
                    <?php print $properties['educationalLanguageStr'][$elem]; ?>
                  <?php endforeach; ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['educationalCognitiveProcessStr'])): ?>
              <div class="detail-ode-educational-cognitive-wrapper">
                <label><?php print t('Cognitive process'); ?></label>
                <div class="detail-ode-educational-cognitive">
                  <ul>
                    <?php foreach (array_keys($properties['educationalCognitiveProcessStr']) as $elem): ?>
                      <li><?php print t($properties['educationalCognitiveProcessStr'][$elem]); ?></li>
                    <?php endforeach; ?>
                  </ul>
                </div>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>

      <div class="panel collapsible">
        <div class="panel-heading highlight-header">
          <div class="panel-title">
            <h2><?php print t('Clasification'); ?></h2>
            <span class="accordion-collapse-icon collapsed"><div class="ico ico-mas"></div></span>
          </div>
        </div>
        <div id="clasification-content" class="panel-collapse collapse">
          <div class="panel-body">
            <?php if (!empty($properties['knowledgeAreaTags'])): ?>
              <div class="detail-ode-knowledge-area-wrapper">
                <label><?php print t('Knowledge area'); ?></label>
                <div class="detail-ode-knowledge-area clearfix">
                  <?php print implode(', ', $properties['knowledgeAreaTags']);?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['learningContextTags'])): ?>
              <div class="detail-ode-learning-context-wrapper">
                <label><?php print t('Learning context'); ?></label>
                <div class="detail-ode-learning-context clearfix">
                  <?php print implode(', ', $properties['learningContextTags']);?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['resourceTypeTags'])): ?>
              <div class="detail-ode-resource-type-wrapper">
                <label><?php print t('Resource type'); ?></label>
                <div class="detail-ode-resource-type clearfix">
                  <?php print implode(', ', $properties['resourceTypeTags']);?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['classificationAccessibilityTree'])): ?>
              <div class="detail-ode-accesibility-wrapper">
                <h3><?php print t('Accesibility'); ?></h3>
                <?php print $properties['classificationAccessibilityTree'] ?>
              </div>
            <?php endif; ?>

            <?php if (!empty($properties['classificationCompetencyTree'])): ?>
              <div class="detail-ode-competency-wrapper">
                <h3><?php print t('Competency'); ?></h3>
                <?php print $properties['classificationCompetencyTree'] ?>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>

      <div class="panel collapsible">
        <div class="panel-heading highlight-header">
          <div class="panel-title">
            <h2><?php print t('Contributions'); ?></h2>
            <span class="accordion-collapse-icon collapsed"><div class="ico ico-mas"></div></span>
          </div>
        </div>
        <div id="contributions-content" class="panel-collapse collapse">
          <div class="panel-body">
            <?php if (!empty($properties['lifecycleContributeStr'])): ?>
              <div class="detail-ode-lifecycle-wrapper">
                <div class="detail-ode-lifecycle">
                  <table class="table">
                    <thead>
                      <th class="col-md-2"><?php print t('Role'); ?></th>
                      <th class="col-md-4"><?php print t('Author'); ?></th>
                      <th class="col-md-3"><?php print t('Date'); ?></th>
                    <thead>
                    <tbody>
                      <?php foreach (array_keys($properties['lifecycleContributeStr']) as $elem): ?>
                        <?php preg_match("/(?P<begin>FN:)(.*)(?P<end>EMAIL)/", $properties['lifecycleContributeStr'][$elem], $contributors); ?>
                        <?php $contributeData = explode('##', $properties['lifecycleContributeStr'][$elem]); ?>
                        <tr>
                          <td class="col-md-2"><?php print t($contributeData['0']); ?></td>
                          <td class="col-md-4"><?php print t('@contributors', array('@contributors' => $contributors['2'])); ?></td>
                          <td class="col-md-3"><?php print date("d/m/Y h:m", strtotime($contributeData['2'])); ?></td>
                        </tr>
                      <?php endforeach; ?>
                    </tbody>
                  </table>
                </div>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>

    <?php print $comments_rendered; ?>
  </div>

  <div class="wrapper-column col-md-3 hide-full">
    <div id="ode-detail-recomended-block" class="style-common">
      <?php print render($recomended_block); ?>
    </div>

    <div id="ode-detail-interlinking-process-block">
      <?php print render($interlinking_process); ?>
    </div>

    <div id="ode-detail-related-facets">
      <?php if (!empty($properties['knowledgeAreaTags'])): ?>
        <section class="block facetapi-styles">
          <h3 class="block__title"><?php print t('Filter by knowledge area'); ?></h3>
          <div class="item-list">
            <ul>
              <?php foreach ($properties['knowledgeAreaTags'] as $property): ?>
                <li class="leaf"><?php print $property; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
      </section>
      <?php endif; ?>

      <?php if (!empty($properties['learningContextTags'])): ?>
      <section class="block facetapi-styles">
          <h3 class="block__title"><?php print t('Filter by learning context'); ?></h3>
          <div class="item-list">
            <ul>
              <?php foreach ($properties['learningContextTags'] as $property): ?>
                <li class="leaf"><?php print $property; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
      </section>
      <?php endif; ?>

      <?php if (!empty($properties['resourceTypeTags'])): ?>
      <section class="block facetapi-styles">
          <h3 class="block__title"><?php print t('Filter by resource type'); ?></h3>
          <div class="item-list">
            <ul>
              <?php foreach ($properties['resourceTypeTags'] as $property): ?>
                <li class="leaf"><?php print $property; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
      </section>
      <?php endif; ?>
    </div>

  </div>
</div>

