package com.emergya.agrega2.odes.service.impl;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.nio.file.FileSystem;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.jws.WebMethod;
import javax.jws.WebService;
import javax.xml.ws.WebServiceContext;
import javax.xml.ws.handler.MessageContext;
import javax.xml.ws.soap.MTOM;

import org.apache.commons.compress.archivers.zip.ZipArchiveEntry;
import org.apache.commons.compress.archivers.zip.ZipArchiveOutputStream;
import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.codehaus.jackson.map.ObjectMapper;
import org.springframework.security.crypto.codec.Base64;
import org.springframework.util.StringUtils;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.A2File;
import com.emergya.agrega2.odes.beans.ContentFile;
import com.emergya.agrega2.odes.util.AgregaUtil;
import com.emergya.agrega2.odes.util.OdesMapping;
import com.emergya.agrega2.odes.util.OdesUtil;
import com.sun.xml.messaging.saaj.packaging.mime.internet.MimeUtility;
import com.sun.xml.ws.api.message.Header;
import com.sun.xml.ws.api.message.HeaderList;
import com.sun.xml.ws.developer.JAXWSProperties;
import com.sun.xml.ws.developer.SchemaValidation;

import es.pode.adminusuarios.negocio.servicios.UsuarioVO;
import es.pode.buscar.negocio.buscar.servicios.ValoresBusquedaVO;
import es.pode.parseadorXML.ParseadorException;
import es.pode.parseadorXML.SCORM2004Dao;
import es.pode.parseadorXML.castor.Manifest;
import es.pode.parseadorXML.castor.Organizations;
import es.pode.parseadorXML.castor.Resource;
import es.pode.parseadorXML.castor.Resources;
import es.pode.parseadorXML.lomes.lomesAgrega.EntidadAgrega;
import es.pode.parseadorXML.lomes.lomesAgrega.LifeCycleAgrega;
import es.pode.parseadorXML.scorm2004.agrega.ManifestAgrega;

/**
 * Class to implement ODE validation and publication web services in Agrega
 */
/**
 * @author ajrodriguez
 *
 */
@MTOM
@SchemaValidation
@WebService(serviceName = "odesService", targetNamespace = "http://ws.odes.agrega2.emergya.com/")
public class OdesServiceImpl {

    @javax.annotation.Resource
    WebServiceContext wsctx;

    private static final Log LOG = LogFactory.getLog(OdesServiceImpl.class);

    private static final String PREVIEW_NAME = "vistaPreviaAgrega.png";

    public static final String AGREGA_URL = "agrega.url";

    /**
     * Catalog mode
     */
    private static final String ODE_COMPLETE = "ODE_COMPLETO";
    private static final String ODE_MIN_CATALOG = "ODE_CATALOGACION_MINIMA";

    /**
     * Method to validate an ODE catalog (from a social network form)
     * @param catalog ODE catalog form
     * @return ODE validation result
     */
    @WebMethod
    public ServiceResponse validateODEForm(Ode catalog) {

        // if (!validateRequest()) {
        // return new ServiceResponse(ResponseCode.NOK, 401,
        // "Security Exception.");
        // }

        A2File file = OdesUtil.getIMSManifest(catalog);

        final ServiceResponse result = validateODEFile(new A2File[] { file });

        Utils.logInfo(LOG, "Result from validateODEForm: " + result.getHttpResponseCode() + " -> " + result.getMessage());

        return result;
    }

    /**
     * Method to validate an ODE catalog (from a catalog file: IMSManifest.xml)
     * @param catalogFile ODE catalog file (IMSManifest.xml)
     * @return ODE validation result
     */
    @WebMethod
    public ServiceResponse validateODEFile(A2File[] catalogFile) {

        // if (!validateRequest()) {
        // return new ServiceResponse(ResponseCode.NOK, 401,
        // "Security Exception.");
        // }

        if (catalogFile != null && catalogFile[0] != null && catalogFile[0].isValid()) {
            String filename = catalogFile[0].getFileName();
            if (filename != null && Base64.isBase64(filename.getBytes())) {
                filename = new String(Base64.decode(filename.getBytes()));
            }
            try {
                // TODO: El fichero viene codificado como quoted-printable, por
                // lo que los = vienen como =3D
                byte[] message = IOUtils.toByteArray(MimeUtility.decode(new ByteArrayInputStream(catalogFile[0].getContent()), "quoted-printable"));
                // El servicio de agrega recibe el fichero en Base64
                byte[] base64Content = Base64.encode(message);
                message = null;

                // Procesamos el fichero con la catalogación
                byte[] auxBase64Content = null;
                if (catalogFile.length > 1 && catalogFile[1] != null && catalogFile[1].isValid()) {
                    String auxFilename = catalogFile[1].getFileName();
                    if (auxFilename != null && Base64.isBase64(auxFilename.getBytes())) {
                        auxFilename = new String(Base64.decode(auxFilename.getBytes()));
                    }
                    byte[] auxMessage = IOUtils.toByteArray(MimeUtility.decode(new ByteArrayInputStream(catalogFile[1].getContent()), "quoted-printable"));
                    // El servicio de agrega recibe el fichero en Base64
                    auxBase64Content = Base64.encode(auxMessage);
                    auxMessage = null;
                }

                ServiceResponse result = AgregaUtil.validateODE(base64Content, auxBase64Content);
                return result;

            } catch (Exception e) {
                Utils.logError(LOG, e, "Error in validateODEFile:" + e.getMessage());
                return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_REQUEST, "Catalog file is not valid");
            }
        } else {
            Utils.logError(LOG, "Error in validateODEFile: Catalog file name or content is null");
            return new ServiceResponse(ResponseCode.NOK, HttpURLConnection.HTTP_BAD_REQUEST, "Catalog file name or content is null");
        }

    }

    /** Extraxt Ode object from zip File with catalog in SCORM 2004
     * @param zipFile ZIP file with SCORM 2004
     * @param author ODE Author
     * @return Ode object if OK, null in other case.
     * @throws IOException 
     * @throws JsonMappingException 
     * @throws  
     */
    @WebMethod
    public ServiceResponse preloadOdeFile(final A2File zipFile, final String author, final Boolean isNewVersion) {

        Ode ode = null;

        try {
            ode = OdesUtil.getOdeFromA2File(zipFile, null, author, null);

        } catch (ParseadorException e) {
            Utils.logError(LOG, "Error building ODE from manifest file: " + e.getMessage() + ".Maybe format belongs to SCORM1.2.");
            return new ServiceResponse(ResponseCode.RETRY_PUBLISH_ODE, 200, "Error building ODE from manifest file: " + e.getMessage() + ". Maybe format belongs to SCORM1.2.",
                    "-1", null);
        }
        if (ode == null) {
            Utils.logWarn(LOG, "Cannot preload ODE data. ODE null.");
            return new ServiceResponse(ResponseCode.NOK, 200, "Cannot generate Ode object from zip file.", "-1", null);
        } else {
            final ObjectMapper mapper = new ObjectMapper();
            try {
                Utils.logInfo(LOG, mapper.writerWithDefaultPrettyPrinter().writeValueAsString(ode));
            } catch (IOException e) {
                Utils.logError(LOG, "Cannot prettyprinter Ode");
            }

            return new ServiceResponse(ResponseCode.OK, 200, "Ode generation OK.", "-1", ode);
        }
    }

    /**
     * Method to publish an ODE
     * @param zipFile ODE in ZIP format, with catalog file inside (ie. files generated in eXeLearning)
     * @return ODE publication result
     */
    @WebMethod
    public ServiceResponse publishODEFile(final A2File zipFile, final String author, final Boolean isNewVersion, final A2File preview) {

        // if (!validateRequest()) {
        // return new ServiceResponse(ResponseCode.NOK, 401,
        // "Security Exception.");
        // }

        A2File[] catalogFiles;
        ServiceResponse result;

        // Preview
        File zipFileResult = null;
        File previewFile = null;
        if (!Utils.isEmpty(preview) && !Utils.isEmpty(preview.getContent())) {
            try {

                final String tmpZipPath = Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + ".zip";
                zipFileResult = new File(tmpZipPath);

                final String tmpPreviewPath = Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + PREVIEW_NAME + ".png";
                previewFile = new File(tmpPreviewPath);

                OutputStream fileOuputStream = new FileOutputStream(zipFileResult);
                fileOuputStream.write(zipFile.getContent());
                fileOuputStream.close();

                OutputStream fileOuputStream2 = new FileOutputStream(previewFile);
                fileOuputStream2.write(preview.getContent());
                fileOuputStream2.close();

                Path zipFilePath = Paths.get(tmpZipPath), pathToSaveInsideZIP = null;
                Path previewPath = Paths.get(tmpPreviewPath);

                FileSystem fs = FileSystems.newFileSystem(zipFilePath, null);
                pathToSaveInsideZIP = fs.getPath(PREVIEW_NAME);
                Files.deleteIfExists(pathToSaveInsideZIP);
                Files.createDirectories(pathToSaveInsideZIP);
                Files.copy(previewPath, pathToSaveInsideZIP, StandardCopyOption.REPLACE_EXISTING);
                fs.close();

                zipFile.setContent(IOUtils.toByteArray(new FileInputStream(zipFileResult)));
            } catch (java.nio.file.NoSuchFileException e) {
                if (zipFileResult != null) {
                    zipFileResult.delete();
                }
                if (previewFile != null) {
                    previewFile.delete();
                }
                Utils.logError(LOG, e, "ERROR building TMP ZIP");
                return new ServiceResponse(ResponseCode.NOK, "El fichero debe contener un archivo de imagen correcto.");
            } catch (IOException e) {
                if (zipFileResult != null) {
                    zipFileResult.delete();
                }
                if (previewFile != null) {
                    previewFile.delete();
                }
                Utils.logError(LOG, e, "ERROR building TMP ZIP");
                return new ServiceResponse(ResponseCode.NOK, "El fichero debe contener un archivo de imagen correcto.");
            }
        }

        try {
            catalogFiles = OdesUtil.getIMSManifest(zipFile);
        } catch (NullPointerException e) {
            if (zipFileResult != null) {
                zipFileResult.delete();
            }
            if (previewFile != null) {
                previewFile.delete();
            }
            return new ServiceResponse(ResponseCode.NOK, "El fichero debe contener un archivo imsmanifest.xml");
        }

        String authorTmp = new String(author);

        result = validateODEFile(catalogFiles);

        if (result.getResponseCode().equals(ResponseCode.OK)) {
            A2File lomes = catalogFiles[0];
            if (catalogFiles[1] != null) {
                lomes = catalogFiles[1];
            }
            String title = (String) OdesUtil.getManifestProperty(lomes.getContent(), Utils.getMessage("agrega.lomes.xpath.general.title"), false);
            if (StringUtils.isEmpty(author)) {
                LifeCycleAgrega lifeCycleAgrega = new LifeCycleAgrega(null);
                EntidadAgrega vCard = null;
                try {
                    vCard = lifeCycleAgrega.interpretaVCard((String) OdesUtil.getManifestProperty(lomes.getContent(), Utils.getMessage("agrega.lomes.xpath.author"), false));
                    authorTmp = vCard.getCorreo();
                    if (StringUtils.isEmpty(author)) {
                        authorTmp = vCard.getNombre();
                    }
                } catch (Exception e) {
                    Utils.logError(LOG, e, "Error parsing resource author: " + e.getMessage());
                }
            }

            Ode ode = OdesUtil.publishODEZip(zipFile, author, title, authorTmp, isNewVersion == null ? "true" : isNewVersion.toString(), ODE_COMPLETE);

            // Setting ODE Node and ODE preview
            if (!Utils.isEmpty(ode.getMecIdentifier())) {
                try {
                    final ValoresBusquedaVO valorBusqueda = AgregaUtil.getResultadoBusquedaODE(ode.getMecIdentifier(), ode.getGeneralLanguage().get(0));
                    if (valorBusqueda != null) {
                        String previewAgrega = valorBusqueda.getUrlImagen();
                        String node = valorBusqueda.getNodo();
                        if (Utils.isEmpty(node)) {
                            node = Utils.getMessage(AGREGA_URL).replace("http://", "");
                        }
                        if (!Utils.isEmpty(previewAgrega)) {
                            previewAgrega = node + valorBusqueda.getUrlImagen();
                        }

                        // Setting custom fields to index performance
                        ode.setOdeNode(node);
                        ode.setPreview(previewAgrega);

                        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(ode.getMecIdentifier());
                        final String publicatorStr = AgregaUtil.getPublicator(agregaUser, node);
                        final String publicatorNameStr = AgregaUtil.getPublicatorName(agregaUser);
                        final String publicatorEmailStr = agregaUser != null ? agregaUser.getEmail() : "";

                        ode.setPublicator(publicatorStr);
                        ode.setPublicatorName(publicatorNameStr);
                        ode.setPublicatorEmail(publicatorEmailStr);
                    }

                    if (ode != null && SolrSupport.injectDocument(ode)) {
                        result = new ServiceResponse(ResponseCode.OK, 200, "Ode published", ode.getId());
                    } else {
                        result = new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published");
                    }
                } catch (Exception e) {
                    result = new ServiceResponse(ResponseCode.NOK, 200, "Publication NOK. ODE null.", "-1", null);
                }
            } else {
                result = new ServiceResponse(ResponseCode.NOK, 509, ode.getDescription());
            }

        } else if (result.getResponseCode().equals(ResponseCode.NOK)) {

            Ode ode = null;

            try {
                ode = OdesUtil.getOdeFromA2File(zipFile, null, author, null);
            } catch (ParseadorException e) {
                return new ServiceResponse(ResponseCode.NOK, 206, "Validation NOK. Returns partial ODE to complete.", "-1", null);
            }
            if (ode == null) {
                result = new ServiceResponse(ResponseCode.NOK, 206, "Validation NOK. Returns partial ODE to complete.", "-1", null);
            } else {
                result = new ServiceResponse(ResponseCode.NOK, 206, "Validation NOK. Returns partial ODE to complete.", "-1", ode);
            }
        }

        if (zipFileResult != null) {
            zipFileResult.delete();
        }
        if (previewFile != null) {
            previewFile.delete();
        }

        return result;
    }

    @WebMethod
    public ServiceResponse publishODEForm(final Ode catalog, final Boolean isNewVersion, final A2File preview, final A2File originalZip) {

        // if (!validateRequest()) {
        // return new ServiceResponse(ResponseCode.NOK, 401,
        // "Security Exception.");
        // }

        ServiceResponse result;
        final ObjectMapper mapper = new ObjectMapper();
        try {
            Utils.logInfo(LOG, mapper.writerWithDefaultPrettyPrinter().writeValueAsString(catalog));
        } catch (IOException e) {
            Utils.logError(LOG, "Cannot prettyprinter Ode");
        }
        ServiceResponse validationResult = validateODEForm(catalog);

        if (validationResult.getResponseCode().equals(ResponseCode.OK)) {
            A2File zipFileA2 = null;
            File filefromA2File = null;

            Manifest manifest;
            try {
                manifest = OdesMapping.initialManifest(catalog);
            } catch (Exception e1) {
                return new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published in Agrega. Cannot obtain Manifest from ODE.");
            }

            List<String> originalZipFilesStr = null;
            String tmpZipPath = null;
            // If we've got previous ZIP SCORM
            if (originalZip != null && !Utils.isEmpty(originalZip.getContent())) {

                // Clean catalog's (Ode) content table
                catalog.setContentTable(new ArrayList<ContentFile>());

                try {
                    filefromA2File = OdesUtil.getFilefromA2File(originalZip);

                    tmpZipPath = filefromA2File.getAbsolutePath();

                    final SCORM2004Dao dao = new SCORM2004Dao();

                    final A2File[] imsManifestArray = OdesUtil.getIMSManifest(originalZip);
                    A2File lomes = imsManifestArray[0];
                    if (imsManifestArray[1] != null) {
                        lomes = imsManifestArray[1];
                    }

                    final InputStream is = new ByteArrayInputStream(lomes.getContent());
                    Manifest manifestOrigin = dao.parsearODEEager(is);

                    Resources resources;
                    Organizations organizations;

                    // If we haven't imsmanifest.xml file on originalZip, get
                    // all files and process paths and names.
                    if (manifestOrigin == null) {
                        originalZipFilesStr = OdesUtil.getContentList(originalZip);

                        manifestOrigin = OdesUtil.getManifestFromResourceFiles(catalog, originalZipFilesStr);
                        organizations = manifestOrigin.getOrganizations();
                        resources = manifestOrigin.getResources();

                    } else { // If we have imsmanifest.xml, add organizations
                             // and resobytesurces to list of paths

                        organizations = manifestOrigin.getOrganizations();
                        resources = manifestOrigin.getResources();
                        // If imslrm.xml have not resources
                        if (Utils.isEmpty(organizations) && Utils.isEmpty(resources)) {
                            lomes = imsManifestArray[0];
                            final InputStream isAux = new ByteArrayInputStream(lomes.getContent());
                            Manifest manifestOriginAux = dao.parsearODEEager(isAux);
                            organizations = manifestOriginAux.getOrganizations();
                            resources = manifestOriginAux.getResources();
                        } else {

                        }

                        // Getting all hrefs in originalZip
                        if (resources != null && resources.getResourceCount() > 0) {
                            originalZipFilesStr = new ArrayList<String>();
                            for (int i = 0; i < resources.getResourceCount(); i++) {
                                Resource resource = resources.getResource(i);
                                String href = resource.getHref();
                                if (!Utils.isEmpty(href)) {
                                    if (!originalZipFilesStr.contains(href)) {
                                        originalZipFilesStr.add(href);
                                    }
                                }
                                for (int j = 0; j < resource.getFileCount(); j++) {
                                    es.pode.parseadorXML.castor.File file = resource.getFile(j);
                                    href = file.getHref();
                                    if (!Utils.isEmpty(href) && !originalZipFilesStr.contains(href)) {
                                        originalZipFilesStr.add(href);
                                    }
                                }
                            }
                        }
                    }
                    // Now sets resources and organizations to new
                    // imsmanifest.xml created from user form
                    manifest.setOrganizations(organizations);
                    manifest.setResources(resources);

                } catch (ParseadorException e) {
                    if (filefromA2File != null) {
                        filefromA2File.delete();
                    }
                    Utils.logError(LOG, e);
                    return new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published in Agrega. Cannot obtain previous Resources from original ZIP.");
                } catch (IOException e) {
                    if (filefromA2File != null) {
                        filefromA2File.delete();
                    }
                    Utils.logError(LOG, e);
                    return new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published in Agrega. Cannot obtain Content associated to originalZip A2File.");
                }

            }

            A2File manifestA2File;
            try {
                manifestA2File = OdesMapping.getManifestFile(new ManifestAgrega(manifest));
            } catch (Exception e1) {
                if (filefromA2File != null) {
                    filefromA2File.delete();
                }
                Utils.logError(LOG, e1);
                return new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published in Agrega. Cannot obtain A2File from manifest.");
            }

            File zipFile = null;

            final String newZipFileLocation = Utils.getMessage("TMP_FOLDER") + Utils.getCurrentMillis() + ".zip";
            try {
                zipFile = new File(newZipFileLocation);
                ZipArchiveOutputStream zaos = new ZipArchiveOutputStream(zipFile);

                /* Manifest */
                ZipArchiveEntry zae = new ZipArchiveEntry(Utils.getMessage("agrega.scorm.default.manifest_name"));
                zae.setSize(manifestA2File.getContent().length);
                zaos.putArchiveEntry(zae);
                zaos.write(manifestA2File.getContent());
                zaos.closeArchiveEntry();

                /* Files */
                if (!Utils.isEmpty(catalog.getContentTable())) {
                    for (ContentFile file : catalog.getContentTable()) {
                        if (file != null && file.getFile() != null) {
                            ZipArchiveEntry zFile = new ZipArchiveEntry(file.getFile().getFileName());
                            zFile.setSize(file.getFile().getContent().length);
                            zaos.putArchiveEntry(zFile);
                            zaos.write(file.getFile().getContent());
                            zaos.closeArchiveEntry();
                        }
                    }
                }

                // Miniatura
                if (!Utils.isEmpty(preview) && !Utils.isEmpty(preview.getContent())) {
                    ZipArchiveEntry zFile = new ZipArchiveEntry(PREVIEW_NAME);
                    zFile.setSize(preview.getContent().length);
                    zaos.putArchiveEntry(zFile);
                    zaos.write(preview.getContent());
                    zaos.closeArchiveEntry();
                }

                zaos.close();
                zipFileA2 = new A2File();
                zipFileA2.setFileName(zipFile.getName());
                zipFileA2.setContent(IOUtils.toByteArray(new FileInputStream(zipFile)));
            } catch (IOException e) {
                Utils.logError(LOG, e.getMessage());
            }

            // If we've got originalZip, put into zipFile content associated
            if (!Utils.isEmpty(tmpZipPath) && !Utils.isEmpty(originalZipFilesStr)) {

                try {

                    Path zipFilePathNew = Paths.get(newZipFileLocation);
                    Path zipFilePathOriginal = Paths.get(tmpZipPath);

                    FileSystem fsNew = FileSystems.newFileSystem(zipFilePathNew, null);
                    FileSystem fsOriginal = FileSystems.newFileSystem(zipFilePathOriginal, null);

                    for (String contentPathStr : originalZipFilesStr) {
                        Path pathToSaveInsideZIP = fsNew.getPath(contentPathStr);
                        Path pathToGetFromZIP = fsOriginal.getPath(contentPathStr);

                        Files.createDirectories(pathToSaveInsideZIP);

                        Files.copy(pathToGetFromZIP, pathToSaveInsideZIP, StandardCopyOption.REPLACE_EXISTING);
                    }
                    fsNew.close();
                    fsOriginal.close();

                    // Update content
                    zipFileA2.setContent(IOUtils.toByteArray(new FileInputStream(zipFile)));

                } catch (IOException e) {
                    if (zipFile != null) {
                        zipFile.delete();
                    }
                    if (filefromA2File != null) {
                        filefromA2File.delete();
                    }
                    Utils.logError(LOG, e);
                    return new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published in Agrega. Cannot obtain and copy Content associated to originalZip A2File.");
                }

            }

            Ode ode = OdesUtil.publishODEZip(zipFileA2, catalog.getAuthor().get(0), catalog.getTitle(), catalog.getAuthor().get(0),
                    isNewVersion == null ? "true" : isNewVersion.toString(), ODE_MIN_CATALOG);

            if (!Utils.isEmpty(ode.getMecIdentifier())) {
                // Setting fields that not exists in LOMES catalog

                // Setting ODE Node and ODE preview
                final ValoresBusquedaVO valorBusqueda = AgregaUtil.getResultadoBusquedaODE(ode.getMecIdentifier(), ode.getGeneralLanguage().get(0));
                if (valorBusqueda != null) {
                    String previewAgrega = valorBusqueda.getUrlImagen();
                    String nodo = valorBusqueda.getNodo();
                    if (Utils.isEmpty(nodo)) {
                        nodo = Utils.getMessage(AGREGA_URL).replace("http://", "");
                    }
                    if (!Utils.isEmpty(previewAgrega)) {
                        previewAgrega = nodo + valorBusqueda.getUrlImagen();
                    } else {
                        previewAgrega = catalog.getPreview();
                    }
                    // Setting custom fields to index performance
                    ode.setOdeNode(nodo);
                    ode.setPreview(previewAgrega);

                    final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(ode.getMecIdentifier());
                    final String publicatorStr = AgregaUtil.getPublicator(agregaUser, nodo);
                    final String publicatorNameStr = AgregaUtil.getPublicatorName(agregaUser);
                    final String publicatorEmailStr = agregaUser != null ? agregaUser.getEmail() : "";

                    ode.setPublicator(publicatorStr);
                    ode.setPublicatorName(publicatorNameStr);
                    ode.setPublicatorEmail(publicatorEmailStr);
                }
                ode.setLabels(catalog.getLabels());
                ode.setKnowledgeArea(catalog.getKnowledgeArea());
                ode.setLearningContext(catalog.getLearningContext());
                ode.setResourceType(catalog.getResourceType());
                ode.setCertified(catalog.getCertified());
                Utils.copyProperties(ode, catalog);
                if (SolrSupport.injectDocument(ode)) {
                    result = new ServiceResponse(ResponseCode.OK, 200, "Ode published", ode.getId());
                } else {
                    result = new ServiceResponse(ResponseCode.NOK, 500, "Ode CANNOT be published");
                }

            } else {
                result = new ServiceResponse(ResponseCode.NOK, 509, ode.getDescription());
            }

            if (zipFile != null) {
                zipFile.delete();
            }
            if (filefromA2File != null) {
                filefromA2File.delete();
            }

        } else {
            validationResult.setHttpResponseCode(500);
            return validationResult;
        }

        return result;
    }

    @WebMethod
    public String getOdeWithFormat(String format, String mecIdentifier, String language) {
        // if (validateRequest()) {
        return AgregaUtil.getOdeWithFormat(format, mecIdentifier, language);
        // } else {
        // return null;
        // }
    }

    @WebMethod
    public String getOdeImageFormat(String mecIdentifier, String language) {
        return AgregaUtil.getOdeWithImageFormat(mecIdentifier, language);
    }

    private boolean validateRequest() {
        MessageContext mctx = wsctx.getMessageContext();

        HeaderList hl = (HeaderList) mctx.get(JAXWSProperties.INBOUND_HEADER_LIST_PROPERTY);

        final Header header = hl.get("http://ws.odes.agrega2.emergya.com/", "Authentication", true);

        // get detail from request headers
        Map<?, ?> http_headers = (Map<?, ?>) mctx.get(MessageContext.HTTP_REQUEST_HEADERS);
        List<?> userList = (List<?>) http_headers.get("Username");
        List<?> passList = (List<?>) http_headers.get("Password");

        String username = "";
        String password = "";

        if (userList != null) {
            username = userList.get(0).toString();
        }

        if (passList != null) {
            password = passList.get(0).toString();
        }

        if (!Utils.isEmpty(username) && !Utils.isEmpty(password) && Utils.getToken(Long.parseLong(username)).equals(password)) {
            return true;
        } else {
            return false;
        }
    }
}
