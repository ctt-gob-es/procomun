/**
 * @file
 *
 * Show Soundcloud upload screen.
 */

(function($){
  Drupal.behaviors.ag_section_podcast = {
    attach : function(context, settings) {
      var upload_message = '<div class="loader">' +
                           '<span class="upload-message">' +
                            Drupal.t('We are uploading the podcast. This may take several minutes, depending on the file size. Please, do not close the browser window until the process is completed...') +
                           '</span></div>';

      $(".form-submit-podcast").click(function() {
        // Validate required fields.
        if (($("#edit-title-field-und-0-value").val().length > 0) &&
            ($("#edit-field-general-language-und option:selected").text() != '_none') &&
            (CKEDITOR.instances['edit-body-und-0-value'].getData().length > 0) &&
            ($("#edit-og-group-ref-und-0-default option:selected").text() != '' &&
              $("#edit-og-group-ref-und-0-default option:selected").text() != '_none') &&
            ($("#edit-podcast-name").val().length > 0) &&
            ($("#edit-podcast-file").val().length > 0)) {
          $('body').append(upload_message);
        }
      });
    }
  };
})(jQuery);
