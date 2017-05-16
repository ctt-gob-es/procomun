;(function($, window) {
  Drupal.behaviors.manual_index = {
    attach: function(context) {
      $(".link-index-manual").click(function() {
        // trigger link id
        nid = $(this).data("nid");

        // Hide previous expanded element
        $("[aria-selected='true']").click();

        // Jump to content
        $("[data-nid=" + nid + "]" + ' > .views-accordion-header').click();
        $('html, body').animate({
          scrollTop: $("[data-nid=" + nid + "]").offset().top - 30
        }, 500);
      });

      // Our function name is prototyped as part of the Drupal.ajax namespace, adding to the commands:
      if (typeof Drupal.ajax != "undefined") {
        Drupal.ajax.prototype.commands.afterAjaxSaveCommentCallback = function(ajax, response, status)
        {
          // The value we passed in our Ajax callback function will be available inside the
          // response object. Since we defined it as selectedValue in our callback, it will be
          // available in response.selectedValue. Usually we would not use an alert() function
          // as we could use ajax_command_alert() to do it without having to define a custom
          // ajax command, but for the purpose of demonstration, we will use an alert() function
          // here:
  
          if (response.status) {
            $("#faq-num-comments-" + response.nid).html(parseInt($("#faq-num-comments-" + response.nid).html()) + 1);
            $("#answer-result-" + response.nid).next().replaceWith(response.answers_result);
            $("#answer-message-" + response.nid).removeClass();
            $("#answer-message-" + response.nid).addClass("message-success");
            $("#answer-message-" + response.nid).html(Drupal.t("The answer has been saved"));
            $(".message-success").css("display", "block");
            setTimeout(function() { $("#answer-message-" + response.nid).fadeOut(2000) }, 5000);
            // Clear ckeditor content when ajax submit success
            for (var instanceName in CKEDITOR.instances) {
              CKEDITOR.instances[instanceName].setData('');
            }
          }
          else {
            $("#answer-message-" + response.nid).removeClass();
            $("#answer-message-" + response.nid).addClass("message-error");
            $("#answer-message-" + response.nid).html(Drupal.t("Error: the answer can not be empty"));
            $(".message-error").css("display", "block");
            setTimeout(function() { $("#answer-message-" + response.nid).fadeOut(2000) }, 5000);
          }
        };
      }

      // Update node visits when view node in accordion
      $(".views-accordion-header").click(function(e) {
        e.stopImmediatePropagation();
        if ($(this).attr('aria-selected') == "true") {
          var nid = $(this).parent().data("nid");
          $.ajax({
            type: "GET",
            url: "/help/visit/" + nid
          });
        }
      });

      // Extract url params.
      $.urlParam = function(name) {
        var results = new RegExp('[\?&]' + name + '=([^&#]*)').exec(window.location.href);
        if (results == null) {
          return null;
        }
        else {
          return results[1] || 0;
        }
      }

      // Expand result node.
      if (window.location.href.search('help/') != -1) {
        node_nid = $.urlParam('help_nid');
        if (node_nid) {
          element = $("[data-nid=" + node_nid + "]" + ' > .views-accordion-header');
          if (element.attr('aria-selected') == "false") {
            element.click();
          }
        }
      }

      // Jump to content when access from direct url
      var url = window.location.href;
      var pieces = url.split("#");
      var section = pieces[0].split("/");
      if (section[section['length']-2] == 'help' && section[section['length']-1] == 'manual') {
        var nid = $("a[href='#" + pieces[1] + "'").parent().parent().parent().attr("data-nid");
        if (nid != null) {
          $("[data-nid=" + nid + "]" + ' > .views-accordion-header').click();
          $('html, body').animate({
            scrollTop: $("[data-nid=" + nid + "]").offset().top - 30
          }, 500);
        }
      }
    }
  }
})(jQuery, window);
