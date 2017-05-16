/**
 * SrvPublicacionService.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.4 Apr 22, 2006 (06:55:48 PDT) WSDL2Java emitter.
 */

package es.pode.publicacion.negocio.servicios;

public interface SrvPublicacionService extends java.rmi.Remote {

    /**
     * Un método como crearPif, sólo que toma en cuenta el tamaño
     * del
     *                 ODE a la hora de validar.
     *                 Este metodo crea un ODE en estado CREADO a partir
     * de un fichero
     *                 PIF teniendo en cuenta el espacio consumido por el
     * usuario
     *                 (CREADOS más RECHAZADOS) y la cuota de espacio del
     * usuario.
     *                 Si el ODE no cabe en la cuota del usuario, se devuelve
     * un error
     *                 en consecuencia. Si hay espacio suficiente se crea
     * el ODE.
     *                 Este metodo solo se usa en los ODEs que estan siendo
     * versionados. Lo que hace es sustituir el ODE que esta siendo
     *                 versionado por uno que importa el usuario a su carpeta
     * personal.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO actualizarVersionODE(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String idOdeOriginal) throws java.rmi.RemoteException;

    /**
     * Este método calcula los ODEs publicados de la plataforma que
     * son
     *                 potenciales duplicados del ODE que le pasan.
     */
    public es.pode.publicacion.negocio.servicios.OdeSimilarVO[] calcularDuplicadosPublicados(java.lang.String idODE) throws java.rmi.RemoteException;

    /**

     */
    public boolean cambiarImagenODE(java.lang.String idODE, java.lang.String imagen) throws java.rmi.RemoteException;

    /**
     * Metodo para compartir un ODE que esta descompartido
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO compartirODE(java.lang.String idODE) throws java.rmi.RemoteException;

    /**
     * Este metodo implementa las operaciones de creacion de un nuevo
     * ODE desde la nada hasta el estado de Creacion.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO creacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Este metodo realiza las operaciones de creacion de un ODE en
     * estado CREADO.
     *                 Valida la informacion del ODE que se pasa en formato
     * PIF(ZIP) y
     *                 lo alberga en la plataforma bajo el usuario con el
     * que se crea.
     *                 Se descomprime en un temporal para validarlo, y si
     * valida se
     *                 crea un localizador y se copia en él.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearDesdeURL(java.lang.String url, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String idiomaDestinatario, java.lang.String tipo) throws java.rmi.RemoteException;

    /**
     * Este metodo realiza las operaciones de creacion de un ODE en
     * estado CREADO.
     *                 Valida la informacion del ODE que se pasa en formato
     * PIF(ZIP) y
     *                 lo alberga en la plataforma bajo el usuario con el
     * que se crea.
     *                 Se descomprime en un temporal para validarlo, y si
     * valida se
     *                 crea un localizador y se copia en él.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPIF(javax.activation.DataHandler ficheroPIF, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma) throws java.rmi.RemoteException;

    /**
     * Metodo encargado de publicar objetos en formato PIF (ZIP).
     * La
     *                 funcionalidad sera similar a la realizada por el metodo
     * publicar(idODE).
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPIFCatalogado(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Un método como crearPif, sólo que toma en cuenta el tamaño
     * del
     *                 ODE a la hora de validar.
     *                 Este metodo crea un ODE en estado CREADO a partir
     * de un fichero
     *                 PIF teniendo en cuenta el espacio consumido por el
     * usuario
     *                 (CREADOS más RECHAZADOS) y la cuota de espacio del
     * usuario.
     *                 Si el ODE no cabe en la cuota del usuario, se devuelve
     * un error
     *                 en consecuencia. Si hay espacio suficiente se crea
     * el ODE.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuota(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma) throws java.rmi.RemoteException;

    /**
     * Un método como crearPif, sólo que toma en cuenta el tamaño
     * del
     *                 ODE a la hora de validar.
     *                 Este metodo crea un ODE en estado CREADO a partir
     * de un fichero
     *                 PIF teniendo en cuenta el espacio consumido por el
     * usuario
     *                 (CREADOS más RECHAZADOS) y la cuota de espacio del
     * usuario.
     *                 Si el ODE no cabe en la cuota del usuario, se devuelve
     * un error
     *                 en consecuencia. Si hay espacio suficiente se crea
     * el ODE.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuotaID(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String id) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO crearPifConCuotaYEstado(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String idioma, java.lang.String estadoTransicion) throws java.rmi.RemoteException;

    /**
     * Metodo para descompartir un ODE que esta compartido
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO descompartirODE(java.lang.String idODE) throws java.rmi.RemoteException;

    /**
     * Metodo que llama a noDisponible con algunos argumentos ya fijos.
     * Este metodo lo usaran de forma externa desde la web semantica
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO despublicarWebSemantica(java.lang.String idODE, java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Elimina el ode que se pasa por parametro del usuario. Los odes
     * eliminables por el usuario son los que estan en estado:creacion,
     *                 no disponible, rechazado.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO eliminar(java.lang.String idODEs, java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Elimina los ODEs especificados siempre y cuando estén en estado
     * CREACION, CATALOGACION o PROPUESTO. Esta operación se realiza en
     *                 los casos en que se rechaza un ODE de un usuario que
     * se ha
     *                 eliminado.
     */
    public java.lang.Boolean eliminarIdODEForzado(java.lang.String[] identificadores) throws java.rmi.RemoteException;

    /**
     * Este metodo elimina los ODEs en estado No Disponible que cumplen
     * las condiciones de los parametros que se le pasan: rango de
     *                 fecha en el que paso a no disponible, usuario al que
     * pertenece
     *                 el ODE, etc.
     *                 Si la lista de usuarios es vacia, se tendran en cuenta
     * los ODEs
     *                 no disponibles de todo el repositorio.
     *                 Si la fecha de fin es vacia, se tendra en cuenta la
     * fecha actual
     *                 como limite temporal superior.
     *                 Si la fecha de inicio es vacia, no se tendra en cuenta
     * limite
     *                 temporal inferior.
     *                 Devuelve un array de resultados de eliminar los ODEs
     * que cumplen
     *                 las condiciones de eliminacion.
     */
    public es.pode.publicacion.negocio.servicios.EliminarResultadoVO[] eliminarNoDisponibles(es.pode.publicacion.negocio.servicios.EliminarNoDisponiblesVO parametro) throws java.rmi.RemoteException;

    /**
     * Elimina los ODEs de los usuarios pasados como parámetro y que
     * estan en creación o rechazados.
     */
    public java.lang.Boolean eliminarOdesUsuarios(java.lang.String[] usuarios) throws java.rmi.RemoteException;

    /**

     */
    public void guardarImagenPorDefecto(javax.activation.DataHandler imagenFile) throws java.rmi.RemoteException;

    /**
     * Metodo que devuelve true cuando el ODE que tiene el id pasado
     * como parametro ha estado en estado versionado en algun momento
     *                 de su ciclo de vida. Se devuelve false en otro caso
     */
    public java.lang.Boolean haEstadoVersionado(java.lang.String idODE) throws java.rmi.RemoteException;

    /**

     */
    public java.lang.Boolean insertarOdesFederadosDespublicados(es.pode.publicacion.negocio.servicios.TransicionVO[] odes, java.lang.String idNodo) throws java.rmi.RemoteException;

    /**
     * Este metodo modifica los valores de titulo y comentarios de
     * un
     *                 ode en estado creado que le pasan.
     *                 Si los valores de titulo o comentarios suministrados
     * son alguno
     *                 o los dos nulos, no se modificara el campo afectado.
     * Solo se
     *                 modificaran los campos con contenido.
     *                 Devuelve un booleano con el resultado de la modificacion
     * y una
     *                 excepcion en caso de no existir ningun ode en creacion
     * con esas
     *                 caracteristicas.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO modificaODECreado(java.lang.String idODE, java.lang.String idUsuario, java.lang.String titulo, java.lang.String comentarios) throws java.rmi.RemoteException;

    /**
     * Metodo que implementa el paso a no disponible del ODE que le
     * indican.
     *                 El paso a no disponible implica la desindexacion del
     * ODE, la
     *                 eliminacion de todas sus valoraciones y un cambio
     * de
     *                 localizacion en disco.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO noDisponible(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Este método pasa a no disponibles la lista de los ODEs que
     * le
     *                 pasan que tienen que estar en estado publicado. Se
     * comporta como
     *                 "noDisponible" pero teniendo en cuenta varios ODEs.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO[] noDisponibles(java.lang.String[] idODEs, java.lang.String idUsuario, java.lang.String comentario) throws java.rmi.RemoteException;

    /**

     */
    public java.lang.String[] obtenerEditoresOdeWebSemantica(java.lang.String idODE) throws java.rmi.RemoteException;

    /**

     */
    public java.lang.String[] obtenerOdesEditablesUsuarioWebSemantica(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Este método nos devuelve un array de usuarios que son los
     *                 creadosres de los identificadores de los odes que
     * le pasamos
     */
    public java.lang.String[] obtenerUsuariosCreacionDeIdentificadores(java.lang.String[] identificadores) throws java.rmi.RemoteException;

    /**
     * Este método devuelve la lista de usuarios creadores de los
     * ODEs
     *                 publicados cuyos identificadores se pasan.
     *                 Si el identificador que se le pasa no tiene ODE publicado
     * asociado, se devuelve "" en el nombre del usuario de creación.
     *                 Si el ODE se creó de forma masiva, no se devuelve
     * el usuario de
     *                 creación.
     */
    public java.lang.String[] obtenerUsuariosCreacionPublicadosIdentificadores(java.lang.String[] idOdes) throws java.rmi.RemoteException;

    /**
     * Este metodo consulta el estado actual del ODE que le pasan.
     * Se
     *                 le pasa el idioma al que traducir el texto descriptivo
     * del
     *                 estado.
     *                 Obtenemos el estado del ODE traducido al idioma que
     * le pasamos.
     */
    public es.pode.publicacion.negocio.servicios.EstadoVO obtenEstadoPorIdODE(java.lang.String idODE, java.lang.String idioma) throws java.rmi.RemoteException;

    /**
     * Este metodo recibe un identificador de un ODE del que espera
     * obtener un historial de las transiciones de estados por los que
     *                 ha ido pasando en su historia.
     *                 Devuelve un array con las transiciones ordenadas por
     * fecha de
     *                 los estados del ODE.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenHistorialPorIdODE(java.lang.String idODE) throws java.rmi.RemoteException;

    /**
     * Este metodo devuele la licencia de un ODE, del que sabemos
     * su
     *                 id.
     */
    public es.pode.publicacion.negocio.servicios.LicenciaVO obtenLicenciaODE(java.lang.String idODE, java.lang.String idioma) throws java.rmi.RemoteException;

    /**
     * Este metodo devuelve el ODE publicado por el identificador
     * que
     *                 le pasan.
     */
    public es.pode.publicacion.negocio.servicios.OdePublicadoVO obtenODEPublicado(java.lang.String idODE) throws java.rmi.RemoteException;

    /**
     * Metodo que devuelve todos los ODEs que estan en estado creado
     * o
     *                 rechazado y esten compartidos
     */
    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenODESCompartidos() throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenOdesCompartidosPorTitulo(java.lang.String titulo) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenOdesCompartidosPorTituloYUsuarios(java.lang.String[] ids, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Metodo que devuelve todos los ODEs que estan en estado creado
     * o
     *                 rechazado y esten compartidos por una lista de usuarios
     */
    public es.pode.publicacion.negocio.servicios.TransicionAutorVO[] obtenODEsCompartidosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException;

    /**
     * Este metodo recupera la lista de ODEs en estado CREADO asociados
     * a un usuario.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsCreadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsCreadosPorUsuarioPorTitulo(java.lang.String idUsuario, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Muestra los odes de todos los usuarios del noodo que estan
     *                 despublicados (no disponibles)
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicados() throws java.rmi.RemoteException;

    /**
     * Devuelve los IDs de los ODEs que se han despublicado entre
     * dos
     *                 fechas dadas
     */
    public es.pode.publicacion.negocio.servicios.OdesFederadosDespublicadosVO[] obtenODEsDespublicadosFederadosPorFecha(java.lang.String fechaInicio, java.lang.String fechaFin) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorFecha(java.lang.String fechaInicio, java.lang.String fechaFin) throws java.rmi.RemoteException;

    /**
     * Este metodo devuelve los ODEs que estan en estado No Disponible
     * asociados al usuario dado.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Muestra los odes de todos los usuarios que comparten grupo
     * de
     *                 trabajo que estan despublicados (no disponibles)
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsDespublicadosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException;

    /**
     * Devuelve los odes de todos los usuarios del nodo que estan
     *                 pendientes de publicacion (en estado propuesto)
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestos() throws java.rmi.RemoteException;

    /**
     * Devuelve los odes de todos los usuarios que esten pendientes
     * de
     *                 catalogar.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODESPropuestosCatalogacion() throws java.rmi.RemoteException;

    /**
     * devuelve los odes del usuario que esten pendientes de catalogar.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODESPropuestosCatalogacionPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Método para obtener los Odes propuestos para catalogación de
     * una
     *                 lista de usuarios
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosCatalogacionPorUsuarios(java.lang.String[] idsUsuarios) throws java.rmi.RemoteException;

    /**
     * Este metodo devuelve los ODEs en estado PROPUESTO asociados
     * al
     *                 usuario dado.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Método para obtener los Odes propuestos de una lista de usuarios
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPropuestosPorUsuarios(java.lang.String[] ids) throws java.rmi.RemoteException;

    /**
     * Este metodo devuelve una lista de identificadores de ODEs que
     * se
     *                 encuentren en estado publicado.
     */
    public es.pode.publicacion.negocio.servicios.IdODEVO[] obtenODEsPublicados() throws java.rmi.RemoteException;

    /**
     * Este metodo devuelve los ODEs que estan en estado
     *                 PUBLICADO_AUTONOMO.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosAutonomo() throws java.rmi.RemoteException;

    /**
     * Este metodo selecciona los ODEs en estado PUBLICADOS_AUTONOMOS
     * asociados al usuario dado.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosAutonomoPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorTitulo(java.lang.String titulo) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorTituloYUsuario(java.lang.String titulo, java.lang.String[] idsUsuario) throws java.rmi.RemoteException;

    /**
     * Este metodo selecciona los ODEs en estado PROPUESTO asociados
     * al
     *                 usuario dado.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsPublicadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Este metodo devuelve la información de publicación de los ODEs
     * que se han publicado para el usuario suministrado.
     */
    public es.pode.publicacion.negocio.servicios.OdePublicadoVO[] obtenODEsPublicadoUsuario(java.lang.String usuario) throws java.rmi.RemoteException;

    /**
     * Devuelve los odes del usuario que estan en estado rechazado.
     */
    public es.pode.publicacion.negocio.servicios.TransicionVO[] obtenODEsRechazadosPorUsuario(java.lang.String idUsuario) throws java.rmi.RemoteException;

    /**
     * Este metodo propone para catalogacion el ODE que se le indica.
     * Devuelve un VO con el error que se ha producido en el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerCatalogacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Este metodo propone para catalogacion el ODE que se le indica
     * pero marca al ODE para que se publique como una nueva version.
     *                 Este metodo solo se utiliza cuando el usuario escoje
     * proponer un
     *                 ODE versionado y quiere que cuando se publique el
     * ODE sustituya
     *                 a la version  anterior (eliminandola y) asignandole
     * el mismo ID.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerCatalogacionNuevaVersion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.Boolean solicitaNuevaVersion) throws java.rmi.RemoteException;

    /**
     * Este metodo propone para publicacion el ODE que se le indica.
     * Devuelve un VO con el error que se ha producido en el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO proponerPublicacion(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Este metodo se encargara de coger un identificador de ODE y
     * realizar todos los pasos para publicarlo, incluyendo la
     *                 generacion del MEC.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicar(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String comunidades, java.lang.String universal, java.lang.String textoLicencia, java.lang.String identificadorLicencia) throws java.rmi.RemoteException;

    /**
     * Este metodo se encargara de coger un identificador de ODE y
     * realizar todos los pasos para publicarlo autonomamente.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarAutonomo(java.lang.String idODE, java.lang.String idUsuario, java.lang.String titulo, java.lang.String comentarios) throws java.rmi.RemoteException;

    /**
     * Publica un ode que este en estado despublicado. No genera un
     * nuevo codigo mec.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarDespublicado(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo, java.lang.String comunidades, java.lang.String universal, java.lang.String textoLicencia, java.lang.String identificadorLicencia) throws java.rmi.RemoteException;

    /**
     * Metodo encargado de publicar objetos en formato PIF (ZIP).
     * La
     *                 funcionalidad sera similar a la realizada por el metodo
     * publicar(idODE).
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO publicarPIF(javax.activation.DataHandler pif, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String sobrescribir, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Método que realiza la carga masiva del conjunto que odes que
     * se
     *                 pasan por parámetro.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionCargaVO[] publicarPifCarga(java.lang.String[] odes, java.lang.String idUsuario, java.lang.String sobrescribir, java.lang.String nombreCarga, java.lang.String pathCarga) throws java.rmi.RemoteException;

    /**

     */
    public es.pode.publicacion.negocio.servicios.ResultadoPublicacionVO publicarWebSemantica(byte[] zipODE, byte[] catalogacionReducida, java.lang.String idUsuario, java.lang.String titulo, java.lang.String[] listaUsuarioEditores, boolean esNuevaVersion, java.lang.String tipoPublicacion) throws java.rmi.RemoteException;

    /**
     * Metodo que implementa el rechazo del ODE que le indican.
     *                 Devuelve un VO con el error que se ha producido en
     * el caso de
     *                 detectarse algun problema.
     */
    public es.pode.publicacion.negocio.servicios.ResultadoOperacionVO rechazar(java.lang.String idODE, java.lang.String idUsuario, java.lang.String comentarios, java.lang.String titulo) throws java.rmi.RemoteException;

    /**
     * Se regeneran los indices de los idiomas que se pasan.
     *                 Se borran todos los odes indexados en esos idiomas
     * y se indexan
     *                 los odes publicados en el momento de la invocacion
     * para cada
     *                 idioma afectado.
     */
    public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[] regeneraIndiceIdioma(es.pode.publicacion.negocio.servicios.RegeneracionIndiceVO paramRegenera) throws java.rmi.RemoteException;

    /**

     */
    public java.lang.Boolean regenerarImagenes(java.lang.Long idTarea) throws java.rmi.RemoteException;

    /**
     * Este metodo reindexa en el indice de busqueda el ODE que se
     * le
     *                 indica con la valoracion que le pasan.
     *                 Devuelve un VO con el codigo de exito o error en la
     * operacion.
     */
    public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO reindexarODEPublicado(java.lang.String idODE, java.lang.Float valoracion) throws java.rmi.RemoteException;

    /**
     * Este metodo reindexa la lista de ODEs publicados que le pasan
     * (lista de identificadores).
     *                 Los elimina del indice  y los vuelve a reindexar cada
     * uno en su
     *                 idioma.
     *                 Se devuelve un VO con codigo de exito/fracaso para
     * cada ODE.
     */
    public es.pode.publicacion.negocio.servicios.ReindexarODEResultadoVO[] reindexarODEsPublicados(java.lang.String[] idODEs) throws java.rmi.RemoteException;

    /**

     */
    public java.lang.String subirFichero(byte[] fichero, java.lang.String nombreFichero) throws java.rmi.RemoteException;
}
