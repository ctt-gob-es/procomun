<?php

// Script configuration. Modify accordingly to the file being imported
$conf = array(
  'file name' => 'educative_centers.csv',
  'file directory' => 'educative_centers',
  'vocabulary name' => 'centros_educativos',
);

// Retrieve the id of the vocabulary used
$conf['vocabulary id'] = taxonomy_vocabulary_machine_name_load($conf['vocabulary name'])->vid;

importCsv($conf);

function importCsv($conf) {
  //Open the file
  $csv = fopen('public://' . $conf['file directory'] . '/' . $conf['file name'], "r");

  //Prepare arrays for cache
  $countries = array();
  $provinces = array();
  $cities = array();
  if ($csv !== FALSE) {
    while(($data = fgetcsv($csv, 1000, ',')) !== FALSE) {
      print("Inserting " . $data[0] . " - " . $data[1] . " - " . $data[2] . " - " . $data[3] . "\n");
      $country_key = 0;
      $province_key = 0;
      $city_key = 0;

      //Check if the country has been saved before.
      // If it is not saved then we have to save and store in the cache
      if (!isset($countries[$data[3]])) { //We have to insert this term
        $term = (object) array(
          'vid' => $conf['vocabulary id'],
          'name' => $data[3],
          'parent' => '0',
        );
        taxonomy_term_save($term);
        $countries[$data[3]] = $term->tid;
        $country_key = $term->tid;
        print_r("Saved country: " . $data[3] . " with key: " . $country_key . "\n");
      }
      else {
        //The country is included. We only have to update the $country_key
        $country_key = $countries[$data[3]];
      }

      //Check if the province has been saved before.
      //If it is not saved then we have to save and store in the cache
      $save= TRUE;
      foreach($provinces as $key => $relation) {
        if (in_array($data[2], array_keys($relation))){
          //The province has been saved before
          if (in_array($country_key, array_values($relation))){
            //Check if some of the parents is the $country_key. If exists in the
            //array we don't have to save the province but we have to update the
            //$province_key
            $province_key = $key;
            $save = FALSE;
            break;
          }
        }
      }
      if ($save){
        //Save the term with this $tid
        $term = (object) array(
          'vid' => $conf['vocabulary id'],
          'name' => $data[2],
          'parent' => $country_key,
        );
        taxonomy_term_save($term);
        $provinces[$term->tid] = array($data[2] => $country_key);
        $province_key = $term->tid;
        print("Saved province: " . $data[2] . " with country: " . $data[3] . " key: " . $province_key . "\n");
      }

      //Check if the city has been saved before.
      //If it is not saved then we have to save and store in the cache
      $save= TRUE;
      foreach($cities as $key => $relation) {
        if (in_array($data[1], array_keys($relation))){
          //The city has been saved before
          if (in_array($province_key, array_values($relation))){
            //Check if some of the parents is the $province_key. If exists in the
            //array we don't have to save the city but we have to update the
            //$city_key
            $save = FALSE;
            $city_key = $key;
            break;
          }
        }
      }
      if ($save){
        //Save the term with this $tid
        $term = (object) array(
          'vid' => $conf['vocabulary id'],
          'name' => $data[1],
          'parent' => $province_key,
        );
        taxonomy_term_save($term);
        $cities[$term->tid] = array($data[1] => $province_key);
        $city_key = $term->tid;
        print("Saved city: " . $data[1] . " with province: " . $data[2] . " key: " . $city_key . "\n");
      }


      //Save the educative center
      $term = (object) array(
        'vid' => $conf['vocabulary id'],
        'name' => $data[0],
        'parent' => $city_key,
      );
      taxonomy_term_save($term);
      print("Saved educative center: " . $data[0] . " with citiy: " . $data[1] . " key: " . $term->tid . "\n");
  }
 }
  //Close the file
  fclose($csv);
}