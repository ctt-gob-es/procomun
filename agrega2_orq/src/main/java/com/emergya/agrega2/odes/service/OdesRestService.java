package com.emergya.agrega2.odes.service;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.odes.beans.OdeContentJson;

@Controller
public interface OdesRestService {

    @RequestMapping(value = { "/odeTreeData/{odeId}/{language}" }, method = RequestMethod.GET, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public List<OdeContentJson> getOdeTreeData(@PathVariable final String odeId, @PathVariable final String language, final HttpServletRequest request);

    @RequestMapping(value = { "/odeTitle/{odeId}" }, method = RequestMethod.GET, produces = { "text/plain;charset=UTF-8" })
    @ResponseBody
    public String getOdeTitle(@PathVariable final String odeId, final HttpServletRequest request);

    @RequestMapping(value = "/getOdeNode", method = RequestMethod.GET, headers = "Accept=application/json")
    @ResponseBody
    public ServiceResponse getOdeNode(HttpServletRequest request);

    @RequestMapping(value = "/getPifTypes{mecIdentifier}", method = RequestMethod.GET, headers = "Accept=application/json")
    @ResponseBody
    public List<String> getPifTypes(@PathVariable String mecIdentifier);

    @RequestMapping(value = { "/getPublicator/{mecIdentifier}" }, method = RequestMethod.GET, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse getPublicator(@PathVariable final String mecIdentifier, final HttpServletRequest request);
    
    @RequestMapping(value = { "/getPublicatorName/{mecIdentifier}" }, method = RequestMethod.GET, produces = { "application/json;charset=UTF-8" })
    @ResponseBody
    public ServiceResponse getPublicatorName(@PathVariable final String mecIdentifier, final HttpServletRequest request);

    @RequestMapping(value = "/getInterlinkingContent/{odeId}", method = RequestMethod.GET, produces = "application/json;charset=UTF-8")
    @ResponseBody
    public List<String> getInterlinkingContent(@PathVariable final String odeId, final HttpServletRequest request);

}
