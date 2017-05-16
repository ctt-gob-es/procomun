(function ($) {
  Drupal.behaviors.agComments = {
    attach: function (context, settings) {

      $('.comments-hidden-link', context).once('agComments', function () {
        $('.comments-hidden').hide();

        $(this, context).click(function (e) {
          var $this = $(this);
          e.preventDefault();
          var node_nid = this.attributes.node.value;

          if (node_nid != 'undefinded') {
            var comments_hidden = $(this).prev('.comments-hidden');
            // Toggle class active to comments:
            comments_hidden.toggleClass('active');
            // Toggle the comments list:
            comments_hidden.toggle();
            $this.find("a").text(function (i, text) {
              return text === Drupal.settings.comments_hidden.seeTxt ? Drupal.settings.comments_hidden.hideTxt : Drupal.settings.comments_hidden.seeTxt;
            })
          }
        });

      });
    }
  };
})(jQuery);
