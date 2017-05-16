<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

print "\n --- Script de reasginacion de seguidores entre usuarios ---\n";

$arguments = drush_get_arguments();

//Remove this permission.
if (isset($arguments[2])) {
  $permission_removal = $arguments[2];

  //Obtener todos los roles candidatos a tener permisos que no deberian tener.
  //Se limita por: nodo, no-administrador, red social, y que no sean los 3 roles basicos. Ah, y que sean publicas!
  $roles_candidates = db_query("SELECT p.rid, p.rid
                             FROM og_role_permission p 
                                INNER JOIN og_role r ON r.rid = p.rid 
                                INNER JOIN field_data_field_og_permissions_level fog ON fog.entity_id = r.gid 
                                INNER JOIN field_data_group_access ga ON ga.entity_id = r.gid 
                             WHERE r.group_bundle = 'social_network' 
                                AND r.rid NOT IN (1,2,3) 
                                AND r.name <> 'administrator member'
                                AND r.group_type = 'node'
                                AND fog.field_og_permissions_level_value = 0
                                AND ga.group_access_value = 0")->fetchAllKeyed();


  foreach ($roles_candidates as $role) {
    $rows = db_query("DELETE FROM og_role_permission WHERE rid = :rid AND permission = :permission", array(':rid' => $role, ':permission' => $permission_removal));
    print "Eliminado permiso: \"" . $permission_removal . "\" del rol: " . $role . " " . $rows . "\n";
  }

}
else {
  print "\nERROR - No has aportado un permiso a eliminar.\n";
}

print "\nFinalizado.\n";

?>
