<?php

/**
* This class is the manager for twitter conversations. Its responsablity is focused
* on manage the convesation with the Twitter API
*/
class TwitterTalker {
  /** Signature method */
  const OAUTH_SIGNATURE_METHOD = 'HMAC-SHA1';
  /** Oauth version */
  const OAUTH_VERSION = '1.0';
  /** Include entities or not */
  const INCLUDE_ENTITIES = 'true';

  /** Consumer key of the twitter app */
  private $consumer_key;
  /** Private consmer secret string */
  private $consumer_secret;
  /** Access token */
  private $access_token;
  /** Secret token */
  private $access_token_secret;

  private $url;
  private $oauth;
  /**
   * Constructor
   */
  function __construct($settings) {
    if (!isset($settings['consumer_key'])
      || !isset($settings['consumer_secret'])
      || !isset($settings['access_token'])
      || !isset($settings['access_token_secret'])) {

      throw new Exception("Some params are missing. Please, check that you configure all the params", 1);
    }
    $this->consumer_key = $settings['consumer_key'];
    $this->consumer_secret = $settings['consumer_secret'];
    $this->access_token = $settings['access_token'];
    $this->access_token_secret = $settings['access_token_secret'];
  }

  public function createTweet($status) {
    $url = 'https://api.twitter.com/1.1/statuses/update.json';
    $this->getOAuth('post', $url);
    $params = array('status' => $status);
    $this->createPetition($params, $url);
  }

  private function getOAuth($method, $url) {
    $oauth = array(
      'oauth_consumer_key' => $this->consumer_key,
      'oauth_nonce' => time(),
      'oauth_signature_method' =>  self::OAUTH_SIGNATURE_METHOD,
      'oauth_timestamp' => time(),
      'oauth_token' => $this->access_token,
      'oauth_version' => self::OAUTH_VERSION,
    );

    $base_url = $this->buildBaseURLString($method, $url, $oauth);
    $signature_key = rawurlencode($this->consumer_secret) . '&' . rawurlencode($this->access_token_secret);
    $signature = base64_encode(hash_hmac('SHA1', $base_url, $signature_key, true));
    $oauth['oauth_signature'] = $signature;

    $this->oauth = $oauth;
    $this->url = $url;
  }

  /* This method builds the base URL string for the OAuth
   */
  private function buildBaseURLString($method, $url, $oauth) {
    $return = array();
    ksort($oauth);

    foreach($oauth as $key=>$value)
    {
      $return[] = "$key=" . $value;
    }
    //The string start with the method in uppercase
    $url = strtoupper($method) . '&'
      . rawurlencode($url) . '&'
      . rawurlencode(implode('&', $return));

    return $url;
  }

  private function createPetition($params, $url) {
    $header[] = 'Authorization: OAuth '.
      'oauth_consumer_key="' . rawurlencode($this->oauth['oauth_consumer_key']) . '", ' .
      'oauth_nonce="' . rawurlencode($this->oauth['oauth_nonce']) . '", ' .
      'oauth_signature="' . rawurlencode($this->oauth['oauth_signature']) . '", ' .
      'oauth_signature_method="' . rawurlencode($this->oauth['oauth_signature_method']) . '", ' .
      'oauth_token="' . rawurlencode($this->oauth['oauth_token']) . '", ' .
      'oauth_timestamp="' . rawurlencode($this->oauth['oauth_timestamp']) . '", ' .
      'oauth_version="' . rawurlencode($this->oauth['oauth_version']) . '"';

    $options = array(
      CURLOPT_URL => $url,
      CURLOPT_HEADER => false,
      CURLOPT_HTTPHEADER => $header,
      CURLOPT_POST => true,
      CURLOPT_RETURNTRANSFER => true,
      CURLOPT_TIMEOUT => 10,
      CURLOPT_POSTFIELDS => $params,
    );

    $petition = curl_init();
    curl_setopt_array($petition, $options);
    $response = curl_exec($petition);
    curl_close($petition);
  }
}
?>
