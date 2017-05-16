<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

print "\n --- Script de reasginacion de seguidores entre usuarios ---\n";

$followers = db_query('SELECT temp_map_user_followers.uid,temp_map_user_id.prouid FROM {temp_map_user_followers} INNER JOIN {temp_map_user_id} ON temp_map_user_followers.following=temp_map_user_id.proid');

foreach ($followers as $follower) {
  $account = user_load($follower->uid);
  $result = flag('flag', 'follow_user', $follower->prouid, $account);
  if (!empty($result)) {
    print "\n Realizado flag follow_user de " . $follower->uid . " a " . $follower->prouid;
  }
  else {
    print "\n No se ha podido realizar el flag de " . $follower->uid . " a " . $follower->prouid;
  }
}

print "\nFinalizado."

?>
