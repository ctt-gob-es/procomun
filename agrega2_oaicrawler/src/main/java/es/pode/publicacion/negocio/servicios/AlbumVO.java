/**
 * AlbumVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;

public class AlbumVO  implements java.io.Serializable {
    /* Identificador del album. */
    private java.lang.Long id;

    /* Título del album. */
    private java.lang.String titulo;

    /* Descripción del album. */
    private java.lang.String descripcion;

    /* Usuario de creación del album. */
    private java.lang.String usuario;

    /* Fecha de creacion del album. */
    private java.lang.String fechaCreacion;

    private es.pode.publicacion.negocio.servicios.TransicionVO[] odes;

    public AlbumVO() {
    }

    public AlbumVO(
           java.lang.Long id,
           java.lang.String titulo,
           java.lang.String descripcion,
           java.lang.String usuario,
           java.lang.String fechaCreacion,
           es.pode.publicacion.negocio.servicios.TransicionVO[] odes) {
           this.id = id;
           this.titulo = titulo;
           this.descripcion = descripcion;
           this.usuario = usuario;
           this.fechaCreacion = fechaCreacion;
           this.odes = odes;
    }


    /**
     * Gets the id value for this AlbumVO.
     * 
     * @return id   * Identificador del album.
     */
    public java.lang.Long getId() {
        return id;
    }


    /**
     * Sets the id value for this AlbumVO.
     * 
     * @param id   * Identificador del album.
     */
    public void setId(java.lang.Long id) {
        this.id = id;
    }


    /**
     * Gets the titulo value for this AlbumVO.
     * 
     * @return titulo   * Título del album.
     */
    public java.lang.String getTitulo() {
        return titulo;
    }


    /**
     * Sets the titulo value for this AlbumVO.
     * 
     * @param titulo   * Título del album.
     */
    public void setTitulo(java.lang.String titulo) {
        this.titulo = titulo;
    }


    /**
     * Gets the descripcion value for this AlbumVO.
     * 
     * @return descripcion   * Descripción del album.
     */
    public java.lang.String getDescripcion() {
        return descripcion;
    }


    /**
     * Sets the descripcion value for this AlbumVO.
     * 
     * @param descripcion   * Descripción del album.
     */
    public void setDescripcion(java.lang.String descripcion) {
        this.descripcion = descripcion;
    }


    /**
     * Gets the usuario value for this AlbumVO.
     * 
     * @return usuario   * Usuario de creación del album.
     */
    public java.lang.String getUsuario() {
        return usuario;
    }


    /**
     * Sets the usuario value for this AlbumVO.
     * 
     * @param usuario   * Usuario de creación del album.
     */
    public void setUsuario(java.lang.String usuario) {
        this.usuario = usuario;
    }


    /**
     * Gets the fechaCreacion value for this AlbumVO.
     * 
     * @return fechaCreacion   * Fecha de creacion del album.
     */
    public java.lang.String getFechaCreacion() {
        return fechaCreacion;
    }


    /**
     * Sets the fechaCreacion value for this AlbumVO.
     * 
     * @param fechaCreacion   * Fecha de creacion del album.
     */
    public void setFechaCreacion(java.lang.String fechaCreacion) {
        this.fechaCreacion = fechaCreacion;
    }


    /**
     * Gets the odes value for this AlbumVO.
     * 
     * @return odes
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] getOdes() {
        return odes;
    }


    /**
     * Sets the odes value for this AlbumVO.
     * 
     * @param odes
     */
    public void setOdes(es.pode.publicacion.negocio.servicios.TransicionVO[] odes) {
        this.odes = odes;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof AlbumVO)) return false;
        AlbumVO other = (AlbumVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.id==null && other.getId()==null) || 
             (this.id!=null &&
              this.id.equals(other.getId()))) &&
            ((this.titulo==null && other.getTitulo()==null) || 
             (this.titulo!=null &&
              this.titulo.equals(other.getTitulo()))) &&
            ((this.descripcion==null && other.getDescripcion()==null) || 
             (this.descripcion!=null &&
              this.descripcion.equals(other.getDescripcion()))) &&
            ((this.usuario==null && other.getUsuario()==null) || 
             (this.usuario!=null &&
              this.usuario.equals(other.getUsuario()))) &&
            ((this.fechaCreacion==null && other.getFechaCreacion()==null) || 
             (this.fechaCreacion!=null &&
              this.fechaCreacion.equals(other.getFechaCreacion()))) &&
            ((this.odes==null && other.getOdes()==null) || 
             (this.odes!=null &&
              java.util.Arrays.equals(this.odes, other.getOdes())));
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
        if (getId() != null) {
            _hashCode += getId().hashCode();
        }
        if (getTitulo() != null) {
            _hashCode += getTitulo().hashCode();
        }
        if (getDescripcion() != null) {
            _hashCode += getDescripcion().hashCode();
        }
        if (getUsuario() != null) {
            _hashCode += getUsuario().hashCode();
        }
        if (getFechaCreacion() != null) {
            _hashCode += getFechaCreacion().hashCode();
        }
        if (getOdes() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getOdes());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getOdes(), i);
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
        new org.apache.axis.description.TypeDesc(AlbumVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "AlbumVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("id");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "id"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "long"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("titulo");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"));
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
        elemField.setFieldName("usuario");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "usuario"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("fechaCreacion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaCreacion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("odes");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "odes"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "TransicionVO"));
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
