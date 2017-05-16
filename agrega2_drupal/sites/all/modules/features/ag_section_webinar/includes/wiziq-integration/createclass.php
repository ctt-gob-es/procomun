<?php

require 'vendor/autoload.php';

use mikemix\Wiziq;

$auth    = new Wiziq\API\Auth('gG7u8svT8QM7xF2wxGIK3Q==', '8X5KRQTQtiE=');
$gateway = new Wiziq\API\Gateway($auth);
$api     = new Wiziq\API\ClassroomApi($gateway);

$email = 'ajmantis@emergya.com';
$id = 18372;
$name = 'Antonio Jesus Mantis';
$culture_name = 'es-ES';
$limit = 2;
$presenter_control = '';
$attendee_control = '';
$recording = TRUE;
$return_url = 'https://procomun.educalab.es';
$status_ping = '';
$duration = 60;
$extend_duration = null;
$timezone = 'Europe/Madrid';

try {
  $classroom = Wiziq\Entity\Classroom::build('Clase de prueba', new \DateTime('03/24/2017 13:00:00'))
    //->withPresenterEmail($email)
    ->withPresenter($id, $name)
    ->withLanguageCultureName($culture_name)
    ->withAttendeeLimit($limit)
    //->withPresenterDefaultControls($presenter_control)
    //->withAttendeeDefaultControls($attendee_control)
    ->withCreateRecording($recording)
    ->withReturnUrl($return_url)
    //->withStatusPingUrl($status_ping)
    ->withDuration($duration)
    //->withExtendDuration($extend_duration);
    ->withTimeZone($timezone);

  $response  = $api->create($classroom);

  printf('Class %s created: %s', $classroom, var_export($response, true));
} catch (Wiziq\Common\Api\Exception\CallException $e) {
  die($e->getMessage());
} catch (Wiziq\Common\Http\Exception\InvalidResponseException $e) {
  die($e->getMessage());
}