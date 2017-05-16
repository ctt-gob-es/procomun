/**
 * SrvPublicacionServiceSoapBindingStub.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;

public class SrvPublicacionServiceSoapBindingStub extends org.apache.axis.client.Stub implements es.pode.publicacion.negocio.servicios.SrvPublicacionService {
    private java.util.Vector cachedSerClasses = new java.util.Vector();
    private java.util.Vector cachedSerQNames = new java.util.Vector();
    private java.util.Vector cachedSerFactories = new java.util.Vector();
    private java.util.Vector cachedDeserFactories = new java.util.Vector();

    static org.apache.axis.description.OperationDesc [] _operations;

    static {
        _operations = new org.apache.axis.description.OperationDesc[71];
        _initOperationDesc1();
        _initOperationDesc2();
        _initOperationDesc3();
        _initOperationDesc4();
        _initOperationDesc5();
        _initOperationDesc6();
        _initOperationDesc7();
        _initOperationDesc8();
    }

    private static void _initOperationDesc1(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("actualizarVersionODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pif"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idOdeOriginal"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "actualizarVersionODEReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[0] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("calcularDuplicadosPublicados");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfOdeSimilarVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.OdeSimilarVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "calcularDuplicadosPublicadosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[1] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("cambiarImagenODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "imagen"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "boolean"));
        oper.setReturnClass(boolean.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "cambiarImagenODEReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[2] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("compartirODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "compartirODEReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[3] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("creacion");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "creacionReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[4] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("crearDesdeURL");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "url"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idiomaDestinatario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "tipo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearDesdeURLReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[5] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("crearPIF");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ficheroPIF"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPIFReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[6] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("crearPIFCatalogado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pif"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPIFCatalogadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[7] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("crearPifConCuota");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pif"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPifConCuotaReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[8] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("crearPifConCuotaID");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pif"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "id"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPifConCuotaIDReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[9] = oper;

    }

    private static void _initOperationDesc2(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("crearPifConCuotaYEstado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pif"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "estadoTransicion"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPifConCuotaYEstadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[10] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("descompartirODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "descompartirODEReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[11] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("despublicarWebSemantica");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "despublicarWebSemanticaReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[12] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("eliminar");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODEs"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[13] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("eliminarIdODEForzado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "identificadores"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        oper.setReturnClass(java.lang.Boolean.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarIdODEForzadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[14] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("eliminarNoDisponibles");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "parametro"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EliminarNoDisponiblesVO"), es.pode.publicacion.negocio.servicios.EliminarNoDisponiblesVO.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfEliminarResultadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.EliminarResultadoVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarNoDisponiblesReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[15] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("eliminarOdesUsuarios");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "usuarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        oper.setReturnClass(java.lang.Boolean.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarOdesUsuariosReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[16] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("guardarImagenPorDefecto");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "imagenFile"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(org.apache.axis.encoding.XMLType.AXIS_VOID);
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[17] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("haEstadoVersionado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        oper.setReturnClass(java.lang.Boolean.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "haEstadoVersionadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[18] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("insertarOdesFederadosDespublicados");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "odes"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"), es.pode.publicacion.negocio.servicios.TransicionVO[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idNodo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        oper.setReturnClass(java.lang.Boolean.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "insertarOdesFederadosDespublicadosReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[19] = oper;

    }

    private static void _initOperationDesc3(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("modificaODECreado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        param.setNillable(true);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        param.setNillable(true);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "modificaODECreadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[20] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("noDisponible");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "noDisponibleReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[21] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("noDisponibles");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODEs"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "noDisponiblesReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[22] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenerEditoresOdeWebSemantica");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"));
        oper.setReturnClass(java.lang.String[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerEditoresOdeWebSemanticaReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[23] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenerOdesEditablesUsuarioWebSemantica");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"));
        oper.setReturnClass(java.lang.String[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerOdesEditablesUsuarioWebSemanticaReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[24] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenerUsuariosCreacionDeIdentificadores");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "identificadores"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"));
        oper.setReturnClass(java.lang.String[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerUsuariosCreacionDeIdentificadoresReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[25] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenerUsuariosCreacionPublicadosIdentificadores");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idOdes"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"));
        oper.setReturnClass(java.lang.String[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerUsuariosCreacionPublicadosIdentificadoresReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[26] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenEstadoPorIdODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EstadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.EstadoVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenEstadoPorIdODEReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[27] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenHistorialPorIdODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenHistorialPorIdODEReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[28] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenLicenciaODE");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LicenciaVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.LicenciaVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenLicenciaODEReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[29] = oper;

    }

    private static void _initOperationDesc4(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEPublicado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdePublicadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.OdePublicadoVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEPublicadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[30] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODESCompartidos");
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionAutorVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODESCompartidosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[31] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenOdesCompartidosPorTitulo");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionAutorVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenOdesCompartidosPorTituloReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[32] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenOdesCompartidosPorTituloYUsuarios");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ids"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionAutorVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenOdesCompartidosPorTituloYUsuariosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[33] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsCompartidosPorUsuarios");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ids"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionAutorVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsCompartidosPorUsuariosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[34] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsCreadosPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsCreadosPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[35] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsCreadosPorUsuarioPorTitulo");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsCreadosPorUsuarioPorTituloReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[36] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsDespublicados");
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[37] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsDespublicadosFederadosPorFecha");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaInicio"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaFin"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfOdesFederadosDespublicadosVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosFederadosPorFechaReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[38] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsDespublicadosPorFecha");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaInicio"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaFin"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosPorFechaReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[39] = oper;

    }

    private static void _initOperationDesc5(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsDespublicadosPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[40] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsDespublicadosPorUsuarios");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ids"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosPorUsuariosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[41] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPropuestos");
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[42] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODESPropuestosCatalogacion");
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODESPropuestosCatalogacionReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[43] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODESPropuestosCatalogacionPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODESPropuestosCatalogacionPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[44] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPropuestosCatalogacionPorUsuarios");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idsUsuarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosCatalogacionPorUsuariosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[45] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPropuestosPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[46] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPropuestosPorUsuarios");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ids"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosPorUsuariosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[47] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicados");
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfIdODEVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.IdODEVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[48] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicadosAutonomo");
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosAutonomoReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[49] = oper;

    }

    private static void _initOperationDesc6(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicadosAutonomoPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosAutonomoPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[50] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicadosPorTitulo");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosPorTituloReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[51] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicadosPorTituloYUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idsUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosPorTituloYUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[52] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicadosPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[53] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsPublicadoUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "usuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfOdePublicadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.OdePublicadoVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadoUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[54] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("obtenODEsRechazadosPorUsuario");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.TransicionVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsRechazadosPorUsuarioReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[55] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("proponerCatalogacion");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "proponerCatalogacionReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[56] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("proponerCatalogacionNuevaVersion");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "solicitaNuevaVersion"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"), java.lang.Boolean.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "proponerCatalogacionNuevaVersionReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[57] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("proponerPublicacion");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "proponerPublicacionReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[58] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("publicar");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comunidades"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "universal"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "textoLicencia"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "identificadorLicencia"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[59] = oper;

    }

    private static void _initOperationDesc7(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("publicarAutonomo");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarAutonomoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[60] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("publicarDespublicado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comunidades"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "universal"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "textoLicencia"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "identificadorLicencia"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarDespublicadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[61] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("publicarPIF");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pif"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://xml.apache.org/xml-soap", "DataHandler"), javax.activation.DataHandler.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "sobrescribir"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarPIFReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[62] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("publicarPifCarga");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "odes"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "sobrescribir"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nombreCarga"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "pathCarga"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfResultadoOperacionCargaVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarPifCargaReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[63] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("publicarWebSemantica");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "zipODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "hexBinary"), byte[].class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "catalogacionReducida"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "hexBinary"), byte[].class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "listaUsuarioEditores"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "esNuevaVersion"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "boolean"), boolean.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "tipoPublicacion"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoPublicacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarWebSemanticaReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[64] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("rechazar");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idUsuario"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "comentarios"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "rechazarReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[65] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("regeneraIndiceIdioma");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "paramRegenera"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "RegeneracionIndiceVO"), es.pode.publicacion.negocio.servicios.RegeneracionIndiceVO.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfReindexarODEResultadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "regeneraIndiceIdiomaReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[66] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("regenerarImagenes");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idTarea"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "long"), java.lang.Long.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "boolean"));
        oper.setReturnClass(java.lang.Boolean.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "regenerarImagenesReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[67] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("reindexarODEPublicado");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODE"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "valoracion"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "float"), java.lang.Float.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ReindexarODEResultadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "reindexarODEPublicadoReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[68] = oper;

        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("reindexarODEsPublicados");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idODEs"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string"), java.lang.String[].class, false, false);
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfReindexarODEResultadoVO"));
        oper.setReturnClass(es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[].class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "reindexarODEsPublicadosReturn"));
        param = oper.getReturnParamDesc();
        param.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[69] = oper;

    }

    private static void _initOperationDesc8(){
        org.apache.axis.description.OperationDesc oper;
        org.apache.axis.description.ParameterDesc param;
        oper = new org.apache.axis.description.OperationDesc();
        oper.setName("subirFichero");
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fichero"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "hexBinary"), byte[].class, false, false);
        oper.addParameter(param);
        param = new org.apache.axis.description.ParameterDesc(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nombreFichero"), org.apache.axis.description.ParameterDesc.IN, new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"), java.lang.String.class, false, false);
        oper.addParameter(param);
        oper.setReturnType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        oper.setReturnClass(java.lang.String.class);
        oper.setReturnQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "subirFicheroReturn"));
        oper.setStyle(org.apache.axis.constants.Style.WRAPPED);
        oper.setUse(org.apache.axis.constants.Use.LITERAL);
        _operations[70] = oper;

    }

    public SrvPublicacionServiceSoapBindingStub() throws org.apache.axis.AxisFault {
         this(null);
    }

    public SrvPublicacionServiceSoapBindingStub(java.net.URL endpointURL, javax.xml.rpc.Service service) throws org.apache.axis.AxisFault {
         this(service);
         super.cachedEndpoint = endpointURL;
    }

    public SrvPublicacionServiceSoapBindingStub(javax.xml.rpc.Service service) throws org.apache.axis.AxisFault {
        if (service == null) {
            super.service = new org.apache.axis.client.Service();
        } else {
            super.service = service;
        }
        ((org.apache.axis.client.Service)super.service).setTypeMappingVersion("1.2");
            java.lang.Class cls;
            javax.xml.namespace.QName qName;
            javax.xml.namespace.QName qName2;
            java.lang.Class beansf = org.apache.axis.encoding.ser.BeanSerializerFactory.class;
            java.lang.Class beandf = org.apache.axis.encoding.ser.BeanDeserializerFactory.class;
            java.lang.Class enumsf = org.apache.axis.encoding.ser.EnumSerializerFactory.class;
            java.lang.Class enumdf = org.apache.axis.encoding.ser.EnumDeserializerFactory.class;
            java.lang.Class arraysf = org.apache.axis.encoding.ser.ArraySerializerFactory.class;
            java.lang.Class arraydf = org.apache.axis.encoding.ser.ArrayDeserializerFactory.class;
            java.lang.Class simplesf = org.apache.axis.encoding.ser.SimpleSerializerFactory.class;
            java.lang.Class simpledf = org.apache.axis.encoding.ser.SimpleDeserializerFactory.class;
            java.lang.Class simplelistsf = org.apache.axis.encoding.ser.SimpleListSerializerFactory.class;
            java.lang.Class simplelistdf = org.apache.axis.encoding.ser.SimpleListDeserializerFactory.class;
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "AlbumVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.AlbumVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfEliminarResultadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.EliminarResultadoVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EliminarResultadoVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfIdODEVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.IdODEVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "IdODEVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfLomESSecundarioVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.LomESSecundarioVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LomESSecundarioVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfOdePublicadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.OdePublicadoVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdePublicadoVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfOdesFederadosDespublicadosVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdesFederadosDespublicadosVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfOdeSimilarVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.OdeSimilarVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdeSimilarVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfReindexarODEResultadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ReindexarODEResultadoVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfResultadoOperacionCargaVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionCargaVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfResultadoOperacionVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionAutorVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "TransicionAutorVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfTransicionVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.TransicionVO[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "TransicionVO");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ArrayOfxsd_string");
            cachedSerQNames.add(qName);
            cls = java.lang.String[].class;
            cachedSerClasses.add(cls);
            qName = new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string");
            qName2 = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item");
            cachedSerFactories.add(new org.apache.axis.encoding.ser.ArraySerializerFactory(qName, qName2));
            cachedDeserFactories.add(new org.apache.axis.encoding.ser.ArrayDeserializerFactory());

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EliminarNoDisponiblesVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.EliminarNoDisponiblesVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EliminarResultadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.EliminarResultadoVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "EstadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.EstadoVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "IdODEVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.IdODEVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LicenciaVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.LicenciaVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LomESPrimarioVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.LomESPrimarioVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LomESSecundarioVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.LomESSecundarioVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdePublicadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.OdePublicadoVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdesFederadosDespublicadosVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "OdeSimilarVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.OdeSimilarVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "RegeneracionIndiceVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.RegeneracionIndiceVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ReindexarODEResultadoVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionCargaVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoOperacionVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ResultadoPublicacionVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "TransicionAutorVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.TransicionAutorVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

            qName = new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "TransicionVO");
            cachedSerQNames.add(qName);
            cls = es.pode.publicacion.negocio.servicios.TransicionVO.class;
            cachedSerClasses.add(cls);
            cachedSerFactories.add(beansf);
            cachedDeserFactories.add(beandf);

    }

    protected org.apache.axis.client.Call createCall() throws java.rmi.RemoteException {
        try {
            org.apache.axis.client.Call _call = super._createCall();
            if (super.maintainSessionSet) {
                _call.setMaintainSession(super.maintainSession);
            }
            if (super.cachedUsername != null) {
                _call.setUsername(super.cachedUsername);
            }
            if (super.cachedPassword != null) {
                _call.setPassword(super.cachedPassword);
            }
            if (super.cachedEndpoint != null) {
                _call.setTargetEndpointAddress(super.cachedEndpoint);
            }
            if (super.cachedTimeout != null) {
                _call.setTimeout(super.cachedTimeout);
            }
            if (super.cachedPortName != null) {
                _call.setPortName(super.cachedPortName);
            }
            java.util.Enumeration keys = super.cachedProperties.keys();
            while (keys.hasMoreElements()) {
                java.lang.String key = (java.lang.String) keys.nextElement();
                _call.setProperty(key, super.cachedProperties.get(key));
            }
            // All the type mapping information is registered
            // when the first call is made.
            // The type mapping information is actually registered in
            // the TypeMappingRegistry of the service, which
            // is the reason why registration is only needed for the first call.
            synchronized (this) {
                if (firstCall()) {
                    // must set encoding style before registering serializers
                    _call.setEncodingStyle(null);
                    for (int i = 0; i < cachedSerFactories.size(); ++i) {
                        java.lang.Class cls = (java.lang.Class) cachedSerClasses.get(i);
                        javax.xml.namespace.QName qName =
                                (javax.xml.namespace.QName) cachedSerQNames.get(i);
                        java.lang.Object x = cachedSerFactories.get(i);
                        if (x instanceof Class) {
                            java.lang.Class sf = (java.lang.Class)
                                 cachedSerFactories.get(i);
                            java.lang.Class df = (java.lang.Class)
                                 cachedDeserFactories.get(i);
                            _call.registerTypeMapping(cls, qName, sf, df, false);
                        }
                        else if (x instanceof javax.xml.rpc.encoding.SerializerFactory) {
                            org.apache.axis.encoding.SerializerFactory sf = (org.apache.axis.encoding.SerializerFactory)
                                 cachedSerFactories.get(i);
                            org.apache.axis.encoding.DeserializerFactory df = (org.apache.axis.encoding.DeserializerFactory)
                                 cachedDeserFactories.get(i);
                            _call.registerTypeMapping(cls, qName, sf, df, false);
                        }
                    }
                }
            }
            return _call;
        }
        catch (java.lang.Throwable _t) {
            throw new org.apache.axis.AxisFault("Failure trying to get the Call object", _t);
        }
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO actualizarVersionODE(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String idOdeOriginal) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[0]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("actualizarVersionODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "actualizarVersionODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {pif, idUsuario, comentarios, titulo, idioma, idOdeOriginal});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.OdeSimilarVO[] calcularDuplicadosPublicados(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[1]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("calcularDuplicadosPublicados");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "calcularDuplicadosPublicados"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.OdeSimilarVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.OdeSimilarVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.OdeSimilarVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public boolean cambiarImagenODE(java.lang.String idODE, java.lang.String imagen) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[2]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("cambiarImagenODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "cambiarImagenODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, imagen});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return ((java.lang.Boolean) _resp).booleanValue();
            } catch (java.lang.Exception _exception) {
                return ((java.lang.Boolean) org.apache.axis.utils.JavaUtils.convert(_resp, boolean.class)).booleanValue();
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO compartirODE(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[3]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("compartirODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "compartirODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO creacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[4]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("creacion");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "creacion"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearDesdeURL(java.lang.String url, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String idiomaDestinatario, java.lang.String tipo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[5]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("crearDesdeURL");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearDesdeURL"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {url, idUsuario, comentarios, titulo, idioma, idiomaDestinatario, tipo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPIF(javax.activation.DataHandler ficheroPIF, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[6]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("crearPIF");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPIF"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {ficheroPIF, idUsuario, comentarios, titulo, idioma});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPIFCatalogado(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[7]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("crearPIFCatalogado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPIFCatalogado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {pif, idUsuario, comentarios, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuota(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[8]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("crearPifConCuota");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPifConCuota"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {pif, idUsuario, comentarios, titulo, idioma});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuotaID(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String id) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[9]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("crearPifConCuotaID");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPifConCuotaID"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {pif, idUsuario, comentarios, titulo, idioma, id});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuotaYEstado(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String estadoTransicion) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[10]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("crearPifConCuotaYEstado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "crearPifConCuotaYEstado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {pif, idUsuario, comentarios, titulo, idioma, estadoTransicion});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO descompartirODE(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[11]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("descompartirODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "descompartirODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO despublicarWebSemantica(java.lang.String idODE, java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[12]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("despublicarWebSemantica");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "despublicarWebSemantica"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO eliminar(java.lang.String idODEs, java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[13]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("eliminar");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminar"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODEs, idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.Boolean eliminarIdODEForzado(java.lang.String[] identificadores) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[14]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("eliminarIdODEForzado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarIdODEForzado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {identificadores});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.Boolean) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.Boolean) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.Boolean.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.EliminarResultadoVO[] eliminarNoDisponibles(es.pode.publicacion.negocio.servicios.EliminarNoDisponiblesVO parametro) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[15]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("eliminarNoDisponibles");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarNoDisponibles"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {parametro});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.EliminarResultadoVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.EliminarResultadoVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.EliminarResultadoVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.Boolean eliminarOdesUsuarios(java.lang.String[] usuarios) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[16]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("eliminarOdesUsuarios");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "eliminarOdesUsuarios"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {usuarios});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.Boolean) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.Boolean) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.Boolean.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public void guardarImagenPorDefecto(javax.activation.DataHandler imagenFile) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[17]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("guardarImagenPorDefecto");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "guardarImagenPorDefecto"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {imagenFile});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        extractAttachments(_call);
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.Boolean haEstadoVersionado(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[18]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("haEstadoVersionado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "haEstadoVersionado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.Boolean) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.Boolean) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.Boolean.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.Boolean insertarOdesFederadosDespublicados(es.pode.publicacion.negocio.servicios.TransicionVO[] odes, java.lang.String idNodo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[19]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("insertarOdesFederadosDespublicados");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "insertarOdesFederadosDespublicados"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {odes, idNodo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.Boolean) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.Boolean) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.Boolean.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO modificaODECreado(java.lang.String idODE, java.lang.String idUsuario, java.lang.String titulo, java.lang.String comentarios) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[20]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("modificaODECreado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "modificaODECreado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, titulo, comentarios});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO noDisponible(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[21]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("noDisponible");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "noDisponible"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[] noDisponibles(java.lang.String[] idODEs, java.lang.String idUsuario, java.lang.String comentario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[22]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("noDisponibles");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "noDisponibles"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODEs, idUsuario, comentario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.String[] obtenerEditoresOdeWebSemantica(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[23]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenerEditoresOdeWebSemantica");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerEditoresOdeWebSemantica"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.String[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.String[]) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.String[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.String[] obtenerOdesEditablesUsuarioWebSemantica(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[24]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenerOdesEditablesUsuarioWebSemantica");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerOdesEditablesUsuarioWebSemantica"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.String[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.String[]) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.String[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.String[] obtenerUsuariosCreacionDeIdentificadores(java.lang.String[] identificadores) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[25]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenerUsuariosCreacionDeIdentificadores");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerUsuariosCreacionDeIdentificadores"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {identificadores});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.String[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.String[]) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.String[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.String[] obtenerUsuariosCreacionPublicadosIdentificadores(java.lang.String[] idOdes) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[26]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenerUsuariosCreacionPublicadosIdentificadores");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenerUsuariosCreacionPublicadosIdentificadores"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idOdes});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.String[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.String[]) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.String[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.EstadoVO obtenEstadoPorIdODE(java.lang.String idODE, java.lang.String idioma) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[27]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenEstadoPorIdODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenEstadoPorIdODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idioma});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.EstadoVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.EstadoVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.EstadoVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenHistorialPorIdODE(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[28]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenHistorialPorIdODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenHistorialPorIdODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.LicenciaVO obtenLicenciaODE(java.lang.String idODE, java.lang.String idioma) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[29]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenLicenciaODE");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenLicenciaODE"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idioma});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.LicenciaVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.LicenciaVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.LicenciaVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.OdePublicadoVO obtenODEPublicado(java.lang.String idODE) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[30]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEPublicado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEPublicado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.OdePublicadoVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.OdePublicadoVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.OdePublicadoVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenODESCompartidos() throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[31]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODESCompartidos");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODESCompartidos"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenOdesCompartidosPorTitulo(java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[32]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenOdesCompartidosPorTitulo");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenOdesCompartidosPorTitulo"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenOdesCompartidosPorTituloYUsuarios(java.lang.String[] ids, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[33]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenOdesCompartidosPorTituloYUsuarios");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenOdesCompartidosPorTituloYUsuarios"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {ids, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenODEsCompartidosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[34]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsCompartidosPorUsuarios");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsCompartidosPorUsuarios"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {ids});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionAutorVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionAutorVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsCreadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[35]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsCreadosPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsCreadosPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsCreadosPorUsuarioPorTitulo(java.lang.String idUsuario, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[36]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsCreadosPorUsuarioPorTitulo");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsCreadosPorUsuarioPorTitulo"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicados() throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[37]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsDespublicados");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicados"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[] obtenODEsDespublicadosFederadosPorFecha(java.lang.String fechaInicio, java.lang.String fechaFin) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[38]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsDespublicadosFederadosPorFecha");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosFederadosPorFecha"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {fechaInicio, fechaFin});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorFecha(java.lang.String fechaInicio, java.lang.String fechaFin) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[39]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsDespublicadosPorFecha");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosPorFecha"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {fechaInicio, fechaFin});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[40]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsDespublicadosPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[41]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsDespublicadosPorUsuarios");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsDespublicadosPorUsuarios"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {ids});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestos() throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[42]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPropuestos");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestos"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODESPropuestosCatalogacion() throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[43]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODESPropuestosCatalogacion");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODESPropuestosCatalogacion"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODESPropuestosCatalogacionPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[44]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODESPropuestosCatalogacionPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODESPropuestosCatalogacionPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosCatalogacionPorUsuarios(java.lang.String[] idsUsuarios) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[45]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPropuestosCatalogacionPorUsuarios");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosCatalogacionPorUsuarios"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idsUsuarios});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[46]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPropuestosPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[47]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPropuestosPorUsuarios");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPropuestosPorUsuarios"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {ids});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.IdODEVO[] obtenODEsPublicados() throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[48]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicados");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicados"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.IdODEVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.IdODEVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.IdODEVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosAutonomo() throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[49]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicadosAutonomo");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosAutonomo"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosAutonomoPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[50]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicadosAutonomoPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosAutonomoPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorTitulo(java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[51]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicadosPorTitulo");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosPorTitulo"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorTituloYUsuario(java.lang.String titulo, java.lang.String[] idsUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[52]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicadosPorTituloYUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosPorTituloYUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {titulo, idsUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[53]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicadosPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadosPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.OdePublicadoVO[] obtenODEsPublicadoUsuario(java.lang.String usuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[54]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsPublicadoUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsPublicadoUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {usuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.OdePublicadoVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.OdePublicadoVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.OdePublicadoVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsRechazadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[55]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("obtenODEsRechazadosPorUsuario");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "obtenODEsRechazadosPorUsuario"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idUsuario});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.TransicionVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.TransicionVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerCatalogacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[56]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("proponerCatalogacion");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "proponerCatalogacion"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerCatalogacionNuevaVersion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.Boolean solicitaNuevaVersion) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[57]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("proponerCatalogacionNuevaVersion");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "proponerCatalogacionNuevaVersion"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo, solicitaNuevaVersion});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerPublicacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[58]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("proponerPublicacion");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "proponerPublicacion"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicar(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String comunidades, java.lang.String universal, java.lang.String textoLicencia, java.lang.String identificadorLicencia) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[59]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("publicar");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicar"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo, comunidades, universal, textoLicencia, identificadorLicencia});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarAutonomo(java.lang.String idODE, java.lang.String idUsuario, java.lang.String titulo, java.lang.String comentarios) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[60]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("publicarAutonomo");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarAutonomo"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, titulo, comentarios});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarDespublicado(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String comunidades, java.lang.String universal, java.lang.String textoLicencia, java.lang.String identificadorLicencia) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[61]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("publicarDespublicado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarDespublicado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo, comunidades, universal, textoLicencia, identificadorLicencia});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarPIF(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String sobrescribir, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[62]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("publicarPIF");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarPIF"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {pif, idUsuario, comentarios, sobrescribir, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[] publicarPifCarga(java.lang.String[] odes, java.lang.String idUsuario, java.lang.String sobrescribir, java.lang.String nombreCarga, java.lang.String pathCarga) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[63]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("publicarPifCarga");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarPifCarga"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {odes, idUsuario, sobrescribir, nombreCarga, pathCarga});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO publicarWebSemantica(byte[] zipODE, byte[] catalogacionReducida, java.lang.String idUsuario, java.lang.String titulo, java.lang.String[] listaUsuarioEditores, boolean esNuevaVersion, java.lang.String tipoPublicacion) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[64]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("publicarWebSemantica");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "publicarWebSemantica"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {new org.apache.axis.types.HexBinary(zipODE), new org.apache.axis.types.HexBinary(catalogacionReducida), idUsuario, titulo, listaUsuarioEditores, new java.lang.Boolean(esNuevaVersion), tipoPublicacion});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO rechazar(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[65]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("rechazar");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "rechazar"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, idUsuario, comentarios, titulo});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ResultadoOperacionVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ResultadoOperacionVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[] regeneraIndiceIdioma(es.pode.publicacion.negocio.servicios.RegeneracionIndiceVO paramRegenera) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[66]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("regeneraIndiceIdioma");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "regeneraIndiceIdioma"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {paramRegenera});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.Boolean regenerarImagenes(java.lang.Long idTarea) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[67]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("regenerarImagenes");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "regenerarImagenes"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idTarea});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.Boolean) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.Boolean) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.Boolean.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO reindexarODEPublicado(java.lang.String idODE, java.lang.Float valoracion) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[68]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("reindexarODEPublicado");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "reindexarODEPublicado"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODE, valoracion});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[] reindexarODEsPublicados(java.lang.String[] idODEs) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[69]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("reindexarODEsPublicados");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "reindexarODEsPublicados"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {idODEs});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[]) _resp;
            } catch (java.lang.Exception _exception) {
                return (es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[]) org.apache.axis.utils.JavaUtils.convert(_resp, es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[].class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

    public java.lang.String subirFichero(byte[] fichero, java.lang.String nombreFichero) throws java.rmi.RemoteException {
        if (super.cachedEndpoint == null) {
            throw new org.apache.axis.NoEndPointException();
        }
        org.apache.axis.client.Call _call = createCall();
        _call.setOperation(_operations[70]);
        _call.setUseSOAPAction(true);
        _call.setSOAPActionURI("subirFichero");
        _call.setEncodingStyle(null);
        _call.setProperty(org.apache.axis.client.Call.SEND_TYPE_ATTR, Boolean.FALSE);
        _call.setProperty(org.apache.axis.AxisEngine.PROP_DOMULTIREFS, Boolean.FALSE);
        _call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
        _call.setOperationName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "subirFichero"));

        setRequestHeaders(_call);
        setAttachments(_call);
 try {        java.lang.Object _resp = _call.invoke(new java.lang.Object[] {new org.apache.axis.types.HexBinary(fichero), nombreFichero});

        if (_resp instanceof java.rmi.RemoteException) {
            throw (java.rmi.RemoteException)_resp;
        }
        else {
            extractAttachments(_call);
            try {
                return (java.lang.String) _resp;
            } catch (java.lang.Exception _exception) {
                return (java.lang.String) org.apache.axis.utils.JavaUtils.convert(_resp, java.lang.String.class);
            }
        }
  } catch (org.apache.axis.AxisFault axisFaultException) {
  throw axisFaultException;
}
    }

}
