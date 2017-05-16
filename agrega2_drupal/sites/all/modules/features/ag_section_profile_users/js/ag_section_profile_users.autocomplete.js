(function ($) {
  if (Drupal && Drupal.ACDB) {
    // Define our custom Search to add more params to query url:
    Drupal.ACDB.prototype.customSearch = function (searchString, field_conditional) {
      field_orig = field_conditional;
      field_conditional = field_conditional.replace(/_/g, "-");
      //Country selector
      var selector_country = $('#edit_profile_datos_personales_field_country_personal_fc_und_0_field_countries_und_chosen span');
      //Province selector
      var selector_province = $('#edit-profile-datos-personales-field-province-personal-fc-und-0-field-province-und-0-value');
      // Parent item selector.
      var selector_locality = $('#edit-profile-datos-personales-field-locality-personal-fc-und-0-field-locality-und-0-value');
      // Get the url string with our params and call the default search methods:
      switch (field_conditional) {
          case 'field-countries':
              searchString = searchString + "/" + selector_country.text() + "/none/none";
              break;
          case 'field-province':
              searchString = searchString + "/" + selector_country.text() + "/" + selector_province.val() + "/none";
              break;
          case 'field-locality':
              //If it's not Spain, set empty values for provinces and locality
              if (selector_country.text() != 'España') {
                selector_province.val('');
                selector_locality.val('');
              }
              //This case applies for countries other than Spain
              //If its different, set the province and locality with 'none' values
              if (!selector_country.text()) {
                  searchString = searchString + "/none";
              } else {
                  searchString = searchString + "/" + selector_country.text();
              }
              if (!selector_province.val()) {
                  searchString = searchString + "/none";
              } else {
                  searchString = searchString + "/" + selector_province.val();
              }
              if (!selector_locality.val()) {
                  searchString = searchString + "/none";
              } else {
                  searchString = searchString + "/" + selector_locality.val();
              }
              break;
      }
      searchString = searchString + "/" + field_orig;
      return this.search(searchString);
    };
  }
  if (Drupal && Drupal.jsAC) {
    // Override Drupal.jsAC.prototype.populatePopup.
    Drupal.jsAC.prototype.populatePopup = function () {
      var $input = $(this.input);
      var position = $input.position();
      // Show popup.
      if (this.popup) {
        $(this.popup).remove();
      }
      this.selected = false;
      this.popup = $('<div id="autocomplete"></div>')[0];
      this.popup.owner = this;
      $(this.popup).css({
        top: parseInt(position.top + this.input.offsetHeight, 10) + 'px',
        left: parseInt(position.left, 10) + 'px',
        width: $input.innerWidth() + 'px',
        display: 'none'
      });
      $input.before(this.popup);

      // Do search.
      this.db.owner = this;
      // If the item has the flag, we call to our custom search:
      if ($(this.input).attr('custom-autocomplete')) {
        this.db.customSearch(this.input.value, $(this.input).attr('custom-autocomplete'));
      }
      else {
        this.db.search(this.input.value);
      }
    }
  }

  if (Drupal){
    Drupal.behaviors.rebindAutocomplete = function(context) {
      // Unbind the behaviors to prevent multiple search handlers
      $("#edit-your-search-field").unbind('keydown').unbind('keyup').unbind('blur').removeClass('autocomplete-processed');
      // Rebind autocompletion with the new code
      Drupal.behaviors.autocomplete(context);
    }
  }
})(jQuery);
