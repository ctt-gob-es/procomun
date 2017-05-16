/**
 * LomESPrimarioVO.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;


/**
 * Este Value Object modela todos aquellos atributos relevantes del
 * ODE que estan en el LOM-ES de catalogacion primario  del ODE.
 */
public class LomESPrimarioVO  implements java.io.Serializable {
    /* Titulo del ODE. */
    private java.lang.String titulo;

    /* Recursos presentes en un ODE. Un ODE puede estar compuesto
     * de
     *                                 multiples elementos y estos ser de
     * diferentes tipos. */
    private java.lang.String[] recurso;

    /* Niveles educativos del ODE. */
    private java.lang.String[] nivelesEducativos;

    /* Idioma en el que esta catalogado el ODE. */
    private java.lang.String idioma;

    /* Formatos presentes en el ODE. */
    private java.lang.String[] formatos;

    /* Fecha de publicacion del ODE. */
    private java.util.Calendar fechaPublicacion;

    /* Edades del publico al que va dirigido el ODE. */
    private java.lang.String[] edades;

    /* La descripcion del ODE. */
    private java.lang.String descripcion;

    /* Contextos del ODE. */
    private java.lang.String[] contextos;

    /* Autor del ODE. */
    private java.lang.String[] autor;

    /* Arbol curricular al que pertenece el ODE. Pueden existir varias
     * clasificaciones curriculares para un mismo ODE. */
    private java.lang.String[] arbolCurricular;

    /* Destinatarios del ODE. Un ODE puede tener como destinatarios
     * de
     *                                 la accion lectiva diferentes colectivos. */
    private java.lang.String[] destinatarios;

    /* Licencia del ODE. */
    private java.lang.String licencia;

    /* Ambito del ODE. */
    private java.lang.String ambito;

    /* Curso al que pertenece el ODE. */
    private java.lang.String curso;

    /* Palabras clave de la clasificacion del ODE. */
    private java.lang.String[] palabrasClave;

    /* Los procesos cognitivos del ODE. */
    private java.lang.String[] procesosCognitivos;

    /* Nivel de agregacion del ODE. */
    private java.lang.Integer nivelAgregacion;

    public LomESPrimarioVO() {
    }

    public LomESPrimarioVO(
           java.lang.String titulo,
           java.lang.String[] recurso,
           java.lang.String[] nivelesEducativos,
           java.lang.String idioma,
           java.lang.String[] formatos,
           java.util.Calendar fechaPublicacion,
           java.lang.String[] edades,
           java.lang.String descripcion,
           java.lang.String[] contextos,
           java.lang.String[] autor,
           java.lang.String[] arbolCurricular,
           java.lang.String[] destinatarios,
           java.lang.String licencia,
           java.lang.String ambito,
           java.lang.String curso,
           java.lang.String[] palabrasClave,
           java.lang.String[] procesosCognitivos,
           java.lang.Integer nivelAgregacion) {
           this.titulo = titulo;
           this.recurso = recurso;
           this.nivelesEducativos = nivelesEducativos;
           this.idioma = idioma;
           this.formatos = formatos;
           this.fechaPublicacion = fechaPublicacion;
           this.edades = edades;
           this.descripcion = descripcion;
           this.contextos = contextos;
           this.autor = autor;
           this.arbolCurricular = arbolCurricular;
           this.destinatarios = destinatarios;
           this.licencia = licencia;
           this.ambito = ambito;
           this.curso = curso;
           this.palabrasClave = palabrasClave;
           this.procesosCognitivos = procesosCognitivos;
           this.nivelAgregacion = nivelAgregacion;
    }


    /**
     * Gets the titulo value for this LomESPrimarioVO.
     * 
     * @return titulo   * Titulo del ODE.
     */
    public java.lang.String getTitulo() {
        return titulo;
    }


    /**
     * Sets the titulo value for this LomESPrimarioVO.
     * 
     * @param titulo   * Titulo del ODE.
     */
    public void setTitulo(java.lang.String titulo) {
        this.titulo = titulo;
    }


    /**
     * Gets the recurso value for this LomESPrimarioVO.
     * 
     * @return recurso   * Recursos presentes en un ODE. Un ODE puede estar compuesto
     * de
     *                                 multiples elementos y estos ser de
     * diferentes tipos.
     */
    public java.lang.String[] getRecurso() {
        return recurso;
    }


    /**
     * Sets the recurso value for this LomESPrimarioVO.
     * 
     * @param recurso   * Recursos presentes en un ODE. Un ODE puede estar compuesto
     * de
     *                                 multiples elementos y estos ser de
     * diferentes tipos.
     */
    public void setRecurso(java.lang.String[] recurso) {
        this.recurso = recurso;
    }


    /**
     * Gets the nivelesEducativos value for this LomESPrimarioVO.
     * 
     * @return nivelesEducativos   * Niveles educativos del ODE.
     */
    public java.lang.String[] getNivelesEducativos() {
        return nivelesEducativos;
    }


    /**
     * Sets the nivelesEducativos value for this LomESPrimarioVO.
     * 
     * @param nivelesEducativos   * Niveles educativos del ODE.
     */
    public void setNivelesEducativos(java.lang.String[] nivelesEducativos) {
        this.nivelesEducativos = nivelesEducativos;
    }


    /**
     * Gets the idioma value for this LomESPrimarioVO.
     * 
     * @return idioma   * Idioma en el que esta catalogado el ODE.
     */
    public java.lang.String getIdioma() {
        return idioma;
    }


    /**
     * Sets the idioma value for this LomESPrimarioVO.
     * 
     * @param idioma   * Idioma en el que esta catalogado el ODE.
     */
    public void setIdioma(java.lang.String idioma) {
        this.idioma = idioma;
    }


    /**
     * Gets the formatos value for this LomESPrimarioVO.
     * 
     * @return formatos   * Formatos presentes en el ODE.
     */
    public java.lang.String[] getFormatos() {
        return formatos;
    }


    /**
     * Sets the formatos value for this LomESPrimarioVO.
     * 
     * @param formatos   * Formatos presentes en el ODE.
     */
    public void setFormatos(java.lang.String[] formatos) {
        this.formatos = formatos;
    }


    /**
     * Gets the fechaPublicacion value for this LomESPrimarioVO.
     * 
     * @return fechaPublicacion   * Fecha de publicacion del ODE.
     */
    public java.util.Calendar getFechaPublicacion() {
        return fechaPublicacion;
    }


    /**
     * Sets the fechaPublicacion value for this LomESPrimarioVO.
     * 
     * @param fechaPublicacion   * Fecha de publicacion del ODE.
     */
    public void setFechaPublicacion(java.util.Calendar fechaPublicacion) {
        this.fechaPublicacion = fechaPublicacion;
    }


    /**
     * Gets the edades value for this LomESPrimarioVO.
     * 
     * @return edades   * Edades del publico al que va dirigido el ODE.
     */
    public java.lang.String[] getEdades() {
        return edades;
    }


    /**
     * Sets the edades value for this LomESPrimarioVO.
     * 
     * @param edades   * Edades del publico al que va dirigido el ODE.
     */
    public void setEdades(java.lang.String[] edades) {
        this.edades = edades;
    }


    /**
     * Gets the descripcion value for this LomESPrimarioVO.
     * 
     * @return descripcion   * La descripcion del ODE.
     */
    public java.lang.String getDescripcion() {
        return descripcion;
    }


    /**
     * Sets the descripcion value for this LomESPrimarioVO.
     * 
     * @param descripcion   * La descripcion del ODE.
     */
    public void setDescripcion(java.lang.String descripcion) {
        this.descripcion = descripcion;
    }


    /**
     * Gets the contextos value for this LomESPrimarioVO.
     * 
     * @return contextos   * Contextos del ODE.
     */
    public java.lang.String[] getContextos() {
        return contextos;
    }


    /**
     * Sets the contextos value for this LomESPrimarioVO.
     * 
     * @param contextos   * Contextos del ODE.
     */
    public void setContextos(java.lang.String[] contextos) {
        this.contextos = contextos;
    }


    /**
     * Gets the autor value for this LomESPrimarioVO.
     * 
     * @return autor   * Autor del ODE.
     */
    public java.lang.String[] getAutor() {
        return autor;
    }


    /**
     * Sets the autor value for this LomESPrimarioVO.
     * 
     * @param autor   * Autor del ODE.
     */
    public void setAutor(java.lang.String[] autor) {
        this.autor = autor;
    }


    /**
     * Gets the arbolCurricular value for this LomESPrimarioVO.
     * 
     * @return arbolCurricular   * Arbol curricular al que pertenece el ODE. Pueden existir varias
     * clasificaciones curriculares para un mismo ODE.
     */
    public java.lang.String[] getArbolCurricular() {
        return arbolCurricular;
    }


    /**
     * Sets the arbolCurricular value for this LomESPrimarioVO.
     * 
     * @param arbolCurricular   * Arbol curricular al que pertenece el ODE. Pueden existir varias
     * clasificaciones curriculares para un mismo ODE.
     */
    public void setArbolCurricular(java.lang.String[] arbolCurricular) {
        this.arbolCurricular = arbolCurricular;
    }


    /**
     * Gets the destinatarios value for this LomESPrimarioVO.
     * 
     * @return destinatarios   * Destinatarios del ODE. Un ODE puede tener como destinatarios
     * de
     *                                 la accion lectiva diferentes colectivos.
     */
    public java.lang.String[] getDestinatarios() {
        return destinatarios;
    }


    /**
     * Sets the destinatarios value for this LomESPrimarioVO.
     * 
     * @param destinatarios   * Destinatarios del ODE. Un ODE puede tener como destinatarios
     * de
     *                                 la accion lectiva diferentes colectivos.
     */
    public void setDestinatarios(java.lang.String[] destinatarios) {
        this.destinatarios = destinatarios;
    }


    /**
     * Gets the licencia value for this LomESPrimarioVO.
     * 
     * @return licencia   * Licencia del ODE.
     */
    public java.lang.String getLicencia() {
        return licencia;
    }


    /**
     * Sets the licencia value for this LomESPrimarioVO.
     * 
     * @param licencia   * Licencia del ODE.
     */
    public void setLicencia(java.lang.String licencia) {
        this.licencia = licencia;
    }


    /**
     * Gets the ambito value for this LomESPrimarioVO.
     * 
     * @return ambito   * Ambito del ODE.
     */
    public java.lang.String getAmbito() {
        return ambito;
    }


    /**
     * Sets the ambito value for this LomESPrimarioVO.
     * 
     * @param ambito   * Ambito del ODE.
     */
    public void setAmbito(java.lang.String ambito) {
        this.ambito = ambito;
    }


    /**
     * Gets the curso value for this LomESPrimarioVO.
     * 
     * @return curso   * Curso al que pertenece el ODE.
     */
    public java.lang.String getCurso() {
        return curso;
    }


    /**
     * Sets the curso value for this LomESPrimarioVO.
     * 
     * @param curso   * Curso al que pertenece el ODE.
     */
    public void setCurso(java.lang.String curso) {
        this.curso = curso;
    }


    /**
     * Gets the palabrasClave value for this LomESPrimarioVO.
     * 
     * @return palabrasClave   * Palabras clave de la clasificacion del ODE.
     */
    public java.lang.String[] getPalabrasClave() {
        return palabrasClave;
    }


    /**
     * Sets the palabrasClave value for this LomESPrimarioVO.
     * 
     * @param palabrasClave   * Palabras clave de la clasificacion del ODE.
     */
    public void setPalabrasClave(java.lang.String[] palabrasClave) {
        this.palabrasClave = palabrasClave;
    }


    /**
     * Gets the procesosCognitivos value for this LomESPrimarioVO.
     * 
     * @return procesosCognitivos   * Los procesos cognitivos del ODE.
     */
    public java.lang.String[] getProcesosCognitivos() {
        return procesosCognitivos;
    }


    /**
     * Sets the procesosCognitivos value for this LomESPrimarioVO.
     * 
     * @param procesosCognitivos   * Los procesos cognitivos del ODE.
     */
    public void setProcesosCognitivos(java.lang.String[] procesosCognitivos) {
        this.procesosCognitivos = procesosCognitivos;
    }


    /**
     * Gets the nivelAgregacion value for this LomESPrimarioVO.
     * 
     * @return nivelAgregacion   * Nivel de agregacion del ODE.
     */
    public java.lang.Integer getNivelAgregacion() {
        return nivelAgregacion;
    }


    /**
     * Sets the nivelAgregacion value for this LomESPrimarioVO.
     * 
     * @param nivelAgregacion   * Nivel de agregacion del ODE.
     */
    public void setNivelAgregacion(java.lang.Integer nivelAgregacion) {
        this.nivelAgregacion = nivelAgregacion;
    }

    private java.lang.Object __equalsCalc = null;
    public synchronized boolean equals(java.lang.Object obj) {
        if (!(obj instanceof LomESPrimarioVO)) return false;
        LomESPrimarioVO other = (LomESPrimarioVO) obj;
        if (obj == null) return false;
        if (this == obj) return true;
        if (__equalsCalc != null) {
            return (__equalsCalc == obj);
        }
        __equalsCalc = obj;
        boolean _equals;
        _equals = true && 
            ((this.titulo==null && other.getTitulo()==null) || 
             (this.titulo!=null &&
              this.titulo.equals(other.getTitulo()))) &&
            ((this.recurso==null && other.getRecurso()==null) || 
             (this.recurso!=null &&
              java.util.Arrays.equals(this.recurso, other.getRecurso()))) &&
            ((this.nivelesEducativos==null && other.getNivelesEducativos()==null) || 
             (this.nivelesEducativos!=null &&
              java.util.Arrays.equals(this.nivelesEducativos, other.getNivelesEducativos()))) &&
            ((this.idioma==null && other.getIdioma()==null) || 
             (this.idioma!=null &&
              this.idioma.equals(other.getIdioma()))) &&
            ((this.formatos==null && other.getFormatos()==null) || 
             (this.formatos!=null &&
              java.util.Arrays.equals(this.formatos, other.getFormatos()))) &&
            ((this.fechaPublicacion==null && other.getFechaPublicacion()==null) || 
             (this.fechaPublicacion!=null &&
              this.fechaPublicacion.equals(other.getFechaPublicacion()))) &&
            ((this.edades==null && other.getEdades()==null) || 
             (this.edades!=null &&
              java.util.Arrays.equals(this.edades, other.getEdades()))) &&
            ((this.descripcion==null && other.getDescripcion()==null) || 
             (this.descripcion!=null &&
              this.descripcion.equals(other.getDescripcion()))) &&
            ((this.contextos==null && other.getContextos()==null) || 
             (this.contextos!=null &&
              java.util.Arrays.equals(this.contextos, other.getContextos()))) &&
            ((this.autor==null && other.getAutor()==null) || 
             (this.autor!=null &&
              java.util.Arrays.equals(this.autor, other.getAutor()))) &&
            ((this.arbolCurricular==null && other.getArbolCurricular()==null) || 
             (this.arbolCurricular!=null &&
              java.util.Arrays.equals(this.arbolCurricular, other.getArbolCurricular()))) &&
            ((this.destinatarios==null && other.getDestinatarios()==null) || 
             (this.destinatarios!=null &&
              java.util.Arrays.equals(this.destinatarios, other.getDestinatarios()))) &&
            ((this.licencia==null && other.getLicencia()==null) || 
             (this.licencia!=null &&
              this.licencia.equals(other.getLicencia()))) &&
            ((this.ambito==null && other.getAmbito()==null) || 
             (this.ambito!=null &&
              this.ambito.equals(other.getAmbito()))) &&
            ((this.curso==null && other.getCurso()==null) || 
             (this.curso!=null &&
              this.curso.equals(other.getCurso()))) &&
            ((this.palabrasClave==null && other.getPalabrasClave()==null) || 
             (this.palabrasClave!=null &&
              java.util.Arrays.equals(this.palabrasClave, other.getPalabrasClave()))) &&
            ((this.procesosCognitivos==null && other.getProcesosCognitivos()==null) || 
             (this.procesosCognitivos!=null &&
              java.util.Arrays.equals(this.procesosCognitivos, other.getProcesosCognitivos()))) &&
            ((this.nivelAgregacion==null && other.getNivelAgregacion()==null) || 
             (this.nivelAgregacion!=null &&
              this.nivelAgregacion.equals(other.getNivelAgregacion())));
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
        if (getTitulo() != null) {
            _hashCode += getTitulo().hashCode();
        }
        if (getRecurso() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getRecurso());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getRecurso(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getNivelesEducativos() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getNivelesEducativos());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getNivelesEducativos(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getIdioma() != null) {
            _hashCode += getIdioma().hashCode();
        }
        if (getFormatos() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getFormatos());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getFormatos(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getFechaPublicacion() != null) {
            _hashCode += getFechaPublicacion().hashCode();
        }
        if (getEdades() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getEdades());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getEdades(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getDescripcion() != null) {
            _hashCode += getDescripcion().hashCode();
        }
        if (getContextos() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getContextos());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getContextos(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getAutor() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getAutor());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getAutor(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getArbolCurricular() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getArbolCurricular());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getArbolCurricular(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getDestinatarios() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getDestinatarios());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getDestinatarios(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getLicencia() != null) {
            _hashCode += getLicencia().hashCode();
        }
        if (getAmbito() != null) {
            _hashCode += getAmbito().hashCode();
        }
        if (getCurso() != null) {
            _hashCode += getCurso().hashCode();
        }
        if (getPalabrasClave() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getPalabrasClave());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getPalabrasClave(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getProcesosCognitivos() != null) {
            for (int i=0;
                 i<java.lang.reflect.Array.getLength(getProcesosCognitivos());
                 i++) {
                java.lang.Object obj = java.lang.reflect.Array.get(getProcesosCognitivos(), i);
                if (obj != null &&
                    !obj.getClass().isArray()) {
                    _hashCode += obj.hashCode();
                }
            }
        }
        if (getNivelAgregacion() != null) {
            _hashCode += getNivelAgregacion().hashCode();
        }
        __hashCodeCalc = false;
        return _hashCode;
    }

    // Type metadata
    private static org.apache.axis.description.TypeDesc typeDesc =
        new org.apache.axis.description.TypeDesc(LomESPrimarioVO.class, true);

    static {
        typeDesc.setXmlType(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "LomESPrimarioVO"));
        org.apache.axis.description.ElementDesc elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("titulo");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "titulo"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("recurso");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "recurso"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("nivelesEducativos");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nivelesEducativos"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("idioma");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "idioma"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("formatos");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "formatos"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("fechaPublicacion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "fechaPublicacion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "dateTime"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("edades");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "edades"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("descripcion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "descripcion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("contextos");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "contextos"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("autor");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "autor"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("arbolCurricular");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "arbolCurricular"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("destinatarios");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "destinatarios"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("licencia");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "licencia"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("ambito");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "ambito"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("curso");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "curso"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(false);
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("palabrasClave");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "palabrasClave"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("procesosCognitivos");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "procesosCognitivos"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://www.w3.org/2001/XMLSchema", "string"));
        elemField.setNillable(true);
        elemField.setItemQName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "item"));
        typeDesc.addFieldDesc(elemField);
        elemField = new org.apache.axis.description.ElementDesc();
        elemField.setFieldName("nivelAgregacion");
        elemField.setXmlName(new javax.xml.namespace.QName("http://servicios.negocio.publicacion.pode.es", "nivelAgregacion"));
        elemField.setXmlType(new javax.xml.namespace.QName("http://schemas.xmlsoap.org/soap/encoding/", "int"));
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
