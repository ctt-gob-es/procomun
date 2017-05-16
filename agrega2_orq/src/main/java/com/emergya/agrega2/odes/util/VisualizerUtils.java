package com.emergya.agrega2.odes.util;

import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.http.client.utils.URIBuilder;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.OdeContentJson;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import es.pode.entregar.negocio.servicios.ItemVO;
import es.pode.entregar.negocio.servicios.ManifestVO;
import es.pode.entregar.negocio.servicios.OrganizacionVO;
import es.pode.entregar.negocio.servicios.RecursoVO;

public class VisualizerUtils {
    private static final Log LOG = LogFactory.getLog(VisualizerUtils.class);

    public static void main(String[] args) {
        List<OdeContentJson> arbol = getODETreeData("1418283540373", null);
        // 1407323746981
        ObjectMapper jsonMapper = new ObjectMapper();
        String treeData = "";
        try {
            treeData = jsonMapper.writeValueAsString(arbol);
        } catch (JsonProcessingException e) {
            Utils.logError(LOG, e.getMessage());
        }

        Utils.logInfo(LOG, treeData);
    }

    private static boolean firstHref = true;

    private static ManifestVO getManifestVO(String identifier, String solrIdentifier, String language) {
        ManifestVO manifest = null;
        if (identifier != null) {
            // Visualizador: IDIOMA Y USUARIO
            manifest = AgregaUtil.getFilesODE(identifier, language, "");
            // Si no tenemos identificador MEC, probamos con todos los ids del
            // ODE
        } else {
            Collection<Object> identifiers = SolrSupport.getOdeIdentifiers(solrIdentifier);
            if (!Utils.isEmpty(identifiers)) {
                for (Object obj : identifiers) {
                    if (obj instanceof String) {
                        // Visualizador: IDIOMA Y USUARIO
                        manifest = AgregaUtil.getFilesODE((String) obj, "es", "");
                        if (manifest != null) {
                            break;
                        }
                    }
                }
            }
        }
        return manifest;
    }

    public static List<OdeContentJson> getODETreeData(String solrIdentifier, String language) {

        Object identifierObj = SolrSupport.getSolrField(solrIdentifier, "mecIdentifierStr");
        String identifier = identifierObj != null ? (String) identifierObj : null;
        ManifestVO manifest = getManifestVO(identifier, solrIdentifier, language);

        if (manifest != null) {
            String treeData = "";
            String title = manifest.getTitulo();

            String odeURL = "";
            ServiceResponse localizacion = AgregaUtil.searchODE(identifier, language);
            if (localizacion != null && ResponseCode.OK.equals(localizacion.getResponseCode())) {
                odeURL = localizacion.getMessage();
            }
            manifest.getLocalizacionURL();
            OrganizacionVO[] organizaciones = manifest.getOrganizaciones();
            if (!Utils.isEmpty(organizaciones)) {
                OdeContentJson odeJson = new OdeContentJson();
                // TODO TEST
                List<OdeContentJson> children = new ArrayList<OdeContentJson>();
                for (OrganizacionVO organizacion : organizaciones) {
                    // Visualizador: Habrá que controlar la secuencia, si
                    // la hay. De momento no.

                    // TODO Test to delete this line to solve #124585
                    // odeJson.setLabel(organizacion.getTituloOrg());
                    odeJson.setLabel(manifest.getTitulo());

                    // Se utiliza el getClicable??

                    ItemVO[] items = organizacion.getItems();

                    if (!Utils.isEmpty(items)) {
                        // List<OdeContentJson> children = new
                        // ArrayList<OdeContentJson>();

                        for (ItemVO item : items) {
                            children.add(processOrganizationItem(odeURL, item));

                        }
                        odeJson.setChildren(children);
                    }
                }

                List<OdeContentJson> listContent = new ArrayList<OdeContentJson>();
                // TO DELETE DUPLICATED PARENT NODES
                if (odeJson.getChildren().size() == 1) {
                    listContent.addAll(children);
                } else {
                    listContent.add(odeJson);
                }

                // Reinitialize itemNumber
                firstHref = true;
                // TODO
                return listContent;
                // return odeJson.getChildren().get(0).getChildren();
            }
        } else {
            Utils.logError(LOG, "No se han obtenido metadatos del ODE");
            return null;
        }

        return null;
    }

    /**
     * Service to provide an URL with the ODE content
     * @param catalog ODE catalog form
     * @param solrIdentifier Identifier of the ODE in Solr
     * @return URL of the ODE visualizer, or an error message if not found or a problem encountered
     */
    // FIXME: @param userName UserName of the user requesting the content
    public static String getODEVisualizer(String solrIdentifier, String language) {
        String result = "";
        List<OdeContentJson> listContent = getODETreeData(solrIdentifier, language);
        String treeData = "";
        if (listContent != null) {
            String title = (String) SolrSupport.getSolrField(solrIdentifier, "titleStr");
            try {
                ObjectMapper jsonMapper = new ObjectMapper();
                treeData = jsonMapper.writeValueAsString(listContent);

                String urlString = "http://localhost:8080/Orquestador/visualizer/html/visualizer.html?";
                if (!Utils.isEmpty(title)) {
                    urlString += "odeTitle=" + URLEncoder.encode(title, "UTF-8");
                }
                if (!Utils.isEmpty(treeData)) {
                    urlString += "&treeData=" + URLEncoder.encode(treeData, "UTF-8");
                }

                System.out.println(urlString);

                URIBuilder uriB = new URIBuilder("http://localhost:8080/Orquestador/visualizer/html/visualizer.html?");

                if (!Utils.isEmpty(title)) {
                    uriB.addParameter("odeTitle", title);
                }
                if (!Utils.isEmpty(treeData)) {
                    uriB.addParameter("treeData", treeData);
                }

                URI uri = uriB.build();

                System.out.println(uri);
            } catch (JsonProcessingException e) {
                Utils.logError(LOG, "Error generando los datos del árbol de recursos");
            } catch (UnsupportedEncodingException e1) {
                Utils.logError(LOG, "No se ha podido obtener la URL del visualizador");
            } catch (URISyntaxException e) {
                Utils.logError(LOG, "No se ha podido obtener la URL del visualizador");
            }
        } else {
            Utils.logError(LOG, "No se han obtenido metadatos del ODE");
            return "No se han obtenido metadatos del ODE";
        }

        return result;
    }

    /**
     * Process ODEs items recursively
     * @param item ODE item to process
     * @return "JSON" object with ODE item data
     */
    private static OdeContentJson processOrganizationItem(String odeURL, ItemVO item) {
        OdeContentJson child = new OdeContentJson();
        if (item != null) {
            child.setLabel(item.getTitulo());
            if (!Utils.isEmpty(item.getHrefRec())) {
                if (item.getVisible() != null && item.getVisible()) {
                    if (firstHref) {
                        child.setId("1");
                        firstHref = false;
                    }
                    child.setHref(odeURL + "/" + item.getHrefRec());
                } else {
                    // FIXME: Cómo tratar los elementos ocultos??
                    child.setLabel(child.getLabel() + " - Oculto");
                }
            }
            RecursoVO recurso = item.getRecurso();
            if (recurso != null) {
                if (item.getVisible() != null && item.getVisible()) {
                    if (firstHref) {
                        child.setId("1");
                        firstHref = false;
                    }
                    final String href = odeURL + "/" + recurso.getHrefRec();
                    Utils.logInfo(LOG, href);
                    child.setHref(href);
                } else {
                    // FIXME: Cómo tratar los elementos ocultos??
                    child.setLabel(child.getLabel() + " - Oculto");
                }
            }

            if (!Utils.isEmpty(item.getItemHijos())) {
                List<OdeContentJson> children = new ArrayList<OdeContentJson>();
                for (ItemVO itemChild : item.getItemHijos()) {
                    children.add(processOrganizationItem(odeURL, itemChild));
                }
                child.setChildren(children);
            }
        }

        return child;
    }
}
