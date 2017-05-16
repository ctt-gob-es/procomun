
-- SUMMARY --

The Simple hierarchical select module displays selected taxonomy fields as
hierarchical selects on node creation/edit forms and as exposed filter in views.


-- REQUIREMENTS --

Taxonomy module (Drupal core) needs to be enabled.


-- INSTALLATION --

* Install as usual, see http://drupal.org/documentation/install/modules-themes/modules-7
  for further information.


-- CONFIGURATION --

* Create a new field (type "Term reference") and select
  "Simple hierarchical select" as widget type.

* Field settings
  - "Display number of nodes"
    Displays the number of nodes associated to a term next to the term name in
    the dropdown.
    WARNING: on sites with a lot of terms and nodes this can be a great
    performance killer (even if the data is cached).
  - "Allow creating new terms"
    Terms may be created directly from within the dropdowns (user needs to have
    permission to create terms in the vocabulary).
  - "Allow creating new levels"
    If selected users with permission to create terms in the vocabulary will be
    able to create a new term as child of the currently selected term.
  - "Force selection of deepest level"
    Force users to select terms from the deepest level.

* Views (exposed filter)
  - add a new filter using the field set-up as "Simple hierarchical select" or
    use "Content: Has taxonomy terms (with depth; Simple hierarchical select)"
    as a new filter
  - use "Simple hierarchical select" as selection type
  - select "Expose this filter to visitors, to allow them to change it"
  - enjoy :)


-- INTEGRATION WITH OTHER MODULES --

* Chosen (http://drupal.org/project/chosen)
  - If you have installed the module "Chosen" (>= 7.x-2.x) all elements of
    "Simple hierarchical select" are modified, so the user can search for items
    within the list. See http://drupal.org/project/chosen for more information.
  - If you have configured "Chosen" to apply always but do not want to apply it
    to the dropdowns created by "Simple hierarchical select" you may use the
    following CSS selector in the "Chosen" configuration:
    <code>select:visible:not(.shs-select)</code>
  - Apart from that you can select whether to use chosen on a per-field base by
    setting the option "Output this field with Chosen" in the field
    configuration.
    - "let chosen decide"
      The field is modified by Chosen if it matches the Chosen configuration.
    - "always"
      The field is always modified by Chosen.
    - "never"
      The field is not modified by Chosen even if it matches the Chosen
      configuration.

* High-performance JavaScript callback handler (http://drupal.org/project/js)
  - If you have lots of terms and a huge hierarchy you could increase the
    performance of "Simple hierarchical select" by installing "JS". It routes
    all javascript callbacks needed by "Simple hierarchical select" through a
    custom handler to avoid loading of all Drupal functions and speed up
    loading.


-- CONTACT --

Current maintainers:
* Stefan Borchert (stborchert) - http://drupal.org/user/36942

This project has been sponsored by:
* undpaul
  Drupal experts providing professional Drupal development services.
  Visit http://www.undpaul.de for more information.



-- PATCHES APPLIED --

Se ha modificado la función _shs_get_term_node_count, para que realice el conteo de nodos hijo desde la tabla de la base de datos "taxonomy_term_hierarchy", y se ha modificado la variable $num_nodes rebajandola en uno, para que un mismo elemento no se cuente a si mismo como nodo hijo.

Parche aplicado por fjperez@emergya.com


Name: shs_remove_number_results_when_no_result.patch
Description: Remove the number of results when we have no results for the learning resources taxonomies tree. By default we print "(0)".

Name: shs_select_default_value.patch
Description: By default the select is empty and should be _none.

Name: 2266723-shs-missing_fields_ajax_rebuild_revision_1.patch
Aplicado el parche https://www.drupal.org/files/issues/shs-missing_fields_ajax_rebuild_revision_1.patch de la issue https://www.drupal.org/node/2266723 que soluciona la no aparición de los campos marcados como "None" de valor "_none" al machacar su valor por defecto. Estos campos no aparecían tras una validación incorrecta en el formulario, impidiendo al usuario añadir nuevos valores. Parece tener relación con los valores _none del parche anterior: shs_select_default_value.patch.