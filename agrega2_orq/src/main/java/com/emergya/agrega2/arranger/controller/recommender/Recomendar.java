package com.emergya.agrega2.arranger.controller.recommender;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
@RequestMapping(value = "/recommender")
public interface Recomendar {
    @RequestMapping(method = RequestMethod.GET, headers = "Accept=application/json")
    public List<Object> recomendar(HttpServletRequest request);
}
