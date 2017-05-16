<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page while offline.
 *
 * All the available variables are mirrored in page.tpl.php. Some may be left
 * blank but they are provided for consistency.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 */
?>
<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <?php print $head; ?>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!--[if lt IE 9]><script src="<?php print base_path() . drupal_get_path('theme', 'nexus') . '/js/html5.js'; ?>"></script><![endif]-->
</head>

<body class="<?php print $classes; ?>" <?php print $attributes;?>>

  
<div id="page" class="clearfix">
  <?php if ($page['user_bar']): ?>
    <div class="user-bar">
      <nav class="container" role="navigation">
        <?php print render($page['user_bar']); ?>
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
              <a href="<?php print $front_page; ?>" title="<?php print $site_name . ' - ' . $site_slogan; ?>">
                <img src="<?php print $logo; ?>" alt="<?php print $site_name . ' - ' . $site_slogan; ?>" />
              </a>
            </div>
          <?php endif; ?>
          <div class="branding hide-accessible">
            <h1 id="site-title">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
           </h1>
            <?php if ($site_slogan): ?>
              <div id="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
          </div>
        </div>
      </div>
      <div class="search-zone header-right">
        <div class="info-bar">
          <?php print render($page['info_bar']); ?>
        </div>
      </div>
      <?php if ($page['nav']): ?>
        <?php print render($page['nav']); ?>
      <?php endif; ?>
    </div>
  </header>

  <?php if ($page['preface']): ?>
    <?php $preface_col = ( 12 / ( (bool) $page['preface'] ) ); ?>
    <section id="preface-area">
      <?php if ($page['preface']): ?>
        <div class="preface-block">
          <?php print render($page['preface']); ?>
        </div>
      <?php endif; ?>
    </section>
  <?php endif; ?>

  <?php if ($page['header']): ?>
    <section id="header-block">
      <div class="container">
        <div class="row">
          <div>
            <?php print render($page['header']); ?>
          </div>
        </div>
      </div>
    </section>
  <?php endif; ?>
  
  <div class="head-ribbon"></div>
  <div class="container"> 
    <div class="row">
      <div id="primary">
        <section id="content" role="main" class="container clearfix">
          <div id="content-wrap">
            <div class="wrap-text">
            <?php print $messages; ?>
            <a id="main-content"></a>
            <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
            <?php print $content; ?><br/><br/>
            </div>
          </div>
        </section> <!-- /#main -->
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
      </div>
    </div>
  </footer>
</div>
</body>
</html>
