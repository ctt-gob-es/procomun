Sass for main structure is in _panels.sass
Sass for specific panes is in the relevant Sass file, ideally with the same name as the Pane Class/ID

General Ideas:
1.) Panel Structure should use the bootstrap grid and NOT the Panel Layouts
2.) Panel column floating should be applied starting at the variable: $screen-sm: 768px !default
3.) The variable in 2.) is used by Bootstrap and can be overwritten in ag-utilities/_bootstrap-variables-overwrite.sass
4.) In _panels, the grid classes for panel layouts should be set in the .tpl.php del layout
5.) Nuevos panel layouts se definen en /<themename>/layouts/