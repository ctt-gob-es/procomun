/**
 * LicenciaVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Contiene la licencia de un ODE. Se necesita para mostrarla
 *                         cuando se quiere publicar un ode, por si la
 * quiere cambiar.
 */
public class LicenciaVO  implements java.io.Serializable {
    /* El tipo de licencia que tiene el ODE. */
    private java.lang.String tipoLicencia;

    /* las comunidades en las que aplica la licencia. Puede ser null
     * si
     *                                 es universal, pq aplica a todas.
     *                                 De momento se guarda como un string
     * internacionalizado, y puede
     *                                 que contenga las comunidades o puede
     * que contenga una
     *                                 descripcion. */
    private java.lang.String comunidades;

    /* Indica si la licencia del ODE es universal o no. */
    private java.lang.String universal;

    public LicenciaVO() {
    }

    public LicenciaVO(
           java.lang.String tipoLicencia,
           java.lang.String comunidades,
           java.lang.String universal) {
           this.tipoLicencia = tipoLicencia;
           this.comunidades = comunidades;
           this.universal = universal;
    }


    /**
     * Gets the tipoLicencia value for this LicenciaVO.
     * 
     * @return tipoLicencia   * El tipo de licencia que tiene el ODE.
     */
    public java.lang.String getTipoLicencia() {
        return tipoLicencia;
    }


    /**
     * Sets the tipoLicencia value for this LicenciaVO.
     * 
     * @param tipoLicencia   * El tipo de licencia que tiene el ODE.
     */
    public void setTipoLicencia(java.lang.String tipoLicencia) {
        this.tipoLicencia = tipoLicencia;
    }


    /**
     * Gets the comunidades value for this LicenciaVO.
     * 
     * @return comunidades   * las comunidades en las que aplica la licencia. Puede ser null
     * si
     *                                 es universal, pq aplica a todas.
     *                                 De momento se guarda como un string
     * internacionalizado, y puede
     *                                 que contenga las comunidades o puede
     * que contenga una
     *                                 descripcion.
     */
    public java.lang.String getComunidades() {
        return comunidades;
    }


    /**
     * Sets the comunidades value for this LicenciaVO.
     * 
     * @param comunidades   * las comunidades en las que aplica la licencia. Puede ser null
     * si
     *                                 es universal, pq aplica a todas.
     *                                 De momento se guarda como un string
     * internacionalizado, y puede
     *                                 que contenga las comunidades o puede
     * que contenga una
     *                                 descripcion.
     */
    public void setComunidades(java.lang.String comunidades) {
        this.comunidades = comunidades;
    }


    /**
     * Gets the universal value for this LicenciaVO.
     * 
     * @return universal   * Indica si la licencia del ODE es universal o no.
     */
    public java.lang.String getUniversal() {
        return universal;
    }


    /**
     * Sets the universal value for this LicenciaVO.
     * 
     * @param universal   * Indica si la licencia del ODE es universal o no.
     */
    public void setUniversal(java.lang.String universal) {
        this.universal = universal;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof LicenciaVO)) return false;
        LicenciaVO other = (LicenciaVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.tipoLicencia==null && other.getTipoLicencia()==null) || 
             (this.tipoLicencia!=null &&
              this.tipoLicencia.equals(other.getTipoLicencia()))) &&
            ((this.comunidades==null && other.getComunidades()==null) || 
             (this.comunidades!=null &&
              this.comunidades.equals(other.getComunidades()))) &&
            ((this.universal==null && other.getUniversal()==null) || 
             (this.universal!=null &&
              this.universal.equals(other.getUniversal())));
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
        if (getTipoLicencia() != null) {
            _hashCode += getTipoLicencia().hashCode();
        }
        if (getComunidades() != null) {
            _hashCode += getComunidades().hashCode();
        }
        if (getUniversal() != null) {
            _hashCode += getUniversal().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(LicenciaVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LicenciaVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("tipoLicencia");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "tipoLicencia"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("comunidades");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comunidades"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("universal");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "universal"));
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
