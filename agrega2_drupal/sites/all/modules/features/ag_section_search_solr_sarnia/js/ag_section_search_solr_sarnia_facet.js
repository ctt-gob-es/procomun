(function ($) {
// Attach behavior to the facet for the home page.
Drupal.behaviors.facethome = {
  attach: function(context, settings) {
      $('ul.facet-home').find('li:gt(' + 3 + ')').hide();
      // Adds "See +" / "See -" links as appropriate.
      $('ul.facet-home').filter(function() {
          return $(this).find('li').length > 3;
      }).each(function() {
          $('<div class="facetapi-limit-link see-more"><a href="#"></a></div>').text(Drupal.t('See +')).click(function() {
              if ($(this).siblings().find('li:hidden').length > 0) {
                  $(this).siblings().find('li:gt(' + 3 + ')').slideDown();
                  $(this).addClass('open').text(Drupal.t('See -'));
              }
              else {
                  $(this).siblings().find('li:gt(' + 3 + ')').slideUp();
                  $(this).removeClass('open').text(Drupal.t('See +'));
              }
              return false;
          }).insertAfter($(this));
      });

      $("#edit-sort").change(function() {
        $("#solr-sarnia-sorting-form").submit();
      });
  }
}

})(jQuery);
