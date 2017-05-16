<?php
/**
 * @file
 * ag_section_newsletter.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function ag_section_newsletter_ckeditor_profile_defaults() {
  $data = array(
    'Newsletter' => array(
      'name' => 'Newsletter',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Source\'], [\'Image\'], [\'xowl_enhance_plugin_button\', \'OCUpload\'],
    [\'Bold\',\'Italic\',\'Underline\'],
    [\'NumberedList\',\'BulletedList\',\'-\',\'Outdent\',\'Indent\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\',\'JustifyBlock\'],
    [\'Link\',\'Unlink\'],
    \'/\',
    [\'Format\',\'Font\',\'FontSize\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 'f',
        'uicolor' => 'default',
        'uicolor_user' => 'default',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 'f',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;pre;address;h1;h2;h3;h4;h5;h6',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'self',
        'css_path' => '%hsites/all/modules/main/xowl/resources/css/xowl.css',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => 'imce',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => 'config.allowedContent = true;',
        'loadPlugins' => array(
          'ocupload' => array(
            'name' => 'OCUpload',
            'desc' => 'One Click Upload',
            'path' => '%base_path%sites/all/modules/contrib/ocupload/js/',
            'buttons' => array(
              'OCUpload' => array(
                'icon' => '../img/icon-ckeditor.png',
                'label' => 'One Click Upload',
              ),
            ),
          ),
        ),
      ),
      'input_formats' => array(
        'newsletter' => 'Newsletter',
      ),
    ),
  );
  return $data;
}
