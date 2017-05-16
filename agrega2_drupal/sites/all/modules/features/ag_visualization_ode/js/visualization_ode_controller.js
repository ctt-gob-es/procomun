/**
 * This widget is in charge of handling communication events with visualizer iframes
 * It's main use is in external sites
 *
 * Created by nicobot<nicolasbottini@gmail.com> on 11/21/13 and adapted for Agrega2.
 */
var env = env || 'prod';
try {
  (function() {
    window.AGVisualizerController || (function (window) {

      window.AGVisualizerController = {

        visualizerIframe : null,
        visualizerOrigin : null,

        parentVisualizerIframe : null,
        parentVisualizerOrigin : null,

        /**
         * Receives messages from iframe
         * @param event
         */
        handleMessage : function(event) {

          switch(event.data) {
            case 'init':
              $this.visualizerIframe = event.source;
              $this.visualizerOrigin = event.origin;
              if (env == 'dev') {
                console.log('Visualizer iFrame registered');
              }

              $this.sendMessage('ode_source', Drupal.settings.AG_ode_visualizer.ode_source);
              break;

            case 'init_parent':
              $this.parentVisualizerIframe = event.source;
              $this.parentVisualizerOrigin = event.origin;
              if (env == 'dev') {
                console.log('Visualizer Parent iFrame registered');
              }
              break;
          }

        },

        /**
         * Sends a message to the iframe
         * @param type kind of message
         * @param value optional content of the message
         * @returns {boolean} false if the is no iframe registered, true in other case
         */
        sendMessage : function(type, value) {
          value = (typeof value === "undefined") ? "" : value;

          // visualizerIframe was not registered, it needs to send the init message on load
          if (!$this.visualizerIframe) {
            return false;
          }

          // the message should be serializable
          $this.visualizerIframe.postMessage(JSON.stringify({type: type, value: value}), $this.visualizerOrigin);
          return true;
        },


        /**
         * Sends a message to the parent iframe
         * @param type kind of message
         * @param value optional content of the message
         * @returns {boolean} false if the is no iframe registered, true in other case
         */
        sendParentMessage : function(type, value) {
          value = (typeof value === "undefined") ? "" : value;

          // visualizerIframe was not registered, it needs to send the init message on load
          if (!$this.parentVisualizerIframe) {
            return false;
          }

          // the message should be serializable
          $this.parentVisualizerIframe.postMessage(JSON.stringify({type: type, value: value}), $this.parentVisualizerOrigin);
          return true;
        }
      }

      var $this = window.AGVisualizerController;

      // useCapture might be true
      window.addEventListener("message", window.AGVisualizerController.handleMessage, false);

      if (window != window.parent) {
        // we've been embedded
        window.parent.postMessage("init", document.referrer);
      }

    }).call({}, window.inDapIF ? parent.window : window);
  })();
} catch (e) {
}
