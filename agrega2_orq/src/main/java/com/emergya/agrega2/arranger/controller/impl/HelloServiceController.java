package com.emergya.agrega2.arranger.controller.impl;

import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.controller.HelloService;

@Component
public class HelloServiceController implements HelloService {

    @ResponseBody
    public String getGreeting(@PathVariable String name) {
        return "Hello " + name;
    }

    @ResponseBody
    public String getGreetingAdmin(@PathVariable String name) {
        return "Hello Admin " + name;
    }

}
