/**
 * @file
 *   Custom JavaScript behaviour for learning path form.
 */
(function ($) {
  Drupal.behaviors.learningPath = {
    attach: function (context) {

      // Controls to simulate the multi-step form.
      $('.multi-step-control li a').click(function () {
        var element = $(this).attr('href');

        // Hide elements.
        $('.region-content .block-panels-mini').hide();
        $('.multi-step-control li a').removeClass('active');

        // Show elements.
        $(element).show();
        $(this).addClass('active');
      });

    }
  }
})(jQuery);
