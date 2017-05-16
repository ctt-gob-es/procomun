/**
 * EliminarResultadoVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Esta clase contiene los parametros interesantes de recoger a
 *                         cerca del resultado de eliminar un ODE de
 * la plataforma.
 */
public class EliminarResultadoVO  implements java.io.Serializable {
    /* Identficador del ODE eliminado. */
    private java.lang.String idODE;

    /* Mensaje sobre la operacion de eliminado de ese ODE. */
    private java.lang.String mensaje;

    /* Codigo del mensaje con el que ha terminado la operacion de
     *                                 eliminado sobre ese ODE. */
    private java.lang.String code;

    /* Titulo del ODE. */
    private java.lang.String titulo;

    public EliminarResultadoVO() {
    }

    public EliminarResultadoVO(
           java.lang.String idODE,
           java.lang.String mensaje,
           java.lang.String code,
           java.lang.String titulo) {
           this.idODE = idODE;
           this.mensaje = mensaje;
           this.code = code;
           this.titulo = titulo;
    }


    /**
     * Gets the idODE value for this EliminarResultadoVO.
     * 
     * @return idODE   * Identficador del ODE eliminado.
     */
    public java.lang.String getIdODE() {
        return idODE;
    }


    /**
     * Sets the idODE value for this EliminarResultadoVO.
     * 
     * @param idODE   * Identficador del ODE eliminado.
     */
    public void setIdODE(java.lang.String idODE) {
        this.idODE = idODE;
    }


    /**
     * Gets the mensaje value for this EliminarResultadoVO.
     * 
     * @return mensaje   * Mensaje sobre la operacion de eliminado de ese ODE.
     */
    public java.lang.String getMensaje() {
        return mensaje;
    }


    /**
     * Sets the mensaje value for this EliminarResultadoVO.
     * 
     * @param mensaje   * Mensaje sobre la operacion de eliminado de ese ODE.
     */
    public void setMensaje(java.lang.String mensaje) {
        this.mensaje = mensaje;
    }


    /**
     * Gets the code value for this EliminarResultadoVO.
     * 
     * @return code   * Codigo del mensaje con el que ha terminado la operacion de
     *                                 eliminado sobre ese ODE.
     */
    public java.lang.String getCode() {
        return code;
    }


    /**
     * Sets the code value for this EliminarResultadoVO.
     * 
     * @param code   * Codigo del mensaje con el que ha terminado la operacion de
     *                                 eliminado sobre ese ODE.
     */
    public void setCode(java.lang.String code) {
        this.code = code;
    }


    /**
     * Gets the titulo value for this EliminarResultadoVO.
     * 
     * @return titulo   * Titulo del ODE.
     */
    public java.lang.String getTitulo() {
        return titulo;
    }


    /**
     * Sets the titulo value for this EliminarResultadoVO.
     * 
     * @param titulo   * Titulo del ODE.
     */
    public void setTitulo(java.lang.String titulo) {
        this.titulo = titulo;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof EliminarResultadoVO)) return false;
        EliminarResultadoVO other = (EliminarResultadoVO) obj;
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
            ((this.mensaje==null && other.getMensaje()==null) || 
             (this.mensaje!=null &&
              this.mensaje.equals(other.getMensaje()))) &&
            ((this.code==null && other.getCode()==null) || 
             (this.code!=null &&
              this.code.equals(other.getCode()))) &&
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
        if (getMensaje() != null) {
            _hashCode += getMensaje().hashCode();
        }
        if (getCode() != null) {
            _hashCode += getCode().hashCode();
        }
        if (getTitulo() != null) {
            _hashCode += getTitulo().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(EliminarResultadoVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EliminarResultadoVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idODE");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("mensaje");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "mensaje"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("code");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "code"));
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
