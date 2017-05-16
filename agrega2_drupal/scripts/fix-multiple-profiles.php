<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

//Get all candidates with many profiles
$uids_duplicated = db_query("SELECT p.uid, count(*) as recount FROM profile p where p.type = 'datos_personales' group by p.uid having recount >1")->fetchAllKeyed();

$uids = array_keys($uids_duplicated);

foreach ($uids as $uid) {

  //Get all their profile ids of type "datos_personales".
  $profile_ids = db_query("SELECT p.pid, p.pid FROM profile p where p.type = :type and p.uid = :uid", array(':uid' => $uid, ':type' => 'datos_personales'))->fetchAllKeyed();

  //If there is more than one, delete all others, leaving first untouched.
  if (is_array($profile_ids) && count($profile_ids) > 1) {
    //Remove first position and get all the others to delete.
    $profiles_to_delete = array_slice($profile_ids, 1);
    profile2_delete_multiple($profiles_to_delete);
    print "Deleting profile ids: " . implode(',', $profiles_to_delete) . " from user " . $uid . "\n";
  }
}


?>