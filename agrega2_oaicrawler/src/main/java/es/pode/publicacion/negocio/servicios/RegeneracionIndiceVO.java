/**
 * RegeneracionIndiceVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Esta clase contiene toda la informacion necesaria para la
 *                         regeneracion de un repositorio.
 */
public class RegeneracionIndiceVO  implements java.io.Serializable {
    /* Identificadores de los idiomas cuyos indices se quieren
     *                                 regenerar. */
    private java.lang.String[] idIdiomas;

    /* Identificador de la tarea a la que hay que reportar los
     *                                 resultados. */
    private java.lang.Long idTarea;

    public RegeneracionIndiceVO() {
    }

    public RegeneracionIndiceVO(
           java.lang.String[] idIdiomas,
           java.lang.Long idTarea) {
           this.idIdiomas = idIdiomas;
           this.idTarea = idTarea;
    }


    /**
     * Gets the idIdiomas value for this RegeneracionIndiceVO.
     * 
     * @return idIdiomas   * Identificadores de los idiomas cuyos indices se quieren
     *                                 regenerar.
     */
    public java.lang.String[] getIdIdiomas() {
        return idIdiomas;
    }


    /**
     * Sets the idIdiomas value for this RegeneracionIndiceVO.
     * 
     * @param idIdiomas   * Identificadores de los idiomas cuyos indices se quieren
     *                                 regenerar.
     */
    public void setIdIdiomas(java.lang.String[] idIdiomas) {
        this.idIdiomas = idIdiomas;
    }


    /**
     * Gets the idTarea value for this RegeneracionIndiceVO.
     * 
     * @return idTarea   * Identificador de la tarea a la que hay que reportar los
     *                                 resultados.
     */
    public java.lang.Long getIdTarea() {
        return idTarea;
    }


    /**
     * Sets the idTarea value for this RegeneracionIndiceVO.
     * 
     * @param idTarea   * Identificador de la tarea a la que hay que reportar los
     *                                 resultados.
     */
    public void setIdTarea(java.lang.Long idTarea) {
        this.idTarea = idTarea;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof RegeneracionIndiceVO)) return false;
        RegeneracionIndiceVO other = (RegeneracionIndiceVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.idIdiomas==null && other.getIdIdiomas()==null) || 
             (this.idIdiomas!=null &&
              java.util.Arrays.equals(this.idIdiomas, other.getIdIdiomas()))) &&
            ((this.idTarea==null && other.getIdTarea()==null) || 
             (this.idTarea!=null &&
              this.idTarea.equals(other.getIdTarea())));
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
        if (getIdIdiomas() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getIdIdiomas());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getIdIdiomas(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getIdTarea() != null) {
            _hashCode += getIdTarea().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(RegeneracionIndiceVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "RegeneracionIndiceVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idIdiomas");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idIdiomas"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idTarea");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idTarea"));
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
