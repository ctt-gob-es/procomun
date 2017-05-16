package com.emergya.agrega2.arranger.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
@RequestMapping(value = "/hello")
public interface HelloService {

    @RequestMapping(value = "/{name}", method = RequestMethod.GET)
    public String getGreeting(String name);

    @RequestMapping(value = "/admin/{name}", method = RequestMethod.GET)
    public String getGreetingAdmin(String name);

}
