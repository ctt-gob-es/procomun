package com.emergya.agrega2.rdf2solr.test;

import java.io.IOException;

import org.apache.commons.io.IOUtils;
import org.junit.Assert;
import org.junit.Test;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.Utils;
import com.emergya.agrega2.odes.util.OdesMapping;

import es.pode.parseadorXML.ParseadorException;

public class ManifestTest {

    @Test
    public void encodingMecIdentifierTest() {
        try {
            Ode ode = OdesMapping.getOdeFromManifest(
                    IOUtils.toByteArray(ManifestTest.class.getResourceAsStream("/lomes_test.xml")), "UTF-8");

            Assert.assertTrue(!Utils.isEmpty(ode.getMecIdentifier()));
            Assert.assertTrue(!Utils.isEmpty(ode.getClassificationEducationalLevel1()));
        } catch (ParseadorException e) {
            Assert.fail("Exception generating ODE from manifest");
        } catch (IOException e) {
            Assert.fail("Exception processing manifest file");
        }

    }

}
