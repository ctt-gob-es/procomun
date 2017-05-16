package com.emergya.agrega2.odes.util;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import javax.net.ssl.HttpsURLConnection;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathExpression;
import javax.xml.xpath.XPathExpressionException;
import javax.xml.xpath.XPathFactory;

import org.apache.commons.compress.archivers.ArchiveEntry;
import org.apache.commons.compress.archivers.zip.ZipArchiveEntry;
import org.apache.commons.compress.archivers.zip.ZipArchiveInputStream;
import org.apache.commons.compress.archivers.zip.ZipFile;
import org.apache.commons.io.FileUtils;
import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.security.crypto.codec.Base64;
import org.springframework.util.StringUtils;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.A2File;

import es.pode.parseadorXML.ParseadorException;
import es.pode.parseadorXML.castor.Item;
import es.pode.parseadorXML.castor.Manifest;
import es.pode.parseadorXML.castor.Organization;
import es.pode.parseadorXML.castor.Organizations;
import es.pode.parseadorXML.castor.Resource;
import es.pode.parseadorXML.castor.Resources;

public class OdesUtil {
	private static final Log LOG = LogFactory.getLog(OdesUtil.class);

	private OdesUtil() {

	}

	/**
	 * Method to get a single XPath value from an XML
	 * 
	 * @param doc
	 *            XML source
	 * @param xPathExpression
	 *            XPath expression to search
	 * @return Result of the evaluation of the XPath expression in the document
	 * @throws XPathExpressionException
	 *             if the expression is not correct
	 */
	public static String getXPathValue(Document doc, String xPathExpression) throws XPathExpressionException {
		XPath xpath = XPathFactory.newInstance().newXPath();
		XPathExpression xPathExp = xpath.compile(xPathExpression);
		if (xPathExp != null) {
			return xPathExp.evaluate(doc);
		} else {
			return null;
		}
	}

	/**
	 * Method to get a multiple XPath value from an XML
	 * 
	 * @param doc
	 *            XML source
	 * @param xPathExpression
	 *            XPath expression to search
	 * @return Result of the evaluation of the XPath expression in the document
	 * @throws XPathExpressionException
	 *             if the expression is not correct
	 */
	public static List<String> getXPathMultiValue(Document doc, String xPathExpression)
			throws XPathExpressionException {
		List<String> result = new ArrayList<String>();
		XPath xpath = XPathFactory.newInstance().newXPath();

		XPathExpression xPathExp = xpath.compile(xPathExpression);
		if (xPathExp != null) {
			NodeList ids = (NodeList) xPathExp.evaluate(doc, XPathConstants.NODESET);
			if (ids != null) {
				for (int idx = 0; idx < ids.getLength(); idx++) {
					Node id = ids.item(idx);
					result.add(id.getTextContent());
				}
			}
		}

		return result;
	}

	/**
	 * Method to get the XPath result from an XML
	 * 
	 * @param manifest
	 *            XML source
	 * @param property
	 *            XPath property to search
	 * @param multiple
	 *            Multiple values or a single one
	 * @return A String with the single value or a List of String if multiple
	 *         values are requested; null if no values are found.
	 */
	public static Object getManifestProperty(byte[] manifest, String property, boolean multiple) {
		Object result = null;
		if (manifest != null) {
			DocumentBuilder dBuilder;
			try {
				dBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
				Document manifestDoc = dBuilder.parse(new ByteArrayInputStream(manifest));

				if (multiple) {
					result = getXPathMultiValue(manifestDoc, property);
				} else {
					result = getXPathValue(manifestDoc, property);
				}
			} catch (Exception e) {
				Utils.logError(LOG, e.getMessage());
			}
		}

		return result;
	}

	/**
	 * Method to generate an Ode catalog file
	 * 
	 * @param catalog
	 *            {@link Ode} with the information to fill the manifest
	 * @return ODE catalog {@link A2File} (imsmanifest.xml)
	 */
	public static A2File getIMSManifest(Ode catalog) {
		A2File file = new A2File();
		try {
			file = OdesMapping.getManifestFromOde(catalog);
		} catch (Exception e) {
			Utils.logError(LOG, e, "Error building manifest from ODE: " + e.getMessage());
		}

		return file;
	}

	/**
	 * Method to extract the catalog {@link A2File} from an ODE in ZIP format
	 * 
	 * @param {@link
	 * 			A2File} with the ODE in ZIP format, with catalog file inside
	 *            (ie. files generated in eXeLearning)
	 * @return ODE catalog {@link A2File} (imsmanifest.xml, and optionally
	 *         imslrm.xml with lomes catalog)
	 */
	public static A2File[] getIMSManifest(A2File zipFile) throws NullPointerException {
		A2File[] files = new A2File[2];

		if (zipFile != null && zipFile.isValid()) {
			try {
				Utils.logDebug(LOG, "Extracting Manifest from ZIP");
				File fileMem = getFilefromA2File(zipFile);

				ZipFile zip = new ZipFile(fileMem, "UTF-8");

				ZipArchiveEntry entry = zip.getEntry(Utils.getMessage("agrega.scorm.default.manifest_name"));
				InputStream is = zip.getInputStream(entry);

				byte[] content = IOUtils.toByteArray(is);

				A2File file = new A2File();
				file.setFileName(Utils.getMessage("agrega.scorm.default.manifest_name"));
				file.setContent(content);
				files[0] = file;

				DocumentBuilder dBuilder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
				Document manifest = dBuilder.parse(new ByteArrayInputStream(content));

				String auxFileName = null;
				try {
					auxFileName = OdesUtil.getXPathValue(manifest, Utils.getMessage("agrega.lomes.xpath.auxFile"));
				} catch (XPathExpressionException e) {
					Utils.logWarn(LOG, e.getMessage());
				}
				if (!StringUtils.isEmpty(auxFileName)) {
					Utils.logDebug(LOG, "Manifest Aux File with LOM-ES data: " + auxFileName);
					ZipArchiveEntry auxEntry = zip.getEntry(auxFileName);
					InputStream isAux = zip.getInputStream(auxEntry);

					byte[] auxContent = IOUtils.toByteArray(isAux);

					A2File auxFile = new A2File();
					auxFile.setFileName(auxFileName);
					auxFile.setContent(auxContent);
					files[1] = auxFile;
				}

				zip.close();

				if (fileMem != null) {
					fileMem.delete();
				}

			} catch (IOException e) {
				Utils.logError(LOG, e.getMessage());
			} catch (ParserConfigurationException e) {
				Utils.logError(LOG, e.getMessage());
			} catch (SAXException e) {
				Utils.logError(LOG, e.getMessage());
			} catch (NullPointerException e) {
				Utils.logError(LOG, e.getMessage());
				throw new NullPointerException();
			}

		}

		return files;
	}

	public static File getFilefromA2File(A2File zipFile) throws FileNotFoundException, IOException {
		File fileMem = new File(Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + zipFile.getFileName());
		FileOutputStream fos = new FileOutputStream(fileMem);
		fos.write(zipFile.getContent());
		fos.close();
		return fileMem;
	}

	/**
	 * Method to publish an ODE in Agrega
	 * 
	 * @param {@link
	 * 			A2File} with the ODE in ZIP format, with catalog file inside
	 *            (ie. files generated in eXeLearning)
	 * @return ODe generated
	 */
	public static Ode publishODEZip(A2File zipFile, String author, String title, String editor, String newVersion,
			String publicationType) {
		ServiceResponse result = null;

		// El servicio de agrega recibe el fichero en Base64
		byte[] base64Content = Base64.encode(zipFile.getContent());

		// result = AgregaUtil.publishODE(base64Content, author, title, editor,
		// newVersion, publicationType);

		// Changed to https://redmine.emergya.es/issues/146285#note-12
		result = AgregaUtil.publishODE(base64Content, author, title, editor, "false", publicationType);

		// If Agrega response is OK, we inject document in Solr, generating its
		// IDs
		Ode ode = null;
		if (result.getResponseCode().equals(ResponseCode.OK)) {

			final String mecIdentifier = result.getMessage();

			try {
				final byte[] scorm2004 = AgregaUtil.getScorm2004(mecIdentifier);
				if (!Utils.isEmpty(scorm2004)) {
					zipFile.setContent(scorm2004);
				} else {
					result = AgregaUtil.despublishODE(mecIdentifier, author);
					Utils.logError(LOG, "Cannot getting ODE published on Agrega with MECD ID {0}.", mecIdentifier);
				}

			} catch (IOException e) {
				Utils.logError(LOG, "Error getting ODE published on Agrega.");
			}

			List<String> ids = new ArrayList<String>();
			ids.add(mecIdentifier);

			try {

				ode = getOdeFromA2File(zipFile, mecIdentifier, author, title);
				ode.setGeneratedId(ode.generateId());
				ode.setId(String.valueOf(Utils.getCurrentMillis()));
				ode.setGeneralIdentifier(ids);
				ode.setMecIdentifier(mecIdentifier);
				
			} catch (ParseadorException e) {
				Utils.logError(LOG, "Error building ODE from manifest file: " + e.getMessage());
			}

		} else {
			Utils.logError(LOG, "Error publishing ODE on Agrega. Code {0}, Message {1}",
					result.getResponseCode().toString(), result.getMessage());
			ode = new Ode();
			ode.setDescription(result.getMessage());
		}

		return ode;
	}

	/**
	 * Method to extract the {@link Ode} information from an ODE in ZIP format
	 * 
	 * @param zipFile
	 *            ODE in Zip format
	 * @param idOde
	 *            Id of the resource in Solr
	 * @param author
	 *            Author of the resource
	 * @param title
	 *            Title of the resource
	 * @return {@link Ode} information
	 */
	public static Ode getOdeFromA2File(A2File zipFile, String idOde, String author, String title)
			throws ParseadorException {
		Ode ode = new Ode();

		A2File[] manifestFiles = getIMSManifest(zipFile);
		A2File imsmanifest = manifestFiles[0];

		File manifestTmpFile = null;
		File tmpDir = null;

		try {
			// Create tmpDirectory
			final String tmpDirLocation = Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + "/";
			tmpDir = new File(tmpDirLocation);
			tmpDir.mkdir();

			imsmanifest.setTmpFolderPath(tmpDirLocation);

			// Create tmp Manifest file
			manifestTmpFile = new File(tmpDirLocation + "imsmanifest.xml");

			FileUtils.writeByteArrayToFile(manifestTmpFile, imsmanifest.getContent());

			if (manifestFiles[1] != null) {
				// Create tmp Imslrm file
				A2File imslrm = manifestFiles[1];
				File imslrmTmpFile = new File(tmpDirLocation + "imslrm.xml");
				FileUtils.writeByteArrayToFile(imslrmTmpFile, imslrm.getContent());
				imslrm.setTmpFolderPath(tmpDirLocation);
			}

			ode = OdesMapping.getOdeFromManifest(imsmanifest);
			tmpDir.delete();

		} catch (IOException e) {
			Utils.logError(LOG, "Error building ODE TEMP FILES: " + e.getMessage());
		} finally {
			if (tmpDir != null) {
				tmpDir.delete();
			}
			if (manifestTmpFile != null) {
				manifestTmpFile.delete();
			}
		}
		return ode;

	}

	public static boolean getOdeSCORM2004(final URL url, final String fileName) {

		boolean done = false;

		HttpsURLConnection con = null;
		OutputStream output = null;
		InputStream inputStream = null;

		try {
			con = (HttpsURLConnection) url.openConnection();
			// Check for errors
			int responseCode = con.getResponseCode();
			if (responseCode == HttpURLConnection.HTTP_OK) {
				inputStream = con.getInputStream();
			} else {
				inputStream = con.getErrorStream();
			}

			output = new FileOutputStream(fileName);

			// Process the response
			BufferedReader reader;
			String line = null;
			reader = new BufferedReader(new InputStreamReader(inputStream));
			while ((line = reader.readLine()) != null) {
				output.write(line.getBytes());
			}

			output.close();
			inputStream.close();

			done = true;
		} catch (IOException e) {
			Utils.logError(LOG, "Cannot obtain SCORM 2004 to process");
		} finally {
			if (con != null) {

			}
		}

		return done;

	}

	public static Manifest getManifestFromResourceFiles(final Ode ode, final List<String> files) {

		Manifest manifest = new Manifest();

		String orgIdent = Utils.getUUID(OdesMapping.class.toString(), "ORG-");

		// Creating Organization
		Organizations orgs = new Organizations();
		orgs.setDefault(orgIdent);
		Organization org = new Organization();
		org.setIdentifier(orgIdent);
		org.setTitle(Utils.getMessage("agrega.lomes.default.organization"));

		Item item = new Item();
		String itemIdent = Utils.getUUID(OdesMapping.class.toString(), "ITEM-");
		String resourceIdent = Utils.getUUID(OdesMapping.class.toString(), "RES-");
		item.setIdentifierref(resourceIdent);
		item.setIdentifier(itemIdent);
		item.setTitle(ode.getTitle());
		org.addItem(0, item);

		// Creating One Resource with Some Files.
		Resources ress = new Resources();
		Resource res = new Resource();
		res.setIdentifier(resourceIdent);
		res.setType("webcontent");
		res.setScormType("asset");
		res.setHref(files.get(0));
		for (String fileStr : files) {
			es.pode.parseadorXML.castor.File vFile = new es.pode.parseadorXML.castor.File();
			vFile.setHref(fileStr);
			res.addFile(vFile);
		}
		ress.addResource(res);

		orgs.addOrganization(org);
		manifest.setOrganizations(orgs);
		manifest.setResources(ress);

		return manifest;

	}

	/**
	 * Get all files and process paths and names from A2File
	 * 
	 * @param originalZip
	 *            Original A2File
	 * @return List<String> With paths
	 * @throws IOException
	 */
	public static List<String> getContentList(final A2File originalZip) throws IOException {
		List<String> originalZipFilesStr = new ArrayList<String>();
		File originalZipFile = null;
		String tmpZipPath = Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + ".zip";
		originalZipFile = new File(tmpZipPath);

		OutputStream fileOuputStream;
		fileOuputStream = new FileOutputStream(originalZipFile);
		fileOuputStream.write(originalZip.getContent());
		fileOuputStream.close();

		ZipArchiveInputStream zaos = new ZipArchiveInputStream(new ByteArrayInputStream(originalZip.getContent()));
		StringBuffer path = new StringBuffer("/");
		ArchiveEntry nextEntry = zaos.getNextEntry();
		while (nextEntry != null) {
			boolean notLeaf = nextEntry.isDirectory();
			String name = nextEntry.getName();
			while (notLeaf) {
				path.append(name).append("/");
				nextEntry = zaos.getNextEntry();
				notLeaf = nextEntry.isDirectory();
				name = nextEntry.getName();
			}
			path.append(name);
			originalZipFilesStr.add(path.toString());
			path = new StringBuffer("/");
			nextEntry = zaos.getNextEntry();
		}
		zaos.close();

		return originalZipFilesStr;
	}

}
