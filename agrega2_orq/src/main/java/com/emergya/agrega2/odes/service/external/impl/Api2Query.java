package com.emergya.agrega2.odes.service.external.impl;

public class Api2Query {

    private String queryParams;

    private String notProvider;

    public Api2Query() {
		super();
	}
    
    public Api2Query(String queryParams, String notProvider) {
		super();
		this.queryParams = queryParams;
		this.notProvider = notProvider;
	}

	public String getQueryParams() {
        return queryParams;
    }

    public void setQueryParams(String queryParams) {
        this.queryParams = queryParams;
    }

    public void setNotProvider(String notProvider) {
        this.notProvider = notProvider;
    }

    public String getNotProvider() {
        return notProvider;
    }

	@Override
	public String toString() {
		return "Api2Query [queryParams=" + queryParams + ", notProvider=" + notProvider + "]";
	}
}
