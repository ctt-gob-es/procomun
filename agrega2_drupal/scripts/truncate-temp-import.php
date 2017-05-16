<?php

define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

db_query('TRUNCATE TABLE {temp_map_user_id}');
db_query('TRUNCATE TABLE {temp_map_user_community}');
db_query('TRUNCATE TABLE {temp_map_user_followers}');
db_query('TRUNCATE TABLE {temp_map_community_id}');
db_query('TRUNCATE TABLE {temp_map_user_favorites}');


