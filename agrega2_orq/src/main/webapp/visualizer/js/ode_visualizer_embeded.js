;(function($) {
  /**
   * This JS is intended to be a way of communication with the container.
   */
  window.ODEVisualizerEmbedded = {
    // set a default referrer
    referrer : (window != window.parent) ? document.referrer : document.location.href,

    /**
     * It receives the message from the container and processes it
     * @param event
     */
    handleMessage : function(event) {

      // we only receive messages from our direct parent
      if (event.source !== window.parent) {
        return;
      }

      var message = null;
      try{
    	  message = JSON.parse(event.data);
      }catch(e){
    	  console.log('Message not related to visualizer: '+message);
      }


      if (message) {
        switch (message.type) {
          case 'log':
            console.log(message.value);
            break;

          case 'close_navigation':
            $("#tree").hide();
            break;

          case 'open_navigation':
            $("#tree").show();
            break;

          case 'maximize':
            break;

          case 'minimize':
            break;

          case 'fullscreen':
            if (BigScreen.enabled) {
              $('body').addClass("fullscreen");
              BigScreen.toggle();
            }
//        	  $(".fullscreen .value").click(function() {
//                  var elem = $("#visor-ode");
//                  if (elem.requestFullscreen) {
//                    elem.requestFullscreen();
//                  } else if (elem.msRequestFullscreen) {
//                    elem.msRequestFullscreen();
//                  } else if (elem.mozRequestFullScreen) {
//                    elem.mozRequestFullScreen();
//                  } else if (elem.webkitRequestFullscreen) {
//                    elem.webkitRequestFullscreen();
//                  }
//                }).trigger('click');
            break;

          case 'ode_source':
            window.ODEVisualizer.updateOdeSource(message.value);
            break;

          default:
            console.log(message.value);
        }
      }
    }
  };
  
  function toggleFullScreen() {
      if (!document.fullscreenElement && !document.mozFullScreenElement && !document.webkitFullscreenElement && !document.msFullscreenElement ) {
        if (document.documentElement.requestFullscreen) {
        	document.documentElement.requestFullscreen();
        } else if (document.documentElement.msRequestFullscreen) {
        	document.documentElement.msRequestFullscreen();
        } else if (document.documentElement.mozRequestFullScreen) {
        	document.documentElement.mozRequestFullScreen();
        } else if (document.documentElement.webkitRequestFullscreen) {
        	document.documentElement.webkitRequestFullscreen(Element.ALLOW_KEYBOARD_INPUT);
        }
      } else {
        if (document.exitFullscreen) {
          document.exitFullscreen();
        } else if (document.msExitFullscreen) {
          document.msExitFullscreen();
        } else if (document.mozCancelFullScreen) {
          document.mozCancelFullScreen();
        } else if (document.webkitExitFullscreen) {
          document.webkitExitFullscreen();
        }
      }
    }

  if (window != window.parent) {
    // we've been embedded
    window.addEventListener("message", window.ODEVisualizerEmbedded.handleMessage, false);
    window.parent.postMessage("init", document.referrer);
  }
})(jQuery);
