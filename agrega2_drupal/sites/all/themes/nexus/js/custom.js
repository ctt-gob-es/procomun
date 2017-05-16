(function ($) {
  Drupal.behaviors.nexusTheme = {
      attach: function (context,settings) {

      $("#views-exposed-form-ode-search-page #edit_type_chosen").once('select-search', function() {
        $(this).width(110);
        $(this).click(function() {
          if ($(this).hasClass('chosen-with-drop')) {
            $(".chosen-results li").each(function() {
              var text = '<a>' + $(this).text() + '</a>';
              $(this).text('');
              $(this).append(text);
            });

            var size_link = 0;
            $(".chosen-results li").click(function() {
              size_link = $(this).children().width();
              $("#edit_type_chosen").width(size_link + 70);
              if ($(this).is(":nth-child(2)")) {
                $("#edit_type_chosen").width(225);
                $("#edit-query").css("padding-left", 235);
                $("#edit-query").focus();
              } else {
                $("#edit-query").css("padding-left", size_link + 80);
                $("#edit-query").focus();
              }
            });
          }
        });
      });

      // Language Menu dropdown
      $('.ag-lang-block', context).once(function(){
        $('.ag-lang-block ul').hide();
        $('.ag-lang-block .current-language', context).click(function() {
          // set Active Class:
          $('.ag-lang-block .current-language').toggleClass('active');
          // Toggle the links:
          $('.ag-lang-block .content ul').toggle();
          return false;
        });
      });

      // Welcome module
      $('.wellcome-close', context).click(function() {
        $('.wellcome-block').hide();
      });

      // Fullscreen button
      $('.fullscreen-button', context).click(function() {
        $(this).toggleClass('collapse');
        $('body:not(.page-ode-search) .center').addClass('fullscreen');
        $('.center').toggleClass('expanded');
        $('.hide-full').toggleClass('active');
        $('.fullscreen').toggleClass('active');
      });

      // FAQs - modal for new question
      $('#ag-section-help-add-faq-form').hide();
      $('.create-question-button', context).click(function() {
        $('#ag-section-help-add-faq-form').toggle();
      });
      $('.cancel-question-button', context).click(function() {
        $('#ag-section-help-add-faq-form').hide();
      });

      // Share networks
      $('.share-outside-networks .wrapper').hide();
      $('.share-outside-networks .toggle-social-networks', context).click(function(e) {
        e.stopImmediatePropagation();
        $(this).next().toggle();
      });

      // Show the page title on Question/Discussion Page
      $('.node-type-question .page-title, .node-type-debate .page-title').removeClass('hide');

      // Alert when close edit/add nodes
      var i18n_es = "Si abandona la página actual sin guardar perderá todos sus cambios";
      var i18n_en = "If you leave the current page without saving you will lose all your changes";
      var i18n_ca = "Si abandona la pàgina actual sense guardar perdrà tots els seus canvis";
      var i18n_eu = "Uneko orrialdea uzten baduzu aurrezteko aldaketa guztiak galduko dituzu gabe";
      var i18n_gl = "Se deixa a páxina actual sen gardar vai perder os seus cambios";
      var askClose = false;
      window[askClose] = false;

       if($('body').hasClass('page-node-add') || $('body').hasClass('page-node-ag-section-newsletter-new') || $('body').hasClass('page-node-ag-section-newsletter-edit') || $('body').hasClass('page-node-edit') ) {
         window[askClose] = true;
       }

       $( 'form #edit-actions .form-submit' ).click( function () {
         window[askClose] = false;
       });


       window.onbeforeunload = askBeforeClose;
       function askBeforeClose() {
         var message = i18n_es;
         var language = 'i18n-es';

         if (window[askClose] && $('body').has('[class*=i18n_]')) {
           var classList = $('body').attr('class').split(/\s+/);

           $.each(classList, function(index, item) {
                 if (item.indexOf('i18n') === 0) {
                    language = item;
                 }
           });
             switch (language) {
               case "i18n-en":
                 message = i18n_en;
                break;
               case "i18n-ca":
                 message = i18n_ca;
                break;
               case "i18n-eu":
                 message = i18n_eu;
                break;
               case "i18n-gl":
                 message = i18n_gl;
                break;
             }
           return message;
         }
       }

      function progressbar(pb, tag) {
        $("#progressbar").removeClass(function (index, css) {
          return (css.match (/(^|\s)p\S+/g) || []).join(' ');
        });
        $("#progressbar").removeClass(function (index, css) {
          return (css.match (/(^|\s)color\S+/g) || []).join(' ');
        });
        switch (tag) {
          case 'text':
          var oldValue = $(pb).attr('oldValue');
          var content = $(pb).val().split(',');
            if ($.trim(oldValue) == '' && $.trim($(pb).val()) != "" || content.length == 1 && oldValue == '') {
              pbVal += increment;
              fullIncrement(pbVal);
            }
            else if ($.trim(oldValue) != '' && $.trim($(pb).val()) == "") {
              fullDecrement(pbVal);
              pbVal -= increment;
            }
            break;
          case 'tag-inc':
            if($(pb + " ul.chosen-choices").children().length == 2) {
              pbVal += increment;
              fullIncrement(pbVal);
            }
            break;
          case 'tag-dec':
            if ($(pb + " ul.chosen-choices").children().length <= 2) {
              fullDecrement(pbVal);
              pbVal -= increment;
            }
            break;
          case 'upload':
            if($(pb)) {
              pbVal += increment;
              fullIncrement(pbVal);
            }
            else {
              fullDecrement(pbVal);
              pbVal -= increment;
            }
            break;
          case 'author':
            if ($("[id^=" + nombre_autor + "]").val().length > 0 || $("[id^=" + correo_autor + "]").val().length > 0) {
              pbVal += increment;
              fullIncrement(pbVal);
            }
            break;
          case 'radio':
            if(!hasCheckedAp) {
              $(pb).each(function( index, value ) {
                if($(value).is(':checked')) {
                  hasCheckedAp = true;
                  pbVal += increment;
                  fullIncrement(pbVal);
                  return false;
                }
              });
            }
            break;
          case 'language':
            if ($(pb).val() != '_none' && ($(pb).attr('oldValue') == '_none')) {
              //$(pb).attr('oldValue', $(pb).val());
              pbVal += increment;
              fullIncrement(pbVal);
            }
            else if ($(pb).val() == '_none' && $(pb).attr('oldValue') != '_none') {
              //$(pb).attr('oldValue', '_none');
              fullDecrement(pbVal);
              pbVal -= increment;

            }
            break;
        }
        var color;
        switch (Math.floor(pbVal/25)) {
          case 0:
            color = 'color-red';
            break;
          case 1:
            color = 'color-orange';
            break;
          case 2:
            color = 'color-yellow';
            break;
          default:
            color = 'color-green';
        }
          $("#progressbar").addClass(color);
          $("#progressbar").progressbar("option", "value", parseInt(pbVal, 10));
          $("#progressbar-percentage").html(pbVal + completed);
          $("#progressbar").addClass("p" + pbVal);
          return false;
      }
      // Hide/show simplenews schedule date field when scheduled send checkbox changes
/*      var $scheduled_simplenews_send = $('#edit-field-simplenews-scheduled-send-und');
      var $scheduled_simplenews_send_date = $('#edit-field-simplenews-scheduled-date');
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
      }*/

      /*
       * Unobfuscate footer contact email using ROT13
       */
      var contact_email = $('.contact_email');

      if (contact_email.length > 0) {
        contact_email.once('contact_email', function () {
          var email = contact_email.attr('href').split(':');
          contact_email.attr('href', 'mailto:' + email[1].replace(/[a-z]/gi, function(s) { return String.fromCharCode(s.charCodeAt(0) + (s.toLowerCase() < 'n' ? 13 : -13)); }));
        });
      }

      /*
       * Unobfuscate help_section contact email using ROT13
       */
      var help_contact_email = $('#contact-us');

      if (help_contact_email.length > 0) {
        help_contact_email.once('help_contact_email', function () {
          var email = help_contact_email.attr('href').split(':');
          help_contact_email.attr('href', 'mailto:' + email[1].replace(/[a-z]/gi, function(s) { return String.fromCharCode(s.charCodeAt(0) + (s.toLowerCase() < 'n' ? 13 : -13)); }));
        });
      }


      /**
       * Modal Badge
       */
       $('body').append('<div class="js-badge-screen badge-screen"></div>');
       //$('body').append('<div class="js-badge-screen badge-screen"></div>');
       $('.user-mozilla-badges-item img', context).once('badges', function () {
         $(this).click(function () {
          $(this).parent().find('.user-mozilla-badges-metadata').toggleClass('is-visible');
          $('.js-badge-screen').toggleClass('is-visible');
        });
       });
      // Close badge
       $('.close-badge-icon, .js-badge-screen', context).once('badgeclose', function () {
        $(this).click(function (e) {
          e.preventDefault();
          $('.user-mozilla-badges-metadata, .js-badge-screen').removeClass('is-visible');
        });
       });

      /**
       * Grid system helper switch button.
       *
       * Shows the grid system column positions for help.
       **/
      $(".button_grid").once('btn-grid', function () {
        $(this).click(function () {
          $("body").toggleClass("grid");
        });
      });

      /**
       * Seteamos placeholders en general.
       **/
      var search_placeholder = Drupal.t('Search...');
      var user_name_placeholder = Drupal.t('USER');
      var user_password_placeholder = Drupal.t('PASSWORD');
      $("#edit-query").attr("placeholder", search_placeholder);
      $("#edit-name").attr("placeholder", user_name_placeholder);
      $("#edit-name--2").attr("placeholder", user_name_placeholder);
      $("#edit-pass").attr("placeholder", user_password_placeholder);
      $("#edit-pass--2").attr("placeholder", user_password_placeholder);
      $(".block-system #edit-name").attr("placeholder", '');

      $("#facetapi-facet-search-apisarnia-ode-search-block-type li a").each(function() {
        var type = $(this).attr("href").split("type=");
        $(this).addClass(type['1'].toLowerCase());
      });

      $( ".block-facetapi ul li.leaf a" ).each(function() {
        var cadena_real = $(this).text();
        // Add results number if the tag if selected too
        var cadena_count = cadena_real.split(",");
        if (cadena_count.length == 2 && !$(this).parent().hasClass("selected")) {
          $(this).parent().append('<span class="pull-right">' + cadena_count['0'] + '</span>');
          $(this).parent().addClass("selected");
        }
        else {
          var cadena_filtro = cadena_real.split(" Apply");
          var array_cadena = cadena_filtro['0'].split('(');
          var texto_filtro = array_cadena['0'];
          var text_slice = texto_filtro.length;
          if (text_slice >= '30') {
            var text_ellipsis = texto_filtro.slice(0,28) + '…';
          } else {
            var text_ellipsis = texto_filtro;
          }

          if (array_cadena['2']) {
            var clean_number = array_cadena['2'].split(')');
            $(this).html(text_ellipsis + '<span class="pull-right">' + clean_number['0'] + '</span>');
          } else if (array_cadena['1']) {
            var clean_number = array_cadena['1'].split(')');
            $(this).html(text_ellipsis + '<span class="pull-right">' + clean_number['0'] + '</span>');
          }
        }
      });

      // Si no quedan mas facetas en sidebar, eliminamos el sidebar.
      // Esta es una solución implementada a nivel global. No hace falta usar if()
      // ni preocuparse por los efectos que este script pueda tener en general.
      if ($('#sidebar-first > section > *').length == 0) $('#primary').removeClass('aside-left');
      if ($('.panel-ag-3up-6-3 .panel-col-first .block-facetapi').length == 0) $('.panel-ag-3up-6-3 .col-md-6').removeClass('col-md-6').addClass('col-md-9');
      if ($('.panel-ag-3up-6-3 .panel-col-first .block-facetapi').length == 0) $('.panel-ag-3up-6-3 .panel-col-first').remove();
      ////////////////////////////////////
      $(".form-item-field-certified-und label").click(function () {
        $(this).toggleClass("active");
      });
      ///////////////////////////////////
      //* de obligatorio puesto en fecha del perfil.
      $("#profile-datos-personales-field-date-birth-personal-fc-und-0-field-date-birth-add-more-wrapper legend span.form-required").appendTo(".form-item-profile-datos-personales-field-date-birth-personal-fc-und-0-field-date-birth-und-0-value-date label");
      ///////////////////////////////////
      // Colocacion de botones de check junto a los de previsualizar y guardar, hay que tocar el buttons.sass y el recurso de aprendizaje.sass
      $("#recurso-de-aprendizaje-node-form .form-item-field-certified-und").appendTo("#edit-actions");
      $("#ode-node-form .form-item-field-certified-und").appendTo("#edit-actions");

      ///////////////////////////////////
      $("#views-form-og-members-admin-default .form-type-select.form-item-operation").appendTo("#views-form-og-members-admin-default > div");
      $("#views-form-og-members-admin-default input.form-submit").appendTo("#views-form-og-members-admin-default > div");
      ///////////////////////////////////
      ///////////////////////////////////
      $(".detail-ode #accordion .panel-body").addClass('hide');
      $(".panel-heading.highlight-header").once('panel-heading',function(){
        $(this).click(function () {
          $(this).parent().toggleClass('active');
          $(this).next().toggleClass('showhide');
          label_adjust($('.detail-ode #accordion .panel-body label'),'div');
        });
      });
      /*
      *  Adjust the grey labels in their height to the next element
      */
      var label_adjust_height = $('.field-label').filter(function() {return $(this).css('float') === 'left' && $(this).css('background-color') === 'rgb(242, 242, 242)';});
      label_adjust = function(label,content){
        label.each(function(){
          contentel = $(this).next(content);
          if((tpx=Math.abs($(this).outerHeight()-contentel.outerHeight()))!==0) {
            $(this).outerHeight()<contentel.outerHeight() ? el = $(this) : el = contentel;
            $(el).css({'padding-bottom': ((tpx/2)+parseInt($(el).css('padding-bottom'))),'padding-top': ((tpx/2)+parseInt($(el).css('padding-top')))});
          }
        });
      }
      label_adjust(label_adjust_height,".field-items");
      label_adjust(label_adjust_height,".field-item");
      label_adjust(label_adjust_height,".item-list");
      if($('.page-user').length) {$('.page-user .nav-tabs li a').click(function(){setTimeout(function(){label_adjust(label_adjust_height,".field-item");},100);});}
      $(".modal-body #comment-body-add-more-wrapper .text-format-wrapper fieldset.filter-wrapper").appendTo(".modal-body #comment-body-add-more-wrapper .text-format-wrapper");
      /*
      * Add active class to facetapi Filters to hide and show them on small screens
      */
      $(".block-facetapi > h3").once('h3-block-facetapi', function () {
        $(this).click(function () {
          $(this).toggleClass("active");
          $(this).parent().find('.content').stop().slideToggle();
        });
      });
      $("#views-exposed-form-agrega2-favourites-panel-pane-1 .views-exposed-widget > label").once('label', function () {
        $(this).click(function (e) {
          e.preventDefault();
          $(this).toggleClass("active");
          $(this).parent().find('.views-widget').stop().slideToggle(200);
          return false;
        });
      });
      ///////////////////////////////////
      if($('body.page-node-add').length){
        var txtshow = Drupal.t('Show Summary'); var txthide = Drupal.t('Hide Summary');
        $('.link-edit-summary').click(function(e){
          e.preventDefault();
          if($('.text-summary-wrapper').hasClass('hide')){$('.text-summary-wrapper').removeClass('hide').show().find('label').append($('.form-item-body-und-0-value > label').find('.field-edit-link a').text(txthide).parent());}
          else{$('.form-item-body-und-0-value > label').append($('.text-summary-wrapper').addClass('hide').hide().find('.field-edit-link a').text(txtshow).parent());}
          return false;
        });
      }
      if($('.node-question.node-teaser,.node-debate.node-teaser').length){
        var questiontext=Drupal.t("Question");var debatetext=Drupal.t("Debate");
        /* Añado el span para el hover con el data-translate correspondiente */$('.node-question,.node-debate').each(function(){$(this).hasClass('node-question') ? $(this).append('<span class="tooltip" data-translate="'+questiontext+'"></span>') : $(this).append('<span class="tooltip" data-translate="'+debatetext+'"></span>');});
        /* Hover effect */$('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      // Animate width/height to auto
      jQuery.fn.animateAuto = function(prop, speed, callback){
          var elem, height, width;
          return this.each(function(i, el){
              el = jQuery(el), elem = el.clone().css({"height":"auto","width":"auto","font-size":"18px"}).appendTo("body");
              console.log(elem);
              height = elem.css("height"),
              width = elem.css("width"),
              elem.remove();
              if(prop === "height")
                  el.animate({"height":height}, speed, callback);
              else if(prop === "width")
                  el.animate({"width":width}, speed, callback);
              else if(prop === "both")
                  el.animate({"width":width,"height":height}, speed, callback);
          });
      }

      // Remove newsletter subscription notification message.
      if ($(".newsletter-notificacion").text().length > 60) {
        $(".message-status").delay(2000).fadeOut(1000);
      };

      // Remove webinar subscription notification message.
      $(".subscribe-notification .message-status").delay(2000).fadeOut(1000);

      /* Imágenes por defecto y diferenciación en el buscador de tipo de resultado */
      if($('body.page-ode-search').length){
        $('.avatar').parent().parent().parent().addClass('avatar');
      }
      if($('.question-result').length){
        var text=Drupal.t("Question");
        $('.question-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.user-result').length){
        var text=Drupal.t("Usuario");
        $('.user-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.community-result').length){
        var text=Drupal.t("Community");
        $('.community-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.event-result').length){
        var text=Drupal.t("Event");
        $('.event-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.ode-result').length){
        var text=Drupal.t("ODE");
        $('.ode-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.post-result').length){
        var text=Drupal.t("Post");
        $('.post-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.debate-result').length){
        var text=Drupal.t("Debate");
        $('.debate-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      if($('.response-result').length){
        var text=Drupal.t("Respuesta");
        $('.response-result .image').each(function(){$(this).append('<span class="tooltip" data-translate="'+text+'"></span>');});
        $('span.tooltip').hover(function(e){$(this).addClass('content-tooltip'); },function(e){$(this).removeClass('content-tooltip'); });
      }
      /* Mensajes privados: recolocando boton */
      if(!$('.new-msg-button').length) $('#privatemsg-list-form>.container-inline').prepend(window.btn);
      $('#privatemsg-list-form>.container-inline').prepend($('body.page-messages .action-links li a').addClass('new-msg-button'));window.btn=$('.new-msg-button');
      $('body.page-messages #content div.content #privatemsg-list-form').append($('body.page-messages #privatemsg-list-form>.container-inline .form-type-select'));
      $('body.page-messages #content div.content > .form-type-select').length > 1 ? $('body.page-messages #content div.content > .form-type-select').first().remove() : null ;
      $('body.page-messages-view .privatemsg-message-actions li.first a').attr('title',Drupal.t('Delete Message')).prepend('<i class="glyphicon glyphicon-trash"></i> ');
      /* Suscribers : recolocando botones y solucionando problemas del Chosen */
      if($('body.page-ag-section-newsletter').length){
        $('#ag-section-newsletter-admin-subscription,#ag-section-newsletter-admin-newsletter-issues').find('legend').hide();
        $('#ag-section-newsletter-admin-subscription,#ag-section-newsletter-admin-newsletter-issues').append($('#edit-options .fieldset-wrapper'));
        $('.new-newsletter-link').appendTo($('#ag-section-newsletter-admin-newsletter-issues .fieldset-wrapper')).find('a').prepend('<i class="glyphicon glyphicon-plus"></i> ');
        $('p.simplenews-last-cron').appendTo($('#ag-section-newsletter-admin-newsletter-issues .fieldset-wrapper'));
      }
      if($('body.page-admin-control-center').length){
        $('.container-inline').find('legend').hide();
        $('.panel-display .col-sm-9').removeClass('col-sm-9').addClass('col-sm-12').parent().find('.col-sm-3').remove();
        $('.page-admin-control-center:not(.page-admin-control-center-community-users) .pane-views-panes .pane-content .vbo-views-form form').append($('.page-admin-control-center .pane-content .item-list'));
        $('.page-admin-control-center .pane-views-panes .pane-content .vbo-views-form form').append($('.page-admin-control-center .pane-content #edit-select'));
      }
      //Remove VBO buttons from og-members-admin until they may be fixed.
      if($('.view-og-members-admin .vbo-table-select-this-page.form-submit').length){
        $('.view-og-members-admin .vbo-table-select-this-page.form-submit').hide();
      }
      if($('.view-og-members-admin .vbo-table-select-all-pages.form-submit').length){
        $('.view-og-members-admin .vbo-table-select-all-pages.form-submit').hide();
      }
      // Gestión de usuarios de comunidades en el Control Center: recolocando botones
      if ($('#views-form-agrega2-communities-user-administration-page')) {
        $('#views-form-agrega2-communities-user-administration-page>div>#edit-select').appendTo('#views-form-agrega2-communities-user-administration-page>div');
      }

      // Tooltip para el link de "Compartir en Procomun"
      if ($("#share-link").length > 0) {
        $("#share-link").tooltip();
      }

        //Añadir la barra de progreso
        if ($("#ode-node-form").length || $("#ode-node-form--2").length) {
            // Every time we update the progressbar, we need to check this. As we need integer numbers to show progress
            // we need to have a rounded increment. In this case we have 19 fields, so we will have a increment of 5.26
            // rounded to 5. So we can have a max of 95% value (19*5). That's why we increase to 100% when current_value
            // is 95 or more. If we round to highest nearest integer, we will have 6 so only with filling 17 fields we are
            // over 100% progress, and we don't want that. A possible solution will be to have an internal value with
            // decimals and round it on progressbar class.
            var fullIncrement = function(current_value) {
              if(parseInt(current_value) >= 95) {
                pbVal += 0;
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
              }
            };
            var fullDecrement = function(current_value) {
              if(parseInt(current_value) >= 100) {
                pbVal -= 0;
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
              }
            };

            var fields = 20;
            var autofill_fields = 6;
            var precision = 1;
            var increment = parseInt((100 / fields).toPrecision(precision));
            var pbVal = autofill_fields * increment;
            var completed = Drupal.t('%');

            $("#edit-og-group-ref", context).once(function() {
                //Add the progress bar.
                var progressBar = '<div class="ode-form-progressbar"><div class="progressbar-title">'
                    + Drupal.t('Easy to find this resource') + '</div><div class="arrow"></div><label>'
                    + Drupal.t('The progress bar completes as the fields are populated, thus increasing the chances of this resource appear in the search results')
                    + '</label><div id="progressbar"></div></div>';
                var percentage = '<span id="progressbar-percentage">0' + completed +'</span>';
                $(this).parent().parent().append(progressBar);
                $("#progressbar").append(percentage);
                $("#progressbar").append('<div class="slice"><div class="bar"></div><div class="fill"></div></div>');
                $("#progressbar").addClass("c100");
            });

            //Inicializar progressbar
            $("#progressbar").progressbar({
                value: 0
            });
            $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
            $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);

            //Inicialización de la barra de progreso en la carga de la página

            //Título
            var oldTitle = '';
            if ($(settings.nexusTheme.fields.titulo).val().length > 0) {
                pbVal += increment;
                oldTitle = $(settings.nexusTheme.fields.titulo).val();
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //Idioma
            $(settings.nexusTheme.fields.idioma).attr('oldValue','_none');
            progressbar(settings.nexusTheme.fields.idioma, 'language');

            //Descripción
            if ($(settings.nexusTheme.fields.descripcion).val().length > 0) {
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //Conocimiento previo
            if ($(settings.nexusTheme.fields.conocimiento_previo).val().length > 0) {
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //Objetivos didáctivos
            if ($(settings.nexusTheme.fields.objetivos_didacticos).val().length > 0) {
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //Etiquetas (field_keywords)
            var oldValueEt = $("input[name='" + settings.nexusTheme.fields.etiquetas + "']").val();
            if (oldValueEt != '') {
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //Archivo adjunto
            if ($('.file-widget .file').length) {
              progressbar('.file-widget .file', 'upload');
            }

            //Área de conocimiento
            var hasChangedAcon = 0;
            if ($(settings.nexusTheme.fields.area_conocimiento + " ul.chosen-choices").children().length > 1){
                hasChangedAcon = 1;
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //Contexto educativo
            var hasChangedCedu = 0;
            if ($(settings.nexusTheme.fields.contexto_educativo + " ul.chosen-choices").children().length > 1){
                hasChangedCedu = 1;
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            //var hasCheckedEd = $("input[name='" + settings.nexusTheme.fields.recurso_educativo + "']").attr('oldValue');
            var hasCheckedAp = $("input[name='" + settings.nexusTheme.fields.recurso_aprendizaje + "']").attr('oldValue');
            //Recurso educativo
            //progressbar("input[name='" + settings.nexusTheme.fields.recurso_educativo + "']", 'radio');


            //Recurso de aprendizaje
            progressbar("input[name='" + settings.nexusTheme.fields.recurso_aprendizaje + "']", 'radio');

            //Idioma destinatario
            $(settings.nexusTheme.fields.idioma_destinatario).attr('oldValue','_none');
            progressbar(settings.nexusTheme.fields.idioma_destinatario, 'language');

            //Imagen miniatura
            if ($(settings.nexusTheme.fields.imagen_miniatura).length > 0) {
              progressbar(settings.nexusTheme.fields.imagen_miniatura, 'upload');
            }

            //Comunidades
            var hasChangedCom = 0;
            if ($(settings.nexusTheme.fields.comunidades + " ul.chosen-choices").children().length > 1){
                hasChangedCom = 1;
                pbVal += increment;
                fullIncrement(pbVal);
                $( "#progressbar" ).progressbar( "option", "value", parseInt(pbVal, 10));
                $("#progressbar-percentage").html($("#progressbar").attr('aria-valuenow') + completed);
            }

            var nombre_autor = settings.nexusTheme.fields.nombre_autor;
            var correo_autor = settings.nexusTheme.fields.correo_autor;
            progressbar(null, 'author')

            pbVal = parseInt(pbVal, 10);
            $("#progressbar").addClass("p"+ pbVal);

            //Actualización dinámica de la barra de progreso

            //Título
            $(settings.nexusTheme.fields.titulo).focus(function(){
                $(this).attr('oldValue',$(this).val());
            });

            $(settings.nexusTheme.fields.titulo).change(function() {
              progressbar(settings.nexusTheme.fields.titulo, 'text');
            });

            //Idioma
            $(settings.nexusTheme.fields.idioma).unbind().change(function() {
              progressbar(settings.nexusTheme.fields.idioma, 'language');
            });
            //Descripción
            $(settings.nexusTheme.fields.descripcion).focus(function(){
                $(this).attr('oldValue',$(this).val());
            });

            $(settings.nexusTheme.fields.descripcion).change(function() {
               progressbar(settings.nexusTheme.fields.descripcion, 'text');
            });

            //Conocimiento previo
            $(settings.nexusTheme.fields.conocimiento_previo).focus(function(){
                $(this).attr('oldValue',$(this).val());
            });

            $(settings.nexusTheme.fields.conocimiento_previo).change(function() {
              progressbar(settings.nexusTheme.fields.conocimiento_previo, 'text');
            });

            //Objetivos didáctivos
            $(settings.nexusTheme.fields.objetivos_didacticos).focus(function(){
                $(this).attr('oldValue',$(this).val());
            });

            $(settings.nexusTheme.fields.objetivos_didacticos).change(function() {
              progressbar(settings.nexusTheme.fields.objetivos_didacticos, 'text');
            });

            // Etiquetas (field_keywords).
            var tagField = "input[name='" + settings.nexusTheme.fields.etiquetas + "']";
            $(tagField).focus(function(){
              $(this).attr('oldValue',$(this).val());
            });
            $(tagField).change(function() {
              progressbar(tagField, 'text');
            });
            $(tagField).bind('autocompleteSelect', function (event, node) {
              progressbar(tagField, 'text');
            });

            // Archivo adjunto (Name).
            //$("input[name='" + settings.nexusTheme.fields.archivo_adjunto + "']").focus(function(){
            //    $(this).attr('oldValue',$(this).val());
           // });

           // $("input[name='" + settings.nexusTheme.fields.archivo_adjunto + "']").change(function() {
           //   progressbar("input[name='" + settings.nexusTheme.fields.archivo_adjunto + "']", 'text');
          //  });
            // Archivo adjunto (upload).
            $(settings.nexusTheme.fields.archivo_adjunto ).change(function() {
              progressbar(settings.nexusTheme.fields.archivo_adjunto, 'upload');
            });
            // Área de conocimiento.
            $(settings.nexusTheme.fields.area_conocimiento + " ul.chosen-choices").bind('DOMNodeInserted', function(e) {
              progressbar(settings.nexusTheme.fields.area_conocimiento, 'tag-inc');
            });
            $(settings.nexusTheme.fields.area_conocimiento + " ul.chosen-choices").bind('DOMNodeRemoved', function(e) {
              progressbar(settings.nexusTheme.fields.area_conocimiento, 'tag-dec');
            });

            //Contexto educativo
            $(settings.nexusTheme.fields.contexto_educativo + " ul.chosen-choices").bind('DOMNodeInserted', function(e) {
                progressbar(settings.nexusTheme.fields.contexto_educativo, 'tag-inc');
            });
            $(settings.nexusTheme.fields.contexto_educativo + " ul.chosen-choices").bind('DOMNodeRemoved', function(e) {
                progressbar(settings.nexusTheme.fields.contexto_educativo, 'tag-dec');
            });

            //Recurso educativo
            //$("input[name='" + settings.nexusTheme.fields.recurso_educativo + "']").change(function () {
            //  progressbar("input[name='" + settings.nexusTheme.fields.recurso_educativo + "']", 'radio');
            //});

            //Recurso de aprendizaje
            $("input[name='" + settings.nexusTheme.fields.recurso_aprendizaje + "']").change(function (){
              progressbar("input[name='" + settings.nexusTheme.fields.recurso_aprendizaje + "']", 'radio');
            });

            //Idioma destinatario
            $(settings.nexusTheme.fields.idioma_destinatario).bind().change(function() {
               progressbar(settings.nexusTheme.fields.idioma_destinatario, 'language');
             });

            //Comunidades
            $(settings.nexusTheme.fields.comunidades + " ul.chosen-choices").bind('DOMNodeInserted', function(e) {
                progressbar(settings.nexusTheme.fields.comunidades, 'tag-inc');
            });
            $(settings.nexusTheme.fields.comunidades + " ul.chosen-choices").bind('DOMNodeRemoved', function(e) {
                progressbar(settings.nexusTheme.fields.comunidades, 'tag-dec');
            });

            // Muestra u oculta el texto de la barra de progreso
            $( ".arrow" ).click(function() {
              $( ".ode-form-progressbar label" ).stop(true, true).slideToggle("slow");
              var attribute = $( ".arrow" ).attr("style");
              if(attribute == null){
                $( ".arrow" ).animate(
                  {  borderSpacing: -90 }, {
                    step: function() {
                      $(this).css('-webkit-transform','rotate(180deg)');
                      $(this).css('-moz-transform','rotate(180deg)');
                      $(this).css('transform','rotate(180deg)');
                  },
                  duration:'slow'
                  },'linear');
              }else{
                $( ".arrow" ).removeAttr("style");
              }
            });


             var contentwrap = $('#logo');
             var contentbar = $('.ode-form-progressbar');
             var contentwrap_offset = contentwrap.offset();
             $(window).on('scroll', function() {
               if($(window).scrollTop() > contentwrap_offset.top) {
                contentbar.addClass('progressbar-fixed');
               } else {
                contentbar.removeClass('progressbar-fixed');
               }
             });
      }

      // Hide the submit button and add one down in add/edit newsletter
      $("input[name='newsletter-submit']").hide();
      if (typeof context.location != 'undefined') {
        $("div.panel-pane.pane-views-panes.pane-ag-newsletter-panel-pane-2").append('<div id="newsletter-submit-button" class="form-submit">' + Drupal.t("Save") + '</div>');
      }

      // Show confirm save without content message and save submit form
      $("#newsletter-submit-button").click(function(e) {
        e.stopImmediatePropagation();
        window[askClose] = false;
        if (!$("#draggableviews-table-ag-newsletter-panel-pane-2").length) {
          var r = confirm(Drupal.t("Really you don't want to add content before creating the newsletter"));
          if (r == true) {
            window[askClose] = false;
            $( "#ag-section-newsletter-generate-newsletter-form" ).submit();
          }
          else {
            window[askClose] = true;
          }
        }
        else {
          window[askClose] = false;

          // Create related content array
          var content_ref_weight = {}
          var i = 0;
          $("div[class^='form-item form-type-select form-item-draggableviews-']").each(function() {
            content_ref_weight[i] = $(this).next().val();
            i++;
          });

          // Pass related content array by POST
          var postData = JSON.stringify(content_ref_weight);
          $("#ag-section-newsletter-generate-newsletter-form").closest("form")
              .append($("<input>", {"type":"hidden", "name":"content_ref_weight", "value":postData}));

          // Submit call for newsletter form
          $("#ag-section-newsletter-generate-newsletter-form").submit();
        }
      });

      // Select content toggle
      $("#newsletter-select-content h2.pane-title").click(function(e){
        e.stopImmediatePropagation();
        $(this).next().slideToggle(500);
        $(this).toggleClass('plus-ico');
      });

      // Hide tabledrag weight and submit
      $("div[class='tabledrag-toggle-weight-wrapper']").hide();
      $("#draggableviews-table-ag-newsletter-panel-pane-2").next().hide();

      // Generate ordered itinerary content and interest content arrays.
      $("#itinerary-node-form #edit-submit, #itinerary-node-form #edit-draft").click(function(e) {
        e.stopImmediatePropagation();

        // Create itinerary content array.
        var itinerary_content_ref_weight = {}
        var i = 0;
        $("#draggableviews-table-learning-path-content-learning-path-content-selected div[class^='form-item form-type-select form-item-draggableviews-']").each(function() {
            itinerary_content_ref_weight[i] = $(this).next().val();
            i++;
        });

        // Create interest content array.
        var interest_content_ref_weight = {}
        i = 0;
        $("#draggableviews-table-learning-path-content-learning-path-interest-content-selected div[class^='form-item form-type-select form-item-draggableviews-']").each(function() {
          interest_content_ref_weight[i] = $(this).next().val();
          i++;
        });

        // Pass itinerary content array by POST.
        var postData = JSON.stringify(itinerary_content_ref_weight);
        $("#itinerary-node-form").closest("form")
          .append($("<input>", {"type":"hidden", "name":"itinerary_content_ref_weight", "value":postData}));

        // Pass interest content array by POST.
        postData = JSON.stringify(interest_content_ref_weight);
        $("#itinerary-node-form").closest("form")
          .append($("<input>", {"type":"hidden", "name":"interest_content_ref_weight", "value":postData}));

        // Submit call for itinerary node form.
        $("#itinerary-node-form").submit();
      });
    }
  }
})(jQuery);
