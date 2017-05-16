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

  if (window != window.parent) {
    // we've been embedded
    window.addEventListener("message", window.ODEVisualizerEmbedded.handleMessage, false);
    window.parent.postMessage("init", document.referrer);
  }
})(jQuery);
