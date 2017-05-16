package com.emergya.agrega2.arranger.model.entity.json;

import com.emergya.agrega2.arranger.model.entity.solr.Ode;
import com.fasterxml.jackson.annotation.JsonValue;

/**
 * Represents a Response from Arranger.
 */
public class ServiceResponse {

    /**
     * {@link ResponseCode}
     */
    private ResponseCode responseCode;

    /**
     * {@link java.net.HttpURLConnection}
     */
    private int httpResponseCode;

    /**
     * Description of response
     */
    private String message;

    /**
     * UUID of {@link @SolrDocument} in case of document injected.
     */
    private String documentId;

    private Ode ode;

    public ServiceResponse() {
        super();
    }

    public ServiceResponse(ResponseCode responseCode, String message) {
        super();
        this.responseCode = responseCode;
        this.message = message;
    }

    public ServiceResponse(ResponseCode responseCode, int httpResponseCode, String message) {
        super();
        this.responseCode = responseCode;
        this.httpResponseCode = httpResponseCode;
        this.message = message;
    }

    public ServiceResponse(ResponseCode responseCode, int httpResponseCode, String message, String documentId) {
        super();
        this.responseCode = responseCode;
        this.httpResponseCode = httpResponseCode;
        this.message = message;
        this.documentId = documentId;
    }

    public ServiceResponse(ResponseCode responseCode, int httpResponseCode, String message, String documentId, Ode ode) {
        super();
        this.responseCode = responseCode;
        this.httpResponseCode = httpResponseCode;
        this.message = message;
        this.documentId = documentId;
        this.ode = ode;
    }

    public ResponseCode getResponseCode() {
        return responseCode;
    }

    public void setResponseCode(ResponseCode responseCode) {
        this.responseCode = responseCode;
    }

    public int getHttpResponseCode() {
        return httpResponseCode;
    }

    public void setHttpResponseCode(int httpResponseCode) {
        this.httpResponseCode = httpResponseCode;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public String getDocumentId() {
        return documentId;
    }

    public void setDocumentId(String documentId) {
        this.documentId = documentId;
    }

    public Ode getOde() {
        return ode;
    }

    public void setOde(Ode ode) {
        this.ode = ode;
    }

    /**
     * Represents two States of {@link ServiceResponse}. NOK(0), OK(1).
     */
    public enum ResponseCode {
        NOK(0), OK(1), RETRY_PUBLISH_ODE(2);
        private final int value;

        private ResponseCode(int value) {
            this.value = value;
        }

        @JsonValue
        public int getValue() {
            return value;
        }

    }

}
