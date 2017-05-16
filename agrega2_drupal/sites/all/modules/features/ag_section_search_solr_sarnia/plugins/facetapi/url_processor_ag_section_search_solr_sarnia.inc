<?php
/**
 * @file
 * A custom URL processor for Agrega2.
 */

/**
 * Extension of FacetapiUrlProcessor.
 */
class FacetapiUrlProcessorAgrega2 extends FacetapiUrlProcessorStandard {
/**
* Implements FacetapiUrlProcessor::getQueryString().
*/
public function getQueryString(array $facet, array $values, $active) {
  $qstring = $this->params;
  $active_items = $this->adapter->getActiveItems($facet);

  // Appends to qstring if inactive, removes if active.
  foreach ($values as $value) {
    // Add double quotes to values not related to date or without "map options".
    if (strpos($facet['field alias'],'Date') === false && !$facet['map options']) {
      $value = '"' . $value . '"';
    }
    if ($active && isset($active_items[$value])) {
      unset($qstring[$this->filterKey][$active_items[$value]['pos']]);
    }
    elseif (!$active) {
      $field_alias = rawurlencode($facet['field alias']);
      // Strips all other filters for this facet if limit option is set.
      if ($this->limitActiveItems($facet)) {
        foreach ($qstring[$this->filterKey] as $pos => $filter) {
          if (0 === strpos($filter, $field_alias)) {
            unset($qstring[$this->filterKey][$pos]);
          }
        }
      }
    // Adds the filter to the query string.
    $qstring[$this->filterKey][] = $field_alias . ':' . $value;
    }
  }
  // Removes duplicates, resets array keys and returns query string.
  // @see http://drupal.org/node/1340528
  $qstring[$this->filterKey] = array_values(array_unique($qstring[$this->filterKey]));
  return array_filter($qstring);;
  }

  /**
   * Implements FacetapiUrlProcessor::setBreadcrumb().
   * Overriding breadcrumbs for facetapi.We don't need this filter on the breadcrumbs.
   */
  public function setBreadcrumb() {

  }
}

