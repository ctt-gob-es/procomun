/**
 * Created by dmarrufo on 4/12/14.
 */
(function ($) {
  Drupal.behaviors.interlinking = {
    attach: function (context, settings) {
      // Handle interlinking process links to show information.
      $(".block-interlinking-process ul.interlinking-list li").find('.wrap-info').hide();
      $(".block-interlinking-process ul.interlinking-list li").once('interlinking', function() {
        $(this).hover(function() {
          $(".block-interlinking-process ul.interlinking-list li").find('.wrap-info').hide();
          $(this).find('.wrap-info').show();
        });
      });

      $(".block-interlinking-process ul.interlinking-list li .wrap-info").mouseleave(function() {
        setTimeout(function(){ $(".block-interlinking-process ul.interlinking-list li").find('.wrap-info').hide(); }, 0);
      });

      // Handle show more link.
      $('.show-more', context).once('interlinking', function () {
        var size_li = $(".block-interlinking-process .content ul.interlinking-list li").size();
        var x = 5;
        // Inicialize elements.
        $('.block-interlinking-process .content ul.interlinking-list li:lt('+x+')').show();

        if (x >= size_li) {
          $('.show-more').hide();
        }

        // Show five elements for iteration.
        $('.show-more').click(function () {
          x = (x+5 <= size_li) ? x+5 : size_li;
          $('.block-interlinking-process .content ul.interlinking-list li:lt('+x+')').show();
          if (x == size_li) {
            $('.show-more').hide();
          }
        });
      });
    }
  };
})(jQuery);
