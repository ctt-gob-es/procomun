package com.emergya.agrega2.arranger.model.entity.solr;

import java.io.Serializable;

import org.apache.solr.client.solrj.beans.Field;

/**
 * Base Entity
 */
public abstract class Entity implements Serializable {

    /**
     * 
     */
    private static final long serialVersionUID = 201595862784369207L;

    /**
     * This entity instance unique id.
     */
    @Field("id")
    private String id;

    private String token;

    private long timeStamp;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;

    }

    public String getToken() {
        return token;
    }

    public long getTimeStamp() {
        return timeStamp;
    }

    @Override
    public int hashCode() {
        return getId().hashCode();
    }

    @Override
    public boolean equals(final Object obj) {
        return equalsInClass(this, obj);
    }

    static public boolean equalsInClass(final Entity entity1, final Object object2) {
        if (entity1 == null && object2 == null) {
            return true;
        }
        if ((entity1 != null && object2 == null) || (entity1 == null && object2 != null) || !(object2 instanceof Entity)) {
            return false;
        }
        final Class<? extends Entity> cls1 = entity1.getClass();
        final Entity entity2 = (Entity) object2;
        final Class<? extends Entity> cls2 = entity2.getClass();
        return cls1 == cls2 && entity1.getId() == entity2.getId();
    }

    static public <T extends Entity> boolean equalsInType(final T entity1, final Object object2, final Class<T> cls) {
        if (entity1 == null && object2 == null) {
            return true;
        }
        if (cls == null || (entity1 != null && object2 == null) || (entity1 == null && object2 != null) || !cls.isInstance(object2)) {
            return false;
        }
        @SuppressWarnings("unchecked")
        final T entity2 = (T) object2;
        return entity1.getId() == entity2.getId();
    }
}
