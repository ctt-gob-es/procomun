package com.emergya.agrega2.arranger.model.entity.aop;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * {@link Aspect} to process {@link SolrDocumentA2} before inject it on Solr.
 */
@Aspect
@Order(50)
@Component
public class SolrDocumentAspect {

    @Before("@annotation(com.emergya.agrega2.arranger.model.entity.aop.HandleSolrDocument)")
    public void generateFields(final JoinPoint joinPoint) {
        final Object[] args = joinPoint.getArgs();
        for (Object arg : args) {
            if (arg instanceof SolrDocumentA2) {
                SolrDocumentA2 doc = (SolrDocumentA2) arg;
                if (Utils.isEmpty(doc.getId())) {
                    // Generating ID
                    doc.setId(String.valueOf(Utils.getCurrentMillis()));
                    // ODEs: Generating ID from generalIdentifiers
                    if (doc instanceof Ode) {
                        ((Ode) doc).setGeneratedId(doc.generateId());
                    }
                } else {
                    // Updating Solr document
                    final SolrDocumentA2 solrDoc = SolrSupport.getSolrDocumentById(doc.getId());
                    Utils.copyProperties(solrDoc, doc);
                }
            }
        }
    }

}
