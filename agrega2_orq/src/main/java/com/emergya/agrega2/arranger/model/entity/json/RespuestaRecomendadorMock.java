package com.emergya.agrega2.arranger.model.entity.json;

import java.util.List;

public class RespuestaRecomendadorMock {

    private List<Recomendacion> recomendaciones;

    public List<Recomendacion> getRecomendaciones() {
        return recomendaciones;
    }

    public void setRecomendaciones(List<Recomendacion> recomendaciones) {
        this.recomendaciones = recomendaciones;
    }

    public class Recomendacion {
        private String odeId;

        private String odeTitle;

        public String getOdeId() {
            return odeId;
        }

        public void setOdeId(String odeId) {
            this.odeId = odeId;
        }

        public String getOdeTitle() {
            return odeTitle;
        }

        public void setOdeTitle(String odeTitle) {
            this.odeTitle = odeTitle;
        }

    }

}
