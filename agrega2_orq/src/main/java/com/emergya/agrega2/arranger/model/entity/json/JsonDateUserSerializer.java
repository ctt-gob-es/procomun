package com.emergya.agrega2.arranger.model.entity.json;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.codehaus.jackson.JsonGenerator;
import org.codehaus.jackson.JsonProcessingException;
import org.codehaus.jackson.map.JsonSerializer;
import org.codehaus.jackson.map.SerializerProvider;
import org.springframework.stereotype.Component;

import com.emergya.agrega2.arranger.model.entity.enums.SolrDocumentType;

/**
 * Serializer of {@link SolrDocumentType} USER Date types
 */
@Component
public class JsonDateUserSerializer extends JsonSerializer<Date> {

    private static final SimpleDateFormat DF = new SimpleDateFormat("yyyy-MM-dd");

    @Override
    public void serialize(Date date, JsonGenerator gen, SerializerProvider provider) throws IOException,
            JsonProcessingException {

        String formattedDate = DF.format(date);

        gen.writeString(formattedDate);
    }

}
