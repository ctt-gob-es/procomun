(function ($) {
  Drupal.behaviors.chosenTheme = {
    attach: function (context) {
      //Define selects that should not be changed by the Chosen library - for example: hierarchical selects
      var exclude_elements = ['.shs-enabled','.shs-select','.fivestar-widget select','#edit-vote--2','.page-admin-control-center #edit-operation', '#control-center-reports-communities-reporting-form select'];
      //Set a min-width for selects in collapsed fieldsets
      $("#edit-ckeditor-lang").chosen({
        width: "14em"
      });
      $("#views-exposed-form-agrega2-favourites-panel-pane-1 #edit-field-categories-tid").chosen({
        width: "100%"
      });
      $("#views-exposed-form-agrega2-favourites-panel-pane-1 #edit-type").chosen({
        width: "100%"
      });
      $("#edit-flagged,#edit-content-type").chosen({
        width: "100%"
      });
      //General settings for all selects
      $("select").not(exclude_elements.join(',')).chosen({
        disable_search_threshold: 10,
        placeholder_text_multiple : Drupal.t("Select Some Options"),
        placeholder_text_single : Drupal.t("Select an Option"),
        no_result_text : Drupal.t("No results match")
      });

      $('select.error').next('.chosen-container').addClass('error');

    }
  }

})(jQuery);
