var gamificationPost = {
  // Number of fields that come autocompleted by default. Don't count language field.
  autofill_fields: 3,
  precision: 1,
  completed: Drupal.t('%'),
  oldValueCK: false,
  oldValueTitle: false,
  oldValueTags: false,
  hasChangedAcon: 0,
  hasChangedCedu: 0,
  hasChangedCom: 0,
  oldCheckedVal: false,
  initialize: function () {
    this.increment = parseInt((100 / this.fields_number).toPrecision(this.precision));
    this.pbVal = this.autofill_fields * this.increment;
    jQuery("#edit-og-group-ref", this.context).once(function () {
      // Add the progress bar.
      var progressBar = '<div class="ode-form-progressbar"><div class="progressbar-title">'
        + Drupal.t('Easy to find this resource') + '</div><div class="arrow"></div><label>'
        + Drupal.t('The progress bar completes as the fields are populated, thus increasing the chances of this resource appear in the search results')
        + '</label><div id="progressbar"></div></div>';
      var percentage = '<span id="progressbar-percentage">0' + gamificationPost.completed + '</span>';
      jQuery(this).parent().parent().append(progressBar);
      jQuery("#progressbar").append(percentage);
      jQuery("#progressbar").append('<div class="slice"><div class="bar"></div><div class="fill"></div></div>');
      jQuery("#progressbar").addClass("c100 green");
    });

    // Progressbar initialization.
    jQuery("#progressbar").progressbar({
      value: parseInt(gamificationPost.pbVal.toPrecision(gamificationPost.precision))
    });
    jQuery("#progressbar").progressbar("option", "value", parseInt(gamificationPost.pbVal.toPrecision(gamificationPost.precision)));
    jQuery("#progressbar-percentage").html(jQuery("#progressbar").attr('aria-valuenow') + gamificationPost.completed);

    // Show or hide text on progressbar.
    jQuery(".arrow").click(function () {
      jQuery(".ode-form-progressbar label").stop(true, true).slideToggle("slow");
      var attribute = jQuery(".arrow").attr("style");
      if (attribute == null) {
        jQuery(".arrow").animate(
          {borderSpacing: -90}, {
            step: function () {
              jQuery(this).css('-webkit-transform', 'rotate(180deg)');
              jQuery(this).css('-moz-transform', 'rotate(180deg)');
              jQuery(this).css('transform', 'rotate(180deg)');
            },
            duration: 'slow'
          }, 'linear');
      }
      else {
        jQuery(".arrow").removeAttr("style");
      }
    });

    var contentwrap = jQuery('#logo');
    var contentbar = jQuery('.ode-form-progressbar');
    var contentwrap_offset = contentwrap.offset();
    jQuery(window).on('scroll', function () {
      if (jQuery(window).scrollTop() > contentwrap_offset.top) {
        contentbar.addClass('progressbar-fixed');
      } else {
        contentbar.removeClass('progressbar-fixed');
      }
    });

    // Bind all events to listen for changes.
    this.bindEvents();

  },
  bindEvents: function () {
    jQuery.each(this.fields, function (key, value) {
      switch (key) {
        case 'titulo':
          if (jQuery(value).val().length > 0) {
            gamificationPost.incrementBar();
            gamificationPost.oldValueTitle = jQuery(value).val();
          }
          jQuery(value).change(function () {
            var currentValue = jQuery(value).val();

            if (gamificationPost.oldValueTitle == false  && jQuery.trim(currentValue) != '') {
              gamificationPost.incrementBar();
              gamificationPost.oldValueTitle = jQuery.trim(currentValue);
            }
            else if (gamificationPost.oldValueTitle != '' && jQuery.trim(currentValue) == '') {
              gamificationPost.decreaseBar();
              gamificationPost.oldValueTitle = jQuery.trim(currentValue);
            }
            return false;
          });
          break;
        case 'miniatura':
            if (jQuery(value).length > 0) {
              gamificationPost.incrementBar();
            }
          break;
        case 'idioma':
          var originalLang = jQuery(value).val();
          if (jQuery(value).val() != '_none') {
            gamificationPost.incrementBar();
          }
          jQuery(value).unbind().change(function () {
            if (jQuery(value).val() != '_none' && originalLang == '_none') {
              gamificationPost.incrementBar();
            }
            else if (jQuery(value).val() == '_none' && originalLang != '_none') {
              gamificationPost.decreaseBar();
            }
            originalLang = jQuery(value).val();
          });
          break;
        case 'cuerpo':
          if (typeof CKEDITOR.instances['edit-body-und-0-value'] != 'undefined') {
            var editor = CKEDITOR.instances['edit-body-und-0-value'];

            if (jQuery.trim(jQuery(editor.getData()).text()) != '') {
              gamificationPost.incrementBar();
            }
          }
          else if (typeof CKEDITOR.instances['edit-body-' + gamificationPost.lang + '-0-value'] != 'undefined') {
            var editor = CKEDITOR.instances['edit-body-' + gamificationPost.lang + '-0-value'];

            if (jQuery.trim(jQuery(editor.getData()).text()) != '') {
              gamificationPost.incrementBar();
            }
          }
          CKEDITOR.on('instanceReady', function (evt) {
            var editor = evt.editor;
            if (jQuery('body.page-node-edit.node-type-post').length) {
              if (jQuery.trim(editor.getData()) != '') {
                gamificationPost.oldValueCK = jQuery.trim(editor.getData());
                gamificationPost.incrementBar();
              }
            }
            editor.on('blur', function () {
              if (jQuery.trim(jQuery(editor.getData()).text()) == '' && gamificationPost.oldValueCK != '' && gamificationPost.oldValueCK != false) {
                gamificationPost.oldValueCK = jQuery.trim(editor.getData());
                gamificationPost.decreaseBar();
              }
              else if ((jQuery.trim(jQuery(editor.getData()).text()) != '' && gamificationPost.oldValueCK == '') || (jQuery.trim(editor.getData()) != '' && gamificationPost.oldValueCK == null)) {
                gamificationPost.oldValueCK = jQuery.trim(editor.getData());
                gamificationPost.incrementBar();
              }
            });
          });
          jQuery('textarea.ckeditor-mod').on('blur', function () {
            var textArea = jQuery('textarea.ckeditor-mod');
            if (jQuery.trim(textArea.val()) == "" && gamificationPost.oldValueCK != "") {
              gamificationPost.decreaseBar();;
            }else if (jQuery.trim(textArea.val()) != "" && gamificationPost.oldValueCK == ""){
              gamificationPost.incrementBar();
            }
            gamificationPost.oldValueCK = jQuery.trim(textArea.val());
          });
          break;
        case 'etiquetas':
          if (jQuery(value).val().length > 0) {
            gamificationPost.incrementBar();
            gamificationPost.oldValueTags = jQuery(value).val();
          }// Need to add normal change event.
          jQuery(value).change(function () {
            var content = jQuery(this).val().split(',');
            var current_value = jQuery.trim(jQuery(this).val());

            if (current_value != '' && content.length == 1 && gamificationPost.oldValueTags == '') {
              gamificationPost.incrementBar();
            }
            else if (current_value == '' && gamificationPost.oldValueTags != '') {
              gamificationPost.decreaseBar();
            }
            else if (gamificationPost.oldValueTags == false && current_value != '') {
              gamificationPost.incrementBar();
            }
            gamificationPost.oldValueTags = current_value;
            return false;
          });
          // This event only runs when autocomplete is triggered.
          jQuery(value, this.context).bind('autocompleteSelect', function (event, node) {
            var content = jQuery(this).val().split(',');
            if (content.length == 1 && (gamificationPost.oldValueTags == '' || gamificationPost.oldValueTags == false)) {
              gamificationPost.incrementBar();
            }
            gamificationPost.oldValueTags = jQuery.trim(jQuery(this).val());
            return false;
          });
          break;
        case 'area_conocimiento':
          if (jQuery(value + " ul.chosen-choices").children().length > 1) {
            this.hasChangedAcon = 1;
            gamificationPost.incrementBar();
          }
          jQuery(document).on('DOMNodeInserted', value + " ul.chosen-choices", function (e) {
            if (jQuery(value + " ul.chosen-choices").children().length > 1 && gamificationPost.hasChangedAcon == 0) {
              gamificationPost.incrementBar();
              gamificationPost.hasChangedAcon = 1;
            }

            return false;
          });

          jQuery(document).on('DOMNodeRemoved', value + " ul.chosen-choices", function (e) {
            if (jQuery(value + " ul.chosen-choices").children().length <= 2 && gamificationPost.hasChangedAcon == 1) {
              gamificationPost.decreaseBar();
              gamificationPost.hasChangedAcon = 0;
            }
            return false;
          });
          break;
        case 'contexto_educativo':
          if (jQuery(value + " ul.chosen-choices").children().length > 1) {
            gamificationPost.hasChangedCedu = 1;
            gamificationPost.incrementBar();
          }
          jQuery(document).on('DOMNodeInserted', value + " ul.chosen-choices", function (e) {
            if (jQuery(value + " ul.chosen-choices").children().length > 1 && gamificationPost.hasChangedCedu == 0) {
              gamificationPost.incrementBar();
              gamificationPost.hasChangedCedu = 1;
            }
            return false;
          });

          jQuery(document).on('DOMNodeRemoved', value + " ul.chosen-choices", function (e) {
            if (jQuery(value + " ul.chosen-choices").children().length <= 2 && gamificationPost.hasChangedCedu == 1) {
              gamificationPost.decreaseBar();
              gamificationPost.hasChangedCedu = 0;
            }
            return false;
          });
          break;
        case 'comunidades':
          if (jQuery(value + " ul.chosen-choices").children().length > 1) {
            gamificationPost.hasChangedCom = 1;
            gamificationPost.incrementBar();
          }
          jQuery(document).on('DOMNodeInserted', value + " ul.chosen-choices", function (e) {
            if (jQuery(value + " ul.chosen-choices").children().length > 1 && gamificationPost.hasChangedCom == 0) {
              gamificationPost.hasChangedCom = 1;
              gamificationPost.incrementBar();
            }
            return false;
          });

          jQuery(document).on('DOMNodeRemoved', value + " ul.chosen-choices", function (e) {
            if (jQuery(value + " ul.chosen-choices").children().length <= 2 && gamificationPost.hasChangedCom == 1) {
              gamificationPost.hasChangedCom = 0;
              gamificationPost.decreaseBar();
            }
            return false;
          });
          break;
        case 'visibilidad':
          if (jQuery(value + " input:checkbox").prop("checked")) {
            gamificationPost.incrementBar();
            gamificationPost.oldCheckedVal = true;
          }
          jQuery(value + " input:checkbox").change(function (e) {
            // We have the following problem here: This event is just fired once when click on this form checkbox,
            // but when we upload any image via AJAX, this event is fired twice resulting on increase/decrease more amount than needed
            // So I came up with checking old value to see if it really changes.
            if (this.checked && gamificationPost.oldCheckedVal == false) {
              gamificationPost.incrementBar();
              gamificationPost.oldCheckedVal = true;
            }
            else if (!this.checked && gamificationPost.oldCheckedVal == true) {
              gamificationPost.decreaseBar();
              gamificationPost.oldCheckedVal = false;
            }
            return false;
          });
          break;
        case 'autores':
          if (jQuery("[id^=" + value.full_name + "]").val().length > 0 || jQuery("[id^=" + value.email + "]").val().length > 0) {
            gamificationPost.incrementBar();
          }
          break;
      }
    });
  },
  incrementBar: function () {
    this.pbVal += this.increment;
    jQuery("#progressbar").progressbar("option", "value", parseInt(this.pbVal));
    jQuery("#progressbar-percentage").html(jQuery("#progressbar").attr('aria-valuenow') + this.completed);
    this.toggleClass();
  },
  decreaseBar: function () {
    this.pbVal -= this.increment;
    jQuery("#progressbar").progressbar("option", "value", parseInt(this.pbVal));
    jQuery("#progressbar-percentage").html(jQuery("#progressbar").attr('aria-valuenow') + this.completed);
    this.toggleClass();
  },
  toggleClass: function() {
    jQuery("#progressbar").removeClass(function (index, css) {
      return (css.match (/(^|\s)p\S+/g) || []).join(' ');
    });
    jQuery("#progressbar").removeClass(function (index, css) {
      return (css.match (/(^|\s)color\S+/g) || []).join(' ');
    });
    jQuery("#progressbar").addClass("p" + jQuery("#progressbar").attr('aria-valuenow'));
    var color;
    switch (Math.floor(this.pbVal/25)) {
      case 0:
        color = "color-red";
        break;
      case 1:
        color = "color-orange";
        break;
      case 2:
        color = "color-yellow";
        break;
      default:
        color = "color-green";
    }
    jQuery("#progressbar").addClass(color);
  }
};

(function ($) {
  Drupal.behaviors.ag_section_post = {
    attach: function (context, settings) {
      if ($("#post-node-form").length) {
        gamificationPost.fields = settings.ag_section_post.article_fields,
        gamificationPost.fields_number = Object.keys(settings.ag_section_post.article_fields).length,
        gamificationPost.context = context;
        // We need to have language, for edit form. CKEDITOR instance comes with current language instead of 'und'.
        gamificationPost.lang = settings.ag_section_post.lang;
        // Initialize all the gamification process.
        gamificationPost.initialize();
      }
    }
  }
})(jQuery);
