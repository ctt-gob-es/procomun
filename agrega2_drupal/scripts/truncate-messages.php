<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

db_query('TRUNCATE TABLE {pm_message}');
db_query('TRUNCATE TABLE {pm_index}');
