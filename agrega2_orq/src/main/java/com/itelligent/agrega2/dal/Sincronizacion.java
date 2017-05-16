package com.itelligent.agrega2.dal;

import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

/**
 * Clase para poder lanzar nuevos hilos.
 * 
 */
@Service
public class Sincronizacion implements Runnable {

    /**
     * Metodo para lanzar el hilo.
     */
    public void doUpload() {
        Decisor.upload();
    }

    @Override
    @Scheduled(fixedDelay = 60000)
    public void run() {
        doUpload();
    }
}
