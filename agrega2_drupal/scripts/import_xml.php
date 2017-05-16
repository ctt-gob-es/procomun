<?php

// Script configuration. Modify accordingly to the file being imported
$conf = array(
  'file name' => 'PODPL_02_Arbol_curricular_LOE_2006_es.xml',
  'file directory' => 'castellano',
  'vocabulary name' => 'arbol_curricular',
  'max title size' => 128,
);

// Retrieve the id of the vocabulary used
$conf['vocabulary id'] = taxonomy_vocabulary_machine_name_load($conf['vocabulary name'])->vid;

importXml($conf);

function importXml($conf) {
  $xml = simplexml_load_file('public://' . $conf['file directory'] . '/' . $conf['file name'], 'SimpleXMLIterator');

  $foo = $xml->xpath('//term');
  foreach ($foo as $v) {
    $parent_node = $v->xpath('parent::*');
    $parent_id = $parent_node[0]->termIdentifier;
    $id = $v->termIdentifier;
    $term_title = $id . ' - ' . trim($v->caption->langstring);
    $description = $v->caption->langstring;

    // The new term to be saved
    $entity = entity_create('taxonomy_term', array('type' => $conf['vocabulary name']));

    // If the term has a parent, find its nid and add it to the entity
    if (!is_null($parent_id)) {
      $result = (new EntityFieldQuery())
        ->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', machine_name($conf['vocabulary name']))
        ->fieldCondition('field_xml_id', 'value', $parent_id)
        ->execute();
      if (count($result['taxonomy_term']) >= 1) {
        $parent_tid = reset(array_keys($result['taxonomy_term']));
        $entity->parent = $parent_tid;
      }
    }

    $entity->vid = $conf['vocabulary id'];
    $entity->name = check_plain(substr($term_title, 0, $conf['max title size']));
    $entity->weight = array_pop(explode('.', $id));
    $entity->field_xml_id['und'][0]['value'] = $id;
    $entity->description = $description;

    echo "$term_title ($id) - parent ($parent_id - tid:$parent_tid)\n";
    taxonomy_term_save($entity);
  }
}

function machine_name($complete_name) {
  return preg_replace('@[^a-z0-9_]+@','_', strtolower($complete_name));
}
