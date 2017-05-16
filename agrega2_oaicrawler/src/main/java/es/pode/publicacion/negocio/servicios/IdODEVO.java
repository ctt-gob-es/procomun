/**
 * IdODEVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Se trata del VO que recoge toda la informacion relevante del ODE
 * para la indexacion del mismo.
 *                         En nuestro caso, la informacion relevante
 * para la indexacion
 *                         esta compuesta por los distintos elementos
 * de catalogacion que
 *                         puede tener embebidos (elementos LOM-ES) y
 * otros datos que caen
 *                         fuera de esta catalogacion.
 */
public class IdODEVO  implements java.io.Serializable {
    /* Valoracion del ODE dentro de la plataforma. */
    private java.lang.Float valoracion;

    /* Con secuencia o sin secuencia. */
    private java.lang.Boolean secuencia;

    /* El localizador que da la ruta para acceder al ODE. */
    private java.lang.String localizador;

    /* Identificador de almacenamiento del ODE. */
    private java.lang.String idODE;

    private java.lang.String imgFile;

    private es.pode.publicacion.negocio.servicios.LomESPrimarioVO catalogacionPrimaria;

    private es.pode.publicacion.negocio.servicios.LomESSecundarioVO[] catalogacionSecundaria;

    public IdODEVO() {
    }

    public IdODEVO(
           java.lang.Float valoracion,
           java.lang.Boolean secuencia,
           java.lang.String localizador,
           java.lang.String idODE,
           java.lang.String imgFile,
           es.pode.publicacion.negocio.servicios.LomESPrimarioVO catalogacionPrimaria,
           es.pode.publicacion.negocio.servicios.LomESSecundarioVO[] catalogacionSecundaria) {
           this.valoracion = valoracion;
           this.secuencia = secuencia;
           this.localizador = localizador;
           this.idODE = idODE;
           this.imgFile = imgFile;
           this.catalogacionPrimaria = catalogacionPrimaria;
           this.catalogacionSecundaria = catalogacionSecundaria;
    }


    /**
     * Gets the valoracion value for this IdODEVO.
     * 
     * @return valoracion   * Valoracion del ODE dentro de la plataforma.
     */
    public java.lang.Float getValoracion() {
        return valoracion;
    }


    /**
     * Sets the valoracion value for this IdODEVO.
     * 
     * @param valoracion   * Valoracion del ODE dentro de la plataforma.
     */
    public void setValoracion(java.lang.Float valoracion) {
        this.valoracion = valoracion;
    }


    /**
     * Gets the secuencia value for this IdODEVO.
     * 
     * @return secuencia   * Con secuencia o sin secuencia.
     */
    public java.lang.Boolean getSecuencia() {
        return secuencia;
    }


    /**
     * Sets the secuencia value for this IdODEVO.
     * 
     * @param secuencia   * Con secuencia o sin secuencia.
     */
    public void setSecuencia(java.lang.Boolean secuencia) {
        this.secuencia = secuencia;
    }


    /**
     * Gets the localizador value for this IdODEVO.
     * 
     * @return localizador   * El localizador que da la ruta para acceder al ODE.
     */
    public java.lang.String getLocalizador() {
        return localizador;
    }


    /**
     * Sets the localizador value for this IdODEVO.
     * 
     * @param localizador   * El localizador que da la ruta para acceder al ODE.
     */
    public void setLocalizador(java.lang.String localizador) {
        this.localizador = localizador;
    }


    /**
     * Gets the idODE value for this IdODEVO.
     * 
     * @return idODE   * Identificador de almacenamiento del ODE.
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this IdODEVO.
     * 
     * @param idODE   * Identificador de almacenamiento del ODE.
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the imgFile value for this IdODEVO.
     * 
     * @return imgFile
     */
    public java.lang.String getImgFile() {
        return imgFile;
    }


    /**
     * Sets the imgFile value for this IdODEVO.
     * 
     * @param imgFile
     */
    public void setImgFile(java.lang.String imgFile) {
        this.imgFile = imgFile;
    }


    /**
     * Gets the catalogacionPrimaria value for this IdODEVO.
     * 
     * @return catalogacionPrimaria
     */
    public es.pode.publicacion.negocio.servicios.LomESPrimarioVO getCatalogacionPrimaria() {
        return catalogacionPrimaria;
    }


    /**
     * Sets the catalogacionPrimaria value for this IdODEVO.
     * 
     * @param catalogacionPrimaria
     */
    public void setCatalogacionPrimaria(es.pode.publicacion.negocio.servicios.LomESPrimarioVO catalogacionPrimaria) {
        this.catalogacionPrimaria = catalogacionPrimaria;
    }


    /**
     * Gets the catalogacionSecundaria value for this IdODEVO.
     * 
     * @return catalogacionSecundaria
     */
    public es.pode.publicacion.negocio.servicios.LomESSecundarioVO[] getCatalogacionSecundaria() {
        return catalogacionSecundaria;
    }


    /**
     * Sets the catalogacionSecundaria value for this IdODEVO.
     * 
     * @param catalogacionSecundaria
     */
    public void setCatalogacionSecundaria(es.pode.publicacion.negocio.servicios.LomESSecundarioVO[] catalogacionSecundaria) {
        this.catalogacionSecundaria = catalogacionSecundaria;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof IdODEVO)) return false;
        IdODEVO other = (IdODEVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.valoracion==null && other.getValoracion()==null) || 
             (this.valoracion!=null &&
              this.valoracion.equals(other.getValoracion()))) &&
            ((this.secuencia==null && other.getSecuencia()==null) || 
             (this.secuencia!=null &&
              this.secuencia.equals(other.getSecuencia()))) &&
            ((this.localizador==null && other.getLocalizador()==null) || 
             (this.localizador!=null &&
              this.localizador.equals(other.getLocalizador()))) &&
            ((this.idODE==null && other.getIdODE()==null) || 
             (this.idODE!=null &&
              this.idODE.equals(other.getIdODE()))) &&
            ((this.imgFile==null && other.getImgFile()==null) || 
             (this.imgFile!=null &&
              this.imgFile.equals(other.getImgFile()))) &&
            ((this.catalogacionPrimaria==null && other.getCatalogacionPrimaria()==null) || 
             (this.catalogacionPrimaria!=null &&
              this.catalogacionPrimaria.equals(other.getCatalogacionPrimaria()))) &&
            ((this.catalogacionSecundaria==null && other.getCatalogacionSecundaria()==null) || 
             (this.catalogacionSecundaria!=null &&
              java.util.Arrays.equals(this.catalogacionSecundaria, other.getCatalogacionSecundaria())));
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
        if (getValoracion() != null) {
            _hashCode += getValoracion().hashCode();
        }
        if (getSecuencia() != null) {
            _hashCode += getSecuencia().hashCode();
        }
        if (getLocalizador() != null) {
            _hashCode += getLocalizador().hashCode();
        }
        if (getIdODE() != null) {
            _hashCode += getIdODE().hashCode();
        }
        if (getImgFile() != null) {
            _hashCode += getImgFile().hashCode();
        }
        if (getCatalogacionPrimaria() != null) {
            _hashCode += getCatalogacionPrimaria().hashCode();
        }
        if (getCatalogacionSecundaria() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getCatalogacionSecundaria());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getCatalogacionSecundaria(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(IdODEVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "IdODEVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("valoracion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "valoracion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "float"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("secuencia");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "secuencia"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("localizador");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "localizador"));
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
        elemField.setFieldName("imgFile");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "imgFile"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("catalogacionPrimaria");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "catalogacionPrimaria"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LomESPrimarioVO"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("catalogacionSecundaria");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "catalogacionSecundaria"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LomESSecundarioVO"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
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
