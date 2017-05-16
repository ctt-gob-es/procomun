;(function($, window) {

  window.ODEVisualizer = {
    $tree : null,

    ode_source : null,

    /**
     * It's in charge of updating the ode data source and updating the page
     *
     * @param string ode_source
     */
    updateOdeSource : function(ode_source) {
      ODEVisualizer.ode_source = ode_source;
      ODEVisualizer.refreshContent();
    },

    /**
     * It loads the json info from the remote resource and updates the page content
     */
    refreshContent : function() {
      loading(true);

      ODEVisualizer.$tree = $('#tree');
      $.ajax({
        url: ODEVisualizer.ode_source,
        dataType: "json",
        success: function( data ) {
          loading(false);
          ODEVisualizer.$tree.tree({
            data: data,
            closedIcon: $('<span class="tree-icons ico ico-tree-closed"></span>'),
            openedIcon: $('<span class="tree-icons ico ico-tree-opened"></span>')
          });
        },
        error: function(error, message, exception) {
          loading(false);
          console.log('There was an error when fetching the ODE: ' + message);
          console.log(exception);
          console.log(error);
        }
      });

      ODEVisualizer.$tree.bind(
    	 	    'tree.init',
    	 	    function() {
    	 	    	ODEVisualizer.$tree.tree('selectNode',ODEVisualizer.$tree.tree('getNodeById', '1'));
    	 	    }
    	 	);
      ODEVisualizer.$tree.bind(
        'tree.select',
        function (event) {
          if(event.node.href){
        	  $('#loadingContent').show();

            $('#content')
                .on('load', function () {
                  $('#loadingContent').hide();
                })
                .attr('src', event.node.href);

          }
        }
      );
      ODEVisualizer.$tree.bind(
    	        'tree.click',
    	        function (event) {
    	          var $target = $(event.click_event.target);
    	          if(event.node.href){
    	        	//$('#loadingContent').show();
    	          }
    	          if($target.is('.jqtree-title-folder')) {
    	            $target.prev(".jqtree-toggler").click();
    	          }
    	        }
    	      );
    }
  };

  $(document).ready(function() {

    BigScreen.onenter = function() {
      // called when the first element enters full screen
      $('body').addClass("fullscreen");
    }

    BigScreen.onexit = function() {
      // called when all elements have exited full screen
      $('body').removeClass("fullscreen");
    }

    // If we get in/out fullscreen (or other) resize the iframe space
    $(window).resize(function() {
      var $content = $("#content");
      var $body = $('body');
      var height = $(window).height() - parseInt($body.css("padding-bottom")) - parseInt($body.css('padding-top'));
      if($body.height() < height) {
        height = $body.height();
      }
      $content.height(height);
    });
  });

})(jQuery, window);

/**
 * Displays/Hides a loading wheel
 * @param active
 */
function loading(active){
  if (active) {
    $('#tree').hide();
	  $('#body').hide();
	  $('#loading').show();

  } else {
    $('#tree').show();
    $('#body').show();
    $('#loading').hide();

  }
}
