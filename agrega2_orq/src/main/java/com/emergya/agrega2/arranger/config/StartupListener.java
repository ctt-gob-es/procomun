package com.emergya.agrega2.arranger.config;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.context.ApplicationListener;
import org.springframework.context.event.ContextRefreshedEvent;
import org.springframework.stereotype.Component;

import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;

@Component
public class StartupListener implements ApplicationListener<ContextRefreshedEvent> {

    private static final Log LOG = LogFactory.getLog(StartupListener.class);

    @Override
    public void onApplicationEvent(ContextRefreshedEvent arg0) {
        final boolean result = SolrSupport.setSolrBoostingFieldsFromDrupal();
        if (!result) {
            Utils.logError(LOG, "Cannot load Boosting info from Drupal");
        }

    }

}
