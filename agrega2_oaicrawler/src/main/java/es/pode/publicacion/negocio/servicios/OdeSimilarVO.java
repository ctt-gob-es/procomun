/**
 * OdeSimilarVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Objeto de valor que representa la información relevante a un ODE
 * que es similar a otro.
 */
public class OdeSimilarVO  implements java.io.Serializable {
    /* Identificador alfanumérico del ODE. */
    private java.lang.String idODE;

    /* Tipo de similitud que presenta este ODE con el que se le haya
     * comparado. */
    private java.lang.String similitud;

    /* Idioma en el que esta publicado el ODE. */
    private java.lang.String idioma;

    /* Titulo del ODE. */
    private java.lang.String titulo;

    public OdeSimilarVO() {
    }

    public OdeSimilarVO(
           java.lang.String idODE,
           java.lang.String similitud,
           java.lang.String idioma,
           java.lang.String titulo) {
           this.idODE = idODE;
           this.similitud = similitud;
           this.idioma = idioma;
           this.titulo = titulo;
    }


    /**
     * Gets the idODE value for this OdeSimilarVO.
     * 
     * @return idODE   * Identificador alfanumérico del ODE.
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this OdeSimilarVO.
     * 
     * @param idODE   * Identificador alfanumérico del ODE.
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the similitud value for this OdeSimilarVO.
     * 
     * @return similitud   * Tipo de similitud que presenta este ODE con el que se le haya
     * comparado.
     */
    public java.lang.String getSimilitud() {
        return similitud;
    }


    /**
     * Sets the similitud value for this OdeSimilarVO.
     * 
     * @param similitud   * Tipo de similitud que presenta este ODE con el que se le haya
     * comparado.
     */
    public void setSimilitud(java.lang.String similitud) {
        this.similitud = similitud;
    }


    /**
     * Gets the idioma value for this OdeSimilarVO.
     * 
     * @return idioma   * Idioma en el que esta publicado el ODE.
     */
    public java.lang.String getIdioma() {
        return idioma;
    }


    /**
     * Sets the idioma value for this OdeSimilarVO.
     * 
     * @param idioma   * Idioma en el que esta publicado el ODE.
     */
    public void setIdioma(java.lang.String idioma) {
        this.idioma = idioma;
    }


    /**
     * Gets the titulo value for this OdeSimilarVO.
     * 
     * @return titulo   * Titulo del ODE.
     */
    public java.lang.String getTitulo() {
        return titulo;
    }


    /**
     * Sets the titulo value for this OdeSimilarVO.
     * 
     * @param titulo   * Titulo del ODE.
     */
    public void setTitulo(java.lang.String titulo) {
        this.titulo = titulo;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof OdeSimilarVO)) return false;
        OdeSimilarVO other = (OdeSimilarVO) obj;
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
            ((this.similitud==null && other.getSimilitud()==null) || 
             (this.similitud!=null &&
              this.similitud.equals(other.getSimilitud()))) &&
            ((this.idioma==null && other.getIdioma()==null) || 
             (this.idioma!=null &&
              this.idioma.equals(other.getIdioma()))) &&
            ((this.titulo==null && other.getTitulo()==null) || 
             (this.titulo!=null &&
              this.titulo.equals(other.getTitulo())));
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
        if (getSimilitud() != null) {
            _hashCode += getSimilitud().hashCode();
        }
        if (getIdioma() != null) {
            _hashCode += getIdioma().hashCode();
        }
        if (getTitulo() != null) {
            _hashCode += getTitulo().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(OdeSimilarVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdeSimilarVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idODE");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("similitud");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "similitud"));
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
        elemField.setFieldName("titulo");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"));
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
