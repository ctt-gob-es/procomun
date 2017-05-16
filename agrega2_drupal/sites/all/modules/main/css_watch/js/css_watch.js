Drupal.behaviors.cssWatch = {
  attach: function () {
    var paths = Drupal.settings.cssWatch.paths; // list of css files to watch, relative to page.
    var poll = Drupal.settings.cssWatch.pollInterval;
    var queryString;

    setInterval(function() {
        for(i = 0; i < paths.length; i++){
          var path = paths[i];
          jQuery.ajax({
            url: path,
            async: false, // nothing works without this
            ifModified: true,
            success: function(data, textStatus, jqXHR) {
              if(textStatus != 'notmodified') {
                queryString = '?_'  + new Date().getTime();
                jQuery('link[href^="' + Drupal.settings.cssWatch.domain + path + '"]').attr("href", Drupal.settings.cssWatch.domain + path.replace(/\?.*|$/, queryString));
              }
            }
          });
        }
    }, poll);
  }
};
