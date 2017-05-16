;(function($, window) {
  Drupal.behaviors.visualization_ode = {
    attach: function(context) {

      var iframeController = window.AGVisualizerController;

      var $viewer = $(".screenViewer");
      var $iframe = $(".screenViewer .content");

      $(".iframe-actions").click(function(e) {
        var $target = $(e.target);

        var $navigate = $target.closest(".navigate");
        var $state = $target.closest(".state");

        if ($navigate.is(".open")) {
          $navigate.removeClass('open').addClass('closed');
          iframeController.sendMessage('close_navigation');
        }
        else if ($navigate.is(".closed")) {
          $navigate.removeClass('closed').addClass('open');
          iframeController.sendMessage('open_navigation');
        }
        else if ($state.is(".maximized")) {
          iframeController.sendMessage('maximize');
          $state.removeClass('maximized').addClass('minimized');
          $iframe.hide();
          iframeController.sendParentMessage('setHeight', $viewer.height());
        }
        else if ($state.is(".minimized")) {
          iframeController.sendMessage('minimize');
          $state.removeClass('minimized').addClass('maximized');
          $iframe.show();
          iframeController.sendParentMessage('setHeight', $iframe.height());
        }
        /*
        else if ($target.closest(".fullscreen").length) {
          // If minimized, we need to show the content
          $state.removeClass('minimized').addClass('maximized');
          $iframe.show();
          iframeController.sendMessage('fullscreen');
        }
        */
      });
      refreshHeight = function(){
        $(".screenViewer .content > iframe").height($(window).height()-53);
      }
      // #120574, #127954 - If widget is not inside an iframe, hide some buttons
      if (window.self === window.top) {
        $('.screenViewer .header .fullscreen').hide();
        $('.screenViewer .header .state').hide();
        $('.screenViewer .header .insert').hide();
        $('.screenViewer .header .download').hide();
        refreshHeight();
        $(window).resize(function(){
          refreshHeight();
        });
      }

      $(".normal-actions .insert").click(function() {
        $(".normal-actions-holder").toggle();

        var $state = $(".iframe-actions .state");
        if ($(".normal-actions-holder").css('display') == 'block') { /* we can't use is(:visible) */
          // the insert box was expanded, lets check if the viewer is maximized
          if ($state.is(".minimized")) {
            $state.click(); /* The viewer is minimized, let's maximize */
          }
        } else {
          // if the element was being displayed, but the current state is minimized,
          // then the user is not seeing anything, thus he expects to see the insert
          if ($state.is(".minimized")) {
            $(".normal-actions-holder").toggle(); // we will show it again (undo the click)
            $state.click(); /* The viewer is minimized, let's maximize */
          }
        }
        var contentHeight = $('body').outerHeight(true) + 2;
        iframeController.sendParentMessage('setHeight', contentHeight);
        iframeController.sendParentMessage('setIframeHeight', contentHeight);
      });

      $(".normal-actions-holder textarea").focus(function() {
        var $this = $(this);
        $this.select();

        // Work around Chrome's little problem
        $this.mouseup(function() {
          // Prevent further mouseup intervention
          $this.unbind("mouseup");
          return false;
        });
      });

      $("#edit-format-ode-download").change(function() {
        $("#ag-visualization-ode-get-ode-formats").submit();
      });
    },
  }
})(jQuery, window);
