/**
 * OdesFederadosDespublicadosVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;

public class OdesFederadosDespublicadosVO  implements java.io.Serializable {
    private java.lang.String idOde;

    private java.util.Calendar fechaDespublicacion;

    private java.lang.String idNodo;

    public OdesFederadosDespublicadosVO() {
    }

    public OdesFederadosDespublicadosVO(
           java.lang.String idOde,
           java.util.Calendar fechaDespublicacion,
           java.lang.String idNodo) {
           this.idOde = idOde;
           this.fechaDespublicacion = fechaDespublicacion;
           this.idNodo = idNodo;
    }


    /**
     * Gets the idOde value for this OdesFederadosDespublicadosVO.
     * 
     * @return idOde
     */
    public java.lang.String getIdOde() {
        return idOde;
    }


    /**
     * Sets the idOde value for this OdesFederadosDespublicadosVO.
     * 
     * @param idOde
     */
    public void setIdOde(java.lang.String idOde) {
        this.idOde = idOde;
    }


    /**
     * Gets the fechaDespublicacion value for this OdesFederadosDespublicadosVO.
     * 
     * @return fechaDespublicacion
     */
    public java.util.Calendar getFechaDespublicacion() {
        return fechaDespublicacion;
    }


    /**
     * Sets the fechaDespublicacion value for this OdesFederadosDespublicadosVO.
     * 
     * @param fechaDespublicacion
     */
    public void setFechaDespublicacion(java.util.Calendar fechaDespublicacion) {
        this.fechaDespublicacion = fechaDespublicacion;
    }


    /**
     * Gets the idNodo value for this OdesFederadosDespublicadosVO.
     * 
     * @return idNodo
     */
    public java.lang.String getIdNodo() {
        return idNodo;
    }


    /**
     * Sets the idNodo value for this OdesFederadosDespublicadosVO.
     * 
     * @param idNodo
     */
    public void setIdNodo(java.lang.String idNodo) {
        this.idNodo = idNodo;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof OdesFederadosDespublicadosVO)) return false;
        OdesFederadosDespublicadosVO other = (OdesFederadosDespublicadosVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.idOde==null && other.getIdOde()==null) || 
             (this.idOde!=null &&
              this.idOde.equals(other.getIdOde()))) &&
            ((this.fechaDespublicacion==null && other.getFechaDespublicacion()==null) || 
             (this.fechaDespublicacion!=null &&
              this.fechaDespublicacion.equals(other.getFechaDespublicacion()))) &&
            ((this.idNodo==null && other.getIdNodo()==null) || 
             (this.idNodo!=null &&
              this.idNodo.equals(other.getIdNodo())));
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
        if (getIdOde() != null) {
            _hashCode += getIdOde().hashCode();
        }
        if (getFechaDespublicacion() != null) {
            _hashCode += getFechaDespublicacion().hashCode();
        }
        if (getIdNodo() != null) {
            _hashCode += getIdNodo().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(OdesFederadosDespublicadosVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdesFederadosDespublicadosVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idOde");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idOde"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("fechaDespublicacion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaDespublicacion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "dateTime"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idNodo");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idNodo"));
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
