(function ($) {
// Toggle content when there are too much.
Drupal.behaviors.toggleCommunitiesCommunityWall = {
  attach: function(context, settings) {
    parentSelector = Drupal.settings.ag_general.parent_selector;
    childSelector = Drupal.settings.ag_general.child_selector;
    howContentShow = Drupal.settings.ag_general.how_content_show - 1;

    var $outer_div = $(parentSelector);
    // First, we want to show only first [howContentShow] contents, so we hide the others
    $outer_div.find(childSelector + ':gt(' + howContentShow + ')').hide();

    // Add "See +" / "See -" links as appropriate.
    $outer_div.filter(function() {
      return $(this).find(childSelector + '').length > howContentShow;
    }).each(function() {
      if ($outer_div.siblings('.see-more').length < 1) {
        $('<div class="see-more"><a href="#"></a></div>').text(Drupal.t('See +')).click(function() {
          // And provide them functionality
          if ($(this).siblings().find(childSelector + ':hidden').length > 0) {
            $(this).siblings().find(childSelector + ':gt(' + howContentShow + ')').slideDown();
            $(this).addClass('open').text(Drupal.t('See -'));
          }
          else {
            $(this).siblings().find(childSelector + ':gt(' + howContentShow + ')').slideUp();
            $(this).removeClass('open').text(Drupal.t('See +'));
          }
          return false;
        }).insertAfter($(this));
      }
    });
  }
}

})(jQuery);
