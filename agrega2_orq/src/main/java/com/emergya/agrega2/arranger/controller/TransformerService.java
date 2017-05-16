package com.emergya.agrega2.arranger.controller;

import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.emergya.agrega2.arranger.model.entity.solr.Community;
import com.emergya.agrega2.arranger.model.entity.solr.Post;

@Controller
public interface TransformerService {

    /** Transform and load Post Tags from old catalog to leraningContext and knowledgeArea.
     * @param post Post to transform
     * @param language Language of Post
     * @return Post received transformed
     */
    @RequestMapping(value = "/transform/post", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public Post transformPost(@RequestBody Post post, @RequestBody String language);

    /** Transform and load Community social Tags from old catalog to leraningContext and knowledgeArea.
     * @param community Community to transform
     * @return Community received transformed
     */
    @RequestMapping(value = "/transform/community", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE, consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseBody
    public Community transformCommunity(@RequestBody Community community);

}
