(function ($) {
    Drupal.behaviors.redirectForm = {
        attach: function (context) {
            $("#edit-selector-form-1").click(function () {
                var qs = window.location.search;
                window.location.replace("/" + $('html').attr('lang') + "/node/add/ode" + qs);
            });
        }
    }
})(jQuery);
