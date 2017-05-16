<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

global $user;

print "\n --- Script de asignacion de imagenes a usuarios migrados ---\n";

$users_migrated = db_query('SELECT u.uid, tu.proid from users u inner join temp_map_user_id tu on tu.prouid = u.uid')->fetchAllKeyed();


$modificados = 0;
$procesados = 0;
foreach ($users_migrated as $key => $value) {
  $agrega_user_id = $value;
  $uid = $key;
  $file = '';
  $filepath = '';
  $files = '';
  $rows = '';

  print "\nImportando imagen de usuario " . $uid . " con id agrega: " . $agrega_user_id;

  // Assign user picture
  if (isset($agrega_user_id) && !empty($agrega_user_id)) {
    // Path where user image must be.
    $filepath = 'public://migration_pictures/' . $agrega_user_id . '.png';

    //Get default image if none selected.
    if (!file_exists($filepath)) {
      $filepath = variable_get('user_picture_default');
      print "\n  - Ruta no encontrada, se ignora.  (" . $filepath . ")";
      print "\n";
      continue;
    }
    else {
      print "\n  + Ruta existe. (" . $filepath . ")";
    }

    // Check if it exists already on the database, caused by multiple imports.
    $files = file_load_multiple(array(), array('uri' => $filepath));
    if (!empty($files)) {
      $file = array_pop($files);
    }

    //If file is not found on database, create a new entry.
    if (empty($file)) {
      $file = (object) array(
        'uid' => 1,
        'uri' => $filepath,
        'filemime' => file_get_mimetype($filepath),
        'status' => 1,
      );
      file_save($file);
      print "\n  * Archivo nuevo, creando fid.";
    }
    else{
      print "\n  * Archivo existe, fid es " . $file->fid;
    }

    //Save to user data if picture was correctly saved.
    if (isset($file->fid) && !empty($file->fid)) {
      $rows = db_update('users')
        ->fields(array('picture' => $file->fid,))
        ->condition('uid', $uid)
        ->execute();
      print "\n  + Actualizando imagen de usuario " . $uid . ". Filas afectadas: " . $rows;
    }
    else {
      print "\n  * No se necesita actualizar la imagen.";
    }
    $procesados++;
    $modificados = $modificados + $rows;
    print "\n";
  }

}

  print "\n\nFinalizado. Modificados: " . $modificados ."  Total procesado: " .  $procesados . "\n";
?>
