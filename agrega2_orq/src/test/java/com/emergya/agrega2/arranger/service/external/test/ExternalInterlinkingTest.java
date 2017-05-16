package com.emergya.agrega2.arranger.service.external.test;

import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.junit.Assert;

import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.service.external.impl.EuropeanaWrapperImpl;
import com.emergya.agrega2.odes.service.external.impl.HispanaWrapperImpl;
import com.emergya.agrega2.odes.service.external.impl.InterlinkingWrapper;
import com.emergya.agrega2.odes.service.external.impl.MuseoPradoWrapperImpl;
import com.emergya.agrega2.odes.service.external.impl.RedinedSolrWrapperImpl;

public class ExternalInterlinkingTest {

    private static final Log LOG = LogFactory.getLog(ExternalInterlinkingTest.class);

    private final String TITLE2SEARCH = "El quijote";

    private InterlinkingWrapper ctrlElPrado;
    private InterlinkingWrapper ctrlEuropeana;
    private InterlinkingWrapper ctrlRedined;
    private InterlinkingWrapper ctrlHispana;

    // @Before
    public void init() {
        ctrlElPrado = new MuseoPradoWrapperImpl();
        ctrlEuropeana = new EuropeanaWrapperImpl();
        ctrlRedined = new RedinedSolrWrapperImpl();
        ctrlHispana = new HispanaWrapperImpl();
    }

    // @Test
    public void testElPrado() {
        Assert.assertNotNull(ctrlElPrado);
        final List<String> content = ctrlElPrado.getContent(TITLE2SEARCH);
        Assert.assertNotNull(content);
        Assert.assertFalse(content.isEmpty());
        for (final String s : content) {
            Utils.logInfo(LOG, "Found El Prado result: {0}", s);
        }
    }

    // @Test
    public void testEuropeana() {
        Assert.assertNotNull(ctrlEuropeana);
        final List<String> content = ctrlEuropeana.getContent(TITLE2SEARCH);
        Assert.assertNotNull(content);
        Assert.assertFalse(content.isEmpty());
        for (final String s : content) {
            Utils.logInfo(LOG, "Found Europeana result: {0}", s);
        }
    }

    // @Test
    public void testRedined() {
        Assert.assertNotNull(ctrlRedined);
        final List<String> content = ctrlRedined.getContent(TITLE2SEARCH);
        Assert.assertNotNull(content);
        Assert.assertFalse(content.isEmpty());
        for (final String s : content) {
            Utils.logInfo(LOG, "Found Redined result: {0}", s);
        }
    }

    // @Test
    public void testHispana() {
        Assert.assertNotNull(ctrlHispana);
        final List<String> content = ctrlHispana.getContent(TITLE2SEARCH);
        Assert.assertNotNull(content);
        Assert.assertFalse(content.isEmpty());
        for (final String s : content) {
            Utils.logInfo(LOG, "Found Hispana result: {0}", s);
        }
    }

}
