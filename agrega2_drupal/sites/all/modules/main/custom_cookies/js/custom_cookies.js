(function ($) {
  Drupal.behaviors.custom_cookies_popup = {
    attach: function(context, settings) {
      $('body').not('.sliding-popup-processed').addClass('sliding-popup-processed').each(function() {
        try {
          var enabled = Drupal.settings.custom_cookies.popup_enabled;
          if(!enabled) {
            return;
          }
          if (!Drupal.custom_cookies.cookiesEnabled()) {
            return;
          } 
          var status = Drupal.custom_cookies.getCurrentStatus();
          var agreed_enabled = Drupal.settings.custom_cookies.popup_agreed_enabled;
          var popup_hide_agreed = Drupal.settings.custom_cookies.popup_hide_agreed;
          if (status == 0) {
            var next_status = 1;
            $('a, input[type=submit]').bind('click.custom_cookies', function(){
              if(!agreed_enabled) {
                Drupal.custom_cookies.setStatus(1);
                next_status = 2;
              }
              Drupal.custom_cookies.changeStatus(next_status);
            });

            $('.agree-button').click(function(){
              if(!agreed_enabled) {
                Drupal.custom_cookies.setStatus(1);
                next_status = 2;
              }
              Drupal.custom_cookies.changeStatus(next_status);
            });

            Drupal.custom_cookies.createPopup(Drupal.settings.custom_cookies.popup_html_info);
          } else {
            return;
          }
        }
        catch(e) {
          return;
        }
      });
    }
  }

  Drupal.custom_cookies = {};

  Drupal.custom_cookies.createPopup = function(html) {
    var popup = $(html)
      .attr({"id": "sliding-popup"})
      .height("auto")
      .width("100%")
      .hide();
    if(Drupal.settings.custom_cookies.popup_position) {
      popup.prependTo("body");
      var height = popup.height();
      popup.show()
        .attr({"class": "sliding-popup-top"})
        .css({"top": -1 * height})
        .animate({top: 0}, Drupal.settings.custom_cookies.popup_delay);
    } else {
      popup.appendTo("body");
      height = popup.height();
      popup.show()
        .attr({"class": "sliding-popup-bottom"})
        .css({"bottom": -1 * height})
        .animate({bottom: 0}, Drupal.settings.custom_cookies.popup_delay)
    }
    Drupal.custom_cookies.attachEvents();
  }

  Drupal.custom_cookies.attachEvents = function() {
    var agreed_enabled = Drupal.settings.custom_cookies.popup_agreed_enabled;
    $('.find-more-button').click(function(){
      window.open(Drupal.settings.custom_cookies.popup_link);
    });
    $('.agree-button').click(function(){
      var next_status = 1;
      if(!agreed_enabled) {
        Drupal.custom_cookies.setStatus(1);
        next_status = 2;
      }
      $('a, input[type=submit]').unbind('click.custom_cookies');
      Drupal.custom_cookies.changeStatus(next_status);
    });
    $('.hide-popup-button').click(function(){
      Drupal.custom_cookies.changeStatus(2);
    });
  }

  Drupal.custom_cookies.getCurrentStatus = function() {
    var search = 'cookie-agreed-'+Drupal.settings.custom_cookies.popup_language+'=';
    var offset = document.cookie.indexOf(search);
    if (offset < 0) {
      return 0;
    }
    offset += search.length;
    var end = document.cookie.indexOf(';', offset);
    if (end == -1) {
      end = document.cookie.length;
    }
    var value = document.cookie.substring(offset, end);
    return parseInt(value);
  }

  Drupal.custom_cookies.changeStatus = function(value) {
    var status = Drupal.custom_cookies.getCurrentStatus();
    if (status == value) return;
    if(Drupal.settings.custom_cookies.popup_position) {
      $(".sliding-popup-top").animate({top: $("#sliding-popup").height() * -1}, Drupal.settings.custom_cookies.popup_delay, function () {
        if(status == 0) {
          $("#sliding-popup").html(Drupal.settings.custom_cookies.popup_html_agreed).animate({top: 0}, Drupal.settings.custom_cookies.popup_delay);
          Drupal.custom_cookies.attachEvents();
        }
        if(status == 1) {
          $("#sliding-popup").remove();
        }
      })
    } else {
      $(".sliding-popup-bottom").animate({bottom: $("#sliding-popup").height() * -1}, Drupal.settings.custom_cookies.popup_delay, function () {
        if(status == 0) {
          $("#sliding-popup").html(Drupal.settings.custom_cookies.popup_html_agreed).animate({bottom: 0}, Drupal.settings.custom_cookies.popup_delay)
          Drupal.custom_cookies.attachEvents();
        }
        if(status == 1) {
          $("#sliding-popup").remove();
        }
      ;})
    }
    Drupal.custom_cookies.setStatus(value);
  }

  Drupal.custom_cookies.setStatus = function(status) {
    var date = new Date();
    date.setDate(date.getDate() + 100);
    document.cookie = "cookie-agreed-"+Drupal.settings.custom_cookies.popup_language + "="+status+";expires=" + date.toUTCString() + ";path=" + Drupal.settings.basePath;
  }

  Drupal.custom_cookies.hasAgreed = function() {
    var status = Drupal.custom_cookies.getCurrentStatus();
    if(status == 1 || status == 2) {
      return true;
    }
    return false;
  }
  
  Drupal.custom_cookies.cookiesEnabled = function() {
    var cookieEnabled = (navigator.cookieEnabled) ? true : false;
      if (typeof navigator.cookieEnabled == "undefined" && !cookieEnabled) { 
        document.cookie="testcookie";
        cookieEnabled = (document.cookie.indexOf("testcookie") != -1) ? true : false;
      }
    return (cookieEnabled);
  }
  
})(jQuery);