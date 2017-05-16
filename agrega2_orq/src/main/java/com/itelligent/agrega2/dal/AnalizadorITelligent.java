package com.itelligent.agrega2.dal;

import java.io.Reader;
import java.util.HashSet;
import java.util.Set;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.StopFilter;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.standard.StandardTokenizer;
import org.apache.lucene.util.Version;

/**
 * Analizador lucene con stop words en español
 * 
 */
public class AnalizadorITelligent extends Analyzer {

    /**
     * Listado de stopWords del analizador
     */
    public static final String[] SPANISH_STOP_WORDS = { "a", "amb", "al", "ante", "asi", "con", "contra", "de",
            "desde", "del", "e", "el", "en", "esta", "este", "ha", "hace", "hacia", "hasta", "la", "las", "le", "lo",
            "los", "mediante", "no", "o", "para", "por", "que", "se", "segun", "si", "sin", "sita", "sobre", "su",
            "tras", "un", "una", "y" };

    private Set<Object> stopTable = new HashSet<Object>();

    /**
     * Inicializa el analizador creando el conjunto de stopwords a partir de la lista 
     */
    public AnalizadorITelligent() {
        stopTable = StopFilter.makeStopSet(SPANISH_STOP_WORDS);
    }

    public final TokenStream tokenStream(String fieldName, Reader reader) {
        TokenStream result = new StandardTokenizer(Version.LUCENE_30, reader);

        result = new StopFilter(true, result, stopTable);

        return result;
    }
}
