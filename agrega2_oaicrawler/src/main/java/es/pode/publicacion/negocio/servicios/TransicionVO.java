/**
 * TransicionVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Esta clase almacena la informacion de transicion entre estados
 *                         de cada ODE almacenado en la plataforma.
 */
public class TransicionVO  implements java.io.Serializable {
    /* Identificador del ODE al que hace referencia la transicion. */
    private java.lang.String idODE;

    /* Los comentarios de la transicion. */
    private java.lang.String comentarios;

    /* La fecha de la transicion. */
    private java.util.Calendar fecha;

    /* Titulo del ODE, en caso de tenerlo. */
    private java.lang.String titulo;

    /* Identificador del usuario. */
    private java.lang.String idUsuario;

    /* Un boolean para saber si el ODE ha sido compartido */
    private java.lang.Boolean compartido;

    private es.pode.publicacion.negocio.servicios.EstadoVO estadoActual;

    private es.pode.publicacion.negocio.servicios.EstadoVO estadoTransitado;

    private es.pode.publicacion.negocio.servicios.AlbumVO album;

    public TransicionVO() {
    }

    public TransicionVO(
           java.lang.String idODE,
           java.lang.String comentarios,
           java.util.Calendar fecha,
           java.lang.String titulo,
           java.lang.String idUsuario,
           java.lang.Boolean compartido,
           es.pode.publicacion.negocio.servicios.EstadoVO estadoActual,
           es.pode.publicacion.negocio.servicios.EstadoVO estadoTransitado,
           es.pode.publicacion.negocio.servicios.AlbumVO album) {
           this.idODE = idODE;
           this.comentarios = comentarios;
           this.fecha = fecha;
           this.titulo = titulo;
           this.idUsuario = idUsuario;
           this.compartido = compartido;
           this.estadoActual = estadoActual;
           this.estadoTransitado = estadoTransitado;
           this.album = album;
    }


    /**
     * Gets the idODE value for this TransicionVO.
     * 
     * @return idODE   * Identificador del ODE al que hace referencia la transicion.
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this TransicionVO.
     * 
     * @param idODE   * Identificador del ODE al que hace referencia la transicion.
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the comentarios value for this TransicionVO.
     * 
     * @return comentarios   * Los comentarios de la transicion.
     */
    public java.lang.String getComentarios() {
        return comentarios;
    }


    /**
     * Sets the comentarios value for this TransicionVO.
     * 
     * @param comentarios   * Los comentarios de la transicion.
     */
    public void setComentarios(java.lang.String comentarios) {
        this.comentarios = comentarios;
    }


    /**
     * Gets the fecha value for this TransicionVO.
     * 
     * @return fecha   * La fecha de la transicion.
     */
    public java.util.Calendar getFecha() {
        return fecha;
    }


    /**
     * Sets the fecha value for this TransicionVO.
     * 
     * @param fecha   * La fecha de la transicion.
     */
    public void setFecha(java.util.Calendar fecha) {
        this.fecha = fecha;
    }


    /**
     * Gets the titulo value for this TransicionVO.
     * 
     * @return titulo   * Titulo del ODE, en caso de tenerlo.
     */
    public java.lang.String getTitulo() {
        return titulo;
    }


    /**
     * Sets the titulo value for this TransicionVO.
     * 
     * @param titulo   * Titulo del ODE, en caso de tenerlo.
     */
    public void setTitulo(java.lang.String titulo) {
        this.titulo = titulo;
    }


    /**
     * Gets the idUsuario value for this TransicionVO.
     * 
     * @return idUsuario   * Identificador del usuario.
     */
    public java.lang.String getIdUsuario() {
        return idUsuario;
    }


    /**
     * Sets the idUsuario value for this TransicionVO.
     * 
     * @param idUsuario   * Identificador del usuario.
     */
    public void setIdUsuario(java.lang.String idUsuario) {
        this.idUsuario = idUsuario;
    }


    /**
     * Gets the compartido value for this TransicionVO.
     * 
     * @return compartido   * Un boolean para saber si el ODE ha sido compartido
     */
    public java.lang.Boolean getCompartido() {
        return compartido;
    }


    /**
     * Sets the compartido value for this TransicionVO.
     * 
     * @param compartido   * Un boolean para saber si el ODE ha sido compartido
     */
    public void setCompartido(java.lang.Boolean compartido) {
        this.compartido = compartido;
    }


    /**
     * Gets the estadoActual value for this TransicionVO.
     * 
     * @return estadoActual
     */
    public es.pode.publicacion.negocio.servicios.EstadoVO getEstadoActual() {
        return estadoActual;
    }


    /**
     * Sets the estadoActual value for this TransicionVO.
     * 
     * @param estadoActual
     */
    public void setEstadoActual(es.pode.publicacion.negocio.servicios.EstadoVO estadoActual) {
        this.estadoActual = estadoActual;
    }


    /**
     * Gets the estadoTransitado value for this TransicionVO.
     * 
     * @return estadoTransitado
     */
    public es.pode.publicacion.negocio.servicios.EstadoVO getEstadoTransitado() {
        return estadoTransitado;
    }


    /**
     * Sets the estadoTransitado value for this TransicionVO.
     * 
     * @param estadoTransitado
     */
    public void setEstadoTransitado(es.pode.publicacion.negocio.servicios.EstadoVO estadoTransitado) {
        this.estadoTransitado = estadoTransitado;
    }


    /**
     * Gets the album value for this TransicionVO.
     * 
     * @return album
     */
    public es.pode.publicacion.negocio.servicios.AlbumVO getAlbum() {
        return album;
    }


    /**
     * Sets the album value for this TransicionVO.
     * 
     * @param album
     */
    public void setAlbum(es.pode.publicacion.negocio.servicios.AlbumVO album) {
        this.album = album;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof TransicionVO)) return false;
        TransicionVO other = (TransicionVO) obj;
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
            ((this.comentarios==null && other.getComentarios()==null) || 
             (this.comentarios!=null &&
              this.comentarios.equals(other.getComentarios()))) &&
            ((this.fecha==null && other.getFecha()==null) || 
             (this.fecha!=null &&
              this.fecha.equals(other.getFecha()))) &&
            ((this.titulo==null && other.getTitulo()==null) || 
             (this.titulo!=null &&
              this.titulo.equals(other.getTitulo()))) &&
            ((this.idUsuario==null && other.getIdUsuario()==null) || 
             (this.idUsuario!=null &&
              this.idUsuario.equals(other.getIdUsuario()))) &&
            ((this.compartido==null && other.getCompartido()==null) || 
             (this.compartido!=null &&
              this.compartido.equals(other.getCompartido()))) &&
            ((this.estadoActual==null && other.getEstadoActual()==null) || 
             (this.estadoActual!=null &&
              this.estadoActual.equals(other.getEstadoActual()))) &&
            ((this.estadoTransitado==null && other.getEstadoTransitado()==null) || 
             (this.estadoTransitado!=null &&
              this.estadoTransitado.equals(other.getEstadoTransitado()))) &&
            ((this.album==null && other.getAlbum()==null) || 
             (this.album!=null &&
              this.album.equals(other.getAlbum())));
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
        if (getComentarios() != null) {
            _hashCode += getComentarios().hashCode();
        }
        if (getFecha() != null) {
            _hashCode += getFecha().hashCode();
        }
        if (getTitulo() != null) {
            _hashCode += getTitulo().hashCode();
        }
        if (getIdUsuario() != null) {
            _hashCode += getIdUsuario().hashCode();
        }
        if (getCompartido() != null) {
            _hashCode += getCompartido().hashCode();
        }
        if (getEstadoActual() != null) {
            _hashCode += getEstadoActual().hashCode();
        }
        if (getEstadoTransitado() != null) {
            _hashCode += getEstadoTransitado().hashCode();
        }
        if (getAlbum() != null) {
            _hashCode += getAlbum().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(TransicionVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "TransicionVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idODE");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("comentarios");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
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
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idUsuario");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("compartido");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "compartido"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("estadoActual");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "estadoActual"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EstadoVO"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("estadoTransitado");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "estadoTransitado"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EstadoVO"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("album");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "album"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "AlbumVO"));
        elemField.setNillable(true);
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
