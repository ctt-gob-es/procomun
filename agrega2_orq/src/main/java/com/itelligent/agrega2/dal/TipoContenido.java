package com.itelligent.agrega2.dal;

/**
 * Enum para el tipo de contenidos
 *
 */
public enum TipoContenido {
    ODE, QUESTION, USER, COMMUNITY, POST, DISCUSSION, UNKNOWN;

    public static TipoContenido getEnum(String strValue) {

        if (strValue.equalsIgnoreCase("ODE") || strValue.equalsIgnoreCase("LEARNING_RESOURCE")
                || strValue.equalsIgnoreCase("RECURSO_DE_APRENDIZAJE")) {
            return TipoContenido.ODE;
        } else if (strValue.equalsIgnoreCase("QUESTION")) {
            return TipoContenido.QUESTION;
        } else if (strValue.equalsIgnoreCase("USER")) {
            return TipoContenido.USER;
        } else if (strValue.equalsIgnoreCase("COMMUNITY")) {
            return TipoContenido.COMMUNITY;
        } else if (strValue.equalsIgnoreCase("POST")) {
            return TipoContenido.POST;
        } else if (strValue.equalsIgnoreCase("DISCUSSION") || strValue.equalsIgnoreCase("DEBATE")) {
            return TipoContenido.DISCUSSION;
        }

        throw new IllegalArgumentException("Unknown tipo " + strValue);
    }
}
