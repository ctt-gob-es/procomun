/**
 * EliminarNoDisponiblesVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Clase que alberga los atributos necesarios para el borrado en
 *                         bloque de ODEs.
 */
public class EliminarNoDisponiblesVO  implements java.io.Serializable {
    /* Fecha desde la que se esta interesado en borrar los ODEs no
     * disponibles. */
    private java.util.Calendar fechaInicio;

    /* Fecha hasta la que se esta interesado en borrar los ODEs no
     * disponibles. */
    private java.util.Calendar fechaFin;

    /* Identificadores de los usuarios de los que se quieren eliminar
     * ODEs. */
    private java.lang.String[] idUsuarios;

    /* Identificador de la tarea programada que invoca el servicio. */
    private java.lang.Long idTarea;

    public EliminarNoDisponiblesVO() {
    }

    public EliminarNoDisponiblesVO(
           java.util.Calendar fechaInicio,
           java.util.Calendar fechaFin,
           java.lang.String[] idUsuarios,
           java.lang.Long idTarea) {
           this.fechaInicio = fechaInicio;
           this.fechaFin = fechaFin;
           this.idUsuarios = idUsuarios;
           this.idTarea = idTarea;
    }


    /**
     * Gets the fechaInicio value for this EliminarNoDisponiblesVO.
     * 
     * @return fechaInicio   * Fecha desde la que se esta interesado en borrar los ODEs no
     * disponibles.
     */
    public java.util.Calendar getFechaInicio() {
        return fechaInicio;
    }


    /**
     * Sets the fechaInicio value for this EliminarNoDisponiblesVO.
     * 
     * @param fechaInicio   * Fecha desde la que se esta interesado en borrar los ODEs no
     * disponibles.
     */
    public void setFechaInicio(java.util.Calendar fechaInicio) {
        this.fechaInicio = fechaInicio;
    }


    /**
     * Gets the fechaFin value for this EliminarNoDisponiblesVO.
     * 
     * @return fechaFin   * Fecha hasta la que se esta interesado en borrar los ODEs no
     * disponibles.
     */
    public java.util.Calendar getFechaFin() {
        return fechaFin;
    }


    /**
     * Sets the fechaFin value for this EliminarNoDisponiblesVO.
     * 
     * @param fechaFin   * Fecha hasta la que se esta interesado en borrar los ODEs no
     * disponibles.
     */
    public void setFechaFin(java.util.Calendar fechaFin) {
        this.fechaFin = fechaFin;
    }


    /**
     * Gets the idUsuarios value for this EliminarNoDisponiblesVO.
     * 
     * @return idUsuarios   * Identificadores de los usuarios de los que se quieren eliminar
     * ODEs.
     */
    public java.lang.String[] getIdUsuarios() {
        return idUsuarios;
    }


    /**
     * Sets the idUsuarios value for this EliminarNoDisponiblesVO.
     * 
     * @param idUsuarios   * Identificadores de los usuarios de los que se quieren eliminar
     * ODEs.
     */
    public void setIdUsuarios(java.lang.String[] idUsuarios) {
        this.idUsuarios = idUsuarios;
    }


    /**
     * Gets the idTarea value for this EliminarNoDisponiblesVO.
     * 
     * @return idTarea   * Identificador de la tarea programada que invoca el servicio.
     */
    public java.lang.Long getIdTarea() {
        return idTarea;
    }


    /**
     * Sets the idTarea value for this EliminarNoDisponiblesVO.
     * 
     * @param idTarea   * Identificador de la tarea programada que invoca el servicio.
     */
    public void setIdTarea(java.lang.Long idTarea) {
        this.idTarea = idTarea;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof EliminarNoDisponiblesVO)) return false;
        EliminarNoDisponiblesVO other = (EliminarNoDisponiblesVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.fechaInicio==null && other.getFechaInicio()==null) || 
             (this.fechaInicio!=null &&
              this.fechaInicio.equals(other.getFechaInicio()))) &&
            ((this.fechaFin==null && other.getFechaFin()==null) || 
             (this.fechaFin!=null &&
              this.fechaFin.equals(other.getFechaFin()))) &&
            ((this.idUsuarios==null && other.getIdUsuarios()==null) || 
             (this.idUsuarios!=null &&
              java.util.Arrays.equals(this.idUsuarios, other.getIdUsuarios()))) &&
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
        if (getFechaInicio() != null) {
            _hashCode += getFechaInicio().hashCode();
        }
        if (getFechaFin() != null) {
            _hashCode += getFechaFin().hashCode();
        }
        if (getIdUsuarios() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getIdUsuarios());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getIdUsuarios(), i);
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
        new org.apache.axis.description.TypeDesc(EliminarNoDisponiblesVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EliminarNoDisponiblesVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("fechaInicio");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaInicio"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "dateTime"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("fechaFin");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaFin"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "dateTime"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idUsuarios");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuarios"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
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
