package com.emergya.agrega2.arranger.dumps;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.junit.Before;
import org.junit.Test;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.A2File;
import com.emergya.agrega2.odes.beans.ContentFile;
import com.emergya.agrega2.odes.service.impl.OdesServiceImpl;

public class OdesTests {

    private static final Log LOG = LogFactory.getLog(OdesTests.class);

    private static final String ID = String.valueOf(Utils.getCurrentMillis());
    private static final String FILE_LOCATION = "/home/ajrodriguez/Escritorio/originalZip.zip";
    private static final String CONTENT_LOCATION = "/home/ajrodriguez/Escritorio/10.png";

    Ode odeTest;
    A2File originalZip;

    @Test
    public void testOdeZip() {

        Utils.logInfo(LOG, "Triying to publish ODE with ID: {0}", ID);

        final OdesServiceImpl odesServiceImpl = new OdesServiceImpl();
        final ServiceResponse publishODEFormResult = odesServiceImpl.publishODEForm(odeTest, false, null, originalZip);

        assertTrue(publishODEFormResult.getResponseCode().equals(ResponseCode.OK));
        Utils.logInfo(LOG, publishODEFormResult.getMessage());
    }

    @Before
    public void init() {

        // Declaring values

        List<String> authors = new ArrayList<String>();
        authors.add("mfuente.atilano@gmail.com");

        List<ContentFile> contentTable = new ArrayList<ContentFile>();
        ContentFile contentFile = new ContentFile();
        A2File a2File = new A2File();

        final Path pathContentFile = Paths.get(CONTENT_LOCATION);
        try {
            a2File = new A2File("CONTENT", Files.readAllBytes(pathContentFile), null);
        } catch (IOException e) {
            Utils.logError(LOG, e);
            assertFalse(true);
        }

        contentFile.setFile(a2File);
        contentFile.setOrder(0);
        contentFile.setTitle("CONTENT");
        contentFile.setUrl("");
        contentTable.add(contentFile);

        String description = "ElODeMinimo";

        List<String> educationalContext = new ArrayList<String>();
        educationalContext.add("classroom");
        educationalContext.add("laboratory");
        educationalContext.add("blended");
        educationalContext.add("presencial");

        List<String> educationalDescription = new ArrayList<String>();
        educationalDescription.add("");
        educationalDescription.add("");

        List<String> educationalEndUserRol = new ArrayList<String>();
        educationalEndUserRol.add("gifted learner");
        educationalEndUserRol.add("individual");

        List<String> educationalLanguage = new ArrayList<String>();
        educationalLanguage.add("es");

        List<String> educationalLearningResourceType = new ArrayList<String>();
        educationalLearningResourceType.add("illustration");

        String generalAggregationLevel = "1";

        List<String> generalDescription = new ArrayList<String>();
        generalDescription.add("ElOdeMnimo");

        List<String> generalIdentifier = new ArrayList<String>();
        generalIdentifier.add("");

        List<String> generalKeyword = new ArrayList<String>();
        generalKeyword.add("");

        List<String> generalLanguage = new ArrayList<String>();
        generalLanguage.add("es");

        String generalTitle = "ElOdeMinimo";

        String id = ID;

        String idDrupal = "";

        List<String> knowledgeArea = new ArrayList<String>();
        knowledgeArea.add("Filosofía");

        List<String> labels = new ArrayList<String>();
        labels.add("");

        List<String> learningContext = new ArrayList<String>();
        learningContext.add("7 - 8 años / Segundo curso");

        List<String> lifeCycleContribute = new ArrayList<String>();
        lifeCycleContribute
                .add("author##BEGIN:VCARD VERSION:3.0 FN: Miguel Atilano EMAIL;TYPE=INTERNET:mfuente.atilano@gmail.com END:VCARD##2015-03-02T11:21:33.000Z##Fecha de creación");

        String odeNode = "";

        Date publicationDate = new Date();

        List<String> resourceType = new ArrayList<String>();
        resourceType.add("ilustración");

        String rightsAccess = "universal";

        String rightsAccessDescription = "universal";

        String rightsCopyrigthAndOtherRestrictions = "creative commons: attribution";

        String title = "ElOdeMinimo";

        // Setting values

        odeTest = new Ode();
        odeTest.setAuthor(authors);
        odeTest.setContentTable(contentTable);
        odeTest.setDescription(description);
        odeTest.setEducationalContext(educationalContext);
        odeTest.setEducationalDescription(educationalDescription);
        odeTest.setEducationalIntendedEndUserRole(educationalEndUserRol);
        odeTest.setEducationalLanguage(educationalLanguage);
        odeTest.setEducationalLearningResourceType(educationalLearningResourceType);
        odeTest.setGeneralAggregationLevel(generalAggregationLevel);
        odeTest.setGeneralDescription(generalDescription);
        odeTest.setGeneralIdentifier(generalIdentifier);
        odeTest.setGeneralKeyword(generalKeyword);
        odeTest.setGeneralLanguage(generalLanguage);
        odeTest.setGeneralTitle(generalTitle);
        odeTest.setId(id);
        odeTest.setIdDrupal(idDrupal);
        odeTest.setKnowledgeArea(knowledgeArea);
        odeTest.setLabels(labels);
        odeTest.setLearningContext(learningContext);
        odeTest.setLifecycleContribute(lifeCycleContribute);
        odeTest.setOdeNode(odeNode);
        odeTest.setPublicationDate(publicationDate);
        odeTest.setResourceType(resourceType);
        odeTest.setRightsAccess(rightsAccess);
        odeTest.setRightsAccessDescription(rightsAccessDescription);
        odeTest.setRightsCopyrightAndOtherRestrictions(rightsCopyrigthAndOtherRestrictions);
        odeTest.setTitle(title);

        final Path path = Paths.get(FILE_LOCATION);
        try {
            originalZip = new A2File("TEST", Files.readAllBytes(path), null);
        } catch (IOException e) {
            Utils.logError(LOG, e);
            assertFalse(true);
        }

    }
}
