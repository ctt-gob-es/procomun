package com.emergya.agrega2.arranger.controller.recommender.impl;

import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.controller.recommender.RecomendarOde;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Decisor;
import com.itelligent.agrega2.dal.TipoContenido;
import com.itelligent.agrega2.dal.beans.Recomendacion;
import com.itelligent.agrega2.dal.beans.RecomendacionOde;

@Deprecated
@Component
public class RecomendarOdeController implements RecomendarOde {

    private static final Log LOG = LogFactory.getLog(RecomendarOdeController.class);

    public @ResponseBody
    List<RecomendacionOde> recomendarODE(HttpServletRequest request) {

        try {
            long idUser = Long.parseLong(request.getParameter("idUser"));
            long idContent = Long.parseLong(request.getParameter("idContent"));
            int numRecomendaciones = Integer.parseInt(request.getParameter("numRecomendaciones"));
            final List<Recomendacion> lstResTmp = Decisor.recomendarContenido(idUser, idContent, TipoContenido.ODE,
                    numRecomendaciones);
            final List<RecomendacionOde> lstRes = new ArrayList<RecomendacionOde>();
            for (Recomendacion recom : lstResTmp) {
                lstRes.add(new RecomendacionOde(recom));
            }

            return lstRes;
        } catch (ClassCastException e) {
            Utils.logError(LOG, e, "ClassCastException -> Cannot convert parameter value.");
            return null;
        } catch (NumberFormatException e) {
            Utils.logError(LOG, e, "NumberFormatException -> Cannot get parameter.");
            return null;
        }

    }
}
