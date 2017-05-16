package es.pode.publicacion.negocio.servicios;

public class SrvPublicacionServiceProxy implements es.pode.publicacion.negocio.servicios.SrvPublicacionService {
  private String _endpoint = null;
  private es.pode.publicacion.negocio.servicios.SrvPublicacionService srvPublicacionService = null;
  
  public SrvPublicacionServiceProxy() {
    _initSrvPublicacionServiceProxy();
  }
  
  public SrvPublicacionServiceProxy(String endpoint) {
    _endpoint = endpoint;
    _initSrvPublicacionServiceProxy();
  }
  
  private void _initSrvPublicacionServiceProxy() {
    try {
      srvPublicacionService = (new es.pode.publicacion.negocio.servicios.SrvPublicacionServiceServiceLocator()).getSrvPublicacionService();
      if (srvPublicacionService != null) {
        if (_endpoint != null)
          ((javax.xml.rpc.Stub)srvPublicacionService)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
        else
          _endpoint = (String)((javax.xml.rpc.Stub)srvPublicacionService)._getProperty("javax.xml.rpc.service.endpoint.address");
      }
      
    }
    catch (javax.xml.rpc.ServiceException serviceException) {}
  }
  
  public String getEndpoint() {
    return _endpoint;
  }
  
  public void setEndpoint(String endpoint) {
    _endpoint = endpoint;
    if (srvPublicacionService != null)
      ((javax.xml.rpc.Stub)srvPublicacionService)._setProperty("javax.xml.rpc.service.endpoint.address", _endpoint);
    
  }
  
  public es.pode.publicacion.negocio.servicios.SrvPublicacionService getSrvPublicacionService() {
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService;
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO actualizarVersionODE(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String idOdeOriginal) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.actualizarVersionODE(pif, idUsuario, comentarios, titulo, idioma, idOdeOriginal);
  }
  
  public es.pode.publicacion.negocio.servicios.OdeSimilarVO[] calcularDuplicadosPublicados(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.calcularDuplicadosPublicados(idODE);
  }
  
  public boolean cambiarImagenODE(java.lang.String idODE, java.lang.String imagen) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.cambiarImagenODE(idODE, imagen);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO compartirODE(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.compartirODE(idODE);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO creacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.creacion(idODE, idUsuario, comentarios, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearDesdeURL(java.lang.String url, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String idiomaDestinatario, java.lang.String tipo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.crearDesdeURL(url, idUsuario, comentarios, titulo, idioma, idiomaDestinatario, tipo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPIF(javax.activation.DataHandler ficheroPIF, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.crearPIF(ficheroPIF, idUsuario, comentarios, titulo, idioma);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPIFCatalogado(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.crearPIFCatalogado(pif, idUsuario, comentarios, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuota(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.crearPifConCuota(pif, idUsuario, comentarios, titulo, idioma);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuotaID(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String id) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.crearPifConCuotaID(pif, idUsuario, comentarios, titulo, idioma, id);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuotaYEstado(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String estadoTransicion) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.crearPifConCuotaYEstado(pif, idUsuario, comentarios, titulo, idioma, estadoTransicion);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO descompartirODE(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.descompartirODE(idODE);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO despublicarWebSemantica(java.lang.String idODE, java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.despublicarWebSemantica(idODE, idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO eliminar(java.lang.String idODEs, java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.eliminar(idODEs, idUsuario);
  }
  
  public java.lang.Boolean eliminarIdODEForzado(java.lang.String[] identificadores) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.eliminarIdODEForzado(identificadores);
  }
  
  public es.pode.publicacion.negocio.servicios.EliminarResultadoVO[] eliminarNoDisponibles(es.pode.publicacion.negocio.servicios.EliminarNoDisponiblesVO parametro) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.eliminarNoDisponibles(parametro);
  }
  
  public java.lang.Boolean eliminarOdesUsuarios(java.lang.String[] usuarios) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.eliminarOdesUsuarios(usuarios);
  }
  
  public void guardarImagenPorDefecto(javax.activation.DataHandler imagenFile) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    srvPublicacionService.guardarImagenPorDefecto(imagenFile);
  }
  
  public java.lang.Boolean haEstadoVersionado(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.haEstadoVersionado(idODE);
  }
  
  public java.lang.Boolean insertarOdesFederadosDespublicados(es.pode.publicacion.negocio.servicios.TransicionVO[] odes, java.lang.String idNodo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.insertarOdesFederadosDespublicados(odes, idNodo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO modificaODECreado(java.lang.String idODE, java.lang.String idUsuario, java.lang.String titulo, java.lang.String comentarios) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.modificaODECreado(idODE, idUsuario, titulo, comentarios);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO noDisponible(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.noDisponible(idODE, idUsuario, comentarios, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[] noDisponibles(java.lang.String[] idODEs, java.lang.String idUsuario, java.lang.String comentario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.noDisponibles(idODEs, idUsuario, comentario);
  }
  
  public java.lang.String[] obtenerEditoresOdeWebSemantica(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenerEditoresOdeWebSemantica(idODE);
  }
  
  public java.lang.String[] obtenerOdesEditablesUsuarioWebSemantica(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenerOdesEditablesUsuarioWebSemantica(idUsuario);
  }
  
  public java.lang.String[] obtenerUsuariosCreacionDeIdentificadores(java.lang.String[] identificadores) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenerUsuariosCreacionDeIdentificadores(identificadores);
  }
  
  public java.lang.String[] obtenerUsuariosCreacionPublicadosIdentificadores(java.lang.String[] idOdes) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenerUsuariosCreacionPublicadosIdentificadores(idOdes);
  }
  
  public es.pode.publicacion.negocio.servicios.EstadoVO obtenEstadoPorIdODE(java.lang.String idODE, java.lang.String idioma) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenEstadoPorIdODE(idODE, idioma);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenHistorialPorIdODE(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenHistorialPorIdODE(idODE);
  }
  
  public es.pode.publicacion.negocio.servicios.LicenciaVO obtenLicenciaODE(java.lang.String idODE, java.lang.String idioma) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenLicenciaODE(idODE, idioma);
  }
  
  public es.pode.publicacion.negocio.servicios.OdePublicadoVO obtenODEPublicado(java.lang.String idODE) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEPublicado(idODE);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenODESCompartidos() throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODESCompartidos();
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenOdesCompartidosPorTitulo(java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenOdesCompartidosPorTitulo(titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenOdesCompartidosPorTituloYUsuarios(java.lang.String[] ids, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenOdesCompartidosPorTituloYUsuarios(ids, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenODEsCompartidosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsCompartidosPorUsuarios(ids);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsCreadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsCreadosPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsCreadosPorUsuarioPorTitulo(java.lang.String idUsuario, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsCreadosPorUsuarioPorTitulo(idUsuario, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicados() throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsDespublicados();
  }
  
  public es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[] obtenODEsDespublicadosFederadosPorFecha(java.lang.String fechaInicio, java.lang.String fechaFin) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsDespublicadosFederadosPorFecha(fechaInicio, fechaFin);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorFecha(java.lang.String fechaInicio, java.lang.String fechaFin) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsDespublicadosPorFecha(fechaInicio, fechaFin);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsDespublicadosPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsDespublicadosPorUsuarios(ids);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestos() throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPropuestos();
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODESPropuestosCatalogacion() throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODESPropuestosCatalogacion();
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODESPropuestosCatalogacionPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODESPropuestosCatalogacionPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosCatalogacionPorUsuarios(java.lang.String[] idsUsuarios) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPropuestosCatalogacionPorUsuarios(idsUsuarios);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPropuestosPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPropuestosPorUsuarios(ids);
  }
  
  public es.pode.publicacion.negocio.servicios.IdODEVO[] obtenODEsPublicados() throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicados();
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosAutonomo() throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicadosAutonomo();
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosAutonomoPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicadosAutonomoPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorTitulo(java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicadosPorTitulo(titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorTituloYUsuario(java.lang.String titulo, java.lang.String[] idsUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicadosPorTituloYUsuario(titulo, idsUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicadosPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.OdePublicadoVO[] obtenODEsPublicadoUsuario(java.lang.String usuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsPublicadoUsuario(usuario);
  }
  
  public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsRechazadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.obtenODEsRechazadosPorUsuario(idUsuario);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerCatalogacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.proponerCatalogacion(idODE, idUsuario, comentarios, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerCatalogacionNuevaVersion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.Boolean solicitaNuevaVersion) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.proponerCatalogacionNuevaVersion(idODE, idUsuario, comentarios, titulo, solicitaNuevaVersion);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerPublicacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.proponerPublicacion(idODE, idUsuario, comentarios, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicar(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String comunidades, java.lang.String universal, java.lang.String textoLicencia, java.lang.String identificadorLicencia) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.publicar(idODE, idUsuario, comentarios, titulo, comunidades, universal, textoLicencia, identificadorLicencia);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarAutonomo(java.lang.String idODE, java.lang.String idUsuario, java.lang.String titulo, java.lang.String comentarios) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.publicarAutonomo(idODE, idUsuario, titulo, comentarios);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarDespublicado(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String comunidades, java.lang.String universal, java.lang.String textoLicencia, java.lang.String identificadorLicencia) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.publicarDespublicado(idODE, idUsuario, comentarios, titulo, comunidades, universal, textoLicencia, identificadorLicencia);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarPIF(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String sobrescribir, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.publicarPIF(pif, idUsuario, comentarios, sobrescribir, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[] publicarPifCarga(java.lang.String[] odes, java.lang.String idUsuario, java.lang.String sobrescribir, java.lang.String nombreCarga, java.lang.String pathCarga) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.publicarPifCarga(odes, idUsuario, sobrescribir, nombreCarga, pathCarga);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO publicarWebSemantica(byte[] zipODE, byte[] catalogacionReducida, java.lang.String idUsuario, java.lang.String titulo, java.lang.String[] listaUsuarioEditores, boolean esNuevaVersion, java.lang.String tipoPublicacion) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.publicarWebSemantica(zipODE, catalogacionReducida, idUsuario, titulo, listaUsuarioEditores, esNuevaVersion, tipoPublicacion);
  }
  
  public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO rechazar(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.rechazar(idODE, idUsuario, comentarios, titulo);
  }
  
  public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[] regeneraIndiceIdioma(es.pode.publicacion.negocio.servicios.RegeneracionIndiceVO paramRegenera) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.regeneraIndiceIdioma(paramRegenera);
  }
  
  public java.lang.Boolean regenerarImagenes(java.lang.Long idTarea) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.regenerarImagenes(idTarea);
  }
  
  public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO reindexarODEPublicado(java.lang.String idODE, java.lang.Float valoracion) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.reindexarODEPublicado(idODE, valoracion);
  }
  
  public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[] reindexarODEsPublicados(java.lang.String[] idODEs) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.reindexarODEsPublicados(idODEs);
  }
  
  public java.lang.String subirFichero(byte[] fichero, java.lang.String nombreFichero) throws java.rmi.RemoteException{
    if (srvPublicacionService == null)
      _initSrvPublicacionServiceProxy();
    return srvPublicacionService.subirFichero(fichero, nombreFichero);
  }
  
  
}