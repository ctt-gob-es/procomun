<?php

/**
 * @filesize( )
 */

class DrupalToolKit {

  ##################
  ##   TAXONOMY   ##
  ##################

  /**
   * @brief Get an array of terms filtered by the string $term_name, the array
   *        can be keyed by term_id ($key_name: False) or term_name ($key_name: TRUE).
   *        This method is userful when we need a autocomplete of terms
   * @return
   */
  public static function taxonomyGetTermsNamesFiltered($vocab_machine_name, $term_name = '', $parent = 0, $key_name = FALSE) {
    $terms = array();
    // Get the vocabulary ID:
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocab_machine_name);

    if (!empty($vocabulary)) {
      $query = db_select('taxonomy_term_data', 't');
      $query->join('taxonomy_term_hierarchy', 'tth', 't.tid = tth.tid');
      $query->fields('t', array('tid', 'name'));
      $query->condition('tth.parent', $parent);
      if (!empty($term_name)) {
        $query->condition('t.name', db_like($term_name) . '%', 'LIKE');
      }
      $results = $query->range(0, 4)
        ->execute();

      foreach ($results as $key => $term) {
        $key = $key_name ? $term->name : $term->tid;
        $terms[$key] = $term->name;
      }
    }
    return $terms;
  }


  /**
   * @brief Get an array of terms filtered by the string $term_name, the array
   *        can be keyed by term_id ($key_name: False) or term_name ($key_name: TRUE).
   *        This method is userful to find a three level hierarchy
   * @return
   */
  public static function taxonomyGetTermsNamesFilteredThreeLevels($vocab_machine_name, $term_name = '', $parent = 0, $key_name = FALSE) {
    $terms = array();
    // Get the vocabulary ID:
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocab_machine_name);
    if (!empty($vocabulary)) {
      $query_level1 = db_select('taxonomy_term_data', 't1');
      $query_level1->join('taxonomy_term_hierarchy', 'tth1', 't1.tid = tth1.tid');
      $query_level1->fields('t1', array('tid'));
      $query_level1->condition('tth1.parent', $parent);

      $query_level2 = db_select('taxonomy_term_data', 't2');
      $query_level2->join('taxonomy_term_hierarchy', 'tth2', 't2.tid = tth2.tid');
      $query_level2->fields('t2', array('tid'));
      $query_level2->condition('tth2.parent', $query_level1, 'IN');

      $query_level3 = db_select('taxonomy_term_data', 't3');
      $query_level3->join('taxonomy_term_hierarchy', 'tth3', 't3.tid = tth3.tid');
      $query_level3->fields('t3', array('tid', 'name'));
      $query_level3->condition('tth3.parent', $query_level2, 'IN');

      if (!empty($term_name)) {
        $query_level3->condition('t3.name', db_like($term_name) . '%', 'LIKE');
      }

      $results = $query_level3->range(0, 4)
        ->execute();

      foreach ($results as $key => $term) {
        $key = $key_name ? $term->name : $term->tid;
        $terms[$key] = $term->name;
      }
    }
    return $terms;
  }

  /**
   * @brief Create new taxonomy term in some vocabulary
   * @return New term
   */
  function taxonomyCreate($term_name, $vid) {
    $term = new stdClass();
    if (!empty($term_name) && !empty($vid)) {
      $term->name = $term_name;
      $term->vid = $vid;
      $status = taxonomy_term_save($term);
    }

    return $term;
  }

  /**
   * @brief Get data from a term filtered by name
   * @return term data founded
   */
  function taxonomyGetByName($term_name, $vid) {
    $term_data = array();
    if (!empty($term_name) && !empty($vid)) {
      $term_data = db_select('taxonomy_term_data', 'ttd')
        ->fields('ttd', array('tid', 'name'))
        ->condition('name', $term_name, '=')
        ->condition('vid', $vid, '=')
        ->execute()
        ->fetchAllKeyed();
    }
    return $term_data;
  }

  ##############
  ##   USER   ##
  ##############

  /**
   * @breaf Retrieve data from user instead of doing a complete loading of the
   *        user entity
   * @param $uid the uid of the user that we need some information
   * @param $data the field that we want to retrieve
   *
   * @return the user's data
   */
  public static function getUserData($uid, $data = array()) {
    //Select query
    $query = db_select('users', 'u');
    $query->fields('u', $data);
    $query->leftJoin('file_managed', 'fm', 'u.picture = fm.fid'); // User picture could be 0
    $query->fields('fm', array('uri'));
    $query->condition('u.uid', $uid);

    return $query->execute()->fetchObject();
  }

  /**
   * @breaf Retrieve profile entity ID from user
   * @param $uid the uid of the user that we need some information
   *
   * @return the user's data
   */
  public static function getUserPid($uid) {
    //Select query
    $query = db_select('users', 'u');
    $query->join('profile', 'p', 'u.uid = p.uid');
    $query->fields('p', ['pid']);
    $query->condition('u.uid', $uid);

    return $query->execute()->fetchObject();
  }

  /**
   * @breaf Retrieve data from user instead of doing a
   *        complete loading of the user entity
   * @param $name the username of the user that we need some information
   * @param $data the field that we want to retrieve
   *
   * @return the user's data
   */
  public static function getUserDataByName($name, $data) {
    //Select query
    $query = db_select('users', 'u');
    $query->fields('u', $data);
    $query->leftJoin('file_managed', 'fm', 'u.picture = fm.fid'); // User picture could be 0
    $query->fields('fm', array('uri'));
    $query->condition('u.name', $name);

    return $query->execute()->fetchObject();
  }

  public static function getUserDataByMail($mail, $data) {
    //Select query
    $query = db_select('users', 'u');
    $query->fields('u', $data);
    $query->leftJoin('file_managed', 'fm', 'u.picture = fm.fid'); // User picture could be 0
    $query->fields('fm', array('uri'));
    $query->condition('u.mail', $mail);

    return $query->execute()->fetchObject();
  }

  /**
   * @brief This function return the list of uids of all the user with role
   * 'administrator'
   * @return The list of uids
   */
  public static function getUidsByRole($role) {
    //Select the uids
    $query = db_select('users', 'u');
    $query->fields('u', array('uid', 'mail'));
    $query->leftJoin('users_roles', 'ur', 'ur.uid = u.uid');
    $query->leftJoin('role', 'r', 'r.rid = ur.rid ');
    $query->condition('r.name', $role);

    $results = $query->execute()->fetchAllAssoc('uid');

    return $results;
  }

  ##############
  ##   NODE   ##
  ##############

  public static function getNodeTitle($nid) {
    if (module_exists('title')) {
      global $language;
      // If title module exist get the translated title:
      $query = db_select('field_data_title_field', 'tf');
      $query->addfield('tf', 'title_field_value', 'title');
      $query->fields('tf', array('entity_id'));
      $query->condition('tf.entity_id', $nid, 'IN');
      $query->condition('tf.language', $language->language);
    }
    else {
      // Get the default drupal title property:
      $query = db_select('node', 'n');
      $query->fields('n', array('title'));
      $query->condition('n.nid', $nid, 'IN');
    }
    $titles = $query->execute();
    return ($titles->rowCount() == 1) ? $titles->fetchObject() : $titles->fetchAllAssoc('entity_id');
  }

  /**
   * @brief Retrieve a EntityfieldQUery configured to get the content publish by a user
   * @return new EntityFieldQuery();
   */
  public static function getPublishedContent($uid, $bundle, $type = 'node') {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', $type)
      ->propertyCondition('status', 1)
      ->propertyCondition('uid', $uid)
      ->addTag('node_access');

    if (isset($bundle)) {
      $query->entityCondition('bundle', $bundle);
    }

    return $query;
  }

  /**
   * Retrieve the content author uid.
   *
   * @param $nid
   *
   * @return int uid
   */
  public static function getNodeAuthor($nid) {
    $query = db_select('node', 'n');
    $query->addfield('n', 'uid');
    $query->condition('n.nid', $nid);
    $result = $query->execute();

    return ($result->rowCount() == 1) ? $result->fetchField() : '';
  }

  ###############
  # TEXT FILTER #
  ###############
  /**
    * Truncates text.
    *
    * Cuts a string to the length of $length and replaces the last characters
    * with the ending if the text is longer than length.
    *
    * ### Options:
    *
    * - `ending` Will be used as Ending and appended to the trimmed string
    * - `exact` If false, $text will not be cut mid-word
    * - `html` If true, HTML tags would be handled correctly
    *
    * @param string  $text String to truncate.
    * @param integer $length Length of returned string, including ellipsis.
    * @param array $options An array of html attributes and options.
    * @return string Trimmed string.
    * @access public
    * @link http://book.cakephp.org/view/1469/Text#truncate-1625
    */
  public static function truncateHtml($text, $length = 100, $options = array()) {
    $default = array(
        'ending' => '...', 'exact' => true, 'html' => false
    );
    $options = array_merge($default, $options);
    extract($options);

    if ($html) {
        if (mb_strlen(preg_replace('/<.*?>/', '', $text)) <= $length) {
            return $text;
        }
        $totalLength = mb_strlen(strip_tags($ending));
        $openTags = array();
        $truncate = '';

        preg_match_all('/(<\/?([\w+]+)[^>]*>)?([^<>]*)/', $text, $tags, PREG_SET_ORDER);
        foreach ($tags as $tag) {
            if (!preg_match('/img|br|input|hr|area|base|basefont|col|frame|isindex|link|meta|param/s', $tag[2])) {
                if (preg_match('/<[\w]+[^>]*>/s', $tag[0])) {
                    array_unshift($openTags, $tag[2]);
                } else if (preg_match('/<\/([\w]+)[^>]*>/s', $tag[0], $closeTag)) {
                    $pos = array_search($closeTag[1], $openTags);
                    if ($pos !== false) {
                        array_splice($openTags, $pos, 1);
                    }
                }
            }
            $truncate .= $tag[1];

            $contentLength = mb_strlen(preg_replace('/&[0-9a-z]{2,8};|&#[0-9]{1,7};|&#x[0-9a-f]{1,6};/i', ' ', $tag[3]));
            if ($contentLength + $totalLength > $length) {
                $left = $length - $totalLength;
                $entitiesLength = 0;
                if (preg_match_all('/&[0-9a-z]{2,8};|&#[0-9]{1,7};|&#x[0-9a-f]{1,6};/i', $tag[3], $entities, PREG_OFFSET_CAPTURE)) {
                    foreach ($entities[0] as $entity) {
                        if ($entity[1] + 1 - $entitiesLength <= $left) {
                            $left--;
                            $entitiesLength += mb_strlen($entity[0]);
                        } else {
                            break;
                        }
                    }
                }

                $truncate .= mb_substr($tag[3], 0 , $left + $entitiesLength);
                break;
            } else {
                $truncate .= $tag[3];
                $totalLength += $contentLength;
            }
            if ($totalLength >= $length) {
                break;
            }
        }
    } else {
        if (mb_strlen($text) <= $length) {
            return $text;
        } else {
            $truncate = mb_substr($text, 0, $length - mb_strlen($ending));
        }
    }
    if (!$exact) {
        $spacepos = mb_strrpos($truncate, ' ');
        if (isset($spacepos)) {
            if ($html) {
                $bits = mb_substr($truncate, $spacepos);
                preg_match_all('/<\/([a-z]+)>/', $bits, $droppedTags, PREG_SET_ORDER);
                if (!empty($droppedTags)) {
                    foreach ($droppedTags as $closingTag) {
                        if (!in_array($closingTag[1], $openTags)) {
                            array_unshift($openTags, $closingTag[1]);
                        }
                    }
                }
            }
            $truncate = mb_substr($truncate, 0, $spacepos);
        }
    }
    $truncate .= $ending;

    if ($html) {
        foreach ($openTags as $tag) {
            $truncate .= '</'.$tag.'>';
        }
    }

    return $truncate;
  }

  ############
  ##   IP   ##
  ############
  public static function getClientIP() {
    $ipAddress = array();
    $arrayVarsIP = array('HTTP_CLIENT_IP', 'HTTP_X_FORWARDED_FOR', 'HTTP_X_FORWARDED', 'HTTP_X_CLUSTER_CLIENT_IP', 'HTTP_FORWARDED_FOR', 'HTTP_FORWARDED', 'REMOTE_ADDR');

    foreach ($arrayVarsIP as $key){
        if (array_key_exists($key, $_SERVER) === true){
            foreach (explode(',', $_SERVER[$key]) as $ip){
                $ip = trim($ip); // just to be safe

                if (filter_var($ip, FILTER_VALIDATE_IP) !== false){
                    $ipAddress[] = $ip;
                }
            }
        }
    }

    return $ipAddress;
  }
}