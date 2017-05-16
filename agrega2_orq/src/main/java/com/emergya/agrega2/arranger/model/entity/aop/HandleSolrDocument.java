package com.emergya.agrega2.arranger.model.entity.aop;

import static java.lang.annotation.ElementType.METHOD;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

/**
 * Annotation that specifies operations on {@link SolrDocumentA2} before inject it on Solr.
 */
@Target({ METHOD })
@Retention(RetentionPolicy.RUNTIME)
public @interface HandleSolrDocument {

}
