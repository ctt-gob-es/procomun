package com.emergya.agrega2.odes.beans;

import java.io.Serializable;

import javax.xml.bind.annotation.XmlElement;

/**
 * Clase que incluiye un nombre de fichero y su contenido
 */
public class A2File implements Serializable {
    /**
     * 
     */
    private static final long serialVersionUID = -7667172828025362451L;

    /**
     * Nombre del fichero
     */
    private String fileName;

    /**
     * Contenido del fichero
     */
    private byte[] content;

    /**
     * Ruta de la carpeta temporal que los contiene (opcional)
     */
    private String tmpFolderPath;

    public A2File() {
        super();
    }

    public A2File(String fileName, byte[] content, String tmpFolderPath) {
        super();
        this.fileName = fileName;
        this.content = content;
        this.tmpFolderPath = tmpFolderPath;
    }

    @XmlElement(required = true, nillable = false)
    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public byte[] getContent() {
        return content;
    }

    public void setContent(byte[] content) {
        this.content = content;
    }

    public String getTmpFolderPath() {
        return tmpFolderPath;
    }

    public void setTmpFolderPath(String tmpFolderPath) {
        this.tmpFolderPath = tmpFolderPath;
    }

    /**
     * Devuelve si el objeto es o no válido
     * @return false si el nombre del fichero o el contenido son nulos
     */
    public boolean isValid() {
        return fileName != null && content != null;
    }

}
