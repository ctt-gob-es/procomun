package com.emergya.agrega2.arranger.controller.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.model.entity.solr.Post;
import com.emergya.agrega2.arranger.util.impl.Utils;
import com.emergya.agrega2.odes.util.TransformUtils;
import com.emergya.agrega2.odes.util.TransformUtils.TransformCatalog;

@Controller
public class TransformerController {

    /** Transform and load Post Tags from old catalog to leraningContext and knowledgeArea.
     * @param post Post to transform
     * @param language Language of Post
     * @return Post received transformed
     */
    @RequestMapping(value = "/transform/post", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public Post transformPost(@RequestBody Post post) {

        final List<String> labels = post.getLabels();

        if (Utils.isEmpty(labels)) {
            return post;
        } else {
            post.setPostLabels(new ArrayList<String>());
        }

        if (Utils.isEmpty(post.getLearningContext())) {
            post.setLearningContext(new ArrayList<String>());
        }

        if (Utils.isEmpty(post.getKnowledgeArea())) {
            post.setKnowledgeArea(new ArrayList<String>());
        }

        // Labels == PostLabels

        for (final String label : labels) {
            final TransformCatalog transformCatalog = TransformUtils.getTransformCatalog().get(label.toLowerCase());

            if (!Utils.isEmpty(transformCatalog)) {
                final List<String> learningContext = transformCatalog.getLearningContext();
                final List<String> knowledgeArea = transformCatalog.getKnowledgeArea();
                final List<String> socialLabels = transformCatalog.getSocialLabels();

                if(!Utils.isEmpty(learningContext)) {
                	post.addLearningContexts(learningContext);
                }
                if(!Utils.isEmpty(knowledgeArea)) {
                	post.addKnowledgeAreas(knowledgeArea);
                }
                if(!Utils.isEmpty(socialLabels)) {
                	post.addPostLabels(socialLabels);
                }
            } else {
                post.addPostLabel(label);
            }
        }

        post.setLabels(post.getPostLabels());

        return post;
    }

}
