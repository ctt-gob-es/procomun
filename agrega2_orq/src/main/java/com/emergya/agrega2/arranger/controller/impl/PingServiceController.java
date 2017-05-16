package com.emergya.agrega2.arranger.controller.impl;

import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Component;

import com.emergya.agrega2.arranger.controller.PingService;
import com.emergya.agrega2.arranger.model.entity.json.RespuestaRecomendadorMock;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * See {@link PingService} for more information.
 */
@Component
public class PingServiceController implements PingService {

    private static final Log LOG = LogFactory.getLog(PingServiceController.class);

    public ServiceResponse ping(HttpServletRequest request) {
        LOG.info("Ping received from " + request.getRemoteAddr() + "!");
        return new ServiceResponse(ResponseCode.OK, "Ping OK. Arranger version: "
                + Utils.getMessage("arranger.version") + " " + Utils.getMessage("arranger.buildTime"));
    }

    public RespuestaRecomendadorMock generarMockRecomendaciones() {
        RespuestaRecomendadorMock respuesta = new RespuestaRecomendadorMock();
        List<RespuestaRecomendadorMock.Recomendacion> list = new ArrayList<RespuestaRecomendadorMock.Recomendacion>();

        for (int i = 0; i < 5; i++) {
            RespuestaRecomendadorMock.Recomendacion recom = respuesta.new Recomendacion();
            recom.setOdeTitle("TITULO" + i);
            recom.setOdeId(String.valueOf(i));
            list.add(recom);
        }

        respuesta.setRecomendaciones(list);
        return respuesta;
    }
}
