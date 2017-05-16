/**
 * ResultadoOperacionVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Este objeto de valor representa el resultado de una operacion
 *                         ejecutada por el servicio de publicacion.
 *                         Contiene el resultado de la operacion en el
 * caso de exito y de
 *                         error.
 */
public class ResultadoOperacionVO  implements java.io.Serializable {
    /* Identificador alfanumerico del tipo de incidencia que se ha
     * detectado y que se reporta. */
    private java.lang.String idResultado;

    /* Descripcion del resultado de la operacion realizada. */
    private java.lang.String descripcion;

    /* El identificador del ODE */
    private java.lang.String idODE;

    /* El tamaino que el ODE ocupa en disco. */
    private java.lang.Long tamainoODE;

    public ResultadoOperacionVO() {
    }

    public ResultadoOperacionVO(
           java.lang.String idResultado,
           java.lang.String descripcion,
           java.lang.String idODE,
           java.lang.Long tamainoODE) {
           this.idResultado = idResultado;
           this.descripcion = descripcion;
           this.idODE = idODE;
           this.tamainoODE = tamainoODE;
    }


    /**
     * Gets the idResultado value for this ResultadoOperacionVO.
     * 
     * @return idResultado   * Identificador alfanumerico del tipo de incidencia que se ha
     * detectado y que se reporta.
     */
    public java.lang.String getIdResultado() {
        return idResultado;
    }


    /**
     * Sets the idResultado value for this ResultadoOperacionVO.
     * 
     * @param idResultado   * Identificador alfanumerico del tipo de incidencia que se ha
     * detectado y que se reporta.
     */
    public void setIdResultado(java.lang.String idResultado) {
        this.idResultado = idResultado;
    }


    /**
     * Gets the descripcion value for this ResultadoOperacionVO.
     * 
     * @return descripcion   * Descripcion del resultado de la operacion realizada.
     */
    public java.lang.String getDescripcion() {
        return descripcion;
    }


    /**
     * Sets the descripcion value for this ResultadoOperacionVO.
     * 
     * @param descripcion   * Descripcion del resultado de la operacion realizada.
     */
    public void setDescripcion(java.lang.String descripcion) {
        this.descripcion = descripcion;
    }


    /**
     * Gets the idODE value for this ResultadoOperacionVO.
     * 
     * @return idODE   * El identificador del ODE
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this ResultadoOperacionVO.
     * 
     * @param idODE   * El identificador del ODE
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the tamainoODE value for this ResultadoOperacionVO.
     * 
     * @return tamainoODE   * El tamaino que el ODE ocupa en disco.
     */
    public java.lang.Long getTamainoODE() {
        return tamainoODE;
    }


    /**
     * Sets the tamainoODE value for this ResultadoOperacionVO.
     * 
     * @param tamainoODE   * El tamaino que el ODE ocupa en disco.
     */
    public void setTamainoODE(java.lang.Long tamainoODE) {
        this.tamainoODE = tamainoODE;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof ResultadoOperacionVO)) return false;
        ResultadoOperacionVO other = (ResultadoOperacionVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.idResultado==null && other.getIdResultado()==null) || 
             (this.idResultado!=null &&
              this.idResultado.equals(other.getIdResultado()))) &&
            ((this.descripcion==null && other.getDescripcion()==null) || 
             (this.descripcion!=null &&
              this.descripcion.equals(other.getDescripcion()))) &&
            ((this.idODE==null && other.getIdODE()==null) || 
             (this.idODE!=null &&
              this.idODE.equals(other.getIdODE()))) &&
            ((this.tamainoODE==null && other.getTamainoODE()==null) || 
             (this.tamainoODE!=null &&
              this.tamainoODE.equals(other.getTamainoODE())));
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
        if (getIdResultado() != null) {
            _hashCode += getIdResultado().hashCode();
        }
        if (getDescripcion() != null) {
            _hashCode += getDescripcion().hashCode();
        }
        if (getIdODE() != null) {
            _hashCode += getIdODE().hashCode();
        }
        if (getTamainoODE() != null) {
            _hashCode += getTamainoODE().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(ResultadoOperacionVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idResultado");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idResultado"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("descripcion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "descripcion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idODE");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("tamainoODE");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "tamainoODE"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "long"));
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
