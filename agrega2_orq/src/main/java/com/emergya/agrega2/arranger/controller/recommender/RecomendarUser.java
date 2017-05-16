package com.emergya.agrega2.arranger.controller.recommender;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.itelligent.agrega2.dal.beans.Recomendacion;

@Deprecated
@Controller
@RequestMapping(value = "/user")
public interface RecomendarUser {

    @RequestMapping(value = "/recommender", method = RequestMethod.GET, headers = "Accept=application/json")
    public List<Recomendacion> recomendarUSER(HttpServletRequest request);
}
