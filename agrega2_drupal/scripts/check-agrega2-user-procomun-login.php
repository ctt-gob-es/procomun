<?php
/**
 * Created by PhpStorm.
 * User: ajmantis
 * Date: 23/10/15
 * Time: 11:48
 */

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$fp = fopen('usuarios_logueados_en_procomun.csv', 'w');
if (($fichero = fopen("usuarios_procomun_formato_no_correo.csv", "r")) !== FALSE) {

  // Cabecera títulos
  $datos = fgetcsv($fichero, 1000);
  $datos[5] = 'EXISTE EN PROCOMÚN';
  $datos[6] = 'HA HECHO LOGIN';
  fputcsv($fp, $datos, ';', '"');

  // Datos
  while (($datos = fgetcsv($fichero, 1000)) !== FALSE) {
    $result = db_query('SELECT mail, login FROM {users} WHERE mail = :mail', array(':mail' => $datos[3]))->fetchAssoc();
    if ($result) {
      $datos[5] = 'SI';
      $datos[6] = ($result['login'] > 0) ? 'SI' : 'NO';
    }
    else {
      $datos[5] = 'NO';
      $datos[6] = 'NO';
    }

    fputcsv($fp, $datos, ';', '"');
  }
}

fclose($fichero);
fclose($fp);
?>
