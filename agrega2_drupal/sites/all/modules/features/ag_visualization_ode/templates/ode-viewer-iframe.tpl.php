<div class="screenViewer inner-section">
  <div class="header do-inline">
    <div class="iframe-actions do-inline space-l-inline-elements">
      <div class="navigate open">
        <div class="open-menu do-inline">
          <div class="ico ico-navegacion"></div><div class="value"><?php print t('Navigation'); ?></div>
        </div>
        <div class="close-menu do-inline">
          <div class="ico ico-x-green"></div><div class="value"><?php print t('Hide navigation'); ?></div>
        </div>
      </div>
      <div class="fullscreen do-inline">
        <div class="ico ico-fullscreen"></div>
        <div class="value"><?php print $fullscreen_link; ?></div>
      </div>
      <div class="state do-inline maximized">
        <div class="maximize do-inline"><div class="ico ico-maximize"></div><div class="value"><?php print t('Maximize'); ?></div></div>
        <div class="minimize do-inline"><div class="ico ico-minimize"></div><div class="value"><?php print t('Minimize'); ?></div></div>
      </div>
    </div>

    <div class="normal-actions do-inline pull-right space-l-inline-elements">
      <div class="insert do-inline"><div class="ico ico-insertar"></div><div class="value"><?php print t('Insert'); ?></div></div>
      <div class="download">
        <?php print render($download_form); ?>
      </div>
    </div>
  </div>

  <div class="content">
    <div class="normal-actions-holder">
      <div class="insert"><textarea rows="2"><?php print $insert_link; ?></textarea></div>
    </div>
    <iframe style="width: 100%;height:606px;" src="<?php print $ode_visualizer_url; ?>" AllowFullScreen></iframe>
  </div>
</div>
