package com.emergya.agrega2.odes.util;

import java.rmi.RemoteException;
import java.util.Arrays;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import com.emergya.agrega2.arranger.util.Utils;

import es.pode.adminusuarios.negocio.servicios.SrvAdminUsuariosService;
import es.pode.adminusuarios.negocio.servicios.SrvAdminUsuariosServiceProxy;
import es.pode.adminusuarios.negocio.servicios.UsuarioVO;
import es.pode.buscar.negocio.buscar.servicios.ParametrosBusquedaAvanzadaVO30;
import es.pode.buscar.negocio.buscar.servicios.ResultadoBusquedaVO;
import es.pode.buscar.negocio.buscar.servicios.SrvBuscarService;
import es.pode.buscar.negocio.buscar.servicios.SrvBuscarServiceProxy;
import es.pode.buscar.negocio.buscar.servicios.ValoresBusquedaVO;
import es.pode.publicacion.negocio.servicios.SrvPublicacionService;
import es.pode.publicacion.negocio.servicios.SrvPublicacionServiceProxy;

public class AgregaUtil {
    private static final Log LOG = LogFactory.getLog(AgregaUtil.class);

    // #####################
    // # AGREGA PROPERTIES #
    // #####################
    public static final String AGREGA_URL = "agrega.url";
    public static final String AGREGA_URL_USERS = "agrega.url.users";
    public static final String AGREGA_SEARCH_SERVICE = "agrega.search_service";
    public static final String AGREGA_PUBLICATION_SERVICE = "agrega.publication_service";

    private AgregaUtil() {
    }

    private static ValoresBusquedaVO getResultadoBusquedaODE(final String identifier, final String language) {
        Utils.logInfo(LOG, "Entering getResultadoBusquedaODE Service");
        ValoresBusquedaVO valorBusquedaVO = null;
        String service = Utils.getMessage(AGREGA_SEARCH_SERVICE);
        String urlString = Utils.getMessage(AGREGA_URL) + (service != null ? service : "");

        SrvBuscarService buscadorService = new SrvBuscarServiceProxy(urlString);

        try {
            ParametrosBusquedaAvanzadaVO30 parametros = new ParametrosBusquedaAvanzadaVO30();
            parametros.setIdentificador(identifier);
            parametros.setComunidadesSeleccionadas(new String[] { "TODAS" });

            if (!Utils.isEmpty(language)) {
                parametros.setIdiomaBusqueda(language);
            }

            ResultadoBusquedaVO result = buscadorService.buscarAvanzado(parametros);

            Utils.logDebug(LOG, "******************RESULTADO********************");
            Utils.logDebug(LOG, "Resultados búsqueda:" + result.getNumeroResultados());

            ValoresBusquedaVO[] results = result.getResultadoBusqueda();
            if (result.getNumeroResultados() > 0) {
                valorBusquedaVO = results[0];
            }
        } catch (RemoteException e) {
            Utils.logError(LOG, "Exception trying to get the NODE of an ODE: " + e.getMessage());
        }

        Utils.logInfo(LOG, "Exiting getResultadoBusquedaODE Service");
        return valorBusquedaVO;
    }

    // public static String getNodoOde(String identifier) {
    // String nodo = "";
    // ValoresBusquedaVO valorBusqueda = getResultadoBusquedaODE(identifier,
    // null);
    // if (valorBusqueda != null && !Utils.isEmpty(valorBusqueda.getNodo())) {
    // nodo = valorBusqueda.getNodo();
    // } else {
    // nodo = Utils.getMessage(AGREGA_URL).replace("http://", "");
    // }
    // return nodo;
    // }

    public static String getPreviewOde(final String identifier, final String language) {
        String preview = null;
        ValoresBusquedaVO valorBusqueda = getResultadoBusquedaODE(identifier, language);
        if (valorBusqueda != null) {
            String nodo = "";
            if (!Utils.isEmpty(valorBusqueda.getNodo())) {
                nodo = valorBusqueda.getNodo();
            } else {
                nodo = Utils.getMessage(AGREGA_URL).replace("http://", "");
            }
            preview = nodo + valorBusqueda.getUrlImagen();
        }
        return preview;
    }

    public static String getNodoOde(final String identifier, final String language) {
        String nodo = "";
        ValoresBusquedaVO valorBusqueda = getResultadoBusquedaODE(identifier, language);
        if (valorBusqueda != null && !Utils.isEmpty(valorBusqueda.getNodo())) {
            nodo = valorBusqueda.getNodo();
        } else {
            nodo = Utils.getMessage(AGREGA_URL).replace("http://", "");
        }
        return nodo;
    }

    public static UsuarioVO getAgregaUserByMecId(final String mecIdentifier) {
        UsuarioVO agregaUser = null;
        final List<String> odeEditors = getOdeEditors(mecIdentifier);
        if (!Utils.isEmpty(odeEditors)) {
            agregaUser = getAgregaUserByUser(odeEditors.get(0));
        }
        return agregaUser;
    }

    public static UsuarioVO getAgregaUserByUser(final String agregaUser) {
        UsuarioVO usuario = null;
        final SrvAdminUsuariosService usersService = new SrvAdminUsuariosServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_URL_USERS));
        try {
            usuario = usersService.obtenerDatosUsuario(agregaUser);
        } catch (RemoteException e) {
            Utils.logError(LOG, "Cannot obtain user data {0}", agregaUser);
        }

        return usuario;
    }

    /** Method to obtain ODEs publicator by its mecIdentifier
     * @param mecIdentifier
     * @return String with Odes author email
     */
    public static String getPublicator(final UsuarioVO agregaUser, final String odeNode) {
        if (agregaUser != null) {
            return getPublicatorName(agregaUser);
        } else {
            return getPublicatorNodeAuton(odeNode);
        }
    }

    private static String getPublicatorNodeAuton(final String odeNode) {

        if (odeNode.contains("juntadeandalucia")) {
            return "Junta de Andalucía";
        } else if (odeNode.contains("hezkuntza")) {
            return "País Vasco";
        } else if (odeNode.contains("madrid")) {
            return "Madrid";
        } else if (odeNode.contains("gobiernodecanarias")) {
            return "Canarias";
        } else {
            return "";
        }
    }

    /** Method to obtain ODEs publicator by its mecIdentifier
     * @param mecIdentifier
     * @return String with Odes author email
     */
    public static String getPublicatorName(final UsuarioVO agregaUser) {

        String fullname = null;

        if (!Utils.isEmpty(agregaUser)) {
            StringBuilder strBuilder = new StringBuilder();
            final String nombre = agregaUser.getNombre();
            if (!Utils.isEmpty(nombre)) {
                strBuilder = nombre.contains("INTEF") ? strBuilder.append("INTEF") : strBuilder.append(nombre);
            }
            final String apellido1 = agregaUser.getApellido1();
            if (!Utils.isEmpty(apellido1)) {
                strBuilder = apellido1.contains("PrimerApellido") || apellido1.trim().contains(".") ? strBuilder : strBuilder.append(" ").append(apellido1);
            }
            strBuilder = (!Utils.isEmpty(agregaUser.getApellido2())) ? strBuilder.append(" ").append(agregaUser.getApellido2()) : strBuilder;
            fullname = strBuilder.toString();
        }
        return fullname;
    }

    public static String getPublicatorEmail(final String mecId, final String node) {
        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(mecId);
        return AgregaUtil.getPublicator(agregaUser, node);
    }

    public static String getPublicatorName(final String mecId) {
        final UsuarioVO agregaUser = AgregaUtil.getAgregaUserByMecId(mecId);
        return AgregaUtil.getPublicatorName(agregaUser);
    }

    public static List<String> getOdeEditors(final String mecId) {

        final SrvPublicacionService publicationService = new SrvPublicacionServiceProxy(Utils.getMessage(AGREGA_URL) + Utils.getMessage(AGREGA_PUBLICATION_SERVICE));

        List<String> result = null;
        String[] editores;
        try {
            editores = publicationService.obtenerEditoresOdeExterno(mecId);
            if (!Utils.isEmpty(editores)) {
                result = Arrays.asList(editores);
            } else {
                Utils.logWarn(LOG, "Cannot invoke 'obtenerEditoresOdeWebSemantica'");
            }
        } catch (RemoteException e) {
            Utils.logError(LOG, e);
        }
        return result;
    }

}
