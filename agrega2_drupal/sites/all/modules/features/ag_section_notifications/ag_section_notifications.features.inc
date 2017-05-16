<?php
/**
 * @file
 * ag_section_notifications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ag_section_notifications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ag_section_notifications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function ag_section_notifications_default_message_type() {
  $items = array();
  $items['certificate_ode'] = entity_import('message_type', '{
    "name" : "certificate_ode",
    "description" : "Certificate ode",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "gl",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003EEl ode [procomun:ode-path] ha superat els criteris seleccionats i \\u00e9s potencialment certificable.\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEl ode [procomun:ode-path] ha superat els criteris seleccionats i \\u00e9s potencialment certificable.\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EThe ode [procomun:ode-path] has exceeded the selected criteria and is potentially certifiable.\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EThe ode [procomun:ode-path] has exceeded the selected criteria and is potentially certifiable.\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003EEl ode [procomun:ode-path] ha superado los criterios seleccionados y es potencialmente certificable.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEl ode [procomun:ode-path] ha superado los criterios seleccionados y es potencialmente certificable.\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EThe ode [procomun:ode-path] hautatutako irizpideen gainditu ditu eta egiaztagarria da potentzialki.\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EThe ode [procomun:ode-path] hautatutako irizpideen gainditu ditu eta egiaztagarria da potentzialki.\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EA ode [procomun:ode-path] superou os criterios seleccionados e \\u00e9 potencialmente certific\\u00e1vel.\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EA ode [procomun:ode-path] superou os criterios seleccionados e \\u00e9 potencialmente certific\\u00e1vel.\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_invitation_pending'] = entity_import('message_type', '{
    "name" : "new_invitation_pending",
    "description" : "new invitation pending",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003EL\\u0027usuari [message:user:name] t\\u0027ha convidat a unir-te a la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EL\\u0027usuari [message:user:name] t\\u0027ha convidat a unir-te a la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EThe user [message:user:name] has invited you to join the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EThe user [message:user:name] has invited you to join the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003EEl usuario [message:user:name] te ha invitado a unirte a la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEl usuario [message:user:name] te ha invitado a unirte a la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EErabiltzaileak [message:user:name] erkidegoan egokitu zuk gonbidatu du [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EErabiltzaileak [message:user:name] erkidegoan egokitu zuk gonbidatu du [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EO usuario [message:user:name] convidouno para formar parte da comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EO usuario [message:user:name] convidouno para formar parte da comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_invitation_pending_subscribe_confirmation'] = entity_import('message_type', '{
    "name" : "new_invitation_pending_subscribe_confirmation",
    "description" : "new_invitation_pending_subscribe_confirmation",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003EEnhorabona! L\\u0027usuari [message:user:name] ha acceptat la sol\\u00b7licitud d\\u0027invitaci\\u00f3 a la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEnhorabona! L\\u0027usuari [message:user:name] ha acceptat la sol\\u00b7licitud d\\u0027invitaci\\u00f3 a la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003ECongratulations! The user [message:user:name] has accepted the invitation request to the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ECongratulations! The user [message:user:name] has accepted the invitation request to the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003E\\u00a1Enhorabuena! El usuario [message:user:name] ha aceptado la solicitud de invitaci\\u00f3n a la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003E\\u00a1Enhorabuena! El usuario [message:user:name] ha aceptado la solicitud de invitaci\\u00f3n a la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EZorionak! Erabiltzailea [message:user:name] gonbidapenarekin komunitateari eskaera onartu du [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EZorionak! Erabiltzailea [message:user:name] gonbidapenarekin komunitateari eskaera onartu du [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EParab\\u00e9ns! O usuario [message:user:name] acepta a solicitude de convocatoria para a comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EParab\\u00e9ns! O usuario [message:user:name] acepta a solicitude de convocatoria para a comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_invitation_pending_unsubscribe_confirmation'] = entity_import('message_type', '{
    "name" : "new_invitation_pending_unsubscribe_confirmation",
    "description" : "new_invitation_pending_unsubscribe_confirmation",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003EHo sentim per\\u00f2 l\\u0027usuari [message:user:name] ha cancel\\u00b7lat la sol\\u00b7licitud d\\u0027invitaci\\u00f3 a la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EHo sentim per\\u00f2 l\\u0027usuari [message:user:name] ha cancel\\u00b7lat la sol\\u00b7licitud d\\u0027invitaci\\u00f3 a la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003ESorry, but the user [message:user:name] has canceled the request for invitation to the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ESorry, but the user [message:user:name] has canceled the request for invitation to the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003ELo sentimos pero el usuario [message:user:name] ha cancelado la solicitud de invitaci\\u00f3n a la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ELo sentimos pero el usuario [message:user:name] ha cancelado la solicitud de invitaci\\u00f3n a la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EBarkatu baina erabiltzaileak [message:user:name] komunitateari gonbidapen eskaera bertan behera utzi du [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EBarkatu baina erabiltzaileak [message:user:name] komunitateari gonbidapen eskaera bertan behera utzi du [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003ESent\\u00edmolo, pero o usuario [message:user:name] cancelou a solicitude de convocatoria para a comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ESent\\u00edmolo, pero o usuario [message:user:name] cancelou a solicitude de convocatoria para a comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_member_pending'] = entity_import('message_type', '{
    "name" : "new_member_pending",
    "description" : "new Member pending",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003EL\\u0027usuari [message:user:name] ha sol\\u00b7licitat ser membre de la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EL\\u0027usuari [message:user:name] ha sol\\u00b7licitat ser membre de la comunitat [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EThe user [message:user:name] has applied for membership in the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EThe user [message:user:name] has applied for membership in the community [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003EEl usuario [message:user:name] ha solicitado ser miembro de la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EEl usuario [message:user:name] ha solicitado ser miembro de la comunidad [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EErabiltzaileak [message:user:name] ditu atxikitzeko eskabidea komunitatean [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EErabiltzaileak [message:user:name] ditu atxikitzeko eskabidea komunitatean [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EO usuario [message:user:name] solicitou a adhesi\\u00f3n da comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EO usuario [message:user:name] solicitou a adhesi\\u00f3n da comunidade [message:field-social-network-ref:title-field]\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  $items['new_member_pending_confirmation'] = entity_import('message_type', '{
    "name" : "new_member_pending_confirmation",
    "description" : "new_member_pending_confirmation",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "es",
    "arguments" : null,
    "message_text" : {
      "ca" : [
        {
          "value" : "\\u003Cp\\u003ELa teva sol\\u00b7licitud per pert\\u00e0nyer a la comunitat [message:field-social-network-ref:title-field] ha arribat amb \\u00e8xit als administradors de la comunitat, en breu avaluaran la teva petici\\u00f3.\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003EMoltes gr\\u00e0cies.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ELa teva sol\\u00b7licitud per pert\\u00e0nyer a la comunitat [message:field-social-network-ref:title-field] ha arribat amb \\u00e8xit als administradors de la comunitat, en breu avaluaran la teva petici\\u00f3.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EMoltes gr\\u00e0cies.\\u003C\\/p\\u003E\\n"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Cp\\u003EYour request to belong to the community [message:field-social-network-ref:title-field] has reached successfully to community\\u0027s administrators. They will evaluate your request soon.\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003EThank you.\\u003C\\/p\\u003E\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EYour request to belong to the community [message:field-social-network-ref:title-field] has reached successfully to community\\u0027s administrators. They will evaluate your request soon.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EThank you.\\u003C\\/p\\u003E\\n"
        }
      ],
      "es" : [
        {
          "value" : "\\u003Cp\\u003ETu solicitud para pertenecer a la comunidad [message:field-social-network-ref:title-field] ha llegado con \\u00e9xito a los administradores de la comunidad, en breve evaluar\\u00e1n tu petici\\u00f3n.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EMuchas gracias.\\u003C\\/p\\u003E\\r\\n",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003ETu solicitud para pertenecer a la comunidad [message:field-social-network-ref:title-field] ha llegado con \\u00e9xito a los administradores de la comunidad, en breve evaluar\\u00e1n tu petici\\u00f3n.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EMuchas gracias.\\u003C\\/p\\u003E\\n"
        }
      ],
      "eu" : [
        {
          "value" : "\\u003Cp\\u003EZure eskaerari baitira euskaldunak [message:field-social-network-ref:title-field] heldu da arrakastaz komunitatea kudeatzaileei, laster zure eskaera ebaluatuko du.\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003EEskerrik asko.\\u003C\\/p\\u003E",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EZure eskaerari baitira euskaldunak [message:field-social-network-ref:title-field] heldu da arrakastaz komunitatea kudeatzaileei, laster zure eskaera ebaluatuko du.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EEskerrik asko.\\u003C\\/p\\u003E\\n"
        }
      ],
      "gl" : [
        {
          "value" : "\\u003Cp\\u003EA s\\u00faa petici\\u00f3n de pertencer \\u00e1 comunidade [message:field-social-network-ref:title-field] chegou con \\u00e9xito para os xestores da comunidade, en breve ha avaliar a s\\u00faa solicitude.\\u003C\\/p\\u003E\\n\\n\\u003Cp\\u003EMoitas grazas.\\u003C\\/p\\u003E",
          "format" : "rich_text",
          "safe_value" : "\\u003Cp\\u003EA s\\u00faa petici\\u00f3n de pertencer \\u00e1 comunidade [message:field-social-network-ref:title-field] chegou con \\u00e9xito para os xestores da comunidade, en breve ha avaliar a s\\u00faa solicitude.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EMoitas grazas.\\u003C\\/p\\u003E\\n"
        }
      ]
    }
  }');
  return $items;
}
