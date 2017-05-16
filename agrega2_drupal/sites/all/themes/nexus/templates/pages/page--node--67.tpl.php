<!-- Hide the default message of empty content in the home -->
<?php
  if($is_front){
    //$title = ''; // This is optional ... it removes the default Welcome to @site-name
    $page['content']['system_main']['default_message'] = array(); // This will remove the 'No front page content has been created yet.'
  }
?>
<section id="page" class="page-403">
  <?php if($page['user_bar']): ?>
    <div class="user-bar">
      <nav class="container" role="navigation">
        <?php print render ($page['user_bar']); ?>
      </nav>
    </div>
  <?php endif; ?>
  <header id="masthead" class="site-header" role="banner">
    <div class="container container-header">
      <?php if ($page['top_bar']): ?>
      <div class="top-bar">
        <?php print render($page['top_bar']); ?>
      </div>
      <?php endif; ?>
      <div class="logo header-left">
        <div id="logo" class="site-branding">
          <?php if ($logo): ?>
            <div id="site-logo">
              <a href="<?php print $front_page; ?>" title="<?php print $site_name . ' - ' . $site_slogan; ?>"><img src="<?php print $logo; ?>" alt="<?php print $site_name . ' - ' . $site_slogan; ?>" /></a>
            </div>
          <?php endif; ?>
          <div class="branding hide-accessible">
            <div id="site-title">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
           </div>
            <?php if ($site_slogan): ?>
              <div id="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
          </div>
        </div>
      </div>
      <div class="search-zone header-right">
        <div class="info-bar">
          <?php print render ($page['info_bar']); ?>
        </div>
      </div>
      <?php if ($page['nav']): ?>
        <?php print render($page['nav']); ?>
      <?php endif; ?>
    </div>
  </header>

  <?php if($page['preface']) : ?>
    <?php $preface_col = ( 12 / ( (bool) $page['preface'] ) ); ?>
    <section id="preface-area">
      <?php if($page['preface']): ?>
        <div class="preface-block">
          <?php print render ($page['preface']); ?>
        </div>
    <?php endif; ?>
    </section>
  <?php endif; ?>

  <?php if($page['header']) : ?>
    <section id="header-block">
      <div class="container">
        <div class="row">
          <div class="">
            <?php print render($page['header']); ?>
          </div>
        </div>
      </div>
    </section>
  <?php endif; ?>

  <div id="main-content">
    <div class="container">
      <div class="row">
        <?php if(($page['sidebar_first']) && ($page['sidebar_second'])) {
          $content_col = 6;
          $aside_count = 'aside-left aside-right';
        } else if(($page['sidebar_first']) or ($page['sidebar_second'])) {
          $content_col = 9;
          if($page['sidebar_first']) {
            $aside_count = 'aside-left';
          } else {
            $aside_count = 'aside-right';
          }
        } else {
          $content_col = 12;
          $aside_count = '';
        } ?>
        <div id="primary" class="content-area col-md-<?php print $content_col; ?> <?php print $aside_count; ?>">
          <section id="content" role="main" class="clearfix center">
            <?php $url = explode('/', ($_SERVER['REQUEST_URI']));
             $path = explode('/', drupal_get_normal_path($url['2'] . '/' . $url['3']));
             if (is_numeric($path[1]) && $path[0]=='node' && og_is_group('node', node_load($path[1]))){
              print $messages; 
            }
            ?>
            <?php if ($page['content_top']): ?><div id="content_top"><?php print render($page['content_top']); ?></div><?php endif; ?>
            <div id="content-wrap">
              <?php print render($title_prefix); ?>
              <?php print render($title_suffix); ?>
              <?php if (!empty($tabs['#primary'])): ?><div class="tabs-wrapper clearfix"><?php print render($tabs); ?></div><?php endif; ?>
              <?php print render($page['help']); ?>
              <?php if ($action_links): ?>
                <ul class="action-links">
                  <?php print render($action_links); ?>
                </ul>
              <?php endif; ?>
              <?php print render($page['content']); ?>
              <div class="wrap-text-403">
              <?php if ($title): ?>
                <h1 <?php print $title_attributes; ?>>
                  <?php print $title . ' - ' . t('Access denied'); ?>
                </h1>
              <?php endif; ?>
              </div>
              <div class="wrap-text"></div>
            </div>
          </section>
        </div>
        <?php if ($page['sidebar_first']): ?>
          <aside id="sidebar-first" class="col-md-3" role="complementary">
            <?php print render($page['sidebar_first']); ?>
          </aside>
        <?php endif; ?>
        <?php if ($page['sidebar_second']): ?>
          <aside id="sidebar-second" class="col-md-3 pull-right" role="complementary">
            <?php print render($page['sidebar_second']); ?>
          </aside>
        <?php endif; ?>
      </div>
    </div>
  </div>

  <?php if ($page['content_bottom']): ?>
    <section id="content-bottom-block">
      <div class="container">
        <div class="row">
          <div>
            <?php print render($page['content_bottom']); ?>
          </div>
        </div>
      </div>
    </section>
  <?php endif; ?>

  <footer id="colophon" class="site-footer" role="contentinfo">
    <div class="container footer-content">
      <?php if ($page['footer']): ?>
        <div>
          <?php print render($page['footer']); ?>
        </div>
      <?php endif; ?>
      <div class="col-sm-8 lists">
        <div class="footer-links-procomun col-sm-4">
          <?php print render($footer_links_procomun); ?>
        </div>
        <div class="footer-links-help col-sm-4">
          <?php print render($footer_links_help); ?>
        </div>
        <div class="footer-links-visited col-sm-4">
          <?php print render($footer_links_visited); ?>
        </div>
      </div>
      <div class="col-sm-4 social">
        <div class="footer-links-social">
          <?php print render($footer_links_social); ?>
        </div>
      </div>
    </div>

    <div class="footer-wrapper">
      <div class="container">
        <div class="row">
          <div class="logo-footer logo-ministerio first">
            <a href="http://www.mecd.gob.es/" target="_blank">
              <img src="<?php print base_path() . drupal_get_path('theme', 'nexus') . '/images/logo_ministerio.png'; ?>" alt="Logo MECD"/>
            </a>
          </div>
          <div class="logo-footer logo-educalab">
            <a href="http://educalab.es/" target="_blank">
              <img src="<?php print base_path() . drupal_get_path('theme', 'nexus') . '/images/logo_educalab.png'; ?>" alt="Logo EDUCALAB"/>
            </a>
          </div>
          <div class="logo-footer logo-intef">
            <a href="http://educalab.es/intef" target="_blank">
              <img src="<?php print base_path() . drupal_get_path('theme', 'nexus') . '/images/logo_intef.png'; ?>" alt="Logo INTEF"/>
            </a>
          </div>
          <div class="logo-footer logo-red">
            <a href="http://www.red.es/" target="_blank">
              <img src="<?php print base_path() . drupal_get_path('theme', 'nexus') . '/images/logo_red.png'; ?>" alt="Logo RED.es"/>
            </a>
          </div>
          <div class="logo-footer logo-feder last">
            <a href="http://europa.eu/index_es.htm" target="_blank">
              <img src="<?php print base_path() . drupal_get_path('theme', 'nexus') . '/images/logo_feder.png'; ?>" alt="Logo FEDER"/>
            </a>
          </div>
        </div>
        <div class="version">
          <p>
            <?php print t('Version !version', array('!version' => FOOTER_VERSION)); ?>
          </p>
        </div>
      </div>
    </div>
  </footer>
</section>
<?php if (theme_get_setting('grid_display','nexus')): ?>
  <div class="button_grid"></div>
<?php endif; ?>
