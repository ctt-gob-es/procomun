package com.itelligent.agrega2.dal;

import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.codehaus.jackson.JsonNode;

import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * Clase que define los objetos recomendación que tendrán 3 parámetros: id,
 * general_title y general_description.
 * 
 */
public class Contenido {

    private static final Log LOG = LogFactory.getLog(Contenido.class);

    private long id;
    private String generalTitle;
    private String generalDescription;
    private TipoContenido tipoContenido;
    private Date dtmIndexacion;

    /**
     * Constructor con parámetros.
     * 
     * @param id
     *            {@code long} Id del contenido.
     * @param generalTitle
     *            {@code String} Título del contenido.
     * @param generalDescription
     *            {@code String} Descripción del contenido.
     */
    public Contenido(long id, String generalTitle, String generalDescription, TipoContenido tipoContenidoI) {
        this.id = id;
        this.generalTitle = generalTitle;
        this.generalDescription = generalDescription;
        this.tipoContenido = tipoContenidoI;
    }

    /**
     * Contructor de objetos Contenido a partir de un nodo JSON.
     * 
     * @param nodeDoc
     *            {@code JsonNode} Nodo JSON.
     */
    public Contenido(JsonNode nodeDoc) {
        String strTitle;
        String strDescription;
        long longId = 0;

        if (nodeDoc.findValue("id") != null) {
            JsonNode nodoId = nodeDoc.findValue("id");
            try {
                longId = Long.parseLong(nodoId.getTextValue());
            } catch (NumberFormatException e) {
                Utils.logError(LOG, "Cannot parse ID {0}", nodoId.getTextValue());
            }
        }

        if (nodeDoc.findValue("generalTitleStr") != null) {
            JsonNode nodoTitle = nodeDoc.findValue("generalTitleStr");
            strTitle = nodoTitle.getTextValue();
        } else {
            strTitle = "No Disponible";
        }

        // Asignamos el primer �ndice del array general_description

        if (nodeDoc.findValue("generalDescriptionStr") != null) {
            JsonNode nodoDescription = nodeDoc.findValue("generalDescriptionStr");
            strDescription = nodoDescription.get(0).getTextValue();
        } else {
            strDescription = "No Disponible";
        }

        if (nodeDoc.findValue("type") != null) {
            JsonNode nodoType = nodeDoc.findValue("type");
            String type = nodoType.getTextValue();
            try {
                this.tipoContenido = TipoContenido.getEnum(type);
            } catch (Exception e) {
                Utils.logWarn(LOG, "Cannot parse new TipoContenido (" + type + ")... Setting default to UNKNOWN");
                this.tipoContenido = TipoContenido.UNKNOWN;
            }
        }

        if (nodeDoc.findValue("lastIndexDate") != null) {
            JsonNode nodoType = nodeDoc.findValue("lastIndexDate");
            String strTdate = nodoType.getTextValue();
            try {
                this.dtmIndexacion = new SimpleDateFormat(Utils.DEFAULT_DATE_FORMAT).parse(strTdate);
            } catch (Exception e) {
                try {
                    this.dtmIndexacion = new SimpleDateFormat(Utils.NOMILLIS_DATE_FORMAT).parse(strTdate);
                } catch (Exception e2) {
                    Utils.logWarn(LOG, "Cannot parse new date (" + strTdate + ")");
                    this.dtmIndexacion = new Date(0);
                }
            }
        }

        this.id = longId;
        this.generalTitle = strTitle;
        this.generalDescription = strDescription;

    }

    /**
     * Constructor por defecto.
     */
    public Contenido() {

    }

    /**
     * Método para obtener el parámetro id.
     * 
     * @return {@code long} id del contenido.
     */
    public long getId() {
        return id;
    }

    /**
     * Método para obtener el parámetro general_title.
     * 
     * @return {@code String} Título del contenido
     */
    public String getGeneralTitle() {
        return generalTitle;
    }

    /**
     * Método para obtener el parámetro general_description.
     * 
     * @return {@code String} Descripción del contenido.
     */
    public String getGeneralDescription() {
        return generalDescription;
    }

    public TipoContenido getTipoContenido() {
        return tipoContenido;
    }

    public Date getDtmIndexacion() {
        return dtmIndexacion;
    }

}
