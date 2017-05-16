<?php
/**
 * @file
 * ag_section_profile_users.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ag_section_profile_users_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_short_d_m_Y';
  $strongarm->value = 'd/m/Y';
  $export['date_format_short_d_m_Y'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'public' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'ckeditor' => array(
          'weight' => '11',
        ),
        'profile_datos_personales' => array(
          'weight' => '2',
        ),
        'profile_datos_organizacion' => array(
          'weight' => '3',
        ),
        'account' => array(
          'weight' => '0',
        ),
        'timezone' => array(
          'weight' => '9',
        ),
        'picture' => array(
          'weight' => '5',
        ),
        'locale' => array(
          'weight' => '4',
        ),
        'mimemail' => array(
          'weight' => '1',
        ),
        'privatemsg' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'profile_cv' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'public' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'profile_datos_personales' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'public' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'summary' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'public' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'profile_datos_organizacion' => array(
          'public' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'mimemail' => array(
          'public' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'privatemsg_send_new_message' => array(
          'public' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'simplenews' => array(
          'public' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  return $export;
}
