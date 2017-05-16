package com.itelligent.agrega2.dal;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.codehaus.jackson.JsonNode;

import com.emergya.agrega2.arranger.util.impl.Utils;

/**
 * Clase encargada de modelar las interaccioens de los usuarios
 */
public class Interaccion {

	private static final Log LOG = LogFactory.getLog(Interaccion.class);

	private long dtmInteraccion;
	private long idUsuario;
	private long idContenido;
	private TipoInteraccion tipoInteraccion;
	private TipoContenido tipoContenido;
	private float score;

	/**
	 * Crea una instancia del tipo Interacción
	 * 
	 * @param dtmInteraccionI
	 *            Fecha de la interacción
	 * @param idUsuarioI
	 *            Identificador del usuario que realiza la interacción
	 * @param idContenidoI
	 *            Identificador del contenido sobre el que se realiza la
	 *            interacción
	 * @param tipoContenidoI
	 *            Tipo del contenido sobre el que se realiza la interacción
	 * @param tipoInteraccionI
	 *            Tipo de interacicon que se realiza
	 * @param scoreI
	 *            score asigando a la interacción si aplica
	 */
	public Interaccion(long dtmInteraccionI, long idUsuarioI,
			long idContenidoI, TipoContenido tipoContenidoI,
			TipoInteraccion tipoInteraccionI, float scoreI) {
		this.dtmInteraccion = dtmInteraccionI;
		this.idUsuario = idUsuarioI;
		this.idContenido = idContenidoI;
		this.tipoInteraccion = tipoInteraccionI;
		this.tipoContenido = tipoContenidoI;
		this.score = scoreI;
	}

	/**
	 * Crea una instancia del tipo Interacción
	 * 
	 * @param dtmInteraccionI
	 *            Fecha de la interacción
	 * @param idUsuarioI
	 *            Identificador del usuario que realiza la interacción
	 * @param idContenidoI
	 *            Identificador del contenido sobre el que se realiza la
	 *            interacción
	 * @param tipoContenidoI
	 *            Tipo del contenido sobre el que se realiza la interacción
	 * @param tipoInteraccionI
	 *            Tipo de interacicon que se realiza
	 */
	public Interaccion(long dtmInteraccionI, long idUsuarioI,
			long idContenidoI, TipoContenido tipoContenidoI,
			TipoInteraccion tipoInteraccionI) {
		this.dtmInteraccion = dtmInteraccionI;
		this.idUsuario = idUsuarioI;
		this.idContenido = idContenidoI;
		this.tipoInteraccion = tipoInteraccionI;
		this.tipoContenido = tipoContenidoI;
	}

	/**
	 * Crea una instancia del tipo Interacción
	 * 
	 * @param dtmInteraccionI
	 *            Fecha de la interacción
	 * @param idUsuarioI
	 *            Identificador del usuario que realiza la interacción
	 * @param idContenidoI
	 *            Identificador del contenido sobre el que se realiza la
	 *            interacción
	 * @param tipoContenidoI
	 *            Tipo del contenido sobre el que se realiza la interacción
	 * @param tipoInteraccionI
	 *            Tipo de interacicon que se realiza
	 */
	public Interaccion(long dtmInteraccionI, long idUsuarioI,
			long idContenidoI, TipoContenido tipoContenidoI) {
		this.dtmInteraccion = dtmInteraccionI;
		this.idUsuario = idUsuarioI;
		this.idContenido = idContenidoI;
		this.tipoContenido = tipoContenidoI;
	}

	/**
	 * Crea una instancia del tipo Interacción.
	 * 
	 * @param nodo
	 *            JsonNode con los datos necesarios para crear la intereaccion.
	 *            Se buscaran los campos: timestamp, uid, id, action, type
	 */
	public Interaccion(JsonNode nodo) {
		this.dtmInteraccion = nodo.get("timestamp").asLong();
		this.idUsuario = nodo.get("uid").asLong();
		this.idContenido = nodo.get("id").asLong();
		try {
			this.tipoInteraccion = TipoInteraccion.valueOf(nodo.get("action")
					.asText().toUpperCase());
		} catch (Exception e) {
			String strTipoError = nodo.get("action").asText().toUpperCase();
			Utils.logWarn(LOG, "Cannot parse new TipoInteraccion("
					+ strTipoError + ")... Setting default to VIEW");
			this.tipoInteraccion = TipoInteraccion.VIEW;
		}
		try {
			this.tipoContenido = TipoContenido.getEnum(nodo.get("type")
					.asText());
		} catch (Exception e) {
			String strTipoError = nodo.get("type").asText().toUpperCase();
			Utils.logWarn(LOG, "Cannot parse new TipoContenido ("
					+ strTipoError + ")... Setting default to UNKNOWN");
			this.tipoContenido = TipoContenido.UNKNOWN;
		}

		// Si el tipo de interacciones score tengo que cojer la puntuacion
		if (this.tipoInteraccion == TipoInteraccion.SCORE) {
			try {
				this.score = nodo.get("score").asInt();
			} catch (Exception e) {
				Utils.logWarn(LOG,
						"Can not parser score value ("
								+ nodo.get("score").asText()
								+ ") ... Seting score to 5");
			}
		}

	}

	public long getDtmInteraccion() {
		return dtmInteraccion;
	}

	public void setDtmInteraccion(long dtmInteraccion) {
		this.dtmInteraccion = dtmInteraccion;
	}

	public long getIdUsuario() {
		return idUsuario;
	}

	public void setIdUsuario(long idUsuario) {
		this.idUsuario = idUsuario;
	}

	public long getIdContenido() {
		return idContenido;
	}

	public void setIdContenido(long idContenido) {
		this.idContenido = idContenido;
	}

	public TipoInteraccion getTipoInteraccion() {
		return tipoInteraccion;
	}

	public void setTipoInteraccion(TipoInteraccion tipoInteraccion) {
		this.tipoInteraccion = tipoInteraccion;
	}

	public TipoContenido getTipoContenido() {
		return tipoContenido;
	}

	public void setTipoContenido(TipoContenido tipoContenido) {
		this.tipoContenido = tipoContenido;
	}

	public float getScore() {
		return score;
	}

	public void setScore(float score) {
		this.score = score;
	}

	public float scoreMahout() {
		if (this.tipoInteraccion == TipoInteraccion.VIEW) {
			return 5;
		} else if (this.tipoInteraccion == TipoInteraccion.LIKE) {
			return (float) 7.5;
		} else if (this.tipoInteraccion == TipoInteraccion.COMMENT) {
			return 8;
		} else if (this.tipoInteraccion == TipoInteraccion.COMPARTIR) {
			return 9;
		} else if (this.tipoInteraccion == TipoInteraccion.FAVORITE) {
			return 10;
		} else if (this.tipoInteraccion == TipoInteraccion.SCORE) {
			return score / 10;
		}
		return (float) 5;
	}
}
