agrega2_orq
===========

Plataforma para la orquestación de los servicios web de comunicación entre plataformas del proyecto Agrega2.

###Despliegue en Apache Tomcat

    mvn clean package  
    cp target/Orquestador.war $TOMCAT/webapps/
    
###Ping services
http://{host}:8080/Orquestador

http://{host}:8080/Orquestador/rest/ping

