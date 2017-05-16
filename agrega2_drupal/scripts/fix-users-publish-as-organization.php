<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

print "\n --- Script de reasignacion de contenido de usuarios a organizaciones ---\n";


$uid_to_org = array(
  '10826' => '7341',
  '12577' => '7341',
  '12278' => '7341',
  '10015' => '7340',
  '8364' => '7340',
  '10793' => '7340',
  '7676' => '7337');



foreach ($uid_to_org as $user_uid => $organization_uid) {

  //USER MUST BE ON THIS ORGANIZATION
  print "\n+ Asegurando que el usuario " . $user_uid . " pertenece a la organizacion: " . $organization_uid . "\n";
  $user = user_load($user_uid);
  $user_wrapper = entity_metadata_wrapper('user', $user);
  $user_wrapper->field_organization_reference->set($organization_uid);
  $user_wrapper->save();

  //OTHER CONTENT
  //CANNOT ASSIGN TO ORGANIZATION OR THEY CANT BE EDITED!!!!!!
  /*$entities_not_post = db_query("SELECT nid, nid FROM {node} WHERE uid = :uid AND type <> 'post'", array(':uid' => $user_uid))->fetchAllKeyed();

  if (empty($entities_not_post)) {
    print "x No hay contenido no-post creado por el usuario " . $user_uid . "\n";
  }

  foreach ($entities_not_post as $entity_id) {
    print "- Modificando el creador del nodo " . $entity_id . " a la organizacion: " . $organization_uid . "\n";
    db_query("UPDATE node SET uid = :uid WHERE nid = :nid", array(':uid' => $organization_uid, ':nid' => $entity_id));
  }*/


  //POST CONTENT
  $entities_post = db_query("SELECT nid, nid FROM {node} WHERE uid = :uid AND type = 'post'", array(':uid' => $user_uid))->fetchAllKeyed();

  if (empty($entities_post)) {
    print "x No hay posts creados por el usuario " . $user_uid . "\n";
  }
  foreach ($entities_post as $entity_id) {
    print "* Modificando el creador original del nodo post " . $entity_id . " a la organizacion: " . $organization_uid . " con usuario original: " . $user_uid . "\n";
    $node = node_load($entity_id);
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $node_wrapper->field_original_user->set($user_uid);
    $node_wrapper->save();

    print "* Modificando el creador del nodo post " . $entity_id . " al usuario: " . $organization_uid . "\n";
    db_query("UPDATE node SET uid = :uid WHERE nid = :nid", array(':uid' => $organization_uid, ':nid' => $entity_id));
  }
}

print "\nFinalizado.";

?>
