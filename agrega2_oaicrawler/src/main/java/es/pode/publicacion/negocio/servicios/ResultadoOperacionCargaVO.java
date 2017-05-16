/**
 * ResultadoOperacionCargaVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * VO que almacena el resultado de la carga de un ode concreto.
 */
public class ResultadoOperacionCargaVO  implements java.io.Serializable {
    /* Identificador del resultado de la carga */
    private java.lang.String idResultado;

    /* Descripción del resultado de la carga */
    private java.lang.String descripcion;

    /* Identificador del ode cargado */
    private java.lang.String idODE;

    /* Tamanio del ode cargado */
    private java.lang.Long tamainoODE;

    /* Título del ode que se carga */
    private java.lang.String tituloOde;

    /* Idioma en el que se carga el ode */
    private java.lang.String idioma;

    /* Nivel de agregación del ode cargado */
    private java.lang.String nivelAgregacion;

    /* Formato/s que contienen el ode */
    private java.lang.String formato;

    /* Identifica si ese ode ha sobrescrito otro que ya estaba
     *                                 publicado en la plataforma */
    private java.lang.String sobrescrito;

    /* Nombre del zip cargado */
    private java.lang.String nombreZip;

    /* Path del zip que se va a cargar */
    private java.lang.String pathZip;

    /* Las rutas taxonomicas del arbol curricular vigente del ode
     * que
     *                                 se va a publicar. */
    private java.lang.String rutaTaxonomica;

    /* Identificadores de los odes potencialmente duplicados al que
     * estamos tratando */
    private java.lang.String odesSimilares;

    public ResultadoOperacionCargaVO() {
    }

    public ResultadoOperacionCargaVO(
           java.lang.String idResultado,
           java.lang.String descripcion,
           java.lang.String idODE,
           java.lang.Long tamainoODE,
           java.lang.String tituloOde,
           java.lang.String idioma,
           java.lang.String nivelAgregacion,
           java.lang.String formato,
           java.lang.String sobrescrito,
           java.lang.String nombreZip,
           java.lang.String pathZip,
           java.lang.String rutaTaxonomica,
           java.lang.String odesSimilares) {
           this.idResultado = idResultado;
           this.descripcion = descripcion;
           this.idODE = idODE;
           this.tamainoODE = tamainoODE;
           this.tituloOde = tituloOde;
           this.idioma = idioma;
           this.nivelAgregacion = nivelAgregacion;
           this.formato = formato;
           this.sobrescrito = sobrescrito;
           this.nombreZip = nombreZip;
           this.pathZip = pathZip;
           this.rutaTaxonomica = rutaTaxonomica;
           this.odesSimilares = odesSimilares;
    }


    /**
     * Gets the idResultado value for this ResultadoOperacionCargaVO.
     * 
     * @return idResultado   * Identificador del resultado de la carga
     */
    public java.lang.String getIdResultado() {
        return idResultado;
    }


    /**
     * Sets the idResultado value for this ResultadoOperacionCargaVO.
     * 
     * @param idResultado   * Identificador del resultado de la carga
     */
    public void setIdResultado(java.lang.String idResultado) {
        this.idResultado = idResultado;
    }


    /**
     * Gets the descripcion value for this ResultadoOperacionCargaVO.
     * 
     * @return descripcion   * Descripción del resultado de la carga
     */
    public java.lang.String getDescripcion() {
        return descripcion;
    }


    /**
     * Sets the descripcion value for this ResultadoOperacionCargaVO.
     * 
     * @param descripcion   * Descripción del resultado de la carga
     */
    public void setDescripcion(java.lang.String descripcion) {
        this.descripcion = descripcion;
    }


    /**
     * Gets the idODE value for this ResultadoOperacionCargaVO.
     * 
     * @return idODE   * Identificador del ode cargado
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this ResultadoOperacionCargaVO.
     * 
     * @param idODE   * Identificador del ode cargado
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the tamainoODE value for this ResultadoOperacionCargaVO.
     * 
     * @return tamainoODE   * Tamanio del ode cargado
     */
    public java.lang.Long getTamainoODE() {
        return tamainoODE;
    }


    /**
     * Sets the tamainoODE value for this ResultadoOperacionCargaVO.
     * 
     * @param tamainoODE   * Tamanio del ode cargado
     */
    public void setTamainoODE(java.lang.Long tamainoODE) {
        this.tamainoODE = tamainoODE;
    }


    /**
     * Gets the tituloOde value for this ResultadoOperacionCargaVO.
     * 
     * @return tituloOde   * Título del ode que se carga
     */
    public java.lang.String getTituloOde() {
        return tituloOde;
    }


    /**
     * Sets the tituloOde value for this ResultadoOperacionCargaVO.
     * 
     * @param tituloOde   * Título del ode que se carga
     */
    public void setTituloOde(java.lang.String tituloOde) {
        this.tituloOde = tituloOde;
    }


    /**
     * Gets the idioma value for this ResultadoOperacionCargaVO.
     * 
     * @return idioma   * Idioma en el que se carga el ode
     */
    public java.lang.String getIdioma() {
        return idioma;
    }


    /**
     * Sets the idioma value for this ResultadoOperacionCargaVO.
     * 
     * @param idioma   * Idioma en el que se carga el ode
     */
    public void setIdioma(java.lang.String idioma) {
        this.idioma = idioma;
    }


    /**
     * Gets the nivelAgregacion value for this ResultadoOperacionCargaVO.
     * 
     * @return nivelAgregacion   * Nivel de agregación del ode cargado
     */
    public java.lang.String getNivelAgregacion() {
        return nivelAgregacion;
    }


    /**
     * Sets the nivelAgregacion value for this ResultadoOperacionCargaVO.
     * 
     * @param nivelAgregacion   * Nivel de agregación del ode cargado
     */
    public void setNivelAgregacion(java.lang.String nivelAgregacion) {
        this.nivelAgregacion = nivelAgregacion;
    }


    /**
     * Gets the formato value for this ResultadoOperacionCargaVO.
     * 
     * @return formato   * Formato/s que contienen el ode
     */
    public java.lang.String getFormato() {
        return formato;
    }


    /**
     * Sets the formato value for this ResultadoOperacionCargaVO.
     * 
     * @param formato   * Formato/s que contienen el ode
     */
    public void setFormato(java.lang.String formato) {
        this.formato = formato;
    }


    /**
     * Gets the sobrescrito value for this ResultadoOperacionCargaVO.
     * 
     * @return sobrescrito   * Identifica si ese ode ha sobrescrito otro que ya estaba
     *                                 publicado en la plataforma
     */
    public java.lang.String getSobrescrito() {
        return sobrescrito;
    }


    /**
     * Sets the sobrescrito value for this ResultadoOperacionCargaVO.
     * 
     * @param sobrescrito   * Identifica si ese ode ha sobrescrito otro que ya estaba
     *                                 publicado en la plataforma
     */
    public void setSobrescrito(java.lang.String sobrescrito) {
        this.sobrescrito = sobrescrito;
    }


    /**
     * Gets the nombreZip value for this ResultadoOperacionCargaVO.
     * 
     * @return nombreZip   * Nombre del zip cargado
     */
    public java.lang.String getNombreZip() {
        return nombreZip;
    }


    /**
     * Sets the nombreZip value for this ResultadoOperacionCargaVO.
     * 
     * @param nombreZip   * Nombre del zip cargado
     */
    public void setNombreZip(java.lang.String nombreZip) {
        this.nombreZip = nombreZip;
    }


    /**
     * Gets the pathZip value for this ResultadoOperacionCargaVO.
     * 
     * @return pathZip   * Path del zip que se va a cargar
     */
    public java.lang.String getPathZip() {
        return pathZip;
    }


    /**
     * Sets the pathZip value for this ResultadoOperacionCargaVO.
     * 
     * @param pathZip   * Path del zip que se va a cargar
     */
    public void setPathZip(java.lang.String pathZip) {
        this.pathZip = pathZip;
    }


    /**
     * Gets the rutaTaxonomica value for this ResultadoOperacionCargaVO.
     * 
     * @return rutaTaxonomica   * Las rutas taxonomicas del arbol curricular vigente del ode
     * que
     *                                 se va a publicar.
     */
    public java.lang.String getRutaTaxonomica() {
        return rutaTaxonomica;
    }


    /**
     * Sets the rutaTaxonomica value for this ResultadoOperacionCargaVO.
     * 
     * @param rutaTaxonomica   * Las rutas taxonomicas del arbol curricular vigente del ode
     * que
     *                                 se va a publicar.
     */
    public void setRutaTaxonomica(java.lang.String rutaTaxonomica) {
        this.rutaTaxonomica = rutaTaxonomica;
    }


    /**
     * Gets the odesSimilares value for this ResultadoOperacionCargaVO.
     * 
     * @return odesSimilares   * Identificadores de los odes potencialmente duplicados al que
     * estamos tratando
     */
    public java.lang.String getOdesSimilares() {
        return odesSimilares;
    }


    /**
     * Sets the odesSimilares value for this ResultadoOperacionCargaVO.
     * 
     * @param odesSimilares   * Identificadores de los odes potencialmente duplicados al que
     * estamos tratando
     */
    public void setOdesSimilares(java.lang.String odesSimilares) {
        this.odesSimilares = odesSimilares;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof ResultadoOperacionCargaVO)) return false;
        ResultadoOperacionCargaVO other = (ResultadoOperacionCargaVO) obj;
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
              this.tamainoODE.equals(other.getTamainoODE()))) &&
            ((this.tituloOde==null && other.getTituloOde()==null) || 
             (this.tituloOde!=null &&
              this.tituloOde.equals(other.getTituloOde()))) &&
            ((this.idioma==null && other.getIdioma()==null) || 
             (this.idioma!=null &&
              this.idioma.equals(other.getIdioma()))) &&
            ((this.nivelAgregacion==null && other.getNivelAgregacion()==null) || 
             (this.nivelAgregacion!=null &&
              this.nivelAgregacion.equals(other.getNivelAgregacion()))) &&
            ((this.formato==null && other.getFormato()==null) || 
             (this.formato!=null &&
              this.formato.equals(other.getFormato()))) &&
            ((this.sobrescrito==null && other.getSobrescrito()==null) || 
             (this.sobrescrito!=null &&
              this.sobrescrito.equals(other.getSobrescrito()))) &&
            ((this.nombreZip==null && other.getNombreZip()==null) || 
             (this.nombreZip!=null &&
              this.nombreZip.equals(other.getNombreZip()))) &&
            ((this.pathZip==null && other.getPathZip()==null) || 
             (this.pathZip!=null &&
              this.pathZip.equals(other.getPathZip()))) &&
            ((this.rutaTaxonomica==null && other.getRutaTaxonomica()==null) || 
             (this.rutaTaxonomica!=null &&
              this.rutaTaxonomica.equals(other.getRutaTaxonomica()))) &&
            ((this.odesSimilares==null && other.getOdesSimilares()==null) || 
             (this.odesSimilares!=null &&
              this.odesSimilares.equals(other.getOdesSimilares())));
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
        if (getTituloOde() != null) {
            _hashCode += getTituloOde().hashCode();
        }
        if (getIdioma() != null) {
            _hashCode += getIdioma().hashCode();
        }
        if (getNivelAgregacion() != null) {
            _hashCode += getNivelAgregacion().hashCode();
        }
        if (getFormato() != null) {
            _hashCode += getFormato().hashCode();
        }
        if (getSobrescrito() != null) {
            _hashCode += getSobrescrito().hashCode();
        }
        if (getNombreZip() != null) {
            _hashCode += getNombreZip().hashCode();
        }
        if (getPathZip() != null) {
            _hashCode += getPathZip().hashCode();
        }
        if (getRutaTaxonomica() != null) {
            _hashCode += getRutaTaxonomica().hashCode();
        }
        if (getOdesSimilares() != null) {
            _hashCode += getOdesSimilares().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(ResultadoOperacionCargaVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionCargaVO"));
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
        elemField.setNillable(true);
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
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("tituloOde");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "tituloOde"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idioma");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("nivelAgregacion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nivelAgregacion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("formato");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "formato"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("sobrescrito");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "sobrescrito"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("nombreZip");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nombreZip"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("pathZip");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pathZip"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("rutaTaxonomica");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "rutaTaxonomica"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("odesSimilares");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "odesSimilares"));
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
