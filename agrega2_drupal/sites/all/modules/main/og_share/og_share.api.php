<?php

/**
 * @file
 * Hooks provistos por el modulo de compartición de contenidos.
 */
 
/**
 * Responde despúes de compartir un contenido en la función og_share_share_form_submit().
 *
 * Este hook se invoca luego de que los valores fueron insertados en la base de datos.
 *
 * @param array $args
 *   Array de las redes en las que se ha compartido el objecto $node.
 * @param object $node
 *   Nodo actualizado.
 */
function hook_og_shared_content($args, $node) {
  // Hacer algo con $node.
  var_dump($args);
  var_dump($node);
}
