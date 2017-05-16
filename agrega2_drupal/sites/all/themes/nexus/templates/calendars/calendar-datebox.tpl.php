<?php
/**
 * @file
 * Template to display the date box in a calendar.
 *
 * - $view: The view.
 * - $granularity: The type of calendar this box is in -- year, month, day, or week.
 * - $mini: Whether or not this is a mini calendar.
 * - $class: The class for this box -- mini-on, mini-off, or day.
 * - $day:  The day of the month.
 * - $date: The current date, in the form YYYY-MM-DD.
 * - $link: A formatted link to the calendar day view for this day.
 * - $url:  The url to the calendar day view for this day.
 * - $selected: Whether or not this day has any items.
 * - $items: An array of items for this day.
 */

if ($selected) {
  //set the link with the class
  if ($view->name == 'events_calendar') {
    $timestamp = strtotime($date);

    if ($view->current_display == 'panel_pane_1') {
      $url = 'node/' . $view->args[0] . '/events';
    }
    elseif ($view->current_display == 'panel_pane_2') {
      $url = 'user/' . arg(1) . '/events';
    }
    $output = l($day, $url, array(
      'query' => array(
        'field_event_date_value' => $timestamp,
        'field_event_date_value2' => $timestamp,
      )));
  }
  else {
    $output = l($day, 'calendar-node-field-event-date/day/' . $date, array('attributes' => array('class' => array('day-with-events'))));
  }
}
else {
  $output = '<span>' . $day . '</span>';
}
?>
<div class="<?php print $granularity ?> <?php print $class; ?>">
  <?php print $output; ?>
</div>