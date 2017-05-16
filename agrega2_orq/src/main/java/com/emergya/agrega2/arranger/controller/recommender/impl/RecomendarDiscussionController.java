package com.emergya.agrega2.arranger.controller.recommender.impl;

import java.util.List;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.controller.recommender.RecomendarDiscussion;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.itelligent.agrega2.dal.Decisor;
import com.itelligent.agrega2.dal.TipoContenido;
import com.itelligent.agrega2.dal.beans.Recomendacion;

@Controller
public class RecomendarDiscussionController implements RecomendarDiscussion{

	private static final Log LOG = LogFactory
			.getLog(RecomendarDiscussionController.class);
	
	
	public @ResponseBody List<Recomendacion> recomendarDISCUSSION(HttpServletRequest request) {
		try {
            long idUser = Long.parseLong(request.getParameter("idUser"));
            long idContent = Long.parseLong(request.getParameter("idContent"));
            int numRecomendaciones = Integer.parseInt(request.getParameter("numRecomendaciones"));
            final List<Recomendacion> lstRes = Decisor.recomendarContenido(idUser, idContent, TipoContenido.DISCUSSION,
                    numRecomendaciones);

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
