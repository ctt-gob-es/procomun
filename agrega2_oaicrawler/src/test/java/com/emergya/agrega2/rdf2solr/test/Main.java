package com.emergya.agrega2.rdf2solr.test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.rmi.RemoteException;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.solr.client.solrj.SolrQuery;
import org.apache.solr.client.solrj.SolrServerException;
import org.apache.solr.client.solrj.impl.HttpSolrServer;
import org.apache.solr.client.solrj.response.QueryResponse;
import org.apache.solr.client.solrj.util.ClientUtils;
import org.apache.solr.common.SolrDocument;
import org.springframework.util.CollectionUtils;
import org.springframework.util.StringUtils;

import com.emergya.agrega2.arranger.util.Utils;

import es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO;
import es.pode.publicacion.negocio.servicios.SrvPublicacionService;
import es.pode.publicacion.negocio.servicios.SrvPublicacionServiceProxy;

public class Main {

    public static final String AGREGA_URL = "agrega.url";
    public static final String AGREGA_PUBLICATION_SERVICE = "agrega.publication_service";

    private static final SimpleDateFormat SDF = new SimpleDateFormat("yyyy-MM-dd");

    private static final String RESUMPTION_TOKEN = "resumptionToken expirationDate";
    private static final String RESUMPTION_TOKEN2 = "resumptionToken completeListSize";

    private static final String UNIQUE = "Catálogo unificado mec-red.es-ccaa de identificación de ODE";
    private static final String UNIQUE2 = "Cat&amp;aacute;logo unificado mec-red.es-ccaa de identificaci&amp;oacute;n de ODE";

    private static String lomesHeader = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<lomes:lom xmlns:lomes=\"http://ltsc.ieee.org/xsd/LOM\">";

    private static String xmlFolder = "*";

    private static final Log LOG = LogFactory.getLog(Main.class);

    public static void main(String[] args) {

        unpublishODEs("*");

    }

    private static void unpublishODEs(final String fromDate) {
        String solrServerUrl = null;
        String mecdIdentifier = null;

        Utils.logInfo(LOG, "Entering despublicationOde method");

        SrvPublicacionService publicationService = new SrvPublicacionServiceProxy(Utils.getMessage(AGREGA_URL)
                + Utils.getMessage(AGREGA_PUBLICATION_SERVICE));
        try {
            final OdesFederadosDespublicadosVO[] odesDespublicados = publicationService
                    .obtenODEsDespublicadosFederadosPorFecha(fromDate, SDF.format(new Date()));
            final int length = odesDespublicados.length;
            Utils.logInfo(LOG, "Found {0} ODEs to unpublish", length);
            if (length > 0) {
                solrServerUrl = getServerURL(true);
                final HttpSolrServer server = new HttpSolrServer(solrServerUrl);
                for (int i = 0; i < length; i++) {
                    mecdIdentifier = odesDespublicados[i].getIdOde();
                    SolrDocument solrDoc = existsDocument(mecdIdentifier, server);
                    if (solrDoc != null) {
                        Utils.logInfo(LOG, "Setting publish to ZERO. Number {0}. ODE MECD id: {1}", i, mecdIdentifier);
                        solrDoc.setField("published", "0");
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
        }

        Utils.logInfo(LOG, "Exiting despublicationOde method");

    }

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
        query.add("q", "mecIdentifier:" + "\"" + mecdIdentifier + "\"");

        QueryResponse response = server.query(query);

        if (response != null && !CollectionUtils.isEmpty(response.getResults())) {
            return response.getResults().get(0);
        } else {
            return null;
        }

    }

    public static void testXML() {
        StringBuffer sb = new StringBuffer();
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("*"));
            String content;
            while ((content = br.readLine()) != null) {
                sb.append(content);
            }

            content = sb.toString();
            content = content.replaceAll("\\t", "");
            content = content.replaceAll("\\n", "");

            final String[] recordsArray = content.split("<record>");
            for (int i = 1; i < recordsArray.length; i++) {
                String record = recordsArray[i];
                try {
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
                    String lomesContentTmpStr = lomesArray[1].replace("</metadata>\n", "").replace("</metadata>", "");
                    lomesContentTmpStr = lomesContentTmpStr.replace("</record>\n", "").replace("</record>", "");

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
                            File file = new File(fileLomes);
                            if (file.exists()) {
                                file.delete();
                            }
                            Writer out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(file), "UTF-8"));
                            out.append(lomesEntry);
                            out.flush();
                            out.close();
                        }
                    }
                } catch (ArrayIndexOutOfBoundsException e) {
                    e.printStackTrace();
                } catch (Exception e) {
                    e.printStackTrace();
                }

            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
