<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<?php if ($tabs): ?>
  <?php print $tabs; ?>
<?php endif; ?>

<?php unset($user_profile['user_picture']); ?>
<?php unset($user_profile['most_used_tags']); ?>

<div class="profile tab-content"<?php print $attributes; ?>>
  <?php if(!empty($profile_datos_personales)): ?>
    <?php $key = current(array_keys($profile_datos_personales)); ?>
  <?php endif; ?>

  <?php if (isset($user_profile['profile_datos_personales'])): ?>
    <?php $user_profile['profile_datos_personales']['#title'] = $profile_datos_personales[$key]->field_profile_name['und'][0]['value']; ?>
  <?php endif; ?>

  <?php if (!empty($profile_edit_button)): ?>
    <div class="<?php print $profile_edit_class; ?>"><?php print $profile_edit_button; ?></div>
  <?php endif; ?>

  <div class="screenViewer inner-section">
    <div class="normal-actions do-inline pull-right space-l-inline-elements">
      <div class="insert do-inline"><div class="ico ico-insertar"></div><div class="value"><?php print t('Share public profile'); ?></div></div>
    </div>

    <div class="content">
      <div class="normal-actions-holder">
        <div class="insert"><textarea rows="2"><?php print $insert_link; ?></textarea></div>
      </div>
    </div>
  </div>

  <?php if (isset($user_profile['profile_cv'])): ?>
    <?php $user_profile['profile_cv']['#title'] = t('Curriculum Vitae'); ?>
  <?php endif; ?>

  <?php print $mi_cuenta; ?>
  <?php print render($user_profile); ?>
</div>
