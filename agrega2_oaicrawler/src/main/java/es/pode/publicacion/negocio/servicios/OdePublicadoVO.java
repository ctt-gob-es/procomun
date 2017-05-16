/**
 * OdePublicadoVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * VO que contiene todos los datos en relación al ODE:
 *                         identificador, idioma, tamaño, fecha de publicacion
 * y titulo.
 */
public class OdePublicadoVO  implements java.io.Serializable {
    /* Identificador del ODE. */
    private java.lang.String idODE;

    /* Idioma del ode. */
    private java.lang.String idioma;

    /* Tamaño del ode. */
    private java.lang.Long tamanio;

    /* Fecha de publicacion del ode. */
    private java.util.Calendar fecha;

    /* Titulo del ode. */
    private java.lang.String titulo;

    /* Se trata del codigo MD5 asociado al ODE. */
    private java.lang.String md5;

    public OdePublicadoVO() {
    }

    public OdePublicadoVO(
           java.lang.String idODE,
           java.lang.String idioma,
           java.lang.Long tamanio,
           java.util.Calendar fecha,
           java.lang.String titulo,
           java.lang.String md5) {
           this.idODE = idODE;
           this.idioma = idioma;
           this.tamanio = tamanio;
           this.fecha = fecha;
           this.titulo = titulo;
           this.md5 = md5;
    }


    /**
     * Gets the idODE value for this OdePublicadoVO.
     * 
     * @return idODE   * Identificador del ODE.
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this OdePublicadoVO.
     * 
     * @param idODE   * Identificador del ODE.
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the idioma value for this OdePublicadoVO.
     * 
     * @return idioma   * Idioma del ode.
     */
    public java.lang.String getIdioma() {
        return idioma;
    }


    /**
     * Sets the idioma value for this OdePublicadoVO.
     * 
     * @param idioma   * Idioma del ode.
     */
    public void setIdioma(java.lang.String idioma) {
        this.idioma = idioma;
    }


    /**
     * Gets the tamanio value for this OdePublicadoVO.
     * 
     * @return tamanio   * Tamaño del ode.
     */
    public java.lang.Long getTamanio() {
        return tamanio;
    }


    /**
     * Sets the tamanio value for this OdePublicadoVO.
     * 
     * @param tamanio   * Tamaño del ode.
     */
    public void setTamanio(java.lang.Long tamanio) {
        this.tamanio = tamanio;
    }


    /**
     * Gets the fecha value for this OdePublicadoVO.
     * 
     * @return fecha   * Fecha de publicacion del ode.
     */
    public java.util.Calendar getFecha() {
        return fecha;
    }


    /**
     * Sets the fecha value for this OdePublicadoVO.
     * 
     * @param fecha   * Fecha de publicacion del ode.
     */
    public void setFecha(java.util.Calendar fecha) {
        this.fecha = fecha;
    }


    /**
     * Gets the titulo value for this OdePublicadoVO.
     * 
     * @return titulo   * Titulo del ode.
     */
    public java.lang.String getTitulo() {
        return titulo;
    }


    /**
     * Sets the titulo value for this OdePublicadoVO.
     * 
     * @param titulo   * Titulo del ode.
     */
    public void setTitulo(java.lang.String titulo) {
        this.titulo = titulo;
    }


    /**
     * Gets the md5 value for this OdePublicadoVO.
     * 
     * @return md5   * Se trata del codigo MD5 asociado al ODE.
     */
    public java.lang.String getMd5() {
        return md5;
    }


    /**
     * Sets the md5 value for this OdePublicadoVO.
     * 
     * @param md5   * Se trata del codigo MD5 asociado al ODE.
     */
    public void setMd5(java.lang.String md5) {
        this.md5 = md5;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof OdePublicadoVO)) return false;
        OdePublicadoVO other = (OdePublicadoVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.idODE==null && other.getIdODE()==null) || 
             (this.idODE!=null &&
              this.idODE.equals(other.getIdODE()))) &&
            ((this.idioma==null && other.getIdioma()==null) || 
             (this.idioma!=null &&
              this.idioma.equals(other.getIdioma()))) &&
            ((this.tamanio==null && other.getTamanio()==null) || 
             (this.tamanio!=null &&
              this.tamanio.equals(other.getTamanio()))) &&
            ((this.fecha==null && other.getFecha()==null) || 
             (this.fecha!=null &&
              this.fecha.equals(other.getFecha()))) &&
            ((this.titulo==null && other.getTitulo()==null) || 
             (this.titulo!=null &&
              this.titulo.equals(other.getTitulo()))) &&
            ((this.md5==null && other.getMd5()==null) || 
             (this.md5!=null &&
              this.md5.equals(other.getMd5())));
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
        if (getIdODE() != null) {
            _hashCode += getIdODE().hashCode();
        }
        if (getIdioma() != null) {
            _hashCode += getIdioma().hashCode();
        }
        if (getTamanio() != null) {
            _hashCode += getTamanio().hashCode();
        }
        if (getFecha() != null) {
            _hashCode += getFecha().hashCode();
        }
        if (getTitulo() != null) {
            _hashCode += getTitulo().hashCode();
        }
        if (getMd5() != null) {
            _hashCode += getMd5().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(OdePublicadoVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdePublicadoVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idODE");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idioma");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("tamanio");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "tamanio"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "long"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("fecha");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fecha"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "dateTime"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("titulo");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("md5");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "md5"));
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
