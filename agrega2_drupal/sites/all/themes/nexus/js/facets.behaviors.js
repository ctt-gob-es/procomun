(function ($) {
  Drupal.behaviors.nexusFacet = {
    attach: function (context) {
      ///////////////////////////////////

      if (context == document) {
        var Fal = new Facet();
        var activeLinks = Fal.extractActiveLinks();

        if (activeLinks.length) {
          Fal.$appliedFilters.html(activeLinks);
          Fal.$filterExposed.show();
        }
        else {
          Fal.$filterExposed.show();
          Fal.$resultsInfo.hide();
        }

        if (Fal.removeEmptyFacets()) {
          // If the dom was modified let's notify rest of behaviors
          Drupal.attachBehaviors(Fal.$facetAPIContent, {'type': 'facetapi'});
        }
      }
      ///////////////////////////////////
    }
  }

})(jQuery);
