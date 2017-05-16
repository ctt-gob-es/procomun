<?php
/**
 * @file
 * Plugin content type for panels to list certifiable odes by visits.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Certifiable odes by visits list'),
  'description' => t("Custom ct pane for list certifiable odes by visits."),
  'category' => t('Agrega2'),
  'render callback' => 'control_center_certification_by_visits',
);

/**
 * Render callback.
 */
function control_center_certification_by_visits($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->module = 'control_center_certifications';
  $block->title = '<none>';

  $visits = variable_get('ode_number_visits');
  $title = isset($_GET['title']) ? '%' . $_GET['title'] . '%' : '%%';

  if (!isset($_GET['certified']) || $_GET['certified'] == 'any') {
    $certified = array('0', '1');
  }
  else if ($_GET['certified'] == 'no') {
    $certified = array('0');
  }
  else {
    $certified = array('1');
  }

  // Retrieve odes in database that exceed visits limits
  $ode_node = db_query('SELECT n.title, n.nid, count(nvc.nid) + IFNULL(oa.total, 0) AS total_visits, fdfs.field_solrid_value, fdfc.field_certified_value FROM node AS n
                        INNER JOIN nodeviewcount AS nvc ON n.nid = nvc.nid
                        INNER JOIN field_data_field_solrid AS fdfs ON n.nid = fdfs.entity_id LEFT JOIN odecount_anon AS oa ON fdfs.field_solrid_value = oa.solrid
                        INNER JOIN field_data_field_certified AS fdfc ON n.nid = fdfc.entity_id AND (fdfc.entity_type = :node AND fdfc.deleted = 0)
                        WHERE type = :ode AND status = 1 AND fdfc.field_certified_value IN (:certified) AND title LIKE :title
                        GROUP BY nvc.nid
                        HAVING total_visits > :visits', array(':node' => 'node', ':ode' => 'ode', ':certified' => $certified, ':title' => $title, ':visits' => $visits));

  // Retrieve odes in solr that exceed visits limits
  $ode_anon = db_query('SELECT oa.solrid, fdfs.field_solrid_value, oa.total FROM odecount_anon AS oa
                        LEFT JOIN field_data_field_solrid AS fdfs ON fdfs.field_solrid_value = oa.solrid
                        WHERE oa.total > :visits AND fdfs.field_solrid_value IS NULL', array(':visits' => $visits));

  $header = array(t('Title'), t('Visits'), t('Certified'));
  $rows = array();
  $no_yes = array('No', 'Yes');

  foreach ($ode_node as $ode) {
    $rows[] = array(
      'title' => l($ode->title, 'ode/view/'. $ode->field_solrid_value),
      'visits' => $ode->total_visits,
      'certified' => $no_yes[$ode->field_certified_value],
      //'solrid' => $ode->field_solrid_value,
    );
  }

  if (!isset($_GET['certified']) || $_GET['certified'] != 'yes') {

    //TODO:Call to solr service to get all odes in $ode_anon variable ids

    foreach ($ode_anon as $ode) {
      $complete_ode = ag_visualization_ode_get_solr_ode($ode->solrid);
      if (isset($_GET['title']) && !empty($_GET['title'])) {
        if (preg_match('/' . $_GET['title'] . '/i', $complete_ode['titleStr'])) {
          $rows[] = array(
            'title' => l($complete_ode['titleStr'], 'ode/view/'. $ode->solrid),
            'visits' => $ode->total,
            'certified' => $no_yes[0],
            //'solrid' => $ode->solrid . ' - SOLR',
          );
        }
      }
      else {
        $rows[] = array(
          'title' => l($complete_ode['titleStr'], 'ode/view/'. $ode->solrid),
          'visits' => $ode->total,
          'certified' => $no_yes[0],
          //'solrid' => $ode->solrid . ' - SOLR',
        );
      }
    }

    //TODO: End
  }

  if (count($rows)) {
    // Sort results by visits
    $rows = array_sort($rows, 'visits', SORT_DESC);
    // PAGER
    $per_page = 10;
    // Initialize the pager
    $current_page = pager_default_initialize(count($rows), $per_page);
    // Split your list into page sized chunks
    $chunks = array_chunk($rows, $per_page, TRUE);

    // TODO: Delete this
/*    foreach ($chunks[$current_page] as $key => $item) {
      if (empty($item['title'])) {
        $complete_ode = ag_visualization_ode_get_solr_ode($item['solrid']);
        $chunks[$current_page][$key]['title'] = l($complete_ode['titleStr'], 'ode/view/'. $item['solrid']);
      }
      unset($chunks[$current_page][$key]['solrid']);
    }*/
    // TODO: End

    $filter_form = drupal_get_form('control_center_certifications_visits_filter_form');
    $output = drupal_render($filter_form);

    // Show the appropriate items from the list
    $output .= theme('table', array('header' => $header, 'rows' => $chunks[$current_page]));
    // Show the pager
    $output .= theme('pager', array('quantity',count($rows)));
    $block->content = $output;
  }
  else {
    $filter_form = drupal_get_form('control_center_certifications_visits_filter_form');
    $output = drupal_render($filter_form);
    $output .= t('No results found.');
    $block->content = $output;
  }

  return $block;
}

/**
 * Simple function to sort an array by a specific key. Maintains index association.
 */
function array_sort($array, $on, $order = SORT_ASC) {
  $new_array = array();
  $sortable_array = array();

  if (count($array) > 0) {
    foreach ($array as $k => $v) {
      if (is_array($v)) {
        foreach ($v as $k2 => $v2) {
          if ($k2 == $on) {
            $sortable_array[$k] = $v2;
          }
        }
      } else {
        $sortable_array[$k] = $v;
      }
    }

    switch ($order) {
      case SORT_ASC:
        asort($sortable_array);
        break;
      case SORT_DESC:
        arsort($sortable_array);
        break;
    }

    foreach ($sortable_array as $k => $v) {
      $new_array[$k] = $array[$k];
    }
  }

  return $new_array;
}

/**
 * Implements hook_form()
 * Return exposed filter form to visits list
 */
function control_center_certifications_visits_filter_form($form, $form_state) {
  $form = array();

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($_GET['title']) ? $_GET['title'] : '',
  );

  $form['certified'] = array(
    '#type' => 'select',
    '#title' => t('Certified'),
    '#options' => array(
      'any' => t('Any'),
      'yes' => t('Yes'),
      'no' => t('No')
    ),
    '#default_value' => isset($_GET['certified']) ? $_GET['certified'] : 'any',
  );

  // TODO: Check this (get)
  $form['#method'] = 'get';

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
  );

  return $form;
}
