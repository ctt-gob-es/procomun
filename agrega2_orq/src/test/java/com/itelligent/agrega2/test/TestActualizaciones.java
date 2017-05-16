package com.itelligent.agrega2.test;

import static org.junit.Assert.assertTrue;

import com.itelligent.agrega2.dal.Decisor;

public class TestActualizaciones {

    // @Test
    public void testActualizar() {
        long idContenidoIncio, dtmInteracionInicio, idContenidoFin, dtmInteraccionFin;

        idContenidoIncio = Decisor.getIdContenidoMax();
        dtmInteracionInicio = Decisor.getDtmInteraccionMax();

        Decisor.upload();

        idContenidoFin = Decisor.getIdContenidoMax();
        dtmInteraccionFin = Decisor.getDtmInteraccionMax();

        assertTrue(idContenidoFin >= idContenidoIncio);
        assertTrue(dtmInteraccionFin >= dtmInteracionInicio);
    }
}
