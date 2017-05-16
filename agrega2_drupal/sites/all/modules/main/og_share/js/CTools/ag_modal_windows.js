/**
 * @file
 *
 * Implement a modal form.
 *
 * @see ctools/help/modal.html for documentation.
 *
 * This javascript relies on the CTools ajax responder.
 */

(function ($) {
  Drupal.theme.prototype.CToolsModalAgrega2 = function () {
    var html = ''
    html += '  <div id="ctools-modal" class="modal">'
    html += '    <div class="modal-dialog ' + Drupal.CTools.Modal.currentSettings.modalClass + '">' // panels-modal-content
    html += '      <div class="ag-modal-content">';
    html += '        <div class="modal-header">';
    html += '          <a class="close" href="#">';
    html += '            <span aria-hidden="true">×</span>';
    html += '            <span class="sr-only closeText">' + Drupal.CTools.Modal.currentSettings.closeText + '<span>';
    html += '          </a>';
    html += '          <h4 id="modal-title" class="modal-title"></h4>';
    html += '        </div>';
    html += '        <div id="modal-content" class="modal-body">';
    html += '        </div>';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';

    return html;
  }
})(jQuery);
