package com.emergya.agrega2.oaiextractor;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.net.MalformedURLException;
import java.net.URL;
import java.rmi.RemoteException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Collection;
import java.util.Date;
import java.util.Iterator;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.solr.client.solrj.SolrQuery;
import org.apache.solr.client.solrj.SolrQuery.ORDER;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.apache.solr.client.solrj.response.QueryResponse;
import org.apache.solr.client.solrj.util.ClientUtils;
import org.apache.solr.common.SolrDocument;
import org.apache.solr.common.SolrDocumentList;
import org.apache.solr.common.util.NamedList;
import org.springframework.util.CollectionUtils;
import org.springframework.util.StringUtils;

import com.emergya.agrega2.arranger.util.Utils;

import es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO;
import es.pode.publicacion.negocio.servicios.SrvPublicacionService;
import es.pode.publicacion.negocio.servicios.SrvPublicacionServiceProxy;

public class OAIExtractor {

    private static final Log LOG = LogFactory.getLog(OAIExtractor.class);

    private static final SimpleDateFormat SDF = new SimpleDateFormat("yyyy-MM-dd");
    private static final String ENCODING = "UTF-8";

    private static final String RESUMPTION_TOKEN = "resumptionToken expirationDate";
    private static final String RESUMPTION_TOKEN2 = "resumptionToken completeListSize";

    private static final String UNIQUE = "Catálogo unificado mec-red.es-ccaa de identificación de ODE";
    private static final String UNIQUE2 = "Cat&amp;aacute;logo unificado mec-red.es-ccaa de identificaci&amp;oacute;n de ODE";

    private static String verb = "ListRecords";
    private static String metadataPrefix = "MetadataPrefix";
    private static String set = "MetadatosFederados";

    private static String xmlFolder = "*";
    private static String tmpFromFile = Utils.getMessage("agrega2.files.fromdate");

    private static String lomesHeader = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<lomes:lom xmlns:lomes=\"http://ltsc.ieee.org/xsd/LOM\">";

    private static String resumptionTokenStr = "";

    private static int count = 0;

    public static final String AGREGA_URL = "agrega.url";
    public static final String AGREGA_PUBLICATION_SERVICE = "agrega.publication_service";

    private static final int MAX_RESULTS = 90000;
    private static final int NUM_ROWS = 100000;
    private static final int THREADS_NUM = 50;

    static {
        verb = Utils.getMessage("agrega2.repository.params.verb") != null ? Utils
                .getMessage("agrega2.repository.params.verb") : verb;
        metadataPrefix = Utils.getMessage("agrega2.repository.params.metadataprefix") != null ? Utils
                .getMessage("agrega2.repository.params.metadataprefix") : metadataPrefix;
        set = Utils.getMessage("agrega2.repository.params.set") != null ? Utils
                .getMessage("agrega2.repository.params.set") : set;
        xmlFolder = Utils.getMessage("agrega2.oaiextractor.outputfolder") != null ? Utils
                .getMessage("agrega2.oaiextractor.outputfolder") : xmlFolder;
        tmpFromFile = Utils.getMessage("agrega2.files.fromdate") != null ? Utils.getMessage("agrega2.files.fromdate")
                : tmpFromFile;
    }

    public static void main(String[] args) {

        final String fromDate = getFromDate();
        final String untilDate = SDF.format(new Date());
        boolean result = false;

        Utils.logInfo(LOG, "Getted fromDate -> {0}", fromDate);

        /**
        * Before start load process, lunch des-publication ODEs WS
        * */
        unpublishODEs(fromDate);

        String repoResponse;
        if (!Utils.isEmpty(fromDate)) {
            repoResponse = getMetadata(verb, metadataPrefix, fromDate, untilDate, set, resumptionTokenStr);
            Utils.logInfo(LOG, "repoRepsonse is: " + repoResponse);
            if (!Utils.isEmpty(repoResponse)) {
                getResumptionToken(repoResponse);
                result = generateXMls(repoResponse);

                while (!Utils.isEmpty(resumptionTokenStr)) {
                    repoResponse = getMetadata(verb, metadataPrefix, fromDate, untilDate, set, resumptionTokenStr);
                    getResumptionToken(repoResponse);
                    result = generateXMls(repoResponse);
                }

                if (result) {
                    setFromDate(new Date());
                }
            }
        }
        // generateDrupalNodes("http://agrega2-front-pre.emergya.es/es/ode/view/");

    }

    private static void generateDrupalNodes(final String endpoint) {
        // Obetener servidor SOLR
        final String solrServerUrl = getServerURL(true);
        Utils.logInfo(LOG, "Getting ODEs from SOLR server {0}", solrServerUrl);
        final HttpSolrServer server = new HttpSolrServer(solrServerUrl);
        // Extraer los identificadores de los ODEs
        // for (int i = 0; i < MAX_RESULTS; i = i + NUM_ROWS) {
        int i = 0;
        int end = i + NUM_ROWS;
        Utils.logInfo(LOG, "Getting from {0} to {1}", i, end);
        try {
            SolrDocumentList docsList = getOdesIds(i, NUM_ROWS, server);
            Utils.logInfo(LOG, "Obtained {0} ODEs", docsList.getNumFound());
            final int size = docsList.size();
            if (size > 0) {
                final CountDownLatch latch = new CountDownLatch(size);
                final BlockingQueue<String> solrIds = new ArrayBlockingQueue<String>(size);
                final Iterator<SolrDocument> iterator = docsList.iterator();
                while (iterator.hasNext()) {
                    final SolrDocument next = iterator.next();
                    final String id = (String) next.getFieldValue("id");
                    solrIds.add(id);
                }

                // Configure executor.
                final ExecutorService executor = Executors.newFixedThreadPool(THREADS_NUM);

                Runnable injector = new Runnable() {
                    @Override
                    public void run() {
                        try {
                            final String id = solrIds.take();
                            Utils.logInfo(LOG, "Getting Drupal ODE: {0}", id);
                            final URL url = new URL(endpoint + id);
                            final String urlContent = Utils.getURLContent(url, null);
                            if (!Utils.isEmpty(urlContent)) {
                                Utils.logInfo(LOG, "Request OK to {0}", url);
                            } else {
                                Utils.logError(LOG, "Request NOK to {0}", url.toString());
                            }
                            latch.countDown();
                        } catch (InterruptedException e) {
                            Utils.logError(LOG, e.getMessage());
                        } catch (MalformedURLException e) {
                            Utils.logError(LOG, e.getMessage());
                        } catch (IOException e) {
                            Utils.logError(LOG, e.getMessage());
                        }
                    }
                };

                // Lunch threads
                for (int j = 0; j < size; j++) {
                    executor.execute(injector);
                }
                executor.shutdown();

            }
        } catch (SolrServerException e) {
            Utils.logError(LOG, e);
        }

        // Por cada identificador realizar una petición GET

    }

    private static boolean generateXMls(final String content) {
    	    	
        final String[] recordsArray = content.split("<record>");
        for (int i = 1; i < recordsArray.length; i++) {
            try {
                String record = recordsArray[i];
                String identifier = "";
                if (record.contains(UNIQUE)) {
                    identifier = record.split(UNIQUE)[1].split("</identifier>")[0];
                    identifier = StringUtils.trimAllWhitespace(identifier).split("</lomes:entry>")[0].replace(
                            "</lomes:catalog><lomes:entryuniqueElementName=\"entry\">", "");
                } else if (record.contains(UNIQUE2)) {
                    identifier = record.split(UNIQUE2)[1].split("</identifier>")[0];
                    identifier = StringUtils.trimAllWhitespace(identifier).split("</lomes:entry>")[0].replace(
                            "</lomes:catalog><lomes:entryuniqueElementName=\"entry\">", "");
                }
                if (Utils.isEmpty(identifier)) {
                    throw new Exception("CANNOT OBTAIN MECD IDENTIFIER");
                }

                final String[] lomesArray = record.split("<lomes:lom>");

                // Delete metadata and record tokens
                String lomesContentTmpStr = lomesArray[1].replace("</metadata>\n", "");
                lomesContentTmpStr = lomesContentTmpStr.replace("</record>\n", "");

                // Delete resumptionToken if exists
                if (lomesContentTmpStr.contains(RESUMPTION_TOKEN)) {
                    final String stringTmp = lomesContentTmpStr.split(RESUMPTION_TOKEN)[0];
                    lomesContentTmpStr = stringTmp.substring(0, stringTmp.length() - 2);
                } else if (lomesContentTmpStr.contains(RESUMPTION_TOKEN2)) {
                    final String stringTmp = lomesContentTmpStr.split(RESUMPTION_TOKEN2)[0];
                    lomesContentTmpStr = stringTmp.substring(0, stringTmp.length() - 2);
                }

                if (lomesArray.length > 1 && !Utils.isEmpty(identifier)) {
                    final StringBuffer lomesSb = new StringBuffer(lomesHeader);
                    String lomesEntry = lomesSb.append(lomesContentTmpStr).toString();                    
                    if (!Utils.isEmpty(lomesEntry)) {
                        final String fileLomes = xmlFolder + identifier + ".xml";
                        Utils.logInfo(LOG, "Generating XML LOMES file: {0}, NUM: {1}", fileLomes, ++count);
                        File file = new File(fileLomes);
                        //Because when a resource if modify two o more on same day, only prevails the change more old and not the most recent. It is a error, the change that shoud be prevails is the most recent. Agrega return the recovery order desc by date
                        if (file.exists()) {                            
                            //Utils.logInfo(LOG, "Deleting XML LOMES file: {0}, NUM: {1}", fileLomes, count--);
                            //file.delete();
                        }else{
                            Writer out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(file), ENCODING));
                            out.append(lomesEntry);
                            out.flush();
                            out.close();
                        }                        
                    }
                }
            } catch (ArrayIndexOutOfBoundsException e) {
                Utils.logError(LOG, e, "Error getting MECD ID. {0}", recordsArray[i]);
            } catch (Exception e) {
                Utils.logError(LOG, e, "Error generating XML files.");
                return false;
            }
        }

        return true;
    }

    private static String getMetadata(final String verb, final String metadataPrefix, final String from,
            final String until, final String set, final String resumptionToken) {

        final StringBuffer urlBf = new StringBuffer();
        String content = "";

        final String repoEndpoint = Utils.getMessage("agrega2.respository.endpoint");
        if (Utils.isEmpty(repoEndpoint)) {
            Utils.logError(LOG, "Error getting REPO ENDPOINT");
            return null;
        }

        urlBf.append(repoEndpoint).append("verb=").append(verb).append("&").append("metadataPrefix=")
                .append(metadataPrefix).append("&").append("from=").append(from).append("&").append("until=")
                .append(until).append("&").append("set=").append(set);
        if (!Utils.isEmpty(resumptionToken)) {
            urlBf.append("&").append("resumptionToken=").append(resumptionToken);
        }

        try {
            content = Utils.getURLContent(new URL(urlBf.toString()), "ISO-8859-1");
        } catch (Exception e) {
            return null;
        }

        return content;

    }

    private static String getFromDate() {
        Utils.logInfo(LOG, "Getting From Date from {0} file", tmpFromFile);
        String dateFrom = "";
        BufferedReader br = null;
        boolean newFromDateFile = false;
        try {
            br = new BufferedReader(new FileReader(tmpFromFile));
            dateFrom = br.readLine();
        } catch (Exception e) {
            Utils.logError(LOG, "Error getting From Date from {0} file", tmpFromFile);
            newFromDateFile = true;
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }

        if (newFromDateFile) {
            BufferedWriter bw = null;
            String fromDateStr = "";

            Calendar cal = Calendar.getInstance();
            cal.setTime(new Date());
            cal.add(Calendar.DAY_OF_YEAR, -1);

            Date fromDate = cal.getTime();
            fromDateStr = SDF.format(fromDate);

            Utils.logWarn(LOG, "Generating From Date File from {0}", fromDateStr);
            try {
                bw = new BufferedWriter(new FileWriter(tmpFromFile));
                bw.append(fromDateStr);
                dateFrom = fromDateStr;
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (bw != null) {
                    try {
                        bw.close();
                    } catch (IOException e) {
                        Utils.logError(LOG, e.getMessage());
                    }
                }
            }

        }
        return dateFrom;

    }

    private static void setFromDate(final Date fromDate) {
        Utils.logInfo(LOG, "Setting From Date to {0} file", tmpFromFile);
        final String fromDateStr = SDF.format(fromDate).toString();
        BufferedWriter bw = null;
        try {
            bw = new BufferedWriter(new FileWriter(tmpFromFile));
            bw.write(fromDateStr);
        } catch (Exception e) {
            Utils.logError(LOG, "Error setting From Date to {0} file", tmpFromFile);
        } finally {
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e.getMessage());
                }
            }
        }
    }

    private static void getResumptionToken(final String metadata) {
        try {
            if (metadata.contains(RESUMPTION_TOKEN)) {
                String rt = metadata.split(RESUMPTION_TOKEN)[1].split(">")[1];
                final String resumptionTokenTmpStr = rt.substring(0, 13);
                resumptionTokenStr = resumptionTokenStr.equals(resumptionTokenTmpStr) ? null : resumptionTokenTmpStr;
            } else {
                resumptionTokenStr = null;
            }
        } catch (Exception e) {
            Utils.logWarn(LOG, "Cannot obtain resumptionToken");
        }
    }

    public static void unpublishODEs(final String fromDate) {
        String solrServerUrl = null;
        String mecdIdentifier = null;

        Utils.logInfo(LOG, "Entering despublicationOde method");

        try {
            SrvPublicacionService publicationService = new SrvPublicacionServiceProxy(Utils.getMessage(AGREGA_URL)
                    + Utils.getMessage(AGREGA_PUBLICATION_SERVICE));
            final OdesFederadosDespublicadosVO[] odesDespublicados = publicationService
                    .obtenODEsDespublicadosFederadosPorFecha(fromDate, SDF.format(new Date()));
            final int length = odesDespublicados.length;
            Utils.logInfo(LOG, "Found {0} ODEs to unpublish", length);
            if (length > 0) {
                solrServerUrl = getServerURL(true);
                Utils.logInfo(LOG, "Setting Solr server to -> {0}", solrServerUrl);
                final HttpSolrServer server = new HttpSolrServer(solrServerUrl);
                for (int i = 0; i < length; i++) {
                    mecdIdentifier = odesDespublicados[i].getIdOde();
                    Utils.logInfo(LOG, "Searching {0} ODE. MECD id: {1}", i, mecdIdentifier);
                    SolrDocument solrDoc = existsDocument(mecdIdentifier, server);
                    if (solrDoc != null) {
                        Utils.logInfo(LOG, "Setting publish to ZERO. Number {0}. ODE MECD id: {1}", i, mecdIdentifier);
                        solrDoc.setField("published", "0");
                        solrDoc.setField("lastIndexDate", null);
                        
                        if(!Utils.isEmpty(solrDoc.get("odeNodeStr"))){
                        	solrDoc.setField("odeNodeStr", swapMultiValue(solrDoc.get("odeNodeStr")));
                        }
                        
                        server.add(ClientUtils.toSolrInputDocument(solrDoc));
                    }
                }
            }

        } catch (RemoteException e) {
            Utils.logError(LOG, e,
                    "Cannot connect to 'SrvPublicacionService'  to 'obtenODEsDespublicadosFederadosPorFecha'.");
        } catch (SolrServerException e) {
            Utils.logError(LOG, e, "Cannot connect to SOLR host {0}", solrServerUrl);
        } catch (IOException e) {
            Utils.logError(LOG, e, "Cannot UPDATE document {0} on SOLR host {1}", mecdIdentifier, solrServerUrl);
        } catch (Exception e) {
            Utils.logError(LOG, e, "Generic ERROR");
        }

        Utils.logInfo(LOG, "Exiting despublicationOde method");

    }
    
    @SuppressWarnings({ "rawtypes" })
    private static Object swapMultiValue(Object value) {
    
    	Object newNotMultiValue = null;    	
    	if( value instanceof Object[] ) {
    		newNotMultiValue =  ((Object[])value)[0];
    	}    	
    	else if( value instanceof Iterable ) {    		
    		Iterator itValue = ((Iterable) value).iterator();
    		newNotMultiValue = itValue.hasNext() ? itValue.next() : null;    		
    	}else{
    		newNotMultiValue = value;
    	}
    	return newNotMultiValue;
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
    private static org.apache.solr.common.SolrDocument existsDocument(final String mecdIdentifier, HttpSolrServer server)
            throws SolrServerException {

        SolrQuery query = new SolrQuery();
        query.add("q", "mecIdentifierStr:" + "\"" + mecdIdentifier + "\"");
        query.addSort("lastIndexDate", ORDER.desc);

        QueryResponse response = server.query(query);

        if (response != null && !CollectionUtils.isEmpty(response.getResults())) {
            return response.getResults().get(0);
        } else {
            return null;
        }

    }

    private static SolrDocumentList getOdesIds(final int start, final int rows, HttpSolrServer server)
            throws SolrServerException {

        SolrQuery query = new SolrQuery();
        query.add("q", "-idDrupal:[* TO *]");
        query.addField("id");
        query.addFilterQuery("type:ODE");
        query.setRows(rows);
        query.setStart(start);

        QueryResponse response = server.query(query);

        if (response != null && !CollectionUtils.isEmpty(response.getResults())) {
            return response.getResults();
        } else {
            return null;
        }

    }
}
