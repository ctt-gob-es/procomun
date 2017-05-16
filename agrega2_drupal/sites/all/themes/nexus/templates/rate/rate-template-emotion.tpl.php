<?php

/**
 * @file
 * Rate widget theme
 */

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}

print theme('item_list', array(
  'items' => $buttons,
  //'title' => $display_options['title'],
  ));

if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}
