package com.emergya.agrega2.odes.beans;

import javax.xml.bind.annotation.XmlElement;

public class ContentFile implements Comparable<ContentFile> {

    private String url;
    private int order;
    private String title;
    private A2File file;

    public int getOrder() {
        return order;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    @XmlElement(required = true, nillable = false)
    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    @XmlElement(required = true, nillable = false)
    public A2File getFile() {
        return file;
    }

    public void setFile(A2File file) {
        this.file = file;
    }

    @Override
    public int compareTo(ContentFile other) {
        return new Integer(this.order).compareTo(other.getOrder());
    }

    @Override
    public boolean equals(Object o1) {
        if (o1 instanceof ContentFile) {
            return this.order == ((ContentFile) o1).getOrder();
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return order;
    }

}
