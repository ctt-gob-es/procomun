package com.emergya.agrega2.rdf2solr;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.apache.commons.io.IOUtils;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.solr.client.solrj.SolrQuery;
import org.apache.solr.client.solrj.SolrQuery.ORDER;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.apache.solr.client.solrj.impl.HttpSolrServer.RemoteSolrException;
import org.apache.solr.client.solrj.response.QueryResponse;
import org.apache.solr.client.solrj.response.UpdateResponse;
import org.springframework.util.CollectionUtils;

import com.emergya.agrega2.arranger.exceptions.HTTPNotFoundException;
import com.emergya.agrega2.arranger.html.BNEParser;
import com.emergya.agrega2.arranger.html.CulturaParser;
import com.emergya.agrega2.arranger.html.DBPediaParser;
import com.emergya.agrega2.arranger.html.OriginParser;
import com.emergya.agrega2.arranger.html.TitleLinkContent;
import com.emergya.agrega2.arranger.model.entity.enums.InterlinkingOrigins;
import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.util.Utils;
import com.emergya.agrega2.odes.util.AgregaUtil;
import com.emergya.agrega2.odes.util.OdesMapping;

import es.pode.adminusuarios.negocio.servicios.UsuarioVO;
import es.pode.parseadorXML.ParseadorException;

public class RDF2Solr {

    private static final int DEFAULT_THREADS_NUM = 20;

    private static final Log LOG = LogFactory.getLog(RDF2Solr.class);

    /**
     * Counts the number of files that are processed
     */
    private static int fileIndex;
    private static ArrayList<String> filesList = new ArrayList<String>();

    public static void main(String[] args) {
        try {

            final String manifestsPath = Utils.getMessage("LOMES_PATH");
            final String serverUrl = getServerURL(true);
            final HttpSolrServer server = new HttpSolrServer(serverUrl);
            List<String> filesList = null;

            File dir = new File(manifestsPath);

            Utils.logInfo(LOG, "==============================================");
            Utils.logInfo(LOG, "Starting RDF 2 Solr process......");
            Utils.logInfo(LOG, "==============================================");

            if (dir != null && dir.isDirectory()) {
                fileIndex = 0;
                filesList = processDirectory(dir);
            } else {
                Utils.logInfo(LOG, "The manifests path (" + manifestsPath + ") doesn't exist or it can't be accessed.");
            }

            Utils.logInfo(LOG, "==============================================");
            Utils.logInfo(LOG, "Launching threads......");
            Utils.logInfo(LOG, "==============================================");
            int filesNum = filesList.size();

            Utils.logInfo(LOG, "Proccessing {0} files.", filesNum);
            if (filesNum > 0) {
                final CountDownLatch latch = new CountDownLatch(filesNum);
                final BlockingQueue<String> xmlsToSolr = new ArrayBlockingQueue<String>(filesNum);
                for (String file : filesList) {
                    xmlsToSolr.add(file);
                }
                // Check if THREADS_NUM if configured on properties file. If
                // does not, get default threads number.
                String threadsNumStr = "";
                try {
                    threadsNumStr = Utils.getMessage("THREADS_NUM");
                } catch (Exception e) {
                }
                final int threadsNum = !Utils.isEmpty(threadsNumStr) ? Integer.parseInt(threadsNumStr) : DEFAULT_THREADS_NUM;

                // Configure executor.
                final ExecutorService executor = Executors.newFixedThreadPool(threadsNum);

                Runnable injector = new Runnable() {
                    @Override
                    public void run() {
                        try {
                            final String fileStr = xmlsToSolr.take();
                            processFile(fileStr, server);
                            latch.countDown();
                        } catch (IOException | SolrServerException e) {
                            Utils.logError(LOG, e.getMessage());
                        } catch (InterruptedException e1) {
                            Utils.logError(LOG, e1.getMessage());
                        } catch (ParseadorException e) {
                            Utils.logError(LOG, "Error parsing XML: " + e.getMessage());
                        }
                    }
                };

                // Lunch threads
                for (int i = 0; i < filesNum; i++) {
                    executor.execute(injector);
                }
                // try {
                // latch.await();
                executor.shutdown();
                // Utils.logInfo(LOG,
                // "==============================================");
                // Utils.logInfo(LOG, "Finishing RDF 2 Solr process......");
                // Utils.logInfo(LOG,
                // "==============================================");
                // } catch (InterruptedException e) {
                // Utils.logError(LOG, e.getMessage());
                // }
            }

        } catch (Exception e) {
            Utils.logError(LOG, e.getMessage());
        }

        Utils.logInfo(LOG, "Calling Drupal service to update ODEs");
        if (updateDrupalOdes()) {
            Utils.logInfo(LOG, "OK! - ODEs updated in Drupal");
        } else {
            Utils.logWarn(LOG, "NOK! - Cannot update ODEs in Drupal. URL -> {0}", Utils.getMessage("drupal.services.odes.update"));
        }

        Utils.logInfo(LOG, "Ending RDF 2 Solr process.");

    }

    /**
     * Processes the content of a directory
     * @param dir Directory to process
     * @return List with paths of files content on directory
     */
    private static ArrayList<String> processDirectory(File dir) {
        if (dir != null) {
            Utils.logInfo(LOG, "***********************************************");
            Utils.logInfo(LOG, "Processing " + dir.getName() + " directory");
            Utils.logInfo(LOG, "***********************************************");
            File[] dirFiles = dir.listFiles();

            if (dirFiles != null && dirFiles.length > 0) {
                for (File file : dirFiles) {
                    if (file.isDirectory()) {
                        processDirectory(file);
                    } else {
                        // processFile(file, server);
                        filesList.add(file.getAbsolutePath());
                    }
                }

            }
        } else {
            Utils.logInfo(LOG, "No files in the directory.");
        }
        return filesList;
    }

    /**
     * Processes a file to get the resource information (LOM-ES) and injects it into Solr
     * @param file File to process
     * @param server {@link HttpSolrServer} where to inject the information
     */
    private static void processFile(String file, HttpSolrServer server) throws IOException, SolrServerException, ParseadorException {
        fileIndex++;
        Utils.logInfo(LOG, fileIndex + " th File Name:" + file);

        final FileInputStream fileInputStream = new FileInputStream(file);
        fileInputStream.close();

        // Ode ode = OdesUtil.getOdeFromManifest(byteArray);

        Ode ode = OdesMapping.getOdeFromManifest(file);

        ode.setId(ode.generateId());
        ode.setGeneratedId(ode.generateIdentifiersId());

        Utils.logInfo(LOG, "--ODE mecIdentifier:" + ode.getMecIdentifier());

        ode.setTitleLinks(searchLinks(file));

        ode.setTitleLinks(getTitleLinksContent(ode));

        org.apache.solr.common.SolrDocument solrDoc = existsDocument(ode.getMecIdentifier(), server);

        // FIXME: If document exists in Solr, we only update its titleLinks
        // (interlinking)
        if (solrDoc == null) {
            Utils.logInfo(LOG, "Document NOT found in Solr, creating: {0}", ode.getMecIdentifier());

            String odeLanguage = "es";

            if (ode.getGeneralLanguage() != null) {
                odeLanguage = ode.getGeneralLanguage().get(0);
                if (Utils.equals(odeLanguage, "x-none")) {
                    odeLanguage = "es";
                }
            }
            ode.setPreview(AgregaUtil.getPreviewOde(ode.getMecIdentifier(), odeLanguage));

        } else {
            Utils.logInfo(LOG, "Document found in Solr, updating: " + ode.getMecIdentifier());

            ode.setPublished("1");

            ode.setId((String) solrDoc.getFieldValue("id"));
            ode.setIdDrupal((String) solrDoc.getFieldValue("idDrupal"));
            // Set lastIndexDate to null to update automatically the
            // date
            solrDoc.setField("lastIndexDate", null);

            ode.setPreview(AgregaUtil.getPreviewOde(ode.getMecIdentifier(), ode.getGeneralLanguage().get(0)));

        }

        final String odeNode = AgregaUtil.getNodoOde(ode.getMecIdentifier(), ode.getGeneralLanguage().get(0));

        ode.setOdeNode(odeNode);

        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(ode.getMecIdentifier());
        final String publicatorStr = AgregaUtil.getPublicator(agregaUser, odeNode);
        final String publicatorNameStr = AgregaUtil.getPublicatorName(agregaUser);
        final String publicatorEmailStr = agregaUser != null ? agregaUser.getEmail() : "";

        ode.setPublicator(publicatorStr);
        ode.setPublicatorName(publicatorNameStr);
        ode.setPublicatorEmail(publicatorEmailStr);

        boolean result = injectDocument(ode, server);
        if (result) {
            Utils.logInfo(LOG, "Injected {0} OK!", ode.getId());
        } else {
            Utils.logError(LOG, "Injected {0} NOK!", ode.getId());
        }

    }

    private static List<String> getTitleLinksContent(final Ode ode) {
        final List<String> titleLinks = new ArrayList<String>(ode.getTitleLinks());
        final List<String> richTitleLinks = new ArrayList<String>();

        InterlinkingOrigins origin = null;

        for (String tl : titleLinks) {

            Utils.logInfo(LOG, "Getting information for TitleLink: {0}", tl);

            try {
                origin = getOriginFromURL(tl);
            } catch (MalformedURLException e) {
                Utils.logError(LOG, e, "MalformedURLException on {0}", tl);
            }

            OriginParser parser = null;
            TitleLinkContent content = null;

            if (InterlinkingOrigins.BNE.equals(origin)) {
                parser = new BNEParser();
            } else if (InterlinkingOrigins.CULTURA.equals(origin)) {
                parser = new CulturaParser();
            } else if (InterlinkingOrigins.DBPEDIA.equals(origin)) {
                parser = new DBPediaParser();
            }
            try {
                if (parser != null) {
                    content = parser.getContent(tl);
                }
            } catch (HTTPNotFoundException e) {
                Utils.logError(LOG, e, "HTTPNotFoundException trying to load TitleLink: {0}", tl);
            }

            if (content != null) {
                try {
                    richTitleLinks.add(getRichTitleLink(tl, content.getTitle(), origin));
                } catch (MalformedURLException e) {
                    Utils.logError(LOG, e, "MalformedURLException trying to load TitleLink: {0}", tl);
                    richTitleLinks.add(tl);
                }
            } else {
                richTitleLinks.add(tl);
            }
        }

        return richTitleLinks;
    }

    private static String getRichTitleLink(final String titleLink, final String title, final InterlinkingOrigins origin) throws MalformedURLException {
        final StringBuilder sb = new StringBuilder();
        sb.append(titleLink).append(Utils.getFormatSeparator()).append(title).append(Utils.getFormatSeparator()).append(origin);
        return sb.toString();
    }

    private static InterlinkingOrigins getOriginFromURL(final String url) throws MalformedURLException {

        final URL uri = new URL(url);
        String host;
        try {
            host = uri.getHost().toLowerCase();
        } catch (NullPointerException e) {
            Utils.logError(LOG, e, "Cannot retrieve host from: {0}", url);
            return null;
        }

        if (host.contains(InterlinkingOrigins.BNE.name().toLowerCase())) {
            return InterlinkingOrigins.BNE;
        } else if (host.contains(InterlinkingOrigins.CULTURA.name().toLowerCase())) {
            return InterlinkingOrigins.CULTURA;
        } else if (host.contains(InterlinkingOrigins.DBPEDIA.name().toLowerCase())) {
            return InterlinkingOrigins.DBPEDIA;
        }
        return null;
    }

    /** Method to inject a {@link SolrDocumentA2} into Solr server.
     * @param document Document to insert on Solr
     * @return <code>true</code> if OK, <code>false</code> if NOK
     */
    public static boolean injectDocument(SolrDocumentA2 document, HttpSolrServer server) {

        try {
            final UpdateResponse response = server.addBean(document);
            server.commit();
            return response.getStatus() == 0 ? true : false;
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot inject document on Solr [IOException]. DocID: {0}", document.getId());
        } catch (SolrServerException e) {
            Utils.logError(LOG, e, "Cannot inject document on Solr [SolrServerException]. DocID: {0}", document.getId());
        } catch (RemoteSolrException e) {
            Utils.logError(LOG, e, "Cannot inject document on Solr [RemoteSolrException]. DocID: {0}", document.getId());
        }

        return false;

    }

    /** Gets the Solr server URL associated to Arranger
     * @return Solr Server URL
     */
    public static String getServerURL(boolean auth) {
        final StringBuilder sb = new StringBuilder();
        sb.append(Utils.getMessage("SOLR_URL_PREFIX"));
        if (auth && !Utils.isEmpty(Utils.getMessage("SOLR_USER"))) {
            sb.append(Utils.getMessage("SOLR_USER"));
            sb.append(":");
            sb.append(Utils.getMessage("SOLR_PASS"));
            sb.append("@");
        }
        sb.append(Utils.getMessage("SOLR_HOST"));
        sb.append(":");
        sb.append(Utils.getMessage("SOLR_PORT"));
        sb.append("/");
        sb.append(Utils.getMessage("SOLR_CONTEXT"));
        sb.append("/");
        sb.append(Utils.getMessage("SOLR_CORE"));
        return sb.toString();
    }

    /** Method to search if a {@link SolrDocumentA2} is present in Solr server.
     * @param document Document to search in Solr by its ID field
     * @return {@link org.apache.solr.common.SolrDocument} if the ID is already present in Solr, or null otherwise. 
     * @throws SolrServerException 
     */
    private static org.apache.solr.common.SolrDocument existsDocument(String mecIdentifier, HttpSolrServer server) throws SolrServerException {

        SolrQuery query = new SolrQuery();
        query.add("q", "mecIdentifierStr:" + "\"" + mecIdentifier + "\"");
        query.addSort("lastIndexDate", ORDER.desc);

        QueryResponse response = server.query(query);

        if (response != null && !CollectionUtils.isEmpty(response.getResults())) {
            return response.getResults().get(0);
        } else {
            return null;
        }

    }

    /**
     * Searches Semantic links of an ODE in N-Triple files (DBPedia, BNE, Cultural, etc) 
     * @param fileName  Name of the file (ODE)
     * @return  List of links for the document
     */
    private static List<String> searchLinks(String fileName) {
        List<String> links = new ArrayList<String>();

        String ntriplesPath = Utils.getMessage("NTRIPLES_PATH");
        String prefix = Utils.getMessage("NTRIPLES_PREFIX");
        int lastSlashIndex = fileName.lastIndexOf(System.getProperty("file.separator"));
        String fileTerm = "<" + prefix + fileName.substring(lastSlashIndex + 1, fileName.length() - 4) + "/>";

        File dir = new File(ntriplesPath);

        if (dir != null && dir.isDirectory()) {
            File[] directoryListing = dir.listFiles();
            // N-Triples Lines Format:
            // <PREFIX#FILENAME/> <http://www.w3.org/2002/07/owl#sameAs> <LINK>
            // .
            for (File ntriple : directoryListing) {

                try {
                    List<String> fileLines = IOUtils.readLines(new FileInputStream(ntriple));

                    for (String line : fileLines) {
                        String[] lineSplit = line.split(" ");
                        if (lineSplit != null && lineSplit.length == 4) {
                            if (fileTerm.equals(lineSplit[0]) && lineSplit[2].length() > 2) {
                                links.add((lineSplit[2].substring(1, lineSplit[2].length() - 1)).trim());
                            }
                        }
                    }

                } catch (Exception e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        } else {
            Utils.logInfo(LOG, "The N-Triples path (" + ntriplesPath + ") doesn't exist or it can't be accessed.");
        }

        return links;
    }

    /** Method to call Drupal to update ODEs
     * @return
     */
    private static boolean updateDrupalOdes() {
        final String urlStr = Utils.getMessage("drupal.services.odes.update");
        boolean result = false;
        URL urlObject;
        try {
            urlObject = new URL(urlStr);
            final String urlContentStr = Utils.getURLContent(urlObject, null);
            Utils.logInfo(LOG, "Response from Drupal: \n {0}", urlContentStr);
            if (!Utils.isEmpty(urlContentStr) && urlContentStr.contains("OK") && !urlContentStr.contains("NOK")) {
                result = true;
            }
        } catch (MalformedURLException e) {
            Utils.logError(LOG, "Malformed URL {0}", urlStr);
        } catch (IOException e) {
            Utils.logError(LOG, "Cannot connect to Drupal: {0}", urlStr);
        }

        return result;
    }

}
