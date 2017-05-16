package com.emergya.agrega2.arranger.controller.recommender;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.itelligent.agrega2.dal.beans.RecomendacionOde;

@Deprecated
@Controller
@RequestMapping(value = "/ode")
public interface RecomendarOde {
    @RequestMapping(value = "/recommender", method = RequestMethod.GET, headers = "Accept=application/json")
    public List<RecomendacionOde> recomendarODE(HttpServletRequest request);
}
