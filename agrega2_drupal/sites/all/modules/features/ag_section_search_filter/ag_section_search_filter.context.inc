<?php
/**
 * @file
 * ag_section_search_filter.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ag_section_search_filter_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'search_filter_list';
  $context->description = '';
  $context->tag = 'Search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ode_search' => 'ode_search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-XfaCoysJPGvzy3TEue0eG5m8LizDMw5V' => array(
          'module' => 'facetapi',
          'delta' => 'XfaCoysJPGvzy3TEue0eG5m8LizDMw5V',
          'region' => 'sidebar_first',
          'weight' => '14',
        ),
        'facetapi-d50stxcA0liLdNNu36WQa2ii7BHYrEgL' => array(
          'module' => 'facetapi',
          'delta' => 'd50stxcA0liLdNNu36WQa2ii7BHYrEgL',
          'region' => 'sidebar_first',
          'weight' => '15',
        ),
        'facetapi-QyKK4xlifUbRbbURjglx184uYNAPJBey' => array(
          'module' => 'facetapi',
          'delta' => 'QyKK4xlifUbRbbURjglx184uYNAPJBey',
          'region' => 'sidebar_first',
          'weight' => '16',
        ),
        'facetapi-JX0VKvyKuQPhCZp1EX8to8HLTHbUzWD1' => array(
          'module' => 'facetapi',
          'delta' => 'JX0VKvyKuQPhCZp1EX8to8HLTHbUzWD1',
          'region' => 'sidebar_first',
          'weight' => '17',
        ),
        'facetapi-TLXJ6W16b5ksNOo8r0FtFBjEXshOPYMd' => array(
          'module' => 'facetapi',
          'delta' => 'TLXJ6W16b5ksNOo8r0FtFBjEXshOPYMd',
          'region' => 'sidebar_first',
          'weight' => '18',
        ),
        'facetapi-roc1KSTOx3C0YknUzGiotyrJVjxEGcFR' => array(
          'module' => 'facetapi',
          'delta' => 'roc1KSTOx3C0YknUzGiotyrJVjxEGcFR',
          'region' => 'sidebar_first',
          'weight' => '19',
        ),
        'facetapi-QF5pCllRxixc2I6QzoemING9lq13NI11' => array(
          'module' => 'facetapi',
          'delta' => 'QF5pCllRxixc2I6QzoemING9lq13NI11',
          'region' => 'sidebar_first',
          'weight' => '20',
        ),
        'facetapi-DGDQna1S4A9h3rNYIObowFA4HwnaY4SZ' => array(
          'module' => 'facetapi',
          'delta' => 'DGDQna1S4A9h3rNYIObowFA4HwnaY4SZ',
          'region' => 'sidebar_first',
          'weight' => '21',
        ),
        'facetapi-S2110LVPO8EFLuD3miE1qyyeaYbDjKAo' => array(
          'module' => 'facetapi',
          'delta' => 'S2110LVPO8EFLuD3miE1qyyeaYbDjKAo',
          'region' => 'sidebar_first',
          'weight' => '22',
        ),
        'facetapi-lcnsQqBL6qV0ugkbiTnpHoCR01RCivpB' => array(
          'module' => 'facetapi',
          'delta' => 'lcnsQqBL6qV0ugkbiTnpHoCR01RCivpB',
          'region' => 'sidebar_first',
          'weight' => '23',
        ),
        'facetapi-N1LfGkWHLTUSjH21hcDcSvMgCq8gg0eZ' => array(
          'module' => 'facetapi',
          'delta' => 'N1LfGkWHLTUSjH21hcDcSvMgCq8gg0eZ',
          'region' => 'sidebar_first',
          'weight' => '24',
        ),
        'facetapi-K1PTN04nyUa80OO00NSjBYp1DRV141Fw' => array(
          'module' => 'facetapi',
          'delta' => 'K1PTN04nyUa80OO00NSjBYp1DRV141Fw',
          'region' => 'sidebar_first',
          'weight' => '25',
        ),
        'facetapi-ROZC2fsGftBFe7CUp53fpU14EWC04kY0' => array(
          'module' => 'facetapi',
          'delta' => 'ROZC2fsGftBFe7CUp53fpU14EWC04kY0',
          'region' => 'sidebar_first',
          'weight' => '26',
        ),
        'facetapi-VQ4Dk1zUG0heSr62N8qcLeLQUknmdhSw' => array(
          'module' => 'facetapi',
          'delta' => 'VQ4Dk1zUG0heSr62N8qcLeLQUknmdhSw',
          'region' => 'sidebar_first',
          'weight' => '27',
        ),
        'facetapi-hN0cvmOdSxIblf7EZA6EpTuhm72kZnBx' => array(
          'module' => 'facetapi',
          'delta' => 'hN0cvmOdSxIblf7EZA6EpTuhm72kZnBx',
          'region' => 'sidebar_first',
          'weight' => '28',
        ),
        'facetapi-fZ8hwdrUlnRle1W1cgtUDpfhQb0lMJny' => array(
          'module' => 'facetapi',
          'delta' => 'fZ8hwdrUlnRle1W1cgtUDpfhQb0lMJny',
          'region' => 'sidebar_first',
          'weight' => '29',
        ),
        'facetapi-ma1d52CwfDzxinOtMpP0fh3VnAv7A2oD' => array(
          'module' => 'facetapi',
          'delta' => 'ma1d52CwfDzxinOtMpP0fh3VnAv7A2oD',
          'region' => 'sidebar_first',
          'weight' => '30',
        ),
        'facetapi-xYqfASAcKM6IlyM452hhqmSalTUbqCeU' => array(
          'module' => 'facetapi',
          'delta' => 'xYqfASAcKM6IlyM452hhqmSalTUbqCeU',
          'region' => 'sidebar_first',
          'weight' => '31',
        ),
        'facetapi-KC5Ga0OR3qIiM7XvpFJwXcTNkhpV044K' => array(
          'module' => 'facetapi',
          'delta' => 'KC5Ga0OR3qIiM7XvpFJwXcTNkhpV044K',
          'region' => 'sidebar_first',
          'weight' => '32',
        ),
        'facetapi-fzCyxLtz74DUEZlpbTkXYQm0MPhGcIlw' => array(
          'module' => 'facetapi',
          'delta' => 'fzCyxLtz74DUEZlpbTkXYQm0MPhGcIlw',
          'region' => 'sidebar_first',
          'weight' => '33',
        ),
        'facetapi-u7kuRNB0Zht2QZppRKxShttRtFds0vnf' => array(
          'module' => 'facetapi',
          'delta' => 'u7kuRNB0Zht2QZppRKxShttRtFds0vnf',
          'region' => 'sidebar_first',
          'weight' => '34',
        ),
        'ag_section_search_solr_sarnia-sort-ode-search' => array(
          'module' => 'ag_section_search_solr_sarnia',
          'delta' => 'sort-ode-search',
          'region' => 'content',
          'weight' => '-30',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Search');
  $export['search_filter_list'] = $context;

  return $export;
}
