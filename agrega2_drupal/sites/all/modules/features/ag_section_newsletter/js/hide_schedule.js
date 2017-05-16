(function ($) {
  Drupal.behaviors.agSectionNewsletter = {
    attach: function (context) {
      // Hide/show simplenews schedule date field when scheduled send checkbox changes
      var $scheduled_simplenews_send = $('#edit-newsletter-scheduled-sending-field-simplenews-scheduled-send');
      var $scheduled_simplenews_send_date = $('#edit-newsletter-scheduled-sending-field-simplenews-scheduled-date');
      toggle_simplenews_send_date();

      $scheduled_simplenews_send.change(function() {
        toggle_simplenews_send_date();
      });

      function toggle_simplenews_send_date() {
        if ($scheduled_simplenews_send.is(':checked')) {
          $scheduled_simplenews_send_date.show();
        }
        else {
          $scheduled_simplenews_send_date.hide();
        }
      }
    }
  }
})(jQuery);
