package com.itelligent.agrega2.dal;

import java.io.File;
import java.io.IOException;
import java.text.Format;
import java.text.Normalizer;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.NumericField;
import org.apache.lucene.index.CorruptIndexException;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.Term;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.MatchAllDocsQuery;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.Sort;
import org.apache.lucene.search.SortField;
import org.apache.lucene.search.TermQuery;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.search.similar.MoreLikeThis;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.store.LockObtainFailedException;
import org.apache.lucene.util.Version;
import org.apache.mahout.cf.taste.impl.common.FastIDSet;

import com.emergya.agrega2.arranger.model.entity.solr.SolrDocumentA2;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.beans.Recomendacion;

/**
 * 
 */
public class RecomendadorContenido {

    private static final Log LOG = LogFactory.getLog(RecomendadorContenido.class);

    static String luceneDir;
    private IndexReader luceneReader;
    private IndexSearcher luceneSearch;

    /**
     * Contructor recomendador contenido
     * 
     */
    public RecomendadorContenido(String strPath) {

        FSDirectory dirIndice = null;
        IndexWriter luceneWriter = null;
        boolean blnCrear;

        luceneDir = strPath + "recomendadorContenidos/";
        File folderIndex = new File(luceneDir);

        if (folderIndex.exists()) {
            blnCrear = false;
        } else {
            blnCrear = true;
        }
        try {
            dirIndice = FSDirectory.open(new File(luceneDir));

            luceneWriter = new IndexWriter(dirIndice, new StandardAnalyzer(Version.LUCENE_30), blnCrear, IndexWriter.MaxFieldLength.UNLIMITED);
            luceneReader = IndexReader.open(dirIndice);
            luceneSearch = new IndexSearcher(luceneReader);
            if (luceneWriter != null) {
                luceneWriter.close();
            }
        } catch (CorruptIndexException e) {
            Utils.logError(LOG, e, "RecomendadorContenido: Corrupt index.");
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendadorContenido: Error getting Lucene folder.");
        }

    }

    /**
     * Normaliza una cadena de texto siguiendo las siguiente estructura:
     * <ul>
     * <li>Eliminacion de acentos</li>
     * <li>Convertir a minusculas</li>
     * <li>Elimina todo lo que no sea caracteres a-z o espacios en blanco</li>
     * </ul>w
     * 
     * @param strInput
     *            String a normalizar
     * @return string normalizado según las normas descritas
     */
    private String normaliza(String strInput) {
        String strOutput;

        strOutput = Normalizer.normalize(strInput, Normalizer.Form.NFD);
        strOutput = strOutput.replaceAll("\\p{InCombiningDiacriticalMarks}+", "");
        strOutput = strOutput.toLowerCase();
        strOutput = strOutput.replaceAll("[^a-z\\s]", "");

        return strOutput;
    }

    /**
     * Convierte un contenido a un documento lucene
     * 
     * @param cont
     *            Contenido que se desea convertir en Dcocument
     * @return Documento lucene con el Contenido
     */
    private Document contenidoToDocument(Contenido cont) {
        Document res = new Document();

        res.add(new Field("strId", Long.toString(cont.getId()), Field.Store.YES, Field.Index.ANALYZED));
        res.add(new NumericField("longId", Field.Store.YES, true).setLongValue(cont.getId()));
        res.add(new Field("strTitulo", cont.getGeneralTitle(), Field.Store.YES, Field.Index.NO));
        res.add(new Field("strTituloTokenizado", this.normaliza(cont.getGeneralTitle()), Field.Store.YES, Field.Index.ANALYZED));
        res.add(new Field("strDescripcion", cont.getGeneralDescription(), Field.Store.YES, Field.Index.NO));
        res.add(new Field("strDescripcionTokenizada", this.normaliza(cont.getGeneralDescription()), Field.Store.YES, Field.Index.ANALYZED));
        res.add(new Field("strTipoContenido", cont.getTipoContenido().toString(), Field.Store.YES, Field.Index.ANALYZED));
        res.add(new NumericField("dtmIndexacion", Field.Store.YES, true).setLongValue(cont.getDtmIndexacion().getTime()));

        return res;
    }

    /**
     * Valida si el id ya se encuenra indexado en un doucmento
     * 
     * @param id
     *            identificador a buscar
     * @return true si el id ya existe false en caso contrario
     */
    private boolean exist(String id) {
        Query query;
        Term t;
        TopDocs docs = new TopDocs(0, null, 0);
        // En orimer lugar busco el documento
        t = new Term("strId", id);
        query = new TermQuery(t);
        try {
            docs = luceneSearch.search(query, 1);
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendadorContenido.recomedar: Error getting file to own search.");
        }

        return docs.totalHits != 0;

    }

    /**
     * Añade la lista de contenidos al indice lucene
     * 
     * @param lstContenidos
     *            Lista de contenidos a añadir
     * @return mayor Id del contenido añadido
     *         <ul>
     *         <li>Indice corrucpo</li>
     *         <li>Indice bloqueado</li>
     *         <li>Error manejo fichero</li>
     *         <ul>
     */
    public long AddContenido(List<Contenido> lstContenidos) {

        long longIdMaxContenido = -1;

        // Creacion del index writer y escritura en el indice
        Directory dirIndice;
        IndexWriter luceneWriter = null;
        try {
            dirIndice = FSDirectory.open(new File(luceneDir));
            luceneWriter = new IndexWriter(dirIndice, new StandardAnalyzer(Version.LUCENE_30), false, IndexWriter.MaxFieldLength.UNLIMITED);
            for (Contenido contenido : lstContenidos) {
                Document docAdd = this.contenidoToDocument(contenido);
                if (this.exist(String.valueOf(contenido.getId()))) {
                    luceneWriter.updateDocument(new Term("strId", String.valueOf(contenido.getId())), docAdd);
                } else {
                    luceneWriter.addDocument(docAdd);
                }
                if (contenido.getId() > longIdMaxContenido) {
                    longIdMaxContenido = contenido.getId();
                }
            }
            if (luceneWriter != null) {
                luceneWriter.close();
            }

            luceneSearch.close();
            luceneReader.close();

            // recarga del reader y del search
            dirIndice = FSDirectory.open(new File(luceneDir));
            luceneReader = IndexReader.open(dirIndice);
            luceneSearch = new IndexSearcher(luceneReader);

        } catch (CorruptIndexException e) {
            Utils.logError(LOG, e, "RecomendadorContenido.AddContenidos: Corrupt index");
        } catch (LockObtainFailedException e) {
            Utils.logError(LOG, e, "RecomendadorContenido.AddContenido: Error trying to block index");
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendadorContenido.AddContenido: Error getting Lucene folder");
        } catch (Exception e) {
            Utils.logError(LOG, e, "RecomendadorContenido.AddContenido: Error trying to load Lucene index.");
        }

        return longIdMaxContenido;
    }

    /**
     * Realiza una recomendación para el identificador de item y tipo de
     * contenido dado
     * 
     * @param idContenido
     *            identificador del item
     * @param fltScoreMin
     *            Score minimo a tener en cuenta
     * @param intNumRecomendaciones
     *            numero de recomendaciones a devolver
     * @param tipoFiltrar
     *            Tipo de contenidos a recomendar
     * @return Lista de recomendaciones
     */
    public List<Recomendacion> recomendar(String idContenido, float fltScoreMin, int intNumRecomendaciones, TipoContenido tipoFiltrar, FastIDSet listaNegra) {
        List<Recomendacion> lstRes = new ArrayList<Recomendacion>();

        int intNumDocs;
        float fltScorePropio;
        MoreLikeThis mlt;
        Query query;
        Term t;
        TopDocs docs = new TopDocs(0, null, 0);
        boolean flagParadaScore = false;

        // En orimer lugar busco el documento
        t = new Term("strId", idContenido);
        query = new TermQuery(t);
        try {
            docs = luceneSearch.search(query, 1);
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendadorContenido.recomedar: Error getting file to own search.");
        }

        if (docs.totalHits == 0) {
            return lstRes;
        }

        // Genero el more like this

        mlt = new MoreLikeThis(luceneReader);
        mlt.setFieldNames(new String[] { "strTituloTokenizado", "strDescripcionTokenizada" });
        mlt.setMinTermFreq(1);
        mlt.setMinDocFreq(1);

        intNumDocs = luceneReader.numDocs();

        // Realizo la consulta para similitud
        try {
            query = mlt.like(docs.scoreDocs[0].doc);

            docs = luceneSearch.search(query, intNumDocs);

            if (docs.totalHits == 0) {
                return lstRes;
            }

            // Cojo el score del primer documento (score propio)
            // 3 Recommendations per type ODE, POST & COMMUNITY
            fltScorePropio = docs.scoreDocs[0].score;
            int i = 0;
            Utils.logInfo(LOG, "Processing {0} documents", docs.scoreDocs.length);
            while (i < docs.scoreDocs.length && lstRes.size() < intNumRecomendaciones && !flagParadaScore && !(intNumRecomendaciones >= 3)) {
                long intIdContenidoRecomendar;
                String strIdContenidoRecomendar;
                float fltScoreRecomendar;
                TipoContenido tipoDocumento;

                Document doc = luceneReader.document(docs.scoreDocs[i].doc);

                tipoDocumento = TipoContenido.valueOf(doc.getField("strTipoContenido").stringValue());
                if (tipoDocumento.name().equals(tipoFiltrar.name())) {
                    strIdContenidoRecomendar = doc.getField("strId").stringValue();
                    intIdContenidoRecomendar = Long.parseLong(strIdContenidoRecomendar);
                    fltScoreRecomendar = docs.scoreDocs[i].score / fltScorePropio;

                    // Nos aseguramos que no es el mismo
                    if (!strIdContenidoRecomendar.equalsIgnoreCase(idContenido)) {
                        // Validao el score
                        if (fltScoreRecomendar > fltScoreMin) {
                            // Valido que no este en lista negra
                            if (!listaNegra.contains(intIdContenidoRecomendar)) {
                                lstRes.add(new Recomendacion(intIdContenidoRecomendar, fltScoreRecomendar));
                            }
                        } else {
                            flagParadaScore = true;
                        }
                    }
                }
                i++;
            }
            Utils.logInfo(LOG, "Docs processed: {0}", i);
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendadorContenido.recomedar: Error getting file to 'more like this'.");
        }

        final SolrDocumentA2 solrDocA2 = SolrSupport.getSolrDocumentById(idContenido);
        final String title = solrDocA2.getTitle();
        final String id = solrDocA2.getId();

        if (lstRes.size() < 3) {
            lstRes.addAll(Decisor.getSolrRecommendations(3 - lstRes.size(), tipoFiltrar.name(), title, id));
        }

        if (tipoFiltrar.name().equals(TipoContenido.ODE.name())) {
            lstRes.addAll(Decisor.getSolrRecommendations(3, "POST", title, id));
            lstRes.addAll(Decisor.getSolrRecommendations(3, "COMMUNITY", title, id));
        } else if (tipoFiltrar.name().equals(TipoContenido.POST.name())) {
            lstRes.addAll(Decisor.getSolrRecommendations(3, "ODE", title, id));
            lstRes.addAll(Decisor.getSolrRecommendations(3, "COMMUNITY", title, id));
        } else if (tipoFiltrar.name().equals(TipoContenido.COMMUNITY.name())) {
            lstRes.addAll(Decisor.getSolrRecommendations(3, "ODE", title, id));
            lstRes.addAll(Decisor.getSolrRecommendations(3, "POST", title, id));
        }

        return lstRes;
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
    private boolean filtroTipoContenido(TipoContenido tipoDocumento, TipoContenido tipoFiltrar) {
        if (tipoFiltrar.name().equals(TipoContenido.ODE.name()) || tipoFiltrar.name().equals(TipoContenido.POST.name())
                || tipoFiltrar.name().equals(TipoContenido.COMMUNITY.name())) {
            if (tipoDocumento.name().equals(TipoContenido.ODE.name()) || tipoDocumento.name().equals(TipoContenido.POST.name())
                    || tipoDocumento.name().equals(TipoContenido.COMMUNITY.name())) {
                return true;
            }
        }
        return false;
    }

    /**
     * Método que devuelve el máximo long en el índice lucene para el campo
     * longId
     * 
     * @return {@code long} Representa el mayor valor del campo longId
     */
    public long getMaxIdEnLucene() {
        Sort sort = new Sort(new SortField("longId", SortField.LONG, true));
        TopDocs result = new TopDocs(0, null, 0);
        try {

            result = this.luceneSearch.search(new MatchAllDocsQuery(), null, this.luceneReader.maxDoc(), sort);
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendarContenido.getMaxIdLucene: error manejo fichero en busqueda.");
        }

        if (result.totalHits == 0) {
            return -1;
        } else {
            Document doc = null;
            try {
                doc = luceneReader.document(result.scoreDocs[0].doc);
            } catch (CorruptIndexException e) {
                Utils.logError(LOG, e, "RecomendadorContenido.getMaxIdLucene: error acceso documento, indice corrupto");
            } catch (IOException e) {
                Utils.logError(LOG, e, "RecomendadorContenido.getMaxIdLucene: error acceso documento, manejofichero.");
            }
            return Long.parseLong(doc.getField("longId").stringValue());
        }

    }

    /**
     * Devuelve el maximo valor de fecha indexacion que se tiene
     * 
     * @return maxima fecha de indexación
     */
    public String getTDateMaxEnLucene() {
        long longTime;
        Sort sort = new Sort(new SortField("dtmIndexacion", SortField.LONG, true));
        TopDocs result = new TopDocs(0, null, 0);
        try {

            result = this.luceneSearch.search(new MatchAllDocsQuery(), null, this.luceneReader.maxDoc(), sort);
        } catch (IOException e) {
            Utils.logError(LOG, e, "RecomendarContenido.getMaxIdLucene: error manejo fichero en busqueda.");
        }

        if (result.totalHits == 0) {
            longTime = -1;
        } else {
            Document doc = null;
            try {
                doc = luceneReader.document(result.scoreDocs[0].doc);
            } catch (CorruptIndexException e) {
                Utils.logError(LOG, e, "RecomendadorContenido.getMaxIdLucene: error acceso documento, indice corrupto");
            } catch (IOException e) {
                Utils.logError(LOG, e, "RecomendadorContenido.getMaxIdLucene: error acceso documento, manejofichero.");
            }
            longTime = Long.parseLong(doc.getField("dtmIndexacion").stringValue());
        }

        longTime += 10;
        Date date = new Date(longTime);
        Format format = new SimpleDateFormat(Utils.DEFAULT_DATE_FORMAT);

        String dateStr = format.format(date);

        return dateStr;
    }

    public void eliminarContenido(long idContenido) throws Exception {
        String strId;

        strId = String.valueOf(idContenido);

        Directory dirIndice;
        IndexWriter luceneWriter = null;

        if (this.exist(strId)) {
            try {
                dirIndice = FSDirectory.open(new File(luceneDir));
                luceneWriter = new IndexWriter(dirIndice, new StandardAnalyzer(Version.LUCENE_30), false, IndexWriter.MaxFieldLength.UNLIMITED);
                luceneWriter.deleteDocuments(new Term("strId", strId));

                luceneWriter.close();

                luceneSearch.close();
                luceneReader.close();

                // recarga del reader y del search
                dirIndice = FSDirectory.open(new File(luceneDir));
                luceneReader = IndexReader.open(dirIndice);
                luceneSearch = new IndexSearcher(luceneReader);

            } catch (CorruptIndexException e) {
                throw new Exception("RecomendadorContenido.eliminarContenido: corrupt index error (" + e.getMessage() + ")");
            } catch (LockObtainFailedException e) {
                throw new Exception("RecomendadorContenido.eliminarContenido: index locked (" + e.getMessage() + ")");
            } catch (IOException e) {
                throw new Exception("RecomendadorContenido.eliminarContenido: IOException error (" + e.getMessage() + ")");
            }

        }

    }

}
