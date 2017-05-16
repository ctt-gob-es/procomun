/**
 * EstadoVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;

public class EstadoVO  implements java.io.Serializable {
    /* Nombre del Estado. */
    private java.lang.String nombre;

    /* Clave del estado. */
    private java.lang.String clave;

    public EstadoVO() {
    }

    public EstadoVO(
           java.lang.String nombre,
           java.lang.String clave) {
           this.nombre = nombre;
           this.clave = clave;
    }


    /**
     * Gets the nombre value for this EstadoVO.
     * 
     * @return nombre   * Nombre del Estado.
     */
    public java.lang.String getNombre() {
        return nombre;
    }


    /**
     * Sets the nombre value for this EstadoVO.
     * 
     * @param nombre   * Nombre del Estado.
     */
    public void setNombre(java.lang.String nombre) {
        this.nombre = nombre;
    }


    /**
     * Gets the clave value for this EstadoVO.
     * 
     * @return clave   * Clave del estado.
     */
    public java.lang.String getClave() {
        return clave;
    }


    /**
     * Sets the clave value for this EstadoVO.
     * 
     * @param clave   * Clave del estado.
     */
    public void setClave(java.lang.String clave) {
        this.clave = clave;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof EstadoVO)) return false;
        EstadoVO other = (EstadoVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.nombre==null && other.getNombre()==null) || 
             (this.nombre!=null &&
              this.nombre.equals(other.getNombre()))) &&
            ((this.clave==null && other.getClave()==null) || 
             (this.clave!=null &&
              this.clave.equals(other.getClave())));
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
        if (getNombre() != null) {
            _hashCode += getNombre().hashCode();
        }
        if (getClave() != null) {
            _hashCode += getClave().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(EstadoVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EstadoVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("nombre");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nombre"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("clave");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "clave"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
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
