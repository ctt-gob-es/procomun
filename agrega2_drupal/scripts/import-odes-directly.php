<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

global $user;


$arguments = drush_get_arguments();

$path_odes = isset($arguments[2]) ? $arguments[2] : '/var/www/agrega2_drupal/recursosaprendizaje.xml';
$path_comments = isset($arguments[3]) ? $arguments[3] : '/var/www/agrega2_drupal/comentarios.xml';

print "\nArchivo de recursos a usar: " . $path_odes;
print "\nArchivo de comentarios a usar: " . $path_comments;

# PASO 0: Parsear el archivo de comentarios para tener una lista de los identificadores de recurso.
# Luego comprobaremos este array para que, si un ode tiene comentarios, lo creamos en drupal,
# y guardamos su NID e ID en la tabla temp_map_content_id para que los comentarios se asignen
# en importaciones posteriores.
print "\nPASO 0: Preparar comentarios...\n";

$recursos_comentados = array();
$xml_object = simplexml_load_file($path_comments);

foreach($xml_object->children() as $value) {
  $identificador_recurso = (string) $value->Identificador_Recurso;

  if (!empty($identificador_recurso) && !array_key_exists($identificador_recurso, $recursos_comentados)) {
    $recursos_comentados[$identificador_recurso] = $identificador_recurso;
  }
}

print "\n Cargados los comentarios: " . count($recursos_comentados) . " recursos candidatos y posibles odes.\n";
# APROX, 915 nodos. Muchos menos de ellos serán ODEs.


# PASO 1: Cargamos en memoria todos aquellos usuarios que hayan pulsado favorito sobre algún tipo de contenido.
print "\nPASO 1: Preparar/precargar usuarios que tienen favoritos...\n";

$recursos_favoritos = array();
$array_uid_users = array();
$resulset = db_query('SELECT id, uid, favorites FROM {temp_map_user_favorites}');

foreach($resulset as $key => $value) {
  $id_xml = $value->favorites;
  // NOTA!: Un mismo id puede haber sido favoriteado por multiples usuarios.
  if ($id_xml && $value->uid) {
    $recursos_favoritos[$id_xml][$value->uid] = $value->uid;
  }

  //Usuarios repetidos, añadir solo los nuevos.
  if (!in_array($value->uid, $array_uid_users)) {
    $array_uid_users[] = $value->uid;
  }
}

$users_loads_multiple = user_load_multiple($array_uid_users);
print "\n Usuarios cargados: " . count($users_loads_multiple) . " elementos.\n";
#   RESULTADO:
#    - $array_uid_users tiene los uids de los usuarios que han favoriteado.
#    - $users_loads_multiple tiene cargados todas las cuentas de usuario que han favoriteado.
#    - $recursos_favoritos tiene como clave: ID de recurso favoriteado y dentro, clave UID y valor UID.



# PASO 2: Creamos un array de traducción con los odes que tengan ID de agrega
# y hayan sido favoriteados o comentados o compartidos y tengan que ser almacenados en Drupal.
# Formato resultante: Clave ID GNOSS XXXX-XX-XX-XX-XXXX y valor ID ODE AGREGA: es_xxx_xxx
print "\nPASO 2: Preparar odes candidatos...\n";

print "\n  Procesando XML...\n";

$array_odes_to_save = array();
$xml_object = simplexml_load_file($path_odes);

print "\n  XML procesado.\n";

//Arrays temporales.
$compartidos = array();
$comentados = array();
$favoritos = array();
$votados = array();
$certificados = array();

$procomun_nid = variable_get('global_community_procomun');
$procomun_proid = db_query('SELECT procid from temp_map_community_id WHERE cid = :cid', array(':cid' => $procomun_nid))->fetchField();

if (!$procomun_nid || !$procomun_proid) {
  print "\n ERROR: No se encuentra el nid de la red global PROCOMUN o su Identificador original guardado al migrar. Deteniendo proceso...\n";
  die();
}


foreach($xml_object->children() as $value) {
  $identificador = (string) $value->Identificador;
  $identificador_agrega = (string) $value->Identificador_Agrega;
  $publicaciones = (array) $value->Publicaciones;

  //Hacer casting al array se carga la estructura, poniendo "Publicación" antes que el 2.
  $publicaciones = $publicaciones['Publicación'];

  //Asegurar que entra en el foreach con estructura de array. El casting a array es muy irregular.
  if (!is_array($publicaciones)) {
    $publicaciones = array($publicaciones);
  }


  //Comprobar todos los campos dentro de cada publicacion.
  $is_shared = FALSE;
  $is_certified = FALSE;
  $is_voted = FALSE;
  foreach ($publicaciones as $value) {
    $publicacion = $value;

    //Contenido que podemos ignorar, ya que no se va a migrar al no tener campo o posibilidad.
    unset($publicacion->Categorías);
    //unset($publicacion->Votos);
    unset($publicacion->Visitas);


    //Comprobamos si se ha compartido en una red distinta a procomun.
    $id_comunidad = (string)$publicacion->Identificador_Comunidad;

    if ($id_comunidad) {
      if ($id_comunidad !== $procomun_proid) {

        $compartidos[$identificador][] = $publicacion;
        $is_shared = TRUE;
      }
    }

    $votos = (array)$publicacion->Votos;
    if (count($votos) > 0) {
      $votados[$identificador][] = $votos;
      $is_voted = TRUE;
    }

    $certificacion = (string)$publicacion->Certificado;
    if (!empty($certificacion)) {
      $certificados[$identificador][] = $certificacion;
      $is_certified = TRUE;
    }
  }

  //Campos no dependientes de "Publicacion"
  $is_commented = array_key_exists($identificador, $recursos_comentados);
  if ($is_commented) {
    $comentados[$identificador] = $identificador;
  }

  $is_fav = array_key_exists($identificador, $recursos_favoritos);
  if ($is_fav) {
    $favoritos[$identificador] = $identificador;
  }

  //Almacenamos en $recursos_comentados los comentados, en $favoritos los favoritos, y en $compartidos los compartidos.
  if (($is_fav || $is_commented || $is_shared || $is_voted || $is_certified) && $identificador_agrega) {
    $array_odes_to_save[$identificador] = $identificador_agrega;
  }

  if (($is_fav || $is_commented || $is_shared || $is_voted || $is_certified) && !$identificador_agrega) {
    $array_odes_sin_id_agrega[$identificador] = $identificador;
  }

  if (!$identificador_agrega) {
    $array_odes_sin_id_agrega_totales[$identificador] = $identificador;
  }


}

print "\n Número de odes compartidos: " . count($compartidos) . ".";
print "\n Número de odes favoriteados: " . count($favoritos) . ".";
print "\n Número de odes comentados: " . count($comentados) . ".";
print "\n Número de odes votados: " . count($votados) . ".";
print "\n Número de odes certificados: " . count($certificados) . ".";

print "\n\n Número de odes totales sin identificador de agrega (del tipo 'es_xxx_xxx'): " . count($array_odes_sin_id_agrega_totales) . ".";
print "\n Número de odes que no se podrán guardar por falta de identificador de agrega (del tipo es_xxx_xxx): " . count($array_odes_sin_id_agrega) . ".";
print "\n Total a guardar (con id de agrega): " . count($array_odes_to_save) . " recursos de aprendizaje/odes.";
print "\n";


# PASO 3: Consultar al solr por ID AGREGA es_xxx_xxx para obtener su ID SOLR: 14XXXXXXXX, e idDrupal si lo hubiera.
# Una vez comprobemos que existe en SOLR, nos lo traemos a Drupal, y comenzamos con los siguientes cambios:
#   PASO 3.1: Guardar el ODE.
#   PASO 3.2: Hacer flag de favorito si fuera necesario.
#   PASO 3.3: Añadir los ids a la tabla auxiliar de comentarios temp_map_content_id.
#   PASO 3.4: Modificar el campo og_group_ref si el documento ha sido compartido en otra red que no sea procomun.
#             Nota: Si se quisiera guardar en Drupal los compartidos en procomun, nos obligaría a guardar los 74000 odes del XML.
#   PASO 3.5: 'Flaggear' el nodo como "Me gusta" si tiene una entrada en array "votados" por tener tag "Votos"
#   PASO 3.6: Marcar como certificado si lo está.
#   PASO 3.7  Si se ha creado correctamente y es un nid nuevo al que existía, actualizarlo en Solr.

print "\nPASO 3: Consultar a SOLR y traernos los odes necesarios...\n";

$endpoint = db_query('SELECT url from wsclient_service WHERE name = :name', array(':name' => 'orchestrator_selection'))->fetchField();

//NOTA: La clave es el ID, y el valor el ID_AGREGA
$total = count($array_odes_to_save);
$contador = 0;
$descartados = 0;
$creados = 0;

foreach($array_odes_to_save as $id_xml => $id_agrega) {
  $contador++;

  $jsonUrl = $endpoint . 'select?q=*:*&fq=type:ODE&wt=json&fq=generalIdentifierStr:"' . $id_agrega . '"&fl=idDrupal,id';
  $json = file_get_contents($jsonUrl);

  $response = json_decode($json);

  # Sólo almacenamos en ARRAY_USERS los que están en SOLR.
  if ($response->response->numFound > 0) {

    // Primeros datos del solr, NID si lo hubiera (aunque se ignora), y SOLR ID.
    $solr_id = $response->response->docs[0]->id;
    $solr_nid = $response->response->docs[0]->idDrupal;
    print "\n" . $contador . "/" . $total . " ID: " . $id_xml . " Solr_ID: " . $solr_id . " con supuesto idDrupal:" . $solr_nid;


    // GUARDAMOS EL NODO ODE, si no existiera ya en Drupal. En ambos casos, obtengo el nid.
    $ode = ag_visualization_ode_get_solr_ode($solr_id);
    $ode_nid = ag_visualization_ode_save($ode);

    if (!$ode_nid) {
      print "\n  * ERROR: ODE no se ha guardado. NID vacio. Se ignora.";
      continue;
    }
    else {
      print "\n  * Nodo real en Drupal: " . $ode_nid;
    }

    # PASO 3.2
    //Con el nid, podemos realizar los flags, y el proceso de favoritos.
    $flagging_uids = $recursos_favoritos[$id_xml];

    if (!empty($flagging_uids) && is_array($flagging_uids)) {
      foreach ($flagging_uids as $key => $user) {
        $flag = flag('flag', 'favorite', $ode_nid, $users_loads_multiple[$user]);
        print "\n  + Está marcado como favorito. Flag de usuario: " . $user;
      }
    }


    # PASO 3.3
    //Ademas, para cuando importemos comentarios, tenemos que tener añadida a la tabla
    //temp_map_content_id que estos odes ya existen en drupal y aceptan comentarios.
    if (array_key_exists($id_xml, $comentados)) {

      //Buscamos si existe alguno con este proid.
      $query = db_select('temp_map_content_id', 'tc');
      $query->fields('tc', array('cid', 'proid', 'type'));
      $query->condition('tc.proid', $id_xml, '=');
      $result = $query->execute()->fetchAssoc();

      if ($result) {
        //Si existe, actualizamos.
        db_update('temp_map_content_id')
          ->fields(array('cid' => $ode_nid,))
          ->condition ('temp_map_content_id.proid', $id_xml, '=')
          ->execute();

         print "\n  + Tendrá comentarios cuando se importen. Entrada existente, con nid:" . $ode_nid . " y proid: " . $id_xml;
      }
      else {
        db_insert('temp_map_content_id')
          ->fields(array(
            'cid' => $ode_nid,
            'proid' => $id_xml,
            'type' => 'ode',
          ))
          ->execute();
       print "\n  + Tendrá comentarios cuando se importen. Nueva entrada, con nid:" . $ode_nid . " y proid: " . $id_xml;
      }

    }



    # PASO 3.4
    // Si está compartido en alguna comunidad, colocarla. En cualquier caso, añadimos procomun.
    $cids = array();
    if (array_key_exists($id_xml, $compartidos)) {
      $publicaciones = $compartidos[$id_xml];

      foreach ($publicaciones as $publicacion) {

        //Cargar nids de las comunidades
        $cid = db_query('SELECT cid from temp_map_community_id WHERE procid = :procid', array(':procid' => (string)$publicacion->Identificador_Comunidad))->fetchField();
        $cids[] = $cid;
      }
    }

    //Si está en alguna, almacenamos en esas y en procomun, si no, sólo procomun.
    $procomun = variable_get('global_community_procomun');
    $cids[] = $procomun;

    //Añadir a og_group_ref si existen.
    if (!empty($cids) && is_array($cids)) {
      //Formato clave->valor con nid.
      $cids = array_unique($cids);
      $cids = array_combine($cids, $cids);

      //Cargamos el nodo. Por suerte, son pocos.
      $node = entity_load_single('node', $ode_nid);

      //Cargamos su wrapper para alterar el campo.
      $w_node = entity_metadata_wrapper('node', $node);
      $current_og_refs = $w_node->og_group_ref->raw();

      //Adjuntamos a los valores actuales y guardamos.
      if (!empty($current_og_refs)) {
        $current_og_refs = array_merge($current_og_refs, $cids);
        $current_og_refs = array_unique($current_og_refs);
      }
      else {
        $current_og_refs = $cids;
      }

      if (count($current_og_refs) > 1) {
        print "\n  + Está compartido. Redes:" . implode(',', $current_og_refs);
      }
      else {
        print "\n  + Compartido por defecto en red global Procomun: " . implode(',', $current_og_refs);
      }


      $w_node->og_group_ref->set($current_og_refs);
      $w_node->save();
    }




    # PASO 3.5:
    //'Flaggear' el nodo como "Me gusta" si tiene una entrada en array "votados" por tener tag "Votos"
    if (array_key_exists($id_xml, $votados)) {
      $votos = $votados[$id_xml];

      foreach ($votos as $voto) {
        $voto = (array) $voto['Voto'];

        if ($voto['Valor'] == '1') {
          //Consultar el uid del usuario. Esto no puede precargarse, ya que los votos vienen en el XML de recursos, no antes, como favoritos.
          $uid = db_query('SELECT prouid from temp_map_user_id WHERE proid = :proid', array(':proid' => $voto['Votante']))->fetchField();

          //Cargar usuario si existe en la migracion.
          if ($uid) {
            $user = user_load($uid);
          }

          //Flag si el usuario se ha creado correctamente.
          if (!empty($user) && $ode_nid) {
            $flag_result = flag('flag', 'like', $ode_nid, $user);
            print "\n  + Tiene votos/me gusta. Flag con el usuario:" . $user->uid . " resultado:" . $flag_result;
          }
        }
      }
    }


    # PASO 3.6:
    // Marcar como certificado si lo está.
    if (array_key_exists($id_xml, $certificados)) {
      $certificaciones = $certificados[$id_xml];

      //Con que tenga una sola certificacion, nos vale para marcarlo como Certificado=1. No distinguimos niveles de certif.
      if (!empty($certificaciones)) {

        //Cargamos el nodo. Por suerte, son pocos.
        $node = entity_load_single('node', $ode_nid);

        //Cargamos su wrapper para alterar el campo.
        $w_node = entity_metadata_wrapper('node', $node);

        //Certificamos.
        $w_node->field_certified->set(TRUE);
        $w_node->save();
        print "\n  + Recurso certificado.";
      }
    }


    # PASO 3.7
    // Si se ha creado correctamente y es un nid nuevo al que existía, actualizarlo en Solr.
    if (!empty($ode_nid) && $ode_nid != $solr_nid) {
      //Update SOLR ID
      $OS_orchestrator_inyection = new OS_orchestrator_inyection();
      list($status, $result) = $OS_orchestrator_inyection->UpdateSolr($ode_nid, $solr_id);
      if ($status != 1) {
        print "\n  - Error al actualizar idDrupal: " . $status . "-" . $result . "--" . $ode_nid. "--" .$solr_id;
      }
      else {
        print "\n  - Actualizando recurso " . $solr_id . ", campo idDrupal a: " . $ode_nid . "... Estado: " . $status . " Result: " . $result->responseCode;
      }
    }
    else {
        print "\n  - Dato idDrupal correcto en solr: " . $solr_nid . " = " . $ode_nid;
    }





    //FIN DE LOS PASOS EN CASO DE EXISTIR NODO.
    if (!empty($ode_nid)) {
      $creados++;
    }


  }
  else{
    print "\nNo existe en Solr el id_agrega: " . $id_agrega . " del ID XML: " . $id_xml;
    $descartados++;
  }
  print "\n";
}

print "\n\nFinalizado. Total procesados:" . $total;
print "\n            Descartados por ausencia en solr:" . $descartados;
print "\n            Creados/importados a Drupal:" . $creados;

?>
