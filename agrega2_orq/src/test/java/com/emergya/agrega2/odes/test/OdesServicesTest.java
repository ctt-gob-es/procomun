package com.emergya.agrega2.odes.test;

import java.io.File;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.junit.Assert;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.A2File;
import com.emergya.agrega2.odes.beans.ContentFile;
import com.emergya.agrega2.odes.service.impl.OdesServiceImpl;
import com.emergya.agrega2.odes.util.OdesUtil;

public class OdesServicesTest {

	private static final Log LOG = LogFactory.getLog(OdesServicesTest.class);

	private A2File zipFile = null;

	private Ode ode = null;

	// @Test
	public void getOdeFromFile() {
		try {
			initFile();
			Ode ode = OdesUtil.getOdeFromA2File(zipFile, "idTest", "authorTest", "titleTest");
			Assert.assertNotNull(ode);

			// Al parsear el fichero, no obtenemos el contentTable
			setContentTable(ode);

			OdesServiceImpl odesService = new OdesServiceImpl();
			Assert.assertTrue(ResponseCode.OK.equals(odesService.validateODEForm(ode).getResponseCode()));
		} catch (Exception e) {
			Assert.fail(e.getMessage());
		}
	}

	private void initFile() throws Exception {
		zipFile = new A2File();
		zipFile.setFileName("Test_Emergya-SCORM_2004.zip");
		zipFile.setContent(IOUtils.toByteArray(this.getClass().getResourceAsStream("Test_Emergya-SCORM_2004.zip")));
	}

	// @Test
	public void getManifestFromOde() {
		try {
			initOde();
			A2File file = OdesUtil.getIMSManifest(ode);

			Assert.assertTrue(Utils.getMessage("agrega.scorm.default.manifest_name").equals(file.getFileName()));
			Assert.assertNotNull(file.getContent());
			Assert.assertTrue(file.getContent().length > 0);

			File fileTmp = new File("/tmp/imsmanifestTest.xml");
			IOUtils.write(file.getContent(), new FileOutputStream(fileTmp));
			OdesServiceImpl odesService = new OdesServiceImpl();
			ServiceResponse response = odesService.validateODEFile(new A2File[] { file });
			Utils.logInfo(LOG, response.getMessage());
			Assert.assertTrue(ResponseCode.OK.equals(response.getResponseCode()));
		} catch (Exception e) {
			Assert.fail(e.getMessage());
		}
	}

	/**
	 * Minimal ODE initialization from Solr query.
	 * 
	 * @throws Exception
	 */
	private void initOde() throws Exception {
		// ode =
		// OdesUtil.getOdeFromManifest(IOUtils.toByteArray(this.getClass().getResourceAsStream("imsmanifest.xml")));
		ode = new Ode();
		ode.setTitle("Test ODE");
		ode.setDescription("Test ODE description TEST-1234567890");
		List<String> autores = new ArrayList<String>();
		autores.add(DataFactoryUtil.getNombre() + DataFactoryUtil.getApellido() + "@test.com");
		ode.setAuthor(autores);
		ode.setPublicationDate(new Date());
		// ode.setGeneralTitle("Test ODE");
		ode.setGeneralIdentifier(Arrays.asList(new String[] { "TEST-1234567890", "TEST-1234567890Z" }));
		ode.setGeneralDescription(Arrays.asList(
				new String[] { "Test ODE description TEST-1234567890", "Test ODE description 2 TEST-1234567890" }));
		ode.setGeneralAggregationLevel("2");
		ode.setGeneralKeyword(Arrays.asList(new String[] { "TEST-ODE", "TEST-Keyword" }));
		ode.setGeneralLanguage(Arrays.asList(new String[] { "es" }));

		ode.setEducationalLearningResourceType(Arrays.asList(new String[] { "real or virtual learning environment" }));
		ode.setEducationalLanguage(Arrays.asList(new String[] { "es" }));

		ode.setRightsCopyrightAndOtherRestrictions("creative commons: attribution - non commercial - share alike");
		ode.setRightsAccess("universal");
		ode.setRightsAccessDescription("Access Type Description");

		List<String> edLevel = new ArrayList<String>();
		edLevel.add(Utils.getNivel_educativo().get("1"));
		edLevel.add(Utils.getNivel_educativo().get("2"));
		edLevel.add(Utils.getNivel_educativo().get("3"));
		ode.setClassificationEducationalLevel1(edLevel);

		edLevel = new ArrayList<String>();
		edLevel.add(Utils.getNivel_educativo().get("1.1"));
		edLevel.add("");
		edLevel.add(Utils.getNivel_educativo().get("3.1"));
		ode.setClassificationEducationalLevel2(edLevel);

		setContentTable(ode);
	}

	private void setContentTable(Ode ode) {
		List<ContentFile> contentTable = new ArrayList<ContentFile>();
		ContentFile contentFile = new ContentFile();
		contentFile.setTitle("Ejemplo ODE file");
		A2File fileAux = new A2File();
		fileAux.setFileName("Ejemplo.txt");
		contentFile.setFile(fileAux);
		contentFile.setOrder(1);
		contentTable.add(contentFile);
		ode.setContentTable(contentTable);
	}
	
}
