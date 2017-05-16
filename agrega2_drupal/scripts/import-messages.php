<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

ini_set('max_execution_time', 0);

$arguments = drush_get_arguments();

$path = isset($arguments[2]) ? $arguments[2] : '/var/www/agrega2_drupal/mensajes.xml';

$xml = simplexml_load_file($path);

// Delete previous messgaes:
db_query("TRUNCATE {pm_index}");
db_query("TRUNCATE {pm_message}");

$contador = 0;
$total = count($xml->children());
foreach ($xml->children() as $content) {
  $contador++;
  $receiving_users = (array)$content->Destinatarios;

  $recipients = db_query('SELECT prouid FROM {temp_map_user_id} WHERE proid IN (:proids)', array(':proids' => $receiving_users['Identificador_Perfil_Destinatario']))->fetchAllKeyed();
  $recipients = array_keys($recipients);
  $author = db_query('SELECT prouid FROM {temp_map_user_id} WHERE proid = :proid', array(':proid' => (string)$content->Identificador_Perfil_Remitente))->fetchField();

  // NOS ASEGURAMOS QUE EXISTEN LOS USUARIOS:
  if (!empty($recipients) && !empty($author)) {
    // LOS USUARIOS EXISTEN
    //Parse date
    $date = str_replace('/', '-', (string)$content->Fecha);
    $timestamp = strtotime($date);
    if (!$timestamp) {
      $timestamp = time();
    }

    $asunto = (string)$content->Asunto;
    $asunto = trim(str_replace("RE: ", '', $asunto));
    $descripcion = (string)$content->Descripción;
    //setlocale(LC_CTYPE, 'es_ES.utf8');
    //$asunto = iconv('UTF-8', 'ASCII//TRANSLIT', $asunto);
    //$descripcion = iconv('UTF-8', 'ASCII//TRANSLIT', $descripcion);

    //Load users
    $loaded_recipients = user_load_multiple($recipients);
    $loaded_author = user_load($author);

    if ($loaded_author && !empty($loaded_recipients)) {
      $thread_id = check_thread_already_exists($recipients, $author, $asunto);
      if (!empty($thread_id)) {
        // Existe un hilo ya:
        $options = array('timestamp' => $timestamp, 'author' => $loaded_author);
        privatemsg_reply((int) $thread_id, $descripcion, $options);
      }
      else {
        // No existe un hilo: Creamos uno
        $options = array('timestamp' => $timestamp, 'author' => $loaded_author);
        privatemsg_new_thread($loaded_recipients, $asunto, $descripcion, $options);
      }
      print $contador . "/" . $total . " Importado mensaje con ID: " . (string)$content->Identificador . ".\n";
    }
    else {
      // ERROR:
      print "Error al importar el mensaje " . (string)$content->Identificador . " enviado entre estos usuarios...:\n";
      print "  Autor:      uid = " . $author . " con id: " . ((string)$content->Identificador_Perfil_Remitente) . "\n";
      print "  Receptores: uids = " . implode(',', $recipients) . " con ids: " . implode(',',((array)$content->Destinatarios)) . "\n";
    }
  }
  else {
    // NO SE HAN ENCONTRADO O LOS REMITENTES O EL AUTOR EN LAS TEMPORALES
    print "Error al no encontrar los autores o remitentes del mensaje: " . (string)$content->Identificador . " enviado entre estos usuarios...:\n";
    print "  Autor:      uid = " . $author . " con id: " . ((string)$content->Identificador_Perfil_Remitente) . "\n";
    print "  Receptores: uids = " . implode(',', $recipients) . " con ids: " . implode(',',((array)$content->Destinatarios)) . "\n";
  }
}

function check_thread_already_exists($participant_a, $participant_b, $subject) {
  $conversation_id = 0;
  $query = "SELECT msg.subject, msg.author, ind.recipient, ind.thread_id ";
  $query .= "FROM {pm_message} msg ";
  $query .= "LEFT JOIN {pm_index} ind on msg.mid = ind.mid ";
  $query .= "CROSS JOIN {pm_index} ind2 ON ind.thread_id = ind2.thread_id AND ind2.recipient IN(:a) AND ind2.deleted = 0 ";
  $query .= "WHERE ((msg.author IN(:a) AND ind.recipient IN (:b)) OR (msg.author IN (:b) AND ind.recipient IN (:a)))";

  $results = db_query($query, array(':a' => $participant_a, ':b' => $participant_b))->fetchAll();

  if (!empty($results)) {
    foreach ($results as $thread) {
      if ($thread->subject == $subject) {
        $conversation_id = $thread->thread_id;
        break;
      }
    }
  }
  // Return converation
  return $conversation_id;
}

