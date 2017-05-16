(function ($) {
  Drupal.behaviors.dropdownMenu = {
    attach: function (context, settings) {
      // Handle user links when we are logged in:
      $('.block-body', context).once('dropdownMenu', function(){
        $('.block-body').hide();
        $('.logged-in .block-header .user-login .user-image, .not-logged-in .block-header .user-login', context).click(function() {
          // set Active Class:
          $(this).parent().toggleClass('active');
          // Toggl the links:
          $('.block-body').toggle();
          return false;
        });
      });
    }
  };
})(jQuery);
