<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function nexus_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['nexus_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nexus Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['nexus_settings']['breadcrumbs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show breadcrumbs in a page'),
    '#default_value' => theme_get_setting('breadcrumbs','nexus'),
    '#description'   => t("Check this option to show breadcrumbs in page. Uncheck to hide."),
  );
  $form['theme_settings']['grid']['grid_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Developer button grid'),
    '#default_value' => theme_get_setting('grid_display','nexus'),
    '#description'   => t("Check this option to show Button to Show Grid columns. Uncheck to hide."),
  );

  $form['nexus_settings']['css_exclude'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude CSS files'),
    '#description' => t('Enter one file per line.'),
    // The paths are stored in an array.
    '#default_value' => implode("\n", (array) theme_get_setting('css_exclude', 'nexus')),
  );

  // Add our custom submit function:
  $form['#submit'][] = 'nexus_form_system_theme_settings_submit';
}

/**
 * Form submit for nexus_form_system_theme_settings_alter().
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function nexus_form_system_theme_settings_submit($form, &$form_state) {
  $exclude = array_filter(array_map('trim', explode("\n", $form_state['values']['css_exclude'])));
  form_set_value(array('#parents' => array('css_exclude')), $exclude, $form_state);
}
