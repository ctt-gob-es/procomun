package com.itelligent.agrega2.dal;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.mahout.cf.taste.common.NoSuchItemException;
import org.apache.mahout.cf.taste.common.TasteException;
import org.apache.mahout.cf.taste.eval.RecommenderBuilder;
import org.apache.mahout.cf.taste.eval.RecommenderEvaluator;
import org.apache.mahout.cf.taste.impl.common.FastIDSet;
import org.apache.mahout.cf.taste.impl.eval.AverageAbsoluteDifferenceRecommenderEvaluator;
import org.apache.mahout.cf.taste.impl.model.file.FileDataModel;
import org.apache.mahout.cf.taste.impl.neighborhood.NearestNUserNeighborhood;
import org.apache.mahout.cf.taste.impl.recommender.GenericUserBasedRecommender;
import org.apache.mahout.cf.taste.impl.similarity.EuclideanDistanceSimilarity;
import org.apache.mahout.cf.taste.impl.similarity.LogLikelihoodSimilarity;
import org.apache.mahout.cf.taste.impl.similarity.PearsonCorrelationSimilarity;
import org.apache.mahout.cf.taste.impl.similarity.TanimotoCoefficientSimilarity;
import org.apache.mahout.cf.taste.model.DataModel;
import org.apache.mahout.cf.taste.model.PreferenceArray;
import org.apache.mahout.cf.taste.neighborhood.UserNeighborhood;
import org.apache.mahout.cf.taste.recommender.RecommendedItem;
import org.apache.mahout.cf.taste.recommender.Recommender;
import org.apache.mahout.cf.taste.similarity.UserSimilarity;

import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.beans.Recomendacion;

/**
 * Clase encargada de la recomendació de intereaciones
 * 
 */
public class RecomendadorIteracion {

    private static final Log LOG = LogFactory.getLog(Sincronizacion.class);

    private String strPath = "fuenteCSVRecomendador/";
    private String strRaizFichero = "agrega";
    private int intNumFile = 0;
    private long longDtmMax = -2;
    private FastIDSet setOdes;
    private FastIDSet setQuestion;
    private FastIDSet setUser;
    private FastIDSet setCommunity;
    private FastIDSet setPost;
    private FastIDSet setDiscussion;
    private DataModel modelo = null;
    private UserSimilarity similitud = null;
    private UserNeighborhood vencindario = null;
    private Recommender recomendador = null;
    private FastIDSet setDeleted;

    /*
     * Creación de los recommender Builders
     */
    private static int K;
    RecommenderBuilder factoriaPearson = new RecommenderBuilder() {

        @Override
        public Recommender buildRecommender(DataModel dataModel) throws TasteException {
            UserSimilarity simil = new PearsonCorrelationSimilarity(dataModel);
            UserNeighborhood vecindario = new NearestNUserNeighborhood(K, simil, dataModel);
            return new GenericUserBasedRecommender(dataModel, vecindario, simil);
        }
    };

    RecommenderBuilder factoriaEuclidea = new RecommenderBuilder() {

        @Override
        public Recommender buildRecommender(DataModel dataModel) throws TasteException {
            UserSimilarity simil = new EuclideanDistanceSimilarity(dataModel);
            UserNeighborhood vecindario = new NearestNUserNeighborhood(K, simil, dataModel);
            return new GenericUserBasedRecommender(dataModel, vecindario, simil);
        }
    };

    RecommenderBuilder factoriaLogLikelihodd = new RecommenderBuilder() {

        @Override
        public Recommender buildRecommender(DataModel dataModel) throws TasteException {
            UserSimilarity simil = new LogLikelihoodSimilarity(dataModel);
            UserNeighborhood vecindario = new NearestNUserNeighborhood(K, simil, dataModel);
            return new GenericUserBasedRecommender(dataModel, vecindario, simil);
        }
    };

    RecommenderBuilder factoriaTanimoto = new RecommenderBuilder() {

        @Override
        public Recommender buildRecommender(DataModel dataModel) throws TasteException {
            UserSimilarity simil = new TanimotoCoefficientSimilarity(dataModel);
            UserNeighborhood vecindario = new NearestNUserNeighborhood(K, simil, dataModel);
            return new GenericUserBasedRecommender(dataModel, vecindario, simil);
        }
    };

    public RecomendadorIteracion(String strPathI) {
        this.strPath = strPathI + "fuenteCSVRecomendador/";
        this.setOdes = new FastIDSet();
        this.setQuestion = new FastIDSet();
        this.setUser = new FastIDSet();
        this.setCommunity = new FastIDSet();
        this.setPost = new FastIDSet();
        this.setCommunity = new FastIDSet();
        this.setDeleted = new FastIDSet();
    }

    public void entrenamiento(String strPath, int[] arrayk) {
        String strCabecera = "Medida";
        String strPearson = "Pearson";
        String strEuclidea = "Euclidea";
        String strLog = "Log-likelihood";
        String strTanimoto = "Tanimoto";
        BufferedWriter bw = null;
        DataModel model;
        try {
            model = new FileDataModel(new File(strPath));
            RecommenderEvaluator evaluator = new AverageAbsoluteDifferenceRecommenderEvaluator();

            bw = new BufferedWriter(new FileWriter("entranamiento.csv"));

            int totalIter = arrayk.length * 4;

            for (int i = 0; i < arrayk.length; i++) {
                Utils.logInfo(LOG, i + "/" + totalIter);
                K = arrayk[i];
                strCabecera += ";" + K;
                strPearson += ";" + evaluator.evaluate(factoriaPearson, null, model, 0.95, 0.05);
                strEuclidea += ";" + evaluator.evaluate(factoriaEuclidea, null, model, 0.95, 0.05);
                strLog += ";" + evaluator.evaluate(factoriaLogLikelihodd, null, model, 0.95, 0.05);
                strTanimoto += ";" + evaluator.evaluate(factoriaTanimoto, null, model, 0.95, 0.05);
            }

            Utils.logInfo(LOG, strCabecera);
            bw.write(strCabecera + "\n");
            Utils.logInfo(LOG, strPearson);
            bw.write(strPearson + "\n");
            Utils.logInfo(LOG, strEuclidea);
            bw.write(strEuclidea + "\n");
            Utils.logInfo(LOG, strLog);
            bw.write(strLog + "\n");
            Utils.logInfo(LOG, strTanimoto);
            bw.write(strTanimoto + "\n");

        } catch (IOException e) {
            Utils.logError(LOG, e);
        } catch (TasteException e) {
            Utils.logError(LOG, e);
        } finally {
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e);
                }
            }
        }
    }

    /*
     * =========================================================================
     * = FIN FACTORIAS
     * ============================================================
     * ==============
     */
    /**
     * Añade los contenidos al conjunto correspondiente para posterioemente
     * poder filtrar por los tipos
     * 
     * @param idContenido
     *            identificador del contenido
     * @param tipo
     *            tipo del contenido
     */
    private void clasificaInteraccion(long idContenido, TipoContenido tipo) {
        if (tipo == TipoContenido.ODE) {
            if (this.setOdes.add(idContenido)) {
                this.setOdes.rehash();
            }
        } else if (tipo == TipoContenido.QUESTION) {
            if (this.setQuestion.add(idContenido)) {
                this.setQuestion.rehash();
            }
        } else if (tipo == TipoContenido.USER) {
            if (this.setUser.add(idContenido)) {
                this.setUser.rehash();
            }
        } else if (tipo == TipoContenido.COMMUNITY) {
            if (this.setCommunity.add(idContenido)) {
                this.setCommunity.rehash();
            }
        } else if (tipo == TipoContenido.POST) {
            if (this.setPost.add(idContenido)) {
                this.setPost.rehash();
            }
        } else if (tipo == TipoContenido.COMMUNITY) {
            if (this.setCommunity.add(idContenido)) {
                this.setCommunity.rehash();
            }
        }
    }

    /**
     * Genera un fichero CSV separado por comas a partir de la lista de
     * interaccione que recibe
     * 
     * @param lstInteraccciones
     *            lista de interacciones a volcar en el csv
     * @param strRuta
     *            ruta en la que se generará el CSV
     * @return mayor id de las interaccioes procesdas
     * @throws IOException
     *             Error en la generacion del fichero
     */
    private long interaccionesToCsv(List<Interaccion> lstInteraccciones, String strRuta) {
        long longMaxDtmCsv = -1;

        BufferedWriter bw = null;
        try {
            bw = new BufferedWriter(new FileWriter(strRuta));

            for (Interaccion interaccion : lstInteraccciones) {
                String strLine = interaccion.getIdUsuario() + "," + interaccion.getIdContenido() + "," + interaccion.scoreMahout() + "\n";

                bw.write(strLine);

                this.clasificaInteraccion(interaccion.getIdContenido(), interaccion.getTipoContenido());

                if (interaccion.getDtmInteraccion() > longMaxDtmCsv) {
                    longMaxDtmCsv = interaccion.getDtmInteraccion();
                }
            }
        } catch (IOException e) {
            Utils.logError(LOG, e);
        } finally {
            if (bw != null) {
                try {
                    bw.close();
                } catch (IOException e) {
                    Utils.logError(LOG, e);
                }
            }
        }

        return longMaxDtmCsv;

    }

    /**
     * Método encargado del arranque del reocmendador
     * 
     * @param lstInteraccciones
     *            Lsiata de interaciones a volcar en la creación del
     *            recomendador
     * @return int Id de la mayor interaccion procesada
     * @throws Exception
     */
    private long arranqueRecomendador(List<Interaccion> lstInteraccciones) {
        long longMaxDtmCsv = -1;

        // valdio si el directorio para los csv del recomendador existe o si hay
        // que crearlo
        File carpetaFuente = new File(this.strPath);

        if (!carpetaFuente.exists()) {
            carpetaFuente.mkdirs();
        } else {
            File[] ficheros = carpetaFuente.listFiles();

            for (int i = 0; i < ficheros.length; ++i) {
                ficheros[i].delete();
            }
        }

        // Genero el csv
        String srtSalidaCSV = this.strPath + this.strRaizFichero + ".csv";

        longMaxDtmCsv = this.interaccionesToCsv(lstInteraccciones, srtSalidaCSV);

        // Genero el data model
        try {
            this.modelo = new FileDataModel(new File(srtSalidaCSV));

            this.similitud = new EuclideanDistanceSimilarity(this.modelo);

            this.vencindario = new NearestNUserNeighborhood(1000, this.similitud, this.modelo);
        } catch (IOException e) {
            Utils.logError(LOG, e);
        } catch (TasteException e) {
            Utils.logError(LOG, e);
        }

        this.recomendador = new GenericUserBasedRecommender(this.modelo, this.vencindario, this.similitud);
        this.intNumFile++;
        return longMaxDtmCsv;
    }

    /**
     * Añade una lista de interacciones al recomendador
     * 
     * @param lstInteraccciones
     *            Lista de interacciones a añadir
     * @return id mayor identificador de las interaccioens procesadas
     * @throws Exception
     */
    public void AnadirInteracciones(List<Interaccion> lstInteraccciones) {
        long longMaxDtmCsv = 0;
        if (lstInteraccciones.size() > 0) {
            if (this.modelo == null) {
                longMaxDtmCsv = this.arranqueRecomendador(lstInteraccciones);
            } else {
                String srtSalidaCSV = this.strPath + this.strRaizFichero + "." + this.intNumFile + ".csv";
                longMaxDtmCsv = this.interaccionesToCsv(lstInteraccciones, srtSalidaCSV);
                this.intNumFile++;

                this.recomendador.refresh(null);
            }

            if (longMaxDtmCsv > this.longDtmMax) {
                this.longDtmMax = longMaxDtmCsv;
            }
        }

    }

    /**
     * Comprueba si un contenido pertenece a un cierto tipo
     * 
     * @param idContenido
     *            identificador del contenido que se desea comprobar
     * @param tipo
     *            tipo al que se desea saber si pertenece
     * @return true si el Contenido es del tipo indicado false encaso contrario
     */
    private boolean filtroTipoContenido(long idContenido, TipoContenido tipo) {
        if (tipo == TipoContenido.ODE) {
            return this.setOdes.contains(idContenido);
        } else if (tipo == TipoContenido.QUESTION) {
            return this.setQuestion.contains(idContenido);
        } else if (tipo == TipoContenido.USER) {
            return this.setUser.contains(idContenido);
        } else if (tipo == TipoContenido.COMMUNITY) {
            return this.setOdes.contains(idContenido);
        } else if (tipo == TipoContenido.POST) {
            return this.setOdes.contains(idContenido);
        } else if (tipo == TipoContenido.DISCUSSION) {
            return this.setDiscussion.contains(idContenido);
        }
        return false;
    }

    /**
     * Realiza al recomendacion para un usuario dado y un tipo de Contenido
     * 
     * @param idUser
     *            identificador del suauiro alq ue se desea realizar la
     *            recomendación
     * @param minScore
     *            Score mínimo que se desea para las recomendaciones
     * @param intNumRecomendaciones
     *            numero de recomendaciones a devolver
     * @param tipoRecomendar
     *            tipo de contenido a recomendar
     * @return
     * @throws Exception
     */
    public List<Recomendacion> recomendar(long idUser, double minScore, int intNumRecomendaciones, TipoContenido tipoRecomendar, long idContenido) {
        List<Recomendacion> lstRecomendaciones = new ArrayList<Recomendacion>();
        List<RecommendedItem> recomendations = new ArrayList<>();
        boolean flagScore = true;

        if (this.modelo == null) {
            return lstRecomendaciones;
        }

        if (minScore <= 0) {
            minScore = Double.MIN_VALUE;
        }

        try {
            recomendations = this.recomendador.recommend(idUser, 100);
        } catch (TasteException e) {
            Utils.logError(LOG, e, "RecomendadorInteraccion.recomendar: Error on recommender process");
        }

        for (int i = 0; i < recomendations.size() && lstRecomendaciones.size() < intNumRecomendaciones && flagScore; i++) {
            RecommendedItem item = recomendations.get(i);

            float score = item.getValue();
            long itemId = item.getItemID();

            if (score >= minScore) {
                if (this.filtroTipoContenido(itemId, tipoRecomendar) && this.isValid(itemId)) {
                    lstRecomendaciones.add(new Recomendacion(itemId, score));
                }
            } else {
                flagScore = false;
            }

        }

        final SolrDocumentA2 solrDocA2 = SolrSupport.getSolrDocumentById(String.valueOf(idContenido));
        final String title = solrDocA2.getTitle();
        final String id = solrDocA2.getId();

        if (lstRecomendaciones.size() < intNumRecomendaciones) {
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones - lstRecomendaciones.size(), tipoRecomendar.name(), title, id));
        }
        if (tipoRecomendar.name().equals(TipoContenido.ODE.name())) {
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones, "POST", title, id));
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones, "COMMUNITY", title, id));
        } else if (tipoRecomendar.name().equals(TipoContenido.POST.name())) {
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones, "ODE", title, id));
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones - lstRecomendaciones.size(), "COMMUNITY", title, id));
        } else if (tipoRecomendar.name().equals(TipoContenido.COMMUNITY.name())) {
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones, "ODE", title, id));
            lstRecomendaciones.addAll(Decisor.getSolrRecommendations(intNumRecomendaciones, "POST", title, id));
        }

        return lstRecomendaciones;
    }

    /**
     * Devuelve la fecha máxima de las interacciones almacenadas
     * 
     * @return Fecha máxima de las interaccioens conocidas
     */
    public long getDtmMax() {
        return this.longDtmMax;
    }

    /**
     * Devuelve el nuemro de interacciones para un usuario concreso
     * 
     * @param idUsuario
     *            identificado del usuario para el que se desea concoer el
     *            número de interacciones
     * @return devuelve el número de interacicones realizadas por el usuario, -1
     *         en caso que el usuario no existe
     */
    public int getNumeroInteraccionesUsuario(long idUsuario) {
        if (this.modelo == null) {
            return 0;
        } else {
            try {
                return this.modelo.getPreferencesFromUser(idUsuario).length();
            } catch (TasteException e) {
                return -1;
            }
        }
    }

    /**
     * Devuelve la lista de identificadores de contenidos para un determinado
     * usuairo
     * 
     * @param longIdUsuario
     *            identificador del usuario
     * @return conjuto con los ids de los contenidos con los que ha
     *         interaccionado el usuario
     */
    public FastIDSet getInteraccionesUsuario(long longIdUsuario) {
        try {
            return this.modelo.getItemIDsFromUser(longIdUsuario);
        } catch (TasteException e) {

            Utils.logError(LOG, e, "RecomendadorInteraccion.getInteraccionesUsuarios: error getting items id");
            return new FastIDSet();
        }
    }

    public boolean isValid(long idContent) {
        if (this.setDeleted.contains(idContent)) {
            return false;
        } else {
            return true;
        }
    }

    public void deleteInteracctionByContent(long idContent) throws Exception {
        boolean blnContenidoValido;

        try {
            PreferenceArray prefContenido = this.modelo.getPreferencesForItem(idContent);
            blnContenidoValido = (prefContenido.length() > 0);
        } catch (NoSuchItemException | NullPointerException e) {
            blnContenidoValido = false;
        } catch (TasteException e) {
            throw new Exception("RecomendadorInteraccion.deleteInteracctionByContent: taste Exception (" + e.getMessage() + ")");
        }

        if (blnContenidoValido) {
            if (this.setDeleted.add(idContent)) {
                this.setDeleted.rehash();
            }
        }
    }

}
