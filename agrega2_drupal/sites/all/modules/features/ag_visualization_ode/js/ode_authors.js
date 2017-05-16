/**
 * @file
 *   Custom JavaScript behaviour for authors and editors in the ODE form.
 */
(function ($) {
  Drupal.behaviors.odeAuthors = {
    attach: function (context) {

      var element = $('.field-name-field-contribuciones-ode input');

      element.blur(function () {
        var elementName = $(this).attr('name');

        if (elementName.indexOf('field_organizaci_n') == -1) {
          $.ajax({
            beforeSend: function (data) {
              // Disable all input elements in the AJAX process.
              element.each(function () {
                if ($(this).attr('name')) {
                  var elementName = $(this).attr('name');

                  if (elementName.indexOf('field_organizaci_n') == -1) {
                    $(this).attr('disabled', 'disabled');
                  }
                }
              });
            },
            complete: function (data) {
              // Check if any input is disabled because it is possible for form
              // autocompletion to set some fields as disabled.
              element.each(function () {
                if ($(this).attr('name')) {
                  var elementName = $(this).attr('name');

                  if (elementName.indexOf('field_organizaci_n') == -1) {
                    $(this).removeAttr('disabled');
                  }
                }
              });
            }
          });
        }
      });
    }
  }
})(jQuery);
