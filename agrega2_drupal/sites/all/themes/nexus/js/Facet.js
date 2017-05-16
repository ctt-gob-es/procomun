(function ($) {
  /**
   * Controla todo los relacionado al comportamiento que deben tener
   * los facet y sus elementos desde la perspectiva frontal
   *
   * @constructor
   */
  var Facet = function () {
    this.$facetAPIContent = $('.block-facetapi .content, .pane-facetapi .pane-content');
    // Todos los links que hay en todas las facetas
    this.$markedFacetLinks = this.$facetAPIContent.find('a.facetapi-active');
    this.$filterExposed = $('.ag-filter-exposed');
    this.$resultsInfo = $('.text');
    this.$appliedFilters = this.$filterExposed.find('.applied-filters');
  };

// Métodos.
  Facet.prototype = {

    /**
     * Consigue todos los filtros aplicados en todas las facetas que se
     * encuentren presentes en la página que se ha renderizado.
     */
    extractActiveLinks: function () {
      var self = this;
      var links = [];

      self.$markedFacetLinks.each(function () {
        var $link = $(this);
        // Reemplazamos "(-)" por el nombre del filtro.
        $link.text(self._getTagNodeText($(this).closest('li')));
        // Eliminamos todos los atributos que sobran.
        $link.removeAttr("id class rel");
        links.push($link);
        // Vamos eliminando los item recogidos de la faceta.
        //$link.closest('li').remove();
      });

      return links;
    },

    /**
     * Limpia todos los facet que no contengan elementos.
     *
     * @return bool true si ha cambiado el dom
     */
    removeEmptyFacets: function () {
      var dom_changed = false;

      this.$facetAPIContent.each(function (i, content) {
        var $content = $(content);
        var lis = $content.find('ul li');
        if (!lis.length) $content.parent().remove();
        dom_changed |= !lis.length;
      });

      return dom_changed;
    },

    /**
     * Obtiene el NODE.NodeText de un elemento DOM
     *
     * @param $el jQuery element del cual queremos obtener el texto.
     * @returns {string|nodeValue|*}
     */
    _getTagNodeText: function ($el) {
      return $el.contents().filter(function () {
        return this.nodeType == Node.TEXT_NODE;
      })[0].nodeValue;
    }
  };

  // Exponemos la clase.
  window.Facet = Facet;
})(jQuery);
