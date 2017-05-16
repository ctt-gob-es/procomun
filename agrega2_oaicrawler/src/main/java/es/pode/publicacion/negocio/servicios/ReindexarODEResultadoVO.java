/**
 * ReindexarODEResultadoVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Esta clase representa el resultado de la reindexacion de un ODE
 * dentro del indice del repositorio de busqueda.
 */
public class ReindexarODEResultadoVO  implements java.io.Serializable {
    /* Localizador del ODE. */
    private java.lang.String localizador;

    /* Mensaje de exito o fracaso en la reindexacion. */
    private java.lang.String mensaje;

    /* Codigo de exito o fracaso en la reindexacion del ODE. */
    private int code;

    public ReindexarODEResultadoVO() {
    }

    public ReindexarODEResultadoVO(
           java.lang.String localizador,
           java.lang.String mensaje,
           int code) {
           this.localizador = localizador;
           this.mensaje = mensaje;
           this.code = code;
    }


    /**
     * Gets the localizador value for this ReindexarODEResultadoVO.
     * 
     * @return localizador   * Localizador del ODE.
     */
    public java.lang.String getLocalizador() {
        return localizador;
    }


    /**
     * Sets the localizador value for this ReindexarODEResultadoVO.
     * 
     * @param localizador   * Localizador del ODE.
     */
    public void setLocalizador(java.lang.String localizador) {
        this.localizador = localizador;
    }


    /**
     * Gets the mensaje value for this ReindexarODEResultadoVO.
     * 
     * @return mensaje   * Mensaje de exito o fracaso en la reindexacion.
     */
    public java.lang.String getMensaje() {
        return mensaje;
    }


    /**
     * Sets the mensaje value for this ReindexarODEResultadoVO.
     * 
     * @param mensaje   * Mensaje de exito o fracaso en la reindexacion.
     */
    public void setMensaje(java.lang.String mensaje) {
        this.mensaje = mensaje;
    }


    /**
     * Gets the code value for this ReindexarODEResultadoVO.
     * 
     * @return code   * Codigo de exito o fracaso en la reindexacion del ODE.
     */
    public int getCode() {
        return code;
    }


    /**
     * Sets the code value for this ReindexarODEResultadoVO.
     * 
     * @param code   * Codigo de exito o fracaso en la reindexacion del ODE.
     */
    public void setCode(int code) {
        this.code = code;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof ReindexarODEResultadoVO)) return false;
        ReindexarODEResultadoVO other = (ReindexarODEResultadoVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.localizador==null && other.getLocalizador()==null) || 
             (this.localizador!=null &&
              this.localizador.equals(other.getLocalizador()))) &&
            ((this.mensaje==null && other.getMensaje()==null) || 
             (this.mensaje!=null &&
              this.mensaje.equals(other.getMensaje()))) &&
            this.code == other.getCode();
        __equalsCalc = null;
        return _equals;
    }

    private boolean __hashCodeCalc = false;
    public synchronized int hashCode() {
        if (__hashCodeCalc) {
            return 0;
        }
        __hashCodeCalc = true;
        int _hashCode = 1;
        if (getLocalizador() != null) {
            _hashCode += getLocalizador().hashCode();
        }
        if (getMensaje() != null) {
            _hashCode += getMensaje().hashCode();
        }
        _hashCode += getCode();
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(ReindexarODEResultadoVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ReindexarODEResultadoVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("localizador");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "localizador"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("mensaje");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "mensaje"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("code");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "code"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "int"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
    }

    /**
     * Return type metadata object
     */
    public static org.apache.axis.description.TypeDesc getTypeDesc() {
        return typeDesc;
    }

    /**
     * Get Custom Serializer
     */
    public static org.apache.axis.encoding.Serializer getSerializer(
           java.lang.String mechType, 
           java.lang.Class _javaType,  
           javax.xml.namespace.QName _xmlType) {
        return 
          new  org.apache.axis.encoding.ser.BeanSerializer(
            _javaType, _xmlType, typeDesc);
    }

    /**
     * Get Custom Deserializer
     */
    public static org.apache.axis.encoding.Deserializer getDeserializer(
           java.lang.String mechType, 
           java.lang.Class _javaType,  
           javax.xml.namespace.QName _xmlType) {
        return 
          new  org.apache.axis.encoding.ser.BeanDeserializer(
            _javaType, _xmlType, typeDesc);
    }

}
