<?php
/**
 * @file
 * ag_migration.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function ag_migration_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'Agrega2_polls';
  $feeds_importer->config = array(
    'name' => 'Agrega2 Polls',
    'description' => 'Agrega2 Polls',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Título/text()',
          'xpathparser:1' => 'Opciones/Opción/Descripción/text()',
          'xpathparser:2' => '(./Opciones/Opción/Votantes/Perfil/text() | ./Opciones/Opción/Descripción/text())',
          'xpathparser:3' => 'Publicaciones/Publicación/Identificador_Perfil_Publicador/text()',
          'xpathparser:4' => 'Publicaciones/Publicación/Fecha_publicación/text()',
          'xpathparser:5' => 'Identificador/text()',
          'xpathparser:6' => 'Publicaciones/Publicación/Identificador_Comunidad/text()',
          'xpathparser:7' => '(Publicaciones/Publicación/Votos/Voto/Votante/text() | Publicaciones/Publicación/Votos/Voto/Valor/text())',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
        ),
        'context' => '//Encuestas/Encuesta',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'choices',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'votes',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'poll_creator',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'poll_date',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'poll_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'poll_community_id',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'poll_likes',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'poll',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['Agrega2_polls'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_comments';
  $feeds_importer->config = array(
    'name' => 'Agrega2 Comments',
    'description' => 'Agrega2 Comments',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:1' => 'Identificador_Recurso/text()',
          'xpathparser:2' => 'Identificador_Perfil_Publicador/text()',
          'xpathparser:3' => 'Identificador/text()',
          'xpathparser:4' => 'Identificador_Comentario_Padre/text()',
          'xpathparser:5' => 'Descripción/text()',
          'xpathparser:6' => 'Fecha/text()',
          'xpathparser:7' => 'Identificador_Comunidad/text()',
        ),
        'rawXML' => array(
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
        ),
        'context' => '//Comentarios/Comentario',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsCommentProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:1',
            'target' => 'agrega2_comment_nid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'agrega2_comment_uid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'agrega2_comment_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'agrega2_comment_pid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'comment',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'agrega2_comment_date',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'agrega2_comment_community_id',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => 'rich_text',
        'skip_hash_check' => FALSE,
        'bundle' => NULL,
        'expire' => -1,
        'author' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_comments'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_communities';
  $feeds_importer->config = array(
    'name' => 'Agrega2 Communities',
    'description' => 'Agrega2 Communities.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Título/text()',
          'xpathparser:1' => 'Descripción/text()',
          'xpathparser:2' => 'Etiquetas/text()',
          'xpathparser:4' => 'Identificador/text()',
          'xpathparser:5' => 'Visibilidad/text()',
          'xpathparser:6' => 'Imagen/text()',
          'xpathparser:7' => '',
          'xpathparser:8' => 'Identificador/text()',
          'xpathparser:9' => 'FechaCreacion/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
        ),
        'context' => '//Comunidades/Comunidad',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_labels',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_procomun_community_id',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'group_access',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_group_image_icon:uri',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_solrid',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'community_id',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'community_date',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'social_network',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_communities'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_discussions';
  $feeds_importer->config = array(
    'name' => 'Agrega2 Discussions',
    'description' => 'Agrega2 Discussions',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Título/text()',
          'xpathparser:1' => 'Descripción/text()',
          'xpathparser:2' => 'Publicaciones/Publicación/Identificador_Comunidad/text()',
          'xpathparser:3' => 'Publicaciones/Publicación/Identificador_Perfil_Publicador/text()',
          'xpathparser:4' => 'Publicaciones/Publicación/Fecha_publicación/text()',
          'xpathparser:5' => 'Etiquetas/text()',
          'xpathparser:6' => 'Identificador/text()',
          'xpathparser:7' => 'Estado/text()',
          'xpathparser:8' => 'Publicaciones/Publicación/Categorías/Categoría/Nombre/text()',
          'xpathparser:9' => '(Publicaciones/Publicación/Votos/Voto/Votante/text() | Publicaciones/Publicación/Votos/Voto/Valor/text())',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
        ),
        'context' => '//Debates/Debate',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'debate_description',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'debate_community_id',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'debate_user_id',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'debate_date',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'debate_labels',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'debate_id',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'debate_state',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'debate_tags',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:9',
            'target' => 'debate_likes',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'debate',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_discussions'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_ode';
  $feeds_importer->config = array(
    'name' => 'Agrega2 ODE',
    'description' => 'Agrega2 ODE',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => '(./Identificador/text() | ./Identificador_Agrega/text())',
          'xpathparser:1' => '(./Publicaciones/Publicación/Identificador_Comunidad/text() | ./Publicaciones/Publicación/Identificador_Perfil_Publicador/text() | ./Publicaciones/Publicación/Tipo_Publicacion/text() |./Publicaciones/Publicación/Fecha_publicación/text())',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
        ),
        'context' => '//RecursosAprendizaje/RecursoAprendizaje',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'ode_id',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'ode_sharing',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'ode',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_ode'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_organizations';
  $feeds_importer->config = array(
    'name' => 'Agrega2 organizations',
    'description' => 'Import organizations',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Nombre/text()',
          'xpathparser:1' => 'Email/text()',
          'xpathparser:2' => 'Descripción/text()',
          'xpathparser:3' => 'Website/text()',
          'xpathparser:4' => 'Identificador/text()',
          'xpathparser:5' => 'Nombre/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '//Organizaciones/Organización',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          4 => '4',
          3 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'profile2:datos_organizacion:field_descripci_n',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'profile2:datos_organizacion:field_website',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'organization_id',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'profile2:datos_organizacion:field_organization_name',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_organizations'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_posts';
  $feeds_importer->config = array(
    'name' => 'Agrega2 Posts',
    'description' => 'Agrega2 Posts',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Título/text()',
          'xpathparser:2' => 'Etiquetas/text()',
          'xpathparser:3' => 'Autores/text()',
          'xpathparser:4' => 'Autor/text()',
          'xpathparser:5' => '(./Publicaciones/Publicación/Identificador_Comunidad/text() | ./Publicaciones/Publicación/Identificador_Perfil_Publicador/text() | ./Publicaciones/Publicación/Tipo_Publicacion/text() |./Publicaciones/Publicación/Fecha_publicación/text())',
          'xpathparser:6' => 'CompartirPermitido/text()',
          'xpathparser:7' => 'Descripción/text()',
          'xpathparser:8' => 'Identificador/text()',
          'xpathparser:9' => 'Imagen_principal/text()',
          'xpathparser:10' => 'Publicaciones/Publicación/Categorías/Categoría/Nombre/text()',
          'xpathparser:11' => 'Enlace/text()',
          'xpathparser:12' => '(Publicaciones/Publicación/Votos/Voto/Votante/text() | Publicaciones/Publicación/Votos/Voto/Valor/text())',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
        ),
        'context' => '//Recursos/Recurso',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'post_labels',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'post_authors',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'post_author',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'post_community_id',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'post_share',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'post_description',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'post_id',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'post_image',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'post_tags',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'post_link',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'post_likes',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'post',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_posts'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_questions';
  $feeds_importer->config = array(
    'name' => 'Agrega2 Questions',
    'description' => 'Agrega2 Questions',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Título/text()',
          'xpathparser:1' => 'Publicaciones/Publicación/Fecha_publicación/text()',
          'xpathparser:2' => 'Etiquetas/text()',
          'xpathparser:3' => 'Publicaciones/Publicación/Identificador_Comunidad/text()',
          'xpathparser:4' => 'Publicaciones/Publicación/Identificador_Perfil_Publicador/text()',
          'xpathparser:5' => 'Identificador/text()',
          'xpathparser:6' => 'Descripción/text()',
          'xpathparser:7' => 'Publicaciones/Publicación/Categorías/Categoría/Nombre/text()',
          'xpathparser:8' => '(Publicaciones/Publicación/Votos/Voto/Votante/text() | Publicaciones/Publicación/Votos/Voto/Valor/text())',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
        ),
        'context' => '//Preguntas/Pregunta',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'question_date',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'question_labels',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'question_community_id',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'question_user_id',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'question_id',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'question_description',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:7',
            'target' => 'question_tags',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:8',
            'target' => 'question_likes',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'question',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_questions'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'agrega2_users';
  $feeds_importer->config = array(
    'name' => 'Agrega2 users',
    'description' => 'Import users.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml html htm',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'Nombre/text()',
          'xpathparser:2' => 'Email/text()',
          'xpathparser:3' => 'Sexo/text()',
          'xpathparser:4' => 'DNI/text()',
          'xpathparser:5' => '(./País/text() | ./Localidad/text())',
          'xpathparser:6' => '(./País/text() | ./Provincia/text())',
          'xpathparser:7' => 'País/text()',
          'xpathparser:8' => 'Fecha_Nacimiento/text()',
          'xpathparser:9' => '(./Nombre/text() | ./Apellidos/text())',
          'xpathparser:10' => 'Centro_Educativo/text()',
          'xpathparser:11' => '(./Comunidades/Comunidad/Identificador/text() | ./Comunidades/Comunidad/Rol/text())',
          'xpathparser:12' => 'Sigue-A/PerfilSeguido/text()',
          'xpathparser:13' => 'Identificador/text()',
          'xpathparser:14' => 'Recursos_Favoritos/Identificador/text()',
          'xpathparser:15' => 'Identificador_Organización/text()',
          'xpathparser:16' => 'URL_Centro_educativo/text()',
          'xpathparser:17' => 'IdentificadorPersona/text()',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
        ),
        'context' => '//Perfiles/Perfil',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          4 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'name',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'profile2:datos_personales:field_sex',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'profile2:datos_personales:field_dni',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'profile2:datos_personales:field_locality_personal_fc',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'profile2:datos_personales:field_province_personal_fc',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'profile2:datos_personales:field_country_personal_fc',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'profile2:datos_personales:field_date_birth_personal_fc',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'profile2:datos_personales:field_name_surname',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:10',
            'target' => 'profile2:datos_personales:field_edu_center_personal_fc',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_old_procomun_community_id',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_old_procomun_followers',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_old_procomun_user_id',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:14',
            'target' => 'user_favorites',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:15',
            'target' => 'user_organization_id',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:16',
            'target' => 'profile2:datos_personales:field_url_educative_center',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:17',
            'target' => 'user_persona_id',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['agrega2_users'] = $feeds_importer;

  return $export;
}
