<?php

function administer_procomun_settings_form($form, &$form_state) {

  $form['global_community_fielset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Config the global community procomun'),
    '#collapsible' => TRUE,
    '#collapse' => FALSE,
  );

  $global_community_default = variable_get('global_community_procomun', 0);
  $global_community_options = array(t('Dont select a community as global community procomun'));

  $form['global_community_fielset']['global_community_procomun'] = array(
    '#type' => 'select',
    '#options' => ag_section_social_netwok_get_global_communities($global_community_options),
    '#title' => t('Select the global community of procomun'),
    '#default_value' => $global_community_default,
  );

  return system_settings_form($form);
}
