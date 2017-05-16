(function ($) {
  Drupal.behaviors.contentComunityPublicDashboard = {
    attach: function (context, settings) {
      $('.comunity-public-dashboard-links', context).once('contentComunityPublicDashboard', function(){
        $('.comunity-public-dashboard-links').hide();
        $('.comunity-public-dashboard-header .comunity-link-action', context).click(function() {
          // Set active this element and links
          $(this).toggleClass('active');
          $('.comunity-public-dashboard-links').toggleClass('active');
          // Toggl the links:
          $('.comunity-public-dashboard-links').toggle();

          return false;
        });
      });
    }
  };
})(jQuery);
