package com.itelligent.agrega2.dal.beans;

/**
 * Clase que define los objetos recomendación que tendrán dos parámetros: id y
 * score.
 */
public class Recomendacion {
    private long id;
    private float score;

    /**
     * Constructor con parámetros.
     * 
     * @param {@code int} Id de la Recomendación.
     * @param {@code float} Score de la Recomendación
     */
    public Recomendacion(int idI, float scoreI) {
        this.id = idI;
        this.score = scoreI;
    }

    public Recomendacion(long idI, float scoreI) {
        this.id = idI;
        this.score = scoreI;
    }

    /**
     * Constructor por defecto
     */
    public Recomendacion() {

    }

    /**
     * Método para obtener el parámetro id.
     * 
     * @return {@code int} Id de la recomendación.
     */
    public long getId() {
        return id;
    }

    /**
     * Método para obtener el parámetro score.
     * 
     * @return {@code float} Score de la recomendación.
     */
    public float getScore() {
        return score;
    }

    /**
     * Método de conversión a String.
     * @return {@code String} Objeto Recomendación convertido a String.
     */
    public String toString() {
        return "id : " + this.id + ", score " + this.score;
    }

}
