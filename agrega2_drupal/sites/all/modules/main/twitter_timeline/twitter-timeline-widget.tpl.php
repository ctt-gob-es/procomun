<?php
/**
 * This file is the template for printing the twitter timeline
 *
 * Variables:
 * $widget_id: The id key for retrieve the timeline
 * $widget_title: Title
 *
 */
?>
<a class="twitter-timeline" href="https://twitter.com/search?q=%40educaINTEF" data-widget-id="<? print $widget_id; ?>"><? print $widget_title; ?></a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>