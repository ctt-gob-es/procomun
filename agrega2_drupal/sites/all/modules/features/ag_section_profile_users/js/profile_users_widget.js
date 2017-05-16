;(function($, window) {
    Drupal.behaviors.profile_users_widget = {
        attach: function(context) {
        $('.normal-actions .insert', context).once('profile_users_widget', function(){
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
          });
        }
    }
})(jQuery, window);
