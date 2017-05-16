package com.emergya.agrega2.arranger.controller;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.model.entity.json.RespuestaRecomendadorMock;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;

/**
 * Ping Service to check if Arranger is up.
 */
@Controller
public interface PingService {

    /** Method to check if Arranger is Up!
     * @param request HttpServletRequest
     * @return OK(1) or NOK(0)
     */
    @RequestMapping(value = { "/ping" }, method = RequestMethod.GET, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse ping(HttpServletRequest request);

    @RequestMapping(value = { "/recomendadorMock" }, method = RequestMethod.GET, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public RespuestaRecomendadorMock generarMockRecomendaciones();

}
