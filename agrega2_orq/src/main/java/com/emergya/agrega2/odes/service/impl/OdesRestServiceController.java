package com.emergya.agrega2.odes.service.impl;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.PathVariable;

import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse;
import com.emergya.agrega2.arranger.model.entity.json.ServiceResponse.ResponseCode;
import com.emergya.agrega2.arranger.solr.SolrSupport;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.beans.OdeContentJson;
import com.emergya.agrega2.odes.service.OdesRestService;
import com.emergya.agrega2.odes.service.external.impl.EuropeanaWrapperImpl;
import com.emergya.agrega2.odes.service.external.impl.HispanaWrapperImpl;
import com.emergya.agrega2.odes.service.external.impl.InterlinkingWrapper;
import com.emergya.agrega2.odes.service.external.impl.MuseoPradoWrapperImpl;
import com.emergya.agrega2.odes.service.external.impl.RedinedSolrWrapperImpl;
import com.emergya.agrega2.odes.util.AgregaUtil;
import com.emergya.agrega2.odes.util.VisualizerUtils;

@Component
public class OdesRestServiceController implements OdesRestService {

	private static final Log LOG = LogFactory.getLog(OdesRestServiceController.class);

	@Override
	public List<OdeContentJson> getOdeTreeData(@PathVariable String odeId, @PathVariable String language,
			HttpServletRequest request) {
		List<OdeContentJson> result = VisualizerUtils.getODETreeData(odeId, language);
		if (Utils.isEmpty(result)) {
			result = new ArrayList<OdeContentJson>();
			OdeContentJson sample = new OdeContentJson();
			sample.setLabel(
					"El recurso solicitado no está disponible en estos momentos. Inténtelo de nuevo más tarde.");
			result.add(sample);
		}

		return result;
	}

	@Override
	public String getOdeTitle(@PathVariable String odeId, HttpServletRequest request) {
		String result = (String) SolrSupport.getSolrField(odeId, "titleStr");
		if (Utils.isEmpty(result)) {
			result = "El recurso solicitado no está disponible en estos momentos. Inténtelo de nuevo más tarde.";
		}
		return result;

	}

	@Override
	public ServiceResponse getOdeNode(final HttpServletRequest request) {
		final String mecIdentifier = (String) request.getParameter("mecIdentifier");
		final String language = (String) request.getParameter("language");
		final String nodoOde = AgregaUtil.getNodoOde(mecIdentifier, language);
		Utils.logInfo(LOG, "Found NODE {0} from {1}", nodoOde, mecIdentifier);
		return new ServiceResponse(ResponseCode.OK, 200, nodoOde);
	}

	@Override
	public List<String> getPifTypes(final String mecIdentifier) {
		return AgregaUtil.getPifTypes(mecIdentifier);
	}

	@Override
	public ServiceResponse getPublicator(@PathVariable final String mecIdentifier, final HttpServletRequest request) {
		final String publicatorStr = (String) SolrSupport.getSolrFieldByMECId(mecIdentifier, "publicatorStr");
		if (!Utils.isEmpty(publicatorStr)) {
			return new ServiceResponse(ResponseCode.OK, 200, publicatorStr);
		} else {
			return new ServiceResponse(ResponseCode.OK, 404, null);
		}
	}

	@Override
	public ServiceResponse getPublicatorName(@PathVariable final String mecIdentifier,
			final HttpServletRequest request) {
		final String publicatorNameStr = (String) SolrSupport.getSolrFieldByMECId(mecIdentifier, "publicatorNameStr");
		if (!Utils.isEmpty(publicatorNameStr)) {
			return new ServiceResponse(ResponseCode.OK, 200, publicatorNameStr);
		} else {
			return new ServiceResponse(ResponseCode.OK, 404, null);
		}
	}

	@SuppressWarnings("unchecked")
	@Override
	public List<String> getInterlinkingContent(@PathVariable final String odeId, final HttpServletRequest request) {

		List<String> originalContent = (List<String>) SolrSupport.getSolrField(odeId, "titleLinksStr");
		final String titleParam = (String) SolrSupport.getSolrField(odeId, "titleStr");

		final String separator = Utils.isEmpty(Utils.getMessage("format_separator")) ? "##"
				: Utils.getMessage("format_separator");

		List<String> results = new ArrayList<String>();
		originalContent = Utils.isEmpty((List<String>) SolrSupport.getSolrField(odeId, "titleLinksStr"))
				? new ArrayList<String>() : originalContent;

		List<String> originalContentCopy = new ArrayList<String>(originalContent);

		// BNE results first
		for (final String str : originalContent) {
			final String[] splitStr = str.split(separator);

			if (splitStr.length == 3 && splitStr[2].equals("BNE")) {
				results.add(str);
				originalContentCopy.remove(str);
			}
		}

		ConcurrentLinkedQueue<String> resultsQueue = new ConcurrentLinkedQueue<String>();

		final Thread threadRedined = createThreadByOrigin(resultsQueue, titleParam, InterlinkingWrapper.REDINED_ID,
				new RedinedSolrWrapperImpl());
		final Thread threadMuseoPrado = createThreadByOrigin(resultsQueue, titleParam,
				InterlinkingWrapper.MUSEO_PRADO_ID, new MuseoPradoWrapperImpl());
		final Thread threadHispana = createThreadByOrigin(resultsQueue, titleParam, InterlinkingWrapper.HISPANA_ID,
				new HispanaWrapperImpl());
		final Thread threadEuropeana = createThreadByOrigin(resultsQueue, titleParam, InterlinkingWrapper.EUROPEANA_ID,
				new EuropeanaWrapperImpl());

		threadRedined.start();
		threadMuseoPrado.start();
		threadHispana.start();
		threadEuropeana.start();

		try {

			threadRedined.join();
			threadMuseoPrado.join();
			threadHispana.join();
			threadEuropeana.join();

		} catch (InterruptedException e) {
			Utils.logError(LOG, e, "An error has been produced collecting interlinking content");
		}

		results.addAll(resultsQueue);

		// Add remaining content
		results.addAll(originalContentCopy);

		return results;
	}

	private <T extends InterlinkingWrapper> Thread createThreadByOrigin(final Queue<String> queue,
			final String titleParam, final String typeContent, final T originWrapper) {

		Thread thread = new Thread() {
			public void run() {
				final List<String> originContent = originWrapper.getContent(titleParam);
				if (!Utils.isEmpty(originContent)) {
					queue.addAll(originContent);
					showLogContent(typeContent, originContent);
				}
			}
		};
		return thread;
	}

	private void showLogContent(final String typeContent, final List<String> contentList) {
		Iterator<String> contentIt = contentList.iterator();
		while (contentIt.hasNext()) {
			Utils.logInfo(LOG, "{0} content added {1}", typeContent, contentIt.next());
		}
	}
}