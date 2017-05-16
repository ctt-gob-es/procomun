package com.emergya.agrega2.arranger.controller.recommender.impl;

import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.controller.recommender.Recomendar;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Decisor;
import com.itelligent.agrega2.dal.TipoContenido;
import com.itelligent.agrega2.dal.beans.Recomendacion;
import com.itelligent.agrega2.dal.beans.RecomendacionSolr;
import com.itelligent.agrega2.dal.beans.RecomendacionSolrUser;

@Component
public class RecomendarController implements Recomendar {

    private static final Log LOG = LogFactory.getLog(RecomendarController.class);

    public @ResponseBody List<Object> recomendar(HttpServletRequest request) {

        String type = request.getParameter("contentType");

        if (!Utils.isEmpty(type)) {
            try {
                long idUser = Long.parseLong(request.getParameter("idUser"));
                long idContent = Long.parseLong(request.getParameter("idContent"));
                int numRecomendaciones = Integer.parseInt(request.getParameter("numRecomendaciones"));

                final List<Recomendacion> lstResTmp = Decisor.recomendarContenido(idUser, idContent, TipoContenido.valueOf(type.toUpperCase()), numRecomendaciones);
                final List<Object> lstRes = new ArrayList<Object>();
                if (TipoContenido.USER.equals(TipoContenido.valueOf(type.toUpperCase()))) {
                    for (Recomendacion recom : lstResTmp) {
                        lstRes.add(new RecomendacionSolrUser(recom));
                    }
                } else {
                    for (Recomendacion recom : lstResTmp) {
                        lstRes.add(new RecomendacionSolr(recom));
                        Utils.logInfo(LOG, recom.toString());
                    }
                }

                return lstRes;

            } catch (ClassCastException e) {
                Utils.logError(LOG, e, "ClassCastException -> Cannot convert parameter value.");
                return null;
            } catch (NumberFormatException e) {
                Utils.logError(LOG, e, "NumberFormatException -> Cannot get parameter.");
                return null;
            } catch (IllegalArgumentException e) {
                Utils.logError(LOG, e, "IllegalArgumentException -> Unrecognized content type: {0}", type);
                return null;
            }
        } else {
            Utils.logError(LOG, "Content type not specified. Cannot recommend.");
            return null;
        }

    }
}
